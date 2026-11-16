/* === Beschreibung (Katalog) ===
 * Einheit diary2 (0x058210 - 0x0595f0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil der Tagebuchverwaltung (diary2.cpp) und entspricht im Aufbau direkt
 * Overlays/OVL104.CPP (class Diary) aus *Sternenschweif*. Sie kümmert sich um das Anhängen neuer Einträge, das
 * automatische Markieren bekannter Stichwörter im Text, das Laden, Umbrechen und Zeichnen einer Tagebuchseite
 * sowie das Formatieren von Orts- und Datumszeilen.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 3/9 gleich (suche.py 30.10.2026, Basis diary2_P1.CPP)
// diary2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x058210-0x0595F0
#include <string.h>
#include <stdio.h>
struct Dia { unsigned short n0; short n2; char *p4; char *p8; int pc; signed char c10; unsigned char c11; signed char a12[0x15]; signed char c27; };
struct Rec { unsigned char c0; unsigned char c1; unsigned char c2; char name[20]; };
struct Obj2 { char b[0x10]; int *p10; short *p14; char r[0x3c - 0x18]; };
struct O1 { char b[164]; void f_145a10(int a, void *p); void *f_145b40(); };
struct Gfx {
    void f_05e2a0(short *a, short *b, short *c, short *d);
    void f_05e2d0(short a, short b, short c, short d);
    void f_05e320(int a, int b);
    void f_05e1d0(short a, short b);
    short f_05e1f0();
    int f_05e200();
    void f_0e93f0(const char *s, int c);
    void f_0e9550(int c);
    short f_0e9590(int c);
    int f_0e9610(const char *s);
    void f_0e9300(const char *a, const char *b);
    void f_0e9650(const char *s, int n);
    int f_0e9680(const char *s);
};

struct MM { void *f_0bdd50(int sz); void f_0bdde0(); };
struct Cls { int f_045e50(unsigned char c); };
struct In { signed char f_126430(); signed char f_126450(); signed char f_126460(); };
struct Zs { void *f_05dec0(); void f_05ded0(void *p); };
struct Qs { void f_0daa90(short s); void f_0daaf0(short s); int f_0daba0(void *p); };

extern Gfx d_1c38b0;
extern RivaFileManager d_1c2098;
extern MM d_1c11b8;
extern Cls d_1c3078;
extern In d_1c2c44;
extern Zs d_1c3068;
extern Qs *d_1bfdb8;
extern const char d_1a1754[];
extern const char d_1b6e50[], d_1b6e54[], d_1b6e58[], d_1b6e5e[];
extern signed char d_1a16c8[];
extern const char d_1a16bc[];
extern const char *d_1a965c;
extern char d_1c21b4[];
extern int d_1c349c, d_1c3870, d_1c3498;
extern int d_1c2a80;
extern unsigned *d_1a34e0;

void f_125400(Obj2 *o, int *a, int *b, int *c);
void f_1254a0(Obj2 *o, int fl);
void f_1459b0(O1 *o);
void f_1459d0(O1 *o);
void f_145300(void *p, int v, int n);
int f_14d6c4(const char *a, const char *b, unsigned n);
void *f_014540(int sz, const char *file, int line);
int f_014a60();
int f_0d3860();
void f_0d2710();
void f_0d26e0();
void f_09a120(void *p, int n);
void f_0585e0(Dia *p);
void f_058850(Dia *p, Rec *tab, char *out, char *word, short *pos);
void f_058960(Dia *p, unsigned short p2);
int f_0591c0(Dia *p, int p2);
void f_0592f0(Dia *p, const char *s);
void f_059330(Dia *p, const char *s);
int f_059410(Dia *p, char *s);

//@ f_058210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hängt einen neuen Text s als Eintrag an das Tagebuch an (Schwesterfunktion Diary::append in
 *   *Sternenschweif* OVL104.CPP). Hat sich der Kalendertag (p->c27) seit dem letzten Eintrag geändert oder würde
 *   die letzte Seite zusammen mit dem neuen Eintrag 20 oder mehr Zeilen umfassen (f_059410), wird eine neue
 *   Seite mit Orts- und Datumskopf angelegt; andernfalls wird die letzte Seite geladen und fortgesetzt, bevor
 *   alle bekannten Stichwörter im neuen Text über f_0585e0 mit Suchmarken versehen werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt, den anzuhängenden Text s
 *   sowie das Kennzeichen u (!= 0 für einen vom Spieler selbst verfassten Eintrag mit Steuerzeichen d_1a16c8[2],
 *   0 für einen automatischen Spieleintrag mit d_1a16c8[1]). Sie gibt die neue Länge des Seitentextes in p->p4
 *   zuzüglich 1 als short zurück (oder 0, wenn s == 0 ist).
 * - Wichtige Variablen: Der Puffer p->p4 (2000 Bytes) nimmt den fertig aufgebauten Seitentext auf, p->n0 zählt
 *   die Gesamtseitenzahl, p->c27 merkt den Kalendertag der letzten Seite, und d_1a16c8[0..3] enthält die
 *   Steuerzeichen für Seitenkopf, Spieleintrag, Spielereintrag und Eintragsende.
 === Ende Beschreibung === */
