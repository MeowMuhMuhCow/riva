/* === Beschreibung (Katalog) ===
 * Einheit fz_167f60_t1 (0x167F60 - 0x169412)
 *
 * Überblick
 * Diese Einheit enthält den ersten Teil der eingebundenen digitalen Sound- und Timer-Bibliothek (HMI SOS -
 * *Sound Operating System*). Sie verwaltet bis zu 5 digitale Soundtreiber-Instanzen (d_1af4c8[0..4]) mit jeweils
 * bis zu 32 aktiven Sample-Kanälen (0xF0-Byte-Einträge ab PT(b, 0x58)), stellt Funktionen zum Starten, Abbrechen
 * und Abfragen/Ändern von Sample-Parametern (Lautstärke, Panning, Pitch, Loop-Zähler) bereit, programmiert den
 * System-Timer-Baustein (0x1234DC Hz Basis) für bis zu 16 zeitgesteuerte Callback-Ereignisse (d_1af558[0..15])
 * und initialisiert über f_168faf einen digitalen Soundkarten-Treiber samt DMA-Puffer.
 === Ende Beschreibung === */
// P3 34/34 gleich (suche.py 24.10.2026, Basis fz_167f60_t1_P1.CPP)
// CC wcc386
// P1 32/34 gleich
// OPT -3r -od -zp1 -s
// fz_167f60_t1.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x167F60-0x169412
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define U16(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define U8(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define PT(p,o) (*(char **)((char *)(p)+(o)))
#define FL(r) U8(r,0x21)
#define REC(b,i) (PT(b,0x58) + (i)*0xf0)
extern char *d_1af4c8[];
extern unsigned char d_1af550;
extern unsigned d_1af554;
extern void (*d_1af558[16])(void);
extern int d_1af594;
extern unsigned d_1af598[];
extern int d_1af5d4;
extern unsigned d_1af5d8[];
extern int d_1af614;
extern unsigned d_1af618[];
extern unsigned char d_1af61a[];
extern unsigned char d_1af658[];
extern int d_1af698;
extern int d_1af8f0[];
extern int d_1af910[];
extern signed char d_1b396c;
extern signed char d_1b3970;
void *f_149cf5(void *a, const void *b, unsigned n);
void f_145300(void *a, int b, unsigned n);
void f_17b938(void);
void f_17b964(void);
void f_17b990(void);
void f_17ba0c(void);
int f_17b837(int a);
int f_17b87d(int a, void (*b)(void));
int f_17ba7b(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_17bd4d(int p1);
int f_17bc5d(int p1);
int f_17be61(int p1, int p2);
int f_1695ef(int p1, int p2, int p3, int p4);
int f_17c3b8(int a);
int f_17c2e3(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
int f_17c367(int a, int b, int c, int d);
int f_17c341(int a, int b, int c, int d, int e);
int f_17c318(int a, int b, int c, int d, int e, int f);
char __far *f_17c6b1(int a, int b, int c, int d);
#pragma aux f_17b837 "*" parm caller [];
#pragma aux f_17b87d "*" parm caller [];
#pragma aux f_17c3b8 "*" parm caller [];
#pragma aux f_17c2e3 "*" parm caller [];
#pragma aux f_17c367 "*" parm caller [];
#pragma aux f_17c341 "*" parm caller [];
#pragma aux f_17c318 "*" parm caller [];
#pragma aux f_17c6b1 "*" parm caller [];
#pragma aux f_149cf5 "*";
#pragma aux f_145300 "*";
#pragma aux f_17b938 "*";
#pragma aux f_17b964 "*";
#pragma aux f_17b990 "*";
#pragma aux f_17ba0c "*";
#pragma aux f_17ba7b "*";
#pragma aux f_17bd4d "*";
#pragma aux f_17bc5d "*";
#pragma aux f_17be61 "*";
#pragma aux f_1695ef "*";
void f_167f60(void);
int f_167f75(int p1, int *p2);
int f_1680f5(int p1, int p2);
int f_168167(int p1);
void f_1681d5(void);
void f_1681ea(void);
int f_1681ff(int p1);
int f_168241(int p1, int p2, int p3);
int f_1682c9(int p1, int p2);
int f_16833f(int p1, int p2);
int f_1683b5(int p1, int p2);
int f_16842b(int p1, int p2, int p3);
int f_1684b1(int p1, int p2);
int f_168527(int p1, int p2, int p3);
int f_1685ad(int p1, int p2);
int f_168623(int p1, int p2);
int f_168699(int p1, int p2);
int f_1686fd(int p1, int p2);
int f_168787(int p1);
int f_1687c9(int p1, int p2);
void f_168843(void);
void f_168858(void);
int f_16886d(unsigned p1, unsigned p2);
int f_168944(int p1);
int f_16897e(unsigned p1, void (*p2)(void), unsigned *p3);
int f_168b6c(unsigned p1, unsigned p2);
int f_168cd4(int p1);
unsigned f_168e6c(int p1);
int f_168e96(int p1);
void f_168ecb(void);
void f_168f6b(void);
void f_168f85(void);
void f_168f9a(void);
int f_168faf(char *p1, unsigned *p2);
#pragma aux f_167f60 "*";
#pragma aux f_167f75 "*";
#pragma aux f_1680f5 "*";
#pragma aux f_168167 "*";
#pragma aux f_1681d5 "*";
#pragma aux f_1681ea "*";
#pragma aux f_1681ff "*";
#pragma aux f_168241 "*";
#pragma aux f_1682c9 "*";
#pragma aux f_16833f "*";
#pragma aux f_1683b5 "*";
#pragma aux f_16842b "*";
#pragma aux f_1684b1 "*";
#pragma aux f_168527 "*";
#pragma aux f_1685ad "*";
#pragma aux f_168623 "*";
#pragma aux f_168699 "*";
#pragma aux f_1686fd "*";
#pragma aux f_168787 "*";
#pragma aux f_1687c9 "*";
#pragma aux f_168843 "*";
#pragma aux f_168858 "*";
#pragma aux f_16886d "*";
#pragma aux f_168944 "*";
#pragma aux f_16897e "*";
#pragma aux f_168b6c "*";
#pragma aux f_168cd4 "*";
#pragma aux f_168e6c "*";
#pragma aux f_168e96 "*";
#pragma aux f_168ecb "*";
#pragma aux f_168f6b "*";
#pragma aux f_168f85 "*";
#pragma aux f_168f9a "*";
#pragma aux f_168faf "*";

//@ f_167f60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalter- beziehungsweise Segment-Startmarkierungsfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_167f60(void)
{
}

//@ f_167f75
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Startet ein neues digitales Audio-Sample (p2) auf dem Soundtreiber p1: Sucht unter den
 *   I(b, 0x14) (32) Sample-Slots den ersten freien Eintrag (Bit 0x80 in FL nicht gesetzt), kopiert den 0xF0 Byte
 *   großen Sample-Deskriptor hinein, markiert den Slot als aktiv (|= 0x80), hängt ihn an das Ende der
 *   verketteten Abspielliste (PT(b, 0x30)) an und gibt die Slot-Nummer zurück.
 * - Eingaben: Treiber-Handle p1 und Zeiger p2 auf die 0xF0-Byte-Sample-Startstruktur.
 * - Rückgabewert: int - Slot-Index (0..31) des gestarteten Samples, -1 wenn alle Kanäle belegt sind, oder 10 bei
 *   ungültigem Treiber.
 * - Wichtige Variablen:
 *   - d_1af4c8: Globale Tabelle der geöffneten digitalen Soundtreiber-Strukturen.
 *   - PT(b, 0x30): Kopfzeiger der einfach verketteten Liste aktiver Samples (Verkettungszeiger an Offset +0xEC).
 === Ende Beschreibung === */
int f_167f75(int p1, int *p2)
{
    unsigned i;
    char *cur;
    char *b;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    for (i = 0; i < I(b,0x14); i++) if (!(FL(REC(b,i)) & 0x80)) break;
    if (i == I(b,0x14)) return -1;
    f_149cf5(REC(b,i), p2, 0xf0);
    I(REC(b,i),4) = *p2;
    I(REC(b,i),0x28) = i;
    cur = PT(b,0x30);
    if (cur == 0) {
        I(REC(b,i),0xec) = 0;
        FL(REC(b,i)) |= 0x80;
        PT(b,0x30) = REC(b,i);
    } else {
        while (I(cur,0xec) != 0) cur = PT(cur,0xec);
        I(REC(b,i),0xec) = 0;
        FL(REC(b,i)) |= 0x80;
        PT(cur,0xec) = REC(b,i);
    }
    return i;
}

//@ f_1680f5
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Markiert ein einzelnes aktives Sample p2 auf dem Soundtreiber p1 durch Setzen von Bit 0x40
 *   im Statusbyte (FL) zum Beenden beim nächsten Mischer-Durchlauf.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - 0 bei Erfolg, 10 bei ungültigem Treiber.
 * - Wichtige Variablen:
 *   - FL(REC(b, p2)): Status-Flags des Sample-Slots (0x80 = aktiv, 0x40 = Stopp angefordert).
 === Ende Beschreibung === */
int f_1680f5(int p1, int p2)
{
    char *b;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    if (!(FL(REC(b,p2)) & 0x80)) return 0;
    FL(REC(b,p2)) |= 0x40;
    return 0;
}

//@ f_168167
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fordert das sofortige Beenden aller 32 Sample-Slots (|= 0x40) des Soundtreibers p1 an.
 * - Eingaben: Treiber-Handle p1.
 * - Rückgabewert: int - 0 bei Erfolg, 10 bei ungültigem Treiber.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_168167(int p1)
{
    char *b;
    unsigned i;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    for (i = 0; i < I(b,0x14); i++) FL(REC(b,i)) |= 0x40;
    return 0;
}

//@ f_1681d5
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1681d5(void)
{
}

//@ f_1681ea
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1681ea(void)
{
}

//@ f_1681ff
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den Zähler/Statuswert an Offset +0x1C (Anzahl aktuell verarbeiteter DMA-Blöcke oder
 *   aktiver Samples) des Soundtreibers p1 aus.
 * - Eingaben: Treiber-Handle p1.
 * - Rückgabewert: int - Wert aus I(b, 0x1C) oder 10 bei ungültigem Treiber.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1681ff(int p1)
{
    char *b;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    return I(b,0x1c);
}

//@ f_168241
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Lautstärke (I(r, 0x2C)) des aktiven Samples p2 auf dem Treiber p1 auf den neuen
 *   Wert p3 und gibt die vorherige Lautstärke zurück.
 * - Eingaben: Treiber-Handle p1, Sample-Handle p2 und neue Lautstärke p3.
 * - Rückgabewert: int - bisheriger Lautstärkewert oder 10 bei inaktivem/ungültigem Sample.
 * - Wichtige Variablen:
 *   - I(r, 0x2c): Aktuelle Kanal-Lautstärke des Samples.
 === Ende Beschreibung === */
int f_168241(int p1, int p2, int p3)
{
    char *b;
    char *r;
    int old;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) {
        old = I(r,0x2c);
        I(r,0x2c) = p3;
    } else {
        return 10;
    }
    return old;
}

//@ f_1682c9
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt die aktuelle Lautstärke (I(r, 0x2C)) des aktiven Samples p2 auf dem Treiber p1 ab.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - aktuelle Lautstärke oder 10 bei Fehler.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1682c9(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) return I(r,0x2c);
    return 10;
}

//@ f_16833f
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt die bereits abgespielte Byteanzahl beziehungsweise den Fortschritt (I(r, 0x58)) des
 *   aktiven Samples p2 auf dem Treiber p1 ab.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - Wert an Offset +0x58 oder 10 bei Fehler.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_16833f(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) return I(r,0x58);
    return 10;
}

//@ f_1683b5
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt die verbleibende Wiederholungsanzahl (Loop-Count an Offset +0x30) des aktiven
 *   Samples p2 auf dem Treiber p1 ab.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - Wert an Offset +0x30 oder 10 bei Fehler.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1683b5(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) return I(r,0x30);
    return 10;
}

