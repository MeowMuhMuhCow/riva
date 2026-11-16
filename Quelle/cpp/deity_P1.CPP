/* === Beschreibung (Katalog) ===
 * Einheit deity (053f20 - 054de0)
 *
 * Überblick
 * Diese Einheit (deity.cpp) implementiert die Gottheits- und Wunder-Klasse (struct Deity) für die Tempel in
 * *Schatten über Riva*. Sie lädt und speichert den göttlichen Gunst- und Tempelstatus aus der Spielstanddatei
 * (0x220004), berechnet die Wunderwahrscheinlichkeit beim Gebet, reduziert das Karmakonto nach einem Gebet und
 * führt die individuellen göttlichen Wunder der verschiedenen Götter (Heilung, Wiederbelebung, Krankheitsschutz,
 * Attributs- und Talentboni, Ausdauer, Nahrung/Wasser) auf die Heldengruppe aus.
 === Ende Beschreibung === */
// P3 18/23 gleich (suche.py 29.10.2026, Basis deity_P1.CPP)
// 05.11. DeepSeek 3202: f_0542a0 Rest 6 -> 4 (volatiler Store auf d_1c11e0 im 16er-Zweig)
// 05.11. Opus W41: f_0542a0 Rest 4 -> GLEICH (ok nicht volatile, heal ohne Rueckgabe, Aufrufer prueft frame.ok, t=frame.saved)
// 06.11. Opus W117: f_0545b0 Rest 26 -> 11 (Inline-Helfer nach Demo f_054bd0, short-Aufruf f_145850, Byte-Nullerweiterung, k-Kopie, r-Umlauf)
// deity.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x053F20-0x054DE0
#include <string.h>
#include "RIVAMEM.H"



