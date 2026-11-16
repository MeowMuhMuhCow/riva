/* === Beschreibung (Katalog) ===
 * Einheit gz_13bb70_t2 (0x13D490 - 0x13E140)
 *
 * Überblick
 *
 * Die Einheit gz_13bb70_t2 enthält grundlegende 2D-Grafik-, Speicher- und VESA-BIOS-Hilfsfunktionen der Engine.
 * Sie umfasst das Rechteck-Clipping für Zeichenoperationen, die DPMI-Allokation und -Freigabe von unterem
 * DOS-Speicher (unterhalb von 1 MB) für Real-Mode-BIOS-Aufrufe, das zeilenweise Kopieren von Bildpuffern mit und
 * ohne Transparenzmaskierung sowie die Abfrage, Diagnoseausgabe und Zustandssicherung des
 * VESA-VBE-Grafiktreibers über Software-Interrupt 0x10 bzw. DPMI-Interrupt 0x31 (0x0300).
 === Ende Beschreibung === */
// P3 12/17 gleich (suche.py 26.10.2026, Basis gz_13bb70_t2_P1.CPP)
// gz_13bb70_t2.cpp - Pass 1, Code 0x13D490-0x13E140 (Helfer C)
#include "R_FIX.H"
#include <i86.h>
union Regs {
    struct { unsigned eax, ebx, ecx, edx, esi, edi, cflag; } e;
    struct { unsigned short ax, ax_, bx, bx_, cx, cx_, dx, dx_, si, si_, di, di_, cflag, cflag_; } x;
    struct { unsigned char al, ah, a2, a3, bl, bh, b2, b3, cl, ch, c2, c3, dl, dh, d2, d3; } h;
};
struct SR { unsigned short es, cs, ss, ds, fs, gs; };
struct RM { unsigned edi, esi, ebp, res, ebx, edx, ecx, eax; unsigned short flags, es, ds, fs, gs, ip, cs, sp, ss; };
void *f_145300(void *p, int c, unsigned n);
void *f_14d075(void *d, const void *s, unsigned n);
int f_145702(int p1, void *p2, void *p3, void *p4);
int f_14d0e4(const char *fmt, ...);
extern union Regs d_1c1080, d_1c10a8;
extern struct SR d_1c109c, d_1c10c4;
extern struct RM d_1c10d0;
extern unsigned char d_1c1110;
extern unsigned char *d_1c1104, *d_1c1108;
extern unsigned d_1c1114, d_1c1150;
extern int d_1c1154;
extern const char d_1b8538[], d_1b8552[], d_1b8569[], d_1b8579[], d_1b857c[], d_1b857e[], d_1b859b[], d_1b85ab[], d_1b85b1[], d_1b85c2[], d_1b85c4[];
extern const char d_1b85dc[], d_1b85f0[], d_1b8604[], d_1b8618[], d_1b862c[], d_1b8640[], d_1b8654[], d_1b8668[], d_1b867c[], d_1b8690[], d_1b86a4[], d_1b86b8[], d_1b86cc[], d_1b86e0[], d_1b86f4[];
char f_13dbb0(short v);
static unsigned pick_13deb0(unsigned b) { return b; }
#pragma aux pick_13deb0 parm [edx] value [edx] modify exact [];
//@ f_13d490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beschneidet ein zu zeichnendes Quellrechteck (p2) und die zugehörige Zielposition (p3) an den
 *   Grenzen eines gültigen Clipping-Rechtecks (p1), sodass nachfolgende Blit-Routinen nicht über den Bildrand
 *   hinauszeichnen. Liegt das Zielrechteck vollständig außerhalb des sichtbaren Bereichs, gibt die Funktion 0
 *   zurück; andernfalls korrigiert sie Startkoordinaten sowie Breite und Höhe und liefert 1.
 * - Eingaben: Zeiger p1 auf das Begrenzungsrechteck (x0, y0, x1, y1), Zeiger p2 auf das Quellrechteck (x, y, w,
 *   h) und Zeiger p3 auf den Zielpunkt (x, y).
 * - Rückgabewert: 1, wenn nach dem Beschneiden noch eine sichtbare Fläche übrig bleibt, sonst 0.
 * - Wichtige Variablen:
 *   - a, b: Rechts- und Unterkante des unbeschnittenen Zielrechtecks (p3->x + p2->w - 1 bzw. p3->y + p2->h - 1).
 *   - c: Differenzbetrag, um den eine überstehende Kante gekürzt werden muss.
 === Ende Beschreibung === */
