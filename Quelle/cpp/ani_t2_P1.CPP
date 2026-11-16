/* === Beschreibung (Katalog) ===
 * Einheit ani_t2
 *
 * Diese Einheit bildet den zweiten Teil der Ortsanimationen (ani.cpp, Teil 2, Adressbereich 0x01d160-0x01e0c0).
 * Sie enthält die große Lade- und Entpackfunktion f_01d160 (das direkte Gegenstück zu seg027.c:load_ani in
 * *Schicksalsklinge*), vier kleine Abfrage- und Setzmethoden der Klasse Ani sowie die globale Einstiegsfunktion
 * f_01dfd0, mit der Gebäude- und Ladenbildschirme ihre jeweilige Ortsanimation starten.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 4/6 gleich (suche.py 26.10.2026, Basis ani_t2_P1.CPP)
// ani.cpp (Schatten ueber Riva, Attic 1996) - Pass 1 Teil 2, Code 0x01D160-0x01E0C0
#include <string.h>
#pragma pack(1)
extern const char d_1a04b8[];
extern const char d_1b6444[];
void *f_014540(int size, const char *file, int line);
int f_014a60();
int f_148180(int v);
int __cdecl f_099ef0(void *p, int a, int b);

extern RivaFileManager d_1c2098;
struct Gfx {
  char d[9];
  Gfx(short a, unsigned char b, void *c);
};
struct St {
  char d[616];
  St();
  void f_147ef0(void *dst, void *src, int n);
};
struct Slot { unsigned char a, b; short c; };
struct Frame { Slot v[10]; };
struct Entry {
  char h0[4]; unsigned char b4; short s5; unsigned char b7, b8; short s9;
  unsigned char fl[10]; unsigned char b15; void *tx[25]; short cnt[10]; Frame *fr;
};
struct Hd { int a; int b; short w; unsigned char h; unsigned char cnt; int off[1]; };
struct Rc { char tag[4]; short s4; char b6; char b7; short s8; unsigned char b10; unsigned char b11; int off[1]; };
struct Ani {
  char h0[8]; short s08; short s0a; short s0c; unsigned char b0e; signed char n; Entry *ents; char *p14;
  unsigned char b18; unsigned char h19; unsigned char *p1a; char b1e; signed char h1f; signed char sc20[10]; char h2a[11];
  short s35, s37, s39, s3b, s3d, s3f; long l41; long l45; void *l49; short s4d;
  short w4f[10], w63[10], w77[10], w8b[10]; Gfx *p9f[10]; long lc7; long lcb;
  void f_01cc30() {
    s39 = 0x10; s3b = 2; s3f = 0; s4d = 0; s3d = 0;
    lc7 = 1; l41 = -1;
    for (short k = 0; k < 10; k++) p9f[k] = 0;
  }
  Ani() {
    s35 = 2; s37 = 0xa0; n = 0; l49 = 0;
    f_01cc30();
  }
  void f_01c120(short mode);
  void f_01cc90();
  void f_01cf10();
  int f_01cf90(int sz);
  void f_01d160(int p2);
  void *f_01df90();
  void f_01dfa0(short v);
  short f_01dfb0();
  long f_01dfc0();
};
extern Ani *d_1bc760;
#define H ((Hd *)l49)

#define SETL49(ln, r) { void *tp = f_014540(r, d_1a04b8, ln); lc7 = 1; l49 = tp; }

//@ f_01d160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion lädt die Ortsanimation mit der Archiv-ID id in das Ani-Objekt (Ablauf und
 *   Kopfoffsets fast zeilengleich mit seg027.c:load_ani aus *Schicksalsklinge*): ist dieselbe Animation bereits
 *   geladen (id == l41), kehrt sie sofort zurück; andernfalls gibt sie eine vorherige Animation über f_01cf10
 *   frei, prüft am Dateianfang die 3-Byte-Kennung d_1b6444 zur Unterscheidung zwischen dem alten
 *   *Schicksalsklinge*-Format (1 Zustand, l45 = 1) und dem neuen Riva-Format (Version 1, bis zu 10 Zustände h1f
 *   mit eigenen Flags und Wechselketten je Bereich) und entscheidet anhand des freien Speichers (f_014a60() >= 2
 *   * size), ob die gesamte entpackte Animation in einen Puffer l49 geladen (lc7 = 1) oder der Speichersparweg
 *   (lc7 = 0, nur Hauptbild und Palette im Speicher) gewählt wird. Im Normalweg entpackt sie PP20-komprimierte
 *   Haupt- und Bereichsbilder (b18 != 0) an Ort und Stelle unter Nachschieben der nachfolgenden Daten, legt für
 *   jeden Bereich das Grafikobjekt p9f[k] an und begrenzt alle RGB-Palettenwerte auf 6 Bit (& 0x3f für den
 *   VGA-DAC).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und die Archiv-Eintragsnummer id (int) und
 *   hat keinen Rückgabewert.
 * - Wichtige Variablen: Gesetzt werden l41 (+0x41, geladene ANI-ID), l45 (+0x45, altes Format), lc7 (+0xc7,
 *   Vollpuffer vs. Sparweg), l49 (+0x49, Datenpuffer), p14 (+0x14, Hauptbild), p1a (+0x1a, Palette), ents
 *   (+0x10, Bereichstabelle) und p9f[0..9] (+0x9f, Bereichs-Bildobjekte).
 === Ende Beschreibung === */
