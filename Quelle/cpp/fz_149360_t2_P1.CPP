/* === Beschreibung (Katalog) ===
 * Einheit fz_149360_t2 (0x149470 - 0x149CAA)
 *
 * Überblick
 * Diese Einheit gehört zur 3D-Dungeon- und Szenen-Engine (BRender-Integration) und steuert bewegliche und
 * interaktive 3D-Szenenobjekte (Türen, Hebel, Fallen, Plattformen, animierte Umgebungsobjekte und umschaltbare
 * Wand-/Bodentexturen). Sie enthält Funktionen zum Umschalten von Objektzuständen, zum zeitgesteuerten
 * Interpolieren von Translationen und Rotationen auf 3D-Transformationstabellen, zur
 * 2D-Punkt-in-Polygon-Kollisionsprüfung auf Welt-Meshes ('E'-Objekten) sowie zum Austauschen von
 * Texturmaterialien.
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s -fp5
// P3 6/10 gleich (suche.py 30.10.2026, Basis fz_149360_t2_P1.CPP)
// Codex Agent 9: Tabellenfamilie, 1/13 GLEICH, +80 B; 24.10.2026.
// F4 Stand (Basis p1 FZ_149360_P1.CPP); C++-Modus; C-Modus (VMCC=wcc386) mit #pragma aux "*" vorbereitet
// fz_149360.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x149360-0x149CAA
#include <string.h>
#ifdef __cplusplus
#include "RIVAMEM.H"



#endif
int f_1664d0(const char *p1, const char *p2, int p3);
int f_144bf0(int p1, int p2);
struct H { int a0, a4, a8, v0c, v10, v14, v18; short *p1c; };
struct E { char act; char pad1; short id; short n; short s6; short s8; unsigned char fl; unsigned char fl2; short sc; short se; int v10; int v14; struct H *p18; int v1c; int v20; int v24; int *p28; int v2c; };
extern int d_1a993d;
extern signed char d_1a9940;
extern char d_1a994b;
extern short d_1a996a;
extern int d_1a996c;
extern int d_1a99ac;
extern int d_1a9aec;
extern int d_1a9af0;
extern short d_1a9af4;
extern int d_1a9ab0;
extern int d_1a9b18;
extern int d_1c8ff4;
extern struct E *d_1cd208;
extern struct E *d_1cd210;
extern const char d_1a988c[];
extern const char d_1b8d8c[];
extern const char d_1b8d98[];
extern const char d_1b8da4[];
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define S(p,o) (*(short *)((char *)(p)+(o)))
#define RET(K) { d_1a996c = K; return K; }
int fixmul(int a, int b);
#pragma aux fixmul = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] value [eax] modify [edx];
int muldiv(int a, int b, int c);
#pragma aux muldiv = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] value [eax] modify [edx];
#ifndef __cplusplus
#pragma aux f_149360 "*";
#pragma aux f_1493c0 "*";
#pragma aux f_149410 "*";
#pragma aux f_149470 "*";
#pragma aux f_149524 "*";
#pragma aux f_149640 "*";
#pragma aux f_1496d4 "*";
#pragma aux f_149728 "*";
#pragma aux f_1497d8 "*";
#pragma aux f_149a14 "*";
#pragma aux f_149a88 "*";
#pragma aux f_149b44 "*";
#pragma aux f_149b9c "*";
#endif
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_149470
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet den Zustand von 3D-Szenenobjekten in der aktuellen Szene (d_1c01d0) um, deren
 *   Objekt-ID mit id übereinstimmt (oder für alle Objekte der Szene, wenn id == -1). Dabei wird das Zustandsfeld
 *   +0x02 entsprechend dem Modus mode (0 = ausschalten, 1 = einschalten, 2 = umschalten/togglen) geändert und
 *   über f_023c60 die Sichtbarkeit bzw. Darstellung des zugehörigen 3D-Knotens aktualisiert.
 * - Eingaben:
 *   - id: Kennung des gesuchten Szenenobjekts (oder -1 für alle Einträge der Szene).
 *   - mode: Schaltmodus (0 = auf 0 setzen, 1 = auf 1 setzen, 2 = zwischen 0 und 1 wechseln).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c01d0: Zeiger auf die aktuelle 3D-Szenenstruktur (Anzahl der Objekte in +0x71, Objektliste in +0x9b).
 *   - p: Zeiger auf den aktuellen 15-Byte-Objekteintrag.
 === Ende Beschreibung === */
