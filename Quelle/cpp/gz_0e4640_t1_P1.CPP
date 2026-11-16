/* === Beschreibung (Katalog) ===
 * Einheit gz_0e4640_t1
 *
 * Diese Einheit bildet den ersten Teil des Abschlussbereichs von popup.cpp (0x0E4640-0x0E4CB0). Sie enthält die
 * Funktionen zum Vorbereiten, Anzeigen und Schließen von Popup-Meldungsfenstern, Text- bzw. Zahleneingabe-Popups
 * sowie von Mengen-Schieberegler-Dialogen.
 === Ende Beschreibung === */
#include "RIVAMOUS.H"
// OPT -4r -oneatx -zp1 -s -ou
// P3 6/8 gleich (suche.py 26.10.2026, Basis gz_0e4640_P1.CPP)
// gz_0e4640.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E4640-0x0E4CB0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01eb40(int p1);                                   // reg eax stapel 0
int f_01eb60(int p1);                                   // reg eax stapel 0
int f_01eb70(int p1, int p2);                           // reg eax edx stapel 0
int f_045db0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e1d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e1f0(int p1);                                   // reg eax stapel 0
int f_05e200(int p1);                                   // reg eax stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e7e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0a6200(int p1, int p2);                           // reg eax edx stapel 0
int f_0a6280(int p1, int p2);                           // reg eax stapel 0
int f_0a6740(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4880(int p1);                                         // reg - stapel 0
int f_0d6710(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0d6ab0(int p1, int p2);                           // reg eax stapel 0
int f_0d6e10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e3580(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3970(int p1, int p2);                           // reg eax edx stapel 0
int f_0e39e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0e4380(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9590(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9610(int p1, int p2);                           // reg eax edx stapel 0
int f_14d5c9(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1bd90c;                    // 0x1BD90C
extern int d_1bf4e8;                    // 0x1BF4E8
extern volatile short d_1bf51c; // haelt Lade-/Schreibfolge in f_0e4710 wie im Original
extern volatile int d_1c0c94;   // haelt Lade-/Schreibfolge in f_0e4710 wie im Original
extern int d_1c299c;                    // 0x1C299C
extern int d_1c2bcc;                    // 0x1C2BCC
extern int d_1c3078;                    // 0x1C3078
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (8), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern int d_1c2e68;
#define P(x) ((int)&(x))
struct RivaE4640LK4 {
        short u;
        RivaE4640LK4();
        ~RivaE4640LK4();
    };
struct RivaE4640Window { char data[56];
      RivaE4640Window(int a,int b,int c,int d,int e);
      ~RivaE4640Window();
    };
struct RivaE4640LK720 { short u; RivaE4640LK720(); ~RivaE4640LK720(); };
//@ f_0e4640  ?
/* === Beschreibung (Katalog) ===
 * Setzt das Flag an Offset +0x38 eines Popup-Fensterobjekts (p1) auf 1, wodurch die nächste Warteschleife
 * (f_0e4380) nicht automatisch nach Ablauf der Lesezeit endet, sondern auf eine ausdrückliche Benutzereingabe
 * wartet.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4640(int p1)
{
    *(short *)(p1 + 0x38) = 1;
}
//@ f_0e4650  groesse 192 B, 55 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Schließt ein geöffnetes Popup-Fenster (p1), stellt den darunterliegenden Bildschirmhintergrund über f_0e3430
 * wieder her und restauriert sämtliche zuvor in der Struktur p1 gesicherten Schriftfarben (+0x2c, +0x2e),
 * Textränder (+0x3a..+0x40), Textabstände (+0x30, +0x32), Musik-/Sound-Zustände (+0x36 über f_01eb70) und
 * Maus-Hotspot-Einstellungen (+0x34, +0x46).
 * - Eingaben: Die Funktion erhält den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4650(int p1)
{
    { RivaMouseGuard mg;
        f_0d2e70();
        f_0e3430(p1);
    }
    f_05e320(P(d_1c38b0), *(short *)(p1 + 0x2c), *(short *)(p1 + 0x2e));
    f_05e2d0(P(d_1c38b0), *(short *)(p1 + 0x3a), *(short *)(p1 + 0x3c), *(short *)(p1 + 0x3e), *(short *)(p1 + 0x40));
    f_05e1d0(P(d_1c38b0), *(short *)(p1 + 0x30), *(short *)(p1 + 0x32));
    *(short *)(p1 + 0x10) = -1;
    *(short *)(p1 + 0x1c) = 0;
    d_1c0c94 = *(short *)(p1 + 0x34);
    f_01eb70(P(d_1c2bcc), *(short *)(p1 + 0x36));
    d_1bf51c = *(short *)(p1 + 0x46);
}
//@ f_0e4710  groesse 288 B, 70 Bef, reg eax edx ebx ecx, stapel 0
/* === Beschreibung (Katalog) ===
 * Bereitet das Öffnen eines Popup-Fensters (p1) für den Text p2 vor: Sie sichert die aktuellen Sound-, Maus- und
 * Textlayout-Einstellungen in den Feldern von p1, schaltet den Mauszeiger um (f_0d2f90(0, 1)), berechnet aus der
 * Spaltenanzahl (+0x12) die Fensterbreite (+0x26) sowie die horizontale Startposition (+0x14 über f_0e3970),
 * richtet die Textränder ein und ermittelt über f_0e9610 die benötigte Textzeilenanzahl (+0x28).
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die Textkennung p2 sowie die zusätzlichen
 *   Textabstandsparameter p3 und p4.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4710(int p1, int p2, int p3, int p4)
{
    short v;
    *(short *)(p1 + 0x36) = f_01eb60(P(d_1c2bcc));
    f_01eb40(P(d_1c2bcc));
    *(short *)(p1 + 0x46) = d_1bf51c;
    d_1bf51c = 0;
    f_0d2f90(0, 1);
    *(int *)(p1 + 0xc) = p2;
    *(short *)(p1 + 0x34) = (short)d_1c0c94;
    d_1c0c94 = 0;
    *(short *)(p1 + 0x1c) = 1;
    f_05e360(P(d_1c38b0), p1 + 0x2c, p1 + 0x2e);
    f_05e2a0(P(d_1c38b0), p1 + 0x3a, p1 + 0x3c, p1 + 0x3e, p1 + 0x40);
    *(short *)(p1 + 0x30) = f_05e1f0(P(d_1c38b0));
    *(short *)(p1 + 0x32) = f_05e200(P(d_1c38b0));
    v = (*(short *)(p1 + 0x12) + 2) * 0x20;
    *(short *)(p1 + 0x26) = v;
    *(short *)(p1 + 0x14) = f_0e3970(p1, v);
    f_05e2d0(P(d_1c38b0), (short)(*(short *)(p1 + 0x14) + 0xf), (short)(*(short *)(p1 + 0x26) - 0x1e), -1, -1);
    f_05e7e0(P(d_1c38b0), (short)p3, (short)p4);
    *(short *)(p1 + 0x28) = f_0e9610(P(d_1c38b0), p2);
}
//@ f_0e4830  groesse 576 B, 164 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * Zeigt ein Popup-Fenster (p1) mit dem Text p3 an und führt - falls eine maximale Eingabelänge p2 > 0 angegeben
 * ist - unterhalb des Textes eine einzeilige Text- bzw. Zahleneingabe (f_0a6740) durch, deren Eingabe
 * anschließend per f_14d5c9 (atoi) in eine 16-Bit-Zahl umgewandelt wird; bei p2 == 0 wird stattdessen ein reines
 * Meldungsfenster über f_0e4380 angezeigt.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die maximale Zeichenanzahl des Eingabefelds p2 (0 für
 *   eine reine Textmeldung ohne Eingabe) sowie die anzuzeigende Textkennung p3.
 * - Rückgabewert: Sie gibt bei Eingabedialogen den eingegebenen Zahlenwert (oder -1 bei Abbruch) bzw. bei reinen
 *   Meldungsfenstern 0 zurück.
 === Ende Beschreibung === */
short f_0e4830(int p1, int p2, int p3)
{
    
    char l50[40];
    short l18;
    RivaE4640LK4 o20;
    l18 = 0;
    f_0d4880(P(d_1c2e68));
    if (p3 != 0 && (short)f_0e9590(P(d_1c38b0), p3) > 0) {
        short old;
        RivaE4640LK4 o14;
        short q;
        q = (short)((short)(unsigned char)f_045db0(P(d_1c3078), 0x5f) * ((short)p2) + 0x20) / 32;
        old = *(short *)(p1 + 0x12);
        if (q > old) *(short *)(p1 + 0x12) = q;
        f_0e4710(p1, p3, 0, 0);
        if (((short)p2)) *(short *)(p1 + 0x28) += 2;
        *(short *)(p1 + 0x2a) = *(short *)(p1 + 0x28) * 8 + 0x1e;
        *(short *)(p1 + 0x16) = f_0e39e0(p1, *(short *)(p1 + 0x2a));
        f_05e320(P(d_1c38b0), 0xff, -1);
        f_05e2d0(P(d_1c38b0), -1, -1, (short)(*(short *)(p1 + 0x16) + 0xf), 1);
        { RivaMouseGuard mg;
            f_0e3580(p1, *(short *)(p1 + 0x28));
            f_0e9550(P(d_1c38b0), p3);
        }
        if (((short)p2)) {
            f_0a6200((int)l50, ((short)p2));
            l18 = f_0a6740((int)l50, P(d_1c299c), (short)(*(short *)(p1 + 0x14) + ((*(short *)(p1 + 0x26) - (f_045db0(P(d_1c3078), 0x5f) & 0xff) * ((short)p2)) >> 1)), (short)((*(short *)(p1 + 0x28) + 1) * 8 + *(short *)(p1 + 0x16)), 0);
            if ((short)l18 != -1) l18 = f_14d5c9(P(d_1c299c));
            f_0a6280((int)l50, 0);
        } else {
            if (!d_1bd90c) f_0d4800(7);
            d_1bf4e8 = 0;
            f_0e4380(p1, 0);
        }
        f_0e4650(p1);
        *(volatile int *)&d_1bf4e8 = 0; // haelt die Register- und Befehlsfolge in f_0e4830 wie im Original
        f_0d3870();
        *(short *)(p1 + 0x12) = old;
        return l18;
    }
    return -1;
}
//@ f_0e4a70  groesse 576 B, 141 Bef, reg eax edx ebx ecx, stapel 8
/* === Beschreibung (Katalog) ===
 * Öffnet ein Popup-Fenster (p1) mit dem Beschreibungstext p3 und blendet darunter einen grafischen Mengen- bzw.
 * Zahlenauswahl-Regler (RivaE4640Window / f_0d6e10, numinput) mit p2 Ziffernstellen im Wertebereich von p4 bis
 * p5 (Startwert p6) ein.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die Stellenanzahl bzw. Breite p2, die Textkennung p3,
 *   der Minimalwert p4, der Maximalwert p5 sowie der voreingestellte Startwert p6.
 * - Rückgabewert: Die Funktion gibt den vom Spieler ausgewählten Zahlenwert zurück oder -1, falls die
 *   Textkennung ungültig war oder der Dialog abgebrochen wurde.
 === Ende Beschreibung === */
short f_0e4a70(int p1, short p2, int p3, short p4, short p5, short p6)
{
    volatile int fl; // haelt den Mausstatus auf dem Stapel wie im Original
    short q;
    short r;
    {
        RivaE4640LK720 o18;
        RivaE4640Window l54(p2, *(int *)p1, p4, p5, p6);
        f_0d4880(P(d_1c2e68));
        if (p3 != 0 && (short)f_0e9590(P(d_1c38b0), p3) > 0) {
            RivaE4640LK720 o14;
            short old;

            q = (short)(p2 * 0xf + 0x20) / 32;
            old = *(short *)(p1 + 0x12);
            if (q > old) *(short *)(p1 + 0x12) = q;
            f_0e4710(p1, p3, 0, 0);
            *(short *)(p1 + 0x28) += 5;
            *(short *)(p1 + 0x2a) = *(short *)(p1 + 0x28) * 8 + 0x1e;
            *(short *)(p1 + 0x16) = f_0e39e0(p1, *(short *)(p1 + 0x2a));
            f_05e320(P(d_1c38b0), 0xff, -1);
            f_05e2d0(P(d_1c38b0), -1, -1, (short)(*(short *)(p1 + 0x16) + 0xf), 1);
            if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; }
            f_0e3580(p1, *(short *)(p1 + 0x28));
            f_0e9550(P(d_1c38b0), p3);
            if (fl == 1) f_0d26e0();
            r = f_0d6e10((int)&l54, (short)(((*(short *)(p1 + 0x26) - p2 * 0xe - 0x32) >> 1) + *(short *)(p1 + 0x14)), (short)((*(short *)(p1 + 0x28) - 1) * 8 + *(short *)(p1 + 0x16)));
            f_0e4650(p1);
            d_1bf4e8 = 0;
            f_0d3870();
            *(short *)(p1 + 0x12) = old;



            return r;
        }


        return -1;
    }
}
//@ f_0e4c60  ?
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4c60 (implementiert in gz_0e4640_t2), die die konstante Bildschirmbreite
 * 320 (0x140) zurückgibt.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den konstanten Wert 320 (0x140) zurück.
 === Ende Beschreibung === */
int f_0e4c60(void)
;
//@ f_0e4c70  ?
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4c70 (implementiert in gz_0e4640_t3), die ebenfalls die konstante
 * Bildschirmbreite 320 (0x140) zurückgibt.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den konstanten Wert 320 (0x140) zurück.
 === Ende Beschreibung === */
int f_0e4c70(void)
;
//@ f_0e4c80  ?
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4c80 (implementiert in gz_0e4640_t3), die einen Block aus
 * hintereinanderliegenden nullterminierten Teilstrings in ein Zeigerarray indiziert.
 * - Eingaben: Übergeben werden das Ziel-Zeigerarray p, der Textblock s sowie die Anzahl der zu suchenden
 *   String-Übergänge n.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4c80(char **p, char *s, unsigned short n)
;