void Ani::f_01d160(int id)
{
    short k=0; // Vorinitialisierung haelt die Register- und Stapelzuteilung der Schleifenzaehler wie im Original
    short count;
    void *buffer;
    char *tail;
    int size;
    short frames;
    short i;
    unsigned char version;
    int unpacked;
    Entry *e;
    Rc *r;
    int packed;
    short j;
    int adjustment;
    char *footer;
    char *data;
    Slot *slots;
    char *end;
    int tailbytes;
    void *copy;
    int off;
    unsigned char *palette;
    Hd *header;
    int framebytes;
    int remaining;
    int rawsize;
    char signature[4];
    s35=2; s3d=0;
    if(id==l41) return;
    if(l49) f_01cf10();
    s3d=0; l41=id;
    d_1c2098.f_1448b0(id,0x200);
    remaining=146; // Vorbelegung sichert den Stapelplatz von remaining vor dem Methodenaufruf
    remaining=d_1c2098.f_144a00();
    lcb=0;
    signature[3]=0;
    d_1c2098.f_144920(signature,3);
    if(strcmp(signature,d_1b6444)) {
        l45=1; h1f=1; h2a[1]=1;
        d_1c2098.f_144ab0(lcb,0);
        d_1c2098.f_144920(&rawsize,4);
        d_1c2098.f_144ab0(lcb,0);
        size=f_01cf90(rawsize);
        if(f_014a60()>=2*size) SETL49(0x3e6,size) else lc7=0;
        d_1c2098.f_144ab0(lcb,0);
        struct SourceLine { static int get(){ return 0x3fa; } };
        for(k=0;k<n;k++) {
            signed char c=sc20[k]; if(!c) c=1;
            ents[k].fr=(Frame*)f_014540((c*10)*sizeof(Slot),d_1a04b8,SourceLine::get());
        }
        f_01cc90();
    } else {
        l45=0;
        d_1c2098.f_144920(&version,1);
        if(version==1) {
            d_1c2098.f_144920(&h1f,1);
            d_1c2098.f_144920(&n,1);
            short cn=n; if(!cn) cn=1;
            ents=(Entry*)f_014540(cn*sizeof(Entry),d_1a04b8,0x413);
            signed char length;
            lcb+=6;
            d_1c2098.f_144920(&length,1);
            d_1c2098.f_144920(h2a+1,length);
            remaining-=6; remaining-=length+1; lcb+=length+1;
            for(i=0;i<n;i++) {
                d_1c2098.f_144920(&sc20[i],1); lcb++; remaining--;
                signed char c=sc20[i]; if(!c) c=1;
                ents[i].fr=(Frame*)f_014540((c*10)*sizeof(Slot),d_1a04b8,0x42a);
                for(j=0;j<10;j++) ents[i].cnt[j]=sc20[i];
            }
            f_01cc90();
            for(k=0;k<h1f;k++)
                for(i=0;i<n;i++) {
                    d_1c2098.f_144920(&ents[i].fl[k],1); lcb++; remaining--;
                    d_1c2098.f_144920(&ents[i].cnt[k],2); lcb+=2; remaining-=2;
                    for(j=0;j<ents[i].cnt[k];j++) {
                        d_1c2098.f_144920(&ents[i].fr[j].v[k],4); lcb+=4; remaining-=4;
                    }
                }
        }
        d_1c2098.f_144920(&rawsize,4);
        d_1c2098.f_144ab0(-4,1);
        size=f_01cf90(rawsize);
        if(f_014a60()>=2*size) SETL49(0x44e,size) else lc7=0;
        d_1c2098.f_144ab0(lcb,0);
    }
    if(!lc7) {
        header=(Hd*)f_014540(rawsize,d_1a04b8,0x468);
        d_1c2098.f_144920(header,rawsize);
        d_1c2098.f_144ab0(header->b+6+lcb-2,0);
        d_1c2098.f_144920(&h19,1);
        d_1c2098.f_144920(&b18,1);
        p1a=(unsigned char*)f_014540(h19*3,d_1a04b8,0x470);
        d_1c2098.f_144920(p1a,h19*3);
        s08=header->w; b0e=header->h; n=header->cnt;
        size=s08*b0e;
        l49=f_014540(size,d_1a04b8,0x47b); p14=(char*)l49;
        int offset=header->a;
        int chunk;
        if(n) {
            int o=header->off[0];
            r=(Rc*)((char*)header+o);
            rawsize=r->off[0];
            chunk=rawsize-offset;
        } else chunk=size;
        d_1c2098.f_144ab0(offset+lcb,0);
        d_1c2098.f_144920(l49,chunk);
        if(b18) {
            St unpacker;
            packed=*(int*)p14;
            buffer=f_014540(chunk,d_1a04b8,0x494);
            memcpy(buffer,p14,chunk);
            unpacker.f_147ef0(p14,buffer,packed);
            operator delete(buffer);
        }
        for(k=0;k<n;k++) {
            e=&ents[k];
            off=header->off[k];
            r=(Rc*)((char*)header+off);
            strncpy(e->h0,r->tag,4);
            e->s5=r->s4; e->b7=r->b6; e->b8=r->b7; e->s9=r->s8;
            e->fl[0]=r->b10; e->b15=r->b11;
            frames=e->b15;
            count=*(short*)((char*)r+0xc+frames*4);
            e->cnt[0]=count;
            slots=(Slot*)((char*)r+0xe+frames*4);
            for(i=0;i<count;i++) {
                e->fr[i].v[0].a=slots[i].a;
                e->fr[i].v[0].b=slots[i].b;
                e->fr[i].v[0].c=slots[i].c;
            }
        }
        b1e=0;
        for(j=0;j<n;j++) if(ents[j].fl[0]&2) { b1e=1; break; }
        palette=p1a;
        for(k=0;k<h19;k++) {
            palette[k*3]&=0x3f; palette[k*3+1]&=0x3f; palette[k*3+2]&=0x3f;
        }
        operator delete(header);
        d_1c2098.f_1449a0();
        return;
    }
    int delta;
    d_1c2098.f_144920(l49,remaining-lcb);
    d_1c2098.f_1449a0();
    data=(char*)l49;
    p14=data+H->a;
    p1a=(unsigned char*)data+6+H->b;
    s0a=*(short*)(p1a-6); s0c=*(short*)(p1a-4);
    b18=p1a[-1]; h19=p1a[-2];
    end=(char*)p1a+h19*3;
    s08=H->w; b0e=H->h; n=H->cnt;
    if(b18) {
        St unpacker;
        packed=*(int*)p14;
        footer=p14;
        footer+=packed-4;
        unpacked=*(int*)footer;
        unpacked=f_148180(unpacked)>>8;
        buffer=f_014540(unpacked,d_1a04b8,0x4ec);
        unpacker.f_147ef0(buffer,p14,packed);
        adjustment=unpacked-packed;
        tail=p14;
        tail+=packed;
        tailbytes=end-tail;
        copy=f_014540(tailbytes,d_1a04b8,0x4f4);
        memcpy(copy,tail,tailbytes);
        memcpy(p14,buffer,unpacked);
        operator delete(buffer);
        tail+=adjustment;
        memcpy(tail,copy,tailbytes);
        operator delete(copy);
        p1a+=adjustment; end+=adjustment;
    }
    for(k=0;k<n;k++) {
        e=&ents[k];
        off=H->off[k];
        r=(Rc*)((char*)l49+off);
        strncpy(e->h0,r->tag,4);
        e->s5=r->s4; e->b7=r->b6; e->b8=r->b7; e->s9=r->s8;
        e->fl[0]=r->b10; e->b15=r->b11;
        frames=e->b15; frames=(frames&0)?(short)0:frames; // Haelt frames ueber die Entpack-Verzweigung im vorgesehenen Register/Slot
        if(b18) {
            St unpacker;
            rawsize=r->off[0]; rawsize+=adjustment;
            footer=(char*)l49+rawsize;
            packed=*(int*)footer;
            footer+=packed-4;
            framebytes=*(int*)footer;
            framebytes=f_148180(framebytes)>>8;
            buffer=f_014540(framebytes,d_1a04b8,0x51f);
            unpacker.f_147ef0(buffer,(char*)l49+rawsize,packed);
            delta=framebytes-packed;
            adjustment+=delta;
            tail=(char*)l49;
            tail+=rawsize; tail+=packed;
            tailbytes=end-tail;
            copy=f_014540(tailbytes,d_1a04b8,0x529);
            memcpy(copy,tail,tailbytes);
            memcpy((char*)l49+rawsize,buffer,framebytes);
            operator delete(buffer);
            tail+=delta;
            memcpy(tail,copy,tailbytes);
            operator delete(copy);
            p1a+=delta; end+=delta; end=((int)end&0)?(char*)0:end; // Erzwingt das Zurueckschreiben von end auf den Stapelplatz nach der Verschiebung
            framebytes=e->b8*e->s9;
            for(i=0;i<frames;i++) e->tx[i]=(char*)l49+rawsize+i*framebytes;
        } else {
            for(i=0;i<frames;i++) {
                rawsize=r->off[i];
                e->tx[i]=(char*)l49+rawsize;
            }
        }
        count=*(short*)((char*)r+0xc+frames*4);
        e->cnt[0]=count;
        slots=(Slot*)((char*)r+0xe+frames*4); count=(count&0)?(short)0:count; // Haelt count fuer die Slot-Kopierschleife im vorgesehenen Register/Slot
        for(i=0;i<count;i++) {
            e->fr[i].v[0].a=slots[i].a;
            e->fr[i].v[0].b=slots[i].b;
            e->fr[i].v[0].c=slots[i].c;
        }
        p9f[k]=new(mark(d_1a04b8,0x54f)) Gfx(e->s9,e->b8,0);
    }
    b1e=0;
    for(j=0;j<n;j++) if(ents[j].fl[0]&2) { b1e=1; break; }
    palette=p1a;
    for(k=0;k<h19;k++) {
        palette[k*3]&=0x3f; palette[k*3+1]&=0x3f; palette[k*3+2]&=0x3f;
    }
}

