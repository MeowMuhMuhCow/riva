/* === Beschreibung (Katalog) ===
 * Einheit fz_17a940 (0x17a940 - 0x17b3c0)
 *
 * Überblick
 * Diese Einheit enthält den Textparser für die 3D-Animations-, Texturfolgen- und Objektdefinitionsdateien der
 * Riva-3D-Engine sowie für eine 100-zeilige Zuordnungstabelle (d_1c76f8). Die Datei wird in einem Vorlauf
 * (f_17a940) zunächst zur Bestimmung der Tabellengrößen gezählt und anschließend im Hauptlauf (f_17aaec) in die
 * vorallozierten Engine-Puffer eingelesen.
 === Ende Beschreibung === */
// P3 7/9 gleich (suche.py 30.10.2026, Basis fz_17a940_P1.CPP)
// OPT -5r -onetx -zp1 -s -fp5
// P1 4/6 gleich
// CC wcc386
// fz_17a940.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x17A940-0x17B3C0 (08.11. Claude I15: Modulgrenze bei 0x17B3C0, Linker-Nullen im Original)
#include <string.h>
int f_14d5c9(int p1);
int f_187bdc(int p1);
int f_188404(int p1, int p2, int p3);
int f_18850c(int p1);
int f_18eebb(void);
int f_18f228(int p1);
int f_15e469(char *p1, const char *p2);
char f_1794a7(int p1);
int f_145318(char *p1, const char *p2);
int f_15e836(int p1);
int f_14572e(char *p1, const char *p2, ...);
#pragma aux f_14d5c9 "*";
#pragma aux f_187bdc "*";
#pragma aux f_188404 "*";
#pragma aux f_18850c "*";
#pragma aux f_18eebb "*";
#pragma aux f_18f228 "*";
#pragma aux f_15e469 "*";
#pragma aux f_1794a7 "*";
#pragma aux f_145318 "*";
#pragma aux f_15e836 "*";
#pragma aux f_17b140 "*";
#pragma aux f_17b260 "*";
#pragma aux f_17b3c0 "*";
#pragma aux f_17b4b8 "*";
#pragma aux f_17b4d0 "*";
#pragma aux f_17b4e0 "*";
#pragma aux f_17b4f0 "*";
extern int d_1af3c0;
extern int d_1b4524;
extern int d_1b4954;
extern int d_1b498c;
extern int d_1b49a0;
extern unsigned char d_1b4e08;
extern char d_1ba070[];
extern char d_1ba078[];
extern char d_1b9ff0[];
extern char d_1ba080[];
extern char d_1ba0a8[];
extern char d_1c76f8[];
extern char d_1ccf88[];
extern int d_1a996c;
extern char *d_1cdb90;
extern char d_1cd0b0[];
extern int d_1d452c;
extern int d_1d4540;
extern int d_1d4554;
extern int d_1d4568;
extern int d_1d457c;
extern int d_1d45d8;
extern int d_1d45e8;
extern int d_1d49a0;
extern int d_1d49a4;
extern int d_1d49a8;
extern int d_1d49ac;
extern int d_1d49b0;
extern int d_1d49b4;
extern int d_1d49b8;
extern int d_1af288[];
extern int d_1b4d1c[];
extern int d_1b4dc4[];
struct S116 { int a[29]; };

