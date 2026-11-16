/* === Beschreibung (Katalog) ===
 * Einheit gz_068f40 (0x068F40 - 0x0695C0)
 *
 * Überblick
 * Die Einheit gz_068f40 enthält die zentrale Eingabe- und Ereignisschleife für Tastatur, Maus und
 * Hintergrund-Updates (f_068f40, f_069460) sowie zwei kleine Byte-Prüffunktionen (f_0695a0, f_0695b0).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
// P3 2/4 gleich (suche.py 25.10.2026, Basis gz_068f40_P1.CPP)
// I9: aus gz_068f40_REST.CPP uebernommen (Stufe-2-Stand), Marken 2 neu
// STAND: NICHT GLEICH, 99 Befehle offen (Lauf 8). Offen: sh in edi statt esi, fl/fl2 liegen in Registern statt [esp+0xc/0x10] (sub esp 0x20 statt 0x28), Reihenfolge r=d762 / 4e2b-Zweig
// gz_068f40.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x068F40-0x0695C0. Tastatur-Abfrage (BIOS int 16h), Sondertasten, Aufr?umen; zwei Mini-Pr?ffunktionen.
extern "C" void exit(int);
extern unsigned short _bios_keybrd(unsigned __cmd);
#pragma aux _bios_keybrd = 0x88 0xe6 0xcd 0x16 0x75 0x09 0x80 0xe6 0x0f 0xfe 0xce 0x75 0x02 0x29 0xc0 __parm [ah] __value [ax] __modify [dx];
struct Q { void f_05e320(short a, short b); void f_05e2d0(short a, short b, short c, int d); void f_05e2a0(short *a, short *b, short *c, short *d);
           void f_0e9660(const void *a, int b, int c); void f_05e340(); };
struct Lock { Lock(); ~Lock(); short x; };
struct Kb { void f_0d48a0(); void f_0d4880(); void f_0f0130(); void f_0d4163(); };
struct Snd { void f_146dfa(int a); };
struct Msg { int f_0e3360(); int f_0e3370(); };
struct Mi { int f_0bba10(); void f_0bbf00(); };
void f_01008c(); void f_0d3870(); int f_0d3860(); void f_0d2710(); void f_0d26e0(); void f_0d32f0();
unsigned f_11bfd0(int k); void f_053c50(); unsigned short f_0d34f0(int p); void f_0a16b0(unsigned k); void f_144570(int k);
void f_076a40(int p); void f_01c840(int p); short f_01dfb0(int p); void f_0463e0(void *p); void f_126840(void *p, int z); void f_0d5550(void *p);
void f_04e0a0(int p); void f_0106e0(int p);
void f_069460();
extern Kb d_1c2e68, d_1c2e78; extern Snd d_1c2edc; extern Q d_1c38b0; extern Msg d_1c2c64; extern Mi d_1bf230;
extern char d_1c2c60[], d_1c2c44[], d_1c2bcc[];
extern const int d_1a1388, d_1a34e0; extern const char d_1b6f34[];
extern unsigned short d_1bd756, d_1bd758, d_1bd75a, d_1bd75c, d_1bd760, d_1bd762, d_1bd764, d_1bd766, d_1bd754;
extern unsigned short d_1c21a2; extern short d_1bd75e, d_1c219e, d_1c219a, d_1bc5f4, d_1bd90c;
extern int d_1c0c4c, d_1bf4e8, d_1bc944, d_1bfb34, d_1c2a80, d_1bcad0, d_1c0ae8, d_1bf514, d_1bf510, d_1bd914, d_1bc760, d_1bc5f0, d_1bc928, d_1bc75c, d_1c0c94;
extern signed char d_1bf4ef, d_1bfb1c;

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_068f40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zentrale Tastatur-, Maus- und System-Abfrageroutine des Spiels: Fragt über BIOS-Interrupt
 *   0x16 (_bios_keybrd) den Status der Umschalttasten (Shift, Ctrl, Alt) und gedrückte Tasten ab, rechnet
 *   Sondertasten (Pfeiltasten mit Shift, Nummernblock-Minus/+, Tastenkombinationen über f_11bfd0) um, behandelt
 *   globale Hotkeys wie die Pause-Funktion (0x1910 = Alt+P, sichert den Hintergrund, gibt den Pausetext d_1b6f34
 *   aus und wartet auf Tastendruck), Hilfe-/Options-Tasten (F1 = 0x3b00, Alt+H = 0x2308, Shift+F1 = 0x5400,
 *   f_0a16b0), den Sofort-Ausstieg (Ctrl+Q = 0x1011, f_144570 + exit(0)) sowie den Debug-/Screenshot-Hotkey (sh
 *   & 0xf == 0xb, f_053c50), wertet Mausklicks (d_1bf4e8) auf UI-Schaltflächen (f_0d34f0) aus und stößt
 *   anschließend die Hintergrundaktualisierung f_069460() an.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void, speichert den ermittelten Tastencode in d_1bd766).
 * - Wichtige Variablen:
 *   - sh (Vom BIOS gelesene Umschalttasten-Bits: d_1bd760 = Shift, d_1bd756 = Ctrl, d_1bd758 = Alt).
 *   - d_1bd762, d_1bd75c, d_1bd75e, d_1bd75a, d_1bd766 (Aktueller 16-Bit-Tastencode, ASCII-Byte, Scancode-Byte
 *     und Ausgabecode).
 *   - d_1bd764 (Softwareseitig injizierter Tastencode mit Vorrang vor dem BIOS-Puffer).
 *   - d_1c21a2 (Sperrflag während der aktiven Pause-Schleife).
 *   - d_1bf4e8 (Mausklick-Ereignisflag).
 === Ende Beschreibung === */
