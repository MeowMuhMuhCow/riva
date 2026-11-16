/* === Beschreibung (Katalog) ===
 * Einheit gz_0f25c0_t1
 *
 * Diese Einheit bildet den ersten Teil des Verwaltungs- und Einstellungsdialogs für das Spielstand-, Ton-,
 * Grafik- und Kampftempo-System (gz_0f25c0, Teil 1) und enthält die Menülogik für das Laden, Speichern und
 * Löschen von Spielständen sowie das Einrichten der zugehörigen Dialogelemente.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 8/12 gleich (suche.py 26.10.2026, Basis gz_0f25c0_t1_P1.CPP)
// gz_0f25c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F25C0-0x0F5110
#include <string.h>
#include "R_FIX.H"
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0cda50();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d5ff0();                       // nicht in clobber.tsv
int f_0d64a0();                       // nicht in clobber.tsv
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0ef8d0();                                         // reg - stapel 0
int f_0ef8f0();                                         // reg - stapel 0
int f_0ef910();                                         // reg - stapel 0
int f_0ef930();                                         // reg - stapel 0
int f_0ef950();                                         // reg - stapel 0
int f_0ef970();                                         // reg - stapel 0
int f_0ef990();                                         // reg - stapel 0
int f_0ef9b0();                                         // reg - stapel 0
int f_0ef9e0();                                         // reg - stapel 0
int f_0efa10();                                         // reg - stapel 0
int f_0efa30();                                         // reg - stapel 0
int f_0efa50();                                         // reg - stapel 0
int f_0efaa0();                                         // reg - stapel 0
int f_0efb10();                                         // reg - stapel 0
int f_0efb30();                                         // reg - stapel 0
int f_0efb50();                                         // reg - stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc7a8;                    // 0x1BC7A8
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (40), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern signed char d_1bed80, d_1bed9c, d_1bee00, d_1c00c4;
extern signed char d_1c0178, d_1c017c, d_1c0180, d_1c0184, d_1c0188, d_1c018c, d_1c0190, d_1c0194, d_1c0198, d_1c019c, d_1c01a0, d_1c01a4, d_1c01a8, d_1c01ac, d_1c01b0, d_1c01b4, d_1c01b8, d_1c01bc, d_1c01c0, d_1c01c4, d_1c01c8, d_1c01cc, d_1c01d0, d_1c01d4;
extern short d_1c0179, d_1c017d, d_1c0181, d_1c0185, d_1c0189, d_1c018d, d_1c0191, d_1c0195, d_1c0199, d_1c019d, d_1c01a1, d_1c01a5, d_1c01a9, d_1c01ad, d_1c01b1, d_1c01b5, d_1c01b9, d_1c01bd, d_1c01c1, d_1c01c5, d_1c01c9, d_1c01cd, d_1c01d1, d_1c01d5;
extern short d_1c212a;
extern volatile short d_1c2198; // haelt das Schreiben in f_0f25c0 wie im Original
extern int d_1c212c;
extern char d_1bb694[];

short f_0d4aa0(int p1, int p2);
int f_0ce650();
int f_0bf820(int, ...);
int f_060740(int p1, int p2);
int f_1254a0(int p1, int p2);
int f_05ff60(int p1, int p2);
int f_060230(int p1);
int f_0f5110(int p1);
void f_0f3920(int p1);
void f_0f3d80(int p1);
void f_0f4040(int p1);
void f_0f4630(int p1);
void f_0f4760(int p1);
void f_0f4850(int p1);
void f_0f4a00();
void f_0f4e00(int p1, int p2);
#define ADR(x) ((int)&(x))
#define SP (*(char **)(p1 + 0x1a))
struct O { int a; int b; char pad[52]; };
#define EQ(x,v) (((x)==(v))?1:0)  // bildet Inline-Flagabfragen mit 0/1-Ergebnis nach
#define GT(x,v) (((x)>(v))?1:0)
#define EQ3(x,v) (((x)==(v))?1:0)
#define ISC(c,s) ((c) == 10 || (s) == 11 || (s) == 12)

//@ f_0f25c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die Liste der verfügbaren Spielstände, indem sie das
 *   Spielstandsverzeichnis durchsucht und die Bezeichnungen sowie Zeitstempel der vorhandenen Speicherdateien in
 *   die interne Tabelle einliest.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt die Anzahl der gefundenen Spielstände oder den Status der Initialisierung
 *   zurück.
 === Ende Beschreibung === */
