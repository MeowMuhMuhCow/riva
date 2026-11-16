/* === Beschreibung (Katalog) ===
 * Einheit gz_01a9b0
 *
 * Diese Einheit implementiert die Kartennotiz-Verwaltung der Automap (amapanno.cpp, Adressbereich
 * 0x01a9b0-0x01b3b0, Objektgröße 14 Bytes, eingehängt im Automap-Objekt unter Offset +0x4f). Sie verwaltet bis
 * zu 500 benutzerdefinierte oder vom Spiel eingetragene Textnotizen je Karte in einer eigenen Spielstandsdatei
 * (Kennung "ANNO"): am Dateianfang steht ein 18-Byte-Kopf (0x12 Bytes), dahinter liegen alle nullterminierten
 * Notiztexte dicht hintereinander (base .. end), und am Dateiende ab Position hdr->end folgt die Eintragstabelle
 * mit n x 12 Bytes (je Eintrag: auf das 8er-Raster gerundete Koordinaten a, b, Textoffset off relativ zu base
 * und Textlänge len inklusive Nullbyte).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 12/17 gleich (suche.py 30.10.2026, Basis gz_01a9b0_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 4 gleich (vorher 4), Rest 432 (vorher 435)
// gz_01a9b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01A9B0-0x01B3B0
#include <string.h>
struct Hdr { char pad[8]; short n; int end; int base; };
struct Ent { unsigned short a; unsigned short b; int off; int len; };
struct Amap { int h; Hdr *hdr; Ent *ent; short cur; };
typedef unsigned short U16;
typedef short RT;
int f_01a880(Amap *p1);







extern int d_1bc758;


//@ f_01a9b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet die zur aktuellen Karte gehörende Notizdatei (p1->h) im Schreib-/Lesemodus
 *   (0x202), schreibt den 18-Byte-Kopfsatz (p1->hdr) an den Dateianfang und - sofern mindestens eine Notiz
 *   vorhanden ist (hdr->n > 0) - die gesamte Eintragstabelle (hdr->n * 12 Bytes aus p1->ent) an die
 *   Dateiposition hdr->end direkt hinter die Notiztexte.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf die Notizverwaltung (p1, Amap *) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: p1->h (+0x00) ist die Dateikennung, p1->hdr (+0x04) zeigt auf den 18-Byte-Kopf (mit
 *   Anzahl n an +0x08 und Tabellenposition end an +0x0a), p1->ent (+0x08) auf das Array für bis zu 500
 *   Notizeinträge und d_1c2098 ist der globale Dateimanager.
 === Ende Beschreibung === */
void f_01a9b0(Amap *p1)
{
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p1->h, 0x202);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144960((void *)( p1->hdr), 0x12)));
    if (p1->hdr->n > 0) {
        ((RivaFileManager*)(&d_1c2098))->f_144ab0( p1->hdr->end, 0);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144960((void *)( p1->ent), p1->hdr->n * 12)));
    }
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
}

//@ f_01aa30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion rundet die übergebenen Kartenpixel-Koordinaten (p2, p3) auf das 8x8-Pixel-Raster
 *   ab (& 0xfff8) und durchsucht die Eintragstabelle p1->ent[0..n-1] linear nach einer Notiz mit genau diesen
 *   Koordinaten.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *) sowie die Koordinaten p2 (X) und
 *   p3 (Y, jeweils unsigned short); sie gibt den gefundenen Eintragsindex (0..n-1) oder -1 zurück, falls dort
 *   keine Notiz liegt.
 * - Wichtige Variablen: Durchsucht wird das Array p1->ent bis zur Grenze p1->hdr->n.
 === Ende Beschreibung === */
short f_01aa30(Amap *p1, short p2, short p3)
{
    short r = -1;
    p2 &= ~7;
    p3 &= ~7;
    short i;
    for (i = 0; i < p1->hdr->n; i++) {
        if ((U16)p2 == p1->ent[i].a && (U16)p3 == p1->ent[i].b) {
            r = i;
            break;
        }
    }
    return r;
}

