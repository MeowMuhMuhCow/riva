/* === Beschreibung (Katalog) ===
 * Einheit diskmen2_t2 (0x05b080 - 0x05b6c0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von diskmen2.cpp und enthält das Laden eines Spielstands über einen
 * expliziten Dateinamen, das Lesen und Schreiben des 16-Byte-Versionskopfs, das Löschen eines Spielstands sowie
 * die Versionsprüfung und automatische Konvertierung älterer Spielstandsformate.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAFILE.H"
// P3 4/5 gleich (suche.py 29.10.2026, Basis diskmen2_t2_P1.CPP)
// diskmen2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil 2, Code 0x05B080-0x05B6C0
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
#define A(x) ((int)&(x))
typedef RivaTextContextData Msg;
struct Dsk { char p0[0x10]; char hdr[12]; char b1c, b1d, b1e, b1f; char p20[8]; short fd; char p2a[0x100]; char names[8][13]; };

extern RivaFileManager d_1c2098;
long f_145279(int h, long pos, int whence);
int f_144e8b(int h, void *buf, unsigned n);
int f_144fbf(const char *name, int mode, ...);
int f_145259(int h);
int f_149336(char *p);
int f_14572e(char *, const char *, ...);
int f_0d3860();
int f_0d2710();
int f_0d26e0();
int f_1483f0(int p1, int p2, int p3, int p4, int p5);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_133fe0(int p1, int p2);
int f_0e93f0(int p1, int p2, int p3);
int f_0a2800(int p1);
int f_0a2800(int p1, int p2);
int f_0a2810(int p1, int p2);
void f_05a020(Dsk *p1, int p2);
void f_05a910(Dsk *p1, int p2);
extern int d_1a34e0;
extern const char *d_1a9678;
extern char d_1a9692;
extern char d_1a9693;
extern const char d_1a9680[];
extern const char d_1a1794[];
extern const char d_1b6ed5[];
extern char d_1c21b4[];
extern short d_1c2140;
extern int d_1c2098x;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;


#include <string.h>
#include <stdio.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
extern unsigned char d_1a9674;
extern unsigned char d_1a9694;
extern unsigned char d_1b6ed1;
extern unsigned char d_1c2a50;
extern unsigned char d_1c2c64;
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
int C05a910_2(int,int);
#pragma aux C05a910_2 "f_05a910" modify exact [eax edx];
int C05b420_2(int,int);
#pragma aux C05b420_2 "f_05b420" modify exact [eax ebx edx];
int C0bf730_2(int,int);
#pragma aux C0bf730_2 "f_0bf730" modify exact [eax edx];
int C0d2e70_0();
#pragma aux C0d2e70_0 "f_0d2e70" modify exact [eax];
int C0d2f90_2(int,int);
#pragma aux C0d2f90_2 "f_0d2f90" modify exact [eax edx];
int C133fe0_2(int,int);
#pragma aux C133fe0_2 "f_133fe0" modify exact [eax edx];
int C144850_2(int,int);
#pragma aux C144850_2 "f_144850" modify exact [eax ecx edx];
int C144bf0_2(int,int);
#pragma aux C144bf0_2 "f_144bf0";
int C144cb6_3(int,int,int);
#pragma aux C144cb6_3 "f_144cb6" modify exact [eax ebx edx];
int __cdecl f_144fbf_k909(int,int);
#pragma aux f_144fbf_k909 "f_144fbf" modify exact [eax];
int C145259_1(int);
#pragma aux C145259_1 "f_145259";
int C145279_3(int,int,int);
#pragma aux C145279_3 "f_145279" modify exact [eax ebx edx];
int C1492b4_3(int,int,int);
#pragma aux C1492b4_3 "f_1492b4";
int C1492d1_1(int);
#pragma aux C1492d1_1 "f_1492d1" modify exact [eax ebx ecx edi esi];
int C1492ed_3(int,int,int);
#pragma aux C1492ed_3 "f_1492ed" modify exact [eax];
int C149336_1(int);
#pragma aux C149336_1 "f_149336" modify exact [eax];
//@ f_05b080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft und lädt eine Spielstanddatei ..\GAMES\<name> anhand eines direkt übergebenen
 *   Dateinamens (statt über den Listenindex wie f_05aed0): existiert die Datei, wird das Verzeichnis ..\TEMP\
 *   bis auf die Ausnahmedatei 0x90001 geleert, die Dateiversion über f_05b420 geprüft (und bei älterer Version
 *   konvertiert), der Spielstand über f_05a910 geladen und anschließend die von f_05b420 erzeugte Meldung
 *   angezeigt.
 * - Eingaben und Rückgabe: Die Funktion erhält das Diskmenü-Objekt self und den Dateinamen name. Sie gibt -1
 *   zurück, wenn die Datei nicht existiert, sonst 1.
 * - Wichtige Variablen: Die lokale Struktur f (Frame492) hält die Pfad- und Suchpuffer für den Dateizugriff auf
 *   ..\GAMES\ und ..\TEMP\.
 === Ende Beschreibung === */
