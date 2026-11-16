/* === Beschreibung (Katalog) ===
 * Einheit fi_ac_co (0x06bdd0 - 0x06d050)
 *
 * Überblick
 * Die Einheit fi_ac_co (fi_ac_co.cpp, vermutlich "Fight Action Character/Combat") baut die
 * Kampfanimations-Sequenzen für Heldenaktionen im taktischen Rundenkampf auf: Fernkampfangriffe mit
 * Projektilflugbahn (f_06bdd0), Zauberangriffe mit Geschossbahn (f_06c380) sowie Spezialzauber wie
 * Verwandlungen, Hindernisse und Herbeirufungen (f_06c930).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 0/3 gleich (suche.py 30.10.2026, Basis fi_ac_co_P1.CPP)
// fi_ac_co.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06BDD0-0x06D050
#include <string.h>
struct E { unsigned char a, b, c, d; };
struct B { int w0; void *w4; void *w8; E e[38]; };
struct P { short x, y; };
struct T9 { char c[9]; };
struct R { signed char x, y; char p2[7]; unsigned char b9; char pa[5]; void *f; char p13[12]; char b1f; };
struct G {
    int d0; char p4[0x14]; unsigned char b18, b19; int d1a;
    unsigned char b1e, b1f, b20, p21, b22, b23, b24, b25, p26;
    int d27; int d2b; char p2f[0xa]; char sub[0x10c];
    short w145; short w147; char p149[0x149]; unsigned char b292;
    char p293[0xde8]; short w107b;
};

int f_06ed10(G *p1, void *p2, B *p3);
int f_0d4a60(void *p);


short f_030d80(void *p);
int f_0727e0(void *p);
signed char f_043490(void *p);
int f_0722a0(G *p1, void *p2, signed char c, B *p3);
int f_06e9e0(G *p1, void *p2, int c, short t, int *pi, B *p3, int z);
unsigned char f_043470(void *p);
R *f_07ea60(void *sub, unsigned v);
unsigned char f_0d54c0(void *p);
int f_071e90(unsigned char v, int *a, int *b);
signed char f_030960(void *p);
void *f_030890(void *p);
unsigned char f_0729c0(void *p);
void *f_030810(void *p);
short f_071e20(short a, short b, short c, short d);
int f_0d1360(void *e, short v);
int f_0d1390(void *e, short v);
void *f_014540(int size, const char *file, int line);
int f_0cdd50(short a, short b, short c, short d, P *buf);
short f_0de820(int v);
void *f_0708f0(G *p);
int f_069a00(void *o, B *b);
int f_06a600(void *o, int v);
int f_06a5b0(void *o, int v);
char f_07ec10(void *sub, int v);
int f_06ebf0(G *p1, void *p2, B *p3, short i);
R *f_07ea90(void *sub, int a, int b, int c);
int f_071e50(G *p1, int a, int b, int c);
short f_043c10(void *p);
short f_043c30(void *p);
unsigned char f_07a9e0(unsigned k);
unsigned char f_07aa10(unsigned k);
int f_04feb0(char *a, int b, int c, int d, int e, int f, short *g, short *h, int i);
T9 *f_0fac80(T9 *t, short a, short b);


int f_07b370(G *p1, int a, int b, unsigned c, int d);
void f_077760(G *p1, short a, unsigned char b, unsigned char c);
int f_077e20(G *p1, char *r, int a, int b);
int f_0cff90(char *r, int v);
int f_0cfc80(char *r, int v);
signed char f_0cfc70(char *r);
int f_0cfa10(char *r);
int f_0cfa50(char *r);
int f_06f5c0(G *p1, char *r, B *p3);
unsigned char f_0cfc50(char *r);
int f_07e7c0(void *sub, unsigned v);
int f_07e850(void *sub, unsigned v);
short f_1457e0(int v);
int f_069460(void);
int f_069be0(void *o);
char f_043dc0(void *p);
int f_043dd0(void *p, int v);

signed char f_0433d0(void *p);

extern const char d_1a1b2c[];
extern short d_1a2746;
extern unsigned short d_1a2744;
extern unsigned char d_1a277c[], d_1a2798[], d_1a274c[], d_1a2750[], d_1a2748[], d_1a27a0[];
extern signed char d_1a7276[], d_1a57ef[];
extern int d_1c0004, d_1c0412;
extern short d_1c040c, d_1c041d, d_1bd924, d_1bd938;
extern signed char d_1c041f;
extern char d_1bd918;
extern char *d_1bd930;
extern T9 **d_1bd92c;
extern char *d_1c2ed4;
extern char d_1c2be0[];

//@ f_06bdd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für einen handlungsfähigen Helden p2 die Animationssequenz eines Fernkampfangriffs
 *   (Bogen, Armbrust oder Wurfwaffe) im Puffer p3 auf: Dreht den Schützen über f_06e9e0 in Schussrichtung t,
 *   trägt die Schussanimation aus d_1a277c ein, berechnet bei einer Distanz > 1 mittels Bresenham-Linie
 *   (f_0cdd50) die Projektilflugbahn vom Schützen zum Ziel, belegt über f_0708f0 ein temporäres Geschoss-Sprite
 *   (0x1000b) und verknüpft es über den Startcode 0x1c mit dem Schützen-Sprite.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem-Objekt p1 (eax, G *), der Heldenzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, B *); zurückgegeben wird das Geschoss-Sprite result (oder das Helden-Sprite q->f,
 *   falls kein Projektil flog).
 * - Wichtige Variablen: src und dst speichern die berechneten Stützpunkte der Projektilbahn, b den
 *   Animationsbefehlsblock des Projektils.
 === Ende Beschreibung === */
