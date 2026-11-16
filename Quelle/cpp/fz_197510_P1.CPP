/* === Beschreibung (Katalog) ===
 * Einheit fz_197510 (0x197510 - 0x198c50)
 *
 * Überblick
 * Diese Einheit enthält die komplette 3D-Mesh-Vorbereitung (BrModelUpdate / prepmesh.c aus BRender): das
 * Berechnen von Flächen- und Vertex-Normalen, das Sortieren und Gruppieren von Dreiecksflächen und Eckpunkten
 * nach Materialien und Glättungsgruppen (Smoothing Groups), den Aufbau der Kantentabelle sowie die Berechnung
 * von Hüllkugelradius und Bounding-Box eines 3D-Modells.
 === Ende Beschreibung === */
// P3 14/21 gleich (suche.py 30.10.2026, Basis fz_197510_P1.CPP)
// OPT -5r -oneatx -zp1 -s
// P1 0/21 gleich
// CC wcc386
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma intrinsic(sqrt)
#define W16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define S16(p,o) (*(short *)((char *)(p) + (o)))
#define I32(p,o) (*(int *)((char *)(p) + (o)))
#define U32(p,o) (*(unsigned *)((char *)(p) + (o)))
#define B8(p,o) (*(unsigned char *)((char *)(p) + (o)))
struct BF { unsigned short b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1,b8:1,b9:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1; };
#define FLG(p,bit,m) (W16(p,0x1c) & (m))
struct te { struct te *next; short first; short last; char other; char pad[3]; };
typedef int (*CMP)(int *, int *);
long IFixedMul(long a, long b);
#pragma aux IFixedMul = "imul ebx" "shrd eax,edx,16" parm nomemory [eax] [ebx] modify nomemory [edx];
long IFixedDiv(long a, long b);
#pragma aux IFixedDiv = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm nomemory [edx] [ebx] modify nomemory [eax];
long IFixedSqr3(long a, long b, long c);
#pragma aux IFixedSqr3 = "imul eax" "xchg ebx,eax" "mov ecx,edx" "imul eax" "add ebx,eax" "adc ecx,edx" "mov eax,esi" "imul eax" "add eax,ebx" "adc edx,ecx" "shrd eax,edx,16" parm nomemory [eax] [ebx] [esi] modify nomemory [ebx ecx edx];
long Mac15(long b, short a, short c, long d, short e, long f);
#pragma aux Mac15 = "cwde" "imul edx" "shrd eax,edx,15" "xchg ecx,eax" "cwde" "imul ebx" "shrd eax,edx,15" "add ecx,eax" "mov eax,esi" "cwde" "imul edi" "shrd eax,edx,15" "add eax,ecx" parm nomemory [edx] [ax] [cx] [ebx] [si] [edi] modify nomemory [ecx];
int f_188404(int p1, int p2, int p3);
int f_18850c(int p1);
int f_199410(int p1);
void f_199484(int p1);
int f_16d3d0(int p1);
void f_197390(char *, ...);
void f_1994e0(void *base, int n, int size, CMP cmp);
int f_16d4fc(int, ...);
extern float d_1ba8d4;
extern float d_1ba8d8;
extern const char d_1ba8dc[];
extern int d_1b52a4;
extern char *d_1d4d34;
extern struct te **d_1d4d38;
extern struct te *d_1d4d3c;
extern void (*d_1d4990)(int, unsigned short);
extern void (*d_1d4994)(int, unsigned short);
#pragma aux f_188404 "*";
#pragma aux f_18850c "*";
#pragma aux f_199410 "*";
#pragma aux f_199484 "*";
#pragma aux f_16d3d0 "*";
#pragma aux f_16d4fc "*";
#pragma aux f_197390 "*";
#pragma aux f_1994e0 "*";
#pragma aux f_197510 "*";
#pragma aux f_1975a0 "*";
#pragma aux f_1975c8 "*";
#pragma aux f_19761c "*";
#pragma aux f_197708 "*";
#pragma aux f_1977a4 "*";
#pragma aux f_1979c0 "*";
#pragma aux f_197a40 "*";
#pragma aux f_197ac0 "*";
#pragma aux f_197c88 "*";
#pragma aux f_197e18 "*";
#pragma aux f_197e98 "*";
#pragma aux f_197fb8 "*";
#pragma aux f_19803c "*";
#pragma aux f_198574 "*";
#pragma aux f_1987fc "*";
#pragma aux f_1988bc "*";
#pragma aux f_198978 "*";
#pragma aux f_1989e4 "*";
#pragma aux f_198a48 "*";
#pragma aux f_198c50 "*";
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_197510
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197510
 * - Aufgabe im Spiel: Sucht beim Aufbau der Kantentabelle eines 3D-Modells in der Hash-Kette d_1d4d38[last], ob
 *   bereits die entgegengesetzt gerichtete Halbkante (last -> first) existiert und noch ungekoppelt ist (other
 *   == 0). Wird sie gefunden, markiert die Funktion sie als beidseitig belegt (other = 1) und gibt ihren
 *   Kantenindex zurück; andernfalls legt sie am Ende des Kanten-Arrays d_1d4d3c einen neuen Kanteneintrag (first
 *   -> last) an, hängt ihn in d_1d4d38[first] ein und erhöht den Kantenzähler d_1b52a4.
 * - Eingaben: Start-Vertexindex (first) und End-Vertexindex (last) der Dreieckskante.
 * - Rückgabewert: Der Index der gefundenen oder neu angelegten Kante.
 * - Wichtige Variablen:
 *   - Globale Hash-Tabelle d_1d4d38, Kanten-Array d_1d4d3c und Kantenzähler d_1b52a4.
 === Ende Beschreibung === */