//@ f_16842b
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Stereo-Panorama-Position (Panning an Offset +0x44) des aktiven Samples p2 auf
 *   dem Treiber p1 auf den neuen Wert p3 und gibt den alten Panning-Wert zurück.
 * - Eingaben: Treiber-Handle p1, Sample-Handle p2 und neuer Panning-Wert p3.
 * - Rückgabewert: int - vorheriger Panning-Wert oder 10 bei Fehler.
 * - Wichtige Variablen:
 *   - I(r, 0x44): Stereo-Balancewert des Samples.
 === Ende Beschreibung === */
int f_16842b(int p1, int p2, int p3)
{
    char *b;
    char *r;
    int old;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) {
        old = I(r,0x44);
        I(r,0x44) = p3;
        return old;
    }
    return 10;
}

//@ f_1684b1
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt die aktuelle Stereo-Panorama-Position (I(r, 0x44)) des aktiven Samples p2 auf dem
 *   Treiber p1 ab.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - aktueller Panning-Wert oder 10 bei Fehler.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1684b1(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) return I(r,0x44);
    return 10;
}

//@ f_168527
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Abspielgeschwindigkeit/Tonhöhe (Sample-Rate bzw. Pitch an Offset +0x34) des
 *   aktiven Samples p2 auf dem Treiber p1 auf p3 und gibt den alten Wert zurück.
 * - Eingaben: Treiber-Handle p1, Sample-Handle p2 und neuer Pitch-/Frequenzwert p3.
 * - Rückgabewert: int - vorheriger Wert oder 10 bei Fehler.
 * - Wichtige Variablen:
 *   - I(r, 0x34): Abtastrate beziehungsweise Tonhöhenversatz des Samples.
 === Ende Beschreibung === */
