/* === Beschreibung (Katalog) ===
 * Einheit gz_0a6280 (0a6280-0a7610)
 *
 * Überblick
 * Diese letzte Einheit des ersten Katalogdrittels enthält zwei Systemkomponenten: im ersten Teil (f_0a6280 bis
 * f_0a6740) das grafische Texteingabefeld-Steuerelement (struct S), das den Bildschirmhintergrund unter jedem
 * Zeichenfeld sichert und Tastatureingaben mit Unterstrich-Cursor verarbeitet, und im zweiten Teil (f_0a6a30 bis
 * f_0a7600) die Low-Level-DOS-/DPMI-Interrupt- und Fehlerbehandlung (Speichersperre über Int 0x31,
 * Timer-Interrupt 0x1c, Tastatur-Interrupt 0x09 mit Abfangen von Strg+C / Strg+Pause / Pause sowie den
 * grafischen Critical-Error-Handler f_0a7240 für Laufwerks- und CD-ROM-Fehler).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// P3 30/32 gleich (suche.py 29.10.2026, Basis gz_0a6280_P1.CPP)
// OPT -4r -onatx -zp1 -s
// P1 14/27 gleich
// gz_0a6280.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A6280-0x0A7610
#include <string.h>
#include <dos.h>
#include <conio.h>
#include <bios.h>
#include <stdlib.h>
#include <i86.h>
#pragma intrinsic(strlen)
int f_0100c0(void);
int f_045df0(int p1, int p2);
int f_05ebd0(int p1, int p2, int p3, int p4);
int f_09a990(int p1, int p2);


int f_0d37b0();

int f_0d3870();
int f_0d4800(int p1);
int f_0e4380(int p1, int p2);





int f_1261b0(int p1);
int f_13d5d0(int p1);
int f_13e690(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_13eab0(int p1, int p2, int p3, int p4);
int f_13f8c0();
int f_144570(int p1, int p2, int p3);
unsigned char f_1453b0(int p1);
unsigned char f_145400(int p1);
int f_149cf0();
int f_149d20();
int f_149dfe(int p1, int p2, int p3, int p4);
void f_149e2e(void *p1, int p2);
#pragma aux f_149e2e parm caller [] modify exact [ecx edx];
int f_149eb4();
int f_149cd2(int p1, void *p2, void *p3);
int f_15dc98(int p1, void *p2);
union MYREGS {
    struct { unsigned eax, ebx, ecx, edx, esi, edi, cflag; } x;
    struct { unsigned short ax, _1, bx, _2, cx, _3, dx, _4, si, _5, di, _6, cflag; } w;
    struct { unsigned char al, ah, _1[2], bl, bh; } h;
};
struct RGB { char r, g, b; };
typedef void (__interrupt __far *VEC)();
extern int d_1a34e0;
extern int d_1bc950;
extern short d_1bc604;
extern volatile short d_1bc5f6;
extern short d_1bd75e;
extern int d_1bd766;
extern volatile int d_1bd76c;
extern int d_1bd90c;
extern short d_1be1b0;
extern short d_1be1b4;
extern short d_1be1b6;
extern short d_1be1b8;
extern short d_1be1ba;
extern VEC d_1be1bc;
extern VEC d_1be1c4;
extern short d_1be1d2;
extern short d_1be1d4;
extern short d_1be1d6;
extern int d_1be1d8;
extern int d_1be1dc;
extern volatile int d_1be1e0;
extern unsigned int d_1be1e4[5];
extern unsigned int d_1be20c[5];
extern short d_1be234;
extern int d_1be23c;
extern int d_1be240;
extern int d_1be244;
extern volatile short d_1be248;
extern volatile short d_1be24a;
extern signed char d_1bf234[7];
extern signed char d_1bf4e8;
extern short d_1bfa6c;
extern volatile short d_1c016c;
extern short d_1c20f4;
extern short d_1c20f6;
extern short d_1c219a;
extern short d_1c219e;
extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c3078;
extern int d_1c38b0;
extern volatile int d_1c3914;
extern char d_0101db[];
extern char d_1a0100[];
extern char d_0d26d0[];
extern char d_0d39c0[];
extern char d_1bf49c[];
extern char d_1bf958[];
void f_0a6bd0(void);
void f_0a7230(void);
struct S {
    short active, x, y, cw, rows, fixed, c0, pos, len;
    int buf;
    char *start;
    char *cur;
    char sub[1];
};

//@ f_0a6280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor eines grafischen Texteingabefeld-Objekts (p), gibt dessen
 *   Hintergrundsicherungspuffer *(int *)(p + 0x12) frei und baut das eingebettete RivaRasterImage-Teilobjekt an
 *   Offset +0x1e über f_0fadc0 und f_0fad20 ab.
 * - Eingaben und Rückgabe: Die Funktion erhält die Objektadresse p sowie ein ungenutztes Flag q und gibt die
 *   Basisadresse p zurück (int).
 * - Wichtige Variablen: Das Feld *(int *)(p + 0x12) verweist auf den Puffer der gesicherten Zeichenhintergründe.
 === Ende Beschreibung === */
int f_0a6280(int p, int q)
{
    void *b = (void *)(*(int *)(p + 0x12));
    p += 0x1e;
    operator delete(b);
    ((RivaRasterImage*)(p))->f_0fadc0();
    return ((int)(((RivaRasterImage*)(p))->f_0fad20( 0))) - 0x1e;
}
//@ f_0a62b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuelle X-Koordinate p->x des Texteingabefeldes zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) und gibt p->x zurück (short).
 * - Wichtige Variablen: Das Feld p->x speichert die aktuelle horizontale Zeichenposition.
 === Ende Beschreibung === */
