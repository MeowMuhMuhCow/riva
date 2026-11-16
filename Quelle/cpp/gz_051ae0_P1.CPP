/* === Beschreibung (Katalog) ===
 * Einheit gz_051ae0 (051ae0 - 052400)
 *
 * Überblick
 * Diese Einheit implementiert die interaktive Textmodus-/Debug-Kommandozeile (struct Zeile) mit einem Ringpuffer
 * für die letzten sechs eingegebenen Befehle (hist[6][21]), Cursorbewegung, Einfüge-/Löschfunktionen und
 * Callback-Ausführung bei Druck auf Enter sowie vier kleine Hilfsfunktionen zum Umschalten von Debug-Schaltern.
 === Ende Beschreibung === */
// P3 11/15 gleich (suche.py 26.10.2026, Basis gz_051ae0_P1.CPP)
// gz_051ae0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x051AE0-0x052400
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_145400(int p1);                                   // reg eax stapel 0
int f_14d1c1(int p1, int p2);                           // reg eax edx stapel 0
void mem_145300(void *p, int c, unsigned n);
#pragma aux mem_145300 "f_145300" parm [eax] [edx] [ebx] modify exact [eax edx ebx];
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a01b4;                    // 0x1A01B4
extern int d_1bc948;                    // 0x1BC948
#define __INLINE_FUNCTIONS__ 1
#include <bios.h>
int f_14d27d(const char *fmt, ...);
extern const char d_1b66cc[];
struct Clk { int f_0d4880(); };
extern Clk d_1c2e68;
extern const char d_1b66d3[], d_1b66e1[], d_1b66f0[], d_1b66fc[];
void f_053a30(int, int, const char *);
#pragma aux f_053a30 parm caller [];
void f_14572e(char *, const char *, int);
#pragma aux f_14572e parm caller [];
struct Zeile {
    unsigned short head, cur;
    char hist[6][21];
    short x, y, pos;
    int (*cb)(char *);
    char prompt[10];
    char fmt[10];
    char buf[22];
    Zeile(short px, short py, char *s, int (*f)(char *));
    Zeile *f_051af0();
    void f_051b30(char *s);
    char *f_051b90();
    char *f_051c10();
    void f_051d30();
    int f_051e80(short key, short asc);
    void f_052300();
};
#define DRAW() f_14d1c1(y, x); f_14d27d(prompt); f_14d27d(fmt, buf); f_14d1c1(y, (short)(x + strlen(prompt) + pos));
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_051ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Positioniert den Textcursor der Debug-Konsole auf die Spalte a und Zeile b.
 * - Eingaben und Rückgabe: Die Funktion erhält die Spalte a (short) und die Zeile b (short) und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Sie ruft f_14d1c1(b, a) mit vertauschter Reihenfolge (Zeile, Spalte) auf.
 === Ende Beschreibung === */
void f_051ae0(short a, short b)
{
    f_14d1c1((int)b, (int)a);
}
//@ f_051af0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert den Befehlsverlauf (History-Ringpuffer mit 6 Einträgen zu je 21 Zeichen) eines
 *   Zeile-Objekts mit Nullen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this entgegen und gibt this zurück.
 * - Wichtige Variablen: Die Ringpuffer-Indizes cur und head werden auf 0 gesetzt und die 126 (0x7e) Bytes von
 *   hist gelöscht.
 === Ende Beschreibung === */
Zeile *Zeile::f_051af0()
{
    cur = 0;
    head = cur;
    mem_145300(hist, 0, 0x7e);
    return this;
}
//@ f_051b20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Destruktor bzw. Platzhalter für den Befehlsverlauf der Debug-Eingabezeile.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter (void) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Variablen verändert.
 === Ende Beschreibung === */
void f_051b20(void)
{
}
//@ f_051b30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert eine neu eingegebene Befehlszeile s im 6-stufigen History-Ringpuffer und rückt den
 *   Schreibindex head zyklisch um eine Position weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält this und den Befehlsstring s (char *) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Der String wird nach hist[head] kopiert und cur = head = (head + 1) % 6 gesetzt.
 === Ende Beschreibung === */
