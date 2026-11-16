// RIVA_KOEPFE.H -- gemeinsame Kopfdatei fuer die 120 meistgerufenen Funktionen von RIVA.EXE
// Zweck : korrekte Deklarationen (Rueckgabetyp, Parameterzahl/-breite, Klasse/Methode, Konstruktor/Destruktor).
//         Nicht bytegleich. Watcom C++ 10.6: Register eax,edx,ebx,ecx, dann Stapel; this in eax; Callee raeumt (ret N).
// Stand : 2026-10-21 (Helfer K).  Quelle: Analyse/Phase4/KOEPFE.tsv + Entwuerfe unter Quelle/cpp + kopfinfo.py.
// Stand : 2026-10-23 Teil 2 (Fable K) angehaengt: mechanische Parameterzahlen fuer 4134 Funktionen, s. u.
// Regeln: "// 0xADRESSE, n Aufrufer".  "// ?" = unsicher (nicht geraten, nur Hinweis).
//         Zeilen ohne "?" stammen aus fertigen Modulen (bytegleich belegt).
// Globale Objekte: d_1c0004 (Game), d_1c2c64 (Msg), d_1c2edc (Snd), d_1c38b0 (Q), d_1c2a84 (Prn ?), d_1c2c40 (Thing-Tabelle).
#ifndef RIVA_KOEPFE_H
#define RIVA_KOEPFE_H

struct Ent; struct Thing; struct Obj; struct Cnt; struct Game; struct Img; struct Msg; struct Snd; struct Q;

// ---------------- Speicher / new / delete ----------------
void  operator delete(void *p);                                    // 0x014710, 212 Aufrufer
void *mark(const char *file, int line);                            // 0x014B10, 138 Aufrufer
void *operator new(unsigned size, void *tag);                      // 0x014AB0, 106 Aufrufer
void *operator new[](unsigned size, void *tag);                    // 0x014AC0, 76 Aufrufer
void *f_014540(int n, void *fi, int line);                         // 0x014540, 50 Aufrufer (Puffer holen; Name ?)

// Ctx: 0x3C Bytes, "Kontext" (Konstruktor/Destruktor unter Speicher, da new/delete-Paar)
struct Cell;
struct Ctx {                                                       // 0x3C Bytes (aus boron1/spell5, bytegleich belegt)
    long x0;
    Cell *r1;                                                      // +0x04
    char pad[0x34];
    Ctx(void *a, void *b, void *c);                                // 0x125400, 140 Aufrufer (meist Ctx c(d_1c349c, d_1c3870, d_1c3498))
    ~Ctx();                                                        // 0x1254A0, 140 Aufrufer
};
int   f_126410(void *p);                                           // 0x126410, 21 Aufrufer: liefert Feld [p+1] (int)
void  wait(int minutes);                                           // 0x125ED0, 36 Aufrufer
void  pass(int hours);                                             // 0x125F70, 19 Aufrufer (? Rueckgabe)

// ---------------- Meldungen ----------------
struct Msg {
    void  f_0bf730(long code);                                     // 0x0BF730, 145 Aufrufer
    int   f_0bf6f0(long code);                                     // 0x0BF6F0, 73 Aufrufer
    short f_0bf7b0(int a, long code, int b, int c, int d);         // 0x0BF7B0, 23 Aufrufer (this + 3 Reg + 2 Stapel)
};
struct Msg2 { void f_057220(long code, int z); };                  // 0x057220, 30 Aufrufer (? vermutlich Msg-Verwandter, 3 Reg)
int   f_0bf820(long p2, int n, ...);                               // 0x0BF820, 73 Aufrufer (Stapel, varargs)
void  f_0bf6c0(int a);                                             // 0x0BF6C0, 37 Aufrufer
void  f_0bf680(int sel);                                           // 0x0BF680, 37 Aufrufer
int   f_0bfa20(...);                                               // 0x0BFA20, 25 Aufrufer: reine Stapelparameter, ret ohne N (? cdecl-artig, Msg-Variante)
void  f_060740(int a, int b);                                      // 0x060740, 27 Aufrufer
void  f_0607e0(int a, char b);                                     // 0x0607E0, 19 Aufrufer: ruft 0x19c90(d_1c2a84, a-0x1F40, b) (? Typen)
void  f_060800(int a, short b, int c);                             // 0x060800, 22 Aufrufer (? 3 Reg)
int  *f_0606a0(void *self, short v);                               // 0x0606A0, 25 Aufrufer (? Rueckgabe/Typ)
int   f_060a70(int a, int b, int c);                               // 0x060A70, 23 Aufrufer (? Kopf ueberlappend, 3 Reg)
void  f_091f70(int a);                                             // 0x091F70, 30 Aufrufer
void  f_09a0d0(long a);                                            // 0x09A0D0, 30 Aufrufer
void  f_09a140(int a, int b);                                      // 0x09A140, 28 Aufrufer

// ---------------- Grafik ----------------
struct Img {
    Img(short a, short b);                                         // 0x0FAC80, 47 Aufrufer
    ~Img();                                                        // 0x0FAD20, 78 Aufrufer
    char data[9];
};
int   f_0fb0b0(Img *i);                                            // 0x0FB0B0, 45 Aufrufer
void  f_0fafb0(Img *i, int a, int b, int c);                       // 0x0FAFB0, 27 Aufrufer
void *f_0fade0(Img *i, int a, int b, int c);                       // 0x0FADE0, 45 Aufrufer (? 4 Reg, Rueckgabe unbekannt)
void  f_0fae30(Img *i, int a, int b, int c);                       // 0x0FAE30, 27 Aufrufer (? 4 Reg + 1 Stapel, ret 4; letzter Parameter Stapel)
void *f_0fac10(void *self, short a, short b, int c);               // 0x0FAC10, 17 Aufrufer (? Konstruktor-artig: [+0]=a,[+2]=b,[+4]=0)

// Q: Textfenster/Zeichenobjekt d_1c38b0 (Clip-Rechteck-Methoden und Textausgabe) -- alles ?, selbes Objekt
struct Q {
    void  f_0e93f0(char *p, long code);                            // 0x0E93F0, 48 Aufrufer
    void  f_05e320(short a, short b);                              // 0x05E320, 46 Aufrufer (? 3 Reg, sichert Felder +0x32/+0x34 nach +0x24/+0x26)
    void  f_05e2d0(short a, short b, short c, int d);              // 0x05E2D0, 23 Aufrufer (? 4 Reg inkl. this, ret 4)
    void  f_05e2a0(short *a, short *b, short *c, short *d);        // 0x05E2A0, 19 Aufrufer (? Getter, ret 4)
    void  f_05ded0(long v);                                        // 0x05DED0, 20 Aufrufer: [this+6]=v
    void  f_0e9660(short a, short b, short c);                     // 0x0E9660, 29 Aufrufer (? Sprungstub nach 0x5E860/0x5E770/0x5E610)
    int   f_0e9300(char *s, int a, int b);                         // 0x0E9300, 21 Aufrufer (? 4 Reg, nutzt strlen)
};
struct Graph {                                                     // 0x14 Bytes
    Graph *f_112df0(short n, int b, int c);                        // 0x112DF0, 25 Aufrufer: Konstruktor (4 Reg)
    void   f_112e70();                                             // 0x112E70, 25 Aufrufer: Destruktor
};
void  f_112ec0();                                                  // 0x112EC0, 25 Aufrufer
void  f_099ef0();                                                  // 0x099EF0, 26 Aufrufer (? Stapelparameter, VGA-Port 0x3D4; Anzahl unklar)
void  f_0d2710();                                                  // 0x0D2710, 78 Aufrufer
void  f_0d26e0();                                                  // 0x0D26E0, 78 Aufrufer
int   f_0d3860();                                                  // 0x0D3860, 61 Aufrufer
int   f_0d3780();                                                  // 0x0D3780, 25 Aufrufer
int   f_0d37b0();                                                  // 0x0D37B0, 32 Aufrufer: setzt [1bf4dc]=0, liefert [1bf4e4] (Maus)
int   f_0d2f90(void *self, int v);                                 // 0x0D2F90, 29 Aufrufer (? Maus, 2 Reg)
void  f_0d4880();                                                  // 0x0D4880, 20 Aufrufer: setzt d_1c016c/d_1c0170 auf 0
void  f_069460();                                                  // 0x069460, 38 Aufrufer
void  f_068f40();                                                  // 0x068F40, 22 Aufrufer
int   f_05ff60(void *self, char c);                                // 0x05FF60, 22 Aufrufer (? 2 Reg)
int   f_060030(void *self);                                        // 0x060030, 21 Aufrufer (? gibt this-2 zurueck)

// ---------------- Text / Datei / Ton ----------------
struct Snd { void f_147323(long a, int b, int c, int d, int e, int f); }; // 0x147323, 44 Aufrufer
void  f_1448b0(unsigned long id, int mode);                        // 0x1448B0, 42 Aufrufer: Datei oeffnen
void  f_1449a0();                                                  // 0x1449A0, 42 Aufrufer: Datei schliessen
void  f_144920(void *buf, int n);                                  // 0x144920, 39 Aufrufer: lesen
void  f_144960(void *buf, int n);                                  // 0x144960, 22 Aufrufer: schreiben
void  f_144ab0(long pos, int from);                                // 0x144AB0, 28 Aufrufer: suchen
short f_149360(int a);                                             // 0x149360, 35 Aufrufer
short f_1457e0(short n);                                           // 0x1457E0, 71 Aufrufer: Zufallszahl 1..n
short f_145760(short lo, short hi);                                // 0x145760, 33 Aufrufer: Zufallszahl lo..hi (? aus f_1457e0(hi-lo+1))
int   f_146dfa(void *self, int a, int b, int c);                   // 0x146DFA, 21 Aufrufer (? 4 Reg)
int   f_133fe0(char *a, Cnt *b);                                   // 0x133FE0, 64 Aufrufer
int   f_071e90(unsigned v, int *a, int *b);                        // 0x071E90, 18 Aufrufer

// ---------------- Sonstiges: Spielobjekte ----------------
struct Lock {
    Lock();                                                        // 0x0CE7C0, 35 Aufrufer: merkt d_1c0b2c, setzt 0
    ~Lock();                                                       // 0x0CE7E0, 35 Aufrufer: stellt d_1c0b2c zurueck
    short saved;
};
struct Ent {
    short f_044c90(int id, int n);                                 // 0x044C90, 37 Aufrufer
    short f_0429a0();                                              // 0x0429A0, 28 Aufrufer
    short f_03d3d0(int a, int b);                                  // 0x03D3D0 (nur im Modul belegt)
    int   f_042960();                                              // 0x042960, 45 Aufrufer
    int   f_042970();                                              // 0x042970, 20 Aufrufer
    int   f_0429b0();                                              // 0x0429B0 (im Modul belegt)
    signed char f_042400(void *p);                                 // 0x042400, 51 Aufrufer
    char  f_042470();                                              // 0x042470, 47 Aufrufer
    char  f_042350();                                              // 0x042350, 44 Aufrufer: lebt
    char *f_0422b0(int n);                                         // 0x0422B0, 27 Aufrufer
    char  f_042380();                                              // 0x042380, 43 Aufrufer: liefert Byte [+0x34]
    char  f_042a10();                                              // 0x042A10, 25 Aufrufer: [+0x33] >= 7 (bool)
    short f_042ac0(short i);                                       // 0x042AC0, 28 Aufrufer: Feld [i*27+0x1AA] (short)
    int   f_0425f0();                                              // 0x0425F0, 23 Aufrufer: Bit aus [+0xBC] (bool)
    int   f_0424e0();                                              // 0x0424E0, 20 Aufrufer: Bit aus [+0xBC] (bool)
    void  f_043e20(char v);                                        // 0x043E20, 17 Aufrufer: [+0x4FB]=v
    int   f_044850(short a, short b);                              // 0x044850, 25 Aufrufer (? 3 Reg)
    short f_044900(int a, int b);                                  // 0x044900, 18 Aufrufer (? Kopf nennt nur 1 Reg)
    int   f_042a60(int k);                                         // 0x042A60, 59 Aufrufer (Methode von Einheit u)
    void  f_044300(int k);                                         // 0x044300, 40 Aufrufer
    short f_036300(int a, int b);                                  // 0x036300, 29 Aufrufer (? 3 Reg, Rueckgabe short)
};
int   f_0d49b0(Ent *e);                                            // 0x0D49B0, 18 Aufrufer (? 1 Reg, ruft Ent::f_042350 u.a.)
int   f_0d4a60(Ent *e);                                            // 0x0D4A60, 50 Aufrufer (? 1 Reg, ruft Ent::f_042350/470/4e0)
char  f_0d54c0(Ent *e);                                            // 0x0D54C0, 22 Aufrufer: Index von e in Tabelle d_1bc8f0 (Stride 0x5EF)
short f_0d4c80(Ent *e);                                            // 0x0D4C80, 21 Aufrufer (? sucht freien Slot, 20 Eintraege a 7 Byte ab +0x55B)
void  f_0d5040(Ent *e, short idx, int a, char b, char c);          // 0x0D5040, 21 Aufrufer (? 4 Reg + 2 Stapel, ret 8)
short f_0d4aa0(void *tab, short key);                              // 0x0D4AA0, 29 Aufrufer (? 2 Reg, Suche in 31 Eintraegen a 27 Byte)
Ent  *f_04feb0(Ent *self, int a, int b, int c, int d, int e);      // 0x04FEB0, 20 Aufrufer (? Konstruktor-artig, 4 Reg + 5 Stapel? ret 0x14)
int   f_0a7950(Thing *t);                                          // 0x0A7950, 33 Aufrufer
int   f_0a7990(Thing *t);                                          // 0x0A7990, 25 Aufrufer: Flag-Bit aus [+6] (bool)
int   f_0391b0(Obj *o, int x);                                     // 0x0391B0, 28 Aufrufer
struct Game {                                                      // Typ von d_1c0004 (in manchen Modulen "Tgt")
    Ent  *f_038c40();                                              // 0x038C40, 63 Aufrufer: erster Eintrag
    int   f_038c80();                                              // 0x038C80, 26 Aufrufer
    Ent  *f_039320(int id);                                        // 0x039320, 43 Aufrufer
    short f_0d54f0(int id);                                        // 0x0D54F0, 30 Aufrufer
    long  f_0de7d0(int k);                                         // 0x0DE7D0, 27 Aufrufer
    int   f_039660(int n);                                         // 0x039660, 36 Aufrufer
    int   f_0de7f0();                                              // 0x0DE7F0, 26 Aufrufer
    void  f_0db820(int v);                                         // 0x0DB820, 18 Aufrufer
    void  f_038d70(int a);                                         // 0x038D70, 20 Aufrufer (? 2 Reg)
    void  f_039a80(int a);                                         // 0x039A80, 19 Aufrufer (? 2 Reg)
    long  f_0de7e0();                                              // 0x0DE7E0, 20 Aufrufer (? liefert Feld [+0x1D] long)
    void  f_0db8b0(long n);                                        // 0x0DB8B0, 20 Aufrufer (? zieht n von [+0x1D] ab)
    int   f_0de7c0();                                              // 0x0DE7C0, 18 Aufrufer (? Byte [+0x1C] != 0)
    void  f_0de810(short v);                                       // 0x0DE810, 17 Aufrufer (? setzt Kurzfeld [+0x23])
    short f_0db9a0();                                              // 0x0DB9A0, 28 Aufrufer (? zaehlt belegte Slots in int[7])
    short f_0dc020(int v);                                         // 0x0DC020, 23 Aufrufer (? sucht v in int[7], Index)
    Game *f_0dd7f0(int a, int b);                                  // 0x0DD7F0, 46 Aufrufer (? 3 Reg, liefert this)
    int   f_0dcf00(int a, int b);                                  // 0x0DCF00, 25 Aufrufer (? 3 Reg)
};
short f_0de820(Game *g);                                           // 0x0DE820, 44 Aufrufer
void *f_039040(Game *g);                                           // 0x039040, 30 Aufrufer
void  f_0dcbb0(Game *g, int a, int b);                             // 0x0DCBB0, 18 Aufrufer
int   f_0bbf00(void *self);                                        // 0x0BBF00, 24 Aufrufer (? 1 Reg, ruft Game::f_0de820)