short f_0a62b0(struct S *p) { return p->x; }
//@ f_0a62c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuelle Y-Koordinate p->y des Texteingabefeldes zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) und gibt p->y zurück (short).
 * - Wichtige Variablen: Das Feld p->y speichert die vertikale Bildschirmposition des Eingabefeldes.
 === Ende Beschreibung === */
short f_0a62c0(struct S *p) { return p->y; }
//@ f_0a62d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die X-Koordinate p->x des Texteingabefeldes auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) sowie den neuen X-Wert v (int) und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p->x wird direkt aktualisiert.
 === Ende Beschreibung === */
void f_0a62d0(struct S *p, int v) { p->x = v; }
//@ f_0a62e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Y-Koordinate p->y des Texteingabefeldes auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) sowie den neuen Y-Wert v (int) und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p->y wird direkt aktualisiert.
 === Ende Beschreibung === */
void f_0a62e0(struct S *p, int v) { p->y = v; }
//@ f_0a62f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest für alle p->rows Zeichenplätze des Texteingabefeldes p den jeweiligen p->cw x 8 Pixel
 *   großen Bildschirmhintergrund aus d_1a34e0 über f_0fafb0 in den Sicherungspuffer p->buf ein, damit Zeichen
 *   beim Löschen spurlos entfernt werden können.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) auf das Eingabefeld und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Jeder Zeichenplatz beansprucht p->cw * 8 Bytes im Hintergrundpuffer p->buf.
 === Ende Beschreibung === */
void f_0a62f0(struct S *p)
{
    short i = 0, off = 0, x = p->x;
    if (p->rows > (short)0) {
        do {
            int addr = p->buf; addr += (short)off; ((RivaRasterImage*)((int)p->sub))->f_0fb060((void *)( addr));
            ((RivaRasterImage*)((int)p->sub))->f_0fafb0((void *)( d_1a34e0), x, p->y);
            i++;
            x += p->cw;
            off += p->cw * 8;
        } while (i < p->rows);
    }
}
//@ f_0a6380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet den Anfangszustand des Texteingabefeldes p, indem vorhandene Vorbelegungszeichen aus
 *   p->start (sofern d_1be1b0 != 0) ausgegeben und die verbleibenden Zeichenplätze (oder im Einzelcursor-Modus
 *   p->fixed != 0 nur die aktuelle Position) mit dem Unterstrich-Zeichen '_' (0x5f) markiert werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Textausgabe erfolgt Zeichen für Zeichen über f_05ebd0 auf dem Schriftmanager
 *   d_1c38b0.
 === Ende Beschreibung === */
void f_0a6380(struct S *p)
{
    short x = p->x;
    char *c = p->start;
    short i;
    if (!p->fixed) {
        for (i = 0; i < p->rows; i++) {
                if (d_1be1b0 != (short)0 && p->len > i) {
                    f_05ebd0((int)&d_1c38b0, (signed char)*c, x, p->y);
                    p->pos = p->pos + 1;
                    p->cur++;
                    x += p->cw;
                    c++;
                    p->x = x;
                } else {
                    f_05ebd0((int)&d_1c38b0, 0x5f, x, p->y);
                    x += p->cw;
                }
        }
    } else {
        f_05ebd0((int)&d_1c38b0, 0x5f, x, p->y);
    }
}
//@ f_0a6440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet den gesamten bisherigen Inhalt des Texteingabefeldes p ab p->start (p->pos Zeichen)
 *   sowie die nachfolgenden Unterstrich-Platzhalter '_' neu auf den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Start-X-Koordinate des Feldes wird als p->x - p->pos * p->cw aus der aktuellen
 *   Cursorposition zurückgerechnet.
 === Ende Beschreibung === */
void f_0a6440(struct S *p)
{
    short x = p->x - p->pos * p->cw;
    short i = 0;
    char *c = p->start;
    if (p->pos > (short)0) {
        do {
            f_05ebd0((int)&d_1c38b0, (signed char)*c++, x, p->y);
            i++;
            x += p->cw;
        } while (i < p->pos);
    }
    if (p->fixed == (short)0) {
        i = p->pos;
        if (i < p->rows) {
            do {
                f_05ebd0((int)&d_1c38b0, 0x5f, x, p->y);
            x += p->cw;
            i++;
            } while (i < p->rows);
        }
    } else {
        f_05ebd0((int)&d_1c38b0, 0x5f, x, p->y);
    }
}
//@ f_0a6510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt ab der aktuellen Cursorposition p->pos bis zum Ende des Eingabefeldes (p->rows) den
 *   ursprünglich gesicherten Bildschirmhintergrund aus p->buf wieder her, um die restlichen
 *   Unterstrich-Platzhalter nach Abschluss der Eingabe zu entfernen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Teilbild p->sub kopiert die gesicherten p->cw x 8-Blöcke über f_0fade0 zurück nach
 *   d_1a34e0.
 === Ende Beschreibung === */