int f_197510(short first, short last)
{
    struct te *tep;
    struct te **h;
    for (tep = d_1d4d38[last]; tep; tep = tep->next) {
        if (tep->last == first && tep->other == 0) {
            tep->other = 1;
            return tep - d_1d4d3c;
        }
    }
    tep = d_1d4d3c + d_1b52a4;
    tep->first = first;
    tep->last = last;
    tep->other = 0;
    tep->next = d_1d4d38[first];
    d_1d4d38[first] = tep;
    return d_1b52a4++;
}
//@ f_1975a0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1975a0
 * - Aufgabe im Spiel: Vergleichsfunktion für qsort (f_1994e0), die zwei Zeiger auf Dreiecksflächen anhand ihrer
 *   Material-Adresse an Offset +0x0c aufsteigend vergleicht.
 * - Eingaben: Zwei Zeiger (p1, p2) auf Flächenzeiger.
 * - Rückgabewert: 1, -1 oder 0 je nach Größenverhältnis der Materialzeiger.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1975a0(int *p1, int *p2)
{
    int *a = (int *)*p1;
    int *b = (int *)*p2;
    if (U32(a, 0xc) > U32(b, 0xc)) return 1;
    if (U32(a, 0xc) < U32(b, 0xc)) return -1;
    return 0;
}
//@ f_1975c8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1975c8
 * - Aufgabe im Spiel: Vergleichsfunktion für die Mesh-Vorbereitung, die zwei temporäre Vertex-Einträge
 *   (PrepXYZ690) ausschließlich anhand ihrer 3D-Raumkoordinaten (v->p[0..2]) lexikographisch vergleicht, damit
 *   räumlich identische Eckpunkte für die Berechnung der Smoothing-Group-Normalen zusammengefasst werden können.
 * - Eingaben: Zwei Zeiger (p1, p2) auf PrepVertex-Zeiger.
 * - Rückgabewert: 0 bei identischem Vertex-Zeiger oder gleichen Koordinaten, sonst 1 oder -1.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_1975c8(int *p1, int *p2)
{
    struct VertexXYZ690 { long p[3]; };
    struct PrepXYZ690 { unsigned material; struct VertexXYZ690 *v; };
    const struct PrepXYZ690 *tv1=(const struct PrepXYZ690 *)*p1;
    const struct PrepXYZ690 *tv2=(const struct PrepXYZ690 *)*p2;
    int i;
    if(tv1->v==tv2->v) return 0;
    for(i=0;i<3;i++) {
        if(tv1->v->p[i]>tv2->v->p[i]) return 1;
        if(tv1->v->p[i]<tv2->v->p[i]) return -1;
    }
    return 0;
}

//@ f_19761c
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x19761c
 * - Aufgabe im Spiel: Vergleichsfunktion (TVCompare_MXYZUVN), die zwei vorbereitete Eckpunkte nacheinander nach
 *   Materialzeiger, 3D-Position (p[0..2]), Texturkoordinaten (map[0..1]) und berechneter Vertex-Normale
 *   (n[0..2]) vergleicht, um doppelte Eckpunkte mit exakt gleichen Attributen zusammenzulegen.
 * - Eingaben: Zwei Zeiger (p1, p2) auf PrepVertex-Zeiger.
 * - Rückgabewert: 1, -1 oder 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
/* BRender-Verwandter: Referenz/brender/v1.3.2/core/v1db/prepmesh.c,
 * TVCompare_MXYZUVN. Riva: Material und Vertex direkt, Normal bei+20. */
struct BVertex690 { long p[3]; long map[2]; };
struct BPrep690 { unsigned material; struct BVertex690 *v; char unknown08[12]; long n[3]; };
int f_19761c(int *p1, int *p2)
{
    const struct BPrep690 *tv1=(const struct BPrep690 *)*p1;
    const struct BPrep690 *tv2=(const struct BPrep690 *)*p2;
    int i;
    if(tv1->material>tv2->material) return 1;
    if(tv1->material<tv2->material) return -1;
    if(tv1->v!=tv2->v) {
        for(i=0;i<3;i++) {
            if(tv1->v->p[i]>tv2->v->p[i]) return 1;
            if(tv1->v->p[i]<tv2->v->p[i]) return -1;
        }
        for(i=0;i<2;i++) {
            if(tv1->v->map[i]>tv2->v->map[i]) return 1;
            if(tv1->v->map[i]<tv2->v->map[i]) return -1;
        }
    }
    for(i=0;i<3;i++) {
        if(tv1->n[i]>tv2->n[i]) return 1;
        if(tv1->n[i]<tv2->n[i]) return -1;
    }
    return 0;
}

//@ f_197708
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197708
 * - Aufgabe im Spiel: Schnellere Vergleichsfunktion für vorbereitete Eckpunkte (bei gesetztem
 *   MODF_DONT_WELD-Flag model->flags & 1), die zwei Einträge nach Material (A[0]), Original-Vertex-Zeiger (A[1])
 *   und Vertex-Normale (A[5..7]) vergleicht, ohne die Koordinaten unterschiedlicher Original-Vertices
 *   miteinander zu verschmelzen.
 * - Eingaben: Zwei Zeiger (p1, p2) auf PrepVertex-Zeiger.
 * - Rückgabewert: 1, -1 oder 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_197708(int *p1, int *p2)
{
    int i;
    {
        int *A = (int *)*p1;
        int *B = (int *)*p2;
        if ((unsigned)A[0] > (unsigned)B[0]) return 1;
        if ((unsigned)A[0] < (unsigned)B[0]) return -1;
        if ((unsigned)A[1] > (unsigned)B[1]) return 1;
        if ((unsigned)A[1] < (unsigned)B[1]) return -1;
        for (i = 0; i < 3; i++) {
            if (A[5 + i] > B[5 + i]) return 1;
            if (A[5 + i] < B[5 + i]) return -1;
        }
    }
    return 0;
}
//@ f_1977a4
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1977a4
 * - Aufgabe im Spiel: Berechnet aus den 3D-Koordinaten dreier Dreiecks-Eckpunkte (p1, p2, p3) über das
 *   Kreuzprodukt der Kantenvektoren u = p2 - p1 und v = p3 - p1 sowie eine Fließkomma-Normierung (sqrt) den
 *   normierten 16-Bit-Flächennormalenvektor (p4[0..2]) und anschließend per Festkomma-Skalarprodukt (Mac15) den
 *   Ebenengleichungs-Abstandswert d (*p5). Entartet das Dreieck zur Länge 0, wird die Standardnormale (0, 0,
 *   0x7fff) eingetragen.
 * - Eingaben: Zeiger auf die drei Eckpunkt-Koordinatenvektoren (p1, p2, p3), Zielzeiger für die
 *   16-Bit-Flächennormale (p4) und Zielzeiger für die Ebenendistanz (p5).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Differenzvektoren (u, v), skalierte Fließkomma-Kanten (ax..bz), Kreuzprodukt-Komponenten (nx, ny,
 *     nz) und Vektorlänge (l).
 *   - Globale Skalierungsfaktoren d_1ba8d4 und d_1ba8d8 (32768.0f).
 === Ende Beschreibung === */