int f_13d490(short *p1, short *p2, short *p3, short *p4, short *p5)
{
    int r;
    short xe, ye; xe = *p2 + *p4 + -1; ye = *p3 + *p5 + -1;
    if (*p2 > p1[2]) {
        r = 0;
    } else {
        if (xe < *p1) return 0;
        if (*p3 > p1[3]) return 0;
        if (ye < p1[1]) return 0;
        if (p1[2] < xe)
            *p4 -= xe - p1[2];
        if (ye > p1[3])
            *p5 -= ye - p1[3];
        if (*p2 < *p1) {
            *p4 -= *p1 - *p2;
            *p2 = *p1;
        }
        if (*p3 < p1[1]) {
            *p5 -= p1[1] - *p3;
            *p3 = p1[1];
        }
        r = 1;
    }
    return r;
}
//@ f_13d570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Reserviert über den DPMI-Aufruf AX = 0x0100 (Interrupt 0x31) einen Block im unteren
 *   DOS-Konventionalspeicher (unterhalb von 1 MB), damit VESA-BIOS-Funktionen im Real Mode Datenstrukturen darin
 *   ablegen können. Rechnet die Bytegröße p1 in 16-Byte-Paragraphen um und gibt bei Erfolg die lineare Adresse
 *   (Segment << 4) zurück.
 * - Eingaben: Gewünschte Blockgröße p1 in Bytes (unsigned int).
 * - Rückgabewert: Lineare Adresse des DOS-Speicherblocks (r.x.ax << 4) oder 0, falls beim DPMI-Aufruf das
 *   Carry-Flag (r.x.cflag) gesetzt wurde.
 * - Wichtige Variablen:
 *   - r: Lokale Registerstruktur (REGS) für den Aufruf von int386x(0x31, ...).
 *   - sr: Lokale Segmentregisterstruktur (SREGS), die vor dem Aufruf mit Nullen initialisiert wird.
 === Ende Beschreibung === */
unsigned f_13d570(int n)
{
    union Regs r;
    struct SR sr;
    f_145300(&sr, 0, 12);
    r.x.ax = 0x100;
    r.x.bx = (n + 15) >> 4;
    f_145702(0x31, &r, &r, &sr);
    if (r.e.cflag == 0) return r.x.ax << 4; return 0;
}
//@ f_13d5d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt einen zuvor mit f_13d570 reservierten DOS-Speicherblock an der linearen Adresse p1 über
 *   den DPMI-Aufruf AX = 0x0101 (Interrupt 0x31) wieder frei (enthält jedoch zwei Originalfehler: vertauschte
 *   memset-Argumente f_145300(&d_1c109c, 12, 0) und Übergabe des Real-Mode-Segments p1 >> 4 statt des
 *   DPMI-Selektors in DX).
 * - Eingaben: Lineare Adresse p1 des DOS-Speicherblocks (unsigned int).
 * - Rückgabewert: 0, wenn das Carry-Flag gesetzt ist (Fehler), sonst 1.
 * - Wichtige Variablen:
 *   - d_1c1080, d_1c109c: Globale Register- und Segmentregisterstrukturen für den DPMI-Aufruf.
 === Ende Beschreibung === */
