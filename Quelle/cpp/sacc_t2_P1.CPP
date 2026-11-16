/* === Beschreibung (Katalog) ===
 * Einheit sacc_t2
 *
 * Diese Einheit implementiert den zweiten Teil des sacc-Animations-Players (sacc, Teil 2) und enthält sämtliche
 * Einzel-Befehlshandler der Skriptsprache (Sprite-Positionierung, Paletten-Fading, Soundeffekt-Trigger,
 * Schleifen, Zufallsverzweigungen und Speicheroperationen), die während einer Animation pro Frame aufgerufen
 * werden.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 40/44 gleich (suche.py 30.10.2026, Basis sacc_t2_P1.CPP)
// sacc.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ED980-0x0F00D0
#include <string.h>
#include <bios.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_013670(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_013de0(int p1);                                   // reg eax stapel 0
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_059d60(int p1, int p2);                           // reg eax edx stapel 0
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e420(int p1, int p2);                           // reg eax edx stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0b1340();                                         // reg - stapel 0
int f_0b13d0(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4070(int p1);                                   // reg eax stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0d4880(int p1);                                         // reg - stapel 0
int f_0d9cc0();                                         // reg - stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0ed8f0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_0f00f0(int p1);                                   // reg eax stapel 0
int f_0f1560(int p1);                                   // reg eax stapel 0
int f_11e760(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_11e8f0();                                         // reg - stapel 0
int f_11e910(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_13efd0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_13f8c0();                                         // reg - stapel 0
int f_13f8d0();                                         // reg - stapel 0
   // reg eax edx ebx ecx stapel 4
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_14778f(int p1, int p2);                           // reg eax edx stapel 0
int f_147808(int p1);                                   // reg eax stapel 0
int f_147aad(int p1);                                   // reg eax stapel 0
int f_147b3f(int p1, int p2);                           // reg eax edx stapel 0
int f_149d20();                                         // reg - stapel 0
int f_149eb4(int, ...);           // reg - stapel 0
int f_149f90();                       // nicht in clobber.tsv
int f_14a1d0(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_14a940();                       // nicht in clobber.tsv
int f_14b100();                       // nicht in clobber.tsv
int f_14b3d0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_14b7b0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_14bb40(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg - stapel 12
int f_14d040();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_0a0000;                    // 0x0A0000
extern int d_0e000f;                    // 0x0E000F
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a9698;                    // 0x1A9698
extern const char d_1b8336[];
extern const char d_1b8337[];
extern const char d_1b8338[];
extern const char d_1b8339[];
extern int d_1bb638;                    // 0x1BB638
extern int d_1bc760;                    // 0x1BC760
extern char d_1bf2f0;                    // 0x1BF2F0
extern signed char d_1bfb10;                    // 0x1BFB10
extern int d_1c00e8;                    // 0x1C00E8
extern int d_1c00ec;                    // 0x1C00EC
extern int d_1c00f0;                    // 0x1C00F0
extern short d_1c00f4;                    // 0x1C00F4
extern short d_1c00f6;                    // 0x1C00F6
extern int d_1c00f8;                    // 0x1C00F8
extern int d_1c00fc;                    // 0x1C00FC
extern int d_1c0100;                    // 0x1C0100
extern int d_1c0104;                    // 0x1C0104
extern int d_1c0108;                    // 0x1C0108
extern int d_1c010c;                    // 0x1C010C
extern int d_1c0110;                    // 0x1C0110
extern int d_1c0114;                    // 0x1C0114
extern int d_1c0118;                    // 0x1C0118
extern int d_1c011c;                    // 0x1C011C
extern int d_1c0120;                    // 0x1C0120
extern int d_1c0124;                    // 0x1C0124
extern int d_1c0128;                    // 0x1C0128
extern int d_1c012c[16];                    // 0x1C012C
extern int d_1c0c4c;                    // 0x1C0C4C
extern volatile int d_1c0c94; // haelt die Lade-/Schreibfolge in f_0ef720 und f_0efb50 wie im Original
extern char d_1c1110;                    // 0x1C1110
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2e68;                    // 0x1C2E68
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1a6678[];           // Text 0x1A6678
extern int d_1bb664, d_1bb65c, d_1bb654, d_1bb64c, d_1bb638, d_1baac0;
int f_145300(int, int, int);
int f_145234(int, int);
int f_145254(int);
int f_148143(int, int, int);
int f_0ed980(int, int, int);
int f_0ee070(int);
int f_0edef0(int, int);
int f_0ede30(int);
struct BIG { char c[0x3b9c]; };
typedef void (*VF)(int, int);
#define S16(p,o) (*(short *)((p)+(o)))
#define U16(p,o) (*(unsigned short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
#define NEWBIG(line) ((int)new (mark(d_1a6678, line)) BIG)
int f_147c84(int, int);
int f_014ac0(int, int, int);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0eecd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt einen sacc-Befehl zum Setzen oder Einblenden einer neuen Farbpalette (oder eines
 *   Palettenbereichs) innerhalb der laufenden Animation aus.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Befehlsdatensatz (p1) sowie den Basiszeiger der
 *   Animationsdaten (p2).
 * - Rückgabewert: Die Funktion gibt das Ergebnis der Palettenoperation zurück.
 === Ende Beschreibung === */