void f_1977a4(int *p1, int *p2, int *p3, short *p4, int *p5)
{
    struct Vector { long v[3]; } u, v;
    float ty, l, ay, bx, nz, ry, ax, rx, nx, bz, az, tx, tz, rz, ny[1], by;
    int uz;
    u.v[0] = p2[0]-p1[0];
    u.v[1] = p2[1]-p1[1];
    uz = (p2[2] & 0) ? 0 : p2[2]; /* haelt die Registerzuteilung wie im Original */
    u.v[2] = uz-p1[2];
    v.v[0] = p3[0]-p1[0];
    v.v[1] = p3[1]-p1[1];
    v.v[2]=((p3[2]&0)?0:p3[2])-p1[2]; /* haelt die Registerzuteilung wie im Original */
    ax = u.v[0] * d_1ba8d4;
    ay = u.v[1] * d_1ba8d4;
    az = u.v[2] * d_1ba8d4;
    bx = v.v[0] * d_1ba8d4;
    by = v.v[1] * d_1ba8d4;
    bz = v.v[2] * d_1ba8d4;
    nx = ay*bz-az*by; ((char *)&nx)[0]=((char *)&nx)[0]; ((char *)&nx)[1]=((char *)&nx)[1]; ((char *)&nx)[2]=((char *)&nx)[2]; ((char *)&nx)[3]=((char *)&nx)[3]; /* haelt die Registerzuteilung wie im Original */
    ny[0] = az*bx-ax*bz;
    nz = ax*by-ay*bx; ((char *)&nz)[0]=((char *)&nz)[0]; /* haelt die Registerzuteilung wie im Original */
    l = sqrt(nx*nx+ny[0]*ny[0]+nz*nz); ((short *)&l)[0]=((short *)&l)[0]; /* haelt die Registerzuteilung wie im Original */
    if(l != 0.0f) {
        l = 1.0/l;
        nx *= l; ny[0] *= l; nz *= l;
        tx=nx*d_1ba8d8; if(tx>=d_1ba8d8) rx=32767.0f; else rx=tx; p4[0]=rx;
        ty=ny[0]*d_1ba8d8; if(ty>=d_1ba8d8) ry=32767.0f; else ry=ty; p4[1]=ry;
        tz=nz*d_1ba8d8; if(tz>=d_1ba8d8) rz=32767.0f; else rz=tz; p4[2]=rz; ((char *)&rz)[0]=((char *)&rz)[0]; ((char *)&rz)[1]=((char *)&rz)[1]; ((char *)&rz)[2]=((char *)&rz)[2]; ((char *)&rz)[3]=((char *)&rz)[3]; /* haelt die Registerzuteilung wie im Original */
    } else {
        p4[0]=0; p4[1]=0; p4[2]=0x7fff;
    }
    { long zz,yy,xx; short z,y,x; zz=p1[2]; p1[2]=zz; z=p4[2]; p4[2]=z; p4[2]=z; /* haelt die Registerzuteilung wie im Original */ yy=p1[1]; p1[1]=yy; y=p4[1]; p4[1]=y; /* haelt die Registerzuteilung wie im Original */ xx=p1[0]; x=p4[0];
      *p5=Mac15(xx,x,y,yy,z,zz); }
}
//@ f_1979c0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1979c0
 * - Aufgabe im Spiel: Durchläuft alle ungeordneten Original-Dreiecksflächen (I32(p1, 8), Anzahl W16(p1, 0x0e))
 *   eines 3D-Modells und berechnet für jede Fläche über f_1977a4 anhand der Original-Vertices (I32(p1, 4)) die
 *   Flächennormale und den Ebenenabstand.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokaler Flächenzeiger (f) und Vertex-Array-Basis (v).
 === Ende Beschreibung === */
void f_1979c0(int p1)
{
    unsigned short *f, *p4;
    int v, i;
    v = I32(p1, 4);
    f = (unsigned short *)I32(p1, 8);
    p4 = f + 10;
    for (i = 0; i < (int)W16(p1, 0xe); ) {
        i++;
        f_1977a4((int *)(f[0] * 0x20 + v), (int *)(f[1] * 0x20 + v), (int *)(f[2] * 0x20 + v), (short *)p4, (int *)(f + 14));
        f += 16;
        p4 += 16;
    }
}
//@ f_197a40
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197a40
 * - Aufgabe im Spiel: Berechnet wie f_1979c0 die Flächennormalen und Ebenenabstände aller Dreiecke eines Modells
 *   neu, greift dabei jedoch auf die bereits vorbereiteten Arrays prepared_faces (I32(p1, 0x48)) und
 *   prepared_vertices (I32(p1, 0x4c)) zurück (schnelles Update bei verformten Modellen).
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokaler Zeiger auf prepared_faces (f) und Basisadresse von prepared_vertices (v).
 === Ende Beschreibung === */
void f_197a40(int p1)
{
    unsigned short *f, *p4;
    int v, i;
    v = I32(p1, 0x4c);
    f = (unsigned short *)I32(p1, 0x48);
    p4 = f + 10;
    for (i = 0; i < (int)W16(p1, 0xe); ) {
        i++;
        f_1977a4((int *)(f[0] * 0x20 + v), (int *)(f[1] * 0x20 + v), (int *)(f[2] * 0x20 + v), (short *)p4, (int *)(f + 14));
        f += 16;
        p4 += 16;
    }
}
//@ f_197ac0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197ac0
 * - Aufgabe im Spiel: Berechnet die Vertex-Normalen (prepared_vertices[v].n[0..2]) eines vorbereiteten
 *   3D-Modells neu (RegenerateVertexNormals), indem ein temporäres Akkumulator-Array (vn) im Scratchpad-Speicher
 *   (f_199410) angelegt, die Flächennormalen der angrenzenden Dreiecke (prepared_faces) auf ihre jeweils drei
 *   Eckpunkte aufaddiert und die Summenvektoren anschließend über f_16d4fc auf die Festkomma-Länge 0x7fff
 *   normiert werden.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokales Normalen-Akkumulator-Array (vn), Flächenzeiger (fp) und Vertexzeiger (vp).
 === Ende Beschreibung === */
