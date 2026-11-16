/* === Beschreibung (Katalog) ===
 * Einheit fi_ac_mo (0x06d580 - 0x06e4f0)
 *
 * Überblick
 * Die Einheit fi_ac_mo (fi_ac_mo.cpp, "Fight Action Monster") ist das Gegenstück zu fi_ac_co für Monster und
 * feindliche NSCs: Sie baut die Animationssequenzen für Monster-Fernkampfangriffe (f_06d580), Monster-Zauber mit
 * Geschossen (f_06daa0) sowie Monster-Spezialaktionen wie Beschwörungen und Gestaltwandlungen (f_06df80) auf.
 === Ende Beschreibung === */
// P3 0/3 gleich (suche.py 29.10.2026, Basis fi_ac_mo_P1.CPP)
// fi_ac_mo.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06D580-0x06E4F0
#include <string.h>
#include "RIVAMEM.H"

typedef short idx_t;
struct E { unsigned char a, b, c, d; };
struct R { int w0; int w4; int w8; E e[38]; };
struct PS { short a, b; };
struct Q { signed char p0, p1; char pad[7]; unsigned char b9; char pad2[3]; unsigned char b13, b14; int q; };
struct T {
    char pad0[0x18];
    unsigned char b18, b19;
    int d1a;
    char pad1;
    unsigned char b1f, b20;
    char pad2;
    unsigned char b22, b23, b24, b25;
    char pad3;
    int d27;
    int d2b;
    char pad4[10];
    char sub[0x145 - 0x39];
    short w145;
    short w147;
};

void *f_014540(int size, const char *file, int line);

short f_06f5c0(T *self, int p2, R *p3);
int f_072940(int p1);
int f_0d06c0(int p1);
int f_07a2b0(T *self, int p2, void *p3);
short f_079f70(T *self, int p2, void *p3);
int f_079e80(T *self, int p2, R *p3, int p4);
int f_0d11c0(int p1);
int f_0728f0(int p1);
signed char f_0cfc70(int p1);
signed char f_072440(T *self, int p2, unsigned char *c);
int f_06f400(T *self, int p2, unsigned char *c, int d, short *e, R *f, int g);
unsigned char f_0cfc50(int p1);
struct Q *f_07ea60(void *a, unsigned char b);
unsigned char f_0729c0(int p1);
void f_071e90(unsigned char a, short *b, short *c);
signed char f_0cfd40(int p1);
int f_0d0910(int p1);
int f_0d08a0(int p1);
unsigned char f_0d54c0(int p1);
short f_071e20(short a, short b, short c, short d);
int f_0cdd50(short a, short b, short c, short d, void *e);
short f_0de820(int p1);
int f_0708f0(T *self);
signed char f_0d05d0(int p1);
void f_07ec10(void *a, int b);
void f_069a00(int a, void *b);
void f_06a600(int a, int b);
void f_06a5b0(int a, int b);
signed char f_0cfd00(int p1);
int f_0cfdc0(int p1);
int f_0cfe30(int p1);
int f_0cff50(int p1);
int f_0cfdf0(int p1);
int f_06d380(T *self, int p2, short *c, R *d);
short f_1457e0(int p1);
unsigned char f_0d01c0(int p1);
unsigned char f_0d01e0(int p1);
int f_077760(T *self, int p2, int p3, int p4);
int f_077e20(T *self, int p2, int p3, int p4);
signed char f_071fb0(T *self, int p2);
int f_0cfc80(int p1, int p2);
int f_07b370(T *self, int p2, int p3, int p4, int p5);
int f_0cfa10(int p1);
int f_0cfa50(int p1);
int f_071e50(T *self, int p2, int p3, int p4);
Q *f_07eb00(void *a, int b);
int f_07eba0(void *a, int b, int c);
signed char f_0cfc90(int p1);
int f_0cff90(int p1, int p2);
int f_0cfca0(int p1, int p2);

extern int d_1c0004;
extern int d_1c0412;
extern int d_1c2ed4;
extern char d_1bd918;
extern short d_1bd924;
extern short d_1a2744;
extern short d_1a2746;
extern unsigned char d_1a277c[];
extern unsigned char d_1a2748[];
extern unsigned char d_1a2798[];
extern short d_1a27a0[];
extern unsigned char d_1a7276[];
extern unsigned char d_1a57ef[];
extern const char d_1a1b4c[];

