/* === Beschreibung (Katalog) ===
 * Einheit fz_194430 (0x194430 - 0x1957c9)
 *
 * Überblick
 * Diese Einheit enthält die allgemeinen Methoden und Verwaltungsfunktionen für BRender-Pixelmaps
 * (BrPixelmapAllocate, BrPixelmapAllocateSub, BrPixelmapMatch, BrPixelmapClone, generisches Linienzeichnen über
 * virtuelle Pixel-Plot-Methoden sowie Abfragen von Pixelbreite und Kanälen aus der Typ-Tabelle d_1b4e94).
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s
// P3 7/12 gleich (suche.py 26.10.2026, Basis fz_194430_P1.CPP)
// CC wcc386
#include <string.h>
// fz_194430.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x194430-0x1957C9
extern unsigned short d_1b4e94[];       // 0x1B4E94, Eintraege zu 4 ushort (8 Bytes), Index = Pixeltyp
extern void *d_1d49b0;                  // 0x1D49B0
struct PM {
    char *identifier;                   // 0x00
    void *pixels;                       // 0x04
    int r0;                             // 0x08
    struct PM *map;                     // 0x0c
    short row_bytes;                    // 0x10
    unsigned char type;                 // 0x12
    unsigned char flags;                // 0x13
    unsigned short base_x;              // 0x14
    unsigned short base_y;              // 0x16
    unsigned short width;               // 0x18
    unsigned short height;              // 0x1a
    short origin_x;                     // 0x1c
    short origin_y;                     // 0x1e
    int user;                           // 0x20
};
#define RB(p) ((*(int *)((char *)(p) + 0xe)) >> 16)
typedef void (__cdecl *PF5)(int, int, int, int, int);
typedef void (__cdecl *PF3)(int, int, int);
typedef void (__cdecl *PF9)(int, int, unsigned short, unsigned short, int, unsigned short, unsigned short, unsigned short, unsigned short);
typedef void (__cdecl *PF7)(int, int, unsigned short, unsigned short, unsigned short, unsigned short, int);
void *f_188404(void *a, int b, int c);
void f_18850c(int a);
void f_16e660(void *a, void *b);
unsigned short f_1957a4(struct PM *pm);
struct PM *f_195590(unsigned char type, unsigned short w, unsigned short h, void *pix, int flag);
#pragma aux f_188404 "*";
#pragma aux f_18850c "*";
#pragma aux f_16e660 "*";
#pragma aux f_1957a4 "*";
#pragma aux f_195590 "*";
#pragma aux f_194430 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_1953e0 "*" parm caller [] modify [eax ecx edx];
#pragma aux f_1953fc "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_1954d0 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_195508 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_195514 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_195550 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_1956c8 "*";
#pragma aux f_195790 "*";
#pragma aux f_1957b8 "*";

#define CALL(o, pm, x, y, c) ((PF5)(*(int *)((o) + 0x24)))((o), (pm), (unsigned short)(x), (unsigned short)(y), (c))
#define PLOT(a, b) if (steep) { CALL(o, pm, b, a, c); } else { CALL(o, pm, a, b, c); }
#define SWAP(a, b) { (a) ^= (b); (b) ^= (a); (a) ^= (b); }

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_194430
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x194430
 * - Aufgabe im Spiel: Zeichnet eine 2D-Linie von (a0, b0) nach (a1, b1) mit der Farbe colour auf einer
 *   beliebigen Pixelmap (pm), indem für jedes berechnete Pixel die virtuelle Punktsetz-Methode an Offset +0x24
 *   des Kontextobjekts (o) aufgerufen wird. Wie f_17e914 nutzt auch diese Funktion den symmetrischen
 *   Doppelschritt-Algorithmus nach Brian Wyvill, arbeitet jedoch geräteunabhängig über Funktionszeiger statt
 *   über direkten Speicherzugriff.
 * - Eingaben: Zeiger auf das Kontext-/Methodenobjekt (o), Ziel-Pixelmap (pm), Startkoordinaten (a0, b0),
 *   Endkoordinaten (a1, b1) und Farbwert (colour).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Differenzen (dx, dy), Vorzeichen (sign_x, sign_y), Schrittrichtung (step), Achsentausch-Flag
 *     (reverse), Fehlerterm (D) und die von beiden Enden aufeinander zulaufenden Punktkoordinaten (x, y sowie
 *     x1, y1).
 === Ende Beschreibung === */