void f_145300(void *, int, int);
#pragma aux f_145300 "*";
void f_197ac0(int p1)
{
    struct V3_197ac0 { long v[3]; };
    struct V3_197ac0 *vn, *vnp;
    char *fp, *vp;
    int f, v, c;
    long x;
    vn = (struct V3_197ac0 *)f_199410(W16(p1, 0x44) * 12);
    f_145300(vn, 0, W16(p1, 0x44) * 12);
    for (f = 1, fp = (char *)I32(p1, 0x48); f < (int)W16(p1, 0x46); f++, fp += 0x20) {
        vn[W16(fp, 0)].v[0] += I32(fp, 0x12) >> 16;
        vn[W16(fp, 0)].v[1] += I32(fp, 0x14) >> 16;
        vn[W16(fp, 0)].v[2] += I32(fp, 0x16) >> 16;
        vn[W16(fp, 2)].v[0] += I32(fp, 0x12) >> 16;
        vn[W16(fp, 2)].v[1] += I32(fp, 0x14) >> 16;
        vn[W16(fp, 2)].v[2] += I32(fp, 0x16) >> 16;
        vn[W16(fp, 4)].v[0] += I32(fp, 0x12) >> 16;
        vn[W16(fp, 4)].v[1] += I32(fp, 0x14) >> 16;
        vn[W16(fp, 4)].v[2] += I32(fp, 0x16) >> 16;
    }
    vp = (char *)I32(p1, 0x4c);
    vnp = vn;
    for (v = 0; v < (int)W16(p1, 0x44); v++, vp += 0x20, vnp++) {
        c = ((int (__cdecl *)(int, int, int))f_16d4fc)(vnp->v[0], vnp->v[1], vnp->v[2]);
        if (c > 2) {
            x = IFixedDiv(0x7fff, c);
            { struct V3_197ac0 *u_ = vn; vn = u_; } // haelt die Registerzuteilung wie im Original
            { struct V3_197ac0 *u_ = vn; vn = u_; } // haelt die Registerzuteilung wie im Original
            { char *u_ = vp; vp = u_; } // haelt die Registerzuteilung wie im Original
            S16(vp, 0x1a) = (short)IFixedMul(vnp->v[0], x);
            S16(vp, 0x1c) = (short)IFixedMul(vnp->v[1], x);
            S16(vp, 0x1e) = (short)IFixedMul(vnp->v[2], x);
        } else {
            S16(vp, 0x1a) = 0x7fff;
            S16(vp, 0x1c) = 0;
            S16(vp, 0x1e) = 0;
        }
    }
    f_199484((int)vn);
}


//@ f_197c88
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197c88
 * - Aufgabe im Spiel: Sortiert die Dreiecksflächen eines 3D-Modells nach ihrem Material (f_1975a0) und baut das
 *   Array prepared_faces (I32(p1, 0x48)) auf. Wenn das Tag-Flag (model->flags & 4) gesetzt ist, legt die
 *   Funktion zusätzlich die Zuordnungstabelle face_tags (I32(p1, 0x60)) an, die für jede sortierte Fläche ihren
 *   ursprünglichen Flächenindex speichert.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Temporäres Zeiger-Array (t) im Scratchpad-Speicher für die qsort-Sortierung (f_1994e0).
 === Ende Beschreibung === */
void f_197c88(int p1)
{
    unsigned short flags;
    int **t;
    flags = W16(p1, 0x1c);
    flags &= 2;
    if ((int)flags) {
        if (I32(p1, 0x48)) f_18850c(I32(p1, 0x48));
        W16(p1, 0x46) = W16(p1, 0xe);
        I32(p1, 0x48) = f_188404(p1, W16(p1, 0xe) << 5, 12);
    } else {
        I32(p1, 0x48) = I32(p1, 8);
        W16(p1, 0x46) = W16(p1, 0xe);
        I32(p1, 8) = f_188404(p1, W16(p1, 0xe) << 5, 5);
        memcpy((void *)I32(p1, 8), (void *)I32(p1, 0x48), W16(p1, 0xe) << 5);
    }
    {
        int **pp;
        int off, i;
        i = 0;
        off = 0;
        t = (int **)f_199410(W16(p1, 0x46) << 2);
        pp = t;
        for (; i < W16(p1, 0xe); i++) {
            *pp++ = (int *)(I32(p1, 8) + off);
            off += 0x20;
        }
    }
    f_1994e0(t, W16(p1, 0x46), 4, f_1975a0);
    flags = W16(p1, 0x1c);
    flags &= 4;
    if ((int)flags) {
        if (I32(p1, 0x60)) f_18850c(I32(p1, 0x60));
        I32(p1, 0x60) = f_188404(p1, W16(p1, 0x46) * 2, 1);
        {
            int off, i;
        off = 0;
        for (i = 0; i < W16(p1, 0x46); i++) {
            S16(I32(p1, 0x60), off) = (short)(((int)t[i] - I32(p1, 8)) >> 5);
            off += 2;
        }
        }
    }
    {
        int i, off;
        struct Block32 { int word[8]; };
        i = 0;
        off = 0;
        for (; i < W16(p1, 0x46); i++) {
            *(struct Block32 *)((char *)I32(p1, 0x48) + off) = *(struct Block32 *)t[i];
            off += 0x20;
        }
    }
    f_199484((int)t);
    flags = W16(p1, 0x1c);
    flags &= 2;
    if (!(int)flags && I32(p1, 8) != I32(p1, 0x48)) {
        f_18850c(I32(p1, 8));
        I32(p1, 8) = I32(p1, 0x48);
    }
}
//@ f_197e18
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197e18
 * - Aufgabe im Spiel: Übernimmt die Original-Dreiecksflächen eines Modells ohne Umsortierung direkt als
 *   prepared_faces (I32(p1, 0x48) = I32(p1, 8)) und füllt bei gesetztem Tag-Flag (flags & 4) das Array face_tags
 *   (I32(p1, 0x60)) mit einer einfachen Identitätsabbildung 0, 1, 2, ....
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Modellfelder prepared_faces (+0x48), nprepared_faces (+0x46) und face_tags (+0x60).
 === Ende Beschreibung === */