int f_168527(int p1, int p2, int p3)
{
    char *b;
    char *r;
    int old;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) {
        old = I(r,0x34);
        I(r,0x34) = p3;
        return old;
    }
    return 10;
}

//@ f_1685ad
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt die aktuelle Abspielgeschwindigkeit/Tonhöhe (I(r, 0x34)) des aktiven Samples p2 auf
 *   dem Treiber p1 ab.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - aktueller Pitch-/Frequenzwert oder 10 bei Fehler.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1685ad(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) return I(r,0x34);
    return 10;
}

//@ f_168623
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt die noch verbleibende Bytezahl (I(r, 0x48)) des aktiven Samples p2 auf dem Treiber
 *   p1 ab.
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - Wert an Offset +0x48 oder 10 bei Fehler.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_168623(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    if (FL(r) & 0x80) return I(r,0x48);
    return 10;
}

//@ f_168699
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Benutzer-Sample-ID (I(r, 0x1C)) des Sample-Slots p2 auf dem Treiber p1 aus.
 * - Eingaben: Treiber-Handle p1 und Sample-Slot p2.
 * - Rückgabewert: int - Benutzerkennung des Samples oder 10 bei ungültigem Treiber.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_168699(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    return I(r,0x1c);
}

//@ f_1686fd
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht unter allen 32 Sample-Slots des Treibers p1 nach dem Eintrag mit der
 *   Benutzer-Sample-ID p2 (+0x1C) und gibt dessen internes Sample-Handle (+0x28) zurück.
 * - Eingaben: Treiber-Handle p1 und gesuchte Sample-ID p2.
 * - Rückgabewert: int - gefundenes Sample-Handle (0..31), -1 bei Nichtfinden oder 10 bei ungültigem Treiber.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1686fd(int p1, int p2)
{
    char *b;
    unsigned i;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    for (i = 0; i < I(b,0x14); i++) {
        if (I(REC(b,i),0x1c) == p2) return I(REC(b,i),0x28);
    }
    return -1;
}

