/* === Beschreibung (Katalog) ===
 * Einheit popup
 *
 * Diese Einheit (aus p:\riva\source\cpp\popup.cpp) implementiert das Zeichnen, Positionieren, interaktive
 * Verschieben mit Maus oder Tastatur sowie die Ereignisschleife der im gesamten Spiel verwendeten
 * Popup-Textfenster.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -oe=200 -zp1 -s
// P3 6/8 gleich (suche.py 30.10.2026, Basis popup_P1.CPP)
// popup.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E36D0-0x0E4640
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01008c();                                         // reg - stapel 0
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_053c50();                                         // reg - stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e340(int p1);                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
int f_0773b0(int p1);                                   // reg eax stapel 0
int f_0a16b0();                       // nicht in clobber.tsv
short f_0a62b0(int p1);                                   // reg eax stapel 0
int f_0a62c0(int p1);                                   // reg eax stapel 0
int f_0a62d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0a62e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0a6440(int p1);                                   // reg eax stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax edx stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d32f0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_0d34f0(int p1);                                   // reg eax stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d4163(int p1);                                   // reg eax stapel 0
int f_0d4880();                                         // reg - stapel 0
int f_0d48a0(int p1);                                   // reg eax stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e3360(int p1);                                   // reg eax stapel 0
int f_0e3370(int p1);                                   // reg eax stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e3580(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0f0130(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
// reg eax edx ebx ecx stapel 12
           // reg eax edx ebx ecx stapel 0
                           // reg eax edx stapel 0
int f_11bfd0(int p1);                                   // reg eax stapel 0
int f_144570(int p1, int p2, int p3);                   // reg - stapel 0
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_15ec70(int p1);                                   // reg eax stapel 0
int f_15f130(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);// reg eax edx ebx ecx stapel 16
int f_15f367(int p1, int p2);                           // reg eax edx stapel 0
int f_15f385(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_15f3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_15f3bc(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1b6f34;                    // 0x1B6F34
extern int d_1bc75c;                    // 0x1BC75C
extern int d_1bc944;                    // 0x1BC944
extern int d_1bcad0;                    // 0x1BCAD0
extern int d_1bd754;                    // 0x1BD754
extern int d_1bd756;                    // 0x1BD756
extern int d_1bd758;                    // 0x1BD758
extern int d_1bd75a;                    // 0x1BD75A
extern int d_1bd75e;                    // 0x1BD75E
extern int d_1bd764;                    // 0x1BD764
extern int d_1bdbd4;                    // 0x1BDBD4
extern int d_1bf510;                    // 0x1BF510
extern int d_1bfb1c;                    // 0x1BFB1C
extern int d_1bfb34;                    // 0x1BFB34
extern int d_1c0ae8;                    // 0x1C0AE8
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c219e;                    // 0x1C219E
extern int d_1c21a2;                    // 0x1C21A2
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2e68;                    // 0x1C2E68
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a64dc[];           // Text 0x1A64DC
// --- eigene Funktionen (8), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern short d_1bd760, d_1bd766, d_1bd75c, d_1bf4f0, d_1bf4f2, d_1bd90c, d_1a64fc, d_1a64fe, d_1a6500, d_1a6502;
extern volatile short d_1bc764; // haelt beide Status-Stores in f_0e3ad0 wie im Original
extern unsigned short d_1bd762;
extern volatile int d_1bf4e8; // haelt die Register- und Befehlsfolge in f_0e3ba0 wie im Original
extern int d_1bf514, d_1c0004, d_1c3914;
extern char d_1bf4ef;
extern char d_1bfae8;
extern signed char d_1bfafc, d_1bfb00;
// --- Hilfen (Helfer E) ---
void f_068f40(void);
int f_15eca0(int p1, int p2);
//@ f_0e36d0
/* === Beschreibung (Katalog) ===
 * Zeichnet einen horizontalen Streifen eines Popup-Fensterrahmens (p1) in der vertikalen Zeilenhöhe p2 * 8 und
 * Streifenhöhe p4 Pixel, indem je nach Streifentyp p3 (0 = Kopfleiste mit Grafikkacheln 0..3, 1 = Mittelstück
 * mit Kacheln 8..11, 2 = Fußleiste mit Kacheln 4..7) das linke Randstück, die mittlere Wiederholungskachelfolge
 * und das rechte Randstück entpackt (f_15f130) und in den Bildschirmpuffer (d_1a34e0) geblittet werden
 * (f_0faf20).
 * - Eingaben: Übergeben werden der Zeiger auf das Popup-Fensterobjekt p1, der vertikale 8-Pixel-Zeilenversatz
 *   p2, der Streifentyp p3 (0, 1 oder 2) sowie die Streifenhöhe p4 in Pixeln.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e36d0(int p1, short p2, short p3, short p4)
{
    short outp;
    int codex_arg_1_142;
    void f_15f130(int, int, int, int, int, short *, short *, int);
    short w;
    short k1, k2;
    short k3, a;
    short x;
    char o1[28];
    char o2[12];
    int buf;
    f_15ec70((int)o1);
    ((int)(((RivaRasterImage*)((int)o2))->f_0fac10( 0x20, p4,(void *)( 0))));
    buf = f_014540(0x400, (int)d_1a64dc, 0xd9);
    ((RivaRasterImage*)((int)o2))->f_0fb060((void *)( buf));
    switch ((unsigned short)p3) {
    case 0: a = 0; k1 = 1; k2 = 2; k3 = k2 + 1; break;
    case 2: a = 4; k1 = 5; k2 = 6; k3 = k2 + 1; break;
    case 1: a = 8; k1 = 10; k2 = 11; k3 = k1 - 1; break;
    }
    x = *(short *)(p1 + 0x14);
    short y = *(short *)(p1 + 0x16) + p2 * 8;
    f_15f130((int)o1, buf, *(int *)p1, a, 0, &outp, &w, 0x140);
    if ((short)w > (short)p4) w = p4;
    ((RivaRasterImage*)((int)o2))->f_0faf20((void *)( (codex_arg_1_142 = d_1a34e0)), x, y, (short)0x20, (short)w, (unsigned short)1); // haelt die Stapelplatzfolge wie im Original
    x += 0x20;
    a = *(short *)(p1 + 0x12);
    for (; a > 0; a--) {
        f_15f130((int)o1, buf, *(int *)p1, (short)k1, 0, &outp, &w, 0x140);
        if ((short)w > (short)p4) w = p4;
        ((RivaRasterImage*)((int)o2))->f_0faf20((void *)( d_1a34e0), x, y, (short)0x20, (short)w, (unsigned short)1);
        x += 0x20;
        a -= 1;
        if (a > 0) {
            f_15f130((int)o1, buf, *(int *)p1, (short)k2, 0, &outp, &w, 0x140);
            if ((short)w > (short)p4) w = p4;
            ((RivaRasterImage*)((int)o2))->f_0faf20((void *)( d_1a34e0), x, y, (short)0x20, (short)w, (unsigned short)1);
            x += 0x20;
        }
    }
    f_15f130((int)o1, buf, *(int *)p1, (short)k3, 0, &outp, &w, 0x140);
    if ((short)w > (short)p4) w = p4;
    ((RivaRasterImage*)((int)o2))->f_0faf20((void *)( d_1a34e0), x, y, (short)0x20, (short)w, (unsigned short)1);
    { struct Bytes3 { unsigned char bytes[3]; }; Bytes3 output_three = *(Bytes3 *)o1; } // gleicht die Groessendifferenz von char o2[12] zu RivaRasterImage (9 Byte) fuer die Stapelplatz-Sortierung aus
    d_1a34e0 = (d_1a34e0 & 0) ? 0 : d_1a34e0; // haelt die Stapelplatzfolge von k3 und outp wie im Original
    operator delete((void *)buf);
    ((int)(((RivaRasterImage*)((int)o2))->f_0fad20( 0)));
    f_15eca0((int)o1, 0);
}

//@ f_0e3970
/* === Beschreibung (Katalog) ===
 * Berechnet die horizontale Startkoordinate (X-Position) eines Popup-Fensters (p1) der Pixelbreite p2: Ist kein
 * fester X-Versatz (+0x22) vorgegeben und die Maussteuerung aktiv, wird das Fenster nahe der aktuellen
 * Maus-X-Position (d_1bf4f0) platziert, andernfalls auf dem 320 Pixel breiten Bildschirm zentriert und an den
 * Rändern 0..319 geklemmt.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1 sowie die Gesamtbreite des Fensters p2 in Pixeln.
 * - Rückgabewert: Die Funktion gibt die berechnete X-Koordinate des linken Fensterrands zurück.
 === Ende Beschreibung === */
