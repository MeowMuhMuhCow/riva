/* === Beschreibung (Katalog) ===
 * Einheit vslider_neu (0x1407A0 - 0x140930)
 *
 * Überblick
 * Die Einheit vslider_neu enthält die Initialisierungsmethode VSlider::f_1407a0 für einen vertikalen
 * Schieberegler (VSlider), die die vier Teilbilder des Reglers (Hintergrundleiste, Schiebeknopf normal/gedrückt
 * und Zusatzgrafik) aus einer Bildressource lädt.
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 1407a0-140930 aus Quelle/cpp/VSLIDER.CPP; erster Entwurf, Einbau separat prüfen.
// vslider.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x1407A0-0x140930. Vier Bilder fuer einen vertikalen Schieberegler anlegen und beim Skript-Objekt anmelden.
extern const char d_1a946c[];
#define vslider_file d_1a946c
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
#include "RIVAIMG.H"     // 0x0FAC80

struct Reg { void f_050580(int p2, int idx, void *a, void *b);
             void f_04fef0(int p2, int r, int z, int idx, int z2, int n); };
extern Reg d_1c2be0;

struct VSlider {
    char p0[4];
    short w04;
    char p6[8];
    short w0e;
    short w10;
    RivaRasterImage *i12, *i16, *i1a, *i1e;
    void f_1407a0(int p2);
};

//@ f_1407a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt über den Ressourcenmanager d_1c2be0 (f_050580) die Abmessungen der Einzelbilder 0, 1
 *   und 3 der Grafikressource p2 ab, legt dafür vier RivaRasterImage-Objekte (this->i12, this->i16, this->i1a,
 *   this->i1e) in den passenden Größen an und entpackt die vier Teilbilder 0..3 über d_1c2be0.f_04fef0 in deren
 *   jeweilige Pixelpuffer (f_0fb0b0()).
 * - Eingaben: this (Zeiger auf die VSlider-Instanz), p2 (Ressourcen-ID der Schieberegler-Grafik).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - this->w04 (+0x04), this->w0e (+0x0E), this->w10 (+0x10): Ausgelesene Höhen- und Breitenwerte der
 *     Schieberegler-Elemente.
 *   - this->i12, this->i16, this->i1a, this->i1e (+0x12 bis +0x1E): Zeiger auf die vier
 *     RivaRasterImage-Teilbilder des vertikalen Schiebereglers.
 === Ende Beschreibung === */
void VSlider::f_1407a0(int p2)
{
    short la, lb;
    d_1c2be0.f_050580(p2, 0, &w0e, &w04);
    i12 = new (mark(vslider_file, 0xfd)) RivaRasterImage(w0e, w04);
    d_1c2be0.f_04fef0(p2, ((int)(((RivaRasterImage*)(i12))->f_0fb0b0())), 0, 0, 0, 0x140);
    d_1c2be0.f_050580(p2, 1, &la, &w10);
    i16 = new (mark(vslider_file, 0x10e)) RivaRasterImage(w0e, w10);
    i1a = new (mark(vslider_file, 0x10f)) RivaRasterImage(w0e, w10);
    d_1c2be0.f_04fef0(p2, ((int)(((RivaRasterImage*)(i16))->f_0fb0b0())), 0, 1, 0, 0x140);
    d_1c2be0.f_04fef0(p2, ((int)(((RivaRasterImage*)(i1a))->f_0fb0b0())), 0, 2, 0, 0x140);
    d_1c2be0.f_050580(p2, 3, &la, &lb);
    i1e = new (mark(vslider_file, 0x126)) RivaRasterImage(w0e, lb);
    d_1c2be0.f_04fef0(p2, ((int)(((RivaRasterImage*)(i1e))->f_0fb0b0())), 0, 3, 0, 0x140);
}