//@ f_168787
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den Statuswert an Offset +0x54 (Index des zuletzt verarbeiteten Kanals) des
 *   Soundtreibers p1 zurück.
 * - Eingaben: Treiber-Handle p1.
 * - Rückgabewert: int - Wert aus I(b, 0x54) oder 10 bei ungültigem Treiber.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_168787(int p1)
{
    char *b;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    return I(b,0x54);
}

//@ f_1687c9
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob das Sample p2 auf dem Soundtreiber p1 bereits fertig abgespielt ist ((FL(r) &
 *   0x80) == 0).
 * - Eingaben: Treiber-Handle p1 und Sample-Handle p2.
 * - Rückgabewert: int - 1 wenn das Sample beendet (inaktiv) ist, 0 wenn es noch läuft, oder 10 bei ungültigem
 *   Treiber.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1687c9(int p1, int p2)
{
    char *b;
    char *r;
    b = d_1af4c8[p1];
    if (b == 0) return 10;
    r = REC(b,p2);
    if (r == 0) return 10;
    return (FL(r) & 0x80) == 0;
}

//@ f_168843
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_168843(void)
{
}

//@ f_168858
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_168858(void)
{
}

//@ f_16886d
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert das SOS-Timer-Subsystem: Klinkt bei (p2 & 1) == 0 den
 *   Timer-Interrupt-Dispatcher f_168ecb über f_17b87d ein, setzt den Basis-Teiler des programmierbaren
 *   Intervalltimers (0x1234DC / p1) über f_168e96 und registriert f_168f6b für die Weiterleitung an den
 *   ursprünglichen DOS-Timer-Interrupt (18,2 Hz).
 * - Eingaben: Grundfrequenz p1 (oder 0xFF00 für Standard-DOS-Takt) und Steuerflags p2.
 * - Rückgabewert: int - gibt immer 0 zurück.
 * - Wichtige Variablen:
 *   - d_1af550: Status-Byte des Timer-Subsystems (Bit 0 = Hardware-Timer aktiv).
 *   - d_1af554: Aktuell programmierter PIT-Zählerteiler.
 === Ende Beschreibung === */
