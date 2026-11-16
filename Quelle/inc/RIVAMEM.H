/* D23: belegte Speicher-Schnittstelle 014ab0/014ac0/014b10/014710.
 * Keine Code-Pragmas; normale Watcom-C++-Deklarationen. */
#ifndef RIVAMEM_H
#define RIVAMEM_H
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void *operator new[](unsigned size, void *tag);
void operator delete(void *p);
#endif
