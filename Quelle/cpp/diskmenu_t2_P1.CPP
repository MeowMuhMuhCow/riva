/* === Beschreibung (Katalog) ===
 * Einheit diskmenu_t2 (0x05d0d0 - 0x05dec0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von diskmenu.cpp und stellt die Zeichen-, Scroll-, Beschreibungs- und
 * Dateinamen-Hilfsfunktionen für das Laden-/Speichern-Menü bereit, darunter das Lesen und Speichern des
 * 256-Byte-Beschreibungstextes (DESC), das Anlegen eines neuen Spielstands und die Knopf-Druckanimation.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 11/16 gleich (suche.py 26.10.2026, Basis diskmenu_t2_P1.CPP)
// diskmenu.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil 2, Code 0x05D0D0-0x05DEC0
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
#define A(x) ((int)&(x))
typedef RivaTextContextData Msg;
#define CXI(m) f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
struct Gx { int v[3]; };
struct Dsk { char p0[0xc]; int f0c; char hdr[12]; char b1c, b1d, b1e, b1f; short w20, w22, w24, w26, fd; char p2a[0x100]; char names[100][13]; char cur[18]; short cnt; };
long f_145279(int h, long pos, int whence);
int f_144e8b(int h, void *buf, unsigned n);
int f_144cb6(int h, const void *buf, unsigned n);
int f_144fbf(const char *name, int mode, ...);
int f_145259(int h);
int f_14572e(char *, const char *, ...);
int f_14d0d7(char *name, int mode);
int f_0d3860();
int f_0d2710();
int f_0d26e0();
int f_1483f0(int p1, int p2, int p3, int p4, int p5);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_133fe0(int p1, int p2);





int f_05e320(int p1, int p2, int p3);
int f_0e9660(int p1, int p2, int p3, int p4);
int f_050580(int p1, int p2, int p3, short *p4, short *p5);
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, short *p7, short *p8, int p9);
int f_0d4800(int p1);
int f_0d4850(int p1, int p2, int p3);
unsigned f_0ce0f0(int p1);
short f_0de7f0(int p1);
short f_0bfea0(int p1, int p2, int p3);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_05b2c0(Dsk *p1);
int f_05b230(Dsk *p1);
int f_0619e0(int p1, void *p2);
extern int d_1a34e0;
extern const char *d_1a9678;
extern char d_1a9693;
extern const char d_1a9680[];
extern short d_1a17d4[];
extern short d_1bd766;
extern short d_1bd760;
extern unsigned short d_1c20b0;
extern signed char d_1bbfdc[];
extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c299c[];
extern int d_1c2be0;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3498;
extern int d_1c3870;
extern int d_1c38b0;
extern int d_1c0004;
extern const char d_1b6ee7[];
extern const char d_1b6efb[];
extern const char d_1b6f00[];
extern const char d_1b6f05[];
extern const char d_1b6f0a[];
extern const char d_1b6f0f[];
extern const char d_1b6f15[];
int f_05d370(Dsk *p1, int p2);
short f_05d460(Dsk *p1, int p2);
void f_05da10(char *p1, const char *p2);
#define FLG(fl) if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0
#define CT signed char
struct Guard {
    int flag;
    Guard() { if (f_0d3860() == 1) { f_0d2710(); flag = 1; } else flag = 0; }
    ~Guard() { if (flag == 1) f_0d26e0(); }
};

//@ f_05d0d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Liste der Spielstandnamen auf der linken Seite des Diskmenüs neu: löscht das
 *   Listenfeld (56x83 Pixel bei (31, 58)) mit der Hintergrundfarbe 0xce und gibt ab der ersten sichtbaren Zeile
 *   p1->w26 bis zu 10 Spielstandnamen untereinander aus, wobei die aktuelle Cursorzeile p1->w22 in Farbe 0xd8
 *   und alle übrigen Zeilen in Farbe 0xda erscheinen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt (Dsk) und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: In p1 geben w26 die oberste sichtbare Zeile, w22 die Cursorzeile (0..9), w20 die
 *   Zeilenhöhe in Pixeln und cnt die Gesamtzahl der Spielstände an.
 === Ende Beschreibung === */
