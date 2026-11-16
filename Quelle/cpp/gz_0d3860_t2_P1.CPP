/* === Beschreibung (Katalog) ===
 * Einheit gz_0d3860_t2 (0x0D3A30 - 0x0D3F25)
 *
 * Überblick
 * Die Einheit gz_0d3860_t2 implementiert die CD-ROM-/Musik-Laufwerkssuche und CD-Prüfung (Mus): Sie enthält den
 * Konstruktor und Destruktor des CD-/Musik-Steuerobjekts (f_0d3a30, f_0d3b10), die rekursive Verzeichnissuche
 * nach einer Prüfdatei auf der Spiel-CD (f_0d3b44), das Durchsuchen aller Laufwerksbuchstaben nach der
 * eingelegten CD (f_0d3c75) sowie die Prüfschleife mit Aufforderungsdialog zum Einlegen der CD (f_0d3df6).
 === Ende Beschreibung === */
// P3 4/5 gleich (suche.py 28.10.2026, Basis gz_0d3860_t2_P1.CPP)
// OPT -4r -od -zp1 -s
// Astra650: Original 0d3a30 bis 0d3f25 exklusiv.
struct S4 { unsigned short a, b, c, d; };
struct S8 { int a,b; };
struct Col { unsigned char c[4]; Col(unsigned char a, unsigned char b, unsigned char c2, unsigned char d) { c[3] = d; c[2] = c2; c[1] = b; c[0] = a; } };
struct Base { char pad[0x3c]; Base(short k); };
struct Base2 { Base2(int k); };
struct Mus : Base { short s3c, s3e, s40, s42; Col c44; int i48, i4c, i50; Mus(short k, int p3); };
struct Mus2 : Base2 { Mus2(int a, int b); };
struct Msg { void f_0bf820(long a, ...); }; extern Msg d_1c2c64;
extern int d_1bf508;
extern short d_1bd756, d_1bd758, d_1bd75c, d_1bd75e, d_1bd760, d_1bd762, d_1bd766;
extern unsigned short d_1bf52a, d_1bf52c, d_1bf52e;
extern signed char d_1bf4ef; extern short d_1bf4a2, d_1bf49e, d_1bf500; extern int d_1bf4a8, d_1bf54c, d_1bf548;
void f_0d2b70();
S8 *f_01a820(S8 *r, unsigned short a, unsigned short b, unsigned short c, unsigned short d);
extern char d_1bf968[]; extern void *d_1bfa68; extern int d_1bf960, d_1bfa6c; extern char d_1a96a4[];
extern const char d_1b8244[], d_1b8246[], d_1b8249[], d_1b824d[], d_1b824f[], d_1b8252[], d_1b8255[], d_1b8257[], d_1b825a[], d_1b825c[];
int f_15f1e1(char *p, int n); int f_15f269(const char *s); void f_15f282(char *d, const char *s); void f_15f2d6(char *d, const char *s);
void *f_15e469(const char *n, const char *m); void f_15e836(void *f); int f_15f2b5(const char *p);
int f_1492b4(const char *p, int a, void *b); int f_1492d1(void *b); void f_1492ed(void *b); int f_144bf0(const char *a, const char *b);
void f_15f1b4(int *d); void f_15f1c8(int d, int *r);
int f_02e11a(void *p); int f_02e080(short d); int f_02fc49(void *p); int f_02ed35(void *p);
void f_0d2f90(int a, short b); void f_0d4070(void *p); void f_0d3f25(void *p, short s);
int f_0d3b44(void *p1, const char *p2);
char *f_0d3c75(short *p1, const char *p2);
struct FF { char pad[0x15]; unsigned char attr; char pad2[8]; char name[14]; };
Mus *f_02ea8a(Mus *, short);
void *f_02ecc3(void *, int);
//@ f_0d3a30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor des CD-/Musik-Steuerobjekts Mus: Ruft den Basiskonstruktor f_02ea8a(p, k) auf,
 *   initialisiert das eingebettete 4-Byte-Farb-/Statusfeld c44 mit Nullen, setzt die Konfigurationsfelder (i50 =
 *   n, s3e = 4, s3c = 0, s42 = 0, s40 = 0, i4c = 0) und gibt den Objektzeiger zurück.
 * - Eingaben:
 *   - p (Zeiger auf das zu initialisierende Mus-Objekt).
 *   - k (Parameter für den Basiskonstruktor f_02ea8a).
 *   - n (Initialwert für das Feld i50).
 * - Rückgabewert: Mus * - Zeiger auf das initialisierte Mus-Objekt.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