unsigned short a8_pixeltype(struct PM*);
#pragma aux a8_pixeltype "f_1957a4" parm [eax] value [ax] modify exact [eax];
void f_194430(int o, int pm, short a0, short b0, short a1, short b1, int colour)
{
    int dx, dy, incr1, incr2, D, x, y, xend, c, pixels_left;
    int x1,y1;
    int sign_x,sign_y,step,reverse,i;
    typedef void Plot908(int,int,int,int,int);
#pragma aux Plot908 parm caller [] modify [eax ebx ecx edx];
#define LINEPLOT(a,b,f) do { if(f) { ((Plot908 *)(*(int *)(o+0x24)))(o,pm,(unsigned short)(b),(unsigned short)(a),colour); } else { ((Plot908 *)(*(int *)(o+0x24)))(o,pm,(unsigned short)(a),(unsigned short)(b),colour); } } while(0)
#define swap(a,b) { (a)^=(b); (b)^=(a); (a)^=(b); }
#define absolute(a,b,sgn) (((a)-(b))*((sgn)=((a)-(b)<0?-1:1)))
    a8_pixeltype((struct PM *)pm);
	dx = absolute(a1, a0, sign_x);
	dy = absolute(b1, b0, sign_y);

	if(dx == 0 && dy == 0) {
		LINEPLOT(a0,b0,0);
		return;
	}

	/* decide increment sign by the slope sign */
	if (sign_x == sign_y)
		step = 1;
	else
		step = -1;

	if (dy > dx) {		/* chooses axis of greatest movement (make dx) */
		swap(a0, b0);
		swap(a1, b1);
		swap(dx, dy);
		reverse = 1;
	} else
		reverse = 0;

	/* note error check for dx==0 should be included here */
	if (a0 > a1) {		/* start from the smaller coordinate */
		x = a1;
		y = b1;
		x1 = a0;
		y1 = b0;
	} else {
		x = a0;
		y = b0;
		x1 = a1;
		y1 = b1;
	}


	/* Note dx=n implies 0 - n or (dx+1) pixels to be set */
	/* Go round loop dx/4 times then plot last 0,1,2 or 3 pixels */
	/* In fact (dx-1)/4 as 2 pixels are already plottted */

	xend = (dx - 1) / 4;
	pixels_left = (dx - 1) % 4;	/* number of pixels left over at the end */
	LINEPLOT(x, y, reverse);
	LINEPLOT(x1, y1, reverse);	/* plot first two points */
	incr2 = 4 * dy - 2 * dx;
	if (incr2 < 0) {	/* slope less than 1/2 */
		c = 2 * dy;
		incr1 = 2 * c;
		D = incr1 - dx;

		for (i = 0; i < xend; i++) {	/* plotting loop */
			++x;
			--x1;
			if (D < 0) {
				/* pattern 1 forwards */
				LINEPLOT(x, y, reverse);
				LINEPLOT(++x, y, reverse);
				/* pattern 1 backwards */
				LINEPLOT(x1, y1, reverse);
				LINEPLOT(--x1, y1, reverse);
				D += incr1;
			} else {
				if (D < c) {
					/* pattern 2 forwards */
					LINEPLOT(x, y, reverse);
					LINEPLOT(++x, y += step, reverse);
					/* pattern 2 backwards */
					LINEPLOT(x1, y1, reverse);
					LINEPLOT(--x1, y1 -= step, reverse);
				} else {
					/* pattern 3 forwards */
					LINEPLOT(x, y += step, reverse);
					LINEPLOT(++x, y, reverse);
					/* pattern 3 backwards */
					LINEPLOT(x1, y1 -= step, reverse);
					LINEPLOT(--x1, y1, reverse);
				}
				D += incr2;
			}
		}		/* end for */

		/* plot last pattern */
		if (pixels_left) {
			if (D < 0) {
				LINEPLOT(++x, y, reverse);	/* pattern 1 */
				if (pixels_left > 1)
					LINEPLOT(++x, y, reverse);
				if (pixels_left > 2)
					LINEPLOT(--x1, y1, reverse);
			} else {
				if (D < c) {
					LINEPLOT(++x, y, reverse);	/* pattern 2  */
					if (pixels_left > 1)
						LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 2)
						LINEPLOT(--x1, y1, reverse);
				} else {
					/* pattern 3 */
					LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 1)
						LINEPLOT(++x, y, reverse);
					if (pixels_left > 2)
						LINEPLOT(--x1, y1 -= step, reverse);
				}
			}
		}		/* end if pixels_left */
	}
	/* end slope < 1/2 */
	else {			/* slope greater than 1/2 */
		c = 2 * (dy - dx);
		incr1 = 2 * c;
		D = incr1 + dx;
		for (i = 0; i < xend; i++) {
			++x;
			--x1;
			if (D > 0) {
				/* pattern 4 forwards */
				LINEPLOT(x, y += step, reverse);
				LINEPLOT(++x, y += step, reverse);
				/* pattern 4 backwards */
				LINEPLOT(x1, y1 -= step, reverse);
				LINEPLOT(--x1, y1 -= step, reverse);
				D += incr1;
			} else {
				if (D < c) {
					/* pattern 2 forwards */
					LINEPLOT(x, y, reverse);
					LINEPLOT(++x, y += step, reverse);

					/* pattern 2 backwards */
					LINEPLOT(x1, y1, reverse);
					LINEPLOT(--x1, y1 -= step, reverse);
				} else {
					/* pattern 3 forwards */
					LINEPLOT(x, y += step, reverse);
					LINEPLOT(++x, y, reverse);
					/* pattern 3 backwards */
					LINEPLOT(x1, y1 -= step, reverse);
					LINEPLOT(--x1, y1, reverse);
				}
				D += incr2;
			}
		}		/* end for */
		/* plot last pattern */
		if (pixels_left) {
			if (D > 0) {
				LINEPLOT(++x, y += step, reverse);	/* pattern 4 */
				if (pixels_left > 1)
					LINEPLOT(++x, y += step, reverse);
				if (pixels_left > 2)
					LINEPLOT(--x1, y1 -= step, reverse);
			} else {
				if (D < c) {
					LINEPLOT(++x, y, reverse);	/* pattern 2  */
					if (pixels_left > 1)
						LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 2)
						LINEPLOT(--x1, y1, reverse);
				} else {
					/* pattern 3 */
					LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 1)
						LINEPLOT(++x, y, reverse);
					if (pixels_left > 2) {
						if (D > c)	/* step 3 */
							LINEPLOT(--x1, y1 -= step, reverse);
						else	/* step 2 */
							LINEPLOT(--x1, y1, reverse);
					}
				}
			}
		}
	}

}
#undef LINEPLOT
#undef swap
#undef absolute

