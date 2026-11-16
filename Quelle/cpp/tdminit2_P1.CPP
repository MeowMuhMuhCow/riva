/* === Beschreibung (Katalog) ===
 * Einheit tdminit2 (0x11f910 - 0x1206a0)
 *
 * Überblick
 * Diese Einheit implementiert die Initialisierung, Speicherprüfung und Szenarienverwaltung der 3D-Dungeon- und
 * Stadtkarten-Engine (TDMINIT.CPP, *Three-Dimensional Map Init*). Sie lädt die 3D-Szenarien aus DUNGEON.ALF bzw.
 * ..\CTEMP\, prüft vorab den verfügbaren Arbeitsspeicher (und legt bei Speichermangel automatisch einen
 * Notfall-Spielstand RIVA_TMP.GAM an), konfiguriert Lichtweite, Kamerahöhe (z. B. für Zwerge, Elfen und
 * Menschen) sowie Bewegungsgeschwindigkeiten und verwaltet die 3D-Automap-Aufrufe.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 22/25 gleich (suche.py 25.10.2026, Basis tdminit2_P1.CPP)
// tdminit2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11F920-0x1206A0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
unsigned f_014a60(void);
int f_019db0(int p1);                                   // reg eax stapel 0
int f_019eb0(int p1);                                   // reg eax stapel 0
int f_019f30(int p1);                                   // reg eax stapel 0
int f_019fc0(int p1);                                   // reg eax stapel 0
int f_01a4b0(int p1);                                   // reg eax stapel 0
int f_01a560(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_01a5d0(int p1);                                   // reg eax stapel 0
int f_0256c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_025740(int,int);
int f_025750(int p1, int p2, int p3, int p4, int p5);   // reg eax stapel 4
int f_0257f0(int p1, int p2);                           // reg eax edx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0

int f_059d50(int); int f_059d50(int,int);
int f_05a020(int p1, int p2);                           // reg eax edx stapel 0
int f_05ecf0(int);
int __cdecl f_099ef0(int,int,int);
int f_09a470(int p1);                                   // reg eax stapel 0
int f_0b13d0(int);
int f_0bd2e0(int p1, int p2);                           // reg edx stapel 0
int f_0bdbc0(int p1);                                   // reg eax stapel 0
int f_0bdbf0(int p1);                                   // reg eax stapel 0
int f_0bdd50(int,int,int,int);
int f_0bdde0(int,int);
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce650();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0da910(int,int,int,int,int,int,int);
int f_0da990(int,int);
signed char f_0dd410(int,int);
int f_0dd520(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0ddf50(int p1);                                   // reg eax stapel 0
int f_0ddfc0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
short f_0de820(int);
int f_0de830(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8b0(int p1, int p2);                           // reg eax edx stapel 0
short f_0de920(int);
                   // reg eax edx ebx stapel 0

                                   // reg eax stapel 0
int f_11f5f0();                                         // reg - stapel 0
int f_11f6e0();                                         // reg - stapel 0
int f_1206c0();                                         // reg - stapel 0
int f_1206f0();                                         // reg - stapel 0
int f_121d80();                                         // reg - stapel 0
int f_1220c0();                                         // reg - stapel 0
int f_122120(int p1);                                   // reg eax stapel 0
int f_122190();                                         // reg - stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_13fd60(int p1);                                   // reg eax stapel 0

int f_14dc28(int p1);                                   // reg eax stapel 0
int f_15164c();                                         // reg - stapel 0
int f_155900(int p1);                                   // reg eax stapel 0
int f_15674c();                                         // reg - stapel 0
int f_161fd8(int,int,int,signed char);
int f_162208();                                         // reg - stapel 0
int f_16232c(int p1);                                   // reg eax stapel 0
int f_163a98(int p1);                                   // reg eax stapel 0
int f_163b08(int p1, int p2);                           // reg eax edx stapel 0
int f_163bac(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a0108;                    // 0x1A0108
extern char d_1a539c;
extern char d_1a54c0;
extern short d_1a7fbc;
extern short d_1a7fbe;
extern unsigned short d_1a7fc0;
extern short d_1a7fc2;
extern int d_1a7fc4;                    // 0x1A7FC4
extern int d_1a7fc8;                    // 0x1A7FC8
extern short d_1a80c4;
extern int d_1a89ac;                    // 0x1A89AC
extern float d_1a8ae8;
extern float d_1a8aec;
extern int d_1a8af0;                    // 0x1A8AF0
extern int d_1a965c;
extern short d_1a9696;
extern char d_1a96a4;
extern signed char d_1a9942;
extern char d_1a9950;
extern short d_1a995c;
extern short d_1a995e;
extern short d_1a9960;
extern int d_1a9978;                    // 0x1A9978
extern unsigned d_1a9a1c;
extern int d_1a9b14;                    // 0x1A9B14
extern int d_1a9b18;                    // 0x1A9B18
extern int d_1a9b24;                    // 0x1A9B24
extern const char d_1b8499[];
extern const char d_1b849b[];
extern const char d_1b849d[];
extern const char d_1b84b4[];
extern char d_1baac0;
extern int d_1bd6c0;                    // 0x1BD6C0
extern char d_1bf230;
extern short d_1bf51c;
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern signed char d_1bfaec;
extern short d_1bfb18;
extern signed char d_1bfb1c;
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0ae8;                    // 0x1C0AE8
extern int d_1c0aec;                    // 0x1C0AEC
extern int d_1c0af0;                    // 0x1C0AF0
extern int d_1c0af4;                    // 0x1C0AF4
extern int d_1c0af8;                    // 0x1C0AF8
extern int d_1c0afc;                    // 0x1C0AFC
extern char d_1c0b00;
extern int d_1c0b94;                    // 0x1C0B94
extern signed char d_1c0b9b;
extern unsigned char d_1c0b9c;
extern int d_1c0c4c;                    // 0x1C0C4C
extern char d_1c11a0;
extern char d_1c11b8;
extern char d_1c14c4;

extern volatile short d_1c2198; // verhindert Wegoptimieren von d_1c2198 = 1 vor bedingtem d_1c2198 = 0 in f_11f920
extern char d_1c2a84;
extern char d_1c2c64;
extern char d_1c3498;
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c8;                    // 0x1C90C8
extern int d_1c90cc;                    // 0x1C90CC
extern const char d_1a7f9c[];           // Text 0x1A7F9C
extern const char d_1a80cc[];           // Text 0x1A80CC
extern const char d_1b8388[];           // Text 0x1B8388
extern const char d_1b840d[];           // Text 0x1B840D
extern const char d_1b846f[];           // Text 0x1B846F
extern const char d_1b847c[];           // Text 0x1B847C
extern const char d_1b8488[];           // Text 0x1B8488
extern const char d_1b8491[];           // Text 0x1B8491
extern const char d_1b84a3[];           // Text 0x1B84A3
extern const char d_1b84ac[];           // Text 0x1B84AC

int f_144570(void);
void f_148534(int);
int f_14572e(char *, const char *, ...);
int f_147c84(int,int,int);
int f_144bf0(const char *, const char *);
int f_014710(int);
extern short d_1bb244;
extern const char d_1b8392[];
extern const char d_1b841a[];
extern const char d_1b8425[];
struct TdmInit2A { ~TdmInit2A(); };
struct TdmInit2B { ~TdmInit2B(); };
#pragma inline_depth(0)
#define AD(x) ((int)&(x))
#define EQM(x,v) (((x)==(v))?1:0)
char *f_120620(short p1);
void f_121050(void);
void f_11fd40(int p1, int p2);
int __stdcall f_11f560(int p1);
void f_11f570(int p1, int p2, int p3, int p4);
void f_11f580(int p1);
void f_11f590(int p1, int p2, int p3);
int f_164994(int p1, int p2, int p3);
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_11f920
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet aus der 3D-Ansicht heraus die Automap bzw. Ortskarte in einem von vier Modi (p1 == 1..4),
 *   berücksichtigt dabei Sonderregeln für Unterwasser- und Spezialgebiete (0x17-0x19, 0x1b) und übernimmt bei
 *   einem gewählten Schnellreiseziel (p1 == 2) die neuen Zielkoordinaten.
 * - Eingaben: Die Funktion erhält im Parameter p1 den gewünschten Kartenmodus (1 bis 4).
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
int f_019eb0(int); int f_019fc0(int); int f_019db0(int); int f_01a560(int,int*,int*);
int f_01a5d0(int); int f_01a4b0(int); int f_019f30(int);
struct MG { int h; MG(); ~MG(); };
void f_11f920(short p1)
{
	int flag;
	int fl2;
	int a, b;
	f_0ce650();
	MG mg;
	d_1c0c4c++;
	f_0d2f90(0, 1);
	flag = 0;
	switch (f_0de820(d_1c0004)) {
	case 0x17: case 0x18: case 0x19:
		if (f_0dd410(d_1c0004, 1) == 5) flag = 1;
		break;
	}
	fl2 = flag;
	if (flag == 1) {
		f_019eb0(AD(d_1c2a84));
	} else if (f_0de820(d_1c0004) == 0x1b && EQ(d_1bfaec, 1)) {
		f_019fc0(AD(d_1c2a84));
		f_019db0(AD(d_1c2a84));
	}
	d_1c0ae8 = 1;
	switch (p1) {
	case 2:
		{
			int r;
			d_1a9960 = d_1a80c4;
			r = f_01a560(AD(d_1c2a84), &a, &b);
			f_122190();
			if (r == 1) f_0dd520(d_1c0004, a, b);
		}
		break;
	case 3:
		f_01a5d0(AD(d_1c2a84));
		break;
	case 4:
		f_019db0(AD(d_1c2a84));
	case 1:
		f_01a4b0(AD(d_1c2a84));
		break;
	}
	if (fl2 == 1) f_019f30(AD(d_1c2a84));
	d_1c0ae8 = 0;
	d_1c0c4c--;
	d_1c2198 = 1;
	if (p1 == (short)2) d_1c2198 = 0;
}
//@ f_11fab0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft an den übergebenen 3D-Kartenkoordinaten über die Kollisionsroutine der 3D-Engine (f_15164c), ob
 *   sich dort ein betretbares oder auslösbares Feld befindet.
 * - Eingaben: Die Funktion erhält in den Parametern p1 und p2 die X- und Y-Koordinaten in der 3D-Szenerie.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Prüfung erfolgreich war und kein Fehlerflag (d_1a9942)
 *   gesetzt wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_11fab0(int p1, int p2)
{
	d_1c90c8 = p2;
	d_1c90c0 = p1;
	d_1a9960 = 0;
	if (f_15164c() == 1 && d_1a9942 == 0) return 1;
	return 0;
}
//@ f_11faf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Beendet die aktuell geladene 3D-Szenerie, gibt das zugehörige Orts-Handler-Objekt (d_1bd6c0) sowie
 *   die Ressourcen der 3D-Engine (f_162208) frei und setzt die aktiven Szenario-Kennungen auf -1 zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11faf0(void)
{
	int q;
	if (f_0de820(d_1c0004) != d_1a7fc2) f_11f5f0();
	d_1a9696 = (short)-1;
	d_1a7fbc = (short)-1;
	q = d_1bd6c0; if (q != 0) ((void (*)(int, int))(*(int *)(*(int *)(q + 8) + 0x10)))(q, 2);
	d_1bd6c0 = 0;
	f_162208();
	d_1c2198 = 1;
}
//@ f_11fb50
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die für die 3D-Ansicht angelegten Bildpuffer, Bedienleisten und Arbeitsspeicherblöcke (d_1c0af0
 *   bis d_1c0afc) wieder frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11fb50(void)
{
	f_1206f0();
	if (d_1c0af4 != 0) {
		delete (TdmInit2A *)d_1c0af4;
		d_1c0af4 = 0;
	}
	if (d_1c0af0 != 0) {
		delete (TdmInit2B *)d_1c0af0;
		d_1c0af0 = 0;
	}
	if (d_1c0af8 != 0) d_1c0af8 = f_014710(d_1c0af8);
	if (d_1c0afc != 0) d_1c0afc = f_014710(d_1c0afc);
}
//@ f_11fbe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Schließt und löscht den Archiv-Manager (d_1c0aec) für die 3D-Dungeon-Daten (DUNGEON.ALF).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11fbe0(void)
{
	int p = d_1c0aec;
	if (p != 0) operator delete((void *)f_025740(p, 0));
	d_1c0aec = 0;
}
//@ f_11fc00
/* === Beschreibung (Katalog) ===
 * - Zweck: Richtet die Maustasten- und Tastaturbelegungstabelle (d_1bf520, d_1bf524) abhängig davon ein, ob die
 *   3D-Ansicht im kleinen Fenster oder im Vollbildmodus (d_1bfb1c) läuft.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11fc00(void)
{
	if (EQM(d_1bfb1c, 1)) d_1bf520 = AD(d_1a54c0);
	else d_1bf520 = AD(d_1a539c);
	d_1bf524 = (int)f_121050;
	d_1bf51c = 1;
}
//@ f_11fc50
/* === Beschreibung (Katalog) ===
 * - Zweck: Entpackt die beiden Datendateien (k + 1 und k + 0x1d) eines 3D-Szenarios p1 (0..27) aus dem Archiv
 *   DUNGEON.ALF in das temporäre Verzeichnis.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Szenario-Index (0 bis 27).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Index gültig war und die Dateien bereitgestellt wurden,
 *   sonst 0.
 === Ende Beschreibung === */