extern char d_1b9fe8[], d_1b9ff4[], d_1b9ff8[], d_1ba000[], d_1ba008[];
extern int d_1a9a4c, d_1a9a54, d_1a9a58;
extern volatile int d_1a9a50;
int strcmp494(const char *,const char *);
#pragma aux strcmp494 "f_144bf0" modify exact [eax];
#pragma aux f_1794a7 modify exact [eax];
#pragma aux f_145318 modify exact [eax edx];
#pragma aux f_17a940 "*";
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_17a940
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17a940
 * - Aufgabe im Spiel: Öffnet im Vorlauf eine Textdefinitionsdatei aus dem 3D-Datenverzeichnis (d_1cd0b0 +
 *   Dateiname + Endung d_1b9fe8), entfernt Zeilenkommentare ab dem Zeichen '#' und zählt anhand des ersten
 *   Schlüsselworts jeder Zeile, wie viele Textursequenzen (d_1a9a4c), Animationsfolgen (d_1a9a54) samt
 *   Einzel-Frames (d_1a9a50) und 3D-Objekteinträge (d_1a9a58) in der Datei definiert sind. Dadurch kann die
 *   Engine vor dem eigentlichen Einlesen (f_17aaec) die exakt benötigten Speicherblöcke reservieren.
 * - Eingaben: Der Basisdateiname der Definitionsdatei als Zeichenkette.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globaler Basispfad d_1cd0b0, Dateiendung d_1b9fe8 und Lesemodus d_1b9ff0: Bestimmen den vollständigen Pfad
 *     der Definitionsdatei.
 *   - Globale Zähler d_1a9a4c, d_1a9a54, d_1a9a50 und d_1a9a58: Werden für die drei Schlüsselworttypen
 *     (d_1b9ff8, d_1ba000, d_1ba008) hochgezählt.
 *   - Lokaler Zeilenpuffer (512 Bytes) und Kommentar-Flag: Speichern die aktuell gelesene Textzeile ohne
 *     '#'-Kommentarteil für die Token-Zerlegung über f_145318.
 === Ende Beschreibung === */
void f_17a940(const char *name)
{
 struct Frame494 {char line[512];char path[256];char c;} frame;
 int n,f; char comment; char *word;
 if(name) {
  strcpy(frame.path,d_1cd0b0);strcat(frame.path,name);strcat(frame.path,d_1b9fe8);
  f=f_15e469(frame.path,d_1b9ff0);
  if(f) {
   while((*(unsigned *)(f+12)&16)==0) {
    frame.line[0]=0;comment=0;n=0;
    while((frame.c=f_1794a7(f))!='\n' && (*(unsigned *)(f+12)&16)==0) {
     if(frame.c=='#'){frame.line[n]=0;comment=1;}
     if(!comment && n<511)frame.line[n++]=frame.c;
    }
    frame.line[n]=0;word=(char *)f_145318(frame.line,d_1b9ff4);
    if(word) {
     if(strcmp494(word,d_1b9ff8)==0)++d_1a9a4c;
     else if(strcmp494(word,d_1ba000)==0) {
      word=(char *)f_145318(0,d_1b9ff4);
      if(word){++d_1a9a54;while((word=(char *)f_145318(0,d_1b9ff4))!=0)++d_1a9a50;}
     }else if(strcmp494(word,d_1ba008)==0)++d_1a9a58;
    }
   }
   f_15e836(f);
  }
 }
}