int close492(int);
#pragma aux close492 "f_1492ed" modify exact [eax];
short valid492(int,int,int);
#pragma aux valid492 "f_05b420" modify exact [eax ebx edx];

int f_05b080(int self,const char *name)
{
 struct Frame492 { char path[80],pattern[80],removePath[80],find[44],saved[20]; } f;
 int result,buf,handle;
 strcpy(f.saved,name);
 sprintf(f.path,(const char *)ND32(d_1a9678),f.saved);
 handle=(short)f_144fbf_k909((int)f.path,0x200);
 if(handle==-1) { result=handle; } else {
 C145259_1(handle);
 sprintf(f.pattern,(const char *)ND32(d_1a9674),NA(d_1b6ed1));
 if((short)C1492b4_3((int)f.pattern,0,(int)f.find)==(short)0) {
  do {
   if(C144bf0_2((int)f.find+30,C144850_2(NA(d_1c2098),0x90001))) {
    sprintf(f.removePath,(const char *)ND32(d_1a9674),f.find+30);
    C149336_1((int)f.removePath);
   }
  } while((short)C1492d1_1((int)f.find)==(short)0);
 }
 close492((int)f.find);
 buf=C014540_3(500,NA(d_1a1794),0x329);
 C0d2f90_2(5,1);
 result=valid492(self,(int)f.saved,buf);
 if(result) {
  result=C05a910_2(self,(int)f.saved);
  C0d2e70_0();
  C0bf730_2(NA(d_1c2c64),C133fe0_2(NA(d_1c3498),buf));
  C014710_1(buf);
 } else {
  C0d2e70_0();
  C0bf730_2(NA(d_1c2c64),C133fe0_2(NA(d_1c3498),buf));
  result=1;
  C014710_1(buf);
 }
 }
 return result;
}

//@ f_05b230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt an den Dateianfang (Versatz 0) der geöffneten Spielstanddatei den
 *   16-Byte-Versionskopf, bestehend aus der 12-Byte-Kennung "DSA VERSION\0" (d_1a9680) und den vier Versions-
 *   und Statusbytes d_1a9694 (1), d_1a9693 (3), d_1a9692 (1) und d_1c2a50.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger self auf das Diskmenü-Objekt (mit dem offenen
 *   Dateihandle an Offset +0x28) und gibt die Summe der geschriebenen Bytes (im Erfolgsfall 16) zurück.
 * - Wichtige Variablen: Das Feld NW(self, 0x28) enthält das Dateihandle der zum Schreiben geöffneten .GAM-Datei.
 === Ende Beschreibung === */
int f_05b230(int self)
{
 int n;
 C145279_3(NW(self,0x28),0,0);
 n=C144cb6_3(NW(self,0x28),NA(d_1a9680),12);
 n+=C144cb6_3(NW(self,0x28),NA(d_1a9694),1);
 n+=C144cb6_3(NW(self,0x28),NA(d_1a9693),1);
 n+=C144cb6_3(NW(self,0x28),NA(d_1a9692),1);
 n+=C144cb6_3(NW(self,0x28),NA(d_1c2a50),1); return n;
}

//@ f_05b2c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest als Gegenstück zu f_05b230 ab Dateiversatz 0 den 16-Byte-Versionskopf einer geöffneten
 *   Spielstanddatei in die Felder p1->hdr (12 Bytes) sowie p1->b1f, p1->b1e, p1->b1d und p1->b1c des
 *   Diskmenü-Objekts ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt die Anzahl der
 *   gelesenen Bytes (bei vollständigem Kopf 16) zurück.
 * - Wichtige Variablen: Das Byte p1->b1e (Dateiversatz 0x0d) speichert die Hauptversionsnummer (3 für *Schatten
 *   über Riva*), p1->b1d (Versatz 0x0e) die Unterversion (1).
 === Ende Beschreibung === */
int f_05b2c0(Dsk *p1)
{
    f_145279(p1->fd, 0, 0);
    int s = f_144e8b(p1->fd, p1->hdr, 0xc);
    s += f_144e8b(p1->fd, &p1->b1f, 1);
    s += f_144e8b(p1->fd, &p1->b1e, 1);
    s += f_144e8b(p1->fd, &p1->b1d, 1);
    return f_144e8b(p1->fd, &p1->b1c, 1) + s;
}

//@ f_05b340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht die Spielstanddatei ..\GAMES\<Name>.GAM des Listeneintrags p2 von der Festplatte
 *   (f_149336) und übermalt anschließend den Namenslistenbereich auf dem Bildschirm (56x82 Pixel ab (32, 59))
 *   mit der Hintergrundfarbe 0xce.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und den Listenindex p2 des
 *   zu löschenden Spielstands. Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array p1->names[p2] liefert den bis zu 8 Zeichen langen Stammnamen der zu löschenden
 *   .GAM-Datei.
 === Ende Beschreibung === */
