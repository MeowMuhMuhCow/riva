/* === Beschreibung (Katalog) ===
 * Einheit chapter (0x03d980 - 0x03f060)
 *
 * Überblick
 * Diese Einheit steuert die erzählerischen Kapitelübergänge, Epilog-/Game-Over-Tafeln und
 * Vollbild-Videoanimationen (SMK/Film-Dateien) von *Schatten über Riva*. Sie baut wahlweise in niedriger
 * VGA-Auflösung (320x200) oder hoher SVGA-Auflösung (640x480, d_1bfb14 == 1) ein Textfenster über einem
 * Hintergrundbild auf, spielt die zugehörige Sprachausgabe und Musik aus dem Spracharchiv (d_1c2edc) ab und
 * enthält den Video-Player f_03ede0.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 2/6 gleich (suche.py 30.10.2026, Basis chapter_P1.CPP)
// chapter.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x03D980-0x03F060
#include <string.h>
#include <bios.h>
extern const char d_1a0c88[];
extern int d_0a0000;
extern signed char d_1bfb14;
extern unsigned short d_1bc8c4;
extern short d_1bd766, d_1c21a4, d_1c2198;
extern short d_1a0ca8[];
extern int d_1a34e0, d_1a9820, d_1bc760, d_1c0c4c, d_1c2a80;
extern volatile int d_1c0c94;
extern int d_1bacd0[], d_1bacc4[];
extern char d_1baac0[];
extern int  d_1c2e78, d_1c2e68, d_1c2edc, d_1c3498;
extern const char *d_1a0cc0[];
extern const char *d_1a0cf4[];
struct Scr { short a, w, h; void *buf; void *vt; };
struct Win { char b[0x41c]; Win(Scr *s, void *f); virtual ~Win(); };
struct Wnd { char b[0x4c]; Wnd(Win *w, void *p); };
struct Obj { char b[0x76]; Obj(); };
void f_045b70(Win *w, int v);
void f_05e1c0(Wnd *w, Win *x);
void f_05e2d0(Wnd *w, int a, int b, int c, int d);
void f_05e1d0(Wnd *w, int a, int b);
void f_05e420(Wnd *w, int a, int b);
void f_05e320(Wnd *w, int a, int b);
void f_05e380(Wnd *w, int a, int b, int c, int d, int e);
void f_0e9550(Wnd *w, int a);
void f_147323(void *p, int a, int b, int c, int d, int e, int f);
void f_147688(void *p, int a);
void f_146dfa(void *p, int a);
int f_14778f(void *p, int a);
void f_147aad(void *p);
int f_0d3780();
int f_0d37b0();
void f_149cf0(int a);
void f_149d20();
void f_10a8b0(Obj *o);
short f_10ae20(Obj *o, int a, int b);
int f_10a980(Obj *o, int a, int b);
int f_10aad0(Obj *o, const char *n, int a, int b);
void f_10ac80(Obj *o);
void __stdcall f_11e9d0(int a);
short f_0d40b6(void *p, int a);
void f_0d4070(void *p);
void f_0f1560(void *p);
void f_0d4880(void *p);
void f_0f00f0(void *p);
void f_0d3f25(void *p, int a);
void f_01cef0(int a);
void f_0d2710();
void f_0d26e0();
void f_0d9cc0();
void f_09ac80(int a, int b, int c);
void f_09a140(int a, int b);
void f_09ade0(int a, int b, int c);
int f_09aed0(int a);
void f_060a10(int a);
void *f_147c84(void *p, int n, void *t);
void __cdecl f_149eb4(void *p, int a, int b);
void __cdecl f_099ef0(void *p, int a, int b);
void f_091f70(int a);
inline int hi() { return (signed char)d_1bfb14 == 1; }
int f_03d980(unsigned short p1);

#include <stdio.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
extern unsigned char d_1a0d10;
extern unsigned char d_1a96a4;
extern unsigned char d_1bd762;
extern unsigned char d_1c2a74;
int C014540_3(int,int,int);
#pragma aux C014540_3 "f_014540" modify exact [eax ebx edx];
int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C099ea0_0();
#pragma aux C099ea0_0 "f_099ea0" modify exact [eax];
int C09a0d0_1(int);
#pragma aux C09a0d0_1 "f_09a0d0" modify exact [eax];
int C09a140_2(int,int);
#pragma aux C09a140_2 "f_09a140" modify exact [eax edi edx esi];
int C0d3780_0();
#pragma aux C0d3780_0 "f_0d3780" modify exact [eax];
int C0d37b0_0();
#pragma aux C0d37b0_0 "f_0d37b0" modify exact [eax];
int __pascal C11e760_2(int,int);
#pragma aux C11e760_2 "f_11e760" modify exact [eax ebx ecx edx];
int C11e8f0_0();
#pragma aux C11e8f0_0 "f_11e8f0" modify exact [eax];
int __cdecl C11e910_8(int,int,int,int,int,int,int,int);
#pragma aux C11e910_8 "f_11e910" modify exact [eax ecx edx];
int C13f8c0_0();
#pragma aux C13f8c0_0 "f_13f8c0" modify exact [eax];
int C146dfa_2(int,int);
#pragma aux C146dfa_2 "f_146dfa" modify exact [eax edx];
int C149d20_0();
#pragma aux C149d20_0 "f_149d20" modify exact [eax];
int __cdecl C149e2e_2(int,int);
#pragma aux C149e2e_2 "f_149e2e" modify exact [eax edi edx esi];
int __pascal C149f90_1(int);
#pragma aux C149f90_1 "f_149f90";
int __pascal C14a1d0_2(int,int);
#pragma aux C14a1d0_2 "f_14a1d0" modify exact [eax ebx ecx edx];
int __pascal C14a940_7(int,int,int,int,int,int,int);
#pragma aux C14a940_7 "f_14a940";
int __pascal C14b100_1(int);
#pragma aux C14b100_1 "f_14b100";
int __pascal C14b3d0_1(int);
#pragma aux C14b3d0_1 "f_14b3d0" modify exact [eax ebx ecx edi edx];
int __pascal C14b7b0_1(int);
#pragma aux C14b7b0_1 "f_14b7b0" modify exact [eax ebx ecx edx];
int __pascal C14bb40_3(int,int,int);
#pragma aux C14bb40_3 "f_14bb40" modify exact [eax ebx ecx edx];
int __cdecl C14d040_1(int);
#pragma aux C14d040_1 "f_14d040";
//@ f_03ede0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion lädt und spielt eine Vollbild-Filmsequenz (name) ab, schaltet dazu bei Bedarf
 *   die Bildschirmauflösung auf die Videogröße um, aktualisiert je Einzelbild die Farbpalette sowie den
 *   geänderten Bildausschnitt, bedient im Hintergrund das Soundsystem und bricht die Wiedergabe ab, sobald der
 *   Spieler eine Maustaste oder die ESC-Taste (0x11b) drückt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dateinamen der Filmsequenz name (const char *), setzt daraus
 *   mit dem CD-/Datenpfad d_1a96a4 und dem Formatstring d_1a0d10 den vollständigen Pfad zusammen und gibt 1
 *   zurück, wenn der Film vom Spieler vorzeitig abgebrochen wurde, sonst 0.
 * - Wichtige Variablen: Die Struktur MovieState16 (movie) verwaltet Breite, Höhe, Bildanzahl, Palettenänderungen
 *   und das aktuelle Dirty-Rectangle (left, top, rectWidth, rectHeight) des Videos; am Ende stellt die Funktion
 *   bei abweichender Auflösung den Standardmodus 320x200 wieder her.
 === Ende Beschreibung === */
