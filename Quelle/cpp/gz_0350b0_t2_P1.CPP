/* === Beschreibung (Katalog) ===
 * Einheit gz_0350b0_t2 (0x036300 - 0x036ee0)
 *
 * Überblick
 * Dieser zweite Teil des Inventar-Moduls (0x0350b0 - 0x036ee0) enthält die Funktionen zum Wegwerfen bzw.
 * Vernichten von Gegenständen aus dem Inventar (f_036300), zum Aufnehmen neuer Gegenstände in freie
 * Rucksackslots oder bestehende Stapel (f_0366e0, f_036a10) sowie die Zu- und Abschaltung passiver Rucksack-Boni
 * (f_036c10, f_036db0), die bereits durch den bloßen Besitz bestimmter Gegenstände im Inventar wirken.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 1/6 gleich (suche.py 24.10.2026, Basis gz_0350b0_t2_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 1 gleich (vorher 1), Rest 340 (vorher 343)
// gz_0350b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0350B0-0x036EE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_033250(int p1, int p2);                           // reg edx stapel 0
int f_033260(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_033450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
short f_033590(int p1, int p2);                           // reg eax edx stapel 0
void f_0335d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
void f_0338a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
int f_0449d0(int p1, int p2);                           // reg eax edx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
short f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_149360();                       // nicht in clobber.tsv
extern int d_1bc894; extern int d_1c2198; extern int d_1c2a80;

extern int d_1c2c64;
extern signed char d_1a47e9[]; extern char d_1a441f[]; extern signed char d_1a6ad3[];
extern char d_1c3498[]; extern char d_1c349c[]; extern char d_1c3870[];
#define A(x) ((int)&(x))
#define S(x) (*(short *)(x))
#define PC(x) (*(signed char *)(x))
struct Msg { int h; int *a; int x; int *b; int *c; short *d; int z[2]; short *e; int pad[6]; };
struct Item { char b[27]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
void f_036db0(int p1, short p2);
void f_036c10(int p1, int p2);

//@ f_036300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion entfernt oder wirft einen Gegenstand (oder eine Teilmenge eines Stapels) aus
 *   dem Inventarslot p2 des Helden p1 weg. Sie verhindert das Wegwerfen wichtiger Questgegenstände (f_0a78f0()),
 *   fragt bei normalem Wegwerfen (p3 == -1) den Spieler um Bestätigung bzw. um die gewünschte Stückzahl,
 *   reduziert die Traglast, zieht gegebenenfalls Körper- und Rucksackboni (f_0335d0, f_036db0) ab und löscht den
 *   Slot bei vollständiger Entnahme.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, den Slot-Index p2 und die zu entfernende
 *   Anzahl p3 (short, -1 = Benutzerabfrage im UI) und gibt 1 zurück, wenn der Gegenstand entfernt wurde, sonst
 *   0.
 * - Wichtige Variablen: Beim Wegwerfen des speziellen Gegenstands 0x1bc wird das globale Ereignisflag d_1bc894 =
 *   1 gesetzt; S(p1 + 0x4ed) ist die getragene Gesamtlast des Helden.
 === Ende Beschreibung === */