struct Guard {
    int flag;
    Guard() { if (f_0d3860() == 1) { f_0d2710(); flag = 1; } else flag = 0; }
    ~Guard() { if (flag == 1) f_0d26e0(); }
};
void f_05b340(Dsk *p1, short p2)
{
    char buf[40]; char name[16];
    strcpy(name, p1->names[p2]);
    strcat(name, d_1b6ed5);
    f_14572e(buf, d_1a9678, name);
    f_149336(buf);
    Guard guard;
    short y = 0x3b;
    int i;
    for (i = 0; (short)i < 0x52; i++) {
        f_1483f0(d_1a34e0, 0x20, y, 0x38, -50);
        y++;
    }
}

//@ f_05b420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die Spielstanddatei ..\GAMES\<p2> und prüft ihren 16-Byte-Versionskopf: stimmt "DSA
 *   VERSION" und die Hauptversion 3 (d_1a9693), wird bei korrekter Unterversion 1 (d_1a9692) sofort 1
 *   zurückgegeben (bzw. bei falscher Unterversion die Meldung 0x9030021 formatiert und 0 geliefert). Hat die
 *   Datei einen anderen 16-Byte-Kopf (z. B. ältere Spielstandversion), versucht ein Konverter-Objekt (0x328
 *   Bytes, f_0a2800/f_0a2810) den Stand umzuwandeln, speichert ihn bei Erfolg über f_05a020 im neuen Format ab
 *   (Rückgabe 2, Meldung 0x9030016 oder 0x9030013) und lädt anschließend den Grundzustand aus Datei 0x90000.
 * - Eingaben und Rückgabe: Die Funktion erhält das Diskmenü-Objekt p1, den Zeiger p2 auf den Dateinamen und den
 *   500-Byte-Ausgabepuffer p3 für den Meldungstext. Sie gibt 1 bei einem aktuellen Spielstand, 2 nach
 *   erfolgreicher Konvertierung und 0 bei einer unbrauchbaren oder fehlenden Datei zurück.
 * - Wichtige Variablen: Das globale Dateihandle d_1c2140 und p1->fd halten den Dateideskriptor während der
 *   Kopfprüfung und Umwandlung.
 === Ende Beschreibung === */
extern volatile short d_1c2140_v;
#pragma aux d_1c2140_v "d_1c2140";
unsigned f_05b420(Dsk *p1, int p2, unsigned char *p3)
{
    Msg m;
    char *hdr; short saved_fd; short saved_sum;
    int sum;
    unsigned result;
    int object;
    f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    f_14572e(d_1c21b4, d_1a9678, p2);
    p1->fd = d_1c2140 = f_144fbf(d_1c21b4, 0x202);
    f_145279(p1->fd, 0, 0);
    hdr = p1->hdr;
    sum = f_144e8b(p1->fd, hdr, (unsigned)12)
        + f_144e8b(p1->fd, &p1->b1f, 1);
    sum += f_144e8b(p1->fd, &p1->b1e, 1);
    sum += f_144e8b(p1->fd, &p1->b1d, 1);
    sum += f_144e8b(p1->fd, &p1->b1c, 1);
    f_145279(p1->fd, 0, 0);
    if (strcmp((*(short*)&saved_sum = sum, hdr), d_1a9680) != 0 || p1->b1e != d_1a9693 || (short)sum != 16) {


    saved_fd = d_1c2140;
    if ((short)saved_sum == 16) {
        object = (int)operator new(0x328, mark(d_1a1794, 0x3af));
        object = object ? f_0a2800(object) : object;
        result = f_0a2810(object, (short)saved_fd);
        if (object) delete (char *)f_0a2800(object, 0);
    } else {
        result = 0;
    }
    f_145259((short)saved_fd);
    if ((short)result == (short)0) {
        m.tables.tail.numbers[1] = f_133fe0(A(d_1c3498), p2);
        if (d_1c2140 != -1)
            f_0e93f0(A(d_1c38b0), (int)p3, 0x9030012);
        else
            f_0e93f0(A(d_1c38b0), (int)p3, 0x9030020);
    } else if ((short)result == -1) {
        m.tables.tail.numbers[1] = f_133fe0(A(d_1c3498), p2);
        f_0e93f0(A(d_1c38b0), (int)p3, 0x9030016);
        f_05a020(p1, p2);
        result = 2;
    } else {
        f_05a020(p1, p2);
        m.tables.tail.numbers[1] = f_133fe0(A(d_1c3498), p2);
        f_0e93f0(A(d_1c38b0), (int)p3, 0x9030013);
        result = 2;
    }
    f_05a910(p1, (int)d_1c2098.f_144850(0x90000));
    f_1254a0((int)&m, 0);
    return result;

    }
    if (d_1a9692 != p1->b1d) {
        m.tables.tail.numbers[1] = f_133fe0(A(d_1c3498), p2);
        f_0e93f0(A(d_1c38b0), (int)p3, 0x9030021);
        result = 0;
    } else {
        result = 1;
        *p3 = 0;
    }
    f_145259(d_1c2140_v);
    f_1254a0((int)&m, 0);
    return result;
}
