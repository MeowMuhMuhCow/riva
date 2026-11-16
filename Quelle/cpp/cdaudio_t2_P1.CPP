/* === Beschreibung (Katalog) ===
 * Einheit cdaudio_t2 (0x0002f883 - 0x0002fedc)
 *
 * Überblick
 *
 * Die Einheit cdaudio_t2 bildet den zweiten Teil der CD-Audio-Steuerung (CDAUDIO.CPP). Sie stellt Funktionen zum
 * automatischen Wiederholen eines abgelaufenen Musikstücks, zum Auslesen der aktuellen
 * Q-Channel-Abspielposition, zum Öffnen und Schließen der CD-Schublade sowie zum Regeln der CD-Lautstärke
 * bereit.
 === Ende Beschreibung === */
// OPT -4r -od -zp1 -s
// P1 0/4 gleich
// cdaudio.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02F883-0x02FEDC
#include <string.h>
#include "RIVAMEM.H"



int f_02e41a(int p1);
int f_0ce7c0(int p1);
int f_0ce7e0(int p1);
struct Msf {
  unsigned char f, s, m, x;
  Msf(const Msf &o) { f = o.f; s = o.s; m = o.m; x = o.x; }
  unsigned frames() const { return (s + m * 60) * 75 + f; }
  int operator<(const Msf &o) const { return frames() < o.frames(); }
};
struct Lk { int v; Lk(); ~Lk(); };
int f_02f12f(int p1, Msf *p2, Msf *p3);
//@ f_02f883
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der im CD-Objekt gespeicherten Start- und Endmarken (a bei +0x02 und b bei
 *   +0x06), ob ein gültiger Abspielbereich gesetzt war und das Laufwerk inzwischen mit dem Abspielen fertig ist
 *   (*(int *)(p1 + 10) == 0). Ist dies der Fall, wird derselbe Abschnitt sofort über f_02f12f erneut gestartet,
 *   um eine Endlosschleife der Hintergrundmusik zu erreichen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt 1 zurück, wenn die Wiedergabe neu
 *   angestoßen wurde, sonst 0.
 * - Wichtige Variablen: Liest die Msf-Zeitmarken a und b, prüft das Bereitschaftsflag p1 + 0x12 sowie das
 *   Spielt-Flag p1 + 10 und setzt bei offener Lade den Fehlercode 0x3bd in p1 + 0x3a.
 === Ende Beschreibung === */
int f_02f883(int p1)
{
  struct Reader {
    static unsigned frames(const Msf &v) { return (v.m*60 + v.s)*75 + v.f; }
  };
  Msf a(*(Msf *)(p1 + 2));
  Msf b(*(Msf *)(p1 + 6));
  int r = 0;
  *(short *)(p1 + 0x3a) = 0;
  if (Reader::frames(a) > 0 && Reader::frames(b) > Reader::frames(a)) {
      Lk lk;
      f_02e41a(p1);
      if (*(int *)(p1 + 0x12) == 0) {
        *(short *)(p1 + 0x3a) = 0x3bd;
      } else if (*(int *)(p1 + 10) == 0) {
        f_02f12f(p1, &a, &b);
        r = 1;
      }
  }
  return r;
}

// Verdeckte Funktionen zwischen 02f883 und 02fc49.
short f_02fa06(int p1) { return *(short *)p1; }
unsigned char f_02fa2c(int p1) { return *(unsigned char *)(*(int *)(p1+0x16)+1); }
unsigned char f_02fa55(int p1) { return *(unsigned char *)(*(int *)(p1+0x16)+2); }

void f_02fa7e(int p1, void *p2, short p3)
{
  struct Track { char b[7]; };
  *(short *)(p1+0x3a) = 0;
  f_02e41a(p1);
  if (*(int *)(p1+0x12) == 0) {
    *(short *)(p1+0x3a) = 0x3bd;
  } else if (p3 < *(unsigned char *)(*(int *)(p1+0x16)+1) || p3 > *(unsigned char *)(*(int *)(p1+0x16)+2)+1) {
    *(short *)(p1+0x3a) = 0x3be;
  } else {
    Track *src = (Track *)(*(int *)(p1+0x1a)+(p3-1)*7);
    Track *dst = (Track *)p2;
    Track *src2 = src;
    *dst = *src2;
    Track *result = dst;
  }
}