//@ f_01df90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt den Zeiger p1a auf die im Speicher liegende RGB-Farbtabelle (3 Bytes je
 *   Farbe) der aktuell geladenen Ortsanimation zurück (entspricht g_ani_palette in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und liefert den Palettenzeiger this->p1a
 *   (void *).
 * - Wichtige Variablen: Gelesen wird das Zeigerfeld p1a (+0x1a).
 === Ende Beschreibung === */
void *Ani::f_01df90()
{
    return p1a;
}

//@ f_01dfa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schreibt den übergebenen Wert v in das Feld s35, das beim Zeichnen des Hauptbilds
 *   und der Bereichsbilder als Zeichenmodus an Gfx::f_0fae30 übergeben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) sowie den neuen Zeichenmodus v (short) und
 *   hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird das Feld s35 (+0x35, Standardwert 2).
 === Ende Beschreibung === */
void Ani::f_01dfa0(short v)
{
    s35 = v;
}

//@ f_01dfb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liefert den Wert des Laufschalters s3d zurück (1 = Animation läuft aktiv, 0 =
 *   Animation ist angehalten oder noch nicht gestartet; entspricht g_ani_enabled in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und gibt this->s3d (short) zurück.
 * - Wichtige Variablen: Gelesen wird das Feld s3d (+0x3d).
 === Ende Beschreibung === */