//@ f_06d580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für ein handlungsfähiges Monster hero (f_072940) die Animationssequenz eines
 *   Fernkampfangriffs im Puffer seq auf (bei großen Monstern f_0d06c0 wird an f_07a2b0 delegiert): Dreht das
 *   Monster über f_06f400 in Schussrichtung to, setzt die Schussphase aus d_1a277c, berechnet bei einer Distanz
 *   > 1 per Bresenham-Algorithmus (f_0cdd50) die Projektilflugbahn und erzeugt über f_0708f0 ein Geschoss-Sprite
 *   (0xd0 + to für Spezialschützen f_0d05d0, sonst waffenabhängig 0xcc/0xf1/0xf5 + to).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax, T *), der Monsterzeiger hero (edx) und der
 *   Sequenzpuffer seq (ebx, R *); zurückgegeben wird das Geschoss-Sprite result bzw. das Monster-Sprite node->q.
 * - Wichtige Variablen: weaponClass (f_0d11c0) bestimmt die Fernkampfwaffenart des Monsters, path speichert die
 *   Koordinaten der Projektilbahn.
 === Ende Beschreibung === */
int f_06d580(T *self, int hero, R *seq)
{
    typedef short (*Line690)(short,short,short,short,short*);
    typedef short (*Weapon660)(int);
    typedef short (*Facing660)(T*,int);
    typedef void (*Turn660)(T*,int,signed char*,short,short*,R*,short);
    typedef int (*Standing660)(T*,int,R*);
    signed char to;
    int result=0;
    signed char from;
    short x1;
    short y1;
    short x2;
    short n=0;
    Q * node;
    short weaponClass;
    short dist;
    short y2;
    if(f_072940(hero)) {
        if(f_0d06c0(hero)) return f_07a2b0(self,hero,(char*)self+0x45);
        weaponClass=((Weapon660)f_0d11c0)(hero);
        memset(seq,0,sizeof(R));
        seq->w0=f_0728f0(hero);
        from=f_0cfc70(hero);
        to=(signed char)((Facing660)f_072440)(self,hero);
        ((Turn660)f_06f400)(self,hero,&from,to,&n,seq,0);
        seq->e[n].a=d_1a277c[weaponClass*4+to];
        seq->e[n].b=0;
        node=f_07ea60(self->sub,f_0cfc50(hero));
        f_071e90((unsigned char)(f_0729c0(hero)+10),&x1,&y1);
        if(f_0cfd40(hero)==1) f_071e90((unsigned char)(f_0729c0(f_0d0910(hero))+10),&x2,&y2);
        else if(f_0cfd40(hero)==4) f_071e90((unsigned char)((unsigned char)((short (*)(int))f_0729c0)(f_0d0910(hero))+30),&x2,&y2);
        else f_071e90((unsigned char)(f_0d54c0(f_0d08a0(hero))+1),&x2,&y2);
        dist=f_071e20(x1,y1,x2,y2);
        (void)(short)(int)hero; // Word-Alias fuer Originalslots
        if(dist>1) {
            short step;
            R shot;
            short ex;
            short i;
            PS * line;
            short sy;
            short cnt;
            short steps;
            short ey;
            short sx;
            PS * path;
            short group;
            line=(PS*)f_014540(0x514,d_1a1b4c,0xe7);
            sx=d_1a2744+(x1+y1)*10;
            sy=d_1a2746+(x1-y1)*5;
            ex=d_1a2744+(x2+y2)*10;
            ey=d_1a2746+(x2-y2)*5;
            cnt=(short)(((Line690)f_0cdd50)(sx,sy,ex,ey,(short*)line)-1);
            step=10;
            group=f_0de820(d_1c0004);
            if(group==7 || group==9) step=5;
            steps=cnt/step;
            path=(PS*)f_014540(steps*4,d_1a1b4c,0x101);
            for(i=1;i<=steps;i++) {
                path[i-1].a=line[i*step].a;
                path[i-1].b=line[i*step].b;
            }
            delete line;
            memset(&shot,0,sizeof(R));
            result=f_0708f0(self);
            shot.w0=0x1000b;
            shot.w4=(int)path;
            if(((int (*)(int))f_0d05d0)(hero)) shot.e[0].a=to+0xd0;
            else shot.e[0].a=(weaponClass==4?0xcc:weaponClass==5?0xf1:0xf5)+to;
            shot.e[0].b=3;
            shot.e[0].d=0x1d;
            shot.e[0].c=steps;
            self->d27=result;
            self->b18=self->b1f=x1;
            self->b19=self->b20=y1;
            self->b24=0;
            self->d1a=0x1000b;
            self->d2b=0;
            self->b22=0xfe;
            self->b23=1;
            self->b25=0xff;
            f_07ec10(self->sub,-1);
            f_069a00(result,&shot);
            f_06a600(result,0);
            seq->e[n].d=0x1c;
            seq->w8=result;
        }
        n++;
        seq->e[n].a=d_1a2748[to];
        seq->e[n].b=0;
        seq->e[n].c=1;
        n++;
        seq->e[n].a=0xff;
        f_069a00(node->q,seq);
        return result?result:node->q;
    }
    return ((Standing660)f_06f5c0)(self,hero,seq);
}