void f_02fb26(int p1, unsigned char *p2)
{
  int f_05ff00(int, void *, int);
  int f_05fee0(int);
  int f_05ff30(int, void *, int);
  int f_02e273(int);
  int f_149cf5(void *, const void *, int);
  struct Command { unsigned char command, subcommand, data[10]; } cmd;
  unsigned char tmp;
  cmd.command = 0xc;
  cmd.subcommand = 1;
  memset(cmd.data,0,10);
  *(unsigned char *)(*(int *)(p1+0x1e)+2) = 3;
  *(short *)(*(int *)(p1+0x1e)+0x12) = 11;
  f_05ff00(p1+0x2e,&cmd,11);
  *(int *)(*(int *)(p1+0x1e)+0xe) = f_05fee0(p1+0x2e);
  f_02e273(p1);
  f_05ff30(p1+0x2e,&cmd,11);
  f_149cf5(p2,cmd.data,10);
  tmp = (p2[0]&0xf0)>>4;
  p2[0] &= 0xf;
  p2[0] += (unsigned char)(tmp*10);
  tmp = (p2[1]&0xf0)>>4;
  p2[1] &= 0xf;
  p2[1] += (unsigned char)(tmp*10);
  tmp = p2[4];
  p2[4] = p2[2];
  p2[2] = tmp;
  tmp = p2[8];
  p2[8] = p2[6];
  p2[6] = tmp;
}
//@ f_02fc49
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert den Laufwerksstatus über f_02e41a(p1) und gibt zurück, ob die Laufwerkstür
 *   geschlossen und ein Medium eingelegt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt den Bereitschaftsstatus aus *(int
 *   *)(p1 + 0x12) zurück.
 * - Wichtige Variablen: Löscht vorab *(short *)(p1 + 0x3a) und liest p1 + 0x12.
 === Ende Beschreibung === */
int f_02fc49(int p1)
{
  *(short *)(p1 + 0x3a) = 0;
  f_02e41a(p1);
  return *(int *)(p1 + 0x12);
}
//@ f_02fc80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den aktuellen Laufwerksstatus über f_02e41a(p1) ab und gibt zurück, ob sich das
 *   CD-Laufwerk im Pause-Zustand befindet.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger p1 entgegen und liefert den Wert aus *(int *)(p1
 *   + 0x0e) zurück.
 * - Wichtige Variablen: Liest das Statusfeld p1 + 0x0e.
 === Ende Beschreibung === */
int f_02fc80(int p1)
{
  *(short *)(p1 + 0x3a) = 0;
  f_02e41a(p1);
  return *(int *)(p1 + 0xe);
}
//@ f_02fcb7
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert den Treiberstatus über f_02e41a(p1) und gibt zurück, ob momentan eine
 *   CD-Audiowiedergabe läuft.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt das Busy-/Play-Flag aus *(int *)(p1
 *   + 10) zurück.
 * - Wichtige Variablen: Liest das Feld p1 + 10 (st).
 === Ende Beschreibung === */
int f_02fcb7(int p1)
{
  *(short *)(p1 + 0x3a) = 0;
  f_02e41a(p1);
  return *(int *)(p1 + 10);
}

// Im bisher ungeteilten Originalbereich folgen drei weitere Funktionen.
void f_02fcee(int p1)
{
  int f_02ee42(int);
  char *f_05fef0(int);
  int f_05fee0(int);
  int f_02e273(int);
  *(short *)(p1 + 0x3a) = 0;
  f_02ee42(p1);
  *f_05fef0(p1 + 0x2e) = 0;
  *(char *)(*(int *)(p1 + 0x1e) + 2) = 0xc;
  *(int *)(*(int *)(p1 + 0x1e) + 0xe) = f_05fee0(p1 + 0x2e);
  *(short *)(*(int *)(p1 + 0x1e) + 0x12) = 1;
  f_02e273(p1);
  *(int *)(*(int *)(p1 + 0x1e) + 0xe) = 0;
  *(short *)(*(int *)(p1 + 0x1e) + 0x12) = 0;
}

void f_02fd74(int p1)
{
  char *f_05fef0(int);
  int f_05fee0(int);
  int f_02e273(int);
  *(short *)(p1 + 0x3a) = 0;
  f_02e41a(p1);
  if (*(int *)(p1 + 0x12) == 0) {
    *f_05fef0(p1 + 0x2e) = 5;
    *(char *)(*(int *)(p1 + 0x1e) + 2) = 0xc;
    *(int *)(*(int *)(p1 + 0x1e) + 0xe) = f_05fee0(p1 + 0x2e);
    *(short *)(*(int *)(p1 + 0x1e) + 0x12) = 1;
    f_02e273(p1);
    *(int *)(*(int *)(p1 + 0x1e) + 0xe) = 0;
    *(short *)(*(int *)(p1 + 0x1e) + 0x12) = 0;
  }
}

void f_02fe03(int p1, short p2)
{
  struct Volume { char b[9]; };
  extern Volume d_1a0750;
  int f_05ff00(int, const void *, int);
  int f_05fee0(int);
  int f_02e273(int);
  Volume v = d_1a0750;
  *(short *)(p1 + 0x3a) = 0;
  if (p2 < 0) p2 = 0;
  if (p2 > 100) p2 = 100;
  p2 *= 255;
  p2 /= 100;
  v.b[2] = p2;
  v.b[4] = p2;
  f_05ff00(p1 + 0x2e, &v, 9);
  *(char *)(*(int *)(p1 + 0x1e) + 2) = 0xc;
  *(int *)(*(int *)(p1 + 0x1e) + 0xe) = f_05fee0(p1 + 0x2e);
  *(short *)(*(int *)(p1 + 0x1e) + 0x12) = 9;
  f_02e273(p1);
  *(int *)(*(int *)(p1 + 0x1e) + 0xe) = 0;
  *(short *)(*(int *)(p1 + 0x1e) + 0x12) = 0;
}
