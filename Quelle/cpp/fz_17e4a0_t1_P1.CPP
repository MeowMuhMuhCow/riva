/* === Beschreibung (Katalog) ===
 * Einheit fz_17e4a0_t1 (0x17e4a0 - 0x180330)
 *
 * Überblick
 * Diese Einheit implementiert die grundlegenden 2D-Pixelmap-Zeichenoperationen der BRender-Engine auf Speicher-
 * und Videospeicher-Oberflächen: das Füllen ganzer Pixelmaps oder rechteckiger Ausschnitte, das Kopieren ganzer
 * Pixelmaps oder Teilrechtecke, das Setzen einzelner Pixel, einen symmetrischen Bresenham-Linienrasterizer
 * (f_17e914), das Zeichnen von Bitmasken/Glyphen (f_18025c) sowie die DPMI-Selektor-Initialisierung für den
 * VGA-Videospeicher 0xA000 (f_1802f0).
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s
// P3 2/10 gleich (suche.py 27.10.2026, Basis fz_17e4a0_t1_P1.CPP)
// CC wcc386
// P1 2/8 gleich (+2 ASM: f_17e914 f_1802f0 als Platzhalter)
// fz_17e4a0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x17E4A0-0x180330 (Teil 1)
#pragma inline_depth(0)
#define W(p,o) (*(unsigned short *)((p)+(o)))
#define S(p,o) (*(short *)((p)+(o)))
#define D(p,o) (*(int *)((p)+(o)))
#define B(p,o) (*(unsigned char *)((p)+(o)))
extern int d_1b4518[];
unsigned short f_1957a4(int p1);
void f_18e7c4(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);
void f_18ebb4(int p1, int p2, int p3, int p4, int p5);
void f_18ec98(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
void f_18edc1(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
void f_18ee19(int p1, int p2, int p3, int p4, int p5, int p6);
void f_18ee5e(int p1, int p2, int p3, int p4);
void f_17e4a0(int a1, int pm, int c);
void f_17e574(int a1, int a2, int dx, unsigned short dy, int a5, unsigned short sx, unsigned short sy, unsigned short w, unsigned short h);
void f_17e650(int a1, int pm, unsigned short x, unsigned short y, unsigned short w, unsigned short h, int c);
void f_17e6c0(int a1, int a2, int pm, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
void f_17e6fc(int a1, int a2, unsigned short x, unsigned short y, unsigned short w, unsigned short h, int c);
void f_17e734(int a1, int a2, int a3);
void f_17e8b8(int a1, int pm, unsigned short x, unsigned short y, int k5);
void f_17e914(int a1, int pm, short ax, short ay, short bx, short by, int colour);
void f_18025c(int a1, int pm, short x, short y, int k5, unsigned short k6, unsigned short k7, unsigned short k8, unsigned short k9, int k10);
void f_1802f0(void);
#pragma aux f_1957a4 "*";
#pragma aux f_18e7c4 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_18ebb4 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_18ec98 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_18edc1 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_18ee19 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_18ee5e "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e4a0 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e574 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e650 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e6c0 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e6fc "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e734 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e8b8 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_17e914 "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_18025c "*" parm caller [] modify [eax ebx ecx edx];
#pragma aux f_1802f0 "*";
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_17e4a0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e4a0
 * - Aufgabe im Spiel: Füllt eine gesamte BRender-Pixelmap (pm) mit einem konstanten Farbwert (c). Ist die
 *   Pixelmap als zusammenhängender linearer Speicherblock ohne Zeilenlücken markiert ((flags & 6) == 6), wird
 *   der gesamte Bereich in einem einzigen Blockaufruf (f_18ebb4) gefüllt; andernfalls erfolgt das Füllen
 *   zeilenweise über f_18ec98.
 * - Eingaben: Zeiger auf das Ausgabegerät bzw. den Kontext (a1), Zeiger auf die Ziel-Pixelmap (pm) und der zu
 *   schreibende Farbwert (c).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Bytes-pro-Pixel-Größe (bpp): Wird über f_1957a4(pm) >> 3 aus dem Pixelmap-Typ bestimmt.
 *   - Lokale Startadresse (ad) und Zeilenbreite in Bytes (rb): Berücksichtigen base_x, base_y sowie bei
 *     negativer row_bytes (Bottom-Up-Pixelmap) den Versatz auf die unterste Zeile (height - 1).
 === Ende Beschreibung === */