void Zeile::f_051b30(char *s)
{
    unsigned h = 0;
    h = head;
    strcpy(hist[h], s);
    head = (head + 1) % 6;
    cur = head;
}
//@ f_051b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blättert im Befehlsverlauf der Debug-Eingabezeile um einen Eintrag nach vorn (Pfeil-ab) und
 *   liefert den gespeicherten Befehl oder 0 am Ende der History zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt this entgegen und gibt einen Zeiger char * auf den History-Eintrag
 *   oder 0 zurück.
 * - Wichtige Variablen: Berechnet wird n = (cur + 1) % 6; ist dort ein gültiger Eintrag vorhanden, wird cur = n
 *   gesetzt und hist[cur] zurückgegeben.
 === Ende Beschreibung === */
char *Zeile::f_051b90()
{
    struct Access {
        static int first(Zeile *z, int i) { return (signed char)z->hist[i][0]; }
    };
    unsigned short n = (cur + 1) % 6;
    char *result;
    if (n == head || head == cur || Access::first(this, n) == 0) {
        unsigned short h = head;
        result = 0;
        cur = h;
    } else {
        cur = n;
        result = hist[(unsigned short)cur];
    }
    return result;
}
//@ f_051c10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blättert im Befehlsverlauf der Debug-Eingabezeile um einen Eintrag zurück zum vorherigen
 *   Befehl (Pfeil-auf).
 * - Eingaben und Rückgabe: Die Funktion nimmt this entgegen und gibt einen Zeiger char * auf den vorherigen
 *   History-Eintrag oder 0 zurück.
 * - Wichtige Variablen: Berechnet wird n = (cur + 5) % 6; sofern dieser Slot belegt ist und nicht auf head
 *   zeigt, wird cur = n gesetzt und hist[cur] geliefert.
 === Ende Beschreibung === */
char *Zeile::f_051c10()
{
    int n = (cur + 5) % 6;
    if ((unsigned short)n == head || (signed char)hist[(unsigned short)n][0] == 0) {
        return 0;
    }
    cur = n;
    return hist[cur];
}
//@ f_051c80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Destruktor für das Zeile-Eingabeobjekt.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Daten verändert.
 === Ende Beschreibung === */
void f_051c80()
{
}
static Zeile *id963(Zeile *p) { return p; }
#pragma aux id963 parm [eax] value [eax] modify exact [eax];
static unsigned keep963(unsigned n) { return n; }
#pragma aux keep963 parm [ebx] value [ebx] modify exact [ebx];
//@ f_051c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein vollständiges Zeile-Eingabezeilenobjekt an den Bildschirmkoordinaten (px, py)
 *   mit Eingabeaufforderung s, Befehls-Callback f und geleertem History- und Eingabepuffer.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger self, die Position px und py, den Prompt-String
 *   s sowie den Callback-Zeiger f und gibt self zurück.
 * - Wichtige Variablen: Initialisiert werden hist, x, y, cb, buf, prompt sowie das Ausgabeformat fmt (%-21s).
 === Ende Beschreibung === */
Zeile *f_051c90(Zeile *self, short px, short py, char *s, int (*f)(char *))
{
    unsigned n = keep963(126);
    self->cur = 0;
    self->head = self->cur;
    memset(self->hist, 0, n);
    Zeile *t = id963(self);
    t->x = px;
    self->y = py;
    self->cb = f;
    memset(self->buf, 0, 0x15);
    strcpy(self->prompt, s);
    f_14572e(self->fmt, d_1b66cc, 0x15);
    return self;
}
//@ f_051d30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Debug-Eingabezeile auf dem Bildschirm aus und liest in einer Schleife
 *   BIOS-Tastatureingaben ein, bis die Tastenverarbeitung f_051e80 das Beenden der Eingabe signalisiert.
 * - Eingaben und Rückgabe: Die Funktion nimmt this entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Während auf einen Tastendruck (_bios_keybrd) gewartet wird, hält d_1c2e68.f_0d4880() den
 *   Systemtimer am Laufen.
 === Ende Beschreibung === */