short f_0eecd0(int self, int d, char *p)
{
    char *s1, *s3, *s2;
    short a, b, c, e;
    short total;
    a = ((short *)(p += 2))[-1];
    b = ((short *)(p += 2))[-1];
    d = (d & 0) ? 0 : d; // haelt das Gewicht von d fuer die Registervergabe wie im Original
    c = ((short *)(p += 2))[-1];
    e = ((short *)(p += 2))[-1];
    total = 8;
    total += strlen(p) + 1;
    s1 = p;
    p += strlen(p) + 1;
    total += strlen(p) + 1;
    unsigned step2 = strlen(p) + 1;
    s2 = p;
    { struct Byte1 { unsigned char bytes[1]; }; Byte1 pod_s2_0 = *(Byte1 *)((char *)&s2 + 0); } // haelt s2 auf dem Stapel und die Stapelplatzfolge wie im Original
    { struct Byte1 { unsigned char bytes[1]; }; Byte1 pod_s2_1 = *(Byte1 *)((char *)&s2 + 1); } // haelt s2 auf dem Stapel und die Stapelplatzfolge wie im Original
    p += step2;
    total += strlen(p) + 1;
    s3 = p;
    p += strlen(p) + 1;
    *(short *)(d + 4) = a;
    *(short *)(d + 6) = b;
    *(short *)(d + 8) = c;
    *(short *)(d + 10) = e;
    f_148143(d + 0xc, (int)s1, 0x4f);
    f_148143(d + 0x5c, (int)s2, 0x4f);
    f_148143(d + 0xac, (int)s3, 0x4f);
    *(int *)(self + 0x3b8c) = 1;
    return total;
}

//@ f_0eedf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktiviert ein Hintergrundbild oder ein statisches Grafikelement der Animation und
 *   trägt dessen Zeichenparameter in die Anzeigeliste ein.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) und den Datenbasiszeiger (p2).
 * - Rückgabewert: Die Funktion gibt den gesetzten Statuswert zurück.
 === Ende Beschreibung === */
char *f_0eedf0(char *p1, char *p2)
{
    char *r = p1;
    strcpy(r, p2);
    return r;
}
//@ f_0eee20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet ein zuvor aktiviertes Grafikelement der Animation wieder aus, indem sie dessen
 *   Sichtbarkeitsflag löscht.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
void f_0eee20(void)
{
}

//@ f_0eee30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt die Bildschirmkoordinaten (x, y) eines Grafikelements der Animation auf neue
 *   Absolutwerte.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt die gesetzte Y-Koordinate zurück.
 === Ende Beschreibung === */
void f_0eee30(int p1, int p2, int p3, int p4)
{
    I32(p1,8) = (int)&d_1bb664;
    S16(p1,0) = (short)p2;
    S16(p1,2) = (short)p3;
    I32(p1,4) = p4;
}
//@ f_0eee50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verschiebt ein Grafikelement der Animation relativ zu seiner aktuellen Position um ein
 *   im Befehl angegebenes Offset (dx, dy).
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt die aktualisierte Koordinate zurück.
 === Ende Beschreibung === */
int f_0eee50(char *p1, unsigned char p2)
{
    int f_145234(int, int);
    void f_145254();
    if (p2 & 4) {
        f_145234((int)p1, (int)&d_1bb638);
        f_145254();
        return (int)p1;
    }
    *(int *)(p1 + 8) = (int)&d_1bb664;
    if (*(char **)(p1 + 4)) delete *(char **)(p1 + 4);
    if (p2 & 2) operator delete(p1);
    return (int)p1;
}
//@ f_0eeea0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion weist einem animierten Objekt der sacc-Sequenz eine neue Bild- oder Frame-Nummer zu.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt die gesetzte Bildnummer zurück.
 === Ende Beschreibung === */
void f_0eeea0(int p1, short *p2, short *p3, int *p4)
{
    *p2 = S16(p1,0);
    *p3 = S16(p1,2);
    *p4 = I32(p1,4);
}
//@ f_0eeec0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Befehlshandler (No-Op) für einen nicht genutzten Befehlscode im
 *   sacc-Animationsskript.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0eeec0(int p1, int p2)
{
    S16(p1,2) = (short)p2;
}
//@ f_0eeed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ändert den Zeichenmodus (beispielsweise Transparenz oder Spiegelung) eines
 *   Grafikelements in der Animation.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den neuen Zeichenmodus zurück.
 === Ende Beschreibung === */