//@ f_01aa90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist der übergebene Index p2 kleiner als die Notizanzahl p1->hdr->n, kopiert die Funktion die
 *   gespeicherten X- und Y-Koordinaten des Eintrags p1->ent[p2] in die Ausgabeparameter *p3 und *p4.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), den Notizindex p2 (int) sowie
 *   die Ausgabezeiger p3 (X) und p4 (Y, jeweils unsigned short *); sie liefert 1 bei gültigem Index, sonst 0.
 * - Wichtige Variablen: Gelesen werden p1->ent[p2].a und p1->ent[p2].b. Hinweis (Originalfehler): Die Bedingung
 *   if ((short)p2 < p1->hdr->n) prüft nicht auf p2 >= 0; wird ein negativer Index (etwa -1) übergeben, liest die
 *   Funktion vor den Anfang des Arrays p1->ent und meldet fälschlich Erfolg (1).
 === Ende Beschreibung === */
int f_01aa90(Amap *p1, int p2, unsigned short *p3, unsigned short *p4)
{
    unsigned n;
    int r = 0;
    if ((short)p2 < p1->hdr->n) {
        *p3 = p1->ent[(short)p2].a;
        *p4 = p1->ent[(short)p2].b;
        r = 1;
    }
    return r;
}

//@ f_01aad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion ersetzt den Text der bestehenden Notiz index durch die neue Zeichenkette text:
 *   hat sich die Textlänge (strlen(text) + 1) gegenüber oldSize vergrößert oder verkleinert, wird im Textbereich
 *   der Notizdatei entsprechend Platz eingefügt (f_144b70) bzw. entfernt (f_144bb0), alle dahinterliegenden
 *   Textoffsets sowie das Textende hdr->end werden um die Längendifferenz angepasst, der neue Text wird
 *   geschrieben und Kopf samt Tabelle werden über f_01a9b0 gesichert.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung self (Amap *), den Eintragsindex index
 *   (short) und den neuen Text text (char *); sie gibt immer 1 zurück.
 * - Wichtige Variablen: Aktualisiert werden self->ent[index].len, die Offsets self->ent[i].off aller
 *   nachfolgenden Notizen sowie self->hdr->end.
 === Ende Beschreibung === */
int f_01aad0(Amap *self, short index, char *text)
{
    struct Adjust920 {
        static inline void move(Amap *self, unsigned origin, int difference) {
            short i;
            for(i=0;i<self->hdr->n;i++) {
                Ent *table=(i & 0) ? (Ent *)0 : self->ent; // Haelt das Tabellenzeiger-Web fuer die Original-Registerzuteilung in der Schleife
                Ent *entry=&table[i];
                if(origin<(unsigned)entry->off) entry->off=difference+entry->off;
            }
            self->hdr->end+=difference;
        }
    };
    Ent *first=(index & 0) ? (Ent *)0 : &self->ent[index]; // Trennt das Eingangs-Adressweb vom spaeteren Tabellenzeiger
    unsigned oldSize=first->len;
    unsigned newSize=strlen(text)+1;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0(self->h,0x202);
    if(oldSize<newSize) {
        ((RivaFileManager*)(&d_1c2098))->f_144b70(self->hdr->base+self->ent[index].off+oldSize,(void *)(0),newSize-oldSize);
        Adjust920::move(self,self->ent[index].off,newSize-oldSize);
        (*(int*)&d_1c2098) = ((*(int*)&d_1c2098) & 0) ? 0 : (*(int*)&d_1c2098); // Haelt die Registerfolge am Zweigende wie im Original
    } else if(oldSize>newSize) {
        ((RivaFileManager*)(&d_1c2098))->f_144bb0(self->hdr->base+self->ent[index].off+newSize,oldSize-newSize);
        Adjust920::move(self,self->ent[index].off,newSize-oldSize);
    }
    ((RivaFileManager*)(&d_1c2098))->f_144ab0(self->hdr->base+self->ent[index].off,0);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144960((void *)(text),newSize)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    self->ent[index].len=newSize;
    f_01a9b0(self);
    index = (index & 0) ? 0 : index; // Haelt die Lebensdauer von index bis zum Funktionsende fuer die Original-Registerwahl
    return 1;
}