void f_05d0d0(Dsk *p1)
{
    Gx g; short i; short x; short y; short row;
    ((int)(((RivaRasterImage*)(&g))->f_0fac80( 0x38, 0x53)));
    {
        Guard guard;
        ((RivaRasterImage*)(&g))->f_0fb150( 0xce);
        y = p1->w26;
        if (p1->cnt - 10 > 0 && y > p1->cnt - 10) y = p1->cnt - 10;
        ((RivaRasterImage*)(&g))->f_0fade0((void *)( d_1a34e0), 0x1f, 0x3a);
        row = y;
        x = 0x3c;
        for (i = 0; i < (short)10 && i < p1->cnt; i++) {
            f_05e320(A(d_1c38b0), (short)(i == p1->w22 ? 0xd8 : 0xda), 0xce);
            f_0e9660(A(d_1c38b0), (int)&p1->names[row], 0x22, x);
            x += p1->w20;
            row++;
        }
        f_05e320(A(d_1c38b0), 0xda, 0xce);
    }
    ((int)(((RivaRasterImage*)(&g))->f_0fad20( 0)));
}

//@ f_05d210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der sortierten Namenstabelle p1->names nach dem in p1->cur gespeicherten Dateinamen
 *   (etwa nach dem Anlegen eines neuen Spielstands) und rückt die Cursorzeile p1->w22 sowie ab Zeile 10 den
 *   Scrollversatz p1->w26 schrittweise vor, bis der gesuchte Eintrag markiert ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Vergleicht p1->names[k] mit dem Zielnamen p1->cur und begrenzt p1->w26 nach oben auf
 *   p1->cnt - 10.
 === Ende Beschreibung === */
void f_05d210(Dsk *p1)
{
    short i = 0;
    for (;;) {
        short u;
        int lim;
        int k = i;
        i++;
        if (strcmp(p1->names[k], p1->cur) == 0) break;
        if (++p1->w22 < (short)10) continue;
        p1->w22 = 9;
        u = p1->w26 + 1;
        lim = p1->cnt - 10;
        p1->w26 = u;
        if (lim > 0 && u > lim) p1->w26 = p1->cnt - 10;
    }
}

//@ f_05d280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Rollt die Spielstandliste um eine Zeile nach unten (p1->w26++), höchstens jedoch bis p1->cnt -
 *   10, sofern mehr als 10 Spielstände vorhanden sind.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Verändert die erste sichtbare Zeile p1->w26 anhand der Gesamtanzahl p1->cnt.
 === Ende Beschreibung === */
void f_05d280(Dsk *p1)
{
    p1->w26++;
    int lim = p1->cnt - 10;
    if (lim > 0 && p1->w26 > lim) p1->w26 = p1->cnt - 10;
}

//@ f_05d2b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Rollt die Spielstandliste als Gegenstück zu f_05d280 um eine Zeile nach oben (p1->w26 - 1),
 *   jedoch nicht unter 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Begrenzt den Scrollversatz p1->w26 nach unten auf 0.
 === Ende Beschreibung === */
void f_05d2b0(Dsk *p1)
{
    short t = p1->w26 - 1;
    p1->w26 = t;
    if (t < 0) p1->w26 = 0;
}

//@ f_05d2d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt ab Dateiversatz 0x10 der bereits geöffneten Spielstanddatei p1->fd die 4-Byte-Kennung
 *   "DESC" (d_1b6efb) sowie den 256-Byte-Beschreibungstext p1->p2a.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt die Summe der
 *   geschriebenen Bytes (im Normalfall 260) zurück.
 * - Wichtige Variablen: Das Feld p1->p2a[0x100] enthält die 6 Zeilen des im Editor eingegebenen
 *   Beschreibungstextes.
 === Ende Beschreibung === */
int f_05d2d0(Dsk *p1)
{
    f_145279(p1->fd, 0x10, 0);
    int a = f_144cb6(p1->fd, d_1b6efb, 4);
    int b = f_144cb6(p1->fd, p1->p2a, 0x100);
    return b + a;
}