Mus *f_0d3a30(Mus *p, short k, int n) {
 p = f_02ea8a(p,k);
 unsigned char i,g,b,a,h,c,d,e,f;
 Mus **self=&p;
 a=0; b=a; c=0; d=c; e=0; f=e;
 Col *q=&p->c44, *r=q;
 g=f; h=d; i=b;
 r->c[3]=0; r->c[2]=g; r->c[1]=h; r->c[0]=i;
 Col *end=r;
 p=(Mus*)((char*)end-0x44);
 p->i50=n; p->s3e=4; p->s3c=0; p->s42=0; p->s40=0; p->i4c=0;
 return p;
}
//@ f_0d3b10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor des Mus-Steuerobjekts: Ruft den Basisdestruktor f_02ecc3(p, 1) auf und gibt p
 *   zurück.
 * - Eingaben:
 *   - p (Zeiger auf das Mus-Objekt).
 *   - k (Destruktor-Flags).
 * - Rückgabewert: void * - Der Objektzeiger p.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void *f_0d3b10(void *p, int k)
{
    p=f_02ecc3(p,1);
    return p;
}
//@ f_0d3b44
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht ausgehend vom aktuellen Arbeitsverzeichnis rekursiv in allen Unterverzeichnissen nach
 *   der Datei p2: Prüft zunächst per f_15e469, ob p2 im aktuellen Verzeichnis geöffnet werden kann (und
 *   speichert bei Erfolg den gefundenen Pfad in d_1a96a4), und durchläuft andernfalls über f_1492b4/f_1492d1
 *   (_dos_findfirst/_dos_findnext mit "*.*") alle Unterverzeichnisse (außer "." und ".."), wechselt per chdir
 *   (f_15f2b5) hinein und ruft sich selbst rekursiv auf.
 * - Eingaben:
 *   - p1 (Zeiger auf das Mus-Objekt).
 *   - p2 (Dateiname der gesuchten CD-Prüfdatei).
 * - Rückgabewert: int - 1, wenn die Datei p2 gefunden wurde (Pfad steht in d_1a96a4), sonst 0.
 * - Wichtige Variablen:
 *   - d_1bf968 (Temporärer Pfadpuffer zur Dateiprüfung).
 *   - d_1a96a4 (Ergebnispuffer, in dem das Verzeichnis der gefundenen Datei gespeichert wird).
 *   - ff (find_t-Struktur für die DOS-Verzeichnissuche).
 === Ende Beschreibung === */
int f_0d3b44(void *p1, const char *p2) {
    int r = 0;
    FF ff; int rc;
    f_15f1e1(d_1bf968, 0x100);
    if (d_1bf968[f_15f269(d_1bf968) - 1] != '\\') f_15f282(d_1bf968, d_1b8244);
    f_15f282(d_1bf968, p2);
    d_1bfa68 = f_15e469(d_1bf968, d_1b8246);
    if (d_1bfa68 != 0) {
        f_15e836(d_1bfa68);
        f_15f1e1(d_1a96a4, 0x100);
        return 1;
    } else {
        for (rc = f_1492b4(d_1b8249, 0x10, &ff); rc == 0 && r == 0; rc = f_1492d1(&ff)) {
            if ((ff.attr & 0x10) != 0 && f_144bf0(d_1b824d, ff.name) != 0 && f_144bf0(d_1b824f, ff.name) != 0) {
                f_15f2b5(ff.name);
                r = f_0d3b44(p1, p2);
                f_15f2b5(d_1b8252);
            }
        }
        f_1492ed(&ff);
        return r;
    }
}
//@ f_0d3c75
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt das Verzeichnis der Spiel-CD anhand der Prüfdatei p2: Prüft zuerst, ob p2 bereits
 *   unter dem zuletzt bekannten Pfad d_1a96a4 erreichbar ist; falls nicht, sichert die Funktion das aktuelle
 *   Laufwerk und Arbeitsverzeichnis, prüft alle Laufwerksbuchstaben ab f_02e11a(p1) bis 'Z' (0x1a) auf ein
 *   gültiges CD-ROM-Laufwerk (f_02e080, f_02fc49), sucht dort vom Wurzelverzeichnis "\\" aus über f_0d3b44 nach
 *   p2, stellt das ursprüngliche Arbeitsverzeichnis wieder her und gibt bei Erfolg den gefundenen Pfad d_1a96a4
 *   (ohne abschließenden Backslash) zurück.
 * - Eingaben:
 *   - p1 (Zeiger auf das Mus-Objekt, in dessen erstem short die gefundene Laufwerksnummer abgelegt wird).
 *   - p2 (Name der gesuchten CD-Prüfdatei).
 * - Rückgabewert: char * - Zeiger auf den gefundenen CD-Pfad d_1a96a4 oder 0, wenn die Datei auf keinem Laufwerk
 *   gefunden wurde.
 * - Wichtige Variablen:
 *   - cwd, cwd2 (Gesicherte Arbeitsverzeichnisse des Startlaufwerks und des geprüften CD-Laufwerks).
 *   - d0, cur (Gesicherte und aktuell getestete Laufwerksnummer).
 === Ende Beschreibung === */