void f_0eeed0(int p1)
{
    I32(p1,0) = (int)&d_1bb65c;
    S16(p1,4) = 0;
    S16(p1,6) = 0;
    S16(p1,8) = 0;
    I32(p1,10) = 0;
    S16(p1,14) = 0;
}
//@ f_0eef00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion legt das Begrenzungsrechteck (Clipping-Bereich) für die Darstellung eines
 *   Animations-Sprites fest.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den letzten übernommenen Koordinatenwert zurück.
 === Ende Beschreibung === */
void f_0eef00(int p1, short *p2, short *p3, short *p4, int *p5, short *p6)
{
    *p2 = S16(p1,4);
    *p3 = S16(p1,6);
    *p4 = S16(p1,8);
    *p5 = I32(p1,10);
    *p6 = S16(p1,14);
}
//@ f_0eef30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ändert die Zeichenpriorität (Z-Ebene) eines Grafikelements innerhalb der aktuellen
 *   sacc-Szene.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den neuen Prioritätswert zurück.
 === Ende Beschreibung === */
void f_0eef30(int p1, int p2, int p3, int p4, int p5, int p6)
{
    S16(p1,4) = (short)p2;
    S16(p1,6) = (short)p3;
    S16(p1,8) = (short)p4;
    I32(p1,10) = p5;
    S16(p1,14) = (short)p6;
}
//@ f_0eef50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sucht einen freien Soundkanal unter den 16 verfügbaren sacc-Kanälen und startet die
 *   Wiedergabe eines digitalen Soundeffekts mit Lautstärke-, Panorama- und Frequenzparametern aus dem
 *   Befehlsdatensatz.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Sound-Befehlsdatensatz (p1) sowie den Basiszeiger der
 *   geladenen Sounddaten (p2).
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Soundtreiber-Aufrufs (f_147323) zurück.
 === Ende Beschreibung === */
void f_0eef50(int p1, int p2)
{
    short k;
    for (k = 0; k < (short)16; k++) {
        if (d_1c012c[k] == 0) {
            d_1c012c[k] = 1;
            if (d_1c0108 == 1)
                f_147323(d_1a9698, S16(p1,4) + p2, U16(p1,6), U16(p1,8), I32(p1,10), S16(p1,14), 1);
            else
                f_147323(d_1a9698, S16(p1,4) + p2, U16(p1,6), U16(p1,8), I32(p1,10), S16(p1,14), 1);
            return;
        }
    }
}
//@ f_0eefe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verändert während der laufenden Wiedergabe die Lautstärke oder das Stereopanorama
 *   eines bereits spielenden Soundkanals der Animation.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Soundkanal-Aktualisierung zurück.
 === Ende Beschreibung === */
void f_0eefe0(int p1, int p2)
{
    short k;
    for (k = 0; k < (short)16; k++) {
        if (d_1c012c[k] == 1 && f_14778f(d_1a9698, S16(p1,4) + p2) == 0) d_1c012c[k] = 0;
    }
}
//@ f_0ef030
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion stoppt gezielt einen bestimmten digitalen Soundeffekt der Animation anhand seiner
 *   Kanal- oder Sample-Kennung.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Anhalten des Kanals zurück.
 === Ende Beschreibung === */
int f_0ef030(int p1)
{
    I32(p1,0) = (int)&d_1bb654;
    strcpy((char *)(p1 + 12), d_1b8336);
    return p1;
}
//@ f_0ef070
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Platzhalter-Handler für einen nicht implementierten Audio- oder
 *   Steuerbefehl im sacc-Format.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0ef070(void)
{
}
//@ f_0ef080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet einen kontinuierlichen Paletten-Überblendeffekt (Fade) mit den im
 *   Befehlsdatensatz hinterlegten Zielwerten und Schrittweiten.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Datenbasiszeiger (p2).
 * - Rückgabewert: Die Funktion gibt den Status der Überblendinitialisierung zurück.
 === Ende Beschreibung === */
void f_0ef080(int p1, int p2, int p3, int p4, int p5, int p6)
{
    S16(p1,4) = (short)p3;
    S16(p1,8) = (short)p5;
    S16(p1,10) = (short)p6;
    S16(p1,6) = (short)p4;
    f_148143(p1 + 12, p2, 0x4f);
}
//@ f_0ef0b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion rotiert einen definierten Bereich von Farbeinträgen der aktuellen Animationspalette
 *   zyklisch weiter (Color-Cycling für Wasser- oder Lichteffekte).
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Palettenrotation zurück.
 === Ende Beschreibung === */
