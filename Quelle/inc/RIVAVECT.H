/* D23: Vektoren und Stream-Schnittstelle der sieben aktiven 15b770..15cxxx-Teile.
 * Vier Bereichszeiger und drei Verwaltungswerte; unbekannte vtable-Slots bleiben reserviert.
 * Neutrale Rekonstruktionsnamen, keine behaupteten Attic-Originalnamen. */
#ifndef RIVAVECT_H
#define RIVAVECT_H
#include "RIVASTRM.H"
#pragma pack(push,1)
/* Alter Struct-Tag bleibt fuer unveraenderte Vorwaertsdeklarationen gueltig. */
struct RivaStreamDevice : RivaFileStream {};
struct RivaIntVector { int *a, *b, *c, *d; int cap, th, th4; };
struct RivaVectorVector { RivaIntVector *a, *b, *c, *d; int cap, th, th4; };
struct RivaRecord32 { int w[8]; };
struct RivaRecordVector { RivaRecord32 *a, *b, *c, *d; int cap, th, th4; };
typedef RivaFileStreamVtable RivaStreamVtable;
#pragma pack(pop)
typedef char riva_vector_layout[(sizeof(RivaIntVector)==28 && sizeof(RivaVectorVector)==28 && sizeof(RivaRecord32)==32 && sizeof(RivaRecordVector)==28 && sizeof(RivaStreamDevice)==24)?1:-1];
#endif
