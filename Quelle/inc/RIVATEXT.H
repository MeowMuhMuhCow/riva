/* D23: Textsatz: Farbwert, Layouteintrag, Bytevektor und Satzkontext.
 * Gemeinsame Definitionen der sechs aktiven Teilquellen 158128..15b770; kein 125400-Textkontext.
 * Neutrale Rekonstruktionsnamen, keine behaupteten Attic-Originalnamen. */
#ifndef RIVATEXT_H
#define RIVATEXT_H
#pragma pack(push,1)
struct RivaRgb { unsigned char a, b, c; };
struct RivaLayoutItem { int type; int x; int y; short w; short h; short s0; short s1; short s2; short s3; int p2; int p3; };
struct RivaByteVector { char *d; char *b; char *e; char *c; int u4; int u5; int mn; };
struct RivaTextLayout { int x; int y; int w; int f3; char b10; char b11; char b12; char b13; char b14; RivaRgb col; int lh; int f7; int sp; int nowrap; int f10; int center; int cnt; int cur; };
#pragma pack(pop)
typedef char riva_text_layout[(sizeof(RivaRgb)==3 && sizeof(RivaLayoutItem)==32 && sizeof(RivaByteVector)==28 && sizeof(RivaTextLayout)==56)?1:-1];
#endif