int f_038ba0(int p1);
int f_038d00(int p1);
int f_039070(int p1);
int f_042480(int p1, int p2);
char f_0426c0(int p1);
int f_042920(int p1, int p2);
int f_042930(int p1, int p2);
int f_042960(int p1);
int f_042970(int p1);
int f_044890(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0dba60(int p1, int p2);
int f_0dbda0(int p1);
int f_0dc3c0(int p1, int p2, int p3, int p4, int p5);
int f_0dce50(int p1, int p2);
int f_11ea00(int p1, int p2, int p3, int p4, int p5);
int f_11ea90(int p1, int p2, int p3, int p4, int p5);
int f_125400(int p1, int p2, int p3, int p4);
void *f_1254a0(void *p, int fl);
int f_125ed0(int p1, int p2);
int f_133fe0(int p1, int p2);
short f_1457e0(int p1);
int f_145850(int p1, int p2, int p3);
extern int d_1bc88c;
extern int d_1c0004;
extern short d_1c11d4;
extern volatile int d_1c11d8;
extern short d_1c11dc;
extern int d_1c11e0;
extern volatile int d_1c1208;
extern volatile int d_1c1218;
extern volatile int d_1c121c;
extern signed char d_1c1220;
extern unsigned short d_1c1224;
extern unsigned short d_1c122c;
extern volatile int d_1c1230;
extern volatile int d_1c1234;
extern int d_1c2198;
extern signed char d_1c21b4;
extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a1648[];


typedef short PS;
struct W { short s0; short s2; };
struct Slot { int a0; int v; };
struct Rec { int u0; Slot *s4; int u8; int uc; Slot *s10; W *s14; ~Rec(); };
#define DELREC(r) delete (r)
struct Stat { short a; short b; int c; short d; };
struct Deity { short id; int state; Rec *rec; Stat st; };
int f_0542a0(Deity *t, PS p2);
int f_054bd0(Deity *t, short p2);
int f_054500(Deity *t, PS p2);
int f_0546d0(Deity *t, PS p2);
int f_0547a0(Deity *t, PS p2);
int f_054900(Deity *t, PS p2);
int f_054a60(Deity *t, PS p2);

#define TRACE(L,F) do { char *tp_ = (char *)operator new(1, mark(d_1a1648, L)); F((int)tp_, 0x220004, t->id, (int)&t->st, 10); operator delete(tp_); } while (0)
int f_145300(int p1, int p2, int p3);
//@ f_053f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein Deity-Objekt für die Gottheit id, legt den Textplatzhalter-Kontext rec an und
 *   lädt die gespeicherten Gunst- und Tempelwerte dieser Gottheit (10 Bytes) aus dem Spielstand (0x220004).
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger t (Deity *) sowie die Gottheits-ID id (short)
 *   und gibt t zurück.
 * - Wichtige Variablen: Das Feld t->id speichert die Gottheitsnummer, t->state wird mit der Standardmeldung
 *   0x1c00000c ("Die Götter erhören Euch nicht") vorbelegt, und f_11ea00 liest die 10 Bytes der Struktur t->st
 *   (a, b, c, d).
 === Ende Beschreibung === */
Deity *f_053f20(Deity *t, short id)
{
    t->state=0;
    t->id=id;
    t->rec=0;
    f_145300((int)&t->st,0,10);
    Deity *p=t; Rec *r=(Rec *)operator new(0x3c,mark(d_1a1648,0x96)); p->rec=r ? (Rec *)f_125400((int)r,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498) : r; d_1c21b4=0; p->state=0x1c00000c;
    { char *tp_=(char *)operator new(1,mark(d_1a1648,0x9a)); f_11ea00((int)tp_,0x220004,p->id,(int)&p->st,10); operator delete(tp_); }
    return t;
}
//@ f_053fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut das Deity-Objekt ab, schreibt zuvor die geänderten Gunst- und Tempelwerte t->st in die
 *   Spielstanddatei 0x220004 zurück und gibt den Textkontext t->rec frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger t sowie ein Freigabeflag fl entgegen und gibt t
 *   zurück.
 * - Wichtige Variablen: Über f_11ea90 werden die 10 Bytes aus t->st zurückgeschrieben und anschließend t->rec
 *   gelöscht.
 === Ende Beschreibung === */
Deity *f_053fd0(Deity *t, int fl)
{
    TRACE(0xb3, f_11ea90);
    DELREC(t->rec);
    return t;
}
//@ f_054030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Gunst-/Spendenwert t->st.c der Gottheit direkt auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält t und den neuen Wert v (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beschrieben wird das 32-Bit-Feld t->st.c.
 === Ende Beschreibung === */
void f_054030(Deity *t, int v)
{
    t->st.c = v;
}
//@ f_054040
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den aktuellen Gunst-/Spendenwert t->st.c der Gottheit zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt t entgegen und gibt t->st.c als int zurück.
 * - Wichtige Variablen: Gelesen wird das Feld t->st.c.
 === Ende Beschreibung === */
int f_054040(Deity *t)
{
    return t->st.c;
}
//@ f_054050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert den Gunst-/Spendenwert t->st.c der Gottheit um den Differenzbetrag d.
 * - Eingaben und Rückgabe: Die Funktion erhält t und das Delta d (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Angepasst wird t->st.c += d.
 === Ende Beschreibung === */
void f_054050(Deity *t, int d)
{
    t->st.c += d;
}
//@ f_054060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt ein Gebet im Tempel der Gottheit t aus: Aus Grundchance t->st.a und Gunstwert t->st.c
 *   wird die Wunderchance berechnet, der Gunstwert um 10 reduziert, über f_0542a0 auf ein Wunder geprüft (wobei
 *   bei Erfolg 15 Zeiteinheiten vergehen) und schließlich die Ergebnismeldung t->state in einem Textfenster
 *   ausgegeben.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger t entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Erfolgschance berechnet sich als pct = t->st.a + (t->st.c / 100) * t->st.b, danach
 *   wird t->st.c um 10 (mindestens auf 0) gesenkt und die Meldung t->state über f_0bf730 angezeigt.
 === Ende Beschreibung === */
void f_054060(Deity *t)
{
    short a = t->st.a;
    int q = t->st.c / 100;
    a += (short)((short)q * t->st.b);
    short pct = a;
    if (t->st.c > 0) { t->st.c -= 10; if (t->st.c < 0) t->st.c = 0; }
    if (f_0542a0(t, pct) == 1) f_125ed0((int)&d_1c2c44, 15);
    if (t->state == 0) {
        if (d_1c21b4 > 0) t->state = f_133fe0((int)&d_1c3498, (int)&d_1c21b4);
        else t->state = 0x1c00000c;
    }
    f_0bf730((int)&d_1c2c64, t->state);
    t->state = 0x1c00000c;
    d_1c21b4 = 0;
}
//@ f_054110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt zu der in *p gespeicherten Gottheits-ID die zugehörige Text-Ressourcenkennung des
 *   Gottesnamens (*p + 0x20000012).
 * - Eingaben und Rückgabe: Die Funktion erhält einen Zeiger p (short *, z. B. &t->id) und gibt die Text-ID als
 *   int zurück.
 * - Wichtige Variablen: Addiert wird der Basisoffset 0x20000012 auf die 16-Bit-Gottheitsnummer *p.
 === Ende Beschreibung === */
int f_054110(short *p)
{
    return *p + 0x20000012;
}
//@ f_054120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert den Textplatzhalter-Kontext t->rec eines Deity-Objekts und lädt dessen
 *   10-Byte-Zustandsblock t->st über f_11ea00 aus dem Spielstand.
 * - Eingaben und Rückgabe: Die Funktion nimmt t entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Setzt d_1c21b4 = 0, t->state = 0x1c00000c und lädt t->st aus 0x220004.
 === Ende Beschreibung === */
void f_054120(Deity *t)
{
    Rec *r=(Rec*)operator new(0x3c,mark(d_1a1648,0x96)); if(r) t->rec=(Rec*)f_125400((int)r,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498); else t->rec=r;
    d_1c21b4 = 0;
    t->state = 0x1c00000c;
    TRACE(0x9a, f_11ea00);
}
//@ f_0541b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert den 10-Byte-Zustandsblock t->st des Deity-Objekts über f_11ea90 in den Spielstand
 *   zurück und gibt t->rec frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt t entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt t->st in die Ressource 0x220004 und baut t->rec ab.
 === Ende Beschreibung === */
void f_0541b0(Deity *t)
{
    TRACE(0xb3, f_11ea90);
    DELREC(t->rec);
}
//@ f_054210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die aktuelle prozentuale Gebets-Erfolgschance bei der Gottheit t aus dem Basiswert
 *   t->st.a und dem Gunstbonus (t->st.c / 100) * t->st.b.
 * - Eingaben und Rückgabe: Die Funktion erhält t und gibt die berechnete Chance als short zurück.
 * - Wichtige Variablen: Ausgewertet werden t->st.a, t->st.b und t->st.c.
 === Ende Beschreibung === */
short f_054210(Deity *t)
{
    short a = t->st.a;
    int q = t->st.c / 100;
    return a + (short)((short)q * t->st.b);
}
//@ f_054240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht nach einem Gebet 10 Punkte vom Gunstwert t->st.c der Gottheit ab und begrenzt ihn nach
 *   unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion nimmt t entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verändert wird t->st.c.
 === Ende Beschreibung === */
void f_054240(Deity *t)
{
    if (t->st.c > 0) { t->st.c -= 10; if (t->st.c < 0) t->st.c = 0; }
}
//@ f_0542a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Würfelt beim Gebet, ob die Gottheit t bei einer Erfolgschance p2 ein Wunder gewährt: Mit 10 %
 *   Unterchance wird zunächst ein toter Held der Gruppe wiederbelebt (f_039070, f_042480), andernfalls wird ein
 *   Wurf 1..t->st.a ausgeführt und an die gottheitsspezifische Wunderfunktion (t->id == 3, 4, 7, 8, 9, 12, 14)
 *   verzweigt.
 * - Eingaben und Rückgabe: Die Funktion erhält t sowie die Erfolgschance p2 (short) und gibt als int den Wert 1
 *   zurück, wenn ein gottheitsspezifisches Wunder ausgelöst wurde, sonst 0.
 * - Wichtige Variablen: Für t->id == 4 (Efferd/Travia/Peraine-Zweig) ist die Wunderbehandlung
 *   (DeityCase670::run: Sättigung f_0dbda0, Heilung 1W6+2 LE oder Schutztimer d_1c11e0 = 0xdd7c0) direkt
 *   inlined, während für die übrigen Götter f_054500, f_0546d0, f_0547a0, f_054900 und f_054a60 aufgerufen
 *   werden.
 === Ende Beschreibung === */
struct HealFrame670 {
 int ok;Deity *saved;volatile int maximum;int current; // volatile an maximum haelt den Rahmen als Block zusammen
 void heal(short amount,Deity *t){
  int actor=0;actor=f_038d00(d_1c0004);
  maximum=f_042970(actor);current=f_042960(actor);int remaining=maximum-current;ok=0;
  if(actor){
   if(amount>(short)remaining)amount=remaining;
   f_044890(actor,amount);
   t->rec->s4->v=actor;t->rec->s14->s2=amount;
   { unsigned char cb=amount>1; int vv=cb+0x2000002a; t->rec->s10->v=vv; }
   ok=1;
  }
 }
};
struct DeityCase670 {static int run(Deity *t,short roll){
 HealFrame670 frame;frame.saved=t;
 int result=0;
 int value=roll;
 if(value<=10){t->state=0x1c000017;f_0dbda0(d_1c0004);result=1;}
 else if(value<=15){
  frame.heal(f_145850(1,6,2),t);if(frame.ok==1){t=frame.saved;result=1;t->state=0x1c000018;} // t neu aus frame laden: Laden vor result=1, ok-Ladung in EBX
 }else if(value<=16){t->state=0x1c000019;/* Volatiler Store haelt die Store-Reihenfolge wie im Original */ *(volatile int *)&d_1c11e0=0xdd7c0;result=1;}
 return result;
}};
int f_0542a0(Deity *t, PS p2)
{
    int r = 0;
    if (f_1457e0(100) <= (short)p2) {
        if (f_1457e0(100) <= 10) {
            int p = f_039070(d_1c0004);
            int ok = 0;
            if (p) { f_042480(p, 0); f_044890(p, 7); t->rec->s4->v = p; *(volatile short *)&d_1c2198 = 1; ok = 1; }
            if (ok == 1) t->state = 0x1c00000d;
        }
        else if (t->st.a > 0) {
            short x = f_1457e0(t->st.a);
            switch (t->id) {
            case 1: case 2: break;
            case 3: r = f_054500(t, x); break;
            case 4: r = DeityCase670::run(t, x); break;
            case 7:
            case 14: r = f_0546d0(t, x); break;
            case 8: r = f_0547a0(t, x); break;
            case 9: r = f_054900(t, x); break;
            case 12: r = f_054a60(t, x); break;
            }
        }
    }
    return r;
}

//@ f_0544f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Wunderfunktion (für Götter ohne eigenes Spezialwunder), die stets 0 zurückgibt.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt als int stets 0 zurück.
 * - Wichtige Variablen: Es werden keine Variablen verändert.
 === Ende Beschreibung === */
int f_0544f0()
{
    return 0;
}
//@ f_054500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Spezialwunder der Gottheit 3 (Rondra) anhand des Wurfs p2 aus: Gewährt entweder zwei
 *   verschiedene Kampf-Segenstimer (d_1c11d4 = 0x5eec0 bzw. d_1c11d8 = 0x5eec0) oder erhöht vorübergehend das
 *   Schwerter-/Waffentalent (0x0e) der Gruppe um +2 (f_0dc3c0, Dauer d_1c1208 = 0x7e900).
 * - Eingaben und Rückgabe: Die Funktion erhält t und den Wurf p2 (short) und gibt als int den Wert 1 bei Erfolg
 *   oder 0 zurück.
 * - Wichtige Variablen: Gesetzt werden die Segenstimer d_1c11d4, d_1c11d8 oder d_1c1208 sowie die entsprechende
 *   Wunder-Textkennung 0x1c000014 bis 0x1c000016 in t->state.
 === Ende Beschreibung === */
int f_054500(Deity *t, PS p2)
{
    int r = 0;
    if ((short)p2 <= 5) { t->state = 0x1c000014; *(volatile int *)&d_1c11d4 = 0x5eec0; r = 1; }
    else if ((short)p2 <= 8) { t->state = 0x1c000015; d_1c11d8 = 0x5eec0; r = 1; }
    else if ((short)p2 <= 9 && d_1c1208 == 0) {
        t->state = 0x1c000016;
        *(int *)&d_1c1208 = 0x7e900;
        int e = d_1c1208;
        int a = 0xe;
        int one = 1;
        d_1bc88c = one;
        f_0dc3c0((a = d_1c0004), e, (signed char)a, 2, one);
        d_1bc88c = 0;
        r = 1;
    }
    return r;
}
//@ f_0545b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Spezialwunder der Gottheit 4 anhand des Wurfs p2 aus: Stillt bei p2 <= 10 Hunger und
 *   Durst der gesamten Gruppe (f_0dbda0), heilt bei p2 <= 15 den am schwersten verletzten Helden um 1W6+2
 *   Lebenspunkte oder aktiviert bei p2 == 16 den Schutztimer d_1c11e0 = 0xdd7c0.
 * - Eingaben und Rückgabe: Die Funktion erhält t und den Wurf p2 (short) und gibt als int den Wert 1 bei Erfolg
 *   oder 0 zurück.
 * - Wichtige Variablen: Über f_038d00(d_1c0004) wird das am stärksten verwundete Gruppenmitglied gesucht und mit
 *   f_044890 geheilt; die Textmeldungen sind 0x1c000017 bis 0x1c000019.
 === Ende Beschreibung === */
int f_0545b0(Deity *t, PS p2)
{
    int a;
    int b;
    int rem;
    int p;
    int k;
    short n;
    Deity * owner;
    int r;
    int ok;
    int rtA6;
    r=0;
    if((short)p2<=10) {t->state=0x1c000017;f_0dbda0(d_1c0004);r=1;}
    else if((short)p2<=15) {
        rtA6=d_1c0004;d_1c0004=rtA6; // Haelt die Registerfolge fuer d_1c0004

        { short rt0=*(short *)&d_1c0004; *(short *)&d_1c0004=rt0; short rt1=((short *)&d_1c0004)[1]; ((short *)&d_1c0004)[1]=rt1; } // Haelt den identischen Feldwert
        n = ((short (*)(int,int,int))f_145850)(1,6,2);
        owner=t;
        p=f_038d00(d_1c0004);
        a=f_042970(p);
        a=(a&0)?0:a; // Haelt das Maximum als Mehrblockwert
        b=f_042960(p);
        b=(b&0)?0:b; // Haelt den aktuellen Wert als Mehrblockwert
        rem=a-b;
        ok=0;
        if(p) {
            if(n>(short)rem) n=rem;
            k=n;
            f_044890(p,k);
            owner->rec->s4->v=p;
            owner->rec->s14->s2=n;
            owner->rec->s10->v=(unsigned char)(k>1)+0x2000002a;
            ok=1;
        }
        if(ok==1) {t->state=0x1c000018;r=1;}
    }
    else if((short)p2<=16) {t->state=0x1c000019;*(volatile int *)&d_1c11e0=0xdd7c0;r=1;}
    return r;
}
//@ f_0546d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Spezialwunder der Gottheiten 7 und 14 (Firun / Ifirn) anhand des Wurfs p2 aus: Setzt
 *   bei p2 <= 3 bzw. p2 <= 6 den Kälteschutz-/Jagdtimer d_1c11dc auf 0x5eec0 bzw. 0xdd7c0 oder verleiht bei p2
 *   == 7 einem nichtmagischen Gruppenmitglied temporäre Astralenergie/Zauberschutz (f_0d5040, Dauer d_1c1218 =
 *   0xdd7c0).
 * - Eingaben und Rückgabe: Die Funktion erhält t und den Wurf p2 (short) und gibt als int den Wert 1 bei Erfolg
 *   oder 0 zurück.
 * - Wichtige Variablen: Beschrieben werden d_1c11dc und d_1c1218 sowie t->state (0x1c000020 bzw. 0x1c000021).
 === Ende Beschreibung === */
int f_0546d0(Deity *t, PS p2)
{
    int r = 0;
    int p = 0;
    if ((short)p2 <= 3) {
        t->state = 0x1c000020;
        *(volatile int *)&d_1c11dc = 0x5eec0;
        r = 1;
    } else {
        if ((short)p2 <= 6) {
            t->state = 0x1c000020;
            *(volatile int *)&d_1c11dc = 0xdd7c0;
            r = 1;
        } else {
            if ((short)p2 <= 7 && d_1c1218 == 0) {
                p = f_038ba0(d_1c0004);
                if (p != 0 && !f_0426c0(p)) {
                    short n = f_0d4c80(p);
                    t->rec->s4->v = p;
                    t->state = 0x1c000021;
                    d_1c1218 = 0xdd7c0;
                    f_0d5040(p, n, d_1c1218, 0, 1, 6);
                    f_042920(p, 0);
                    f_042930(p, 0);
                    r = 1;
                }
            }
        }
    }
    return r;
}
//@ f_0547a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Spezialwunder der Gottheit 8 (Tsa / Peraine) anhand des Wurfs p2 aus: Heilt bei p2
 *   <= 10 ein verletztes Gruppenmitglied um 2W6 Lebenspunkte, gewährt bei p2 <= 15 der Gruppe 1000
 *   Ausdauer-/Regenerationspunkte (f_0dba60) oder erweckt bei p2 <= 18 einen toten Helden mit 7 Lebenspunkten
 *   wieder zum Leben.
 * - Eingaben und Rückgabe: Die Funktion erhält t und den Wurf p2 (short) und gibt als int den Wert 1 bei Erfolg
 *   oder 0 zurück.
 * - Wichtige Variablen: Die Meldungskennungen 0x1c000022 bis 0x1c000024 werden in t->state gespeichert, und bei
 *   Wiederbelebung wird d_1c2198 = 1 gesetzt.
 === Ende Beschreibung === */
static inline int HA(Deity *t0, short n)
{
    short lim;
    int p = f_038d00(d_1c0004);
    int b;
    int a = f_042970(p);
    b = f_042960(p);
    Deity *t = t0;
    lim = a - b;
    int r = 0;
    (void)&r;
    if (p != 0) {
        if (n > lim) n = a - b;
        { short rt309_ = lim; lim = rt309_; } // Haelt den Umlauf fuer lim
        { short rt = n; n = rt; } // Haelt den Umlauf fuer n
        f_044890(p, n);
        t->rec->s4->v = p;
        t->rec->s14->s2 = n;
        t->rec->s10->v = (n > 1) ? 0x2000002b : 0x2000002a;
        r = 1;
    }
    return r;
}
static inline int HB(Deity *t)
{
    int p = f_039070(d_1c0004);
    int r = 0;
    if (p != 0) {
        f_042480(p, 0);
        f_044890(p, 7);
        t->rec->s4->v = p;
        *(volatile short *)&d_1c2198 = 1;
        r = 1;
    }
    return r;
}
int f_0547a0(Deity *t, PS p2)
{
    int r = 0;
    if ((short)p2 <= 10) {
        int x = f_145850(2, 6, 0);
        if (HA(t, x) == 1) { t->state = 0x1c000022; r = 1; }
    } else if ((short)p2 <= 15) {
        t->state = 0x1c000023; f_0dba60(d_1c0004, 1000); r = 1;
    } else if ((short)p2 <= 18) {
        if (HB(t) == 1) { t->state = 0x1c000024; r = 1; }
    }
    return r;
}
//@ f_054900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt (sofern der Gunstwert t->st.c > 500 ist) die Spezialwunder der Gottheit 9 (Phex) anhand
 *   des Wurfs p2 aus: Gewährt für 0x5eec0 Zeiteinheiten entweder einen Bonus von +1 auf Schleichen und
 *   Verstecken (0x31, 0x30), einen Bonus von +1 auf Taschendiebstahl/Feilschen (0x15) oder einen Bonus von +1
 *   auf ein Grundattribut (3, Charisma/Gewandtheit).
 * - Eingaben und Rückgabe: Die Funktion erhält t und den Wurf p2 (short) und gibt als int den Wert 1 bei Erfolg
 *   oder 0 zurück.
 * - Wichtige Variablen: Die Sperrtimer d_1c121c, d_1c1220 und d_1c1224 verhindern eine mehrfache Stapelung
 *   desselben Phex-Segens, während f_0dc3c0 die temporären Boni auf die Gruppe d_1c0004 anwendet.
 === Ende Beschreibung === */
// BLIND: f_054900 hier komplett neu aus dem Original-Assembler schreiben (orig.sh deity f_054900).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
int f_054900(Deity *t, PS p2)
{
    int z;
    int r = 0;
    if (t->st.c > 500) {
        if ((short)p2 <= 5) {
            if (d_1c121c == 0) {
                t->state = 0x1c000025;
                d_1c121c = 0x5eec0;
                { int e = d_1c121c; int a = 0x31; int one = 1; d_1bc88c = one; f_0dc3c0((a = d_1c0004), e, (signed char)a, one, one); }
                { int e = d_1c121c; int a = 0x30; int one = 1; int zero = 0; d_1bc88c = one; f_0dc3c0((a = d_1c0004), e, (signed char)a, one, one); d_1bc88c = zero; }
                r = 1;
            }
        } else if ((short)p2 <= 8) {
            if (*(volatile int *)&d_1c1220 == 0) {
                t->state = 0x1c000026;
                *(volatile int *)&d_1c1220 = 0x5eec0;
                { int e = *(volatile int *)&d_1c1220; int a = 0x15; int one = 1; d_1bc88c = one; f_0dc3c0((a = d_1c0004), e, (signed char)a, one, one); d_1bc88c = 0; }
                r = 1;
            }
        } else if ((short)p2 <= 9) {
            z = *(volatile int *)&d_1c1224;
            if (z == 0) {
                t->state = 0x1c000027;
                *(volatile int *)&d_1c1224 = 0x5eec0;
                { int e = *(volatile int *)&d_1c1224; int a = 3; signed char c4 = 1; d_1bc88c = 1; f_0dc3c0((a = d_1c0004), e, (signed char)a, c4, z); d_1bc88c = 0; }
                r = z + 1; // Haelt z ueber den Aufruf lebendig
            }
        }
    }
    return r;
}

//@ f_054a60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Spezialwunder der Gottheit 12 (Rahja / Travia / Ingerimm) anhand des Wurfs p2 aus:
 *   Erhöht bei p2 <= 8 vorübergehend die Talente 0x14 und 0x10 um +2 (d_1c122c = 0xdd7c0), steigert bei p2 <= 13
 *   das Attribut 2 (Charisma) vorübergehend um +1 (d_1c1230 = 0x5eec0) oder regeneriert bei p2 == 14 über
 *   f_0dce50 zwei Gruppenwerte (d_1c1234 = 0xdd7c0).
 * - Eingaben und Rückgabe: Die Funktion erhält t und den Wurf p2 (short) und gibt als int den Wert 1 bei Erfolg
 *   oder 0 zurück.
 * - Wichtige Variablen: Verwaltet werden die Segenstimer d_1c122c, d_1c1230 und d_1c1234 sowie die Meldungen
 *   0x1c00002d bis 0x1c00002f.
 === Ende Beschreibung === */
#define V122C (*(volatile int *)&d_1c122c)
int f_054a60(Deity *t, PS p2)
{
    int k = p2;
    int r = 0;
    if (k <= 8) {
        if (V122C == 0) {
            t->state = 0x1c00002d;
            V122C = 0xdd7c0;
            { int e = V122C; int a = 0x14; int one = 1; d_1bc88c = one; f_0dc3c0((a = d_1c0004), e, (signed char)a, 2, one); }
            { int e = V122C; int a = 0x10; int one = 1; int zero = 0; d_1bc88c = one; f_0dc3c0((a = d_1c0004), e, (signed char)a, 2, one); d_1bc88c = zero; }
            r = 1;
        }
    } else {
        if (k <= 13) {
            int z = d_1c1230;
            if (z == 0) {
                t->state = 0x1c00002e;
                d_1c1230 = 0x5eec0;
                { int e_ = d_1c1230; int a = 2; signed char c4_ = 1; int c5_ = z; d_1bc88c = 1; f_0dc3c0((a = d_1c0004), e_, (signed char)a, c4_, c5_); d_1bc88c = 0; }
                r = 1;
            }
        } else {
            if (k <= 14) {
                if (d_1c1234 == 0) {
                    t->state = 0x1c00002f;
                    d_1c1234 = 0xdd7c0;
                    f_0dce50(d_1c0004, 0x14);
                    f_0dce50(d_1c0004, 0x10);
                    r = 1;
                }
            }
        }
    }
    return r;
}
//@ f_054ba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kapselt den Aufruf von f_0dc3c0, um einen temporären göttlichen Attributs- oder Talentbonus
 *   auf die gesamte Heldengruppe d_1c0004 anzuwenden.
 * - Eingaben und Rückgabe: Die Funktion erhält t, die Wirkungsdauer p2, die Eigenschafts-/Talentkennung p3, den
 *   Bonuswert p4 sowie die Kategorie p5 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Während des Aufrufs von f_0dc3c0 wird das globale Schutzflag d_1bc88c auf 1 und danach
 *   wieder auf 0 gesetzt.
 === Ende Beschreibung === */
void f_054ba0(Deity *t, int p2, signed char p3, signed char p4, signed char p5)
{
    d_1bc88c = 1;
    f_0dc3c0(d_1c0004, p2, p3, p4, p5);
    d_1bc88c = 0;
}
//@ f_054bd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Heilt das am stärksten verwundete Gruppenmitglied (f_038d00(d_1c0004)) um bis zu p2
 *   Lebenspunkte (höchstens bis zum Maximum) und trägt den Namen des Geheilten sowie die geheilte Punktzahl in
 *   die Textplatzhalter von t->rec ein.
 * - Eingaben und Rückgabe: Die Funktion erhält t sowie die maximale Heilmenge p2 (short) und gibt als int den
 *   Wert 1 zurück, wenn ein Held geheilt wurde, sonst 0.
 * - Wichtige Variablen: Die Differenz aus Maximal-LE (f_042970) und aktueller LE (f_042960) begrenzt p2, bevor
 *   f_044890(p, p2) aufgerufen wird.
 === Ende Beschreibung === */
int f_054bd0(Deity *t, short p2)
{
    int p = f_038d00(d_1c0004);
    int saved_global = d_1c0004; d_1c0004 = saved_global; // Haelt die Registerfolge fuer d_1c0004
    union Saved { int v; short w[2]; } a;
    a.v = f_042970(p);
    a.w[0] ^= a.w[1] ^ a.w[1]; // Wort-Alias haelt den 4-Byte-Slot
    int n = a.v - f_042960(p);
    int r = 0;
    if (p) {
        if (p2 > (short)n) p2 = n;
        f_044890(p, p2);
        t->rec->s4->v = p;
        t->rec->s14->s2 = p2;
        t->rec->s10->v = (p2 > 1) + 0x2000002a;
        r = 1;
    }
    return r;
}
//@ f_054c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht ein totes Gruppenmitglied (f_039070(d_1c0004)), erweckt es durch Löschen des Todesflags
 *   (f_042480(p, 0)) und Heilen von 7 Lebenspunkten (f_044890(p, 7)) wieder zum Leben und trägt den Helden in
 *   t->rec ein.
 * - Eingaben und Rückgabe: Die Funktion nimmt t entgegen und gibt als int den Wert 1 zurück, wenn ein toter Held
 *   wiederbelebt wurde, sonst 0.
 * - Wichtige Variablen: Bei erfolgreicher Wiederbelebung wird das Bildschirm-Update-Flag d_1c2198 = 1 gesetzt.
 === Ende Beschreibung === */
int f_054c50(Deity *t)
{
    int p = f_039070(d_1c0004);
    int r = 0;
    if (p) { f_042480(p, 0); f_044890(p, 7); t->rec->s4->v = p; *(volatile short *)&d_1c2198 = 1; r = 1; }
    return r;
}
//@ f_054ca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert außerhalb eines geöffneten Tempels direkt den gespeicherten Gunstwert der Gottheit p1
 *   in der Spielstanddatei um den Betrag p2 (etwa nach einer göttergefälligen Tat oder einem Frevel in der
 *   Spielwelt).
 * - Eingaben und Rückgabe: Die Funktion erhält die Gottheits-ID p1 (int) sowie die Gunständerung p2 (int) und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sie legt kurzzeitig ein Deity-Objekt für p1 auf dem Heap an, lädt dessen Stand aus
 *   0x220004, addiert p2 auf t->st.c, speichert den Stand über f_11ea90 zurück und gibt das Objekt sofort wieder
 *   frei.
 === Ende Beschreibung === */
int f_145300(int p1, int p2, int p3);
void f_054ca0(int p1, int p2)
{
    Deity *t;
    int raw = (int)operator new(0x14, mark(d_1a1648, 0x3a6));
    if (raw) {
        int tt = raw;
        Rec *r;
        ((Deity *)tt)->state = 0;
        ((Deity *)tt)->rec = 0;
        ((Deity *)tt)->id = (short)p1;
        f_145300((int)&((Deity *)tt)->st, 0, 10);
        Deity *q = (Deity *)tt;
        r = (Rec *)operator new(0x3c, mark(d_1a1648, 0x96));
        r = r ? (Rec *)f_125400((int)r, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498) : r;
        q->rec = r;
        d_1c21b4 = 0;
        q->state = 0x1c00000c;
        {
            char *tp_ = (char *)operator new(1, mark(d_1a1648, 0x9a));
            f_11ea00((int)tp_, 0x220004, q->id, (int)&q->st, 10);
            operator delete(tp_);
        }
        t = (Deity *)tt;
    } else {
        t = (Deity *)raw;
    }
    *(volatile int *)&t->st.c += p2;
    Deity *saved = t;
    {
        char *tp2_ = (char *)operator new(1, mark(d_1a1648, 0xb3));
        f_11ea90((int)tp2_, 0x220004, t->id, (int)&t->st, 10);
        operator delete(tp2_);
    }
    DELREC(t->rec);
    operator delete(saved);
}