void f_17e4a0(int a1, int pm, int c)
{
    int offset, bpp, r, rb, ad;
    unsigned short flags;
    bpp = f_1957a4(pm) >> 3;
    flags = B(pm,0x13) & 6;
    if ((int)flags == 6) {
        if (S(pm,0x10) > 0) r = 0; else r = W(pm,0x1a) - 1;
        ad = ((offset = D(pm,4)) + (W(pm,0x16) + r) * (rb = D(pm,0xe) >> 16)) + W(pm,0x14) * bpp;
        f_18ebb4(ad, D(a1,0xc), W(pm,0x18) * W(pm,0x1a), bpp, c);
        return;
    }
    rb = D(pm,0xe) >> 16;
    offset = D(pm,4);
    ad = W(pm,0x14) * bpp + (offset + W(pm,0x16) * rb);
    f_18ec98(ad, D(a1,0xc), W(pm,0x18), W(pm,0x1a), rb, bpp, c);
}
//@ f_17e574
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e574
 * - Aufgabe im Spiel: Kopiert einen rechteckigen Bildausschnitt der Größe w x h von den Quellkoordinaten (sx,
 *   sy) einer Quell-Pixelmap (a5) an die Zielkoordinaten (dx, dy) einer Ziel-Pixelmap (a2). Dabei werden für
 *   Quelle und Ziel sowohl die jeweiligen base_x/base_y-Versätze als auch die Speicherselektoren (map) für
 *   DPMI-/Videospeicherzugriffe berücksichtigt.
 * - Eingaben: Ziel-Kontext (a1), Ziel-Pixelmap (a2), Zielkoordinaten (dx, dy), Quell-Pixelmap (a5),
 *   Quellkoordinaten (sx, sy) sowie Breite (w) und Höhe (h).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokaler Quell-Kontext (q): Nutzt a5->user oder, falls dieser 0 ist, den globalen Standard-Speicherkontext
 *     d_1b4518.
 *   - Lokale Startadressen für Quelle (sa) und Ziel (da): Werden aus dem Pixelzeiger, row_bytes, base_x/base_y
 *     und bpp berechnet und an den Blockkopierer f_18edc1 übergeben.
 === Ende Beschreibung === */
void f_17e574(int a1, int a2, int dx, unsigned short dy, int a5, unsigned short sx, unsigned short sy, unsigned short w, unsigned short h)
{
    struct PM { int id; char *pixels; int r0, map; short row_bytes; unsigned char type, flags; unsigned short base_x, base_y, width, height; short ox, oy; int user; };
    #define P(x) ((struct PM *)(x))
    int q, bpp, sa, da;
        q = P(a5)->user ? P(a5)->user : (int)d_1b4518;
    
    bpp = f_1957a4(a5) >> 3;
    sa = (int)(P(a5)->pixels + (P(a5)->base_y + sy) * P(a5)->row_bytes + (P(a5)->base_x + sx) * bpp);
    da = (int)(P(a2)->pixels + (P(a2)->base_y + dy) * P(a2)->row_bytes + (P(a2)->base_x + (unsigned short)dx) * bpp);
    f_18edc1(da, P(a1)->map, sa, P(q)->map, w, h, P(a2)->row_bytes, P(a5)->row_bytes, bpp);
    #undef P
}
//@ f_17e650
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e650
 * - Aufgabe im Spiel: Füllt ein rechteckiges Teilgebiet (x, y, w, h) innerhalb einer Ziel-Pixelmap (pm)
 *   zeilenweise über f_18ec98 mit dem angegebenen Farbwert (c).
 * - Eingaben: Kontext (a1), Ziel-Pixelmap (pm), Rechteckkoordinaten (x, y), Abmessungen (w, h) und Farbwert (c).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Startadresse (ad), Zeilenstride (rb) und Bytes pro Pixel (bpp): Bestimmen den exakten Zielbereich
 *     im Pixelpuffer.
 === Ende Beschreibung === */