void f_0a6510(struct S *p)
{
    RivaMouseGuard mg;
    for (;;) {
        short pos = p->pos;
        if (pos >= p->rows) break;
        int addr = (pos << 3) * p->cw;
        int buf = p->buf;
        addr += buf;
        ((RivaRasterImage*)((int)p->sub))->f_0fb060((void *)( addr));
        ((RivaRasterImage*)((int)p->sub))->f_0fade0((void *)( d_1a34e0), p->x, p->y);
        p->x += p->cw;
        p->pos++;
    }
}
//@ f_0a65b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt im Texteingabefeld p einen Rückschritt (Backspace) aus: Sofern p->pos > 0 ist, wird die
 *   Cursorposition um ein Zeichen nach links bewegt, der gesicherte Hintergrund an der alten und neuen Position
 *   wiederhergestellt und an der neuen Position wieder der Unterstrich-Cursor '_' gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct S *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Felder p->pos, p->cur und p->x werden um eine Zeichenstelle zurückgesetzt.
 === Ende Beschreibung === */
void f_0a65b0(struct S *p)
{
    RivaMouseGuard mg;
    if (p->pos > 0) {
        if (p->fixed == 1 && p->pos != p->rows)
            ((RivaRasterImage*)((int)p->sub))->f_0fade0((void *)( d_1a34e0), p->x, p->y);
        p->x -= p->cw;
        p->pos--;
        p->cur--;
        ((RivaRasterImage*)((int)p->sub))->f_0fb060((void *)( p->buf + (short)p->cw * ((short)p->pos * 8)));
        ((RivaRasterImage*)((int)p->sub))->f_0fade0((void *)( d_1a34e0), p->x, p->y);
        f_05ebd0((int)&d_1c38b0, 0x5f, p->x, p->y);
    }
}
//@ f_0a6690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt ein neu eingegebenes Zeichen c an der aktuellen Cursorposition (p->x, p->y) des
 *   Eingabefeldes p aus, nachdem dort der Hintergrund aus p->sub wiederhergestellt wurde, rückt p->x und p->pos
 *   weiter und zeichnet im Modus p->fixed == 1 den Unterstrich-Cursor an die neue Position.
 * - Eingaben und Rückgabe: Die Funktion erhält den Eingabefeldzeiger p (struct S *) sowie das Zeichen c (signed
 *   char) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p->cw gibt den horizontalen Zeichenvorschub in Pixeln an.
 === Ende Beschreibung === */
void f_0a6690(struct S *p, signed char c)
{
    RivaMouseGuard mg;
    ((RivaRasterImage*)((int)p->sub))->f_0fade0((void *)( d_1a34e0), p->x, p->y);
    f_05ebd0((int)&d_1c38b0, c, p->x, p->y);
    p->x += p->cw;
    p->pos++;
    if (p->fixed == 1 && p->pos != p->rows)
        f_05ebd0((int)&d_1c38b0, 0x5f, p->x, p->y);
}
//@ f_0a6740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette interaktive Texteingabe im Feld p an der Position (x, y) für den
 *   Zielstring str aus: Die Funktion sichert den Hintergrund, gibt den Starttext aus, verarbeitet in einer
 *   Schleife druckbare Zeichen (in Großbuchstaben über f_145400, ohne führendes Leerzeichen), Rücktaste (8),
 *   Eingabetaste (0x0d, erst gültig wenn mindestens ein Zeichen eingegeben wurde) sowie Abbruch per Escape
 *   (0x1b) oder Rechtsklick (f_0d37b0) und schließt den String mit einem Nullbyte ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Eingabefeldzeiger p (struct S *), den Zielpuffer str (char
 *   *), die Koordinaten x und y sowie den Cursor-Modus fixed (int) und gibt 0 bei Bestätigung oder -1 bei
 *   Abbruch zurück (short).
 * - Wichtige Variablen: Ist die maximale Zeichenanzahl p->rows erreicht, überschreibt jedes weitere Zeichen den
 *   letzten Platz (p->pos - 1).
 === Ende Beschreibung === */