//@ f_01ad00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Solange weniger als 500 Notizen auf der Karte eingetragen sind (hdr->n < 500), legt die
 *   Funktion am Tabellenende einen neuen Eintrag mit den auf 8 abgerundeten Koordinaten (p2 & ~7, p3 & ~7), dem
 *   aktuellen Textende (hdr->end - hdr->base) als Offset und der Textlänge strlen(p4) + 1 an, schreibt den Text
 *   p4 ans Ende des Textbereichs der Datei, schiebt hdr->end weiter und speichert Kopf und Tabelle über
 *   f_01a9b0.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), die Koordinaten p2 (X) und p3
 *   (Y, jeweils short) sowie den Text p4 (char *); sie gibt 1 zurück, wenn die Notiz angelegt wurde, oder 0,
 *   wenn bereits 500 Notizen vorhanden sind.
 * - Wichtige Variablen: Geändert werden p1->hdr->n, p1->hdr->end und der neue Eintrag p1->ent[c].
 === Ende Beschreibung === */
int f_01ad00(Amap *p1, short p2, short p3, char *p4)
{
    int r = 0;
    p2 &= ~7;
    p3 &= ~7;
    unsigned n;
    short c;
    n = strlen(p4) + 1;
    c = p1->hdr->n;
    if (c < 500) {
        int o = c * 12;
        p1->hdr->n++;
        *(unsigned short *)(o + (char *)p1->ent) = p2;
        *(unsigned short *)(o + 2 + (char *)p1->ent) = p3;
        *(int *)(o + 4 + (char *)p1->ent) = p1->hdr->end - p1->hdr->base;
        *(unsigned *)(o + 8 + (char *)p1->ent) = n;
        ((RivaFileManager*)(&d_1c2098))->f_1448b0( p1->h, 0x202);
        ((RivaFileManager*)(&d_1c2098))->f_144ab0( p1->hdr->base + p1->ent[c].off, 0);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144960((void *)( p4), n)));
        ((RivaFileManager*)(&d_1c2098))->f_1449a0();
        p1->hdr->end += n;
        f_01a9b0(p1);
        r = 1;
    }
    return r;
}

//@ f_01ae60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schneidet den Text der Notiz p2 per f_144bb0 aus der Notizdatei heraus,
 *   verschiebt die Textoffsets aller dahinterliegenden Notizen sowie hdr->end um die gelöschte Textlänge nach
 *   vorn, lässt die nachfolgenden Tabelleneinträge ent[p2 + 1 .. n - 1] um einen Platz aufrücken, verringert
 *   hdr->n um 1 und schreibt Kopf und Tabelle neu in die Datei.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *) sowie den zu löschenden Index p2
 *   (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Aktualisiert werden p1->hdr->n, p1->hdr->end, p1->ent und die Notizdatei p1->h.
 === Ende Beschreibung === */
static inline void h_shift01(Amap *q, Ent *pe)
{
    int len = -pe->len;
    (*(int*)&d_1c2098) = ((*(int*)&d_1c2098) & 0) ? 0 : (*(int*)&d_1c2098); // Haelt die Registerzuteilung beim Inline-Einsetzen wie im Original
    unsigned off = pe->off;
    short i;
    for (i = 0; i < q->hdr->n; i++) {
        if (off < (unsigned)q->ent[i].off)
            q->ent[i].off += len;
    }
    q->hdr->end += len;
}

void f_01ae60(Amap *p1, int p2)
{
    short i;
    int off;
    int len;

    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p1->h, 0x202);
    len = p1->ent[(short)p2].len;
    off = p1->hdr->base + p1->ent[(short)p2].off;
    ((RivaFileManager*)(&d_1c2098))->f_144bb0( off, len);
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    h_shift01(p1, &p1->ent[(short)p2]);
    for (i = p2 + 1; i < p1->hdr->n; i++)
        p1->ent[i - 1] = p1->ent[i];
    p1->hdr->n--;
    f_01a9b0(p1);
}
//@ f_01afa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor setzt die Zeiger hdr und ent auf 0, stellt den Iteratorzähler cur auf -1,
 *   markiert über das globale Flag d_1bc758 = 1, dass eine Notizverwaltung aktiv ist, speichert die übergebene
 *   Dateikennung p2 in p1->h und lädt bzw. erzeugt die Notizdatei über f_01a880 (AMAPANNO.CPP).
 * - Eingaben und Rückgabe: Die Funktion erhält das neu angelegte Objekt p1 (Amap *, this) und die Dateikennung
 *   p2 (int, in der Regel (fid + 7) | 0x40000000) und gibt p1 zurück.
 * - Wichtige Variablen: Initialisiert werden p1->h, p1->hdr, p1->ent, p1->cur und das globale Aktiv-Flag
 *   d_1bc758.
 === Ende Beschreibung === */
