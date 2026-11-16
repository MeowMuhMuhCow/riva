/* === Beschreibung (Katalog) ===
 * Einheit xdialog_t1 (0x140B40 - 0x141D30)
 *
 * Überblick
 *
 * Die Einheit xdialog_t1 bildet den ersten Hauptteil des erweiterten Multiple-Choice-Dialogsystems
 * (xdialog.cpp), über das in *Schatten über Riva* sämtliche Gespräche mit Nichtspielercharakteren (NSCs)
 * abgewickelt werden. Sie kümmert sich um das Laden des Dialogfensters (0x150004), der Schaltflächengrafiken
 * (0x150005), des NSC-Porträts (0x150000) und der binären Dialogskriptdatei (f_140d00), das Lesen und Speichern
 * des Gesprächsfortschritts in der temporären Statusdatei (0x40000000), den Aufbau der rechten Themenliste
 * (f_140f20), das Formatieren und Zeichnen einzelner Redeabsätze (f_1414e0 / f_141720) sowie das Anzeigen und
 * Abfragen von Multiple-Choice-Antwortverzweigungen (f_141a40 / f_141c00).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 10/16 gleich (suche.py 25.10.2026, Basis xdialog_t1_P1.CPP)
// xdialog.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x140B40-0x143330
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e240(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_01e290(int p1, int p2);                           // reg eax stapel 0
int f_01e3a0(int p1, int p2);                           // reg eax edx stapel 0
int f_01e430(int p1, int p2);                           // reg eax edx stapel 0
int f_01e570(int p1);                                   // reg eax stapel 0
int f_04fe30(int p1, int p2);
int f_04fe60(int p1, int p2);                           // reg eax stapel 0
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
int f_05e1f0(int p1);                                   // reg eax stapel 0
int f_05e200(int p1);                                   // reg eax stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e420(int p1, int p2);
int f_0e9650(int p1, int p2);                           // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9650(int p1, int p2);                         // reg eax edx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                   // reg eax ebx stapel 0
                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0

                   // reg eax edx ebx stapel 0
int f_145970(int p1, int p2);                           // reg eax edx stapel 0
int f_1459d0(int p1, int p2);
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b10(int p1);                                   // reg eax stapel 0
int f_149cf0(int p1);                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a94b0;                    // 0x1A94B0
extern int d_1a9564;                    // 0x1A9564
extern int d_1a965c;                    // 0x1A965C
extern int d_1b8708;                    // 0x1B8708
extern int d_1b870a;                    // 0x1B870A
extern int d_1b870b;                    // 0x1B870B
extern unsigned short d_1bd762;
extern int d_1bd766;
extern int d_1bf510;                    // 0x1BF510
extern int d_1bf514;                    // 0x1BF514
extern volatile short d_1bf51c;         // haelt die Lade-/Speicherfolge und Inline-Entscheidung in f_141420 und f_141820 wie im Original
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern int d_1c1160;                    // 0x1C1160
extern short d_1c1164;
extern short d_1c1166;
                    // 0x1C2098
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a948c[];           // Text 0x1A948C
// --- eigene Funktionen (36), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#include <stdio.h>
struct A10 { int v[10]; };
extern struct A10 d_1c1168;
extern char d_144bf0[], d_15f2d6[], d_15f269[];
void f_140980();
void f_142d20(int p1);
int f_142920(int p1);
int f_0e9690(int p1, int p2);
#define PI(p,o) (*(int *)((p)+(o)))
#define PS(p,o) (*(short *)((p)+(o)))
#define PB(p,o) (*(unsigned char *)((p)+(o)))
#define PC(p,o) (*(signed char *)((p)+(o)))
#define SS(a) (*(short *)(a))
#define OBJ ((int)&d_1c38b0)
#define OB2 ((int)&d_1c2098)
#define DELP(x) operator delete((void *)(x))


//@ f_140b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut den grafischen Rahmen des Dialogbildschirms auf: Reserviert bei Bedarf vier Hintergrund-
 *   und Schaltflächenpuffer (p1[0] für das linke Textfeld 201x149 bei (10, 50), p1[1] für die rechte Themenliste
 *   93x194 bei (226, 5), p1[2] und p1[3] für die ungedrückte und gedrückte "Ende"-Schaltfläche 92x16), zeichnet
 *   das Dialog-Hintergrundbild 0x150004 auf den Bildschirm, sichert die beiden Textfeld-Hintergründe aus dem
 *   Bildspeicher und lädt die beiden Schaltflächen-Sprites aus der Ressource 0x150005.
 * - Eingaben: Zeiger p1 (int *) auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - a: Lokales Bildlader-Objekt (164 Bytes) für das Hintergrundbild 0x150004.
 *   - b: Lokales Sprite-Lader-Objekt (32 Bytes) für die Schaltflächengrafiken 0x150005.
 *   - p1[0] bis p1[3]: Grafikpuffer für Haupttextfeld, Themenliste und die beiden Zustände der
 *     Beenden-Schaltfläche.
 === Ende Beschreibung === */
