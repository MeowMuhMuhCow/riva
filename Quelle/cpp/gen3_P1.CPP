/* === Beschreibung (Katalog) ===
 * Einheit gen3 (095820 - 096790)
 *
 * Überblick
 * Die Einheit gen3 (Character Generation 3) übernimmt die Bildschirm- und Textausgabe im
 * Heldenerschaffungs-Editor: Sie zeichnet die 14 Grundwerte mit farblicher Hervorhebung geänderter Eigenschaften
 * (f_095820), gibt einzelne Talentwerte (f_0959c0) und Zauberwerte (f_095ae0) zweispaltig mit Farbmarkierung für
 * gestiegene oder ausgeschöpfte Werte aus und baut alle elf Karteikarten-Seiten (0..10) des
 * Generierungsbildschirms auf (f_095c40).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/4 gleich (suche.py 29.10.2026, Basis gen3_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Optionshinweis: (nur f_095c40, die ersten drei Funktionen -4r -oneatx -zp1 -s)
// gen3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct B7 { char c[7]; };
struct SO { int a[14]; short s; };
struct P2 { short x, y; };
extern struct P2 d_1a33b8[];
extern struct B7 d_1a33f0, d_1a33f8, d_1a3400;
extern signed char *d_1bc89c;
extern int d_1bc8a0;
extern char d_1c21b4[], d_1c3068[], d_1c38b0[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_133fe0(const char *p1, char *p2);
int f_0e9660(char *p1, char *p2, int p3, int p4);
int f_0e93f0(char *p1, char *p2, int p3);
int f_0e9690(char *p1, char *p2);
int f_0e9510(char *p1, int p2, int p3, int p4);
int f_05e320(char *p1, int p2, int p3);
int f_05dec0(char *p1);
int f_0936d0(int p1);
int f_040370(char *p1, int p2);
int f_0974f0(int p1, int p2);
char f_09a040(int p1);
int f_09a080(int p1);
#pragma aux f_0974f0 parm [eax edx] modify exact [eax edx]
#pragma aux f_09a040 parm [eax] modify exact [eax]
#pragma aux f_09a080 parm [eax] modify exact [eax]
short f_043ac0(int p1, int p2);
signed char f_03ad80(int p1, int p2);

short f_036ed0(int p1);
short f_036ee0(int p1, int p2);









signed char f_043b20(int p1, int p2);
signed char f_043b30(int p1, int p2);


void f_095820(int p1);
void f_0959c0(int p1, int p2, int p3, short p4);
void f_095ae0(int p1, int p2, int p3, int p4);
//@ f_095820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die 14 Eigenschaften (0..13: MU bis JZ) des aktuellen Helden an den in d_1a33b8
 *   hinterlegten Bildschirmkoordinaten aus und färbt im Eigenschaftstausch-Modus (*(int *)(p1 + 0x11b) != 0)
 *   bereits erhöhte Werte (+1) oder gesenkte Werte (-1) farblich unterschiedlich (0xfd, 0xfc, 0xff) ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generierungsstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die Koordinatentabelle d_1a33b8 bestimmt die exakte X/Y-Position jeder der 14
 *   Eigenschaften auf der ersten Seite des Charakterbogens.
 === Ende Beschreibung === */
