// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0dea00-0dea70 aus Quelle/cpp/G0DE790.CPP; erster Entwurf, Einbau separat prüfen.
// gz_0de790.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xDE790-0xDEA70. Feldzugriffe (Getter/Setter) der Game-Struktur und ein Konstruktor-artiger Initialisierer.
#pragma pack(1)
struct Game {
    int a[7]; signed char b1c; int l1d; short s21, s23, s25, s27, s29, s2b; int i2d, i31, i35, i39; short s3d, s3f; int i41, i45; signed char c49, c4a;
    void f_0de790(short k, int v); void f_0de7a0(signed char v); void f_0de7b0(int v);
    int f_0de7c0(); int f_0de7d0(short k); int f_0de7e0(); short f_0de7f0();
    short f_0de800(); void f_0de810(short v); short f_0de820(); void f_0de830(short v);
    int f_0de840(); void f_0de850(int v); int f_0de860(); void f_0de870(int v);
    int f_0de880(); void f_0de890(int v); int f_0de8a0(); void f_0de8b0(int v);
    short f_0de8c0(); void f_0de8d0(short v); short f_0de8e0(); void f_0de8f0(short v);
    short f_0de900(); void f_0de910(short v); short f_0de920(); void f_0de930(short v);
    void f_0de940(short v); short f_0de950(); void f_0de960(int v); int f_0de970();
    int f_0de980(); void f_0de990(int v); short f_0de9a0(); void f_0de9b0(short v);
    int f_0de9c0(); void f_0de9d0(signed char v); short f_0de9e0(); void f_0de9f0(signed char v);
};















































































struct Rec { short w0, w2, w4, w6, w8; short _a; int _c; short w10; int d12, d16; short w1a, w1c; int d1e; short _22[4]; short w2a; int d2c; };
//@ f_0dea00
Rec *f_0dea00(Rec *r, short a, short b, short c, short d, int e) {
    r->w8 = 0; r->w10 = 0; r->d12 = 0; r->d16 = 0; r->w1a = 0; r->w1c = 0;
    r->w0 = a; r->w2 = b; r->w6 = d; r->_c = e; r->w4 = c;
    r->d1e = c > 0; r->w2a = 0; r->d2c = 0;
    return r;
}
