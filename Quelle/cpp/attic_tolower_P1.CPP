// OPT -4r -oneatx -zp1 -s
// Astra630: Pilot, Quelle aus bereits rekonstruiertem F1453B0.CPP; keine neue BRender-Einheit.
// fz_1453b0.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x1453B0-0x145547. Umlaut-faehige tolower/toupper fuer Zeichen und Strings (DOS-Codepage).
extern const char d_1a97c4[];
#define tolower_file d_1a97c4   // 0x1A97C4
extern const char d_1b8950[], d_1b895f[];   // "string != NULL" (D20081, fremd)
extern signed char d_1bbfdc[];
extern "C" int tolower(int c);   // 0x15EA70
extern "C" int toupper(int c);   // 0x15EA62
void f_1664d0(const char *a, const char *file, int line);

//@ f_1453b0
char f_1453b0(char c)
{
    if ((d_1bbfdc[(unsigned char)(c + 1)] & 0xc0) && (d_1bbfdc[(unsigned char)(c + 1)] & 0x40))
        return tolower((unsigned char)c);
    if (c == (char)0x99) return (char)0x94;
    if (c == (char)0x8e) return (char)0x84;
    if (c == (char)0x9a) c = (char)0x81;
    return c;
}

//@ f_145400
char f_145400(char c)
{
    if ((d_1bbfdc[(unsigned char)(c + 1)] & 0xc0) && (d_1bbfdc[(unsigned char)(c + 1)] & 0x80))
        return toupper((unsigned char)c);
    if (c == (char)0x94) return (char)0x99;
    if (c == (char)0x84) return (char)0x8e;
    if (c == (char)0x81) c = (char)0x9a;
    return c;
}

//@ f_145450
char *f_145450(char *s)
{
    char *p = s; char *r = s;
    if (!s) f_1664d0(d_1b8950, tolower_file, 0x5d);
    for (;;) {
        char t = *p; unsigned u = (unsigned char)t; if (u == 0) break; char c = t;
        if (((int)d_1bbfdc[(unsigned char)(c + 1)] & 0xc0u) && (d_1bbfdc[(unsigned char)(c + 1)] & 0x40))
            c = tolower(u);
        else if (c == (char)0x99) c = (char)0x94;
        else if (c == (char)0x8e) c = (char)0x84;
        else if (c == (char)0x9a) c = (char)0x81;
        *p++ = c;
    }
    return r;
}

//@ f_1454d0
char *f_1454d0(char *s)
{
    char *p = s; char *r = s;
    if (!s) f_1664d0(d_1b895f, tolower_file, 0x73);
    for (;;) {
        char t = *p; unsigned u = (unsigned char)t; if (u == 0) break; char c = t;
        if (((int)d_1bbfdc[(unsigned char)(c + 1)] & 0xc0u) && (d_1bbfdc[(unsigned char)(c + 1)] & 0x80))
            c = toupper(u);
        else if (c == (char)0x94) c = (char)0x99;
        else if (c == (char)0x84) c = (char)0x8e;
        else if (c == (char)0x81) c = (char)0x9a;
        *p++ = c;
    }
    return r;
}
