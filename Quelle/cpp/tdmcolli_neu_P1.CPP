/* === Beschreibung (Katalog) ===
 * Einheit tdmcolli_neu (0x11F790 - 0x11F910)
 *
 * Überblick
 * Die Einheit tdmcolli_neu enthält zwei Funktionen der 3D-Dungeon-Kollisions- und Ereignisbehandlung
 * (tdmcolli.cpp): die Auswertung von Zonenwechseln und Auslösern im 3D-Dungeon (f_11f790) sowie eine Abfrage auf
 * einen speziellen Questzustand in den Dungeons 23 bis 25 (f_11f8d0).
 === Ende Beschreibung === */
// tdmcolli.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Welle 1
// Code 0x11F790-0x11F90F. Namen f_/d_<Adresse> bis Phase 6, Globale bis Phase 2 extern.
// d_1c0b30: volatile (Original liest sie bei jedem Zugriff neu aus dem Speicher)
struct Game;
extern Game *d_1c0004;
short          f_0de800(Game *g);
unsigned short f_0de820(Game *g);
short          f_0de950(Game *g);
void           f_0de930(Game *g, int x);
void           f_0de960(Game *g, int x);
signed char    f_0dd410(Game *g, int x);
void           f_1223c0();

struct Lock {                                            // lokales Objekt mit Konstruktor/Destruktor
    Lock();                                              // 0x0CE7C0
    ~Lock();                                             // 0x0CE7E0
    int x;
};
struct View {
    long a, b;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(int n);                              // Tabelle +0x24
};
extern View *d_1bd6c0;
extern volatile int d_1c0b30;
extern int   d_1c0ae4;
extern short d_1a7f78, d_1a7f7a;
extern short d_1bd6c4;
extern signed char d_1bfb1c;
extern int   d_1c2a80;

inline int f_flag() { return d_1bfb1c == 1; }

void f_11f790()
{
    int   changed = 0;
    short arg;
    short old = f_0de800(d_1c0004);
    if (d_1c0b30 == 1) d_1a7f78 = d_1a7f7a;
    d_1a7f7a = f_0de950(d_1c0004);
    if (d_1c0b30 == 1 && d_1c0ae4 == 0 && d_1a7f7a != d_1a7f78 && d_1a7f7a != -1) {
        f_0de930(d_1c0004, 1);
        d_1c0b30 = 0;
        arg = d_1a7f7a;
        changed = 1;
    }
    if (d_1c0ae4 == 1) {
        if (d_1a7f7a != -1) {
            arg = d_1a7f7a;
            changed = 1;
            f_1223c0();
        }
        f_0de930(d_1c0004, 1);
        d_1c0ae4 = 0;
        f_0de960(d_1c0004, 0);
    }
    if (d_1bd6c4 != 0) {
        changed = 1;
        arg = d_1bd6c4;
        d_1bd6c4 = 0;
    }
    if (changed == 1) {
        {
            Lock lock;
            d_1bd6c0->v9(arg);
        }
        if (f_0de800(d_1c0004) != old && f_flag()) d_1c2a80 = 0;
    }
}

int f_11f8d0()
{
    int r = 0;
    switch (f_0de820(d_1c0004)) {
    case 23: case 24: case 25:
        if (f_0dd410(d_1c0004, 1) == 5) r = 1;
        break;
    }
    return r;
}
