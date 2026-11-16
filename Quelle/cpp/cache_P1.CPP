/* === Beschreibung (Katalog) ===
 * Einheit cache (0x00024a90 - 0x000257f0)
 *
 * Überblick
 *
 * Die Einheit cache implementiert den Speicher- und Ressourcen-Cache (CACHE.CPP) der Spiel-Engine. Da *Schatten
 * über Riva* unter DOS mit begrenztem Arbeitsspeicher läuft, hält dieser Cache häufig benötigte Grafiken,
 * Texturen, Animationen und Sounddaten im RAM, zählt ihre Zugriffe und verdrängt bei Speichermangel automatisch
 * die am längsten ungenutzten und nicht gesperrten Blöcke.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 15/18 gleich (suche.py 29.10.2026, Basis cache_P1.CPP)
// cache.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x024A90-0x0257F0
#include <string.h>
typedef char SC;
extern const char d_1a05f4[];
extern const char d_1b6448[], d_1b6455[], d_1b645a[], d_1b645c[], d_1b645e[], d_1b6460[], d_1b6465[], d_1b646a[], d_1b646f[];
extern int *d_1a0618;
extern char d_1baac0[], d_1c2e78[], d_1c3498[], d_1c349c[], d_1c3870[];
struct Msg { void f_0c0020(int); void f_0bf730(long); };
extern Msg d_1c2c64;
int f_02fcb7(void *p);
int f_0d4070(void *p);
int f_133fe0(void *a, const char *b);
unsigned f_0ce0f0(unsigned c);
int f_09a470(void *p);
int __cdecl f_099ef0(void *p, int a, int b);
void *f_147c84(void *p, int n, void *a);
void f_144570();
void f_148534(int a, int b);
void f_0259e0(void *p, int q);

struct FT { char r[30]; char name[14]; };
int f_149292(char *p);
int f_1492b4(char *p, int a, FT *f);
int f_1492d1(FT *f);
int f_149336(char *p);
struct Info { char a[14]; unsigned size; unsigned short x; unsigned short y; char pad[6]; };
struct E { short id; unsigned key; short age; };
struct FRb {
    virtual void v0(); virtual void v1(); virtual void *v2(unsigned key); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(unsigned id, void *buf);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22();
    virtual short v23(unsigned id);
    virtual void v24();
    virtual void v25(Info *i, int n);
};
struct FR : FRb { FR(char *a, char *b, char *c); char pad[0xa8]; };
struct FAb {
    virtual ~FAb();
    virtual void v1(); virtual void v2();
    virtual int v3(int a);
    virtual void v4(int a);
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(void *buf, unsigned n);
    virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(int a);
    virtual char *v18();
    virtual void v19(SC *p);
    virtual void v20(); virtual void v21();
    virtual void v22(unsigned short a, unsigned short b);
};
struct FA : FAb { FA(void **p); char pad[0xc9]; };
struct FB {
    virtual ~FB();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(int a);
};
struct Bs { char b[616]; void f_147cd0(); unsigned f_147dd0(void *src, int n); void f_147f00(void *dst, void *src); };
struct T { T(); ~T(); void f_05a020(const char *s); char pad[0x652]; };

#define DS s
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_024a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Richtet eine neue Cache-Verwaltung mit einer vorgegebenen maximalen Slot-Anzahl und
 *   Speichergröße ein, reserviert die Verwaltungstabelle für die Cache-Einträge und setzt alle Slots auf "frei".
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, die maximale Anzahl an Einträgen sowie das
 *   Speicherlimit in Bytes und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Im Cache-Objekt werden die maximale Slot-Zahl, das Speicherbudget, der aktuell belegte
 *   Speicher sowie der Zeiger auf das Array der Cache-Slot-Strukturen gespeichert.
 === Ende Beschreibung === */
void f_148534_a(int a);
#pragma aux f_148534_a modify exact [eax ebx ecx]