short f_0e3970(int p1, short p2)
{
    short r;
    short t;
    signed char b;
    if (*(short *)(p1 + 0x22)) {
        r = ((0x140 - (short)p2) >> 1) + *(short *)(p1 + 0x22);
    } else {
        if (!d_1bf4ef && (b = !*(volatile char *)&d_1bfae8)) // haelt die Registerwahl ebx fuer den Abschlusstest wie im Original
            r = d_1bf4f0 - p2 + 0x10;
        else
            r = (0x140 - (short)p2) >> 1;
    }
    t = r + p2 - 0x13f;
    if ((short)t > 0) r -= t;
    if ((short)r < 0) r = 0;
    return r;
}

//@ f_0e39e0
/* === Beschreibung (Katalog) ===
 * Berechnet die vertikale Startkoordinate (Y-Position) eines Popup-Fensters (p1) der Pixelhöhe p2: Ist kein
 * fester Y-Versatz (+0x24) gesetzt und die Maus aktiv, wird das Fenster vertikal um die Maus-Y-Position
 * (d_1bf4f2) zentriert, sonst auf dem 200 Pixel hohen Bildschirm eingemittet und auf den sichtbaren Bereich
 * 0..199 begrenzt.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1 sowie die Gesamthöhe des Fensters p2 in Pixeln.
 * - Rückgabewert: Die Funktion gibt die berechnete Y-Koordinate des oberen Fensterrands zurück.
 === Ende Beschreibung === */