short f_0722a0(G *p1, void *p2);
int f_06bdd0(G *p1, void *p2, B *p3)
{
    short x;
    short y1;
    short n;
    short step;
    short count;
    short ten;
    short y;
    short type;
    short x1;
    P *src;
    short a;
    B b;
    short t;
    short mode;
    short z;
    signed char kind;
    void *obj;
    P *dst;
    short i = 0;
    R *q;
    void *result = 0;

    if (f_0d4a60(p2)) {
        type = f_030d80(p2);
        memset(p3, 0, 0xa4);
        // Spaeter Blockbeginn ordnet die TempAlloc-Namen fuer Originalslots
        {
            short y2;
            short x2;
            p3->w0 = f_0727e0(p2);
            kind = f_043490(p2);
            t = f_0722a0(p1, p2);
            f_06e9e0(p1, p2, kind, t, (int *)&i, p3, 0);
            p3->e[i].a = d_1a277c[type * 4 + t];
            p3->e[i].b = 0;
            q = f_07ea60(p1->sub, f_043470(p2));

            f_071e90((unsigned char)(f_0d54c0(p2) + 1), (int *)&x, (int *)&a);
            obj = 0;
            if (f_030960(p2) == 1 || f_030960(p2) == 4)
                obj = f_030890(p2);
            if (f_030960(p2) == 1) {
                if (obj == 0) goto done_effect;
                f_071e90((unsigned char)(f_0729c0(obj) + 10), (int *)&y, (int *)&z);
            } else if (f_030960(p2) == 4) {
                if (obj == 0) goto done_effect;
                f_071e90((unsigned char)(f_0729c0(obj) + 0x1e), (int *)&y, (int *)&z);
            } else {
                f_071e90((unsigned char)(f_0d54c0(f_030810(p2)) + 1), (int *)&y, (int *)&z);
            }
        done_effect:
            if (f_071e20(x, a, y, z) > 1) {
                if ((f_030960(p2) == 1 || f_030960(p2) == 4) && obj) {
                    y = f_0d1360(obj, y);
                    z = f_0d1390(obj, z);
                }
                (void)(signed char)(x + a); // Berechneter Name ohne Speicher-Alias fuer die Slotvergabe
                src = (P *)f_014540(0x514, d_1a1b2c, 0xbc);
                x1 = (x + a) * 10 + d_1a2744;
                y1 = (x - a) * 5 + d_1a2746;
                x2 = (y + z) * 10 + d_1a2744;
                y2 = (y - z) * 5 + d_1a2746;
                n = f_0cdd50(x1, y1, x2, y2, src) - 1;
                ten = 10;
                mode = f_0de820(d_1c0004);
                if (mode == 7 || mode == 9)
                    ten = 5;
                count = n / ten;
#if FIX_R040
                if (count < 1) count = 1;
#endif
                dst = (P *)f_014540(count * 4, d_1a1b2c, 0xd6);
                for (step = 1; step <= count; step++) {
                    dst[step - 1].x = src[step * ten].x;
                    dst[step - 1].y = src[step * ten].y;
                }
                delete src;
                memset(&b, 0, 0xa4);
                result = f_0708f0(p1);
                b.w0 = 0x1000b;
                (void)(short)b.w0; // Schmale Feldsicht fuer die TempAlloc-Sortierung
                b.w4 = dst;
                b.e[0].a = ((type == 4) ? 0xcc : (type == 5) ? 0xf1 : 0xf5) + t;
                b.e[0].b = 3;
                b.e[0].d = 0x1d;
                b.e[0].c = (char)count;
                p1->d27 = (int)result;
                p1->b1f = (unsigned char)x;
                p1->b18 = p1->b1f;
                p1->b20 = (unsigned char)a;
                p1->b19 = p1->b20;
                p1->b24 = 0;
                p1->d1a = 0x1000b;
                p1->d2b = 0;
                p1->b22 = 0xfe;
                p1->b23 = 1;
                p1->b25 = 0xff;
                f_07ec10(p1->sub, -1);
                f_069a00(result, &b);
                f_06a600(result, 0);
                p3->e[i].d = 0x1c;
                p3->w8 = result;
            }
            i++;
            if (type == 4)
                p3->e[i].a = d_1a274c[t];
            else if (type == 6)
                p3->e[i].a = d_1a2750[t];
            else
                p3->e[i].a = d_1a2748[t];
            p3->e[i].b = 0;
            p3->e[i].c = 1;
            i++;
            p3->e[i].a = 0xff;
            f_069a00(q->f, p3);
            return (int)(result ? result : q->f);
        }
    }
    return f_06ed10(p1, p2, p3);
}