int f_16886d(unsigned p1, unsigned p2)
{
    int t;
    if (p2 & 2) d_1b3970 = 1; else d_1b3970 = 0;
    if ((p2 & 1) == 0) {
        d_1b396c = 1;
        d_1af550 |= 1;
        f_17b938();
        f_17b87d(0xffff, f_168ecb);
        f_17b964();
    } else {
        d_1af550 &= 0xfe;
    }
    if (p1 != 0 && (p2 & 1) == 0) {
                if (p1 == 0xff00) {
            f_168e96(0xffff);
            d_1af5d4 = 0xff00;
        } else {
            f_168e96(0x1234dc / p1);
            d_1af5d4 = p1;
        }
        d_1af594 = (int)f_168f6b;
        d_1af614 = 0x10000;

    } else {
        d_1af554 = 0xffff;
    }
        return 0;
}

//@ f_168944
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fährt das Timer-Subsystem herunter und stellt bei gesetztem Aktiv-Bit (d_1af550 & 1) über
 *   f_17b990 den ursprünglichen DOS-Timer-Interruptvektor wieder her.
 * - Eingaben: Ungenutzter Parameter p1.
 * - Rückgabewert: int - gibt immer 0 zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_168944(int p1)
{
    if (d_1af550 & 1) {
        f_17b938();
        f_17b990();
        f_17b964();
    }
    return 0;
}

//@ f_16897e
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Registriert eine periodische Timer-Callback-Funktion p2 mit der Aufruffrequenz p1 Hz in
 *   einem freien Slot (0..15) der Tabelle d_1af558, erhöht bei Bedarf die Hardware-Timer-Grundfrequenz
 *   (f_168e96), berechnet für alle aktiven Timer-Events die neuen 16.16-Festkomma-Schrittraten d_1af5d8[i] und
 *   gibt das zugewiesene Event-Handle in *p3 zurück.
 * - Eingaben: Gewünschte Frequenz p1 in Hz, Callback-Zeiger p2 und Rückgabezeiger p3 für das Handle.
 * - Rückgabewert: int - 0 bei Erfolg, 11 (0x0B) wenn alle 16 Timer-Slots belegt sind.
 * - Wichtige Variablen:
 *   - d_1af558: Array von 16 Funktionszeigern auf registrierte Timer-Callbacks.
 *   - d_1af598: Gewünschte Frequenz in Hz je Timer-Slot.
 *   - d_1af5d8, d_1af618: 16.16-Festkomma-Schrittweite und laufender Phasenakkumulator je Timer-Slot.
 === Ende Beschreibung === */
