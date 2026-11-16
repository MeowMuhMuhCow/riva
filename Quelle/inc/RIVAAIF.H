/* D23: AIF-Bild und Datei-Schnittstelle; 145760..1467xx, alle fuenf Teilquellen.
 * Bildlayout durch 640/STRUKTUREN und Riva-Zugriffe belegt; unbekannte Felder bleiben reserviert.
 * Neutrale Rekonstruktionsnamen, keine behaupteten Attic-Originalnamen. */
#ifndef RIVAAIF_H
#define RIVAAIF_H
#include "RIVASTRM.H"
#pragma pack(push,1)
typedef RivaFileStreamVtable RivaAifFileVtable;
typedef RivaFileStream RivaAifFile;
struct RivaAifImage { char z0[4]; signed char type; signed char f5; short w; short h; short n; short c; char z1[0x10];
 char *buf; int name; char c26; signed char c27; char c28; short idx; int len; char *out; char *tmp; char z2[4];
 char b100[100]; RivaAifFile *f; };
#pragma pack(pop)
typedef char riva_aif_layout[(sizeof(RivaAifImage)==0xa3 && sizeof(RivaAifFile)==0x18)?1:-1];
#endif