void f_197e18(int p1)
{
    unsigned short ft;
    int i, off;
    if (I32(p1, 0x48) != I32(p1, 8)) {
        if (I32(p1, 0x48) != 0) f_18850c(I32(p1, 0x48));
    }
    W16(p1, 0x46) = W16(p1, 0xe);
    I32(p1, 0x48) = I32(p1, 8);
    ft = W16(p1, 0x1c);
    ft &= 4;
    if ((unsigned int)ft) {
        if (I32(p1, 0x60)) f_18850c(I32(p1, 0x60));
        I32(p1, 0x60) = f_188404(p1, W16(p1, 0x46) * 2, 1);
        off = 0;
        for (i = 0; i < (int)W16(p1, 0x46); i++) {
            S16(I32(p1, 0x60), off) = (short)i;
            off += 2;
        }
    }
}
//@ f_197e98
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197e98
 * - Aufgabe im Spiel: Fasst aufeinanderfolgende Dreiecksflächen gleichen Materials in prepared_faces (I32(p1,
 *   0x48)) zu Flächengruppen (face_groups an Offset +0x54, Anzahl nface_groups an +0x50) zusammen. Jede
 *   12-Byte-Gruppe speichert das gemeinsame Material, den Startzeiger im Flächen-Array und die Anzahl der
 *   zugehörigen Dreiecke.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Der Byte-Offset des letzten geschriebenen Gruppeneintrags (i).
 * - Wichtige Variablen:
 *   - Lokale Gruppenzähler (u), Dreieckszähler je Gruppe (sv) und Schreiboffsets (i, l20).
 === Ende Beschreibung === */
int f_197e98(int p1)
{
    int i, off = 0, u, l1c, l20;
    int sv = 0;
    {
        i = 1;
        off = 0x20;
        u = i;
        for (; i < (int)W16(p1, 0x46); i++) {
            int base = *(int *)(p1 + 0x48);
            if (I32(base + off, 0xc) != I32(base + off, -0x14)) u++;
            off += 0x20;
        }
        if (I32(p1, 0x54) != 0 && W16(p1, 0x50) != u) {
        f_18850c(I32(p1, 0x54));
        I32(p1, 0x54) = 0;
        }
        if (I32(p1, 0x54) == 0) I32(p1, 0x54) = f_188404(p1, u * 12, 6);
        W16(p1, 0x50) = (unsigned short)u;
        l1c = 1;
        I32(I32(p1, 0x54), 4) = I32(p1, 0x48);
        off = 0x20;
        i = 0;
        { int jh380_; u = jh380_ ^ jh380_; }   // haelt die Registerzuteilung wie im Original
        u = 0;
        sv = 1;
        l20 = 12;
        for (; l1c < (int)W16(p1, 0x46); l1c++) {
            if (I32(I32(p1, 0x48) + off, 0xc) != I32(I32(p1, 0x48) + off, -0x14)) {
                u++;
                I32(I32(p1, 0x54), i) = I32(I32(p1, 0x48) + off, -0x14);
                S16(I32(p1, 0x54) + i, 8) = sv;
                { int u_ = i; i = u_; } // haelt die Registerzuteilung wie im Original
                { int u_ = off; off = u_; } // haelt die Registerzuteilung wie im Original
                i += 12;
                I32(I32(p1, 0x54) + l20, 4) = I32(p1, 0x48) + off;
                l20 += 12;
                sv = 0;
            }
            off += 0x20;
            sv++;
        }
    }
    I32(I32(p1, 0x54), i) = I32(I32(p1, 0x48) + off, -0x14);
    S16(I32(p1, 0x54), 8 + i) = sv;
    return i;
}
//@ f_197fb8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197fb8
 * - Aufgabe im Spiel: Berechnet für eine Teilmenge räumlich zusammenfallender Dreiecks-Eckpunkte (s bis e) die
 *   geglätteten Normalenvektoren: Stimmen die Smoothing-Group-Bitmasken (smoothing an Offset +0x10 der Fläche)
 *   zweier Einträge in mindestens einem Bit überein, wird die Flächennormale von a zum Normalen-Akkumulator von
 *   b addiert.
 * - Eingaben: Startzeiger (s) und Endzeiger (e) eines Bereichs im nach Position sortierten
 *   PrepVertex-Zeiger-Array.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Laufzeiger a und b über die Eckpunkt-Referenzen derselben 3D-Koordinate.
 === Ende Beschreibung === */
void f_197fb8(int **s, int **e)
{
    int **b, **a;
    for (b = s; b < e; b++) {
        for (a = s; a < e; a++) {
            if (W16(I32(*b, 0x10), 0x10) & W16(I32(*a, 0x10), 0x10)) {
                I32(*b, 0x14) += I32(I32(*a, 0x10), 0x12) >> 16;
                I32(*b, 0x18) += I32(I32(*a, 0x10), 0x14) >> 16;
                I32(*b, 0x1c) += I32(I32(*a, 0x10), 0x16) >> 16;
            }
        }
    }
}
struct UpVertex690 { long p[3],map[2]; unsigned char rgba[4]; unsigned short r; short n[3]; };
struct UpFace690 { unsigned short vertices[3],edges[3]; unsigned material; unsigned short smoothing; unsigned char flags,pad13; short n[3],pad1a; long d; };
struct UpModel690 {
    char *identifier; struct UpVertex690 *vertices; struct UpFace690 *faces;
    unsigned short nvertices,nfaces; long pivot[3]; unsigned short flags,pad1e;
    void *custom,*user; long radius,min[3],max[3];
    unsigned short nprepared_vertices,nprepared_faces;
    struct UpFace690 *prepared_faces; struct UpVertex690 *prepared_vertices;
    unsigned short nface_groups,nvertex_groups; void *face_groups,*vertex_groups;
    unsigned short nedges,pad5e; unsigned short *face_tags,*vertex_tags;
    unsigned long prep_flags;
};
typedef char UpVertexSize690[sizeof(struct UpVertex690)==32?1:-1];
typedef char UpFaceSize690[sizeof(struct UpFace690)==32?1:-1];

