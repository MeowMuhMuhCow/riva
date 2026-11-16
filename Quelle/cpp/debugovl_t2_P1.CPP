/* === Beschreibung (Katalog) ===
 * Einheit debugovl_t2 (0538a0 - 053f00)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil des Entwickler- und Diagnose-Overlays (debugovl.cpp). Sie enthält die
 * Texteingabe- und Formatierungsroutinen des Debug-Monitors, den Tonfolgen-Generator für den PC-Lautsprecher,
 * den Befehlsinterpreter für die Text-Kommandotabelle d_1a15a4 sowie die Hauptfunktion f_053c50, die aus dem
 * Grafikmodus in die Textmodus-Debugkonsole umschaltet und danach den Grafikbildschirm samt Palette
 * wiederherstellt.
 === Ende Beschreibung === */
// P3 6/7 gleich (suche.py 25.10.2026, Basis debugovl_t2_P1.CPP)
// debugovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil t2 0x0538A0-0x053F00
#include <string.h>
#include <stdarg.h>
#include <bios.h>
#include "RIVAMEM.H"



struct Cmd { void (*fn)(); const char *name; signed char flags; };
int f_14d1c1(int p1, int p2);
int f_14d27d(const char *fmt, ...);
int f_14d36e(int p1);
int f_14d5c9(char *p1);
int f_14d652(char *b, const char *fmt, va_list ap);
int f_14d667(int p1);
int f_14d6b1();
signed char f_145400(int p1);
int f_149cf0(int p1);
void __cdecl f_149eb4(void *p, int a, int b);
void __cdecl f_149dfe(const char *p);
void __cdecl f_099ef0(void *p, int a, int b);
int f_09ac80(int p1, int p2, void *p3);
int f_09ade0(int p1, int p2, void *p3);
int f_09aed0(int p1);
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1, int p2);
int f_0d2710();
int f_0d26e0();
int f_0d3860();
void f_0d4880(void *p);
int f_01cef0(int p1);
int f_11e6d0(int p1);
#pragma aux f_11e6d0 modify exact [eax];
int f_13e240();
void *f_147c84(void *p, int n, void *t);
void *f_145300(void *p, int c, unsigned n);
int f_051e80(char *p1, int p2, int p3);
void f_053700();
void f_053a30(short x, short y, const char *fmt, ...);
extern short d_1a1490;
extern int d_1a1494;
extern short d_1a1590[];
extern int d_1a34e0;
extern struct Cmd d_1a15a4[];
extern char d_1baac0[];
extern short d_1bc760;
extern int d_1bc944;
extern short d_1bc984;
extern char d_1bc988[];
extern int d_1bca0a;
extern short d_1bca0c;
extern short d_1bca0e;
extern short d_1bd75c;
extern short d_1bd762;
extern short d_1bd766;
extern int d_1c0c4c;
extern char d_1c21b4[];
extern char d_1c2a78[];
extern char d_1c2e68[];
extern const char d_1b6962[];
extern const char d_1b6d68[];
extern const char d_1b6d6a[];
//@ f_0538a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht im Textmodus die Zeile y ab Spalte x, gibt den Eingabeprompt prompt aus und liest
 *   Zeichen für Zeichen (mit Rücktaste-Korrektur und automatischer Großschreibung) eine Benutzereingabe in den
 *   Puffer buf ein, bis Enter (0x1c0d) gedrückt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält die Spalte x, die Zeile y, den Zielpuffer buf (char *) sowie den
 *   Prompttext prompt und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tasten werden direkt über _bios_keybrd nach d_1bd762, d_1bd766 und d_1bd75c gelesen;
 *   bei Enter wird das zuvor angehängte Wagenrücklaufzeichen (0x0d) durch buf[pos - 1] = 0 wieder terminiert.
 === Ende Beschreibung === */
