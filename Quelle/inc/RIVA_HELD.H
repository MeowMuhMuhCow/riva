/* RIVA_HELD.H - Heldenstruktur fuer Riva (Watcom 10.6), uebernommen aus DSA 2 Sternenschweif (Q 004 Quelle/inc/s_struct.h).
 * Erzeugt 25.10.2026 (Instanz 11). Held = 0x5ef Bytes wie in Sternenschweif (Import ueber die Spiele).
 * Anpassungen: Borland-int -> short, Bitfelder "unsigned short b:1" -> "unsigned char b:1" (Watcom packt sonst 2-Byte-weise),
 * C++-Inline-Elemente entfernt. Offsets/Namen in den Kommentaren gelten unveraendert. Feldtabelle: Analyse/Pass2/held_felder.tsv.
 * Geprueft 25.10.2026 mit Watcom 10.6 (Messdienst): Groessenpruefung besteht, le_max +0x70, attrib[1].cur +0x4a, inv[2].quantity +0x1e0.
 * Von keiner Einheit automatisch eingebunden; Nutzung: #include "RIVA_HELD.H". */
#ifndef RIVA_HELD_H
#define RIVA_HELD_H
#ifndef NR_SKILLS
#define NR_SKILLS 52	/* Sternenschweif s_const.h */
#endif
#ifndef NR_SPELLS
#define NR_SPELLS 86
#endif
#ifndef NR_INV_SLOTS
#define NR_INV_SLOTS 31
#endif
#pragma pack(push,1)
struct hero_attrib {			/* 3 Bytes, hero +0x46 + 3*i (BE HERO_ATTRIB_ORIG/ATTRIB/ATTRIB_MOD) */
	signed char normal;		/* +0 Grundwert */
	signed char cur;		/* +1 aktueller Wert */
	signed char mod;		/* +2 Modifikator; wirksamer Wert = cur + mod */
};

struct hero_ill {			/* 5 Bytes: Krankheit (+0xc0) bzw. Gift (+0xe8) */
	signed char state;		/* +0 ILL_STATE_SICK (-1) krank/vergiftet, ILL_STATE_RECOVER (1) genesend */
	signed char days;		/* +1 Dauer (Tage bzw. Ticks), wird je Durchlauf erhoeht */
	signed char loss_kk;		/* +2 abgezogene KK (Bannstaub: abgezogene AE) */
	signed char loss_ge;		/* +3 abgezogene GE */
	unsigned char effect:1;	/* +4 Bit 0: Wirkung ist eingetreten (Werte abgezogen) */
	unsigned char diagnosed:1;	/*    Bit 1 erkannt: erste Heilkunde-Probe gelungen (O090 setzt, O074 loescht) */
	unsigned char ill_b2:1;
	unsigned char ill_b3:1;
	unsigned char ill_b4:1;
	unsigned char ill_b5:1;
	unsigned char ill_b6:1;
	unsigned char ill_b7:1;
};

struct hero_effect {			/* 7 Bytes, hero +0x55b, 20 Stueck (R02 add_effect/remove_effect) */
	signed long time;		/* +0 Restzeit (Ticks) */
	signed char type;		/* +4 Art */
	signed char index;		/* +5 Index (z. B. Eigenschaft) */
	signed char value;		/* +6 Betrag */
};