int f_11fc50(short p1)
{
	short k = p1;
	int r = 0;
	if (k >= 0 && k < 0x1c) {
		f_0257f0(d_1c0aec, k + 1);
		f_0257f0(d_1c0aec, k + 0x1d);
		r = 1;
	}
	return r;
}
//@ f_11fc90
/* === Beschreibung (Katalog) ===
 * - Zweck: Ermittelt das aktuell benötigte 3D-Szenario der Heldengruppe, kopiert dessen Dateinamen nach
 *   d_1c0b00, entpackt die zugehörigen Szenariodateien und aktualisiert die Szenario-Kennungen im
 *   Gruppenzustand.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11fc90(void)
{
	short s = 0;
	short h = d_1a9696;
	if (h == (short)-1) s = f_0de820(d_1c0004);
	else s = -1;
	if (s >= 0 && s < 0x1c) strcpy(&d_1c0b00, f_120620(s));
	if (s != -1) {
		if (s >= 0 && s < 0x1c) {
			f_0257f0(d_1c0aec, s + 1);
			f_0257f0(d_1c0aec, s + 0x1d);
		}
		d_1a7fbc = s;
		f_0de830(d_1c0004, s);
		f_0de810(d_1c0004, -1);
	}
}
//@ f_11fd40
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt einen kritischen Lade- oder Speicherfehler der 3D-Engine, indem der aktuelle Spielstand
 *   automatisch unter dem Dateinamen RIVA_TMP.GAM (p1) gesichert, die übergebene Fehlermeldung (p2) auf dem
 *   Bildschirm angezeigt und das Programm anschließend kontrolliert beendet wird.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Dateinamen des Notfall-Spielstands und in p2 den Zeiger
 *   auf den Fehlertext.
 * - Rückgabewert: Die Funktion kehrt nicht zum Aufrufer zurück, da sie das Programm über f_148534(1) beendet.
 === Ende Beschreibung === */