short f_058210(Dia *p, char *s, short u)
{
    void f_059330(void *, const char *);
    short f_0e9610(Gfx *, const char *);
    signed char f_126430(In *);
#pragma aux f_126430 modify [eax edx ebx];
#pragma function(memset)
#pragma aux memset parm [eax] [edx] [ebx] modify [eax edx ebx ecx];
    int f_14572e(char *, const char *, ...);
#pragma aux f_14572e parm caller [] modify [eax ecx edx];
    short a, c, d, b;
    short ret = 0;
    short old_lines;
    char *old_text;
    char *buf;
    int need_header;

    d_1c38b0.f_05e2a0(&a, &b, &c, &d);
    d_1c38b0.f_05e2d0(0x11, 0xcc, 0x19, -1);
    if (s) {
        int need_header;
        char *old_text;
        void *tag = mark(d_1a1754, 0x48);
        // Drei codelose DWORD-Picks vor dem Header-Nullstore
        int zero = (d_1c349c ^ d_1c349c) ^ (d_1c3870 ^ d_1c3870) ^ (d_1c3498 ^ d_1c3498);
        old_text = (char *)zero; need_header = 0;
        char *buf = new (tag) char[100];
        ret = f_0e9610(&d_1c38b0, s);
        memset(p->p4, 0, 2000);
        old_lines = 0;
        if (f_126430(&d_1c2c44) != p->c27) {
            need_header = 1;
            ret++;
        }
        if (p->n0 > 1) {
            f_0591c0(p, (unsigned short)(p->n0 - 1));
            old_lines = f_059410(p, p->p4);
        }
        { int rt = d_1c349c; d_1c349c = rt; } // Konfliktsortierung wie im Original
        if (old_lines && old_lines + ret < 20) {
            old_text = new (mark(d_1a1754, 0x6b)) char[2000];
            memcpy(old_text, p->p4, strlen(p->p4));
        } else {
            p->n2 = p->n0++;
            need_header = 1;
        }
        f_145300(p->p4, 0, 2000);
        if (need_header) {
            p->c27 = d_1c2c44.f_126430();
            f_14572e(buf, d_1b6e50, d_1a16c8[0]);
            strcat(p->p4, buf);
            {
                Obj2 o;
                // Sieben berechnete Aliasnamen fuer die Stapelsortierung
                (void)((unsigned char *)&o)[1];
                (void)((unsigned char *)&o)[2];
                (void)((unsigned char *)&o)[3];
                (void)((unsigned char *)&o)[4];
                (void)((unsigned char *)&o)[5];
                (void)((unsigned char *)&o)[6];
                (void)((unsigned char *)&o)[7];
                f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
                d_1c38b0.f_0e93f0(buf, 0x20000011);
                f_1254a0(&o, 0);
            }
            strcat(p->p4, buf);
            f_059330((void *)p, buf);
            strcat(p->p4, buf);
        }
        int symbol = (u != (short)0);
        symbol++; f_14572e(buf, d_1b6e54, d_1a16c8[u ? 2 : 1]);
        strcat(p->p4, buf);
        d_1c38b0.f_0e9300(p->p4, s);
        f_14572e(buf, d_1b6e58, d_1a16c8[3]);
        strcat(p->p4, buf);
        f_0585e0(p);
        if (old_text) {
            if (need_header) {
                old_text[strlen(old_text) - 2] = d_1a16c8[3];
                old_text[strlen(old_text) - 1] = 0;
            }
            strcat(old_text, p->p4);
            memcpy(p->p4, old_text, strlen(old_text));
            delete old_text;
        }
        ret = strlen(p->p4);
        delete buf;
        ret++;
    }
    d_1c38b0.f_05e2d0(a, b, c, d);
    return ret;
}