void Zeile::f_051d30()
{
    struct Keys { short k, pad1, ks, pad2; };
    Keys keys;
    Keys *kp = &keys;
    int r;
    short xx = x;
    short yy = y;
    int iyy = yy;
    f_14d1c1(iyy, xx);
    f_14d27d(prompt);
    f_14d27d(fmt, buf);
    unsigned len = strlen(prompt);
    short py = y;
    int iy = py;
    f_14d1c1(iy, (short)(x + len + pos));
    do {
        keys.ks = 0;
        keys.k = 0;
        while (keys.k == 0) {
            d_1c2e68.f_0d4880();
            if (_bios_keybrd(_KEYBRD_READY)) {
                short raw = _bios_keybrd(_KEYBRD_READ);
                keys.k = raw;
                raw &= 0xff;
                keys.ks = raw;
            }
        }
        r = f_051e80(keys.k, keys.ks);
    } while (r == 1);
}
//@ f_051e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wartet auf einen Tastendruck im BIOS-Tastaturpuffer und liefert sowohl den vollen
 *   16-Bit-Keycode (*p2) als auch den 8-Bit-ASCII-Code (*p3) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält self sowie die beiden Ausgabezeiger p2 und p3 (short *) und gibt
 *   als int stets 1 zurück.
 * - Wichtige Variablen: In der Warteschleife wird d_1c2e68.f_0d4880() aufgerufen, bis
 *   _bios_keybrd(_KEYBRD_READY) eine Taste meldet.
 === Ende Beschreibung === */
int f_051e20(int self, short *p2, short *p3)
{
    unsigned short k;
    *p3 = 0;
    *p2 = *p3;
    while (*p2 == 0) {
        d_1c2e68.f_0d4880();
        if (_bios_keybrd(_KEYBRD_READY)) {
            k = _bios_keybrd(_KEYBRD_READ);
            *p2 = k;
            *p3 = k & 0xff;
        }
    }
    return 1;
}
//@ f_051e80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet einen einzelnen Tastendruck in der Debug-Eingabezeile: Pfeil-auf/ab blättern durch
 *   die History, Pfeil-links/rechts, Pos1 (0x4700) und Ende (0x4f00) bewegen den Cursor, Entf (0x5300) und
 *   Rücktaste (0x0e08) löschen Zeichen, Escape (0x011b) leert die Zeile, druckbare Zeichen werden in
 *   Großbuchstaben umgewandelt eingefügt, und Enter (0x1c0d) nimmt den Befehl in die History auf und führt den
 *   Callback cb(buf) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält this, den 16-Bit-Tastencode key sowie den ASCII-Code asc und gibt
 *   als int zurück, ob die Eingabeschleife weiterlaufen soll (1, solange cb 0 liefert) oder beendet wird (0).
 * - Wichtige Variablen: Der Eingabepuffer buf fasst bis zu 21 Zeichen, pos gibt die aktuelle Cursorposition an,
 *   und nach jeder Änderung wird die Zeile über f_14d27d neu ausgegeben.
 === Ende Beschreibung === */
