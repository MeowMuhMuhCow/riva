/* === Beschreibung (Katalog) ===
 * Einheit gz_038ba0_t2 (0x03aa20 - 0x03ac38)
 *
 * Überblick
 * Dieser zweite Teil der Einheit gz_038ba0 enthält mit f_03aa20 den zentralen Dispatcher für die aktive
 * Talent-Anwendung durch den Spieler (über das "Talent benutzen"-Symbol im Spielbildschirm oder in Tavernen).
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P1 0/1 gleich
// gz_038ba0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x038BA0-0x03AC50
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
typedef RivaTextContextData PL;
int f_012dd0(int p1);
short f_03ac50(int p1, int p2);
int f_03afe0(int p1, int p2);
int f_03b0b0(int p1, int p2);
int f_03b190(int p1, int p2);
int f_03b400(int p1, int p2);
int f_03b4f0(int p1, int p2);
int f_03b8d0(int p1, int p2);
int f_03bc50(int p1, int p2);
int f_038e90(int p1, int p2, short p3);
int f_03c210(int p1, int p2, int p3, int p4);
int f_03c630(int p1, int p2, int p3);
int f_0b8a00(int p1, int p2);
int f_0d49b0(int p1);
int f_0dc020(int p1, int p2);
int f_126f80(void *p1, int p2, int p3, int p4, int p5, int p6);
int f_1270c0(void *p1);
int f_1271f0(void *p1);
extern signed char d_1a9670;
extern int d_1bf1ac;
extern int d_1c0004;
//@ f_03aa20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion öffnet für einen handlungsfähigen Helden p1 über f_03ac50 das Menü der
 *   situationsabhängig direkt einsetzbaren Talente und verzweigt je nach gewähltem Talent zur entsprechenden
 *   Ausführungsroutine: Heilkunde Gift (0x2c -> f_03bc50), Heilkunde Krankheiten (0x2d -> f_03c210), Heilkunde
 *   Wunden (0x2e -> f_03b8d0), Falschspiel (9 -> f_03b400), Musizieren (0x2f -> f_03b190), Gaukelei (0x10 ->
 *   f_03b4f0), Akrobatik (0x2b -> f_03b0b0), Taschendiebstahl (0x31 -> f_03afe0), Abrichten/Tierkunde (0x20 ->
 *   f_012dd0) oder Schätzen (0x19 -> f_03c630).
 * - Eingaben und Rückgabe: Die Funktion erhält den ausführenden Helden p1, den Probenmodifikator p2 (signed
 *   char), den Kontextcode p3 (short, z. B. 4 in einer Taverne) und eine optionale Gegenstands-ID p4 (für das
 *   Talent Schätzen) und gibt das Ergebnis der Talentanwendung (1 bei Erfolg, negative Werte bei Fehlschlag oder
 *   -3 bei Abbruch) zurück.
 * - Wichtige Variablen: Ist die Talentprobe in einem besonderen Kontext (p3 != 0) fehlgeschlagen (result < 0 &&
 *   result != -3), wird über f_0b8a00(d_1bf1ac, ...) ein entsprechendes Ereignis im aktuellen Ort ausgelöst
 *   (etwa Rauswurf aus der Taverne bei ertapptem Falschspiel oder Taschendiebstahl).
 === Ende Beschreibung === */
short f_03aa20(int p1, signed char p2, short p3, short p4)
{
struct Apply670 { static int run(int actor,signed char mod){
 int ask670(int,int);
#pragma aux ask670 "f_038e90" modify exact [eax edx]
 d_1a9670=f_0dc020(d_1c0004,actor);
 short adjustment=mod;
 int chosen=ask670(d_1c0004,0x205000c);
 if(chosen==0)return -3;
 f_03c210(actor,chosen,adjustment,0);
 return 1;
}};

    short result;
    short opcode;
    short v;
    int t;
    char obj[8];
    result = 0;
    if (f_0d49b0(p1)) {
        opcode = f_03ac50(p1, (short)p3);
        switch (opcode) {
        case 0x2c:
            result = f_03bc50(p1, p2);
            break;
        case 0x2d:
            result=Apply670::run(p1,p2);
            break;
        case 0x2e:
            result = f_03b8d0(p1, p2);
            break;
        case 9:
            result = f_03b400(p1, p2);
            break;
        case 0x2f:
            result = f_03b190(p1, p2);
            break;
        case 0x10:
            result = f_03b4f0(p1, p2);
            break;
        case 0x2b:
            result = f_03b0b0(p1, p2);
            break;
        case 0x31:
            result = f_03afe0(p1, (short)(p2 + 10));
            break;
        case 0x20:
            if (f_012dd0(p1)) result = 1;
            else result = -3;
            break;
        case -1:
            result = -3;
            break;
        case 0x19:
            result = f_03c630(p1, p2, (short)p4);
            break;
        }
        if ((short)result < 0 && (short)result != -3 && p3 != 0) {
            f_126f80(obj, 1, 0, 2, 0, 0);
            f_1270c0(obj);
            f_0b8a00(d_1bf1ac, f_1271f0(obj));
        }
    } else {
        result = -1;
    }
    return result;
}
