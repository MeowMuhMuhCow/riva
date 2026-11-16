/* === Beschreibung (Katalog) ===
 * Einheit gz_07a470 (07a470 - 07a8a0)
 *
 * Überblick
 * Diese Einheit enthält weitere Animations-Kommandogeneratoren für Großgegner (Tod f_07a470, Trefferreaktion
 * f_07a4d0, Parade f_07a560) sowie die Datei- und Grafik-Laderoutinen für die Kampffeld-Definitionen
 * (0x4001000c, f_07a600, f_07a6a0, f_07a730) und das Kampfhintergrundbild (f_07a7e0).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// P3 6/7 gleich (suche.py 25.10.2026, Basis gz_07a470_P1.CPP)
// gz_07a470.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07A470-0x07A8A0
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
#pragma pack(1)
struct Ent { char a, b, c, d; };
struct Cmd { int w0; int w4; int w8; Ent e[38]; };
struct Q { char pad[15]; int w; };
struct T12 { int a, b, c; };
struct Obj { char pad[0xa4]; };
int f_06f5c0(int p1, int p2, Cmd *p3);
int f_072940(int p1);
int f_0728f0(int p1);
unsigned char f_0cfc50(int p1);
Q *f_07ea60(int p1, int p2);
void f_069a00(int p1, Cmd *p2);
void *f_145300(void *p, int c, unsigned n);
void __cdecl f_099ef0(int p, int a, int b);





Obj *f_1459b0(Obj *p1);
Obj *f_1459d0(Obj *p1, int p2);
int f_145a40(Obj *p1, int p2, int p3);
int f_145b40(Obj *p1);
short f_149360(int p1, char *p2);
extern T12 d_1a250c[];
extern char *d_1bdaec;

extern char d_1a280c[];

//@ f_07a470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet die Todes- bzw. Endanimationssequenz (e[0].a = 1, b = 3, c = 0xff) für einen besiegten
 *   Großgegner p2.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2 sowie den Befehlszeiger p3 (Cmd *)
 *   und gibt das Animationshandle q->w (int) zurück.
 * - Wichtige Variablen: Übergibt die initialisierte 0xa4-Byte-Kommandostruktur p3 an f_069a00.
 === Ende Beschreibung === */
int f_07a470(int p1, int p2, Cmd *p3)
{
    Q *q;
    f_145300(p3, 0, 0xa4);
    p3->w0 = f_0728f0(p2);
    p3->e[0].a = 1; p3->e[0].b = 3; p3->e[0].c = 0xff;
    p3->e[1].a = 0xff;
    q = f_07ea60(p1 + 0x39, f_0cfc50(p2));
    f_069a00(q->w, p3);
    return q->w;
}

//@ f_07a4d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für einen handlungsfähigen Großgegner p2 die Trefferreaktions-Animation (0x47, bei
 *   gesetztem Doppel-Flag *(p1 + 0x1ee) zweimal hintereinander), oder fällt bei Kampfunfähigkeit auf die
 *   Standardanimation f_06f5c0 zurück.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2 und den Befehlszeiger p3 (Cmd *)
 *   und gibt das Animationshandle (int) zurück.
 * - Wichtige Variablen: Prüft f_072940(p2) sowie das Wiederholungsflag *(p1 + 0x1ee).
 === Ende Beschreibung === */
int f_07a4d0(int p1, int p2, Cmd *p3)
{
    Q *q;
    short n = 0;
    if (f_072940(p2)) {
        f_145300(p3, 0, 0xa4);
        p3->w0 = f_0728f0(p2);
        p3->e[0].a = 0x47; p3->e[0].b = 0;
        n = 1;
        if (*(char *)(p1 + 0x1ee)) {
            p3->e[n].a = 0x47; p3->e[n++].b = 0;
        }
        p3->e[n].a = 0xff;
        q = f_07ea60(p1 + 0x39, f_0cfc50(p2));
        f_069a00(q->w, p3);
        return q->w;
    }
    return f_06f5c0(p1, p2, p3);
}

//@ f_07a560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für einen Großgegner p2 die Parade- bzw. Abwehranimation (0x6f), gefolgt von einer
 *   optionalen Treffersequenz (0x47), falls *(p1 + 0x1ef) gesetzt ist. *(Hinweis: Enthält danach eine redundante
 *   Prüfung if (n != 0), die wegen des vorangegangenen n++ immer wahr ist, sodass der else-Zweig return
 *   f_06f5c0(...) toter Code ist; siehe Fehlerliste.)*
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2 und den Befehlszeiger p3 (Cmd *)
 *   und gibt das Animationshandle (int) zurück.
 * - Wichtige Variablen: Beschreibt p3->e[0..2] und startet die Sequenz über f_069a00.
 === Ende Beschreibung === */