//@ f_19803c
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x19803c
 * - Aufgabe im Spiel: Erzeugt aus den vorbereiteten Dreiecksflächen eines Modells das deduplizierte Array
 *   prepared_vertices (model->prepared_vertices) samt geglätteten und normierten Vertex-Normalen, schreibt die
 *   neuen Eckpunktindizes in die Flächen (prepared_faces) zurück und legt bei Bedarf das Rückzuordnungs-Array
 *   vertex_tags an. Gibt ein neu alloziertes Array zurück, das für jeden vorbereiteten Eckpunkt dessen
 *   Materialzeiger enthält.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (model).
 * - Rückgabewert: Zeiger (ret) auf das Array der Materialzeiger je vorbereitetem Vertex (wird anschließend an
 *   f_1987fc übergeben).
 * - Wichtige Variablen:
 *   - Temporärer Scratchpad-Puffer (scratch) mit 3 * nprepared_faces Einträgen (temp_verts) und Zeiger-Array
 *     (ptrs).
 *   - Vergleichsfunktionen cmp1 (f_1975c8) und cmp2 (f_197708 oder f_19761c).
 === Ende Beschreibung === */
struct PrepVertex690 {
    unsigned material;
    struct UpVertex690 *v;
    unsigned reserved,index;
    struct UpFace690 *face;
    long n[3];
};
typedef char PrepVertexSize690[sizeof(struct PrepVertex690)==32?1:-1];
int f_19803c(struct UpModel690 *model)
{
    int n3;
    struct PrepVertex690 * rec;
    int i;
    int k;
    int a;
    struct PrepVertex690 ** ptrs;
    unsigned short ft2;
    unsigned * ret;
    int c;
    unsigned short ft;
    long x;
    void * scratch;
    CMP cmp1;
    CMP cmp2;
    int bytes;
    int idx;
    struct UpVertex690 * o;
    struct UpFace690 * face;
    int f;
    struct PrepVertex690 * temp_verts;
#define NORM690(r) c=f_16d4fc((r)->n[0],(r)->n[1],(r)->n[2]); \
    if(c>2) { x=IFixedDiv(0x7fff,c); \
      o->n[0]=(short)IFixedMul((r)->n[0],x); \
      o->n[1]=(short)IFixedMul((r)->n[1],x); \
      o->n[2]=(short)IFixedMul((r)->n[2],x); \
    } else {o->n[0]=0x7fff; o->n[1]=0; o->n[2]=0;}
    if((int)(ft=model->flags&1)) {cmp1=f_1975c8;cmp2=f_197708;}
    else {cmp1=f_1975c8;cmp2=f_19761c;}
    n3=model->nprepared_faces*3;
    bytes=model->nprepared_faces*0x6c;
    scratch=(void *)f_199410(bytes);
    memset(scratch,0,bytes);
    temp_verts=(struct PrepVertex690 *)scratch;
    ptrs=(struct PrepVertex690 **)(temp_verts+n3);
    rec=temp_verts;
    for(i=0,f=0,face=model->prepared_faces;f<model->nprepared_faces;f++,face++) {
        for(k=0;k<3;k++,i++,rec++) {
            rec->material=face->material;
            rec->v=model->vertices+face->vertices[k];
            rec->face=face;
            ptrs[i]=rec;
        }
    }
    f_1994e0(ptrs,n3,4,cmp1);
    for(k=0,a=0;k<n3-1;k++) {
        if(cmp1((int *)(ptrs+k),(int *)(ptrs+k+1))) {
            f_197fb8((int **)(ptrs+a),(int **)(ptrs+k+1));
            a=k+1;
        }
    }
    f_197fb8((int **)(ptrs+a),(int **)(ptrs+n3));
    f_1994e0(ptrs,n3,4,cmp2);
    idx=0;
    for(k=0;k<n3-1;k++) {
        ptrs[k]->index=idx;
        if(cmp2((int *)(ptrs+k),(int *)(ptrs+k+1)))idx++;
    }
    ptrs[k]->index=idx;
    idx++;
    if(model->prepared_vertices && model->nprepared_vertices!=idx) {
        f_18850c((int)model->prepared_vertices);
        model->prepared_vertices=0;
    }
    if(model->prepared_vertices==0)
        model->prepared_vertices=(struct UpVertex690 *)f_188404((int)model,idx*sizeof(*o),0xb);
    model->nprepared_vertices=(unsigned short)idx;
    o=model->prepared_vertices;
    ret=(unsigned *)f_188404((int)model,model->nprepared_vertices*4,1);
    idx=0;
    for(k=0;k<n3-1;k++) {
        if(ptrs[k]->index!=ptrs[k+1]->index) {
            *o=*ptrs[k]->v;
            NORM690(ptrs[k])
            o++;
            ret[idx]=ptrs[k]->material;
            idx++;
        }
    }
    *o=*ptrs[k]->v;
    NORM690(ptrs[k])
    ret[idx]=ptrs[k]->material;
    rec=temp_verts;
    for(f=0,face=model->prepared_faces;f<model->nprepared_faces;f++,face++) {
        for(k=0;k<3;k++,rec++) {
            face->vertices[k]=(unsigned short)rec->index;
        }
    }
    if((int)(ft=model->flags&4)) {
        if(model->vertex_tags)f_18850c((int)model->vertex_tags);
        model->vertex_tags=(unsigned short *)f_188404((int)model,model->nprepared_vertices*2,1);
        for(k=0;k<n3;k++)
            model->vertex_tags[temp_verts[k].index]=(unsigned short)(temp_verts[k].v-model->vertices);
    }
    f_199484((int)scratch);
    if(!(int)(ft2=model->flags&2)) {
        if(model->vertices)f_18850c((int)model->vertices);
        model->vertices=model->prepared_vertices;
        model->nvertices=model->nprepared_vertices;
    }
    return (int)ret;
}
#undef NORM690

//@ f_198574
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x198574
 * - Aufgabe im Spiel: Schnellere Variante von f_19803c (für Modelle mit Flag 0x10), die ohne
 *   Smoothing-Sortierung die von den vorbereiteten Flächen referenzierten Eckpunkte pro Material dedupliziert,
 *   in das neu angelegte Array prepared_vertices (I32(p1, 0x4c)) kopiert, die Flächenindizes aktualisiert und
 *   ein Array mit den Materialzeigern je Vertex zurückgibt.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Zeiger (ret) auf das Array der Materialzeiger je vorbereitetem Vertex.
 * - Wichtige Variablen:
 *   - Scratchpad-Puffer (buf) mit Hash-/Lookup-Zeigern je Original-Vertex und Datensätzen (recs).
 === Ende Beschreibung === */