void f_17e650(int a1, int pm, unsigned short x, unsigned short y, unsigned short w, unsigned short h, int c)
{
    int bpp, rb, offset, ad;
    bpp = f_1957a4(pm) >> 3;
    ad = ((offset = D(pm,4)) + (W(pm,0x16) + y) * (rb = D(pm,0xe) >> 16)) + (W(pm,0x14) + x) * bpp;
    f_18ec98(ad, D(a1,0xc), w, h, rb, bpp, c);
}
//@ f_17e6c0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e6c0
 * - Aufgabe im Spiel: Kopiert einen rechteckigen Bereich (x, y, w, h) von einer Quell-Pixelmap (pm) an exakt
 *   dieselbe Position (x, y) der Ziel-Pixelmap (a2), indem f_17e574 mit identischen Quell- und Zielkoordinaten
 *   aufgerufen wird.
 * - Eingaben: Ziel-Kontext (a1), Ziel-Pixelmap (a2), Quell-Pixelmap (pm), Koordinaten (x, y) sowie Breite (w)
 *   und Höhe (h).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_17e6c0(int a1, int a2, int pm, unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
    f_17e574(a1, a2, x, y, pm, x, y, w, h);
}
//@ f_17e6fc
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e6fc
 * - Aufgabe im Spiel: Leitet das Füllen eines Rechtecks (x, y, w, h) mit der Farbe c direkt an f_17e650 weiter
 *   (Alias- bzw. Methoden-Wrapper für RectangleFill).
 * - Eingaben: Kontext (a1), Ziel-Pixelmap (a2), Koordinaten (x, y), Abmessungen (w, h) und Farbwert (c).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_17e6fc(int a1, int a2, unsigned short x, unsigned short y, unsigned short w, unsigned short h, int c)
{
    f_17e650(a1, a2, x, y, w, h, c);
}
//@ f_17e734
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e734
 * - Aufgabe im Spiel: Kopiert den gesamten Inhalt einer Quell-Pixelmap (src) in eine gleich große Ziel-Pixelmap
 *   (pm). Sind beide Pixelmaps als lückenlos linear gekennzeichnet ((flags & 6) == 6), wird ein schneller
 *   linearer Speicherkopierlauf (f_18ee19) ausgeführt; andernfalls erfolgt das Kopieren zeilenweise über
 *   f_18edc1.
 * - Eingaben: Ziel-Kontext (a1), Ziel-Pixelmap (pm) und Quell-Pixelmap (src).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Startadressen ad1 (Ziel) und ad2 (Quelle) sowie Bytes pro Pixel (bpp).
 *   - Lokaler Quell-Kontext (q): Wird aus src->user oder dem globalen Standardkontext d_1b4518 bezogen.
 === Ende Beschreibung === */
