// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 091c00-091ea0 aus Quelle/cpp/GAME.CPP; erster Entwurf, Einbau separat prüfen.
// game.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x091C00-0x091EA0 (Sprungtabelle 0x091BD0 davor, R35). Hauptschleife: Spielmodus abfragen und Bildschirme starten.
extern const short d_1a28ec[6] = {1000, 100, 300, 100, 0, 0};   // 0x1A28EC
extern const char d_1a28f8[];
#define game_file d_1a28f8
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
struct Game;
extern Game *d_1c0004;
short f_0de800(Game *g);
short f_0de820(Game *g);
struct Msg { void f_0bf730(long code); };
extern Msg d_1c2c64;
struct Scr { Scr(); ~Scr();   // Konstruktor und Destruktor liegen beide bei 0x059D50 (leer, nur ret)
     int f_05b860(int a); char pad[0x652]; };
struct Obj2 { int x; };
extern Obj2 d_1bf230;
int f_0bba10(Obj2 *o);
extern short d_1c21a4;
extern signed char d_1bcacc;
extern signed char d_1bfb1c;
extern long d_1a34e0;
extern int d_1c0c94;
extern short d_1c219c;
extern int d_1bdb94;
extern int d_1c2a80;
extern short d_1bd90c;
void f_09a0d0(long a);
void f_092b90();
void f_09a400();
void f_0b9280();
void f_1216f0();
void f_053ab0(const short *t);
void f_0405e0();
void f_046bf0();
void f_09a140(int a, int b);
void f_0d2710();
void f_0f2720(int a);
void f_0d26e0();
void f_03ebb0();
inline signed char fb() { return d_1bfb1c; }
//@ f_091c00
void f_091c00()
{
    Scr *o;
    d_1c21a4 = 0;
    while (d_1c21a4 == 0) {
        if ((d_1bcacc == 1) != 0) {
            f_09a0d0(d_1a34e0);
            f_092b90();
            f_09a400();
            d_1c21a4 = 4;
        }
        if (d_1c21a4 == 0) {
            if (fb() == 0) d_1c0c94 = 1;
            if (f_0de800(d_1c0004) != -1) f_0b9280();
            else if (f_0de820(d_1c0004) != -1) f_1216f0();
            else f_053ab0(d_1a28ec);
            if (d_1c219c != (short)0) f_0405e0();
            if (d_1bdb94 == 1) {
                if (f_0bba10(&d_1bf230) == 1 || (d_1c2a80 == 0 && fb() == 1)) {
                    if (d_1bd90c == 0) {
                        if (d_1c21a4 == 0 || d_1c21a4 == (short)1) {
                            if (f_0de800(d_1c0004) == -1) {
                                f_046bf0();
                                d_1bdb94 = 0;
                            }
                        }
                    }
                }
            }
        }
        if (d_1c21a4 != 0) {
            switch (d_1c21a4) {
            case 2: case 7: case 8: case 9: case 10: case 11:
                f_03ebb0();
                break;
            case 3:
                d_1c2c64.f_0bf730(0x200001b0);
                break;
            case 1:
                f_09a140(0, 25);
                f_0d2710();
                f_09a0d0(d_1a34e0);
                f_0f2720(16);
                f_092b90();
                f_09a400();
                f_0d26e0();
                d_1bcacc = 1;
                break;
            }
            switch (d_1c21a4) {
            case 3: case 4: case 7: case 8: case 9: case 10: case 11: {
                o = new (mark(game_file, 203)) Scr;
                if (o->f_05b860(1)) d_1c21a4 = 0;
                delete o;
                break;
            }
            case 1: {
                o = new (mark(game_file, 215)) Scr;
                if (o->f_05b860(0)) d_1c21a4 = 0;
                delete o;
                break;
            }
            }
        }
    }
}