int f_149470(short a)
{
    struct E *p;
    struct E *candidate;
    struct E *found;
    short want;
    int count;

    found = 0;
    count = d_1a99ac;
    p = d_1cd210;
    ++count;
    goto first_check;
first_loop:
    if (a != p->id) goto first_next;
    if (!p->n) goto first_next;
    if (!p->act) goto first_next;
    found = p;
    goto first_done;
first_next:
    p = (struct E *)((char *)p + 0x30);
first_check:
    --count;
    if (count != 0) goto first_loop;
first_done:
    if (found == 0) RET(0xf013);

    count = d_1a99ac;

    p = d_1cd210;

    want = found->n + 1;

    candidate = 0;

    ++count;

    goto second_check;
second_loop:
        if (a == p->id) {
            if (want == p->n) {
                candidate = p;
                goto second_done;
            }
            if (p->n == (short)1) candidate = p;
        }
    p = (struct E *)((char *)p + 0x30);
second_check:
    --count;
    if (count != 0) goto second_loop;
second_done:
    if (candidate == 0) RET(0xf015);

    found->act = 0;
    candidate->act = 1;
    d_1a994b = 0;
    RET(0);
}
//@ f_149524
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft vor dem Auslösen einer Objektbewegung (z. B. Tür oder bewegliche Wand), ob ein
 *   Szenenobjekt mit der Kennung id bereits eine aktive Bewegung in der Bewegungsliste (+0xa7) ausführt, und
 *   startet andernfalls für alle passenden Objekte die Bewegung über f_149640.
 * - Eingaben:
 *   - id: Objekt-ID in der 3D-Szene (oder -1 für alle passenden Objekte).
 *   - mode: Gewünschter Bewegungsmodus (0 = zurück zum Ursprung, 1 = zur Zielposition, 2 = Richtung umkehren).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c01d0: Aktuelle 3D-Szene (+0x74 = Anzahl aktiver Bewegungen, +0xa7 = Array aktiver
 *     28-Byte-Bewegungseinträge).
 === Ende Beschreibung === */
int f_149524(short a)
{
    struct E *e;
    struct H *h;
    int i;
    int found;
    int step;
    int delta;

    if ((signed char)d_1a993d == (signed char)0) RET(0xf002);
    if (d_1a996a != (short)-1) RET(0xf016);

    i = d_1a99ac;
    found = 0;
    e = d_1cd210;
    ++i;
    goto check;
loop:
    if (a == e->id && e->p18 != 0) {
        found = 1;
        goto done;
    }
    e++;
check:
    --i;
    if (i != 0) goto loop;
done:
    if (!found) RET(0xf013);

    h = e->p18;
    if (h == 0) RET(0xf017);

    if (e->v10 != 0) I(&d_1a9af4, 0) = 0;
    else I(&d_1a9af4, 0) = h->v0c;
    if (d_1a9b18 < 0) d_1a9b18 = -d_1a9b18;
    step = h->v10;
    delta = I(&d_1a9af4, 0) - e->v10;
    if (delta < 0) {
        step = -step;

        d_1a9b18 = -d_1a9b18;

    }
    d_1a9aec = step;

    d_1cd208 = e;

    d_1a996a = a;

    d_1a994b = 0;
    d_1a9af0 = 0;
    e->fl |= 0x20;
    RET(0);
}
//@ f_149640
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Legt für ein konkretes 3D-Szenenobjekt obj einen neuen Interpolationsauftrag im
 *   Bewegungsarray (+0xa7, bis zu 64 gleichzeitige Einträge) an. Sie bestimmt aus dem aktuellen
 *   Animationsfortschritt (+0x1f) und dem Zielmodus mode, ob vorwärts (+1) oder rückwärts (-1) interpoliert
 *   wird, und trägt Objektzeiger, 3D-Actor-Knoten (+0x1b), Schrittweite (+0x17) und Endwert (0x10000 im
 *   16.16-Festkommaformat bzw. 0) in den freien Slot ein.
 * - Eingaben:
 *   - obj: Zeiger auf den Szenenobjekt-Datensatz.
 *   - mode: Bewegungsmodus (0 = rückwärts nach 0, 1 = vorwärts nach 0x10000, 2 = umschalten, 3 = sofortiger
 *     Sprung ans Ende).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - slot: Freier 28-Byte-Eintrag im Array d_1c01d0->+0xa7.
 *   - step: Festkomma-Geschwindigkeit aus obj->+0x17 (bei mode == 3 direkt 0x10000 bzw. -0x10000).
 === Ende Beschreibung === */
