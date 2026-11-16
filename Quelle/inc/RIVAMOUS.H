/* D23: Mauswache. 0d3860 fragt den Zustand ab;
 * 0d2710 verbirgt, 0d26e0 stellt die vorher sichtbare Maus wieder her.
 * void-Vertraege aus mosaic, nicht die alten geratenen int-Prototypen. */
#ifndef RIVAMOUS_H
#define RIVAMOUS_H
void f_0d26e0(void);
void f_0d2710(void);
int f_0d3860(void);
struct RivaMouseGuard {
    int fl;
    RivaMouseGuard() { if (f_0d3860()==1) { f_0d2710(); fl=1; } else { fl=0; } }
    ~RivaMouseGuard() { if (fl==1) f_0d26e0(); }
};
#endif