int f_0e39e0(int p1, int p2)
{
    int r;
    int t;
    signed char b;
    if (*(short *)(p1 + 0x24)) {
        r = ((200 - (short)p2) >> 1) + *(short *)(p1 + 0x24);
    } else {
        if (!d_1bf4ef && (b = !d_1bfae8)) {
            r = (short)p2;
            r >>= 1;
            r = *(volatile short *)&d_1bf4f2 - r; // haelt die Auswertungsreihenfolge (Shift vor Maus-Y-Load) wie im Original
        } else
            r = (200 - (short)p2) >> 1;
    }
    t = p2 + r - 199;
    if ((short)t > 0) r -= t;
    if ((short)r < 0) r = 0;
    return r;
}

//@ f_0e3a60
/* === Beschreibung (Katalog) ===
 * Sichert die vier Bildschirmkanten unter einem gestrichelten Verschieberahmen an der Position (p2, p3) mit den
 * Abmessungen (p4, p5) über die Grafikroutinen f_15f367 (horizontale Linien) und f_15f3a0 (vertikale Linien) in
 * den Zwischenpuffer p6.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die X-Koordinate p2, die Y-Koordinate p3, die Breite
 *   p4, die Höhe p5 sowie die Adresse des Linien-Zwischenpuffers p6.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e3a60(int p1, short p2, short p3, short p4, short p5, int p6)
{
    f_15f367((unsigned short)(p3 * 0x140), p6);
    f_15f367((unsigned short)((p3 + p5 - 1) * 0x140), p6 + 0x140);
    f_15f3a0((unsigned short)p2, p6 + 0x280, 0x140);
    f_15f3a0((unsigned short)(p2 + p4 - 1), p6 + 0x348, 0x140);
}

//@ f_0e3ad0
/* === Beschreibung (Katalog) ===
 * Stellt die vier zuvor mit f_0e3a60 in den Puffer p6 gesicherten Bildschirmkanten des Verschieberahmens an der
 * Position (p2, p3) mit den Maßen (p4, p5) über f_15f385 und f_15f3bc wieder im Bildschirmpuffer her.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die X-Koordinate p2, die Y-Koordinate p3, die Breite
 *   p4, die Höhe p5 sowie der Linien-Zwischenpuffer p6.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e3ad0(int p1, short p2, short p3, short p4, short p5, int p6)
{
    f_15f385((unsigned short)(p3 * 0x140 + p2), p6 + (short)p2, (short)p4);
    f_15f385((unsigned short)((p3 + p5 - 1) * 0x140 + p2), p6 + 0x140 + (short)p2, (short)p4);
    d_1bc764 = 1;
    f_15f3bc((unsigned short)(p3 * 0x140 + p2), p6 + 0x280 + (short)p3, (short)p5, 0x140);
    f_15f3bc((unsigned short)(p3 * 0x140 + p2 + p4 - 1), p6 + 0x348 + (short)p3, (short)p5, 0x140);
    d_1bc764 = 1;
}

//@ f_0e3ba0
/* === Beschreibung (Katalog) ===
 * Führt das interaktive Verschieben eines Popup-Fensters (p1) der Größe (p4, p5) ab Startposition (p2, p3)
 * durch: Solange die Maustaste gedrückt gehalten wird oder Pfeiltasten (0x4d00, 0x4b00, 0x5000, 0x4800) betätigt
 * werden, bewegt die Funktion einen Umrissrahmen (f_1481a0) über den Bildschirm und speichert beim Loslassen die
 * neue Zielposition in den Feldern +0x18 und +0x1a.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die aktuelle X-Koordinate p2, die aktuelle
 *   Y-Koordinate p3, die Fensterbreite p4 sowie die Fensterhöhe p5.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void *f_014710(void *p);
#define MX (*(volatile short *)&d_1bf4f0) // Maus-X wird im Interrupt aktualisiert; haelt alle Lesezugriffe in der Schleife wie im Original
#define MY (*(volatile short *)&d_1bf4f2) // Maus-Y wird im Interrupt aktualisiert; haelt alle Lesezugriffe in der Schleife wie im Original
void f_0e3ba0(int p1, short p2, short p3, short p4, short p5)
{
    int buf;
    short tx, ty, ox, oy, mx, my;

    mx = -1;
    ox = -1;
    oy = -1;
    if (*(short *)(p1 + 0x20) == 0) {
        buf = f_014540(0x410, (int)d_1a64dc, 0x18d);
        if (buf != 0) {
            *(short *)(p1 + 0x1e) = 1;
            {
                RivaMouseGuard mg;
                if (mx != -1)
                    f_0e3ad0(p1, ox, oy, p4, p5, buf);
                f_0e3a60(p1, p2, p3, p4, p5, buf);
                f_1481a0((int)&d_1bdbd4, d_1a34e0, p2, p3, p4, p5, -1);
            }
            ox = p2;
            oy = p3;
            mx = MX;
            my = MY;
            while (!f_0d3790() || d_1bd760) {
                f_068f40();
                if (d_1bd760) {
                    tx = p2;
                    ty = p3;
                    if (d_1bd766 == 0x4d00)
                        p2 += 8;
                    else if (d_1bd766 == 0x4b00)
                        p2 -= 8;
                    else if (d_1bd766 == 0x5000)
                        p3 += 8;
                    else if (d_1bd766 == 0x4800)
                        p3 -= 8;
                    else if (d_1bd766 == 0x11b || d_1bd766 == 0x5100)
                        break;
                    if (p2 < 0)
                        p2 = 0;
                    if (p3 < 0)
                        p3 = 0;
                    if (p2 + p4 > 0x140)
                        p2 = 0x140 - p4;
                    if (p3 + p5 > 0xc8)
                        p3 = 0xc8 - p5;
                    if (p2 != tx || p3 != ty) {
                        RivaMouseGuard mg;
                        if (mx != -1)
                            f_0e3ad0(p1, ox, oy, p4, p5, buf);
                        f_0e3a60(p1, p2, p3, p4, p5, buf);
                        f_1481a0((int)&d_1bdbd4, d_1a34e0, p2, p3, p4, p5, -1);
                        ox = p2;
                        oy = p3;
                        mx = tx;
                    }
                } else {
                    if (mx != MX || my != MY) {
                        {
                            RivaMouseGuard mg;
                            if (mx != -1)
                                f_0e3ad0(p1, ox, oy, p4, p5, buf);
                            f_0e3a60(p1, p2, p3, p4, p5, buf);
                            f_1481a0((int)&d_1bdbd4, d_1a34e0, p2, p3, p4, p5, -1);
                        }
                        ox = p2;
                        oy = p3;
                        if (mx != -1) {
                            p2 += MX - mx;
                            p3 += MY - my;
                            if (p2 < 0)
                                p2 = 0;
                            if (p3 < 0)
                                p3 = 0;
                            if (p2 + p4 > 0x140)
                                p2 = 0x140 - p4;
                            if (p3 + p5 > 0xc8)
                                p3 = 0xc8 - p5;
                        }
                        mx = MX;
                        my = MY;
                    }
                }
            }
            *(short *)(p1 + 0x1e) = 0;
            RivaMouseGuard mg;
            *(short *)(p1 + 0x18) = ox;
            *(short *)(p1 + 0x1a) = oy;
            f_0e3ad0(p1, ox, oy, p4, p5, buf);
            buf = (int)f_014710((void *)buf);
        }
    }
    f_0d3770();
    d_1bf4e8 = 0;
}


//@ f_0e4370
/* === Beschreibung (Katalog) ===
 * Ruft die zentrale Ereignis- und Eingabeverarbeitung (f_068f40) einmalig auf, um Maus-, Tastatur- und
 * Timer-Ereignisse während eines offenen Dialogs zu aktualisieren.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4370(void)
{
    f_068f40();
}

//@ f_0e4380
/* === Beschreibung (Katalog) ===
 * Steuert die Warteschleife eines angezeigten Popup-Fensters (p1, optional mit zugehörigem Eingabefeld- oder
 * Schaltflächen-Controller p2): Sie berechnet die Lesezeit anhand der Zeilenanzahl (+0x28) und der
 * konfigurierten Textgeschwindigkeit (d_1bfb00 bzw. d_1bfafc), überwacht Klicks auf die Titelleiste zum
 * Verschieben des Fensters (f_0e3ba0) samt anschließendem Neuzeichnen und wartet, bis die Lesezeit abläuft oder
 * der Spieler das Fenster per Mausklick oder Taste (d_1bd75c) schließt.
 * - Eingaben: Übergeben werden der Zeiger auf das Popup-Fensterobjekt p1 sowie optional die Adresse eines
 *   untergeordneten UI-Steuerelements p2 (0 bei reinen Textmeldungen).
 * - Rückgabewert: Sie gibt den Tastencode der zuletzt gedrückten Taste (d_1bd75c) zurück.
 === Ende Beschreibung === */