void f_17e734(int a1, int pm, int src)
{
    struct PM { int id; char *pixels; int r0, map; short row_bytes; unsigned char type, flags; unsigned short base_x, base_y, width, height; short ox, oy; int user; };
    #define P(x) ((struct PM *)(x))
    int ad1, ad2, bpp, q;
    unsigned char flags;
    q = P(src)->user ? P(src)->user : (int)d_1b4518;
    bpp = f_1957a4(pm) >> 3;
    flags = P(pm)->flags & 6;
    if ((int)flags == 6) {
        flags = P(src)->flags & 6;
        if ((int)flags == 6) {
            ad1 = (int)(P(pm)->pixels + (P(pm)->base_y + (P(pm)->row_bytes > 0 ? 0 : P(pm)->height - 1)) * P(pm)->row_bytes + P(pm)->base_x * bpp);
            ad2 = (int)(P(src)->pixels + (P(src)->base_y + (P(pm)->row_bytes > 0 ? 0 : P(pm)->height - 1)) * P(src)->row_bytes + P(src)->base_x * bpp);
            f_18ee19(ad1, P(a1)->map, ad2, P(q)->map, P(pm)->row_bytes * P(pm)->height / bpp, bpp);
            return;
        }
    }
    ad1 = (int)(P(pm)->pixels + P(pm)->base_y * P(pm)->row_bytes + P(pm)->base_x * bpp);
    ad2 = (int)(P(src)->pixels + P(src)->base_y * P(src)->row_bytes + P(src)->base_x * bpp);
    f_18edc1(ad1, P(a1)->map, ad2, P(q)->map, P(pm)->width, P(pm)->height, P(pm)->row_bytes, P(src)->row_bytes, bpp);
    #undef P
}
//@ f_17e8b8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e8b8
 * - Aufgabe im Spiel: Setzt ein einzelnes Pixel an den Koordinaten (x, y) einer Ziel-Pixelmap (pm) über die
 *   Low-Level-Schreibroutine f_18ee5e auf den Farbwert k5.
 * - Eingaben: Kontext (a1), Ziel-Pixelmap (pm), Pixelkoordinaten (x, y) und Farbwert (k5).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Zieladresse (ad) und Bytes pro Pixel (bpp): Bestimmen die Speicheradresse des zu ändernden Pixels.
 === Ende Beschreibung === */
void f_17e8b8(int a1, int pm, unsigned short x, unsigned short y, int k5)
{
    int offset, bpp, ad;
    bpp = f_1957a4(pm) >> 3;
    ad = ((offset = D(pm,4)) + (W(pm,0x16) + y) * (D(pm,0xe) >> 16)) + (W(pm,0x14) + x) * bpp;
    f_18ee5e(ad, D(a1,0xc), bpp, k5);
}
//@ f_17e914
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17e914
 * - Aufgabe im Spiel: Zeichnet eine 2D-Linie von (ax, ay) nach (bx, by) mit der Farbe colour direkt in den
 *   Speicher einer Pixelmap (pm). Die Funktion nutzt den symmetrischen Doppelschritt-Linienalgorithmus nach
 *   Brian Wyvill, der gleichzeitig von beiden Endpunkten zur Linienmitte läuft und pro Schleifendurchlauf vier
 *   Pixel setzt.
 * - Eingaben: Kontext (a1), Ziel-Pixelmap (pm), Startpunkt (ax, ay), Endpunkt (bx, by) und Farbwert (colour).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Achsenabstände (dx, dy), Schrittrichtung (step), Achsentausch-Flag (reverse) sowie die
 *     symmetrischen Laufkoordinaten (x, y von links und x1, y1 von rechts).
 *   - Lokale Entscheidungsvariable (D) und Inkremente (incr1, incr2): Steuern die Auswahl des jeweiligen
 *     Zwei-Pixel-Schritts für flache und steile Anstiege.
 === Ende Beschreibung === */
void f_17e914(int a1,int pm,short ax,short ay,short bx,short by,int colour) {
    struct PM904 { int id; char *pixels; int reserved, qualifier; short row_bytes; unsigned char type, flags; unsigned short base_x,base_y,width,height; short ox,oy; int user; };
    #define map ((struct PM904*)pm)
    int dx,dy,incr1,incr2,D,x,y,xend,c,pixels_left;
    int x1,y1,sign_x,sign_y,step,reverse,i;
    char *dest; int bytes;
#define MEMADR(xx,yy) (map->pixels+(map->base_y+(yy))*map->row_bytes+(map->base_x+(xx))*bytes)
#define LINEPLOT(x,y,flag) do {				\
	if(flag) {								\
		dest = MEMADR(y,x); \
	} else {								\
		dest = MEMADR(x,y); \
	}										\
	f_18ee5e((int)dest,((struct PM904*)a1)->qualifier,bytes,colour);	\
} while(0)

