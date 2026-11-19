#!/usr/bin/env python3
"""
prepare_sources.py - Kopiert die rekonstruierten Riva-Quellen (Quelle/cpp, Quelle/inc)
nach Port/src/ (ohne Quelle/ jemals zu veraendern) und bereitet sie fuer Standard-C/C++
(GCC/MinGW, Clang, MSVC) vor:
  1. Entfernt in geteilten Einheiten (teile_alle.tsv) Funktionsdefinitionen f_xxxxxx,
     deren Adresse ausserhalb des Einheitsbereichs [lo, hi) liegt (ersetzt durch Prototyp).
  2. Ersetzt die 70 Watcom-#pragma-aux-Inline-Assembler-Makros durch portable C-Funktionen
     auf Dateiebene (niemals innerhalb von Funktionsruempfen).
  3. Ersetzt #pragma-aux-Wrapper mit vertauschter Registerreihenfolge (parm [edx][eax] usw.)
     durch Inline-Weiterleitungen in kanonischer Parameterreihenfolge.
  4. Erzeugt Kompatibilitaets-Header (watcom_compat.h, i86.h, bios.h, dos.h, conio.h) in Port/src/inc/.
"""

import json
import re
import shutil
import tarfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
PORT_DIR = HERE.parent
REPO_ROOT = PORT_DIR.parent

GH_QUELLE = REPO_ROOT / "GitHub_Vorbereitung" / "riva" / "Quelle"
BAUSTAND_TGZ = REPO_ROOT / "GitHub_Vorbereitung" / "riva" / "Bauen" / "baustand.tgz"

SRC_DIR = PORT_DIR / "src"
SRC_CPP = SRC_DIR / "cpp"
SRC_INC = SRC_DIR / "inc"


def load_unit_bounds():
    bounds = {}
    with tarfile.open(BAUSTAND_TGZ, "r:gz") as tar:
        lines = tar.extractfile("meta/teile_alle.tsv").read().decode("utf-8").splitlines()
    for l in lines:
        t = l.split("\t")
        if len(t) >= 4:
            bounds[t[1]] = (int(t[2], 16), int(t[3], 16))
    return bounds


def strip_out_of_bounds_functions(text: str, unit: str, lo: int, hi: int) -> tuple[str, int]:
    """Entfernt auf Top-Level (Klammer-Tiefe 0) ausschliesslich Funktionsruempfe von f_xxxxxx
    (bzw. Class::f_xxxxxx), deren Adresse nicht in [lo, hi) liegt. Alle Hilfs-Structs,
    Typedefs und Inline-Helfer bleiben vollstaendig erhalten."""
    # Wir scannen den Text zeichenweise (mit Kommentar-/String-Erkennung) und merken uns
    # Top-Level-Bloecke '{ ... }' samt der unmittelbar davorstehenden Signatur.
    n = len(text)
    i = 0
    in_line_comment = False
    in_block_comment = False
    in_str = None
    depth = 0
    last_top_stmt_start = 0
    edits = []  # (start_pos, end_pos, replacement)

    while i < n:
        ch = text[i]
        if in_line_comment:
            if ch == "\n":
                in_line_comment = False
                if depth == 0:
                    line_start = i + 1
                    if text.startswith("#", line_start) or text.startswith("//@", line_start):
                        pass
            i += 1
            continue
        if in_block_comment:
            if text.startswith("*/", i):
                in_block_comment = False
                i += 2
            else:
                i += 1
            continue
        if in_str:
            if ch == "\\":
                i += 2
                continue
            if ch == in_str:
                in_str = None
            i += 1
            continue

        if text.startswith("//", i):
            in_line_comment = True
            i += 2
            continue
        if text.startswith("/*", i):
            in_block_comment = True
            i += 2
            continue
        if ch in ('"', "'"):
            in_str = ch
            i += 1
            continue

        if depth == 0:
            if ch == ";":
                last_top_stmt_start = i + 1
            elif ch == "\n":
                # Falls die gerade beendete Zeile eine Praeprozessor-Direktive war, beginnt danach ein neues Statement
                line_s = text.rfind("\n", 0, i) + 1
                if text[line_s:i].lstrip().startswith("#"):
                    last_top_stmt_start = i + 1
            elif ch == "{":
                brace_open = i
                brace_close = n - 1
                depth = 1
                i += 1
                while i < n and depth > 0:
                    c2 = text[i]
                    if in_line_comment:
                        if c2 == "\n":
                            in_line_comment = False
                        i += 1
                        continue
                    if in_block_comment:
                        if text.startswith("*/", i):
                            in_block_comment = False
                            i += 2
                        else:
                            i += 1
                        continue
                    if in_str:
                        if c2 == "\\":
                            i += 2
                            continue
                        if c2 == in_str:
                            in_str = None
                        i += 1
                        continue
                    if text.startswith("//", i):
                        in_line_comment = True
                        i += 2
                        continue
                    if text.startswith("/*", i):
                        in_block_comment = True
                        i += 2
                        continue
                    if c2 in ('"', "'"):
                        in_str = c2
                        i += 1
                        continue
                    if c2 == "{":
                        depth += 1
                    elif c2 == "}":
                        depth -= 1
                        if depth == 0:
                            brace_close = i
                            break
                    i += 1

                # Pruefe die Signatur zwischen last_top_stmt_start und brace_open
                raw_sig = text[last_top_stmt_start:brace_open]
                # Entferne Kommentare und #pragma-Zeilen fuer die Analyse
                sig_nc = re.sub(r"/\*.*?\*/", " ", raw_sig, flags=re.S)
                sig_nc = re.sub(r"//[^\n]*", " ", sig_nc)
                sig_lines_clean = [
                    sl for sl in sig_nc.splitlines() if not sl.strip().startswith("#")
                ]
                sig_flat = " ".join(sig_lines_clean).strip()

                # Ist es eine Funktionsdefinition von f_xxxxxx (nicht struct/class/union/enum)?
                m_fn = re.search(
                    r"(?:^|[\s*&:])(?:([A-Za-z_][A-Za-z0-9_]*)\s*::\s*)?f_([0-9a-fA-F]{6})\s*\([^;{}]*\)\s*(?:const\s*)?$",
                    sig_flat,
                )
                if m_fn and not re.match(r"^(?:struct|class|union|enum)\b", sig_flat):
                    cls_name = m_fn.group(1)
                    va = int(m_fn.group(2), 16)
                    if not (lo <= va < hi):
                        # Finde den exakten Beginn der Funktionssignatur in raw_sig (nach Kommentaren/#pragma)
                        if cls_name:
                            # Out-of-line-Methode: Signatur + Rumpf entfernen (Methode ist in der Klasse deklariert)
                            # Behalte vorangehende Kommentare/#pragma in raw_sig
                            m_last_fn = list(
                                re.finditer(
                                    rf"[^\n;{{}}]*\b{re.escape(cls_name)}\s*::\s*f_{va:06x}\b",
                                    raw_sig,
                                    flags=re.I,
                                )
                            )
                            sig_pos = (
                                last_top_stmt_start + m_last_fn[-1].start()
                                if m_last_fn
                                else last_top_stmt_start
                            )
                            edits.append(
                                (
                                    sig_pos,
                                    brace_close + 1,
                                    f"/* [Port: {cls_name}::f_{va:06x} in Nachbareinheit] */",
                                )
                            )
                        else:
                            # Freie Funktion: Ersetze nur '{ ... }' durch ';'
                            edits.append(
                                (
                                    brace_open,
                                    brace_close + 1,
                                    f"; /* [Port: f_{va:06x} in Nachbareinheit] */",
                                )
                            )
                last_top_stmt_start = brace_close + 1
        i += 1

    if not edits:
        return text, 0

    out = []
    prev = 0
    for s, e, rep in edits:
        out.append(text[prev:s])
        out.append(rep)
        prev = e
    out.append(text[prev:])
    return "".join(out), len(edits)


