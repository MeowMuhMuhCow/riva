/* === Beschreibung (Katalog) ===
 * Einheit loadseq_neu (0x0B0F90 - 0x0B1130)
 *
 * Überblick
 * Die Einheit loadseq_neu verwaltet das Laden und Freigeben einer 160 x 100 Pixel großen Ladesequenz-Grafik
 * (Seq) einschließlich eines temporären Grafikspeicher-Pools (d_1bf240).
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0b0f90-0b1130 aus Quelle/cpp/LOADSEQ.CPP; erster Entwurf, Einbau separat prüfen.
// loadseq.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x0B0F90-0x0B1130. Ladesequenz: Bild (160x100) in Puffer laden, Aufraeumen.
extern const char d_1a51d4[];
#define loadseq_file d_1a51d4
#include "RIVAMEM.H"



struct Gfx {
    int pad[6];
    Gfx(long a, long b, long c, int d, int e);           // 0x0BD910
    ~Gfx();                                              // 0x0BDA30
    int f_0bd900();
    void *f_0bdd50(long size, const char *file, int line);
    void f_0bdde0(void *p, const char *file, int line);
};
struct Img { int x; int w; int h; };
void * __stdcall f_14bb40(int a, int b, const char *name);   // 0x14BB40
void __stdcall f_14b7b0(void *p);   // 0x14B7B0
#define LOAD(n) f_14bb40(-1, 0x200, n)
void __stdcall f_14a940(int, void *, int, int, int, int, Img *);   // 0x14A940
extern char *d_1bed4c;
extern Gfx *d_1bf240;
extern Gfx d_1c11b8;
struct Seq {
    int a;       // +0
    Img *pic;    // +4
    void *buf;   // +8
    int ok;      // +0xc
    short s;     // +0x10
    void f_0b0fc0(const char *name);
    void f_0b1090();
};
//@ f_0b0f90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reserviert beim Initialisieren einen 24 Bytes großen Platzhalterblock d_1bed4c auf dem
 *   Heap.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bed4c: Globaler Zeiger auf den 24-Byte-Puffer.
 === Ende Beschreibung === */
void f_0b0f90()
{
    d_1bed4c = new (mark(loadseq_file, 32)) char[24];
}
//@ f_0b0fc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den Platzhalter d_1bed4c frei, legt einen temporären Gfx-Speicherpool d_1bf240 an,
 *   reserviert einen 0x3e80 (16000) Bytes großen Bildpuffer this->buf aus dem Grafikpool d_1c11b8, lädt die
 *   benannte Bilddatei name über f_14bb40 und entpackt sie - sofern ihre Abmessungen genau 160 x 100 Pixel
 *   betragen - über f_14a940 in den Puffer this->buf.
 * - Eingaben: this (Zeiger auf die Seq-Instanz), name (Dateiname der zu ladenden Sequenzgrafik).
 * - Rückgabewert: Keiner (void). Setzt bei Erfolg this->ok = 1, sonst 0.
 * - Wichtige Variablen:
 *   - this->pic (+0x04): Zeiger auf die geladene Bildressource (Img).
 *   - this->buf (+0x08): Zeiger auf den 16000 Bytes großen Rohpixelpuffer (160 * 100).
 *   - this->ok (+0x0C): Erfolgsflag (1 = Bild erfolgreich geladen und entpackt).
 *   - d_1bf240: Temporärer Gfx-Speicherpool.
 === Ende Beschreibung === */
void Seq::f_0b0fc0(const char *name)
{
    ok = 0;
    delete d_1bed4c;
    d_1bf240 = new (mark(loadseq_file, 41)) Gfx(0x40000, 0x40000, 0x4b000, 10, 0);
    if (d_1bf240->f_0bd900()) {
        buf = d_1c11b8.f_0bdd50(0x3e80, loadseq_file, 45);
        if (buf) {
            pic = (Img *)LOAD(name);
            if (pic) {
                if (pic->w == 160 && pic->h == 100) {
                    int w = pic->w, h = pic->h;
                    f_14a940(0, buf, h, w, 0, 0, pic);
                    ok = 1;
                }
            }
        }
        s = 0;
        a = 0;
    }
}
//@ f_0b1090
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Räumt nach dem Abspielen der Ladesequenz die Bildressource this->pic (f_14b7b0) und den
 *   Pixelpuffer this->buf (f_0bdde0) wieder auf, gibt den temporären Gfx-Pool d_1bf240 frei und legt den
 *   24-Byte-Platzhalter d_1bed4c erneut an.
 * - Eingaben: this (Zeiger auf die Seq-Instanz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - this->pic (+0x04), this->buf (+0x08), this->ok (+0x0C): Werden beim Aufräumen auf 0 zurückgesetzt.
 *   - d_1bf240, d_1bed4c: Globale Speicherverwaltungszeiger.
 === Ende Beschreibung === */
void Seq::f_0b1090()
{
    if (d_1bf240->f_0bd900()) {
        ok = 0;
        if (pic) { f_14b7b0(pic); pic = 0; }
        if (buf) { d_1c11b8.f_0bdde0(buf, loadseq_file, 81); buf = 0; }
    }
    delete d_1bf240;
    d_1bf240 = 0;
    d_1bed4c = new (mark(loadseq_file, 87)) char[24];
}