void f_0538a0(short x, short y, char *buf, const char *prompt)
{
    short i;
    short kk;
    short pos = 0;
    short ex = x + strlen(prompt);
    i = x;
    f_14d1c1(y, i);
    while (i++ < 0x50) f_14d27d(d_1b6962);
    f_14d1c1(y, x);
    f_14d27d(prompt);
    f_14d1c1(y, ex);
    do {
        f_0d4880(d_1c2e68);
        d_1bd762 = 0;
        d_1bd766 = 0;
        d_1bd75c = 0;
        if (_bios_keybrd(1)) {
            d_1bd762 = d_1bd766 = _bios_keybrd(0);
            d_1bd75c = d_1bd762 & 0xff;
        }
        if (d_1bd75c) {
            if (d_1bd75c == 8) {
                if (pos > 0) pos--;
                buf[pos] = 0;
                f_053a30(ex + pos, y, d_1b6d68);
                f_14d1c1(y, (short)(ex + pos));
            } else {
                signed char c = f_145400((unsigned char)d_1bd75c);
                buf[pos] = c;
                f_053a30(ex + pos, y, d_1b6d6a, c);
                pos++;
                buf[pos] = 0;
            }
        }
    } while (d_1bd766 != 0x1c0d);
    buf[pos - 1] = 0;
}
//@ f_053a10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest über f_0538a0 eine Textzeile an Position (x, y) in buf ein und wandelt sie mit f_14d5c9
 *   (atoi) in eine Ganzzahl um.
 * - Eingaben und Rückgabe: Die Funktion erhält x, y, den Puffer buf sowie prompt und gibt keinen deklarierten
 *   Wert zurück (im Assembler bleibt das atoi-Ergebnis in EAX).
 * - Wichtige Variablen: Sie kombiniert f_0538a0 unmittelbar mit dem Zahlenparser f_14d5c9(buf).
 === Ende Beschreibung === */
void f_053a10(short x, short y, char *buf, const char *prompt)
{
    f_0538a0(x, y, buf, prompt);
    f_14d5c9(buf);
}
//@ f_053a30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert einen printf-artigen Text mit variabler Argumentliste in den Puffer d_1c21b4,
 *   ersetzt geschützte Leerzeichen (0xff) durch normale Leerzeichen ' ' und gibt den Text an der
 *   Textmodus-Position (x, y) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält die Spalte x, die Zeile y, den Formatstring fmt sowie beliebige
 *   printf-Argumente und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Formatierung erfolgt über f_14d652 (vsprintf) in den globalen Puffer d_1c21b4.
 === Ende Beschreibung === */
void f_053a30(short x, short y, const char *fmt, ...)
{
    va_list ap;
    char *q;
    va_start(ap, fmt);
    f_14d652(d_1c21b4, fmt, ap);
    va_end(ap);
    f_14d1c1(y, x);
    for (q = d_1c21b4; (q = strchr(q, 0xff)) != 0; ) *q = ' ';
    f_14d27d(d_1c21b4);
}
//@ f_053ab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt eine nullterminierte Folge von (Frequenz, Dauer)-Wortpaaren über den
 *   PC-Systemlautsprecher ab und schaltet den Tongeber danach wieder aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt einen Zeiger p (short *) auf das Ton-Array entgegen und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Für jedes Paar mit p[0] > 0 und p[1] > 0 schaltet f_14d667(p[0]) (sound) die Frequenz
 *   ein, f_149cf0(p[1]) (delay) wartet die Dauer in Millisekunden ab, und f_14d6b1() (nosound) beendet die
 *   Tonausgabe.
 === Ende Beschreibung === */
void f_053ab0(short *p)
{
    while (p[1] > 0 && p[0] > 0) {
        f_14d667(*(volatile short *)p);
        f_149cf0((p += 2)[-1]);
    }
    f_14d6b1();
}
//@ f_053ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der globalen Debug-Kommandotabelle d_1a15a4 nach einem Befehl mit dem Namen name und
 *   gibt den Zeiger auf den gefundenen Tabelleneintrag zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Befehlsnamen name (const char *) und gibt einen Zeiger struct
 *   Cmd * auf den Eintrag oder 0 bei Nichtfinden zurück.
 * - Wichtige Variablen: Die Tabelle d_1a15a4 enthält Tripel aus Funktionszeiger fn, Befehlsstring name und
 *   Steuerflags flags bis zum Endeintrag fn == 0.
 === Ende Beschreibung === */
struct Cmd *f_053ae0(const char *name)
{
    struct Cmd *r = 0;
    short i;
    if (name) {
        for (i = 0; d_1a15a4[i].fn != 0 && r == 0; i++)
            if (strcmp(d_1a15a4[i].name, name) == 0) r = &d_1a15a4[i];
    }
    return r;
}
//@ f_053b30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht den eingegebenen Debug-Befehl name in der Kommandotabelle d_1a15a4, bereitet je nach
 *   Befehlsflags den Textbildschirm vor, führt die zugehörige Debug-Funktion (*cmd->fn)() aus, spielt ein kurzes
 *   Bestätigungssignal über den PC-Lautsprecher ab und liefert zurück, ob der Debug-Monitor beendet werden soll.
 * - Eingaben und Rückgabe: Die Funktion erhält den Befehlsstring name (const char *) und gibt als int den Wert
 *   von d_1bc984 (1 = Debug-Konsole verlassen, 0 = weiter) zurück.
 * - Wichtige Variablen: Das Flagbit cmd->flags & 1 steuert, ob vor dem Befehl nur der Bildschirm gelöscht oder
 *   auch der Systemkopf f_053700 ausgegeben wird; d_1a1590 enthält die Tonfolge nach Befehlsausführung.
 === Ende Beschreibung === */
