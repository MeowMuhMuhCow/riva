/* D23: ACE-Schluesselregister. Layouts und Verwendungen 011720..0129xx,
 * gemeinsame globale Register d_1c2128/d_1c2138 in gz_020420.
 * Stream-vtable ist die belegte Praefixsicht bis einschliesslich Schreibslot 24. */
#ifndef RIVAACE_H
#define RIVAACE_H
#include "RIVASTRM.H"
#pragma pack(push,1)
struct RivaAceIntEntry { int v; short id; };
struct RivaAceShortEntry { short v; short id; };
struct RivaAceByteEntry { char v; short id; char gv() { return v; } short gid() { return id; } };
struct RivaAceIntRegister { short cap; short n; RivaAceIntEntry **arr; };
struct RivaAceShortRegister { short cap; short n; RivaAceShortEntry **arr; };
struct RivaAceByteRegister { short cap; short n; RivaAceByteEntry **arr; };
typedef RivaFileStreamVtable RivaAceStreamVtable;
typedef RivaFileStream RivaAceStream;
#pragma pack(pop)
typedef char riva_ace_layout[(sizeof(RivaAceIntEntry)==6 && sizeof(RivaAceShortEntry)==4 && sizeof(RivaAceByteEntry)==3 && sizeof(RivaAceIntRegister)==8 && sizeof(RivaAceShortRegister)==8 && sizeof(RivaAceByteRegister)==8 && sizeof(RivaAceStream)==24)?1:-1];
#endif