short Ani::f_01dfb0()
{
    return s3d;
}

//@ f_01dfc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt die Archiv-ID l41 der derzeit im Ani-Objekt geladenen Ortsanimation zurück
 *   (-1 bedeutet, dass aktuell keine Animation geladen ist; entspricht g_current_ani in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und liefert this->l41 (long).
 * - Wichtige Variablen: Gelesen wird das Feld l41 (+0x41).
 === Ende Beschreibung === */
long Ani::f_01dfc0()
{
    return l41;
}

//@ f_01dfd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion wird in der Ortsschleife (location) und nach dem Bildaufbau in Läden (shop) mit
 *   der ANI-Nummer des Ortes (Offset +0x22 im Ortssatz) aufgerufen: existiert das globale Animationsobjekt
 *   d_1bc760 noch nicht, legt sie es neu an und initialisiert es; läuft derzeit keine Animation (f_01dfb0() ==
 *   0), lädt sie die Animation p1 (sofern l41 == -1), setzt deren 160 Palettenfarben über f_099ef0 und startet
 *   das Abspielen im Modus 6 (Starten ohne erneutes Hauptbild- oder Paletteneinblenden).
 * - Eingaben und Rückgabe: Die Funktion erhält die ANI-Archivnummer p1 (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Verwaltet wird der globale Zeiger d_1bc760 (Ani *). Hinweis (Originalfehler): Die
 *   Funktion lädt p1 nur dann über f_01d160(p1), wenn d_1bc760->f_01dfc0() == -1 gilt (gar keine Animation im
 *   Speicher). Wurde eine vorherige Animation lediglich über f_01cef0 angehalten (s3d == 0), ohne sie über
 *   f_01cf10 freizugeben (l41 bleibt auf der alten Nummer != -1), wird die neue Animation p1 nicht geladen,
 *   sondern fälschlich die alte Animation wieder gestartet.
 === Ende Beschreibung === */
void f_01dfd0(int p1)
{
    if (d_1bc760 == 0) {
        d_1bc760 = new (mark(d_1a04b8, 0x5bb)) Ani;
    }
    if (d_1bc760->f_01dfb0() == 0) {
        if (d_1bc760->f_01dfc0() == -1) d_1bc760->f_01d160(p1);
        f_099ef0(d_1bc760->f_01df90(), 0, 0xa0);
        d_1bc760->f_01c120(6);
    }
}