void f_11fd40(int p1, int p2)
{
	int s, p, t_;
	f_0b13d0(1);
	s = f_147c84((int)operator new[](0x300, mark(d_1a7f9c, 0x15e)), 0x100, AD(d_1baac0));
	s = s ? s : 0;
	t_ = (int)operator new(0x652, mark(d_1a7f9c, 0x160));
	p = (t_ != 0) ? f_059d50(t_) : t_;
	f_05a020(p, p1);
	if (p) operator delete((void *)f_059d50(p, 0));
	f_09a470(s);
	f_099ef0(s + 0x1e0, 0xa0, 0x60);
	f_0c0020(AD(d_1c2c64), 5);
	f_0bf730(AD(d_1c2c64), f_133fe0(AD(d_1c3498), p2));
	operator delete((void *)s);
	f_144570();
	f_148534(1);
}
//@ f_11fe20
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest aus der Szenariotabelle den benötigten Mindest-Speicherbedarf (inklusive 200.000 Bytes
 *   Sicherheitsreserve) für niedrige und hohe Texturdetailstufe des Szenarios p1 aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Szenario-Index sowie in p2 und p3 zwei Ausgabepointer für
 *   die beiden Speicherwerte.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_11fe20(short p1, int *p2, int *p3)
{
	*p2 = *(int *)((char *)&d_1a7fc4 + p1 * 8) + 200000;
	*p3 = *(int *)((char *)&d_1a7fc8 + p1 * 8) + 200000;
	return 1;
}
//@ f_11fe50
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob für das 3D-Szenario p1 in der gewünschten Detailstufe p2 genügend freier Speicher vorhanden
 *   ist, gibt bei Speichermangel schrittweise Caches frei und stuft die Detailstufe notfalls auf 0 (niedrig)
 *   oder 2 (kritischer Speichermangel) herab.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Szenario-Index und in p2 die gewünschte Detailstufe (0
 *   oder 1).
 * - Rückgabewert: Die Funktion gibt die tatsächlich mögliche Detailstufe (0, 1 oder 2 bei Speichermangel)
 *   zurück.
 === Ende Beschreibung === */
