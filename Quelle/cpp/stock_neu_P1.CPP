/* === Beschreibung (Katalog) ===
 * Einheit stock_neu (0x11C180 - 0x11C760)
 *
 * Überblick
 * Die Einheit stock_neu implementiert die doppelt verkettete Bestandsliste Stock (stock.cpp), mit der
 * Gegenstandsbestände (jeweils 31 Bytes pro Item: 16-Bit-Gegenstands-ID, 16-Bit-Stückzahl und 27 Bytes
 * Zusatzinfo) für Händlerlager, Truhen oder Beutel im Speicher verwaltet, aus Arrays aufgebaut und wieder in
 * Arrays exportiert werden.
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// I13 30.10.: = Quelle/cpp/STOCK.CPP (Bauquelle, Fable REST9: Einheit stock_neu umfasst das ganze Modul)
// stock.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Paket 4.23
// Code 0x11C180-0x11C760, wpp386 -4r -oneatx -zp1 -s (Watcom C/C++ 10.6). Namen f_<Adresse> bis Phase 6.
// Bestandsliste: verkettete Knoten mit je einem Eintrag (Item, 31 Bytes). Zahlen bei mark() = Attics Quellzeilen.
#include "R_FIX.H"
#include <string.h>
extern const char stock_file[] = "p:\\riva\\source\\cpp\\stock.cpp";   // 0x1A7DD8
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
struct Msg { void f_0bf730(long code); };
extern Msg d_1c2c64;                                     // Meldungen
struct Info { char b[27]; };
struct Item {
    short id;
    short amount;
    Info  info;
    Item() : id(0), amount(0) { memset(&info, 0, sizeof info); }
    Item(short i, short a, Info inf) : id(i), amount(a) { memcpy(&info, &inf, sizeof info); }
};
struct Node { Item *item; Node *prev; Node *next; };
struct Stock {
    short count;                                         // +0x00
    Node *head;                                          // +0x02
    Node *tail;                                          // +0x06
    short pad;                                           // +0x0A
    int   locked;                                        // +0x0C
    Node *at(short i) { Node *n = head; for (short k = 0; k != i; k++) n = n->next; return n; }
    void  f_11c180(Item *tab);
    void  f_11c2e0(Item *out);
    short f_11c320();
    Item *f_11c330(short i);
    int   f_11c350(Item *src);
    int   f_11c460(short pos, Item *src);
    void  f_11c580(short i);
    short f_11c5f0(short i);
    short f_11c620(short i);
    char *f_11c650(short i);
    void  f_11c680(short i, short v);
    void  f_11c6b0(short i, short v);
    void  f_11c6e0(short i, short v);
    void  f_11c710(short i, short v);
    Node *f_11c740(short i);
};

void Stock::f_11c180(Item *tab)
{
    Node *prev, *n;
    if (tab[count].id == 0) return;
    prev = 0;
    n = new (mark(stock_file, 111)) Node;
    head = n;
    n->prev = 0;
    while (tab[count].id > 0) {
        n->item = new (mark(stock_file, 131)) Item;
        n->item->id = tab[count].id;
        n->item->amount = tab[count].amount;
        n->item->info = tab[count].info;
        if (prev) { prev->next = n; n->prev = prev; }
        prev = n;
        n = new (mark(stock_file, 156)) Node;
        count++;
    }
    delete n;
    prev->next = 0;
    tail = prev;
}
void Stock::f_11c2e0(Item *out)
{
    Node *n = head;
    do {
        out->id = n->item->id;
        out->amount = n->item->amount;
        out->info = n->item->info;
        n = n->next;
        out++;
    } while (n);
}
short Stock::f_11c320() { return count; }
Item *Stock::f_11c330(short i) { return at(i)->item; }
int Stock::f_11c350(Item *src)
{
    if (locked == 1) { d_1c2c64.f_0bf730(0x21040011L); return 0; }
    Node *n = new (mark(stock_file, 243)) Node;
    Item *it = new (mark(stock_file, 244)) Item(src->id, src->amount, src->info);
    delete src;
    if (head == 0) {
        head = tail = n;
        n->item = it;
        n->prev = n->next = 0;
    } else {
        n->item = it;
        tail->next = n;
        n->prev = tail;
        n->next = 0;
        tail = n;
    }
    count++;
    return 1;
}
int Stock::f_11c460(short pos, Item *src)
{
    if (locked == 1) { d_1c2c64.f_0bf730(0x21040011L); return 0; }
    Item *it = new (mark(stock_file, 302)) Item(src->id, src->amount, src->info);
    delete src;
    if (pos == count) f_11c350(it);
    else {
        Node *a = at(pos);
        Node *n = new (mark(stock_file, 324)) Node;
        n->item = it;
        if (a->prev) a->prev->next = n;
        n->prev = a->prev;
        n->next = a;
        a->prev = n;
        if (pos == 0) head = n;
        count++;
    }
    return 1;
}
void Stock::f_11c580(short i)
{
    Node *n = at(i);
#if FIX_R009   /* R009: Beim Entfernen des einzigen Listenelements (head == 0) Nullzeiger-Dereferenzierung vermeiden und tail aktualisieren */
    if (i == 0) { head = n->next; if (head) head->prev = n->prev; else tail = 0; }
#else
    if (i == 0) { head = n->next; head->prev = n->prev; }
#endif
    else {
        if (i == count - 1) { tail = n->prev; n->prev->next = n->next; }
        else { n->next->prev = n->prev; n->prev->next = n->next; }
    }
    delete n->item;
    delete n;
    count--;
}
short Stock::f_11c5f0(short i) { return at(i)->item->id; }
short Stock::f_11c620(short i) { return at(i)->item->amount; }
char *Stock::f_11c650(short i) { return at(i)->item->info.b; }
void  Stock::f_11c680(short i, short v) { at(i)->item->id = v; }
void  Stock::f_11c6b0(short i, short v) { at(i)->item->amount = v; }
void  Stock::f_11c6e0(short i, short v) { at(i)->item->id += v; }
void  Stock::f_11c710(short i, short v) { at(i)->item->id -= v; }
Node *Stock::f_11c740(short i)
{
    Node *n = head;
    for (short k = 0; k != i; k++) n = n->next;
    return n;
}
