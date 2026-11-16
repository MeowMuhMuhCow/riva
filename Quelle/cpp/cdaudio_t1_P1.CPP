/* === Beschreibung (Katalog) ===
 * Einheit cdaudio_t1 (0x0002e56f - 0x0002f883)
 *
 * Überblick
 *
 * Die Einheit cdaudio_t1 implementiert den ersten Teil der CD-Audio-Steuerung (CDAUDIO.CPP) für die
 * Hintergrundmusik von der Spiele-CD. Sie liest das Inhaltsverzeichnis (Table of Contents, TOC) der eingelegten
 * CD aus, prüft, ob es sich um die Original-Riva-CD mit genau 13 Tracks handelt, rechnet Minuten:Sekunden:Frames
 * (Msf) in Sektoradressen um und steuert das Starten, Stoppen und Positionieren der CD-Audiowiedergabe.
 === Ende Beschreibung === */
// P1 4/8 gleich [F1 23.10.: -od; Msf-Klasse mit Ktoren/operator-/tot()/lba(); neue Funktion f_02ef53 (02ef53-02f12f, war Teil von f_02ee42); Ktor/Dtor 02ea8a/02ecc3 ohne f_-Name im OBJ]
// OPT -4r -od -zp1 -s
// cdaudio.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02E56F-0x02FEDC
#include "R_FIX.H"
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
extern const char d_1a0730[];
struct Msf { unsigned char f, s, m, z; Msf() {} Msf(unsigned char mm, unsigned char ss, unsigned char ff) { z = 0; m = mm; s = ss; f = ff; } unsigned tot() { return (m * 0x3c + s) * 0x4b + f; } unsigned lba() { return (m * 0x3c + s) * 0x4b + f - 0x96; }
    Msf(unsigned v) { unsigned u = v; z = 0; m = u / 0x1194; u -= m * 0x1194; s = u / 0x4b; f = u - s * 0x4b; }
    Msf(Msf &o) { f = o.f; s = o.s; m = o.m; z = o.z; }
    Msf operator-(Msf &b) { return Msf(tot() - b.tot()); }
};
struct Hdr { unsigned char cmd, first, last; Msf t; };
struct Trk { unsigned char cmd, num; Msf t; unsigned char st; Trk(); };
struct Req {
    unsigned char len, z1, cmd; char pad[10]; unsigned char b0d;
    int i0e; unsigned short w12, w14; int i16;
};
int f_02e080(int p1);
struct Buf {
    char b[12];
    Buf(int n); ~Buf();
    Req *f_05fef0(); int f_05fee0();
    int f_05ff00(void *d, int n); int f_05ff30(void *d, int n);
};
extern "C" Buf *f_05fe80(Buf *, int);
struct CD {
    short dev; Msf a; Msf b; int st; int i0e; int open;
    Hdr *hdr; Trk *trk; Req *req; Buf bufA; Buf bufB; short err;
    void f_02e273(); void f_02e304(int n); void f_02e375(); void f_02e41a();
    short f_02e11a(); int f_02e199(); unsigned f_02e204();
    int f_02e56f(); CD(short p2); ~CD(); int f_02ed35();
    void f_02ee42(); void f_02ef53(Msf *p2); void f_02f12f(Msf *p2, Msf *p3); Msf f_02f406(short n, int mode);
};

//@ f_02e56f
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest über den CD-Treiber die Disk-Info (cmd = 10) sowie die Startzeiten aller Tracks (cmd =
 *   11) in das Array trk ein und überprüft, ob die eingelegte CD genau 13 Tracks (hdr->last == 13) besitzt, wie
 *   es für die *Schatten-über-Riva*-CD erforderlich ist.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des CD-Objekts und gibt 1 zurück, wenn das
 *   Inhaltsverzeichnis gültig gelesen wurde und 13 Tracks umfasst, andernfalls 0.
 * - Wichtige Variablen: Legt bei Bedarf die Strukturen hdr (Hdr) und trk (Array aus 14 Trk-Einträgen) an und
 *   befüllt sie über den DOS-Transferpuffer bufB.
 === Ende Beschreibung === */