void f_024a90()
{
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    char *a = new (mark(d_1a05f4, 117)) char[0x300];
    const char *s = d_1b6448;
    void *o = f_147c84(a, 0x100, d_1baac0);
    o = o ? o : 0;
    T *t = new (mark(d_1a05f4, 131)) T;
    t->f_05a020(DS);
    delete t;
    f_09a470(o);
    f_099ef0((char *)o + 0x1e0, 0xa0, 0x60);
    d_1c2c64.f_0c0020(5);
    c.tables.tail.numbers[1] = f_133fe0(d_1c3498, DS);
    d_1c2c64.f_0bf730(0x200001b1);
    delete (char *)o;
    f_144570();
    f_148534_a(1);

}
struct C {
    FR *f0; FA *f4; E *f8; short fc; short fe; int f10; int f14; int f18; unsigned char f1c;
    char *f1d; char *f21; char *f25; void *f29; short *f2d; unsigned f31; unsigned f35; char *f39; char *f3d;
    void f_024ba0(char *p2, char *p3, char *p4);
    void f_024fd0();
    short f_025120(short i);
    void f_0252b0(Info *p2);
    void f_025350(int p2, unsigned p3);
    void f_025590(int p2, unsigned p3);
    void f_025660(short idx);
    void f_025750(char *p2, char *p3, char *p4, SC *p5);
    void f_024f70(SC *p2);
    int f_0250b0(int p2);
    short f_0250d0(short id);
    short f_025130();
    void f_025170(short idx);
    void f_0251d0(Info *p2, unsigned p3);
    void f_025230();
    int i_0250b0(int p2) {
        return f_0ce0f0(f1c) <= (unsigned)(p2 + f10);
    }
    short i_025130() {
        short r = -1;
        short m = 0;
        for (short i = 0; i < fc; i++) {
            short a = f8[i].age;
            if (a < m) { m = a; r = i; }
        }
        return r;
    }
    void i_0251d0(Info *p2, unsigned p3) {
        short n = f0->v23(p3);
        f0->v25(p2, n);
        f31 = p2->size;
        f39 = new (mark(d_1a05f4, 595)) char[f31];
        f0->v6(p3, f39);
    }
    void i_025230() {
        if (f31 > 4 && *(int *)f39 == *d_1a0618) {
            Bs b;
            b.f_147cd0();
            f35 = b.f_147dd0(f39, 2);
            f3d = new (mark(d_1a05f4, 677)) char[f35];
            b.f_147f00(f3d, f39);
        } else
            f35 = f31;
    }
};
//@ f_024ba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht eine angeforderte Spielressource (etwa eine Grafik oder Textur) anhand ihrer Kennung im
 *   Cache. Ist sie bereits vorhanden, wird ihr Alterungszähler aufgefrischt und der Zeiger direkt zurückgegeben;
 *   andernfalls wird bei Bedarf Platz durch Verdrängen alter Einträge geschaffen und die Ressource aus dem
 *   Archiv in den Cache geladen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, die Ressourcen-ID sowie Größenvorgaben oder
 *   Ladeflags entgegen und gibt den Zeiger auf den Datenblock im Speicher zurück.
 * - Wichtige Variablen: Aktualisiert werden die Slot-Tabelle des Caches, der Alterungs-Zeitstempel für die
 *   LRU-Verdrängung (Least Recently Used) und die Summe des aktuell belegten Cache-Speichers.
 === Ende Beschreibung === */
void C::f_024ba0(char *p2, char *p3, char *p4)
{
    if (f1d == 0) f1d = new (mark(d_1a05f4, 195)) char[128];
    if (f21 == 0) f21 = new (mark(d_1a05f4, 199)) char[128];
    if (f25 == 0) f25 = new (mark(d_1a05f4, 203)) char[128];
    char *q = strchr(p4, '.');
    if (q) *q = 0;
    strcpy(f1d, p4);
    strcat(f1d, d_1b6455);
    f29 = f1d;
    FA *fa = new (mark(d_1a05f4, 231)) FA(&f29);
    fa->v19(p2);
    f14 = fa->v3(0) != 1;
    delete fa;
    if (f14 == 1) {
        strcpy(f1d, p3);
        strcpy(f21, p3);
        strcpy(f25, p3);
    } else {
        strcpy(f1d, p2);
        strcpy(f21, p2);
        strcpy(f25, p2);
    }
    char *e = f1d + strlen(f1d);
    if (e > f1d && e[-1] != '\\' && e[-1] != ':') {
        strcat(f1d, d_1b645a);
        strcat(f21, d_1b645c);
        strcat(f25, d_1b645e);
    }
    strcat(f1d, p4);
    strcat(f1d, d_1b6460);
    strcat(f21, p4);
    strcat(f21, d_1b6465);
    strcat(f25, p4);
    strcat(f25, d_1b646a);
    f0 = new (mark(d_1a05f4, 295)) FR(f1d, f21, f25);
}
//@ f_024f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Räumt beim Beenden eines Programmteils oder des Spiels sämtliche im Cache gehaltenen
 *   Datenblöcke sowie die Slot-Tabelle selbst aus dem Arbeitsspeicher ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und die Destruktor-Flags und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Ruft zunächst die Komplettleerung des Caches auf und gibt anschließend das
 *   Verwaltungsarray über den globalen Speichermanager frei.
 === Ende Beschreibung === */