void f_068f40()
{
    f_01008c();
    f_0d3870();
    d_1c2e68.f_0d48a0();
    unsigned short sh = _bios_keybrd(2);
    unsigned short r = 0;
    d_1bd760 = sh & 3;
    d_1bd756 = sh & 4;
    d_1bd758 = sh & 8;
    d_1bd762 = 0;
    if ((short)d_1bd764) {
        d_1c2e68.f_0d4880();
        d_1bd762 = d_1bd764;
        d_1bd764 = 0;
    } else {
        if (_bios_keybrd(1)) {
            d_1c2e68.f_0d4880();
            d_1bd762 = _bios_keybrd(0);
        }
    }
    if ((short)d_1bd762) {
        d_1bd75c = d_1bd762 & 0xff;
        d_1bd75e = (d_1bd762 >> 8) & 0xff;
        r = d_1bd762;
        if (d_1bd760 && d_1bd75e == 0x4d) r = 0x4d00;
        else if (d_1bd760 && d_1bd75e == 0x4b) r = 0x4b00;
        else if (d_1bd760 && d_1bd75e == 0x50) r = 0x5000;
        else if (d_1bd760 && d_1bd75e == 0x48) r = 0x4800;
        else if (d_1bd762 == 0x4a2d) { r = (d_1bd762 = 0x352d); }
        else if (d_1bd762 == 0x4e2b) { r = (d_1bd762 = 0x1b2b); }
        else if (d_1bd756 || d_1bd758 || d_1bd760) { r = (d_1bd762 = f_11bfd0((short)d_1bd762)); }
        d_1bd75a = d_1bd762;
        if (!d_1c21a2) {
            if (d_1bd762 == 0x1910) {
                short s24, s18, s1c, s20;
                RivaRasterImage img(8, 8);
                d_1c21a2 = 1;
                d_1c0c4c = d_1c0c4c + 1;
                d_1c38b0.f_05e320(0xff, -1);
                d_1c38b0.f_05e2a0(&s20, &s1c, &s24, &s18);
                d_1c38b0.f_05e2d0(10, 100, 10, 0);
                volatile int fl;
                if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
                img.f_0fafb0((void *)(d_1a34e0), 0, 0);
                d_1c38b0.f_0e9660(d_1b6f34, 0, 0);
                if (fl == 1) f_0d26e0();
                do {
                    d_1bd754++;
                    f_068f40();
                    d_1c2e68.f_0f0130();
                } while ((short)d_1bd766 == (short)0);
                d_1bd754 = 0;
                volatile int fl2;
                if (f_0d3860() == 1) { f_0d2710(); fl2 = 1; } else fl2 = 0;
                img.f_0fade0((void *)(d_1a34e0), 0, 0);
                if (fl2 == 1) f_0d26e0();
                d_1c38b0.f_05e340();
                d_1c38b0.f_05e2d0(s20, s1c, s24, s18);
                d_1c21a2 = 0;
                d_1c0c4c = d_1c0c4c - 1;
                d_1bf4e8 = r = 0;
                f_0d3870();
            }
            if (d_1bd762 == 0x3b00 || d_1bd762 == 0x2308 || d_1bd762 == 0x5400 || d_1bd762 == 0x2300) {
                Lock lk;
                f_0a16b0(d_1bd762);
                d_1bd766 = 0;
            } else if (d_1bd762 == 0x1011) {
                f_144570(d_1bd762);
                exit(0);
            }
        }
    }
    if ((sh & 0xf) == 0xb && d_1bc944 == 0) f_053c50();
    if (d_1bf4e8 != 0) {
        r = 0;
        d_1c2e68.f_0d4880();
        ((volatile int&)d_1bf4e8) = 0;
        signed char b1c; if (d_1bf4ef == 0 && (d_1c2a80 != 0 || (b1c = d_1bfb1c) == 1 || d_1bcad0 == 1 || d_1bd90c == 1 || d_1c0ae8 == 1
                || d_1c2c64.f_0e3360() == 1 || d_1c2c64.f_0e3370() == 1)) {
            if ((volatile int&)d_1bf514 != 0) r = f_0d34f0(d_1bf514);
            if ((short)r == (short)0 && (volatile int&)d_1bf510 != 0) r = f_0d34f0(d_1bf510);
            d_1bd75a = r;
        }
    }
    f_0d32f0();
    if (d_1bfb34 == 0 && ((short)d_1c21a2 == (short)0)) f_069460();
    else if (d_1c219e == 1) {
        struct KbWrap { char pad[16]; Kb k; };
        (*(KbWrap *)&d_1c2e68).k.f_0d4163();
        d_1c2edc.f_146dfa(1);
        ((int&)d_1bc75c) = 0;
        d_1c219e = 0;
    }
    d_1bd766 = r;
}