int f_149640(short a)
{
    struct E *e;
    struct H *h;
    int found;
    int count;
    if ((signed char)d_1a993d == (signed char)0) return 0;
    count = d_1a99ac;
    e = d_1cd210;
    found = 0;
    ++count;
    goto check;
loop:
    if (a == e->id && e->p18 != 0) { found = 1; goto done; }
    ++e;
check:
    --count;
    if (count != 0) goto loop;
done:
    if (!found) return 0;
    h = e->p18;
    if (e->fl & 0x20) {
        if (d_1a9aec > 0) return 3;
        return 4;
    }
    if (e->v10 >= 0 && e->v10 >= h->v0c) return 1;
    return 2;
}
//@ f_1496d4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht die Liste der 3D-Szenenobjekte (d_1cd210, Anzahl d_1a99ac) nach dem ersten
 *   aktiven Eintrag (e->act != 0) mit der Objekt-ID a und gibt dessen Zustands-/Variantennummer e->n zurück.
 * - Eingaben: a (gesuchte Objekt-ID).
 * - Rückgabewert: Die 16-Bit-Zustandsnummer (unsigned short)e->n des gefundenen aktiven Objekts oder 0, falls
 *   die Engine inaktiv ist (d_1a993d == 0) oder kein passendes Objekt gefunden wurde.
 * - Wichtige Variablen: e (Laufzeiger über d_1cd210), found (Suchflag).
 === Ende Beschreibung === */
int f_1496d4(short a)
{
    struct E *e;
    int found;
    int i;
    if ((signed char)d_1a993d == (signed char)0) return 0;
    i = d_1a99ac;
    e = d_1cd210;
    found = 0;
    ++i;
    goto check;
loop:
    if (e->act && a == e->id) { found = 1; goto done; }
    ++e;
check:
    --i;
    if (i != 0) goto loop;
done:
    if (!found) return 0;
    return (unsigned short)e->n;
}
//@ f_149728
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht in der Szenenobjektliste (d_1cd210, Anzahl d_1a99ac) das Objekt mit der Kennung a
 *   und schreibt dessen 3D-Positionskoordinaten (e->v1c, e->v20, e->v24) in die drei übergebenen Ausgabezeiger
 *   p2, p3 und p4.
 * - Eingaben: a (Objekt-ID), p2 (Ausgabezeiger für X), p3 (Ausgabezeiger für Y), p4 (Ausgabezeiger für Z).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 bei nicht initialisierter Szene, 0xf005 bei einem Nullzeiger-Parameter
 *   oder 0xf013, wenn die Objekt-ID a nicht existiert.
 * - Wichtige Variablen: e (Laufzeiger über d_1cd210), d_1a996c (globaler Fehlercode).
 === Ende Beschreibung === */