void f_0ef0b0(int p1, int *p2, short *p3, short *p4, short *p5, short *p6)
{
    *p2 = p1 + 12;
    *p3 = S16(p1,4);
    *p4 = S16(p1,6);
    *p5 = S16(p1,8);
    *p6 = S16(p1,10);
}
//@ f_0ef0e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert eine automatische Bewegung (Pfad- oder Geschwindigkeitsvektor) für ein
 *   Sprite der sacc-Animation über eine festgelegte Anzahl von Frames.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den gesetzten Bewegungsparameter zurück.
 === Ende Beschreibung === */
void f_0ef0e0(int p1, int p2)
{
    char b[2];
    int p3;
    if (d_1c00ec == 1) {
        if (d_1c00f6 <= 200) f_145300(0xadc00, 0, 0x1e00);
        else f_13efd0(0, 0, 0x1ae, 0x280, 0x32, 0);
        d_1c00ec = 0;
    }
    if (d_1c00f6 <= 200) f_05e2d0(d_1c00f0, 0, 0x140, 0, 1);
    else f_05e2d0(d_1c00f0, 0, 0x280, 0, 1);
    f_05e320(d_1c00f0, S16(p1,8), 0);
    f_05e420(d_1c00f0, 8);
    if (d_1c0100 == 0xc0001) {
        b[0] = (char)0xf1; b[1] = 0;
        f_0e9660(d_1c00f0, (int)b, 0, 0);
    }
    f_0e9660(d_1c00f0, p1 + 12, S16(p1,4), S16(p1,6));
    d_1c00ec = 1;
}
//@ f_0ef1d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion richtet eine automatische Bildsequenz-Weiterschaltung (Sprite-Animation mit
 *   Frame-Intervall und Wiederholungsmodus) für ein Objekt der sacc-Szene ein.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den letzten initialisierten Animationsparameter zurück.
 === Ende Beschreibung === */
int f_0ef1d0(int p1)
{
    I32(p1,0) = (int)&d_1bb64c;
    strcpy((char *)(p1 + 12), d_1b8337);
    strcpy((char *)(p1 + 0x5c), d_1b8338);
    strcpy((char *)(p1 + 0xac), d_1b8339);
    return p1;
}
//@ f_0ef250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Befehlshandler im sacc-Interpreter.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0ef250(void)
{
}
//@ f_0ef260
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt einen unbedingten oder zählerabhängigen Sprung (Schleife) auf eine andere
 *   Framenummer innerhalb des sacc-Animationsskripts aus.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Zeiger auf den aktuellen Framezähler (p2).
 * - Rückgabewert: Die Funktion gibt die neue Framenummer zurück.
 === Ende Beschreibung === */
void f_0ef260(int p1, int *p2, int *p3, int *p4, short *p5, short *p6, short *p7, short *p8)
{
    *p2 = p1 + 12;
    *p3 = p1 + 0x5c;
    *p4 = p1 + 0xac;
    *p5 = S16(p1,4);
    *p6 = S16(p1,6);
    *p7 = S16(p1,8);
    *p8 = S16(p1,10);
}
//@ f_0ef2b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verzweigt mit einer im Befehl angegebenen Zufallswahrscheinlichkeit auf einen
 *   alternativen Frameabschnitt der Animation (beispielsweise für zufällige Blinzel- oder Umgebungseffekte).
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Zeiger auf den Framezähler (p2).
 * - Rückgabewert: Die Funktion gibt den Ergebniswert der Zufallsprüfung zurück.
 === Ende Beschreibung === */
void f_0ef2b0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
    S16(p1,4) = (short)p5;
    S16(p1,6) = (short)p6;
    S16(p1,8) = (short)p7;
    S16(p1,10) = (short)p8;
    f_148143(p1 + 12, p2, 0x4f);
    f_148143(p1 + 0x5c, p3, 0x4f);
    f_148143(p1 + 0xac, p4, 0x4f);
}
//@ f_0ef310
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ändert die Abspielgeschwindigkeit (Verzögerung zwischen zwei Frames) der laufenden
 *   sacc-Animation.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den neu gesetzten Zeitwert zurück.
 === Ende Beschreibung === */