extern char d_1ba010[],d_1ba038[],d_1ba064[];
extern double d_1ba067;
extern char *d_1cd200,*d_1a9924,*d_1cd1f4,*d_1cd1f0;
extern short *d_1cd1fc;
int copy494(char *,const char *,int);
#pragma aux copy494 "f_148143" modify exact [eax ebx edx];
#pragma aux f_14d5c9 modify exact [eax];
double number494(const char *,char **);
#pragma aux number494 "f_18e187" value [8087] modify exact [eax edx];
#define QI(p,o) (*(int *)((char *)(p)+(o)))
#define QW(p,o) (*(short *)((char *)(p)+(o)))
#define QB(p,o) (*(char *)((char *)(p)+(o)))
#pragma aux f_17aaec "*";
//@ f_17aaec
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17aaec
 * - Aufgabe im Spiel: Liest dieselbe 3D-Definitionsdatei wie f_17a940 im Hauptlauf vollständig ein, zerlegt die
 *   Zeilen in Tokens und füllt die globalen Tabellen für 3D-Texturdefinitionen (d_1cd200, je 36 Bytes),
 *   Animations-Frame-Paare (d_1cd1f4 zu je 24 Bytes und d_1cd1fc für die Frame-/Dauer-Paare) sowie
 *   3D-Objekt-/Billboard-Assets (d_1cd1f0, je 32 Bytes inklusive Fließkomma-Skalierung und Verknüpfung auf
 *   Textur und Animation). Am Ende passt die Funktion die globalen Zähler (d_1a9a4c, d_1a9a50, d_1a9a54,
 *   d_1a9a58) nach unten an, falls tatsächlich weniger gültige Einträge gelesen wurden als im Vorlauf gezählt.
 * - Eingaben: Der Basisdateiname der Definitionsdatei als Zeichenkette.
 * - Rückgabewert: 0 bei Erfolg, 0xf005 bei fehlendem Dateinamen (NULL) oder 0xf010, wenn die Datei nicht
 *   geöffnet werden konnte.
 * - Wichtige Variablen:
 *   - Globale Tabellenzeiger d_1cd200 (Texturbeschreibungen), d_1a9924 (Texturwert-Array), d_1cd1f4
 *     (Animationsköpfe), d_1cd1fc (Animations-Wertepaare) und d_1cd1f0 (3D-Asset-Einträge).
 *   - Lokale Laufzähler für die vier Tabellen (na, nb, np, nc): Verhindern ein Überschreiten der im Vorlauf
 *     ermittelten Obergrenzen.
 *   - Globale Fehlervariablen d_1a996c und d_1cdb90: Speichern im Fehlerfall den Fehlercode und die formatierte
 *     Fehlermeldung (d_1ccf88).
 === Ende Beschreibung === */
