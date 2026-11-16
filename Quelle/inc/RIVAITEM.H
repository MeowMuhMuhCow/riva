/* D23: Gegenstandsdefinition = Namenszeiger + 16 geladene Dateibytes.
 * item.cpp kopiert vier long-Werte, die Zugriffe 0a7800..0a7ad0 belegen
 * die Feldgrenzen. Offsetnamen bleiben bis zur fachlichen Benennung erhalten. */
#ifndef RIVAITEM_H
#define RIVAITEM_H
#pragma pack(push,1)
struct RivaItemRecord { long v[4]; };
struct RivaItemData {

  short s4;
  union { unsigned short w; struct { unsigned short bf6_0:1, bf6_1:1, bf6_2:1, bf6_3:1, bf6_4:1, bf6_5:1, bf6_6:1, bf6_7:1,
                 bf6_8:1, bf6_9:1, bf6_10:1, bf6_11:1, bf6_12:1, bf6_13:1, bf6_14:1, bf6_15:1; } b; } u6;
  unsigned char c8, c9; short sa, sc; signed char ce; unsigned char cf; signed char c10; unsigned char c11;
  signed char c12, c13;

};
struct RivaItemDefinition {
    union { char *name; char b0[4]; };
    union { RivaItemRecord rec; RivaItemData data; };
    RivaItemDefinition();
    ~RivaItemDefinition();

  short f_0a7800(); short f_0a7810(); short f_0a7820(); short f_0a7830();
  unsigned char f_0a78a0(); unsigned char f_0a78b0(); unsigned char f_0a78c0(); unsigned char f_0a78d0();
  unsigned short f_0a78e0();
  int f_0a78f0(); int f_0a7910(); int f_0a7930(); int f_0a7950();
  int f_0a7970(); int f_0a7990(); int f_0a79b0(); int f_0a79c0();
  int f_0a79e0(); int f_0a7a00(); int f_0a7a20(); int f_0a7a40();
  int f_0a7a60(); int f_0a7a80();
  int f_0a7a90(); int f_0a7aa0(); int f_0a7ac0(); int f_0a7ad0(); short f_0a7ae0(short p);

};
#pragma pack(pop)
typedef char riva_item_layout[(sizeof(RivaItemRecord)==16 && sizeof(RivaItemData)==16 && sizeof(RivaItemDefinition)==20)?1:-1];
#endif