int f_16897e(unsigned p1, void (*p2)(void), unsigned *p3)
{
    unsigned i;
    unsigned idx;
    unsigned ratio;
    unsigned t;
    ratio = 0;
    for (i = 0; i < 0x10; i++) if (d_1af558[i] == 0) break;
    if (i >= 0x10) return 0xb;
    if (d_1af550 & 1) f_17b938();
    idx = i;
    d_1af558[i] = p2;
    d_1af598[i] = p1;
    if (0x1234dc / p1 < d_1af554) {
        f_168e96(0x1234dc / p1);
        ratio = (d_1af554 << 16) / (0x1234dc / p1);
    }
    for (i = 0; i < 0x10; i++) {
        if (d_1af558[i] != 0) {
            if (d_1af598[i] == 0xff00) {
                if (d_1af554 == 0xffff) {
                    d_1af5d8[i] = 0x10000;
                } else {
                    d_1af5d8[i] = 0x123333 / (0x1234dc / d_1af554);
                }
            } else {
                d_1af5d8[i] = (d_1af598[i] << 16) / (0x1234dc / d_1af554);
            }
            if (ratio != 0) {
                t = (d_1af618[i] * (ratio & 0xffff)) >> 16;
                t += (d_1af618[i] * (ratio >> 16)) >> 16;
                d_1af618[i] = t;
            }
        }
    }
    if (d_1af550 & 1) f_17b964();
    *p3 = idx;
    return 0;
}

//@ f_168b6c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Aufruffrequenz eines bereits registrierten Timer-Events p1 auf den neuen Wert
 *   p2 Hz und berechnet die Festkomma-Schrittraten aller aktiven Timer-Slots neu.
 * - Eingaben: Timer-Event-Handle p1 (0..15) und neue Frequenz p2 in Hz.
 * - Rückgabewert: int - 0 bei Erfolg, 10 bei ungültigem Handle.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_168b6c(unsigned p1, unsigned p2)
{
    unsigned i;
    if (p1 >= 0x10) return 10;
    if (d_1af558[p1] != 0) {
        if (d_1af550 & 1) f_17b938();
        d_1af598[p1] = p2;
        if (0x1234dc / p2 < d_1af554) f_168e96(0x1234dc / p2);
        for (i = 0; i < 0x10; i++) {
            if (d_1af558[i] != 0) {
                if (d_1af598[i] == 0xff00) {
                    if (d_1af554 == 0xffff) {
                        d_1af5d8[i] = 0x10000;
                    } else {
                        d_1af5d8[i] = 0x123333 / (0x1234dc / d_1af554);
                    }
                } else {
                    d_1af5d8[i] = (d_1af598[i] << 16) / (0x1234dc / d_1af554);
                }
                d_1af618[i] = 0;
            }
        }
        if (d_1af550 & 1) f_17b964();
    } else {
        return 10;
    }
    return 0;
}

//@ f_168cd4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entfernt das Timer-Event p1 aus der Tabelle d_1af558, ermittelt die höchste verbleibende
 *   Frequenz max unter den übrigen aktiven Events, programmiert den Hardware-Timer-Teiler über f_168e96
 *   entsprechend herunter und passt die Schrittraten d_1af5d8 aller verbleibenden Events an.
 * - Eingaben: Timer-Event-Handle p1.
 * - Rückgabewert: int - gibt immer 0 zurück.
 * - Wichtige Variablen:
 *   - max: Höchste noch benötigte Frequenz aller übrigen Timer-Callbacks.
 === Ende Beschreibung === */
