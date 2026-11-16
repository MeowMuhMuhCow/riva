/* === Beschreibung (Katalog) ===
 * Einheit fz_145760_t2 (0x146920 - 0x147B3F)
 *
 * Überblick
 * Diese Einheit enthält den zweiten, zentralen Teil des digitalen Soundmanagers (hmi.cpp, globale Instanz
 * d_1c2edc). Sie verwaltet die Initialisierung des *HMI Sound Operating System (SOS)* anhand der Datei
 * sound.cfg, das Parsen der Attic-eigenen Sound-Steuerblöcke (VOLU, PAN , PITC, PANS), das Starten, Stoppen und
 * Nachführen von bis zu 16 gleichzeitigen Soundkanälen sowie die Lautstärke-, Pitch- und
 * Stereopanoramasteuerung.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 20/22 gleich (suche.py 25.10.2026, Basis fz_145760_t2_P1.CPP)
// fz_145760.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x145760-0x147C84
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_147cd0(int p1);                                   // reg eax stapel 0
int f_147ef0(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_1664d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_167f75(int p1, int p2, int p3, int p4);           // reg eax edx ecx stapel 0 (SICHERT)
int f_1680f5(int p1, int p2);                           // reg eax edx stapel 0
int f_168787(int p1);                                   // reg eax stapel 0
int f_1687c9(int p1, int p2);                           // reg eax edx stapel 0
int f_16886d(int p1, int p2);                           // reg eax edx stapel 0
int f_168944(int p1);                                   // reg eax stapel 0
int f_16897e(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_168cd4(int p1);                                   // reg eax stapel 0
int f_168faf(int p1, int p2);                           // reg eax edx stapel 0
int f_169412(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16991e(int p1, int p2);                           // reg eax edx stapel 0
int f_16997a();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9698;                    // 0x1A9698
extern int d_1a97dc;                    // 0x1A97DC
extern int d_1a9820;                    // 0x1A9820
extern int d_1a9824;                    // 0x1A9824
extern int d_1a982c;                    // 0x1A982C
extern int d_1a9830;                    // 0x1A9830
extern int *d_1a9834;                    // 0x1A9834
extern int d_1b8996;                    // 0x1B8996
extern int d_1baac0;                    // 0x1BAAC0
                    // 0x1C2098
extern int d_1c3914;                    // 0x1C3914
extern int d_1c3918;                    // 0x1C3918
extern unsigned int d_1c391c;                    // 0x1C391C
extern unsigned int d_1c3920[];                    // 0x1C3920 Breiten int,unsigned
extern int d_1c3960;                    // 0x1C3960
extern const char d_1a97e0[];           // Text 0x1A97E0
extern const char d_1a97f4[];           // Text 0x1A97F4
extern const char d_1a980c[];           // Text 0x1A980C
extern const char d_1b898c[];           // Text 0x1B898C
extern const char d_1b899c[];           // Text 0x1B899C
extern const char d_1b89b8[];           // Text 0x1B89B8
extern const char d_1b8a82[];           // Text 0x1B8A82
extern const char d_1b8a92[];           // Text 0x1B8A92
extern const char d_1b8aa4[];           // Text 0x1B8AA4
extern const char d_1b8ab0[];           // Text 0x1B8AB0
// --- eigene Funktionen (63), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern int d_1a9828;
extern const char d_1b89e1[];
extern const char d_1b89f2[];
// OPT -4r -od -zp1 -s
#define STR(s) ((int)(s))
#define LV short
#define LT(i) ((i) < 0x10)
#define II(o) (*(int *)(p + (o)))
#define SS(o) (*(short *)(p + (o)))
#define US(o) (*(unsigned short *)(p + (o)))
#define AA(i) (*(int *)((short)(i) * 4 + p + 0x24))
#define DD(i) d_1c3920[(short)(i)]
struct HT { char pad[0x21a]; HT(int, int, int, int, int, int, int, int, int); ~HT(); };
typedef int (*VF)(int, int, int);
typedef unsigned (*VF1)(int);
typedef void (*VF0)(int);
#define VTB(o) (*(int *)((o) + 0x14))
int f_146364(int);
short f_14633d(int);
int f_146389(int, int *);
int f_146900(void);
void f_147aad(int);
void f_146f46(int, int);
int f_144fbf(const char *, ...);
int f_1452bc(int);
int f_144e8b(int, char *, int);
int f_145259(int);
char *f_14d50b(char *, const char *);
int f_15ead2(const char *, const char *, ...);
extern const char d_1b8a03[], d_1b8a0e[], d_1b8a17[], d_1b8a2b[], d_1b8a36[], d_1b8a4a[], d_1b8a54[], d_1b8a66[], d_1b8a70[];
//@ f_146920
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor des globalen Soundmanagers (d_1c2edc). Er initialisiert alle Hardware- und
 *   Treiberfelder (IRQ, DMA, Port, Treiber-ID), leert das Array der 16 aktiven Soundkanäle (AA(0) bis AA(15)),
 *   setzt die vier Hüllkurven-Steuertabellen (PP(0x18c + i*4)) auf 0, stellt die Standardlautstärke (0x7fff) und
 *   Standard-Abtastrate (11025 Hz) ein und liest über f_146b32 die Soundkartenkonfiguration ein.
 * - Eingaben: p (Zeiger auf das Soundmanager-Objekt).
 * - Rückgabewert: Gibt p zurück.
 * - Wichtige Variablen:
 *   - AA(0..15) (+0x5c..+0x98): Zeiger-Array der 16 digitalen Soundkanäle (HM *).
 *   - SS(0x18a): Byte-Offset des PCM-Datenanfangs nach einem Attic-Soundheader.
 *   - US(0x186): Master-Lautstärke (0x7fff).
 === Ende Beschreibung === */