//@ f_06daa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für ein handlungsfähiges Monster hero die Animationssequenz eines Zauberspruchs auf (bei
 *   großen Monstern über f_079f70): Dreht das Monster, falls es nicht sich selbst verzaubert (hero != target),
 *   über f_06f400 zum Ziel target, wählt die Zaubergeste d_1a2798[to] und erzeugt bei gesetztem Geschossflag
 *   d_1c0412 und Distanz > 1 ein magisches Projektil-Sprite (0xef oder 0xf0) entlang der Bresenham-Linie zum
 *   Ziel.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Monsterzeiger hero (edx) und der
 *   Sequenzpuffer seq (ebx); zurückgegeben wird das Geschoss-Sprite result bzw. das Monster-Sprite node->q.
 * - Wichtige Variablen: target (f_0d0910(hero)) ist das Ziel des Monsterzaubers, d_1c0412 steuert die
 *   Projektilanzeige.
 === Ende Beschreibung === */
int f_06daa0(T *self, int hero, R *seq)
{
    typedef short (*Facing660)(T*,int);
    typedef void (*Turn660)(T*,int,signed char*,short,short*,R*,short);
    typedef int (*Standing660)(T*,int,R*);
    typedef int (*Large660)(T*,int,void*);
    int result = 0;
    int target;
    PS *path;
    Q *node;
    short x1;
    short y1;
    short x2;
    short n = 0;
    short y2;
    signed char from;
    signed char to;
    if (f_072940(hero)) {
        if (f_0d06c0(hero)) return ((Large660)f_079f70)(self, hero, (char *)self + 0x45);
        memset(seq, 0, sizeof(R));
        seq->w0 = f_0728f0(hero);
        target = f_0d0910(hero);
        from = f_0cfc70(hero);
        if (hero != target) {
            to = (signed char)((Facing660)f_072440)(self, hero);
            ((Turn660)f_06f400)(self, hero, &from, to, &n, seq, 0);
        } else {
            to = from;
        }
        seq->e[n].a = d_1a2798[to];
        seq->e[n].b = 0;
        node = f_07ea60(self->sub, f_0cfc50(hero));
        if (d_1c0412 && hero != target) {
            f_071e90((unsigned char)(f_0729c0(hero) + 10), &x1, &y1);
            if (f_0cfd40(hero) == 1) f_071e90((unsigned char)(f_0729c0(f_0d0910(hero)) + 10), &x2, &y2);
            else if (f_0cfd40(hero) == 4) f_071e90((unsigned char)(f_0729c0(f_0d0910(hero)) + 30), &x2, &y2);
            else f_071e90((unsigned char)(f_0d54c0(f_0d08a0(hero)) + 1), &x2, &y2);
            if (f_071e20(x1, y1, x2, y2) > 1) {
                R shot;
                short i;
                short steps;
                short ex;
                short ey;
                PS *line;
                short sx;
                short step;
                short cnt;
                short sy;
                (void)(signed char)x2; // I1-Alias ordnet die Names-Liste fuer die Originalslots
                line = (PS *)f_014540(0x514, d_1a1b4c, 0x193);
                sx = d_1a2744 + (x1 + y1) * 10;
                sy = d_1a2746 + (x1 - y1) * 5;
                ex = d_1a2744 + (x2 + y2) * 10;
                ey = d_1a2746 + (x2 - y2) * 5;
                cnt = f_0cdd50(sx, sy, ex, ey, line) - 1;
                step = 10;
                steps = cnt / step;
                path = (PS *)f_014540(steps * 4, d_1a1b4c, 0x19f);
                for (i = 1; i <= steps; i++) {
                    path[i - 1].a = line[i * step].a;
                    path[i - 1].b = line[i * step].b;
                }
                delete line;
                memset(&shot, 0, sizeof(R));
                result = f_0708f0(self);
                shot.w0 = 0x1000b;
                shot.w4 = (int)path;
                shot.e[0].a = (f_0cfd00(hero) % 2) ? 0xef : 0xf0;
                shot.e[0].b = 3;
                shot.e[0].d = 0x1d;
                shot.e[0].c = steps;
                self->d27 = result;
                self->b18 = self->b1f = x1;
                self->b19 = self->b20 = y1;
                self->b24 = 0;
                self->d1a = 0x1000b;
                self->d2b = 0;
                self->b22 = 0xfe;
                self->b23 = 1;
                self->b25 = 0xff;
                f_07ec10(self->sub, -1);
                f_069a00(result, &shot);
                f_06a600(result, 0);
                seq->e[n].d = 0x1c;
                seq->w8 = result;
            }
        }
        n++;
        seq->e[n].a = d_1a2748[to];
        seq->e[n].b = 0;
        seq->e[n].c = 1;
        n++;
        seq->e[n].a = 0xff;
        f_069a00(node->q, seq);
        return result ? result : node->q;
    }
    return ((Standing660)f_06f5c0)(self, hero, seq);
}

