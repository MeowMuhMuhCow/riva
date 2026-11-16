// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 01e110-01e240 aus Quelle/cpp/ARYLIST.CPP; erster Entwurf, Einbau separat pr�fen.
// arylist.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x01E110-0x01E240. Feldliste: Zeigertabelle um 50 Plätze und Datenpuffer in 16-KB-Schritten vergrößern.
#include <string.h>
extern const char d_1a04d8[];
#define arylist_file d_1a04d8
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
struct AryList {
    unsigned short err;                                  // +0x00
    unsigned short count;                                // +0x02
    unsigned short cap;                                  // +0x04
    unsigned long used;                                  // +0x06 belegte Bytes im Puffer
    unsigned long size;                                  // +0x0A Puffergröße
    unsigned short esize;                                // +0x0E Größe eines Elements
    char pad[0x0e];
    void **tab;                                          // +0x1E
    char *buf;                                           // +0x22
    void f_01e110();
    void f_01e1a0(int n);
};
//@ f_01e110
void AryList::f_01e110()
{
    err = 0;
    if (count == cap) {
        unsigned n = cap * sizeof(void *);
        void **p = (void **)new (mark(arylist_file, 90)) char[n + 200];
        if (p == 0) err = 0x401;
        else {
            if (tab) {
                memcpy(p, tab, n);
                delete tab;
                tab = 0;
            }
            tab = p;
            cap += 50;
        }
    }
}
//@ f_01e1a0
void AryList::f_01e1a0(int n)
{
    unsigned long need = esize * n;
    err = 0;
    while (err == 0 && used + need > size) {
        unsigned long s = size;
        unsigned long t = s + 0x4000;
        char *p = new (mark(arylist_file, 150)) char[t];
        if (p == 0) err = 0x401;
        else {
            if (buf) {
                memcpy(p, buf, s);
                delete buf;
                buf = 0;
            }
            buf = p;
            size += 0x4000;
        }
    }
}
