/* D23: Datenansicht des 60-Byte-Textkontexts 125400/1254a0.
 * Fuer Quellen mit ausdruecklichem Konstruktor-/Destruktoraufruf.
 * Tabellenlayout identisch mit RivaTextContext; addresses haelt die noch
 * vorhandene ganzzahlige Adressarithmetik ausdruecklich als Alias fest. */
#ifndef RIVACDAT_H
#define RIVACDAT_H
#include "RIVACTX.H"
#pragma pack(push,1)
struct RivaTextAddresses {
    int objects, second_objects, items, numbers, short_numbers, wide_numbers;
    int second_counts, item_counts, text_buffer, text_cursor, catalog;
    int resource_id, lookup, previous;
};
struct RivaTextContextData {
    union { char *storage; int storage_address; };
    union { RivaTextTables tables; RivaTextAddresses addresses; char *slots[14]; };
};
#pragma pack(pop)
typedef char riva_text_data_layout[(sizeof(RivaTextContextData)==sizeof(RivaTextContext) && sizeof(RivaTextContextData)==60 && offsetof(RivaTextContextData,tables)==offsetof(RivaTextContext,tables))?1:-1];
#endif
