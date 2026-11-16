// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 11e960-11e9a0 aus Quelle/cpp/SVGA.CPP; erster Entwurf, Einbau separat prüfen.
// svga.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Paket 4.23
// Code 0x11E960-0x11E9A0, Daten 0x1A7EA8-0x1A7EB8, wpp386 -4r -oneatx -zp1 -s (Watcom C/C++ 10.6)
#include <string.h>                                      // strcpy als Intrinsic (eingebettet)
const char *f_13da20();
extern unsigned char d_1c0a98;
static char d_1a7ea8[2][8] = { "NONE", "VESA" };                     // 0x1A7EA8
//@ f_11e960
char * __stdcall f_11e960(char *d)                       // 0x11E960, Argument auf dem Stapel (ret 4)
{
    strcpy(d, f_13da20());
    return d_1a7ea8[d_1c0a98];
}
