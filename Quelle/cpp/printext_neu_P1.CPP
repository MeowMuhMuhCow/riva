// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0e9360-0e93f0 aus Quelle/cpp/PRINTEXT.CPP; erster Entwurf, Einbau separat prüfen.
// printext.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle
// Code 0x0E9360-0x0E93F0. Text zu einem Eintrag erzeugen (500-Byte-Puffer) und mit Vorgabe vergleichen.
#include <string.h>
extern const char d_1a65dc[];
#define printext_file d_1a65dc
void *f_014540(long size, const char *file, int line);   // Speicher mit Herkunft
void operator delete(void *p);                           // 0x014710
struct Entry;
struct List { int f_134010(int id); Entry *f_134030(int id); };
struct Pool { Entry *f_099b10(int id); };
struct World { char pad[0x34]; Pool *pool; };
extern World *d_1c0c48;
struct PrintExt {
    char pad[0x48];
    List *list;                                          // +0x48
    int f_0e9360(const char *text, int id);
    void f_0e9450(char *buf, Entry *e);
};
//@ f_0e9360
int PrintExt::f_0e9360(const char *text, int id)
{
    int found = 0;
    char *buf = (char *)f_014540(500, printext_file, 76);
    Entry *e;
    if (list->f_134010(id) == 1) e = list->f_134030(id);
    else e = d_1c0c48->pool->f_099b10(id);
    if (e) {
        f_0e9450(buf, e);
        if (strcmp(buf, text) == 0) found = 1;
    }
    delete buf;
    return found;
}
