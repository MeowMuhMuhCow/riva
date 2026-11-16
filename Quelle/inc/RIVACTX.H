/* D23: Textkontext 0x3c, Konstruktor 125400, Destruktor 1254a0.
 * Tabellen und Puffer werden in textstub angelegt und vom Dekoder benutzt.
 * Namen sind beschreibende Rekonstruktionen. fXX sowie a/p bleiben als
 * explizite Sichten fuer die noch folgende Entkrueckung erhalten.
 * Die int*-Sicht p bezeichnet dieselben 32-Bit-Slots wie objects;
 * keine Behauptung einer zweiten Speicherregion. */
#ifndef RIVACTX_H
#define RIVACTX_H
#include <stddef.h>
#pragma pack(push,1)
struct RivaTextCatalog { int f_134010(int); char *f_134030(int); };
struct RivaTextLookup { char *f_099b10(int); };
struct RivaTextFormat { unsigned char a:2; unsigned char b:3; unsigned char :3; unsigned char c:3; unsigned char :5; unsigned char x1; unsigned char x2; };
struct RivaTextSelector { unsigned char lo:4; unsigned char hi:4; };
struct RivaTextFlags { unsigned char a:2; unsigned char b:2; unsigned char c:4; };
struct RivaTextContext;
struct RivaTextTail {
    union { void **second_objects; void **f8; };
    union { void **items; void **fc; };
    union { int *numbers; int *f10; };
    union { short *short_numbers; short *f14; };
    union { int *wide_numbers; int *f18; };
    union { short *second_counts; short *f1c; };
    union { short *item_counts; short *f20; };
    union { char *text_buffer; char *f24; };
    union { char *text_cursor; char *f28; };
    union { RivaTextCatalog *catalog; RivaTextCatalog *f2c; };
    union { int resource_id; int f30; };
    union { RivaTextLookup *lookup; RivaTextLookup *f34; };
    union { RivaTextContext *previous; RivaTextContext *f38; };
};
struct RivaTextTables {
    union { void **objects; void **f4; int *p; };
    union { char c[52]; RivaTextTail tail; };
};
struct RivaTextContext {
    union { char *storage; char *f0; int a; };
    union { RivaTextTables tables; char *slots[14]; };
    RivaTextContext(const void *a, const void *b, const void *c);
    ~RivaTextContext();
    void f_1254c0();
    int f_1254e0();
    signed char f_125500();
    void f_125550(signed char p2, signed char p3, signed char p4);
    void f_125940(void *p, RivaTextFormat a, RivaTextFlags b);
    void f_125c20(void *p, short n, RivaTextFormat a, RivaTextFlags b);
    void f_125a30(void *p, short n, RivaTextFormat a, RivaTextFlags b);
    void f_125880(int x);
    void f_1258c0(int n);
    RivaTextContext *f_125400(void *a, void *b, void *c);
    RivaTextContext *f_1254a0(int unused);
};
#pragma pack(pop)
typedef char riva_context_layout[(sizeof(RivaTextContext)==0x3c && offsetof(RivaTextContext,tables)==4 && ((offsetof(RivaTextContext,tables)+offsetof(RivaTextTables,tail))+offsetof(RivaTextTail,item_counts))==0x20 && ((offsetof(RivaTextContext,tables)+offsetof(RivaTextTables,tail))+offsetof(RivaTextTail,previous))==0x38 && sizeof(RivaTextFormat)==4 && sizeof(RivaTextFlags)==1)?1:-1];
#endif