def transform_watcom_constructs(text: str, unit: str) -> str:
    top_defs = []
    bottom_defs = []

    # Menü-Zeilengrenzen sind vorzeichenlose Bytes (Original f_0be4f0:
    # 0x0bea4a/0x0beb0f: and edx,0xff). GCC liest plain char sonst
    # signiert; die letzte Grenze >127 macht "Zurück" unerreichbar.
    if unit == "menu":
        text = text.replace("char *a76;", "unsigned char *a76;")
        text = text.replace("char *positions=p->a76;", "unsigned char *positions=p->a76;")
        text = text.replace("char *pos=*(char *volatile *)&p->a76;",
                            "unsigned char *pos=*(unsigned char *volatile *)&p->a76;")

    # 0. Hex-Floats ohne Leerzeichen vor +/- (z.B. 0x1e+frames oder 0x1e-0x116) fuer C++-Präprozessor trennen
    text = re.sub(r"(0x[0-9a-fA-F]*[eE])([+-])", r"\1 \2", text)

    # 0b. va_arg(ap, short/char) -> (short/char)va_arg(ap, int), da GCC sonst ud2 (__builtin_trap) erzeugt
    text = re.sub(
        r"\bva_arg\s*\(\s*([A-Za-z0-9_]+)\s*,\s*((?:unsigned\s+|signed\s+)?(?:short|char))\s*\)",
        r"((\2)va_arg(\1, int))",
        text,
    )

    # 1. Far-Pointer-Operator `:>` ersetzen
    text = re.sub(
        r"\(\(unsigned short\)s\.es\s*:>\s*\(void __near \*\)r\.x\.ebx\)",
        r"((void *)(uintptr_t)r.x.ebx)",
        text,
    )
    text = re.sub(
        r"\(\(__segment\)\s*([a-zA-Z0-9_]+)\s*:>\s*\([^)]+\)\s*([a-zA-Z0-9_]+)\)",
        r"((void *)(((uintptr_t)(\1) << 4) + (uintptr_t)(\2)))",
        text,
    )

    # 2. Watcom __pragma("...") in typedefs und Struct-Konstruktoren/-Destruktoren aufloesen
    text = re.sub(r'\b__pragma\s*\(\s*"[^"]+"\s*\)\s*', lambda m: m.group(0), text)
    # In typedef: typedef int __pragma("cut_konv") cut_t(...);
    text = re.sub(r'(typedef\s+[^\n;(__]+?)\s*__pragma\s*\(\s*"[^"]+"\s*\)\s*', r"\1 ", text)
    # In struct-Konstruktoren/Destruktoren:
    # 0 Argumente: __pragma("fn") ClassName();
    text = re.sub(
        r'__pragma\s*\(\s*"([A-Za-z0-9_]+)"\s*\)\s*([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*(?:void)?\s*\)\s*;',
        r"\2() { \1(this); }",
        text,
    )
    # Destruktor: __pragma("fn") ~ClassName();
    text = re.sub(
        r'__pragma\s*\(\s*"([A-Za-z0-9_]+)"\s*\)\s*~\s*([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*(?:void)?\s*\)\s*;',
        r"~\2() { \1(this, 2); }",
        text,
    )
    # 1 Argument: __pragma("fn") ClassName(T1);
    text = re.sub(
        r'__pragma\s*\(\s*"([A-Za-z0-9_]+)"\s*\)\s*([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*([^,)]+)\s*\)\s*;',
        r"\2(\3 _a1) { \1(this, _a1); }",
        text,
    )
    # 3 Argumente: __pragma("fn") ClassName(T1, T2, T3);
    text = re.sub(
        r'__pragma\s*\(\s*"([A-Za-z0-9_]+)"\s*\)\s*([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*([^,)]+)\s*,\s*([^,)]+)\s*,\s*([^,)]+)\s*\)\s*;',
        r"\2(\3 _a1, \4 _a2, \5 _a3) { \1(this, _a1, _a2, _a3); }",
        text,
    )

    # 3. svga1_neu_P1.CPP: f_11e760 wird teils (w, h) (__pascal), teils (h, w) (__stdcall) aufgerufen
    if unit == "svga1_neu":
        text = text.replace(
            "unsigned long W, Hh;",
            "unsigned long W, Hh; if (w < (unsigned)x) w = (unsigned)x;",
        )

    # 4. Inline-ASM #pragma aux (70 Zeilen in 22 Einheiten) durch C-Implementierungen auf Dateiebene ersetzen
    # Hilfsfunktion: entfernt lokale/globale Prototypen von fn und fuegt Definition in top_defs ein
    def hoist_inline(fn: str, c_def: str):
        nonlocal text
        pat = rf"(?:\bextern\s+)?\b(?:int|unsigned(?:\s+int|\s+short|\s+char|\s+long)?|long|short|void)\s+{re.escape(fn)}\s*\([^;{{}}]*\)\s*;"
        if re.search(pat, text) or re.search(rf"#\s*pragma\s+aux\s+{re.escape(fn)}\b", text):
            text = re.sub(pat, f"/* {fn} hoisted */", text)
            top_defs.append(c_def)

    for fn in ("local_frame", "bar298", "sperre"):
        hoist_inline(fn, f"static inline void {fn}(void) {{}}")
    hoist_inline("pick_edx", "static inline int pick_edx(int v) { return v; }")
    hoist_inline("w15_inedx", "static inline int w15_inedx(int v) { return v; }")
    hoist_inline("sxax", "static inline int sxax(short v) { return v; }")

    if unit == "fz_14dc28_t7a":
        for m_id in re.finditer(
            r"\b(int|unsigned short|unsigned char)\s+(same_[a-z0-9_]+|angle_before_bh298|init_d_mem298|result_before_di298|angle_mem298|threshold_no_si298|hold_d298)\s*\(([^)]+)\)\s*;",
            text,
        ):
            ret_t, fn_name, param_decl = m_id.group(1), m_id.group(2), m_id.group(3)
            param_name = param_decl.split()[-1].lstrip("*")
            hoist_inline(fn_name, f"static inline {ret_t} {fn_name}({param_decl}) {{ return {param_name}; }}")
        for fn_v in ("forget_a298", "entry_before_bp298"):
            hoist_inline(fn_v, f"static inline void {fn_v}(void) {{}}")
        hoist_inline("hold_d298", "static inline void hold_d298(int) {}")
        hoist_inline("pair_a298", "static inline int pair_a298(int a, int) { return a; }")
        for fn_m in ("fmb_pose298", "a4_angle_mul", "a4_y_mul", "fm298", "fmb298"):
            hoist_inline(
                fn_m,
                f"static inline int {fn_m}(int a, int b) {{ return (int)(((long long)a * (long long)b) >> 16); }}",
            )
        hoist_inline(
            "md298",
            "static inline int md298(int a, int b, int c) { return c ? (int)(((long long)a * (long long)b) / (long long)c) : 0; }",
        )

    if unit == "amap_t12":
        hoist_inline(
            "wurzel32",
            "static inline int wurzel32(int x) { int r=0, d=1; while ((x -= d) >= 0) { r++; d += 2; } return r; }",
        )

    # Fixed-Point Mul (imul + shrd 16):
    for fn in ("fixmul", "fxmul831", "FMUL", "mul14eeac", "FM", "mul150334", "mul1508fc", "fmul", "fmulnm", "FMB", "IFixedMul"):
        if re.search(rf"#\s*pragma\s+aux\s+{re.escape(fn)}\b", text):
            hoist_inline(
                fn,
                f"static inline int {fn}(int a, int b) {{ return (int)(((long long)a * (long long)b) >> 16); }}",
            )

    # Fixed-Point Div ((a << 16) / b):
    for fn in ("fxdiv831", "fxdiv831_b", "FDIV", "div14eeac", "div150334", "div1508fc", "div298", "IFixedDiv"):
        if re.search(rf"#\s*pragma\s+aux\s+{re.escape(fn)}\b", text):
            hoist_inline(
                fn,
                f"static inline int {fn}(int a, int b) {{ return b ? (int)(((long long)a << 16) / (long long)b) : 0; }}",
            )

    # MulDiv ((a * b) / c):
    for fn in ("muldiv", "mdv", "md2682", "md152020", "MULDIV", "MD", "MD2", "MD3", "M0x", "M0y", "M1x", "M1y", "M2x", "M2y"):
        if re.search(rf"#\s*pragma\s+aux\s+{re.escape(fn)}\b", text):
            hoist_inline(
                fn,
                f"static inline int {fn}(int a, int b, int c) {{ return c ? (int)(((long long)a * (long long)b) / (long long)c) : 0; }}",
            )

    # rcp298(int hi, int lo, int b)
    if re.search(r"#\s*pragma\s+aux\s+rcp298\b", text):
        hoist_inline(
            "rcp298",
            "static inline int rcp298(int hi, int lo, int b) { return b ? (int)((((long long)hi << 32) | (unsigned int)lo) / (long long)b) : 0; }",
        )

    if unit in ("fz_197510", "fz_198c50"):
        hoist_inline(
            "IFixedSqr3",
            "static inline int IFixedSqr3(int a, int b, int c) { return (int)((((long long)a*a + (long long)b*b + (long long)c*c)) >> 16); }",
        )
        hoist_inline(
            "Mac15",
            "static inline int Mac15(int a, int b, int c, int d, int e, int f) { return (int)(((long long)(short)b * a) >> 15) + (int)(((long long)(short)c * d) >> 15) + (int)(((long long)(short)e * f) >> 15); }",
        )

    if unit == "fz_17e4a0_t1":
        hoist_inline("dpmi_seg", "static inline short dpmi_seg(unsigned, unsigned) { return 0; }")
        hoist_inline("dpmi_seg0", "static inline short dpmi_seg0(unsigned) { return 0; }")

    if unit == "gfx_t3":
        hoist_inline(
            "remap983",
            "static inline void remap983(unsigned char *buf, int width, int height, int skip, unsigned char *table) {\n"
            "    for (int y = 0; y < (unsigned short)height; ++y) {\n"
            "        for (int x = 0; x < (unsigned short)width; ++x) { *buf = table[*buf]; ++buf; }\n"
            "        buf += skip;\n"
            "    }\n}",
        )

    if unit == "gz_05dec0":
        text = re.sub(
            r"extern void blit_tr\([^;]+\);\s*#pragma aux blit_tr[^\n]*\\\s*(?:\"[^\"]*\"\s*\\\s*)*\"[^\"]*\";",
            "static inline void blit_tr(const unsigned char *s, unsigned char *d, const unsigned char *tbl, unsigned char h, unsigned char w) {\n"
            "    for (unsigned char y = 0; y < h; ++y) {\n"
            "        for (unsigned char x = 0; x < w; ++x) { unsigned char px = *s++; if (px) d[x] = tbl[(unsigned)px * 2]; }\n"
            "        d += 320;\n"
            "    }\n}",
            text,
        )
        text = re.sub(
            r"extern void blit_fill\([^;]+\);\s*#pragma aux blit_fill[^\n]*\\\s*(?:\"[^\"]*\"\s*\\\s*)*\"[^\"]*\";",
            "static inline void blit_fill(const unsigned char *s, unsigned char *d, const unsigned char *tbl, unsigned char h, unsigned char w, unsigned char fill) {\n"
            "    for (unsigned char y = 0; y < h; ++y) {\n"
            "        for (unsigned char x = 0; x < w; ++x) { unsigned char px = *s++; d[x] = px ? tbl[(unsigned)px * 2] : fill; }\n"
            "        d += 320;\n"
            "    }\n}",
            text,
        )

    if unit == "gz_068f40":
        text = text.replace("extern unsigned short _bios_keybrd(unsigned __cmd);", "#define _bios_keybrd port_bios_keybrd")
    if unit == "ch_skill":
        text = text.replace(
            "    if (f_043e30(p1) == 0) {\n"
            "        f_0ce7c0(&q);\n"
            "        f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);\n"
            "        pl.b[1] = 0x2000005c + skill;\n"
            "        pl.a[1] = p1;\n"
            "        pl.c[1] = abs(change);\n"
            "        pl.b[2] = abs(change) > 1 ? 0x20000164 : 0x20000194;\n"
            "    }\n"
            "    f_03adba(p1, skill, change); // Fortsetzung im eigenen Einsprungpunkt 0x03ADBA",
            "    int f_0bf680(void *);\n"
            "    int f_0ce7e0(void *, int);\n"
            "    signed char first, second;\n"
            "    int r;\n"
            "    if (f_043e30(p1) == 0) {\n"
            "        f_0ce7c0(&q);\n"
            "        f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);\n"
            "        pl.b[1] = 0x2000005c + skill;\n"
            "        pl.a[1] = p1;\n"
            "        pl.c[1] = abs(change);\n"
            "        pl.b[2] = abs(change) > 1 ? 0x20000164 : 0x20000194;\n"
            "        pl.b[3] = change < 0 ? 0x200001b7 : 0x200001b6;\n"
            "        pl.c[2] = *(signed char *)(p1 + skill + 0x7a);\n"
            "        pl.c[3] = *(signed char *)(p1 + skill + 0x81);\n"
            "        pl.b[4] = change < 0 ? 0x200001b7 : 0x200001b6;\n"
            "        f_0bf6c0(&d_1c2c64, 5);\n"
            "        r = f_0bf7b0(&d_1c2c64, 1, 0x200001b8, 0, (short)abs(change), (short)abs(change));\n"
            "        first = (signed char)r;\n"
            "        f_0bf680(&d_1c2c64);\n"
            "        second = abs(change) - first;\n"
            "        f_1254a0(&pl, 0);\n"
            "        f_0ce7e0(&q, 0);\n"
            "    } else {\n"
            "        second = abs(change) / 2;\n"
            "        first = second;\n"
            "        if (change % 2 != 0) {\n"
            "            if (f_1457e0(100) < 50) first++;\n"
            "            else second++;\n"
            "        }\n"
            "    }\n"
            "    if (change < 0) {\n"
            "        *(signed char *)(p1 + skill + 0x7a) -= first;\n"
            "        *(signed char *)(p1 + skill + 0x81) -= second;\n"
            "    } else {\n"
            "        *(signed char *)(p1 + skill + 0x7a) += first;\n"
            "        *(signed char *)(p1 + skill + 0x81) += second;\n"
            "    }\n"
            "    if (d_1c2a80 == 0x30000) d_1c2198 = 1;",
        )
    if unit == "gz_0d5b50":
        text = text.replace("extern unsigned short kb(unsigned cmd);", "#define kb port_bios_keybrd")
    if unit == "mouse":
        # In kooperativer Single-Thread-Umgebung muessen Tastenabfrage-Schleifen (wie while(f_0d3780()) in f_0d5b50(0))
        # die Event- und Timer-Pumpe (f_0d2920) anstossen, da kein Hardware-IRQ0 im Hintergrund laeuft.
        text = text.replace("d_1bf4cc = 0;\n    return d_1bf4d4;", "(void)port_bios_keybrd(1); d_1bf4cc = 0;\n    return d_1bf4d4;")
        text = text.replace("d_1bf4cc = 0;\n    return d_1bf4d4 == 0;", "(void)port_bios_keybrd(1); d_1bf4cc = 0;\n    return d_1bf4d4 == 0;")
        text = text.replace("d_1bf4dc = 0;\n    return d_1bf4e4;", "(void)port_bios_keybrd(1); d_1bf4dc = 0;\n    return d_1bf4e4;")
        text = text.replace("d_1bf4dc = 0;\n    return d_1bf4e4 == 0;", "(void)port_bios_keybrd(1); d_1bf4dc = 0;\n    return d_1bf4e4 == 0;")

    if unit == "fz_15689d_t1":
        # f_1568d1: im p3-Rekonstruktionsstand war die innere 4-Modi-Kopierschleife (0x156a16..0x156aab)
        # als leere Mess-Kruecke ausgelassen; hier die exakten 4 Kopiermodi des Originals einsetzen.
        text = text.replace(
            "                        typedef void (*CopyFn)(unsigned char *, unsigned char *, unsigned short);\n"
            "   // haelt die Registerzuteilung wie im Original",
            "                        extern int d_1a9ba0, d_1a9ba4;\n"
            "                        if (m == 0) {\n"
            "                            memcpy(dst, src, w);\n"
            "                        } else if (m == 1) {\n"
            "                            unsigned char tr = (unsigned char)d_1a9b9c;\n"
            "                            for (unsigned short k = 0; k < w; ++k) {\n"
            "                                unsigned char px_v = src[k];\n"
            "                                if (px_v != tr) dst[k] = px_v;\n"
            "                            }\n"
            "                        } else if (m == 2) {\n"
            "                            unsigned char lo = *(unsigned char *)&d_1a9ba0;\n"
            "                            unsigned char hi = *(unsigned char *)&d_1a9ba4;\n"
            "                            for (unsigned short k = 0; k < w; ++k) {\n"
            "                                unsigned char dv = dst[k];\n"
            "                                if (dv < lo || dv > hi) dst[k] = src[k];\n"
            "                            }\n"
            "                        } else if (m == 3) {\n"
            "                            unsigned char lo = *(unsigned char *)&d_1a9ba0;\n"
            "                            unsigned char hi = *(unsigned char *)&d_1a9ba4;\n"
            "                            unsigned char tr = (unsigned char)d_1a9b9c;\n"
            "                            for (unsigned short k = 0; k < w; ++k) {\n"
            "                                unsigned char dv = dst[k];\n"
            "                                if (dv < lo || dv > hi) {\n"
            "                                    unsigned char sv = src[k];\n"
            "                                    if (sv != tr) dst[k] = sv;\n"
            "                                }\n"
            "                            }\n"
            "                        }",
        )
        # f_156b4d: dynamische x86-Maschinencode-Erzeugung (lodsb/stosb/ret in d_1a9bc7 mit parm [esi] [edi])
        # durch die identische portable Bresenham-Zeilenskalierung ersetzen.
        text = text.replace(
            "            d_1a9bc7((char *)*r1, (char *)*r2);",
            "            {\n"
            "                unsigned char *s_row = (unsigned char *)*r1;\n"
            "                unsigned char *d_row = (unsigned char *)*r2;\n"
            "                short x_out = 0;\n"
            "                int err = w1;\n"
            "                for (short i_in = 0; i_in < (short)w1; ++i_in) {\n"
            "                    err -= w2;\n"
            "                    unsigned char px_v = *s_row++;\n"
            "                    while ((short)err <= 0) {\n"
            "                        if (x_out >= (short)w2) goto row_scale_done;\n"
            "                        *d_row++ = px_v;\n"
            "                        ++x_out;\n"
            "                        err += w1;\n"
            "                    }\n"
            "                }\n"
            "                row_scale_done:;\n"
            "            }",
        )

    if unit == "ace_t1":
        # Ace::Ace (f_0104b0) wird als Placement-Konstruktor aufgerufen (t ? f_0104b0(t, ...) : t)
        # und muss daher unter GCC/Itanium-ABI explizit this in EAX zurueckgeben.
        text = text.replace("#define Ace f_0104b0", "/* Ace struct */")
        text = text.replace(
            "Ace(int p2, short p3, short p4);",
            "Ace *f_0104b0(int p2, short p3, short p4);",
        )
        text = text.replace(
            "Ace::Ace(int p2, short p3, short p4) {\n",
            "Ace *Ace::f_0104b0(int p2, short p3, short p4) {\n"
            "  f_0fabf0(&a); f_0fabf0(&b);\n",
        )
        text = text.replace(
            "  f_010a90();\n}",
            "  f_010a90();\n  return this;\n}",
        )

    # 5. Nicht-Standard parm [...] Wrapper auf Dateiebene korrigieren
    if unit == "zmain":
        text = text.replace(
            "int f_14572e(int, int, int, int, int, int);",
            'extern "C" int f_14572e(char *, const char *, ...);\n'
            "static inline int f_14572e_zmain(int, int a, int b, int c, int d, int e) { return f_14572e((char*)a, (const char*)b, c, d, e); }\n"
            "#define f_14572e f_14572e_zmain",
        )
        text = text.replace("int f_148143(int p1, int p2);", "int f_148143(int p1, int p2, int p3);")
        text = text.replace("f_148143((int)d_1c20b4, (int)d_1c21b4);", "f_148143((int)d_1c20b4, (int)d_1c21b4, 0x3f);")
        text = text.replace("f_148143((int)name, AD(d_1c21b4));", "f_148143((int)name, AD(d_1c21b4), 14);")
        text = text.replace("int call_149caa(int, int, int);", "/* call_149caa hoisted */")
        text = text.replace("int call_05da10(int, int, int);", "/* call_05da10 hoisted */")
        top_defs.append(
            'extern "C" void f_149caa(void *);\n'
            "static inline int call_149caa(int, int, int c) { f_149caa((void*)c); return 0; }\n"
            'extern "C" int f_05da10_real(int, int) __asm__("_f_05da10");\n'
            "static inline int call_05da10(int, int a, int b) { return f_05da10_real(a, b); }"
        )

    if unit == "dialog_t1":
        text = text.replace("int shift_date(int, void *);", "/* shift_date hoisted */")
        text = text.replace("int call_125f70(int, int);", "/* call_125f70 hoisted */")
        text = text.replace("int call_125ed0(int, int);", "/* call_125ed0 hoisted */")
        top_defs.append(
            'extern "C" int f_126f40_real(void *, int) __asm__("_f_126f40");\n'
            "static inline int shift_date(int d, void *a) { return f_126f40_real(a, d); }\n"
            'extern "C" int f_125f70_real(int, int) __asm__("_f_125f70");\n'
            "static inline int call_125f70(int d, int a) { return f_125f70_real(a, d); }\n"
            'extern "C" int f_125ed0_real(int, int) __asm__("_f_125ed0");\n'
            "static inline int call_125ed0(int d, int a) { return f_125ed0_real(a, d); }"
        )

    if unit == "fz15c5a0":
        bottom_defs.append(
            'extern "C" RivaRecordVector *f_15c3f0_real(RivaRecordVector *, int, RivaRecordVector *) __asm__("_f_15c3f0");\n'
            "RivaRecordVector *riva_15c3f0(RivaRecordVector *a, RivaRecordVector *b, int d) { return f_15c3f0_real(a, d, b); }"
        )

    if unit == "gz_020420_t2":
        text = text.replace("short aux_0bf820(int p1, int, int, int, int, int, int);", "/* aux_0bf820 hoisted */")
        top_defs.append(
            'extern "C" short f_0bf820_real(int, int, int, int, int, int) __asm__("_f_0bf820");\n'
            "static inline short aux_0bf820(int, int a, int b, int c, int d, int e, int f) { return f_0bf820_real(a, b, c, d, e, f); }"
        )

    if unit == "gz_0a6280":
        bottom_defs.append(
            "int call_13d570_2(const char *, int n) { return f_13d570(n); }"
        )

    if unit == "misc_b":
        text = text.replace(
            "f_0d3df6(5, (int)d_1b8236, (const char *)&d_1c2e78);",
            "f_0d3df6((const char *)&d_1c2e78, 5, (int)d_1b8236);",
        )

    if unit == "no_ovl":
        text = text.replace("int f_1265c0_x(int, int);", "/* f_1265c0_x hoisted */")
        top_defs.append(
            'extern "C" int f_1265c0_real(int, int) __asm__("_f_1265c0");\n'
            "static inline int f_1265c0_x(int d, int a) { return f_1265c0_real(a, d); }"
        )

    if unit == "tower4_t1":
        text = text.replace("void call650_133890(int,int);", "/* call650_133890 hoisted */")
        text = text.replace("void call650_1337c0(int,int);", "/* call650_1337c0 hoisted */")
        top_defs.append(
            'extern "C" void f_133890_real(int, int) __asm__("_f_133890");\n'
            "static inline void call650_133890(int d, int a) { f_133890_real(a, d); }\n"
            'extern "C" void f_1337c0_real(int, int) __asm__("_f_1337c0");\n'
            "static inline void call650_1337c0(int d, int a) { f_1337c0_real(a, d); }"
        )

    if unit == "use_t1":
        text = text.replace("void f_05e360_ecx(int, int, int, int);", "/* f_05e360_ecx hoisted */")
        top_defs.append(
            'extern "C" void f_05e360_real(int, int, int) __asm__("_f_05e360");\n'
            "static inline void f_05e360_ecx(int, int a, int d, int b) { f_05e360_real(a, d, b); }"
        )

    if unit == "uvesa":
        text = text.replace(
            'extern "C" int bankcall30_A20T(int,void *,void *);',
            "static inline int bankcall30_A20T(int a, void *b, void *d) { return f_149cd2(a, d, b); }",
        )
        text = text.replace("d_1c1108->s4 = 0x40;", "d_1c1108->s4 = 0x1000;")
        text = re.sub(
            r"\b(?:(?:\(unsigned\)\s*)?(?:d_1c1108|m|vb)->(?:s8|sa)|vb)\s*<<\s*4\b",
            "((unsigned)(uintptr_t)port_get_vram())",
            text,
        )

    if unit == "gz_13bb70_t2":
        text = text.replace(
            "if (r.e.cflag == 0) return r.x.ax << 4; return 0;",
            "return (unsigned)(uintptr_t)calloc(1, (size_t)n + 256);",
        )
        text = text.replace(
            "f_145702(0x31, &d_1c1080, &d_1c1080, &d_1c109c);",
            "/* f_13d5d0 no-op under Win32 */",
        )
        text = text.replace(
            "*(unsigned short *)(d_1c1104 + 6) + *(unsigned short *)(d_1c1104 + 8) * 0x10",
            "(int)(d_1c1104 + 0x100)",
        )
        text = text.replace(
            "((*(unsigned short *)(d_1c1104 + 8) << 4) + *(unsigned short *)(d_1c1104 + 6))",
            "(d_1c1104 + 0x100)",
        )
        text = text.replace(
            "((*(unsigned short *)(d_1c1104 + 16) << 4) + *(unsigned short *)(d_1c1104 + 14))",
            "(d_1c1104 + 0x120)",
        )
        text = text.replace(
            "(unsigned)r.x.ax << 4",
            "(unsigned)r.x.ax",
        )

    if unit == "gz_13fef0_t1":
        text = text.replace("inline void *f_1401f0", "void *f_1401f0")
        text = text.replace("inline int f_1401e0", "int f_1401e0")

    if unit == "gz_05fbf0_t1":
        text = text.replace("unsigned lin = r.w.ax << 4;", "unsigned lin = r.x.eax;")

    # Ersetze alle direkten VGA-Basisadressen 0xA0000 / 0xa0000 durch port_get_vram()
    # Ausnahme: sacc_t2 (0xa0000 ist ALF-Ressourcen-ID 0x000A0000 neben 0xa0001; 0xadc00 ist 0xA0000+0xDC00) und
    # fz_14dc28_t7a (0xa0000 ist 16.16-Fixkommawert 10.0 in md298).
    if unit not in ("sacc_t2", "fz_14dc28_t7a"):
        text = re.sub(r"\b0x0?[aA]0000\b", "((int)(uintptr_t)port_get_vram())", text)
    if unit == "sacc_t2":
        text = re.sub(r"\b0x0?[aA][dD][cC]00\b", "(((int)(uintptr_t)port_get_vram()) + 0xdc00)", text)

    # 6. Einzelspezifische C++-Standardkonformitaets-Anpassungen
    if unit == "gz_0e2ac0":
        # Watcom 12-Byte-Memberfunktionszeiger-Thunk (d_1c004c -> p1->fn) aufrufen
        text = text.replace(
            "    typedef int (P::*MF)(int, int, short);\n"
            "    iVar5 = (p1->*(*(MF *)&p1->fn))(iVar5, local_20, sVar2);",
            "    typedef int (*RealMF)(struct P *, int, int, short);\n"
            "    typedef RealMF (*ThunkMF)(void);\n"
            "    RealMF _rmf = p1->fn ? ((ThunkMF)p1->fn)() : 0;\n"
            "    if (_rmf) iVar5 = _rmf((struct P *)((char *)p1 + p1->adj), iVar5, local_20, sVar2);",
        )

    if unit == "mo_spell":
        # Watcom 12-Byte-Memberfunktionszeiger-Layout in struct S (f0e an +0x0e) und d_1bf378[n]
        text = text.replace(
            "typedef void (S::*MPF)();",
            "struct MPF { FP2 fn; int off; int zero; };",
        )
        text = text.replace(
            "    p->mp = d_1bf378[n];\n"
            "    (p->*(p->mp))();",
            "    p->mp = d_1bf378[n];\n"
            "    if (p->mp.fn) { FP _fp = p->mp.fn(p); if (_fp) _fp((char *)p + p->mp.off); }",
        )

    if unit == "spell":
        # Watcom 12-Byte-Memberfunktionszeiger-Layout in Host10ce80 und d_1c042c_cb[p2]
        text = text.replace(
            "struct Host10ce80;\n"
            "typedef void (Host10ce80::*Cb10ce80)();\n"
            "struct Host10ce80 { char prefix[6]; Cb10ce80 callback; };",
            "typedef void (*SpellRealFn)(void *);\n"
            "typedef SpellRealFn (*SpellThunkFn)(void *);\n"
            "struct Cb10ce80 { SpellThunkFn fn; int off; int zero; };\n"
            "struct Host10ce80 { char prefix[6]; Cb10ce80 callback; };",
        )
        text = text.replace(
            "          Host10ce80 *caster = (Host10ce80 *)p1;\n"
            "          caster->callback = d_1c042c_cb[p2];\n"
            "          (caster->*caster->callback)();",
            "          Host10ce80 *caster = (Host10ce80 *)p1;\n"
            "          caster->callback = d_1c042c_cb[p2];\n"
            "          if (caster->callback.fn) { SpellRealFn _sfn = caster->callback.fn(caster); if (_sfn) _sfn((char *)caster + caster->callback.off); }",
        )

    if unit == "gz_1340e0":
        # 12-Byte-Methodenzeiger-Layout in DGROUP (d_1c0e8c) beibehalten
        text = text.replace(
            "typedef void (Handler134492::*Method134492)();",
            "struct Method134492 {\n"
            "    void (Handler134492::*m)();\n"
            "    int pad;\n"
            "    Method134492() {}\n"
            "    Method134492(int) : m(0), pad(0) {}\n"
            "    Method134492(void (Handler134492::*p)()) : m(p), pad(0) {}\n"
            "};",
        )
        # Unter GCC legt f_1343c0 direkte Funktionszeiger (nicht Watcom-Thunks) in d_1c0e8c ab;
        # direkter Aufruf vermeidet zudem den Itanium-ABI Bit-0-Vtable-Check bei ungeraden Funktionsadressen.
        text = text.replace(
            "    GM &mf = *(GM *)&p->f;\n"
            "    mf = *(GM *)((E *)&d_1c0e8c + k);\n"
            "    (((GC *)p)->*mf)();",
            "    E *_e = (E *)&d_1c0e8c + k;\n"
            "    p->f = _e->f; p->off = _e->off; p->x = _e->x;\n"
            "    if (p->f) ((void (*)(G *))((void *)p->f))((G *)((char *)p + p->off));",
        )
        text = text.replace(
            "      E *e = (E *)&d_1c0e8c + r;\n"
            "      p = (G *)((char *)p + e->off);\n"
            "      slot.cb = e->f((int)p);\n"
            "      slot.cb((int)p);",
            "      E *e = (E *)&d_1c0e8c + r;\n"
            "      p = (G *)((char *)p + e->off);\n"
            "      if (e->f) ((void (*)(int))((void *)e->f))((int)p);",
        )

    if unit == "equip":
        text = text.replace(
            "extern volatile short d_1bc5f6;",
            'extern volatile short d_1bc5f6;\nextern "C" void riva_pump_timers_and_events(void);',
        )
        text = text.replace("while(!d_1bc5f6);", "while(!d_1bc5f6) riva_pump_timers_and_events();")
        text = text.replace("while (!d_1bc5f6) ;", "while (!d_1bc5f6) riva_pump_timers_and_events();")

    if unit == "editor2":
        # f_061b10 wird als Placement-Konstruktor aufgerufen (s45 ? f_061b10(s45, ...) : s45)
        # und muss unter GCC explizit this in EAX zurueckgeben.
        text = text.replace(
            " f_061b10(short n, short w, short x, short y, int p5, char *p6, short p7); };\n"
            "f_061b10::f_061b10(short n, short w, short x, short y, int p5, char *p6, short p7)\n"
            "{",
            " f_061b10 *init(short n, short w, short x, short y, int p5, char *p6, short p7); };\n"
            'extern "C" f_061b10 *f_061b10_ctor(f_061b10 *self, short n, short w, short x, short y, int p5, char *p6, short p7) __asm__("_f_061b10");\n'
            'extern "C" f_061b10 *f_061b10_ctor(f_061b10 *self, short n, short w, short x, short y, int p5, char *p6, short p7) { return self->init(n, w, x, y, p5, p6, p7); }\n'
            "f_061b10 *f_061b10::init(short n, short w, short x, short y, int p5, char *p6, short p7)\n"
            "{\n"
            "    this->r = R1320();",
        )
        text = text.replace(
            "    } else\n        this->r.a = 0xffff;\n}",
            "    } else\n        this->r.a = 0xffff;\n    return this;\n}",
        )

    if unit == "final2":
        text = text.replace(
            "X08e300::X08e300() : B05ff60(11) { }",
            'extern "C" int _vt_1baf38 __asm__("_d_1baf38"); extern "C" void *f_05ff60_real(void *, int) __asm__("_f_05ff60");\n'
            'extern "C" void *f_08e300_real(void *p1) __asm__("_f_08e300");\n'
            'extern "C" void *f_08e300_real(void *p1) { char *r = (char *)f_05ff60_real(p1, 11); *(void **)(r + 8) = &_vt_1baf38; return r; }',
        )

    if unit == "sewerag3":
        text = text.replace(
            "X0f7260::X0f7260() : B05ff60(3) { }   // Konstruktor, setzt vtable; erzeugt $dt:X0f7260 als COMDAT am Modulende (= f_0faba0)",
            'extern "C" int _vt_1bb71c __asm__("_d_1bb71c"); extern "C" void *f_05ff60_real(void *, int) __asm__("_f_05ff60");\n'
            'extern "C" void *f_0f7260_real(void *p1) __asm__("_f_0f7260");\n'
            'extern "C" void *f_0f7260_real(void *p1) { char *r = (char *)f_05ff60_real(p1, 3); *(void **)(r + 8) = &_vt_1bb71c; return r; }',
        )

    if unit == "ship2":
        text = text.replace(
            "X1034b0::X1034b0() : B0fb5f0(0x18) { }   // Konstruktor, setzt vtable; erzeugt $dt:X1034b0 als COMDAT am Modulende (= f_107280)",
            'extern "C" int _vt_1bb7d4 __asm__("_d_1bb7d4"); extern "C" void *f_0fb5f0_real(void *, int) __asm__("_f_0fb5f0");\n'
            'extern "C" void *f_1034b0_real(void *p1) __asm__("_f_1034b0");\n'
            'extern "C" void *f_1034b0_real(void *p1) { char *r = (char *)f_0fb5f0_real(p1, 0x18); *(void **)(r + 8) = &_vt_1bb7d4; return r; }',
        )

    if unit == "tower2":
        text = text.replace(
            "X12c5b0::X12c5b0() : B05ff60(0x14) { }   // Konstruktor, setzt vtable; erzeugt $dt:X12c5b0 als COMDAT am Modulende (= f_12ea30)",
            'extern "C" int _vt_1bbb94 __asm__("_d_1bbb94"); extern "C" void *f_05ff60_real(void *, int) __asm__("_f_05ff60");\n'
            'extern "C" void *f_12c5b0_real(void *p1) __asm__("_f_12c5b0");\n'
            'extern "C" void *f_12c5b0_real(void *p1) { char *r = (char *)f_05ff60_real(p1, 0x14); *(void **)(r + 8) = &_vt_1bbb94; return r; }',
        )

    if unit == "star2":
        # 12-Byte-Methodenzeiger-Layout in DGROUP (d_1a7caa..d_1a7d54) beibehalten
        text = text.replace(
            "X118e60::X118e60() : B115630(8) { }   // Konstruktor, setzt vtable; erzeugt $dt:X118e60 als COMDAT am Modulende (= f_11a880)",
            'extern "C" void *f_115630_real(void *, int) __asm__("_f_115630");\n'
            'extern "C" void *f_118e60_real(void *p1) __asm__("_f_118e60");\n'
            'extern "C" void *f_118e60_real(void *p1) { char *r = (char *)f_115630_real(p1, 8); *(void **)(r + 8) = &d_1bb98c; return r; }',
        )
        text = text.replace(
            "typedef void (StarMember492::*StarMethod492)();",
            "struct StarMethod492 {\n"
            "    void (StarMember492::*m)();\n"
            "    int pad;\n"
            "    StarMethod492() {}\n"
            "    StarMethod492(int) : m(0), pad(0) {}\n"
            "    StarMethod492(void (StarMember492::*p)()) : m(p), pad(0) {}\n"
            "};",
        )
        text = text.replace(
            "                    struct QB *qb = (struct QB *)&entry->fb;\n"
            "                    object = qb->off + p1;\n"
            "                    call = qb->fn(object);\n"
            "                    accepted = call(object, entry->a, value);",
            "                    struct QB *qb = (struct QB *)&entry->fb;\n"
            "                    object = qb->off + p1;\n"
            "                    call = (FPI3)(void *)qb->fn;\n"
            "                    accepted = call(object, entry->a, value);",
        )
        text = text.replace(
            "                    struct QA *qa = (struct QA *)&entry->fa;\n"
            "                    object = p1 + qa->off;\n"
            "                    call = (FPI3)qa->fn(object);\n"
            "                    ((FPV)call)(object);",
            "                    struct QA *qa = (struct QA *)&entry->fa;\n"
            "                    object = p1 + qa->off;\n"
            "                    call = (FPI3)(void *)qa->fn;\n"
            "                    ((FPV)call)(object);",
        )

    if unit == "cdaudio_t1":
        text = text.replace("Msf(Msf &o)", "Msf(const Msf &o)")
        text = text.replace("Msf operator-(Msf &b)", "Msf operator-(const Msf &b)")

    if unit == "debug":
        text = text.replace('extern "C" int exit(int code);', "/* exit in stdlib.h */")

    if unit in ("fz_148170", "gz_0d0350"):
        text = text.replace(
            'extern "C" unsigned long _lrotr(unsigned long, unsigned int);',
            "/* _lrotr in stdlib.h */",
        )

    if unit == "fz_15689d_t3a1":
        text = text.replace(
            "static RivaIntVector *(*keep_15c500)(RivaIntVector *) = Z15c500::f_15c500;",
            "/* keep_15c500 removed */",
        )

    if unit == "fz_167f60_t2":
        text = text.replace("f_1696b8(p4, p3, p2)", "f_1696b8((void **)p4, p3, p2)")

    if unit == "fz_145760_t2":
        text = text.replace(
            "    unsigned short a;\n    short b, c, d;",
            "    unsigned int a = 0x220;\n    int b = 7, c = 1, d = 0xe016;",
        )

    if unit == "gz_03f060_t1":
        text = text.replace(
            "char pcx[164];",
            "char pcx[164]; char _img_local[16]; if ((unsigned)img < 0x10000u) img = (int)_img_local;",
        )
        text = text.replace(
            "void picture492(const char*);",
            'void f_03f060(const char *name, int img); static inline void picture492(const char *s) { char _b[16]; f_03f060(s, (int)_b); }',
        )
        text = text.replace(
            "void f_03f170() {",
            'extern "C" char *getenv(const char *); void f_03f170() { const char *_sk = getenv("RIVA_SKIP_INTRO"); if (_sk && _sk[0] == \'1\') return;',
        )

    if unit == "gz_060aa0":
        text = text.replace(
            "int f_05e2a0(void *, int *, int *, int *, int *);",
            "int f_05e2a0(void *, short *, short *, short *, short *);",
        )

    if unit == "gz_0f25c0_t2":
        text = text.replace("int f_0bbf00(int,int);", "/* hidden overload removed */")

    if unit == "hyperhlp_t3":
        text = text.replace("int f_15da8c(int, char **);", "struct P f_15da8c(int);")

    if unit == "import_error":
        text = text.replace("int f_14d0e4();", "int f_14d0e4(const char *, ...);")

    if unit == "fightovl":
        top_defs.append('extern "C" int f_0fb0b0(...);')

    if unit == "import_saveload":
        text = text.replace("int f_148143();", "int f_148143(...);")
        text = text.replace("int f_155f70();", "int f_155f70(...);")
        text = text.replace("int f_164880();", "int f_164880(...);")

    if unit == "itemdist_t3":
        text = text.replace("int f_1404e0(int p1, int p2, int p3);", "int f_1404e0(int p1);")

    if unit == "game_neu":
        text = text.replace("extern const short d_1a28ec[6] = {1000, 100, 300, 100, 0, 0};", "extern const short d_1a28ec[6];")

    if unit == "gz_0da510_t1":
        text = text.replace("int f_0141d0(char *p);", "int f_0141d0(char *p, int e);")
        text = text.replace("int f_0141e0(char *p);", "int f_0141e0(char *p, int b, int c);")
        text = text.replace("virtual short v23();", "virtual short v23(int e);")
        text = text.replace("return f_013db0ext(p);", "return f_013db0(p, e);")
        text = text.replace("short s = p->v23();", "short s = p->v23(e);")
        text = text.replace("else f_0141d0(p);", "else f_0141d0(p, e);")
        text = text.replace(
            "int f_0da820(char *p)\n{\n    SEL(f_144e8b(*(int *)(p + 0x8c)), f_0141e0(p))\n}",
            "int f_0da820(char *p, int b, int c)\n{\n    SEL(f_144e8b(*(int *)(p + 0x8c), b, c), f_0141e0(p, b, c))\n}",
        )

    if unit == "gz_013da0_t1":
        text = text.replace("void f_0141d0(void *buf); void f_0141e0(void *buf, unsigned n);", "int f_0141d0(void *buf); int f_0141e0(void *buf, unsigned n);")
        text = text.replace("void AlfDisk::f_0141d0(void *buf) { f_144e8b(fd, buf, e62.n); }", "int AlfDisk::f_0141d0(void *buf) { return f_144e8b(fd, buf, e62.n); }")
        text = text.replace("void AlfDisk::f_0141e0(void *buf, unsigned n) {", "int AlfDisk::f_0141e0(void *buf, unsigned n) {")
        text = text.replace("  f_144e8b(fd, buf, rem);\n}", "  return f_144e8b(fd, buf, rem);\n}")

    if unit == "fz_148570":
        text = text.replace("void f_1489d0(int p, int buf)", "int f_1489d0(int p, int buf)")
        text = text.replace("  f_144e8b(I(p,4), (void *)buf, n);\n}", "  return f_144e8b(I(p,4), (void *)buf, n);\n}")
        text = text.replace("void f_148a20(int p, int buf, int n)", "int f_148a20(int p, int buf, int n)")
        text = text.replace("  f_144e8b(I(p,4), (void *)b, n);\n}", "  return f_144e8b(I(p,4), (void *)b, n);\n}")
        text = text.replace("void f_148a60(int p, int buf, int n)", "int f_148a60(int p, int buf, int n)")
        text = text.replace("  f_144cb6(I(p,4), (void *)b, n);\n}", "  return f_144cb6(I(p,4), (void *)b, n);\n}")

    # Watcom 1-Slot virtuelle Destruktoren & Konstruktor-this-Rueckgaben fuer GCC Itanium ABI anpassen
    if unit == "cache":
        text = text.replace("virtual ~FAb();", "virtual void v0(int fl);")
        text = text.replace("virtual ~FB();", "virtual void v0(int fl);")
        text = text.replace("delete fa;", "if (fa) fa->v0(3);")
        text = text.replace("void f_0256c0(C *p, short n, int sz)", "C *f_0256c0(C *p, short n, int sz)")
        text = text.replace("    p->f10 = sz;\n}", "    p->f10 = sz;\n    return p;\n}")

    if unit == "gz_0257f0":
        text = text.replace("virtual ~FRb();", "virtual void v0(int fl);")
        text = text.replace("virtual ~FAb();", "virtual void v0(int fl);")
        text = text.replace("if (f4) { delete f4; f4 = 0; }", "if (f4) { f4->v0(3); f4 = 0; }")
        text = text.replace("if (f0) { delete f0; f0 = 0; }", "if (f0) { f0->v0(3); f0 = 0; }")

    if unit == "hyperhlp_t3":
        text = text.replace("struct VB { virtual ~VB();", "struct VB { virtual void v0(int fl);")
        text = text.replace("delete d_1bde40;", "if (d_1bde40) d_1bde40->v0(3);")
        text = text.replace("delete d_1bde3c;", "if (d_1bde3c) d_1bde3c->v0(3);")

    if unit == "chapter":
        text = text.replace("virtual ~Win();", "int vptr; void v0(int fl) { ((void (*)(void *, int))(*(int *)vptr))(this, fl); }")
        text = text.replace("struct WinDel { virtual ~WinDel() {} };\n    delete (WinDel *)win;", "if (win) win->v0(3);")
        text = text.replace("struct WinDel { virtual ~WinDel() {} };\n        delete (WinDel *)win;", "if (win) win->v0(3);")

    if unit in ("fz_144090_rand910a", "fz_144090_rand910b"):
        text = text.replace("struct V6 { short a, b, c; virtual ~V6(); };", "struct V6 { short a, b, c; int vptr; void v0(int fl) { ((void (*)(void *, int))(*(int *)vptr))(this, fl); } };")
        text = text.replace("delete d_1be17c;", "if (d_1be17c) d_1be17c->v0(3);")

    if unit == "location":
        text = text.replace(
            "struct LocBase : LocPad {\n  virtual void v0();\n  virtual void v1();\n  virtual void v2();\n  virtual ~LocBase();\n};",
            "struct LocBase : LocPad {\n  int vptr;\n  void v3(int fl) { ((void (*)(void *, int))(*(int *)(vptr + 0x0c)))(this, fl); }\n};",
        )
        text = text.replace("delete (LocBase *)d_1bf1ac;", "if (d_1bf1ac) ((LocBase *)d_1bf1ac)->v3(3);")
        text = text.replace("void f_0b8ef0(int p)", "int f_0b8ef0(int p)")
        text = text.replace("  f_0b3950(a, W16(p, 0x40 + c * 2) * 0x1518);\n}", "  return f_0b3950(a, W16(p, 0x40 + c * 2) * 0x1518);\n}")

    if unit == "boron2_t1":
        text = text.replace(
            "    virtual short v0(int a, int b);",
            "    int vptr;\n    short v0(int a, int b) { return ((short (*)(void *, int, int))(*(int *)vptr))(this, a, b); }",
        )

    if unit == "tdmcolli_neu":
        text = text.replace(
            "    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();\n"
            "    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();\n"
            "    virtual void v9(int n);",
            "    int vptr;\n    void v9(int n) { ((void (*)(void *, int))(*(int *)(vptr + 0x24)))(this, n); }",
        )
        text = text.replace(
            "    if (d_1bd6c4 != 0) {",
            "    dsa_platform_run_pending_3d_actions();\n    if (d_1bd6c4 != 0) {",
        )

    if unit == "fz_145760_t1d":
        text = text.replace(
            " virtual int m0(); virtual int m4(); virtual int m8(); virtual int mC(); virtual int m10();\n"
            " virtual int m14(int, short = 0x200); virtual int m18(); virtual int m1C();\n"
            " virtual int m20(void *, int); virtual int m24(); virtual int m28();\n"
            " virtual int m2C(); virtual int m30(); virtual int m34(int);\n"
            " virtual int m38(); virtual int m3C(); virtual int m40(int, int);",
            " int vptr;\n"
            " int m14(int a, short b = 0x200) { return ((int (*)(void *, int, int))(*(int *)(vptr + 0x14)))(this, a, b); }\n"
            " int m20(void *a, int b) { return ((int (*)(void *, void *, int))(*(int *)(vptr + 0x20)))(this, a, b); }\n"
            " int m28() { return ((int (*)(void *))(*(int *)(vptr + 0x28)))(this); }\n"
            " int m34(int a) { return ((int (*)(void *, int))(*(int *)(vptr + 0x34)))(this, a); }\n"
            " int m40(int a, int b) { return ((int (*)(void *, int, int))(*(int *)(vptr + 0x40)))(this, a, b); }",
        )

    if unit == "fz_145760_t2":
        text = text.replace(
            "    virtual void v00(); virtual void v04(); virtual void v08();\n"
            "    virtual void v0c(); virtual void v10();\n"
            "    virtual int open(int, short);\n"
            "    virtual void v18(); virtual void v1c();\n"
            "    virtual int read(void *, int);\n"
            "    virtual void v24(); virtual void close();",
            "    int vptr;\n"
            "    int open(int a, short b) { return ((int (*)(void *, int, int))(*(int *)(vptr + 0x14)))(this, a, b); }\n"
            "    int read(void *a, int b) { return ((int (*)(void *, void *, int))(*(int *)(vptr + 0x20)))(this, a, b); }\n"
            "    void close() { ((void (*)(void *))(*(int *)(vptr + 0x28)))(this); }",
        )
        text = text.replace(
            "    virtual void v00(); virtual void v04(); virtual void v08();\n"
            "    virtual void v0c(); virtual void v10();\n"
            "    virtual int open(int, short);\n"
            "    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();\n"
            "    virtual void release(); virtual void v2c(); virtual unsigned length();",
            "    int vptr;\n"
            "    int open(int a, short b) { return ((int (*)(void *, int, int))(*(int *)(vptr + 0x14)))(this, a, b); }\n"
            "    void release() { ((void (*)(void *))(*(int *)(vptr + 0x28)))(this); }\n"
            "    unsigned length() { return ((unsigned (*)(void *))(*(int *)(vptr + 0x30)))(this); }",
        )

    if unit == "gz_01e240":
        text = text.replace("void f_01e240(AL *p1, unsigned short p2, CMPF p3, CPYF p4, LENF p5)", "AL *f_01e240(AL *p1, unsigned short p2, CMPF p3, CPYF p4, LENF p5)")
        text = text.replace("    p1->len = p5;\n}", "    p1->len = p5;\n    return p1;\n}")

    if unit == "char_opt":
        text = text.replace("void f_03f390(int p1, int p2)", "int f_03f390(int p1, int p2)")
        text = text.replace("  *(short *)p1 = (short)p2;\n}", "  *(short *)p1 = (short)p2;\n  return p1;\n}")

    if unit == "diary3_gz059a10":
        text = text.replace("void f_059d50(void)\n{\n}", "int f_059d50(int p)\n{\n    return p;\n}")

    if unit == "gz_0a2400_t2":
        text = text.replace("void f_0a2800(void)\n{\n}", "int f_0a2800(int p)\n{\n    return p;\n}")

    if unit == "gz_0e04f0_t2":
        text = text.replace("void f_0e0680(int *p, int v)", "int *f_0e0680(int *p, int v)")
        text = text.replace("    p[2] = d_1a34e0;\n}", "    p[2] = d_1a34e0;\n    return p;\n}")

    if unit == "gz_1099f0_t3":
        text = text.replace("void f_10a940(int p1)", "int f_10a940(int p1)")
        text = text.replace("    *(int *)(p1 + 0x22) = 0;\n}", "    *(int *)(p1 + 0x22) = 0;\n    return p1;\n}")
        text = text.replace("void f_10a260(int p1, int p2)", "int f_10a260(int p1, int p2)")
        text = text.replace("    *(int *)(r + 0x58) = (int)d_1bb890;\n}", "    *(int *)(r + 0x58) = (int)d_1bb890;\n    return r;\n}")

    if unit == "fz_145760_t1c2":
        text = text.replace(
            "void f_1459b0(RivaAifImage *p)\n{ p->f = (RivaFileStream *)&d_1c2098; p->c27 = p->c28 = p->c26 = 0; }",
            "RivaAifImage *f_1459b0(RivaAifImage *p)\n{ p->f = (RivaFileStream *)&d_1c2098; p->c27 = p->c28 = p->c26 = 0; return p; }",
        )

    if unit == "fz_147cd0":
        text = text.replace("void f_147cd0(P *p)", "P *f_147cd0(P *p)")
        text = text.replace("    p->s260 = 0;\n}", "    p->s260 = 0;\n    return p;\n}")
        text = text.replace("int f_169c3a(int p1);", "int f_169c3a(int p1, int p2);")
        text = text.replace("int f_147f00(int p1, int p2, int p3) { return f_169c3a(p3); }", "int f_147f00(int p1, int p2, int p3) { return f_169c3a(p3, p2); }")

    if unit == "xdialog_t3":
        text = text.replace("void f_142f70(int p1, int p2, int p3)", "int f_142f70(int p1, int p2, int p3)")
        text = text.replace("    W32(p1, 0xaf) = 0;\n}", "    W32(p1, 0xaf) = 0;\n    return p1;\n}")

    if unit == "gz_0fa9b0":
        text = text.replace("void f_0fabf0(Q *p)", "Q *f_0fabf0(Q *p)")
        text = text.replace("    p->b = 0;\n}", "    p->b = 0;\n    return p;\n}")

    if unit == "gz_02d9c0_t3":
        text = text.replace("void f_02de80(int p1, int p2)", "int f_02de80(int p1, int p2)")
        text = text.replace("    *(int *)(r + 0x58) = (int)&d_1bac4c;\n}", "    *(int *)(r + 0x58) = (int)&d_1bac4c;\n    return r;\n}")

    if unit == "gz_038ba0_t1":
        text = text.replace("void f_038d70(int p1, int p2)", "int f_038d70(int p1, int p2)")
        text = text.replace("void f_038e10(int p1, int p2)", "int f_038e10(int p1, int p2)")
        text = text.replace("void f_038e90(int p1, int p2)", "int f_038e90(int p1, int p2)")
        text = text.replace("  f_038f20(p1, p2, (int)sVar4, (int)sVar1, 0);\n}", "  return f_038f20(p1, p2, (int)sVar4, (int)sVar1, 0);\n}")

    if unit == "gz_05dec0":
        text = text.replace("void Text::f_05e170() {", "void *Text::f_05e170() {")
        text = text.replace("void f_05e170();", "void *f_05e170();")
        text = text.replace("  se = 0;\n}", "  se = 0;\n  return this;\n}")

    if unit == "hyperhlp_t1":
        text = text.replace("void f_09db60(void)\n{\n    VC(d_1be0bc, 0x30, FP1)(d_1be0bc);\n}", "int f_09db60(void)\n{\n    return ((int (*)(int))(*(int *)(*(int *)d_1be0bc + 0x30)))(d_1be0bc);\n}")

    if unit == "gz_0b5dc0_t2":
        text = text.replace("void f_0b8520(int p)\n{\n  I32(p, 0x58) = (int)d_1bb248;\n}", "int f_0b8520(int p)\n{\n  I32(p, 0x58) = (int)d_1bb248;\n  return p;\n}")

    if unit == "gz_0dc9a0_tc":
        text = text.replace("void f_0dd480(int p1)", "int f_0dd480(int p1)")
        text = text.replace("    f_1511ec(p1_00, p2);\n}", "    return f_1511ec(p1_00, p2);\n}")

    if unit == "gz_0e93f0_t1":
        text = text.replace("void f_0e9670(int p1, int p2, int p3, int p4)\n{\n  f_05e770(p1, p2, (short)p3, (short)p4);\n}", "int f_0e9670(int p1, int p2, int p3, int p4)\n{\n  return f_05e770(p1, p2, (short)p3, (short)p4);\n}")

    if unit == "gz_1155d0":
        text = text.replace("void f_115640(int p1, int p2)", "int f_115640(int p1, int p2)")
        text = text.replace("  f_060030(p1);\n}", "  f_060030(p1);\n  return p1;\n}")

    if unit == "diskmen2_t1":
        text = text.replace("int f_0de930(void *o);", "int f_0de930(void *o, int a);")
        text = text.replace("f_0de930(d_1c0004);", "f_0de930(d_1c0004, 1);")

    if unit == "gz_010010":
        text = text.replace("*(unsigned char *)0x417 &= 0xf0;", "/* BIOS Data Area 0x417 im Windows-Port neutralisiert */")

    if unit == "gz_096790":
        text = text.replace('extern const char gen4_file[44] = "p:\\\\riva\\\\source\\\\cpp\\\\gen4.cpp";', 'extern const char d_1a3408[];\n#define gen4_file d_1a3408')

    if unit == "amap_t12":
        text = text.replace("    S(0x0b) = 0;\n    S(0x0d) = 0;", '    S(0x0b) = 0;\n    __asm__ __volatile__("nop");\n    S(0x0d) = 0;')
        text = text.replace("    S(0x1f) = 0;\n    S(0x21) = 0;", '    S(0x1f) = 0;\n    __asm__ __volatile__("nop");\n    S(0x21) = 0;')

    if unit == "amap_t345":
        text = text.replace("    s5 = 0; s7 = 0; s9 = 0; sb = 0;", '    s5 = 0; s7 = 0; __asm__ __volatile__("nop"); s9 = 0; sb = 0;')
        text = text.replace("    s17 = -1; s19 = -1;", '    s17 = -1; __asm__ __volatile__("nop"); s19 = -1;')
        text = text.replace("    g2b = 0; g2f = 0; t33 = 0; d37 = 0;", '    g2b = 0; g2f = 0; __asm__ __volatile__("nop"); t33 = 0; d37 = 0;')
        text = text.replace("i43 = 0; i47 = 0;", 'i43 = 0; __asm__ __volatile__("nop"); i47 = 0;')
        text = text.replace("    im53[0] = 0;\n    i73 = 0;", '    im53[0] = 0;\n    __asm__ __volatile__("nop");\n    i73 = 0;')
        text = text.replace("    wf1 = 0; wf3 = 0;", '    wf1 = 0; __asm__ __volatile__("nop"); wf3 = 0;')
        text = text.replace("    i0f9 = 0;\n    fd = 0;", '    i0f9 = 0;\n    __asm__ __volatile__("nop");\n    fd = 0;')
        text = text.replace("    i105 = 0;\n    s109 = 0;", '    i105 = 0;\n    __asm__ __volatile__("nop");\n    s109 = 0;')
        text = text.replace("    s140 = 0;\n    s142 = 0;", '    s140 = 0;\n    __asm__ __volatile__("nop");\n    s142 = 0;')

    if unit == "attic_rest_1227b0":
        text = text.replace("  p1[4] = 0;\n  p1[5] = 0;", '  p1[4] = 0;\n  __asm__ __volatile__("nop");\n  p1[5] = 0;')

    if unit == "cache":
        text = text.replace("p->f14 = 0; p->f18 = 0;", 'p->f14 = 0; __asm__ __volatile__("nop"); p->f18 = 0;')
        text = text.replace("p->f29 = 0; p->f2d = 0;", 'p->f29 = 0; __asm__ __volatile__("nop"); p->f2d = 0;')

    if unit in ("gfx_t2a", "gfx_t2c"):
        text = text.replace("  S(p1+0xc) = 0;\n  I(p1+0xe) = 0;", '  S(p1+0xc) = 0;\n  __asm__ __volatile__("nop");\n  I(p1+0xe) = 0;')

    if unit == "gz_05dec0":
        text = text.replace("  s10 = 0;\n  s12 = 0;", '  s10 = 0;\n  __asm__ __volatile__("nop");\n  s12 = 0;')

    if unit == "gz_0d0350":
        text = text.replace("    *(short *)(p1 + 0xd0) = 0;\n    *(short *)(p1 + 0xd2) = 0;", '    *(short *)(p1 + 0xd0) = 0;\n    __asm__ __volatile__("nop");\n    *(short *)(p1 + 0xd2) = 0;')

    if unit == "xdialog_t3":
        text = text.replace("    W32(p1, 0x45) = 0;\n    W32(p1, 0x49) = 0;", '    W32(p1, 0x45) = 0;\n    __asm__ __volatile__("nop");\n    W32(p1, 0x49) = 0;')
        text = text.replace("    W32(p1, 0x59) = 0;\n    W32(p1, 0x61) = 0;", '    W32(p1, 0x59) = 0;\n    __asm__ __volatile__("nop");\n    W32(p1, 0x61) = 0;')
        text = text.replace("    W16(p1, 0x6f) = -1;\n    W16(p1, 0x71) = -1;", '    W16(p1, 0x6f) = -1;\n    __asm__ __volatile__("nop");\n    W16(p1, 0x71) = -1;')
        text = text.replace("    W32(p1, 0x9f) = 0;\n    W32(p1, 0xa3) = 0;", '    W32(p1, 0x9f) = 0;\n    __asm__ __volatile__("nop");\n    W32(p1, 0xa3) = 0;')

    if unit == "gz_0beff0":
        text = text.replace("  ap = (char *)&d + 4;", "  va_start(ap, d);")
        text = text.replace("  ap = (char *)&c + 4;", "  va_start(ap, c);")

    if top_defs:
        text = "\n".join(top_defs) + "\n" + text
    if bottom_defs:
        text = text + "\n" + "\n".join(bottom_defs) + "\n"

    return apply_port_fixes(text, unit)