int f_149728(short a, int *p2, int *p3, int *p4)
{
    struct E *e;
    int i;
    int *y;
    y = p3;
    if (!*(volatile signed char *)&d_1a993d) RET(0xf002); // volatile haelt Befehlsplanung mit y = p3 am Funktionseingang wie im Original
    if ((*&p2) == 0 || p3 == 0 || p4 == 0) RET(0xf005);
    i = 0;
    e = d_1cd210;
    if (d_1a99ac > 0) {
        do {
            if (e->id == a) break;
            i++;
            e++;
        } while (i < d_1a99ac);
    }
    if (i >= d_1a99ac) RET(0xf013);
    *p2 = e->v1c;
    *y = e->v20;
    *p4 = e->v24;
    RET(0);
}
//@ f_1497d8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft in der 3D-Welt, ob ein gegebener 2D-Punkt (x, y in der Horizontalebene) innerhalb
 *   der Grundfläche eines bestimmten Welt-Mesh-Objekts vom Typ 'E' mit dem Namen name liegt (z. B. zur
 *   Erkennung, ob die Heldengruppe in einer Auslösezone, auf einer Brücke oder in einem Raumsegment steht). Dazu
 *   transformiert sie den Punkt in das lokale Koordinatensystem des Actors (f_031980 / f_1588f0) und führt
 *   anschließend einen 2D-Strahlenschnitt-Test (Point-in-Polygon / Jordan-Kurvensatz) über alle Dreiecke des
 *   zugehörigen BRender-Modells durch.
 * - Eingaben:
 *   - name: Name des gesuchten 3D-Actors (z. B. Zonen- oder Raumname).
 *   - x: X-Koordinate im 16.16-Festkommaformat (br_scalar).
 *   - y: Y-Koordinate im 16.16-Festkommaformat (br_scalar).
 * - Rückgabewert: 1, wenn die ungerade Anzahl von Kantenüberschneidungen zeigt, dass der Punkt im Inneren des
 *   Mesh-Umrisses liegt, sonst 0.
 * - Wichtige Variablen:
 *   - d_1c01d0: Aktuelle 3D-Szene, deren Objektbaum ab +0x77 nach dem Namen name (f_02c6c0) durchsucht wird.
 *   - v: Transformierter lokaler 3D-Punkt (vx, vy, vz).
 *   - inside: Paritätszähler (0 oder 1), der bei jedem Schnitt eines Dreiecks-Kantenabschnitts mit dem positiven
 *     X-Strahl ab (vx, vy) umgeschaltet wird.
 === Ende Beschreibung === */
int f_1497d8(short *out, int x, int y)
{
    
    
    struct Vertex908 { int x, y, z; };
    struct Ref908 { unsigned short vertex; unsigned short unused[5]; };
    struct Polygon908 { unsigned char flags, count; unsigned short vertex[23]; };
    char *node, *world;
    Ref908 *refs;
    Vertex908 *vertices, *previous, *current;
    Polygon908 *polygon;
    unsigned short *index;
    int polygons, face, high, edge, edges, low, crossing;
    int savedX908;


    if (!*(volatile signed char *)&d_1a993d) return 0xf002; // volatile haelt Befehlsplanung am Funktionseingang wie im Original
    if (out == 0) return 0xf005;
    node=(char *)d_1c8ff4;
    if(node==0){*out=0;return 0xf01a;}
    savedX908=x;
    int savedY908=y;
    while(node) {
        world=(char *)I(node,0x28);
        if(world && savedX908>=I(world,0x20) && savedX908<=I(world,0x2c) && savedY908>=I(world,0x28) && savedY908<=I(world,0x34) && *((char *)I(world,0)+2)=='E') {
            refs=(Ref908 *)I(world,0x40);
            vertices=(Vertex908 *)I(world,0x38);
            polygon=(Polygon908 *)I(world,0x44);
            polygons=*(unsigned short *)(world+0xa);
            face=0;
            while(face<polygons) {
                index=(unsigned short *)((char *)polygon+2);
                edges=*((unsigned char *)polygon+1);
                low=0x7fffffff; high=(int)0x80000000;
                current=vertices+refs[index[edges-1]].vertex;
                edge=0;
                while(edge<edges) {
                    previous=current;
                    current=vertices+refs[*index].vertex;
                    if((savedY908>=previous->z && savedY908<=current->z) || (savedY908>=current->z && savedY908<=previous->z)) {
                        if(previous->z!=current->z) {
                            crossing=previous->x+muldiv(savedY908-previous->z, current->x-previous->x, current->z-previous->z);
                            if(crossing<low)low=crossing;
                            if(crossing>high)high=crossing;
                        }
                    }
                    edge++; index++;
                }
                if(low<savedX908 && savedX908<high){*out=S(node,2);return 0;}
                face++; polygon++;
            }
        }
        node=(char *)I(node,0x2c);
    }
    *out=0;return 0xf01a;
}