#include <stdlib.h>
short f_0e4380(int p1, int p2)
{
    int saved = d_1bf514;
    int time;
    int limit;
    while (d_1bd760 != (short)0) f_068f40();
    time = d_1c3914;
    {
        signed char rate;
        int height;
        if (d_1bd90c != (short)0 && f_0773b0(d_1c0004)) {
            height = *(volatile short *)(p1 + 0x28); // verhindert das Vorziehen des Feldzugriffs vor die Verzweigung wie im Original
            rate = d_1bfb00;
        } else {
            height = *(volatile short *)(p1 + 0x28); // verhindert das Vorziehen des Feldzugriffs vor die Verzweigung wie im Original
            rate = d_1bfafc;
        }
        limit = height * 12;
        limit *= ((signed char)(rate + 1) << 1);
    }
    do {
        d_1a64fc = *(short *)(p1 + 0x14);
        d_1a6500 = d_1a64fc + *(short *)(p1 + 0x26);
        d_1a64fe = *(short *)(p1 + 0x16) + 1;
        d_1a6502 = *(short *)(p1 + 0x16) + 0xe;
        *(volatile int *)&d_1bf514 = (int)&d_1a64fc; // haelt die Store-Reihenfolge vor f_068f40() wie im Original
        f_068f40();
        d_1bf514 = saved; // stellt den vorherigen Hotspot-Tabellenzeiger wieder her (echte Programmlogik)
        if (d_1bd762 == 0x4900 || d_1bd762 == 0x5100 || f_0d37b0()) {
            d_1bd766 = 2;
            d_1bd75c = 0x1b;
        }
        if (*(short *)(p1 + 0x20) == 0 &&
            (d_1bd766 == 1 || d_1bd760 != (short)0) &&
            (f_0d3780() || d_1bd760 != (short)0)) {
            { RivaMouseGuard mg; f_0e3430(p1); }
            f_0e3ba0(p1, *(short *)(p1 + 0x14), *(short *)(p1 + 0x16),
                     *(short *)(p1 + 0x26), *(short *)(p1 + 0x2a));
            {
                RivaMouseGuard mg;
                if (p2 != 0) {
                    f_0a62d0(p2, (short)(f_0a62b0(p2) -
                        (*(short *)(p1 + 0x14) - *(short *)(p1 + 0x18))));
                    f_0a62e0(p2, (short)(f_0a62c0(p2) -
                        (*(short *)(p1 + 0x16) - *(short *)(p1 + 0x1a))));
                }
                *(short *)(p1 + 0x14) = *(short *)(p1 + 0x18);
                *(short *)(p1 + 0x16) = *(short *)(p1 + 0x1a);
                f_05e320((int)&d_1c38b0, 0xff, -1);
                f_05e2d0((int)&d_1c38b0,
                         (short)(*(short *)(p1 + 0x14) + 0xf), -1,
                         (short)(*(short *)(p1 + 0x16) + 0xf), 1);
                f_0e3580(p1, *(short *)(p1 + 0x28));
                f_0e9550((int)&d_1c38b0, *(int *)(p1 + 0xc));
                if (p2 != 0) f_0a6440(p2);
                d_1bd766 = 0;
            }
        }
    } while ((*(short *)(p1 + 0x38) != (short)0 || p2 != 0 ||
              abs(time - d_1c3914) <= limit) &&
             d_1bd766 != 2 && d_1bd75c == (short)0);
    f_0d5b50(0);
    *(short *)(p1 + 0x38) = 0;
    return d_1bd75c;
}