int Zeile::f_051e80(short key, short asc)
{
    struct Verlauf {
        static int anfang(Zeile *z,int n) { return (signed char)z->hist[n][0]; }
        static char *vor(Zeile *z) {
            int m; unsigned short n=(z->cur+5)%6;
            if (n==z->head || anfang(z,m=n)==0) return 0;
            z->cur=n; return z->hist[(unsigned short)m];
        }
        static char *nach(Zeile *z) {
            { int *gp1437=&d_1a01b4; int keep1437=*gp1437; *gp1437=keep1437; } /* Haelt den Sortierknoten fuer d_1a01b4 */ { int *gp1437=&d_1bc948; int keep1437=*gp1437; *gp1437=keep1437; } /* Haelt den Sortierknoten fuer d_1bc948 */ int m; unsigned short n=(z->cur+1)%6;
            if (n==z->head || z->head==z->cur || anfang(z,m=n)==0) { z->cur=z->head; return 0; }
            z->cur=n; return z->hist[(unsigned short)m];
        }
        static void merke(Zeile *z,char *s) {
            strcpy(z->hist[z->head],s);
            z->head=(z->head+1)%6;
            z->cur=z->head;
        }
    };
    char ac;
    int r=0;
    char *s;
    short len; short i;
    switch ((unsigned short)key) {
    case 0x4800:
        s=Verlauf::vor(this);
        if (s) { strcpy(buf,s); pos=strlen(buf); }
        break;
    case 0x5000:
        s=Verlauf::nach(this);
        if (s) { strcpy(buf,s); pos=strlen(buf); }
        else { pos=0; buf[0]=0; }
        break;
    case 0x4b00:
        { int *gp1437=&d_1a01b4; int keep1437=*gp1437; *gp1437=keep1437; } /* Haelt den Sortierknoten fuer d_1a01b4 */ 
        if (pos>0) --pos;
        break;
    case 0x4d00:
        if ((signed char)buf[pos]!=0) ++pos;
        break;
    case 0x11b:
        buf[0]=0; pos=0; cur=head;
        break;
    case 0x1c0d:
        if ((signed char)buf[0]!=0) {
            Verlauf::merke(this,buf);
            int v=cb(buf);
            pos=0; r=v; buf[0]=0;
        }
        break;
    case 0x4700: pos=0; break;
    case 0x4f00: pos=strlen(buf); break;
    case 0x5300:
        for (i=pos; (signed char)buf[i]!=0; ++i) buf[i]=buf[i+1];
        break;
    case 0xe08:
        if (pos>0) {
            memmove(buf+(pos-1),buf+pos,strlen((char *)((int)pos+(int)buf))+1);
            --pos;
        }
        break;
    default:
        int c=*(int*)&asc; c=*(int*)&asc; c=(int)asc; c=*(int*)&asc; c=*(int*)&asc; // Haelt c frueh in EBX
        len=strlen(buf);
        if ((short)c) {
            asc=(unsigned char)f_145400((unsigned char)asc);
            if (len<=20) {
                memmove(buf+(pos+1),buf+pos,strlen(buf+pos)+1);
                s=(char *)this+pos++; ac=(char)asc; *(char *)&asc=ac; s[160]=ac;
            }
        }
        break;
    }
    { short a=x; short b=y; y=b; f_14d1c1((int)b,(int)a); } // Haelt b fuer den Aufruf in Register
    f_14d27d(prompt);
    f_14d27d(fmt,buf);
    short px=x+strlen(prompt);
    px+=*(volatile short *)&pos;
    short py=y;
    int ix942=px;
    int iy942=py;
    int rr=(*&r);
    f_14d1c1(iy942,ix942);
    return rr==0;
}
//@ f_052300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Eingabeaufforderung prompt und den aktuellen Pufferinhalt buf der
 *   Debug-Eingabezeile neu und setzt den Textcursor an die Position pos.
 * - Eingaben und Rückgabe: Die Funktion nimmt this entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ausgegeben werden prompt und buf an den Koordinaten (x, y) des Zeile-Objekts.
 === Ende Beschreibung === */
void Zeile::f_052300()
{
    short xx = x;
    short yy = y;
    f_14d1c1(yy, xx);
    f_14d27d(prompt);
    f_14d27d(fmt, buf);
    short py;
    f_14d1c1(py = y, (short)(x + strlen(prompt) + pos));
}
//@ f_052380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das globale Debug-Flag d_1a01b4 ein (1) und gibt die zugehörige Bestätigungsmeldung
 *   (d_1b66d3) auf dem Debug-Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beschrieben wird d_1a01b4 = 1.
 === Ende Beschreibung === */
void f_052380()
{
    d_1a01b4 = 1;
    f_053a30(10, 0x12, d_1b66d3);
}
//@ f_0523a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das globale Debug-Flag d_1a01b4 aus (0) und gibt die zugehörige Bestätigungsmeldung
 *   (d_1b66e1) auf dem Debug-Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beschrieben wird d_1a01b4 = 0.
 === Ende Beschreibung === */
void f_0523a0()
{
    d_1a01b4 = 0;
    f_053a30(10, 0x12, d_1b66e1);
}
//@ f_0523c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das globale Debug-Flag d_1bc948 ein (1) und gibt die Meldung d_1b66f0 auf dem
 *   Debug-Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beschrieben wird d_1bc948 = 1.
 === Ende Beschreibung === */
void f_0523c0()
{
    d_1bc948 = 1;
    f_053a30(10, 0x12, d_1b66f0);
}
//@ f_0523e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das globale Debug-Flag d_1bc948 aus (0) und gibt die Meldung d_1b66fc auf dem
 *   Debug-Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beschrieben wird d_1bc948 = 0.
 === Ende Beschreibung === */
void f_0523e0()
{
    d_1bc948 = 0;
    f_053a30(10, 0x12, d_1b66fc);
}