void resetMovieMode16();
#pragma aux resetMovieMode16 "f_11e8f0" modify [eax ebx ecx edx];
struct MovieFormat16 { char text[20]; };
struct MovieState16 {
    int header;unsigned width,height,frames;char pad10[0x68-0x10];
    int paletteChanged;char palette[768];char pad36c[8];
    int left,top,rectWidth,rectHeight;
};
int f_03ede0(const char *name)
{
    char path[80];
    MovieFormat16 format=*(MovieFormat16 *)&d_1a0d10;
    struct Frame {int result;unsigned frame;};Frame state;
    state.result=0;int palette=0;
    MovieState16 *movie;
    char *buffer=0;
    C149d20_0();
    sprintf(path,format.text,NA(d_1a96a4),name);
    C09a140_2(0,25);
    C09a0d0_1(ND32(d_1a34e0));
    movie=(MovieState16 *)C14bb40_3((int)path,0,-1);
    if(!movie)goto done;
    buffer=(char *)C014540_3(movie->width*movie->height,NA(d_1a0c88),0x23f);
    if(!buffer)goto done;
    if((unsigned char)C11e760_2(movie->width,movie->height)) {
        resetMovieMode16();
        C14a940_7((int)movie,0,0,movie->width,movie->height,(int)buffer,0);
        for(state.frame=0;state.frame<movie->frames;state.frame++) {
            C14b3d0_1((int)movie);
            while(C14a1d0_2((int)movie,0)) {
                C146dfa_2(NA(d_1c2edc),1);
                if(movie->paletteChanged && !palette) {
                    C099ea0_0();C14d040_1((int)movie->palette);
                    C149e2e_2(NA(d_1c2a74),255);palette=1;
                }
                C11e910_8((int)buffer,movie->left,movie->top,movie->rectWidth,movie->rectHeight,movie->width,movie->left,movie->top);
            }
            palette=0;
            if(state.frame!=movie->frames) { C14b100_1((int)movie);C146dfa_2(NA(d_1c2edc),1); }
            do {
                if(C0d3780_0()==1 || C0d37b0_0()==1) {
                    while(C0d3780_0()==1 || C0d37b0_0()==1) {}
                    state.result=1;goto close_movie;
                }
                if(_bios_keybrd(_KEYBRD_READY)) {
                    ND16(d_1bd762)=(short)_bios_keybrd(_KEYBRD_READ);
                    C149d20_0();
                    if((unsigned short)ND16(d_1bd762)==0x11b) {state.result=1;goto close_movie;}
                }
            } while(C149f90_1((int)movie));
        }
    }
close_movie:
    C14b7b0_1((int)movie);
    if(buffer)C014710_1((int)buffer);
done:
    C09a140_2(0,25);
    if((short)C13f8c0_0()!=320) {C11e760_2(320,200);resetMovieMode16();}
    C149d20_0();
    return state.result;
}