#define swap(a,b)           {a^=b; b^=a; a^=b;}
#define absolute(i,j,k)     ( (i-j)*(k = ( (i-j)<0 ? -1 : 1)))

   	bytes = (f_1957a4(pm)>>3);

	dx = absolute(bx, ax, sign_x);
	dy = absolute(by, ay, sign_y);

	if(dx == 0 && dy == 0) {
		dest = MEMADR(ax,ay);
		f_18ee5e((int)dest,((struct PM904*)a1)->qualifier,bytes,colour);
		return;
	};

	
	if (sign_x == sign_y)
		step = 1;
	else
		step = -1;

	if (dy > dx) {		
		swap(ax, ay);
		swap(bx, by);
		swap(dx, dy);
		reverse = 1;
	} else
		reverse = 0;

	
	if (ax > bx) {		
		x = bx;
		y = by;
		x1 = ax;
		y1 = ay;
	} else {
		x = ax;
		y = ay;
		x1 = bx;
		y1 = by;
	}


	
	
	

	xend = (dx - 1) / 4;
	pixels_left = (dx - 1) % 4;	
	LINEPLOT(x, y, reverse);
	LINEPLOT(x1, y1, reverse);	
	incr2=4*dy-2*dx;
	if (incr2 < 0) {	
		
		c=2*dy; incr1=2*c;
		D = incr1 - dx;

		for (i = 0; i < xend; i++) {	
			++x;
			--x1;
			if (D < 0) {
				
				LINEPLOT(x, y, reverse);
				LINEPLOT(++x, y, reverse);
				
				LINEPLOT(x1, y1, reverse);
				LINEPLOT(--x1, y1, reverse);
				D += incr1;
			} else {
				if (D < c) {
					
					LINEPLOT(x, y, reverse);
					LINEPLOT(++x, y += step, reverse);
					
					LINEPLOT(x1, y1, reverse);
					LINEPLOT(--x1, y1 -= step, reverse);
				} else {
					
					LINEPLOT(x, y += step, reverse);
					LINEPLOT(++x, y, reverse);
					
					LINEPLOT(x1, y1 -= step, reverse);
					LINEPLOT(--x1, y1, reverse);
				}
				D += incr2;
			}
		}		

		
		if (pixels_left) {
			if (D < 0) {
				LINEPLOT(++x, y, reverse);	
				if (pixels_left > 1)
					LINEPLOT(++x, y, reverse);
				if (pixels_left > 2)
					LINEPLOT(--x1, y1, reverse);
			} else {
				if (D < c) {
					LINEPLOT(++x, y, reverse);	
					if (pixels_left > 1)
						LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 2)
						LINEPLOT(--x1, y1, reverse);
				} else {
					
					LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 1)
						LINEPLOT(++x, y, reverse);
					if (pixels_left > 2)
						LINEPLOT(--x1, y1 -= step, reverse);
				}
			}
		}		
	}
	
	else {			
		c=2*(dy-dx); incr1=2*c;
		D = incr1 + dx;
		for (i = 0; i < xend; i++) {
			++x;
			--x1;
			if (D > 0) {
				
				LINEPLOT(x, y += step, reverse);
				LINEPLOT(++x, y += step, reverse);
				
				LINEPLOT(x1, y1 -= step, reverse);
				LINEPLOT(--x1, y1 -= step, reverse);
				D += incr1;
			} else {
				if (D < c) {
					
					LINEPLOT(x, y, reverse);
					LINEPLOT(++x, y += step, reverse);

					
					LINEPLOT(x1, y1, reverse);
					LINEPLOT(--x1, y1 -= step, reverse);
				} else {
					
					LINEPLOT(x, y += step, reverse);
					LINEPLOT(++x, y, reverse);
					
					LINEPLOT(x1, y1 -= step, reverse);
					LINEPLOT(--x1, y1, reverse);
				}
				D += incr2;
			}
		}		
		
		if (pixels_left) {
			if (D > 0) {
				LINEPLOT(++x, y += step, reverse);	
				if (pixels_left > 1)
					LINEPLOT(++x, y += step, reverse);
				if (pixels_left > 2)
					LINEPLOT(--x1, y1 -= step, reverse);
			} else {
				if (D < c) {
					LINEPLOT(++x, y, reverse);	
					if (pixels_left > 1)
						LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 2)
						LINEPLOT(--x1, y1, reverse);
				} else {
					
					LINEPLOT(++x, y += step, reverse);
					if (pixels_left > 1)
						LINEPLOT(++x, y, reverse);
					if (pixels_left > 2) {
						if (D > c)	
							LINEPLOT(--x1, y1 -= step, reverse);
						else	
							LINEPLOT(--x1, y1, reverse);
					}
				}
			}
		}
	}

	return;
}