void f_0a6380(struct S *p);
void f_0a65b0(struct S *p);
short f_0a6740(struct S *p, char *str, int x, int y, int fixed)
{
    short xx, yy;
    short r;
    xx=0;
    p->active = 1;
    p->x = x;
    p->y = y;
    p->fixed = fixed;
    p->cur = str;
    p->start = str;
    r = 0;
    p->len = strlen(str);
    {
    { char keep=*(char*)&d_1a34e0; *(char*)&d_1a34e0=keep; }
        RivaMouseGuard mg;
        S *q = p;
        short i;
        i = 0;
        yy = 0;
        xx = q->x;
        if (q->rows > (short)0) {
            do {
                int addr=(short)yy;
                int buf=q->buf;
                addr+=buf;
                ((RivaRasterImage*)((int)q->sub))->f_0fb060((void *)(addr));
                ((RivaRasterImage*)((int)q->sub))->f_0fafb0((void *)( d_1a34e0), (short)xx, q->y);
                i++;
                xx += q->cw;
                yy += q->cw << 3;
            } while (i < (short)q->rows);
        }
        f_0a6380(p);
    }
    if (!*(short *)&d_1bd90c)
        f_0d4800(7);
    f_0d3870();
    *(volatile int *)&d_1bf4e8 = 0;
    f_149d20();
    {
        short k = 0;
        for (;;) {
            short c;
            if (k == 0xd && p->pos != (short)0)
                break;
            k = (unsigned char)f_1453b0(f_0e4380((int)&d_1c2c64, (int)p) & 0xff);
            if (!k)
                k = 0xd;
            *(short *)&d_1bd766 = *(short *)&d_1bd75e;
            { int scale=(short)p->pos*8; int width=(short)p->cw; int product=scale*width; int addr=p->buf; addr+=product; ((RivaRasterImage*)((int)p->sub))->f_0fb060((void *)(addr)); }
            c = k;
            if (c == 0xd)
                continue;
            if (c == 0x1b || f_0d37b0()) {
                *(short *)&d_1bd766 = 0;
                *p->start = (char)d_1bd766;
                r = -1;
                break;
            }
            if (c == 8) {
                f_0a65b0(p);
                continue;
            }
            if (f_045df0((int)&d_1c3078, (unsigned char)k) == 1) {
                if (c == 0x20 && p->pos == (short)0)
                    continue;
                k = f_145400((unsigned char)k);
                if (p->pos == p->rows) {
                    --*(volatile int *)&p->cur;
                    int screen=d_1a34e0; short color=d_1bd75e;
                    short nx=p->x; nx-=*(volatile short *)&p->cw;
                    d_1a34e0=screen; d_1bd75e=color;
                    p->pos = p->pos - 1;
                    int ofs=((short)p->pos * 8) * (short)p->cw;
                    int buf=p->buf;
                    ofs+=buf;
                    ((RivaRasterImage*)((p->x = nx, (int)p->sub)))->f_0fb060((void *)( ofs));
                }
                *p->cur++ = (char)k;
                f_0a6690(p, (signed char)k);
            }
        }
    }
    if (p->fixed == (short)0) {
        S *q = p;
        RivaMouseGuard mg2;
        for (;;) {
            short pos = q->pos;
            if (pos >= q->rows) break;
            int addr = ((short)pos * 8) * (short)q->cw;
            int buf = q->buf;
            addr += buf;
            ((RivaRasterImage*)((int)q->sub))->f_0fb060((void *)( addr));
            ((RivaRasterImage*)((int)q->sub))->f_0fade0((void *)( d_1a34e0), q->x, q->y);
            q->x = q->x + q->cw;
            q->pos = q->pos + 1;
        }
    }
    *p->cur = 0;
    p->active = 0;
    return r;
}
//@ f_0a6a30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über DPMI-Interrupt 0x31 (Funktion 0x0400) ab, ob virtueller Speicher aktiv ist, und
 *   sperrt in diesem Fall über DPMI-Funktion 0x0600 (Lock Linear Region) fünf für Hardware-Interrupts kritische
 *   Code- und Datenbereiche (f_0a6bd0..f_0a7230, f_0100c0..d_0101db, d_1a0100, d_0d26d0..d_0d39c0 und
 *   d_1bf49c..d_1bf958) im physischen RAM gegen Auslagerung.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Arrays d_1be1e4 und d_1be20c speichern die Startadressen und Längen der d_1be234
 *   gesperrten Speicherbereiche.
 === Ende Beschreibung === */
void f_0a6a30(void)
{
    short i;
    union MYREGS regs;

    i = 0;
    regs.x.eax = 0x400;
    f_149cd2(0x31, &regs, &regs);
    if (regs.h.bl & 4) {
        d_1be1e4[i] = (unsigned)f_0a6bd0;
        d_1be20c[i] = (unsigned)f_0a7230 - (unsigned)f_0a6bd0;
        ++i;
        d_1be1e4[i] = (unsigned)f_0100c0;
        d_1be20c[i] = (unsigned)d_0101db - (unsigned)f_0100c0;
        ++i;
        d_1be1e4[i] = (unsigned)d_1a0100;
        d_1be20c[i] = 8;
        ++i;
        d_1be1e4[i] = (unsigned)d_0d26d0;
        d_1be20c[i] = (unsigned)d_0d39c0 - (unsigned)d_0d26d0;
        ++i;
        d_1be1e4[i] = (unsigned)d_1bf49c;
        d_1be20c[i] = (unsigned)d_1bf958 - (unsigned)d_1bf49c;
        ++i;
        d_1be234 = i;
        --i;
        while (i >= 0) {
            regs.x.eax = 0x600;
            regs.w.bx = (unsigned short)(d_1be1e4[i] >> 16);
            regs.w.cx = (unsigned short)d_1be1e4[i];
            regs.w.si = (unsigned short)(d_1be20c[i] >> 16);
            regs.w.di = (unsigned short)d_1be20c[i];
            f_149cd2(0x31, &regs, &regs);
            --i;
        }
    }
}
//@ f_0a6b50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hebt beim Programmende für alle zuvor in f_0a6a30 gesperrten Code- und Datenbereiche die
 *   DPMI-Speichersperre über Interrupt 0x31, Funktion 0x0601 (Unlock Linear Region) wieder auf.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Anzahl der freizugebenden Bereiche steht in d_1be234.
 === Ende Beschreibung === */
void f_0a6b50(void)
{
    short i;
    union MYREGS regs;

    if (d_1be234 != 0) {
        i = d_1be234 - 1;
        while (i >= 0) {
            regs.x.eax = 0x601;
            regs.w.bx = (unsigned short)(d_1be1e4[i] >> 16);
            regs.w.cx = (unsigned short)d_1be1e4[i];
            regs.w.si = (unsigned short)(d_1be20c[i] >> 16);
            regs.w.di = (unsigned short)d_1be20c[i];
            f_149cd2(0x31, &regs, &regs);
            i--;
        }
    }
}
//@ f_0a6bd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Markierungsfunktion, deren Adresse in f_0a6a30 den Beginn des im RAM zu sperrenden
 *   Interrupt-Codebereichs (f_0a6bd0 bis f_0a7230) markiert.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion greift auf keine Variablen zu.
 === Ende Beschreibung === */