void f_13d5d0(unsigned p1)
{
#if FIX_R001   /* R001: memset-Argumente (Fuellwert 0, Laenge 12) bei d_1c109c waren vertauscht */
    f_145300(&d_1c109c, 0, 12);
#else
    f_145300(&d_1c109c, 12, 0);
#endif
    d_1c1080.x.dx = p1 >> 4;
    d_1c1080.x.ax = 0x101;
    f_145702(0x31, &d_1c1080, &d_1c1080, &d_1c109c);
}
//@ f_13d620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen rechteckigen Bildausschnitt der Breite p3 und Höhe p4 zeilenweise ohne
 *   Transparenzprüfung über memcpy (f_1452d0) aus einem Quellpuffer p1 (Zeilenbreite p5) in einen Zielpuffer p2
 *   (Zeilenbreite p6).
 * - Eingaben: Quellzeiger p1, Zielzeiger p2, Breite p3, Höhe p4, Quell-Pitch p5 und Ziel-Pitch p6.
 * - Rückgabewert: Der um p4 Zeilen weitergerückte Zielzeiger (int).
 * - Wichtige Variablen:
 *   - a: Schleifenzähler über die p4 zu kopierenden Bildzeilen.
 === Ende Beschreibung === */
void f_13d620(char *p1, char *p2, short p3, short p4, short p5, short p6)
{
    char *dst = p2;
    short i = 0;
    while (i < p4) {
        f_14d075(dst, p1, p3);
        p1 += p5;
        dst += p6;
        i++;
    }
}
//@ f_13d670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen rechteckigen Bildausschnitt der Breite p3 und Höhe p4 mit Transparenzmaskierung
 *   aus dem Quellpuffer p1 (Zeilenbreite p5) in den Zielpuffer p2 (Zeilenbreite p6), indem für jede Zeile die
 *   transparente Kopierroutine f_13d6d0 mit dem Farbwert p7 als Transparenzfarbe aufgerufen wird.
 * - Eingaben: Quellzeiger p1, Zielzeiger p2, Breite p3, Höhe p4, Quell-Pitch p5, Ziel-Pitch p6 und transparente
 *   Farbkennung p7 (char).
 * - Rückgabewert: Der um p4 Zeilen weitergerückte Zielzeiger (int).
 * - Wichtige Variablen:
 *   - a: Schleifenzähler über die p4 Bildzeilen.
 === Ende Beschreibung === */
void f_13d670(char *p1, short p2, short p3, short p4, unsigned char p5)
{
    char *dst = p1;
    short i = 0;
    while (i < p3) {
        f_145300(dst, (*&p5), (*&p2));
        dst += p4;
        i++;
    }
}
//@ f_13d6b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert eine einzelne Pixelzeile der Länge p3 ohne Transparenzprüfung von p1 nach p2.
 * - Eingaben: Quellzeiger p1, Zielzeiger p2 und Byteanzahl p3.
 * - Rückgabewert: Rückgabewert von f_1452d0 (memcpy).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13d6b0(char *p1, char *p2, unsigned n, char key)
{
    char *dst = p2;
    char *e = dst;
    if (n > 0) {
        e += n;
        do {
            if (key != *p1) *dst = *p1;
            dst++;
            p1++;
        } while (dst < e);
    }
}
//@ f_13d6d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert eine einzelne Pixelzeile der Länge p3 von p1 nach p2, überspringt dabei alle
 *   Quellpixel mit der transparenten Farbe p4 und fasst zusammenhängende nicht-transparente Pixelsequenzen zu
 *   schnellen Blockkopien (f_1452d0) zusammen.
 * - Eingaben: Quellzeiger p1, Zielzeiger p2, Zeilenlänge p3 und transparente Farbe p4 (char).
 * - Rückgabewert: Der bis zum Zeilenende vorgerückte Quellzeiger (int).
 * - Wichtige Variablen:
 *   - a: Laufender Zähler für die Länge des aktuellen zusammenhängenden Blocks sichtbarer Pixel.
 === Ende Beschreibung === */