void f_0ef310(void)
{
    if (d_1c00f6 <= 200) f_145300(0xadc00, 0, 0x1e00);
    else f_13efd0(0, 0, 0x1ae, 0x280, 0x32, 0);
}
//@ f_0ef360
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet ein einzelnes Sprite- oder Bildobjekt der sacc-Animation unter
 *   Berücksichtigung von Modus, Skalierung, Spiegelung und RLE-/Transparenzkompression in den Zielpuffer.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Sprite-Eintrag oder die Zeichenparameter (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Grafikzeichenroutine zurück.
 === Ende Beschreibung === */
void f_0ef360(int p1, int p2)
{
    int redraw = 1;
    short key = 0;
    short sel = 0;
    short c;
    int p3;
    int s1, s2, s3;
    if (d_1c00ec == 1) {
        if (d_1c00f6 <= 200) f_145300(0xadc00, 0, 0x1e00);
        else f_13efd0(0, 0, 0x1ae, 0x280, 0x32, 0);
        d_1c00ec = 0;
    }
    if (d_1c00f6 <= 200) f_05e2d0(d_1c00f0, 0, 0x140, 0, 1);
    else f_05e2d0(d_1c00f0, 0, 0x280, 0, 1);
    f_05e420(d_1c00f0, 8);
    f_149d20();
    for (;;) {
        f_146dfa(d_1a9698, 1);
        c = _bios_keybrd(1);
        if (c) {
            key = _bios_keybrd(0);
            if (key == 0x4800)
            {
                if (sel > 0) sel--; else sel = 1;
                redraw = 1;
            }
            else if (key == 0x5000)
            {
                if (sel < 1) sel++; else sel = 0;
                redraw = 1;
            }
        }
        if (redraw == 1) {
            f_05e320(d_1c00f0, S16(p1,8), 0);
            f_0e9660(d_1c00f0, (p1 + 12), S16(p1,4), S16(p1,6));
            f_05e320(d_1c00f0, sel == 0 ? S16(p1,10) : S16(p1,8), 0);
            f_0e9660(d_1c00f0, (p1 + 0x5c), S16(p1,4), (short)(S16(p1,6) + 8));
            f_05e320(d_1c00f0, sel == 1 ? S16(p1,10) : S16(p1,8), 0);
            redraw = 0;
            f_0e9660(d_1c00f0, (p1 + 0xac), S16(p1,4), (short)(S16(p1,6) + 0x10));
        }
        if (key == 0x1c0d) {
            if (d_1c00f6 <= 200) f_145300(0xadc00, 0, 0x1e00);
            else f_13efd0(0, 0, 0x1ae, 0x280, 0x32, 0);
            d_1c00f4 = sel;
            return;
        }
    }
}
//@ f_0ef590
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion kopiert einen rechteckigen Bildausschnitt innerhalb der sacc-Animationspuffer ohne
 *   Transparenzprüfung.
 * - Eingaben: Die Funktion erhält die Quell- und Zielpufferzeiger sowie die Abmessungen (p1 bis p4).
 * - Rückgabewert: Die Funktion gibt den Zeiger oder Status nach dem Kopiervorgang zurück.
 === Ende Beschreibung === */
void f_0ef590(int p1, int p2, int p3)
{
    int obj = 0;
    int b, a;
    short k = 0;
    // haelt die Symboltabellenfolge der Vftables fuer die Registervergabe wie im Original
    d_1bb664 = (d_1bb664 & 0) ? 0 : d_1bb664;
    d_1bb65c = (d_1bb65c & 0) ? 0 : d_1bb65c;
    d_1bb654 = (d_1bb654 & 0) ? 0 : d_1bb654;
    do {
        if (I32(p1 + k * 4, 0x274) != 0) {
            f_0eeea0(I32(p1 + k * 4, 0x274), (short *)&a, (short *)&b, &obj);
            if ((unsigned short)p3 != (unsigned short)a) goto cmp;
            if ((unsigned short)b == (unsigned short)p2) {
                ((VF)I32(I32(obj,0),4))(obj, I32(p1,0x3b80));
                ((VF)I32(I32(obj,0),0))(obj, I32(p1,0x3b80));
            }
        }
next: ;
    } while (++k < (short)300);
    goto end;
cmp:
    if ((unsigned short)p3 >= (unsigned short)a) goto next;
end:
    // haelt die Symboltabellenfolge der Vftables fuer die Registervergabe wie im Original
    d_1bb664 = (d_1bb664 & 0) ? 0 : d_1bb664;
    d_1bb65c = (d_1bb65c & 0) ? 0 : d_1bb65c;
    d_1bb654 = (d_1bb654 & 0) ? 0 : d_1bb654;
    d_1bb64c = (d_1bb64c & 0) ? 0 : d_1bb64c;
}
//@ f_0ef620
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion kopiert einen rechteckigen Bildausschnitt unter Auslassung transparenter Quellpixel
 *   (Farbindex 0) in den Animations-Bildpuffer.
 * - Eingaben: Die Funktion erhält die Quell- und Zielzeiger sowie die Abmessungen des Bildausschnitts (p1 bis
 *   p4).
 * - Rückgabewert: Die Funktion liefert den Zeiger nach Abschluss des Kopierens zurück.
 === Ende Beschreibung === */
void f_0ef620(int p1, int p2)
{
    int obj = 0;
    int a, b;
    short k = 0;
    do {
        if (I32(p1 + k * 4, 0x274) != 0) {
            f_0eeea0(I32(p1 + k * 4, 0x274), (short *)&a, (short *)&b, &obj);
            if ((unsigned short)p2 != (unsigned short)b) goto cmp;
            ((VF)I32(I32(obj,0),4))(obj, I32(p1,0x3b80));
        }
next: ;
    } while (++k < (short)300);
    goto end;
cmp:
    if ((unsigned short)p2 >= (unsigned short)b) goto next;
end:
    ;
}
//@ f_0ef690
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion füllt den gesamten Animations-Hintergrundpuffer mit einem einheitlichen Farbindex.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz mit der Füllfarbe (p1).
 * - Rückgabewert: Die Funktion gibt das Ergebnis der Speicherfülloperation zurück.
 === Ende Beschreibung === */
void f_0ef690(int p1, int p2)
{
    f_0ef590(d_1c00e8, (unsigned short)p1, (unsigned short)p2);
}
//@ f_0ef6b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet ein gefülltes einfarbiges Rechteck an den im sacc-Befehl angegebenen
 *   Koordinaten in den Animationspuffer.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Zeichenoperation zurück.
 === Ende Beschreibung === */
void f_0ef6b0(int p1)
{
    f_0ef620(d_1c00e8, p1);
}
//@ f_0ef720
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dekomprimiert ein lauflängencodiertes (RLE) oder gepacktes Einzelbild einer sacc-Spur
 *   in den Zielbildpuffer.
 * - Eingaben: Die Funktion erhält den Quellzeiger auf die gepackten Bilddaten (p1), den Zielpuffer (p2) sowie
 *   die Bildabmessungen (p3, p4).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Entpacken zurück.
 === Ende Beschreibung === */
void __cdecl paletteRead494(int,int,int);
#pragma aux paletteRead494 "f_149eb4" modify exact [eax ecx edx];
void f_0ef720(int p1, int p2)
{
    void *f_147c84(void *, int, void *);
    int p2_ = 0;
    int p1_ = 0;
    p1_ = p1;
    p2_ = p2;
    int sv2;
    int sv1 = d_1c0c94;
    int esi, n;
    short sv;
    esi = (int)f_147c84(new (mark(d_1a6678, 0x4a7)) char[0x300], 0x100, &d_1baac0);
    esi = esi ? esi : 0;
    sv2 = d_1c2a80;
    d_1c2a80 = 0;
    d_1c0c94 = 0;
    d_1c0c4c = d_1c0c4c + 1;
    if (d_1bc760 != 0) f_01cef0(d_1bc760);
    f_0d2710();
    f_09ac80(d_1a34e0, 0, 0);
    paletteRead494(esi, 0, 0x100);
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    f_0f1560((int)&d_1c2e68);
    sv = f_0d40b6((int)&d_1c2e78);
    f_0d4070((int)&d_1c2e78);
    int raw = NEWBIG(0x4c2);
    n = raw ? f_0ed980(raw, p1_, p2_) : raw;
    f_0ee070(n);
    if (n) operator delete((void *)f_0edef0(n, 0));
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    f_0d3f25((int)&d_1c2e78, sv);
    f_09ade0(d_1a34e0, 0, 0);
    f_09aed0(0);
    f_0d2f90(0, 1);
    f_0d26e0();
    if (p1_ != 0x40000) f_09a120(esi, 0x19);
    f_0d4880((int)&d_1c2e68);
    f_0f00f0((int)&d_1c2e68);
    operator delete((void *)esi);
    d_1c0c94 = sv1;
    d_1c2a80 = sv2;
    d_1c0c4c = d_1c0c4c - 1;
}
//@ f_0ef8d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt den Wert einer internen Register- oder Skriptvariable der sacc-Animation auf
 *   eine Konstante.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den zugewiesenen Wert zurück.
 === Ende Beschreibung === */
void f_0ef8d0(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x10000, 0x10000);
}
//@ f_0ef8f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion addiert einen konstanten Wert auf eine interne Skriptvariable der sacc-Animation.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den neuen Variablenwert zurück.
 === Ende Beschreibung === */