int Open493(RivaFileManager *,int,int);
#pragma aux Open493 "f_1448b0" parm [eax] [edx] [ebx] value [eax] modify [eax ebx edx];
int Size493(RivaFileManager *);
#pragma aux Size493 "f_144a00" parm [eax] value [eax] modify [eax];
void Close493(RivaFileManager *);
#pragma aux Close493 "f_1449a0" parm [eax] modify [eax];
int Read493(RivaFileManager *,void *,int);
#pragma aux Read493 "f_144920" parm [eax] [edx] [ebx] value [eax] modify [eax ebx edx];
int Write493(RivaFileManager *,void *,int);
#pragma aux Write493 "f_144960" parm [eax] [edx] [ebx] value [eax] modify [eax ebx edx];
void *Alloc493(MM *,int,const char *,int);
#pragma aux Alloc493 "f_0bdd50";
void Free493(MM *,void *,const char *,int);
#pragma aux Free493 "f_0bdde0";
//@ f_0585e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht den neu aufgebauten Seitentext in p->p4 Wort für Wort und markiert alle Wörter, die
 *   in der Stichwortdatei 0x40080002 vorkommen, über f_058850 mit ihrer jeweiligen 2-Byte-Suchmarke
 *   (Schwesterfunktion Diary::mark_names in *Sternenschweif*). Anschließend wird die Stichwortdatei mit den neu
 *   gesetzten "gefunden"-Merkern (c1 = 1) zurückgeschrieben, damit die Begriffe im Suchmenü des Tagebuchs
 *   erscheinen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Der Puffer p->p8 (2000 Bytes) dient als Zwischenkopie des unmarkierten Seitentextes, tab
 *   enthält die aus der Datei 0x40080002 geladene Tabelle von 23-Byte-Stichwortsätzen (Rec), und buf[64] sammelt
 *   jeweils ein Wort aus zusammenhängenden Wortzeichen (d_1c3078.f_045e50).
 === Ende Beschreibung === */
void f_0585e0(Dia *p)
{
    int sz;
    Rec *tab;
    char buf[64];
    short end;
    short idx;
    short len;
    short pos;
    short k;
    signed char ch;

    pos = 0;
    (void)buf[1]; // Codefreie Byte-Sicht auf buf fuer die Stapelfolge
    len = strlen(p->p4);
    end = len;
    idx = 0;
    k = 0;
    ch = p->p4[0];
    f_145300(buf, 0, 64);
    Open493(&d_1c2098,0x40080002,0x200);
    sz = Size493(&d_1c2098);
    tab = (Rec *)Alloc493(&d_1c11b8,sz,d_1a1754,0xca);
    Read493(&d_1c2098,tab,sz);
    Close493(&d_1c2098);
    f_145300(p->p8, 0, 2000);
    strcpy(p->p8, p->p4);
    f_145300(p->p4, 0, 2000);
    while (idx <= end) {
        if (ch == d_1a16c8[0]) {
            do {
                p->p4[pos++] = ch;
                ch = p->p8[++idx];
            } while (ch != d_1a16c8[1] && ch != d_1a16c8[2]);
            p->p4[pos++] = ch;
            ch = p->p8[++idx];
        }
        if (d_1c3078.f_045e50((unsigned char)ch) == 1) {
            buf[k++] = ch;
            idx++;
        } else if (buf[0]) {
            f_058850(p, tab, p->p4, buf, &pos);
            k = 0;
        } else {
            p->p4[pos++] = ch;
            idx++;
        }
        ch = p->p8[idx];
        { short z = end; end = z; } // Haelt den Nutzwert von end wie im Original
    }
    if (buf[0])
        f_058850(p, tab, p->p4, buf, &pos);
    Open493(&d_1c2098,0x40080002,0x201);
    Write493(&d_1c2098,tab,sz);
    Close493(&d_1c2098);
    Free493(&d_1c11b8,tab,d_1a1754,0xfd);
}