void f_145300(void *, int, int);
#pragma aux f_145300 "*";
int f_198574(int p1)
{
    unsigned short ft;
    char *face, *recs, *buf;
    int *rec, *ret, *rp;
    int off, i, k, cnt;
    struct Copy198574 { int x[8]; };
    unsigned short *fp, *fe;
    cnt = 0;
    if (!(int)(ft = W16(p1, 0x1c) & 2) && I32(p1, 4) == I32(p1, 0x4c)) I32(p1, 0x4c) = cnt;
    buf = (char *)f_199410(W16(p1, 0x46) * 24 + W16(p1, 0xc) * 4);
    recs = buf + W16(p1, 0xc) * 4;
    i = 0;
    f_145300(buf, 0, W16(p1, 0xc) * 4);
    rec = (int *)recs;
    face = (char *)I32(p1, 0x48);
    for (; i < (int)W16(p1, 0x46); i++, face += 0x20) {
        rec = (int *)(recs + cnt * 8);
        fp = (unsigned short *)face;
        fe = fp + 3;
        do {
            if (((int **)buf)[*fp] && ((int **)buf)[*fp][1] == I32(face, 0xc)) {
                *fp = (unsigned short)(((char *)((int **)buf)[*fp] - recs) >> 3);
            } else {
                rec[0] = I32(p1, 4) + *fp * 0x20;
                rec[1] = I32(face, 0xc);
                ((int **)buf)[*fp] = rec;
                rec += 2;
                *fp = (unsigned short)cnt;
                cnt++;
            }
            fp++;
        } while (fp != fe);
    }
    W16(p1, 0x44) = (unsigned short)cnt;
    if (I32(p1, 0x4c)) f_18850c(I32(p1, 0x4c));
    I32(p1, 0x4c) = f_188404(p1, cnt << 5, 0xb);
    ret = (int *)f_188404(p1, cnt * 4, 1);
    rp = ret;
    rec = (int *)recs;
    for (off = 0, k = off; k < (int)W16(p1, 0x44); k++, off += 32) {
        rp++;
        rec += 2;
        *(struct Copy198574 *)((char *)I32(p1, 0x4c) + off) = *(struct Copy198574 *)rec[-2];
        rp[-1] = rec[-1];
    }
    if ((int)(ft = W16(p1, 0x1c) & 4)) {
        if (I32(p1, 0x64)) f_18850c(I32(p1, 0x64));
        I32(p1, 0x64) = f_188404(p1, W16(p1, 0x44) * 2, 1);
        face = recs;
        for (k = 0; k < (int)W16(p1, 0x44); k++) {
            S16(I32(p1, 0x64), k * 2) = (short)((I32(face, 0) - I32(p1, 4)) >> 5);
            face += 8;
        }
    }
    f_199484((int)buf);
    if (!(int)(ft = W16(p1, 0x1c) & 2)) {
        if (I32(p1, 4)) f_18850c(I32(p1, 4));
        I32(p1, 4) = I32(p1, 0x4c);
        W16(p1, 0xc) = W16(p1, 0x44);
    }
    return (int)ret;
}
//@ f_1987fc
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1987fc
 * - Aufgabe im Spiel: Fasst aufeinanderfolgende vorbereitete Eckpunkte gleichen Materials anhand des von
 *   f_19803c bzw. f_198574 gelieferten Material-Arrays (p2) zu Vertex-Gruppen (vertex_groups an Offset +0x58,
 *   Anzahl nvertex_groups an +0x52) zu je 12 Bytes zusammen.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1) und Zeiger auf das Material-Array der Vertices (p2).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokaler Gruppenzeiger (g), Gruppenanzahl (num) und laufender Vertex-Basiszeiger (base).
 === Ende Beschreibung === */
struct VGrp1987 { int value; int *base; short count; short pad; };
void f_1987fc(int p1, int *p2)
{
    struct VGrp1987 *g;
    int i, num, base;
    i = 1;
    num = 1;
    for (; i < (int)W16(p1, 0x44); i++) {
        if (p2[i] != p2[i-1]) num++;
    }
    if (I32(p1, 0x58)) f_18850c(I32(p1, 0x58));
    I32(p1, 0x58) = f_188404(p1, num * 12, 6);
    g = *(struct VGrp1987 * volatile *)((char *)p1 + 0x58); // haelt die Registerzuteilung wie im Original
    W16(p1, 0x52) = (unsigned short)num;
    base = I32(p1, 0x4c);
    g->base = (int *)base;
    g->value = p2[0];
    base += 0x20;
    for (i = 1; i < (int)W16(p1, 0x44); i++, base += 0x20) {
        if (p2[i] != p2[i-1]) {
            g->count = (short)((base - (int)g->base) >> 5);
            g++;
            g->base = (int *)base;
            g->value = p2[i];
        }
    }
    g->count = (short)((base - (int)g->base) >> 5);
}

//@ f_1988bc
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1988bc
 * - Aufgabe im Spiel: Baut für alle Dreiecksflächen eines 3D-Modells die vollständige Kantentabelle auf, indem
 *   im Scratchpad-Speicher (d_1d4d34) die Hash-Tabelle d_1d4d38 und das Kanten-Array d_1d4d3c angelegt, für jede
 *   der drei Kanten jedes Dreiecks f_197510 aufgerufen und die resultierenden Kantenindizes in edges[0..2] der
 *   Fläche sowie die Gesamtzahl der Kanten in nedges (W16(p1, 0x5c)) gespeichert werden.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Kanten-Arbeitszeiger d_1d4d34, d_1d4d38, d_1d4d3c und Gesamtzähler d_1b52a4.
 === Ende Beschreibung === */