//@ f_05d320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest als Gegenstück zu f_05d2d0 ab Dateiversatz 0x10 der geöffneten Spielstanddatei p1->fd
 *   die 4-Byte-Kennung "DESC" sowie den 256-Byte-Beschreibungstext in den Puffer p1->p2a ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt die Summe der
 *   gelesenen Bytes zurück.
 * - Wichtige Variablen: Liest über p1->fd in ein lokales 4-Byte-Feld hdr4 und den Beschreibungspuffer p1->p2a.
 === Ende Beschreibung === */
int f_05d320(Dsk *p1)
{
    char hdr4[4];
    f_145279(p1->fd, 0x10, 0);
    int a = f_144e8b(p1->fd, hdr4, 4);
    int b = f_144e8b(p1->fd, p1->p2a, 0x100);
    return b + a;
}

//@ f_05d370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die bestehende Spielstanddatei ..\GAMES\<Name>.GAM des Listeneintrags p2 zum Schreiben
 *   (0x201), aktualisiert an Dateiversatz 0x10 den "DESC"-Block mit dem geänderten Beschreibungstext p1->p2a,
 *   schließt die Datei wieder und setzt p1->w24 = -1 (keine ungesicherte Beschreibung mehr offen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und den Listenindex p2. Sie
 *   gibt die Anzahl der geschriebenen Bytes (260 bei Erfolg, 0 bei Fehler) zurück.
 * - Wichtige Variablen: Das Feld p1->w24 merkt den Index des Eintrags, dessen Beschreibung gerade bearbeitet
 *   wurde, und wird nach dem Speichern auf -1 zurückgesetzt.
 === Ende Beschreibung === */
int f_05d370(Dsk *p1, int p2)
{
    char buf[40];
    char name[16];
    int r = 0;
    strcpy(name, p1->names[(short)p2]);
    strcat(name, d_1b6f00);
    f_14572e(buf, d_1a9678, name);
    ;
    short fd = f_144fbf(buf, 0x201);
    p1->fd = fd;
    if (fd != -1) {
        f_145279(fd, 0x10, 0);
        int a = f_144cb6(p1->fd, d_1b6f05, 4); int b = f_144cb6(p1->fd, p1->p2a, 0x100); r += a; r += b;
        f_145259(p1->fd);
        p1->w24 = -1;
    }
    return r;
}

//@ f_05d460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die Spielstanddatei ..\GAMES\<Name>.GAM des Listeneintrags p2 lesend, prüft über
 *   f_05b2c0, ob es sich um einen gültigen Spielstand der Version 3 ("DSA VERSION", b1e == 3) handelt, und liest
 *   bei Erfolg den 256-Byte-Beschreibungstext in p1->p2a ein. Gehört die Datei zu einer älteren oder fremden
 *   Version, werden das Beschreibungsfeld auf dem Bildschirm und der Puffer p1->p2a geleert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und den Listenindex p2. Sie
 *   gibt bei gültigem Spielstand die gelesene Byteanzahl (260) als short zurück, sonst 0.
 * - Wichtige Variablen: Prüft p1->hdr gegen d_1a9680 ("DSA VERSION") und p1->b1e gegen d_1a9693 (3).
 === Ende Beschreibung === */
short f_05d460(Dsk *p1, int p2)
{
    char buf[40];
    char name[16];
    char hdr4[4];
    int fl;
    short res = 0;
    strcpy(name, p1->names[(short)p2]);
    strcat(name, d_1b6f0a);
    f_14572e(buf, d_1a9678, name);
    short fd = f_144fbf(buf, 0x200);
    p1->fd = fd;
    if (fd != -1) {
        f_05b2c0(p1);
        f_145279(p1->fd, 0, 0);
        if (strcmp(p1->hdr, d_1a9680) != 0 || p1->b1e != d_1a9693) {
            f_145259(p1->fd);
            FLG(fl);
            short y = 0x3a;
            short i;
            for (i = 0; i < 0x31; i++) {
                f_1483f0(d_1a34e0, 0x76, y, 0xa9, -50);
                y++;
            }
            void *ms(void *, int, unsigned);
            #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
            ms(p1->p2a, 0, 0x100);
            if (fl == (short)1) f_0d26e0();
        } else {
            f_145279(p1->fd, 0x10, 0);
            int a = f_144e8b(p1->fd, hdr4, 4);
            short b = f_144e8b(p1->fd, p1->p2a, 0x100);
            res = a + b;
            f_145259(p1->fd);
        }
    }
    return res;
}

//@ f_05d600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft vor dem Anlegen eines neuen Spielstands, ob der auf 8 Zeichen normierte Name p2 bereits
 *   in der Spielstandliste p1->names (0..p1->cnt - 1) vorkommt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und den zu suchenden Namen
 *   p2. Sie gibt 1 zurück, wenn der Name bereits existiert, sonst 0.
 * - Wichtige Variablen: Durchläuft die ersten p1->cnt Einträge von p1->names.
 === Ende Beschreibung === */
int f_05d600(Dsk *p1, char *p2)
{
    int r = 0;
    short i = 0;
    for (i = 0; i < p1->cnt; i++) {
        if (strcmp(p2, p1->names[i]) == 0) { r = 1; break; }
    }
    return r;
}

//@ f_05d650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt den Knopf "Neu" im Diskmenü: bricht mit einer Meldung ab, wenn bereits 100
 *   Spielstände existieren (0x903000e), weniger als 1 MB Festplattenplatz frei ist (0x9030010) oder die aktive
 *   Gruppe leer ist (0x9030015). Andernfalls fragt die Funktion einen bis zu 8 Zeichen langen Dateinamen ab
 *   (0x9030001), bereinigt ihn über f_05da10, weist den reservierten Namen "START" zurück (0x903001e), holt bei
 *   bereits vorhandenem Namen eine Überschreibbestätigung (0x903000f) ein und legt schließlich die neue
 *   .GAM-Datei mit Versionskopf und leerem DESC-Block an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt 1 zurück, wenn die
 *   neue Datei angelegt wurde, oder 0 bei Abbruch.
 * - Wichtige Variablen: Das Feld p1->cur speichert den neu vergebenen, auf 8 Zeichen aufgefüllten Namen, damit
 *   die Liste danach auf diesen Eintrag positioniert werden kann.
 === Ende Beschreibung === */
int f_05d650(Dsk *p1)
{
    int result = 0, accepted = 0;
    char path[100];
    Msg m;
    char stem[16], name[16];
    CXI(m);
    unsigned avail = f_0ce0f0(0);
    int done = 0;
    if (p1->cnt == (short)100) {
        f_0bf730(A(d_1c2c64), 0x903000e);
        goto finish;
    }
    if (avail < 0x100000) {
        f_0bf730(A(d_1c2c64), 0x9030010);
        goto finish;
    }
    if (f_0de7f0(d_1c0004) == (short)0) {
        f_0bf730(A(d_1c2c64), 0x9030015);
        goto finish;
    }
    if (p1->w24 != -1) {
        f_05d370(p1, (short)(p1->w24 + p1->w26));
    }
    {
        for (;;) {
            if (done) break;
            if (f_0bfea0(A(d_1c2c64), 8, 0x9030001) != -1) {
                f_05da10(name, d_1c299c);
                strcpy(p1->cur, name);
                f_0d4850((int)p1->cur, 8, 0x20);
                strcpy(stem, name);
                char *q = strchr(stem, ' ');
                if (q) *q = 0;
                else if ((q = strchr(stem, '.')) != 0) *q = 0;
                m.tables.tail.numbers[1] = f_133fe0(A(d_1c3498), (int)stem);
                if (!stricmp(stem, d_1b6f0f)) {
                    f_0bf730(A(d_1c2c64), 0x903001e);
                } else {
                    int found = f_05d600(p1, p1->cur);
                    if (!found || f_0bf6f0(A(d_1c2c64), 0x903000f) == 1) {
                        done = 1;
                        accepted = 1;
                    }
                }
            } else done = 1;
        }
    }
    if (accepted) {
        strcat(name, d_1b6f15);
        f_14572e(path, d_1a9678, name);
        char *header = p1->p2a;
        memset(header, 0, 0x100);
        short fd = f_14d0d7(path, 0);
        Dsk *disk = p1;
        disk->fd = fd;
        if (fd != -1) {
            f_05b230(disk);
            f_145279(disk->fd, 0x10, 0);
            f_144cb6(p1->fd, d_1b6efb, 4);
            f_144cb6(p1->fd, header, 0x100);
            f_145259(p1->fd);
            result = 1;
        }
    }
finish:
    f_1254a0((int)&m, 0);
    return result;
}

//@ f_05da10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen vom Spieler eingegebenen Dateinamen p2 nach p1, kürzt ihn auf maximal 8 Zeichen
 *   und ersetzt in der deutschen Spielversion (d_1c20b0 == 1) alle Sonderzeichen, die weder Buchstaben oder
 *   Ziffern (d_1bbfdc) noch deutsche DOS-Umlaute (Ä, Ö, Ü, ß) sind, durch einen Unterstrich '_'.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielpuffer p1 (mindestens 9 Bytes) und den Eingabestring p2.
 *   Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1c20b0 kennzeichnet die Sprachversion (1 = Deutsch), d_1bbfdc ist
 *   die Zeichenklassentabelle (ctype) der Laufzeitbibliothek.
 === Ende Beschreibung === */
void f_05da10(char *p1, const char *p2)
{
    strcpy(p1, p2);
    short i;
    for (i = 0; i < 8; i++) {
        CT c = p1[i];
        if (c && (d_1bbfdc[(unsigned char)(c + 1)] & 0xe0) == 0 && d_1c20b0 == 1 &&
            c != (CT)0x99 && c != (CT)0x8e && c != (CT)0x9a && c != (CT)0xe1)
            p1[i] = '_';
    }
    p1[8] = 0;
}

//@ f_05da90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert eine eventuell noch offene Beschreibung (p1->w24 != -1) über f_05d370, löscht das
 *   Beschreibungsfeld auf dem Bildschirm, lädt die Beschreibung des aktuell unter dem Cursor stehenden
 *   Spielstands (w22 + w26) über f_05d460 und zeigt sie im Texteditor-Feld p1->f0c (f_0619e0) an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Verwendet p1->w24 (offener Beschreibungseintrag), p1->w22 (Cursorzeile), p1->w26
 *   (oberste Zeile) und p1->f0c (Editor-Objekt).
 === Ende Beschreibung === */
void f_05da90(Dsk *p1)
{
    struct Clear {
        static inline void run(Dsk *self) {
            Guard guard;
            short y = 0x3a;
            short i;
            for (i = 0; i < 0x31; i++) {
                f_1483f0(d_1a34e0, 0x76, y, 0xa9, -50);
                y++;
            }
            memset(self->p2a, 0, 0x100);
        }
    };
    if (p1->w24 != -1) f_05d370(p1, (short)(p1->w24 + p1->w26));
    Clear::run(p1);
    f_05d460(p1, (short)(p1->w22 + p1->w26));
    f_0619e0(p1->f0c, p1->p2a);
}

//@ f_05db50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übermalt das Beschreibungsfeld auf dem Bildschirm (169x49 Pixel ab (118, 58)) mit der
 *   Hintergrundfarbe 0xce und füllt den 256-Byte-Beschreibungspuffer p1->p2a komplett mit Nullbytes.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Zeichnet über f_1483f0 49 waagrechte Linien in den VGA-Bildschirmspeicher d_1a34e0.
 === Ende Beschreibung === */
void f_05db50(Dsk *p1)
{
    Guard guard;
    short y = 0x3a;
    short i;
    for (i = 0; i < 0x31; i++) {
        f_1483f0(d_1a34e0, 0x76, y, 0xa9, -50);
        y++;
    }
    memset(p1->p2a, 0, 0x100);
}

//@ f_05dbd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die .GAM-Datei des aktuell ausgewählten Spielstands (w22 + w26) im Lese-/Schreibmodus,
 *   liest das erste Byte und schreibt es unverändert zurück, damit das Betriebssystem den Änderungszeitstempel
 *   der Datei auf die aktuelle Uhrzeit setzt und der Spielstand beim nächsten Öffnen des Diskmenüs ganz oben
 *   steht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Nutzt die globalen Pfadpuffer d_1c21b4 und d_1c27a8 zum Zusammensetzen des Dateipfads
 *   ..\GAMES\<Name>.GAM.
 === Ende Beschreibung === */
void f_05dbd0(Dsk *p1)
{
    char b;
    strcpy(d_1c21b4, p1->names[p1->w22 + p1->w26]);
    strcat(d_1c21b4, d_1b6ee7);
    f_14572e(d_1c27a8, d_1a9678, d_1c21b4);
    short fd = f_144fbf(d_1c27a8, 2);
    int h = fd;
    f_144e8b(h, &b, 1);
    f_145279(h, 0, 0);
    f_144cb6(h, &b, 1);
    f_145259(h);
}

//@ f_05dca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht eine Schaltflächentabelle p1 (mit je 5 short-Werten x1, y1, x2, y2, Code pro
 *   Eintrag bis zur Endmarke x1 == -1) nach dem Aktionscode p2 und gibt dessen Tabellenindex zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Schaltflächentabelle (d_1a17d4) und den
 *   gesuchten Aktionscode p2. Sie gibt den 0-basierten Index des letzten passenden Eintrags oder -1 zurück.
 * - Wichtige Variablen: Prüft in jedem 5-short-Satz das fünfte Element p1[4] gegen p2.
 === Ende Beschreibung === */