//@ f_058850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vergleicht ein einzelnes aus dem Tagebuchtext gelesenes Wort word mit allen Einträgen der
 *   Stichworttabelle tab (Schwesterfunktion Diary::mark_word in *Sternenschweif*). Beim ersten passenden Begriff
 *   schreibt die Funktion dessen Kategoriemarke (r->c2) und Kennung (r->c0) vor das Wort in den Ausgabetext out,
 *   markiert den Begriff in der Tabelle als im Tagebuch gefunden (r->c1 = 1) und hängt danach das Wort selbst
 *   an.
 * - Eingaben und Rückgabe: Die Funktion erhält das Tagebuch-Objekt p (ungenutzt), die Stichworttabelle tab, den
 *   Zieltext out, den 64-Byte-Wortpuffer word sowie den Zeiger pos auf die aktuelle Schreibposition in out. Sie
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Jeder Tabelleneintrag r (Rec, 23 Bytes) besteht aus der Kennung c0 (0xff am
 *   Tabellenende), dem Gefunden-Merker c1, der Kategoriemarke c2 und dem bis zu 20 Zeichen langen Namen name.
 === Ende Beschreibung === */
void f_058850(Dia *p, Rec *tab, char *out, char *word, short *pos)
{
    char *nm;
    int found;
    short i;
    short j;
    short len;
    Rec *r;

    (void)&nm; // Haelt nm auf dem Stapel
    { char *zo = out; out = zo; zo = out; out = zo; zo = out; out = zo; } // Haelt out vor den uebrigen Registern
    { Rec *zt0 = tab; tab = zt0; zt0 = tab; tab = zt0; } // Haelt tab vor len
    i = 0;
    found = 0;
    while (1) {
        r = &tab[i];
        {  char *zo = out; out = zo; short zi = i; i = zi; } // Haelt die Stapel- und Registerfolge
        { Rec *zr = r; r = zr; } // Haelt den Nutzwert von r
        unsigned first = r->c0;
        { unsigned z = first; first = z; z = first; first = z; } // Haelt EAX in Gebrauch
        if (first == 0xff || found != 0)
            break;
        nm = r->name;
        len = strlen(nm);
        if (len > 0 && f_14d6c4(nm, word, len) == 0) {
            out[(*pos)++] = r->c2;
            out[(*pos)++] = r->c0;
            found = 1;
            r->c1 = found;
        }
        i++;
    }
    len = strlen(word);
    j = 0;
    if (len > (short)0) {
        do {
            { short zj = j; j = zj; } // Haelt den Nutzwert von j
            char *q = (char *)(j + (int)word);
            char *d = (char *)((*pos)++ + (int)out);
            char c = *q;
            *d = c;
            j++;
        } while (j < len);
    }
    f_145300(word, 0, 0x40);
}

//@ f_058960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die Tagebuchseite p2 über f_0591c0 und gibt sie formatiert im Tagebuchfenster aus: den
 *   Seitenkopf in Farbe 0xfd mit darunterliegender Trennlinie (0x8030056, Farbe 0xbb) und die Einträge in Farbe
 *   0xfe (Schwesterfunktion Diary::show_page in *Sternenschweif*). Ist eine Suche aktiv (p->c10 != 0), werden
 *   entweder eigene Einträge (p->c10 == -1) oder Treffer der gesuchten Marke p->c10/p->c11 mit den Steuercodes
 *   0xf1/0xf0 farbig hervorgehoben, während sonstige Kategoriemarken übersprungen werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt und die 0-basierte
 *   Seitennummer p2. Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Suchfelder p->c10 (Marke), p->c11 (Kennung) und p->a12 (gesuchter Name) steuern die
 *   Hervorhebung; ein aus *Sternenschweif* übernommener Originalfehler führt dazu, dass hier nur Kategoriemarken
 *   im Bereich d_1a16c8[4]..d_1a16c8[8] übersprungen werden, während f_059410 den Bereich
 *   d_1a16c8[4]..d_1a16c8[9] prüft.
 === Ende Beschreibung === */