void f_0a6bd0(void) { }
//@ f_0a6bf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet innerhalb des Tastatur-Interrupts (INT 09h) den am Tastaturport 0x60 anliegenden
 *   Scancode, fängt die Tastenkombinationen Pause (0xe1), Strg+C (0x1d + 0x2e) und Strg+Pause/Untbr (0x1d + 0xe0
 *   + 0x46) direkt durch Bestätigung am PIC/PPI (Ports 0x20 und 0x61) ab, damit DOS das Spiel nicht abbricht,
 *   und setzt für alle normalen Tasten das Weiterleitungsflag d_1be1d8 = 1.
 * - Eingaben und Rückgabe: Die Far-Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1be1b6 verfolgt den gedrückten Zustand der Strg-Taste (0x1d/0x9d), d_1be1d2
 *   zählt abgefangene Unterbrechungstasten und d_1be1d8 steuert, ob der ursprüngliche BIOS-Tastaturinterrupt
 *   aufgerufen wird.
 === Ende Beschreibung === */
int f_0100c0(void);
void __far f_0a6bf0(void)
{
    short k;
    int a_;
    if (d_1be1dc == 1) {
        k = inp(0x60);
        if (k != 0xe0 && k != 0xe1 && (k & 0x80))
            f_0100c0();
    } else {
        k = f_0100c0();
    }
    if (d_1be1b4 > 0) {
        d_1be1b4--;
ack:
        outp(0x20, 0x20);
        a_ = inp(0x61);
        outp(0x61, a_ | 0x80);
        outp(0x61, a_);
    } else if (k == 0xe1) {
        d_1be1b4 = 2;
        d_1be1d2++;
        goto ack;
    } else {
        if (k == 0x1d) {
            d_1be1b6=1;
            // haelt die Registerzuteilung wie im Original
            *(unsigned short *)&d_1be1b6 = 1u;
        }
        else if (k == 0x9d)
            d_1be1b6 = 0;
        if (d_1be1b6 == 1 && k == 0x2e) {
            d_1be1b8 = 1;
            d_1be1d2++;
            goto ack;
        }
        if (d_1be1b8 == 1 && k == 0xae) {
            d_1be1b8 = 0;
            goto ack;
        }
        if (d_1be1b6 == 1) {
            switch ((unsigned short)d_1be1ba) {
            case 0:
                if (k == 0xe0) {
                    d_1be1ba = 1;
                    break;
                }
reset:
                d_1be1ba = 0;
                break;
            case 1:
                if (k == 0x46) {
                    d_1be1ba = 2;
                    d_1be1d2++;
                    goto ack;
                }
                d_1be1ba = 0;
                break;
            case 2:
                if (k == 0xe0) {
                    d_1be1ba = 3;
                    goto ack;
                }
                d_1be1ba = 0;
                break;
            case 3:
            default:
                goto reset;
            }
        }
        d_1be1d8 = 1;
    }
}
//@ f_0a6df0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die C-Laufzeit-Signale SIGINT (4) und SIGBREAK (7), indem die Funktion sich selbst
 *   sofort wieder über f_15dc98 (signal) als Handler registriert und den Zähler d_1be1d6 erhöht.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zähler d_1be1d6 protokolliert abgefangene Abbruchsignale.
 === Ende Beschreibung === */
void f_0a6df0(void)
{
    f_15dc98(4, (void *)f_0a6df0);
    f_15dc98(7, (void *)f_0a6df0);
    ++d_1be1d6;
}
//@ f_0a6e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht als DOS-Strg+C-Handler (__far __loadds) lediglich den Zähler d_1be1d4, um einen
 *   Programmabbruch durch DOS zu verhindern.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1be1d4 zählt die Aufrufe.
 === Ende Beschreibung === */
void __far __loadds f_0a6e20(void)
{
    ++d_1be1d4;
}
//@ f_0a6e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt beim Programmende die ursprünglichen Interruptvektoren für den Timer (INT 1Ch,
 *   d_1be1bc) und die Tastatur (INT 09h, d_1be1c4) wieder her, entsperrt die DPMI-Speicherbereiche über f_0a6b50
 *   und gibt die beiden 16.000-Byte-Notfallpuffer d_1be240 und d_1be244 frei.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die alten Interruptvektoren d_1be1bc und d_1be1c4 wurden beim Start in f_0a6ea0
 *   gesichert.
 === Ende Beschreibung === */
void f_0a6e30(void)
{
    _dos_setvect(0x1c, d_1be1bc);
    _dos_setvect(9, d_1be1c4);
    f_0a6b50();
    if (d_1be240 != 0) { f_13d5d0(d_1be240); d_1be240 = 0; }
    if (d_1be244 != 0) { f_13d5d0(d_1be244); d_1be244 = 0; }
}
//@ f_0a6ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Richtet beim Spielstart die Interruptvektoren für den Systemtimer (INT 1Ch -> f_0a7110) und
 *   die Tastatur (INT 09h -> f_0a7160) ein, sperrt die Interrupt-Routinen im RAM (f_0a6a30), registriert die
 *   Aufräumroutine f_0a6e30 sowie den Critical-Error-Handler f_0a7240, reserviert drei 16.000-Byte-Puffer
 *   (d_1be240, d_1be244, d_1be23c) und lädt das 320x50-Notfallbanner aus der Datei d_1b7d4f vorab in den
 *   Speicher d_1be23c.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Durch das Vorabladen des Fehlerbanners d_1b7d4f in d_1be23c kann der
 *   Critical-Error-Handler f_0a7240 später auch bei ausgefallenem CD-ROM- oder Diskettenlaufwerk ohne
 *   Dateizugriff eine Fehlermeldung auf dem Bildschirm anzeigen.
 === Ende Beschreibung === */
