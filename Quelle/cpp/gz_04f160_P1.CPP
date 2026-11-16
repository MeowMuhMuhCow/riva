/* === Beschreibung (Katalog) ===
 * Einheit gz_04f160 (04f160 - 04fc60)
 *
 * Überblick
 * Diese Einheit implementiert die zentrale Ereignis- und Eingabeschleife des Heldenbogens (f_04f3f0) sowie die
 * Aktualisierung der Slot-Markierungen und der Gegenstands-Statuszeile am unteren Fensterrand (f_04f160).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 0/2 gleich (suche.py 29.10.2026, Basis gz_04f160_P1.CPP)
// gz_04f160.cpp (Schatten ueber Riva) - Pass 1, Code 0x04F160-0x04FC60
#include <string.h>
struct T { signed char k; short s1; short s3; char p5[4]; short s9; int ia; int ib; char p13[10]; short s1d; char p1f; short s20; short s22; short s24; short s26; char p28[0x112-0x28]; int x112; };
struct O { int a0; int p4; char p8[0x10]; int p18; char p1c[0x20]; };
int f_036300(int p1, int p2, int p3);




int f_045960(int p1, int p2);
int f_046bc0(int p1);
int f_04aef0(T *p1, int p2);
int f_04af60(T *p1);
int f_04b0d0(T *p1, int p2, int p3, int p4);
int f_04b3a0(T *p1);
int f_04b5f0(T *p1);
int f_04b670(T *p1);
int f_04b6f0(T *p1);
int f_04b880(int p1, int p2);
int f_04b980(T *p1);
int f_04c000(T *p1);
int f_04c360(T *p1);
int f_04c5c0(T *p1);
int f_04dbf0(T *p1);
int f_04e020(T *p1);
int f_04e340(T *p1);
int f_04e470(T *p1);
int f_04ed90(T *p1);
int f_05e320(int p1, int p2, int p3);
int f_068f40();
void f_0a7840(RivaItemDefinition *item,char *dst,short n);



int f_0bf730(int p1, int p2);
int f_0d26e0();
int f_0d2710();
int f_0d3530(int p1);
int f_0d37b0();
int f_0d3800();
int f_0d3860();
short f_0d4ad0(int p1);
short f_0d4b00(int p1);
int f_0d5550(int p1);
int f_0d5a90();
int f_0dbfb0(int p1, int p2);
int f_0e9300(int p1, int p2, int p3);
int f_0e9660(int p1, int p2, int p3, int p4);

O *f_125400(O *p1, int p2, int p3);
int f_1254a0(O *p1);
extern char d_1a0514;
extern char d_1a0515;
extern int d_1a0fd4;
extern int d_1a10ec;
extern int d_1a1288;
extern int d_1a34e0;
extern int d_1a9668;
extern int d_1bc8f4;
extern char d_1bc930;
extern int d_1bc940;
extern unsigned short d_1bd762;
extern short d_1bd766;
extern signed char d_1bf4ef;
extern short d_1bf4f0;
extern short d_1bf4f2;
extern int d_1bf510;
extern int d_1bf514;
extern int d_1bfa78;
extern signed char d_1bfaec;
extern int d_1c0004;
extern int d_1c0c4c;
extern short d_1c2198;
extern int d_1c21b4;
extern int d_1c2bcc;

extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;

//@ f_04f160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet den aktuellen Heldenbogen über f_04e470 neu, hebt die ausgewählten Inventarslots
 *   (p->s20 und p->s22) farbig hervor und gibt am unteren Fensterrand (ab y = 0xc0) den vollständigen Namen des
 *   ausgewählten Gegenstands mitsamt Zusatzhinweisen (z. B. "nicht passend für diesen Helden" oder das
 *   zugehörige Kampftalent bei Waffen) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p (struct T *) entgegen und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_042a60(p->ib, p->s20) wird die Gegenstands-ID im aktuell markierten Slot
 *   ermittelt, f_0a7840 formatiert den Gegenstandsnamen nach d_1c21b4, f_045960 prüft die Tragbarkeit durch den
 *   Helden p->ia, und bei Waffen liefert f_0a78b0 das zugehörige Kampftalent.
 === Ende Beschreibung === */