//@ f_1953e0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1953e0
 * - Aufgabe im Spiel: Ruft die virtuelle Methode an Offset +0x28 des Pixelmap-Kontextobjekts (o) mit den
 *   Argumenten (o, a, b) auf und gibt anschließend den Wert b zurück.
 * - Eingaben: Kontextobjekt (o), Ziel-Pixelmap (a) und Parameter (b).
 * - Rückgabewert: Der übergebene Parameter b.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
#pragma aux f_1953e0 "*" parm caller [] modify [eax ebx ecx edx];
int f_1953e0(int o, int a, int b)
{
    typedef void PF3F(int, int, int);
    #pragma aux PF3F parm caller [] modify [eax ebx ecx edx];
    ((PF3F *)(*(int *)(o + 0x28)))(o, a, b);
    return b;
}

//@ f_1953fc
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1953fc
 * - Aufgabe im Spiel: Erzeugt zu einer bestehenden Quell-Pixelmap (pm) eine passende Begleit-Pixelmap
 *   (BrPixelmapMatch) anhand des angeforderten Verwendungsmodus (mode): Bei mode == 0
 *   (Offscreen-/Backbuffer-Klon) wird eine neue Pixelmap gleichen Typs und gleicher Abmessungen angelegt; bei
 *   mode == 1 (Tiefen-/Z-Puffer) wird eine 16-Bit-Z-Puffer-Pixelmap vom Typ 0x0b (BR_PMT_DEPTH_16) mit passend
 *   skalierter Zeilenbreite (row_bytes) und eigenem Pixelspeicher alloziert.
 * - Eingaben: Kontext (o), Referenz-Pixelmap (pm) und Match-Modus (mode: 0 für Farbklon, 1 für 16-Bit-Z-Puffer).
 * - Rückgabewert: Zeiger auf die neu angelegte Pixelmap (n) oder 0 bei unbekanntem Modus.
 * - Wichtige Variablen:
 *   - Lokaler Zeiger auf die neue Pixelmap (n), Bittiefe der Vorlage (bpp) und berechnete Zeilenbreite (r).
 === Ende Beschreibung === */