void f_140b40(int *p1)
{
    char a[164]; char b[32];
    f_145970((int)a, OB2);
    f_04fe30((int)b, 0);
    if (p1[0] == 0) { int t = (int)operator new(9, mark(d_1a948c, 599)); int s = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 0xc9, 0x95))) : t; p1[0] = s; }
    if (p1[1] == 0) { int t = (int)operator new(9, mark(d_1a948c, 0x268)); int s = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 0x5d, 0xc2))) : t; p1[1] = s; }
    if (p1[2] == 0) { int t = (int)operator new(9, mark(d_1a948c, 0x279)); int s = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 0x5c, 0x10))) : t; p1[2] = s; }
    if (p1[3] == 0) { int t = (int)operator new(9, mark(d_1a948c, 0x28a)); int s = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 0x5c, 0x10))) : t; p1[3] = s; }
    f_0d2710();
    f_145a10((int)a, 0x150004, d_1a34e0);
    f_145b10((int)a);
    ((RivaRasterImage*)(p1[0]))->f_0fafb0((void *)( d_1a34e0), 10, 0x32);
    ((RivaRasterImage*)(p1[1]))->f_0fafb0((void *)( d_1a34e0), 0xe2, 5);
    f_04fef0((int)b, 0x150005, ((int)(((RivaRasterImage*)(p1[2]))->f_0fb0b0())), 0, 0, 0, 0x140);
    f_04fef0((int)b, 0x150005, ((int)(((RivaRasterImage*)(p1[3]))->f_0fb0b0())), 0, 1, 0, 0x140);
    f_0d26e0();
    f_04fe60((int)b, 0);
    f_1459d0((int)a, 0);
}

//@ f_140d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die binäre Dialogressource self->fileId über den Dateimanager d_1c2098 in einen neu
 *   angelegten Puffer self->data und richtet die acht Abschnittszeiger p0 bis p7 (für Porträt-/Kopfdaten,
 *   Themenzuordnung, Themenphasen, Aktionsskripte, Antwortverzweigungen, Textabsätze, Parameterlisten und
 *   Rohtexte) anhand des Dateikopfes (Meta680) ein.
 * - Eingaben: Zeiger self (Dialog680 *) auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Dateigröße der Dialogressource self->fileId in Bytes.
 *   - header: Zeiger auf den 40-Byte-Kopfblock (Meta680) am Anfang von self->data.
 *   - self->height: Aus dem ersten Datenblock (*(short *)(self->p0 + 6) + 3) gelesene Zeilenhöhe.
 === Ende Beschreibung === */
#pragma pack(push,1)
struct Dialog680 {
 char unknown00[0x10];unsigned fileId;char unknown14[0x35-0x14];
 char *data,*p0,*p1,*p2,*p3,*p4,*p5,*p6,*p7;
 char unknown59[4];int state;char unknown61[0xa7-0x61];short height;
};
struct Meta680 {int unknown[2];int p0,p1,p2,p3,p4,p5,p6,p7;};
#pragma pack(pop)
void f_140d00(Dialog680 *self)
{
 
 self->state=0;
 if(self->data){operator delete(self->data);self->data=0;}
 int n=((int)(((RivaFileManager*)(OB2))->f_144a30(self->fileId)));
 self->data=new(mark(d_1a948c,0x2d1))char[n];
 ((RivaFileManager*)(OB2))->f_1448d0(self->fileId,(void *)(self->data));
 Meta680 *header=(Meta680*)self->data;
 self->p0=self->data+header->p0;
 self->p1=self->data+header->p1;
 self->p2=self->data+header->p2;
 self->p3=self->data+header->p3;
 if(header->p4) self->p4=self->data+header->p4;
 self->p5=self->data+header->p5;
 if(header->p6) self->p6=self->data+header->p6;
 self->p7=self->data+header->p7;
 self->height=*(short*)(self->p0+6)+3;
}
//@ f_140de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den bisherigen Gesprächsstand für den aktuellen Dialogpartner (PS(p1, 0x1F)) aus der
 *   temporären Spielstandsdatei 0x40000000 (in dem Unterverzeichnis PI(p1, 0x1B)): Positioniert den Dateizeiger
 *   auf den Datensatz (PB(p1, 0x1A) + 4) * PS(p1, 0x1F) + 6 und liest das 4-Byte-Flag "bereits begrüßt" (p1 +
 *   0x9B) sowie das Array der aktuellen Themenphasen (PI(p1, 0xAB), Länge PB(p1, 0x1A)).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sv: Gesicherter vorheriger Archiv-/Pfadkontext d_1a965c.
 === Ende Beschreibung === */
