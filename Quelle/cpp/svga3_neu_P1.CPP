// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 11e9a0-11ea00 aus Quelle/cpp/SVGA3.CPP; erster Entwurf, Einbau separat prüfen.
// svga.cpp Teil 3 (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026 mit der Variantenmaschine
// Code 0x11E9A0-0x11E9F6 (danach Nullbytes bis 0x11EA00 = Modulende), wpp386 -4r -oneatx -zp1 -s
// Zugriffsfunktionen der Grafik und Modus setzen. Namen f_<Adresse> bis Phase 6.
unsigned short f_13e580();
extern short d_1c0aa0[32];
void f_13e3a0();
short __pascal f_13f8d0(unsigned char c);
short f_13f8c0();
void f_13efd0(int a, int b, int c, short d, short e);
//@ f_11e9a0
int f_11e9a0() { return f_13e580(); }
//@ f_11e9b0
short *f_11e9b0() { return d_1c0aa0; }
void (*f_11e9c0())() { return f_13e3a0; }
//@ f_11e9d0
void __pascal f_11e9d0(unsigned char c)
{
    f_13efd0(0, 0, 0, f_13f8c0(), f_13f8d0(c));
}