unsigned char f_11fe50(short p1, unsigned char p2)
{
	unsigned loc[2];
	unsigned u;
	unsigned char c = p2;
	loc[0] = *(int *)((char *)&d_1a7fc4 + p1 * 8) + 200000;
	loc[1] = *(int *)((char *)&d_1a7fc8 + p1 * 8) + 200000;
	u = f_014a60();
	if (u < loc[p2]) {
		f_13fd60(AD(d_1c14c4));
		u = f_014a60();
		if (u < loc[p2]) {
			f_15674c();
			u = f_014a60();
			if (u < loc[p2]) {
				c = 0;
				if (u < loc[0]) c = 2;
			}
		}
	}
	return c;
}
//@ f_11fed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert den Pfad des temporären Szenario-Verzeichnisses ("..\CTEMP\") zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die Zeichenkette "..\CTEMP\" zurück.
 === Ende Beschreibung === */
char *f_11fed0(void)
{
	return (char *)d_1b8388;
}
//@ f_11fee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Lädt die 3D-Szenerie mit dem Index p1 in die 3D-Engine (f_161fd8), nachdem der verfügbare Speicher
 *   geprüft wurde; reicht der Speicher trotz Cache-Leerung nicht aus oder tritt ein Ladefehler auf, wird der
 *   Spielstand als RIVA_TMP.GAM gerettet und das Spiel mit einer Fehlermeldung beendet.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Index des zu ladenden 3D-Szenarios.
 * - Rückgabewert: Die Funktion gibt bei erfolgreichem Laden 1 zurück.
 === Ende Beschreibung === */