void f_058960(Dia *p, unsigned short p2)
{
    void f_059330(void *, const char *);
    void f_0e9650(Gfx *, const char *);
    int f_14572e(char *, const char *, ...);
#pragma aux f_14572e parm caller [] modify [eax ecx edx];
    short d, a, b, c;
    short pos, idx, end, len, k;
    int flag;
    signed char ch;
    Obj2 o;
    // Codefreie WORD-Sichten steuern die Stapelsortierung
    (void)((short *)&o)[1];
    (void)((short *)&o)[2];
    (void)((short *)&o)[3];
    (void)((short *)&o)[4];
    (void)((short *)&o)[5];
    (void)((short *)&o)[6];


    d_1c38b0.f_05e2a0(&a, &b, &c, &d);
    if (f_0591c0(p, (unsigned short)p2)) {
        len = strlen(p->p4);
        end = len;
        pos = 0;
        d_1c38b0.f_05e2d0(0x19, 0xce, 0x1e, -1);
        idx = 0;
        f_145300(p->p8, 0, 2000);
        flag = 0;
        while (idx < end) {
            ch = p->p4[idx++];
            { signed char zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; zc = ch; ch = zc; } // Haelt den Nutzwert von ch
            { int zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; zf = flag; flag = zf; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; len = pos; pos = len; } // Haelt den Nutzwert von flag und pos
            if (ch == d_1a16c8[0]) {
                if (p->p8[0]) {
                    p->p8[pos] = 0;
                    d_1c38b0.f_05e320(0xfe, -1);
                    pos = 0;
                    f_0e9650(&d_1c38b0, p->p8);
                }
                while (ch != d_1a16c8[1] && ch != d_1a16c8[2]) {
                    ch = (ch & 0) ? 0 : ch; // Haelt die Registerwahl in der Kopfschleife
                    char *text_base = p->p4;
                    ch = text_base[idx++];
                    p->p8[pos++] = ch;
                }
                p->p8[pos - 1] = p->p8[pos] = 0;
                d_1c38b0.f_05e320(0xfd, -1);
                f_0e9650(&d_1c38b0, p->p8);
                d_1c38b0.f_05e320(0xbb, -1);
                d_1c38b0.f_05e1d0(d_1c38b0.f_05e1f0(), d_1c38b0.f_05e200() - 2);
                d_1c38b0.f_0e9550(0x8030056);
                d_1c38b0.f_05e1d0(d_1c38b0.f_05e1f0(), d_1c38b0.f_05e200() + 2);
                pos = 0;
                idx--;
            } else if (p->c10 == -1 && ch == d_1a16c8[2]) {
                flag = 1;
                p->p8[pos++] = '\xf1';
            } else if (ch == d_1a16c8[3] && flag) {
                p->p8[pos++] = '\xf0';
                flag = 0;
            } else if (p->c10 && ch == p->c10) {
                ch = p->p4[idx++];
                if (ch == p->c11) {
                    p->p8[pos++] = '\xf1';
                    ch = p->p4[idx++];
                    k = 0;
                    while (ch && ch == p->a12[k++]) {
                        p->p8[pos++] = ch;
                        ch = p->p4[idx++];
                    }
                    p->p8[pos++] = '\xf0';
                    idx--;
                }
            } else if (ch >= d_1a16c8[4] && ch <= d_1a16c8[8]) {
                idx++;
            } else if (ch != d_1a16c8[1] && ch != d_1a16c8[2] && ch != d_1a16c8[3]) {
                p->p8[pos++] = ch;
            }
        }
        p->p8[pos] = 0;
        d_1c38b0.f_05e320(0xfe, -1);
        f_0e9650(&d_1c38b0, p->p8);
    } else {
        d_1c38b0.f_05e320(0xfd, -1);
        d_1c38b0.f_05e2d0(0x19, 0xce, 0x1e, -1);
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        d_1c38b0.f_0e93f0(d_1c21b4, 0x20000011);
        f_1254a0(&o, 0);
        f_14572e(p->p4, d_1b6e5e, d_1c21b4);
        f_059330((void *)p, d_1c21b4);
        strcat(p->p4, d_1c21b4);
        f_0e9650(&d_1c38b0, p->p4);
        d_1c38b0.f_05e320(0xbb, -1);
        d_1c38b0.f_05e1d0(d_1c38b0.f_05e1f0(), 0x24);
        d_1c38b0.f_0e9550(0x8030056);
    }
    d_1c38b0.f_05e2d0(a, b, c, d);
}