#undef map
#undef MEMADR
#undef LINEPLOT
#undef swap
#undef absolute
//@ f_18025c
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18025c
 * - Aufgabe im Spiel: Überträgt ein 1-Bit-Bitmap-Muster (beispielsweise ein Schriftzeichen oder Symbol) mit
 *   gegebener Farbe an die Position (x, y) einer Ziel-Pixelmap (pm), indem die Zieladresse im Pixelpuffer
 *   berechnet und an die Bit-Kopierroutine f_18e7c4 übergeben wird.
 * - Eingaben: Kontext (a1), Ziel-Pixelmap (pm), Zielkoordinaten (x, y), Quellzeiger der Bitmaske (k5),
 *   Bit-Koordinaten und Abmessungen (k6, k7, k8, k9) sowie der Farbwert (k10).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Bytes-pro-Pixel-Größe (bpp): Dient zur Berechnung des Ziel-Byteoffsets und wird an f_18e7c4
 *     durchgereicht.
 === Ende Beschreibung === */
void f_18025c(int a1, int pm, short x, short y, int k5, unsigned short k6, unsigned short k7, unsigned short k8, unsigned short k9, int k10)
{
    struct PM { int id; char *pixels; int r0, map; short row_bytes; unsigned char type, flags; unsigned short base_x, base_y, width, height; short ox, oy; int user; };
    #define P(x) ((struct PM *)(x))
    int bpp;
    bpp = f_1957a4(pm) >> 3;
    f_18e7c4((int)(P(pm)->pixels + (P(pm)->base_y + y) * P(pm)->row_bytes + (P(pm)->base_x + x) * bpp), P(a1)->map, P(pm)->row_bytes, k5, k6, k7, k8, k9, bpp, k10);
    #undef P
}
//@ f_1802f0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1802f0
 * - Aufgabe im Spiel: Initialisiert einmalig über den DPMI-Interrupt 0x31 (Funktion 0x0002,
 *   Segment-in-Deskriptor-Umwandlung) die Protected-Mode-Selektoren für das Real-Mode-Segment 0x0000 (d_1b4590)
 *   und das VGA-Videospeichersegment 0xA000 (d_1b4592) und vermerkt die abgeschlossene Initialisierung im Flag
 *   d_1b4594.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globales Initialisierungs-Flag d_1b4594: Verhindert mehrfache DPMI-Aufrufe.
 *   - Globale Selektoren d_1b4590 (Segment 0) und d_1b4592 (VGA-Segment 0xA000).
 === Ende Beschreibung === */
void f_1802f0(void)
{
    extern short d_1b4594;
    extern volatile short d_1b4590;
    extern volatile short d_1b4592;
    extern short dpmi_seg(unsigned, unsigned);
#pragma aux dpmi_seg = "int 31h" parm [ebx] [eax] value [ax] modify exact [eax ebx];
    extern short dpmi_seg0(unsigned);
#pragma aux dpmi_seg0 = "mov ebx,0" "int 31h" parm [eax] value [ax] modify exact [eax ebx];
    do {
    if ((int)0 == d_1b4594) {
        d_1b4590 = dpmi_seg0(2);
        d_1b4592 = dpmi_seg(0xa000, 2);
        d_1b4594 = 1;
    }
    } while (0);
}