char *f_0d3c75(short *p1, const char *p2) {
    char cwd[256]; char cwd2[256]; int r = 0, i, d0, cur;
    f_15f2d6(d_1bf968, d_1a96a4);
    f_15f282(d_1bf968, d_1b8255);
    f_15f282(d_1bf968, p2);
    d_1bfa68 = f_15e469(d_1bf968, d_1b8257);
    if (d_1bfa68 != 0) {
        f_15e836(d_1bfa68);
        return d_1a96a4;
    } else {
        f_15f1e1(cwd, 0x100);
        f_15f1b4(&d0);
        for (i = f_02e11a(p1); i <= 0x1a && r == 0; i++) {
            f_15f1c8(i, &cur);
            f_15f1b4(&cur);
            if (cur == i) {
                if (f_02e080((short)i) != 0) {
                    *p1 = i;
                    if (f_02fc49(p1) != 0) {
                        f_15f1e1(cwd2, 0x100);
                        f_15f2b5(d_1b825a);
                        r = f_0d3b44(p1, p2);
                        f_15f2b5(cwd2);
                    }
                }
            }
        }
        f_15f1c8(d0, &cur);
        f_15f2b5(cwd);
        if (r == 1) {
            if (d_1a96a4[f_15f269(d_1a96a4) - 1] == '\\') d_1a96a4[f_15f269(d_1a96a4) - 1] = 0;
            return d_1a96a4;
        } else return 0;
    }
}
inline int one650() { return 1; }
//@ f_0d3df6
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt sicher, dass die Spiel-CD eingelegt und initialisiert ist: Prüft bei d_1bf960 == 0,
 *   ob die CD neu gesucht werden muss (p1->i4c == 0, f_02fc49(p1) == 0 oder d_1bfa6c != 0), sucht in einer
 *   Schleife über f_0d3c75(p1, d_1b825c) nach der CD-Kennungsdatei, zeigt bei fehlender CD den Dialog 0x200001b2
 *   ("Bitte CD einlegen") an, bis die CD gefunden und über f_02ed35(p1) erfolgreich initialisiert wurde, und
 *   startet anschließend die Musikspur p1->s3c über f_0d3f25.
 * - Eingaben:
 *   - p1 (Zeiger auf das Mus-Steuerobjekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bf960 (Rekursionsschutz-Flag während der CD-Prüfung).
 *   - d_1bfa6c (Anforderungsflag für eine erneute CD-Prüfung).
 === Ende Beschreibung === */
struct Menu493 { void f_0bf820(long,short,...); };
void f_0d3df6(Mus *p1) {
    struct H { static short conv() { return 1; } };
    if (d_1bf960 == 0) {
        d_1bf960 = 1;
        if (p1->i4c == 0 || f_02fc49(p1) == 0 || d_1bfa6c != 0) {
            p1->s42 = 0;
            f_0d4070(p1);
            while (p1->s42 < 1) {
                if (f_0d3c75((short *)p1, d_1b825c) != 0) {
                    p1->s42 = 1;
                    f_0d2f90(5, H::conv());
                    if (f_02ed35(p1) == 1) p1->i4c = 1; else p1->s42 = -1;
                    f_0d2f90(0, H::conv());
                }
                if (p1->s42 < 1) ((Menu493 *)&d_1c2c64)->f_0bf820(0x200001b2, 1, 0x20000104);
            }
            f_0d3f25(p1, p1->s3c);
            d_1bfa6c = 0;
        }
        d_1bf960 = 0;
    }
}