int CD::f_02e56f()
{
    struct MsfInit {
        unsigned char f, s, m, z;
        MsfInit(unsigned char mm = 0, unsigned char ss = 0, unsigned char ff = 0) { z=0; m=mm; s=ss; f=ff; }
    };
    struct HdrInit {
        unsigned char cmd, first, last;
        MsfInit t;
        HdrInit() {}
    };
    unsigned short i;
    int ok = 1;
    Msf g(0x3c);
    f_02e375();
    if (hdr == 0) {
        hdr = (Hdr *)new (mark(d_1a0730, 0x187)) HdrInit;
    }
    hdr->cmd = 10;
    hdr->first = 0;
    hdr->last = 0;
    req->cmd = 3;
    req->w12 = 7;
    bufB.f_05ff00(hdr, 7);
    req->i0e = bufB.f_05fee0();
    f_02e304(0x1e);
    bufB.f_05ff30(hdr, 7);
    if (hdr->last != 13) {
        ok = 0;
    } else {
        if (trk == 0) {
            trk = new (mark(d_1a0730, 0x1b0)) Trk[14];
        }
        for (i = hdr->first - 1; i < hdr->last; i++) {
            trk[i].cmd = 0xb;
            trk[i].num = (char)i + 1;
            bufB.f_05ff00(&trk[i], 7);
            f_02e273();
            bufB.f_05ff30(&trk[i], 7);
            if (trk[i].st == 0xff) {
                hdr->last = (char)i;
            }
        }
        trk[hdr->last].cmd = 0xb;
        trk[hdr->last].num = 0xff;
        trk[hdr->last].t = hdr->t - g;
        trk[hdr->last].st = 0;
        req->i0e = 0;
        req->w12 = 0;
    }
    return ok;
}

//@ f_02ea8a
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Richtet das CD-Verwaltungsobjekt ein, legt die beiden Low-Memory-Puffer bufA (0x1a Bytes für
 *   den Request-Header) und bufB (0x0d Bytes für IOCTL-Daten) an, prüft über f_02e199 und f_02e204, ob MSCDEX
 *   mindestens in Version 2.10 läuft, und wählt das angegebene oder erste verfügbare CD-ROM-Laufwerk aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p sowie die gewünschte Laufwerksnummer p2 (-1
 *   für automatische Suche) und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Setzt im Fehlerfall das Feld p->err auf 0x3ba (kein CD-Laufwerk), 0x3bb (MSCDEX zu alt)
 *   oder 0x3bc (ungültiges Laufwerk).
 === Ende Beschreibung === */
CD *f_02ea8a(CD *p, short p2)
{
    struct MS {
        unsigned char f, s, m, z;
        MS *go(unsigned char mm = 0, unsigned char ss = 0, unsigned char ff = 0) {
            z = 0; m = mm; s = ss; f = ff; return this;
        }
    };
    p = (CD *)((char *)((MS *)((char *)p + 2))->go() - 2);
    p = (CD *)((char *)((MS *)((char *)p + 6))->go() - 6);
    p = (CD *)((char *)f_05fe80(&p->bufA, 0x1a) - 0x22);
    CD **t0 = &p;
    p = (CD *)((char *)f_05fe80(&p->bufB, 0xd) - 0x2e);
    CD **t1 = &p;
    p->err = 0;
    p->hdr = 0;
    p->trk = 0;
    p->req = p->bufA.f_05fef0();
    p->req->len = 0x1a;
    p->req->z1 = 0;
    p->req->b0d = 0;
    p->req->i0e = 0;
    p->req->w12 = 0;
    p->req->w14 = 0;
    p->req->i16 = 0;
    if (p->f_02e199() < 1) {
        p->err = 0x3ba;
    } else if (p->f_02e204() < 0x20a) {
        p->err = 0x3bb;
    } else if (p2 < 0) {
        p->dev = p->f_02e11a();
    } else {
        p->dev = p2;
        if (f_02e080(p->dev) == 0) {
            p->err = 0x3bc;
        }
    }
    if (p->err == 0) {
        p->f_02e41a();
    }
    return p;
}

//@ f_02ecc3
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die dynamisch angelegten Tabellen trk und hdr sowie die beiden DOS-Transferpuffer bufB
 *   und bufA wieder frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger p und die Destruktor-Flags z entgegen und gibt
 *   den Objektzeiger zurück.
 * - Wichtige Variablen: Räumt p->trk, p->hdr, p->bufB und p->bufA über operator delete und f_05fea0 ab.
 === Ende Beschreibung === */
CD *f_02ecc3(CD *p, int z)
{
    extern Buf *f_05fea0(Buf *, int);
    if (p->trk != 0) operator delete(p->trk);
    if (p->hdr != 0) operator delete(p->hdr);
    p = (CD *)((char *)f_05fea0(&p->bufB, 0) - 0x2e);
    p = (CD *)((char *)f_05fea0(&p->bufA, 0) - 0x22);
    return p;
}

//@ f_02ed35
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert den Laufwerksstatus über f_02e41a(): Ist keine CD eingelegt (open == 0), wird der
 *   Fehlercode 0x3bd gesetzt; andernfalls wird eine laufende Wiedergabe über f_02ee42() gestoppt und das
 *   Inhaltsverzeichnis der CD über f_02e56f() neu eingelesen.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des CD-Objekts und gibt den Erfolgsstatus von
 *   f_02e56f() zurück.
 * - Wichtige Variablen: Setzt a und b auf 00:00:00 zurück und aktualisiert err.
 === Ende Beschreibung === */
int CD::f_02ed35()
{
#if FIX_R003   /* R003: Uninitialisierten Rueckgabewert r bei offenem Laufwerk (open == 0) mit 0 vorbelegen */
    int r = 0;
#else
    int r;
#endif
    err = 0;
    a = Msf(0, 0, 0);
    b = Msf(0, 0, 0);
    f_02e41a();
    if (open == 0) {
        err = 0x3bd;
    } else {
        f_02ee42();
        r = f_02e56f();
    }
    return r;
}