int f_168cd4(int p1)
{
    unsigned i;
    unsigned max;
    max = 0;
    d_1af558[p1] = 0;
    for (i = 0; i < 0x10; i++) {
        if (d_1af558[i] != 0) if (d_1af598[i] > max && d_1af598[i] != 0xff00) max = d_1af598[i];
    }
    if (max != 0) f_168e96(0x1234dc / max); else f_168e96(0xffff);
    if (d_1af550 & 1) f_17b938();
    for (i = 0; i < 0x10; i++) {
        if (d_1af558[i] != 0) {
            if (d_1af598[i] == 0xff00) {
                if (d_1af554 == 0xffff) {
                    d_1af5d8[i] = 0x10000;
                } else {
                    d_1af5d8[i] = 0x123333 / (0x1234dc / d_1af554);
                }
            } else {
                d_1af5d8[i] = (d_1af598[i] << 16) / (0x1234dc / d_1af554);
            }
            d_1af618[i] = 0;
        }
    }
    if (d_1af550 & 1) f_17b964();
    return 0;
}

//@ f_168e6c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die aktuell eingestellte Frequenz (d_1af598[p1]) des Timer-Events p1 zurück.
 * - Eingaben: Timer-Event-Handle p1.
 * - Rückgabewert: unsigned - Frequenz in Hz.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
unsigned f_168e6c(int p1)
{
    return d_1af598[p1];
}

//@ f_168e96
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert den neuen Hardware-Timer-Teilerwert p1 in d_1af554 und schreibt ihn über
 *   f_17b837 in den Timer-Baustein (Port 0x40/0x43).
 * - Eingaben: Neuer PIT-Zählerteiler p1.
 * - Rückgabewert: int - gibt immer 0 zurück.
 * - Wichtige Variablen:
 *   - d_1af554: Aktueller Teilerwert des Hardware-Timers.
 === Ende Beschreibung === */
int f_168e96(int p1)
{
    d_1af554 = p1;
    f_17b837(p1);
    return 0;
}

//@ f_168ecb
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zentrale Timer-Interrupt-Serviceroutine: Addiert bei jedem Tick für alle 16 Slots die
 *   Schrittweite d_1af5d8[i] auf den Akkumulator d_1af618[i] und ruft, sobald das Überlauf-Bit im oberen Wort
 *   (d_1af61a[i*4] & 1) gesetzt ist, die zugehörige Callback-Funktion d_1af558[i]() auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1af618, d_1af61a: 32-Bit-Phasenakkumulator und dessen oberes 16-Bit-Überlaufwort.
 === Ende Beschreibung === */
void f_168ecb(void)
{
    unsigned i;
    for (i = 0; i < 0x10; i++) {
        if (d_1af558[i] != 0) {
            d_1af618[i] += d_1af5d8[i];
            if (d_1af61a[i*4] & 1) {
                *(short *)&d_1af61a[i*4] = 0;
                if (d_1af658[i*4] != 0xff) d_1af698 = d_1af658[i*4];
                d_1af558[i]();
            }
        }
    }
}

//@ f_168f6b
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Standard-Callback für die 18,2-Hz-Systemuhr, der über f_17ba0c an den alten
 *   DOS-Timer-Interrupt weiterleitet.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_168f6b(void)
{
    f_17ba0c();
}

//@ f_168f85
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_168f85(void)
{
}

//@ f_168f9a
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_168f9a(void)
{
}

//@ f_168faf
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet und initialisiert einen digitalen Soundtreiber p1: Trägt ihn in einen freien Slot
 *   von d_1af4c8 ein, lädt bei Bedarf das Treiber-Binärmodul (f_17ba7b) sowie die Sample- und Mischerpuffer
 *   (0x1E00 und 0x4000 Bytes), reserviert über f_1695ef den DMA-Puffer im unteren DOS-Speicher, füllt ihn mit
 *   Stille (0x80 bei 8-Bit unsigned, sonst 0), initialisiert die Hardware über die Treiber-Einsprungpunkte
 *   (f_17c2e3..f_17c367) und schreibt das Treiber-Handle nach *p2.
 * - Eingaben: Zeiger p1 auf die Treiber-Konfigurationsstruktur und Rückgabezeiger p2 für das Treiber-Handle.
 * - Rückgabewert: int - 0 bei Erfolg, sonst SOS-Fehlercode (z. B. 5 bei Speichermangel).
 * - Wichtige Variablen:
 *   - d_1af4c8: Array der aktiven Soundtreiber-Instanzen.
 *   - I(p1, 0x3c), I(p1, 0x44): Zeiger und Größe des DMA-Abspielpuffers.
 === Ende Beschreibung === */