//@ f_03d980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion legt für eine Kapitel- oder Endsequenz-Kennung p1 (0x2001..0x2003 für die drei
 *   Kapitel-Erzähltafeln, 0x4001..0x4006 für die verschiedenen Todes-/Niederlage- und Epilogbildschirme) ein
 *   temporäres Grafik- und Textfenster an, gibt den gesprochenen Erzähltext (0x2a0006..0x2a000e) auf dem
 *   Soundkanal aus und schreibt bei den mehrteiligen Kapiteltexten (0x2002, 0x2003) zusätzlich den
 *   Untertiteltext (0x2a000001..0x2a000004) auf den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält den Sequenzcode p1 (unsigned short) und gibt 1 zurück, solange
 *   bei der dreiteiligen Erzählung 0x2003 noch weitere Textabschnitte folgen (d_1bc8c4), 100 beim Endbildschirm
 *   0x4006 (Endlosschleife der Musik) oder 0 bei einseitigen Tafeln.
 * - Wichtige Variablen: Der globale Zähler d_1bc8c4 (0, 1, 2) schaltet bei p1 == 0x2003 durch die drei
 *   aufeinanderfolgenden Erzählabschnitte; d_1bfb14 wählt zwischen der 320x200- und der
 *   640x480-Fenstergeometrie.
 === Ende Beschreibung === */