int f_146920(int p, int p2)
{
    LV i;
    for (i = 0; i < (short)0x10; i++) {
        AA(i) = 0;
        d_1c3960 = 0;
    }
    II(0x20) = p2;
    memset((void *)(p + 100), 0, 0x10c);
    II(0x68) = d_1a9820;
    II(0xa8) = d_1a9828;
    II(0) = 1;
    II(0xc) = 1;
    II(4) = 0;
    II(8) = 0;
    SS(0x18a) = 0;
    SS(0x17a) = 0x7fff;
    SS(0x188) = 0;
    SS(0x186) = SS(0x188);
    return p;
}
//@ f_146a09
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor des Soundmanagers. Er stoppt und löscht alle aktiven Soundkanäle, gibt die vier
 *   Hüllkurven-Steuertabellen frei, meldet den registrierten Timer-Event (SS(0x18)) beim SOS-Timer ab (f_1564a6)
 *   und fährt den HMI-SOS-Digitaltreiber (f_155068, f_154e34) sowie das Timer-System (f_15622a) herunter.
 * - Eingaben: p (Zeiger auf den Soundmanager), fl (Destruktor-Flags).
 * - Rückgabewert: Gibt p zurück.
 * - Wichtige Variablen: SS(0x04) (Flag "Treiber initialisiert"), SS(0x14) (SOS-Treiber-Handle), SS(0x18)
 *   (SOS-Timer-Event-Handle).
 === Ende Beschreibung === */
int f_146a09(int p, int p2)
{
    II(0) = 0;
    II(0xc) = 0;
    if (II(4) == 1) {
        f_168cd4(II(0x176));
        f_168cd4(d_1a9830);
        f_168944(0);
        if (II(0xac) != 0) operator delete((void *)II(0xac));
        II(0xb4) = II(0x1c);
        II(0xac) = II(0x14);
        II(0xb0) = II(0x18);
        f_169412(II(0x172), 1, 1);
        f_16997a();
        II(4) = 0;
        II(8) = 0;
    }
    return p;
}
//@ f_146ae4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet die digitale Soundausgabe zur Laufzeit ein (p2 == 1) oder aus (p2 == 0). Beim
 *   Ausschalten werden sofort alle aktuell laufenden Soundkanäle über f_147aad gestoppt.
 * - Eingaben: p (Soundmanager), p2 (1 = aktivieren, 0 = deaktivieren).
 * - Rückgabewert: Alter Zustand des Aktivierungsflags SS(0x06) oder 0, falls überhaupt keine Soundkarte
 *   initialisiert wurde (SS(0x04) == 0).
 * - Wichtige Variablen: SS(0x04) (Hardware bereit), SS(0x06) (Sound aktuell eingeschaltet).
 === Ende Beschreibung === */