Amap *f_01afa0(Amap *p1, int p2)
{
    p1->hdr = 0;
    p1->ent = 0;
    p1->cur = -1;
    d_1bc758 = 1;
    p1->h = p2;
    f_01a880(p1);
    return p1;
}

//@ f_01afd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Destruktor sichert den Dateikopf und die Eintragstabelle ein letztes Mal über f_01a9b0,
 *   gibt das Eintragsarray p1->ent und den Kopfsatz p1->hdr frei und setzt das globale Aktiv-Flag d_1bc758
 *   wieder auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Objekt p1 (Amap *, this) sowie das ungenutzte
 *   Watcom-Destruktorflag kp2 (int) und gibt p1 zurück.
 * - Wichtige Variablen: Freigegeben werden p1->ent und p1->hdr; zurückgesetzt wird d_1bc758.
 === Ende Beschreibung === */
Amap *f_01afd0(Amap *p1, int kp2)
{
    f_01a9b0(p1);
    operator delete(p1->ent);
    operator delete(p1->hdr);
    d_1bc758 = 0;
    return p1;
}

//@ f_01b060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist mindestens eine Notiz vorhanden (hdr->n != 0), schreibt die Funktion die Koordinaten der
 *   ersten Notiz (ent[0].a, ent[0].b) in *p2 und *p3, stellt den internen Iterator p1->cur auf 1 und gibt 1
 *   zurück; bei leerer Liste setzt sie cur = -1 und liefert 0.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *) sowie die Ausgabezeiger p2 (X)
 *   und p3 (Y, jeweils unsigned short *); sie gibt 1 zurück, wenn eine erste Notiz existiert, sonst 0.
 * - Wichtige Variablen: Genutzt werden p1->hdr->n, p1->ent[0] und der Iterator p1->cur (+0x0c).
 === Ende Beschreibung === */
short f_01b060(Amap *p1, unsigned short *p2, unsigned short *p3)
{
    int r = 0;
    if (p1->hdr->n == 0) {
        p1->cur = -1;
        return r;
    }
    *p2 = p1->ent->a;
    *p3 = p1->ent->b;
    r = 1;
    p1->cur = 1;
    return r;
}

//@ f_01b0a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Solange der Iterator p1->cur kleiner als die Notizanzahl p1->hdr->n ist, gibt die Funktion die
 *   Koordinaten des Eintrags p1->ent[p1->cur] über *p2 und *p3 zurück, erhöht p1->cur um 1 und liefert 1; am
 *   Tabellenende gibt sie 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *) sowie die Ausgabezeiger p2 (X)
 *   und p3 (Y, jeweils unsigned short *) und liefert 1 bei einem weiteren Eintrag, sonst 0.
 * - Wichtige Variablen: Genutzt werden p1->cur, p1->hdr->n und p1->ent.
 === Ende Beschreibung === */