int f_03d980(unsigned short p1)
{
    void f_05e380_frame(Wnd *, int, int, int, int, int);
#pragma aux f_05e380_frame "f_05e380" modify [esp];
    struct Scr0 : Scr { Scr0() { a = 1; w = 320; h = 200; buf = (void *)0xa0000; vt = d_1bacd0; } };
    struct Scr1 : Scr { Scr1() { a = 2; w = 640; h = 480; buf = (void *)0xa0000; vt = d_1bacc4; } };
    Scr *screen;
    int result;
    result = 0;
    signed char mode0 = d_1bfb14;
    if ((int)mode0 == 0) {
        screen = new (mark(d_1a0c88, 0x91)) Scr0;
    } else {
        screen = new (mark(d_1a0c88, 0x95)) Scr1;
    }
    Win *win = new (mark(d_1a0c88, 0x98)) Win(screen, &d_1c2098);
    Wnd *window = new (mark(d_1a0c88, 0x99)) Wnd(win, &d_1c3498);
    f_045b70(win, 0x130000);
    f_05e1c0(window, win);
    extern void f_05e420(Wnd *, int);
    mode0 = d_1bfb14;
    if ((int)mode0 == 0) {
        f_05e2d0(window, 10, 300, -1, 1);
        f_05e1d0(window, 10, 176);
        f_05e420(window, 8);
    } else {
        f_05e2d0(window, 40, 560, -1, 1);
        f_05e1d0(window, 40, 435);
        f_05e420(window, 9);
    }
    f_05e320(window, 255, -1);
    f_05e380_frame(window, 255, 253, 249, 252, 231);
    switch (p1) {
    case 0x2001:
        { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0006, 0x7fff, 0x8000, t, 0, 1); }
        result = 0;
        break;
    case 0x2002:
        { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0006, 0x7fff, 0x8000, t, 0, 1); }
        f_0e9550(window, 0x2a000001);
        { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000b, 0x7fff, 0x8000, t, 0, 1); }
        result = 0;
        break;
    case 0x2003: {
        signed char mode3 = d_1bfb14;
        if ((int)mode3 == 0) f_05e1d0(window, 10, 153);
        switch (d_1bc8c4) {
        case 0:
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0007, 0x7fff, 0x8000, t, 0, 1); }
            f_0e9550(window, 0x2a000002);
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000c, 0x7fff, 0x8000, t, 0, 1); }
            d_1bc8c4 = 1;
            result = 1;
            break;
        case 1:
            f_147688(&d_1c2edc, 0x2a000c);
            f_0e9550(window, 0x2a000003);
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000d, 0x7fff, 0x8000, t, 0, 1); }
            d_1bc8c4 = 2;
            result = 1;
            break;
        case 2:
            f_147688(&d_1c2edc, 0x2a000d);
            f_0e9550(window, 0x2a000004);
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000e, 0x7fff, 0x8000, t, 0, 1); }
            d_1bc8c4 = 0;
            break;
        }
        break;
    }
    case 0x4001:
    case 0x4002:
    case 0x4003:
        { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0008, 0x7fff, 0x8000, t, 0, 1); }
        result = 0;
        break;
    case 0x4004:
    case 0x4005:
        { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0009, 0x7fff, 0x8000, t, 0, 1); }
        result = 0;
        break;
    case 0x4006:
        { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000a, 0x7fff, 0x8000, t, 0, 1); }
        result = 100;
        break;
    }
    delete window;
    struct WinDel { virtual ~WinDel() {} };
    delete (WinDel *)win;
    delete screen;
    return result;
}
#pragma inline_depth(0)
#pragma inline_depth(0)
//@ f_03de30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion stellt das geladene Hintergrundbild o einer Kapitel- oder Endsequenz dar, ruft
 *   f_03d980 (inlined) zur Ausgabe von Text und Sprache auf und wartet in einer Ereignisschleife auf das Ende
 *   der Sprachausgabe, einen Mausklick, einen Tastendruck oder den Ablauf des Zeitlimits in_tmo, wobei
 *   mehrteilige Kapiteltexte (result == 1) automatisch nacheinander durchlaufen werden.
 * - Eingaben und Rückgabe: Die Funktion erhält das Bildobjekt o (Obj *), den Sequenzcode in_mode (unsigned) und
 *   ein optionales Timeout in_tmo (unsigned, 0 = unbegrenzt warten) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Während der Warteschleife hält f_146dfa(&d_1c2edc, 1) den Sound-Stream am Laufen und
 *   startet Hintergrundschleifen (0x2a000a bzw. 0x2a0007) bei Bedarf neu.
 === Ende Beschreibung === */
