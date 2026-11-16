/* D23: shape.cpp, gemeinsames Rasterbild 0x09 Byte.
 * +0 Breite, +2 Hoehe, +4 Eigentum, +5 Zeilentabelle.
 * row_addresses ist die vorhandene Ganzzahlsicht derselben Zeilenzeiger;
 * ihre verbleibende Adressarithmetik wird separat entkrueckt. */
#ifndef RIVAIMG_H
#define RIVAIMG_H
#pragma pack(push,1)
struct RivaRasterFields {
    short w,h;
    union { signed char k; char c4; };
    union { int *row_addresses; char **rows; };
};
struct RivaRasterImage {
    union { RivaRasterFields raster; char b[9]; char d[9]; char data[9]; };
    RivaRasterImage();
    RivaRasterImage(short w,short h);
    RivaRasterImage(short w,short h,void *pixels);
    ~RivaRasterImage();
    char *f_0fb0b0();
    RivaRasterImage *f_0fac10(short a, short b, void *c);
    void f_0fad50(short a, short b, void *c);
    void f_0fadc0();
    void f_0fade0(void *e, int x_input, int y_input);
    void f_0fae30(void *e, int x_input, int y_input, int m_input);
    void f_0faec0(void *e, short x, short y, short s1, short s2);
    void f_0faf20(void *e, short x, short y, short s1, short s2, unsigned short m);
    void f_0fafb0(void *e, short x, short y);
    void f_0fb000(void *e, short x, short y, short s1, short s2);
    void f_0fb060(void *base);
    void f_0fb090(void *e);
    void f_0fb0c0(RivaRasterImage *o);
    RivaRasterImage *f_0fac80(short a, short b);
    RivaRasterImage *f_0fad20(int flag_unused491);
    void f_0fb120();
    void f_0fb150(short v);
    void f_0fb1a0(char a, signed char b);
    void f_0fb210(short *pw, short *ph);
    void f_0fb220(short x, short y, short bw, short bh, short c);
    void f_0fb320(short x, short y, short bw, short c);
    void f_0fb350(short x, short y, short bh, short c);
    void f_0fb3a0(RivaRasterImage *o, short x, short y, short n);
    void f_0fb3e0(char *dst, short stride, short x, short y, short cw, short ch, short mode);
    void f_0fb4d0(RivaRasterImage *o, short x, short y);
    void f_0fb540(RivaRasterImage *o, short x, short y, short bw, short bh);
};
#pragma pack(pop)
typedef char riva_raster_layout[(sizeof(RivaRasterFields)==9 && sizeof(RivaRasterImage)==9)?1:-1];
#endif