void f_0ef8f0(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x20000, 0x10000);
}
//@ f_0ef910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion subtrahiert einen konstanten Wert von einer internen Skriptvariable der
 *   sacc-Animation.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den neuen Variablenwert zurück.
 === Ende Beschreibung === */
void f_0ef910(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x30000, 0x10000);
}
//@ f_0ef930
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion kopiert den Wert einer internen sacc-Skriptvariable in eine andere Skriptvariable.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den kopierten Wert zurück.
 === Ende Beschreibung === */
void f_0ef930(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x40000, 0x10000);
}
//@ f_0ef950
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion addiert den Wert einer zweiten sacc-Skriptvariable auf die erste Zielvariable.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt die berechnete Summe zurück.
 === Ende Beschreibung === */
void f_0ef950(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x50000, 0x10000);
}
//@ f_0ef970
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion subtrahiert den Wert einer zweiten sacc-Skriptvariable von der ersten Zielvariable.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt die berechnete Differenz zurück.
 === Ende Beschreibung === */
void f_0ef970(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x60000, 0x10000);
}
//@ f_0ef990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion weist einer sacc-Skriptvariable eine Zufallszahl in einem durch den Befehl
 *   vorgegebenen Wertebereich zu.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt die erzeugte Zufallszahl zurück.
 === Ende Beschreibung === */