void f_03de30(Obj *o, unsigned in_mode, unsigned in_tmo)
{
    struct PartMode1139 { unsigned char b[1]; };
    union { unsigned value; PartMode1139 p0;
        struct { unsigned char pad[1]; PartMode1139 part; } p1;
        struct { unsigned char pad[2]; PartMode1139 part; } p2;
        struct { unsigned char pad[3]; PartMode1139 part; } p3;
    } mode;
    mode.value = in_mode;
    unsigned tmo = in_tmo;
                int codex_arg_4_370;
    void f_05e380_frame(Wnd *, int, int, int, int, int);
#pragma aux f_05e380_frame "f_05e380" modify [esp];
    extern void f_05e420(Wnd *, int);
    struct Scr0 : Scr { Scr0() { a = 1; w = 320; h = 200; buf = (void *)0xa0000; vt = d_1bacd0; } };
    struct Scr1 : Scr { Scr1() { a = 2; w = 640; h = 480; buf = (void *)0xa0000; vt = d_1bacc4; } };
    volatile unsigned flag = tmo > 0;
    f_149d20();
    int result;
    do {
        Wnd *window;
        Win *win;
        Scr *screen;
        unsigned m;
        int rr;
        Wnd *x;
        f_10a8b0(o);
        d_1bd766 = f_10ae20(o, 0, 0);
        m = mode.value;
        rr = 0;
        signed char display = d_1bfb14;
        if (display == 0)
            screen = new (mark(d_1a0c88, 0x91)) Scr0;
        else
            screen = new (mark(d_1a0c88, 0x95)) Scr1;
        win = new (mark(d_1a0c88, 0x98)) Win(screen, &d_1c2098);
        window = new (mark(d_1a0c88, 0x99)) Wnd(win, &d_1c3498);
        f_045b70(win, 0x130000);
        f_05e1c0(window, win);
        x = window;
        display = d_1bfb14;
        if (display == 0) {
            f_05e2d0(window, 10, 300, -1, 1);
            f_05e1d0(window, 10, 176);
            f_05e420(window, 8);
        } else {
            f_05e2d0(window, 40, 560, -1, 1);
            f_05e1d0(window, 40, 435);
            f_05e420(window, 9);
        }
        f_05e320(x, 255, -1);
        f_05e380_frame(x, 255, 253, 249, 252, 231);
        switch ((unsigned short)m) {
        case 0x2001:
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0006, 0x7fff, 0x8000, t, 0, 1); }
            rr = 0;
            break;
        case 0x2002:
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0006, 0x7fff, 0x8000, t, 0, 1); }
            f_0e9550(x, 0x2a000001);
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000b, 0x7fff, 0x8000, t, 0, 1); }
            rr = 0;
            break;
        case 0x2003:
            display = d_1bfb14;
            if (display == 0) f_05e1d0(x, 10, 153);
            switch (d_1bc8c4) {
            case 0:
                { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0007, 0x7fff, 0x8000, t, 0, 1); }
                f_0e9550(x, 0x2a000002);
                { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000c, 0x7fff, 0x8000, t, 0, 1); }
                d_1bc8c4 = 1;
                rr = 1;
                break;
            case 1:
                f_147688(&d_1c2edc, 0x2a000c);
                f_0e9550(x, 0x2a000003);
                { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000d, 0x7fff, 0x8000, t, 0, 1); }
                d_1bc8c4 = 2;
                rr = 1;
                break;
            case 2:
                f_147688(&d_1c2edc, 0x2a000d);
                f_0e9550(x, 0x2a000004);
                { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000e, 0x7fff, 0x8000, t, 0, 1); }
                d_1bc8c4 = 0;
                break;
            }
            break;
        case 0x4001:
        case 0x4002:
        case 0x4003:
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0008, 0x7fff, 0x8000, t, 0, 1); }
            rr = 0;
            break;
        case 0x4004:
        case 0x4005:
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0009, 0x7fff, 0x8000, t, 0, 1); }
            rr = 0;
            break;
        case 0x4006:
            { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a000a, 0x7fff, 0x8000, t, 0, 1); }
            rr = 100;
            break;
        }
        // Teilzugriffe halten die Stapel- und Registervergabe wie im Original
        { struct Teil0 { unsigned char b[1]; }; Teil0 teil0 = *(Teil0 *)(&x); }
        { struct Teil1 { unsigned char b[1]; }; Teil1 teil1 = *(Teil1 *)((char *)&x + 1); }
        { struct Teil2 { unsigned char b[1]; }; Teil2 teil2 = *(Teil2 *)((char *)&x + 2); }
        delete x;
        struct WinDel { virtual ~WinDel() {} };
        delete (WinDel *)win;
        delete screen;
        result = (short)rr;
        for (;;) {
            f_146dfa(&d_1c2edc, 1);
            if (result == 100 && f_14778f(&d_1c2edc, 0x2a000a) == 0)
                f_147323(&d_1c2edc, 0x2a000a, 0x7fff, 0x8000, (codex_arg_4_370 = d_1a9820), 0, 1);
            else if (result == 1 && f_14778f(&d_1c2edc, 0x2a0007) == 0)
                f_147323(&d_1c2edc, 0x2a0007, 0x7fff, 0x8000, d_1a9820, 0, 1);
            if (f_0d3780() == 1 || f_0d37b0() == 1) {
                while (f_0d3780() == 1 || f_0d37b0() == 1) ;
                break;
            }
            if (flag) {
                if (--tmo == (unsigned)-1) break;
                f_149cf0(10);
            }
            if (_bios_keybrd(1)) { _bios_keybrd(0); break; }
        }
    } while (result == 1);
    f_10ac80(o);
    f_11e9d0(0);
    // Teilzugriffe halten mode im Stapelslot wie im Original
    { PartMode1139 dead0 = mode.p0; }
    { PartMode1139 dead1 = mode.p1.part; }
    { PartMode1139 dead2 = mode.p2.part; }
    { PartMode1139 dead3 = mode.p3.part; }
    f_147aad(&d_1c2edc);
}
#pragma inline_depth(3)
#pragma inline_depth(3)
//@ f_03e440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese übergeordnete Präsentationsfunktion lädt ein Vollbild-Kapitelbild mit dem Dateinamen p3
 *   in der Auflösung p1 x p2, blendet Mauszeiger und laufende UI-Timer aus, führt die komplette Bild-, Text- und
 *   Sprachpräsentation (identisch zu f_03de30) für den Modus p4 und das Timeout p5 durch und stellt anschließend
 *   den normalen Grafikmodus (320x200) sowie die Benutzeroberfläche wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält die Bildbreite p1 (short), die Bildhöhe p2 (short), den
 *   Bilddateinamen p3 (const char *), den Sequenzmodus p4 (short) und das Timeout p5 (int); sie hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: saved_c94 und saved_b6 sichern den Zustand des UI-/Timer-Systems (d_1c0c94, d_1c2e78)
 *   über die Dauer der Zwischensequenz hinweg.
 === Ende Beschreibung === */