void f_146ae4(int p, int p2)
{
    if (p2 != 1 && p2 != 0)
        f_1664d0(STR(d_1b899c), STR(d_1a980c), 0x180);
    II(0xc) = p2;
    f_147aad(p);
}
//@ f_146b32
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Konfigurationsdatei sound.cfg (d_1a9828) über f_147954 ein und initialisiert,
 *   falls eine gültige Soundkarten-ID (II(0x08) != -1) eingetragen ist, das HMI-SOS-Timersystem (f_1561c7,
 *   f_149fb1) und den digitalen Soundtreiber (f_154dc0, f_154ec7). Außerdem registriert sie den
 *   1-Hz-Timer-Callback f_146900 sowie den 18-Hz-Hüllkurven-Timer f_147b3f (0x12 Hz).
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: 1 bei erfolgreicher Treiberinitialisierung, sonst 0.
 * - Wichtige Variablen:
 *   - II(0x08): HMI-SOS-Karten-ID aus sound.cfg (-1 = kein Sound).
 *   - II(0x20) (Port), II(0x24) (IRQ), II(0x28) (DMA), II(0x2c) (Parameter): Hardwareeinstellungen der
 *     Soundkarte.
 === Ende Beschreibung === */
int f_146b32(int p, unsigned short p2, short p3, short p4, short p5)
{
    int r = 0;
    II(0xc0) = (short)p3;
    II(0xc8) = (short)p5;
    II(0xc4) = (short)p4;
    II(0x168) = (unsigned short)p2;
    II(0x10) = f_16886d(0xff00, 0);
    if (II(0x10) == 0) {
        II(0x10) = f_16991e(0, 0);
        if (II(0x10) == 0) {
            if ((unsigned short)p2 != 0xffff) {
                II(0x10) = f_168faf(p + 100, p + 0x172);
                if (II(0x10) == 0) {
                    II(0x1c) = II(0xb4);
                    II(0x14) = II(0xac);
                    II(0x18) = II(0xb0);
                    II(0xb4) = 0x4000;
                    II(0xac) = f_014540(0x5000, STR(d_1a980c), 0x1a1);
                    *(char **)(p + 0xb0) = *(char **)(p + 0xac) + 0x4000;
                    II(0x10) = f_16897e(d_1a982c, II(0x16c), p + 0x176);
                    if (II(0x10) == 0) {
                        II(0x90) = 0x800;
                        II(0x78) = 0x10;
                        r = 1;
                        II(4) = 1;
                        II(8) = 1;
                        II(0x10) = f_16897e(1, (int)f_146900, (int)&d_1a9830);
                    }
                }
            } else {
                r = 1;
                II(4) = 1;
            }
        }
    }
    return r;
}
//@ f_146d0f
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den letzten Fehler- bzw. Statuscode (SS(0x10)) der HMI-SOS-Initialisierung im
 *   Soundmanager p zurück.
 * - Eingaben: p (Zeiger auf den Soundmanager).
 * - Rückgabewert: 16-Bit-Statuswert SS(0x10) (short).
 * - Wichtige Variablen: SS(0x10).
 === Ende Beschreibung === */
short f_146d0f(int p)
{
    return SS(0x10);
}
//@ f_146d36
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bereitschaftsflag (II(8)) des digitalen Soundtreibers im Soundmanager p zurück.
 * - Eingaben: p (Zeiger auf den Soundmanager).
 * - Rückgabewert: 1, wenn der digitale Soundtreiber initialisiert ist, sonst 0.
 * - Wichtige Variablen: II(8).
 === Ende Beschreibung === */
int f_146d36(int p)
{
    return II(8);
}
//@ f_146d5c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert das HMI-SOS-Treiber-Handle (SS(0x172)) des Soundmanagers p zurück.
 * - Eingaben: p (Zeiger auf den Soundmanager).
 * - Rückgabewert: Das 16-Bit-Treiber-Handle (short).
 * - Wichtige Variablen: SS(0x172).
 === Ende Beschreibung === */
short f_146d5c(int p)
{
    return SS(0x172);
}
//@ f_146d86
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht die 16 Kanal-Slots (AA(0..15)) des Soundmanagers p nach demjenigen aktiven
 *   HM-Soundkanal, dessen SOS-Sample-Handle (f_14633d) mit p2 übereinstimmt, und gibt den Kanalzeiger zurück.
 * - Eingaben: p (Soundmanager), p2 (gesuchtes SOS-Sample-Handle).
 * - Rückgabewert: Zeiger auf das gefundene HM-Kanalobjekt oder 0.
 * - Wichtige Variablen: i (Laufindex 0..15), AA(i).
 === Ende Beschreibung === */