void __interrupt f_0a7110(void);
void __interrupt f_0a7160(void);
int __far f_0a7240(int, int, int, int);
extern int f_13d570(int);
extern int f_13d570(int, const char *);
extern int f_15e469(const char *);
extern int f_15e55f(int, int, int);
extern int f_15e65b(int, int, int, int);
extern int f_15e836(int);
extern void f_15e181(void (__far *)());
extern void f_15e1be(int (*)(int, int, int, int));
extern void *f_145300(void *, int, unsigned);
extern char d_1b7d4c[], d_1b7d4f[], d_1c2a74[];
void f_0a6ea0(void)
{
    void call_0a6a30(void);
#pragma aux call_0a6a30 "f_0a6a30" parm [] modify exact [eax edx]
    int call_13d570(int);
#pragma aux call_13d570 "f_13d570" parm [eax] value [eax] modify exact [eax edx]
    int call_13d570_2(const char *, int);
#pragma aux call_13d570_2 "f_13d570" parm [edx] [eax] value [eax] modify exact [eax edx]
    d_1be1bc = _dos_getvect(0x1c);
    d_1be1c4 = _dos_getvect(9);
    _dos_setvect(0x1c, f_0a7110);
    _dos_setvect(9, f_0a7160);
    call_0a6a30();
    f_15e181((void (__far *)())f_0a6e30);
    f_15e1be((int (*)(int, int, int, int))f_0a7240);
    d_1be240 = f_13d570(16000);
    *(volatile int *)&d_1be244 = call_13d570(16000);
    d_1be23c = call_13d570_2(d_1b7d4c, 16000);
    int fh = f_15e469(d_1b7d4f);
    if (fh) {
        f_15e55f(fh, 0x50, 0);
        f_15e65b(d_1be23c, 16000, 1, fh);
        f_15e836(fh);
    } else {
        f_149e2e(d_1c2a74, 255);
        f_145300((void *)d_1be23c, 255, 16000);
    }
}
//@ f_0a6fb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert bei jedem Timer-Tick (18,2 Hz) die globalen Spielzeit- und Animationszähler
 *   (d_1be1e0, d_1c3914, d_1c016c, d_1bc5f6), zählt sieben Kurzzeit-Countdowns d_1bf234[0..6] herunter (und löst
 *   bei Ablauf d_1c219a = 1 aus) und ruft reentranzsicher (d_1bc604) die Uhrzeitfortschreibung
 *   f_1261b0(&d_1c2c44) auf.
 * - Eingaben und Rückgabe: Die Far-Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ist das Debug-Profilflag d_1bc950 gesetzt, färbt die Funktion für die Dauer der
 *   Interrupt-Ausführung den Paletteneintrag 0 grün (0, 63, 0) und am Ende wieder schwarz.
 === Ende Beschreibung === */
void __far f_0a6fb0(void)
{
    struct RGB c1;
    struct RGB c2;
    short i;
    if (d_1bc950 != 0) {
        c1.r = 0;
        c1.g = 0x3f;
        c1.b = 0;
        f_149e2e(&c1, 0);
    }
    d_1be1e0++;
    d_1c3914++;
    if (d_1bc604 == 0) {
        d_1bc604 = 1;
        d_1c016c++;
        for (i = 0; i <= 6; i++) {
            if (d_1bf234[i] > 0) {
                --d_1bf234[i];
                if (d_1bf234[i] == 0) {
                    d_1c219a = 1;
                }
            }
        }
        f_1261b0((int)&d_1c2c44);
        d_1bc604 = 0;
    }
    d_1c219e = 1;
    d_1bc5f6++;
    if (d_1bc950 != 0) {
        c2.r = 0;
        c2.g = 0;
        c2.b = 0;
        f_149e2e(&c2, 0);
    }
}
//@ f_0a70b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft die Tastatur-Interruptlogik f_0a6bf0 geschützt durch das Reentranz-Flag d_1be24a auf.
 * - Eingaben und Rückgabe: Die Far-Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1be24a verhindert geschachtelte Aufrufe von f_0a6bf0.
 === Ende Beschreibung === */
void __far f_0a70b0(void)
{
    if (d_1be24a == 0) {
        d_1be24a = 1;
        f_0a6bf0();
        d_1be24a = 0;
    }
}
//@ f_0a70e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft die Timer-Tick-Logik f_0a6fb0 geschützt durch das Reentranz-Flag d_1be248 auf.
 * - Eingaben und Rückgabe: Die Far-Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1be248 verhindert geschachtelte Aufrufe von f_0a6fb0.
 === Ende Beschreibung === */
