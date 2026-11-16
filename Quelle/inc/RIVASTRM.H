/* D23: gemeinsame Stream-ABI. Vtable d_1bbf24 belegt die Slots.
 * Ein Stream hat 20 Byte implementationsabhaengigen Zustand und danach
 * den Vtablezeiger. Die Dateimanager-Felder konkretisieren diesen Zustand;
 * andere Implementierungen werden damit nicht gleichgesetzt.
 * Slot 00 ist noch nicht fachlich benannt und wird nicht aufgerufen. */
#ifndef RIVASTRM_H
#define RIVASTRM_H
#pragma pack(push,1)
struct RivaFileStream;
struct RivaFileStreamVtable {
    unsigned reserved_00;
    void (*f_144820)(RivaFileStream *stream);
    char * (*f_144850)(RivaFileStream *stream, unsigned p2);
    int (*f_144870)(RivaFileStream *stream, unsigned p2);
    void (*f_144890)(RivaFileStream *stream, unsigned p2);
    union { int (*f_1448b0)(RivaFileStream *stream, unsigned p2, int p3); int (*open)(RivaFileStream *stream, unsigned p2, int p3); int (*m14)(RivaFileStream *stream, unsigned p2, int p3); int (*r14)(RivaFileStream *stream, unsigned p2, int p3); };
    int (*f_1448d0)(RivaFileStream *stream, unsigned p2, void *buffer);
    int (*f_1448f0)(RivaFileStream *stream, int p2);
    union { unsigned (*f_144920)(RivaFileStream *stream, void *p2, int p3); unsigned (*read)(RivaFileStream *stream, void *p2, int p3); unsigned (*m20)(RivaFileStream *stream, void *p2, int p3); unsigned (*r20)(RivaFileStream *stream, void *p2, int p3); };
    union { unsigned (*f_144960)(RivaFileStream *stream, void *p2, int p3); unsigned (*write)(RivaFileStream *stream, void *p2, int p3); };
    union { int (*f_1449a0)(RivaFileStream *stream); int (*close)(RivaFileStream *stream); int (*m28)(RivaFileStream *stream); int (*r28)(RivaFileStream *stream); };
    void (*f_1449d0)(RivaFileStream *stream);
    union { long (*f_144a00)(RivaFileStream *stream); long (*length)(RivaFileStream *stream); long (*m30)(RivaFileStream *stream); };
    union { long (*f_144a30)(RivaFileStream *stream, unsigned p2); long (*m34)(RivaFileStream *stream, unsigned p2); };
    int (*f_144a50)(RivaFileStream *stream, int p2);
    long (*f_144a80)(RivaFileStream *stream);
    union { int (*f_144ab0)(RivaFileStream *stream, int p2, int p3); int (*seek)(RivaFileStream *stream, int p2, int p3); int (*m40)(RivaFileStream *stream, int p2, int p3); };
    void (*f_144af0)(RivaFileStream *stream, unsigned p2);
    void (*f_144b10)(RivaFileStream *stream);
    int (*f_144b40)(RivaFileStream *stream, int p2);
    void (*f_144b70)(RivaFileStream *stream, int p2, void *p3, int p4);
    void (*f_144bb0)(RivaFileStream *stream, int p2, int p3);
};
struct RivaFileStream { char state[0x14]; RivaFileStreamVtable *vt; };
#pragma pack(pop)
typedef char riva_stream_layout[(sizeof(RivaFileStream)==24 && sizeof(RivaFileStreamVtable)==88)?1:-1];
extern RivaFileStreamVtable d_1bbf24;
#endif