int f_146d86(int p, int p2)
{
    LV i;
    for (i = 0; i < (short)0x10; i++) {
        if (AA(i) != 0) {
            if (f_14633d(AA(i)) == (short)p2)
                return AA(i);
        }
    }
    return 0;
}
//@ f_146dfa
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Aktualisiert in der Hauptschleife alle 16 Soundkanäle (AA(0..15)) des Soundmanagers p,
 *   lädt über f_146389 benötigte Streaming-Blöcke nach, baut abgelaufene oder über das Zeitlimit DD(i)
 *   (d_1c391c) gekommene Kanäle ab und führt die Spitzenwerte für gleichzeitige Kanäle (SS(0x188)) und
 *   Treiberauslastung (SS(0x186)) nach.
 * - Eingaben: p (Soundmanager), p2 (Flag: 1 erlaubt mehrere Nachladevorgänge im selben Durchlauf, 0 begrenzt auf
 *   einen Nachladevorgang x).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: x (Nachlade-Sperrflag), cnt (Anzahl aktiver Kanäle), v (SOS-Treiberstatus aus f_168787).
 === Ende Beschreibung === */
void f_146dfa(int p, int p2)
{
    int x;
    int i;
    int v, cnt;
    x = 0;
    v = 0;
    cnt = 0;
    if (II(0xc) == 1) {
        v = f_168787(II(0x172));
        for (i = 0; ((short)(i) < (short)0x10); i = i + 1) {
            if (AA(i) != 0) {
                if (f_146389(AA(i), &x) == 1 || d_1c391c > DD(i)) {
                    delete (HT *)AA(i);
                    AA(i) = 0;
                    DD(i) = 0;
                } else {
                    cnt++;
                }
                if (p2 == 1)
                    x = 0;
            }
        }
        if (SS(0x188) < (short)cnt)
            SS(0x188) = cnt;
        if (SS(0x186) < (short)v)
            SS(0x186) = v;
    }
}
struct HDR { int magic; unsigned short minv; unsigned short maj; int size; };
//@ f_146f46
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft vor dem Abspielen einer Sounddatei p2, ob diese mit dem Attic-eigenen
 *   8-Byte-Soundheader (d_1a9834) beginnt, und liest in diesem Fall die eingebetteten Steuerblöcke für
 *   Lautstärke (VOLU), festes Panorama (PAN ), Abtastraten-Pitch (PITC) und zeitgesteuerte Hüllkurven (PANS /
 *   Kurventabellen PP(0x18c + i*4)) ein. Am Ende speichert sie die Gesamtlänge des Headers in SS(0x18a), damit
 *   die eigentliche PCM-Wiedergabe erst hinter dem Header einsetzt.
 * - Eingaben: p (Soundmanager), p2 (geöffnetes Dateiobjekt F *).
 * - Rückgabewert: 1, wenn die Datei gültig geprüft bzw. geparst wurde, 0 bei Dateifehlern.
 * - Wichtige Variablen:
 *   - header, size: Signatur und Bytegröße des Attic-Soundheaders.
 *   - tag, val: 4-Byte-Chunk-Kennung (VOLU, PAN , PITC, PANS) und zugehöriger Parameterwert.
 *   - SS(0x18a): Startoffset der rohen PCM-Daten (Hinweis: wird bei Dateien ohne Header nicht auf 0
 *     zurückgesetzt, siehe Fehlerliste).
 === Ende Beschreibung === */