//@ f_058dc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die komplette Tagebuchansicht einschließlich Hintergrundbild (0x80000), der sechs
 *   Schaltflächen/Lesezeichen (d_1bfdb8), der aktuell aufgeschlagenen Tagebuchseite (f_058960) sowie der
 *   zentrierten Überschrift "Seite x von n" (0x8030060 bzw. 0x8030076 in der Suchansicht; Schwesterfunktion
 *   Diary::draw in *Sternenschweif*). Beim erstmaligen Öffnen (mode == 1 oder mode == 4) liest die Funktion
 *   zuvor die Gesamtseitenzahl aus der Tagebuchdatei und blendet am Ende die Palette über f_09a120 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Tagebuch-Objekt, den Darstellungsmodus mode
 *   (1 = Öffnen auf letzter Seite, 4 = Öffnen auf Seite 0, 2 = Suchansicht, 0 = bloßes Neuzeichnen beim
 *   Blättern) und einen optionalen Zielpuffer p3 (0 = eigenen Puffer anlegen oder Bildschirm nutzen). Sie gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zeiger buf verweist bei ausreichend freiem Speicher (> 80000 Bytes) auf einen
 *   temporären 64000-Byte-Hintergrundpuffer und sonst direkt auf den VGA-Bildschirmspeicher d_1a34e0.
 === Ende Beschreibung === */
void f_058dc0(Dia *p1, short mode, unsigned *p3)
{
    struct Frame {
        O1 o1; Obj2 o2; int copyFlag;
    } f;
    unsigned *buf, *q;
    int flag;
    short w, s;
    short a, b, d, c;
    void f_1459d0(void *, int);
    f_1459b0(&f.o1);
    f_125400(&f.o2, &d_1c349c, &d_1c3870, &d_1c3498);
    if (p3 == 0) {
        if (f_014a60() > 80000)
            buf = (unsigned *)f_014540(64000, d_1a1754, 0x1c4);
        else buf = d_1a34e0;
    } else buf = p3;
    void *saved = d_1c3068.f_05dec0();
    d_1c3068.f_05ded0(buf);
    if (mode == 4) {
        d_1a965c = d_1a16bc;
        if (d_1c2098.f_1448b0(0x40000000, 0x200) > 0) {
            d_1c2098.f_144920(p1, 2);
            d_1c2098.f_144920(&p1->c27, 1);
            d_1c2098.f_1449a0();
        }
        p1->n2 = 0;
        d_1a965c = 0;
        mode = 1;
    } else if (mode == 1) {
        d_1a965c = d_1a16bc;
        if (d_1c2098.f_1448b0(0x40000000, 0x200) > 0) {
            d_1c2098.f_144920(p1, 2);
            d_1c2098.f_144920(&p1->c27, 1);
            d_1c2098.f_1449a0();
        }
        d_1a965c = 0;
        if (p1->n0)
            p1->n2 = p1->n0 - 1;
        else p1->n2 = 0;
    }
    flag = 0;
    if (buf == d_1a34e0 && f_0d3860() == 1) {
        f_0d2710();
        flag = 1;
    }
    d_1c2a80 = 0x80000;
    f.o1.f_145a10(0x80000, buf);
    if (mode == 2) {
        for (s = 0; s < 6; s = s + 1)
            d_1bfdb8->f_0daa90(s);
    } else {
        for (s = 0; s < 6; s = s + 1)
            d_1bfdb8->f_0daaf0(s);
    }
    d_1bfdb8->f_0daba0(buf);
    if (flag == 1)
        f_0d26e0();
    f_058960(p1, (unsigned short)p1->n2);
    d_1c38b0.f_05e320(0xfe, -1);
    if (mode == 2) {
        p1 = (Dia *)0x8030076;
    } else {
        f.o2.p14[1] = p1->n2 + 1;
        f.o2.p14[2] = p1->n0;
        p1 = (Dia *)0x8030060;
    }
    w = d_1c38b0.f_0e9590((int)p1);
    d_1c38b0.f_05e2a0((short *)&a, (short *)&b, (short *)&c, (short *)&d);
    d_1c38b0.f_05e2d0(0x82 - (w >> 1), w + 1, 0x10, -1);
    d_1c38b0.f_0e9550((int)p1);
    d_1c38b0.f_05e2d0(a, b, c, d);
    d_1c3068.f_05ded0(saved); saved = ((int)saved & 0) ? 0 : saved; saved = ((int)saved & 0) ? 0 : saved;
    if (buf != d_1a34e0) {
        if (f_0d3860() == 1) {
            f_0d2710();
            f.copyFlag = 1;
        } else f.copyFlag = 0;
        memcpy(d_1a34e0, buf, 64000);
        if (f.copyFlag == 1)
            f_0d26e0();
    }
    if (mode == 1) {
        q = (unsigned *)f_014540(0x300, d_1a1754, 0x23a);
        q = ((int)q & 0) ? 0 : q;
        memcpy(q, f.o1.f_145b40(), 0x300);
        f_09a120(q, 0x19); delete q;


    }
    if (p3 == 0 && buf != d_1a34e0) delete buf;
    mode = (mode & 0) ? (short)0 : mode; f_1254a0(&f.o2, 0);
    f_1459d0((void *)&f.o1, 0);
}