int f_168faf(char *p1, unsigned *p2)
{
    unsigned i;
    unsigned j;
    int rc;
    for (i = 0; i < 5; i++) if (d_1af4c8[i] == 0) break;
    if (i == 6) return 0xb;
    d_1af4c8[i] = p1;
    if (I(p1,0xd8) == 0) if (U16(p1,0xdc) == 0) {
        rc = f_17ba7b(I(p1,0x104), i, (int)(p1+0xe0), (int)(p1+0xd8), (int)(p1+0xfc), (int)(p1+0xe8), (int)(p1+0xec));
        if (rc != 0) return rc;
        I(p1,0x58) = f_17bd4d(0x1e00);
        I(p1,0x48) = f_17bd4d(0x4000);
        U8(p1,0) |= 2;
    }
    f_145300(PT(p1,0x58), 0, 0x1e00);
    rc = f_17be61(i, (int)(p1+0x6c));
    if (rc != 0) return rc;
    if (I(p1,0x3c) == 0) {
        U8(p1,0) |= 4;
        if ((I(p1,0x3c) = f_1695ef(I(p1,0x44), (int)(p1+0xf0), (int)(p1+0x100), (int)(p1+0xf4))) == 0) {
            f_17bc5d(i);
            return 5;
        }
        if (I(p1,0x90) == 8) {
            if (U8(p1,0xa9) & 0x80) {
                for (j = 0; j < I(p1,0x44); j++) PT(p1,0x3c)[j] = 0;
            } else {
                for (j = 0; j < I(p1,0x44); j++) PT(p1,0x3c)[j] = 0x80;
            }
        } else {
            for (j = 0; j < I(p1,0x44); j++) PT(p1,0x3c)[j] = 0;
        }
    }
    PT(p1,0x40) = PT(p1,0x3c) + I(p1,0x44);
    I(p1,0x18) = d_1af8f0[I(p1,0x64)];
    I(p1,0x28) = I(p1,0x3c);
    PT(p1,0x4c) = PT(p1,0x48) + 0x4000;
    I(p1,0x50) = 0x4000;
    I(p1,0x30) = 0;
    I(p1,0x54) = -1;
    I(p1,0x2c) = 0x400;
    I(p1,0x14) = 0x20;
    I(p1,0xc) = I(p1,0x90);
    I(p1,0x8) = I(p1,0x94) + 1;
    I(p1,0x10) = 0x8000;
    I(p1,0x108) = d_1af910[i];
    I(p1,0x1c) = 0;
    I(p1,0x20) = 0;
    I(p1,0x24) = 0;
    if (U8(p1,0xa9) & 2) {
        *(char __far **)(p1+0x34) = f_17c6b1(I(p1,0xe0), U16(p1,0xe4), I(p1,0xd8), U16(p1,0xdc));
    }
    f_17c3b8(I(p1,0x64));
    f_17c2e3(I(p1,0xe0), U16(p1,0xe4), I(p1,0xd8), U16(p1,0xdc), I(p1,0x5c), I(p1,0x60), I(p1,0x64), I(p1,0x68), I(p1,0x68), I(p1,0x68));
    f_17c367(I(p1,0xe0), U16(p1,0xe4), I(p1,0xd8), U16(p1,0xdc));
    f_17c341(I(p1,0xe0), U16(p1,0xe4), I(p1,0xd8), U16(p1,0xdc), I(p1,4));
    f_17c318(I(p1,0xe0), U16(p1,0xe4), I(p1,0xd8), U16(p1,0xdc), I(p1,0xf0), I(p1,0x44));
    U8(p1,0) |= 1;
    *p2 = i;
    return 0;
}