int f_07a560(int p1, int p2, Cmd *p3)
{
    Q *q;
    short n = 0;
    f_145300(p3, 0, 0xa4);
    p3->w0 = f_0728f0(p2);
    p3->e[n].a = 0x6f; p3->e[n++].b = 0;
    if (*(char *)(p1 + 0x1ef)) {
        p3->e[n].a = 0x47; p3->e[n++].b = 0;
    }
    p3->e[n].a = 0xff;
    if (n != 0) {
        q = f_07ea60(p1 + 0x39, f_0cfc50(p2));
        f_069a00(q->w, p3);
        return q->w;
    }
    return f_06f5c0(p1, p2, p3);
}

//@ f_07a5f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion (ret), die keine Aktion ausführt.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_07a5f0(void)
{
}

//@ f_07a600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den 0x1a0 (416) Byte großen Kampffeld-Datensatz für die Kampfnummer *(short *)(p + 0x1ea)
 *   aus der Kampfdatei 0x4001000c nach p + 0xed3 (Gegneraufstellung, Heldenstartplätze, Beute und
 *   Fluchtparameter).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Begrenzt *(short *)(p + 0x1ea) auf die im Dateikopf (erste 2 Bytes) gespeicherte
 *   maximale Eintragsanzahl k - 1.
 === Ende Beschreibung === */
void f_07a600(char *p)
{
    int n;
    short k;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x4001000c, 0x200);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &n), 2)));
    k = n;
    if (*(short *)(p + 0x1ea) > k) *(short *)(p + 0x1ea) = k - 1;
    ((RivaFileManager*)(&d_1c2098))->f_144ab0( *(short *)(p + 0x1ea) * 0x1a0u + 2, 0);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p + 0xed3), 0x1a0)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
}

inline void h_07a6a0(char *p, short k)
{
    if (k >= *(short *)(p + 0x1ea)) {
        ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x4001000c, 2);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &k), 2)));
        ((RivaFileManager*)(&d_1c2098))->f_144ab0( *(short *)(p + 0x1ea) * 0x1a0u + 2, 0);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144960((void *)( p + 0xed3), 0x1a0)));
        ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    }
}
//@ f_07a6a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt nach dem Ende eines festen Kampfes (*(short *)(p + 0x1ea) <= 0xa5) den aktualisierten
 *   0x1a0 Byte großen Kampffeld-Datensatz p + 0xed3 (z. B. mit als tot markierten Gegnern und liegengelassener
 *   Beute) zurück in die temporäre Kampfdatei 0x4001000c.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt den Dateimanager d_1c2098 im Schreibmodus (2) an Dateiposition kampf_nr * 0x1a0 +
 *   2.
 === Ende Beschreibung === */
void f_07a6a0(char *p)
{
    h_07a6a0(p, 0xa5);
}

//@ f_07a730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den Kampffeld-Datensatz k aus 0x4001000c nach p + 0xed3 und zählt, wie viele der 20
 *   Gegner-Slots (p + 0xee9 + i * 15) noch mit lebenden Gegnern belegt sind (etwa um vor Kampfbeginn zu prüfen,
 *   ob ein Kampf bereits erledigt wurde). Für dynamische Kämpfe (k > 0xa5) gibt sie konstant 99 zurück.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p (char *) und die Kampfnummer k (short) und gibt die Anzahl
 *   der vorhandenen Gegner (int, oder 99 bei Zufallskämpfen) zurück.
 * - Wichtige Variablen: Prüft in einer Schleife über 20 Slots das Monster-ID-Byte p[i * 15 + 0xee9].
 === Ende Beschreibung === */
int f_07a730(char *p, short k)
{
    int n;
    short i;
    n = 0;
    if (k > 0xa5) {
        n = 99;
    } else {
        ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x4001000c, 0x200);
        ((RivaFileManager*)(&d_1c2098))->f_144ab0( k * 0x1a0u + 2, 0);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p + 0xed3), 0x1a0)));
        ((RivaFileManager*)(&d_1c2098))->f_1449a0();
        for (i = 0; i < (short)0x14; i++) {
            if (p[i * 0xf + 0xee9]) n++;
        }
    }
    return n;
}

//@ f_07a7e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt zu Kampfbeginn das zum Arena-/Boden-Typ *(p + 0x1073) + 0x14 gehörende 320 x
 *   200-Kampfhintergrundbild aus der Tabelle d_1a250c, setzt die zugehörige Farbpalette über f_099ef0 (inklusive
 *   Sonderpalette für Kämpfe in der Liste d_1a280c) und sichert das Bild im Hintergrundpuffer d_1bdaec.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt das Bildlade-Objekt Obj (f_1459b0, f_145a40, f_145b40) und kopiert 0xfa00 Bytes
 *   nach d_1bdaec.
 === Ende Beschreibung === */
void f_07a7e0(char *p)
{
    Obj o;
    f_1459b0(&o);
    f_145a40(&o, d_1a250c[*(signed char *)(*(int *)(p + 0x1073) + 0x14)].a, *(int *)p);
    f_099ef0(f_145b40(&o) + 0xc0, 0x40, 0x40);
    if (f_149360(*(short *)(p + 0x1ea), d_1a280c) != -1) {
        f_099ef0(f_145b40(&o), 0, 0x40);
    }
    memcpy(d_1bdaec, *(char **)p, 0xfa00);
    f_1459d0(&o, 0);
}