void __far f_0a70e0(void)
{
    if (d_1be248 == 0) {
        d_1be248 = 1;
        f_0a6fb0();
        d_1be248 = 0;
    }
}
//@ f_0a7110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bedient als Hardware-Interrupt-Routine (__interrupt) den Timer-Interrupt INT 1Ch, führt
 *   reentranzsicher f_0a6fb0 aus und verkettet anschließend über _chain_intr zum ursprünglichen
 *   BIOS-Timer-Handler d_1be1bc.
 * - Eingaben und Rückgabe: Die Interrupt-Routine erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der alte Interruptvektor liegt in d_1be1bc.
 === Ende Beschreibung === */
void __interrupt f_0a7110(void)
{
    if (d_1be248 == 0) {
        d_1be248 = 1;
        f_0a6fb0();
        d_1be248 = 0;
    }
    _chain_intr(d_1be1bc);
}
//@ f_0a7160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bedient als Hardware-Interrupt-Routine (__interrupt) den Tastatur-Interrupt INT 09h, führt
 *   f_0a6bf0 aus und verkettet nur dann über _chain_intr an den alten Tastaturhandler d_1be1c4, wenn f_0a6bf0
 *   das Flag d_1be1d8 == 1 gesetzt hat (also keine gesperrte Tastenkombination wie Strg+C vorlag).
 * - Eingaben und Rückgabe: Die Interrupt-Routine erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1be1d8 entscheidet über die Weiterleitung an das BIOS.
 === Ende Beschreibung === */
void __interrupt f_0a7160(void)
{
    if (d_1be24a == 0) {
        d_1be24a = 1;
        f_0a6bf0();
        d_1be24a = 0;
    }
    if (d_1be1d8 == 1) {
        d_1be1d8 = 0;
        _chain_intr(d_1be1c4);
    }
}
//@ f_0a71c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht den schnellen Sound-/Animations-Timerzähler d_1bd76c um 1 und markiert bei aktivem
 *   Debug-Flag d_1bc950 die Laufzeit durch kurzes Rotfärben (63, 0, 0) des Paletteneintrags 0.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1bd76c dient als hochfrequenter Taktzähler.
 === Ende Beschreibung === */
void f_0a71c0(void)
{
    struct RGB c1, c2;
    if (d_1bc950 != 0) {
        c1.r = 0x3f; c1.g = 0; c1.b = 0;
        f_149e2e(&c1, 0);
    }
    d_1bd76c++;
    if (d_1bc950 != 0) {
        c2.r = 0; c2.g = 0; c2.b = 0;
        f_149e2e(&c2, 0);
    }
}
//@ f_0a7230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Markierungsfunktion, deren Adresse in f_0a6a30 das Ende des im physischen RAM gesperrten
 *   Interrupt-Codebereichs markiert.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion verwendet keine Variablen.
 === Ende Beschreibung === */
void f_0a7230(void) { }
//@ f_0a7240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt als DOS-Critical-Error-Handler (INT 24h) schwerwiegende Laufwerks- oder
 *   CD-ROM-Lesefehler: Die Funktion liest die aktuelle VGA-Palette aus, bildet die acht Farben des vorab
 *   geladenen 320x50-Fehlerbanners (d_1be23c) über f_09a990 auf die bestpassenden Einträge der aktuellen Palette
 *   ab, sichert den oberen Bildschirmstreifen nach d_1be244, blendet das Fehlerbanner ein und wartet auf die
 *   Taste für "Wiederholen" (d_1c20f4 -> Rückgabe 1) oder "Abbrechen" (d_1c20f6 -> Programmende mit exit(0x2a)),
 *   während andere Tasten mit einem Warnton (3.000 Hz) quittiert werden.
 * - Eingaben und Rückgabe: Die Far-Funktion erhält vier DOS-Fehlerparameter und gibt 1 (Operation wiederholen)
 *   zurück, sofern nicht mit exit(0x2a) abgebrochen wird (int).
 * - Wichtige Variablen: Bei der Prüfung, ob die aktuelle Palette komplett dunkel ist, steht die Bedingung if
 *   (!bad || i == 0xff) statt if (!bad) (siehe Fehlerliste).
 === Ende Beschreibung === */