int getc_A2_1225(int);
#pragma aux getc_A2_1225 "f_1794a7" modify exact [eax];
int f_17aaec(const char *name)
{
 int abs(int);
#pragma intrinsic(abs)
 char line[512],path[256],texture[20];
 char *a,*b,*asset,*values,*word,*token,*scan;
 short *pairs;
 int na,nb,nc,np,f,n,count,i,x;
 char c,comment;
 if(name==0){d_1cdb90=d_1ba010;d_1a996c=0xf005;return 0xf005;}
 strcpy(path,d_1cd0b0);strcat(path,name);strcat(path,d_1b9fe8);
 f=f_15e469(path,d_1b9ff0);
 if(f==0){f_14572e(d_1ccf88,d_1ba038,path);d_1cdb90=d_1ccf88;return d_1a996c=0xf010;}
 na=0;a=d_1cd200;values=d_1a9924;pairs=d_1cd1fc;b=d_1cd1f4;np=0;nb=0;asset=d_1cd1f0;nc=0;
 while((*(unsigned *)(f+12)&16)==0) {
  line[0]=0;n=0;comment=0;
  while((c=getc_A2_1225(f))!='\n' && (*(unsigned *)(f+12)&16)==0){
   if(c=='#'){line[n]=0;comment=1;}
   if(!comment && n<511){++n;line[n-1]=c;}
  }
  line[n]=0;word=(char *)f_145318(line,d_1b9ff4);
  if(word==0)goto nextline;
  if(strcmp494(word,d_1b9ff8)==0){
   int amount; QB(a,21)=0;QW(a,24)=0;QW(a,22)=0;
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   copy494(a,token,19);a[19]=0;
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   amount=f_14d5c9((int)token);
   if(amount<0){QB(a,20)=1;QW(a,26)=amount;QW(a,26)=-QW(a,26);}else {QB(a,20)=0;QW(a,26)=amount;}
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   QW(a,28)=f_14d5c9((int)token);
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   QW(a,30)=f_14d5c9((int)token);QI(a,32)=(int)values;
   ++na;if(na>d_1a9a4c)break;
   values+=(unsigned short)QW(a,26)*4;a+=36;
  }else if(strcmp494(word,d_1ba000)==0){
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   copy494(b,token,15);b[15]=0;QI(b,20)=(int)pairs;
   count=0;
   for(;;){
    token=(char *)f_145318(0,d_1ba064);if(!token)break;
    pairs[0]=1;pairs[1]=(short)f_14d5c9((int)token);
    token=(char *)f_145318(0,d_1b9ff4);if(!token)break;
    pairs[0]=(short)f_14d5c9((int)token);++np;
    if(np>d_1a9a50)break;
    ++count;pairs+=2;
    count=(count&0)?0:count; // haelt die Registerzuteilung wie im Original
   }
   // haelt die Registerzuteilung wie im Original
   nb=(nb&0)?0:nb;
   // haelt die Registerzuteilung wie im Original
   n=(n&0)?0:n;
   n=nb+1;
   *(volatile short *)(b+16)=count;
   nb=n;
   if(nb>d_1a9a54)break;
   b+=24;
  }else if(strcmp494(word,d_1ba008)==0){
   asset[0]=0;QI(asset,12)=0;QI(asset,16)=0;QW(asset,20)=0;QI(asset,24)=0;QI(asset,28)=0;texture[0]=0;
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   copy494(asset,token,10);asset[10]=0;
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   QI(asset,12)=(int)(number494(token,0)*d_1ba067);
   token=(char *)f_145318(0,d_1b9ff4);if(!token)goto nextline;
   x=(int)(number494(token,0)*d_1ba067);QI(asset,16)=abs(x);
   token=(char *)f_145318(0,d_1b9ff4);
   if(token){
    copy494(texture,token,12);texture[12]=0;
    token=(char *)f_145318(0,d_1b9ff4);
    if(token){
     QW(asset,20)=f_14d5c9((int)token);
     word=(char *)f_145318(0,d_1b9ff4);
     if(word){
      scan=d_1cd1f4;
      for(i=0;i<nb;i++,scan+=24)if(strcmp494(word,scan)==0){QI(asset,28)=QI(scan,20);break;}
      scan=d_1cd200;
      for(i=0;i<na;i++,scan+=36)if(strcmp494(texture,scan)==0){QI(asset,24)=(int)scan;break;}
     }
    }
   }
   ++nc;if(nc>d_1a9a58)break;
   if(QI(asset,28)==0 || QI(asset,24)==0)QW(asset,20)=0;
   asset+=32;
  }
 nextline:;
 }
 f_15e836(f);
 if(nc<d_1a9a58)d_1a9a58=nc;
 if(nb<d_1a9a54)d_1a9a54=nb;
 if(np<d_1a9a50)d_1a9a50=np;
 if(na<d_1a9a4c)d_1a9a4c=na;
 d_1a996c=0;return 0;
}

//@ f_17b140
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b140
 * - Aufgabe im Spiel: Löscht zunächst das jeweils erste Byte aller 100 Zeilen der globalen
 *   64-Byte-Zuordnungstabelle (d_1c76f8), öffnet anschließend - sofern ein Dateiname übergeben wurde - eine
 *   Textdatei mit der Endung d_1ba070 und liest diese zeilenweise ein. In der Schleife zerlegt die Funktion jede
 *   Zeile mit f_145318 am Trennzeichen d_1ba078 und wandelt das erste Token per f_14d5c9 (atoi) in eine Zahl um,
 *   verwirft das Ergebnis jedoch ungenutzt (vermutlich ein unfertiger Vorläufer von f_17b260).
 * - Eingaben: Der Basisdateiname als Zeichenkette (oder NULL, um nur die Tabelle zu leeren).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale 100x64-Byte-Tabelle d_1c76f8 (bzw. ab Basis d_1c76b8 mit Indexversatz 1): Wird zu Beginn in jedem
 *     ersten Zeilenbyte auf 0 gesetzt.
 *   - Lokaler Zeilenpuffer (512 Bytes) und Pfadpuffer (256 Bytes): Dienen zum Öffnen und zeilenweisen
 *     Durchlaufen der Datei.
 === Ende Beschreibung === */