void f_140de0(int p1)
{
    int sv;
    void *t;
    if (PI(p1,0xab) == 0) PI(p1,0xab) = (int)operator new[](PB(p1,0x1a), mark(d_1a948c, 0x311));
    sv = d_1a965c;
    d_1a965c = PI(p1,0x1b);
    ((RivaFileManager*)(OB2))->f_1448b0( 0x40000000, 0x200);
    ((RivaFileManager*)(OB2))->f_144ab0( (PB(p1,0x1a) + 4) * PS(p1,0x1f) + 6, 0);
    { int q = p1 + 0x9b; q = (q & 0) ? 0 : q; sv = (sv & 0) ? 0 : sv; ((int)(((RivaFileManager*)(OB2))->f_144920((void *)( q), 4))); } // haelt die Registerzuteilung von q und sv wie im Original
    ((int)(((RivaFileManager*)(OB2))->f_144920((void *)( PI(p1,0xab)), PB(p1,0x1a))));
    ((RivaFileManager*)(OB2))->f_1449a0();
    d_1a965c = sv;
    d_1bf510 = (d_1bf510 & 0) ? 0 : d_1bf510; // haelt die Registerfolge am Funktionsende wie im Original
}

//@ f_140e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt den aktuellen Gesprächsstand des Dialogpartners (p1 + 0x9B und das Themenphasen-Array
 *   PI(p1, 0xAB)) an die zugehörige Offsetposition (PB(p1, 0x1A) + 4) * PS(p1, 0x1F) + 6 in der temporären
 *   Spielstandsdatei 0x40000000 zurück.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sv: Gesicherter vorheriger Wert von d_1a965c.
 === Ende Beschreibung === */
void f_140e90(int p1)
{
    int sv;
    sv = d_1a965c;
    d_1a965c = PI(p1,0x1b);
    ((RivaFileManager*)(OB2))->f_1448b0( 0x40000000, 0x201);
    ((RivaFileManager*)(OB2))->f_144ab0( (PB(p1,0x1a) + 4) * PS(p1,0x1f) + 6, 0);
    ((int)(((RivaFileManager*)(OB2))->f_144960((void *)( p1 + 0x9b), 4)));
    ((int)(((RivaFileManager*)(OB2))->f_144960((void *)( PI(p1,0xab)), PB(p1,0x1a))));
    ((RivaFileManager*)(OB2))->f_1449a0();
    d_1a965c = sv;
 // KRUECKE gleichstand (Argon 851)
}

//@ f_140f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut die Liste der aktuell im Gespräch verfügbaren Stichworte (Themen) neu auf: Leert den
 *   Textspeicher PI(p1, 0x59), setzt alle Einträge im Sichtbarkeitsarray PI(p1, 0x61) zunächst auf 0xFF
 *   (unsichtbar), durchläuft die Themen-Zuordnungstabelle PI(p1, 0x3D) und trägt jedes Thema i, das entweder ein
 *   allgemeines Thema (i >= PB(p1, 0x18)) oder im Freischaltarray PI(p1, 0x14) aktiviert ist, mit seinem Namen
 *   (0x15020002 + i) in die Auswahlliste ein.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - q: Laufzeiger über die 6-Byte-Einträge der Themen-Zuordnungstabelle PI(p1, 0x3D).
 *   - PB(p1, 0x65): Zähler für die Anzahl der aktuell in der rechten Spalte sichtbaren Gesprächsthemen.
 *   - PI(p1, 0x5D): Gültigkeitsflag der Themenliste (wird am Ende auf 1 gesetzt).
 === Ende Beschreibung === */