def apply_port_fixes(text: str, unit: str) -> str:
    """Bewahrt gepruefte Portkorrekturen bei jedem frischen Quellenlauf.

    Kontext muss exakt passen: geaenderte Ausgangsquellen werden nicht still
    mit einem veralteten Patch vermischt. Die Patches enthalten nur Quelltext.
    """
    patch = PORT_DIR / "patches" / (unit + ".patch")
    if not patch.exists():
        return text
    source = text.splitlines(keepends=True)
    # Wie die Eingabequellen bytegetreu via latin1 lesen; UTF-8-Kommentare
    # duerfen beim Kontextvergleich keine andere Dekodierung erhalten.
    lines = patch.read_bytes().decode("latin1").splitlines(keepends=True)
    result = []
    cursor = 0
    i = 2  # --- und +++
    while i < len(lines):
        match = re.match(r"@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@", lines[i])
        if not match:
            raise ValueError(f"Ungueltiger Portpatch {patch}, Zeile {i + 1}")
        start = int(match[1]) - 1
        old, new = [], []
        i += 1
        while i < len(lines) and not lines[i].startswith("@@ "):
            line = lines[i]
            if line[0] in " -":
                old.append(line[1:])
            if line[0] in " +":
                new.append(line[1:])
            if line[0] not in " +-":
                raise ValueError(f"Ungueltige Patchzeile in {patch}")
            i += 1
        if (start < cursor or len(old) != int(match[2] or 1) or
                len(new) != int(match[4] or 1) or source[start:start + len(old)] != old):
            raise ValueError(f"Portpatch {patch} passt nicht mehr ab Quellzeile {start + 1}")
        result.extend(source[cursor:start])
        result.extend(new)
        cursor = start + len(old)
    result.extend(source[cursor:])
    return "".join(result)