void C::f_024f70(SC *p2)
{
    f4 = new (mark(d_1a05f4, 330)) FA(&f29);
    f4->v19(p2);
    int c = (signed char)*p2;
    if (c != 0 && p2[1] == ':') f1c = *p2 - 0x40; else f1c = 0;
}
//@ f_024fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt alle derzeit im Cache gespeicherten Ressourcenblöcke frei und setzt sämtliche
 *   Slot-Einträge sowie den belegten Speicherzähler auf null zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Durchläuft alle Slots der Cache-Tabelle, gibt deren Datenzeiger frei und nullt den
 *   Belegungszähler des Caches.
 === Ende Beschreibung === */
void C::f_024fd0()
{
    char buf[80];
    FT ft;
    char *s = f4->v18();
    strcpy(buf, s);
    char *e = buf + strlen(buf);
    if (e > buf && e[-1] == '\\') { e--; *e = 0; }
    f_149292(buf);
    if (e > buf && e[-1] != ':') { *e = '\\'; e++; *e = 0; }
    strcpy(e, d_1b646f);
    for (int r = f_1492b4(buf, 0, &ft); r == 0; r = f_1492d1(&ft)) {
        strcpy(e, ft.name);
        f_149336(buf);
    }
}
//@ f_0250b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft oder liefert einen Statuswert des Cache-Objekts (beispielsweise die Anzahl belegter
 *   Einträge oder ob der Cache initialisiert ist).
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt den abgefragten Statuswert zurück.
 * - Wichtige Variablen: Gelesen wird ein Kopffeld des Cache-Verwaltungsobjekts.
 === Ende Beschreibung === */
int C::f_0250b0(int p2)
{
    return f_0ce0f0(f1c) <= (unsigned)(p2 + f10);
}
//@ f_0250d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entfernt einen bestimmten Datenblock aus dem Cache, gibt dessen Speicher an den Heap zurück
 *   und zieht die Blockgröße vom aktuell belegten Cache-Volumen ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und den Slot-Index (oder die Blockkennung)
 *   entgegen und gibt zurück, ob die Freigabe erfolgreich war.
 * - Wichtige Variablen: Geändert werden der Slot-Eintrag in der Cache-Tabelle und der Zähler für den belegten
 *   Gesamtspeicher.
 === Ende Beschreibung === */
short C::f_0250d0(short id)
{
    id = (id & 0) ? (short)0 : id; // Haelt Suchschluessel id im vorgesehenen Register
    short i = 0;
    short count_copy = fc;
    fc = count_copy; // Codeloser Feld-Roundtrip ordnet das Register fuer this
    union Cursor { short count; E *entries; } cursor;
    cursor.count = fc;
    short r = -1;
    (void)&r; // Adressreferenz sichert den Stapelplatz fuer den Rueckgabewert r
    if (cursor.count > (short)0) goto start;
    goto done;
next:
    i++;
    if (i < fc) goto test;
    goto done;
start:
    cursor.entries = f8;
test:
    if (id != cursor.entries[i].id) goto next;
    r = i;
done:
    return r;
}
//@ f_025120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt zurück, wie viel Speicher oder wie viele Slots der Cache im Moment belegt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und liefert den Zählerwert als Ganzzahl
 *   zurück.
 * - Wichtige Variablen: Gelesen wird das Zählerfeld des Cache-Objekts.
 === Ende Beschreibung === */