void f_1988bc(int p1)
{
    int k;
    char *f;
    d_1d4d34 = (char *)f_199410(W16(p1, 0xe) * 0x24 + W16(p1, 0xc) * 4);
    d_1d4d38 = (struct te **)d_1d4d34;
    d_1d4d3c = (struct te *)(d_1d4d34 + W16(p1, 0xc) * 4);
    memset(d_1d4d34, 0, W16(p1, 0xc) * 4);
    d_1b52a4 = 0;
    f = (char *)I32(p1, 8);
    for (k = 0; k < (int)W16(p1, 0xe); k++) {
        W16(f, 6) = ((int (*)(int, int))f_197510)(S16(f, 0), I32(f, 0) >> 16);
        f += 0x20;
        W16(f, -0x18) = ((int (*)(int, int))f_197510)(I32(f, -0x20) >> 16, I32(f, -0x1e) >> 16);
        W16(f, -0x16) = ((int (*)(int, int))f_197510)(I32(f, -0x1e) >> 16, S16(f, -0x20));
    }
    W16(p1, 0x5c) = (unsigned short)d_1b52a4;
    f_199484((int)d_1d4d34);
}
//@ f_198978
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x198978
 * - Aufgabe im Spiel: Berechnet den Hüllkugelradius (radius an Offset +0x28) eines 3D-Modells, indem für alle
 *   Eckpunkte das Maximum der quadrierten Festkomma-Abstände vom Modellursprung (IFixedSqr3) bestimmt und daraus
 *   über f_16d3d0 die Quadratwurzel gezogen wird.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (p1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokales Maximum der quadrierten Abstände (m) und laufender Vertexzeiger (v).
 === Ende Beschreibung === */
void f_198978(int p1)
{
    int *v, k, m, t;
    v = (int *)I32(p1, 4);
    m = 0;
    for (k = 0; k < (int)W16(p1, 0xc); k++, v += 8) {
        t = IFixedSqr3(v[0], v[1], v[2]);
        if (m < t) m = t;
    }
    I32(p1, 0x28) = f_16d3d0(m);
}
//@ f_1989e4
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1989e4
 * - Aufgabe im Spiel: Berechnet die achsenparallele Bounding-Box (min[0..2] und max[0..2]) eines 3D-Modells,
 *   indem alle Eckpunkte (vertices[0 .. nvertices-1]) durchlaufen und für jede der drei Raumachsen X, Y und Z
 *   das Minimum und Maximum bestimmt werden.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (model).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Modellfelder min[3] und max[3] sowie der laufende Vertexzeiger (vp).
 === Ende Beschreibung === */
    struct BVertexBounds690 { long p[3]; char rest[20]; };
    struct BModelBounds690 {
        char unknown00[4]; struct BVertexBounds690 *vertices;
        char unknown08[4]; unsigned short nvertices;
        char unknown0e[30]; long min[3], max[3];
    };
void f_1989e4(struct BModelBounds690 *model)
{
    int axis,v;
    struct BVertexBounds690 *vp;
    for(axis=0;axis<3;axis++)
        model->min[axis]=model->max[axis]=model->vertices[0].p[axis];
    for(v=1,vp=model->vertices+1;v<model->nvertices;v++,vp++) {
        for(axis=0;axis<3;axis++) {
            if(vp->p[axis]>model->max[axis]) model->max[axis]=vp->p[axis];
            if(vp->p[axis]<model->min[axis]) model->min[axis]=vp->p[axis];
        }
    }
}

//@ f_198a48
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x198a48
 * - Aufgabe im Spiel: Hauptfunktion zur Modellvorbereitung (BrModelUpdate): Sie prüft zunächst, ob alle
 *   Eckpunktindizes aller Dreiecksflächen im gültigen Bereich < nvertices liegen (sonst Abbruch über f_197390),
 *   und aktualisiert anschließend je nach Bitmaske p2 die Kantentabelle (p2 & 2, f_1988bc), den Hüllkugelradius
 *   (p2 & 4, f_198978), die Bounding-Box (p2 & 0x10, f_1989e4), die vollständige Flächen-/Vertex-Sortierung und
 *   Normalenberechnung (p2 & 8) oder nur die schnellen Positionen und Normalen ((p2 & 9) == 1). Zuletzt wird -
 *   sofern eingetragen - der globale Modell-Update-Hook d_1d4990 aufgerufen.
 * - Eingaben: Zeiger auf die 3D-Modellstruktur (model) und Update-Flag-Bitmaske (p2).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Update-Flags p2, Modell-Flags model->flags und globaler Callback-Zeiger d_1d4990.
 === Ende Beschreibung === */
/* Teilfelder/Abstaende aus BRender1.1 MODEL.H, an Riva-Original geprueft. */
void f_198a48(struct UpModel690 *model,unsigned short p2)
{
    int ft,i,j,r;
    struct UpFace690 *fp;
    struct UpVertex690 *vp=0;
    if(model->faces && model->vertices) {
        if(model->nfaces==0) {
            if(model->face_groups) f_18850c((int)model->face_groups);
            model->face_groups=0;
            p2&=0xfff4;
        }
        for(i=0,fp=model->faces;i<model->nfaces;i++,fp++) {
            for(j=0;j < 3;j++)
                if(fp->vertices[j]>=model->nvertices) f_197390((char *)d_1ba8dc,i,j);
        }
        if((int)(ft=p2&2)) f_1988bc((int)model);
        if((int)(ft=p2&4)) f_198978((int)model);
        if((int)(ft=p2&0x10)) f_1989e4((struct BModelBounds690 *)model);
        if((int)(ft=p2&8)) {
            if((int)(ft=model->flags&0x10)) {
                f_1979c0((int)model);
                f_197e18((int)model);
                f_197e98((int)model);
                r=f_198574((int)model);
                f_1987fc((int)model,(int *)r);
                f_18850c(r);
                f_197ac0((int)model);
                model->prep_flags&=2;
            } else {
                f_1979c0((int)model);
                f_197c88((int)model);
                f_197e98((int)model);
                r=f_19803c(model);
                f_1987fc((int)model,(int *)r);
                f_18850c(r);
                *(unsigned char *)&model->prep_flags|=2;
            }
        }
        if((int)(ft=p2&9)==1) {
            if((int)(ft=model->flags&6)==6) {
                for(i=0,vp=model->prepared_vertices;i<model->nprepared_vertices;i++,vp++) {
                    vp->p[0]=model->vertices[model->vertex_tags[i]].p[0];
                    vp->p[1]=model->vertices[model->vertex_tags[i]].p[1];
                    vp->p[2]=model->vertices[model->vertex_tags[i]].p[2];
                }
            }
            f_197a40((int)model);
            f_197ac0((int)model);
        }
        if(d_1d4990) d_1d4990((int)model,p2);
    }
}