def write_compat_headers():
    SRC_INC.mkdir(parents=True, exist_ok=True)

    (SRC_INC / "watcom_compat.h").write_text(
        """#ifndef WATCOM_COMPAT_H
#define WATCOM_COMPAT_H

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

/* Watcom-Modifikatoren fuer GCC/Clang/MSVC neutralisieren, damit alle
   Spiel-Einheiten einheitlich die Standard-Aufrufkonvention nutzen. */
#ifndef __far
#define __far
#endif
#ifndef _far
#define _far
#endif
#ifndef __near
#define __near
#endif
#ifndef _near
#define _near
#endif
#ifndef __interrupt
#define __interrupt
#endif
#ifndef _interrupt
#define _interrupt
#endif
#ifndef __loadds
#define __loadds
#endif
#ifndef __watcall
#define __watcall
#endif
#ifndef __based
#define __based(x)
#endif
#ifndef __segment
#define __segment unsigned short
#endif

#ifndef _disable
#define _disable() ((void)0)
#endif
#ifndef _enable
#define _enable() ((void)0)
#endif

/* Vereinheitliche __pascal und __stdcall im Spielcode auf __cdecl */
#ifdef __pascal
#undef __pascal
#endif
#define __pascal

#ifdef __stdcall
#undef __stdcall
#endif
#define __stdcall

#ifndef FP_SEG
#define FP_SEG(p) ((unsigned short)(((uintptr_t)(p) >> 16) & 0xFFFF))
#endif
#ifndef FP_OFF
#define FP_OFF(p) ((unsigned int)(uintptr_t)(p))
#endif
#ifndef MK_FP
#define MK_FP(seg, off) ((void *)(((uintptr_t)(seg) << 4) + (uintptr_t)(off)))
#endif

#ifdef __cplusplus
extern "C" {
#endif
unsigned char *port_get_vram(void);
int port_inp(unsigned port);
int port_outp(unsigned port, int val);
unsigned short port_bios_keybrd(unsigned cmd);
void port_sound(unsigned freq);
void port_nosound(void);
void dsa_platform_run_pending_3d_actions(void);
#ifdef __cplusplus
}
#endif

/* Original-Compilerflag -zp1: 1-Byte-Struktur-Packing fuer alle Spielstrukturen */
#pragma pack(1)

#endif /* WATCOM_COMPAT_H */
""",
        encoding="utf-8",
    )

    (SRC_INC / "i86.h").write_text(
        """#ifndef PORT_I86_H
#define PORT_I86_H

#include "watcom_compat.h"

#pragma pack(push, 1)
struct DWORDREGS {
    unsigned int eax, ebx, ecx, edx, esi, edi, cflag;
};
struct WORDREGS {
    unsigned short ax, _1, bx, _2, cx, _3, dx, _4, si, _5, di, _6;
    unsigned int cflag;
};
struct BYTEREGS {
    unsigned char al, ah, _1, _2, bl, bh, _3, _4, cl, ch, _5, _6, dl, dh, _7, _8;
};
union REGS {
    struct DWORDREGS x;
    struct DWORDREGS e;
    struct WORDREGS w;
    struct BYTEREGS h;
};
struct SREGS {
    unsigned short es, cs, ss, ds, fs, gs;
};
#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif
int f_149cd2(int intno, void *in, void *out);
int f_145702(int intno, void *in, void *out, void *sregs);
void f_149caa(void *sregs);
#ifndef int386
#define int386(n, in, out) f_149cd2(n, in, out)
#endif
#ifndef int386x
#define int386x(n, in, out, s) f_145702(n, in, out, s)
#endif
#ifndef segread
#define segread(s) f_149caa(s)
#endif
#ifndef sound
#define sound(f) port_sound(f)
#endif
#ifndef nosound
#define nosound() port_nosound()
#endif
#ifdef __cplusplus
}
#endif

#endif /* PORT_I86_H */
""",
        encoding="utf-8",
    )

    (SRC_INC / "bios.h").write_text(
        """#ifndef PORT_BIOS_H
#define PORT_BIOS_H

#include "watcom_compat.h"

#define _KEYBRD_READ        0
#define _KEYBRD_READY       1
#define _KEYBRD_SHIFTSTATUS 2

#define _PRINTER_WRITE      0
#define _PRINTER_INIT       1
#define _PRINTER_STATUS     2

#ifndef _bios_keybrd
#define _bios_keybrd(cmd) port_bios_keybrd(cmd)
#endif

#ifndef _bios_printer
#define _bios_printer(cmd, port, data) ((unsigned)0x90)
#endif

#endif /* PORT_BIOS_H */
""",
        encoding="utf-8",
    )

    (SRC_INC / "dos.h").write_text(
        """#ifndef PORT_DOS_H
#define PORT_DOS_H

#include "i86.h"

#pragma pack(push, 1)
struct find_t {
    char reserved[21];
    char attrib;
    unsigned short wr_time;
    unsigned short wr_date;
    unsigned long size;
    char name[13];
};
#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
struct diskfree_t {
    unsigned short total_clusters;
    unsigned short avail_clusters;
    unsigned short sectors_per_cluster;
    unsigned short bytes_per_sector;
};
#endif
struct dosdate_t {
    unsigned char day;
    unsigned char month;
    unsigned short year;
    unsigned char dayofweek;
};
struct dostime_t {
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
    unsigned char hsecond;
};
#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif
void *f_15e114(unsigned intno);
void f_15e0e7(unsigned intno, void *handler);
void f_15e97a(void *handler);
#ifndef _dos_getvect
#define _dos_getvect(n) ((VEC)f_15e114(n))
#endif
#ifndef _dos_setvect
#define _dos_setvect(n, h) f_15e0e7(n, (void *)(h))
#endif
#ifndef _chain_intr
#define _chain_intr(h) f_15e97a((void *)(h))
#endif
#ifdef __cplusplus
}
#endif

#endif /* PORT_DOS_H */
""",
        encoding="utf-8",
    )

    (SRC_INC / "conio.h").write_text(
        """#ifndef PORT_CONIO_H
#define PORT_CONIO_H

#include "watcom_compat.h"

#ifndef inp
#define inp(p) port_inp(p)
#endif
#ifndef outp
#define outp(p, v) port_outp(p, v)
#endif
#ifndef cputs
#define cputs(s) fputs((s), stdout)
#endif

#endif /* PORT_CONIO_H */
""",
        encoding="utf-8",
    )