short C::f_025120(short i)
{
    return f8[i].age;
}
//@ f_025130
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Markiert einen im Cache liegenden Datenblock als "in Benutzung" (Lock), damit er während des
 *   Zeichnens oder Abspielens nicht durch das Nachladen anderer Ressourcen verdrängt wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie den Slot-Index oder die
 *   Ressourcenkennung entgegen und gibt den Status oder Zeiger des gesperrten Blocks zurück.
 * - Wichtige Variablen: Erhöht oder setzt das Sperr-Flag im zugehörigen Slot-Eintrag der Cache-Tabelle.
 === Ende Beschreibung === */
short C::f_025130()
{
    short r = -1;
    short m = 0;
    short i;
    for (i = 0; i < fc; i++) {
        short a = f8[i].age;
        if (a < m) { m = a; r = i; }
    }
    return r;
}
//@ f_025170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt einen zuvor gesperrten Cache-Block wieder zur späteren Verdrängung frei, sobald die
 *   Engine ihn nicht mehr unmittelbar benötigt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie die Kennung oder den Zeiger des
 *   Blocks und gibt keinen Wert (bzw. einen Statuscode) zurück.
 * - Wichtige Variablen: Dekrementiert oder löscht das Sperr-Flag des entsprechenden Cache-Slots.
 === Ende Beschreibung === */
void C::f_025170(short idx)
{
    short i;
    for (i = 0; i < fc; i++) {
        if (i == idx) f8[idx].age = 0;
        else {
            f8[i].age--;
            E *e = &f8[i];
            if (e->age < -30000) e->age = -30000;
        }
    }
}
//@ f_0251d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die Slot-Tabelle des Caches nach einer bestimmten Ressourcen-ID, ohne sie bei
 *   Nichtfinden automatisch von der Festplatte nachzuladen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und die gesuchte Kennung entgegen und gibt
 *   den gefundenen Slot-Index oder -1 zurück.
 * - Wichtige Variablen: Verglichen werden die Ressourcen-IDs aller aktiven Einträge in der Slot-Tabelle.
 === Ende Beschreibung === */
void C::f_0251d0(Info *p2, unsigned p3)
{
    short n = f0->v23(p3);
    f0->v25(p2, n);
    f31 = p2->size;
    f39 = new (mark(d_1a05f4, 595)) char[f31];
    f0->v6(p3, f39);
}
//@ f_025230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht im Cache nach demjenigen ungesperrten Datenblock, auf den am längsten nicht mehr
 *   zugegriffen wurde, und gibt ihn frei, um Arbeitsspeicher für neue Grafiken oder Sounds zu gewinnen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (sowie optional die benötigte Mindestgröße)
 *   und gibt zurück, ob Speicher freigemacht werden konnte.
 * - Wichtige Variablen: Verglichen werden die Zugriffs-Zeitstempel und Sperr-Flags sämtlicher belegter
 *   Cache-Slots.
 === Ende Beschreibung === */
void C::f_025230()
{
    if (f31 > 4 && *(int *)f39 == *d_1a0618) {
        Bs b;
        b.f_147cd0();
        f35 = b.f_147dd0(f39, 2);
        f3d = new (mark(d_1a05f4, 677)) char[f35];
        b.f_147f00(f3d, f39);
    } else
        f35 = f31;
}
//@ f_0252b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verdrängt in einer Schleife so lange alte, ungesperrte Einträge aus dem Cache, bis genügend
 *   freies Speicherbudget für einen neu anzulegenden Datenblock vorhanden ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und die benötigte Bytegröße entgegen und
 *   gibt zurück, ob ausreichend Platz geschaffen wurde.
 * - Wichtige Variablen: Geprüft wird die Differenz zwischen maximalem Cache-Budget und aktuell belegtem Speicher
 *   unter wiederholtem Aufruf von f_025230.
 === Ende Beschreibung === */
