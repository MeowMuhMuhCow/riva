// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 01e0c0-01e110 aus Quelle/cpp/G01E0C0.CPP; erster Entwurf, Einbau separat prüfen.
// gz_01e0c0.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x01E0C0-0x01E110. Globales Objekt d_1bc760 abbauen (Zustand 2, freigeben); Dreibyte-Nuller.
struct Ani { char pad[0x35]; short state; };
void f_01cf10(Ani *a);
void operator delete(void *p);   // 0x014710
extern Ani *d_1bc760;            // BSS 0x1BC760-0x1BC768
//@ f_01e0c0
void f_01e0c0()
{
    d_1bc760->state = 2;
    f_01cf10(d_1bc760);
    Ani *t = d_1bc760; if (t) { f_01cf10(t); delete t; }
    d_1bc760 = 0;
}
//@ f_01e100
void f_01e100(char *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}