void f_095820(int p1)
{
    char *f_148518(int value, char *buffer, int radix);
    SO output;
    char digits[12];
    register char *screen = d_1c38b0;
    short index;
    short number;

    f_125400(&output, d_1c349c, d_1c3870, d_1c3498);
    for (index = 0; (number = index) <= 13; ++index) {
        if ((signed char)f_043ac0(*(int *)(p1 + 0xdf), number)) {
            if (*(int *)(p1 + 0x11b) != 0) {
                if (*(signed char *)(p1 + number + 0x14) == 1) {
                    f_148518((signed char)f_043ac0(*(int *)(p1 + 0xdf), number), digits, 10);
                    ((int *)output.a[4])[1] = f_133fe0(d_1c3498, digits);
                    f_0e93f0(screen, d_1c21b4, f_09a080(0xfd));
                } else if (*(signed char *)(p1 + number + 0x14) == -1) {
                    f_148518((signed char)f_043ac0(*(int *)(p1 + 0xdf), number), digits, 10);
                    ((int *)output.a[4])[1] = f_133fe0(d_1c3498, digits);
                    f_0e93f0(screen, d_1c21b4, f_09a080(0xfc));
                } else {
                    f_148518((signed char)f_043ac0(*(int *)(p1 + 0xdf), number), digits, 10);
                    ((int *)output.a[4])[1] = f_133fe0(d_1c3498, digits);
                    f_0e93f0(screen, d_1c21b4, f_09a080(0xff));
                }
                f_0e9660(screen, d_1c21b4,
                          d_1a33b8[index].x,
                          (short)(d_1a33b8[index].y - 1));
            } else {
                f_148518((signed char)f_043ac0(*(int *)(p1 + 0xdf), number), digits, 10);
                f_0e9660(screen, digits,
                          d_1a33b8[number].x,
                          (short)(d_1a33b8[number].y - 1));
            }
        }
    }
    f_1254a0(&output, 0);
}
//@ f_0959c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert und zeichnet den aktuellen Wert eines Talents (p2) in einer zweispaltigen Liste ab
 *   der Basiszeile p4 (relativ zum ersten Talent p3 der Gruppe) und färbt den Zahlenwert ein, je nachdem ob das
 *   Talent bereits gesteigert wurde (0xfc) oder ob das Steigerungslimit bzw. drei Fehlversuche erreicht sind
 *   (0xfd).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p1, den Talentindex p2, den Startindex p3
 *   der aktuellen Talentgruppe sowie die Y-Startkoordinate p4 entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1bc89c liefert die Anzahl der bisherigen Fehlversuche ([0]) und
 *   erfolgreichen Steigerungen ([1]) des jeweiligen Talents.
 === Ende Beschreibung === */
void f_0959c0(int p1, int p2, int p3, short p4)
{
    short level491(int);
    #pragma aux level491 "f_036ed0" parm [eax] modify exact [eax]
    signed char skill491(int,int);
    #pragma aux skill491 "f_03ad80" parm [eax] [edx] modify exact [eax edx]
    struct Frame491 { char buf[12]; B7 format; char gap; } f;
    short delta[2];
    signed char color;
 // Vorabdeklarationen vor dem ersten Funktionsaufruf
    color=f_09a040(0xff);
    f.format=d_1a33f0;
    short first=p3; first=(first&0)?0:first; short difference=p2-first; // haelt die Registerzuteilung beim Differenzwert wie im Original
    delta[0]=difference;
    int idx=(short)p2;
    int off=idx*2;
    signed char *q=(signed char *)off; q=((int)q&0)?0:q; // haelt das Zeigerregister q wie im Original
    int limit=(d_1bc89c+(int)q)[1];
    if(level491(idx)<=limit || *(q=d_1bc89c+(int)q)==3) color=f_09a040(0xfd);
    else if(q[1]!=0) color=f_09a040(0xfc);
    sprintf(f.buf,(char *)&f.format,color,skill491(*(int *)(p1+0xdf),(short)p2),(unsigned char)f_09a040(0xff));
    short width=f_0e9690(d_1c38b0,f.buf);
    
    
    f_0e9660(d_1c38b0,f.buf,(short)(((unsigned char)delta[0]&1)?0x135-width:0xde-width),(short)(*(short *)&p4 /* haelt den Stapelzugriff auf p4 wie im Original */+(delta[0]/2)*12));
}

//@ f_095ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert und zeichnet analog zu f_0959c0 den aktuellen Wert eines Zauberspruchs (p2)
 *   zweispaltig auf den Zauberseiten der Heldenerschaffung und hebt bereits gesteigerte (0xfc) oder nicht weiter
 *   steigerbare Sprüche (0xfd) farblich hervor.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generierungskontext p1, den Zauberindex p2, den
 *   Gruppenstartindex p3 sowie die Y-Startkoordinate p4 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Statusarray d_1bc8a0 speichert Fehlversuche und Steigerungsanzahl jedes
 *   Zauberspruchs, während f_036ee0 die maximal zulässigen Steigerungen pro Spruch liefert.
 === Ende Beschreibung === */