int __cdecl f_149eb4(void *,int,int);
void __cdecl f_149e2e(const char *,int);
int f_13eab0(int,int,int,int,int,int,int);
int f_144570(void);
int __cdecl f_149dfe(const char *);
int f_149cf0(int);
extern char d_1c2a74[], d_1c2a78[];
int __far f_0a7240(int, int, int, int)
{
    unsigned char t658_42;
    struct Set {
        static void set(RGB *p, unsigned char r, unsigned char g, unsigned char b) { p->r=r; p->g=g; p->b=b; }
    };
    struct RivaMouseGuard {
        int fl;
        RivaMouseGuard() { if(f_0d3860()==1) { f_0d2710(); fl=1; } else fl=0; }
        ~RivaMouseGuard() { if(fl==1) f_0d26e0(); }
    };
    unsigned char *pal = (unsigned char *)d_1be244;
    int bad=0;
    RGB *colors=(RGB *)(pal+0x400);
    RivaMouseGuard mg;
    unsigned char col[8];
    short i = 0, j, k, ox, res;
    *(int *)&d_1bfa6c = 1;
    f_149eb4(pal,0,0x100);
    for (i=0;i<0x100;i++) {
        unsigned char *q = pal + i*3;
        if (q[0] > 0x10 || q[1] > 0x10 || (t658_42 = q[2]) > 0x10) { bad = 1; break; }
    }
    if (!bad || i == 0xff) {
        f_149e2e((const char *)d_1c2a74, 0xff);
        Set::set((RGB *)(pal+0x2fd), 0x18, 0x18, 0x18);
    }
    Set::set(colors+0, 0, 0, 0);
    Set::set(colors+1, 0, 0, 12);
    Set::set(colors+2, 8, 4, 1);
    Set::set(colors+3, 5, 8, 25);
    Set::set(colors+4, 7, 13, 25);
    Set::set(colors+5, 9, 17, 25);
    Set::set(colors+6, 20, 16, 4);
    Set::set(colors+7, 25, 21, 9);
    for (k = 0; k < 8; k++)
        col[k] = f_09a990((int)(colors+k), (int)pal);
    for (j = 0; j < 16000; j++)
        ((unsigned char *)d_1be240)[j] = col[((unsigned char *)*(int *)&d_1be23c)[j] & 0xf];
    ox = ((short)f_13f8c0() - 0x140) / 2;
    f_13eab0(d_1be244, 0, ox, 0, 0x140, 0x32, 0x140);
    f_13e690(d_1be240, 0, ox, 0, 0x140, 0x32, 0x140);
    int frequency;
    frequency = 3000;
    res = 0x29a;
    while (res == 0x29a) {
        unsigned short key;
        while (_bios_keybrd(_KEYBRD_READY) == 0) ;
        key = _bios_keybrd(_KEYBRD_READ);
        if ((short)key == d_1c20f4) {
            res = 1;
        } else if ((short)key == d_1c20f6) {
            f_144570();
            f_149dfe(d_1c2a78);
            res = 2;
            exit(0x2a);
        } else {
            sound(frequency);
            f_149cf0(10);
            nosound();
        }
    }
    f_13e690(d_1be244, 0, (short)(ox & 0xffff), 0, 0x140, 0x32, 0x140);
    return res;
}
//@ f_0a74e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert den Critical-Error-Handler f_0a7240 über f_15e1be, reserviert die drei
 *   16.000-Byte-Notfallpuffer d_1be240, d_1be244 und d_1be23c und lädt das Fehlerbanner d_1b7d4f ab Datei-Offset
 *   0x50 in den Puffer d_1be23c.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion entspricht dem Fehlerbanner-Initialisierungsteil von f_0a6ea0 ohne erneutes
 *   Umbiegen der Timer- und Tastatur-Interrupts.
 === Ende Beschreibung === */
extern int f_13d570(int);
extern int f_13d570(int, const char *);
extern int f_15e469(const char *);
extern int f_15e55f(int, int, int);
extern int f_15e65b(int, int, int, int);
extern int f_15e836(int);
extern void *f_145300(void *, int, unsigned);
extern void f_15e1be(int (__far *)(int, int, int, int));
extern char d_1b7d4c[], d_1b7d4f[];
void f_0a74e0(void)
{
    int call_13d570(int);
#pragma aux call_13d570 "f_13d570" parm [eax] value [eax] modify exact [eax edx]
    int call_13d570_2(const char *, int);
#pragma aux call_13d570_2 "f_13d570" parm [edx] [eax] value [eax] modify exact [eax edx]
    f_15e1be(f_0a7240);
    d_1be240 = f_13d570(16000);
    *(volatile int *)&d_1be244 = call_13d570(16000);
    *(int *)&d_1be23c = call_13d570_2(d_1b7d4c, 16000);
    int fh = f_15e469(d_1b7d4f);
    if (fh) {
        f_15e55f(fh, 0x50, 0);
        f_15e65b(*(int *)&d_1be23c, 16000, 1, fh);
        f_15e836(fh);
    } else {
        f_149e2e(d_1c2a74, 255);
        f_145300((void *)*(int *)&d_1be23c, 255, 16000);
    }
}
//@ f_0a7590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die beiden 16.000-Byte-Notfallpuffer d_1be240 und d_1be244 über f_13d5d0 frei und setzt
 *   ihre Zeiger auf 0.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Zeiger d_1be240 und d_1be244 werden vor der Freigabe auf ungleich 0 geprüft.
 === Ende Beschreibung === */
void f_0a7590(void)
{
    if (d_1be240 != 0) { f_13d5d0(d_1be240); d_1be240 = 0; }
    if (d_1be244 != 0) { f_13d5d0(d_1be244); d_1be244 = 0; }
}
//@ f_0a75d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den VGA-Paletteneintrag 0 (Hintergrund-/Rahmenfarbe) über f_149e2e auf das RGB-Tripel
 *   (a, b, c).
 * - Eingaben und Rückgabe: Die Funktion erhält die drei Farbwerte a, b und c (int) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Eine lokale RGB-Struktur t übergibt die drei Bytes an f_149e2e.
 === Ende Beschreibung === */
void f_0a75d0(int a, int b, int c)
{
    struct RGB t;
    t.r = a; t.g = b; t.b = c;
    f_149e2e(&t, 0);
}
//@ f_0a7600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die drei Farbkomponenten a, b und c in das 3-Byte-RGB-Tripel p[0..2].
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielzeiger p (char *) sowie die drei Farbwerte a, b und c
 *   (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion entspricht der Hilfsmethode Set::set aus f_0a7240.
 === Ende Beschreibung === */
void f_0a7600(char *p, int a, int b, int c)
{
    p[0] = a; p[1] = b; p[2] = c;
}