//@ f_06df80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für ein Monster p2 Spezialzauber- und Verwandlungsanimationen anhand der Effekt-Tabellen
 *   d_1a7276 bzw. d_1a57ef auf (bei großen Monstern über f_079e80): Bei mode == 0 oder 2 führt das Monster die
 *   Zauberpose d_1a27a0 (gegebenenfalls mit Sterbe-/Effektfolge 0x26 und f_06d380) aus; bei mode == 7 beschwört
 *   es ein neues Monster im Slot d_1bd924 auf Position (bx1, by2); bei mode == 5 verwandelt es sich in den
 *   Einheitentyp 0x10 (f_077760), jeweils begleitet vom Glitzereffekt 0xd8 (0x1000b).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Monsterzeiger p2 (edx), der
 *   Sequenzpuffer p3 (ebx), der Effektindex p4 (ecx, short) und auf dem Stapel p5 (short); zurückgegeben wird
 *   das aktive Effekt- oder Monster-Sprite (int in eax).
 * - Wichtige Variablen: state bündelt den neuen Monsterzeiger uu, die Zielkoordinaten a3c/a44, das Effekt-Sprite
 *   v und den Rasterknoten x.
 === Ende Beschreibung === */
int f_06df80(T *self, int p2, R *p3, short p4, short p5)
{
    signed char mode;
    // 20-Byte-Objekt haelt die fuenf DWORD-Rollen in Originalreihenfolge
    struct State { int uu; int a44; int v; int a3c; Q *x; } state;
    short px;
    state.v = 0;
    idx_t idx = 0;
    short py;
    if (f_0d06c0(p2)) return f_079e80(self, p2, p3, p4);
    if (f_072940(p2) || ((signed char (*)(int))f_0cfdc0)(p2) || ((signed char (*)(int))f_0cfe30)(p2) || ((signed char (*)(int))f_0cff50)(p2) || ((signed char (*)(int))f_0cfdf0)(p2)) {
        if (p5 == 2) mode = d_1a7276[p4 * 14];
        else mode = d_1a57ef[p4 * 12];
        state.x = f_07ea60(self->sub, f_0cfc50(p2));
        { Q *copy = state.x; state.x = copy; } // Codeloser Zeiger-Roundtrip fuer die Registerfolge
        if (mode == 0 || mode == 2) {
            memset(p3, 0, 0xa4);
            p3->w0 = f_0728f0(p2);
            p3->e[(short)idx].a = *(short *)((char *)d_1a27a0 + f_0cfc70(p2));
            p3->e[(short)idx++].b = 0;
            if (d_1bd918) {
                signed char c3 = f_0cfc70(p2);
                if (c3 != 1) f_06f400(self, p2, (unsigned char *)&c3, 1, (short *)&idx, p3, 0);
                p3->e[(short)idx].a = 0x26;
                p3->e[(short)idx++].b = 0;
                state.v = f_06d380(self, p2, (short *)&idx, p3);
            }
            p3->e[(short)idx].a = 0xff;
            f_069a00(state.x->q, p3);
            return state.v ? state.v : state.x->q;
        } else {
            px = state.x->p0;
            py = state.x->p1;
            if (mode == 7) {
                int r = f_1457e0(10);
                state.uu = d_1c2ed4 + d_1bd924 * 0x73;
                unsigned short w = ((unsigned short *)(d_1a1b4c + 0x1e))[r];
                r = w;
                unsigned char bx1 = f_0d01c0(p2);
                px = bx1;
                unsigned char by2 = f_0d01e0(p2);
                py = by2;
                r = (unsigned char)r;
                f_077760(self, d_1bd924, r, 0);
                state.a44 = by2;
                state.a3c = bx1;
                (void)(signed char)state.a3c; // Schmaler Alias nach gueltiger Definition
                { short rt = d_1bd924; d_1bd924 = rt; } // Berechneter Zusatzname fuer die Registerfolge
                f_077e20(self, state.uu, state.a3c, state.a44);
                f_0cfc80(state.uu, f_071fb0(self, f_0cfc70(p2)));
                f_07b370(self, state.a3c, state.a44, (unsigned char)(d_1bd924 + 10), f_0cfc70(state.uu));
                self->w145 += ((unsigned short (*)(int))f_0cfa10)(state.uu);
                self->w147 += ((unsigned short (*)(int))f_0cfa50)(state.uu);
                f_06f5c0(self, state.uu, p3);
                d_1bd924++;
            } else if (mode == 5) {
                short Y;
                unsigned char e14;
                short X;
                signed char c70;
                X = px;
                e14 = state.x->b14;
                c70 = f_0cfc70(p2);
                Y = py;
                if (state.x->b13 != (unsigned char)0xff) {
                    Q *m = f_07eb00(self->sub, (unsigned char)(state.x->b13 + 0x14));
                    f_07eba0(self->sub, m->b9, 0);
                }
                f_07eba0(self->sub, f_0cfc50(p2), 0);
                signed char c90 = f_0cfc90(p2);
                state.a44 = Y;
                state.a3c = X;
                f_071e50(self, state.a3c, state.a44, e14);
                f_077760(self, f_0729c0(p2), 0x10, 0);
                f_077e20(self, p2, state.a3c, state.a44);
                f_0cfc80(p2, c70);
                f_071e50(self, state.a3c, state.a44, (unsigned char)(f_0729c0(p2) + 10));
                f_0cff90(p2, 1);
                f_0cfca0(p2, c90);
                f_06f5c0(self, p2, p3);
            }
            int nv;
            R rr;
            memset(&rr, 0, 0xa4);
            nv = f_0708f0(self);
            rr.w0 = 0x1000b;
            rr.e[0].a = 0xd8;
            rr.e[0].b = 0;
            rr.e[0].d = 0x1d;
            self->d2b = 0;
            self->b22 = 0x64;
            self->b23 = 1;
            self->b25 = 0xff;
            self->d27 = nv;
            self->b24 = 0;
            self->b1f = px;
            self->b18 = px;
            self->b20 = py;
            self->b19 = py;
            self->d1a = 0x1000b;
            f_07ec10(self->sub, -1);
            f_069a00(nv, &rr);
            f_06a5b0(nv, 1);
            return nv;
        }
    }
    return ((int (*)(T *, int, R *))f_06f5c0)(self, p2, p3);
}