void f_13d6d0(char *p1, char *p2, int p3, short p4, short p5, short p6, char key)
{
    char *dst_base = p2;
    short i;
    i = 0;
    char *src_base = p1;
    if (i < p4) goto again;
    return;
again:
    {
        int n = (short)p3;
        if ((unsigned)n > 0) goto copy;
    }
step:
        i++;
        src_base += p5;
        dst_base += p6;
        if (i >= p4) return;
        goto again;
copy:
    {
        char k = key;
        char *src = src_base;
        char *dst = dst_base;
        char *end = dst_base + (short)p3;
        do {
            if (k != *src) *dst = *src;
            dst++;
            src++;
        } while (dst < end);
    }
    goto step;
}
//@ f_13d740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über den DPMI-Real-Mode-Interrupt-Simulator (AX = 0x0300 an Interrupt 0x31, simulierter
 *   Interrupt 0x10) die VESA-VBE-Controller-Informationen (AX = 0x4F00) ab und kopiert den 512 Byte großen
 *   Info-Block aus dem unteren DOS-Speicher in die globale Struktur d_1c10b0 (enthält einen harmlosen
 *   Originalfehler: f_145300(&d_1c10d0, 0, 0x32) wird unmittelbar hintereinander zweimal aufgerufen).
 * - Eingaben: Keine.
 * - Rückgabewert: 1, wenn der VESA-Aufruf AX == 0x004F zurückliefert und die Signatur "VESA"
 *   (f_147120(&d_1c10b0, "VESA", 4) == 0) im Puffer steht, sonst 0.
 * - Wichtige Variablen:
 *   - a: Lineare Adresse des temporär im unteren DOS-Speicher (f_13d570(0x200)) angelegten 512-Byte-Puffers.
 *   - d_1c10d0: 50-Byte-DPMI-Real-Mode-Call-Struktur (ES = a >> 4, EAX = 0x4F00).
 === Ende Beschreibung === */
char f_13d740(void)
{
    if (d_1c1110 == 1) return 1;
    d_1c1104 = (unsigned char *)f_13d570(0x200);
    d_1c1108 = (unsigned char *)f_13d570(0x102);
    f_145300(d_1c1104, 0, 0x200);
    f_145300(d_1c1104 + 0x100, 0xff, 0x100);
    f_145300(d_1c1108, 0, 0x102);
#if FIX_R002   /* R002: Redundanten doppelten memset-Aufruf auf d_1c10d0 vermeiden */
    f_145300(&d_1c10d0, 0, 0x32);
#else
    f_145300(&d_1c10d0, 0, 0x32);
    f_145300(&d_1c10d0, 0, 0x32);
#endif
    d_1c10d0.eax = 0x4f00;
    d_1c10d0.edi = 0;
    d_1c10a8.x.ax = 0x300;
    d_1c10d0.es = (unsigned)d_1c1104 >> 4;
    d_1c10a8.h.bl = 0x10; d_1c10a8.h.bh = 0;
    d_1c10a8.x.cx = 0;
    d_1c10c4.es = FP_SEG(&d_1c10d0);
    d_1c10a8.e.edi = FP_OFF(&d_1c10d0);
    f_145702(0x31, &d_1c10a8, &d_1c10a8, &d_1c10c4);
    if ((d_1c10d0.eax & 0xffff) == 0x4f) { // 16-Bit-Maske fuer AX-Pruefung wie im Originalcode
        d_1c1114 = *(unsigned short *)(d_1c1108 + 8) << 4;
        d_1c1110 = 1;
    } else {
        d_1c1110 = 0;
    }
    return d_1c1110;
}
//@ f_13d920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob ein VESA-kompatibles Grafik-BIOS vorhanden ist, und gibt auf der Textkonsole
 *   detaillierte Diagnoseinformationen zur VESA-Version (d_1c10b4), zum OEM-Herstellerstring (d_1c10b6), zum
 *   Videospeicher (d_1c10c2 * 64 KB) sowie zu allen unterstützten Grafikmodi aus der Modusliste (d_1c10be) aus.
 * - Eingaben: Keine.
 * - Rückgabewert: 0, wenn kein VESA-Treiber gefunden wurde, sonst der Rückgabewert des abschließenden
 *   printf-Aufrufs (f_145858).
 * - Wichtige Variablen:
 *   - c: Lineare Adresse des 512-Byte-DOS-Puffers für den VbeInfoBlock.
 *   - a: Umrechnung eines Real-Mode-Far-Pointers (Seg:Off) in eine lineare Speicheradresse (((ptr >> 16) << 4) +
 *     (ptr & 0xFFFF)), genutzt für den OEM-String und die Modusliste b.
 === Ende Beschreibung === */