//@ f_149a14
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet für alle Szenenobjekte in d_1cd210 (d_1a99ac Einträge), deren Kennung mit a
 *   übereinstimmt, das Aktivierungsbit enabled (Bit 1 in e->fl2) entsprechend dem Parameter on (0 = ausschalten,
 *   != 0 = einschalten) um.
 * - Eingaben: a (Objekt-ID), on (gewünschter Schaltzustand).
 * - Rückgabewert: 0 wenn genau ein Objekt geschaltet wurde, 0xf014 wenn mehrere Objekte dieselbe ID a trugen,
 *   0xf013 wenn kein Objekt gefunden wurde, oder 0xf002 wenn d_1a993d == 0 ist.
 * - Wichtige Variablen: e (Laufzeiger über d_1cd210), cnt (Anzahl der gefundenen Objekte mit ID a).
 === Ende Beschreibung === */
int f_149a14(int a, int on)
{
    struct Flag908 { unsigned low:1, enabled:1, high:6; };
    int i;
    struct E *e;
    int cnt;
    if ((signed char)d_1a993d == (signed char)0) {
        RET(0xf002);
    } else {
        i = d_1a99ac;
        cnt = 0;
        e = d_1cd210;
        ++i;
        goto f149a14_check;
f149a14_loop:
            if ((short)a == e->id) {
                ++cnt;
                if (on)
                    ((Flag908 *)&e->fl2)->enabled=1;
                else
                    ((Flag908 *)&e->fl2)->enabled=0;
            }
            ++e;
f149a14_check:
        if (--i != 0) goto f149a14_loop;
        if (cnt == 0) RET(0xf013);
        if (cnt == 1) RET(0);
        RET(0xf014);
    }
}
//@ f_149a88
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreitet alle aktiven Bewegungsaufträge im Array d_1c01d0->+0xa7 um ticks Zeitschritte
 *   voran, begrenzt den Fortschrittswert (+0x14) auf das Intervall [0, 0x10000], aktualisiert den Status im
 *   zugehörigen Szenenobjekt und berechnet über f_149b44 die neue 3D-Transformationsmatrix des bewegten
 *   BRender-Actors. Erreicht eine Bewegung ihr Ziel (0 oder 0x10000), wird der Auftrag aus dem aktiven Slot
 *   entfernt.
 * - Eingaben: ticks (Anzahl der verstrichenen Zeitschritte).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - slot: Aktiver 28-Byte-Bewegungseintrag in d_1c01d0->+0xa7.
 *   - val: Neuer 16.16-Festkomma-Interpolationsfaktor (0 bis 0x10000).
 === Ende Beschreibung === */