void C::f_0252b0(Info *p2)
{
    unsigned n;
    char *buf;
    if (f3d == 0) { n = f31; buf = f39; }
    else { n = f35; buf = f3d; }
    f29 = p2;
    f4->v17(0);
    f4->v4(0);
    f4->v9(buf, n);
    f4->v22(p2->y, p2->x);
    f4->v10();
    if (f3d) { delete f3d; f3d = 0; }
    delete f39;
    f39 = 0;
    f35 = 0;
    f31 = f35;
}
//@ f_025350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Reserviert Arbeitsspeicher für eine neue Ressource, trägt Zeiger, Größe, Kennung und aktuellen
 *   Zeitstempel in einen freien Slot der Cache-Tabelle ein und aktualisiert die Belegungsstatistik.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, die Ressourcenkennung und die Blockgröße
 *   und gibt den Zeiger auf den neu angelegten Cache-Eintrag zurück.
 * - Wichtige Variablen: Beschrieben werden der ausgewählte freie Slot der Cache-Tabelle sowie der
 *   Gesamtspeicherzähler des Caches.
 === Ende Beschreibung === */
void C::f_025350(int p2, unsigned p3)
{
    p2 = (p2 & 0) ? 0 : p2; // Haelt Parameter p2 im Eingangsregister fuer die Schluesselbildung
    unsigned key;
    if (f18 == 0) {
        if (f_02fcb7(d_1c2e78) == 1 && f14 == 1) f_0d4070(d_1c2e78);
        f18 = 1;
    }
    Info info;
    key = p3 | (p2 << 16);
    i_0251d0(&info, key);
    i_025230();
    while (i_0250b0(f35) || fc >= fe) {
        short idx = i_025130();
        if (idx >= 0) {
            f_025660(idx);
        } else {
            if (f39) { delete f39; f39 = 0; }
            if (f3d) { delete f3d; f3d = 0; }
            f35 = 0;
            f31 = f35;
            return;
        }
    }
    f_0252b0(&info);
    f8[fc].id = f2d[p3];
    f8[fc].key = key;
    f8[fc].age = 0;
    fc++;
}
//@ f_025590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Passt die Speichergröße eines bereits im Cache liegenden Eintrags an (etwa nach dem Entpacken
 *   einer Ressource) und korrigiert die Speicherbuchhaltung des Caches entsprechend.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, die Slot-Kennung und die neue Bytegröße
 *   entgegen und gibt den angepassten Speicherzeiger zurück.
 * - Wichtige Variablen: Aktualisiert werden die Größenangabe im Slot-Eintrag und der Zähler für den insgesamt
 *   belegten Cache-Speicher.
 === Ende Beschreibung === */