void f_13d920(void)
{
    if (d_1c1104) {
        f_13d5d0((unsigned)d_1c1104);
        d_1c1104 = 0;
    }
    if (d_1c1108) {
        f_13d5d0((unsigned)d_1c1108);
        d_1c1108 = 0;
    }
    if (d_1c1150) {
        unsigned c = d_1c1150;
#if FIX_R001   /* R001: memset-Argumente (Fuellwert 0, Laenge 12) bei d_1c109c waren vertauscht */
        f_145300(&d_1c109c, 0, 12);
#else
        f_145300(&d_1c109c, 12, 0);
#endif
        unsigned n = 0;
        d_1c1080.x.ax = 0x101;
        d_1c1080.x.dx = c >> 4;
        f_145702(0x31, &d_1c1080, &d_1c1080, &d_1c109c);
        d_1c1150 = n;
    }
}
//@ f_13da20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet bei initialisiertem VESA-Treiber (d_1c1110 == 1) aus dem im VBE-Info-Block
 *   (d_1c1104) bei Offset +6 (Offset) und +8 (Segment) hinterlegten Real-Mode-Far-Pointer die lineare
 *   Speicheradresse des OEM-Herstellerstrings.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Lineare Adresse des VESA-OEM-Strings (*(unsigned short *)(d_1c1104 + 6) + *(unsigned short
 *   *)(d_1c1104 + 8) * 16) oder 0, falls VESA nicht aktiv ist.
 * - Wichtige Variablen:
 *   - d_1c1110: Globales VESA-Initialisierungsflag (1 = VBE-Info-Block gültig).
 *   - d_1c1104: Zeiger auf den 512-Byte-DOS-Puffer mit dem VESA-Controller-Infoblock (VbeInfoBlock).
 === Ende Beschreibung === */
int f_13da20(void)
{
    if (d_1c1110 == 1)
        return *(unsigned short *)(d_1c1104 + 6) + *(unsigned short *)(d_1c1104 + 8) * 0x10;
    return 0;
}
//@ f_13da50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die im VESA-Controller-Infoblock (d_1c1104) gespeicherten Diagnoseinformationen
 *   formatiert über f_14d0e4 aus, darunter die 4-Byte-Signatur ("VESA"), die Haupt- und Nebenversion (+4), den
 *   zeichenweise ausgegebenen OEM-Herstellerstring (+6/+8), die 4 Capabilities-Bytes (+10..+13) sowie sämtliche
 *   unterstützten VESA-Modusnummern (aus der 0xFFFF-terminierten Liste bei +14/+16, jeweils 10 Modi pro Zeile).
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Lineare Adresse des OEM-Strings ((*(unsigned short *)(d_1c1104 + 8) << 4) + *(unsigned short
 *     *)(d_1c1104 + 6)).
 *   - ms: Lineare Adresse der VESA-Modusliste ((*(unsigned short *)(d_1c1104 + 16) << 4) + *(unsigned short
 *     *)(d_1c1104 + 14)).
 *   - v, n: Aktuelle Modusnummer aus der Liste (bis 0xFFFF) und Spaltenzähler für den Zeilenumbruch nach je 10
 *     Einträgen.
 === Ende Beschreibung === */