def extract_pragma_aliases(text: str) -> dict[str, str]:
    """Extrahiert #pragma aux <ident> "<target>" Zuordnungen fuer den COFF-Symbol-Normalisierer."""
    aliases = {}
    skip = {
        "call_149caa", "call_05da10", "shift_date", "call_125f70", "call_125ed0",
        "riva_15c3f0", "aux_0bf820", "call_13d570_2", "f_1265c0_x",
        "call650_133890", "call650_1337c0", "f_05e360_ecx", "bankcall30_A20T",
    }
    for l in text.splitlines():
        s = l.strip()
        if not s.startswith("#pragma") or "aux" not in s or "=" in s:
            continue
        m = re.match(r'^#\s*pragma\s+aux\s+(?:\([^)]+\)\s+)?([A-Za-z_][A-Za-z0-9_]*)\s+"([^"]+)"', s)
        if m:
            ident, target = m.group(1), m.group(2)
            if ident in skip or target in ("*", "_*"):
                continue
            mt = re.search(r"([fd]_[0-9a-fA-F]{6})", target)
            if mt:
                aliases[ident] = "_" + mt.group(1).lower()
    return aliases


def main():
    bounds = load_unit_bounds()
    SRC_CPP.mkdir(parents=True, exist_ok=True)
    SRC_INC.mkdir(parents=True, exist_ok=True)

    # 1. Kopiere Original-Header aus GitHub_Vorbereitung/riva/Quelle/inc nach Port/src/inc
    for h in sorted((GH_QUELLE / "inc").iterdir()):
        if h.is_file():
            shutil.copy2(h, SRC_INC / h.name)
            shutil.copy2(h, SRC_INC / h.name.upper())
            shutil.copy2(h, SRC_INC / h.name.lower())

    write_compat_headers()

    # 2. Kopiere und bereite alle 571 Einheiten + verfügbare C++-Anker vor
    total_removed = 0
    unit_aliases = {}
    manifest = []

    cpp_files = sorted((GH_QUELLE / "cpp").glob("*_P1.CPP"))
    anchor_sources = {
        "gz_0d451f_t1": REPO_ROOT / "Quelle" / "cpp" / "p3" / "gz_0d451f_t1_P1.CPP",
        "fz_17c708_t3": REPO_ROOT / "Quelle" / "cpp" / "p1" / "fz_17c708_t3_P1.CPP",
        "fz_17e4a0_t2": REPO_ROOT / "Quelle" / "cpp" / "p3" / "fz_17e4a0_t2_P1.CPP",
        "fz_199700_t1": REPO_ROOT / "Quelle" / "cpp" / "p3" / "fz_199700_t1_P1.CPP",
        "fz_199700_t2": REPO_ROOT / "Quelle" / "cpp" / "p3" / "fz_199700_t2_P1.CPP",
    }
    all_sources = [(p.name[:-7], p) for p in cpp_files]
    for au, ap in anchor_sources.items():
        if ap.exists():
            all_sources.append((au, ap))

    for unit, src_path in all_sources:
        lo, hi = bounds.get(unit, (0, 0xFFFFFF))
        raw_text = src_path.read_text(encoding="latin1")
        aliases = extract_pragma_aliases(raw_text)
        if aliases:
            unit_aliases[unit] = aliases

        cleaned, rem = strip_out_of_bounds_functions(raw_text, unit, lo, hi)
        total_removed += rem
        transformed = transform_watcom_constructs(cleaned, unit)

        dst_path = SRC_CPP / f"{unit}_P1.CPP"
        dst_path.write_text(transformed, encoding="latin1")
        manifest.append(dict(unit=unit, lo=lo, hi=hi, file=f"{unit}_P1.CPP", oob_removed=rem))

    (SRC_DIR / "manifest.json").write_text(
        json.dumps(dict(units=manifest, aliases=unit_aliases), indent=2),
        encoding="utf-8",
    )
    print(f"Prepared {len(manifest)} units in {SRC_CPP} (removed {total_removed} out-of-bounds duplicate functions).")


if __name__ == "__main__":
    main()
