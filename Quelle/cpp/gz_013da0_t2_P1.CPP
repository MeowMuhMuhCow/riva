/* === Beschreibung (Katalog) ===
 * Einheit gz_013da0_t2 (0x0144e0 - 0x014540)
 *
 * Überblick
 * Diese kleine Einheit enthält die DPMI-Speicherabfragefunktion f_0144e0 am Übergang zwischen alfdisk.cpp und
 * der Speicherverwaltung alloc.cpp.
 === Ende Beschreibung === */
// P3 17/24 gleich (suche.py 25.10.2026, Basis gz_013da0_P1.CPP)
// I9: aus G013DA0_REST.CPP uebernommen (Stufe-2-Stand), Marken 9 neu
// G013DA0 REST: alfdisk.cpp-Teil 0x13DA0-0x144D2 (23 Funktionen, 3 offen: 013DF0/013F20/014020 +0141E0/0142A0/014480 klein). Zweite Einheit alloc.cpp ab 0x144E0 -> G0144E0_OK.CPP
// gz_013da0.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x13DA0-0x14540. Klasse AlfDisk (ALF-Archiv): Datei oeffnen/pruefen, Gruppen- und Eintragstabellen laden, Lesen/Suchen, DPMI-Speicherabfrage.
#include <string.h>
#include <i86.h>
extern char d_1c1190[];                                   // zmain, fremdes Datenstueck 1C1190-1C3914
void f_0ed8f0(void *obj, long code, const char *s, ...);
int f_144fbf(const char *name, int mode, ...);            // open
int f_144e8b(int h, void *buf, unsigned n);               // read
long f_145279(int h, long pos, int whence);               // lseek
int f_145259(int h);                                      // close
long f_1455a4(int h);                                     // tell
void f_1455b5();
int f_145702(int intno, union REGS *in, union REGS *out, struct SREGS *s);
#pragma pack(1)
#define PID long
#define LO(p) ((short)(p))
#define HI(p) ((short)(((p) - (short)(p)) >> 16))
struct Rec { signed char c0; char r1[13]; unsigned n; char r12[6]; long off; };   // 0x1C Bytes
struct VBase {
  virtual void v0(); virtual int v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual int v5(int a, int b); virtual void v6(); virtual void v7(int a); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual int v12(); virtual void v13(); virtual void v14();
  virtual int v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual short v22(); virtual void v23(); virtual void v24();
  virtual void v25(void *out, short n);
};
struct AlfDisk : VBase {
  char *name;
  long magic; char h0c[4]; short s10; long p12; char h16[2]; long l18; char h1c[2]; long l1e; char h22[2]; long l24; char h28[16];
  int fd; short cur3c; short cur3e; short s40; short *p42;
  Rec e46; Rec e62; short *p7e;
  void chk(); void chk2(); void ldg(short di);
  Rec *f_013da0(); int f_013db0(int a); int f_013de0(); int f_013df0(PID p2); short *f_013f20(int g, unsigned *cnt);
  int f_014020(PID p2, int unused); int f_014190(int a, int b); void f_0141d0(void *buf); void f_0141e0(void *buf, unsigned n);
  int f_014210(); void f_014220(); unsigned f_014240(); int f_014250(int a); long f_014280(); long f_0142a0(long pos, short wh);
  short f_014300(); int f_014310(int a); short f_014350(); int f_0143c0(signed char *buf, short idx);
  short f_014410(); int f_014420(signed char *buf, int g); void f_014480(char *p2, int p3);
  void f_013c00(char *p, Rec r);
};
inline void AlfDisk::chk() {
  int ok = 0;
  fd = f_144fbf(name, 0x200, 0x180);
  if (fd > 0) { f_144e8b(fd, &magic, 0x30); if (magic == 0x20464c41) ok = 1; }
  if (!ok) f_0ed8f0(d_1c1190, 0x29a000e, name);
}
inline void AlfDisk::chk2() {
  if (fd == -1) chk();
}
inline void AlfDisk::ldg(short di) {
  if (di != cur3e) {
    f_145279(fd, di * 28 + l1e, 0);
    f_144e8b(fd, &e46, 0x1c);
    cur3e = di;
    f_145279(fd, e46.off + l24, 0);
    f_144e8b(fd, p7e, e46.n * 2);
    cur3e = di;
  }
}
#define CHK if (fd == -1) chk()
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0144e0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x0144e0
 * - Aufgabe im Spiel: Fragt über den DPMI-Interrupt 0x31 mit der Funktionsnummer AX = 0x0500 (*Get Free Memory
 *   Information*) den aktuellen Stand des freien Protected-Mode-Speichers ab und gibt das erste 32-Bit-Feld
 *   (info[0], größter verfügbarer freier Speicherblock in Bytes) zurück.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Die Größe des größten zusammenhängenden freien Speicherblocks in Bytes (info[0]).
 * - Wichtige Variablen:
 *   - Lokale Registerstrukturen r (REGS), s (SREGS) und das 48-Byte-Antwortfeld info[12].
 === Ende Beschreibung === */
int f_0144e0()
{
    union REGS r;
    struct SREGS s;
    int info[12];
    f_1455b5();
    r.x.eax = 0x500;
    memset(&s, 0, sizeof(s));
    s.es = FP_SEG(info);
    r.x.edi = FP_OFF(info);
    f_145702(0x31, &r, &r, &s);
    return info[0];
}