unsigned f_014a60(void);
int f_014b10(const char *, int);
int f_014ac0(int, int);
int f_0bdde0(int, int, const char *, int);
void f_11fd40(const char *, char *);
int f_0bdd50(int, int, const char *, int);
int f_11fee0(short p1)
{
	unsigned t[2];
	char *base;
	unsigned char m;
	char *nm;
	int r;
	unsigned char c;
	unsigned char k;

	k = d_1bfb18;
	d_1c0b9c = k;
	c = k;
	t[0] = *(int *)((char *)&d_1a7fc4 + p1 * 8) + 200000;
	t[1] = *(int *)((char *)&d_1a7fc8 + p1 * 8) + 200000;
	if (f_014a60() < t[k]) {
		f_13fd60(AD(d_1c14c4));
		if (f_014a60() < t[k]) {
			unsigned now;
			f_15674c();
			now = f_014a60();
			if (now < t[k]) {
				c = 0;
				if (now < t[0])
					c = 2;
			}
		}
	}
	base = (char *)d_1b8388;
	m = c;
	nm = f_120620(p1);
	if (c == (unsigned char)2) {
		char *b = (char *)f_0bdd50(AD(d_1c11b8), 0x2000, d_1a7f9c, 0x272);
		f_14572e(b, d_1b8392, nm, f_0bdbf0(AD(d_1c11a0)), f_0bdbc0(AD(d_1c11a0)));
		f_11fd40(d_1b840d, b);
		f_0bdde0(AD(d_1c11b8), (int)b, d_1a7f9c, 0x283);
	}
	r = f_161fd8((int)base, (int)nm, (int)d_1b841a, (signed char)!m);
	if (r != 0 && r != 0xf00d) {
		char *mm = (char *)f_014ac0(0x200, f_014b10(d_1a7f9c, 0x299));
		f_14572e(mm, d_1b8425, nm, r);
		f_11fd40(d_1b846f, mm);
		f_014710((int)mm);
	}
	f_11f6e0();
	if (f_0de920(d_1c0004))
		f_0ddfc0(d_1c0004);
	return 1;
}
//@ f_120080
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt nach dem Laden eines 3D-Szenarios die Startposition der Gruppe und erzeugt über f_05ecf0 das
 *   passende Orts-/Dungeon-Steuerobjekt (d_1bd6c0).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120080(void)
{
	short s = f_0de820(d_1c0004);
	f_0ddf50(d_1c0004);
	f_05ecf0(s);
	d_1c2198 = 0;
}
//@ f_1200b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Allokiert beim Start der 3D-Ansicht die benötigten Grafikpuffer (208 x 135 Pixel), die
 *   Schaltflächenleiste (d_1c0af4) sowie die Hilfsspeicherblöcke (d_1c0af8, d_1c0afc) und richtet den
 *   Interrupt-/Timer-Hook der 3D-Engine ein.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1200b0(void)
{
	int p, t_;
	f_121d80();
	if (d_1c0af8 == 0) d_1c0af8 = f_014540(10000, (int)d_1a7f9c, 0x2f9);
	if (d_1c0afc == 0) d_1c0afc = f_014540(0x13c, (int)d_1a7f9c, 0x2fd);
	if (d_1c0af0 == 0) {
		t_ = (int)operator new(9, mark(d_1a7f9c, 0x303));
		p = (t_ != 0) ? ((int)(((RivaRasterImage*)(t_))->f_0fac80( 0xd0, 0x87))) : t_;
		d_1c0af0 = p;
	}
	((RivaRasterImage*)(d_1c0af0))->f_0fb120();
	if (d_1c0af4 == 0) {
		t_ = (int)operator new(0x42, mark(d_1a7f9c, 0x30a));
		p = (t_ != 0) ? f_0da910(t_, 0x280000, 0x280001, 0x280002, 0x280003, d_1bb244, 0x1f) : t_;
		d_1c0af4 = p;
	}
	f_1206c0();
}
//@ f_1201a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Verbindet den 3D-Renderpuffer (d_1c0af0) mit dem Haupt-Bildschirmfenster (d_1bf230).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1201a0(void)
{
	f_0bd2e0(AD(d_1bf230), d_1c0af0);
}
//@ f_1201c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Erzeugt und initialisiert den Archiv-Manager (d_1c0aec) für die Datei DUNGEON.ALF abhängig davon, ob
 *   die Daten von Festplatte oder von CD-ROM gelesen werden.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1201c0(void)
{
	char buf[80];
	int t_, p;
	t_ = (int)operator new(0x41, mark(d_1a7f9c, 0x32e));
	p = (t_ != 0) ? f_0256c0(t_, 500, 5000000) : t_;
	d_1a965c = (int)d_1b847c;
	d_1c0aec = p;
	if (((RivaFileManager*)(AD((*(char*)&d_1c2098))))->f_144870( 0) == 1) {
		f_025750(d_1c0aec, (int)d_1b849b, (int)d_1b8499, (int)d_1b8491, (int)d_1b8488);
	} else {
		strcpy(buf, &d_1a96a4);
		strcat(buf, d_1b849d);
		f_025750(d_1c0aec, (int)d_1b84b4, (int)buf, (int)d_1b84ac, (int)d_1b84a3);
	}
}
//@ f_1202a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt vor dem Betreten einer 3D-Szenerie die Lichtquellen, Helligkeitswerte und Renderflags der
 *   3D-Engine auf ihre Ausgangswerte zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1202a0(void)
{
	short i;
	d_1a9950 = 0;
	d_1a9a1c = d_1a9a1c & 0xfebfefff;
	d_1a9b18 = 0x280000;
	d_1a9978 = 100;
	i = 1;
	f_16232c(0);
	for (; i < 9; i++) {
		f_163b08(i, 0);
		f_163bac(i, 0);
	}
}
//@ f_120310
/* === Beschreibung (Katalog) ===
 * - Zweck: Überträgt sämtliche Parameter des aktuellen 3D-Szenarios aus der Szenariotabelle (f_120620) in die
 *   3D-Engine, darunter die von der Körpergröße des Gruppenanführers abhängige Augenhöhe (niedrig für Zwerge,
 *   mittel für Menschen, hoch für Elfen/Magier), Nebel-/Sichtweiten, Decken-/Bodenhöhen, Wellenparameter und
 *   Renderflags.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120310(void)
{
	char *p;
	short c;
	short d;
	p = f_120620(d_1a7fbc);
	d = 1;
	if ((c = f_042350((struct hero *)(f_038c40(d_1c0004)))) == 6) {
		d = 0;
	} else if (c == 10 || c == 12 || c == 11) {
		d = 2;
	}
	d_1a7fbe = d;
	f_163a98(*(unsigned short *)(p + 0x36));
	f_163bac(0, *(short *)(p + 0x32) << 16);
	d_1a7fc0 = *(unsigned short *)(p + 0x34);
	f_122120(d_1a7fc0);
	d_1a9b24 = *(short *)(p + 0x30) << 16;
	d_1c0b9b = -1;
	f_1220c0();
	d_1c90cc = *(short *)(p + 0x16 + d_1a7fbe * 2) << 16;
	f_0de8b0(d_1c0004, d_1c90cc);
	f_155900((unsigned short)(*(unsigned short *)(p + 0x18) << 3));
	d_1a89ac = *(int *)(p + 0x10);
	f_14dc28(*(short *)(p + 0x14) << 16);
	d_1a8ae8 = *(float *)(p + 0x42);
	d_1a995c = *(short *)(p + 0x38);
	d_1a995e = *(short *)(p + 0x3a);
	d_1a9b14 = *(short *)(p + 0x3c) << 16;
	d_1c0b94 = *(signed char *)(p + 0xf);
	d_1a0108 = *(short *)(p + 0x3e);
	d_1a8af0 = *(short *)(p + 0x40);
	d_1a8aec = *(float *)(p + 0x46);
	d_1a9a1c |= *(unsigned *)(p + 0x1c);
	d_1a9a1c &= ~*(unsigned *)(p + 0x20);
}
//@ f_120460
/* === Beschreibung (Katalog) ===
 * - Zweck: Initialisiert beim Spielstart einmalig die 3D-Engine (Auflösung 320 x 200, Speicher-Callbacks) und
 *   legt den Archiv-Manager für DUNGEON.ALF an.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120460(void)
{
	char buf[80];
	int t_, p;
	f_11f590((int)&f_11f580, (int)&f_11f570, (int)&f_11f560);
	f_164994(320, 200, 19);
	d_1a9950 = 0;
	t_ = (int)operator new(0x41, mark(d_1a7f9c, 0x32e));
	p = (t_ != 0) ? f_0256c0(t_, 500, 5000000) : t_;
	d_1a965c = (int)d_1b847c;
	d_1c0aec = p;
	if (((RivaFileManager*)(AD((*(char*)&d_1c2098))))->f_144870( 0) == 1) {
		f_025750(d_1c0aec, (int)d_1b849b, (int)d_1b8499, (int)d_1b8491, (int)d_1b8488);
	} else {
		strcpy(buf, &d_1a96a4);
		strcat(buf, d_1b849d);
		f_025750(d_1c0aec, (int)d_1b84b4, (int)buf, (int)d_1b84ac, (int)d_1b84a3);
	}
}
//@ f_120570
/* === Beschreibung (Katalog) ===
 * - Zweck: Ermittelt anhand des Archetyps des aktuellen Gruppenanführers die Kamerahöhen-Stufe für die
 *   3D-Ansicht (0 für Zwerge mit Archetyp 6, 2 für großgewachsene Archetypen 10-12, 1 für alle übrigen).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die Kamerahöhen-Stufe (0, 1 oder 2) zurück.
 === Ende Beschreibung === */