int f_05dca0(short *p1, short p2)
{
    int r = -1;
    int n = 0;
    while (*p1 != -1) {
        if (p2 == p1[4]) r = n;
        p1 += 5;
        n++;
    }
    return r;
}

//@ f_05dcd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt für die Diskmenü-Schaltflächen 0x83..0x8c eine kurze Eindrück-Animation dar: ermittelt
 *   die Knopfposition über f_05dca0 in d_1a17d4, lädt das normale und das gedrückte Knopfbild aus dem NVF-Archiv
 *   0x90004, zeichnet für 7 Zeiteinheiten (f_0d4800) das gedrückte Bild und danach wieder das normale Bild auf
 *   den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 und den Aktionscode p2 der
 *   betätigten Schaltfläche. Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globalen Variablen d_1bd766 (letzter Tastencode) und d_1bd760
 *   (9-Zeilen-Schnellschritt) werden über die Wartepause f_0d4800(7) hinweg in lokalen Variablen gesichert und
 *   wiederhergestellt.
 === Ende Beschreibung === */
struct DE { short x, y, a, b, id; };
void f_05dcd0(int p1, short p2)
{
    Gx g2;
    short w;
    short e0;
    short sv1 = d_1bd766;
    short e1;
    Gx g1;
    short sv2 = d_1bd760;
    short ten;
    short h;
    if (p2 >= 0x83 && p2 < 0x8d) {
        short idx;
        ten = 10;
        if (sv2 && (p2 == 0x83 || p2 == 0x85)) p2++;
        idx = (short)f_05dca0(d_1a17d4, p2);
        { short rt = ten; ten = rt; }   // Codeloser Roundtrip dreht die Stapelplatz-Sortierung (ten nach 0x28)
        p2 -= 0x82;
        e0 = ((DE *)d_1a17d4)[idx].x;
        e1 = ((DE *)d_1a17d4)[idx].y;
        { short rt = e0; e0 = rt; } { short rt = e1; e1 = rt; }   // Haelt e0/e1 auf ihren Stapelplaetzen
        f_050580(A(d_1c2be0), 0x90004, p2, &w, &h);
        ((int)(((RivaRasterImage*)(&g1))->f_0fac80( w, h)));
        ((int)(((RivaRasterImage*)(&g2))->f_0fac80( w, h)));
        f_04feb0(A(d_1c2be0), 0x90004, ((int)(((RivaRasterImage*)(&g1))->f_0fb0b0())), 0, p2, 0, &w, &h, 0x140);
        f_04feb0(A(d_1c2be0), 0x90004, ((int)(((RivaRasterImage*)(&g2))->f_0fb0b0())), 0, (short)(p2 + ten), 0, &w, &h, 0x140);
        {
        Guard guard;
        ((RivaRasterImage*)(&g2))->f_0fade0((void *)( d_1a34e0), e0, e1);
        f_0d4800(7);
        ((RivaRasterImage*)(&g1))->f_0fade0((void *)( d_1a34e0), e0, e1);
        d_1bd766 = sv1;
        d_1bd760 = sv2;
        }
        ((int)(((RivaRasterImage*)(&g2))->f_0fad20( 0)));
        ((int)(((RivaRasterImage*)(&g1))->f_0fad20( 0)));
    }
}