int f_036300(int p1, int p2, short p3)
{
    int f_145300(int, int, int);
    short s;
    short r = 0;
    short t;
    int o;
    CX(m);
    m.a[1] = p1;
    s = S(p1 + 0x1a8 + (short)p2 * 0x1b);
    if (s != (short)0) {
        if ((int)s == 0x1bc) d_1bc894 = 1;
        f_0bf6c0(A(d_1c2c64), 5);
        o = s * 4;
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a78f0() != 0) {
            m.b[1] = (*(int **)&d_1c2c40)[s];
            m.e[1] = 1;
            if (((short)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a78e0())) == 0x1b4 || ((short)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a78e0())) == 0x16b || ((short)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a78e0())) == 0x163)
                f_0bf730(A(d_1c2c64), 0x200001b9);
            else
                f_0bf730(A(d_1c2c64), 0x20000032);
        } else if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7950() != 0) {
            if ((int)S((short)p2 * 0x1b + p1 + 0x1aa) != 1) {
                if ((int)p3 == -1) {
                    m.b[1] = (*(int **)&d_1c2c40)[s];
                    m.e[1] = 2;
                    int q = S((short)p2 * 0x1b + p1 + 0x1aa);
                    p3 = f_0bf7b0(A(d_1c2c64), 2, 0x20000033, 0, q, q);
                }
            } else {
                m.b[1] = (*(int **)&d_1c2c40)[s];
                m.e[1] = p3;
                if ((int)p3 == -1 && f_0bf6f0(A(d_1c2c64), 0x20000034) != 1) goto L4d4;
                p3 = 1;
            }
L4d4:
            if ((int)p3 != -1) {
                int e = (short)p2;
                int ip = p1 + e * 0x1b;
                if (p3 < S(ip + 0x1aa)) {
                    S(ip + 0x1aa) = S(ip + 0x1aa) - p3;
                    short v = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7810();
                    S(p1 + 0x4ed) = S(p1 + 0x4ed) - v * p3;
                    r = 1;
                    signed char c = ((signed char)(f_043030((struct hero *)(p1), e)));
                    if (c) {
                        c = ((signed char)(f_043030((struct hero *)(p1), e)));
                        t = c - p3;
                        if ((int)t <= 0) {
                            t = 0;
                            f_043000((struct hero *)(p1), e, 0);
                        }
                        f_043060((struct hero *)(p1), (short)p2, (signed char)t);
                    }
                } else {
                    short v = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7810();
                    S(p1 + 0x4ed) = S(p1 + 0x4ed) - v * S(ip + 0x1aa);
                    f_145300(p1 + 0x1a8 + e * 0x1b, 0, 0x1b);
                    f_042870((struct hero *)(p1), -1);
                    r = 1;
                }
            }
        } else {
            m.b[1] = (*(int **)&d_1c2c40)[s];
            m.e[1] = 1;
            if ((int)p3 != -1 || f_0bf6f0(A(d_1c2c64), 0x20000034) == 1) {
                if ((int)(short)p2 < 0xf) f_0335d0(p1, s, (short)p2);
                short v = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7810();
                S(p1 + 0x4ed) = S(p1 + 0x4ed) - v;
                f_036db0(p1, s);
                f_145300(p1 + 0x1a8 + (short)p2 * 0x1b, 0, 0x1b);
                f_042870((struct hero *)(p1), -1);
                r = 1;
            }
        }
        f_0bf680(A(d_1c2c64));
    }
    if (d_1c2a80 == 0x30000) *(short *)&d_1c2198 = 1;
    int result = r;
    CXEND(m);
    return result;
}

//@ f_0366e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion fügt einem Helden h bis zu n Exemplare des Gegenstands id in seinen Rucksack
 *   (Slots 15..30) hinzu (vergleichbar mit get_item in *Sternenschweif*). Sie prüft je nach Modus die
 *   Traglastgrenze, füllt bei stapelbaren Gegenständen zuerst einen vorhandenen Stapel bis maximal 99 Stück auf,
 *   belegt für weitere oder nicht stapelbare Gegenstände freie Rucksackslots ab Slot 15, initialisiert Ladungen,
 *   Magie-Flags und Bruchfaktoren und aktiviert über f_036c10 eventuelle Besitzboni.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger h, die Gegenstands-ID id, den Prüfmodus mode (0
 *   = still prüfen, 1 = mit Überlastungsmeldung prüfen, 2 = Traglast ignorieren) sowie die Stückzahl n und gibt
 *   die tatsächlich aufgenommene Anzahl zurück.
 * - Wichtige Variablen: Die Tabellen d_1a47e9 (Standardladungen magischer Gegenstände) und d_1a441f
 *   (Standard-Bruchfaktor von Waffen) liefern die Initialwerte für neu angelegte Inventarslots.
 === Ende Beschreibung === */