struct PM *f_1953fc(int o, struct PM *pm, unsigned char mode)
{
    unsigned short f_1957a4_direct(struct PM *);
#pragma aux f_1957a4_direct "f_1957a4" parm [eax] value [ax] modify [eax];
    int r;
    unsigned short bpp;
    int divisor;
    struct PM *n = 0;

    switch (mode) {
    case 0:
        n = f_195590(pm->type, pm->width, pm->height, 0, pm->row_bytes < 0);
        break;
    case 1:
        n = f_195590(0xb, pm->width, pm->height, pm, (int)n);
        bpp = f_1957a4_direct(pm);
        divisor = (int)bpp >> 3;
        n->row_bytes = (RB(pm) * 2) / divisor;
        if (n->row_bytes > 0) {
            r = RB(n);
        } else {
            r = -RB(n);
        }
        n->pixels = f_188404(n, n->height * r, 3);
        if (n->row_bytes < 0) {
            n->pixels = (char *)n->pixels + r * (n->height - 1);
        }
        break;
    default:
        break;
    }
    return n;
}

//@ f_1954d0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1954d0
 * - Aufgabe im Spiel: Erstellt eine vollständige Kopie (BrPixelmapClone) einer bestehenden Pixelmap (pm), indem
 *   zuerst über f_195590 eine neue Pixelmap gleichen Typs, gleicher Größe und gleicher Zeilenorientierung
 *   angelegt und anschließend der gesamte Pixelinhalt über f_16e660 hineinkopiert wird.
 * - Eingaben: Kontext (o) und Zeiger auf die zu klonende Quell-Pixelmap (pm).
 * - Rückgabewert: Zeiger auf die neu angelegte und befüllte Pixelmap (n).
 * - Wichtige Variablen:
 *   - Lokaler Zeiger auf die neue Pixelmap (n).
 === Ende Beschreibung === */
struct PM *f_1954d0(int o, struct PM *pm)
{
    struct PM *n;

    n = f_195590(pm->type, pm->width, pm->height, 0, pm->row_bytes < 0);
    f_16e660(n, pm);
    return n;
}

//@ f_195508
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x195508
 * - Aufgabe im Spiel: Gibt eine Pixelmap-Ressource (a) über den BRender-Ressourcenmanager (f_18850c) frei.
 * - Eingaben: Kontext (o) und Zeiger auf die freizugebende Pixelmap (a).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_195508(int o, int a)
{
    f_18850c(a);
}