struct Reader494 {
    char data[0x14];
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0c(); virtual void v10();
    virtual int open(int, short);
    virtual void v18(); virtual void v1c();
    virtual int read(void *, int);
    virtual void v24(); virtual void close();
};
struct VideoHeader494 {
    int magic;
    unsigned short minor;
    unsigned short major;
    int size;
    int operator==(int *other) {
        return magic == *other;
    }
};
void f_146f46(int p, int p2)
{
    struct Mode494 { static short get() { return 0x200; } };
    short total = 0;
    int tag = 0;
    short size = 0;
    VideoHeader494 header;
    ((Reader494 *)II(0x20))->open(p2, Mode494::get());
    total += ((Reader494 *)II(0x20))->read(&header, 10);
    if (header == d_1a9834) {
        char buf[20];
        if (header.minor == 0 && header.major == 1) {}
        else f_1664d0(STR(d_1b89b8), STR(d_1a980c), 0x250);
        SS(0x18a) = header.size;
        while (total < SS(0x18a)) {
            total += ((Reader494 *)II(0x20))->read(&tag, 4);
            total += ((Reader494 *)II(0x20))->read(&size, 2);
            switch ((unsigned)tag) {
            case 0x554c4f56:
                if (US(0x17c) == 0x7fff)
                    total += ((Reader494 *)II(0x20))->read((void *)(p + 0x17c), size);
                else
                    total += ((Reader494 *)II(0x20))->read(buf, size);
                break;
            case 0x204e4150:
                if (US(0x17e) == 0x8000)
                    total += ((Reader494 *)II(0x20))->read((void *)(p + 0x17e), size);
                else
                    total += ((Reader494 *)II(0x20))->read(buf, size);
                break;
            case 0x43544950:
                if (II(0x182) == d_1a9820)
                    total += ((Reader494 *)II(0x20))->read((void *)(p + 0x182), size);
                else
                    total += ((Reader494 *)II(0x20))->read(buf, size);
                break;
            case 0x534e4150:
                if (SS(0x180) == 0)
                    total += ((Reader494 *)II(0x20))->read((void *)(p + 0x180), size);
                else
                    total += ((Reader494 *)II(0x20))->read(buf, size);
                break;
            default:
                total += ((Reader494 *)II(0x20))->read(buf, size);
                break;
            }
        }
    }
    ((Reader494 *)II(0x20))->close();
}
//@ f_147323
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet und startet eine digitale Soundressource anhand ihrer Ressourcen-ID p2 mit p3
 *   Wiederholungen. Falls bereits mehr als 11 Kanäle gleichzeitig aktiv sind, beendet sie zunächst den ältesten
 *   Kanal, parst über f_146f46 eventuelle Steuerblöcke der Sounddatei, erzeugt ein neues HM-Kanalobjekt
 *   (f_1461f4) in einem freien Slot AA(i) und aktiviert bei vorhandenen Hüllkurven den dynamischen Effektkanal.
 * - Eingaben: p (Soundmanager), p2 (Ressourcen-ID der Sounddatei), p3 (Loop-Anzahl).
 * - Rückgabewert: Vergebener Kanalindex (0..15) oder -1 bei Fehlern bzw. deaktiviertem Sound.
 * - Wichtige Variablen:
 *   - F: Neu angelegtes Dateiobjekt zum Lesen der Soundressource p2.
 *   - HT: Neu erzeugtes HM-Soundkanal-Objekt im freien Slot AA(i).
 *   - US(0x17c), SS(0x17e), SS(0x180), II(0x182): Vorbereitete Startwerte für Lautstärke, Panning, Pitch und
 *     Basis-Samplingrate.
 === Ende Beschreibung === */
struct File5 {
    char pad[0x14];
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0c(); virtual void v10();
    virtual int open(int, short);
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void release(); virtual void v2c(); virtual unsigned length();
};
int f_147323(int p, int p2, unsigned short p3, unsigned short p4, int p5, short p6, unsigned short p7)
{
    struct Flags5 { static short mode() { return 0x200; } };
    unsigned t;
    int r;
    short n;
    short k;
    short i;
    r = 0;
    n = 0;
    k = 0;
    t = 0;
    if (0x7fff < (unsigned short)p3)
        f_1664d0(STR(d_1b89e1), STR(d_1a980c), 0x2b2);
    if (II(8) == 1) {
      if (II(0xc) == 1) {
       if (((File5 *)II(0x20))->open(p2,Flags5::mode()) == 1) {
        t = ((File5 *)II(0x20))->length();
        ((File5 *)II(0x20))->release();
        k = f_168787(II(0x172));
        if ((short)k > SS(0x186))
            SS(0x186) = k;
        if (k > 0xf) {
            f_147aad(p);
            k = 0;
            n = 0;
        } else {
            for (i = 0; i < (short)0x10; i++) {
                if (AA(i) != 0) {
                    if (0xb < (short)n) {
                        delete (HT *)AA(i);
                        AA(i) = 0;
                        break;
                    }
                    n++;
                    if (0xb < (short)n)
                        i = 0;
                }
            }
        }
        for (i = 0; i < (short)0x10; i++) {
            if (AA(i) == 0) {
             if (r == 0) {
                US(0x17c) = (unsigned short)p3 + (SS(0x17a) - 0x7fff);
                SS(0x17e) = p4;
                SS(0x180) = p6;
                II(0x182) = p5;
                f_146f46(p, p2);
                AA(i) = (int)new (mark(d_1a980c, 0x2f0)) HT(p2, II(0x20), (int)SS(0x18a), II(0x172), (unsigned)US(0x17c), (unsigned)US(0x17e), II(0x182), (int)SS(0x180), p7);
                r = 1;
                t = t / (unsigned)II(0x182) + 1;
                if (0xffffffffU - t < d_1c391c)
                    DD(i) = t - (0xffffffffU - d_1c391c);
                else
                    DD(i) = d_1c391c + t + 1;
                break;
             }
            }
        }
        if ((short)n > SS(0x188))
            SS(0x188) = n;
       }
      }
    }
    return r;
}
//@ f_147688
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob im Kanal-Slot p2 aktuell noch ein Sound abgespielt wird. Ist das Sample bereits
 *   abgelaufen, wird das Kanalobjekt in AA(p2) gleich freigegeben.
 * - Eingaben: p (Soundmanager), p2 (Kanalindex 0..15).
 * - Rückgabewert: 1, wenn der Kanal noch aktiv spielt, sonst 0.
 * - Wichtige Variablen: AA(p2).
 === Ende Beschreibung === */