extern char rowsB700[101][64];
#pragma aux rowsB700 "d_1c76b8";
void f_17b140(char *p)
{
    char line[512];
    char path[256];
    int i;
    int f;
    int n;
    char c;
    int t;

    for (i = 0; i < 100; i++)
        rowsB700[i+1][0]=0;
    if (p != 0) {
        strcpy(path, (char *)(int)&d_1cd0b0);
        strcat(path, p);
        strcat(path, (char *)(int)&d_1ba070);
        f = f_15e469(path, (char *)(int)&d_1b9ff0);
        if (f != 0) {
            while ((*(unsigned *)(f + 0xc) & 0x10) == 0) {
                line[0] = 0;
                n = 0;
                while ((c = f_1794a7(f)) != '\n' && (*(unsigned *)(f + 0xc) & 0x10) == 0) {
                    if (n < 0x1ff) {
                        line[n] = c;
                        n++;
                    }
                }
                line[n] = 0;
                t = f_145318(line, d_1ba078);
                if (t != 0) f_14d5c9(t);
            }
            f_15e836(f);
        }
    }
}
//@ f_17b260
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b260
 * - Aufgabe im Spiel: Leert die globale 100x64-Byte-Zuordnungstabelle d_1c76f8 und liest anschließend aus der
 *   angegebenen Textdatei zeilenweise Zahlenlisten ein. Die erste Zahl jeder Zeile (modulo 100, sofern größer
 *   als 0) bestimmt den Zeilenindex in d_1c76f8 und wird als erstes Byte eingetragen, woraufhin bis zu 58
 *   weitere positive Zahlenwerte (jeweils modulo 100) als nullterminierte Bytefolge in derselben 64-Byte-Zeile
 *   abgelegt werden.
 * - Eingaben: Der vollständige Dateipfad der einzulesenden Textdatei als Zeichenkette.
 * - Rückgabewert: 0 bei Erfolg, 0xf005 bei einem NULL-Zeiger oder 0xf010, falls die Datei nicht geöffnet werden
 *   kann.
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1c76f8: Nimmt je Index (1..99) bis zu 59 Bytewerte plus abschließende Nullterminierung
 *     auf.
 *   - Lokaler Zähler der belegten Bytes pro Tabellenzeile (used): Begrenzt das Einlesen auf maximal 60
 *     Positionen pro Zeile, damit die 64-Byte-Zeile nicht überläuft.
 *   - Globale Fehlervariablen d_1a996c und d_1cdb90: Nehmen Fehlercode und Fehlertext auf.
 === Ende Beschreibung === */
int f_17b260(char *p)
{
    char line[512];
    int stream, index, count, value, used;
    char c, *dst, *token;
    if (p == 0) {
        d_1cdb90 = d_1ba080;
        return d_1a996c = 0xf005;
    }
    stream = f_15e469(p, d_1b9ff0);
    if (stream == 0) {
        f_14572e(d_1ccf88, d_1ba0a8, p);
        d_1cdb90 = d_1ccf88;
        d_1a996c = 0xf010;
        return 0xf010;
    }
    index = 0;
    do {
        index += 64;
        d_1c76f8[index - 64] = 0;
    } while (index != 0x1900);
    while ((*(unsigned char *)(stream + 12) & 16) == 0) {
        line[0] = 0;
        count = 0;
        while ((c = f_1794a7(stream)) != '\n' &&
               (*(unsigned char *)(stream + 12) & 16) == 0) {
            if (count < 511) line[count++] = c;
        }
        line[count] = 0;
        token = (char *)f_145318(line, d_1ba078);
        if (token == 0) continue;
        value = f_14d5c9((int)token) % 100;
        if (value <= 0) continue;
        dst = d_1c76f8 + value * 64;
        used = 2;
        *dst++ = (char)value;
        while ((token = (char *)f_145318(0, d_1ba078)) != 0) {
            value = f_14d5c9((int)token) % 100;
            if (value > 0) {
                *dst++ = (char)value;
                ++used;
            }
            if (used >= 60) break;
        }
        *dst = 0;
    }
    f_15e836(stream);
    d_1a996c = 0;
    return 0;
}