void f_095ae0(int p1, int p2, int p3, int p4)
{
    short spell_level_494(int, int);
    #pragma aux spell_level_494 "f_036ee0" parm [eax] [edx] modify exact [eax edx]
    signed char spell_494(int, int);
    #pragma aux spell_494 "f_0430f0" parm [eax] [edx] modify exact [eax edx]
    struct Frame1154 { char buf[12]; B7 format; char gap; short delta[2]; } f;
    signed char color;
 // Vorabdeklarationen vor dem ersten Funktionsaufruf
    color=f_09a040(0xff);
    short first=p3;  // Startwert fuer die Differenzberechnung
    short difference=p2-first;
    f.delta[0]=difference;
    f.format=d_1a33f8;
    int idx=(short)p2;
    int off=idx*2;
    signed char *q=(signed char *)off;
    int limit=(*(signed char **)&d_1bc8a0+(int)q)[1];
    if(limit>=spell_level_494(idx,*(int *)(p1+0xdf)) || *(q=(*(signed char **)&d_1bc8a0)+(int)q)==3) color=f_09a040(0xfd);
    else if(q[1]!=0) color=f_09a040(0xfc);
    sprintf(f.buf,(char *)&f.format,color,spell_494(*(int *)(p1+0xdf),(short)p2),(unsigned char)f_09a040(0xff));
    short width=f_0e9690(d_1c38b0,f.buf);
    f_0e9660(d_1c38b0,f.buf,(short)(((unsigned char)f.delta[0]&1)?0x135-width:0x9d-width),(short)((short)p4+(f.delta[0]/2)*12));
}

//@ f_095c40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet abhängig von der aktuell aufgeschlagenen Seite (*(char *)(p1 + 7) von 0 bis 10) die
 *   Inhalte des Heldenerschaffungsbogens: Seite 0 (Grundwerte, Gottheit, Vermögen, LE, AE, MR, Ausdauer), Seiten
 *   1..3 (Talente und verbleibende Talentversuche), Seite 4 (Kampftalente mit AT/PA-Aufteilung und
 *   Fernkampfwerten) sowie Seiten 5..10 (Zaubersprüche nach Herkunftsgebieten und verbleibende Zauberversuche).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generierungsstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Zu Beginn jeder Seite stellt f_0974f0 die drei gesicherten Hintergrundstreifen (i_eb,
 *   i_ef, i_f3) wieder her, damit alte Zahlenwerte vor dem Neuzeichnen sauber gelöscht werden.
 === Ende Beschreibung === */