#pragma aux f_05e380 modify [esp];
#pragma aux f_0d40b6 modify exact [eax];
#pragma aux f_09a140 modify exact [eax ecx edx];
struct ScrBase_e440 : Scr { ScrBase_e440(int, int, int, void *); };
void f_03e440(short p1, short p2, const char *p3, short p4, int p5)
{
    extern void f_05e420(Wnd *, int);
    struct Scr0 : ScrBase_e440 { Scr0() : ScrBase_e440(1, 320, 200, (void *)0xa0000) { vt = d_1bacd0; } };
    struct Scr1 : ScrBase_e440 { Scr1() : ScrBase_e440(2, 640, 480, (void *)0xa0000) { vt = d_1bacc4; } };
    Scr *screen;
    unsigned tmo;
    Obj *obj;
    Win *win;
    const char *rt3;
    unsigned short mode;
    unsigned short m;
    Wnd *window;
    Wnd *rtw;
    short rt;
    short saved_b6;
    int rr;
    int saved_c94;
    int result;
    unsigned flag;
    Obj *o;
    obj = new (mark(d_1a0c88, 0x15c)) Obj;
    saved_c94 = d_1c0c94;
    saved_b6 = ((short (*)(void *))f_0d40b6)(&d_1c2e78);
    d_1c0c4c++;
    d_1c2a80 = 0;
    d_1c0c94 = 0;
    f_0f1560(&d_1c2e68);
    f_0d4070(&d_1c2e78);
    if (d_1bc760) f_01cef0(d_1bc760);
    f_0d2710();
    f_09ac80(d_1a34e0, 0, 0);
    f_09a140(0, 0x19);
    rt = p1; p1 = rt;
    rt3 = p3; p3 = rt3;
    if (f_10a980(obj, p1, p2) == 1) {
        if (hi()) f_0d9cc0();
        if (f_10aad0(obj, p3, 0, 0) == 1) {
            o = obj;
            const unsigned short *incoming_mode = (const unsigned short *)&p4;
            mode = *incoming_mode;
            tmo = p5;
            flag = tmo > 0;
            f_149d20();
            do {
                f_10a8b0(o);
                d_1bd766 = f_10ae20(o, 0, 0);
                m = mode;
                rr = 0;
                signed char display = d_1bfb14;
                if (display == 0)
                    screen = new (mark(d_1a0c88, 0x91)) Scr0;
                else
                    screen = new (mark(d_1a0c88, 0x95)) Scr1;
                win = new (mark(d_1a0c88, 0x98)) Win(screen, &d_1c2098);
                window = new (mark(d_1a0c88, 0x99)) Wnd(win, &d_1c3498);
                mode = (mode & 0) ? 0 : mode; // Haelt die Registervergabe wie im Original
                f_045b70(win, 0x130000);
                f_05e1c0(window, win);
                display = d_1bfb14;
                if (display == 0) {
                    f_05e2d0(window, 10, 300, -1, 1);
                    f_05e1d0(window, 10, 176);
                    f_05e420(window, 8); o = (flag & 0) ? (Obj *)0 : o;
                } else {
                    f_05e2d0(window, 40, 560, -1, 1);
                    f_05e1d0(window, 40, 435);
                    f_05e420(window, 9); o = (flag & 0) ? (Obj *)0 : o;
                }
                f_05e320(window, 255, -1);
                f_05e380(window, 255, 253, 249, 252, 231);
                switch (m) {
                case 0x2001:
                    { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a0006, 0x7fff, 0x8000, t, 0, 1); }
                    rr = 0;
                    break;
                case 0x2002:
                    { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0006, 0x7fff, 0x8000, t, 0, 1); }
                    f_0e9550(window, 0x2a000001);
                    { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a000b, 0x7fff, 0x8000, t, 0, 1); }
                    rr = 0;
                    break;
                case 0x2003:
                    display = d_1bfb14;
                    if (display == 0) f_05e1d0(window, 10, 153);
                    switch (d_1bc8c4) {
                    case 0:
                        { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a0007, 0x7fff, 0x8000, t, 0, 1); }
                        f_0e9550(window, 0x2a000002);
                        { int t = d_1a9820; tmo = (tmo & 0) ? 0 : tmo; f_147323(&d_1c2edc, 0x2a000c, 0x7fff, 0x8000, t, 0, 1); }
                        d_1bc8c4 = 1;
                        rr = 1;
                        break;
                    case 1:
                        f_147688(&d_1c2edc, 0x2a000c);
                        f_0e9550(window, 0x2a000003);
                        { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a000d, 0x7fff, 0x8000, t, 0, 1); }
                        d_1bc8c4 = 2;
                        rr = 1;
                        break;
                    case 2:
                        f_147688(&d_1c2edc, 0x2a000d);
                        f_0e9550(window, 0x2a000004);
                        { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a000e, 0x7fff, 0x8000, t, 0, 1); }
                        d_1bc8c4 = 0;
                        break;
                    }
                    break;
                case 0x4001:
                case 0x4002:
                case 0x4003:
                    { int t = d_1a9820; f_147323(&d_1c2edc, 0x2a0008, 0x7fff, 0x8000, t, 0, 1); }
                    rr = 0;
                    break;
                case 0x4004:
                case 0x4005:
                    { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a0009, 0x7fff, 0x8000, t, 0, 1); }
                    rr = 0;
                    break;
                case 0x4006:
                    { int t = d_1a9820; o = ((unsigned)o & 0) ? (Obj *)0 : o; f_147323(&d_1c2edc, 0x2a000a, 0x7fff, 0x8000, t, 0, 1); }
                    rr = 100;
                    break;
                }
                rtw = window; window = rtw;
                delete window;
                struct WinDel { virtual ~WinDel() {} };
                delete (WinDel *)win;
                delete screen;
                result = (short)rr;
                for (;;) {
                    int t1, t2;
                    f_146dfa(&d_1c2edc, 1);
                    if (result == 100 && f_14778f(&d_1c2edc, 0x2a000a) == 0)
                        f_147323(&d_1c2edc, 0x2a000a, 0x7fff, 0x8000, (t1 = d_1a9820), 0, 1);
                    else if (result == 1 && f_14778f(&d_1c2edc, 0x2a0007) == 0)
                        f_147323(&d_1c2edc, 0x2a0007, 0x7fff, 0x8000, (t2 = d_1a9820), 0, 1);
                    if (f_0d3780() == 1 || f_0d37b0() == 1) {
                        while (f_0d3780() == 1 || f_0d37b0() == 1) ;
                        break;
                    }
                    if (flag) {
                        if (--tmo == (unsigned)-1) break;
                        f_149cf0(10);
                    }
                    if (_bios_keybrd(1)) { _bios_keybrd(0); break; }
                }
            } while (result == 1);
            f_10ac80(o);
            f_11e9d0(0);
            f_147aad(&d_1c2edc);
        }
    }
    f_10a980(obj, 0x140, 200);
    f_09a140(0, 0x19);
    f_09ade0(d_1a34e0, 0, 0);
    f_09aed0(0);
    f_0d26e0();
    delete obj;
    *(volatile short *)&d_1c2198 = 1;
    d_1c0c94 = saved_c94;
    f_0d4880(&d_1c2e68);
    f_0f00f0(&d_1c2e68);
    d_1c0c4c--;
    f_0d3f25(&d_1c2e78, saved_b6);
}