void f_140f20(int p1)
{
    int s, i;
    void *t;
    short *q;
    if (PI(p1,0x59) == 0) {
        { int t_ = (int)operator new(0x26, mark(d_1a948c, 0x387)); s = (t_ != 0) ? f_01e240(t_, 1, (int)d_144bf0, (int)d_15f2d6, (int)d_15f269) : t_; }
        PI(p1,0x59) = s;
    }
    f_01e570(PI(p1,0x59));
    if (PI(p1,0x61) == 0) PI(p1,0x61) = (int)operator new[](PB(p1,0x1a), mark(d_1a948c, 0x39c));
    for (i = 0; i < (int)PB(p1,0x1a); i++) *(unsigned char *)(i + PI(p1,0x61)) = 0xff;
    PB(p1,0x65) = 0;
    PB(p1,0x66) = 0;
    q = (short *)PI(p1,0x3d);
    while ((i = (int)*q) != 0) {
        i--;
        if (i >= (int)PB(p1,0x18) || (i < (int)PB(p1,0x18) && (int)*(signed char *)(i + PI(p1,0x14)) != 0)) {
            f_0e93f0(OBJ, (int)&d_1c21b4, i + 0x15020002);
            *(unsigned char *)(i + PI(p1,0x61)) = f_01e430(PI(p1,0x59), (int)&d_1c21b4);
            if (i < (int)(PB(p1,0x19) - 1)) PB(p1,0x65) = PB(p1,0x65) + 1;
        }
        q += 3;
    }
    PI(p1,0x5d) = 1;
}

//@ f_141020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das 32x32 Pixel große Porträt des aktuellen Gesprächspartners (Sprite-Index PS(PI(p1,
 *   0x39), 4) aus der Porträtdatei 0x150000), zeichnet es an die Position (12, 9) links oben ins Dialogfenster
 *   und gibt daneben den Namen des Gesprächspartners (*PI(p1, 0x39) + PI(p1, 0x55)) mit schwarzem Schatten
 *   (0xFE) und weißer Schrift (0xFF) aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - b: Lokales Sprite-Lader-Objekt (32 Bytes) für 0x150000.
 *   - s: Temporäres 32x32-Grafikobjekt für das NSC-Porträt.
 *   - l24, l2c, l20, l1c, l18, l28: Gesicherte Textfenster-Ränder und Textfarben von d_1c38b0.
 === Ende Beschreibung === */
void f_141020(int p1)
{
    char b[32];
    short l24, l20, l1c, l18, l28, l2c;
    int s;
    f_04fe30((int)b, 0);
    { int t_ = (int)operator new(9, mark(d_1a948c, 0x3e3)); s = (t_ != 0) ? ((int)(((RivaRasterImage*)(t_))->f_0fac80( 0x20, 0x20))) : t_; }
    f_04fef0((int)b, 0x150000, ((int)(((RivaRasterImage*)(s))->f_0fb0b0())), 0, (int)PS(PI(p1,0x39),4), 0, 0x140);
    {
        RivaMouseGuard mg;
        ((RivaRasterImage*)(s))->f_0fade0((void *)( d_1a34e0), 0xc, 9);
        f_05e2a0(OBJ, (int)&l24, (int)&l2c, (int)&l20, (int)&l1c);
        f_05e360(OBJ, (int)&l18, (int)&l28);
        f_05e2d0(OBJ, 0x3a, 0x92, 0xd, 1);
        f_05e320(OBJ, 0xfe, -1);
        { int *q = (int *)PI(p1,0x39); int n = PI(p1,0x55); f_0e9650(OBJ, *q + n); }
        f_05e2d0(OBJ, 0x39, 0x92, 0xc, 1);
        f_05e320(OBJ, 0xff, -1);
        { int *q = (int *)PI(p1,0x39); int n = PI(p1,0x55); f_0e9650(OBJ, *q + n); }
        f_05e320(OBJ, (int)l18, (int)l28);
        f_05e2d0(OBJ, (int)l24, (int)l2c, (int)l20, (int)l1c);
        if (s) DELP(((int)(((RivaRasterImage*)(s))->f_0fad20( 0))));
    }
    f_04fe60((int)b, 0);
}

//@ f_1411e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die p2-te sichtbare Themenzeile in der rechten Auswahlspalte bei x = 226, y = 5 + 9 *
 *   (p2 - 1) mit Schatteneffekt (0xFE) und der angegebenen Vordergrundfarbe p3 (z. B. 0xFF für normal, 0xFC für
 *   hervorgehoben, 0xCD für abgeblendet).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, 1-basierte sichtbare Zeilennummer p2 (signed char) und Farbwert
 *   p3 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Ermittelter interner Themenindex zur sichtbaren Zeile p2.
 *   - s2: Zeiger auf die Zeichenkette des Themennamens aus dem Textpuffer PI(p1, 0x59).
 === Ende Beschreibung === */