//@ f_06c380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für einen handlungsfähigen Helden p2 die Animationssequenz eines Kampfzaubers auf: Dreht
 *   den Zaubernden über f_06e9e0 zum Ziel, wählt je nach Zaubererklasse (f_042350 == 7 oder f_0433d0 % 2) die
 *   Zaubergeste aus d_1a2798, erzeugt bei aktiviertem Geschossflag d_1c0412 und Distanz > 1 ein magisches
 *   Projektil-Sprite (0xef oder 0xf0) entlang der Bresenham-Bahn (f_0cdd50) und hängt die Endpose an.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax, G *), der Heldenzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, B *); zurückgegeben wird das Geschoss-Sprite result bzw. das Helden-Sprite q->f.
 * - Wichtige Variablen: d_1c0412 gibt an, ob der gewirkte Zauber ein sichtbares Geschoss abfeuert.
 === Ende Beschreibung === */
int f_06c380(G *p1, void *p2, B *p3)
{
    short n;
    short x;
    R *q;
    short x2;
    P *dst;
    void *obj;
    short y2;
    short z;
    short count;
    short i = 0;
    short y1;
    short type;
    signed char kind;
    short step;
    void *result;
    P *src;
    short x1;
    short y;
    short mode;
    B b;
    short ten;
    short t;
    short a;

    result = 0;
    if (f_0d4a60(p2)) {
        memset(p3, 0, 0xa4);
        p3->w0 = f_0727e0(p2);
        kind = f_043490(p2);
        t = f_0722a0(p1, p2);
        f_06e9e0(p1, p2, kind, t, (int *)&i, p3, 0);
        mode = (f_042350((struct hero *)(p2)) == 7) ? 0 : (f_0433d0(p2) % 2);
        p3->e[i].a = d_1a2798[mode * 4 + t];
        p3->e[i].b = 0;
        q = f_07ea60(p1->sub, f_043470(p2));

        // Erzwingt direkten Speichervergleich von d_1c0412 wie im Original
        if (*(volatile int *)&d_1c0412 && f_030960(p2) != 5) {
            f_071e90((unsigned char)(f_0d54c0(p2) + 1), (int *)&x, (int *)&a);
            obj = 0;
            if (f_030960(p2) == 1 || f_030960(p2) == 4)
                obj = f_030890(p2);
            if (f_030960(p2) == 1) {
                if (obj == 0) goto done_effect;
                f_071e90((unsigned char)(f_0729c0(obj) + 10), (int *)&y, (int *)&z);
            } else if (f_030960(p2) == 4) {
                if (obj == 0) goto done_effect;
                f_071e90((unsigned char)(f_0729c0(obj) + 0x1e), (int *)&y, (int *)&z);
            } else {
                f_071e90((unsigned char)(f_0d54c0(f_030810(p2)) + 1), (int *)&y, (int *)&z);
            }
        done_effect:
            if (f_071e20(x, a, y, z) > 1) {
                if ((f_030960(p2) == 1 || f_030960(p2) == 4) && obj) {
                    y = f_0d1360(obj, y);
                    z = f_0d1390(obj, z);
                }
                src = (P *)f_014540(0x514, d_1a1b2c, 0x192);
                x1 = (x + a) * 10 + d_1a2744;
                y1 = (x - a) * 5 + d_1a2746;
                x2 = (y + z) * 10 + d_1a2744;
                y2 = (y - z) * 5 + d_1a2746;
                n = f_0cdd50(x1, y1, x2, y2, src) - 1;
                ten = 10;
                count = n / ten;
#if FIX_R040
                if (count < 1) count = 1;
#endif
                dst = (P *)f_014540(count * 4, d_1a1b2c, 0x19e);
                for (step = 1; step <= count; step++) {
                    dst[step - 1].x = src[step * ten].x;
                    dst[step - 1].y = src[step * ten].y;
                }
                delete src;
                memset(&b, 0, 0xa4);
                result = f_0708f0(p1);
                b.w0 = 0x1000b;
                (void)(short)b.w0; // Schmale Feldsicht fuer die TempAlloc-Sortierung
                b.w4 = dst;
                b.e[0].a = mode ? 0xf0 : 0xef;
                b.e[0].b = 3;
                b.e[0].d = 0x1d;
                b.e[0].c = (char)count;
                p1->d27 = (int)result;
                p1->b1f = (unsigned char)x;
                p1->b18 = p1->b1f;
                p1->b20 = (unsigned char)a;
                p1->b19 = p1->b20;
                p1->b24 = 0;
                p1->d1a = 0x1000b;
                p1->d2b = 0;
                p1->b22 = 0xfe;
                p1->b23 = 1;
                p1->b25 = 0xff;
                f_07ec10(p1->sub, -1);
                f_069a00(result, &b);
                f_06a600(result, 0);
                p3->e[i].d = 0x1c;
                p3->w8 = result;
            }
        }
        i++;
        type = f_030d80(p2);
        if (type == 4) {
            unsigned char value = d_1a274c[t];
            p3->e[i].a = value;
        }
        else if (type == 6)
            p3->e[i].a = d_1a2750[t];
        else
            p3->e[i].a = d_1a2748[t];
        p3->e[i].b = 0;
        p3->e[i].c = 1;
        i++;
        p3->e[i].a = 0xff;
        f_069a00(q->f, p3);
        {
            void *rv = result;
            if (!rv) rv = q->f;
            return (int)rv;
        }
    }
    return f_06ed10(p1, p2, p3);
}