//@ f_069460
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die periodischen Hintergrund- und Bildaktualisierungen während der Eingabeschleife
 *   aus: Aktualisiert bei Bedarf Kampfanimationen (f_076a40), Musik-/Sound-Streams (d_1bf230.f_0bbf00,
 *   d_1c2edc.f_146dfa), laufende 2D-Animationen (f_01c840), Kompass/Statusanzeigen (f_0463e0), die Spielzeituhr
 *   (f_126840), Monster-/Gruppenbewegungen (f_0d5550) sowie die 3D-/Kartenansicht (f_04e0a0).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c219e (Timer-Tick-Flag, das anzeigt, dass ein neuer Frame-/Zeit-Tick abgearbeitet werden muss).
 *   - d_1bd914, d_1bc760, d_1bc5f4, d_1c2a80 (Zeiger und Statusflags für aktive Subsysteme).
 === Ende Beschreibung === */
void f_069460()
{
    if (d_1bd914) f_076a40(d_1bd914);
    if (d_1c219e == 1) {
        if (d_1c219a != (short)0 && d_1bf230.f_0bba10() && !d_1c2c64.f_0e3360())
            d_1bf230.f_0bbf00();
        if (d_1bc760) { if (f_01dfb0(d_1bc760)) f_01c840(d_1bc760); }
        d_1c2e78.f_0d4163();
        d_1c2edc.f_146dfa(1);
        if (d_1bc5f4) f_0106e0(d_1bc5f0);
        else {
            if (d_1c2c64.f_0e3360() == 0) f_0463e0(d_1c2c60);
            if (d_1bf230.f_0bba10() && d_1c2c64.f_0e3360() == 0 && d_1c0c94 != 0) f_126840(d_1c2c44, 0);
            f_0d5550(d_1c2bcc);
            if ((d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) && d_1a1388 != 0) f_04e0a0(d_1bc928);
            d_1c2e68.f_0f0130();
        }
        d_1c219e = 0;
    }
}

int f_0695a0(signed char *p) { return *p == 0; }
int f_0695b0(signed char *p) { return *p == 1; }