struct inv_slot {			/* 0x1b Bytes, hero +0x1a8 + 0x1b*i (BE: struct inventory, dort 14 Bytes) */
	signed short item_id;		/* +0x00 Gegenstand (Index in g_items, ds:b84a); 0 = leer */
	signed short quantity;		/* +0x02 Anzahl bzw. Ladungen */
	unsigned char broken:1;	/* +0x04 Bit 0 (BE inventory_flags) */
	unsigned char half_empty:1;	/*       Bit 1 Wasserschlauch halb leer */
	unsigned char empty:1;		/*       Bit 2 Wasserschlauch leer */
	unsigned char magic:1;		/*       Bit 3 magisch (O085 "magic") */
	unsigned char inv_b4:1;	/*       Bit 4 */
	unsigned char poison_expurgicum:1; /*   Bit 5 */
	unsigned char poison_vomicum:1; /*      Bit 6 */
	unsigned char magic_revealed:1; /*      Bit 7 Magie bekannt */
	signed char f05;		/* +0x05 */
	signed char bf;			/* +0x06 Bruchfaktor (O085 "bf"; O048/O062 nennen es "charges" - offen) */
	signed char rs_lost;		/* +0x07 verlorener RS (BE) */
	signed char lighting_timer;	/* +0x08 Brenndauer Fackel/Lampe (BE) */
	signed char poison_type;	/* +0x09 Gift auf der Waffe (O079 "poison", O085 "ptype") */
	signed char poison_charges;	/* +0x0a verbleibende Giftladungen (O079 "charges", O085 "pcnt") */
	unsigned long key_bits;	/* +0x0b Schluesselbund 0x145: belegte Faecher (Bit i = g_keyring_keys[i]; O092 box_has/box_set) */
	signed char _r0f;
	signed char f10;		/* +0x10 (O084) */
	signed char _r11[0x1b - 0x11];
};