int f_01b0a0(Amap *p1, unsigned short *p2, unsigned short *p3)
{
    int r = 0;
    if (p1->cur < p1->hdr->n) {
        *p2 = p1->ent[p1->cur].a;
        *p3 = p1->ent[p1->cur].b;
        p1->cur = p1->cur + 1;
        r = 1;
    }
    return r;
}

//@ f_01b100
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion berechnet, wie viele Notizeinträge bis zur festen Obergrenze von 500 Plätzen noch
 *   frei sind (500 - p1->hdr->n).
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *) und gibt die Anzahl freier Plätze
 *   (short) zurück.
 * - Wichtige Variablen: Gelesen wird p1->hdr->n.
 === Ende Beschreibung === */
short f_01b100(Amap *p1)
{
    return 500 - p1->hdr->n;
}

//@ f_01b120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion prüft, ob die aktuelle Anzahl der Notizen p1->hdr->n kleiner als 500 ist.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *) und gibt 1 zurück, wenn noch
 *   Platz ist, sonst 0.
 * - Wichtige Variablen: Gelesen wird p1->hdr->n.
 === Ende Beschreibung === */
int f_01b120(Amap *p1)
{
    int r = 0;
    if (p1->hdr->n < 500)
        r = 1;
    return r;
}

//@ f_01b140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion rundet die übergebenen Koordinaten (p2, p3) auf das 8er-Raster ab und prüft in
 *   der Eintragstabelle p1->ent, ob an dieser Stelle bereits eine Notiz eingetragen ist.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), die X-Koordinate p2 (int) und
 *   die Y-Koordinate p3 (short); sie gibt 1 zurück, wenn dort eine Notiz steht, sonst 0.
 * - Wichtige Variablen: Durchsucht wird p1->ent[0 .. hdr->n - 1].
 === Ende Beschreibung === */
static inline short find1330(Amap *p, short y, short x)
{
    short r = -1;
    x &= ~7;
    y &= ~7;
    short i;
    for (i = 0; i < p->hdr->n; i++) {
        int offset = i;
        offset *= sizeof(Ent);
        Ent *e = (Ent *)(offset + (char *)p->ent);
        if (e->a == (U16)x && (U16)y == e->b) {
            r = i;
            break;
        }
    }
    return r;
}
short f_01b140(Amap *p1, int p2, short p3)
{
    int result = 0;
    if (find1330(p1, p3, p2) >= 0) result = 1;
    return result;
}

//@ f_01b1b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist der übergebene Notizindex p3 >= 0, öffnet die Funktion die Notizdatei p1->h im Lesemodus
 *   (0x200), positioniert den Dateizeiger auf hdr->base + ent[p3].off, liest ent[p3].len Bytes in den Zielpuffer
 *   p2 und schließt die Datei wieder.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), den Zielpuffer p2 (void *, im
 *   Kartenbildschirm d_1c21b4) und den Eintragsindex p3 (short); sie liefert 1 bei Erfolg (p3 >= 0), sonst 0.
 * - Wichtige Variablen: Genutzt werden p1->h, p1->hdr->base, p1->ent[p3].off und p1->ent[p3].len.
 === Ende Beschreibung === */
int f_01b1b0(Amap *p1, void *p2, short p3)
{
    int r = 0;
    if (p3 >= 0) {
        ((RivaFileManager*)(&d_1c2098))->f_1448b0( p1->h, 0x200);
        int o = p3 * 12;
        ((RivaFileManager*)(&d_1c2098))->f_144ab0( p1->hdr->base + *(int *)((char *)p1->ent + o + 4), 0);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p2), *(int *)(o + (char *)p1->ent + 8))));
        ((RivaFileManager*)(&d_1c2098))->f_1449a0();
        r = 1;
    }
    return r;
}

//@ f_01b230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion sucht zunächst über die auf 8 abgerundeten Koordinaten (p3, p4) den passenden
 *   Notizeintrag in p1->ent; wird einer gefunden (r >= 0), liest sie dessen Text genau wie f_01b1b0 aus der
 *   Notizdatei in den Zielpuffer p2.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), den Zielpuffer p2 (void *) sowie
 *   die Koordinaten p3 (X) und p4 (Y, jeweils short); sie gibt 1 zurück, wenn eine Notiz gefunden und gelesen
 *   wurde, sonst 0.
 * - Wichtige Variablen: Genutzt werden p1->ent, p1->hdr->base und d_1c2098.
 === Ende Beschreibung === */