//@ f_0591c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den Text der Tagebuchseite p2 anhand der Offsettabelle aus der Tagebuchdatei (d_1a16bc,
 *   Dateikennung 0x40000000) in den Puffer p->p4 und aktualisiert bei Bedarf die Gesamtseitenzahl p->n0 sowie
 *   den gespeicherten Kalendertag p->c27 (Schwesterfunktion Diary::load_page in *Sternenschweif*).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt und die 0-basierte
 *   Seitennummer p2. Sie gibt 1 zurück, wenn die Seite existiert und geladen wurde, sonst 0.
 * - Wichtige Variablen: Die lokalen Variablen a und b nehmen die beiden aufeinanderfolgenden 32-Bit-Dateioffsets
 *   der Seite p2 und p2 + 1 aus der Offsettabelle ab Dateiversatz 4 auf, sodass genau b - a Textbytes gelesen
 *   werden.
 === Ende Beschreibung === */
int f_0591c0(Dia *p, int p2)
{
    int r = 0;
    int a = 0;
    int b = 0;
    short c = 0;

    f_145300(p->p4, 0, 2000);
    d_1a965c = d_1a16bc;
    int t_465 = d_1c2098.f_1448b0(0x40000000, 0x200);
    if (t_465 > 0) {
        d_1c2098.f_144920(&c, 2);
        if ((short)c && (unsigned short)p2 < (short)(int)(short)(c & 0xffff)) {
            d_1c2098.f_144920(&p->c27, 2);
            d_1c2098.f_144ab0((unsigned short)p2 * 4u, 1);
            d_1c2098.f_144920(&a, 4);
            d_1c2098.f_144920(&b, 4);
            d_1c2098.f_144ab0(a, 0);
            d_1c2098.f_144920(p->p4, b - a);
            r = 1;
        }
        d_1c2098.f_1449a0();
    }
    d_1a965c = 0;
    if (p->n0 < (short)c)
        p->n0 = c;
    return r;
}

//@ f_0592f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert den Namen des aktuellen Aufenthaltsorts der Heldengruppe über die Textkennung
 *   0x20000011 in den übergebenen Zielpuffer s (Schwesterfunktion Diary::place_str in *Sternenschweif*).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt (ungenutzt) und den
 *   Zielpuffer s. Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das lokale Kontextobjekt o (Obj2) richtet die aktuellen Textparameter (d_1c349c,
 *   d_1c3870, d_1c3498) für die Textformatierung d_1c38b0.f_0e93f0 ein.
 === Ende Beschreibung === */
void f_0592f0(Dia *p, const char *s)
{
    Obj2 o;

    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    d_1c38b0.f_0e93f0(s, 0x20000011);
    f_1254a0(&o, 0);
}