//@ f_03ebb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zeigt den zur aktuellen Niederlage- oder Spielende-Ursache (d_1c21a4) passenden
 *   Game-Over-/Endbildschirm samt Sprachausgabe an. Sie wählt anhand der Tabelle d_1a0ca8[d_1c21a4] das passende
 *   Bild aus d_1a0cc0 (in 320x200 oder 640x480) und ruft f_03e440 mit dem Modus loc | 0x4000 auf.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: d_1c21a4 enthält den Grund des Spielendes, d_1a0ca8 ordnet ihm den Bild-/Sequenzindex
 *   1..6 zu, und d_1a0cc0 enthält die Dateinamen der zugehörigen Grafiken (je 6 für Low-Res und High-Res).
 === Ende Beschreibung === */
struct Palette1111 { unsigned char r, g, b; Palette1111(); };
void f_03ebb0()
{
    f_060a10(500000);
    void *o = new (mark(d_1a0c88, 0x19c)) Palette1111[256];
    signed char mode = d_1bfb14;
    short h, w, k;
    w = 0; h = 0; k = 0;
    switch ((unsigned char)mode) {
    case 0: w = 0x140; h = 200; break;
    case 1: k = 6; w = 0x280; h = 0x1e0; break;
    }
    {
        {
            unsigned short loc = d_1a0ca8[d_1c21a4] | 0x4000;
            k += d_1a0ca8[d_1c21a4];
            const char *nm = d_1a0cc0[k];
            short rt = d_1c21a4;
            d_1c21a4 = rt; // Haelt die Registervergabe vor dem Aufruf wie im Original
            f_149eb4(o, 0, 0x100);
            f_03e440(w, h, nm, loc, 0);
        }
    }
    f_099ef0(o, 0, 0x100);
    delete (char *)o;
}
//@ f_03eca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion präsentiert den Übergangsbildschirm für das Kapitel p1 (1, 2 oder 3) mit Bild,
 *   Erzähltext und Sprachausgabe über f_03e440 und trägt anschließend über f_091f70 den entsprechenden
 *   Tagebucheintrag (0x47, 0x48 oder 0x49) in das Chronikbuch der Gruppe ein.
 * - Eingaben und Rückgabe: Die Funktion erhält die Kapitelnummer p1 (1..3) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Die Tabelle d_1a0cf4 liefert die Dateinamen der Kapitelbilder (mit Offset +3 bei
 *   aktivierter SVGA-Auflösung d_1bfb14 == 1).
 === Ende Beschreibung === */