//@ f_195514
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x195514
 * - Aufgabe im Spiel: Kopiert ein Teilrechteck (a4, a5, a6, a7) von der Quell-Pixelmap (a3) an dieselben
 *   Koordinaten (a4, a5) der Ziel-Pixelmap (a2), indem die virtuelle Rechteck-Kopiermethode an Offset +0x14 des
 *   Kontextobjekts (o) aufgerufen wird.
 * - Eingaben: Kontext (o), Ziel-Pixelmap (a2), Quell-Pixelmap (a3), Koordinaten (a4, a5) sowie Breite (a6) und
 *   Höhe (a7).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_195514(int o, int a2, int a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7)
{
    ((PF9)(*(int *)(o + 0x14)))(o, a2, a4, a5, a3, a4, a5, a6, a7);
}

//@ f_195550
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x195550
 * - Aufgabe im Spiel: Füllt ein Rechteck (a3, a4, a5, a6) in der Ziel-Pixelmap (a2) mit der Farbe a7, indem die
 *   virtuelle Rechteck-Füllmethode an Offset +0x18 des Kontextobjekts (o) aufgerufen wird.
 * - Eingaben: Kontext (o), Ziel-Pixelmap (a2), Koordinaten (a3, a4), Abmessungen (a5, a6) und Farbwert (a7).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_195550(int o, int a2, unsigned short a3, unsigned short a4, unsigned short a5, unsigned short a6, int a7)
{
    ((PF7)(*(int *)(o + 0x18)))(o, a2, a3, a4, a5, a6, a7);
}

//@ f_195590
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x195590
 * - Aufgabe im Spiel: Legt eine neue BRender-Pixelmap-Struktur (BrPixelmapAllocate) vom Pixeltyp type mit der
 *   Breite w und Höhe h als Kindressource von d_1d49b0 an. Die Funktion setzt den Ursprung (origin_x, origin_y)
 *   auf die Bildmitte, berechnet row_bytes anhand der Typtabelle d_1b4e94, alloziert - falls kein fertiger
 *   Pixelpuffer (pix == 0) übergeben wurde - den Pixelspeicher als Kindressource der Pixelmap und richtet bei
 *   gesetztem Bottom-Up-Flag (flag & 1) den Pixelzeiger auf die unterste Zeile bei negativer row_bytes aus.
 * - Eingaben: Pixelformat-Typ (type), Breite (w), Höhe (h), optionaler bestehender Pixelpuffer (pix) und
 *   Orientierungs-Flags (flag).
 * - Rückgabewert: Zeiger auf die neu angelegte Pixelmap-Struktur (pm).
 * - Wichtige Variablen:
 *   - Globale Pixelformat-Deskriptortabelle d_1b4e94: Liefert je Pixeltyp die Bittiefe (e[0]) und
 *     Ausrichtungs-Granularität (e[2]).
 *   - Globale Wurzelressource d_1d49b0: Dient als Elternressource für die neue Pixelmap.
 === Ende Beschreibung === */
struct PM *f_195590(unsigned char type, unsigned short w, unsigned short h, void *pix, int flag)
{
    struct PM *pm;
    unsigned short *e;
    void **q = &d_1d49b0; // haelt die Registerzuteilung wie im Original

    e = (unsigned short *)((char *)d_1b4e94 + type * 8);
    pm = (struct PM *)f_188404(*q, 0x24, 2);
    pm->identifier = 0;
    pm->type = type;
    pm->map = 0;
    pm->flags = 2;
    pm->base_x = 0;
    pm->base_y = 0;
    pm->width = w;
    pm->height = h;
    pm->origin_x = w / 2;
    pm->origin_y = h / 2;
    pm->row_bytes = (e[0] * e[2] * ((w + e[2] - 1) / e[2])) / 8;
    if (((RB(pm) << 3) % e[0]) == 0) {
        pm->flags |= 4;
    }
    if (pix) {
        pm->pixels = pix;
    } else {
        pm->pixels = f_188404(pm, RB(pm) * pm->height, 3);
    }
    if (flag & 1) {
        pm->pixels = (char *)pm->pixels + (pm->height - 1) * RB(pm);
        pm->row_bytes = -pm->row_bytes;
    }
    return pm;
}

