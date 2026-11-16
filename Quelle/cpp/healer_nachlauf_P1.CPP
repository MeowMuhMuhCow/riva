// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 09b9e0-09ba80 aus Quelle/cpp/HEALER.CPP; erster Entwurf, Einbau separat pr�fen.
// healer.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle
// Code 0x09B9E0-0x09BA80. Heiler-Ort: beim Betreten Anzeige-Objekt neu anlegen.
// Daten (Dateiname 0x1A3514) liegen noch im Sammelstück D10086 (dort kein zulässiger Schnitt, Fixup-Reihenfolge).
extern const char healer_file[];                         // 0x1A3514
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
struct Shop {                                            // 0x42 Bytes, Konstruktor 0x0DA910, Destruktor 0x0DA990
    char b[0x42];
    Shop(long a, long b_, long c, long d, short e, short f);
    ~Shop();
};
extern Shop *d_1bfdb8;
extern signed char d_1bed64;
extern short d_1bb244;
struct Loc {
    char pad[0x28];
    void f_109430();
};
struct Healer : Loc {
    short pic;                                           // +0x28
    char pad2[0x5c - 0x2a];
    short typ;                                           // +0x5C
    void f_09b9e0();
};
//@ f_09b9e0
void Healer::f_09b9e0()
{
    Loc::f_109430();
    if ((d_1bed64 == 1) != 0) {
        pic = (typ != 0x12 ? 1 : 0) + 0x1c;
        delete d_1bfdb8;
        d_1bfdb8 = new (mark(healer_file, 67)) Shop(0x280000, 0x280001, 0x280002, 0x280003, d_1bb244, pic);
    }
}