void f_1411e0(int p1, signed char p2, short p3)
{
    short r;
    short x = 0xe2;
    short y = 5;
    short n = p2;
    int q = p1;
    unsigned char i = 0;
    short cnt = 0;
    r = -1;
    if (p2 > 0) {
        while ((short)r == (short)-1 && (int)i < (int)(PB(q,0x1a) - 1)) {
            signed char *arr = (signed char *)PI(q,0x61);
            if (arr[i] != (signed char)-1) cnt = cnt + 1;
            if (cnt == n) r = i;
            i++;
        }
    }
    if ((short)r != (short)-1) {
        y += (short)(9 * (p2 - 1));
        signed char *arr2 = (signed char *)PI(p1,0x61);
        int s2 = f_01e3a0(PI(p1,0x59), (int)arr2[r]);
        {
            RivaMouseGuard mg;
            f_05e320(OBJ, 0xfe, -1);
            f_0e9660(OBJ, s2, (short)(x + 1), (short)(y + 1));
            f_05e320(OBJ, (int)p3, -1);
            f_0e9660(OBJ, s2, (short)x, (short)y);
        }
    }
}

//@ f_141310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Beschriftung der "Ende"-Schaltfläche (Textkennung 0x15010002) zentriert im
 *   Bereich (225, 179) (92x16 Pixel) mit schwarzem Schatten (0xFE) und der gewünschten Textfarbe p2.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Textfarbe p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - w, h: Gemessene Pixelbreite und -höhe des Schaltflächentextes.
 *   - x, y: Zentrierte Ausgabekoordinaten auf der Schaltfläche.
 === Ende Beschreibung === */
void f_141310(int p1, short p2)
{
    short w, h;
    short x, y;
    f_0e93f0(OBJ, PI(p1,0xaf), 0x15010002);
    w = f_0e9690(OBJ, PI(p1,0xaf));
    h = f_05e420(OBJ, -1);
    x = (0x5c - w) / 2 + 0xe1;
    y = (0x10 - h) / 2 + 0xb3;
    {
        RivaMouseGuard mg;
        f_05e320(OBJ, 0xfe, -1);
        f_0e9660(OBJ, PI(p1,0xaf), (int)(short)(x + 1), (int)(short)(y + 1));
        f_05e320(OBJ, (int)(short)p2, -1);
        f_0e9660(OBJ, PI(p1,0xaf), (int)(short)x, (int)(short)y);
    }
}

//@ f_141420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die gesamte rechte Themenauswahlspalte sowie die "Ende"-Schaltfläche in der Farbe p2
 *   neu. Wurde die Themenliste zuvor als veraltet markiert (PI(p1, 0x5D) == 0, etwa weil im Gespräch ein neues
 *   Stichwort freigeschaltet wurde), stellt die Funktion zuerst den Spaltenhintergrund PI(p1, 4) wieder her und
 *   baut die Themenliste über f_140f20 neu auf.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Textfarbe p2 (int, z. B. 0xFF aktiv oder 0xCD inaktiv).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - c: Schleifenzähler (1 bis PC(p1, 0x65)) über alle sichtbaren Themenzeilen.
 === Ende Beschreibung === */
void f_141420(int p1, int p2)
{
    short sv = d_1bf51c;
    if (PI(p1,0x5d) == 0) {
        RivaMouseGuard mg;
        d_1bf51c = 0;
        ((RivaRasterImage*)(PI(p1,4)))->f_0fade0((void *)( d_1a34e0), 0xe2, 5);
        f_140f20(p1);
        d_1c1164 = 0;
        ((volatile short *)&d_1c1164)[1] = 0x94; // haelt den Store auf d_1c1166 und das Inlining von RivaMouseGuard wie im Original
        f_142d20(p1);
        d_1bf51c = sv; // echte Zustandssicherung von d_1bf51c im Originalcode
    }
    signed char c = 1;
    while (c <= PC(p1,0x65)) {
        f_1411e0(p1, (int)c, (int)(short)p2);
        c++;
    }
    f_141310(p1, (int)(short)p2);
}

//@ f_1414e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert und zeichnet einen einzelnen 14-Byte-Textblock p2 im linken Haupttextfenster: Löst
 *   gegebenenfalls dynamische Platzhalter (*(int *)(p2 + 3) != -1) über den Callback PI(p1, 0x2D) und sprintf
 *   auf, setzt bei wörtlicher Rede (*p2 == 1 für NSC oder *p2 == 2 für Held) Anführungszeichen <...>, wählt die
 *   Sprecherfarbe (0xF9, 0xFF, 0xF0 oder bei hervorgehobener Auswahl p3 == 1 die Farbe 0xFC) und gibt den Absatz
 *   samt Zeilenumbruch (d_1b870a) über den Textrenderer d_1c38b0 aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, Zeiger p2 (short *) auf den 14-Byte-Absatzdatensatz und
 *   Hervorhebungsflag p3 (int, 1 = aktiv markierte Antwortoption, 0 = normal).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - a: Array von bis zu 10 aufgelösten Platzhalter-Strings (a.v[0]..a.v[9]) für sprintf.
 *   - t: Sprecher-/Darstellungsart (*p2: 1 = NSC, 2 = Held, 3 = Beschreibung).
 === Ende Beschreibung === */