void f_13da50(void)
{
    unsigned char *s;
    unsigned short *ms, v, n;
    f_14d0e4(d_1b8538, d_1c1104[0], d_1c1104[1], d_1c1104[2], d_1c1104[3]);
    f_14d0e4(d_1b8552, *(short *)(d_1c1104 + 4) >> 8, (short)(*(short *)(d_1c1104 + 4) & 0xff)); // 8-Bit-Maske fuer VBE-Minor-Version wie im Originalcode
    s = (unsigned char *)((*(unsigned short *)(d_1c1104 + 8) << 4) + *(unsigned short *)(d_1c1104 + 6));
    f_14d0e4(d_1b8569);
    unsigned c;
    while ((c = *s) != 0) {
        f_14d0e4(d_1b8579, c);
        s++;
    }
    f_14d0e4(d_1b857c);
    f_14d0e4(d_1b857e, d_1c1104[10], d_1c1104[11], d_1c1104[12], d_1c1104[13]);
    f_14d0e4(d_1b859b);
    ms = (unsigned short *)((*(unsigned short *)(d_1c1104 + 16) << 4) + *(unsigned short *)(d_1c1104 + 14));
    v = *ms;
    n = 0;
    ms++;
    while (v != 0xffff) {
        ms++;
        n++;
        f_14d0e4(d_1b85ab, v);
        v = ms[-1];
        if (n == 10) {
            f_14d0e4(d_1b85b1);
            n = 0;
        }
    }
    f_14d0e4(d_1b85c2);
}
//@ f_13dba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kurzer Wrapper, der die VESA-Modusabfrage für die übergebene Modusnummer a direkt an
 *   f_13dbb0(a) weiterleitet.
 * - Eingaben: VESA-Modusnummer a (short).
 * - Rückgabewert: 1 bei erfolgreicher Modusabfrage, sonst 0 (char).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
char f_13dba0(short a)
{
    return f_13dbb0(a);
}
//@ f_13dbb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt bei initialisiertem VESA-Treiber (d_1c1110 == 1) über den DPMI-Real-Mode-Interrupt 0x31
 *   (AX = 0x0300, simulierter INT 0x10 mit EAX = 0x4F01, ECX = v) die VESA-Mode-Info-Struktur für den
 *   Grafikmodus v in den unteren DOS-Puffer d_1c1108 (ES = d_1c1108 >> 4, EDI = 0) ab und merkt bei Erfolg ((EAX
 *   & 0xFFFF) == 0x004F) die abgefragte Modusnummer in *(short *)(d_1c1108 + 0x100).
 * - Eingaben: VESA-Modusnummer v (short).
 * - Rückgabewert: 1, wenn das VESA-BIOS AX == 0x004F meldet, sonst 0 (char).
 * - Wichtige Variablen:
 *   - ok: Rückgabeflag (0 oder 1).
 *   - d_1c10d0: 50-Byte-DPMI-Real-Mode-Aufrufstruktur.
 *   - d_1c1108: 258-Byte-DOS-Puffer für den 256-Byte-ModeInfoBlock plus gemerkte Modusnummer bei +0x100.
 === Ende Beschreibung === */