// =====================================================================================================================
// Teil 2 (Fable K, 23.10.2026, Pass 2 Hebel 1): mechanisch abgeleitete PARAMETERZAHL je Funktion (inkl. this), Typen generisch int.
// Quelle: gw/koepfe_bauen.py -> gw/koepfe.tsv.  Massgeblich ist die ZAHL, nicht der Typ.  Sicherheitsgrad je Zeile:
//   sicher   = gelesene Parameterregister (clobber.tsv, hoechstes gelesenes Register + 1) | ret N bei 4 gelesenen Registern
//              (4 + N/4) | Definition in einer Einheit, in der die Funktion GLEICH ist (Basis Analyse/Pass2/zaehlen_fstand)
//              | Varargs-Menuefunktionen f_0bfa20/f_0bf980/f_0bf820 (Fable N)
//   vermutet = R106-Liste (Aufrufer setzen das Register >= 90 %, Rumpf liest es nicht; darunter die Destruktor-Flags
//              f_1254a0/f_0fad20/f_112e70) | Aufrufer-Modus aus parmzahl (>= 3 Aufrufer, >= 80 %) | ret N bei < 4 gelesenen Registern
// "deklariert AxB" = in den P1-Einheiten A Parameter in B Einheiten (Uneinheitlichkeit sichtbar).
// Vorsicht: "liest Register" ist bei Laufzeit-/Bibliotheksroutinen (0x16d000-0x170000, fz_-Einheiten) kein Parameterbeweis -
// koepfe_patch.py prueft deshalb je Aufrufstelle, ob das Original das Register wirklich setzt (sonst GESPERRT).
// Watcom: char vorzeichenlos; Parameter eax, edx, ebx, ecx, dann Stapel (Callee raeumt, ret N); this in eax; Varargs rein Stapel.
// Nur mit -DRIVA_KOEPFE_GENERISCH sichtbar (kollidiert sonst mit den Klassen in Teil 1).
#ifdef RIVA_KOEPFE_GENERISCH
int f_0100c0(int);                           // sicher; liest eax; deklariert 1x1 4x1
int f_0101e0(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_010430(int, int);                      // vermutet (sicher 0); Aufrufer-Modus 2; deklariert 0x2 2x1
int f_010440(int);                           // sicher; liest eax; deklariert 1x2
int f_010450(int);                           // sicher; liest eax; deklariert 1x2
int f_010460(int);                           // sicher; liest eax; deklariert 1x4
int f_010470(int);                           // sicher; liest eax; deklariert 1x4
int f_010480(int);                           // sicher; liest eax; deklariert 1x3
int f_010490(int);                           // sicher; liest eax; deklariert 1x2 2x1
int f_0104a0(int);                           // sicher; liest eax; deklariert -
int f_0104b0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x24
int f_010590(int, int);                      // sicher; liest eax; GLEICH-Def ace_t1:2; deklariert 1x1 2x23
int f_010640(int, int);                      // sicher; GLEICH-Def ace_t1:2; deklariert 2x2
int f_010650(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_010660(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_010670(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_010680(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_010690(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_0106a0(int, int);                      // sicher; GLEICH-Def ace_t1:2; deklariert 2x2
int f_0106b0(int, int);                      // sicher; GLEICH-Def ace_t1:2; deklariert 2x2
int f_0106c0(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_0106d0(int);                           // sicher; liest eax; deklariert 1x3
int f_0106e0(int);                           // sicher; liest eax; deklariert 1x2
int f_0109d0(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_010a20(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_010a70(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 0x1 1x2
int f_010a90(int);                           // sicher; liest eax; deklariert 1x2
int f_010e50(int);                           // sicher; liest eax; deklariert 1x2
int f_010f50(int);                           // sicher; liest eax; deklariert 1x2
int f_0110f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_011350(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_0113b0(int, int, int);                 // sicher; GLEICH-Def ace_t1:3; deklariert 3x2
int f_0113d0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x3
int f_011410(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_011440(int, int);                      // sicher; GLEICH-Def ace_t1:2; deklariert 2x2
int f_0114a0(int, int, int, int);            // sicher; GLEICH-Def ace_t1:4; deklariert 4x2
int f_0114e0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_011540(int, int, int, int);            // sicher; GLEICH-Def ace_t1:4; deklariert 4x2
int f_011580(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_0115a0(int);                           // sicher; GLEICH-Def ace_t1:1; deklariert 1x2
int f_0115c0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_011680(int);                           // sicher; liest eax; deklariert 1x2
int f_0116a0(int);                           // sicher; liest eax; deklariert 1x2
int f_011750(int, int, int, int);            // sicher; GLEICH-Def ace_t2:4; deklariert 4x1
int f_011770(int, int, int, int);            // sicher; GLEICH-Def ace_t2:4; deklariert 4x1
int f_0117e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_011970(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_011dd0(int, int);                      // sicher; GLEICH-Def ace_t2:2; deklariert 2x1
int f_011e50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_011fb0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0123a0(int, int);                      // sicher; GLEICH-Def ace_t2:2; deklariert 2x1
int f_0123d0(int, int);                      // sicher; GLEICH-Def ace_t2:2; deklariert 2x1
int f_012450(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0125b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_012700(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_012870(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0129a0(int, int);                      // sicher; GLEICH-Def ace_t3:2; deklariert 2x1
int f_012dd0(int);                           // sicher; liest eax; deklariert 1x2
int f_0132a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0133b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_013580(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_013670(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_013710(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_013770(int);                           // sicher; GLEICH-Def gz_0132a0:1; deklariert 1x1
int f_0137e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_013a70(int, int, int, int);            // sicher; GLEICH-Def alfdisk:4; deklariert 4x2
int f_013a80(int, int);                      // sicher; GLEICH-Def alfdisk:2; deklariert 2x2
int f_013ad0(int, int);                      // sicher; GLEICH-Def alfdisk:2; deklariert 2x2
int f_013ba0(int, int);                      // sicher; GLEICH-Def alfdisk:2; deklariert 2x2
int f_013c00(int, int, int, int, int, int, int, int, int, int, int); // vermutet (sicher 2); liest eax edx; ret 28?; deklariert 3x2
int f_013de0(int);                           // sicher; liest eax; deklariert 1x3
int f_013df0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_014020(int, int);                      // sicher; liest eax edx; deklariert 2x1 3x1
int f_0141d0(int);                           // sicher; liest eax; deklariert 1x1
int f_014210(int);                           // sicher; liest eax; deklariert 1x1
int f_014300(int);                           // sicher; liest eax; deklariert 1x1
int f_0143c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_014540(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x53
int f_014710(int);                           // sicher; liest eax; deklariert 1x18 2x2
int f_0149a0(int);                           // sicher; liest eax; deklariert -
int f_014ab0(int, int);                      // sicher; liest edx; deklariert -
int f_014ac0(int, int);                      // sicher; liest edx; deklariert 3x1
int f_014b10(int, int);                      // sicher; liest eax edx; deklariert -
int f_014b30(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert -
int f_014ba0(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert -
int f_014cc0(int);                           // sicher; liest eax; deklariert 1x3
int f_014df0(int, int, int, int, int, int, int); // vermutet (sicher 4); liest edx ebx ecx; ret 12?; deklariert 7x5
int f_014f20(int, int, int, int, int, int);  // vermutet (sicher 4); liest edx ebx ecx; ret 8?; deklariert 6x3
int f_015040(int);                           // sicher; GLEICH-Def amap_t1:1; deklariert 1x3
int f_0150f0(int);                           // sicher; GLEICH-Def amap_t1:1; deklariert 1x3
int f_015190(int);                           // sicher; liest eax; deklariert 1x5
int f_015280(int);                           // sicher; liest eax; deklariert 1x5
int f_015310(int);                           // sicher; liest eax; deklariert 1x3
int f_0153c0(int);                           // sicher; liest eax; deklariert 1x3
int f_015450(int);                           // sicher; liest eax; deklariert 1x3
int f_0155e0(int);                           // sicher; liest eax; deklariert 1x3
int f_0156f0(int);                           // sicher; liest eax; deklariert 1x5
int f_015af0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_015bb0(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x2
int f_015be0(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x2
int f_015c00(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x3
int f_015c40(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x3
int f_015c80(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x3
int f_015ce0(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x3
int f_015d40(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_015dc0(int, int, int, int);            // sicher; GLEICH-Def amap_t1:4; deklariert 4x2
int f_015e30(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_015fd0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_016080(int);                           // sicher; GLEICH-Def amap_t1:1; deklariert 1x2
int f_016140(int, int);                      // sicher; GLEICH-Def amap_t1:2; deklariert 2x2
int f_016180(int, int, int, int);            // sicher; GLEICH-Def amap_t1:4; deklariert 4x2
int f_0161d0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_0163b0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_0164b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_016580(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_016800(int);                           // sicher; GLEICH-Def amap_t2:1; deklariert 1x1
int f_0168f0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0169b0(int);                           // sicher; liest eax; deklariert 1x1
int f_016bc0(int);                           // sicher; liest eax; deklariert 1x3
int f_016fd0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_017280(int);                           // sicher; liest eax; deklariert 1x3
int f_017530(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0176f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0177b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_017b10(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_017dc0(int);                           // sicher; GLEICH-Def amap_t3:1; deklariert 1x2
int f_017e00(int);                           // sicher; liest eax; deklariert 1x3
int f_017f70(int);                           // sicher; liest eax; deklariert 1x3
int f_018090(int);                           // sicher; GLEICH-Def amap_t3:1; deklariert 1x2
int f_018250(int);                           // sicher; GLEICH-Def amap_t3:1; deklariert 1x2
int f_018360(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_018510(int);                           // sicher; liest eax; deklariert 1x3
int f_0185c0(int);                           // sicher; GLEICH-Def amap_t3:1; deklariert 1x2
int f_018630(int);                           // sicher; liest eax; deklariert 1x3
int f_018720(int);                           // sicher; liest eax; deklariert 1x3
int f_018ab0(int, int);                      // sicher; GLEICH-Def amap_t3:2; deklariert 2x2
int f_018af0(int);                           // sicher; liest eax; deklariert 1x2
int f_018f00(int);                           // sicher; liest eax; deklariert 1x2
int f_019460(int);                           // sicher; liest eax; deklariert 1x3
int f_019620(int, int);                      // sicher; GLEICH-Def amap_t4:2; deklariert 2x2
int f_019800(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_019b30(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_019b40(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_019c90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_019db0(int);                           // sicher; liest eax; deklariert 1x2
int f_019eb0(int);                           // sicher; liest eax; deklariert 1x2
int f_019f30(int);                           // sicher; liest eax; deklariert 1x2
int f_019fb0(int);                           // sicher; liest eax; deklariert 1x3
int f_019fc0(int);                           // sicher; liest eax; deklariert 1x2
int f_019fd0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x10
int f_01a270(int);                           // sicher; GLEICH-Def amap_t5:1; deklariert 1x1
int f_01a470(int);                           // sicher; liest eax; deklariert -
int f_01a490(int);                           // sicher; liest eax; deklariert 1x1
int f_01a4b0(int);                           // sicher; liest eax; deklariert 1x1
int f_01a560(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_01a5d0(int);                           // sicher; liest eax; deklariert 1x1
int f_01a820(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_01a880(int);                           // sicher; liest eax; deklariert 1x1
int f_01a9b0(int);                           // sicher; GLEICH-Def gz_01a9b0:1; deklariert 1x1
int f_01aa30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_01aa90(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_01aad0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_01ad00(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_01ae60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_01afa0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_01afd0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x3
int f_01b060(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_01b0a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_01b100(int);                           // sicher; liest eax; deklariert 1x2
int f_01b120(int);                           // sicher; GLEICH-Def gz_01a9b0:1; deklariert 1x1
int f_01b140(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_01b1b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_01b230(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5
int f_01b2f0(int, int, int, int, int);       // sicher; liest edx ebx ecx; ret 4?; GLEICH-Def gz_01a9b0:5; deklariert 5x2
int f_01b320(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_01b3b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_01b4d0(int);                           // sicher; liest eax; deklariert 1x2
int f_01b5a0(int);                           // sicher; GLEICH-Def amapplst:1; deklariert 1x2
int f_01b610(int);                           // sicher; GLEICH-Def amapplst:1; deklariert 1x2
int f_01b650(int);                           // sicher; GLEICH-Def amapplst:1; deklariert 1x2
int f_01b680(int);                           // sicher; GLEICH-Def amapplst:1; deklariert 1x2
int f_01b6a0(int);                           // sicher; GLEICH-Def amapplst:1; deklariert 1x2
int f_01b860(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_01b880(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 0x3
int f_01b890(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_01b8a0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_01ba50(int);                           // sicher; liest eax; deklariert 1x5
int f_01bb60(int);                           // sicher; liest eax; deklariert 1x5
int f_01bc70(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_01be20(int);                           // sicher; liest eax; deklariert 1x1
int f_01bfb0(int);                           // sicher; liest eax; deklariert 1x1
int f_01c000(int);                           // sicher; liest eax; deklariert 1x5
int f_01c080(int);                           // sicher; liest eax; deklariert 2x1
int f_01c090(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_01c120(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x5
int f_01c300(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_01c530(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_01c730(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_01c840(int);                           // sicher; liest eax; deklariert 1x4
int f_01cae0(int, int, int);                 // sicher; GLEICH-Def ani_t1:3; deklariert 3x2
int f_01cc30(int);                           // sicher; GLEICH-Def ani_t1:1; deklariert 1x2
int f_01cc90(int, int, int, int);            // sicher; liest eax ecx; deklariert 1x3
int f_01ceb0(int, int);                      // sicher; GLEICH-Def ani_t1:2; deklariert 2x2
int f_01ced0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_01cee0(int, int);                      // sicher; GLEICH-Def ani_t1:2; deklariert 2x2
int f_01cef0(int);                           // sicher; liest eax; deklariert 1x14
int f_01cf10(int);                           // sicher; liest eax; deklariert 1x4
int f_01cf90(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_01d160(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_01df90(int);                           // sicher; liest eax; deklariert 1x3
int f_01dfa0(int, int);                      // sicher; GLEICH-Def ani_t2:2; deklariert 2x2
int f_01dfb0(int);                           // sicher; liest eax; deklariert 1x3
int f_01dfc0(int);                           // sicher; liest eax; deklariert 1x3
int f_01dfd0(int);                           // sicher; liest eax; deklariert 1x3
int f_01e110(int);                           // sicher; liest eax; deklariert 1x1
int f_01e1a0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_01e240(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x4
int f_01e290(int);                           // sicher; liest eax; deklariert 1x1 2x3
int f_01e300(int);                           // sicher; GLEICH-Def gz_01e240:1; deklariert 1x1
int f_01e310(int);                           // sicher; GLEICH-Def gz_01e240:1; deklariert 1x1
int f_01e320(int);                           // sicher; GLEICH-Def gz_01e240:1; deklariert 1x1
int f_01e330(int);                           // sicher; GLEICH-Def gz_01e240:1; deklariert 1x1
int f_01e3a0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_01e430(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_01e570(int);                           // sicher; liest eax; deklariert 1x4
int f_01e5e0(int);                           // sicher; liest eax; deklariert 1x2
int f_01e630(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x4
int f_01e860(int);                           // sicher; liest eax; deklariert 1x1
int f_01eb40(int);                           // sicher; liest eax; deklariert 1x6
int f_01eb50(int);                           // sicher; liest eax; deklariert 1x5
int f_01eb60(int);                           // sicher; liest eax; deklariert 1x3
int f_01eb70(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_01ebc0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_01ec20(int, int);                      // sicher; GLEICH-Def gz_01eb40:2; deklariert 2x3
int f_01eee0(int);                           // sicher; GLEICH-Def gz_01eb40:1; deklariert 1x2
int f_01f350(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_01f3c0(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x5
int f_01f410(int, int);                      // sicher; liest eax; GLEICH-Def gz_01eb40:2; deklariert 2x5
int f_01f450(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_01f460(int);                           // sicher; liest eax; deklariert 1x5
int f_01f470(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_01f480(int);                           // sicher; liest eax; deklariert 1x7
int f_01f490(int, int, int);                 // vermutet (sicher 1); liest eax; R106 ebx; deklariert 1x7
int f_01f560(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_01f620(int);                           // sicher; liest eax; deklariert 1x7
int f_01f6f0(int);                           // sicher; liest eax; deklariert 1x7
int f_01f7d0(int);                           // sicher; liest eax; deklariert 1x7
int f_01f8b0(int);                           // sicher; liest eax; deklariert 1x7
int f_01f990(int);                           // sicher; liest eax; deklariert 1x7
int f_01fa70(int);                           // sicher; liest eax; deklariert 1x7
int f_01fa80(int);                           // sicher; liest eax; deklariert 1x7
int f_01fb40(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_01fef0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_020090(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_020150(int);                           // sicher; liest eax; deklariert 1x5
int f_020260(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_020640(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_020760(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0208d0(int);                           // sicher; liest eax; deklariert 1x4
int f_020970(int, int);                      // sicher; liest edx; deklariert 2x2
int f_021180(int);                           // sicher; GLEICH-Def gz_020420_t1:1; deklariert 0x1 1x1
int f_021190(int);                           // sicher; GLEICH-Def gz_020420_t1:1; deklariert 0x1 1x1
int f_0211a0(int);                           // sicher; GLEICH-Def gz_020420_t1:1; deklariert 1x2
int f_021430(int, int, int);                 // sicher; GLEICH-Def gz_020420_t1:3; deklariert 3x1
int f_021490(int);                           // sicher; liest eax; deklariert 1x2
int f_021a30(int);                           // sicher; GLEICH-Def gz_020420_t2:1; deklariert 1x1
int f_022030(int);                           // sicher; liest eax; deklariert 1x2
int f_0222d0(int);                           // sicher; liest eax; deklariert 1x3
int f_022480(int);                           // sicher; GLEICH-Def gz_0222d0:1; deklariert 1x1
int f_0228b0(int);                           // sicher; GLEICH-Def gz_0222d0:1; deklariert 1x1
int f_022910(int, int);                      // sicher; GLEICH-Def gz_0222d0:2; deklariert 2x1
int f_022960(int);                           // sicher; GLEICH-Def gz_0222d0:1; deklariert 1x2
int f_0234a0(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_0234d0(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_0237c0(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_023970(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_0239a0(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_0239f0(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_023a40(int);                           // sicher; GLEICH-Def boron2_t1:1; deklariert 1x2
int f_023f70(int);                           // sicher; GLEICH-Def boron2_t2:1; deklariert 1x3
int f_023fc0(int);                           // sicher; liest eax; deklariert 1x2
int f_024070(int);                           // sicher; GLEICH-Def boron2_t2:1; deklariert 1x3
int f_0240e0(int);                           // sicher; GLEICH-Def boron2_t2:1; deklariert 1x3
int f_024150(int);                           // sicher; GLEICH-Def boron2_t2:1; deklariert 1x3
int f_0242c0(int);                           // sicher; GLEICH-Def boron2_t2:1; deklariert 1x3
int f_024890(int, int);                      // sicher; GLEICH-Def gz_024890:2; deklariert 2x1
int f_0248d0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0248e0(int, int);                      // sicher; GLEICH-Def gz_024890:2; deklariert 2x1
int f_024930(int);                           // sicher; GLEICH-Def gz_024890:1; deklariert 1x1
int f_024980(int);                           // sicher; liest eax; deklariert 1x2
int f_024ba0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_024f70(int, int);                      // sicher; GLEICH-Def cache:2; deklariert 2x2
int f_024fd0(int);                           // sicher; liest eax; deklariert 1x2
int f_0250b0(int, int);                      // sicher; GLEICH-Def cache:2; deklariert 2x2
int f_025120(int, int);                      // sicher; GLEICH-Def cache:2; deklariert 2x2
int f_025130(int);                           // sicher; GLEICH-Def cache:1; deklariert 1x2
int f_025170(int, int);                      // sicher; GLEICH-Def cache:2; deklariert 2x2
int f_0251d0(int, int, int);                 // sicher; GLEICH-Def cache:3; deklariert 3x2
int f_025230(int);                           // sicher; GLEICH-Def cache:1; deklariert 1x2
int f_0252b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_025350(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_025660(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0256c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_025740(int, int);                      // sicher; liest eax; GLEICH-Def cache:2; deklariert 2x2
int f_025750(int, int, int, int, int);       // sicher; liest eax; ret 4?; GLEICH-Def cache:5; deklariert 5x3
int f_0257f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0259e0(int);                           // sicher; liest eax; deklariert 1x2 2x1
int f_025ac0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_025be0(int);                           // sicher; liest eax; deklariert 1x2 2x1
int f_025c40(int);                           // sicher; liest eax; deklariert 1x3
int f_025c50(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_025cd0(int);                           // sicher; liest eax; deklariert 1x4
int f_025d90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_025f90(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x3
int f_026150(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_026280(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_0264d0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_026570(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_026600(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0266e0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0268c0(int);                           // sicher; liest eax; deklariert 1x3
int f_026a20(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_026a70(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_026a80(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_026b50(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_026cf0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_026db0(int, int, int, int);            // sicher; GLEICH-Def gz_026b50:4; deklariert 4x1
int f_026de0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_026e80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_026ff0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_027050(int);                           // sicher; liest eax; deklariert 1x2 2x3
int f_027070(int);                           // sicher; liest eax; deklariert 1x7
int f_027080(int);                           // sicher; liest eax; deklariert 1x5
int f_027090(int);                           // sicher; liest eax; deklariert 1x5
int f_0270a0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0270b0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0270c0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0270d0(int);                           // sicher; liest eax; deklariert 1x5
int f_027240(int);                           // sicher; liest eax; deklariert 1x5
int f_027280(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0272d0(int);                           // sicher; liest eax; deklariert 1x5
int f_027420(int);                           // sicher; liest eax; deklariert 1x2
int f_027690(int);                           // sicher; liest eax; deklariert 1x5
int f_027750(int);                           // sicher; liest eax; deklariert 1x5
int f_027830(int, int, int, int);            // vermutet (sicher 2); liest eax edx; R106 ecx; deklariert 2x5
int f_027860(int);                           // sicher; liest eax; deklariert 1x2
int f_0279f0(int);                           // sicher; liest eax; deklariert 1x2
int f_027b30(int);                           // sicher; liest eax; deklariert 1x2
int f_027c50(int);                           // sicher; liest eax; deklariert 1x2
int f_027e20(int);                           // sicher; liest eax; deklariert 1x2
int f_027f80(int);                           // sicher; liest eax; deklariert 1x2
int f_028190(int, int);                      // sicher; GLEICH-Def gz_028190:2; deklariert 2x1
int f_02b100(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b160(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b1b0(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b270(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b2a0(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b2c0(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b3b0(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b440(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b450(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b460(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b470(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b480(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b490(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b4a0(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b4b0(int);                           // sicher; GLEICH-Def castle_t1:1; deklariert 1x2
int f_02b880(int);                           // sicher; GLEICH-Def castle_t2:1; deklariert 1x1
int f_02bad0(int);                           // sicher; liest eax; deklariert 1x2
int f_02c030(int);                           // sicher; GLEICH-Def castle_t2:1; deklariert 1x1
int f_02c150(int);                           // sicher; liest eax; deklariert 1x2
int f_02cbe0(int);                           // sicher; GLEICH-Def castle_t3:1; deklariert 1x1
int f_02d230(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_02d7a0(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_02d900(int);                           // sicher; liest eax; deklariert 1x2
int f_02ddf0(int);                           // sicher; liest eax; deklariert 1x2
int f_02de00(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_02de20(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_02de80(int, int);                      // sicher; liest edx; deklariert 2x3
int f_02de90(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_02dee0(int);                           // sicher; liest eax; deklariert 1x5
int f_02df40(int);                           // sicher; liest eax; deklariert 1x3
int f_02dfa0(int);                           // sicher; liest eax; deklariert 1x2
int f_02dfe0(int);                           // sicher; liest eax; deklariert 1x2 3x1
int f_02e030(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_02e080(int);                           // sicher; liest eax; deklariert 1x2
int f_02e11a(int);                           // sicher; liest eax; deklariert 1x2
int f_02e199(int);                           // sicher; liest eax; deklariert 1x2
int f_02e204(int);                           // sicher; liest eax; deklariert 1x2
int f_02e273(int);                           // sicher; liest eax; deklariert 1x2
int f_02e304(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_02e375(int);                           // sicher; liest eax; deklariert 1x2
int f_02e41a(int);                           // sicher; liest eax; deklariert 1x3
int f_02e56f(int, int, int, int);            // sicher; liest eax ecx; deklariert 1x2
int f_02ea8a(int, int);                      // sicher; liest eax edx; deklariert -
int f_02ecc3(int, int);                      // sicher; liest eax edx; deklariert -
int f_02ed35(int);                           // sicher; liest eax; deklariert 1x2
int f_02ee42(int);                           // sicher; liest eax; deklariert 1x2
int f_02f12f(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_02f406(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_02f883(int, int);                      // sicher; liest eax edx; deklariert 1x1
int f_02fc49(int);                           // sicher; liest eax; deklariert 1x1
int f_02fcb7(int);                           // sicher; liest eax; deklariert 1x4
int f_02ff70(int);                           // sicher; liest eax; deklariert 1x3
int f_02ffa0(int);                           // sicher; liest eax; deklariert 1x5
int f_030080(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_0307d0(int);                           // sicher; liest eax; deklariert 1x2
int f_030810(int);                           // sicher; liest eax; deklariert 1x10
int f_030850(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_030890(int);                           // sicher; liest eax; deklariert 1x9
int f_030930(int, int);                      // sicher; GLEICH-Def gz_0307d0_t1:2; deklariert 2x1
int f_030960(int);                           // sicher; liest eax; deklariert 1x10
int f_0309d0(int);                           // sicher; liest eax; deklariert 1x2
int f_030a40(int);                           // sicher; liest eax; deklariert 1x2
int f_030b00(int);                           // sicher; liest eax; deklariert 1x2
int f_030cb0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_030d00(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_030d80(int);                           // sicher; liest eax; deklariert 1x12
int f_030e20(int, int);                      // sicher; liest eax edx; deklariert 2x11
int f_030ed0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_030fe0(int);                           // sicher; liest eax; deklariert 1x3
int f_031020(int);                           // sicher; liest eax; deklariert 1x2
int f_032130(int);                           // sicher; liest eax; deklariert 1x2
int f_032470(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0324e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_032630(int);                           // sicher; GLEICH-Def gz_0307d0_t2:1; deklariert 1x1
int f_032670(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0326d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_032730(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_032820(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x22
int f_032ab0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x11
int f_033250(int, int);                      // sicher; liest edx; deklariert 2x7
int f_033260(int, int, int);                 // sicher; liest edx ebx; deklariert 3x7
int f_033450(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x7
int f_033530(int, int);                      // sicher; liest eax edx; deklariert 2x14
int f_033590(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0335d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_0338a0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x4
int f_033c50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_033ce0(int);                           // sicher; liest eax; deklariert 1x3
int f_033db0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0348d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_034920(int, int);                      // sicher; GLEICH-Def ch_item2:2; deklariert 2x2
int f_0349b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_034ad0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_034e20(int);                           // sicher; liest eax; deklariert 1x2
int f_0350b0(int);                           // sicher; liest eax; deklariert 1x3
int f_035110(int);                           // sicher; liest eax; deklariert 1x6
int f_035180(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_035260(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0352c0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_036300(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x44
int f_0366e0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 3x1 4x29
int f_036a10(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x18
int f_036c10(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_036db0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_036ed0(int);                           // sicher; liest eax; deklariert 1x6
int f_036ee0(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_037030(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_037140(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_037250(int);                           // sicher; GLEICH-Def ch_level_t1:1; deklariert 1x2
int f_037280(int);                           // sicher; GLEICH-Def ch_level_t1:1; deklariert 1x2
int f_0372c0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_037420(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_037730(int);                           // sicher; liest eax; deklariert 1x3
int f_0378e0(int);                           // sicher; liest eax; deklariert 1x3
int f_037bb0(int);                           // sicher; liest eax; deklariert 1x3
int f_037e60(int);                           // sicher; liest eax; deklariert 1x3
int f_0384e0(int);                           // sicher; liest eax; deklariert 1x1
int f_038880(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_038ba0(int);                           // sicher; liest eax; deklariert 1x22
int f_038be0(int);                           // sicher; liest eax; deklariert 1x34
int f_038c20(int);                           // sicher; liest eax; deklariert 1x3
int f_038c40(int);                           // sicher; liest eax; deklariert 1x102
int f_038c80(int);                           // sicher; liest eax; deklariert 1x37
int f_038cb0(int);                           // sicher; liest eax; deklariert 1x9
int f_038d00(int);                           // sicher; liest eax; deklariert 1x2
int f_038d70(int, int);                      // sicher; liest eax edx; deklariert 2x29
int f_038e10(int, int);                      // sicher; liest eax edx; deklariert 2x13
int f_038e90(int, int);                      // sicher; liest eax edx; deklariert 2x19
int f_038f20(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_039040(int);                           // sicher; liest eax; deklariert 1x43
int f_039070(int);                           // sicher; liest eax; deklariert 1x3
int f_0390a0(int);                           // sicher; liest eax; deklariert 1x6
int f_0390d0(int);                           // sicher; liest eax; deklariert 1x2
int f_039110(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_039160(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0391b0(int, int);                      // sicher; liest eax edx; deklariert 2x38
int f_0391f0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_039230(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_039320(int, int);                      // sicher; liest eax edx; deklariert 2x79 3x1
int f_039420(int, int);                      // sicher; liest eax edx; deklariert 2x24
int f_039580(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x9
int f_039660(int, int);                      // sicher; liest eax edx; deklariert 2x69
int f_0396f0(int, int);                      // sicher; liest eax edx; deklariert 2x30
int f_039780(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0397d0(int, int);                      // sicher; liest eax edx; deklariert 2x17
int f_039830(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0398c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x24
int f_039910(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_039960(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2 4x2
int f_039a10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x9
int f_039a80(int, int);                      // sicher; liest eax edx; deklariert 2x33
int f_039ac0(int, int);                      // sicher; liest eax edx; deklariert 2x33
int f_039b00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_039b70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x17
int f_039be0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_039c50(int, int);                      // sicher; liest edx; deklariert 2x11
int f_039c90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_039cf0(int);                           // sicher; liest eax; deklariert 1x2
int f_03aa20(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 3x3 4x6
int f_03ac50(int, int);                      // sicher; liest edx; deklariert 2x2
int f_03ad80(int, int);                      // sicher; liest eax edx; deklariert 2x17
int f_03af20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 2x1 3x19
int f_03af30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_03afe0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03b0b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03b400(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03b4f0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03b5e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03b8d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03bc00(int, int);                      // sicher; GLEICH-Def gz_03b8d0:2; deklariert 2x1
int f_03bc50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03c210(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5
int f_03c530(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_03c630(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_03c860(int);                           // sicher; liest eax; deklariert 1x2
int f_03cc60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03cd00(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_03d3d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_03d4b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x17
int f_03d790(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_03d7d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_03d820(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_03d860(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_03d8b0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x10
int f_03e440(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_03eca0(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 1x6
int f_03ede0(int);                           // sicher; liest eax; deklariert -
int f_03f060(int);                           // sicher; liest eax; deklariert -
int f_03f240(int, int, int);                 // sicher; GLEICH-Def gz_03f060:3; deklariert 3x1
int f_03f270(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_03f290(int);                           // sicher; GLEICH-Def gz_03f060:1; deklariert 1x1
int f_03f2a0(int);                           // sicher; liest eax; deklariert 1x1
int f_03f390(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03f3b0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_03f4d0(int);                           // sicher; liest eax; deklariert 1x2
int f_03f7b0(int);                           // sicher; liest eax; deklariert 1x2
int f_03f890(int);                           // sicher; liest eax; deklariert 1x2
int f_03fa80(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_03fc00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_03fdf0(int);                           // sicher; liest eax; deklariert 1x2
int f_040310(int, int, int);                 // sicher; GLEICH-Def gz_040280:3; deklariert 3x1
int f_040370(int, int);                      // sicher; liest eax edx; deklariert 2x14
int f_040400(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0406d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_040730(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_040780(int, int);                      // sicher; liest eax edx; deklariert 2x27
int f_0407e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_040820(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_040880(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_040900(int, int);                      // sicher; liest eax edx; deklariert 2x18
int f_040980(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_040a00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x18
int f_040a40(int);                           // sicher; liest eax; deklariert 1x6
int f_040b90(int);                           // sicher; liest eax; deklariert 1x2
int f_040cb0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_040da0(int);                           // sicher; liest eax; deklariert 1x4
int f_040e00(int);                           // sicher; liest eax; deklariert 1x5
int f_040e40(int);                           // sicher; liest eax; deklariert 1x2
int f_040e60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_040e90(int);                           // sicher; liest eax; deklariert 1x10
int f_040f40(int);                           // sicher; GLEICH-Def gz_040280:1; deklariert 0x1 1x1
int f_041630(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0416d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0417f0(int);                           // sicher; liest eax; deklariert 1x1
int f_041920(int);                           // sicher; liest eax; deklariert 1x21
int f_041ae0(int);                           // sicher; liest eax; deklariert 1x8
int f_041d90(int);                           // sicher; liest eax; deklariert 1x2
int f_0421c0(int);                           // sicher; liest eax; deklariert 1x3
int f_0421f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_042220(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_042230(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_042240(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042250(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042270(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_042280(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_042290(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_0422a0(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_0422b0(int);                           // sicher; liest eax; deklariert 1x35
int f_0422c0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0422f0(int, int);                      // sicher; liest eax edx; deklariert 2x3 3x1
int f_042320(int);                           // sicher; liest eax; deklariert 1x6
int f_042330(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_042340(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_042350(int);                           // sicher; liest eax; deklariert 1x68
int f_042360(int);                           // sicher; liest eax; deklariert 1x2 2x1
int f_042380(int);                           // sicher; liest eax; deklariert 1x65
int f_042390(int);                           // sicher; liest eax; deklariert 1x6
int f_0423a0(int);                           // sicher; liest eax; deklariert 1x7
int f_0423b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0423c0(int);                           // sicher; liest eax; deklariert 1x18
int f_0423d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0423e0(int);                           // sicher; liest eax; deklariert 1x3
int f_0423f0(int);                           // sicher; liest eax; deklariert 1x5
int f_042400(int);                           // sicher; liest eax; deklariert 1x69
int f_042410(int);                           // sicher; liest eax; deklariert 1x7
int f_042420(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_042430(int);                           // sicher; liest eax; deklariert 1x6
int f_042440(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_042450(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_042460(int);                           // sicher; liest eax; deklariert 1x2
int f_042470(int);                           // sicher; liest eax; deklariert 1x65
int f_042480(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0424d0(int);                           // sicher; liest eax; deklariert 1x16
int f_0424e0(int);                           // sicher; liest eax; deklariert 1x25
int f_0424f0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_042520(int);                           // sicher; liest eax; deklariert 1x2
int f_042530(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042560(int);                           // sicher; liest eax; deklariert 1x6
int f_042570(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0425a0(int);                           // sicher; liest eax; deklariert 1x10
int f_0425b0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0425f0(int);                           // sicher; liest eax; deklariert 1x31
int f_042600(int);                           // sicher; liest eax; deklariert 1x9
int f_042610(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_042640(int);                           // sicher; liest eax; deklariert 1x12
int f_042650(int, int);                      // sicher; liest eax edx; deklariert 2x13
int f_042680(int);                           // sicher; liest eax; deklariert 1x2
int f_042690(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0426c0(int);                           // sicher; liest eax; deklariert 1x2
int f_0426d0(int, int);                      // sicher; GLEICH-Def gz_0421c0_t1:2; deklariert 2x1
int f_042700(int);                           // sicher; liest eax; deklariert 1x2
int f_042710(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042740(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_042750(int);                           // sicher; liest eax; deklariert 1x11
int f_042760(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_042770(int);                           // sicher; liest eax; deklariert 1x2
int f_042780(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_042790(int);                           // sicher; liest eax; deklariert 1x4
int f_0427a0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0427b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0427c0(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_0427d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0427e0(int);                           // sicher; liest eax; deklariert 1x7
int f_0427f0(int, int);                      // sicher; GLEICH-Def gz_0421c0_t1:2; deklariert 2x1
int f_042800(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_042810(int);                           // sicher; liest eax; deklariert 1x9
int f_042820(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_042830(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_042840(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042850(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_042860(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042870(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_042880(int);                           // sicher; liest eax; deklariert 1x3
int f_042890(int);                           // sicher; liest eax; deklariert 1x6
int f_0428a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0428b0(int);                           // sicher; liest eax; deklariert 1x6
int f_0428c0(int);                           // sicher; liest eax; deklariert 1x5
int f_0428d0(int);                           // sicher; liest eax; deklariert 1x16
int f_0428e0(int);                           // sicher; liest eax; deklariert 1x2
int f_0428f0(int);                           // sicher; liest eax; deklariert 1x10
int f_042900(int);                           // sicher; liest eax; deklariert 1x6
int f_042910(int);                           // sicher; liest eax; deklariert 1x4
int f_042920(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_042930(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_042940(int);                           // sicher; liest eax; deklariert 1x3
int f_042950(int);                           // sicher; liest eax; deklariert 1x11
int f_042960(int);                           // sicher; liest eax; deklariert 1x65
int f_042970(int);                           // sicher; liest eax; deklariert 1x24
int f_042980(int);                           // sicher; liest eax; deklariert 1x2
int f_042990(int, int);                      // sicher; GLEICH-Def gz_0421c0_t1:2; deklariert 2x1
int f_0429a0(int);                           // sicher; liest eax; deklariert 1x36
int f_0429b0(int);                           // sicher; liest eax; deklariert 1x14
int f_0429c0(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_0429e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0429f0(int);                           // sicher; liest eax; deklariert 1x3
int f_042a10(int);                           // sicher; liest eax; deklariert 1x34
int f_042a20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_042a40(int, int);                      // sicher; liest eax edx; deklariert 2x17
int f_042a60(int, int);                      // sicher; liest eax edx; deklariert 2x83
int f_042a90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x13
int f_042ac0(int, int);                      // sicher; liest eax edx; deklariert 2x46
int f_042af0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_042b20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x11
int f_042b50(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_042b80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_042bb0(int, int);                      // sicher; liest eax edx; deklariert 2x20
int f_042be0(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_042c10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_042c40(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_042ca0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_042d00(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_042d30(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_042d60(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_042da0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_042dd0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_042e10(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_042e40(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_042e80(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042eb0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_042ef0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_042f20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_042f60(int, int);                      // sicher; GLEICH-Def gz_0421c0_t1:2; deklariert 2x1
int f_042f90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_042fd0(int, int);                      // sicher; liest eax edx; deklariert 2x13
int f_043000(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_043030(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_043060(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_043090(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0430c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x10
int f_0430f0(int, int);                      // sicher; liest eax edx; deklariert 2x16
int f_043100(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_043110(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x14
int f_043120(int);                           // sicher; liest eax; deklariert 1x9
int f_043130(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_043150(int);                           // sicher; GLEICH-Def gz_0421c0_t1:1; deklariert 1x1
int f_043160(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043170(int);                           // sicher; liest eax; deklariert 1x15
int f_043180(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043190(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_0431a0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0431d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_043210(int);                           // sicher; liest eax; deklariert 1x2
int f_043230(int);                           // sicher; liest eax; deklariert 1x6
int f_043240(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_043250(int);                           // sicher; liest eax; deklariert 1x4
int f_043260(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_043270(int);                           // sicher; liest eax; deklariert 1x4
int f_043280(int, int);                      // sicher; GLEICH-Def gz_0421c0_t1:2; deklariert 2x1
int f_043290(int);                           // sicher; liest eax; deklariert 1x3
int f_0432a0(int, int);                      // sicher; GLEICH-Def gz_0421c0_t1:2; deklariert 2x1
int f_0432b0(int);                           // sicher; liest eax; deklariert 1x11
int f_0432c0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0432d0(int);                           // sicher; liest eax; deklariert 1x6
int f_0432e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0432f0(int);                           // sicher; liest eax; deklariert 1x9
int f_043300(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043310(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_043320(int);                           // sicher; liest eax; deklariert 1x4
int f_043330(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043340(int);                           // sicher; liest eax; deklariert 1x9
int f_043350(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043360(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_043370(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043380(int);                           // sicher; liest eax; deklariert 1x2
int f_043390(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0433c0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0433d0(int);                           // sicher; liest eax; deklariert 1x9
int f_0433e0(int);                           // sicher; liest eax; deklariert 1x2
int f_0433f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043400(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043410(int);                           // sicher; liest eax; deklariert 1x11
int f_043420(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_043430(int, int);                      // sicher; liest eax; GLEICH-Def gz_0421c0_t2:2; deklariert 2x10
int f_043450(int);                           // sicher; liest eax; deklariert 1x9
int f_043460(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_043470(int);                           // sicher; liest eax; deklariert 1x13 2x2
int f_043480(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043490(int);                           // sicher; liest eax; deklariert 1x14
int f_0434a0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0434b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0434d0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0434e0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_043510(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043520(int);                           // sicher; liest eax; deklariert 1x2
int f_043530(int);                           // sicher; liest eax; deklariert 1x2
int f_043540(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043550(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043560(int, int);                      // sicher; liest eax; GLEICH-Def gz_0421c0_t2:2; deklariert 2x2
int f_043590(int, int);                      // sicher; liest eax; GLEICH-Def gz_0421c0_t2:2; deklariert 2x2
int f_0435c0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0435e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043600(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043620(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043640(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_043670(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043690(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0436b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0436e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043700(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_043720(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_043750(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043770(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0437b0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0437e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043820(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_043840(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_043860(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043880(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_0438a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0438d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0438f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043910(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_043940(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043960(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043980(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0439b0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0439d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043a10(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_043a40(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_043a80(int, int);                      // sicher; liest eax edx; deklariert 2x15
int f_043aa0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_043ac0(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_043ae0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_043af0(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x4
int f_043b00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_043b10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_043b20(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043b30(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043b40(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_043b50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_043b60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043b70(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043b80(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043b90(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043ba0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043bb0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043bc0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043bd0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043be0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043c10(int);                           // sicher; liest eax; deklariert 1x5
int f_043c20(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043c30(int);                           // sicher; liest eax; deklariert 1x5
int f_043c40(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043c50(int);                           // sicher; GLEICH-Def gz_0421c0_t2:1; deklariert 1x1
int f_043c60(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043c70(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043c80(int);                           // sicher; liest eax; deklariert 1x2
int f_043c90(int);                           // sicher; liest eax; deklariert 1x4
int f_043ca0(int);                           // sicher; liest eax; deklariert 1x7
int f_043cb0(int);                           // sicher; liest eax; deklariert 1x2
int f_043cc0(int);                           // sicher; liest eax; deklariert 1x2
int f_043cd0(int);                           // sicher; GLEICH-Def gz_0421c0_t2:1; deklariert 1x2
int f_043ce0(int);                           // sicher; liest eax; deklariert 1x4
int f_043cf0(int);                           // sicher; liest eax; deklariert 1x2
int f_043d00(int);                           // sicher; GLEICH-Def gz_0421c0_t2:1; deklariert 1x1
int f_043d10(int);                           // sicher; liest eax; deklariert 1x5
int f_043d20(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043d40(int);                           // sicher; liest eax; deklariert 1x4
int f_043d50(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_043d70(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043d90(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043dc0(int);                           // sicher; liest eax; deklariert 1x10
int f_043dd0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_043de0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043df0(int);                           // sicher; liest eax; deklariert 1x3
int f_043e00(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_043e10(int);                           // sicher; liest eax; deklariert 1x2
int f_043e20(int, int);                      // sicher; liest eax edx; deklariert 2x30
int f_043e30(int);                           // sicher; liest eax; deklariert 1x10
int f_043e40(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_043e50(int);                           // sicher; liest eax; deklariert 1x2
int f_043e60(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_043e70(int);                           // sicher; liest eax; deklariert 1x3
int f_043e80(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043ea0(int);                           // sicher; liest eax; deklariert 1x2
int f_043eb0(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043ed0(int);                           // sicher; liest eax; deklariert 1x2
int f_043ee0(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043f00(int);                           // sicher; liest eax; deklariert 1x3
int f_043f10(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043f30(int);                           // sicher; liest eax; deklariert 1x3
int f_043f50(int, int);                      // sicher; GLEICH-Def gz_0421c0_t2:2; deklariert 2x1
int f_043f70(int);                           // sicher; liest eax; deklariert 1x2
int f_043f80(int);                           // sicher; liest eax; deklariert 1x2
int f_043f90(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043fa0(int);                           // sicher; liest eax; deklariert 1x2
int f_043fb0(int);                           // sicher; liest eax; deklariert 1x2
int f_043fc0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_043fd0(int, int);                      // sicher; liest eax; GLEICH-Def gz_0421c0_t2:2; deklariert 2x3
int f_043ff0(int, int);                      // sicher; liest eax; GLEICH-Def gz_0421c0_t2:2; deklariert 2x3
int f_044010(int, int, int);                 // sicher; GLEICH-Def gz_0421c0_t2:3; deklariert 3x1
int f_044030(int);                           // sicher; GLEICH-Def gz_0421c0_t2:1; deklariert 1x1
int f_044040(int);                           // sicher; GLEICH-Def gz_0421c0_t2:1; deklariert 1x2
int f_044060(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_044080(int);                           // sicher; GLEICH-Def gz_0421c0_t2:1; deklariert 1x1
int f_044090(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_044190(int);                           // sicher; liest eax; deklariert 1x2
int f_0441b0(int);                           // sicher; liest eax; deklariert 1x3
int f_0441c0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0441d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_044210(int);                           // sicher; liest eax; deklariert 1x3
int f_044220(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_044230(int, int);                      // sicher; liest eax edx; deklariert 2x27
int f_0442b0(int, int);                      // sicher; liest eax edx; deklariert 2x5 4x2
int f_044300(int, int);                      // sicher; liest eax edx; deklariert 2x74
int f_044670(int);                           // sicher; liest eax; deklariert 1x2
int f_044850(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x51
int f_044890(int, int);                      // sicher; liest eax edx; deklariert 2x13 4x3
int f_044900(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x39
int f_044940(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_0449d0(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_044a00(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_044b60(int);                           // sicher; liest eax; deklariert 1x3
int f_044c90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x70
int f_044e30(int);                           // sicher; liest eax; deklariert 1x3
int f_044ea0(int);                           // sicher; liest eax; deklariert 1x6
int f_045080(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_045170(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_045190(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0451c0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0451f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_045210(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 1x3
int f_0452a0(int);                           // sicher; liest eax; deklariert 1x3
int f_045300(int);                           // sicher; liest eax; deklariert 1x8
int f_0453e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x18
int f_045430(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x14
int f_0455b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_045610(int);                           // sicher; liest eax; deklariert 1x9
int f_045660(int);                           // sicher; liest eax; deklariert 1x9
int f_0456e0(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_045710(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_045750(int);                           // sicher; liest eax; deklariert 1x2
int f_0457c0(int);                           // sicher; liest eax; deklariert 1x2
int f_045820(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0458b0(int);                           // sicher; liest eax; deklariert 1x10
int f_045960(int, int);                      // sicher; liest eax edx; deklariert 2x13
int f_0459e0(int);                           // sicher; liest eax; deklariert 1x3
int f_045a80(int, int);                      // sicher; liest eax; GLEICH-Def gz_0452a0:2; deklariert 2x2
int f_045a90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_045b70(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_045db0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_045de0(int);                           // sicher; GLEICH-Def gz_045db0:1; deklariert 1x1
int f_045df0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_045e10(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_045e50(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_045fd0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_046090(int, int);                      // sicher; liest edx; deklariert 2x1
int f_046320(int);                           // sicher; liest eax; deklariert 1x1
int f_0463e0(int);                           // sicher; liest eax; deklariert 1x2
int f_046520(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0465c0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_046b60(int, int);                      // sicher; liest edx; deklariert 2x2
int f_046bc0(int);                           // sicher; liest eax; deklariert 1x6 4x1
int f_046d10(int, int);                      // sicher; liest eax edx; deklariert 2x21
int f_046d90(int, int);                      // sicher; liest eax; GLEICH-Def chest:2; deklariert 1x1 2x20
int f_046de0(int);                           // sicher; liest eax; deklariert 1x22
int f_046eb0(int);                           // sicher; liest eax; deklariert 1x8
int f_046ec0(int);                           // sicher; liest eax; deklariert 1x8
int f_046fc0(int);                           // sicher; liest eax; deklariert 1x2
int f_047080(int);                           // sicher; GLEICH-Def chest:1; deklariert 1x2
int f_047120(int);                           // sicher; liest eax; deklariert 1x10
int f_0471b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_047420(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_047570(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_047620(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_047650(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_047660(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_047720(int);                           // sicher; liest eax; deklariert 1x5
int f_0477a0(int);                           // sicher; liest eax; deklariert 1x5
int f_047830(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5
int f_0480a0(int);                           // sicher; GLEICH-Def cityriva_t1:1; deklariert 1x1
int f_048110(int);                           // sicher; GLEICH-Def cityriva_t1:1; deklariert 1x2
int f_04a890(int);                           // sicher; liest eax; deklariert 1x6
int f_04ad40(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x1 2x5
int f_04aee0(int, int, int);                 // vermutet (sicher 1); liest eax; Aufrufer-Modus 3; deklariert 1x2
int f_04aef0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_04af60(int);                           // sicher; liest eax; deklariert 1x3
int f_04af80(int);                           // sicher; liest eax; deklariert 1x3
int f_04b050(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_04b0d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x8
int f_04b3a0(int);                           // sicher; liest eax; deklariert 1x7
int f_04b5f0(int);                           // sicher; liest eax; deklariert 1x2
int f_04b670(int);                           // sicher; liest eax; deklariert 1x2
int f_04b6f0(int);                           // sicher; liest eax; deklariert 1x2
int f_04b770(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_04b880(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 2x2
int f_04b980(int);                           // sicher; liest eax; deklariert 1x2
int f_04c000(int);                           // sicher; liest eax; deklariert 1x2
int f_04c5c0(int);                           // sicher; liest eax; deklariert 1x2
int f_04c7e0(int);                           // sicher; liest eax; deklariert 1x2
int f_04cbc0(int);                           // sicher; liest eax; deklariert 1x2
int f_04cdd0(int);                           // sicher; liest eax; deklariert 1x2
int f_04cff0(int);                           // sicher; liest eax; deklariert 1x2
int f_04d150(int);                           // sicher; liest eax; deklariert 1x2
int f_04d4d0(int);                           // sicher; liest eax; deklariert 1x2
int f_04d730(int);                           // sicher; liest eax; deklariert 1x2
int f_04d9b0(int);                           // sicher; liest eax; deklariert 1x2
int f_04dbf0(int);                           // sicher; liest eax; deklariert 1x2
int f_04e020(int);                           // sicher; liest eax; deklariert 1x2
int f_04e0a0(int);                           // sicher; liest eax; deklariert 1x1
int f_04e340(int);                           // sicher; liest eax; deklariert 1x4
int f_04ed90(int);                           // sicher; liest eax; deklariert 1x4
int f_04ee60(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_04f160(int);                           // sicher; liest eax; deklariert 1x1
int f_04f3f0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_04fc60(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_04fce0(int, int);                      // sicher; liest eax; GLEICH-Def gz_04fce0:2; deklariert 1x2 2x1
int f_04fcf0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_04fd30(int, int, int);                 // vermutet (sicher 1); liest eax; R106 ebx; deklariert 1x5
int f_04fd40(int);                           // sicher; liest eax; deklariert 1x5
int f_04fd60(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_04fdb0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5
int f_04fe30(int, int);                      // sicher; GLEICH-Def dcut:2; deklariert 0x2 2x6
int f_04fe60(int, int);                      // sicher; liest eax; GLEICH-Def dcut:2; deklariert 1x1 2x6
int f_04feb0(int, int, int, int, int, int, int, int, int); // vermutet (sicher 4); liest eax ebx ecx; ret 20?; deklariert 2x1 9x23
int f_04fef0(int, int, int, int, int, int, int); // vermutet (sicher 4); liest eax ebx ecx; ret 12?; deklariert 7x21
int f_050710(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_050770(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0508f0(int);                           // sicher; liest eax; deklariert 1x1 2x3
int f_050920(int);                           // sicher; liest eax; deklariert 1x4
int f_050930(int);                           // sicher; liest eax; deklariert 1x4
int f_050940(int);                           // sicher; liest eax; deklariert 1x4
int f_050950(int);                           // sicher; GLEICH-Def dealitem:1; deklariert 1x1
int f_050960(int);                           // sicher; liest eax; deklariert 1x4
int f_050970(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_050980(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_050b40(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_050c70(int);                           // sicher; liest eax; deklariert 1x4
int f_050e30(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_050ea0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_051060(int);                           // sicher; liest eax; deklariert 1x4
int f_051200(int, int, int, int);            // sicher; GLEICH-Def dealitem:4; deklariert 4x1
int f_0512b0(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x2
int f_051350(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0514e0(int);                           // sicher; GLEICH-Def dealitem:1; deklariert 1x1
int f_0515f0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_051780(int);                           // sicher; liest eax; deklariert 1x2
int f_051870(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_051e20(int, int, int);                 // sicher; GLEICH-Def gz_051ae0:3; deklariert 3x1
int f_051e80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_053810(int, int);                      // sicher; GLEICH-Def debugovl_t1:2; deklariert 2x1
int f_0538a0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_053a10(int, int, int, int);            // sicher; GLEICH-Def debugovl_t2:4; deklariert 4x1
int f_053a30(int, int, int, int);            // sicher; GLEICH-Def debugovl_t2:4; deklariert 3x1 4x3
int f_053ab0(int);                           // sicher; liest eax; deklariert 1x1
int f_053ae0(int);                           // sicher; GLEICH-Def debugovl_t2:1; deklariert 1x1
int f_053f20(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_053fd0(int, int);                      // sicher; liest eax; GLEICH-Def deity:2; deklariert 2x2
int f_054030(int, int);                      // sicher; GLEICH-Def deity:2; deklariert 2x1
int f_054040(int);                           // sicher; GLEICH-Def deity:1; deklariert 1x1
int f_054050(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_054060(int);                           // sicher; liest eax; deklariert 1x3
int f_054110(int);                           // sicher; liest eax; deklariert 1x2
int f_0541b0(int);                           // sicher; GLEICH-Def deity:1; deklariert 1x1
int f_054240(int);                           // sicher; GLEICH-Def deity:1; deklariert 1x1
int f_054500(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0546d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0547a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_054900(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_054a60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_054ba0(int, int, int, int, int);       // sicher; GLEICH-Def deity:5; deklariert 5x1
int f_054ca0(int, int);                      // sicher; liest eax edx; deklariert 2x11
int f_056a20(int);                           // sicher; GLEICH-Def dialog_t2:1; deklariert 1x1
int f_056a30(int);                           // sicher; liest eax; deklariert 1x9
int f_056a40(int);                           // sicher; liest eax; deklariert 1x8
int f_056a50(int);                           // sicher; liest eax; deklariert 1x11
int f_056d00(int);                           // sicher; liest eax; deklariert 1x2
int f_056d70(int);                           // sicher; liest eax; deklariert 1x2
int f_056d90(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_057220(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x54
int f_0574c0(int);                           // sicher; liest eax; deklariert 1x2
int f_057660(int);                           // sicher; liest eax; deklariert 1x2
int f_057750(int);                           // sicher; liest eax; deklariert 1x4
int f_057760(int);                           // sicher; liest eax; deklariert 1x4
int f_057770(int);                           // sicher; liest eax; deklariert 1x2
int f_0580a0(int);                           // sicher; liest eax; deklariert 1x2
int f_058210(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0585e0(int);                           // sicher; liest eax; deklariert 1x2
int f_058850(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert 5x2
int f_058960(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_058dc0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0591c0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0592f0(int, int);                      // sicher; GLEICH-Def diary2:2; deklariert 2x2
int f_059330(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_059410(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0595f0(int);                           // sicher; liest eax; deklariert 1x2
int f_059630(int);                           // sicher; liest eax; deklariert 1x2
int f_059660(int);                           // sicher; liest eax; deklariert 1x2
int f_059a40(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_059ad0(int);                           // sicher; liest eax; deklariert 1x2
int f_059d60(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_059e40(int, int);                      // sicher; liest edx; deklariert 2x1
int f_059e90(int);                           // sicher; liest eax; deklariert 1x2
int f_05a020(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_05a5c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_05a820(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_05a910(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_05aed0(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 1x2
int f_05b080(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_05b230(int);                           // sicher; liest eax; deklariert 1x1
int f_05b2c0(int);                           // sicher; liest eax; deklariert 1x2
int f_05b340(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_05b420(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_05b770(int, int);                      // sicher; GLEICH-Def gz_05b6c0:2; deklariert 2x1
int f_05b780(int);                           // sicher; GLEICH-Def gz_05b6c0:1; deklariert 1x1
int f_05b790(int);                           // sicher; GLEICH-Def gz_05b6c0:1; deklariert 1x1
int f_05b7a0(int, int);                      // sicher; GLEICH-Def gz_05b6c0:2; deklariert 2x1
int f_05b7b0(int);                           // sicher; GLEICH-Def gz_05b6c0:1; deklariert 1x1
int f_05b7c0(int, int);                      // sicher; GLEICH-Def gz_05b6c0:2; deklariert 2x1
int f_05b7d0(int);                           // sicher; GLEICH-Def gz_05b6c0:1; deklariert 1x1
int f_05cf70(int);                           // sicher; liest eax; deklariert 1x2
int f_05d0d0(int);                           // sicher; liest eax; deklariert 1x2
int f_05d280(int);                           // sicher; GLEICH-Def diskmenu_t2:1; deklariert 1x1
int f_05d2b0(int);                           // sicher; GLEICH-Def diskmenu_t2:1; deklariert 1x1
int f_05d2d0(int);                           // sicher; liest eax; deklariert 1x2
int f_05d320(int);                           // sicher; GLEICH-Def diskmenu_t2:1; deklariert 1x1
int f_05d370(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_05d460(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_05d650(int);                           // sicher; liest eax; deklariert 1x2
int f_05da10(int, int);                      // sicher; liest eax edx; deklariert 2x2 3x1
int f_05da90(int);                           // sicher; liest eax; deklariert 1x2
int f_05db50(int);                           // sicher; GLEICH-Def diskmenu_t2:1; deklariert 1x1
int f_05dbd0(int);                           // sicher; GLEICH-Def diskmenu_t2:1; deklariert 1x1
int f_05dca0(int, int);                      // sicher; GLEICH-Def diskmenu_t2:2; deklariert 2x1
int f_05dcd0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_05dec0(int);                           // sicher; liest eax; deklariert 1x22
int f_05ded0(int, int);                      // sicher; liest eax edx; deklariert 2x27
int f_05dee0(int);                           // sicher; GLEICH-Def gz_05dec0:1; deklariert 1x2
int f_05def0(int, int);                      // sicher; GLEICH-Def gz_05dec0:2; deklariert 2x2
int f_05dfc0(int);                           // sicher; GLEICH-Def gz_05dec0:1; deklariert 1x2
int f_05e080(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x2
int f_05e170(int);                           // sicher; liest eax; deklariert 1x2
int f_05e1c0(int, int);                      // sicher; liest eax edx; deklariert 2x4 3x1
int f_05e1d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x9
int f_05e1f0(int);                           // sicher; liest eax; deklariert 1x9
int f_05e200(int);                           // sicher; liest eax; deklariert 1x10
int f_05e270(int);                           // sicher; liest eax; deklariert 2x16
int f_05e2a0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x30
int f_05e2d0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x34
int f_05e320(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x63 4x1
int f_05e340(int);                           // sicher; liest eax; deklariert 1x16
int f_05e360(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x24
int f_05e380(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x4
int f_05e3d0(int);                           // sicher; GLEICH-Def gz_05dec0:1; deklariert 1x2
int f_05e400(int, int);                      // sicher; GLEICH-Def gz_05dec0:2; deklariert 2x2
int f_05e410(int);                           // sicher; GLEICH-Def gz_05dec0:1; deklariert 1x2
int f_05e420(int, int);                      // sicher; liest eax edx; deklariert 2x14 3x1
int f_05e440(int);                           // sicher; liest eax; deklariert 2x10
int f_05e490(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_05e610(int);                           // sicher; liest eax; deklariert 2x5
int f_05e770(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 4x3
int f_05e7e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x9
int f_05e800(int, int, int, int);            // vermutet (sicher 3); liest eax edx ebx; R106 ecx; deklariert 3x8
int f_05e820(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_05e830(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_05e840(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_05e850(int);                           // sicher; liest eax; deklariert 1x6
int f_05e860(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 4x3
int f_05ebd0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x7
int f_05ecf0(int);                           // sicher; GLEICH-Def dodungeo:1; deklariert 1x2
int f_05f190(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x24
int f_05f220(int, int);                      // sicher; liest eax; GLEICH-Def door:2; deklariert 2x24
int f_05f280(int, int);                      // sicher; liest eax edx; deklariert 2x20
int f_05f360(int);                           // sicher; liest eax; deklariert 1x4
int f_05f460(int);                           // sicher; GLEICH-Def door:1; deklariert 1x2
int f_05f470(int);                           // sicher; liest eax; deklariert 1x12 2x1
int f_05f480(int);                           // sicher; liest eax; deklariert 1x16
int f_05f4f0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 2x10
int f_05f560(int);                           // sicher; liest eax; deklariert 1x9
int f_05f580(int);                           // sicher; liest eax; deklariert 1x21
int f_05f5a0(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_05f6e0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_05f7d0(int);                           // sicher; GLEICH-Def door:1; deklariert 1x1
int f_05f800(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_05fa00(int, int);                      // sicher; liest eax edx; deklariert 2x27
int f_05fc00(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_05fd70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_05fe40(int);                           // sicher; liest eax; deklariert 1x1
int f_05fe80(int, int);                      // sicher; liest eax edx; deklariert -
int f_05fea0(int);                           // sicher; liest eax; deklariert -
int f_05fee0(int);                           // sicher; liest eax; deklariert 1x2
int f_05fef0(int);                           // sicher; liest eax; deklariert 1x2
int f_05ff00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_05ff30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_060030(int);                           // sicher; liest eax; deklariert 1x1 2x20
int f_060080(int);                           // sicher; liest eax; deklariert 1x1
int f_0600f0(int, int);                      // sicher; liest edx; deklariert 2x5
int f_060100(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_060230(int);                           // vermutet (sicher 0); Aufrufer-Modus 1; deklariert 0x7 1x3 3x1
int f_060240(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 0x9
int f_0602d0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0602f0(int, int);                      // sicher; liest eax edx; deklariert 2x1 4x2
int f_060360(int);                           // sicher; liest eax; deklariert 1x14
int f_0603b0(int);                           // sicher; liest eax; deklariert 1x27
int f_0606a0(int, int);                      // sicher; liest eax edx; deklariert 2x49
int f_060740(int);                           // sicher; liest eax; deklariert 2x43 4x10
int f_060760(int);                           // sicher; liest eax; deklariert 1x19
int f_060770(int, int);                      // sicher; liest eax edx; deklariert 2x15
int f_0607e0(int, int);                      // sicher; liest eax edx; deklariert 2x41
int f_060800(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x47
int f_060990(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0609d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_060a10(int);                           // sicher; liest eax; deklariert 1x13
int f_060a80(int);                           // sicher; liest eax; deklariert 1x4 4x1
int f_060ae0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_060fd0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x3
int f_061050(int, int);                      // sicher; liest edx; deklariert 2x2
int f_061080(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_061350(int);                           // sicher; liest eax; deklariert 1x4
int f_0614d0(int);                           // sicher; liest eax; deklariert 1x4
int f_061590(int);                           // sicher; liest eax; deklariert 1x5
int f_0616f0(int);                           // sicher; liest eax; deklariert 1x5
int f_0617f0(int);                           // sicher; liest eax; deklariert 1x4
int f_061880(int);                           // sicher; liest eax; deklariert 1x4
int f_0619e0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_061b10(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x5
int f_061cd0(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 2x5
int f_061d20(int);                           // sicher; liest eax; deklariert 1x2
int f_061e60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_061ee0(int);                           // sicher; liest eax; deklariert 1x2
int f_061f10(int, int);                      // sicher; liest edx; deklariert 2x3
int f_061f40(int, int);                      // sicher; liest edx; deklariert 2x2
int f_061f60(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_061fa0(int);                           // sicher; liest eax; deklariert 1x3
int f_061fd0(int);                           // sicher; liest eax; deklariert 1x2
int f_062000(int);                           // sicher; liest eax; deklariert 1x2
int f_062120(int);                           // sicher; liest eax; deklariert 1x2
int f_0621b0(int);                           // sicher; liest eax; deklariert 1x3
int f_0622e0(int);                           // sicher; liest eax; deklariert 1x2
int f_062390(int);                           // sicher; liest eax; deklariert 1x2
int f_0624b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0625e0(int);                           // sicher; liest eax; deklariert 1x4
int f_0627a0(int);                           // sicher; GLEICH-Def gz_0625e0:1; deklariert 1x2
int f_0631f0(int);                           // sicher; GLEICH-Def gz_0625e0:1; deklariert 1x1
int f_063200(int);                           // sicher; GLEICH-Def gz_0625e0:1; deklariert 1x1
int f_063210(int);                           // sicher; GLEICH-Def gz_0625e0:1; deklariert 1x1
int f_063220(int);                           // sicher; GLEICH-Def gz_0625e0:1; deklariert 1x1
int f_0634f0(int);                           // sicher; GLEICH-Def gz_0625e0:1; deklariert 1x1
int f_063740(int);                           // sicher; GLEICH-Def environ1:1; deklariert 1x1
int f_063870(int);                           // sicher; GLEICH-Def environ1:1; deklariert 1x1
int f_063900(int, int);                      // sicher; liest edx; deklariert 2x2
int f_063b90(int, int, int);                 // sicher; GLEICH-Def environ1:3; deklariert 3x1
int f_063f40(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0641c0(int);                           // sicher; GLEICH-Def gz_0640f0_t1:1; deklariert 1x2
int f_064240(int, int);                      // sicher; GLEICH-Def gz_0640f0_t1:2; deklariert 2x1
int f_064880(int);                           // sicher; liest eax; deklariert 1x2
int f_0661f0(int);                           // sicher; GLEICH-Def environ2_t1:1; deklariert 1x1
int f_066a90(int);                           // sicher; GLEICH-Def environ2_t1:1; deklariert 1x1
int f_066b20(int);                           // sicher; liest eax; deklariert 1x2
int f_066e50(int);                           // sicher; liest eax; deklariert 1x2
int f_067f10(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_068000(int);                           // sicher; GLEICH-Def environ2_t2:1; deklariert 1x2
int f_068380(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0695b0(int);                           // sicher; liest eax; deklariert -
int f_0695c0(int);                           // sicher; liest eax; deklariert 1x2
int f_069630(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_069640(int);                           // sicher; liest eax; deklariert 1x2
int f_069650(int, int);                      // sicher; liest eax edx; deklariert -
int f_069660(int);                           // sicher; liest eax; deklariert 1x2
int f_069670(int, int);                      // sicher; liest eax edx; deklariert -
int f_069690(int);                           // sicher; liest eax; deklariert 1x2
int f_0696a0(int);                           // sicher; liest eax; deklariert 1x2
int f_0696b0(int);                           // sicher; liest eax; deklariert -
int f_0696c0(int);                           // sicher; liest eax; deklariert -
int f_0696e0(int);                           // sicher; liest eax; deklariert 1x2
int f_0696f0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_069730(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_069770(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0697c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x24
int f_069860(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_0698b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_069970(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_069a00(int, int);                      // sicher; liest eax edx; deklariert 2x14
int f_069a20(int);                           // sicher; liest eax; deklariert 1x2
int f_069b10(int);                           // sicher; liest eax; deklariert 1x2
int f_069be0(int);                           // sicher; liest eax; deklariert 1x10
int f_069c10(int, int, int, int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 28; deklariert 11x1
int f_06a550(int, int, int, int, int);       // sicher; GLEICH-Def gz_069970:5; deklariert 5x1
int f_06a5a0(int);                           // sicher; GLEICH-Def gz_069970:1; deklariert 1x1
int f_06a5b0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_06a5e0(int, int);                      // sicher; GLEICH-Def gz_069970:2; deklariert 2x1
int f_06a5f0(int);                           // sicher; liest eax; deklariert 1x1
int f_06a600(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_06a610(int);                           // sicher; GLEICH-Def gz_069970:1; deklariert 1x1
int f_06a620(int, int);                      // sicher; GLEICH-Def gz_069970:2; deklariert 2x1
int f_06a630(int);                           // sicher; GLEICH-Def gz_069970:1; deklariert 1x1
int f_06a640(int, int);                      // sicher; GLEICH-Def gz_069970:2; deklariert 2x1
int f_06a650(int, int);                      // sicher; GLEICH-Def gz_069970:2; deklariert 2x1
int f_06a660(int);                           // sicher; GLEICH-Def gz_069970:1; deklariert 1x1
int f_06a670(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_06a6a0(int, int);                      // sicher; GLEICH-Def gz_069970:2; deklariert 2x1
int f_06a6b0(int);                           // sicher; GLEICH-Def gz_069970:1; deklariert 1x1
int f_06a6c0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_06a6d0(int);                           // sicher; GLEICH-Def gz_069970:1; deklariert 1x1
int f_06a6e0(int, int, int);                 // sicher; liest eax ebx; deklariert 3x5
int f_06a710(int, int);                      // sicher; liest eax; GLEICH-Def gz_069970:2; deklariert 2x2
int f_06a790(int);                           // sicher; liest eax; deklariert 1x2
int f_06a900(int);                           // sicher; liest eax; deklariert 1x2
int f_06acb0(int);                           // sicher; liest eax; deklariert -
int f_06bd70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_06bdd0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_06c380(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_06c930(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x6
int f_06d050(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_06d0d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_06d380(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_06d4a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_06d580(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_06daa0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_06df80(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_06e4f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_06e9e0(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x8
int f_06ebf0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_06ed10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x14
int f_06ed80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_06efc0(int, int, int, int);            // vermutet (sicher 3); liest eax edx ebx; R106 ecx; deklariert 3x1 4x6
int f_06f400(int, int, int, int, int, int, int); // vermutet (sicher 4); liest edx ebx ecx; ret 12?; deklariert 7x3
int f_06f5c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_06f690(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_06f850(int, int, int, int);            // vermutet (sicher 3); liest eax edx ebx; Aufrufer-Modus 4; deklariert 4x5
int f_06fb20(int);                           // sicher; liest eax; deklariert 1x1
int f_0701d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_070440(int);                           // sicher; liest eax; deklariert 1x1
int f_0709d0(int);                           // sicher; liest eax; deklariert 1x2
int f_070c50(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_070d70(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert -
int f_070e50(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x1
int f_0710e0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_0711c0(int);                           // sicher; liest eax; deklariert 1x1
int f_0712f0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_071880(int);                           // sicher; liest eax; deklariert 1x1
int f_071e20(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x11
int f_071e50(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x15
int f_071e90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x23
int f_071f20(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_071f70(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_071fb0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_071fe0(int, int);                      // sicher; liest edx; deklariert 2x5
int f_072110(int, int);                      // sicher; liest edx; deklariert 2x4
int f_0722a0(int, int);                      // sicher; liest edx; deklariert 2x8 4x1
int f_072440(int, int);                      // sicher; liest edx; deklariert 2x5 3x1
int f_072610(int, int, int);                 // sicher; liest edx ebx; deklariert 3x1
int f_0727e0(int);                           // sicher; liest eax; deklariert 1x11
int f_072810(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_072850(int);                           // sicher; liest eax; deklariert 1x1
int f_072910(int);                           // sicher; GLEICH-Def gz_0727e0:1; deklariert 0x2 1x9
int f_072940(int);                           // sicher; liest eax; deklariert 1x7
int f_0729c0(int);                           // sicher; liest eax; deklariert 1x19
int f_072a00(int);                           // sicher; liest eax; deklariert 1x7
int f_072b70(int);                           // sicher; liest eax; deklariert 1x5
int f_072cf0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_072ec0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0730d0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_073410(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_0735b0(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x4
int f_073800(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_0738a0(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x4
int f_074680(int, int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 20; deklariert 9x2
int f_074a50(int, int);                      // sicher; GLEICH-Def fi_g_tar_t1:2; deklariert 2x1
int f_074a90(int, int, int, int, int, int, int, int, int); // vermutet (sicher 4); liest edx ebx ecx; ret 20?; deklariert 9x2
int f_074b40(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x11
int f_0757f0(int);                           // sicher; liest eax; deklariert 1x19
int f_0758b0(int);                           // sicher; liest eax; deklariert 1x8
int f_075930(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_075bc0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_075e90(int, int, int, int, int, int, int, int, int); // sicher; liest edx ebx ecx; ret 20?; GLEICH-Def fi_gfx:9; deklariert 9x1
int f_075f10(int);                           // sicher; liest eax; deklariert 1x10
int f_0762e0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x12
int f_076480(int, int, int, int, int, int, int, int, int); // vermutet (sicher 4); liest edx ebx ecx; ret 20?; deklariert 9x1
int f_0765a0(int);                           // sicher; liest eax; deklariert 1x10
int f_076a40(int);                           // sicher; liest eax; deklariert 1x1
int f_076bd0(int);                           // sicher; liest eax; deklariert 1x3
int f_0773b0(int);                           // sicher; liest eax; deklariert 1x16
int f_077400(int);                           // sicher; liest eax; deklariert 1x5
int f_077540(int);                           // sicher; liest eax; deklariert 1x3
int f_077760(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1 4x3
int f_077e20(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_077fd0(int);                           // sicher; liest eax; deklariert 1x2
int f_078170(int);                           // sicher; liest eax; deklariert 1x2
int f_078430(int);                           // sicher; liest eax; deklariert 1x2
int f_078550(int);                           // sicher; liest eax; deklariert 1x2
int f_078790(int);                           // sicher; liest eax; deklariert 1x2
int f_0789b0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_078a90(int);                           // sicher; liest eax; deklariert 4x1
int f_078b40(int, int, int, int, int, int);  // vermutet (sicher 4); liest edx ebx ecx; ret 8?; deklariert 6x1
int f_078c90(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_078ec0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_078f60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0790e0(int, int, int);                 // sicher; GLEICH-Def fi_large_t1:3; deklariert 3x1
int f_079110(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0791f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_079670(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0799c0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_079e80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1 4x1
int f_079f70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_07a2b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_07a470(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_07a4d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_07a560(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_07a600(int);                           // sicher; liest eax; deklariert 1x2
int f_07a6a0(int);                           // sicher; liest eax; deklariert 1x2
int f_07a730(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_07a7e0(int);                           // sicher; liest eax; deklariert 1x2
int f_07a8a0(int);                           // sicher; liest eax; deklariert 1x1
int f_07a9e0(int, int);                      // sicher; liest eax edx; deklariert 1x3
int f_07aa10(int, int);                      // sicher; liest eax edx; deklariert 1x3
int f_07aa40(int);                           // sicher; liest eax; deklariert 1x2
int f_07aab0(int, int, int, int);            // sicher; liest eax ecx; deklariert 1x2
int f_07ab80(int);                           // sicher; liest eax; deklariert 1x2
int f_07ad40(int, int, int, int, int, int, int); // sicher; liest edx ebx ecx; ret 12?; GLEICH-Def fi_miovl:7; deklariert 7x1
int f_07aec0(int);                           // sicher; liest eax; deklariert 1x2
int f_07b150(int, int);                      // sicher; liest edx; deklariert 2x2
int f_07b1d0(int);                           // vermutet (sicher 0); Aufrufer-Modus 1; deklariert 0x4
int f_07b220(int);                           // sicher; liest eax; deklariert 1x8
int f_07b370(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_07b580(int, int, int);                 // sicher; liest edx ebx; deklariert 2x2
int f_07b5e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_07b6b0(int, int, int, int, int);       // sicher; liest edx ebx ecx; ret 4?; GLEICH-Def gz_07b370:5; deklariert 5x2
int f_07b7e0(int);                           // sicher; liest eax; deklariert 1x4
int f_07bd30(int, int, int);                 // sicher; liest edx ebx; deklariert 3x9
int f_07be00(int, int, int);                 // sicher; liest edx ebx; deklariert 3x1
int f_07beb0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 2x2 4x1
int f_07c1a0(int, int, int, int, int, int);  // vermutet (sicher 4); liest edx ebx ecx; ret 8?; deklariert 6x2
int f_07c2a0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_07c900(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_07cb00(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_07d080(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_07d6a0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_07db20(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x3
int f_07dee0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_07e5c0(int);                           // sicher; liest eax; deklariert 1x3
int f_07e640(int);                           // sicher; liest eax; deklariert 1x2 2x1
int f_07e6c0(int);                           // sicher; GLEICH-Def fi_olist:1; deklariert 1x2
int f_07e730(int, int);                      // sicher; GLEICH-Def fi_olist:2; deklariert 2x2
int f_07e760(int, int);                      // sicher; GLEICH-Def fi_olist:2; deklariert 2x2
int f_07e790(int);                           // sicher; GLEICH-Def fi_olist:1; deklariert 1x2
int f_07e7c0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_07e850(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_07e8e0(int);                           // sicher; liest eax; deklariert 1x3
int f_07e930(int);                           // sicher; liest eax; deklariert 1x8
int f_07ea20(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_07ea60(int, int);                      // sicher; liest eax edx; deklariert 2x20
int f_07ea90(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_07ead0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_07eb00(int, int);                      // sicher; liest eax edx; deklariert 2x9 4x2
int f_07eb30(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_07eb80(int);                           // sicher; GLEICH-Def fi_olist:1; deklariert 1x2
int f_07eba0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x15
int f_07ec10(int, int);                      // sicher; liest eax edx; deklariert 2x15
int f_07f3a0(int, int);                      // sicher; liest eax edx; deklariert -
int f_07fe00(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_081130(int, int);                      // sicher; liest eax edx; deklariert -
int f_0817a0(int);                           // sicher; liest eax; deklariert -
int f_082350(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_082460(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0828d0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_082920(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_082d30(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_083060(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0832b0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_083680(int, int);                      // sicher; liest edx; deklariert -
int f_0839d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_083dc0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_083f80(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_084410(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0845b0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_084890(int, int, int);                 // sicher; liest edx ebx; deklariert 3x4
int f_084a60(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_084b40(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x5
int f_084dd0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_084f90(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_085050(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 3x1 4x1
int f_085640(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_085cd0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_085d60(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_086590(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_086800(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_086950(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_086a00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x10
int f_086bf0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_087270(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_0873f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_087780(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_087ea0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_088510(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0886c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_088a50(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_088f20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0890a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0892a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_089990(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_08a020(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_08a160(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_08a370(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_08a740(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_08ae00(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_08af80(int);                           // sicher; liest eax; deklariert 1x2
int f_08b500(int);                           // sicher; liest eax; deklariert 1x2
int f_08ba30(int);                           // sicher; liest eax; deklariert 1x2
int f_08bc00(int);                           // sicher; GLEICH-Def gz_08ba30:1; deklariert 1x1
int f_08bcd0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_08c2e0(int);                           // sicher; liest eax; deklariert 1x1
int f_08c5b0(int);                           // sicher; liest eax; deklariert 1x1
int f_08c820(int);                           // sicher; liest eax; deklariert 1x2
int f_08c920(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_08ccc0(int);                           // sicher; GLEICH-Def gz_08cb00:1; deklariert 0x1 1x1
int f_08cd00(int);                           // sicher; GLEICH-Def gz_08cb00:1; deklariert 1x2
int f_08d7a0(int);                           // sicher; liest eax; deklariert 1x2
int f_08d880(int);                           // sicher; GLEICH-Def final1:1; deklariert 1x1
int f_08dc20(int);                           // sicher; GLEICH-Def gz_08dae0:1; deklariert 1x1
int f_08de20(int);                           // sicher; liest eax; deklariert 1x4
int f_08dee0(int, int);                      // sicher; GLEICH-Def gz_08dae0:2; deklariert 2x1
int f_08f180(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f190(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f1b0(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f1c0(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 0x1 1x2
int f_08f3e0(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f420(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f460(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f4a0(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f4b0(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f4d0(int);                           // sicher; GLEICH-Def final2_t1:1; deklariert 1x1
int f_08f900(int);                           // sicher; GLEICH-Def final2_t2:1; deklariert 1x1
int f_08f910(int);                           // sicher; GLEICH-Def final2_t2:1; deklariert 1x1
int f_08f920(int);                           // sicher; GLEICH-Def final2_t2:1; deklariert 1x1
int f_08f930(int);                           // sicher; GLEICH-Def final2_t2:1; deklariert 1x1
int f_08f960(int);                           // sicher; GLEICH-Def final2_t2:1; deklariert 1x1
int f_08f980(int);                           // sicher; GLEICH-Def final2_t2:1; deklariert 1x1
int f_08fd60(int);                           // sicher; liest eax; deklariert 1x2
int f_090b90(int);                           // sicher; liest eax; deklariert 1x2
int f_090d20(int);                           // sicher; GLEICH-Def final2_t3:1; deklariert 1x1
int f_090de0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_090eb0(int);                           // sicher; GLEICH-Def final2_t3:1; deklariert 1x1
int f_090fa0(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_0910f0(int);                           // sicher; GLEICH-Def final2_t3:1; deklariert 1x1
int f_0911e0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0914a0(int);                           // sicher; liest eax; deklariert 1x2
int f_0915c0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0916b0(int, int);                      // sicher; GLEICH-Def final2_t3:2; deklariert 2x1
int f_091f70(int);                           // sicher; liest eax; deklariert 1x57
int f_092140(int);                           // sicher; GLEICH-Def gamepoin:1; deklariert 1x1
int f_092190(int);                           // sicher; GLEICH-Def gamepoin:1; deklariert 1x1
int f_0921d0(int);                           // sicher; GLEICH-Def gamepoin:1; deklariert 1x1
int f_092310(int, int, int);                 // vermutet (sicher 0); Aufrufer-Modus 3; deklariert 1x1
int f_092ee0(int, int, int);                 // sicher; GLEICH-Def gz_092ee0:3; deklariert 3x1
int f_092f00(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_092f20(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_092f40(int);                           // sicher; liest eax; deklariert 1x1
int f_0934f0(int);                           // sicher; liest eax; deklariert 2x1
int f_0936d0(int);                           // sicher; liest eax; deklariert 1x1
int f_0937e0(int);                           // sicher; liest eax; deklariert 1x1
int f_0938a0(int);                           // sicher; liest eax; deklariert 1x2
int f_093900(int);                           // sicher; liest eax; deklariert -
int f_093bb0(int);                           // sicher; liest eax; deklariert 1x1
int f_094330(int);                           // sicher; liest eax; deklariert 1x5
int f_0945c0(int);                           // sicher; liest eax; deklariert 1x4
int f_094700(int);                           // sicher; liest eax; deklariert 1x1
int f_094ac0(int);                           // sicher; liest eax; deklariert 1x2
int f_094c70(int);                           // sicher; liest eax; deklariert 1x3
int f_094f40(int);                           // sicher; liest eax; deklariert 1x4
int f_095600(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_095710(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_095820(int);                           // sicher; liest eax; deklariert 1x2
int f_0959c0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_095ae0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_095c40(int);                           // sicher; liest eax; deklariert 1x1
int f_096790(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_096960(int);                           // sicher; liest eax; deklariert 1x1
int f_0969c0(int);                           // sicher; liest eax; deklariert 1x1
int f_096d40(int);                           // sicher; liest eax; deklariert 1x1
int f_0971f0(int, int, int);                 // sicher; liest eax ebx; deklariert -
int f_0974f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 2x2
int f_097600(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_097700(int);                           // sicher; liest eax; deklariert 1x1
int f_0978a0(int);                           // sicher; liest eax; deklariert 1x1 2x2
int f_097960(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_098240(int);                           // sicher; liest eax; deklariert 1x1
int f_098730(int);                           // sicher; liest eax; deklariert 1x2
int f_098a90(int);                           // sicher; liest eax; deklariert 1x1
int f_098d90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_098e60(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_098fe0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 3x1 4x2
int f_0990b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_099510(int, int, int);                 // sicher; GLEICH-Def gfx_t2:3; deklariert 3x1
int f_099560(int);                           // sicher; liest eax; deklariert 1x2
int f_0995c0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_099740(int, int);                      // sicher; GLEICH-Def gfx_t2:2; deklariert 2x1
int f_099750(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0997a0(int);                           // sicher; GLEICH-Def gfx_t2:1; deklariert 1x1
int f_0998e0(int, int);                      // sicher; GLEICH-Def gfx_t2:2; deklariert 2x1
int f_099910(int);                           // sicher; liest eax; deklariert 1x2
int f_0999f0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_099a20(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_099a90(int);                           // sicher; GLEICH-Def gfx_t2:1; deklariert 1x1
int f_099ad0(int, int);                      // sicher; GLEICH-Def gfx_t2:2; deklariert 2x1
int f_099b10(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_099d20(int, int);                      // sicher; GLEICH-Def gfx_t2:2; deklariert 2x1
int f_099d50(int);                           // sicher; GLEICH-Def gfx_t2:1; deklariert 1x1
int f_099da0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_099f70(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_099fa0(int);                           // sicher; liest eax; deklariert 1x6
int f_099ff0(int);                           // sicher; liest eax; deklariert 1x2
int f_09a030(int);                           // sicher; liest eax; deklariert 1x2
int f_09a040(int, int);                      // sicher; liest eax edx; deklariert 1x2 2x7
int f_09a080(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x7
int f_09a0d0(int);                           // sicher; liest eax; deklariert 1x41 2x1 4x1
int f_09a120(int, int);                      // sicher; liest eax edx; deklariert 2x29
int f_09a140(int, int);                      // sicher; liest eax edx; deklariert 2x46
int f_09a180(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x3
int f_09a2d0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_09a470(int);                           // sicher; liest eax; deklariert 1x4
int f_09a4c0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_09a540(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_09a720(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_09a7d0(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x1
int f_09a850(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_09a990(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_09aa00(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x2
int f_09ac80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x16
int f_09ade0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x16
int f_09aed0(int);                           // sicher; liest eax; deklariert 1x15 2x1
int f_09b080(int, int);                      // sicher; liest edx; deklariert 2x2
int f_09b500(int);                           // sicher; GLEICH-Def headquar:1; deklariert 1x1
int f_09b540(int);                           // sicher; GLEICH-Def headquar:1; deklariert 1x1
int f_09b570(int);                           // sicher; liest eax; deklariert 1x2
int f_09b900(int, int);                      // sicher; GLEICH-Def gz_09b900:2; deklariert 2x1
int f_09b980(int, int);                      // sicher; liest edx; deklariert 2x2
int f_09bc00(int);                           // sicher; liest eax; deklariert 1x2
int f_09be20(int);                           // sicher; liest eax; deklariert 1x2
int f_09c090(int);                           // sicher; liest eax; deklariert 1x2
int f_09c330(int);                           // sicher; liest eax; deklariert 1x2
int f_09c750(int);                           // sicher; liest eax; deklariert 1x1
int f_09c760(int);                           // sicher; GLEICH-Def gz_09ba80:1; deklariert 1x1
int f_09c770(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_09c780(int);                           // sicher; liest eax; deklariert 1x10
int f_09c800(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x10
int f_09c890(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x9
int f_09c910(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_09c990(int);                           // sicher; liest eax; deklariert 1x7
int f_09ce70(int);                           // sicher; liest eax; deklariert 1x2
int f_09cf50(int, int, int);                 // sicher; GLEICH-Def hyperhlp_t1:3; deklariert 3x1
int f_09cf80(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_09d540(int);                           // sicher; liest eax; deklariert 1x3
int f_09d640(int, int);                      // sicher; liest eax edx; deklariert 1x3
int f_09d850(int);                           // sicher; liest eax; deklariert 1x2
int f_09dae0(int);                           // sicher; GLEICH-Def hyperhlp_t1:1; deklariert 0x2 1x2
int f_09db10(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_09db40(int);                           // sicher; GLEICH-Def hyperhlp_t1:1; deklariert 1x1
int f_09db80(int, int, int);                 // sicher; liest edx ebx; deklariert 3x4
int f_09dbe0(int, int, int, int);            // sicher; liest eax edx ecx; deklariert 2x2 4x2
int f_09dc00(int);                           // sicher; liest eax; deklariert 1x4
int f_09dc50(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_09e100(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_09e140(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x4
int f_09e1c0(int);                           // sicher; GLEICH-Def hyperhlp_t2:1; deklariert 1x1
int f_09e220(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 3x1 4x4
int f_09e3f0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_09ea10(int);                           // sicher; liest eax; deklariert 1x2
int f_09ece0(int);                           // sicher; liest eax; deklariert 1x3
int f_09f070(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_09f6a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a01a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a1c50(int, int);                      // sicher; GLEICH-Def gz_0a16b0:2; deklariert 2x1
int f_0a1c70(int, int, int, int, int);       // sicher; GLEICH-Def gz_0a16b0:5; deklariert 5x1
int f_0a1cb0(int, int);                      // sicher; GLEICH-Def gz_0a16b0:2; deklariert 2x1
int f_0a1e10(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0a2020(int);                           // sicher; GLEICH-Def icon:1; deklariert 1x1
int f_0a20a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0a2230(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a22e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0a2400(int);                           // sicher; liest eax; deklariert 2x3
int f_0a2430(int);                           // sicher; liest eax; deklariert 1x6
int f_0a2440(int);                           // sicher; liest eax; deklariert 1x6
int f_0a2450(int);                           // sicher; liest eax; deklariert 1x4
int f_0a2460(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_0a2480(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_0a2500(int);                           // sicher; liest eax; deklariert -
int f_0a2520(int, int, int, int, int, int, int); // vermutet (sicher 4); liest edx ebx ecx; ret 12?; deklariert 7x5
int f_0a2810(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a2e30(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0a3430(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0a34d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0a3570(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert 0x1 5x1
int f_0a3700(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0a3730(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0a3830(int, int, int);                 // sicher; GLEICH-Def import:3; deklariert 3x1
int f_0a3840(int);                           // sicher; GLEICH-Def import:1; deklariert 1x1
int f_0a3850(int);                           // sicher; GLEICH-Def import:1; deklariert 1x1
int f_0a3870(int);                           // sicher; GLEICH-Def import:1; deklariert 1x1
int f_0a38a0(int);                           // sicher; GLEICH-Def import:1; deklariert 1x1
int f_0a3c30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0a4690(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0a50e0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0a51c0(int, int, int);                 // sicher; GLEICH-Def import2_t2:3; deklariert 3x1
int f_0a5230(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a5240(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0a5730(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0a5780(int, int);                      // sicher; GLEICH-Def gz_0a5730:2; deklariert 2x1
int f_0a5a70(int);                           // sicher; GLEICH-Def gz_0a5730:1; deklariert 1x1
int f_0a5b30(int);                           // sicher; GLEICH-Def gz_0a5730:1; deklariert 1x1
int f_0a5b90(int, int);                      // sicher; GLEICH-Def gz_0a5730:2; deklariert 2x1
int f_0a5bb0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a5d20(int);                           // sicher; GLEICH-Def gz_0a5730:1; deklariert 1x1
int f_0a5d80(int);                           // sicher; liest eax; deklariert 1x2
int f_0a5f30(int);                           // sicher; liest eax; deklariert 1x2
int f_0a6030(int);                           // sicher; liest eax; deklariert 1x2
int f_0a61a0(int);                           // sicher; GLEICH-Def gz_0a5730:1; deklariert 1x1
int f_0a6200(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0a6280(int);                           // sicher; liest eax; deklariert 2x2
int f_0a62b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0a62c0(int);                           // sicher; liest eax; deklariert 1x2
int f_0a62d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a62e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0a6380(int);                           // sicher; liest eax; deklariert 1x1
int f_0a6440(int);                           // sicher; liest eax; deklariert 1x2
int f_0a65b0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a6690(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0a6740(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_0a6b50(int);                           // sicher; liest eax; deklariert 0x1
int f_0a75d0(int, int, int);                 // sicher; GLEICH-Def gz_0a6280:3; deklariert 3x1
int f_0a7600(int, int, int, int);            // sicher; GLEICH-Def gz_0a6280:4; deklariert 4x1
int f_0a7610(int, int, int);                 // sicher; liest ebx; deklariert 0x2 3x1
int f_0a7800(int);                           // sicher; liest eax; deklariert 1x8
int f_0a7810(int);                           // sicher; liest eax; deklariert 1x19
int f_0a7820(int);                           // sicher; liest eax; deklariert 1x3
int f_0a7830(int);                           // sicher; liest eax; deklariert 1x2
int f_0a7840(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x19
int f_0a7890(int);                           // sicher; liest eax; deklariert 1x1
int f_0a78a0(int);                           // sicher; liest eax; deklariert 1x17
int f_0a78b0(int);                           // sicher; liest eax; deklariert 1x19
int f_0a78c0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a78d0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a78e0(int);                           // sicher; liest eax; deklariert 1x4
int f_0a78f0(int);                           // sicher; liest eax; deklariert 1x21
int f_0a7910(int);                           // sicher; liest eax; deklariert 1x12
int f_0a7930(int);                           // sicher; liest eax; deklariert 1x8
int f_0a7950(int);                           // sicher; liest eax; deklariert 1x47
int f_0a7970(int);                           // sicher; liest eax; deklariert 1x6
int f_0a7990(int);                           // sicher; liest eax; deklariert 1x37
int f_0a79b0(int);                           // sicher; liest eax; deklariert 1x14
int f_0a79c0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a79e0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7a00(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7a20(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7a40(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7a60(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7a80(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7a90(int);                           // sicher; liest eax; deklariert 1x6
int f_0a7ac0(int);                           // sicher; liest eax; deklariert 1x1
int f_0a7ad0(int);                           // sicher; liest eax; deklariert 1x10
int f_0a8830(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_0a8b40(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x1 2x5
int f_0a8be0(int);                           // sicher; liest eax; deklariert 1x6
int f_0a8e40(int);                           // sicher; liest eax; deklariert 1x2
int f_0a9040(int, int);                      // sicher; GLEICH-Def itemdist_t1:2; deklariert 2x1
int f_0a9080(int);                           // sicher; liest eax; deklariert 1x2
int f_0a9630(int);                           // sicher; liest eax; deklariert 1x2
int f_0a9840(int, int);                      // sicher; GLEICH-Def itemdist_t2:2; deklariert 2x2
int f_0a9890(int);                           // sicher; liest eax; deklariert 1x2
int f_0a9990(int);                           // sicher; liest eax; deklariert 1x4
int f_0a9a40(int);                           // sicher; liest eax; deklariert 1x2
int f_0a9b50(int);                           // sicher; GLEICH-Def itemdist_t2:1; deklariert 1x2
int f_0a9c90(int);                           // sicher; liest eax; deklariert 1x4
int f_0a9d90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_0a9e50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0aa250(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0aa430(int);                           // sicher; liest eax; deklariert 1x3
int f_0aa5b0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0aa690(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0aa930(int, int);                      // sicher; GLEICH-Def itemdist_t3:2; deklariert 2x2
int f_0aa990(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0aab50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 1x1 3x2
int f_0aac50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0aadb0(int);                           // sicher; liest eax; deklariert 1x2
int f_0aaf10(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_0aafe0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0ab080(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0ab2e0(int, int);                      // sicher; GLEICH-Def itemdist_t3:2; deklariert 2x2
int f_0ab320(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0ab520(int);                           // sicher; GLEICH-Def itemdist_t3:1; deklariert 1x2
int f_0ab550(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0ab6f0(int);                           // sicher; liest eax; deklariert 1x3
int f_0ab880(int);                           // sicher; GLEICH-Def gz_0ab880:1; deklariert 1x4
int f_0abbc0(int, int, int, int, int);       // sicher; GLEICH-Def lang_cze:5; deklariert 5x1
int f_0abc00(int, int, int, int);            // sicher; GLEICH-Def lang_cze:4; deklariert 4x1
int f_0abc30(int, int, int, int);            // sicher; GLEICH-Def lang_cze:4; deklariert 4x1
int f_0abc60(int, int, int, int, int, int);  // sicher; GLEICH-Def lang_cze:6; deklariert 6x1
int f_0abda0(int, int, int, int, int);       // sicher; GLEICH-Def lang_cze:5; deklariert 5x1
int f_0abf10(int, int, int, int, int, int, int); // sicher; GLEICH-Def gz_0abf10:7; deklariert 7x1
int f_0ac800(int, int, int);                 // sicher; GLEICH-Def lang_dan:3; deklariert 3x1
int f_0ac970(int, int);                      // sicher; GLEICH-Def lang_dan:2; deklariert 2x1
int f_0ac9e0(int, int, int, int, int, int);  // sicher; GLEICH-Def lang_dan:6; deklariert 6x1
int f_0acac0(int, int, int, int, int, int, int); // sicher; GLEICH-Def gz_0acac0:7; deklariert 7x1
int f_0accd0(int, int, int, int, int, int);  // sicher; GLEICH-Def lang_fin:6; deklariert 6x1
int f_0acd00(int, int, int, int, int);       // sicher; GLEICH-Def lang_fin:5; deklariert 5x1
int f_0ad660(int, int);                      // sicher; GLEICH-Def lang_fin:2; deklariert 2x1
int f_0add30(int, int, int, int, int, int, int); // sicher; GLEICH-Def gz_0add30:7; deklariert 7x1
int f_0adf10(int, int, int, int, int);       // sicher; GLEICH-Def lang_nor:5; deklariert 5x1
int f_0ae640(int, int, int, int, int, int);  // sicher; GLEICH-Def lang_nor:6; deklariert 6x1
int f_0aeff0(int, int, int, int, int, int);  // sicher; GLEICH-Def lang_spa:6; deklariert 6x1
int f_0af1e0(int, int, int, int, int, int, int); // sicher; GLEICH-Def gz_0af1e0:7; deklariert 7x1
int f_0af8b0(int, int, int, int);            // sicher; GLEICH-Def lang_swe:4; deklariert 4x1
int f_0af8e0(int, int, int, int);            // sicher; GLEICH-Def lang_swe:4; deklariert 4x1
int f_0af910(int, int, int, int, int, int);  // sicher; GLEICH-Def lang_swe:6; deklariert 6x1
int f_0afa70(int, int, int, int, int, int, int); // sicher; GLEICH-Def lang_swe:7; deklariert 7x1
int f_0afe80(int, int, int);                 // sicher; GLEICH-Def lang_swe:3; deklariert 3x1
int f_0b0460(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x9
int f_0b04d0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0b04e0(int);                           // sicher; liest eax; deklariert 1x3
int f_0b04f0(int);                           // sicher; GLEICH-Def gz_0b0410:1; deklariert 1x1
int f_0b0530(int);                           // sicher; liest eax; deklariert 1x2
int f_0b0790(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0b0800(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0b09b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0b0a00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_0b0af0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_0b0c30(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0b0e20(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0b0e60(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0b0f40(int);                           // sicher; liest eax; deklariert 1x3
int f_0b0fc0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0b1090(int);                           // sicher; liest eax; deklariert 1x1
int f_0b1140(int);                           // sicher; liest eax; deklariert 1x1
int f_0b11d0(int);                           // sicher; GLEICH-Def gz_0b1130:1; deklariert 1x1
int f_0b13d0(int);                           // sicher; liest eax; deklariert 1x6
int f_0b14e0(int);                           // sicher; GLEICH-Def gz_0b1130:1; deklariert 1x1
int f_0b1510(int);                           // sicher; GLEICH-Def gz_0b1130:1; deklariert 1x1
int f_0b2640(int);                           // sicher; GLEICH-Def gz_0b2640:1; deklariert 0x1 1x1
int f_0b2900(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0b2cc0(int);                           // sicher; GLEICH-Def gz_0b2640:1; deklariert 1x2
int f_0b33d0(int);                           // sicher; liest eax; deklariert -
int f_0b3560(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0b3640(int);                           // sicher; liest eax; deklariert 1x1
int f_0b37d0(int);                           // sicher; liest eax; deklariert -
int f_0b3950(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0b6f30(int);                           // sicher; GLEICH-Def gz_0b5dc0_t1:1; deklariert 0x1 1x1
int f_0b7c60(int);                           // sicher; GLEICH-Def gz_0b5dc0_t1:1; deklariert 1x1
int f_0b7c90(int);                           // sicher; GLEICH-Def gz_0b5dc0_t1:1; deklariert 1x1
int f_0b7d60(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0b8490(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_0b8520(int);                           // sicher; liest eax; deklariert 1x5 2x7
int f_0b8530(int);                           // sicher; liest eax; deklariert 2x1
int f_0b8a00(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0b8a10(int);                           // sicher; liest eax; deklariert 1x2
int f_0b8a20(int, int);                      // sicher; GLEICH-Def location:2; deklariert 2x1
int f_0b8a40(int);                           // sicher; liest eax; deklariert 1x2
int f_0b8b20(int);                           // sicher; GLEICH-Def location:1; deklariert 1x2
int f_0b8b70(int);                           // sicher; liest eax; deklariert 1x2
int f_0b8cc0(int);                           // sicher; GLEICH-Def location:1; deklariert 1x2
int f_0b8d40(int);                           // sicher; liest eax; deklariert 1x3
int f_0b8ef0(int);                           // sicher; liest eax; deklariert 1x2
int f_0b8f70(int);                           // sicher; liest eax; deklariert 1x2
int f_0b9060(int);                           // sicher; liest eax; deklariert 1x9
int f_0b90a0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0b9890(int);                           // sicher; liest eax; deklariert 1x2
int f_0b9940(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0b9950(int, int);                      // sicher; GLEICH-Def gz_0b9940:2; deklariert 2x1
int f_0b9ec0(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0b9f40(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0b9ff0(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0ba0b0(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0ba0d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0ba160(int, int);                      // sicher; liest eax; GLEICH-Def gz_0b9940:2; deklariert 2x3
int f_0ba180(int);                           // sicher; liest eax; deklariert 1x3
int f_0ba300(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0ba4c0(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x2
int f_0ba4e0(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x2
int f_0ba530(int);                           // sicher; liest eax; deklariert 1x2
int f_0ba640(int);                           // sicher; liest eax; deklariert 1x2
int f_0ba9c0(int);                           // sicher; liest eax; deklariert 1x2
int f_0bab50(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0babc0(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0bac00(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0bac10(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0bac30(int);                           // sicher; GLEICH-Def gz_0b9940:1; deklariert 1x1
int f_0bac50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0bad80(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0badf0(int);                           // sicher; liest eax; deklariert 2x2
int f_0baf80(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0bb020(int);                           // sicher; liest eax; deklariert 1x2
int f_0bb2e0(int, int);                      // sicher; GLEICH-Def marketha:2; deklariert 2x2
int f_0bb640(int);                           // sicher; liest eax; deklariert 1x2
int f_0bb900(int, int);                      // sicher; GLEICH-Def gz_0bb900:2; deklariert 2x1
int f_0bba60(int);                           // sicher; GLEICH-Def gz_0bb900:1; deklariert 1x1
int f_0bbe10(int, int, int);                 // sicher; liest edx ebx; deklariert 3x3
int f_0bbe40(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0bbf00(int);                           // sicher; liest eax; deklariert 1x40
int f_0bc060(int);                           // sicher; liest eax; deklariert 1x6
int f_0bc1e0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0bc6c0(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_0bc8d0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0bcae0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 2x1 4x5
int f_0bcd30(int, int, int);                 // sicher; liest edx ebx; deklariert 3x4
int f_0bcfc0(int);                           // sicher; liest eax; deklariert 1x2
int f_0bd170(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_0bd2e0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0bd350(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_0bd360(int);                           // sicher; liest eax; deklariert 1x6
int f_0bd3e0(int);                           // sicher; GLEICH-Def gz_0bd2e0:1; deklariert 1x2
int f_0bd490(int, int);                      // sicher; GLEICH-Def gz_0bd2e0:2; deklariert 2x1
int f_0bd4d0(int);                           // sicher; GLEICH-Def gz_0bd2e0:1; deklariert 1x1
int f_0bd510(int, int, int, int);            // sicher; GLEICH-Def gz_0bd2e0:4; deklariert 4x1
int f_0bd540(int);                           // sicher; GLEICH-Def gz_0bd2e0:1; deklariert 1x2
int f_0bd5a0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0bd780(int, int);                      // sicher; liest eax edx; deklariert 4x1
int f_0bd900(int);                           // sicher; liest eax; deklariert 1x1
int f_0bd910(int, int, int, int, int, int);  // vermutet (sicher 3); liest eax edx ebx; ret 8?; deklariert 6x2
int f_0bda30(int);                           // sicher; liest eax; deklariert 1x1
int f_0bda70(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0bdb00(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0bdbc0(int);                           // sicher; liest eax; deklariert 1x3
int f_0bdbf0(int);                           // sicher; liest eax; deklariert 1x3
int f_0bdc20(int);                           // sicher; liest eax; deklariert 1x2
int f_0bdc30(int);                           // sicher; liest eax; deklariert 1x2
int f_0bdc40(int);                           // sicher; GLEICH-Def memory:1; deklariert 1x2
int f_0bdcb0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0bdde0(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x1 4x3
int f_0bde40(int);                           // sicher; GLEICH-Def gz_0bde40:1; deklariert 0x9 1x20
int f_0bde50(int);                           // sicher; GLEICH-Def gz_0bde40:1; deklariert 1x1
int f_0bdf20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0be0f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0be200(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x3
int f_0be2b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0be4f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_0bec40(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_0beff0(int);                           // sicher; liest eax; deklariert 1x2
int f_0bf1b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0bf480(int);                           // sicher; liest eax; deklariert 1x3
int f_0bf580(int);                           // sicher; liest eax; deklariert 1x2
int f_0bf650(int);                           // sicher; GLEICH-Def gz_0beff0:1; deklariert 1x1
int f_0bf680(int);                           // sicher; liest eax; deklariert 1x56 2x15
int f_0bf6c0(int, int);                      // sicher; liest eax edx; deklariert 2x69
int f_0bf6f0(int, int);                      // sicher; liest eax edx; deklariert 2x120 3x1
int f_0bf730(int, int);                      // sicher; liest eax edx; deklariert 2x203 3x1
int f_0bf7b0(int, int, int, int, int, int);  // sicher; liest eax edx ecx; ret 8?; GLEICH-Def gz_0beff0:6; deklariert 6x30
int f_0bf820(int, ...);                      // sicher; varargs (Fable N); deklariert 0x46 1x4 2x57 3x4 4x4 5x1 6x2
int f_0bf980(int, ...);                      // sicher; varargs (Fable N); deklariert 0x8 1x1 2x11 5x2 6x1
int f_0bfa20(int, ...);                      // sicher; varargs (Fable N); deklariert 0x21 2x24 5x2 6x2 8x1
int f_0bfac0(int);                           // sicher; liest eax; deklariert 1x2
int f_0bfae0(int);                           // sicher; liest eax; deklariert 1x2
int f_0bfaf0(int);                           // sicher; liest eax; deklariert 1x3
int f_0bfc50(int);                           // sicher; liest eax; deklariert 1x3
int f_0bfd40(int);                           // sicher; liest eax; deklariert 1x3
int f_0bfd80(int);                           // sicher; liest eax; deklariert 1x3
int f_0bfea0(int, int, int);                 // sicher; liest eax edx; GLEICH-Def menuovl:3; deklariert 3x17
int f_0bff00(int);                           // sicher; liest eax; deklariert 1x2
int f_0bff80(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0bffd0(int);                           // sicher; GLEICH-Def gz_0bff80:1; deklariert 1x1
int f_0bffe0(int);                           // sicher; GLEICH-Def gz_0bff80:1; deklariert 1x1
int f_0bfff0(int);                           // sicher; GLEICH-Def gz_0bff80:1; deklariert 1x1
int f_0c0000(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0c0010(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0c0020(int, int);                      // sicher; liest eax edx; deklariert 2x25
int f_0c0030(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0c04b0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_0c0550(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0c07d0(int);                           // sicher; GLEICH-Def gz_0bff80:1; deklariert 1x1
int f_0c0c80(int);                           // sicher; liest eax; deklariert 1x2
int f_0c2f00(int);                           // sicher; GLEICH-Def mine1_t1:1; deklariert 1x3
int f_0c2f40(int);                           // sicher; liest eax; deklariert 1x2
int f_0c3350(int);                           // sicher; GLEICH-Def mine1_t2:1; deklariert 1x1
int f_0c3d70(int);                           // sicher; GLEICH-Def mine1_t2:1; deklariert 1x1
int f_0c47c0(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4870(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4940(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4a00(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4ae0(int);                           // sicher; liest eax; deklariert 1x2
int f_0c4cc0(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4d80(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4e40(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c4f20(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c5060(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c5120(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c5200(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c52c0(int);                           // sicher; GLEICH-Def mine1_t3:1; deklariert 1x1
int f_0c55d0(int);                           // sicher; liest eax; deklariert 1x2
int f_0c5830(int);                           // sicher; liest eax; deklariert 1x2
int f_0c5920(int);                           // sicher; GLEICH-Def mine1_t4:1; deklariert 1x1
int f_0c5ac0(int);                           // sicher; GLEICH-Def mine1_t4:1; deklariert 0x1 1x2
int f_0c5b70(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0c5e20(int, int);                      // sicher; GLEICH-Def gz_0c5d80:2; deklariert 2x1
int f_0c5e30(int, int);                      // sicher; GLEICH-Def gz_0c5d80:2; deklariert 2x1
int f_0c6de0(int);                           // sicher; liest eax; deklariert 1x2
int f_0c7180(int);                           // sicher; liest eax; deklariert 1x2
int f_0c7300(int);                           // sicher; liest eax; deklariert 1x2
int f_0c74e0(int);                           // sicher; GLEICH-Def mine2_t1:1; deklariert 1x2
int f_0c7520(int);                           // sicher; GLEICH-Def mine2_t1:1; deklariert 1x2
int f_0c7660(int);                           // sicher; liest eax; deklariert 1x2
int f_0c7b50(int);                           // sicher; GLEICH-Def mine2_t2:1; deklariert 0x1 1x3
int f_0c7c20(int);                           // sicher; liest eax; deklariert 1x2
int f_0c7fb0(int);                           // sicher; GLEICH-Def mine2_t2:1; deklariert 1x2
int f_0c8410(int);                           // sicher; liest eax; deklariert 1x2
int f_0c8540(int);                           // sicher; GLEICH-Def mine2_t2:1; deklariert 1x3
int f_0c8c40(int);                           // sicher; liest eax; deklariert 1x1
int f_0c8d50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0c8e40(int);                           // sicher; liest eax; deklariert 1x2
int f_0c91b0(int);                           // sicher; GLEICH-Def mine2_t3:1; deklariert 1x3
int f_0c9290(int);                           // sicher; GLEICH-Def mine2_t3:1; deklariert 1x3
int f_0c9790(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0c99b0(int, int);                      // sicher; GLEICH-Def gz_0c9940_t1:2; deklariert 2x1
int f_0c99c0(int, int);                      // sicher; GLEICH-Def gz_0c9940_t1:2; deklariert 2x1
int f_0c9eb0(int, int);                      // sicher; GLEICH-Def gz_0c9940_t1:2; deklariert 2x1
int f_0ca770(int);                           // sicher; GLEICH-Def gz_0c9940_t1:1; deklariert 1x1
int f_0ca7c0(int);                           // sicher; liest eax; deklariert 1x3
int f_0cad50(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cad60(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cada0(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cadb0(int, int);                      // sicher; GLEICH-Def gz_0c9940_t2:2; deklariert 2x1
int f_0cb250(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cb290(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cb2a0(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cb2f0(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cb340(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cb360(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cb410(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0cb760(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cbb10(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cbb40(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 2x3
int f_0cbd50(int);                           // sicher; GLEICH-Def gz_0c9940_t2:1; deklariert 1x1
int f_0cc010(int, int);                      // sicher; liest edx; deklariert 2x1 3x2
int f_0cc7a0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0cc8c0(int);                           // sicher; liest eax; deklariert 1x2
int f_0ccb50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0cd000(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0cd990(int);                           // sicher; GLEICH-Def gz_0cd990:1; deklariert 1x1
int f_0cd9e0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0cda00(int, int);                      // sicher; GLEICH-Def gz_0cd990:2; deklariert 2x1
int f_0cdd30(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0cdd50(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x9
int f_0ce070(int);                           // sicher; liest eax; deklariert 1x5 2x1
int f_0ce0f0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x3 2x1
int f_0ce120(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0ce280(int);                           // sicher; GLEICH-Def misc_b:1; deklariert 1x4
int f_0ce2b0(int);                           // sicher; liest eax; deklariert 1x4
int f_0ce2f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0ce3e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0ce4f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0ce590(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0ce710(int);                           // sicher; liest eax; deklariert 1x6 4x1
int f_0ce7c0(int);                           // sicher; liest eax; deklariert 1x39 2x1
int f_0ce7e0(int);                           // sicher; liest eax; deklariert 1x5 2x31
int f_0ce980(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0ce9d0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0ce9f0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0ceaa0(int);                           // sicher; GLEICH-Def mo_spell:1; deklariert 1x1
int f_0cead0(int);                           // sicher; GLEICH-Def mo_spell:1; deklariert 1x1
int f_0ceb00(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0cf910(int);                           // sicher; liest eax; deklariert 1x12
int f_0cf920(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0cf930(int);                           // sicher; liest eax; deklariert 1x6
int f_0cf940(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cf950(int);                           // sicher; liest eax; deklariert 1x9
int f_0cf960(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cf970(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 2x5
int f_0cf990(int);                           // sicher; liest eax; deklariert 1x4
int f_0cf9a0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cf9b0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0cf9d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_0cf9f0(int);                           // sicher; liest eax; deklariert 1x9
int f_0cfa00(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfa10(int);                           // sicher; liest eax; deklariert 1x14
int f_0cfa20(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0cfa30(int);                           // sicher; liest eax; deklariert 1x6
int f_0cfa40(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfa50(int);                           // sicher; liest eax; deklariert 1x13
int f_0cfa60(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0cfa70(int);                           // sicher; liest eax; deklariert 1x6
int f_0cfa80(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfa90(int);                           // sicher; liest eax; deklariert 1x4
int f_0cfaa0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfab0(int);                           // sicher; liest eax; deklariert 1x5
int f_0cfac0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cfad0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfae0(int);                           // sicher; liest eax; deklariert 2x5
int f_0cfb00(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfb10(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 2x5
int f_0cfb30(int);                           // sicher; liest eax; deklariert 1x3
int f_0cfb40(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfb50(int);                           // sicher; liest eax; deklariert 1x3
int f_0cfb60(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfb70(int);                           // sicher; liest eax; deklariert 1x3
int f_0cfb80(int, int);                      // sicher; GLEICH-Def gz_0ced30:2; deklariert 2x2
int f_0cfb90(int);                           // sicher; liest eax; deklariert 2x2
int f_0cfbb0(int);                           // sicher; liest eax; deklariert 1x4
int f_0cfbc0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cfbd0(int);                           // sicher; liest eax; deklariert 1x5
int f_0cfbe0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0cfbf0(int);                           // sicher; liest eax; deklariert -
int f_0cfc10(int);                           // sicher; liest eax; deklariert 1x7
int f_0cfc20(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfc30(int);                           // sicher; liest eax; deklariert 1x3
int f_0cfc40(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfc50(int);                           // sicher; liest eax; deklariert 1x17 2x1
int f_0cfc60(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0cfc70(int);                           // sicher; liest eax; deklariert 1x16
int f_0cfc80(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_0cfc90(int);                           // sicher; liest eax; deklariert 1x4
int f_0cfca0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cfcb0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0cfcc0(int);                           // sicher; liest eax; deklariert 1x7
int f_0cfcd0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0cfce0(int);                           // sicher; liest eax; deklariert 1x8
int f_0cfcf0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0cfd00(int);                           // sicher; liest eax; deklariert 1x7
int f_0cfd10(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0cfd20(int);                           // sicher; liest eax; deklariert 1x5
int f_0cfd30(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0cfd40(int);                           // sicher; liest eax; deklariert 1x9
int f_0cfd70(int);                           // sicher; liest eax; deklariert 1x9
int f_0cfd80(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0cfd90(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0cfda0(int);                           // sicher; liest eax; deklariert 1x4
int f_0cfdb0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0cfdc0(int);                           // sicher; liest eax; deklariert 1x16
int f_0cfdd0(int, int);                      // sicher; liest eax edx; deklariert 2x11
int f_0cfdf0(int);                           // sicher; liest eax; deklariert 1x6
int f_0cfe00(int, int);                      // sicher; liest eax edx; deklariert 2x6 3x2
int f_0cfe30(int);                           // sicher; liest eax; deklariert 1x12
int f_0cfe40(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cfe60(int);                           // sicher; liest eax; deklariert 1x4
int f_0cfec0(int);                           // sicher; liest eax; deklariert 1x7
int f_0cfed0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cfef0(int);                           // sicher; liest eax; deklariert 1x8
int f_0cff00(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cff20(int);                           // sicher; liest eax; deklariert 1x3
int f_0cff50(int);                           // sicher; liest eax; deklariert 1x8
int f_0cff60(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0cff80(int);                           // sicher; liest eax; deklariert 1x10
int f_0cff90(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_0cffb0(int);                           // sicher; liest eax; deklariert 1x7
int f_0cffc0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0cffe0(int);                           // sicher; liest eax; deklariert 1x5
int f_0cfff0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0d0010(int);                           // sicher; liest eax; deklariert 1x3
int f_0d0020(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d0040(int);                           // sicher; liest eax; deklariert 1x1
int f_0d0070(int);                           // sicher; GLEICH-Def gz_0ced30:1; deklariert 1x2
int f_0d0080(int);                           // sicher; liest eax; deklariert 1x3
int f_0d0090(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d00a0(int);                           // sicher; liest eax; deklariert 1x8
int f_0d00b0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0d00c0(int);                           // sicher; liest eax; deklariert 1x7
int f_0d00d0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d00e0(int);                           // sicher; liest eax; deklariert 1x7
int f_0d00f0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0d0100(int);                           // sicher; liest eax; deklariert 1x6
int f_0d0110(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d0120(int);                           // sicher; liest eax; deklariert 1x7
int f_0d0130(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0d0140(int);                           // sicher; liest eax; deklariert 1x6
int f_0d0150(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d0160(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 1x5
int f_0d0170(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0d0180(int);                           // sicher; liest eax; deklariert 1x4
int f_0d0190(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d01a0(int);                           // sicher; liest eax; deklariert 1x7
int f_0d01b0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0d01c0(int);                           // sicher; liest eax; deklariert 1x4
int f_0d01d0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d01e0(int);                           // sicher; liest eax; deklariert 1x4
int f_0d01f0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d0230(int, int);                      // sicher; liest eax edx; deklariert 1x1
int f_0d0260(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d0350(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0d03f0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d0400(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0d0440(int);                           // sicher; liest eax; deklariert 1x5
int f_0d0460(int);                           // sicher; liest eax; deklariert 1x2
int f_0d0480(int);                           // sicher; liest eax; deklariert 1x2
int f_0d04a0(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d04c0(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d04e0(int);                           // sicher; liest eax; deklariert 1x3
int f_0d0500(int);                           // sicher; liest eax; deklariert 1x2
int f_0d0520(int);                           // sicher; liest eax; deklariert 1x2
int f_0d0550(int);                           // sicher; liest eax; deklariert 1x1
int f_0d0570(int);                           // sicher; liest eax; deklariert 1x1
int f_0d0590(int);                           // sicher; liest eax; deklariert 1x1
int f_0d05b0(int);                           // sicher; liest eax; deklariert 1x1
int f_0d05d0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d05f0(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d0610(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d0640(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d0660(int);                           // sicher; liest eax; deklariert 1x1
int f_0d0680(int);                           // sicher; liest eax; deklariert 1x4
int f_0d06a0(int);                           // sicher; liest eax; deklariert 1x1
int f_0d06c0(int);                           // sicher; liest eax; deklariert 1x13
int f_0d06f0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d0710(int);                           // sicher; liest eax; deklariert 1x3
int f_0d0730(int);                           // sicher; liest eax; deklariert 1x2
int f_0d0760(int);                           // sicher; liest eax; deklariert 1x4
int f_0d0790(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d07b0(int);                           // sicher; liest eax; deklariert 1x1
int f_0d07e0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0d08a0(int);                           // sicher; liest eax; deklariert 1x9
int f_0d08e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0d0910(int);                           // sicher; liest eax; deklariert 1x8
int f_0d0940(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0d0960(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_0d0a20(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0d0a60(int, int);                      // sicher; liest eax edx; deklariert 2x3 4x1
int f_0d0ac0(int);                           // sicher; liest eax; deklariert 1x2 2x1
int f_0d0b70(int);                           // sicher; GLEICH-Def gz_0d0350:1; deklariert 1x1
int f_0d0bb0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_0d0df0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0d0f90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_0d10c0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0d11e0(int);                           // sicher; liest eax; deklariert 1x11
int f_0d1250(int);                           // sicher; liest eax; deklariert 1x7
int f_0d12e0(int);                           // sicher; liest eax; deklariert 1x3
int f_0d1320(int, int, int);                 // sicher; liest ebx; deklariert 1x3
int f_0d1360(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0d1390(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0d13b0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0d1440(int);                           // sicher; liest eax; deklariert 1x3
int f_0d16a0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d18a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d1a90(int);                           // sicher; liest eax; deklariert 1x2
int f_0d1b20(int);                           // sicher; liest eax; deklariert 1x3
int f_0d1b60(int);                           // sicher; liest eax; deklariert 1x2
int f_0d1cd0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d1eb0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d2050(int, int);                      // sicher; liest eax edx; deklariert 1x2
int f_0d2130(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0d2440(int);                           // sicher; liest eax; deklariert 1x2
int f_0d2f40(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0d2f90(int, int);                      // sicher; liest eax edx; deklariert 2x42
int f_0d3080(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 0x1 6x2
int f_0d3390(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_0d33d0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d3420(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x7
int f_0d34b0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_0d34f0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d3530(int);                           // sicher; liest eax; deklariert 1x7
int f_0d3570(int);                           // sicher; liest eax; deklariert 1x2
int f_0d35b0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d3680(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d38b0(int);                           // sicher; liest eax; deklariert 1x4 4x1
int f_0d38d0(int);                           // sicher; liest eax; deklariert 1x5
int f_0d3950(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x7
int f_0d39d0(int, int);                      // sicher; liest eax edx; deklariert -
int f_0d3a10(int);                           // sicher; liest eax; deklariert 1x1
int f_0d3a30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d3b44(int, int);                      // sicher; liest eax edx; deklariert -
int f_0d3c75(int, int);                      // sicher; liest eax edx; deklariert -
int f_0d3df6(int);                           // sicher; liest eax; deklariert 1x1 3x1
int f_0d3f25(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_0d4070(int);                           // sicher; liest eax; deklariert 1x13
int f_0d40b6(int);                           // sicher; liest eax; deklariert 1x9
int f_0d4163(int);                           // sicher; liest eax; deklariert 1x3 2x1
int f_0d4248(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d4324(int, int);                      // sicher; liest eax edx; deklariert -
int f_0d435b(int);                           // sicher; liest eax; deklariert -
int f_0d448c(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_0d451f(int, int, int);                 // sicher; liest eax edx ebx; deklariert 1x1 3x3
int f_0d4730(int);                           // sicher; liest eax; deklariert 1x3
int f_0d4800(int);                           // sicher; liest eax; deklariert 1x18
int f_0d4850(int, int);                      // sicher; liest eax edx; deklariert 3x3
int f_0d48a0(int);                           // sicher; liest eax; deklariert 1x4
int f_0d49b0(int);                           // sicher; liest eax; deklariert 1x28
int f_0d4a10(int);                           // sicher; liest eax; deklariert 1x9
int f_0d4a60(int);                           // sicher; liest eax; deklariert 0x1 1x80
int f_0d4aa0(int, int);                      // sicher; liest eax edx; deklariert 2x48
int f_0d4ad0(int);                           // sicher; liest eax; deklariert 1x13
int f_0d4b00(int);                           // sicher; liest eax; deklariert 1x14
int f_0d4b30(int);                           // sicher; liest eax; deklariert 1x3
int f_0d4b60(int);                           // sicher; liest eax; deklariert 1x3
int f_0d4b90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0d4c80(int);                           // sicher; liest eax; deklariert 1x22 4x11
int f_0d4cd0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0d5040(int, int, int, int, int, int);  // sicher; GLEICH-Def no_ovl:6; deklariert 0x10 6x23
int f_0d5290(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0d54c0(int);                           // sicher; liest eax; deklariert 1x29
int f_0d54f0(int, int);                      // sicher; liest eax edx; deklariert 2x51
int f_0d5550(int);                           // sicher; liest eax; deklariert 1x5
int f_0d56c0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d5b50(int);                           // sicher; liest eax; deklariert 1x12 2x1
int f_0d65c0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d6690(int);                           // sicher; liest eax; deklariert 1x6
int f_0d66f0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d6700(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d6710(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_0d6ab0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_0d6b90(int);                           // sicher; liest eax; deklariert 1x2
int f_0d6ba0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d6bb0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d6bc0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0d6bd0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d6ce0(int);                           // sicher; liest eax; deklariert 1x2
int f_0d6e10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d7830(int);                           // sicher; GLEICH-Def options_t1:1; deklariert 1x1
int f_0d78a0(int);                           // sicher; GLEICH-Def options_t1:1; deklariert 1x3
int f_0d78b0(int, int);                      // sicher; GLEICH-Def options_t1:2; deklariert 1x1 2x2
int f_0d78c0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0d7a20(int);                           // sicher; liest eax; deklariert 1x1
int f_0d7ce0(int);                           // sicher; liest eax; deklariert 1x1
int f_0d8090(int);                           // sicher; liest eax; deklariert 1x1
int f_0d82f0(int, int);                      // sicher; liest eax edx; deklariert 1x1
int f_0d8520(int);                           // sicher; liest eax; deklariert 1x2
int f_0d87e0(int);                           // sicher; liest eax; deklariert 1x1
int f_0d8950(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d8c00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d8d20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d9190(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0d9670(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0d9740(int);                           // sicher; GLEICH-Def options_t2:1; deklariert 1x1
int f_0d98c0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_0d99d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_0d9b20(int);                           // sicher; liest eax; deklariert 1x3
int f_0d9d20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0d9ea0(int, int, int, int, int, int);  // vermutet (sicher 4); liest edx ebx ecx; ret 8?; deklariert 6x2
int f_0d9fe0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0da250(int, int, int, int, int, int);  // vermutet (sicher 4); liest edx ebx ecx; ret 8?; deklariert 6x2
int f_0da460(int, int, int, int);            // sicher; liest eax ecx; deklariert 4x2
int f_0da5c0(int, int);                      // sicher; GLEICH-Def gz_0da510:2; deklariert 2x1
int f_0da7b0(int, int, int);                 // sicher; GLEICH-Def gz_0da510:3; deklariert 3x1
int f_0da7f0(int, int);                      // sicher; GLEICH-Def gz_0da510:2; deklariert 2x1
int f_0da840(int);                           // sicher; GLEICH-Def gz_0da510:1; deklariert 1x1
int f_0da8a0(int, int);                      // sicher; GLEICH-Def gz_0da510:2; deklariert 2x1
int f_0da990(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x6 2x3
int f_0da9a0(int, int, int);                 // sicher; liest eax ebx; deklariert 1x1
int f_0daa90(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_0daaf0(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_0dab50(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0daba0(int, int);                      // sicher; liest eax edx; deklariert 2x13
int f_0dac90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 2x2 3x1
int f_0dacc0(int);                           // sicher; liest eax; deklariert 1x12
int f_0dade0(int);                           // sicher; liest eax; deklariert 1x1
int f_0db020(int);                           // sicher; liest eax; deklariert 1x2
int f_0db0c0(int);                           // sicher; liest eax; deklariert 1x1
int f_0db2f0(int);                           // sicher; liest eax; deklariert 1x2
int f_0db3b0(int, int);                      // sicher; GLEICH-Def panel:2; deklariert 2x1
int f_0db3d0(int);                           // sicher; liest eax; deklariert 1x4
int f_0db4a0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0db6b0(int, int);                      // sicher; GLEICH-Def panel:2; deklariert 2x1
int f_0db7b0(int);                           // sicher; GLEICH-Def gz_0db7b0:1; deklariert 1x1
int f_0db7f0(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0db820(int, int);                      // sicher; liest eax edx; deklariert 2x31
int f_0db8b0(int, int);                      // sicher; liest eax edx; deklariert 2x30
int f_0db900(int);                           // sicher; liest eax; deklariert 1x2
int f_0db910(int);                           // sicher; GLEICH-Def gz_0db7b0:1; deklariert 1x1
int f_0db940(int);                           // sicher; liest eax; deklariert 1x11
int f_0db970(int);                           // sicher; liest eax; deklariert 1x17
int f_0db9a0(int);                           // sicher; liest eax; deklariert 1x60
int f_0db9d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x9
int f_0dba10(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_0dba60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0dbad0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_0dbb20(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0dbb50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_0dbc10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_0dbc80(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0dbcb0(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0dbce0(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0dbd10(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0dbd40(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0dbd70(int, int);                      // sicher; GLEICH-Def gz_0db7b0:2; deklariert 2x1
int f_0dbda0(int);                           // sicher; liest eax; deklariert 1x7
int f_0dbde0(int, int, int);                 // sicher; GLEICH-Def gz_0db7b0:3; deklariert 3x1
int f_0dbe20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_0dbe80(int);                           // sicher; GLEICH-Def gz_0db7b0:1; deklariert 1x1
int f_0dbeb0(int);                           // sicher; liest eax; deklariert 1x12
int f_0dbee0(int);                           // sicher; GLEICH-Def gz_0db7b0:1; deklariert 1x1
int f_0dbf10(int);                           // sicher; liest eax; deklariert 1x3
int f_0dbfb0(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0dbff0(int);                           // sicher; liest eax; deklariert 1x7
int f_0dc020(int, int);                      // sicher; liest eax edx; deklariert 2x35
int f_0dc050(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x10
int f_0dc110(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_0dc1f0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_0dc2d0(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_0dc3c0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x6
int f_0dc430(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0dc4d0(int);                           // sicher; liest eax; deklariert 1x2
int f_0dc650(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0dc9a0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_0dca30(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0dcae0(int);                           // sicher; liest eax; deklariert 1x13
int f_0dcb60(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0dcbb0(int, int);                      // sicher; liest eax edx; deklariert 2x42
int f_0dcc10(int);                           // sicher; liest eax; deklariert 1x17
int f_0dcc40(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x18
int f_0dcd30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_0dcdf0(int, int);                      // sicher; liest eax edx; deklariert 2x14
int f_0dce50(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0dcf00(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x52
int f_0dd100(int, int);                      // sicher; liest eax edx; deklariert 2x17
int f_0dd1d0(int, int);                      // sicher; liest eax edx; deklariert 2x20
int f_0dd220(int);                           // sicher; liest eax; deklariert 1x2
int f_0dd2f0(int);                           // sicher; liest eax; deklariert 1x2
int f_0dd3a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x12
int f_0dd410(int, int);                      // sicher; liest edx; deklariert 2x14
int f_0dd440(int);                           // sicher; liest eax; deklariert 1x10
int f_0dd480(int);                           // sicher; liest eax; deklariert 1x4
int f_0dd4a0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0dd4f0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0dd520(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0dd640(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0dd680(int, int, int, int);            // sicher; GLEICH-Def gz_0dc9a0_t1:4; deklariert 4x1
int f_0dd6d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_0dd750(int, int);                      // sicher; liest eax edx; deklariert 2x32
int f_0dd7f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x71
int f_0ddc70(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0ddcf0(int);                           // sicher; liest eax; deklariert 1x2
int f_0ddd60(int);                           // sicher; liest eax; deklariert 1x3
int f_0ddeb0(int);                           // sicher; liest eax; deklariert 1x2
int f_0ddf50(int);                           // sicher; liest eax; deklariert 1x3
int f_0ddfc0(int);                           // sicher; liest eax; deklariert 1x4
int f_0de020(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0de070(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0de0d0(int);                           // sicher; liest eax; deklariert 1x10
int f_0de120(int);                           // sicher; liest eax; deklariert 1x1
int f_0de170(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0de1c0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_0de210(int);                           // sicher; liest eax; deklariert 1x17 2x1
int f_0de410(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_0de480(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0de4d0(int);                           // sicher; liest eax; deklariert 1x11
int f_0de540(int);                           // sicher; liest eax; deklariert 1x2
int f_0de570(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0de5a0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0de5d0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0de600(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0de790(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0de7a0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0de7b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0de7c0(int);                           // sicher; liest eax; deklariert 1x28
int f_0de7d0(int, int);                      // sicher; liest eax edx; deklariert 2x39
int f_0de7e0(int);                           // sicher; liest eax; deklariert 1x27
int f_0de7f0(int);                           // sicher; liest eax; deklariert 1x33
int f_0de800(int);                           // sicher; liest eax; deklariert 1x15
int f_0de810(int, int);                      // sicher; liest eax edx; deklariert 2x29
int f_0de820(int);                           // sicher; liest eax; deklariert 1x52
int f_0de830(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_0de840(int);                           // sicher; liest eax; deklariert 1x16
int f_0de850(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_0de860(int);                           // sicher; liest eax; deklariert 1x4
int f_0de870(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0de880(int);                           // sicher; liest eax; deklariert 1x19
int f_0de890(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_0de8a0(int);                           // sicher; liest eax; deklariert 1x2
int f_0de8b0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0de8c0(int);                           // sicher; liest eax; deklariert 1x12
int f_0de8d0(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_0de8e0(int);                           // sicher; liest eax; deklariert 1x4
int f_0de8f0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0de900(int);                           // sicher; liest eax; deklariert 1x4
int f_0de910(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0de920(int);                           // sicher; liest eax; deklariert 1x2
int f_0de930(int, int);                      // sicher; liest eax edx; deklariert 2x11
int f_0de940(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0de950(int);                           // sicher; liest eax; deklariert -
int f_0de960(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0de970(int);                           // sicher; liest eax; deklariert 1x1
int f_0de980(int);                           // sicher; liest eax; deklariert 1x3
int f_0de990(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0de9a0(int);                           // sicher; liest eax; deklariert -
int f_0de9b0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0de9c0(int);                           // sicher; liest eax; deklariert 1x6
int f_0de9d0(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_0de9e0(int);                           // sicher; liest eax; deklariert 1x7
int f_0de9f0(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_0dea00(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_0dea70(int);                           // sicher; liest eax; deklariert 1x3
int f_0dec50(int);                           // sicher; liest eax; deklariert 1x2
int f_0dee80(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0df2f0(int);                           // sicher; GLEICH-Def gz_0dee80:1; deklariert 1x1
int f_0df310(int);                           // sicher; GLEICH-Def gz_0dee80:1; deklariert 1x1
int f_0df340(int);                           // sicher; GLEICH-Def gz_0dee80:1; deklariert 1x1
int f_0df490(int);                           // sicher; GLEICH-Def gz_0dee80:1; deklariert 1x1
int f_0df540(int);                           // sicher; liest eax; deklariert 1x2
int f_0df6b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0dfb20(int);                           // sicher; GLEICH-Def gz_0dee80:1; deklariert 1x1
int f_0dfb50(int, int);                      // sicher; GLEICH-Def gz_0dee80:2; deklariert 2x1
int f_0dfb70(int, int);                      // sicher; GLEICH-Def gz_0dee80:2; deklariert 2x1
int f_0dfb80(int, int);                      // sicher; GLEICH-Def gz_0dee80:2; deklariert 2x1
int f_0dfba0(int, int);                      // sicher; GLEICH-Def gz_0dee80:2; deklariert 2x1
int f_0dfbc0(int);                           // sicher; liest eax; deklariert 1x2
int f_0dfdd0(int, int);                      // sicher; liest edx; deklariert 4x1
int f_0e0120(int);                           // sicher; liest eax; deklariert -
int f_0e0250(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_0e0400(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0e04f0(int, int);                      // sicher; GLEICH-Def gz_0e04f0:2; deklariert 2x1
int f_0e0530(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0e0680(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0e07a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0e08e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0e0a30(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0e0be0(int);                           // sicher; liest eax; deklariert 1x2
int f_0e0dc0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0e1040(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0e14e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0e1600(int);                           // sicher; liest eax; deklariert 1x3
int f_0e1850(int);                           // sicher; liest eax; deklariert 1x2
int f_0e1ab0(int);                           // sicher; liest eax; deklariert 1x2
int f_0e1d10(int);                           // sicher; liest eax; deklariert 1x2
int f_0e1f80(int);                           // sicher; liest eax; deklariert 1x2
int f_0e2160(int);                           // sicher; liest eax; deklariert 1x2
int f_0e2340(int);                           // sicher; liest eax; deklariert 1x2
int f_0e2630(int, int);                      // sicher; GLEICH-Def gz_0e2520:2; deklariert 2x2
int f_0e2660(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0e26d0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_0e2700(int);                           // sicher; liest eax; deklariert 1x2
int f_0e27a0(int);                           // sicher; liest eax; deklariert 1x2
int f_0e2860(int);                           // sicher; GLEICH-Def poolinit:1; deklariert 1x1
int f_0e28a0(int);                           // sicher; liest eax; deklariert 1x2
int f_0e29b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0e2ac0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0e2b90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0e2cb0(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert 5x2
int f_0e2f70(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x3
int f_0e31c0(int, int);                      // sicher; GLEICH-Def gz_0e2ac0:2; deklariert 2x1
int f_0e31d0(int, int, int, int);            // sicher; GLEICH-Def gz_0e2ac0:4; deklariert 4x1
int f_0e3200(int, int, int, int);            // sicher; GLEICH-Def gz_0e2ac0:4; deklariert 4x1
int f_0e3290(int, int, int, int);            // sicher; GLEICH-Def gz_0e2ac0:4; deklariert 4x1
int f_0e3360(int);                           // sicher; liest eax; deklariert 1x12
int f_0e3370(int);                           // sicher; liest eax; deklariert 1x3
int f_0e3380(int);                           // sicher; liest eax; deklariert 1x3
int f_0e3390(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0e33a0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0e33b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0e33c0(int);                           // sicher; liest eax; deklariert 1x2
int f_0e3430(int);                           // sicher; liest eax; deklariert 1x7
int f_0e3580(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0e36d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_0e3970(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0e39e0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0e3ba0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x5
int f_0e4380(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_0e4640(int);                           // sicher; GLEICH-Def gz_0e4640:1; deklariert 1x1
int f_0e4650(int);                           // sicher; liest eax; deklariert 1x3
int f_0e4710(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0e4830(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_0e4a70(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_0e4c80(int, int, int);                 // sicher; GLEICH-Def gz_0e4640:3; deklariert 3x1
int f_0e4d80(int);                           // sicher; liest eax; deklariert 1x3
int f_0e74e0(int, int);                      // sicher; liest edx; deklariert 2x1
int f_0e7560(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x2
int f_0e7720(int);                           // sicher; liest eax; deklariert 1x2
int f_0e8580(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0e8810(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0e8a30(int);                           // sicher; liest eax; deklariert 1x1
int f_0e8c20(int);                           // sicher; liest eax; deklariert 1x3
int f_0e8dc0(int);                           // sicher; liest eax; deklariert 1x1
int f_0e8eb0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0e9240(int);                           // sicher; liest eax; deklariert 1x5
int f_0e92e0(int, int, int);                 // sicher; liest ebx; deklariert 3x2
int f_0e9300(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x30
int f_0e93f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x67
int f_0e9440(int, int, int);                 // sicher; GLEICH-Def gz_0e93f0:3; deklariert 3x1
int f_0e9450(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_0e9510(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x15
int f_0e9550(int, int);                      // sicher; liest eax edx; deklariert 2x19
int f_0e9590(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_0e95d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x9
int f_0e9610(int, int);                      // sicher; liest eax edx; deklariert 2x5 3x1
int f_0e9650(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 2x1 3x2
int f_0e9660(int, int, int, int);            // sicher; liest ebx ecx; deklariert 1x1 4x34
int f_0e9670(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x4
int f_0e9680(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 2x1
int f_0e96e0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0e96f0(int, int);                      // sicher; GLEICH-Def gz_0e93f0:2; deklariert 2x1
int f_0e9850(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 1x1
int f_0e9b40(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0e9d10(int);                           // sicher; liest eax; deklariert 1x2
int f_0ea210(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 0x1 1x1
int f_0ea220(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 0x1 1x1
int f_0ea230(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 0x2 1x1
int f_0ea240(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 0x2 1x1
int f_0ea250(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 0x1 1x1
int f_0ea320(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 1x1
int f_0ea340(int);                           // sicher; GLEICH-Def gz_0e93f0:1; deklariert 1x1
int f_0eba10(int);                           // sicher; liest eax; deklariert 1x3
int f_0ed890(int, int);                      // sicher; GLEICH-Def gz_0ec070_t2:2; deklariert 2x2
int f_0ed8a0(int, int);                      // sicher; GLEICH-Def gz_0ec070_t2:2; deklariert 2x1
int f_0ed8f0(int, int, int);                 // sicher; GLEICH-Def gz_0ec070_t2:3; deklariert 2x1 3x4 4x3
int f_0ed950(int, int, int);                 // sicher; GLEICH-Def gz_0ec070_t2:3; deklariert 2x2 3x1
int f_0ed980(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0ede30(int);                           // sicher; liest eax; deklariert 1x3
int f_0edef0(int, int);                      // sicher; liest eax; GLEICH-Def sacc_t1:2; deklariert 2x2
int f_0edff0(int, int, int);                 // sicher; GLEICH-Def sacc_t1:3; deklariert 3x1
int f_0ee070(int);                           // sicher; liest eax; deklariert 1x2
int f_0ee450(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0ee580(int, int);                      // sicher; liest eax; GLEICH-Def sacc_t1:2; deklariert 2x2
int f_0ee610(int);                           // sicher; GLEICH-Def sacc_t1:1; deklariert 1x1
int f_0ee650(int);                           // sicher; liest eax; deklariert 1x2
int f_0ee720(int);                           // sicher; liest eax; deklariert 1x2
int f_0eebb0(int);                           // sicher; GLEICH-Def sacc_t1:1; deklariert 1x1
int f_0eebe0(int, int, int);                 // sicher; GLEICH-Def sacc_t1:3; deklariert 3x1
int f_0eecd0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0eee30(int, int, int, int);            // sicher; GLEICH-Def sacc_t2:4; deklariert 4x1
int f_0eeea0(int, int, int, int);            // sicher; GLEICH-Def sacc_t2:4; deklariert 4x1
int f_0eeec0(int, int);                      // sicher; GLEICH-Def sacc_t2:2; deklariert 2x1
int f_0eeed0(int);                           // sicher; GLEICH-Def sacc_t2:1; deklariert 1x1
int f_0eef00(int, int, int, int, int, int);  // sicher; GLEICH-Def sacc_t2:6; deklariert 6x1
int f_0eef30(int, int, int, int, int, int);  // sicher; GLEICH-Def sacc_t2:6; deklariert 6x1
int f_0ef030(int);                           // sicher; GLEICH-Def sacc_t2:1; deklariert 1x1
int f_0ef080(int, int, int, int, int, int);  // sicher; GLEICH-Def sacc_t2:6; deklariert 6x1
int f_0ef0b0(int, int, int, int, int, int);  // sicher; GLEICH-Def sacc_t2:6; deklariert 6x1
int f_0ef1d0(int);                           // sicher; GLEICH-Def sacc_t2:1; deklariert 1x1
int f_0ef260(int, int, int, int, int, int, int, int); // sicher; GLEICH-Def sacc_t2:8; deklariert 8x1
int f_0ef2b0(int, int, int, int, int, int, int, int); // sicher; GLEICH-Def sacc_t2:8; deklariert 8x1
int f_0ef590(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0ef690(int, int);                      // sicher; GLEICH-Def sacc_t2:2; deklariert 2x1
int f_0ef720(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0f00e0(int);                           // sicher; liest eax; deklariert 1x2
int f_0f00f0(int);                           // sicher; liest eax; deklariert 1x5
int f_0f0100(int, int);                      // sicher; GLEICH-Def gz_0f00d0:2; deklariert 2x1
int f_0f0130(int);                           // sicher; liest eax; deklariert 1x5
int f_0f01b0(int);                           // sicher; liest eax; deklariert 1x2
int f_0f04c0(int);                           // sicher; liest eax; deklariert 1x3
int f_0f0790(int);                           // sicher; liest eax; deklariert 1x3
int f_0f09b0(int);                           // sicher; liest eax; deklariert 1x3
int f_0f12f0(int);                           // sicher; GLEICH-Def gz_0f12f0:1; deklariert 1x2
int f_0f1560(int);                           // sicher; liest eax; deklariert 1x5
int f_0f1570(int, int);                      // sicher; GLEICH-Def gz_0f12f0:2; deklariert 2x1
int f_0f1580(int);                           // sicher; liest eax; deklariert 1x1
int f_0f16b0(int);                           // sicher; liest eax; deklariert 2x1
int f_0f16f0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0f1730(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_0f17e0(int);                           // sicher; liest eax; deklariert -
int f_0f1e80(int);                           // sicher; liest eax; deklariert 1x1
int f_0f2080(int);                           // sicher; liest eax; deklariert 1x2
int f_0f2310(int);                           // sicher; liest eax; deklariert 1x1
int f_0f2500(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_0f25c0(int);                           // sicher; liest eax; deklariert 1x2
int f_0f2630(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0f26b0(int);                           // sicher; GLEICH-Def gz_0f25c0_t1:1; deklariert 1x1
int f_0f2c10(int);                           // sicher; liest eax; deklariert 1x2
int f_0f2c50(int);                           // sicher; GLEICH-Def gz_0f25c0_t1:1; deklariert 1x2
int f_0f2c80(int);                           // sicher; liest eax; deklariert 1x2
int f_0f2dc0(int);                           // sicher; GLEICH-Def gz_0f25c0_t1:1; deklariert 1x2
int f_0f3d80(int);                           // sicher; liest eax; deklariert 1x2
int f_0f3ff0(int);                           // sicher; GLEICH-Def gz_0f25c0_t2:1; deklariert 1x1
int f_0f4850(int);                           // sicher; liest eax; deklariert 1x2
int f_0f49b0(int);                           // sicher; GLEICH-Def gz_0f25c0_t2:1; deklariert 1x1
int f_0f4bd0(int, int);                      // sicher; GLEICH-Def gz_0f25c0_t2:2; deklariert 2x1
int f_0f4e00(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0f5450(int, int);                      // sicher; GLEICH-Def gz_0f5250_t1:2; deklariert 2x1
int f_0f5770(int);                           // sicher; GLEICH-Def gz_0f5250_t1:1; deklariert 1x2
int f_0f5d00(int);                           // sicher; GLEICH-Def gz_0f5250_t1:1; deklariert 1x1
int f_0f5d10(int);                           // sicher; GLEICH-Def gz_0f5250_t1:1; deklariert 1x1
int f_0f6550(int, int);                      // sicher; liest edx; deklariert 2x2
int f_0f6940(int, int);                      // sicher; GLEICH-Def gz_0f5250_t2:2; deklariert 2x1
int f_0f6ee0(int);                           // sicher; GLEICH-Def gz_0f5250_t2:1; deklariert 0x1 1x2
int f_0f6ef0(int);                           // sicher; GLEICH-Def gz_0f5250_t2:1; deklariert 1x1
int f_0f6f20(int);                           // sicher; GLEICH-Def gz_0f5250_t2:1; deklariert 1x1
int f_0f6f30(int);                           // sicher; GLEICH-Def gz_0f5250_t2:1; deklariert 1x1
int f_0f6f60(int);                           // sicher; GLEICH-Def gz_0f5250_t2:1; deklariert 0x1 1x1
int f_0f7120(int);                           // sicher; liest eax; deklariert 0x1 1x2
int f_0f7160(int);                           // sicher; GLEICH-Def sewerag3_t1:1; deklariert 0x1 1x1
int f_0f7180(int);                           // sicher; GLEICH-Def sewerag3_t1:1; deklariert 0x1 1x2
int f_0f71e0(int);                           // sicher; liest eax; deklariert 0x1 1x2
int f_0f7220(int);                           // sicher; GLEICH-Def sewerag3_t1:1; deklariert 1x2
int f_0f7260(int);                           // sicher; GLEICH-Def sewerag3_t1:1; deklariert 1x2
int f_0f8300(int);                           // sicher; liest eax; deklariert 1x2
int f_0f86e0(int);                           // sicher; liest eax; deklariert 1x2
int f_0f8f90(int);                           // sicher; liest eax; deklariert 1x2
int f_0f94b0(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x2
int f_0f9890(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x1
int f_0f98b0(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x1
int f_0f98d0(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x1
int f_0f98f0(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x1
int f_0f9910(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x1
int f_0f9930(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 1x1
int f_0f9a00(int);                           // sicher; liest eax; deklariert 1x2
int f_0f9dc0(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 0x1 1x1
int f_0f9e10(int, int, int);                 // sicher; liest edx ebx; deklariert 3x3
int f_0fa280(int, int);                      // sicher; liest edx; deklariert 2x4
int f_0fa340(int);                           // sicher; GLEICH-Def sewerag3_t3:1; deklariert 0x1 1x1
int f_0fa4e0(int, int);                      // sicher; GLEICH-Def sewerag3_t3:2; deklariert 2x1
int f_0fa9b0(int);                           // sicher; GLEICH-Def gz_0fa9b0:1; deklariert 1x1
int f_0faa10(int, int);                      // sicher; liest edx; deklariert 2x6
int f_0faba0(int, int);                      // sicher; GLEICH-Def gz_0fa9b0:2; deklariert 2x1
int f_0fabf0(int);                           // sicher; liest eax; deklariert 1x6
int f_0fac10(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x17
int f_0fac80(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x54
int f_0fad20(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; Destruktor-Flag; deklariert 1x11 2x87
int f_0fad50(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_0fadc0(int);                           // sicher; liest eax; deklariert 1x3 2x1
int f_0fade0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x64
int f_0fae30(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x31
int f_0faec0(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x6
int f_0faf20(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x4
int f_0fafb0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x29
int f_0fb000(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x1
int f_0fb060(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_0fb090(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 2x5
int f_0fb0b0(int);                           // sicher; liest eax; deklariert 1x55 6x1 8x1
int f_0fb0c0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_0fb120(int);                           // sicher; liest eax; deklariert 1x9 4x1
int f_0fb150(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_0fb1a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0fb210(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x11
int f_0fb220(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x1
int f_0fb3a0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x11
int f_0fb3e0(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x5
int f_0fb4d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_0fb540(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_0fb5f0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_0fb630(int);                           // sicher; liest eax; deklariert 2x3
int f_0fb660(int, int);                      // sicher; liest edx; deklariert 2x9
int f_0fbee0(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_0fc0d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_0fc5a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0fc6e0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0fca60(int);                           // sicher; liest eax; deklariert 1x8
int f_0fce00(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_0fcee0(int);                           // sicher; liest eax; deklariert 1x2
int f_0fd350(int);                           // sicher; liest eax; deklariert 1x2
int f_0fd510(int);                           // sicher; GLEICH-Def ship_t2:1; deklariert 1x1
int f_0fd540(int);                           // sicher; liest eax; deklariert 1x2
int f_0fd7c0(int);                           // sicher; GLEICH-Def ship_t2:1; deklariert 1x2
int f_0fd900(int);                           // sicher; GLEICH-Def ship_t2:1; deklariert 1x2
int f_0fdc30(int, int);                      // sicher; liest edx; deklariert 0x1 2x1
int f_0fdcb0(int, int, int);                 // sicher; GLEICH-Def gz_0fdbd0_t1:3; deklariert 3x1
int f_0fdd10(int, int, int);                 // sicher; liest eax ebx; deklariert 1x2 3x1
int f_0fdf00(int);                           // sicher; liest eax; deklariert 1x3
int f_0fe5c0(int, int);                      // sicher; liest eax edx; deklariert 1x2 2x1
int f_0fee00(int);                           // sicher; liest eax; deklariert 1x3
int f_0fef70(int);                           // sicher; GLEICH-Def gz_0fdbd0_t2:1; deklariert 1x1
int f_0fef90(int, int, int);                 // sicher; GLEICH-Def gz_0fdbd0_t2:3; deklariert 3x1
int f_0fefc0(int);                           // sicher; liest eax; deklariert 1x1
int f_0fefe0(int);                           // sicher; liest eax; deklariert 1x2
int f_0feff0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_0ff000(int, int);                      // sicher; GLEICH-Def gz_0fdbd0_t2:2; deklariert 2x1
int f_0ff020(int, int);                      // sicher; GLEICH-Def gz_0fdbd0_t2:2; deklariert 2x1
int f_0ff630(int);                           // sicher; GLEICH-Def gz_0fdbd0_t2:1; deklariert 1x2
int f_100850(int);                           // sicher; liest eax; deklariert 1x3
int f_100e30(int, int, int);                 // sicher; liest ebx; deklariert 0x2
int f_100f50(int);                           // sicher; GLEICH-Def ship1_t2:1; deklariert 1x1
int f_100fd0(int);                           // sicher; GLEICH-Def ship1_t2:1; deklariert 1x1
int f_101100(int);                           // sicher; GLEICH-Def ship1_t2:1; deklariert 1x1
int f_101110(int);                           // sicher; GLEICH-Def ship1_t2:1; deklariert 1x1
int f_101160(int);                           // sicher; GLEICH-Def ship1_t2:1; deklariert 1x1
int f_1014c0(int);                           // sicher; liest eax; deklariert 1x2
int f_101c20(int);                           // sicher; liest eax; deklariert 1x2
int f_101f60(int);                           // sicher; liest eax; deklariert 1x2
int f_1026d0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_1027e0(int);                           // sicher; liest eax; deklariert 1x3
int f_1028c0(int, int);                      // sicher; GLEICH-Def ship1_t3:2; deklariert 2x1
int f_102980(int);                           // sicher; liest eax; deklariert 1x1
int f_102a60(int);                           // sicher; liest eax; deklariert 1x2
int f_102bb0(int);                           // sicher; liest eax; deklariert 1x2
int f_102c90(int, int);                      // sicher; liest edx; deklariert 2x1
int f_102e00(int, int);                      // sicher; GLEICH-Def gz_102e00:2; deklariert 2x1
int f_1034b0(int);                           // sicher; GLEICH-Def gz_102e00:1; deklariert 1x2
int f_1034d0(int);                           // sicher; GLEICH-Def gz_102e00:1; deklariert 1x1
int f_103530(int, int, int, int, int);       // sicher; liest edx ebx ecx; ret 4?; GLEICH-Def gz_102e00:5; deklariert 5x4
int f_104760(int);                           // sicher; GLEICH-Def ship2_t1:1; deklariert 1x1
int f_104980(int);                           // sicher; liest eax; deklariert 1x4
int f_105860(int);                           // sicher; liest eax; deklariert 1x3
int f_105cd0(int, int);                      // sicher; liest eax edx; deklariert 1x3
int f_105dc0(int);                           // sicher; liest eax; deklariert 1x3
int f_1065f0(int);                           // sicher; liest eax; deklariert 1x3
int f_107280(int, int);                      // sicher; GLEICH-Def gz_107200:2; deklariert 2x1
int f_107360(int);                           // sicher; GLEICH-Def gz_107200:1; deklariert 1x2
int f_108d10(int);                           // sicher; liest eax; deklariert 1x3
int f_109180(int, int);                      // sicher; GLEICH-Def gz_108d10:2; deklariert 2x1
int f_109290(int, int);                      // sicher; liest edx; deklariert 2x4
int f_1092e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_109430(int);                           // sicher; liest eax; deklariert 1x2
int f_1094e0(int);                           // sicher; liest eax; deklariert 0x1 1x5
int f_109800(int);                           // sicher; liest eax; deklariert 1x4
int f_109a50(int);                           // sicher; liest eax; deklariert 1x2
int f_109b20(int);                           // sicher; liest eax; deklariert 1x1
int f_109ba0(int);                           // sicher; GLEICH-Def gz_1099f0:1; deklariert 1x1
int f_109f30(int);                           // sicher; liest eax; deklariert 1x2
int f_10a170(int);                           // sicher; liest eax; deklariert 1x2
int f_10a260(int, int);                      // sicher; liest edx; deklariert 2x5
int f_10a270(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_10a2e0(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert 5x4
int f_10a5a0(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert 5x2
int f_10a7d0(int);                           // sicher; GLEICH-Def gz_1099f0:1; deklariert 1x1
int f_10a7f0(int, int, int, int, int);       // sicher; GLEICH-Def gz_1099f0:5; deklariert 5x1
int f_10a830(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_10a8b0(int);                           // sicher; liest eax; deklariert 1x5
int f_10a8d0(int);                           // sicher; GLEICH-Def gz_1099f0:1; deklariert 1x1
int f_10a8e0(int, int);                      // sicher; GLEICH-Def gz_1099f0:2; deklariert 2x1
int f_10a8f0(int, int);                      // sicher; GLEICH-Def gz_1099f0:2; deklariert 2x1
int f_10a940(int);                           // sicher; liest eax; deklariert 1x5
int f_10a980(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_10aa60(int, int);                      // sicher; liest eax edx; deklariert 2x2 4x1
int f_10aad0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_10ac80(int);                           // sicher; liest eax; deklariert 1x6
int f_10ad00(int);                           // sicher; liest eax; deklariert 1x2
int f_10ad70(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_10ae00(int);                           // sicher; GLEICH-Def gz_10ac80:1; deklariert 1x1
int f_10ae20(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_10af20(int);                           // sicher; liest eax; deklariert 1x2
int f_10af40(int);                           // sicher; liest eax; deklariert 1x2
int f_10af50(int, int);                      // sicher; GLEICH-Def gz_10ac80:2; deklariert 2x1
int f_10af60(int, int);                      // sicher; liest edx; deklariert 2x2
int f_10afd0(int);                           // sicher; GLEICH-Def smith:1; deklariert 1x1
int f_10b0c0(int);                           // sicher; GLEICH-Def smith:1; deklariert 1x1
int f_10b2f0(int);                           // sicher; liest eax; deklariert 1x2
int f_10b520(int);                           // sicher; liest eax; deklariert 1x2
int f_10b6a0(int);                           // sicher; liest eax; deklariert -
int f_10b890(int);                           // sicher; liest eax; deklariert 1x11
int f_10bc50(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_10bd70(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_10cae0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_10cba0(int, int);                      // sicher; liest eax edx; deklariert 2x6 3x1
int f_10cbc0(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 2x6
int f_10cbd0(int);                           // sicher; liest eax; deklariert -
int f_10ccf0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_10cde0(int);                           // sicher; liest eax; deklariert 1x1
int f_10d5e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_10d640(int);                           // sicher; liest eax; deklariert 1x3
int f_10e6c0(int);                           // sicher; GLEICH-Def gz_10d6b0_t1:1; deklariert 1x2
int f_10ea90(int);                           // sicher; GLEICH-Def gz_10d6b0_t1:1; deklariert 1x2
int f_10ef30(int);                           // sicher; GLEICH-Def gz_10d6b0_t1:1; deklariert 1x2
int f_10f250(int);                           // sicher; liest eax; deklariert 1x3
int f_10fc00(int);                           // sicher; GLEICH-Def spell3:1; deklariert 0x1 1x1
int f_110490(int);                           // sicher; GLEICH-Def spell3:1; deklariert 0x1 1x1
int f_110620(int);                           // sicher; GLEICH-Def spell3:1; deklariert 0x1 1x1
int f_110e70(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_110ed0(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_1110c0(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_111440(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_1118a0(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_111a80(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_111b60(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_111d70(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_111f80(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_112080(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112090(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112140(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112150(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112160(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112170(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112180(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112190(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_1121a0(int);                           // sicher; GLEICH-Def gz_110d90:1; deklariert 0x1 1x1
int f_112790(int);                           // sicher; GLEICH-Def gz_112590:1; deklariert 0x1 1x1
int f_112b80(int);                           // sicher; GLEICH-Def gz_112590:1; deklariert 0x1 1x1
int f_112bf0(int);                           // sicher; GLEICH-Def gz_112590:1; deklariert 0x1 1x1
int f_112c20(int);                           // sicher; GLEICH-Def gz_112590:1; deklariert 0x1 1x1
int f_112c90(int);                           // sicher; GLEICH-Def gz_112590:1; deklariert 0x1 1x1
int f_112df0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x44
int f_112e70(int, int);                      // sicher; liest eax; GLEICH-Def spoil:2; Destruktor-Flag; deklariert 1x1 2x43
int f_112ec0(int);                           // sicher; liest eax; deklariert 1x46
int f_112fd0(int);                           // sicher; liest eax; deklariert 1x2
int f_1130d0(int);                           // sicher; GLEICH-Def spoil:1; deklariert 1x2
int f_113110(int);                           // sicher; GLEICH-Def spoil:1; deklariert 1x2
int f_1131b0(int);                           // sicher; liest eax; deklariert 1x27
int f_113240(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_113340(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x20
int f_1134d0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_113500(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_1135c0(int);                           // sicher; liest eax; deklariert 1x2
int f_113640(int);                           // sicher; liest eax; deklariert 1x13
int f_1136d0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_1137e0(int);                           // sicher; GLEICH-Def gz_113770:1; deklariert 0x1 1x1
int f_113920(int, int, int);                 // sicher; GLEICH-Def gz_113770:3; deklariert 3x1
int f_113d40(int);                           // sicher; liest eax; deklariert 1x2
int f_114130(int);                           // sicher; liest eax; deklariert 4x2
int f_1142c0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_114340(int, int, int);                 // sicher; liest edx ebx; deklariert 3x3
int f_114f50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_115080(int, int, int);                 // sicher; GLEICH-Def star_t2:3; deklariert 3x1
int f_1150b0(int, int, int);                 // sicher; liest edx ebx; deklariert 3x4
int f_1155d0(int, int);                      // sicher; liest edx; deklariert 2x7
int f_115630(int, int);                      // sicher; liest edx; deklariert 2x3
int f_115640(int);                           // sicher; liest eax; deklariert 1x1 2x3
int f_115d40(int);                           // sicher; GLEICH-Def gz_1155d0:1; deklariert 1x2
int f_116750(int);                           // sicher; liest eax; deklariert 1x2
int f_1168a0(int);                           // sicher; liest eax; deklariert 1x2
int f_116c00(int);                           // sicher; liest eax; deklariert 1x2
int f_116e40(int);                           // sicher; liest eax; deklariert 1x2
int f_116f90(int);                           // sicher; liest eax; deklariert 1x2
int f_117080(int);                           // sicher; liest eax; deklariert 1x2
int f_117460(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_117650(int);                           // sicher; liest eax; deklariert 1x2
int f_117ed0(int);                           // sicher; liest eax; deklariert 1x2
int f_1182a0(int);                           // sicher; liest eax; deklariert 1x2
int f_118460(int);                           // sicher; liest eax; deklariert 1x2
int f_118580(int);                           // sicher; liest eax; deklariert 1x2
int f_1186f0(int);                           // sicher; liest eax; deklariert 1x2
int f_118e60(int);                           // sicher; GLEICH-Def star2_t1:1; deklariert 1x3
int f_118e80(int);                           // sicher; GLEICH-Def star2_t1:1; deklariert 1x2
int f_119af0(int);                           // sicher; GLEICH-Def star2_t1:1; deklariert 1x2
int f_119b00(int);                           // sicher; GLEICH-Def star2_t1:1; deklariert 1x2
int f_119d50(int);                           // sicher; GLEICH-Def star2_t1:1; deklariert 1x2
int f_119d60(int);                           // sicher; GLEICH-Def star2_t1:1; deklariert 1x2
int f_11a020(int);                           // sicher; liest eax; deklariert 1x2
int f_11a180(int);                           // sicher; GLEICH-Def star2_t2:1; deklariert 1x1
int f_11a250(int, int, int, int, int, int);  // vermutet (sicher 4); liest edx ebx ecx; ret 8?; deklariert 6x1
int f_11a320(int);                           // sicher; liest eax; deklariert 1x2
int f_11a5c0(int);                           // sicher; GLEICH-Def star2_t2:1; deklariert 1x2
int f_11a6b0(int);                           // sicher; GLEICH-Def star2_t2:1; deklariert 1x1
int f_11a6e0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_11a880(int, int);                      // sicher; GLEICH-Def gz_11a880:2; deklariert 2x1
int f_11b5f0(int);                           // sicher; liest eax; deklariert 1x2
int f_11b790(int);                           // sicher; liest eax; deklariert 1x2
int f_11b8f0(int);                           // sicher; liest eax; deklariert 1x1
int f_11b9c0(int);                           // sicher; liest eax; deklariert 1x2
int f_11bd90(int, int);                      // sicher; GLEICH-Def gz_11bd60:2; deklariert 2x1
int f_11bde0(int);                           // sicher; liest eax; deklariert 1x1
int f_11bfd0(int);                           // sicher; liest eax; deklariert 1x1
int f_11c0f0(int, int, int);                 // sicher; liest eax ebx; deklariert 3x3
int f_11c120(int, int);                      // sicher; liest eax; GLEICH-Def gz_11c070:2; deklariert 2x4
int f_11c160(int);                           // sicher; liest eax; deklariert 1x6
int f_11c170(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_11c180(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_11c2e0(int, int);                      // sicher; liest eax edx; deklariert -
int f_11c320(int);                           // sicher; liest eax; deklariert 1x12
int f_11c330(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_11c350(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_11c460(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_11c580(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_11c5f0(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_11c620(int, int);                      // sicher; liest eax edx; deklariert 2x12
int f_11c650(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_11c680(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_11c6e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_11c740(int, int);                      // sicher; GLEICH-Def gz_11c580:2; deklariert 2x1
int f_11c760(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_11c7b0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x1 2x2
int f_11c7c0(int);                           // sicher; liest eax; deklariert 1x1
int f_11c8a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_11c980(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_11caf0(int);                           // sicher; liest eax; deklariert 1x3
int f_11cc00(int);                           // sicher; GLEICH-Def gz_11caf0_t1:1; deklariert 1x1
int f_11cc30(int);                           // sicher; GLEICH-Def gz_11caf0_t1:1; deklariert 1x1
int f_11cd20(int);                           // sicher; GLEICH-Def gz_11caf0_t1:1; deklariert 1x1
int f_11cdb0(int);                           // sicher; GLEICH-Def gz_11caf0_t1:1; deklariert 1x1
int f_11ce00(int);                           // sicher; GLEICH-Def gz_11caf0_t1:1; deklariert 1x1
int f_11cf00(int);                           // sicher; GLEICH-Def gz_11caf0_t1:1; deklariert 1x1
int f_11e4d0(int);                           // sicher; GLEICH-Def gz_11caf0_t2:1; deklariert 1x1
int f_11e6d0(int);                           // sicher; liest eax; deklariert 1x3
int f_11e730(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x2
int f_11e760(int, int, int, int, int, int);  // vermutet (sicher 0); ret 8?; deklariert 2x4 6x3
int f_11e960(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x2
int f_11e9d0(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x2 5x2
int f_11ea00(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x7
int f_11ea90(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_11eae0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_11ebc0(int, int, int);                 // sicher; liest edx ebx; deklariert 3x1
int f_11ed00(int, int);                      // sicher; liest edx; deklariert 2x2
int f_11ed30(int, int);                      // sicher; GLEICH-Def gz_11ed00:2; deklariert 2x2
int f_11ed40(int, int);                      // sicher; GLEICH-Def gz_11ed00:2; deklariert 2x1
int f_11ee50(int);                           // sicher; GLEICH-Def gz_11ed00:1; deklariert 1x1
int f_11ee70(int);                           // sicher; liest eax; deklariert 1x1
int f_11efd0(int);                           // sicher; liest eax; deklariert 1x2
int f_11f1b0(int);                           // sicher; liest eax; deklariert 1x2
int f_11f320(int);                           // sicher; liest eax; deklariert 1x3
int f_11f400(int);                           // sicher; liest eax; deklariert 1x1
int f_11f550(int);                           // sicher; liest eax; deklariert 1x3
int f_11f560(int);                           // sicher; GLEICH-Def gz_11f550:1; deklariert 1x1
int f_11f570(int, int, int, int);            // sicher; GLEICH-Def gz_11f550:4; deklariert 4x1
int f_11f590(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_11f5b0(int, int, int);                 // sicher; GLEICH-Def gz_11f550:3; deklariert 3x1
int f_11f790(int, int, int, int);            // sicher; liest ecx; deklariert 0x1 4x1
int f_11f920(int);                           // sicher; liest eax; deklariert 1x4
int f_11fab0(int, int);                      // sicher; GLEICH-Def tdminit2:2; deklariert 2x1
int f_11fd40(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_11fe20(int, int, int);                 // sicher; GLEICH-Def tdminit2:3; deklariert 3x1
int f_11fee0(int);                           // sicher; liest eax; deklariert 1x3
int f_1205c0(int);                           // sicher; liest eax; deklariert 1x3
int f_1205e0(int);                           // sicher; GLEICH-Def tdminit2:1; deklariert 1x1
int f_120620(int);                           // sicher; liest eax; deklariert 1x6
int f_120640(int);                           // sicher; liest eax; deklariert 1x2
int f_1207a0(int);                           // sicher; liest eax; deklariert -
int f_120980(int);                           // sicher; liest eax; deklariert -
int f_122120(int);                           // sicher; liest eax; deklariert 1x3
int f_122800(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_1228e0(int, int);                      // sicher; GLEICH-Def tdmpal:2; deklariert 2x1
int f_122b70(int);                           // sicher; liest eax; deklariert 1x4
int f_122c10(int);                           // sicher; GLEICH-Def tdmpal:1; deklariert 1x1
int f_122c20(int, int);                      // sicher; GLEICH-Def tdmpal:2; deklariert 2x1
int f_122c30(int);                           // sicher; liest eax; deklariert 1x3
int f_122c50(int);                           // sicher; liest eax; deklariert 1x4
int f_122c70(int);                           // sicher; GLEICH-Def tdmpal:1; deklariert 1x1
int f_1230a0(int);                           // sicher; GLEICH-Def gz_123080:1; deklariert 1x2
int f_1232e0(int);                           // sicher; liest eax; deklariert 1x4
int f_123320(int);                           // sicher; GLEICH-Def gz_123080:1; deklariert 1x1
int f_123330(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_123850(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_123900(int, int);                      // sicher; GLEICH-Def temple:2; deklariert 2x1
int f_1241d0(int);                           // sicher; GLEICH-Def temple:1; deklariert 1x1
int f_124240(int);                           // sicher; GLEICH-Def temple:1; deklariert 1x1
int f_124810(int);                           // sicher; liest eax; deklariert 1x2
int f_124a20(int);                           // sicher; liest eax; deklariert 1x2
int f_125400(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x18 4x147
int f_1254a0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; Destruktor-Flag; deklariert 1x61 2x107
int f_1254e0(int);                           // sicher; liest eax; deklariert 1x2
int f_125500(int);                           // sicher; liest eax; deklariert 1x2
int f_125550(int, int);                      // sicher; liest eax edx; deklariert 4x2
int f_125940(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_125a30(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_125c20(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_125e50(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_125ed0(int, int);                      // sicher; liest eax edx; deklariert 2x64
int f_125f70(int, int);                      // sicher; liest eax edx; deklariert 2x32 3x1
int f_1261b0(int);                           // sicher; liest eax; deklariert 1x2
int f_126410(int);                           // sicher; liest eax; deklariert 1x27
int f_126420(int);                           // sicher; liest eax; deklariert 1x5
int f_126430(int);                           // sicher; liest eax; deklariert 1x4
int f_126450(int);                           // sicher; liest eax; deklariert 1x6
int f_126460(int);                           // sicher; liest eax; deklariert 1x4
int f_1264d0(int, int);                      // sicher; liest eax edx; deklariert -
int f_1264e0(int);                           // sicher; liest eax; deklariert -
int f_1264f0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_126520(int);                           // sicher; liest eax; deklariert 1x1
int f_1265a0(int);                           // sicher; liest eax; deklariert 1x1
int f_1265c0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_126840(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_126b60(int);                           // sicher; liest eax; deklariert -
int f_126c40(int);                           // sicher; liest eax; deklariert 1x1
int f_126c70(int);                           // sicher; liest eax; deklariert 1x2
int f_126dd0(int);                           // sicher; liest eax; deklariert 1x2
int f_126f40(int);                           // sicher; liest eax; deklariert 1x4 2x1
int f_126f80(int, int, int, int, int, int);  // vermutet (sicher 3); liest eax edx ebx; ret 8?; deklariert 6x2
int f_1270c0(int);                           // sicher; liest eax; deklariert 1x6
int f_1271f0(int);                           // sicher; liest eax; deklariert 1x3
int f_127ee0(int);                           // sicher; liest eax; deklariert 1x2
int f_127fa0(int);                           // sicher; liest eax; deklariert 1x2
int f_128e90(int);                           // sicher; GLEICH-Def tower0_t2:1; deklariert 1x1
int f_128fa0(int);                           // sicher; GLEICH-Def tower0_t2:1; deklariert 1x1
int f_129030(int);                           // sicher; GLEICH-Def tower0_t2:1; deklariert 1x1
int f_129080(int);                           // sicher; liest eax; deklariert 1x1
int f_1299d0(int);                           // sicher; GLEICH-Def gz_1295c0:1; deklariert 1x1
int f_129a70(int);                           // sicher; GLEICH-Def gz_1295c0:1; deklariert 1x1
int f_129b00(int, int);                      // sicher; GLEICH-Def gz_1295c0:2; deklariert 2x1
int f_129cc0(int);                           // sicher; GLEICH-Def gz_1295c0:1; deklariert 1x2
int f_12aa30(int);                           // sicher; liest eax; deklariert 1x2
int f_12b370(int);                           // sicher; GLEICH-Def tower1_t2:1; deklariert 1x1
int f_12b850(int);                           // sicher; GLEICH-Def tower1_t2:1; deklariert 1x1
int f_12b880(int);                           // sicher; GLEICH-Def tower1_t2:1; deklariert 1x1
int f_12ba40(int);                           // sicher; GLEICH-Def tower1_t2:1; deklariert 1x1
int f_12ba70(int);                           // sicher; liest eax; deklariert 1x2
int f_12c020(int);                           // sicher; GLEICH-Def tower1_t2:1; deklariert 1x2
int f_12c030(int);                           // sicher; GLEICH-Def tower1_t2:1; deklariert 1x2
int f_12c0a0(int);                           // sicher; liest eax; deklariert 1x2
int f_12c260(int, int);                      // sicher; GLEICH-Def gz_12c190:2; deklariert 2x1
int f_12c5b0(int);                           // sicher; GLEICH-Def gz_12c190:1; deklariert 1x2
int f_12cf20(int);                           // sicher; liest eax; deklariert 1x2
int f_12d060(int);                           // sicher; liest eax; deklariert 1x2
int f_12d1a0(int);                           // sicher; liest eax; deklariert 1x2
int f_12d2e0(int);                           // sicher; GLEICH-Def tower2_t1:1; deklariert 1x2
int f_12d570(int);                           // sicher; liest eax; deklariert 1x2
int f_12d760(int);                           // sicher; GLEICH-Def tower2_t1:1; deklariert 1x2
int f_12d7a0(int);                           // sicher; GLEICH-Def tower2_t1:1; deklariert 1x2
int f_12d960(int);                           // sicher; GLEICH-Def tower2_t2:1; deklariert 1x1
int f_12d980(int);                           // sicher; GLEICH-Def tower2_t2:1; deklariert 1x1
int f_12d9a0(int);                           // sicher; GLEICH-Def tower2_t2:1; deklariert 1x1
int f_12d9c0(int);                           // sicher; liest eax; deklariert 1x2
int f_12dce0(int, int, int, int, int);       // vermutet (sicher 4); liest edx ebx ecx; ret 4?; deklariert 5x3
int f_12df80(int, int);                      // sicher; liest edx; deklariert 2x2
int f_12e350(int, int);                      // sicher; liest edx; deklariert 2x2
int f_12e960(int, int, int);                 // sicher; GLEICH-Def gz_12e960:3; deklariert 3x1
int f_12ea30(int, int);                      // sicher; GLEICH-Def gz_12e960:2; deklariert 2x1
int f_12f8d0(int);                           // sicher; GLEICH-Def tower3_t1:1; deklariert 1x1
int f_12f950(int);                           // sicher; GLEICH-Def tower3_t1:1; deklariert 1x1
int f_12f9d0(int);                           // sicher; GLEICH-Def tower3_t1:1; deklariert 1x1
int f_12fa20(int);                           // sicher; liest eax; deklariert 1x2
int f_12ff10(int, int, int);                 // sicher; GLEICH-Def tower3_t1:3; deklariert 3x1
int f_130040(int);                           // sicher; GLEICH-Def tower3_t2:1; deklariert 1x2
int f_1307b0(int);                           // sicher; GLEICH-Def tower3_t2:1; deklariert 1x2
int f_1309f0(int);                           // sicher; liest eax; deklariert 1x2
int f_130ea0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_130fd0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_131530(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_131650(int, int, int, int, int);       // sicher; liest edx ebx ecx; ret 4?; GLEICH-Def tower3_t3:5; deklariert 5x2
int f_1319a0(int, int, int, int);            // sicher; GLEICH-Def tower3_t3:4; deklariert 4x1
int f_131a10(int);                           // sicher; GLEICH-Def tower3_t3:1; deklariert 0x1 1x1
int f_131a70(int);                           // sicher; liest eax; deklariert 1x4
int f_131b50(int, int);                      // sicher; GLEICH-Def gz_131a70:2; deklariert 2x1
int f_132990(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_1329a0(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_1329b0(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132a70(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132a80(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132bd0(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132be0(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132bf0(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132d40(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132d50(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132d60(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x1
int f_132f40(int);                           // sicher; liest eax; deklariert 1x2
int f_1330b0(int);                           // sicher; GLEICH-Def tower4_t1:1; deklariert 1x2
int f_1333c0(int, int);                      // sicher; GLEICH-Def tower4_t2:2; deklariert 2x2
int f_133410(int, int);                      // sicher; liest edx; deklariert 2x2
int f_133650(int, int);                      // sicher; liest edx; deklariert 2x2
int f_133760(int, int);                      // sicher; GLEICH-Def tower4_t2:2; deklariert 2x2
int f_1337c0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_133890(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_133b30(int);                           // sicher; liest eax; deklariert 1x2
int f_133ca0(int);                           // sicher; GLEICH-Def tower4_t2:1; deklariert 1x1
int f_133cd0(int);                           // sicher; liest eax; deklariert 1x2
int f_133fc0(int, int);                      // vermutet (sicher 0); Aufrufer-Modus 2; deklariert -
int f_133fd0(int);                           // sicher; liest eax; deklariert 1x1
int f_133fe0(int, int);                      // sicher; liest eax edx; deklariert 2x93 3x2 4x1
int f_134010(int, int);                      // sicher; liest edx; deklariert 2x1
int f_134030(int, int, int);                 // sicher; liest edx ebx; deklariert 2x1
int f_1340e0(int, int, int, int);            // sicher; GLEICH-Def gz_1340e0:4; deklariert 4x1
int f_134150(int);                           // sicher; GLEICH-Def gz_1340e0:1; deklariert 1x1
int f_134160(int);                           // sicher; GLEICH-Def gz_1340e0:1; deklariert 1x1
int f_134170(int);                           // sicher; GLEICH-Def gz_1340e0:1; deklariert 1x1
int f_1341d0(int, int);                      // sicher; GLEICH-Def gz_1340e0:2; deklariert 2x1
int f_134250(int, int);                      // sicher; GLEICH-Def gz_1340e0:2; deklariert 2x1
int f_134380(int);                           // sicher; GLEICH-Def gz_1340e0:1; deklariert 1x1
int f_134840(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x7
int f_134870(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x1
int f_1348d0(int, int);                      // vermutet (sicher 0); R106 edx; deklariert 0x5 2x2
int f_1348e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_134910(int);                           // sicher; liest eax; deklariert 1x1
int f_134d50(int);                           // sicher; liest eax; deklariert 1x1
int f_135010(int);                           // sicher; GLEICH-Def gz_1340e0:1; deklariert 1x1
int f_135040(int);                           // sicher; liest eax; deklariert 1x5
int f_135200(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_135590(int);                           // sicher; GLEICH-Def use_t1:1; deklariert 1x1
int f_135d40(int);                           // sicher; liest eax; deklariert 1x4
int f_135d70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_135dc0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_135ef0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_136140(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_136210(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_136250(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_136290(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_136340(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_1363f0(int);                           // sicher; GLEICH-Def use_t2:1; deklariert 1x1
int f_136470(int);                           // sicher; GLEICH-Def use_t2:1; deklariert 1x1
int f_1364f0(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_1365d0(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_136720(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_136870(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_1369b0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_136af0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_136ca0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_136e80(int, int);                      // sicher; GLEICH-Def use_t2:2; deklariert 2x1
int f_136e90(int, int);                      // sicher; GLEICH-Def use_t2:2; deklariert 2x1
int f_136ea0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_136ed0(int, int);                      // sicher; liest edx; deklariert 2x3
int f_136fe0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_137180(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1374f0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_137ad0(int, int);                      // sicher; liest edx; deklariert 2x2
int f_138330(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_1386a0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_138960(int, int);                      // sicher; GLEICH-Def use_t4:2; deklariert 2x1
int f_1389b0(int);                           // sicher; liest eax; deklariert 1x2
int f_138fe0(int);                           // sicher; GLEICH-Def use_t4:1; deklariert 1x1
int f_139b10(int, int, int);                 // sicher; GLEICH-Def use_t4:3; deklariert 3x1
int f_13a550(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_13a620(int);                           // sicher; liest eax; deklariert 1x2
int f_13a700(int);                           // sicher; GLEICH-Def use_t5:1; deklariert 1x1
int f_13a9c0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_13aa40(int);                           // sicher; GLEICH-Def gz_13aa40:1; deklariert 1x1
int f_13ad00(int);                           // sicher; GLEICH-Def gz_13aa40:1; deklariert 1x1
int f_13adb0(int);                           // sicher; GLEICH-Def gz_13aa40:1; deklariert 1x1
int f_13b7b0(int);                           // sicher; GLEICH-Def use3:1; deklariert 1x1
int f_13b840(int);                           // sicher; GLEICH-Def use3:1; deklariert 1x1
int f_13b9b0(int);                           // sicher; GLEICH-Def use3:1; deklariert 1x1
int f_13bb70(int, int, int);                 // sicher; liest edx ebx; deklariert 3x3
int f_13bbd0(int);                           // sicher; GLEICH-Def gz_13bb70_t1:1; deklariert 1x1
int f_13bc30(int);                           // sicher; liest eax; deklariert 1x2
int f_13c290(int);                           // sicher; GLEICH-Def gz_13bb70_t1:1; deklariert 1x1
int f_13c2e0(int, int, int);                 // sicher; GLEICH-Def gz_13bb70_t1:3; deklariert 3x1
int f_13c340(int);                           // sicher; liest eax; deklariert 1x2
int f_13cc50(int);                           // sicher; liest eax; deklariert 1x2
int f_13d490(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_13d570(int);                           // sicher; liest eax; deklariert 1x1
int f_13d5d0(int);                           // sicher; liest eax; deklariert 1x2
int f_13dba0(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x3
int f_13dbb0(int);                           // sicher; liest eax; deklariert 1x2
int f_13dc90(int);                           // sicher; GLEICH-Def gz_13bb70_t2:1; deklariert 1x1
int f_13e140(int);                           // sicher; liest eax; deklariert 1x4
int f_13e3a0(int);                           // sicher; GLEICH-Def uvesa:1; deklariert 1x1
int f_13e690(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x6
int f_13eab0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1 7x2
int f_13efd0(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x3
int f_13f360(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x1
int f_13f8e0(int, int, int, int);            // sicher; GLEICH-Def uvesa:4; deklariert 4x1
int f_13f9d0(int, int, int, int);            // sicher; GLEICH-Def virtdisk:4; deklariert 4x1
int f_13fa10(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x1
int f_13fa20(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x1
int f_13fa30(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x1
int f_13fa40(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x1
int f_13fa50(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x2
int f_13fa60(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x1
int f_13fa90(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_13faf0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_13fbe0(int, int);                      // sicher; GLEICH-Def virtdisk:2; deklariert 2x1
int f_13fbf0(int);                           // sicher; GLEICH-Def virtdisk:1; deklariert 1x1
int f_13fc30(int, int);                      // sicher; GLEICH-Def virtdisk:2; deklariert 2x1
int f_13fc40(int, int);                      // sicher; GLEICH-Def virtdisk:2; deklariert 2x1
int f_13fc70(int);                           // sicher; liest eax; deklariert 1x9 2x3
int f_13fcd0(int, int);                      // sicher; liest eax edx; deklariert 2x10 3x1
int f_13fd60(int);                           // sicher; liest eax; deklariert 1x2
int f_13fdd0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_13ffa0(int, int, int);                 // sicher; GLEICH-Def gz_13fef0:3; deklariert 3x1
int f_1400c0(int);                           // sicher; GLEICH-Def gz_13fef0:1; deklariert 1x1
int f_140140(int, int);                      // sicher; GLEICH-Def gz_13fef0:2; deklariert 2x1
int f_140150(int);                           // sicher; GLEICH-Def gz_13fef0:1; deklariert 1x1
int f_140300(int);                           // sicher; liest eax; deklariert 1x1 2x3
int f_140360(int);                           // sicher; liest eax; deklariert 1x6
int f_140370(int);                           // sicher; liest eax; deklariert 1x6
int f_140380(int);                           // sicher; liest eax; deklariert 1x6
int f_140390(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_140410(int, int);                      // sicher; GLEICH-Def gz_13fef0:2; deklariert 2x1
int f_140460(int, int);                      // sicher; GLEICH-Def gz_13fef0:2; deklariert 2x1
int f_1404e0(int);                           // sicher; liest eax; deklariert 1x5 3x1
int f_1405c0(int);                           // sicher; liest eax; deklariert 1x6
int f_1407a0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_140930(int);                           // sicher; GLEICH-Def gz_140930:1; deklariert 1x1
int f_1409c0(int, int, int);                 // sicher; GLEICH-Def gz_140930:3; deklariert 3x1
int f_140b00(int);                           // sicher; GLEICH-Def gz_140930:1; deklariert 1x1
int f_140b40(int);                           // sicher; liest eax; deklariert 1x2
int f_140d00(int);                           // sicher; liest eax; deklariert 1x2
int f_140de0(int);                           // sicher; liest eax; deklariert 1x2
int f_140e90(int);                           // sicher; GLEICH-Def xdialog_t1:1; deklariert 1x1
int f_140f20(int);                           // sicher; liest eax; deklariert 1x1
int f_141020(int);                           // sicher; liest eax; deklariert 1x2
int f_1411e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_141310(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_141420(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1414e0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_141720(int, int, int);                 // sicher; GLEICH-Def xdialog_t1:3; deklariert 3x1
int f_141780(int);                           // sicher; GLEICH-Def xdialog_t1:1; deklariert 1x1
int f_141950(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_141a40(int);                           // sicher; liest eax; deklariert 1x1
int f_141c00(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_141d30(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_141ef0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_141fc0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1422a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_142390(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_142480(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1425a0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_142700(int, int);                      // sicher; GLEICH-Def xdialog_t2:2; deklariert 2x1
int f_142750(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_142890(int, int);                      // sicher; GLEICH-Def xdialog_t2:2; deklariert 2x2
int f_142920(int);                           // sicher; liest eax; deklariert 1x3
int f_142d20(int);                           // vermutet (sicher 0); Aufrufer-Modus 1; deklariert 1x3
int f_142e10(int);                           // sicher; liest eax; deklariert 1x2
int f_142e90(int);                           // sicher; liest eax; deklariert 1x2
int f_142f70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3
int f_1430a0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_143170(int);                           // sicher; liest eax; deklariert 1x2
int f_143330(int, int);                      // sicher; GLEICH-Def gz_143330:2; deklariert 2x1
int f_143350(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_143390(int);                           // sicher; liest eax; deklariert 1x3
int f_1433c0(int);                           // sicher; liest eax; deklariert 1x3
int f_1433d0(int, int);                      // sicher; liest eax edx; deklariert 3x3
int f_1434f0(int);                           // sicher; liest eax; deklariert 1x3
int f_143500(int);                           // sicher; GLEICH-Def gz_143330:1; deklariert 1x1
int f_1439e0(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1445c0(int);                           // sicher; GLEICH-Def fz_144090:1; deklariert 1x1
int f_1445d0(int);                           // sicher; GLEICH-Def fz_144090:1; deklariert 1x1
int f_1445e0(int);                           // sicher; GLEICH-Def fz_144090:1; deklariert 1x1
int f_144610(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x8
int f_144630(int, int);                      // sicher; GLEICH-Def fz_144090:2; deklariert 2x2
int f_144670(int, int);                      // sicher; GLEICH-Def fz_144090:2; deklariert 2x2
int f_1446b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_144820(int);                           // sicher; GLEICH-Def fz_144090:1; deklariert 1x2
int f_144850(int, int);                      // sicher; liest eax; GLEICH-Def fz_144090:2; deklariert 2x9 4x2
int f_144870(int, int);                      // sicher; liest eax; GLEICH-Def fz_144090:2; deklariert 2x13 4x3
int f_144890(int, int);                      // sicher; liest eax; GLEICH-Def fz_144090:2; deklariert 2x6 3x1 4x4
int f_1448b0(int, int, int);                 // sicher; liest eax ebx; deklariert 3x45 4x1
int f_1448d0(int, int, int);                 // vermutet (sicher 1); liest eax; R106 ebx; deklariert 2x5 3x3
int f_144920(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x41
int f_144960(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x26 4x1
int f_1449a0(int);                           // sicher; liest eax; deklariert 1x42 3x2
int f_1449d0(int);                           // sicher; GLEICH-Def fz_144090:1; deklariert 1x2
int f_144a00(int);                           // sicher; liest eax; deklariert 1x8 3x2
int f_144a30(int, int);                      // sicher; liest eax; GLEICH-Def fz_144090:2; deklariert 2x6 3x1 4x2
int f_144a80(int);                           // sicher; liest eax; deklariert 1x3
int f_144ab0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x35
int f_144af0(int, int);                      // sicher; liest eax; GLEICH-Def fz_144090:2; deklariert 1x1 2x4 4x1
int f_144b10(int);                           // sicher; GLEICH-Def fz_144090:1; deklariert 1x2
int f_144b70(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x3 4x2
int f_144bb0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_144cb6(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x15
int f_144e8b(int, int, int);                 // sicher; liest eax edx ebx; deklariert 1x1 2x1 3x19
int f_145279(int, int, int);                 // sicher; liest eax edx ebx; deklariert 1x1 3x11
int f_1452bc(int);                           // sicher; liest eax; deklariert 1x9
int f_145318(int);                           // sicher; liest eax; deklariert 2x3
int f_145400(int);                           // sicher; liest eax; deklariert 1x10
int f_145450(int);                           // sicher; liest eax; deklariert 1x3
int f_1454d0(int);                           // sicher; liest eax; deklariert 1x14 2x1
int f_145547(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_145590(int, int, int);                 // sicher; liest eax ebx; deklariert 3x2
int f_145702(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_145760(int, int);                      // sicher; liest eax edx; deklariert 2x47
int f_1457e0(int);                           // sicher; liest eax; deklariert 1x95
int f_145850(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x25
int f_145920(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_145970(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_1459b0(int);                           // sicher; liest eax; deklariert 1x19 2x1
int f_1459d0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x11 2x11
int f_145a10(int, int, int);                 // vermutet (sicher 0); R106 ebx; deklariert 3x19
int f_145a20(int, int, int, int);            // vermutet (sicher 0); R106 ecx; deklariert 4x5
int f_145a60(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_145b10(int);                           // sicher; liest eax; deklariert 1x8
int f_145b40(int);                           // sicher; liest eax; deklariert 1x16
int f_145b50(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_145b70(int);                           // sicher; liest eax; deklariert 1x2
int f_145b80(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5
int f_145c20(int);                           // sicher; liest eax; deklariert 1x2
int f_145c80(int);                           // sicher; liest eax; deklariert 1x2
int f_145d60(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_145e30(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_145ee0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_146030(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_146170(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1462d3(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_14633d(int);                           // sicher; liest eax; deklariert 1x2
int f_146364(int);                           // sicher; liest eax; deklariert 1x2
int f_146389(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_146552(int);                           // sicher; liest eax; deklariert 1x2
int f_1466cd(int);                           // sicher; liest eax; deklariert 1x2
int f_146864(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1468dc(int);                           // sicher; liest eax; deklariert 1x2
int f_146920(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_146a09(int, int);                      // sicher; GLEICH-Def fz_145760_t2:2; deklariert 2x1
int f_146ae4(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_146b32(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_146d0f(int);                           // sicher; liest eax; deklariert 1x1
int f_146d36(int);                           // sicher; liest eax; deklariert 1x2
int f_146d5c(int);                           // sicher; liest eax; deklariert 1x1
int f_146d86(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_146dfa(int, int);                      // sicher; liest eax edx; deklariert 2x26
int f_146f46(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_147323(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x77
int f_147688(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_147746(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_14778f(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_147808(int);                           // sicher; liest eax; deklariert 1x4
int f_147869(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1478b4(int);                           // sicher; liest eax; deklariert 1x2
int f_1478de(int);                           // sicher; liest eax; deklariert 1x2
int f_147904(int);                           // sicher; liest eax; deklariert 1x2
int f_14792e(int);                           // sicher; liest eax; deklariert 1x2
int f_147954(int);                           // sicher; liest eax; deklariert 1x1
int f_147aad(int);                           // sicher; liest eax; deklariert 1x11
int f_147b3f(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_147b97(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_147c02(int, int);                      // sicher; liest eax edx; deklariert 2x10
int f_147c84(int, int, int);                 // sicher; liest eax edx ebx; deklariert 0x1 2x2 3x24 4x1
int f_147cd0(int);                           // sicher; liest eax; deklariert 1x7
int f_147d00(int, int);                      // sicher; GLEICH-Def fz_147cd0:2; deklariert 2x1
int f_147d30(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x1
int f_147d40(int, int);                      // sicher; GLEICH-Def fz_147cd0:2; deklariert 2x1
int f_147d50(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x1
int f_147d60(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x1
int f_147d70(int, int);                      // sicher; GLEICH-Def fz_147cd0:2; deklariert 2x1
int f_147d80(int, int);                      // sicher; GLEICH-Def fz_147cd0:2; deklariert 2x1
int f_147d90(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x1
int f_147da0(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x1
int f_147db0(int, int);                      // sicher; GLEICH-Def fz_147cd0:2; deklariert 2x1
int f_147dc0(int, int, int);                 // sicher; GLEICH-Def fz_147cd0:3; deklariert 3x1
int f_147dd0(int, int, int);                 // sicher; liest edx ebx; deklariert 3x2
int f_147de0(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x1
int f_147ef0(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x8
int f_147f00(int, int, int);                 // sicher; liest ebx; deklariert 3x2
int f_147f10(int);                           // sicher; GLEICH-Def fz_147cd0:1; deklariert 1x2
int f_148130(int, int, int);                 // sicher; GLEICH-Def fz_147cd0:3; deklariert 3x1
int f_148143(int, int, int);                 // sicher; liest eax edx ebx; deklariert 2x1 3x6 4x1
int f_148170(int);                           // sicher; liest eax; deklariert 1x1
int f_148180(int);                           // sicher; liest eax; deklariert 1x5
int f_1481a0(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x12
int f_148270(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert -
int f_148320(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert -
int f_1483f0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x12
int f_148450(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x7
int f_1484ce(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_148518(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_148534(int);                           // sicher; liest eax; deklariert 1x10 2x1
int f_14854c(int);                           // sicher; liest eax; deklariert -
int f_148570(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1485c0(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148620(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148650(int);                           // sicher; GLEICH-Def fz_148570:1; deklariert 1x1
int f_1486f0(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148840(int, int, int);                 // sicher; GLEICH-Def fz_148570:3; deklariert 3x1
int f_148990(int, int, int);                 // sicher; GLEICH-Def fz_148570:3; deklariert 3x1
int f_1489d0(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148ac0(int);                           // sicher; GLEICH-Def fz_148570:1; deklariert 1x1
int f_148b10(int);                           // sicher; GLEICH-Def fz_148570:1; deklariert 1x1
int f_148b40(int);                           // sicher; GLEICH-Def fz_148570:1; deklariert 1x1
int f_148b70(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148be0(int);                           // sicher; GLEICH-Def fz_148570:1; deklariert 1x1
int f_148c10(int, int, int);                 // sicher; GLEICH-Def fz_148570:3; deklariert 3x1
int f_148c50(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148d20(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148d60(int);                           // sicher; GLEICH-Def fz_148570:1; deklariert 1x1
int f_148d70(int, int);                      // sicher; GLEICH-Def fz_148570:2; deklariert 2x1
int f_148e00(int, int, int, int);            // sicher; GLEICH-Def fz_148570:4; deklariert 4x1
int f_149010(int, int, int);                 // sicher; GLEICH-Def fz_148570:3; deklariert 3x1
int f_1491c0(int, int, int);                 // sicher; GLEICH-Def fz_148570:3; deklariert 3x1
int f_149210(int, int, int, int);            // sicher; GLEICH-Def fz_148570:4; deklariert 4x1
int f_149292(int);                           // sicher; liest eax; deklariert 1x2
int f_1492d1(int);                           // sicher; liest eax; deklariert 1x6
int f_1492f0(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_149313(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_149336(int);                           // sicher; liest eax; deklariert 1x10 2x1
int f_1493c0(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_149410(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_149524(int);                           // sicher; liest eax; deklariert 1x8
int f_149640(int);                           // sicher; liest eax; deklariert 1x6
int f_149728(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_1497d8(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_149a14(int, int);                      // sicher; liest eax edx; deklariert 2x9
int f_149b9c(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_149caa(int);                           // sicher; liest eax; deklariert 1x1 3x1
int f_149cd2(int, int, int);                 // vermutet (sicher 1); liest eax; R106 ebx; deklariert 3x2
int f_149cf5(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_149dbe(int, int, int);                 // sicher; liest ebx; deklariert 2x1
int f_149f10(int, int, int, int, int, int, int, int, int); // vermutet (sicher 0); ret 20?; deklariert -
int f_14a1d0(int, int, int, int, int, int);  // vermutet (sicher 0); ret 8?; deklariert 2x2 6x3
int f_14b0c0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert -
int f_14b3d0(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x3 5x3
int f_14b520(int);                           // sicher; liest eax; deklariert -
int f_14b7b0(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x2 5x2
int f_14bb10(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x1
int f_14bb30(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert 1x1
int f_14bb40(int, int, int, int, int, int, int); // vermutet (sicher 0); ret 12?; deklariert 3x1 7x4
int f_14cf00(int);                           // sicher; liest eax; deklariert -
int f_14d075(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x5
int f_14d0c2(int);                           // sicher; liest eax; deklariert -
int f_14d0d7(int);                           // sicher; liest eax; deklariert 1x1 2x6
int f_14d17f(int);                           // sicher; liest eax; deklariert 1x7
int f_14d1c1(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_14d2a3(int);                           // sicher; liest eax; deklariert 1x1
int f_14d36e(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x3
int f_14d3ee(int, int);                      // sicher; liest eax edx; deklariert 4x2
int f_14d44c(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_14d50b(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x3
int f_14d5c9(int);                           // sicher; liest eax; deklariert 1x7 2x1
int f_14d652(int, int, int);                 // vermutet (sicher 1); liest eax; R106 ebx; deklariert 3x1
int f_14d667(int);                           // sicher; liest eax; deklariert 1x1
int f_14d6c4(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_14d717(int, int);                      // sicher; liest eax edx; deklariert 2x5
int f_14d75e(int, int, int, int);            // sicher; liest ecx; deklariert -
int f_14d784(int, int, int, int);            // sicher; liest eax edx ecx; deklariert -
int f_14d7dc(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x3
int f_14dc28(int);                           // sicher; liest eax; deklariert 1x2
int f_14dc6c(int);                           // sicher; liest eax; deklariert 1x2
int f_14dd20(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x3
int f_14def4(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x2
int f_14e288(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_14e520(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_14e5c8(int);                           // sicher; liest eax; deklariert 1x2
int f_14ea94(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5
int f_14ec24(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x2
int f_14eeac(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x2
int f_14f61c(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_14fc78(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1511ec(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_1512d8(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_15156c(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_151958(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_152020(int);                           // sicher; liest eax; deklariert 1x2
int f_152310(int);                           // sicher; liest eax; deklariert 1x2
int f_1524d0(int);                           // sicher; liest eax; deklariert 1x1
int f_152654(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_152870(int);                           // sicher; liest eax; deklariert 1x1
int f_154e78(int);                           // sicher; liest eax; deklariert 1x1
int f_154eb8(int, int, int, int);            // sicher; GLEICH-Def fz_14dc28_t7:4; deklariert 4x1
int f_154f00(int);                           // sicher; liest eax; deklariert 1x1
int f_154f08(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_155268(int, int, int);                 // sicher; GLEICH-Def fz_14dc28_t7:3; deklariert 3x1
int f_155900(int);                           // sicher; liest eax; deklariert 1x2
int f_155968(int);                           // sicher; liest eax; deklariert 1x3
int f_155ab0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_155b20(int);                           // sicher; liest eax; deklariert 1x1
int f_155b80(int);                           // sicher; liest eax; deklariert 1x1
int f_155bc8(int);                           // sicher; liest eax; deklariert 1x2
int f_155bfc(int);                           // sicher; liest eax; deklariert 1x1
int f_155c94(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_155d74(int);                           // sicher; liest eax; deklariert 1x2
int f_155e08(int);                           // sicher; liest eax; deklariert 1x2
int f_155ebc(int);                           // sicher; GLEICH-Def fz_14dc28_t7:1; deklariert 1x1
int f_155f70(int);                           // sicher; liest eax; deklariert 1x3
int f_156370(int, int, int, int);            // sicher; GLEICH-Def fz_14dc28_t8:4; deklariert 4x2
int f_156384(int, int, int, int, int);       // sicher; GLEICH-Def fz_14dc28_t8:5; deklariert 5x1
int f_1566b8(int);                           // sicher; liest eax; deklariert 1x1
int f_1567af(int);                           // sicher; liest eax; deklariert 1x1
int f_15680e(int, int);                      // sicher; liest edx; deklariert -
int f_156870(int, int);                      // sicher; liest eax edx; deklariert 3x1
int f_15689d(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_1568b9(int);                           // sicher; GLEICH-Def fz_15689d_t1:1; deklariert 1x2
int f_1568bf(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1568cb(int);                           // sicher; liest eax; deklariert 1x1
int f_1568d1(int, int);                      // vermutet (sicher 0); R106 edx; deklariert -
int f_156cf4(int);                           // sicher; liest eax; deklariert 1x2 4x2
int f_156de4(int);                           // sicher; liest eax; deklariert 1x2
int f_15713c(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_157158(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15717c(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1574ac(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x2
int f_157614(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_15794c(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_158128(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_1581c8(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_158258(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_158288(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_158314(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1583f8(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_158420(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_15843c(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_1590bc(int);                           // sicher; liest eax; deklariert 1x1
int f_15b770(int);                           // sicher; liest eax; deklariert 1x2
int f_15b790(int);                           // sicher; liest eax; deklariert 1x2
int f_15b8a0(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15b8d0(int);                           // sicher; liest eax; deklariert 1x1 2x1
int f_15b980(int, int);                      // sicher; GLEICH-Def fz_15689d_t3:2; deklariert 2x1
int f_15b990(int, int);                      // sicher; liest eax; GLEICH-Def fz_15689d_t3:2; deklariert 2x3
int f_15b9b0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15ba50(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_15baa0(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15bab0(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15bad0(int);                           // sicher; liest eax; deklariert 1x3
int f_15bc00(int);                           // sicher; liest eax; deklariert 1x1 2x2
int f_15bc30(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15bcc0(int, int);                      // sicher; GLEICH-Def fz_15689d_t3:2; deklariert 2x1
int f_15bcd0(int, int);                      // sicher; liest eax; GLEICH-Def fz_15689d_t3:2; deklariert 2x3
int f_15bcf0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15bdd0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_15be30(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15be40(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15be60(int);                           // sicher; liest eax; deklariert 1x3
int f_15bea0(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15bec0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15bfa0(int);                           // sicher; liest eax; deklariert 1x1 2x2
int f_15bfe0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15c050(int, int);                      // sicher; GLEICH-Def fz_15689d_t3:2; deklariert 2x1
int f_15c060(int, int);                      // sicher; liest eax; GLEICH-Def fz_15689d_t3:2; deklariert 2x2
int f_15c080(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15c120(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_15c140(int, int, int, int);            // vermutet (sicher 2); liest eax edx; Aufrufer-Modus 4; deklariert 2x2
int f_15c170(int);                           // sicher; liest eax; deklariert 1x4
int f_15c180(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15c1a0(int);                           // sicher; liest eax; deklariert 1x5
int f_15c1e0(int);                           // sicher; GLEICH-Def fz_15689d_t3:1; deklariert 1x1
int f_15c300(int);                           // sicher; liest eax; deklariert 1x2
int f_15c330(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x1 2x2
int f_15c370(int, int);                      // sicher; GLEICH-Def fz_15689d_t3:2; deklariert 2x1
int f_15c3e0(int, int);                      // sicher; GLEICH-Def fz_15689d_t3:2; deklariert 2x1
int f_15c3f0(int, int);                      // sicher; liest eax; GLEICH-Def fz_15689d_t3:2; deklariert 2x3
int f_15c410(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15c4b0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 4x2
int f_15c5c8(int);                           // sicher; liest eax; deklariert 1x4
int f_15c6d0(int, int);                      // vermutet (sicher 1); liest eax; Aufrufer-Modus 2; deklariert 1x1 2x3
int f_15c700(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_15c850(int);                           // sicher; liest eax; deklariert 1x4
int f_15c860(int);                           // sicher; liest eax; deklariert 1x4
int f_15c870(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_15c9b0(int);                           // sicher; liest eax; deklariert 1x2
int f_15cae0(int);                           // sicher; GLEICH-Def fz_15689d_t4:1; deklariert 1x1
int f_15cb30(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15cbb0(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15cf90(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_15cff0(int);                           // sicher; GLEICH-Def fz_15689d_t4:1; deklariert 1x1
int f_15d040(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15d150(int, int, int, int);            // sicher; GLEICH-Def fz_15689d_t4:4; deklariert 4x1
int f_15d1d0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_15d4d0(int);                           // sicher; liest eax; deklariert 1x4
int f_15d4e8(int);                           // sicher; liest eax; deklariert 1x3
int f_15d574(int);                           // sicher; GLEICH-Def fz_15689d_t4:1; deklariert 1x1
int f_15d584(int);                           // sicher; liest eax; deklariert 1x5
int f_15d744(int);                           // sicher; GLEICH-Def fz_15689d_t4:1; deklariert 0x1 1x3
int f_15d754(int);                           // sicher; liest eax; deklariert 1x2
int f_15d90c(int, int);                      // sicher; liest eax edx; deklariert 1x2 2x2
int f_15da8c(int);                           // sicher; liest eax; deklariert 2x3
int f_15dadc(int, int);                      // sicher; liest eax edx; deklariert 1x1 2x3
int f_15db68(int);                           // sicher; liest eax; deklariert 1x4
int f_15dc00(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_15dc3f(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_15dc63(int);                           // sicher; liest eax; deklariert -
int f_15dc98(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_15e0e7(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert -
int f_15e114(int, int, int);                 // sicher; liest eax ebx; deklariert -
int f_15e181(int);                           // sicher; liest eax; deklariert -
int f_15e29b(int);                           // sicher; liest eax; deklariert -
int f_15e36c(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert -
int f_15e430(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_15e473(int);                           // sicher; liest eax; deklariert -
int f_15e51d(int, int);                      // sicher; liest eax edx; deklariert -
int f_15e55f(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1 4x1
int f_15e65b(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x4
int f_15e836(int);                           // sicher; liest eax; deklariert 1x6
int f_15e863(int);                           // sicher; liest eax; deklariert -
int f_15e878(int);                           // sicher; liest eax; deklariert -
int f_15e884(int, int);                      // sicher; liest eax edx; deklariert -
int f_15e8e9(int, int);                      // sicher; liest eax edx; deklariert -
int f_15e9c0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert -
int f_15ea62(int);                           // sicher; liest eax; deklariert 1x3
int f_15ea70(int);                           // sicher; liest eax; deklariert 1x2
int f_15eaab(int);                           // sicher; liest eax; deklariert -
int f_15eaf3(int);                           // sicher; liest eax; deklariert 1x4
int f_15ebd6(int);                           // sicher; liest eax; deklariert 1x5
int f_15ec58(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_15ec70(int);                           // sicher; liest eax; deklariert 1x5
int f_15eca0(int, int);                      // vermutet (sicher 1); liest eax; R106 edx; deklariert 1x2 2x3
int f_15ecb0(int, int, int, int, int, int, int, int); // sicher; GLEICH-Def fz_15ec70:8; deklariert 8x1
int f_15f130(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert 8x5
int f_15f1b4(int);                           // sicher; liest eax; deklariert 1x1
int f_15f1c8(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_15f1e1(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15f269(int);                           // sicher; liest eax; deklariert -
int f_15f282(int, int);                      // sicher; liest eax edx; deklariert -
int f_15f2b5(int);                           // sicher; liest eax; deklariert 1x2
int f_15f2d6(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_15f2f5(int, int);                      // sicher; liest eax edx; deklariert -
int f_15f2ff(int);                           // sicher; liest eax; deklariert -
int f_15f30c(int);                           // sicher; liest eax; deklariert -
int f_15f342(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_15f35d(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_15f367(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15f385(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_15f3a0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_15f3bc(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_15f3d4(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_15f42e(int);                           // sicher; liest eax; deklariert -
int f_15fdd5(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_15fffc(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_160320(int);                           // sicher; liest eax; deklariert 1x6
int f_160790(int);                           // sicher; liest eax; deklariert -
int f_160d18(int, int);                      // sicher; liest eax edx; deklariert -
int f_160d8c(int, int);                      // sicher; liest eax edx; deklariert -
int f_160e94(int);                           // sicher; liest eax; deklariert -
int f_160f64(int, int);                      // sicher; liest eax edx; deklariert -
int f_161e84(int);                           // sicher; liest eax; deklariert 1x6
int f_161fd8(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_1622c0(int);                           // sicher; liest eax; deklariert 1x1
int f_16232c(int);                           // sicher; liest eax; deklariert 1x2
int f_16238c(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_162a4c(int, int);                      // sicher; liest eax edx; deklariert -
int f_162b10(int);                           // sicher; liest eax; deklariert -
int f_162b38(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_162c64(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert -
int f_162cc0(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert -
int f_162d28(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert -
int f_162db8(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x6
int f_163050(int);                           // sicher; liest eax; deklariert 1x6
int f_163428(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_163484(int, int);                      // sicher; liest eax edx; deklariert 2x1 4x5
int f_163504(int, int);                      // sicher; liest eax edx; deklariert -
int f_163a98(int);                           // sicher; liest eax; deklariert 1x2
int f_163b08(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_163bac(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_163bf8(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x7
int f_163d48(int);                           // sicher; liest eax; deklariert -
int f_164748(int, int, int, int, int);       // vermutet (sicher 1); liest eax; ret 4?; deklariert 1x1 2x1
int f_164808(int, int, int, int, int);       // vermutet (sicher 1); liest eax; ret 4?; deklariert 1x1 2x1
int f_164880(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_164994(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_164d04(int);                           // sicher; liest eax; deklariert 1x1
int f_164e64(int, int);                      // sicher; liest eax edx; deklariert -
int f_165570(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_165620(int, int);                      // sicher; liest eax edx; deklariert -
int f_165c50(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_165d73(int, int, int);                 // sicher; liest eax edx ebx; deklariert 2x1
int f_165de2(int, int);                      // sicher; liest edx; deklariert 0x1
int f_165e06(int);                           // sicher; liest eax; deklariert 1x1
int f_165e20(int, int, int, int, int, int);  // vermutet (sicher 0); ret 8?; deklariert -
int f_1664d0(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x11
int f_16657c(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_166599(int);                           // sicher; liest eax; deklariert -
int f_1665ee(int, int);                      // sicher; liest eax edx; deklariert -
int f_166608(int);                           // sicher; liest eax; deklariert -
int f_16662b(int);                           // sicher; liest eax; deklariert -
int f_16663e(int, int);                      // sicher; liest edx; deklariert -
int f_166642(int);                           // sicher; liest eax; deklariert -
int f_1666cf(int);                           // sicher; liest eax; deklariert -
int f_1666fc(int, int);                      // sicher; liest eax edx; deklariert -
int f_166723(int);                           // sicher; liest eax; deklariert -
int f_166760(int, int, int, int);            // sicher; liest eax edx ecx; deklariert -
int f_166797(int, int, int, int);            // sicher; liest eax edx ecx; deklariert -
int f_166803(int, int);                      // sicher; liest eax edx; deklariert -
int f_166856(int);                           // sicher; liest eax; deklariert -
int f_16691e(int);                           // sicher; liest eax; deklariert -
int f_1669e9(int);                           // sicher; liest eax; deklariert -
int f_166a96(int, int);                      // sicher; liest eax edx; deklariert -
int f_166b95(int);                           // sicher; liest eax; deklariert -
int f_166f26(int);                           // sicher; liest eax; deklariert -
int f_166fdc(int, int, int);                 // sicher; liest ebx; deklariert -
int f_16704e(int, int);                      // sicher; liest eax edx; deklariert -
int f_167382(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_167721(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16785f(int, int);                      // sicher; liest eax edx; deklariert -
int f_1678be(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_1678e2(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_167905(int, int, int);                 // sicher; liest edx ebx; deklariert -
int f_167963(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_167a5f(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_167f48(int);                           // sicher; liest eax; deklariert -
int f_167f75(int, int, int, int);            // sicher; liest eax edx ecx; deklariert 2x3 4x1
int f_1680f5(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_168167(int);                           // sicher; GLEICH-Def fz_167f60_t1:1; deklariert 1x2
int f_1681ff(int);                           // sicher; GLEICH-Def fz_167f60_t1:1; deklariert 1x2
int f_168241(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_1682c9(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_16833f(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1683b5(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_16842b(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_1684b1(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_168527(int, int, int);                 // sicher; GLEICH-Def fz_167f60_t1:3; deklariert 3x2
int f_1685ad(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_168623(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_168699(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_1686fd(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_168787(int);                           // sicher; liest eax; deklariert 1x3
int f_1687c9(int, int);                      // sicher; liest eax edx; deklariert 2x4
int f_16886d(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_168944(int);                           // sicher; liest eax; deklariert 1x3
int f_16897e(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_168b6c(int, int);                      // sicher; GLEICH-Def fz_167f60_t1:2; deklariert 2x2
int f_168cd4(int);                           // sicher; liest eax; deklariert 1x4
int f_168e6c(int);                           // sicher; GLEICH-Def fz_167f60_t1:1; deklariert 1x2
int f_168e96(int);                           // sicher; liest eax; deklariert 1x2
int f_168faf(int, int);                      // sicher; liest eax edx; deklariert 2x3
int f_169412(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_1695ef(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_1696b8(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_1697d4(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x2
int f_16991e(int, int);                      // sicher; liest eax edx; deklariert 2x2
int f_1699f9(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_169a33(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x1
int f_169b56(int, int);                      // sicher; liest edx; deklariert -
int f_169c99(int);                           // sicher; liest eax; deklariert 1x1
int f_16a69e(int, int);                      // sicher; liest edx; deklariert -
int f_16a796(int, int);                      // sicher; liest edx; deklariert -
int f_16a848(int, int);                      // sicher; liest edx; deklariert -
int f_16a8f0(int, int);                      // sicher; liest edx; deklariert -
int f_16a95b(int, int, int);                 // sicher; liest eax ebx; deklariert -
int f_16a9ca(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert -
int f_16a9da(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_16ab99(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16ac31(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16ac61(int, int, int);                 // sicher; liest ebx; deklariert -
int f_16acca(int);                           // sicher; liest eax; deklariert -
int f_16acea(int, int, int);                 // vermutet (sicher 1); liest eax; Aufrufer-Modus 3; deklariert 3x1
int f_16adb6(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert -
int f_16af3a(int, int, int);                 // sicher; liest edx ebx; deklariert -
int f_16b2b3(int);                           // sicher; liest eax; deklariert -
int f_16b433(int);                           // sicher; liest eax; deklariert 1x1
int f_16b484(int);                           // sicher; liest eax; deklariert 1x1
int f_16b4ae(int);                           // sicher; liest eax; deklariert 1x1
int f_16b52c(int);                           // sicher; liest eax; deklariert 3x1
int f_16b54a(int);                           // sicher; liest eax; deklariert -
int f_16b568(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x1
int f_16b60c(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_16b930(int);                           // sicher; liest eax; deklariert 1x9
int f_16b984(int, int);                      // sicher; liest eax edx; deklariert -
int f_16b9f4(int, int);                      // sicher; liest eax edx; deklariert -
int f_16ba64(int, int);                      // sicher; liest eax edx; deklariert -
int f_16bad4(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_16bc24(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_16bc6c(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_16bcb4(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_16bd00(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_16bd4c(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_16bd98(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_16c138(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_16c24c(int, int);                      // sicher; liest eax edx; deklariert -
int f_16c544(int, int);                      // sicher; liest eax edx; deklariert -
int f_16c73c(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_16cb64(int);                           // sicher; liest eax; deklariert -
int f_16cb84(int, int);                      // sicher; liest eax edx; deklariert -
int f_16cbdc(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_16cc44(int, int);                      // sicher; liest eax edx; deklariert 2x8
int f_16ccac(int, int);                      // sicher; liest eax edx; deklariert 2x7
int f_16cd48(int);                           // sicher; liest eax; deklariert -
int f_16cd74(int);                           // sicher; liest eax; deklariert 4x7
int f_16cda0(int);                           // sicher; liest eax; deklariert -
int f_16cf00(int);                           // sicher; liest eax; deklariert 1x1
int f_16cf05(int);                           // sicher; liest eax; deklariert 1x1
int f_16cf6a(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x7
int f_16cff5(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_16d077(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_16d295(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x6
int f_16d2c9(int);                           // sicher; liest eax; deklariert 1x7
int f_16d33f(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x8
int f_16d34f(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_16d3b7(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x7
int f_16d4d8(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 2x1 4x6
int f_16d4fc(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 2x1 3x1
int f_16d529(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16d7e7(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 1x1 4x6
int f_16d818(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16d87b(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16d8ad(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 2x2 4x5
int f_16dd11(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_16e00c(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert -
int f_16e060(int);                           // sicher; liest eax; deklariert 1x1
int f_16e660(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_16e93c(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert 6x6
int f_16ecb4(int);                           // sicher; liest eax; deklariert 1x6
int f_16ecba(int);                           // sicher; liest eax; deklariert 1x6
int f_16ecc0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_16f086(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_16f4f5(int);                           // sicher; liest eax; deklariert -
int f_16f693(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x5 5x1
int f_16f830(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_16f867(int, int, int, int);            // sicher; liest ecx; deklariert -
int f_16f992(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_16fc19(int, int, int, int);            // sicher; liest edx ecx; deklariert 0x3 4x4
int f_16ff04(int);                           // sicher; liest eax; deklariert -
int f_16ff84(int);                           // sicher; liest eax; deklariert -
int f_17004c(int, int, int);                 // sicher; liest eax ebx; deklariert -
int f_1702b8(int);                           // sicher; liest eax; deklariert 1x6
int f_1707f8(int, int);                      // sicher; liest eax edx; deklariert -
int f_1708f4(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_170af4(int, int);                      // sicher; liest eax edx; deklariert -
int f_170cb8(int);                           // sicher; liest eax; deklariert -
int f_170e84(int, int);                      // sicher; liest eax edx; deklariert -
int f_171000(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_171180(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_171994(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_1719e4(int, int);                      // sicher; liest eax edx; deklariert -
int f_171c20(int, int);                      // sicher; liest eax edx; deklariert -
int f_171f14(int, int);                      // sicher; liest eax edx; deklariert -
int f_172028(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_172148(int, int);                      // sicher; liest eax edx; deklariert 2x6
int f_172378(int, int);                      // sicher; liest eax edx; deklariert -
int f_1724d8(int, int);                      // sicher; liest eax edx; deklariert -
int f_172628(int);                           // sicher; liest eax; deklariert 1x6
int f_17272c(int);                           // sicher; liest eax; deklariert -
int f_172870(int);                           // sicher; liest eax; deklariert -
int f_172bdc(int);                           // sicher; liest eax; deklariert -
int f_1735c4(int, int);                      // sicher; liest edx; deklariert -
int f_1737c4(int);                           // sicher; liest eax; deklariert -
int f_1739e8(int);                           // sicher; liest eax; deklariert -
int f_173d0c(int);                           // sicher; liest eax; deklariert -
int f_174158(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_1744c8(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17464c(int);                           // sicher; liest eax; deklariert 1x6
int f_175127(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_1751d3(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_175322(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_1753a5(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_175839(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_1758bc(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_176784(int);                           // sicher; liest eax; deklariert -
int f_17684a(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1768b3(int, int);                      // sicher; liest edx; deklariert -
int f_176a38(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_176b18(int, int);                      // sicher; liest eax edx; deklariert -
int f_176b3c(int, int);                      // sicher; liest eax edx; deklariert -
int f_176d78(int);                           // sicher; liest eax; deklariert -
int f_176e24(int, int);                      // sicher; liest eax edx; deklariert -
int f_176f10(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x8
int f_1771c2(int, int);                      // sicher; liest eax edx; deklariert 0x1
int f_177260(int);                           // sicher; liest eax; deklariert -
int f_177910(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_1782e8(int);                           // sicher; liest eax; deklariert 1x7
int f_178334(int, int, int, int);            // sicher; liest eax edx ecx; deklariert -
int f_1783f7(int);                           // sicher; liest eax; deklariert -
int f_17854b(int, int, int, int, int, int, int); // vermutet (sicher 3); liest eax edx ebx; ret 12?; deklariert -
int f_1786fa(int, int, int);                 // sicher; liest ebx; deklariert -
int f_178c64(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_178ee6(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_179001(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_179170(int);                           // sicher; liest eax; deklariert -
int f_1791bb(int, int);                      // sicher; liest eax edx; deklariert -
int f_1792b0(int);                           // sicher; liest eax; deklariert -
int f_179307(int);                           // sicher; liest eax; deklariert -
int f_179338(int);                           // sicher; liest eax; deklariert -
int f_179411(int);                           // sicher; liest eax; deklariert -
int f_179488(int, int, int);                 // sicher; liest eax ebx; deklariert -
int f_1794a7(int);                           // sicher; liest eax; deklariert 1x1
int f_179530(int);                           // sicher; liest eax; deklariert -
int f_17955f(int);                           // sicher; liest eax; deklariert -
int f_179611(int);                           // sicher; liest eax; deklariert -
int f_179732(int);                           // sicher; liest eax; deklariert -
int f_179739(int, int);                      // sicher; liest edx; deklariert -
int f_179741(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_179988(int, int);                      // sicher; liest eax edx; deklariert -
int f_179a7d(int);                           // sicher; liest eax; deklariert -
int f_179abc(int, int);                      // sicher; liest eax edx; deklariert -
int f_179b51(int, int, int, int);            // sicher; liest eax edx ecx; deklariert -
int f_179c74(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_179cd2(int, int);                      // sicher; liest eax edx; deklariert -
int f_179d15(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_179e0f(int, int);                      // sicher; liest eax edx; deklariert -
int f_17a126(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_17a316(int);                           // sicher; liest eax; deklariert -
int f_17a33d(int);                           // sicher; liest eax; deklariert -
int f_17a40c(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17a6a0(int, int, int, int, int);       // vermutet (sicher 0); ret 4?; deklariert -
int f_17a811(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17a891(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_17aaec(int);                           // sicher; liest eax; deklariert -
int f_17b260(int);                           // sicher; liest eax; deklariert -
int f_17b4d0(int);                           // sicher; liest eax; deklariert 1x1
int f_17b4e0(int);                           // sicher; GLEICH-Def fz_17a940:1; deklariert 1x1
int f_17b5c1(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17b6d0(int, int);                      // sicher; liest eax edx; deklariert -
int f_17b6fb(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_17b75f(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17b7a9(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17b837(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 1x1
int f_17b87d(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 2x1
int f_17b938(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 0x1
int f_17b964(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 0x1
int f_17b990(int, int, int, int);            // sicher; liest eax ebx ecx; deklariert 0x1
int f_17ba0c(int);                           // sicher; liest eax; deklariert 0x1
int f_17ba7b(int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 12; deklariert 7x1
int f_17bc5d(int);                           // sicher; liest eax; deklariert 1x2
int f_17bd4d(int);                           // sicher; liest eax; deklariert 1x1
int f_17bdb1(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_17be61(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_17befd(int, int, int, int);            // sicher; liest ebx ecx; deklariert 2x1
int f_17bf3a(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17bf77(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c023(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c059(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_17c0b6(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 3x1
int f_17c0ec(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x1
int f_17c151(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c1ad(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x1
int f_17c1d0(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c1f3(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c237(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c290(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c2c0(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x1
int f_17c2e3(int, int, int, int);            // sicher; liest ebx ecx; deklariert 10x1
int f_17c318(int, int, int, int);            // sicher; liest ebx ecx; deklariert 6x1
int f_17c341(int, int, int, int);            // sicher; liest ebx ecx; deklariert 5x1
int f_17c367(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x1
int f_17c3b8(int, int, int, int);            // sicher; liest ebx ecx; deklariert 1x1
int f_17c3ed(int, int, int, int);            // sicher; liest ebx ecx; deklariert 1x1
int f_17c422(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c461(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c4ab(int, int, int, int);            // sicher; liest ebx ecx; deklariert -
int f_17c50c(int, int, int, int);            // sicher; liest ebx ecx; deklariert 0x1
int f_17c529(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 3x1
int f_17c56a(int, int, int, int);            // sicher; liest ebx ecx; deklariert 2x1
int f_17c598(int, int, int, int);            // sicher; liest ebx ecx; deklariert 1x1
int f_17c604(int, int, int, int);            // sicher; liest ebx ecx; deklariert 1x1
int f_17c651(int, int, int, int);            // sicher; liest ebx ecx; deklariert 1x1
int f_17c6b1(int, int, int, int);            // sicher; liest ebx ecx; deklariert 4x1
int f_17c6e0(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 3x1
int f_17c709(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert 1x1
int f_17d2a8(int, int);                      // sicher; liest eax edx; deklariert -
int f_17d2d6(int, int);                      // sicher; liest eax edx; deklariert -
int f_17d2f7(int);                           // sicher; liest eax; deklariert -
int f_17d2fc(int);                           // sicher; liest eax; deklariert -
int f_17d381(int);                           // sicher; liest eax; deklariert -
int f_17d43c(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17d4d8(int, int);                      // sicher; liest edx; deklariert -
int f_17d4ff(int);                           // sicher; liest eax; deklariert -
int f_17d515(int, int);                      // sicher; liest eax edx; deklariert -
int f_17d53b(int);                           // sicher; liest eax; deklariert -
int f_17d549(int);                           // sicher; liest eax; deklariert -
int f_17d72a(int, int);                      // sicher; liest eax edx; deklariert -
int f_17d788(int);                           // sicher; liest eax; deklariert -
int f_17d7ad(int);                           // sicher; liest eax; deklariert -
int f_17d803(int, int);                      // sicher; liest eax edx; deklariert -
int f_17d988(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17d9c1(int, int);                      // sicher; liest eax edx; deklariert -
int f_17da1a(int, int);                      // sicher; liest eax edx; deklariert -
int f_17db49(int);                           // sicher; liest eax; deklariert -
int f_17dbb2(int);                           // sicher; liest eax; deklariert -
int f_17df27(int);                           // sicher; liest eax; deklariert -
int f_17e055(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_17e147(int, int, int, int, int, int);  // sicher; liest eax edx ebx ecx; ret 8; deklariert -
int f_17e217(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_17e332(int, int);                      // sicher; liest edx; deklariert -
int f_17e465(int);                           // sicher; liest eax; deklariert -
int f_17e6c0(int, int, int, int, int, int, int); // sicher; GLEICH-Def fz_17e4a0_t1:7; deklariert 7x2
int f_17e6fc(int, int, int, int, int, int, int); // sicher; GLEICH-Def fz_17e4a0_t1:7; deklariert 7x2
int f_180330(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert 4x2
int f_1803e4(int);                           // sicher; liest eax; deklariert 1x2
int f_187bdc(int);                           // sicher; liest eax; deklariert 1x1
int f_187c18(int, int);                      // sicher; liest eax edx; deklariert -
int f_187c4c(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_187ca0(int, int);                      // sicher; liest eax edx; deklariert -
int f_187ce0(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_187d10(int, int);                      // sicher; liest eax edx; deklariert -
int f_187d54(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_187d94(int, int);                      // sicher; liest eax edx; deklariert -
int f_187dcc(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_187e30(int);                           // sicher; liest eax; deklariert -
int f_187e44(int, int);                      // sicher; liest eax edx; deklariert -
int f_187eb0(int);                           // sicher; liest eax; deklariert -
int f_187ec4(int);                           // sicher; liest eax; deklariert -
int f_187ecc(int, int);                      // sicher; liest eax edx; deklariert -
int f_187f2c(int);                           // sicher; liest eax; deklariert -
int f_188260(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1882cc(int, int);                      // sicher; liest eax edx; deklariert -
int f_1883e0(int);                           // sicher; liest eax; deklariert -
int f_188404(int, int, int);                 // sicher; liest eax edx ebx; deklariert 3x4
int f_188490(int);                           // sicher; liest eax; deklariert -
int f_18850c(int);                           // sicher; liest eax; deklariert 1x4
int f_1885c8(int);                           // sicher; liest eax; deklariert 1x1
int f_188664(int, int);                      // sicher; liest eax edx; deklariert -
int f_188c94(int, int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 20; deklariert -
int f_188d48(int);                           // sicher; liest eax; deklariert -
int f_188ec4(int, int);                      // sicher; liest eax edx; deklariert -
int f_189284(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert -
int f_189a0c(int, int);                      // sicher; liest eax edx; deklariert -
int f_189a74(int, int);                      // sicher; liest eax edx; deklariert -
int f_189df8(int);                           // sicher; liest eax; deklariert -
int f_189e01(int, int);                      // sicher; liest eax edx; deklariert -
int f_189e39(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18a031(int);                           // sicher; liest eax; deklariert -
int f_18a06c(int, int);                      // sicher; liest eax edx; deklariert -
int f_18a151(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_18a185(int);                           // sicher; liest eax; deklariert -
int f_18a448(int, int);                      // sicher; liest eax edx; deklariert -
int f_18a478(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18a58d(int, int);                      // sicher; liest eax edx; deklariert -
int f_18a624(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_18a669(int, int);                      // sicher; liest eax edx; deklariert -
int f_18a68d(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_18a7b6(int, int);                      // sicher; liest eax edx; deklariert -
int f_18a988(int, int);                      // sicher; liest edx; deklariert -
int f_18a992(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18ab57(int, int);                      // sicher; liest eax edx; deklariert -
int f_18b1e0(int, int, int, int);            // sicher; liest eax ecx; deklariert -
int f_18c6e6(int, int, int);                 // vermutet (sicher 2); liest edx; R106 ebx; deklariert -
int f_18c6f4(int, int, int);                 // vermutet (sicher 2); liest eax edx; R106 ebx; deklariert -
int f_18c71e(int, int, int, int, int, int, int); // vermutet (sicher 1); liest eax; ret 12?; deklariert -
int f_18c74e(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18c8ba(int, int);                      // sicher; liest eax edx; deklariert -
int f_18c953(int, int, int);                 // vermutet (sicher 2); liest eax edx; R106 ebx; deklariert -
int f_18c97d(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18cb28(int, int, int);                 // vermutet (sicher 2); liest eax edx; R106 ebx; deklariert -
int f_18cb52(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18cca8(int, int, int, int);            // sicher; liest eax ecx; deklariert -
int f_18cd12(int, int);                      // sicher; liest eax edx; deklariert -
int f_18cd23(int, int, int, int);            // sicher; liest eax edx ecx; deklariert -
int f_18cd58(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_18cdd8(int);                           // sicher; liest eax; deklariert -
int f_18ce57(int);                           // sicher; liest eax; deklariert -
int f_18cf1e(int, int);                      // sicher; liest eax edx; deklariert -
int f_18d170(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_18d226(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_18d389(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18d3ef(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18d46a(int);                           // sicher; liest eax; deklariert -
int f_18d558(int);                           // sicher; liest eax; deklariert -
int f_18d571(int, int);                      // sicher; liest edx; deklariert -
int f_18d5b4(int);                           // sicher; liest eax; deklariert -
int f_18da90(int);                           // sicher; liest eax; deklariert -
int f_18dc64(int);                           // sicher; liest eax; deklariert -
int f_18dd50(int, int, int, int);            // sicher; liest ecx; deklariert -
int f_18dda2(int);                           // sicher; liest eax; deklariert -
int f_18ddea(int, int);                      // sicher; liest eax edx; deklariert -
int f_18debe(int, int);                      // sicher; liest eax edx; deklariert -
int f_18df18(int);                           // sicher; liest eax; deklariert -
int f_18e061(int);                           // sicher; liest eax; deklariert -
int f_18e0d6(int);                           // sicher; liest eax; deklariert 1x1
int f_18e0e6(int, int);                      // sicher; liest eax edx; deklariert -
int f_18e187(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_18e380(int);                           // sicher; GLEICH-Def fz_18e380:1; deklariert 1x1
int f_18e3b8(int);                           // sicher; GLEICH-Def fz_18e380:1; deklariert 1x1
int f_18e60c(int, int);                      // sicher; GLEICH-Def fz_18e380:2; deklariert 2x1
int f_18e628(int);                           // sicher; GLEICH-Def fz_18e380:1; deklariert 1x1
int f_18ebb4(int, int, int);                 // sicher; liest ebx; deklariert 5x1
int f_18ec98(int, int, int);                 // sicher; liest ebx; deklariert 7x1
int f_18edc1(int, int, int);                 // sicher; liest ebx; deklariert 9x1
int f_18ee19(int, int, int);                 // sicher; liest ebx; deklariert 6x1
int f_18ee5e(int, int, int);                 // sicher; liest ebx; deklariert 4x1
int f_18f228(int);                           // sicher; liest eax; deklariert 1x1
int f_192dc1(int, int);                      // sicher; liest eax edx; deklariert -
int f_19300f(int);                           // sicher; liest eax; deklariert -
int f_19303c(int);                           // sicher; liest eax; deklariert -
int f_19304b(int, int);                      // sicher; liest eax edx; deklariert -
int f_193543(int, int);                      // sicher; liest eax edx; deklariert -
int f_1935c9(int);                           // sicher; liest eax; deklariert -
int f_1935f8(int, int, int, int, int, int, int); // vermutet (sicher 3); liest eax edx ebx; ret 12?; deklariert -
int f_1936b1(int, int);                      // sicher; liest eax edx; deklariert -
int f_19373e(int, int);                      // sicher; liest eax edx; deklariert -
int f_193782(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert -
int f_1937e5(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_193977(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_193a50(int, int, int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 24; deklariert -
int f_193c0d(int, int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 20; deklariert -
int f_193ca0(int, int);                      // sicher; liest edx; deklariert -
int f_193e23(int);                           // sicher; liest eax; deklariert -
int f_194344(int, int, int, int, int, int);  // vermutet (sicher 0); ret 8?; deklariert -
int f_1954d0(int, int);                      // sicher; GLEICH-Def fz_194430:2; deklariert 2x1
int f_195508(int, int);                      // sicher; GLEICH-Def fz_194430:2; deklariert 2x1
int f_195514(int, int, int, int, int, int, int); // sicher; GLEICH-Def fz_194430:7; deklariert 7x1
int f_195550(int, int, int, int, int, int, int); // sicher; GLEICH-Def fz_194430:7; deklariert 7x1
int f_195590(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x2
int f_195790(int);                           // sicher; GLEICH-Def fz_194430:1; deklariert 1x1
int f_1957a4(int);                           // sicher; liest eax; deklariert 1x3
int f_1957b8(int);                           // sicher; GLEICH-Def fz_194430:1; deklariert 1x1
int f_1957c9(int, int);                      // sicher; liest eax edx; deklariert -
int f_195bbc(int, int);                      // sicher; liest eax edx; deklariert -
int f_195ce8(int, int);                      // sicher; liest eax edx; deklariert -
int f_196280(int, int);                      // sicher; liest eax edx; deklariert -
int f_1968cf(int);                           // sicher; liest eax; deklariert 1x1
int f_196936(int, int);                      // sicher; liest eax edx; deklariert -
int f_19697e(int);                           // sicher; liest eax; deklariert -
int f_1969b3(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_196a56(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_196ab9(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_196b2a(int, int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 20; deklariert -
int f_196d64(int, int, int, int);            // sicher; liest eax edx ebx ecx; deklariert -
int f_196f46(int, int, int);                 // sicher; liest eax ebx; deklariert -
int f_196fd3(int, int, int);                 // sicher; liest ebx; deklariert -
int f_197025(int, int, int);                 // sicher; liest ebx; deklariert -
int f_19704b(int, int, int);                 // sicher; liest ebx; deklariert -
int f_197070(int, int, int);                 // sicher; liest ebx; deklariert -
int f_19710e(int);                           // sicher; liest eax; deklariert -
int f_197159(int, int);                      // sicher; liest eax edx; deklariert -
int f_1971aa(int, int, int, int, int, int, int, int); // sicher; liest eax edx ebx ecx; ret 16; deklariert -
int f_1971eb(int, int, int, int, int, int, int); // vermutet (sicher 1); liest eax; ret 12?; deklariert -
int f_197308(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_197390(int, int);                      // sicher; GLEICH-Def fz_197390:2; deklariert 2x4
int f_1973ec(int, int);                      // sicher; GLEICH-Def fz_197390:2; deklariert 2x1
int f_197448(int, int, int, int);            // sicher; GLEICH-Def fz_197390:4; deklariert 4x1
int f_19749b(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_197510(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1977a4(int, int, int, int, int);       // sicher; liest eax edx ebx ecx; ret 4; deklariert 5x1
int f_1979c0(int);                           // sicher; liest eax; deklariert 1x1
int f_197a40(int);                           // sicher; liest eax; deklariert 1x1
int f_197ac0(int);                           // sicher; liest eax; deklariert 1x1
int f_197c88(int);                           // sicher; liest eax; deklariert 1x1
int f_197e18(int);                           // sicher; liest eax; deklariert 1x1
int f_197e98(int);                           // sicher; liest eax; deklariert 1x1
int f_197fb8(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_19803c(int);                           // sicher; liest eax; deklariert 1x1
int f_198574(int);                           // sicher; liest eax; deklariert 1x1
int f_1987fc(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_1988bc(int);                           // sicher; liest eax; deklariert 1x1
int f_198978(int);                           // sicher; liest eax; deklariert 1x1
int f_1989e4(int);                           // sicher; liest eax; deklariert 1x1
int f_198a48(int, int);                      // sicher; liest eax edx; deklariert 2x1
int f_198d23(int);                           // sicher; liest eax; deklariert -
int f_198d42(int, int, int, int, int, int, int); // vermutet (sicher 0); ret 12?; deklariert -
int f_198dd4(int, int);                      // sicher; liest edx; deklariert -
int f_198e43(int, int, int, int, int, int);  // vermutet (sicher 3); liest eax edx ebx; ret 8?; deklariert -
int f_198e7f(int, int, int, int, int, int, int, int, int, int, int); // vermutet (sicher 4); liest edx ebx ecx; ret 28?; deklariert -
int f_19905c(int, int, int);                 // sicher; liest ebx; deklariert -
int f_19914c(int, int, int);                 // sicher; liest ebx; deklariert -
int f_199192(int, int, int);                 // sicher; liest ebx; deklariert -
int f_19927e(int);                           // sicher; liest eax; deklariert -
int f_1992e9(int, int, int);                 // sicher; liest eax edx ebx; deklariert -
int f_199410(int, int, int);                 // vermutet (sicher 1); liest eax; Aufrufer-Modus 3; deklariert 1x2
int f_199484(int);                           // sicher; GLEICH-Def fz_199410:1; deklariert 1x2
int f_1995bc(int, int, int, int, int, int, int); // vermutet (sicher 3); liest eax edx ebx; ret 12?; deklariert -
int f_1995f8(int, int, int, int, int, int, int); // vermutet (sicher 0); ret 12?; deklariert -
int f_199611(int, int, int, int, int, int, int); // vermutet (sicher 0); ret 12?; deklariert -
int f_1997a0(int, int);                      // sicher; liest edx; deklariert -
int f_199a90(int, int);                      // sicher; liest edx; deklariert -
int f_199b00(int, int);                      // sicher; liest eax edx; deklariert -
int f_199ba0(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_199ee0(int);                           // sicher; liest eax; deklariert -
int f_199f10(int);                           // sicher; liest eax; deklariert -
int f_19c820(int, int, int);                 // sicher; liest edx ebx; deklariert -
int f_19cbf0(int, int, int);                 // sicher; liest ebx; deklariert -
int f_19d420(int, int, int, int);            // sicher; liest edx ecx; deklariert -
int f_19d440(int, int, int, int);            // sicher; liest edx ebx ecx; deklariert -
int f_19d560(int, int, int);                 // sicher; liest edx ebx; deklariert -
#endif // RIVA_KOEPFE_GENERISCH
#endif