void f_04f160(T *p)
{
    int t106_16;
    short sh;
    signed char cv;
    int r;
    int v;
    volatile int g;
    if (f_0d3860() == 1) { f_0d2710(); g = 1; } else g = 0;
    { 
      
      char rt2=d_1a0515; d_1a0515=rt2;
      signed char rt3=d_1bf4ef; d_1bf4ef=rt3;
      short rt4=d_1c2198; d_1c2198=rt4; } // Haelt die Sortierfolge der Globals
    f_04e470(p);
    d_1a0515 = 0xff;
    d_1a0514 = 0xff;
    f_0d5550((int)&d_1c2bcc);
    if (p->k < 3) {
        if (d_1bf4ef == 0) {
            if ((t106_16 = p->s20) != -1 && p->ib == p->ia && p->s22 == -1)
                f_04b0d0(p, d_1a34e0, p->s20, 0);
            sh = f_0d3530((cv = d_1bc930) ? (int)&d_1a10ec : (int)&d_1a0fd4);
            if (sh >= 0x80 && sh <= 0xa0) {
                if (p->s22 != -1) {
                    p->s22 = sh - 0x80;
                } else {
                    if (sh < 0x9f) {
                        p->s20 = sh - 0x80;
                    }
                }
            }
        }
        if (p->s20 != -1 && p->ib == p->ia)
            f_04b0d0(p, d_1a34e0, p->s20, 0xfd);
        if (p->s22 != -1)
            f_04b0d0(p, d_1a34e0, p->s22, 0xf9);
        v = p->s20;
        if (v != -1) {
            if (f_042a60((struct hero *)(p->ib), v)) {
                sh = f_042a60((struct hero *)(p->ib), p->s20);
                RivaItemDefinition **description_items = d_1c2c40;
                f_0a7840(description_items[sh], (char *)((int)&d_1c21b4), 1);
                sh = f_042a60((struct hero *)(p->ib), p->s20);
                if (f_045960(p->ia, (int)sh) == 0) {
                    f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x200001b5);
                    f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x3040001);
                }
                sh = f_042a60((struct hero *)(p->ib), p->s20);
                RivaItemDefinition **tested_items = d_1c2c40;
                if (tested_items[sh]->f_0a7990() != 0) {
                    sh = f_042a60((struct hero *)(p->ib), p->s20);
                    int item_offset = (sh & 0) ? 0 : sh * 4; // Haelt die separate Offset-Lebensdauer
                    int table_base = *(int *)&d_1c2c40;
                    if (((RivaItemDefinition*)(*(int *)(item_offset + table_base)))->f_0a7950() == 0) {
                        f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x200001b5);
                        sh = f_042a60((struct hero *)(p->ib), p->s20);
                        RivaItemDefinition **items = d_1c2c40;
                        cv = ((signed char)(items[sh]->f_0a78b0()));
                        f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, cv + 0x2000005c);
                    }
                }
                f_05e320((int)&d_1c38b0, 0xff, -1);
                f_0e9660((int)&d_1c38b0, (int)&d_1c21b4, 0, 0xc0);
            }
        }
    }
    p->s3 = 0;
    d_1c2198 = p->s3;
    if (g == 1) f_0d26e0();
}