void f_0ef990(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x70000, 0x10000);
}
//@ f_0ef9b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob eine sacc-Skriptvariable gleich einem Vergleichswert ist, und führt bei
 *   Übereinstimmung einen bedingten Sprung auf einen Zielframe aus.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Zeiger auf den aktuellen Framezähler (p2).
 * - Rückgabewert: Die Funktion gibt die (gegebenenfalls geänderte) Framenummer zurück.
 === Ende Beschreibung === */
void f_0ef9b0(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 1;
    f_0ef720(0x80000, 0x10000);
}
//@ f_0ef9e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob eine sacc-Skriptvariable ungleich einem Vergleichswert ist, und springt bei
 *   Erfolg auf den angegebenen Zielframe.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Zeiger auf den aktuellen Framezähler (p2).
 * - Rückgabewert: Die Funktion gibt die aktuelle oder neue Framenummer zurück.
 === Ende Beschreibung === */
void f_0ef9e0(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 1;
    f_0ef720(0xf0000, 0x10000);
}
//@ f_0efa10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob eine sacc-Skriptvariable kleiner als ein Vergleichswert ist, und führt bei
 *   erfüllter Bedingung einen Sprung im Animationsskript aus.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Zeiger auf den Framezähler (p2).
 * - Rückgabewert: Die Funktion gibt die resultierende Framenummer zurück.
 === Ende Beschreibung === */
void f_0efa10(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x90000, 0x10000);
}
//@ f_0efa30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob eine sacc-Skriptvariable größer als ein Vergleichswert ist, und verzweigt
 *   bei erfüllter Bedingung auf den Zielframe.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Zeiger auf den Framezähler (p2).
 * - Rückgabewert: Die Funktion gibt die resultierende Framenummer zurück.
 === Ende Beschreibung === */
void f_0efa30(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0xb0000, 0x10000);
}
//@ f_0efa50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet während einer laufenden sacc-Animation eine Textzeile (Untertitel oder
 *   Beschriftung) an den im Befehl hinterlegten Koordinaten ein.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1) sowie den Basiszeiger der Animationsdaten (p2).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0efa50(void)
{
    signed char c = d_1bfb10;
    d_1c0104 = 1;
    if (c == 1 && d_1c1110 == 1) { d_1c00f8 = 1; f_0ef720(0xa0001, 0x10000); }
    else { d_1c00f8 = 0; f_0ef720(0xa0000, 0x10000); }
}
//@ f_0efaa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet für eine laufende Palettenüberblendung der sacc-Animation den nächsten
 *   Zwischenschritt der RGB-Farbwerte und überträgt die Palette an die Grafikkarte.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1).
 * - Rückgabewert: Die Funktion gibt den Status der Palettenaktualisierung zurück.
 === Ende Beschreibung === */
void f_0efaa0(void)
{
    signed char c = d_1bfb10;
    d_1c0104 = 0;
    d_1c0108 = 1;
    if (c == 1 && d_1c1110 == 1) { d_1c00f8 = 1; f_0ef720(0xc0001, 0x10000); }
    else { d_1c00f8 = 0; f_0ef720(0xc0000, 0x10000); }
    d_1c0108 = 0;
}
//@ f_0efb10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt das Abbruch- oder Ende-Flag der laufenden sacc-Sequenz, sodass der Player nach
 *   dem aktuellen Frame anhält.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück.
 === Ende Beschreibung === */
void f_0efb10(void)
{
    d_1c0104 = 0;
    d_1c00f8 = 0;
    f_0ef720(0xd0000, 0x10000);
}
//@ f_0efb30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet während der Animation die Unterbrechbarkeit durch den Benutzer
 *   (Tastatur/Maus-Abbruch erlaubt oder gesperrt) um.
 * - Eingaben: Die Funktion erhält den Befehlsdatensatz (p1).
 * - Rückgabewert: Die Funktion gibt den gesetzten Schalterwert zurück.
 === Ende Beschreibung === */