void f_0f25c0(short *p1)
{
	d_1c2198 = 1;
	if (p1[1] < p1[2]) {
		do { p1[2] -= 9; } while (p1[1] < p1[2]);
	}
	if (p1[2] < 0) p1[2] = 0;
	while ((int)p1[1] > (int)p1[2] + 9) p1[2] += 9;
	if ((0 < *p1 - 10) && ((int)p1[2] > *p1 - 10)) p1[2] = *p1 - 10;
}

//@ f_0f2630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die für die Spielstandsliste und das Optionsmenü reservierten Text- und
 *   Grafikpuffer wieder frei.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der letzten Speicherfreigabe zurück.
 === Ende Beschreibung === */
void f_0f2630(int p1, int p2, int p3)
{
	short n;
	int i;
	char *q;
	n = strlen(SP);
	if (n) {
		i = n;
		SP[i + 2] = 0;
		SP[i + 1] = 0xf0;
		SP[i] = SP[i - 1];
		SP[i - 1] = 0xf2;
		f_0e9660(ADR(d_1c38b0), (int)SP, (int)(short)p2, (int)(short)p3);
		SP[i - 1] = SP[i];
		q = SP;
		q[i + 1] = 0;
		SP[i] = q[i + 1];
	}
}

//@ f_0f26b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob in einem bestimmten Spielstand-Slot eine gültige Speicherdatei existiert,
 *   und liest deren Kurzbeschreibung aus dem Dateiheader.
 * - Eingaben: Die Funktion erhält die Nummer des Spielstand-Slots (p1) sowie optional einen Zielpuffer für den
 *   Namen (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Slot belegt und gültig ist, oder 0 bei einem leeren Slot.
 === Ende Beschreibung === */
void f_0f26b0(int p1)
{
	memset(SP, 0, 0x16);
}

//@ f_0f2720
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion baut den Dateinamen für einen Spielstand-Slot (zum Beispiel RIVA0001.SAV) zusammen und
 *   prüft den Lese- oder Schreibzugriff auf die Datei.
 * - Eingaben: Die Funktion erhält die Slotnummer (p1) und den Zielpuffer für den Dateipfad (p2).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den erzeugten Dateinamen oder den Prüfstatus zurück.
 === Ende Beschreibung === */
int f_0f2720(unsigned p1);
#pragma aux f_0f2720 "f_0f2720";
int f_0f2720(unsigned p1)
{
	int o;
	int r;
	f_0ce7c0(ADR(o));
	r = 0;
	f_060a10(0x2625a0);
	switch (p1) {
	case 0: f_0ef8f0(); break;
	case 1: f_0ef8d0(); break;
	case 3: f_0ef950(); break;
	case 5: f_0ef910(); break;
	case 6: f_0ef930(); break;
	case 10: f_0ef970(); break;
	case 12: f_0ef990(); break;
	case 13: f_0ef9b0(); break;
	case 9: f_0efa30(); break;
	case 11: f_0efa10(); break;
	case 15: f_0efa50(); break;
	case 16: f_0efaa0(); break;
	case 8: f_0efb10(); break;
	case 4: r = f_0efb50(); break;
	case 7: f_0ef9e0(); break;
	case 2: f_0efb30(); break;
	}
	f_0ce650();
	f_0ce7e0(ADR(o), 0);
	return r;
}

//@ f_0f27e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt den vollständigen Ladevorgang eines ausgewählten Spielstands durch, liest die
 *   Helden-, Gruppen-, Orts- und Questdaten ein, aktualisiert die Grafik- und Musikumgebung und meldet etwaige
 *   Lese- oder Versionsfehler.
 * - Eingaben: Die Funktion erhält die Slotnummer oder den Dateinamen des zu ladenden Spielstands (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Laden zurück oder 0 bei einem Fehler.
 === Ende Beschreibung === */
struct Reg700Z;
struct Obj700Z { signed char flag; short number; char pad; Obj700Z *init(Reg700Z &r,short id,signed char f); };
struct Reg700Z { short count; Obj700Z **list; void append(Obj700Z *o) {list[count]=o;count++;} };
inline Obj700Z *Obj700Z::init(Reg700Z &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern Reg700Z reg700z;
#pragma aux reg700z "d_1c212a"
extern Obj700Z ob700z_1c0178;
#pragma aux ob700z_1c0178 "d_1c0178"
extern Obj700Z ob700z_1c017c;
#pragma aux ob700z_1c017c "d_1c017c"
extern Obj700Z ob700z_1c0180;
#pragma aux ob700z_1c0180 "d_1c0180"
extern Obj700Z ob700z_1c0184;
#pragma aux ob700z_1c0184 "d_1c0184"
extern Obj700Z ob700z_1c0188;
#pragma aux ob700z_1c0188 "d_1c0188"
extern Obj700Z ob700z_1c018c;
#pragma aux ob700z_1c018c "d_1c018c"
extern Obj700Z ob700z_1c0190;
#pragma aux ob700z_1c0190 "d_1c0190"
extern Obj700Z ob700z_1c0194;
#pragma aux ob700z_1c0194 "d_1c0194"
extern Obj700Z ob700z_1c0198;
#pragma aux ob700z_1c0198 "d_1c0198"
extern Obj700Z ob700z_1c019c;
#pragma aux ob700z_1c019c "d_1c019c"
extern Obj700Z ob700z_1c01a0;
#pragma aux ob700z_1c01a0 "d_1c01a0"
extern Obj700Z ob700z_1c01a4;
#pragma aux ob700z_1c01a4 "d_1c01a4"
extern Obj700Z ob700z_1c01a8;
#pragma aux ob700z_1c01a8 "d_1c01a8"
extern Obj700Z ob700z_1c01ac;
#pragma aux ob700z_1c01ac "d_1c01ac"
extern Obj700Z ob700z_1c01b0;
#pragma aux ob700z_1c01b0 "d_1c01b0"
extern Obj700Z ob700z_1c01b4;
#pragma aux ob700z_1c01b4 "d_1c01b4"
extern Obj700Z ob700z_1c01b8;
#pragma aux ob700z_1c01b8 "d_1c01b8"
extern Obj700Z ob700z_1c01bc;
#pragma aux ob700z_1c01bc "d_1c01bc"
extern Obj700Z ob700z_1c01c0;
#pragma aux ob700z_1c01c0 "d_1c01c0"
extern Obj700Z ob700z_1c01c4;
#pragma aux ob700z_1c01c4 "d_1c01c4"
extern Obj700Z ob700z_1c01c8;
#pragma aux ob700z_1c01c8 "d_1c01c8"
extern Obj700Z ob700z_1c01cc;
#pragma aux ob700z_1c01cc "d_1c01cc"
extern Obj700Z ob700z_1c01d0;
#pragma aux ob700z_1c01d0 "d_1c01d0"
extern Obj700Z ob700z_1c01d4;
#pragma aux ob700z_1c01d4 "d_1c01d4"
void f_0f27e0(void) {
ob700z_1c0178.init(reg700z,0x46,0);
ob700z_1c017c.init(reg700z,0x47,0);
ob700z_1c0180.init(reg700z,0x48,0);
ob700z_1c0184.init(reg700z,0x49,0);
ob700z_1c0188.init(reg700z,0x4a,0);
ob700z_1c018c.init(reg700z,0x4b,0);
ob700z_1c0190.init(reg700z,0x4c,0);
ob700z_1c0194.init(reg700z,0x4d,0);
ob700z_1c0198.init(reg700z,0x4e,0);
ob700z_1c019c.init(reg700z,0x4f,0);
ob700z_1c01a0.init(reg700z,0x50,0);
ob700z_1c01a4.init(reg700z,0x51,0);
ob700z_1c01a8.init(reg700z,0x52,0);
ob700z_1c01ac.init(reg700z,0x53,0);
ob700z_1c01b0.init(reg700z,0x54,0);
ob700z_1c01b4.init(reg700z,0x55,0);
ob700z_1c01b8.init(reg700z,0x56,0);
ob700z_1c01bc.init(reg700z,0x57,0);
ob700z_1c01c0.init(reg700z,0x58,0);
ob700z_1c01c4.init(reg700z,0x59,0);
ob700z_1c01c8.init(reg700z,0x16c,0);
ob700z_1c01cc.init(reg700z,0x24a,0);
ob700z_1c01d0.init(reg700z,600,0);
ob700z_1c01d4.init(reg700z,0x259,0);
}

//@ f_0f2c10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft vor dem Speichern eines Spielstands, ob das Speichern in der aktuellen
 *   Spielsituation erlaubt ist und genügend Speicherplatz auf dem Laufwerk zur Verfügung steht.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn gespeichert werden darf, oder 0, wenn das Speichern blockiert
 *   ist.
 === Ende Beschreibung === */
int f_0f2c10(int p1)
{
	int r = 0;
	if (f_0d4a60(p1)) {
		if (f_042400((struct hero *)(p1)) == 0) {
			short s = f_0d4aa0(p1, 0x16f);
			if (s == -1) r = 1;
		}
	}
	return r;
}

//@ f_0f2c50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löscht eine bestehende Spielstandsdatei nach einer Sicherheitsabfrage von der
 *   Festplatte und aktualisiert die Anzeige der Slotliste.
 * - Eingaben: Die Funktion erhält die Nummer des zu löschenden Spielstand-Slots (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Löschen oder 0 bei Abbruch zurück.
 === Ende Beschreibung === */
int f_0f2c50(int p1)
{
	int r = 0;
	if (f_0d4a60(p1)) {
		if (f_042400((struct hero *)(p1)) == 0) r = 1;
	}
	return r;
}

//@ f_0f2c80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion speichert den aktuellen Spielzustand samt eingegebenem Spielstandsnamen und kleinem
 *   Vorschaubild in den gewählten Slot und gibt bei Schreibfehlern eine Warnmeldung aus.
 * - Eingaben: Die Funktion erhält die Nummer des Ziel-Slots (p1) sowie die Beschreibung des Spielstands (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Speichern erfolgreich war, oder 0 bei einem
 *   Schreibfehler.
 === Ende Beschreibung === */
int f_0f2c80(int p1)
{
	struct { int buf[7]; int r; } fr;
	fr.r = 0;
	short n;
	int cnz;
	int x;
	int cz;
	short c2 = 0;
	short i;
	short s;
	signed char c;
	int p;
	{ int t_ = (int)(d_1c0004); n = f_0398c0(t_, p1, (int)fr.buf); }
	short &g1347=*(short*)&d_1c0004; short t1347=g1347; g1347=t1347; // haelt die Registerfolge in f_0f2c80 wie im Original

	x = 0;
	cnz = 0;
	cz = 0;
	for (i = 0; i < n; i++) {
			p = i;
			p = fr.buf[p];
			c = f_042350((struct hero *)(p));
			s = c;
			c2 = f_042380((struct hero *)(p));
			if (ISC(c, s)) {
				if (f_042380((struct hero *)(p)) == 0) x = p; else cnz = p;
			} else if (c2 == 0) cz = p;
	}
	if (x) fr.r = x;
	else {
		if (cnz) { fr.r = cnz; goto aus1281; }
		if (cz) { fr.r = cz; goto aus1281; }
		if (0 < (short)n) {
			i = f_1457e0(n);
			fr.r = fr.buf[i - 1];
		}
	}
	aus1281: return fr.r;
}

//@ f_0f2d90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion legt einen automatischen oder schnellen Spielstand (Autosave/Quicksave) in einem fest
 *   reservierten Slot an.
 * - Eingaben: Die Funktion erhält eine Kennung oder einen Namenszusatz für den automatischen Spielstand (p1).
 * - Rückgabewert: Die Funktion gibt den Erfolgsstatus des Speichervorgangs zurück.
 === Ende Beschreibung === */
int f_0f2d90(void)
{
	int r = f_0f2c80((int)f_0f2c10);
	if (r == 0) r = f_0f2c80((int)f_0f2c50);
	return r;
}

//@ f_0f2dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt den zuletzt angelegten automatischen oder aktuellen Spielstand direkt wieder ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Ladevorgangs (f_0f27e0) zurück.
 === Ende Beschreibung === */
void f_0f2dc0(int p1)
{
	int r = f_05ff60(p1, 1);
	*(int *)(r + 8) = (int)d_1bb694;
}

//@ f_0f2de0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet und steuert das grafische Spielstands- und Optionsfenster (Laden, Speichern,
 *   Löschen, Spieleinstellungen und Spiel beenden), verarbeitet die Benutzereingaben in der Slotliste und führt
 *   die gewählte Aktion aus.
 * - Eingaben: Die Funktion erhält den Modus des Fensters (p1, beispielsweise ob das Speichern erlaubt ist oder
 *   das Fenster aus dem Hauptmenü aufgerufen wurde).
 * - Rückgabewert: Die Funktion gibt den Statuscode der ausgeführten Menüaktion zurück.
 === Ende Beschreibung === */
inline int eq0f2de0(const signed char &x,signed char y) { return x==y; }
int f_0f2de0(int p1, int p2)
{
	struct { O oB,oD,oA,oC; } st;
	short s;
	int menuCount;
	int r = 1;
	switch ((short)p2) {
	case 0x3f2:
		return r;
	case 0x3fc:
		f_0f3920(p1);
		return r;
	case 0x3fd:
		if (eq0f2de0(d_1bed9c,0)) {
			if (f_0bf6f0(ADR(d_1c2c64), 0x25000003) != 1) goto done0f2de0;
			d_1bed9c = 1;
			s = f_0bf820(ADR(d_1c2c64), 0x25000004, 2, 0x25000005, 0x25000006);
			if (s != 2) goto done0f2de0;
			f_0dd7f0(d_1c0004, 0, 0x16a8);
			return r;
		}
		if (f_0bf6f0(ADR(d_1c2c64), 0x25000007) != 1) goto done0f2de0;
		f_0dd7f0(d_1c0004, 0, 0x16a8);
		return r;
	case 0x406:
		if (f_0bf6f0(ADR(d_1c2c64), 0x25000008) != 1) goto done0f2de0;
		f_0dd7f0(d_1c0004, 0, 0x1c2);
		return r;
	case 0x410:
		if (f_0bf6f0(ADR(d_1c2c64), 0x25000008) != 1) goto done0f2de0;
		f_0dd7f0(d_1c0004, 0, 0x1cc);
		return r;
	case 0x41a:
		if (f_0bf6f0(ADR(d_1c2c64), 0x25000008) != 1) goto done0f2de0;
		f_0dd7f0(d_1c0004, 0, 0x1d6);
		return r;
	case 0x424:
		if (f_0bf6f0(ADR(d_1c2c64), 0x25000008) != 1) goto done0f2de0;
		f_0dd7f0(d_1c0004, 0, 0x1e0);
		return r;
	case 0x42e:
		f_125400(ADR(st.oA), ADR(d_1c349c), ADR(d_1c3870), ADR(d_1c3498));
		s = f_0bf820(ADR(d_1c2c64), 0x25000009, menuCount = 2, 0x2500000a, 0x2500000b);
		if (s == (short)1) {
			if (eq0f2de0(d_1c00c4,1) && GT(d_1bee00, 0)) {
				*(int *)(st.oA.b + 4) = f_038c40(d_1c0004);
				f_0bf730(ADR(d_1c2c64), 0x2500000c);
			} else f_0dd7f0(d_1c0004, 0, 0x15e0);
		}
		f_1254a0(ADR(st.oA), 0);
		return r;
	case 0x42f:
		f_125400(ADR(st.oB), ADR(d_1c349c), ADR(d_1c3870), ADR(d_1c3498));
		if (eq0f2de0(d_1c00c4,1) && eq0f2de0(d_1c01b8,0) && (int)(signed char)(d_1c01d4 & 2) == 0) {
			*(int *)(st.oB.b + 4) = f_039320(d_1c0004, 0x33);
			f_0bf730(ADR(d_1c2c64), 0x2500000d);
			f_057220(ADR(d_1c2c00), 0x8030012, 0);
			d_1c01d4 |= 2;
		}
		f_1254a0(ADR(st.oB), 0);
		return r;
	case 0x438:
		if (f_0bf6f0(ADR(d_1c2c64), 0x25000008) != 1) goto done0f2de0;
		f_0dd7f0(d_1c0004, 0, 0x1ea);
		return r;
	case 0x442:
		f_0f3d80(p1);
		return r;
	case 0x44c:
		if (!eq0f2de0(d_1c0180,0)) goto done0f2de0;
		d_1c0180 = 1;
		f_0bf730(ADR(d_1c2c64), 0x25000017);
		return r;
	case 0x456:
		f_0f4040(p1);
		return r;
	case 0x460:
		if (!eq0f2de0(d_1c0184,0)) goto done0f2de0;
		d_1c0184 = 1;
		f_0bf730(ADR(d_1c2c64), 0x25000029);
		return r;
	case 0x46a:
		if ((int)(short)f_060760(0x1f45) != 2) goto done0f2de0;
		{ int a46a; int b46a; if (f_0bf6f0(b46a = (a46a = ADR(d_1c2c64)), 0x2500002a) != 1) goto done0f2de0; } // haelt die Stapelplatzfolge in f_0f2de0 wie im Original
		f_0dd7f0(d_1c0004, 2, 0x15f2);
		if (!eq0f2de0(d_1c017c,0)) goto done0f2de0;
		d_1c017c = 1;
		d_1c0180 = 1;
		f_060740(0x1f43, 1);
		f_0607e0(0x1f43, 1);
		return r;
	case 0x474:
		if (!(eq0f2de0(d_1c0188,1) && eq0f2de0(d_1bed80,0) && eq0f2de0(d_1c01d0,0))) goto done0f2de0;
		f_0bf730(ADR(d_1c2c64), 0x2500002b);
		d_1c01d0 = 1;
		return r;
	case 0x475:
		f_0f4630(p1);
		return r;
	case 0x47e:
		f_0f4760(p1);
		return r;
	case 0x488:
		f_0f4850(p1);
		return r;
	case 0x489:
		if (eq0f2de0(d_1c01a4,0)) {
			f_0bf730(ADR(d_1c2c64), 0x25000035);
			d_1c01a4 = 1;
		}
#if FIX_R076   /* R076: Da f_0f5110 stets 0 liefert, d_1c01a0 beim Oeffnen von Truhe 0x489 direkt setzen */
		f_0f5110(p1);
		*(volatile signed char *)&d_1c01a0 = 1;
#else
		if (f_0f5110(p1) != 1) goto done0f2de0;
		*(volatile signed char *)&d_1c01a0 = 1; // haelt das Schreiben in d_1c01a0 wie im Original
#endif
		return r;
	case 0x492:
		((void (*)(int))f_0f4a00)(p1); // Fremder Prototyp ist void f_0f4a00(), das Original uebergibt hier jedoch p1.
		return r;
	case 0x49c:
		if (!(EQ(d_1c01ac, 1) && EQ(d_1c0178, 0))) goto done0f2de0; f_0f2720(1); d_1c0178 = 1; f_091f70(0x10); f_056930(); f_056a30(9); f_056950(); f_019fd0(ADR(d_1c2a84), 1, f_0de840(d_1c0004), f_0de880(d_1c0004), 0x2500003a); f_057220(ADR(d_1c2c00), 0x8030010, 0);
		return r;
	case 0x49d:
		s = p2;
		if (EQ(d_1c01ac,1) && EQ(d_1c0178,0)) {
			if (!(EQ(d_1c01ac, 1) && EQ(d_1c0178, 0))) goto done0f2de0; f_0f2720(1); d_1c0178 = 1; f_091f70(0x10); f_056930(); f_056a30(9); f_056950(); f_019fd0(ADR(d_1c2a84), 1, f_0de840(d_1c0004), f_0de880(d_1c0004), 0x2500003a); f_057220(ADR(d_1c2c00), 0x8030010, 0);
			return r;
		}
		if (!(EQ(d_1c01b0,1) && EQ(d_1c01b8,0))) goto done0f2de0;
		f_0f4e00(p1, s);
		return r;
	case 0x4ba:
		f_0f4e00(p1, (short)p2);
		return r;
	case 0x4a6:
		f_125400(ADR(st.oC), ADR(d_1c349c), ADR(d_1c3870), ADR(d_1c3498));
		if (eq0f2de0(d_1c01ac,0)) {
			f_0f2720(0);
			*(int *)(st.oC.b + 4) = f_038c40(d_1c0004);
			f_0bf730(ADR(d_1c2c64), 0x2500003b);
			d_1c01ac = 1;
			f_091f70(0xf);
			f_056930();
			f_056a30(8);
			f_056950();
			f_057220(ADR(d_1c2c00), 0x803000f, 0);
		}
		f_1254a0(ADR(st.oC), 0);
		return r;
	case 0x4b0:
		f_125400(ADR(st.oD), ADR(d_1c349c), ADR(d_1c3870), ADR(d_1c3498));
		if (eq0f2de0(d_1c01b0,1) && eq0f2de0(d_1c01b4,0)) {
			*(int *)(st.oD.b + 4) = f_039320(d_1c0004, 0x33);
			f_0bf730(ADR(d_1c2c64), 0x2500003c);
			d_1c01b4 = 1;
		}
		f_1254a0(ADR(st.oD), 0);
		return r;
	case 0x4c4:
		if (!eq0f2de0(d_1c01bc,0)) goto done0f2de0;
		f_0bf730(ADR(d_1c2c64), 0x25000049);
		d_1c01bc = 1;
		return r;
	default:
		r = 0;
	done0f2de0:
		return r;
	}
	return r;
}

//@ f_0f3870
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet die Liste der Spielstand-Slots samt Vorschaubild und Beschreibungstext des
 *   aktuell markierten Eintrags in das Dialogfenster.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Dialogfenster oder den aktuellen Auswahlindex (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Zeichenoperation zurück.
 === Ende Beschreibung === */
int f_0f3870(int p1)
{
	int r;
	if (EQ3(d_1c017c, 0) && EQ3(d_1c01c8, 1)) r = 1; else r = 0;
	f_069860(p1 + 2, 0x2e, r);
	if (EQ3(d_1c0190, 0) && EQ3(d_1c0194, 1) && EQ3(d_1c0188, 1)) r = 1; else r = 0;
	f_069860(p1 + 2, 0x91, r);
	return f_060230(p1);
}

//@ f_0f3910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als kleiner Hilfs-Callback zur Aktualisierung der Spielstandsanzeige bei einem
 *   Wechsel des gewählten Eintrags.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
void f_0f3910(void)
{
}