static inline short h_aa30(Amap *p1, short p2, short p3)
{
    short r = -1;
    p2 &= ~7;
    p3 &= ~7;
    short i;
    for (i = 0; i < p1->hdr->n; i++) {
        Ent *e = &p1->ent[i];
        if ((U16)p2 == e->a && (U16)p3 == e->b) {
            r = i;
            break;
        }
    }
    return r;
}

int f_01b230(Amap *p1, void *p2, short p3, short p4)
{
    RT r = h_aa30(p1, p3, p4);
    int result = 0;
    if (r >= 0) {
        ((RivaFileManager*)(&d_1c2098))->f_1448b0( p1->h, 0x200);
        int o = r * 12;
        ((RivaFileManager*)(&d_1c2098))->f_144ab0( p1->hdr->base + *(int *)((char *)p1->ent + o + 4), 0);
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p2), *(int *)(o + (char *)p1->ent + 8))));
        ((RivaFileManager*)(&d_1c2098))->f_1449a0();
        result = 1;
    }
    return result;
}

//@ f_01b2f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist ein gültiger Notizindex p2 >= 0 angegeben, ersetzt die Funktion den Text dieser
 *   bestehenden Notiz über f_01aad0; ist p2 < 0, legt sie stattdessen über f_01ad00 eine neue Notiz an den
 *   Koordinaten (p4, p5) an.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), den Notizindex p2 (int), den
 *   Text p3 (char *) sowie die Koordinaten p4 (X) und p5 (Y, jeweils int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Delegiert an f_01aad0 bzw. f_01ad00.
 === Ende Beschreibung === */
void f_01b2f0(Amap *p1, int p2, char *p3, int p4, int p5)
{
    if ((short)p2 >= 0) {
        f_01aad0(p1, (short)p2, p3);
        return;
    }
    f_01ad00(p1, (short)p4, (short)p5, p3);
}

//@ f_01b320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion sucht in p1->ent, ob an den auf das 8er-Raster abgerundeten Koordinaten (p2, p3)
 *   bereits eine Notiz existiert: falls ja (r >= 0), wird deren Text über f_01aad0 durch p4 ersetzt; falls nein,
 *   wird über f_01ad00 ein neuer Notizeintrag an (p2, p3) angelegt.
 * - Eingaben und Rückgabe: Die Funktion erhält die Notizverwaltung p1 (Amap *), die Koordinaten p2 (X) und p3
 *   (Y, jeweils int) sowie den Text p4 (char *); sie gibt 1 zurück, wenn die Notiz gespeichert wurde, oder 0,
 *   wenn die Tabelle bei einer Neuanlage voll war.
 * - Wichtige Variablen: Durchsucht wird p1->ent[0 .. hdr->n - 1], gespeichert wird über f_01aad0 bzw. f_01ad00.
 === Ende Beschreibung === */
int f_01b320(Amap *p1, int p2, int p3, char *p4)
{
    RT r;
    short x;
    short y;
    short i;
    Amap *q;

    r = -1;
    x = p2;
    y = p3;
    p1 = ((unsigned)p1 & 0) ? (Amap *)0 : p1; // Trennt das Objektzeiger-Web wie beim Inline-Einsetzen von f_01aa30
    q = p1;
    x &= ~7;
    y &= ~7;
    for (i = 0; i < q->hdr->n; ++i) {
        if ((U16)x == q->ent[i].a && (U16)y == q->ent[i].b) {
            r = i;
            break;
        }
    }
    int tested = r;
    if (tested >= 0)
        tested = f_01aad0(p1, r, (*&p4));
    else
        tested = f_01ad00(p1, (short)p2, (short)p3, p4);
    return tested;
}