short f_120570(void)
{
	signed char s;
	short c;
	int r;
	s = f_042350((struct hero *)(f_038c40(d_1c0004)));
	c = s;
	r = 1;
	if (s == 6) { r = 0; return r; }
	if (c == 10 || c == 12 || c == 11) r = 2;
	return r;
}
//@ f_1205c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest aus dem Tabelleneintrag des aktuellen 3D-Szenarios die konkrete Kamerahöhe für die übergebene
 *   Größenstufe p1 (0, 1 oder 2) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 die Größenstufe (0, 1 oder 2).
 * - Rückgabewert: Die Funktion gibt die zugehörige Kamerahöhe als 16-Bit-Wert zurück.
 === Ende Beschreibung === */
short f_1205c0(short p1)
{
	char *e = f_120620(d_1a7fbc);
	return *(short *)(e + 0x16 + p1 * 2);
}
//@ f_1205e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht in der 28 Einträge umfassenden Szenariotabelle (d_1a80cc, Satzlänge 0x4a Bytes) nach einem
 *   Szenario anhand seines Dateinamens (z. B. "RIVA01").
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf den gesuchten Szenarionamen.
 * - Rückgabewert: Die Funktion gibt den Tabellenindex (0..27) zurück oder -1, falls der Name nicht gefunden
 *   wurde.
 === Ende Beschreibung === */