void f_1414e0(int p1, short *p2, int p3)
{
    struct A10 a;
    int s;
    int r;
    int w;
    unsigned short u;
    short *q;
    short t;
    char *d;
    char *fmt;
    char *src;
    int pp;
    a = d_1c1168;
    if (*(int *)(p2 + 3) != -1) {
        { int t_ = (int)operator new(0x26, mark(d_1a948c, 0x4ac)); s = (t_ != 0) ? f_01e240(t_, 1, (int)d_144bf0, (int)d_15f2d6, (int)d_15f269) : t_; }
        q = (short *)(PI(p1,0x51) + *(int *)(p2 + 3));
        while (*q != (short)-1) {
            r = ((int (*)(short))PI(p1,0x2d))(*q);
            u = f_01e430(s, r);
            w = f_01e3a0(s, u);
            a.v[u] = w;
            q++;
        }
        sprintf((char *)&d_1c21b4, (char *)(PI(p1,0x55) + *(int *)(p2 + 5)), a.v[0], a.v[1], a.v[2], a.v[3], a.v[4], a.v[5], a.v[6], a.v[7], a.v[8], a.v[9]);
        if (s != 0) {
            operator delete((void *)f_01e290(s, 0));
        }
    } else {
        char *base = (char *)PI(p1,0x55);
        strcpy((char *)&d_1c21b4, base + *(int *)(p2 + 5));
    }
    src = (char *)&d_1c21b4;
    pp = p1;
    d = (char *)PI(pp,0xaf);
    t = *p2;
    if (t == 1 || t == 2)
        *d++ = 0x3c;
    strcpy(d, src);
    if (t == 1 || t == 2)
        strcat((char *)PI(pp,0xaf), (char *)&d_1b8708);
    switch (t) {
    case 1: f_05e320(OBJ, 0xf9, -1); break;
    case 2: f_05e320(OBJ, 0xff, -1); break;
    case 3: f_05e320(OBJ, 0xf0, -1); break;
    }
    if (p3 == 1)
        f_05e320(OBJ, 0xfc, -1);
    f_0e9650(OBJ, PI(p1,0xaf));
    f_0e9650(OBJ, (int)&d_1b870a);
}

//@ f_141720
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine Folge von 14-Byte-Textabsätzen ab p2 im Haupttextfenster aus, indem f_1414e0 in
 *   einer Schleife für jeden Absatz aufgerufen wird, bis die Ende-Markierung *p2 == 4 erreicht ist.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, Startzeiger p2 (short *) auf die Absatzliste und
 *   Hervorhebungsflag p3 (int).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen (nutzt RivaMouseGuard).
 === Ende Beschreibung === */
void f_141720(int p1, short *p2, int p3)
{
    RivaMouseGuard mg;
    while (*p2 != 4) {
        f_1414e0(p1, p2, p3);
        p2 += 7;
    }
}

//@ f_141780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt die Klick-Animation der "Ende"-Schaltfläche beim Verlassen des Dialogs ab: Zeichnet das
 *   gedrückte Schaltflächen-Sprite PI(p1, 8) mit dunkler Beschriftung (0xC9), wartet 500 Zeiteinheiten
 *   (f_149cf0(0x1F4)), stellt das ungedrückte Sprite PI(p1, 0x0C) mit heller Beschriftung (0xFF) wieder her und
 *   wartet weitere 100 Einheiten.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_141780(int p1)
{
    RivaMouseGuard mg;
    ((RivaRasterImage*)(PI(p1,8)))->f_0fae30((void *)( d_1a34e0), 0xe1, 0xb3, 0);
    f_141310(p1, 0xc9);
    f_149cf0(0x1f4);
    ((RivaRasterImage*)(PI(p1,0xc)))->f_0fae30((void *)( d_1a34e0), 0xe1, 0xb3, 0);
    f_141310(p1, 0xff);
    f_149cf0(0x64);
}