//@ f_06c930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für einen Helden p2 Spezial- und Effektanimationen bei Zaubern oder Gegenstandseinsatz
 *   (abhängig von p4 und p5 über die Tabellen d_1a7276 bzw. d_1a57ef) auf: Unterstützt unter anderem das
 *   Platzieren von Hindernissen auf dem Kampffeld (c == 3, Grafik 0x260000), das Beschwören/Erzeugen neuer
 *   Kampfeinheiten (c == 7 oder 8, Slot d_1bd924 mit Erscheinungseffekt 0xec/0xed/0xee),
 *   Unsichtbarkeits-/Verwandlungseffekte (d_1c040c == 0x2e) sowie glitzernde Zaubereffekte (0xd8 auf
 *   Effekt-Sprite 0x1000b).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Heldenzeiger p2 (edx), der Sequenzpuffer
 *   p3 (ebx), der Effektindex p4 (ecx, short) und auf dem Stapel der Modus p5 (short); zurückgegeben wird das
 *   aktive Effekt- oder Figuren-Sprite (int in eax).
 * - Wichtige Variablen: d_1bd924 zählt dynamisch beschworene Kampfeinheiten, d_1bd92c cached geladene
 *   Hindernis-Grafiken.
 === Ende Beschreibung === */
int f_06c930(G *p1, void *p2, B *p3, short p4, short p5)
{
    
    short w1;
    short w2;
    char *r;
    B buf;
    R *q;
    short x;
    signed char c;
    short y;
    short i = 0;
    void *o = 0;
    short k;
    T9 *t;

    { signed char rt = d_1c041f; d_1c041f = rt; } // Codeloser Global-Roundtrip fuer die Registerfolge
    (void)(signed char)(p4 + p5); // Berechneter schmaler Name fuer TempAlloc
    if ((f_0d4a60(p2) && !((char)(f_0424d0((struct hero *)(p2))))) || ((char)(f_042470((struct hero *)(p2)))) || d_1c040c == 0x2e) {
        if (p4 == 4 && p5 == 2) {
            q = f_07ea90(p1->sub, 0x68, (signed char)f_043c10(p2), (signed char)f_043c30(p2));
            { char * extra4 = d_1bd930; d_1bd930 = extra4; } // Berechnete Vorsortierung fuer die Registerfolge
            q->b1f = 1;
            f_071e50(p1, q->x, q->y, 0);
            memset(&buf, 0, 0xa4);
            o = f_0708f0(p1);
            buf.w0 = 0x1000b;
            buf.e[0].a = 0xd8;
            buf.e[0].b = 0;
            buf.e[0].d = 0x1d;
            p1->d27 = (int)o;
            p1->b1f = q->x;
            p1->b18 = p1->b1f;
            p1->b20 = q->y;
            p1->b19 = p1->b20;
            p1->b24 = 0;
            p1->d1a = 0x1000b;
            p1->d2b = 0;
            p1->b22 = 100;
            p1->b23 = 1;
            p1->b25 = 0xff;
            { char * extra0 = d_1bd930; d_1bd930 = extra0; } // Berechnete Vorsortierung fuer die Registerfolge
            f_07ec10(p1->sub, -1);
            f_069a00(o, &buf);
            f_06a5b0(o, 1);
            return (int)o;
        }
        if (p5 == 2)
            c = d_1a7276[p4 * 14];
        else
            c = d_1a57ef[p4 * 12];
        q = f_07ea60(p1->sub, f_043470(p2));
        if (c == 0) {
            memset(p3, 0, 0xa4);
            p3->w0 = f_0727e0(p2);
            p3->e[i].a = d_1a27a0[f_043490(p2)];
            p3->e[i++].b = 0;
            if (d_1bd918) {
                p3->e[i].a = 0x26;
                p3->e[i++].b = 0;
            }
            { signed char extra1 = d_1c041f; d_1c041f = extra1; } // Berechnete Vorsortierung fuer die Registerfolge
            f_06ebf0(p1, p2, p3, i);
            i++;
            p3->e[i].a = 0xff;
            f_069a00(q->f, p3);
            return (int)q->f;
        } else if (c == 3) {
            k = 0x68;
            x = f_043c10(p2);
            y = f_043c30(p2);
            if (d_1bd92c[k]) {
                t = d_1bd92c[k];
                { signed char extra2 = d_1c041f; d_1c041f = extra2; } // Berechnete Vorsortierung fuer die Registerfolge
                ((RivaRasterImage*)(t))->f_0fb210((short *)( &w1),(short *)( &w2));
            } else {
                T9 *tmp;
                f_04feb0(d_1c2be0, 0x260000, p1->d0, 0, k - 100, 0, &w1, &w2, 0x140);
                tmp = (T9 *)operator new(sizeof(T9), mark(d_1a1b2c, 0x259));
                t = d_1bd92c[k] = tmp ? f_0fac80(tmp, w1, w2) : 0;
                ((RivaRasterImage*)(t))->f_0fb090((void *)( p1->d0));
            }
            p1->b1e = (unsigned char)k;
            p1->b18 = (unsigned char)x;
            p1->b19 = (unsigned char)y;
            p1->b1f = f_07a9e0((unsigned char)k);
            p1->b20 = f_07aa10((unsigned char)k);
            p1->b24 = 0;
            p1->d27 = 0;
            p1->d2b = (int)t;
            p1->b22 = 0x32;
            p1->b23 = 1;
            p1->b25 = 0xff;
            unsigned char value = f_07ec10(p1->sub, -1);
            p4 = d_1bd938++;
            d_1bd930[p4] = value;
            f_07b370(p1, x, y, (unsigned char)(k + 0x32), 0);
            p1->w107b++;
            return f_06ed10(p1, p2, p3);
#if FIX_R040
        } else if ((c == 7 || c == 8) && d_1bd924 < 0x14) {
#else
        } else if (c == 7 || c == 8) {
#endif
            r = d_1c2ed4 + d_1bd924 * 0x73;
            x = f_043c10(p2);
            y = f_043c30(p2);
            f_077760(p1, d_1bd924, (unsigned char)d_1c041d, 0);
            f_077e20(p1, r, x, y);
            { signed char extra3 = d_1bd918; d_1bd918 = extra3; } // Berechnete Vorsortierung fuer die Registerfolge
            f_0cff90(r, d_1c041f);
            f_0cfc80(r, f_043490(p2));
            f_07b370(p1, x, y, (unsigned char)(d_1bd924 + 10), f_0cfc70(r));
            p1->w145 += f_0cfa10(r);
            p1->w147 += f_0cfa50(r);
            f_06f5c0(p1, r, p3);
            q = f_07ea60(p1->sub, f_0cfc50(r));
            f_07e7c0(p1->sub, q->b9);
            d_1bd924++;
            memset(&buf, 0, 0xa4);
            o = f_0708f0(p1);
            buf.w0 = 0x1000b;
            buf.e[0].a = (d_1c041d == 0x50) ? (unsigned char)(f_1457e0(100) >= 50) + 0xed : 0xec;
            buf.e[0].b = 0;
            buf.e[0].d = 0x1d;
            p1->d27 = (int)o;
            p1->b1f = q->x;
            p1->b18 = p1->b1f;
            p1->b20 = q->y;
            p1->b19 = p1->b20;
            p1->b24 = 0;
            p1->d1a = 0x1000b;
            p1->d2b = 0;
            p1->b22 = 100;
            p1->b23 = 1;
            p1->b25 = 0xff;
            f_07ec10(p1->sub, -1);
            f_069a00(o, &buf);
            f_06a5b0(o, 1);
            p1->b292 = 0;
            do {
                f_069460();
            } while (!p1->b292 && !f_069be0(o));
            f_07e850(p1->sub, q->b9);
            return (int)q->f;
        } else {
            if (d_1c040c == 0x2e) {
                if (f_043dc0(p2))
                    f_043dd0(p2, 2);
                else
                    f_043dd0(p2, 1);
            }
            memset(&buf, 0, 0xa4);
            o = f_0708f0(p1);
            buf.w0 = 0x1000b;
            buf.e[0].a = 0xd8;
            buf.e[0].b = 0;
            buf.e[0].d = 0x1d;
            p1->d27 = (int)o;
            p1->b1f = q->x;
            p1->b18 = p1->b1f;
            p1->b20 = q->y;
            p1->b19 = p1->b20;
            p1->b24 = 0;
            p1->d1a = 0x1000b;
            p1->d2b = 0;
            p1->b22 = 100;
            p1->b23 = 1;
            p1->b25 = 0xff;
            f_07ec10(p1->sub, -1);
            f_069a00(o, &buf);
            f_06a5b0(o, 1);
            return (int)o;
        }
    }
    return f_06ed10(p1, p2, p3);
}