struct PaletteGrok17 { unsigned char red, green, blue; PaletteGrok17(); };
void f_03eca0(int p1)
{
    struct Frame1083 { int n; void *o; int loc; } frame;
    f_060a10(750000);
    void *allocated = new (mark(d_1a0c88, 0x1d6)) PaletteGrok17[256];
    signed char mode = d_1bfb14;
    frame.o = allocated;
    frame.o = allocated;
    frame.o = allocated;

    short w, h, k;
    w = 0; h = 0; k = 0;
    switch ((unsigned char)mode) {
    case 0: w = 0x140; h = 200; break;
    case 1: k = 3; w = 0x280; h = 0x1e0; break;
    }
    frame.loc = p1 | 0x2000;
    frame.n = (short)p1;
    const char *nm = d_1a0cf4[k + frame.n];
    f_149eb4(frame.o, 0, 0x100);
    if (frame.n == 1) f_03e440(w, h, nm, frame.loc, 1000);
    else f_03e440(w, h, nm, frame.loc, 0);
    f_099ef0(frame.o, 0, 0x100);
    delete (char *)frame.o;
    switch ((unsigned short)p1) {
    case 1: f_091f70(0x47); break;
    case 2: f_091f70(0x48); break;
    case 3: f_091f70(0x49); break;
    }
}