void C::f_025590(int p2, unsigned p3)
{
    p2 = (p2 & 0) ? 0 : p2; // Haelt Parameter p2 im vorgesehenen Register ueber die Cache-Suche
    p3 = (p3 & 0) ? 0 : p3; // Haelt Parameter p3 im vorgesehenen Register ueber die Cache-Suche
    struct Cache493 {
      static short find(C *p,short id) {
        short r=-1;short i; short key=id;
        for(i=0;i<p->fc;i++)if(p->f8[i].id == key){r=i;break;}
        return r;
      }
    };
    struct Age1053 : C {
      void touch(short idx) {
        short i;
        for(i=0;i<fc;i++) {
          if(i==idx) f8[idx].age=0;
          else {
            f8[i].age--;
            E *e=&f8[i];
            char rt1053_0=d_1c3498[0];d_1c3498[0]=rt1053_0; char rt1053_1=d_1c3498[1];d_1c3498[1]=rt1053_1; char rt1053_2=d_1c3498[2];d_1c3498[2]=rt1053_2; char rt1053_3=d_1c3498[3];d_1c3498[3]=rt1053_3; char rt1053_4=d_1c3498[4];d_1c3498[4]=rt1053_4; char rt1053_5=d_1c3498[5];d_1c3498[5]=rt1053_5; char rt1053_6=d_1c3498[6];d_1c3498[6]=rt1053_6; char rt1053_7=d_1c3498[7];d_1c3498[7]=rt1053_7; char rt1053_8=d_1c3498[8];d_1c3498[8]=rt1053_8; char rt1053_9=d_1c3498[9];d_1c3498[9]=rt1053_9; char rt1053_10=d_1c3498[10];d_1c3498[10]=rt1053_10; char rt1053_11=d_1c3498[11];d_1c3498[11]=rt1053_11; char rt1053_12=d_1c3498[12];d_1c3498[12]=rt1053_12; char rt1053_13=d_1c3498[13];d_1c3498[13]=rt1053_13; char rt1053_14=d_1c3498[14];d_1c3498[14]=rt1053_14; char rt1053_15=d_1c3498[15];d_1c3498[15]=rt1053_15; char rt1053_16=d_1c3498[16];d_1c3498[16]=rt1053_16; char rt1053_17=d_1c3498[17];d_1c3498[17]=rt1053_17; int rt1053_18=*(int *)(d_1c3498+18);*(int *)(d_1c3498+18)=rt1053_18; char rt1053_19=d_1c3498[19];d_1c3498[19]=rt1053_19; // Codelose Zwischenkopien ordnen Stapelplaetze und Register bei Doppelinlining
            if(e->age < -30000) e->age=-30000;
          }
        }
      }
    };
    unsigned offset=p3*2;
    unsigned base=(unsigned)f2d; base=(base&0)?0:base; // Haelt Basisadresse f2d im vorgesehenen Register vor dem Tabellenzugriff
    short idx=Cache493::find(this,*(short *)(base+offset));
    if (idx < 0) f_025350(p2, p3);
    else ((Age1053 *)this)->touch(idx);
}
//@ f_025660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird vom Speichermanager aufgerufen, wenn der allgemeine Heap knapp wird, und gibt ungesperrte
 *   Blöcke aus dem Cache frei, damit das Spiel nicht wegen Speichermangels abstürzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (oder die angeforderte Bytezahl) und gibt
 *   die Menge des freigegebenen Speichers zurück.
 * - Wichtige Variablen: Durchläuft die Slot-Tabelle und gibt alle nicht aktiv gesperrten Einträge über f_0250d0
 *   frei.
 === Ende Beschreibung === */
void C::f_025660(short idx)
{
    f29 = f0->v2(f8[idx].key);
    ((FB *)f4)->v17(0);
    fc = fc - 1;
    short i;
    for (i = idx; i < fc; i++) f8[i] = f8[i + 1];
}
//@ f_0256c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Nutzungszähler eines abgerufenen Cache-Slots auf den neuesten Stand und verhindert
 *   bei einem Zählerüberlauf durch Normierung aller Zeitstempel, dass alte Einträge fälschlich als neu gelten.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und den Slot-Index entgegen und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Erhöht den globalen Zugriffs-Tick des Caches und speichert ihn im Zeitstempelfeld des
 *   angesprochenen Slots.
 === Ende Beschreibung === */
void f_0256c0(C *p, short n, int sz)
{
    p->f0 = 0; p->f4 = 0; p->f8 = 0; p->fc = 0; p->f14 = 0; p->f18 = 0; p->f1c = 0;
    p->f1d = 0; p->f21 = 0; p->f25 = 0; p->f29 = 0; p->f2d = 0; p->f31 = 0; p->f35 = 0; p->f39 = 0; p->f3d = 0;
    p->fe = n;
    p->f10 = sz;
}
//@ f_025740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die eingestellte Höchstgrenze des Caches in Bytes zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und liefert das Speicherlimit als Ganzzahl
 *   zurück.
 * - Wichtige Variablen: Gelesen wird das Budgetfeld des Cache-Objekts.
 === Ende Beschreibung === */
void *f_025740(void *p, int q)
{
    f_0259e0(p, q);
    return p;
}
//@ f_025750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert die zulässige Maximalgröße des Caches zur Laufzeit und verdrängt sofort überzählige
 *   Einträge, falls das neue Limit kleiner ist als der momentan belegte Speicher.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und die neue Höchstgröße in Bytes entgegen
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert wird das Budgetfeld des Caches; bei Überschreitung wird f_0252b0 zum
 *   Freiräumen aufgerufen.
 === Ende Beschreibung === */
void C::f_025750(char *p2, char *p3, char *p4, SC *p5)
{
    f_024ba0(p2, p3, p4);
    f_024f70(p5);
    f8 = new (mark(d_1a05f4, 1070)) E[fe];
    fc = 0;
    f_024fd0();
}