struct hero {				/* 0x5ef Bytes */
	char version[0x0c];		/* +0x000 Kennung "DSA VERSION" (O171 kopiert g_dsa_version_string hinein) */
	unsigned char ver[4];		/* +0x00c Versionsbytes (O171/O177: g_version_a/c/b/d); Spielstand-Satz ab hier (O077) */
	signed short portrait;		/* +0x010 Bildnummer des Portraets in der Kopfbilddatei (O076, O093) */
	char file_name[0x10];		/* +0x012 Name der Heldendatei (BE HERO_NAME; O071/O088 vergleichen ihn) */
	char name[0x10];		/* +0x022 angezeigter Name (BE HERO_NAME2) */
	signed char nr_items;		/* +0x032 Zahl belegter Inventarplaetze (BE NR_INVENTORY_SLOTS_FILLED) */
	signed char type;		/* +0x033 Heldentyp HERO_TYPE_* (>= 7 zauberkundig) */
	signed char sex;		/* +0x034 Geschlecht (0 = maennlich) */
	unsigned char height;		/* +0x035 Groesse (cm) */
	signed short weight;		/* +0x036 Gewicht (Unzen) */
	signed char god;		/* +0x038 Gottheit */
	signed char level;		/* +0x039 Stufe */
	signed long ap;			/* +0x03a Abenteuerpunkte */
	signed long money;		/* +0x03e Geld (Heller); Gruppengeld wird auf die Helden verteilt (O200) */
	signed char rs_bonus;		/* +0x042 RS-Bonus (BE RS_BONUS1) */
	signed char rs_bonus2;		/* +0x043 (BE RS_BONUS2) */
	signed char rs_be;		/* +0x044 Ruestungsbehinderung (BE RS_BE) */
	signed char bp_left;		/* +0x045 Bewegungspunkte im Kampf (O150 "bp", O154 add45) */
	struct hero_attrib attrib[14];	/* +0x046 Eigenschaften ATTRIB_* */
	signed short le_max;		/* +0x070 LE-Grundwert (BE LE_ORIG) */
	signed short le;		/* +0x072 Lebensenergie */
	signed short ae_max;		/* +0x074 AE-Grundwert (BE AE_ORIG) */
	signed short ae;		/* +0x076 Astralenergie */
	signed char mr;			/* +0x078 Magieresistenz (ohne mr_mod, O076_0832) */
	signed char atpa_base;		/* +0x079 AT/PA-Basis = (IN + KK + GE) / 5 (O076_0940) */
	signed char at[7];		/* +0x07a AT je Waffentalent 0..6 */
	signed char pa[7];		/* +0x081 PA je Waffentalent 0..6 */
	signed char at_mod;		/* +0x088 (BE AT_MOD) */
	signed char pa_mod;		/* +0x089 (BE PA_MOD) */
	signed char weapon_type;	/* +0x08a Art der gefuehrten Waffe (BE WEAPON_TYPE) */
	signed char attack_type;	/* +0x08b Kampfweise (BE ATTACK_TYPE; O154 set8b) */
	signed char le_mod;		/* +0x08c dauerhaft verlorene LE (O076_0549) (BE LE_MOD) */
	signed char timer_id;		/* +0x08d (BE TIMER_ID) */
	signed char start_gear;		/* +0x08e (BE START_GEAR) */
	signed char herbs;		/* +0x08f (BE HERBS) */
	signed char hunger_timer;	/* +0x090 (BE HUNGER_TIMER) */
	signed char hunger;		/* +0x091 Hunger in % (O005, O076_0E64) */
	signed char thirst;		/* +0x092 Durst in % (O005, O076_0EA7) */
	signed char fighter_id;		/* +0x093 Kampffigur (BE FIGHTER_ID) */
	signed char viewdir;		/* +0x094 Blickrichtung im Kampf (BE VIEWDIR) */
	signed char actions;		/* +0x095 Aktionen (BE ACTIONS) */
	signed char action_id;		/* +0x096 Kampfaktion (O154 "Aktion"; O076: 100 tot, 12 bewusstlos) */
	signed char spell_id;		/* +0x097 letzter Zauber im Kampf (BE SPELL_ID) */
	signed char enemy_id;		/* +0x098 Ziel im Kampf (O079 "enemy_id", O154 "Ziel") */
	signed char group_no;		/* +0x099 Gruppe 0..5 (O074 "grp"; Vergleich mit g_group_no) */
	signed char money_share;	/* +0x09a NSC: Anteil am Gruppengeld in % (O200_0084); BE: TEMPLE_ID */
	signed char npc_id;		/* +0x09b NSC-Nummer, 0 = kein NSC (O196 "npc", O200) */
	signed char group_pos;		/* +0x09c (BE GROUP_POS) */
	signed long heal_timer;		/* +0x09d (BE HEAL_TIMER) */
	signed long staffspell_timer;	/* +0x0a1 (BE STAFFSPELL_TIMER) */
	signed char recipe_id;		/* +0x0a5 Alchimie-Rezept (BE RECIPE_ID) */
	signed char recipe_timer;	/* +0x0a6 (BE RECIPE_TIMER) */
	signed char ruhe_koerper;	/* +0x0a7 (BE RUHE_KOERPER) */
	signed char blind;		/* +0x0a8 Kampfrunden geblendet (BE BLIND) */
	signed char ecliptifactus;	/* +0x0a9 (BE ECLIPTIFACTUS) */
	signed char saftkraft;		/* +0x0aa (BE SAFTKRAFT) */
	signed char fireban;		/* +0x0ab (BE FIREBAN) */
	signed char invisible;		/* +0x0ac (BE INVISIBLE) */
	signed char sprite_no;		/* +0x0ad Kampfgrafik (BE SPRITE_NO) */
	signed char alchemy_inn_id;	/* +0x0ae (BE ALCHEMY_INN_ID) */
	signed short escape_position;	/* +0x0af (BE ESCAPE_POSITION) */
	signed char jail;		/* +0x0b1 (BE JAIL) */
	signed char axxeleratus;	/* +0x0b2 (BE AXXELERATUS) */
	signed char drunk;		/* +0x0b3 betrunken (BE DRUNK; R10: O074_0872) */
	signed char parried;		/* +0x0b4 in dieser Runde schon pariert (O135: Paradebild nur beim ersten Mal; O080: 0
					   je Runde; O158/O159/O161: Angreifer AT +2, keine Parade mehr) (BE HERO_IS_TARGET) */
	signed char fb5;		/* +0x0b5 (Kampf); 99 = Zauber aus einem Gegenstand (O047; O235/O236: ohne Eingabe, Hoechstwirkung) */
	unsigned char fb6_b0:1;	/* +0x0b6 Bit 0 (O080/O157; O154 setb6) */
	unsigned char fb6_b1:1;
	unsigned char fb6_b2:1;
	unsigned char fb6_b3:1;
	unsigned char fb6_b4:1;
	unsigned char fb6_b5:1;
	unsigned char fb6_b6:1;
	unsigned char fb6_b7:1;
	signed char fb7;		/* +0x0b7 */
	signed char rest_bonus;	/* +0x0b8 Erholungsbonus der naechsten Regeneration (O072 camp_regenerate setzt, O074 hero_sleep
				   addiert ihn zu LE/AE und loescht ihn) (frueher fb8) */
	signed char watches;		/* +0x0b9 Wachen in dieser Rast (O071/O072; ab 2 keine Erholung group_sleep, je Wache -2) (frueher fb9) */
	unsigned char rest_magic:1;	/* +0x0ba Bit 0: in der Rast gezaubert (O072 camp_use_magic; Erholung -1) (frueher fba_b0) */
	unsigned char rest_food:1;	/*        Bit 1: in der Rast Nahrung/Wasser gesucht (O071 camp_find_food) (frueher fba_b1) */
	unsigned char rest_herbs:1;	/*        Bit 2: in der Rast Kraeuter gesucht (O071 camp_gather_herbs; Erholung -2) (frueher fba_b2) */
	unsigned char fba_b3:1;
	unsigned char fba_b4:1;
	unsigned char fba_b5:1;
	unsigned char fba_b6:1;
	unsigned char fba_b7:1;
	signed char mr_mod;		/* +0x0bb MR-Modifikator; wirksame MR = mr + mr_mod (O076_07FB) */
	/* +0x0bc Zustandsbits (BE hero_flags +0xaa) */
	unsigned char dead:1;		/* +0xbc.0 tot */
	unsigned char asleep:1;	/* +0xbc.1 schlaeft (O076_01F3 weckt, O080_0679) */
	unsigned char petrified:1;	/* +0xbc.2 versteinert */
	unsigned char brewing:1;	/* +0xbc.3 braut (BE) */
	unsigned char chamaelioni:1;	/* +0xbc.4 (BE) */
	unsigned char renegade:1;	/* +0xbc.5 (BE) */
	unsigned char unconscious:1;	/* +0xbc.6 bewusstlos (O080_0679, O089/O081 Merker) */
	unsigned char tied:1;		/* +0xbc.7 gefesselt (BE) */
	/* +0x0bd */
	unsigned char scared:1;	/* +0xbd.0 veraengstigt (O089 Angstgift, nur im Kampf) */
	unsigned char ueber_eis:1;	/* +0xbd.1 Ueber Eis wirkt (EFFECT_UEBER_EIS; O235 spell_ueber_eis) (frueher bd1) */
	unsigned char bd2:1;		/* +0xbd.2 (BE: duplicatus) */
	unsigned char tame:1;		/* +0xbd.3 gezaehmt/beherrscht (O194 Bannbaladin der Gegner) (BE tame; frueher bd3) */
	unsigned char harmless:1;	/* +0xbd.4 Harmlose Gestalt (EFFECT_HARMLOS; Portraet 0x3a4, O076) (frueher bd4) */
	unsigned char gods_pissed:1;	/* +0xbd.5 Goetter erzuernt: keine Tempelwunder fuer den Helden (O033; BE gods_pissed; frueher bd5) */
	unsigned char transformed:1;	/* +0xbd.6 verwandelt (O233 Verwandlung beenden: Eigenschaften +1) (BE transformed; frueher bd6) */
	unsigned char saftkraft_on:1;	/* +0xbd.7 Saft, Kraft, Monstermacht wirkt (EFFECT_SAFTKRAFT_ON; O236) (frueher bd7) */
	/* +0x0be weitere Bits (DSA 2) */
	unsigned char scharfes_auge:1;	/* +0xbe.0 Scharfes Auge wirkt (EFFECT_SCHARFES_AUGE; O236) (frueher be0) */
	unsigned char see_und_fluss:1;	/* +0xbe.1 In See und Fluss wirkt (EFFECT_SEE_UND_FLUSS; O237 fuer die Gruppe) (frueher be1) */
	unsigned char sooty:1;	/* +0xbe.2 verrusst, CH - 2 (vermutet; Wasserstellen O002/O065/O066 waschen ab, CH + 2) */
	unsigned char adler_wolf:1;	/* +0xbe.3 Adler, Wolf: Tiergestalt (EFFECT_ADLER_WOLF; Portraet 0x3a4 Bild n-1, O076) (frueher be3) */
	unsigned char flim_flam:1;	/* +0xbe.4 Flim Flam: Licht (EFFECT_FLIM_FLAM; O237) (frueher be4) */
	unsigned char dunkelheit:1;	/* +0xbe.5 Dunkelheit (EFFECT_DUNKELHEIT; O237) (frueher be5) */
	unsigned char be6:1;
	unsigned char be7:1;
	signed char fbf;		/* +0x0bf */
	struct hero_ill illness[8];	/* +0x0c0 Krankheiten ILLNESS_* (Eintrag 0 unbenutzt) */
	struct hero_ill poison[10];	/* +0x0e8 Gifte POISON_* (Eintrag 0 unbenutzt) */
	signed char skills[NR_SKILLS];	/* +0x11a Talentwerte TA_* */
	unsigned char skill_incs;	/* +0x14e gespeicherte Talentsteigerungen (BE TA_RISE) */
	signed char spells[NR_SPELLS];	/* +0x14f Zauberwerte SP_* */
	unsigned char spell_incs;	/* +0x1a5 gespeicherte Zaubersteigerungen (BE SP_RISE) */
	signed char magic_school;	/* +0x1a6 Magierakademie (BE MAGIC_SCHOOL) */
	signed char staffspell_lvl;	/* +0x1a7 Stabzauberstufe (BE STAFFSPELL_LVL) */
	struct inv_slot inv[NR_INV_SLOTS]; /* +0x1a8 Inventar (0..14 am Koerper, 15..30 Rucksack) */
	signed short load;		/* +0x4ed Traglast (BE LOAD) */
	signed char f4ef;		/* +0x4ef */
	signed char f4f0;		/* +0x4f0 (O076_0E64/0EA7 setzen 0) */
	signed short target_x;		/* +0x4f1 Zielfeld im Kampf (O137 Zauberwirkung/Beschwoerung, O153..O156) */
	signed short target_y;		/* +0x4f3 */
	signed short gardianum;		/* +0x4f5 Schutzpunkte des Gardianum (O233: AE + Stufe; O080: 0 nach dem Kampf) (frueher f4f5) */
	signed char duplicatus;		/* +0x4f7 Spiegelbilder des Duplicatus 0..2 (O137 setzt 1/2, O112 zeichnet die
					   Figur 2- bzw. 3-mal, O161: AT des Gegners / 2 bzw. / 3, O076: 0 beim Tod) */
	signed char fur_hands;		/* +0x4f8 Pelz an den Haenden (Dungeon 13, O065): 1..5 brennender Pelz breitet sich aus
					   (O005 hero_fur_tick, BINGE.LTX[22..26]), 6 kuehler Pelz, -1 geheilt (FF kehrt zurueck), 0 keiner
					   (frueher f4f8, in O005 als "Sucht" gedeutet) */
	signed char slot_pos;		/* +0x4f9 Platz in der Portraetleiste (R02_051F, O201) */
	signed char attack_style;	/* +0x4fa Kampfstil aus dem Kampfmenue (O154): 0 normal, 1 -> attack_type 2, sonst -2 */
	signed char _r4fb[0x553 - 0x4fb];
	signed short saved_le_max;	/* +0x553 gemerkte Werte (R02), O076_0EEA fuellt die 8 Bytes */
	signed short saved_le;		/* +0x555 */
	signed short saved_ae_max;	/* +0x557 */
	signed short saved_ae;		/* +0x559 */
	struct hero_effect effects[20];	/* +0x55b zeitlich begrenzte Wirkungen (R02_087D add_effect) */
	void *f5e7;			/* +0x5e7 (O091, O206) */
	char * *txt;		/* +0x5eb Textliste (O006, O090, O206, O207) */

};
#pragma pack(pop)
typedef char riva_held_groesse_pruefen[(sizeof(struct hero)==0x5ef && sizeof(struct inv_slot)==0x1b && sizeof(struct hero_attrib)==3 && sizeof(struct hero_ill)==5)?1:-1];
#endif