int f_149a88(void)
{
    int target;
    int current;
    struct E *e;
    int value;

    target = d_1a9aec;
    current = d_1a9af0;
    e = d_1cd208;
    if (e == 0) goto done;
    if (d_1a996a == (short)-1) goto done;

    if (current != target) {
        int delta = d_1a9b18;
        current += fixmul(delta, d_1a9ab0);
        if (target > 0 && current > target) goto clamp;
        if (target < 0 && current < target) goto clamp;
        goto unclamp;
clamp:
        current = target;
unclamp:;
    }
    value = fixmul(current, d_1a9ab0) + e->v10;
    if ((target > 0 && value > *(int *)&d_1a9af4) ||
        (target < 0 && value < *(int *)&d_1a9af4)) {
        unsigned char flag = e->fl;
        e->v10 = *(int *)&d_1a9af4;
        flag &= 0xdf;
        e->fl = flag;
        (*(volatile unsigned short *)&d_1a996a) = 0xffff; // volatile haelt Schreibreihenfolge vor e = 0 wie im Original
        e = 0;
    } else {
        e->v10 = value;
    }
done:
    d_1cd208 = e;
    (*(volatile int *)&d_1a9af0) = current; // volatile haelt Schreibreihenfolge zwischen d_1cd208 und d_1a9aec wie im Original
    d_1a9aec = target;
    return value;
}
//@ f_149b44
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet für einen aktiven Bewegungseintrag slot die aktuelle 3x4-Transformationsmatrix
 *   des 3D-Actors (actor->+0x28) neu: Zuerst wird die Basisposition des Objekts gesetzt (f_1584f0), anschließend
 *   werden die drei Rotationswinkel um den aktuellen Fortschrittsfaktor skaliert (f_158ed8, f_1583b0) und
 *   zuletzt der ebenfalls mit dem Fortschrittsfaktor skalierte Translationsvektor aufaddiert (f_158530).
 * - Eingaben: slot (Zeiger auf den 28-Byte-Bewegungseintrag).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - mat: Zeiger auf die BRender-3x4-Matrix des bewegten Actors (actor + 0x28).
 *   - obj: Zeiger auf die Bewegungsdefinition mit Translationsvektor (+0x03..+0x0b) und Rotationswinkeln
 *     (+0x0f..+0x13).
 === Ende Beschreibung === */
int f_149b44(void)
{
    struct E *e;
    if (d_1cd208 == 0 || d_1a996a == (short)-1) return 0xf016;
    e = d_1cd208;
    e->v10 = I(&d_1a9af4, 0);
    d_1cd208 = 0;
    e->fl &= 0xdf;
    (*(unsigned short *)&d_1a996a) = 0xffff;
    d_1a994b = 0;
    return 0;
}
//@ f_149b9c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet bei schaltbaren Wanddisplay-, Schalter- oder Texturobjekten (Liste +0xa3, Anzahl
 *   in +0x73) mit der Kennung id zwischen zwei BRender-Materialien/Texturen (+0x09 und +0x0d) um und ruft
 *   f_1573f0 zum Aktualisieren des Materials im 3D-Renderer auf.
 * - Eingaben:
 *   - id: Objekt-ID (oder -1 für alle umschaltbaren Texturobjekte der Szene).
 *   - mode: Schaltmodus (0 = Grundtextur, 1 = Alternativtextur, 2 = umschalten).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p (Laufzeiger über die 17-Byte-Einträge in d_1c01d0->+0xa3).
 === Ende Beschreibung === */
int f_149b9c(int p1, int p2)
{
    int found;
    int i;
    struct E *e;
    struct H *h;
    if ((signed char)d_1a993d == (signed char)0) return d_1a996c = 0xf002;
    if (d_1a9940 == (signed char)0) return d_1a996c = 0xf00c;
    if (p1 == 0) return d_1a996c = 0xf005;
    found = 0;
    i = 0;
    e = d_1cd210;
    if (0 < d_1a99ac) {
        do {
            h = e->p18;
            if (h != 0 && h->v18 != 0 && h->p1c != 0 && e->p28 != 0) {
                if (f_144bf0(*e->p28, p1) == 0) {
                    if (p2 != 0 && h->p1c != 0) {
                        e->s6 = 0;
                        e->sc = *h->p1c;
                        e->fl |= 0x40;
                    } else {
                        e->fl &= 0xbf;
                    }
                    found = 1;
                }
            }
            i++;
            e++;
        } while (i < d_1a99ac);
    }
    if (found == 0) return d_1a996c = 0xf012;
    return d_1a996c = 0;
}