void f_0efb30(void)
{
    d_1c00f8 = 0;
    d_1c0104 = 0;
    f_0ef720(0x100000, 0x10000);
}
//@ f_0efb50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion skaliert und zeichnet ein Sprite der sacc-Animation mit frei wählbarer Zielbreite und
 *   Zielhöhe (Zoom-Effekt) unter Berücksichtigung des Clipping-Rechtecks in den Bildpuffer.
 * - Eingaben: Die Funktion erhält den Quellbildzeiger, die Zielkoordinaten sowie die skalierten Breiten- und
 *   Höhenwerte (p1 bis p6).
 * - Rückgabewert: Die Funktion gibt den Status nach Abschluss des skalierten Zeichnens zurück.
 === Ende Beschreibung === */
static inline int h_efb50_eq(const signed char &a,int b){return a==b;}
static inline void h_efb50_reset(int n,int text,int sound,int &name,int &entries)
{
 f_0ede30(n);
 name=n+0x1ac;f_145300(name,0,200);
 f_145300(n+0x1c,0,400);
 entries=n+0x274;f_145300(entries,0,1200);
 int last=0;last=n+0x724;f_145300(last,0,200);
 S16(n,0x3b84)=0;S16(n,0x3b86)=0;I32(n,0x3b8c)=0;
 I32(n,0x3b7c)=text;I32(n,0x3b80)=sound;
}
int f_0efb50(void)
{
 struct L{int flag,save,pal,p1,p2,sv;}l;
 int n,pal;
 l.flag=0;l.save=d_1c0c94;
 void *f_147c84(void *, int, void *);
 pal=(int)f_147c84(new (mark(d_1a6678, 0x583)) char[0x300], 0x100, &d_1baac0);
 l.pal=pal?pal:0;
 d_1c2a80=0;d_1c0c94=0;d_1c0104=0;++d_1c0c4c;d_1c00f8=0;
 if(d_1bc760)f_01cef0(d_1bc760);
 f_0d2710();f_09ac80(d_1a34e0,0,0);
 f_149eb4(l.pal,0,256);f_09a140(0,25);f_09a0d0(d_1a34e0);
 f_0f1560((int)&d_1c2e68);l.sv=f_0d40b6((int)&d_1c2e78);f_0d4070((int)&d_1c2e78);
 d_1c00fc=1;
 if(h_efb50_eq((signed char&)d_1bf2f0,1)){
  int raw=NEWBIG(0x5a0);n=raw?f_0ed980(raw,0xe000f,0x1000a):raw;
  f_0ee070(n);
 }else{
  int raw=NEWBIG(0x5a5);int cur=raw?f_0ed980(raw,0xe0000,0x10000):raw;
  n=cur;f_0ee070(cur);l.flag=1;
  if(d_1c00f4!=1)goto end_chain;
  h_efb50_reset(cur,0xe0003,0x10003,l.p2,l.p1);f_0ee070(cur);
  if(d_1c00f4!=1)goto end_chain;
  h_efb50_reset(cur,0xe0005,0x10004,l.p2,l.p1);f_0ee070(cur);
  if(d_1c00f4!=0)goto end_chain;
  h_efb50_reset(cur,0xe0007,0x10005,l.p2,l.p1);f_0ee070(cur);
  if(d_1c00f4!=0)goto end_chain;
  h_efb50_reset(cur,0xe0009,0x10006,l.p2,l.p1);f_0ee070(cur);
  if(d_1c00f4!=1)goto end_chain;
  h_efb50_reset(cur,0xe0012,0x1000b,l.p2,l.p1);l.flag=0;f_0ee070(cur);
 end_chain:
  if(l.flag==1){f_0ede30(n);
  f_145300(n+0x1ac,0,200);f_145300(n+0x1c,0,400);
  f_145300(n+0x274,0,1200);f_145300(n+0x724,0,200);
  S16(n,0x3b84)=0;S16(n,0x3b86)=0;I32(n,0x3b8c)=0;
  I32(n,0x3b7c)=0xe000b;I32(n,0x3b80)=0x10007;f_0ee070(n);}
 }
 if(n)operator delete((void*)f_0edef0(n,0));
 d_1c00fc=0;f_09a140(0,25);f_09a0d0(d_1a34e0);
 f_0d3f25((int)&d_1c2e78,(short)l.sv);
 f_09ade0(d_1a34e0,0,0);f_09aed0(0);f_0d26e0();
 if(l.flag==1)f_09a120(l.pal,25);
 f_0d4880((int)&d_1c2e68);f_0f00f0((int)&d_1c2e68);operator delete((void*)l.pal);
 d_1c0c94=l.save;--d_1c0c4c;return l.flag;
}