//@ f_059330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert das aktuelle aventurische Spieldatum für den Seitenkopf des Tagebuchs in den Puffer
 *   s (Schwesterfunktion Diary::date_str in *Sternenschweif*). Während der Namenlosen Tage (Tag < 0) wird der
 *   Sondertext 0x8030077 mit Tag + 6 und Jahreszahl verwendet, an normalen Tagen der Text 0x8030053 (auf der
 *   ersten Tagebuchseite) bzw. 0x8030054 (ab Seite 2) mit Tag, Monatsname (0x20000012 + Monat) und Jahr.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt und den Zielpuffer s. Sie
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Zeitobjekt d_1c2c44 liefert über f_126430(), f_126450() und f_126460() den
 *   aktuellen Tag, Monat und das Jahr.
 === Ende Beschreibung === */
void f_059330(Dia *p, const char *s)
{
    Obj2 o;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    if (d_1c2c44.f_126430() < 0) {
        o.p14[1] = (short)d_1c2c44.f_126430() + 6;
        o.p14[2] = d_1c2c44.f_126460();
        d_1c38b0.f_0e93f0(s, 0x8030077);
    } else {
        o.p14[1] = d_1c2c44.f_126430();
        o.p14[2] = d_1c2c44.f_126460();
        o.p10[1] = d_1c2c44.f_126450() + 0x20000012;
        d_1c38b0.f_0e93f0(s, (p->n0 > 1) + 0x8030053);
    }
    f_1254a0(&o, 0);
}

//@ f_059410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt, wie viele Bildschirmzeilen ein Tagebuch-Seitentext s im Tagebuchfenster (206 Pixel
 *   Breite) einschließlich Seitenkopf und Trennzeile nach dem Wortumbruch (f_0e9680) einnimmt (Schwesterfunktion
 *   Diary::count_lines in *Sternenschweif*). Anhand dieses Werts entscheidet f_058210, ob ein neuer Eintrag noch
 *   unter die 20-Zeilen-Grenze der letzten Seite passt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Tagebuch-Objekt (ungenutzt) und den zu
 *   messenden Seitentext s. Sie gibt die berechnete Zeilenanzahl als short zurück.
 * - Wichtige Variablen: Der auf dem Heap angelegte 2000-Byte-Puffer buf nimmt die von Steuercodes und
 *   Kategoriemarken (d_1a16c8[4]..d_1a16c8[9]) bereinigten Textabschnitte für die Zeilenmessung auf.
 === Ende Beschreibung === */
short f_059410(Dia *p, const char *s)
{
    short len, a, d, lines, c, b, pos, end;
    char *buf;
    int idx;
    short check;
    signed char ch;

    pos = 0;
    lines = 0;
    len = strlen(s);
    end = len;
    buf = new (mark(d_1a1754, 0x2b3)) char[2000];
    d_1c38b0.f_05e2a0(&a, &b, &c, &d);
    idx = check = 0;
    d_1c38b0.f_05e2d0(0x19, 0xce, 0x1e, -1);
    f_145300(buf, 0, 2000);
    while (check < end) {
        ch = s[(short)idx]; ++idx;
        { short transit = *(short *)&d_1c3498; *(short *)&d_1c3498 = transit; } // Haelt die Konfliktsortierung wie im Original
        if (ch == d_1a16c8[0]) {
            if (buf[0]) {
                buf[pos] = 0;
                pos = 0;
                lines += d_1c38b0.f_0e9680(buf);
                end = (end & 0) ? (short)0 : end; // Haelt den Nutzwert des Endzaehlers
            }
            while (ch != d_1a16c8[1] && ch != d_1a16c8[2]) {
                ch = s[(short)idx++];
                buf[pos++] = ch;
            }
            buf[pos] = 0;
            buf[pos - 1] = buf[pos];
            pos = 0;
            idx--;
            lines += d_1c38b0.f_0e9680(buf);
            lines++;
            end = (end & 0) ? (short)0 : end; // Haelt den Nutzwert des Endzaehlers
        } else if (ch >= d_1a16c8[4] && ch <= d_1a16c8[9]) {
            idx++;
        } else if (ch != d_1a16c8[1] && ch != d_1a16c8[2] && ch != d_1a16c8[3]) {
            buf[pos++] = ch;
        }
        end = (end & 0) ? (short)0 : end; // Haelt den Nutzwert des Endzaehlers
        check = (short)idx;
    }
    buf[pos] = 0;
    lines += d_1c38b0.f_0e9680(buf) - 1;
    d_1c38b0.f_05e2d0(a, b, c, d);
    delete buf;
    return lines;
}