#define H *(int *)(p1 + 0xdf)
#define HDR f_0974f0(p1, f_05dec0(d_1c3068))
#define ITOA(v) itoa(v, frame.buf, 10)
#define PRN(x, y) f_0e9660(d_1c38b0, frame.buf, x, y)
void f_095c40(int p1)
{
    char attrib494(char *,short);
    #pragma aux attrib494 "f_043ac0" modify exact [eax edx];

    unsigned char lowcolor494(unsigned char);
    #pragma aux lowcolor494 "f_09a040" modify exact [eax];
    unsigned char highcolor494(unsigned char);
    #pragma aux highcolor494 "f_09a040" modify exact [eax];
    unsigned char getlevel181(char *);
    #pragma aux getlevel181 "f_0428b0" parm [eax] modify exact [eax ebx ecx];

    #pragma pack(push,4)
    struct Output494 {int a[14];short s;};
    struct Frame494 {Output494 o;char buf[12];B7 fm;} frame;
    #pragma pack(pop)
    union U1174 { int full; unsigned char byte[4]; short word[2]; } y;
    int index;
    short i,number,width,average;
    int column,row,sum,third,next_index;
    signed char value;
    width=0; width=12; width=9; width=76; width=86; width=112; width=32; width=19; width=41; width=26; width=118; // haelt die Konstanten-Reihenfolge fuer die Registerzuteilung wie im Original
    
    (void)*((unsigned char *)&p1+1); // haelt die Parameter-Sicht fuer den Stapelrahmen wie im Original
    (void)(unsigned char)p1; // haelt die Byte-Sicht des Parameters wie im Original
    frame.fm=d_1a3400;
    f_125400(&frame.o, d_1c349c, d_1c3870, d_1c3498);
    f_05e320(d_1c38b0, 0xff, -1);
    { int rt1174=d_1bc8a0; d_1bc8a0=rt1174; } // haelt die Registerzuteilung in f_095c40 wie im Original
    switch (*(char *)(p1 + 7)) {
    case 0:
        HDR;
        f_0936d0(p1);
        f_095820(p1);
        if (((char)(f_042350((struct hero *)(H))))) {
            *(unsigned short *)(frame.o.a[5] + 2) = getlevel181((char *)H);
            f_0e9510(d_1c38b0, 0xe140013, 0xcd, 0x18);
            *(short *)(frame.o.a[5] + 2) = f_0428c0((struct hero *)(H));
            f_0e9510(d_1c38b0, 0xe140014, 0xcd, 0x24);
            value = f_042390((struct hero *)(H));
            f_0e9510(d_1c38b0, value + 0x20000012, 0xcd, 0x30);
            f_040370(d_1c21b4, ((int)(f_042410((struct hero *)(H)))));
            f_0e9660(d_1c38b0, d_1c21b4, 0xcd, 0x3c);
            number = f_042960((struct hero *)(H));
            ITOA(number);
            PRN(0xac, 0xa3);
            number = f_0429a0((struct hero *)(H));
            ITOA(number);
            PRN(0xdd, 0xa3);
            sum = (short)f_042960((struct hero *)(H));
            value = (signed char)attrib494((char *)H, 6);
            ITOA(sum + value);
            width = f_0e9690(d_1c38b0, frame.buf);
            PRN((short)(0x135 - width), 0xa3);
            value = f_0423a0((struct hero *)(H));
            ITOA(value);
            PRN(0xff, 0xb7);
            f_1254a0(&frame.o, 0);
            return;
        }
        break;
    case 1:
        HDR;
        for (i = 0; i < 9; i++) f_0959c0(p1, i, 0, 41);
        { int first1174;
          for (i = 9, first1174 = 9; i < 19; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_0959c0(p1, i, first1174, 118); } }
        ITOA(((char)(f_043340((struct hero *)(H)))));
        PRN(271, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 2:
        HDR;
        for (i = 19; i < 26; i++) f_0959c0(p1,i,19,41);
        for (i = 32; i < 41; i++) f_0959c0(p1, i, 32, 112);
        ITOA(((char)(f_043340((struct hero *)(H)))));
        PRN(271, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 3:
        HDR;
        { int rt1174_3=d_1bc8a0; d_1bc8a0=rt1174_3; } // haelt die Registerzuteilung in f_095c40 wie im Original
        for (i = 41; i < 50; i++) f_0959c0(p1, i, 41, 41);
        for (i = 26; i < 32; i++) f_0959c0(p1, i, 26, 118);
        { int first1174;
          for (i = 50, first1174 = 50; i < 52; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_0959c0(p1, i, first1174, 169); } }
        ITOA(((char)(f_043340((struct hero *)(H)))));
        PRN(271, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 4:
        HDR;
        value = f_042890((struct hero *)(H));
        ITOA(value);
        PRN(0xe4, 0x1d);
        value = f_042890((struct hero *)(H));
        ITOA(value);
        PRN(0x107, 0x1d);
        index = 0;
        y.full = 0x2f;
        (void)y.byte[2]; (void)y.byte[1]; (void)y.byte[0]; // haelt die Byte-Sicht der Union y wie im Original
        for(;(short)index<7;y.full+=12,index=next_index+1) {
            column = (short)index;
            value = f_043b20(H, column);
            ITOA(value);
            row = (short)y.full;
            width = f_0e9690(d_1c38b0, frame.buf);
            PRN((short)(0xea - width), row);
            value = f_043b30(H, column);
            ITOA(value);
            width = f_0e9690(d_1c38b0, frame.buf);
            PRN((short)(0x10d - width), row);
            value = f_03ad80(H, column);
            sprintf(frame.buf,(char *)&frame.fm,(unsigned char)(value>0?highcolor494(0xfc):lowcolor494(0xfd)),value,(unsigned char)f_09a040(0xff));
            width = f_0e9690(d_1c38b0, frame.buf);
            next_index = index;
            PRN((short)(0x135 - width), (short)y.full);
        }
        sum = (signed char)attrib494((char *)H, 1);
        sum += (signed char)attrib494((char *)H, 4);
        third = (signed char)attrib494((char *)H, 6);
        average = (third + sum) / 4;
        value = f_03ad80(H, 7);
        ITOA(value + average);
        PRN(0xe4, 0x8f);
        value = f_03ad80(H, 8);
        ITOA(value + average);
        PRN(0xe4, 0x9b);
        f_1254a0(&frame.o, 0);
        return;
    case 5:
        HDR;
        { int height1174;
          for (i = 1, height1174 = 41; i < 6; i++, i=(i&0)?(short)0:i, height1174=(height1174&0)?0:height1174) { // haelt die Registerzuteilung der Schleifenvariablen wie im Original
            f_095ae0(p1,i,1,height1174); } }
        { int first1174;
          for (i = 33, first1174 = 33; i < 38; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_095ae0(p1, i, first1174, 94); } }
        { int height1174;
          for (i = 6, height1174 = 145; i <= 11; i++, i=(i&0)?(short)0:i, height1174=(height1174&0)?0:height1174) { // haelt die Registerzuteilung der Schleifenvariablen wie im Original
            f_095ae0(p1,i,6,height1174); } }
        ITOA(((char)(f_0432f0((struct hero *)(H)))));
        PRN(217, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 6:
        HDR;
        { int rt1174_6=d_1bc8a0; d_1bc8a0=rt1174_6; } // haelt die Registerzuteilung in f_095c40 wie im Original
        for (i = 12; i <= 17; i++) f_095ae0(p1,i,12,41);
        { int height1174;
          for (i = 18, height1174 = 94; i < 24; i++, i=(i&0)?(short)0:i, height1174=(height1174&0)?0:height1174) { // haelt die Registerzuteilung der Schleifenvariablen wie im Original
            f_095ae0(p1,i,18,height1174); } }
        { int first1174;
          for (i = 24, first1174 = 24; i < 27; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_095ae0(p1, i, first1174, 147); } }
        ITOA(((char)(f_0432f0((struct hero *)(H)))));
        PRN(217, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 7:
        HDR;
        { int first1174;
          for (i = 27, first1174 = 27; i < 33; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_095ae0(p1, i, first1174, 41); } }
        { int first1174;
          for (i = 38, first1174 = 38; i < 45; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_095ae0(p1, i, first1174, 94); } }
        { int first1174;
          for (i = 45, first1174 = 45; i <= 46; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_095ae0(p1, i, first1174, 159); } }
        ITOA(((char)(f_0432f0((struct hero *)(H)))));
        PRN(217, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 8:
        HDR;
        { int first1174;
          for (i = 47, first1174 = 47; i <= 48; i++, i=(i&0)?(short)0:i, first1174=(first1174&0)?0:first1174) { // haelt die Registerzuteilung des Schleifenzaehlers wie im Original
            f_095ae0(p1, i, first1174, 41); } }
        { int height1174;
          for (i = 49, height1174 = 70; i < 58; i++, i=(i&0)?(short)0:i, height1174=(height1174&0)?0:height1174) { // haelt die Registerzuteilung der Schleifenvariablen wie im Original
            f_095ae0(p1,i,49,height1174); } }
        { int height1174;
          for (i = 58, height1174 = 147; i < 60; i++, i=(i&0)?(short)0:i, height1174=(height1174&0)?0:height1174) { // haelt die Registerzuteilung der Schleifenvariablen wie im Original
            f_095ae0(p1,i,58,height1174); } }
        ITOA(((char)(f_0432f0((struct hero *)(H)))));
        PRN(217, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 9:
        HDR;
        for (i = 60; i < 76; i++) f_095ae0(p1,i,60,41);
        ITOA(((char)(f_0432f0((struct hero *)(H)))));
        PRN(217, 0xb7);
        f_1254a0(&frame.o, 0);
        return;
    case 10:
        HDR;
        for (i = 76; i < 86; i++) f_095ae0(p1,i,76,41);
        ITOA(((char)(f_0432f0((struct hero *)(H)))));
        PRN(217, 0xb7);
    }
    f_1254a0(&frame.o, 0);
}