//@ f_141820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt am unteren Rand des linken Textfensters (y = 191) in Farbe 0xFC den Hinweis "Weiter..."
 *   (0x15010005) an, schaltet den Mauszeiger auf das Warte-/Weiter-Symbol (f_0d5b50(1)) und wartet in einer
 *   Ereignisschleife, bis der Spieler eine Taste drückt (d_1bd762 != 0) oder eine Maustaste betätigt (f_0d3780 /
 *   f_0d37b0).
 * - Eingaben: Keine (bzw. ungenutzter Dialogzeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - l1c, l18, l14, l10, l20, l24: Gesicherte Textbereichs- und Farbeinstellungen von d_1c38b0.
 *   - sv: Gesicherter Zustand des Maus-Rechteck-Flags d_1bf51c.
 === Ende Beschreibung === */
void f_141820(void)
{
    short l1c, l18, l14, l10, l20, l24;
    short sv;
    f_05e2a0(OBJ, (int)&l1c, (int)&l18, (int)&l14, (int)&l10);
    f_05e2d0(OBJ, 10, 0xc9, 0xbf, 1);
    f_05e360(OBJ, (int)&l20, (int)&l24);
    f_05e320(OBJ, 0xfc, -1);
    {
        RivaMouseGuard mg;
        f_0e9550(OBJ, 0x15010005);
    }
    f_05e320(OBJ, (int)l20, (int)l24);
    f_05e2d0(OBJ, (int)l1c, (int)l18, (int)l14, (int)l10);
    sv = d_1bf51c;
    d_1bf51c = 0;
    f_0d3870();
    f_0d5b50(1);
    do {
        f_068f40();
        if (d_1bd762 != 0 || f_0d3780() != 0) break;
    } while (f_0d37b0() == 0);
    f_0d3870();
    d_1bf51c = sv;
}

//@ f_141950
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Arbeitet eine bedingte Sequenz von 14-Byte-Redeabsätzen ab p2 im Haupttextfenster (x =
 *   10..201, y = 50) ab: Prüft für jeden Eintrag (*p2 != 4) über die Bedingungsfunktion PI(p1, 0x25) mit der
 *   Bedingungsnummer p2[1], ob der Absatz gültig ist, gibt ihn bei r == 1 über f_1414e0 aus und führt
 *   anschließend die zugehörige Folgeaktion p2[2] über den Aktions-Callback PI(p1, 0x29) aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Zeiger p2 (short *) auf die bedingte Absatzsequenz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Ergebnis der Bedingungsprüfung (1 = Bedingung erfüllt, Absatz anzeigen und Aktion ausführen).
 === Ende Beschreibung === */
void f_141950(int p1, short *p2)
{
    short l1c, l18, l14, l20, l28, l24;
    int r;
    RivaMouseGuard mg;
    f_05e2a0(OBJ, (int)&l1c, (int)&l18, (int)&l14, (int)&l20);
    f_05e360(OBJ, (int)&l28, (int)&l24);
    f_05e2d0(OBJ, 10, 0xc9, 0x32, 0);
    while (*p2 != 4) {
        r = ((int (*)(int))PI(p1,0x25))((int)p2[1]);
        if (r == 1) {
            f_1414e0(p1, p2, 0);
            ((void (*)(int, int))PI(p1,0x29))(p1, (int)p2[2]);
        }
        p2 += 7;
    }
    f_05e320(OBJ, (int)l28, (int)l24);
    f_05e2d0(OBJ, (int)l1c, (int)l18, (int)l14, (int)l20);
}

//@ f_141a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet bis zu drei Multiple-Choice-Antwortmöglichkeiten aus dem aktuellen Verzweigungsblock
 *   PI(p1, 0x95) untereinander in das linke Textfenster und trägt für jede Antwortoption das umgebende
 *   Bildschirmrechteck (x0, y0, x1, y1) sowie den Rückgabecode 0x90 + Index in die Klickzonentabelle ab p1 +
 *   0x6B ein.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - PC(p1, 0x93): Anzahl der aufgebauten Antwortoptionen (0 bis 3).
 *   - p1 + 0x6B: Array von 10-Byte-Klickzonen (x0, y0, x1, y1, id), das hinter der letzten Antwort mit 0xFFFF
 *     terminiert wird.
 === Ende Beschreibung === */
void f_141a40(int p1)
{
    int flag;
    int b, c;
    short *q;
    PB(p1,0x93) = 0;
    PB(p1,0x94) = 0;
    PS(p1,0x99) = 0;
    while (*(int *)(PI(p1,0x95) + 6 + PC(p1,0x93) * 4) != -1 && PC(p1,0x93) < 3) {
        SS(PC(p1,0x93) * 10 + 0x6b + p1) = f_05e1f0(OBJ);
        SS(PC(p1,0x93) * 10 + 0x6d + p1) = f_05e200(OBJ);
        f_141720(p1,(short*)(*(char**)((char*)p1+0x4d)+*(int*)(PI(p1,0x95)+6+PC(p1,0x93)*4)),0);
        SS(PC(p1,0x93) * 10 + 0x6f + p1) = SS(PC(p1,0x93) * 10 + 0x6b + p1) + 200;
        SS(PC(p1,0x93) * 10 + 0x71 + p1) = f_05e200(OBJ) - 1;
        SS(PC(p1,0x93) * 10 + 0x73 + p1) = PC(p1,0x93) + 0x90;
        PC(p1,0x93) = PC(p1,0x93) + 1;
    }
    SS(p1 + 0x6b + PC(p1,0x93) * 10) = 0xffff;
    SS(p1 + 0x6d + PC(p1,0x93) * 10) = 0xffff;
    SS(p1 + 0x6f + PC(p1,0x93) * 10) = 0xffff;
    SS(p1 + 0x71 + PC(p1,0x93) * 10) = 0xffff;
    SS(p1 + 0x73 + PC(p1,0x93) * 10) = 0xffff;
    d_1c38b0 = (d_1c38b0 & 0) ? 0 : d_1c38b0; // haelt die Registerfolge in der End-Store-Kette wie im Original
}

//@ f_141c00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wertet eine Gesprächsverzweigung (PI(p1, 0x95)) aus: Besitzt der Knoten keine
 *   Auswahlmöglichkeiten für den Spieler (PI(PI(p1, 0x95), 6) == -1), wird automatisch der erste Folgezweig
 *   (PS(p1, 0x99) = 1) gewählt und bei p2 == 1 über f_141820 auf einen Klick gewartet; andernfalls baut die
 *   Funktion die Antwortoptionen über f_141a40 auf, aktiviert deren Maus-Klickzonen (p1 + 0x6B) und wartet in
 *   einer Eingabeschleife (f_142d20 / f_142920), bis der Spieler eine Antwort gewählt hat. Gibt anschließend den
 *   Folge-Knotenindex aus *(short *)(ix * 2 + base + 0x10) zurück.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Warte-Flag p2 (int, 1 = bei direktem Weiterlaufen ohne
 *   Antwortwahl auf "Weiter..."-Klick warten).
 * - Rückgabewert: Der 16-Bit-Index des nächsten Verzweigungsblocks (-1, wenn der Verzweigungsbaum endet).
 * - Wichtige Variablen:
 *   - u1 bis u5: Gesicherte globale Mauszonen- und Callback-Zeiger (d_1bf510..d_1bf524).
 *   - ix: Index der vom Spieler gewählten Antwort (PS(p1, 0x99)).
 === Ende Beschreibung === */
short f_141c00(int p1, int p2)
{
    short u3;
    int u2, u5, u4, u1;
    int r;

    u5 = d_1bf524;
    u4 = d_1bf520;
    u3 = d_1bf51c;
    u1 = d_1bf510;
    u2 = d_1bf514;
    if (PI(PI(p1,0x95), 6) == -1) {
        PS(p1,0x99) = 1;
        if (p2 == 1) {
            f_0d26e0();
            ((void (*)(int))f_141820)(p1);
            f_0d2710();
        }
    } else {
        f_141a40(p1);
        d_1bf51c = 0;
        *(short *)&d_1bd766 = 0;
        *(volatile int *)&d_1bf510 = p1 + 0x6b; // haelt die Store-Reihenfolge und Registerzuteilung vor der Schleife wie im Original
        *(volatile int *)&d_1bf514 = 0; // haelt den direkten Speicher-Nullstore wie im Original
        *(volatile short *)&d_1c1164 = 0; // haelt den direkten Speicher-Nullstore wie im Original
        *(volatile short *)&d_1c1166 = 0x90; // haelt die Store-Reihenfolge wie im Original
        *(volatile int *)&d_1bf524 = (int)f_140980; // haelt die Store-Reihenfolge wie im Original
        *(volatile int *)&d_1bf520 = p1 + 0x6b; // erzwingt getrenntes Berechnen/Speichern von p1 + 0x6b wie im Original
        d_1bf51c = 1;
        f_0d26e0();
        do {
            f_068f40();
            f_142d20(p1);
            r = f_142920(p1);
        } while (r == 0);
        f_0d2710();
        d_1bf51c = 0;
        d_1bf524 = u5;
        f_0d3870();
        f_0d3770();
        f_0d3770();
        d_1bf510 = u1;
        d_1bf514 = u2;
        d_1bf520 = u4;
        d_1bf51c = u3;
    }
    int ix = PS(p1,0x99);
    int base = PI(p1,0x95);
    return *(short *)(ix * 2 + base + 0x10);
}