int f_1205e0(const char *p)
{
	int i = 0;
	int r = -1;
	for (; (short)i < 0x1c; i++) {
		if (f_144bf0(p, (const char *)d_1a80cc + (short)i * 0x4a) == 0) { r = i; break; }
	}
	return r;
}
//@ f_120620
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert einen Zeiger auf den 74 Bytes (0x4a) großen Konfigurationseintrag des 3D-Szenarios p1 in der
 *   Szenariotabelle d_1a80cc (oder auf den Standardeintrag 28, falls p1 außerhalb von 0..27 liegt).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Szenario-Index.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den Szenario-Tabelleneintrag zurück.
 === Ende Beschreibung === */
char *f_120620(short p1)
{
	if (p1 < 0 || p1 >= 0x1c) p1 = 0x1c;
	return (char *)d_1a80cc + p1 * 0x4a;
}
//@ f_120640
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht ein 3D-Szenario anhand seines Namens p und gibt direkt den Zeiger auf dessen
 *   Konfigurationseintrag in d_1a80cc zurück.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf den Szenarionamen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den gefundenen Szenario-Tabelleneintrag (bzw. den
 *   Standardeintrag 28) zurück.
 === Ende Beschreibung === */
char *f_120640(const char *p)
{
	int r = -1;
	const char *q = p;
	int i = 0;
	for (; (short)i < 0x1c; i++) {
		if (f_144bf0(q, (const char *)d_1a80cc + (short)i * 0x4a) == 0) { r = i; break; }
	}
	short s = (short)r;
	if (s < 0 || s >= 0x1c) s = 0x1c;
	return (char *)d_1a80cc + s * 0x4a;
}