char f_13dbb0(short v)
{
    char ok = 0;
    if (d_1c1110 == 1) {
        f_145300(&d_1c10d0, 0, 0x32);
        d_1c10d0.eax = 0x4f01;
        d_1c10d0.ecx = v;
        d_1c10d0.edi = 0; d_1c10d0.es = (unsigned)d_1c1108 >> 4; d_1c10a8.x.ax = 0x300; d_1c10a8.x.cx = 0;
        d_1c10a8.h.bl = 0x10;
        d_1c10a8.h.bh = 0;
        d_1c10c4.es = FP_SEG(&d_1c10d0);
        d_1c10a8.e.edi = FP_OFF(&d_1c10d0);
        f_145702(0x31, &d_1c10a8, &d_1c10a8, &d_1c10c4);
        if ((d_1c10d0.eax & 0xffff) == 0x4f) { // 16-Bit-Maske fuer AX-Pruefung wie im Originalcode
            ok = 1;
            *(short *)(d_1c1108 + 0x100) = v;
        }
    }
    return ok;
}
//@ f_13dc90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft f_13dbb0(v) auf, um den VESA-ModeInfoBlock für Modus v in d_1c1108 zu laden, und gibt
 *   entweder eine Fehlermeldung (d_1b85c4) oder 15 einzelne Strukturfelder des Modus (Modusattribute,
 *   Fensterattribute A/B, Granularität, Fenstergröße, Segmente A/B, Bytes pro Scanline, horizontale/vertikale
 *   Auflösung, Zeichenzellenbreite/-höhe, Planes, Bits pro Pixel und Bankanzahl) formatiert über f_14d0e4 aus.
 * - Eingaben: VESA-Modusnummer v (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c1108: Puffer mit den 256 Bytes der VESA-ModeInfoBlock-Struktur.
 === Ende Beschreibung === */
void f_13dc90(short v)
{
    if (!f_13dbb0(v)) {
        f_14d0e4(d_1b85c4, v);
    } else {
        f_14d0e4(d_1b85dc, *(short *)d_1c1108);
        f_14d0e4(d_1b85f0, d_1c1108[2]);
        f_14d0e4(d_1b8604, d_1c1108[3]);
        f_14d0e4(d_1b8618, *(short *)(d_1c1108 + 4));
        f_14d0e4(d_1b862c, *(short *)(d_1c1108 + 6));
        f_14d0e4(d_1b8640, *(unsigned short *)(d_1c1108 + 8));
        f_14d0e4(d_1b8654, *(unsigned short *)(d_1c1108 + 10));
        f_14d0e4(d_1b8668, *(unsigned short *)(d_1c1108 + 16));
        f_14d0e4(d_1b867c, *(short *)(d_1c1108 + 18));
        f_14d0e4(d_1b8690, *(short *)(d_1c1108 + 20));
        f_14d0e4(d_1b86a4, d_1c1108[24]);
        f_14d0e4(d_1b86b8, d_1c1108[25]);
        f_14d0e4(d_1b86cc, d_1c1108[26]);
        f_14d0e4(d_1b86e0, d_1c1108[27]);
        f_14d0e4(d_1b86f4, d_1c1108[28]);
    }
}
//@ f_13de50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt einen zuvor mit f_13de00 bzw. f_13deb0 gesicherten VESA-Grafikzustand aus dem
 *   DOS-Puffer p1 über f_13df90 wieder her und gibt anschließend den DOS-Speicherblock p1 über f_13d5d0 frei.
 * - Eingaben: Lineare Adresse p1 des gesicherten DOS-Zustandspuffers (unsigned int).
 * - Rückgabewert: 1 bei erfolgreicher Wiederherstellung, sonst 0.
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_13de50(void)
{
    d_1c10a8.x.ax = 0x300;
    d_1c10a8.h.bl = 0x10;
    d_1c10a8.x.cx = 0;
    d_1c10a8.h.bh = 0;
    d_1c10c4.es = FP_SEG(&d_1c10d0);
    d_1c10a8.e.edi = FP_OFF(&d_1c10d0);
    f_145702(0x31, &d_1c10a8, &d_1c10a8, &d_1c10c4);
}
//@ f_13deb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sichert den kompletten VESA-SVGA-Hardwarezustand (CX = 0x0F) über den DPMI-Real-Mode-Interrupt
 *   0x10 (AX = 0x4F04, DL = 0x01) in den übergebenen DOS-Speicherpuffer p1 (ES = p1 >> 4, BX = 0).
 * - Eingaben: Lineare Adresse p1 des Zielpuffers im unteren DOS-Speicher (unsigned int).
 * - Rückgabewert: 1, wenn AL == 0x4F gemeldet wird, sonst 0.
 * - Wichtige Variablen:
 *   - d_1c10d0: Globale 50-Byte-Struktur für den simulierten Real-Mode-Interrupt 0x10.
 === Ende Beschreibung === */
void f_13deb0(void)
{
    union Regs r;
    struct SR s;
    if (d_1c1110 == 1) {
        if (!d_1c1150) {
            f_145300(&d_1c10d0, 0, 0x32);
            d_1c10d0.eax = 0x4f04;
            d_1c10d0.ecx = 0xf;
            d_1c10d0.edx = 0;
            d_1c10a8.x.ax = 0x300;
            d_1c10a8.h.bl = 0x10;
            d_1c10a8.h.bh = 0;
            d_1c10a8.x.cx = 0;
            d_1c10c4.es = FP_SEG(&d_1c10d0);
            d_1c10a8.e.edi = FP_OFF(&d_1c10d0);
            f_145702(0x31, &d_1c10a8, &d_1c10a8, &d_1c10c4);
            if ((d_1c10d0.eax & 0xffff) == 0x4f) { // 16-Bit-Maske fuer AX-Pruefung wie im Originalcode
                int sz = (short)(d_1c10d0.ebx << 6);
                f_145300(&s, 0, 0xc);
                r.x.ax = 0x100;
                r.x.bx = (sz + 15) >> 4;
                f_145702(0x31, &r, &r, &s);
                d_1c1150 = pick_13deb0((r.e.cflag == 0) ? (unsigned)r.x.ax << 4 : 0);
            } else {
                return;
            }
        }
        f_145300(&d_1c10d0, 0, 0x32);
        d_1c10d0.eax = 0x4f04;
        d_1c10d0.ecx = 0xf;
        d_1c10d0.edx = 1;
        d_1c10d0.ebx = 0;
        d_1c10d0.es = d_1c1150 >> 4;
        d_1c10a8.x.ax = 0x300;
        d_1c10a8.h.bl = 0x10;
        d_1c10a8.h.bh = 0;
        d_1c10a8.x.cx = 0;
        d_1c10c4.es = FP_SEG(&d_1c10d0);
        d_1c10a8.e.edi = FP_OFF(&d_1c10d0);
        f_145702(0x31, &d_1c10a8, &d_1c10a8, &d_1c10c4);
        d_1c1154 = 1;
    }
}
//@ f_13e080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Grafik- oder Textmodus über das Standard-VGA-BIOS (INT 0x10, AH = 0x00, AL = p1) und
 *   liest anschließend über AH = 0x0F den tatsächlich aktivierten BIOS-Videomodus wieder aus.
 * - Eingaben: Gewünschte BIOS-Videomodusnummer p1 (char, z. B. 0x03 für den 80x25-Textmodus).
 * - Rückgabewert: Die vom BIOS gemeldete aktive Modusnummer (r.h.al, vorzeichenerweitert auf int).
 * - Wichtige Variablen:
 *   - r: Lokale Registerstruktur (REGS) für die beiden Aufrufe von int386(0x10, &r, &r).
 === Ende Beschreibung === */
void f_13e080(void)
{
    if (d_1c1154 == 1) {
        f_145300(&d_1c10d0, 0, 0x32);
        d_1c10d0.eax = 0x4f04; d_1c10d0.ecx = 0xf; d_1c10d0.edx = 2; d_1c10d0.ebx = 0;
        d_1c10d0.es = d_1c1150 >> 4;
        d_1c10a8.x.ax = 0x300;
        d_1c10a8.h.bl = 0x10;
        d_1c10a8.h.bh = 0;
        d_1c10a8.x.cx = 0;
        d_1c10c4.es = FP_SEG(&d_1c10d0);
        d_1c10a8.e.edi = FP_OFF(&d_1c10d0);
        f_145702(0x31, &d_1c10a8, &d_1c10a8, &d_1c10c4);
        d_1c1154 = 0;
    }
}