//@ f_04f3f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette interaktive Hauptschleife des Heldenbogens für den übergebenen Helden aus:
 *   Sie verarbeitet Tastatur- und Mausnavigation durch die Inventarslots, den Reiterwechsel, den Heldenwechsel
 *   (Pfeil links/rechts), das Ablegen/Aufnehmen/Benutzen von Gegenständen (Enter/Entf), die Anzeige von
 *   Krankheits-, Gift- und Stufenaufstiegshinweisen sowie bei Rechtsklick oder Bild-auf das Öffnen der
 *   Steigerungs- und Detaildialoge (f_04b980 bis f_04c5c0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Heldenbogen-Objekt p sowie den Zeiger auf den
 *   beim Öffnen darzustellenden Helden p2 und gibt als int das Ergebnis von f_1254a0 zurück.
 * - Wichtige Variablen: Das Feld p->s1 beendet bei != 0 (Escape 0x11b) die Schleife, p->k hält den aktuellen
 *   Reiter (1 bis 5), p->ia und p->ib verweisen auf den aktiven bzw. beim Gegenstandstransfer gewählten Helden,
 *   und d_1bd766 / d_1bd762 liefern die aktuellen Tasten- und Hotspot-Codes.
 === Ende Beschreibung === */
int f_04f3f0(T *p, int p2)
{
    O *f_125400(O *, int, int, int);
    int f_1254a0(O *, int);
    extern int d_1c3498;
    struct F { O obj; int g4,g1,g2,g3; } frame;
    short lx;
    short t5;
    short t4;
    int r6;
    int r8;
    int uv;
    short sh;
    signed char cv, ab6cv; char ab6byte;
    unsigned short u1;

    short ly;
    lx = -1;
    ly = -1;
    f_125400(&frame.obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    if ((char)((char)(f_042350((struct hero *)(p2)))) != (char)0) {
        if (f_0dbfb0(d_1c0004, p2) != 0) {
            if (*(short *)&d_1a9668 != (short)0)
                goto setup;
        }
    }
    return f_1254a0(&frame.obj, 0);
setup:
    {
        d_1bc8f4 = p2;
        p->k = 1;
        p->ia = d_1bc8f4;
        d_1bd766 = 0;
        p->ib = p->ia;
        ++d_1c0c4c;
        f_04b3a0(p);
        for (;;) {
            if (p->s1 != (short)0) break;
            if (d_1c2198 != (short)0 || p->s3 != (short)0)
                f_04f160(p);
            d_1bf514 = 0;
            if (*(volatile signed char *)&p->k < 3) {
                if ((ab6byte=d_1bc930) != (char)0)
 d_1bf510 = (int)&d_1a10ec;
 else d_1bf510 = (int)&d_1a0fd4;
            } else
                d_1bf510 = (int)&d_1a1288;
            struct EventsA1 {
                static inline void update(T *q) {
                    char before = d_1bfaec, current;
                    f_068f40();
                    f_0d5a90();
                    if (*(int *)&d_1bfa78 == 1) {
                        current = d_1bfaec;
                        if (before != current) {
                            q->k = 1;
                            *(short *)&(*(int *)&d_1c2198) = 1;
                        }
                        if (q->s9 != -1) f_04aef0(q, q->s9);
                    }
                }
            };
            EventsA1::update(p);
            if (d_1c2198 != (short)0)
                f_04f160(p);
            if (d_1bd766 == 0x4d00) {
LAB_53a:
                f_04e020(p);
            } else if (d_1bd766 == 0x4b00) goto LAB_594;
            else if (d_1bd766 == 0xa4) {
                if (p->s22 != -1) goto LAB_53a;
                d_1c2198=f_04b880(p->ia,0x304005c);
            } else if (d_1bd766 == 0xa3) {
                if (p->s22 != -1) goto LAB_594;
                d_1c2198=f_04b880(p->ia,0x304005c);
            }
            goto ab6_key_done;
LAB_594:
            f_04b6f0(p);
ab6_key_done:
            if (p->k < 3) {
                if (d_1bd766 == 0x4800) {
                    if (p->s22 == -1 && p->s24 == -1) {
                        if (f_0d3860() == 1) { f_0d2710(); frame.g1 = 1; } else frame.g1 = 0;
                        uv = f_04b0d0(p, d_1a34e0, p->s20, 0);
                    if (frame.g1 == 1) f_0d26e0();
}
                    f_04b670(p);
                } else if (d_1bd766 == 0x5000) {
                    if (p->s22 == -1 && p->s24 == -1) {
                        if (f_0d3860() == 1) { f_0d2710(); frame.g2 = 1; } else frame.g2 = 0;
                        uv = f_04b0d0(p, d_1a34e0, p->s20, 0);
                    if (frame.g2 == 1) f_0d26e0();
}
                    f_04b5f0(p);
                } else if (d_1bd766 == 0x7a || (d_1bd766 == 0x7b && (ab6byte=d_1bc930) == (char)0)) {
                    f_04e340(p);
                    d_1c2198 = 1;
                }
                if (d_1bd766 >= 0x80 && d_1bd766 <= 0xa0) {
                    if (p->s22 != -1) {
                        p->s22 = d_1bd766 - 0x80;
                        d_1bd766 = 0x1c0d;
                    } else if (d_1bd766 < 0x9f) {
                        t5 = d_1bd766 - 0x80;
                        d_1bd766 = 0x1c0d;
                        p->s20 = t5;
                    }
                }
                if (d_1bd766 == 0x1c0d)
                    f_04dbf0(p);
                if (d_1bd766 == 0x5300 && p->s20 != -1 && p->s22 == -1) {
                    if (p->ib != p->ia) f_0bf730((int)&d_1c2c64, 0x3040039);
                    else { f_036300(p->ia, p->s20, -1); f_04b3a0(p); }
                }
                if (d_1bc940 == 1)
                    d_1bd766 = 0x11b;
                if ((d_1bd766 == 0x11b || d_1bd766 == 0x7e) && p->s22 != -1 && f_0d3800() == 0) {
                    p->s1d = 0;
                    p->ib = p->ia;
                    f_04b3a0(p);
                    d_1bd766 = 0;
                }
                if (d_1bf4ef == 0) {
                    r6 = d_1bf4f0;
                    if (*(short *)&lx != r6 || (r6 = (short)ly) != *(volatile short *)&d_1bf4f2) {
                        lx = d_1bf4f0;
                        ly = d_1bf4f2;
                        if (p->k < 3) {
                            if ((ab6byte=d_1bc930) != (char)0)
                                r6 = (int)&d_1a10ec;
                            else
                                r6 = (int)&d_1a0fd4;
                        } else
                            r6 = (int)&d_1a1288;
                        t4 = f_0d3530(r6);
                        r8 = t4;
                        if (r8 >= 0x80 && r8 <= 0xa0) {
                            if (p->s22 != -1) {
                                p->s22 = t4 - 0x80;
                            } else if (r8 < 0x9f)
                                p->s20 = t4 - 0x80;
                        }
                    }
                }
                if (p->s24 != p->s20 && p->ib == p->ia) {
                    if (f_0d3860() == 1) { f_0d2710(); frame.g3 = 1; } else frame.g3 = 0;
                    f_04b0d0(p, d_1a34e0, p->s24, 0);
                    f_04b0d0(p, d_1a34e0, p->s20, 0xfd);
                    p->s24 = p->s20;
                    ((RivaRasterImage*)(p->x112))->f_0fade0((void *)( d_1a34e0), 0, 0xc0);
                    uv = p->s20;
                    if (f_042a60((struct hero *)(p->ia), uv)) {
                        t5 = f_042a60((struct hero *)(p->ia), p->s20);
                        RivaItemDefinition **table_first = d_1c2c40;
                        f_0a7840(table_first[t5], (char *)((int)&d_1c21b4), 1);
                        t5 = f_042a60((struct hero *)(p->ia), p->s20);
                        if (f_045960(p->ia, (int)t5) == 0) {
                            f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x200001b5);
                            f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x3040001);
                        }
                        t5 = f_042a60((struct hero *)(p->ia), p->s20);
                        if (d_1c2c40[t5]->f_0a7990() != 0) {
                            t5 = f_042a60((struct hero *)(p->ia), p->s20);
                            RivaItemDefinition **table_third = d_1c2c40;
                            if (table_third[t5]->f_0a7950() == 0) {
                                f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x200001b5);
                                t5 = f_042a60((struct hero *)(p->ia), p->s20);
                                int item_offset = (t5 & 0) ? 0 : t5 * 4; // Haelt die getrennte Offset-Lebensdauer
                                int item_base = *(int *)&d_1c2c40;
                                cv = ((signed char)(((RivaItemDefinition*)(*(int *)(item_offset + item_base)))->f_0a78b0()));
                                f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, cv + 0x2000005c);
                            }
                        }
                        f_05e320((int)&d_1c38b0, 0xff, -1);
                        f_0e9660((int)&d_1c38b0, (int)&d_1c21b4, 0, 0xc0);
                    }
                if (frame.g3 == 1) f_0d26e0();
}
                if (p->s26 != p->s22 && p->s22 != -1) {
                    if (f_0d3860() == 1) { f_0d2710(); frame.g4 = 1; } else frame.g4 = 0;
                    f_04b0d0(p, d_1a34e0, p->s26, 0);
                    if (p->ib == p->ia)
                        f_04b0d0(p, d_1a34e0, p->s20, 0xfd);
                    f_04b0d0(p, d_1a34e0, p->s22, 0xf9);
                    p->s26 = p->s22;
                if (frame.g4 == 1) f_0d26e0();
}
            }
            if (d_1bc940 == 1) {
                d_1bd766 = 0x11b;
                d_1bc940 = 0;
            }
            if (d_1bd766 == 0x11b) {
                p->s1 = 1;
                d_1bd766 = 0;
                d_1bd762 = 0;
            }
            if (d_1bd766 == 0x7c && (t5 = f_0d4ad0(p->ia)) != (short)0) {
                uv = p->ia;
                *(int *)(frame.obj.p4 + 4) = uv;
                t5 = f_0d4ad0(uv);
                f_0bf730((int)&d_1c2c64, t5 + 0x304000c);
            } else {
                if (d_1bd766 == 0x7d && (t5 = f_0d4b00(p->ia)) != (short)0) {
                    uv = p->ia;
                    *(int *)(frame.obj.p4 + 4) = uv;
                    t5 = f_0d4b00(uv);
                    f_0bf730((int)&d_1c2c64, t5 + 0x304002b);
                }
                else if (d_1bd766 == 0xa1) {
                    f_04ed90(p);
                    d_1c2198 = 1;
                } else if (d_1bd766 == 0xa2) {
                    struct ActorSlotA1 { int unused; int value; };
                    ActorSlotA1 *actor_slot = (ActorSlotA1 *)frame.obj.p4;
                    actor_slot->value = p->ia;
                    cv = f_0428d0((struct hero *)(actor_slot->value));
                    r6 = f_046bc0((int)(short)(cv + 1));
                    r8 = ((int)(f_0428f0((struct hero *)(p->ia))));
                    *(int *)(frame.obj.p18 + 4) = r6 - r8;
                    { int fl_rt = d_1bf514; d_1bf514 = fl_rt; } // Haelt die Registerfolge vor dem Aufruf
                    f_0bf730((int)&d_1c2c64, 0x304005f);
                }
            }
            if (f_0d37b0() != 0 || d_1bd762 == 0x4900) {
                u1 = p->s9;
                f_04af60(p);
                p->s9 = u1;
                switch (p->k) {
                case 1: f_04b980(p); break;
                case 2: f_04c000(p); break;
                case 3: f_04c360(p); break;
                case 4:
                case 5: f_04c5c0(p);
                }
                if (p->s9 != -1)
                    f_04aef0(p, p->s9);
            }
        }
        *(volatile short *)&d_1c2198 = 1;
        int nesting = d_1c0c4c;
        d_1c0c4c = nesting - 1;
    }
    return f_1254a0(&frame.obj, 0);
}