//@ f_1956c8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1956c8
 * - Aufgabe im Spiel: Erzeugt eine Unter-Pixelmap (BrPixelmapAllocateSub), die einen rechteckigen Ausschnitt (x,
 *   y, w, h) einer bestehenden Eltern-Pixelmap (pm) beschreibt und deren Pixelspeicher direkt mitbenutzt. Dabei
 *   werden die Ausschnittgrenzen auf die Abmessungen von pm geclippt, base_x/base_y sowie origin_x/origin_y
 *   entsprechend verschoben und das Besitz-Flag für eigenen Pixelspeicher (~2) gelöscht.
 * - Eingaben: Zeiger auf die Quell-Pixelmap (pm), Ausschnittkoordinaten (x, y) sowie gewünschte Breite (w) und
 *   Höhe (h).
 * - Rückgabewert: Zeiger auf die neu angelegte Unter-Pixelmap (npm).
 * - Wichtige Variablen:
 *   - Lokaler Zeiger auf die Unter-Pixelmap (npm) sowie geclippte linke Kante (left908), Breite (w) und Höhe
 *     (heightResult908).
 === Ende Beschreibung === */
struct PM *f_1956c8(struct PM *pm, unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
    void **q = &d_1d49b0; // haelt die Registerzuteilung wie im Original
    struct PM *npm;
    int left908, heightResult908, width908;

    npm = (struct PM *)f_188404(*q, 0x24, 2);
    d_1d49b0 = ((int)d_1d49b0 & 0) ? 0 : d_1d49b0; // haelt die Registerzuteilung wie im Original
    *npm = *pm;
    npm->flags &= ~2;

    x = (x > pm->width) ? pm->width : x;
    y = (y > pm->height) ? pm->height : y;

    npm->base_x += x;
    npm->base_y += y;
    npm->origin_x -= x;
    npm->origin_y -= y;

    left908 = x;
    w = (left908 + w > pm->width) ? pm->width - left908 : w;
    npm->width = w;
    heightResult908 = (y + h > pm->height) ? pm->height - y : h;
    npm->height = heightResult908;
    *(unsigned *)d_1b4e94 = (*(unsigned *)d_1b4e94 & 0) ? 0 : *(unsigned *)d_1b4e94; // haelt die Registerzuteilung wie im Original
    return npm;
}

//@ f_195790
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x195790
 * - Aufgabe im Spiel: Liest aus der globalen Pixeltyp-Deskriptortabelle d_1b4e94 das zweite 16-Bit-Wort
 *   (d_1b4e94[pm->type * 4 + 1]) für den Typ der übergebenen Pixelmap aus.
 * - Eingaben: Zeiger auf die Pixelmap (pm).
 * - Rückgabewert: Der 16-Bit-Deskriptorwert an Index +1 des jeweiligen Pixeltyps.
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1b4e94.
 === Ende Beschreibung === */
unsigned short f_195790(struct PM *pm)
{
    return d_1b4e94[pm->type * 4 + 1];
}

//@ f_1957a4
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1957a4
 * - Aufgabe im Spiel: Gibt die Farbtiefe in Bits pro Pixel (d_1b4e94[pm->type * 4]) für den Pixeltyp der
 *   übergebenen Pixelmap zurück.
 * - Eingaben: Zeiger auf die Pixelmap (pm).
 * - Rückgabewert: Die Anzahl der Bits pro Pixel als unsigned short.
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1b4e94.
 === Ende Beschreibung === */
unsigned short f_1957a4(struct PM *pm)
{
    return d_1b4e94[pm->type * 4];
}

//@ f_1957b8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1957b8
 * - Aufgabe im Spiel: Gibt die Kanalmaske (d_1b4e94[pm->type * 4 + 3], z. B. Farb-/Alpha-/Tiefenkanäle) für den
 *   Pixeltyp der übergebenen Pixelmap aus der Tabelle d_1b4e94 zurück.
 * - Eingaben: Zeiger auf die Pixelmap (pm).
 * - Rückgabewert: Die 16-Bit-Kanalmaske des Pixeltyps.
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1b4e94.
 === Ende Beschreibung === */
unsigned short f_1957b8(struct PM *pm)
{
    return d_1b4e94[pm->type * 4 + 3];
}