void f_147688(int p, int p2)
{
    int i;
    if (II(0xc) == 1) {
        for (i = 0; ((short)(i) < (short)0x10); i = i + 1) {
            if (AA(i) != 0) {
                if (f_146364(AA(i)) == p2) {
                    delete (HT *)AA(i);
                    AA(i) = 0;
                    DD(i) = 0;
                }
            }
        }
    }
}
//@ f_147746
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt die globale Master-Lautstärke (US(0x186)) des digitalen Soundmanagers ein (begrenzt
 *   auf 0..0x7fff) und gibt den zuvor eingestellten Wert zurück.
 * - Eingaben: p (Soundmanager), p2 (neue Gesamtlautstärke).
 * - Rückgabewert: Vorherige Gesamtlautstärke.
 * - Wichtige Variablen: US(0x186).
 === Ende Beschreibung === */
void f_147746(int p, int p2)
{
    if (0x7fff < (unsigned short)p2)
        f_1664d0(STR(d_1b89f2), STR(d_1a980c), 0x325);
    US(0x17a) = (unsigned short)p2;
}
//@ f_14778f
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die Sound-Ressource mit der Kennung p2 derzeit in einem der 16 Kanäle
 *   (AA(0..15)) des Soundmanagers p abgespielt wird (f_146364(AA(i)) == p2).
 * - Eingaben: p (Soundmanager), p2 (gesuchte Sound-Ressourcen-ID).
 * - Rückgabewert: 1, wenn das Sample aktuell läuft, sonst 0.
 * - Wichtige Variablen: i (Slot-Index), AA(i).
 === Ende Beschreibung === */
int f_14778f(int p, int p2)
{
    int r;
    LV i;
    r = 0;
    if (II(0xc) == 1) {
        for (i = 0; i < (short)0x10; i++) {
            if (AA(i) != 0) {
                if (f_146364(AA(i)) == p2) {
                    r = 1;
                    break;
                }
            }
        }
    }
    return r;
}
//@ f_147808
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob im Soundmanager p aktuell überhaupt mindestens ein digitaler Soundkanal
 *   (AA(0..15)) belegt ist.
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: 1, wenn mindestens ein Kanal aktiv ist, sonst 0.
 * - Wichtige Variablen: i (Slot-Index), AA(i).
 === Ende Beschreibung === */