int f_053b30(const char *name)
{
    struct Cmd *cmd = f_053ae0(name);
    *(int *)&d_1bc984 = 0;
    if (cmd) {
        int flags = cmd->flags;
        if ((flags & 1) != 0) {
            f_14d36e(0);
            f_14d1c1(1, 1);
            d_1a1490 = 1;
        } else {
            f_14d36e(0);
            f_14d1c1(1, 1);
            d_1a1490 = 1;
            f_053700();
            { short t_ = (short)(d_1a1490); f_14d1c1(t_, 1); }
        }
        (*cmd->fn)();
        f_053ab0(d_1a1590);
        flags = cmd->flags;
        if ((flags & 1) && !(flags & 2)) {
            f_14d36e(0);
            f_14d1c1(1, 1);
            d_1a1490 = 1;
            f_053700();
        }
    }
    return *(int *)&d_1bc984;
}
//@ f_053c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet aus dem laufenden Spiel heraus die interaktive Textmodus-Debugkonsole: Sie sichert den
 *   aktuellen VGA-Grafikbildschirm und die Farbpalette, schaltet in den 80x25-Textmodus (f_149dfe), zeigt den
 *   Systemkopf und die Eingabezeile d_1bc988 an, verarbeitet Debug-Kommandos bis zum Beenden und stellt
 *   anschließend Grafikmodus, Bildschirminhalt und Palette wieder her.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Sperrflag d_1bc944 verhindert einen rekursiven Aufruf; f_09ac80 und f_09ade0 sichern
 *   bzw. restaurieren den Grafikbildschirm d_1a34e0 über das Backup-Objekt d_1a1494, und f_11e6d0(0x13) schaltet
 *   zurück in den VGA-Modus 13h.
 === Ende Beschreibung === */
void f_053c50()
{
    char buf[0x300];
    struct {
        int fl;
        short key;
        short pad0;
        char lk[4];
        short code;
        short pad1;
    } s;

    if (f_13e240() == 1) {
        f_053ab0(d_1a1590);
        return;
    }
    if (d_1bc944 != 0) return;

    f_0ce7c0(s.lk);
    f_147c84(buf, 0x100, d_1baac0);
    d_1bc944 = 1;
    ++d_1c0c4c;
    if (f_0d3860() == 1) {
        f_0d2710();
        s.fl = 1;
    } else {
        s.fl = 0;
    }
    if (*(int *)&d_1bc760 != 0) f_01cef0(*(int *)&d_1bc760);
    f_149eb4(buf, 0, 0x100);
    f_09ac80(d_1a34e0, d_1a1494, buf);
    f_149dfe(d_1c2a78);
    char *base = d_1bc988;
    f_053700();
    { short y_ = d_1bca0a; short x_ = d_1bca0c; f_14d1c1(x_, y_); }
    f_14d27d(base + 0x8c);
    f_14d27d(base + 0x96, base + 0xa0);
    {
        short sum = strlen(base + 0x8c) + (short)d_1bca0a + d_1bca0e;
        short x_ = d_1bca0c;
        f_14d1c1(x_, sum);
    }

    do {
        s.code = 0;
        s.key = 0;
        while (s.key == 0) {
            f_0d4880(d_1c2e68);
            if (_bios_keybrd(1)) {
                s.key = _bios_keybrd(0);
                s.code = s.key & 0xff;
            }
        }
    } while (f_051e80(d_1bc988, s.key, s.code) == 1);

    d_1bd75c = 0;
    d_1bd762 = 0;
    d_1bd766 = 0;
    f_11e6d0(0x13);
    f_145300(buf, 0, 0x300);
    f_099ef0(buf, 0, 0x100);
    f_09ade0(d_1a34e0, d_1a1494, buf);
    f_09aed0(d_1a1494);
    f_099ef0(buf, 0, 0x100);
    d_1bc944 = 0;
    --d_1c0c4c;
    if (s.fl == 1) f_0d26e0();
    f_0ce7e0(s.lk, 0);
}
