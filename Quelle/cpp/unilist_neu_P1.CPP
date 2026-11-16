// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 134050-1340e0 aus Quelle/cpp/UNILIST.CPP; erster Entwurf, Einbau separat pr�fen.
// unilist.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle
// Code 0x134050-0x1340E0. Universelle Liste: Platz um 50 Einträge vergrößern.
#include <string.h>
extern const char d_1a8e08[];
#define unilist_file d_1a8e08
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
struct UniList {
    short err;                                           // +0x00
    unsigned short count;                                // +0x02
    unsigned short cap;                                  // +0x04
    unsigned short size;                                 // +0x06 Größe eines Eintrags
    char pad[10];
    char *data;                                          // +0x12
    void f_134050();
};
//@ f_134050
void UniList::f_134050()
{
    err = 0;
    if (count == cap) {
        unsigned n = cap * size;
        unsigned t = n + size * 50;
        char *p = new (mark(unilist_file, 83)) char[t];
        if (p == 0) err = 0x401;
        else {
            if (data) {
                memcpy(p, data, n);
                delete data;
                data = 0;
            }
            data = p;
            cap += 50;
        }
    }
}