struct InventorySlot {
 short id, quantity;
 unsigned char flags;
 char field5;
 signed char weaponBF;
 char rest[20];
};
struct InventoryHero {
 char pre[0x32]; signed char count;
 char between[0x1a8-0x33];
 InventorySlot inv[31];
 short load;
};
struct InventoryMessage:Msg { InventoryMessage(){f_125400((int)this,A(d_1c349c),A(d_1c3870),A(d_1c3498));}~InventoryMessage(){f_1254a0((int)this,0);} };
short f_0366e0(InventoryHero*h, short id, short mode, short n)
{
 short stack_pos; short ret=0; short slot=14; short done;
 InventoryMessage m;
 m.a[1]=(int)h;
 if(mode!=2 && h->load >= f_042a40((struct hero *)((int)h),6)*100) {
  if(mode!=(short)0) f_0bf730(A(d_1c2c64),0x20000035);
 } else if(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7950() && (stack_pos=f_033590((int)h,id))!=-1) {
  if(h->inv[stack_pos].quantity+n>99) n=99-h->inv[stack_pos].quantity;
  h->inv[stack_pos].quantity+=n;
  h->load+=((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7810()*n;
  ret=n;
 } else if(h->count<31) {
  done=0;
  do {
   if(h->count<31) {
    slot=14;
    while(h->inv[++slot].id!=(short)0 && slot<31);
    if(slot<31) {
     if(n>99)n=99;
     h->count++;
     h->inv[slot].id=id;
     h->inv[slot].quantity=((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7950() ? n :
      ((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7970() ? d_1a47e9[((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a78a0()))*3] : 0;
     if(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7a90())h->inv[slot].flags|=8;
     if(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7990())h->inv[slot].weaponBF=d_1a441f[((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a78a0()))*10];
     if(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7950()) {
      h->load+=((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7810()*n;
      ret=n;
      n=0;
     } else {
      h->load+=((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7810();
      n--;
      ret++;
     }
     if(n==(short)0)done=1;
     f_036c10((int)h,id);
    } else done=1;
   } else done=1;
  } while(done==0);
 }
 if(d_1c2a80==0x30000 || d_1c2a80==0x30001)*(short*)&d_1c2198=1;
 return ret;
}
//@ f_036a10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion legt einen Gegenstand p2 mit der Stückzahl p3 gezielt in einen bestimmten, noch
 *   leeren Inventarslot p4 eines Helden p1 hinein (etwa beim Laden von Charakteren oder beim direkten Platzieren
 *   von Ausrüstung) und wendet sowohl Rucksack- als auch Körperslot-Boni (f_036c10, f_0338a0) an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, die Gegenstands-ID p2, die Anzahl p3, den
 *   Zielslot p4 und einen optionalen Vorlagenzeiger p5 (Item *) zum Kopieren bestehender Slot-Flags; sie gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Ist der Zielslot p4 bereits belegt (S(p4 * 0x1b + 0x1a8 + p1) != 0), bricht die Funktion
 *   ohne Änderung ab.
 === Ende Beschreibung === */
extern short Refresh493;
#pragma aux Refresh493 "d_1c2198";
void f_036a10(int p1, short p2, short p3, short p4, Item *p5)
{
    if (S((short)p4 * 0x1b + 0x1a8 + p1) == 0) {
        if (99 < (short)p3) p3 = 99;
        PC(p1 + 0x32) = PC(p1 + 0x32) + 1;
        if (p5 != 0) *(Item *)((short)p4 * 0x1b + 0x1a8 + p1) = *p5;
        int idx = (short)p4;
        int ip = (int)((char *)p1 + idx * 0x1b);
        S(ip + 0x1a8) = (short)p2;
        // Codelose Blockgrenze fuer die Registerwahl des Slotindex
        idx = (idx & 0) ? 0 : idx;
        ip = (idx & 0) ? 0 : ip;
        idx = (short)p2;
        int t = d_1c2c40[idx]->f_0a7950();
        idx = 0; // Beendet die Lebensdauer von idx fuer die Registervergabe
        if (t != 0) {
            S(ip + 0x1aa) = (short)p3;
        } else {
            t = d_1c2c40[(short)p2]->f_0a7970();
            if (t != 0) {
                signed char c = (signed char)d_1c2c40[(short)p2]->f_0a78a0();
                S(ip + 0x1aa) = (signed char)d_1a47e9[c * 3];
            } else {
                S(ip + 0x1aa) = 0;
            }
        }
        t = d_1c2c40[(short)p2]->f_0a7a90();
        if (t != 0) *(unsigned char *)((short)p4 * 0x1b + 0x1ac + p1) |= 8;
        t = d_1c2c40[(short)p2]->f_0a7990();
        if (t != 0) {
            signed char c = (signed char)d_1c2c40[(short)p2]->f_0a78a0();
            *(char *)((short)p4 * 0x1b + 0x1ae + p1) = d_1a441f[c * 10];
        }
        int n = (short)p2;
        { short hold = Refresh493; Refresh493 = hold; } // Haelt das Konfliktgewicht von d_1c2198 fuer die Registerwahl
        short v = d_1c2c40[n]->f_0a7810();
        S(p1 + 0x4ed) = S(p1 + 0x4ed) + v * (short)p3;
        f_036c10(p1, n);
        f_0338a0(p1, p1, n, -1, (short)p4);
        if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) Refresh493 = 1;
    }
}

//@ f_036c10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion gewährt einem Helden passive Talent-, Zauber-, Attributs- oder
 *   Magieresistenz-Boni, sobald er bestimmte besondere Gegenstände in sein Inventar aufnimmt. Dazu gehören unter
 *   anderem +3 auf Schlösserknacken bei ID 0xa1, +5 Magieresistenz bei ID 0xa3, +2 auf Klettern bei ID 0x46, -2
 *   auf ein Attribut beim verfluchten Objekt ID 0x1cb, die Initialisierung des Buchs ID 0x174 sowie je +2 auf
 *   drei Zaubersprüche bei den magischen Schriften/Artefakten 0x1c2, 0x1c3 und 0x1c4.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und die aufgenommene Gegenstands-ID p2
 *   (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Die Talentboni werden über f_03af20, die Magieresistenz über f_0449d0, die
 *   Attributsänderung über f_045430 und die Zauberboni über f_043110 direkt auf den Helden angewendet.
 === Ende Beschreibung === */
void f_036c10(int p1, short p2)
{
    if ((short)p2 == 0xa1) { f_03af20(p1, 0x1d, 3); return; }
    if ((short)p2 == 0xa3) { f_0449d0(p1, 5); return; }
    if ((short)p2 == 0x46) { f_03af20(p1, 0x32, 2); return; }
    if ((short)p2 == 0x1cb) { f_045430(p1, 7, -2); return; }
    if ((short)p2 == 0x174) {
        short n = f_0d4aa0(p1, 0x174);
        f_042a90((struct hero *)(p1), n, 0xbf);
        f_03d8b0(p1, n, 2, 1);
        f_03d8b0(p1, n, 6, 1);
        f_03d8b0(p1, n, 7, 1);
        f_03d8b0(p1, n, 0xe, 1);
        return;
    }
    if ((short)p2 == 0x1c2) {
        f_043110((struct hero *)(p1), 7, 2);
        f_043110((struct hero *)(p1), 0xc, 2);
        f_043110((struct hero *)(p1), 0x38, 2);
    } else if ((short)p2 == 0x1c3) {
        f_043110((struct hero *)(p1), 0x12, 2);
        f_043110((struct hero *)(p1), 0x15, 2);
        f_043110((struct hero *)(p1), 0x17, 2);
    } else if ((short)p2 == 0x1c4) {
        f_043110((struct hero *)(p1), 0x12, 2);
        f_043110((struct hero *)(p1), 0x15, 2);
        f_043110((struct hero *)(p1), 0x1f, 2);
    }
}

//@ f_036db0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion nimmt die durch f_036c10 gewährten passiven Besitzboni für die Gegenstände
 *   0xa1, 0xa3, 0x46, 0x1cb, 0x1c2, 0x1c3 und 0x1c4 wieder zurück, sobald der Gegenstand aus dem Inventar des
 *   Helden entfernt oder an einen anderen Helden weitergegeben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und die entfernte Gegenstands-ID p2 (short)
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die Abzüge sind exakt spiegelbildlich zu den Aufschlägen in f_036c10 (mit Ausnahme des
 *   einmaligen Initialisierungseffekts von 0x174).
 === Ende Beschreibung === */
void f_036db0(int p1, short p2)
{
    if ((short)p2 == 0xa1) {
        f_03af20(p1, 0x1d, -3);
        return;
    }
    if ((short)p2 == 0xa3) {
        f_0449d0(p1, -5);
        return;
    }
    if ((short)p2 == 0x46) {
        f_03af20(p1, 0x32, -2);
        return;
    }
    if ((short)p2 == 0x1cb) {
        f_045430(p1, 7, 2);
        return;
    }
    if ((short)p2 == 0x1c2) {
        f_043110((struct hero *)(p1), 7, -2);
        f_043110((struct hero *)(p1), 0xc, -2);
        f_043110((struct hero *)(p1), 0x38, -2);
        return;
    }
    if ((short)p2 == 0x1c3) {
        f_043110((struct hero *)(p1), 0x12, -2);
        f_043110((struct hero *)(p1), 0x15, -2);
        f_043110((struct hero *)(p1), 0x17, -2);
        return;
    }
    if ((short)p2 == 0x1c4) {
        f_043110((struct hero *)(p1), 0x12, -2);
        f_043110((struct hero *)(p1), 0x15, -2);
        f_043110((struct hero *)(p1), 0x1f, -2);
    }
}

//@ f_036ed0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion liest aus der globalen Talenttabelle d_1a6ad3 aus, wie viele Punkte ein
 *   Held beim Stufenaufstieg maximal auf das Talent p1 steigern darf (in der Regel 1, 2 oder 3 Punkte pro
 *   Stufe).
 * - Eingaben und Rückgabe: Die Funktion erhält den Talentindex p1 und gibt das Steigerungslimit
 *   d_1a6ad3[(short)p1 * 4] als short zurück.
 * - Wichtige Variablen: Die Tabelle d_1a6ad3 ist Teil der vierspaltigen Talent-Stammdatentabelle ab 0x1a6ad0
 *   (drei Prüfattribute plus maximale Steigerung pro Stufe).
 === Ende Beschreibung === */
short f_036ed0(int p1)
{
    return d_1a6ad3[(short)p1 * 4];
}