int f_147808(int p)
{
    int r;
    LV i;
    r = 0;
    if (II(0xc) == 1) {
        for (i = 0; i < (short)0x10; i++) {
            if (AA(i) != 0) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
//@ f_147869
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft bei aktivierter Soundausgabe (II(0xc) == 1), ob der spezifische Kanal-Slot p2
 *   (AA(p2)) aktuell belegt ist.
 * - Eingaben: p (Soundmanager), p2 (Kanalindex 0..15).
 * - Rückgabewert: 1, wenn Slot p2 aktiv ist, sonst 0.
 * - Wichtige Variablen: AA(p2).
 === Ende Beschreibung === */
int f_147869(int p, int p2)
{
    int r = 0;
    if (II(0xc) == 1) {
        if (AA(p2) != 0)
            r = 1;
    }
    return r;
}
//@ f_1478b4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den protokollierten Spitzenwert gleichzeitig aktiver Soundkanäle (SS(0x188)) zurück.
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: Maximalzahl gleichzeitiger Kanäle (short).
 * - Wichtige Variablen: SS(0x188).
 === Ende Beschreibung === */
short f_1478b4(int p)
{
    return SS(0x188);
}
//@ f_1478de
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Spitzenwertzähler gleichzeitig aktiver Soundkanäle (SS(0x188)) auf 0 zurück.
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: SS(0x188).
 === Ende Beschreibung === */
void f_1478de(int p)
{
    SS(0x188) = 0;
}
//@ f_147904
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den protokollierten Spitzenwert SS(0x186) des SOS-Treibers zurück.
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: Gespeicherter 16-Bit-Wert SS(0x186) (short).
 * - Wichtige Variablen: SS(0x186).
 === Ende Beschreibung === */
short f_147904(int p)
{
    return SS(0x186);
}
//@ f_14792e
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den gespeicherten Spitzenwert SS(0x186) im Soundmanager p auf 0 zurück.
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: SS(0x186).
 === Ende Beschreibung === */
void f_14792e(int p)
{
    SS(0x186) = 0;
}
//@ f_147954
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest und parst eine Text-Konfigurationsdatei im INI-Stil (insbesondere sound.cfg)
 *   zeilenweise und trägt die gefundenen Schlüssel-Wert-Paare für digitale Soundkarte (DIGI_ID, DIGI_PORT,
 *   DIGI_IRQ, DIGI_DMA, DIGI_PARAM, DIGI_VOLUME) und MIDI-Musik (MIDI_ID, MIDI_PORT, MIDI_PARAM, MIDI_VOLUME) in
 *   die Felder des Soundmanagers ein. Hexadezimale Werte mit 0x-Präfix werden mit Basis 16 (f_152267), alle
 *   übrigen dezimal umgewandelt.
 * - Eingaben: p (Soundmanager), p2 (Dateiname, z. B. "sound.cfg").
 * - Rückgabewert: 1 bei erfolgreichem Einlesen, 0 wenn die Datei nicht geöffnet werden kann.
 * - Wichtige Variablen:
 *   - buf: Zeilenpuffer (100 Bytes) auf dem Stack.
 *   - d_1a985c..d_1a98bc: Schlüsselwort-Konstanten für die 10 Konfigurationsparameter.
 === Ende Beschreibung === */
int f_146b32(int, int, int, int, int);
int f_147954(int p)
{
    int r;
    int h, n;
    char *buf, *q;
    unsigned short a;
    short b, c, d;
    r = 0;
    II(0x10) = 0;
    h = f_144fbf(d_1b8a03, 0x200);
    if (h > 0) {
        n = f_1452bc(h);
        buf = (char *)operator new[](n, mark(d_1a980c, 0x3a1));
        f_144e8b(h, buf, n);
        f_145259(h);
        q = f_14d50b(buf, d_1b8a0e);
        f_15ead2(q, d_1b8a17, &a);
        q = f_14d50b(buf, d_1b8a2b);
        f_15ead2(q, d_1b8a36, &b);
        q = f_14d50b(buf, d_1b8a4a);
        f_15ead2(q, d_1b8a54, &c);
        q = f_14d50b(buf, d_1b8a66);
        f_15ead2(q, d_1b8a70, &d);
        r = f_146b32(p, a, b, c, d);
        operator delete(buf);
    } else {
        II(0x10) = 4;
    }
    return r;
}
//@ f_147aad
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stoppt alle 16 digitalen Soundkanäle (AA(0..15)), zerstört deren HM-Kanalobjekte und gibt
 *   deren Speicher frei.
 * - Eingaben: p (Soundmanager).
 * - Rückgabewert: 1 bei Erfolg, 0 wenn kein Soundtreiber aktiv ist.
 * - Wichtige Variablen: AA(i) (wird für i = 0..15 abgebaut und auf 0 gesetzt).
 === Ende Beschreibung === */
void f_147aad(int p)
{
    int i;
    for (i = 0; ((short)(i) < (short)0x10); i = i + 1) {
        if (AA(i) != 0) {
            delete (HT *)AA(i);
            AA(i) = 0;
            DD(i) = 0;
        }
    }
}