//@ f_02ee42
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sendet so lange den Stop-Befehl (req->cmd = 0x85, Stop Audio) an das CD-ROM-Laufwerk, bis das
 *   Laufwerk meldet, dass keine Audiowiedergabe mehr aktiv ist (st != 1).
 * - Eingaben und Rückgabe: Die Methode nimmt den this-Zeiger des CD-Objekts entgegen und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Löscht die gespeicherten Start-/Endpositionen a und b und prüft in einer Schleife das
 *   Statusfeld st.
 === Ende Beschreibung === */
void CD::f_02ee42()
{
    err = 0;
    a = Msf(0, 0, 0);
    b = Msf(0, 0, 0);
    int s = st;
    f_02e41a();
    while (s == 1) {
        req->cmd = 0x85;
        f_02e273();
        s = st;
        f_02e41a();
    }
}

//@ f_02ef53
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die gewünschte Zielposition p2 innerhalb des gültigen Trackbereichs der CD liegt,
 *   stoppt eine laufende Wiedergabe und fährt den Lesekopf mit dem Treiberbefehl 0x83 (Seek) an die berechnete
 *   LBA-Sektoradresse (p2->lba()).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie den Zeiger p2 auf die Ziel-Zeitmarke (Msf)
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Setzt bei Bereichsüberschreitung err = 0x3be und schreibt die Sektoradresse in req->w14.
 === Ende Beschreibung === */
void CD::f_02ef53(Msf *p2)
{
    unsigned *d;
    err = 0;
    if (p2->tot() < trk[hdr->first - 1].t.tot() || p2->tot() > trk[hdr->last].t.tot()) {
        err = 0x3be;
    } else {
        f_02ee42();
        req->cmd = 0x83;
        req->i0e = 0;
        req->w12 = 0;
        d = (unsigned *)&req->w14;
        *d = p2->lba();
        f_02e273();
    }
}

//@ f_02f12f
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt den Audioabschnitt zwischen der Startposition p2 und der Endposition p3 mit dem
 *   MSCDEX-Befehl 0x84 (Play Audio) ab, speichert a = *p2 und b = *p3 für spätere Wiederholungsprüfungen und
 *   setzt err = 0x3bf, falls das Laufwerk nach dem Startbefehl nicht in den Abspielmodus wechselt.
 * - Eingaben und Rückgabe: Die Methode nimmt den this-Zeiger sowie die Startzeit p2 und Endzeit p3 entgegen und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Übergibt die Startadresse p2->lba() in req->i0e und die Sektoranzahl p3->tot() -
 *   p2->tot() in req->w12.
 === Ende Beschreibung === */
void CD::f_02f12f(Msf *p2, Msf *p3)
{
    unsigned *len;
    err = 0;
    if (open == 0) {
        err = 0x3bd;
    } else if (p2->tot() < trk[hdr->first - 1].t.tot() || p3->tot() > trk[hdr->last].t.tot()) {
        err = 0x3be;
    } else {
        f_02ee42();
        req->cmd = 0x84;
        req->i0e = p2->lba();
        len = (unsigned *)&req->w12;
        *len = p3->tot() - p2->tot();
        f_02e273();
        f_02e41a();
        if (st == 0) {
            err = 0x3bf;
        } else {
            a = *p2;
            b = *p3;
        }
    }
    req->i0e = 0;
    req->w12 = 0;
}

//@ f_02f406
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet die Wiedergabe des Musiktracks mit der Nummer n anhand der im TOC gespeicherten
 *   Trackgrenzen: Bei mode == 1 wird von Track n bis zum Ende der CD gespielt, andernfalls genau dieser einzelne
 *   Track (trk[n - 1].t bis trk[n].t), und die Spieldauer wird als Msf-Wert zurückgegeben.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, die Tracknummer n und den Abspielmodus mode und
 *   gibt die Länge des gestarteten Abschnitts als Msf-Struktur zurück.
 * - Wichtige Variablen: Prüft n gegen hdr->first und hdr->last (Fehler 0x3be bei ungültiger Tracknummer) und
 *   delegiert an f_02f12f.
 === Ende Beschreibung === */
Msf CD::f_02f406(short n, int mode)
{
    Msf r(0);
    f_02e41a();
    err = 0;
    if (open == 0) {
        err = 0x3bd;
    } else if (n < hdr->first || n > hdr->last) {
        err = 0x3be;
    } else if (mode == 1) {
        f_02f12f(&trk[n - 1].t, &trk[hdr->last].t);
        r = trk[hdr->last].t - trk[n - 1].t;
    } else {
        f_02f12f(&trk[n - 1].t, &trk[n].t);
        r = trk[n].t - trk[n - 1].t;
    }
    return r;
}
