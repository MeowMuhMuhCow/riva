/*
 * riva_3d_brender.cpp - BRender v1.1.2 (Argonaut 1995/2022 MIT) & Attic 3D-Engine
 * fuer DSA 3: Schatten ueber Riva (Etappe 2a: 3D-Stadt/Dungeon).
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dsa_platform.h"

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef double longdouble;
typedef int8_t sbyte;

extern uint8_t riva_dgroup_base[];

typedef uint8_t undefined;
typedef uint8_t undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined3;
typedef int32_t undefined4;
typedef uint8_t byte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint32_t ulong;
typedef int64_t longlong;
typedef uint64_t ulonglong;
typedef int32_t int3;
typedef double float10;
typedef int code();
#define swi(x) ((code *)0)

#define CONCAT11(a, b) ((uint16_t)(((uint16_t)(uint8_t)(a) << 8) | (uint16_t)(uint8_t)(b)))
#define CONCAT12(a, b) ((uint32_t)(((uint32_t)(uint8_t)(a) << 16) | (uint32_t)(uint16_t)(b)))
#define CONCAT21(a, b) ((uint32_t)(((uint32_t)(uint16_t)(a) << 8) | (uint32_t)(uint8_t)(b)))
#define CONCAT22(a, b) ((uint32_t)(((uint32_t)(uint16_t)(a) << 16) | (uint32_t)(uint16_t)(b)))
#define CONCAT31(a, b) ((uint32_t)(((uint32_t)(a) << 8) | (uint32_t)(uint8_t)(b)))
#define CONCAT13(a, b) ((uint32_t)(((uint32_t)(uint8_t)(a) << 24) | ((uint32_t)(b) & 0xffffffu)))
#define CONCAT44(a, b) ((int64_t)(((uint64_t)(uint32_t)(a) << 32) | (uint64_t)(uint32_t)(b)))
#define SUB42(a, off) ((uint16_t)((uint32_t)(a) >> ((off) * 8)))
#define SUB41(a, off) ((uint8_t)((uint32_t)(a) >> ((off) * 8)))
#define ZEXT24(a) ((uint32_t)(uint16_t)(a))
#define SEXT24(a) ((int32_t)(int16_t)(a))
#define SBORROW4(a, b) (__builtin_sub_overflow_p((int32_t)(a), (int32_t)(b), (int32_t)0))
#define CARRY4(a, b) ((uint32_t)((uint32_t)(a) + (uint32_t)(b)) < (uint32_t)(a))
#define LOCK() do {} while (0)
#define UNLOCK() do {} while (0)

/* External functions from other units & CRT */
int f_144bf0(const char *s1, const char *s2);
void *f_145300(void *dst, int val, uint32_t len);
int f_14572e(char *buf, const char *fmt, ...);
char *f_148143(char *dst, const char *src, uint32_t n);
int f_149cd2(int a, void *b, void *c);
void *f_14d075(void *dst, const void *src, uint32_t len);
int f_150490(int a, int b);
int f_15149c(void);
int f_152870(int a);
int f_1537c0(void);
int f_153b40(int a, int b);
int f_154f00(int a);
int f_155934(void);
int f_155f70(void *a);
int f_156370(int size, const char *mod, const char *desc, int id);
void f_1563a8(int ptr);
int f_1563bc(void);
int f_1564cc(void);
void f_15666c(void);
void f_156698(void);
int f_156846(double v);
void *f_15e469(const char *path, const char *mode);
int f_15e836(void *fp, int flag);
int f_15ea0f(void *buf, int sz, int cnt, void *fp);
int f_15ead2(const char *buf, const char *fmt, ...);
void *f_15eaf3(uint32_t size);
void f_15ebd6(void *ptr);
int f_15f1dc(const char *s1, const char *s2, uint32_t n);
int f_15fdd5(void *fp, int off, int whence);
int f_165de2(void);
int f_17718c(int a);
int f_177260(void *sset);
int f_177910(const char *path, void *out, void *tmp);
void *f_177e30(const char *path);
void *f_1781c8(int type, int w, int h, void *pixels, int flags);
void f_1782e8(void *pm);
int f_179488(void *fp, void *buf, int len);
int f_1794a7(void *fp);
int f_17a891(int ch, void *fp);
void f_17a940(const char *name);
int f_17aaec(const char *name);
int f_15ea62(int c);
void f_166797(void *dst, int val, int dwords);
int f_17b260(void *mat);
int f_17b3c0(void);
int f_17b4b8(void);
int f_17b4d0(void *diag);
int f_17b4e0(void *fs);
int f_17b4f0(void *mem);
int f_17e4a0(void);
int f_1802f0(void);
int f_1803e4(int a);
void *f_195590(int type, int w, int h, void *pixels, int flags);
void *f_196810(int size, uint8_t type);
void f_196834(void *ptr);
uint32_t f_196840(uint8_t type);
int f_197308(const char *s, void *fp);
void f_197390(const char *fmt, ...);
void f_1973ec(const char *fmt, ...);
void f_197448(const char *fmt, int line, const char *msg, ...);
char *f_19749b(char *buf, int n, void *fp);
void f_197510(void *model, uint16_t flags);
void f_198c50(void *mat, uint16_t flags);
void f_198d18(void *pm, uint16_t flags);

/* DGROUP symbol mappings (base 0x1a0000) */
#define DAT_001d49a4 (*((int32_t *)(&riva_dgroup_base[0x349a4])))
#define DAT_001a9a34 (*((int32_t *)(&riva_dgroup_base[0x09a34])))
#define DAT_001a991c (*((int32_t *)(&riva_dgroup_base[0x0991c])))
#define DAT_001a9920 (*((int32_t *)(&riva_dgroup_base[0x09920])))
#define DAT_001a9928 (*((int32_t *)(&riva_dgroup_base[0x09928])))
#define DAT_001a992c (*((int32_t *)(&riva_dgroup_base[0x0992c])))
#define DAT_001a9931 (*((uint8_t *)(&riva_dgroup_base[0x09931])))
#define DAT_001a9932 (*((uint8_t *)(&riva_dgroup_base[0x09932])))
#define DAT_001a9933 (*((uint8_t *)(&riva_dgroup_base[0x09933])))
#define DAT_001a9936 (*((uint8_t *)(&riva_dgroup_base[0x09936])))
#define DAT_001a9937 (*((uint8_t *)(&riva_dgroup_base[0x09937])))
#define DAT_001a993c (*((uint8_t *)(&riva_dgroup_base[0x0993c])))
#define DAT_001a993d (*((uint8_t *)(&riva_dgroup_base[0x0993d])))
#define DAT_001a993f (*((uint8_t *)(&riva_dgroup_base[0x0993f])))
#define DAT_001a9940 (*((uint8_t *)(&riva_dgroup_base[0x09940])))
#define DAT_001a9941 (*((uint8_t *)(&riva_dgroup_base[0x09941])))
#define DAT_001a9942 (*((uint8_t *)(&riva_dgroup_base[0x09942])))
#define DAT_001a9944 (*((uint8_t *)(&riva_dgroup_base[0x09944])))
#define DAT_001a9945 (*((uint8_t *)(&riva_dgroup_base[0x09945])))
#define DAT_001a9948 (*((uint8_t *)(&riva_dgroup_base[0x09948])))
#define DAT_001a9949 (*((uint8_t *)(&riva_dgroup_base[0x09949])))
#define DAT_001a994a (*((uint8_t *)(&riva_dgroup_base[0x0994a])))
#define DAT_001a994b (*((uint8_t *)(&riva_dgroup_base[0x0994b])))
#define DAT_001a994c (*((uint8_t *)(&riva_dgroup_base[0x0994c])))
#define DAT_001a994d (*((uint8_t *)(&riva_dgroup_base[0x0994d])))
#define DAT_001a994e (*((uint8_t *)(&riva_dgroup_base[0x0994e])))
#define DAT_001a9950 (*((uint8_t *)(&riva_dgroup_base[0x09950])))
#define DAT_001a9951 (*((uint8_t *)(&riva_dgroup_base[0x09951])))
#define DAT_001a9952 (*((uint8_t *)(&riva_dgroup_base[0x09952])))
#define DAT_001a9953 (*((uint8_t *)(&riva_dgroup_base[0x09953])))
#define DAT_001a9954 (*((uint8_t *)(&riva_dgroup_base[0x09954])))
#define DAT_001a9955 (*((uint8_t *)(&riva_dgroup_base[0x09955])))
#define DAT_001a9956 (*((uint8_t *)(&riva_dgroup_base[0x09956])))
#define DAT_001a9957 (*((uint8_t *)(&riva_dgroup_base[0x09957])))
#define DAT_001a9958 (*((uint8_t *)(&riva_dgroup_base[0x09958])))
#define DAT_001a9959 (*((uint8_t *)(&riva_dgroup_base[0x09959])))
#define DAT_001a995a (*((uint8_t *)(&riva_dgroup_base[0x0995a])))
#define DAT_001a9962 (*((int16_t *)(&riva_dgroup_base[0x09962])))
#define DAT_001a9968 (*((int16_t *)(&riva_dgroup_base[0x09968])))
#define DAT_001a996a (*((int16_t *)(&riva_dgroup_base[0x0996a])))
#define DAT_001a9970 (*((int32_t *)(&riva_dgroup_base[0x09970])))
#define DAT_001a9974 (*((int32_t *)(&riva_dgroup_base[0x09974])))
#define DAT_001a9984 (*((int32_t *)(&riva_dgroup_base[0x09984])))
#define DAT_001a9988 (*((int32_t *)(&riva_dgroup_base[0x09988])))
#define DAT_001a998c (*((int32_t *)(&riva_dgroup_base[0x0998c])))
#define DAT_001a9990 (*((int32_t *)(&riva_dgroup_base[0x09990])))
#define DAT_001a999c (*((int32_t *)(&riva_dgroup_base[0x0999c])))
#define DAT_001a99ac (*((int32_t *)(&riva_dgroup_base[0x099ac])))
#define DAT_001a99b0 (*((int32_t *)(&riva_dgroup_base[0x099b0])))
#define DAT_001a99b8 (*((int32_t *)(&riva_dgroup_base[0x099b8])))
#define DAT_001a99bc (*((int32_t *)(&riva_dgroup_base[0x099bc])))
#define DAT_001a99c8 (*((int32_t *)(&riva_dgroup_base[0x099c8])))
#define DAT_001a99e8 (*((int32_t *)(&riva_dgroup_base[0x099e8])))
#define DAT_001a99ec (*((int32_t *)(&riva_dgroup_base[0x099ec])))
#define DAT_001a99f0 (*((int32_t *)(&riva_dgroup_base[0x099f0])))
#define DAT_001a99f8 (*((int32_t *)(&riva_dgroup_base[0x099f8])))
#define DAT_001a99fc (*((int32_t *)(&riva_dgroup_base[0x099fc])))
#define DAT_001a9a00 (*((int32_t *)(&riva_dgroup_base[0x09a00])))
#define DAT_001a9a08 (*((int32_t *)(&riva_dgroup_base[0x09a08])))
#define DAT_001a9a1c (*((int32_t *)(&riva_dgroup_base[0x09a1c])))
#define DAT_001a9a20 (*((int32_t *)(&riva_dgroup_base[0x09a20])))
#define DAT_001a9a24 (*((int32_t *)(&riva_dgroup_base[0x09a24])))
#define DAT_001a9a38 (*((int32_t *)(&riva_dgroup_base[0x09a38])))
#define DAT_001a9a40 (*((int32_t *)(&riva_dgroup_base[0x09a40])))
#define DAT_001a9a44 (*((int32_t *)(&riva_dgroup_base[0x09a44])))
#define DAT_001a9a4c (*((int32_t *)(&riva_dgroup_base[0x09a4c])))
#define DAT_001a9a60 (*((int32_t *)(&riva_dgroup_base[0x09a60])))
#define DAT_001a9a64 (*((int32_t *)(&riva_dgroup_base[0x09a64])))
#define DAT_001a9a68 (*((int32_t *)(&riva_dgroup_base[0x09a68])))
#define DAT_001a9a6c (*((int32_t *)(&riva_dgroup_base[0x09a6c])))
#define DAT_001a9a70 (*((int32_t *)(&riva_dgroup_base[0x09a70])))
#define DAT_001a9a88 (*((int32_t *)(&riva_dgroup_base[0x09a88])))
#define DAT_001a9a8c (*((int32_t *)(&riva_dgroup_base[0x09a8c])))
#define DAT_001a9ab8 (*((int32_t *)(&riva_dgroup_base[0x09ab8])))
#define DAT_001a9ae4 (*((int32_t *)(&riva_dgroup_base[0x09ae4])))
#define DAT_001a9aec (*((int32_t *)(&riva_dgroup_base[0x09aec])))
#define DAT_001a9af0 (*((int32_t *)(&riva_dgroup_base[0x09af0])))
#define DAT_001a9af8 (*((int32_t *)(&riva_dgroup_base[0x09af8])))
#define DAT_001a9b00 (*((int32_t *)(&riva_dgroup_base[0x09b00])))
#define DAT_001a9b08 (*((int32_t *)(&riva_dgroup_base[0x09b08])))
#define DAT_001a9b0c (*((int32_t *)(&riva_dgroup_base[0x09b0c])))
#define DAT_001a9b14 (*((int32_t *)(&riva_dgroup_base[0x09b14])))
#define DAT_001a9b18 (*((int32_t *)(&riva_dgroup_base[0x09b18])))
#define DAT_001a9b30 (*((int32_t *)(&riva_dgroup_base[0x09b30])))
#define DAT_001a9b34 (*((int32_t *)(&riva_dgroup_base[0x09b34])))
#define DAT_001a9b3c (*((int32_t *)(&riva_dgroup_base[0x09b3c])))
#define DAT_001a9b40 (*((int32_t *)(&riva_dgroup_base[0x09b40])))
#define DAT_001a9d20 (*((int32_t *)(&riva_dgroup_base[0x09d20])))
#define DAT_001a9d24 (*((int32_t *)(&riva_dgroup_base[0x09d24])))
#define DAT_001a9d28 (*((uint8_t *)(&riva_dgroup_base[0x09d28])))
#define DAT_001a9d2c (*((int32_t *)(&riva_dgroup_base[0x09d2c])))
#define DAT_001a9d34 (*((int32_t *)(&riva_dgroup_base[0x09d34])))
#define DAT_001aa8a8 (*((uint8_t *)(&riva_dgroup_base[0x0a8a8])))
#define DAT_001aa8a9 (*((uint8_t *)(&riva_dgroup_base[0x0a8a9])))
#define DAT_001aa8aa (*((uint8_t *)(&riva_dgroup_base[0x0a8aa])))
#define DAT_001aa8ab (*((uint8_t *)(&riva_dgroup_base[0x0a8ab])))
#define DAT_001ad9e3 (*((uint8_t *)(&riva_dgroup_base[0x0d9e3])))
#define DAT_001ad9e4 (*((uint8_t *)(&riva_dgroup_base[0x0d9e4])))
#define DAT_001ad9e6 (*((int32_t *)(&riva_dgroup_base[0x0d9e6])))
#define DAT_001ad9ea (*((int32_t *)(&riva_dgroup_base[0x0d9ea])))
#define DAT_001ad9ee (*((int32_t *)(&riva_dgroup_base[0x0d9ee])))
#define DAT_001ad9f2 (*((int32_t *)(&riva_dgroup_base[0x0d9f2])))
#define DAT_001ad9f6 (*((int32_t *)(&riva_dgroup_base[0x0d9f6])))
#define DAT_001ada02 (*((int32_t *)(&riva_dgroup_base[0x0da02])))
#define DAT_001ada06 (*((int32_t *)(&riva_dgroup_base[0x0da06])))
#define DAT_001aea34 (*((int32_t *)(&riva_dgroup_base[0x0ea34])))
#define DAT_001aea38 (*((int32_t *)(&riva_dgroup_base[0x0ea38])))
#define DAT_001aea3c (*((int32_t *)(&riva_dgroup_base[0x0ea3c])))
#define DAT_001aea40 (*((int32_t *)(&riva_dgroup_base[0x0ea40])))
#define DAT_001aea48 (*((uint8_t *)(&riva_dgroup_base[0x0ea48])))
#define DAT_001aea4c (*((int32_t *)(&riva_dgroup_base[0x0ea4c])))
#define DAT_001b4518 (*((int32_t *)(&riva_dgroup_base[0x14518])))
#define DAT_001b4a24 (*((uint8_t *)(&riva_dgroup_base[0x14a24])))
#define DAT_001b4a28 (*((uint8_t *)(&riva_dgroup_base[0x14a28])))
#define DAT_001b4f3c (*((uint8_t *)(&riva_dgroup_base[0x14f3c])))
#define DAT_001b4f79 (*((uint8_t *)(&riva_dgroup_base[0x14f79])))
#define DAT_001b4f7a (*((uint8_t *)(&riva_dgroup_base[0x14f7a])))
#define DAT_001b4f7b (*((uint8_t *)(&riva_dgroup_base[0x14f7b])))
#define DAT_001b9a40 (*((int32_t *)(&riva_dgroup_base[0x19a40])))
#define DAT_001c6c78 (*((int32_t *)(&riva_dgroup_base[0x26c78])))
#define DAT_001c6d68 (*((int32_t *)(&riva_dgroup_base[0x26d68])))
#define DAT_001c72f8 (*((int32_t *)(&riva_dgroup_base[0x272f8])))
#define DAT_001c90c0 (*((int32_t *)(&riva_dgroup_base[0x290c0])))
#define DAT_001c90c4 (*((int32_t *)(&riva_dgroup_base[0x290c4])))
#define DAT_001c90c8 (*((int32_t *)(&riva_dgroup_base[0x290c8])))
#define DAT_001c90cc (*((int32_t *)(&riva_dgroup_base[0x290cc])))
#define DAT_001c90d0 (*((int16_t *)(&riva_dgroup_base[0x290d0])))
#define DAT_001c90d2 (*((int16_t *)(&riva_dgroup_base[0x290d2])))
#define DAT_001c90d4 (*((int16_t *)(&riva_dgroup_base[0x290d4])))
#define DAT_001c90d8 (*((int32_t *)(&riva_dgroup_base[0x290d8])))
#define DAT_001c90e0 (*((int32_t *)(&riva_dgroup_base[0x290e0])))
#define DAT_001c90e4 (*((int32_t *)(&riva_dgroup_base[0x290e4])))
#define DAT_001c90e8 (*((int32_t *)(&riva_dgroup_base[0x290e8])))
#define DAT_001c90ec (*((int32_t *)(&riva_dgroup_base[0x290ec])))
#define DAT_001c90f0 (*((int32_t *)(&riva_dgroup_base[0x290f0])))
#define DAT_001c90f8 (*((int32_t *)(&riva_dgroup_base[0x290f8])))
#define DAT_001c9100 (*((int32_t *)(&riva_dgroup_base[0x29100])))
#define DAT_001c9330 (*((int32_t *)(&riva_dgroup_base[0x29330])))
#define DAT_001c9340 (*((int32_t *)(&riva_dgroup_base[0x29340])))
#define DAT_001c9344 (*((int32_t *)(&riva_dgroup_base[0x29344])))
#define DAT_001c9348 (*((int32_t *)(&riva_dgroup_base[0x29348])))
#define DAT_001c934c (*((int32_t *)(&riva_dgroup_base[0x2934c])))
#define DAT_001c9350 (*((int32_t *)(&riva_dgroup_base[0x29350])))
#define DAT_001c9354 (*((int32_t *)(&riva_dgroup_base[0x29354])))
#define DAT_001c9358 (*((uint8_t *)(&riva_dgroup_base[0x29358])))
#define DAT_001c9368 (*((int32_t *)(&riva_dgroup_base[0x29368])))
#define DAT_001c936c (*((int32_t *)(&riva_dgroup_base[0x2936c])))
#define DAT_001c9370 (*((int32_t *)(&riva_dgroup_base[0x29370])))
#define DAT_001c937c (*((int16_t *)(&riva_dgroup_base[0x2937c])))
#define DAT_001c9588 (*((int32_t *)(&riva_dgroup_base[0x29588])))
#define DAT_001c958c (*((int32_t *)(&riva_dgroup_base[0x2958c])))
#define DAT_001c9590 (*((int16_t *)(&riva_dgroup_base[0x29590])))
#define DAT_001c9594 (*((int32_t *)(&riva_dgroup_base[0x29594])))
#define DAT_001c9598 (*((int32_t *)(&riva_dgroup_base[0x29598])))
#define DAT_001cae88 (*((int32_t *)(&riva_dgroup_base[0x2ae88])))
#define DAT_001cae8c (*((int32_t *)(&riva_dgroup_base[0x2ae8c])))
#define DAT_001cae90 (*((int16_t *)(&riva_dgroup_base[0x2ae90])))
#define DAT_001cae94 (*((int32_t *)(&riva_dgroup_base[0x2ae94])))
#define DAT_001cae98 (*((int32_t *)(&riva_dgroup_base[0x2ae98])))
#define DAT_001cc7b8 (*((uint8_t *)(&riva_dgroup_base[0x2c7b8])))
#define DAT_001ccf38 (*((int16_t *)(&riva_dgroup_base[0x2cf38])))
#define DAT_001ccf5e (*((uint8_t *)(&riva_dgroup_base[0x2cf5e])))
#define DAT_001ccf60 (*((int16_t *)(&riva_dgroup_base[0x2cf60])))
#define DAT_001ccf62 (*((int16_t *)(&riva_dgroup_base[0x2cf62])))
#define DAT_001ccf88 (*((int32_t *)(&riva_dgroup_base[0x2cf88])))
#define DAT_001cd088 (*((uint8_t *)(&riva_dgroup_base[0x2d088])))
#define DAT_001cd0b0 (*((uint8_t *)(&riva_dgroup_base[0x2d0b0])))
#define DAT_001cd1b4 (*((int32_t *)(&riva_dgroup_base[0x2d1b4])))
#define DAT_001cd1e0 (*((int32_t *)(&riva_dgroup_base[0x2d1e0])))
#define DAT_001cd1e8 (*((int32_t *)(&riva_dgroup_base[0x2d1e8])))
#define DAT_001cd1ec (*((int32_t *)(&riva_dgroup_base[0x2d1ec])))
#define DAT_001cd1f8 (*((int32_t *)(&riva_dgroup_base[0x2d1f8])))
#define DAT_001cd204 (*((int32_t *)(&riva_dgroup_base[0x2d204])))
#define DAT_001cd210 (*((uint8_t * *)(&riva_dgroup_base[0x2d210])))
#define DAT_001cd21c (*((int32_t *)(&riva_dgroup_base[0x2d21c])))
#define DAT_001cd220 (*((int32_t *)(&riva_dgroup_base[0x2d220])))
#define DAT_001cd224 (*((int32_t *)(&riva_dgroup_base[0x2d224])))
#define DAT_001cd230 (*((int32_t *)(&riva_dgroup_base[0x2d230])))
#define DAT_001cd234 (*((int32_t *)(&riva_dgroup_base[0x2d234])))
#define DAT_001cd238 (*((int32_t *)(&riva_dgroup_base[0x2d238])))
#define DAT_001cd300 (*((int32_t *)(&riva_dgroup_base[0x2d300])))
#define DAT_001cd30c (*((int32_t *)(&riva_dgroup_base[0x2d30c])))
#define DAT_001cd314 (*((int32_t *)(&riva_dgroup_base[0x2d314])))
#define DAT_001cd318 (*((int32_t *)(&riva_dgroup_base[0x2d318])))
#define DAT_001cd31c (*((int32_t * *)(&riva_dgroup_base[0x2d31c])))
#define DAT_001cd320 (*((int32_t *)(&riva_dgroup_base[0x2d320])))
#define DAT_001cd324 (*((int32_t *)(&riva_dgroup_base[0x2d324])))
#define DAT_001cd334 (*((int32_t *)(&riva_dgroup_base[0x2d334])))
#define DAT_001cd338 (*((uint8_t *)(&riva_dgroup_base[0x2d338])))
#define DAT_001cdb08 (*((int32_t *)(&riva_dgroup_base[0x2db08])))
#define DAT_001cdb0c (*((int32_t *)(&riva_dgroup_base[0x2db0c])))
#define DAT_001cdb10 (*((int32_t *)(&riva_dgroup_base[0x2db10])))
#define DAT_001cdb14 (*((int32_t *)(&riva_dgroup_base[0x2db14])))
#define DAT_001cdb44 (*((int32_t *)(&riva_dgroup_base[0x2db44])))
#define DAT_001cdb48 (*((int32_t *)(&riva_dgroup_base[0x2db48])))
#define DAT_001cdb4c (*((int32_t *)(&riva_dgroup_base[0x2db4c])))
#define DAT_001cdb50 (*((int32_t *)(&riva_dgroup_base[0x2db50])))
#define DAT_001cdb54 (*((int32_t *)(&riva_dgroup_base[0x2db54])))
#define DAT_001cdb58 (*((int32_t *)(&riva_dgroup_base[0x2db58])))
#define DAT_001cdb5c (*((int32_t *)(&riva_dgroup_base[0x2db5c])))
#define DAT_001cdb60 (*((int32_t *)(&riva_dgroup_base[0x2db60])))
#define DAT_001cdb68 (*((int32_t *)(&riva_dgroup_base[0x2db68])))
#define DAT_001cdb6c (*((int32_t *)(&riva_dgroup_base[0x2db6c])))
#define DAT_001cdb70 (*((int32_t *)(&riva_dgroup_base[0x2db70])))
#define DAT_001cdb74 (*((int32_t *)(&riva_dgroup_base[0x2db74])))
#define DAT_001cdb94 (*((int32_t *)(&riva_dgroup_base[0x2db94])))
#define DAT_001cdc00 (*((int32_t *)(&riva_dgroup_base[0x2dc00])))
#define DAT_001cdc14 (*((int32_t *)(&riva_dgroup_base[0x2dc14])))
#define DAT_001cdc18 (*((int16_t *)(&riva_dgroup_base[0x2dc18])))
#define DAT_001cdc1a (*((int16_t *)(&riva_dgroup_base[0x2dc1a])))
#define DAT_001cdc1c (*((int16_t *)(&riva_dgroup_base[0x2dc1c])))
#define DAT_001cdc1e (*((int16_t *)(&riva_dgroup_base[0x2dc1e])))
#define DAT_001cdc20 (*((int16_t *)(&riva_dgroup_base[0x2dc20])))
#define DAT_001cdc22 (*((int16_t *)(&riva_dgroup_base[0x2dc22])))
#define DAT_001cdc24 (*((int16_t *)(&riva_dgroup_base[0x2dc24])))
#define DAT_001cdc26 (*((uint16_t *)(&riva_dgroup_base[0x2dc26])))
#define DAT_001cdc28 (*((uint16_t *)(&riva_dgroup_base[0x2dc28])))
#define DAT_001ce540 (*((int32_t *)(&riva_dgroup_base[0x2e540])))
#define DAT_001ce544 (*((uint8_t *)(&riva_dgroup_base[0x2e544])))
#define DAT_001ce548 (*((uint8_t *)(&riva_dgroup_base[0x2e548])))
#define DAT_001ce54c (*((uint8_t *)(&riva_dgroup_base[0x2e54c])))
#define DAT_001ce550 (*((uint8_t *)(&riva_dgroup_base[0x2e550])))
#define DAT_001ce5e4 (*((int32_t *)(&riva_dgroup_base[0x2e5e4])))
#define DAT_001ce5e8 (*((uint8_t * *)(&riva_dgroup_base[0x2e5e8])))
#define DAT_001ce5ec (*((int32_t *)(&riva_dgroup_base[0x2e5ec])))
#define DAT_001ce5f6 (*((uint8_t *)(&riva_dgroup_base[0x2e5f6])))
#define DAT_001ce5f8 (*((int32_t *)(&riva_dgroup_base[0x2e5f8])))
#define DAT_001ce5fc (*((int32_t *)(&riva_dgroup_base[0x2e5fc])))
#define DAT_001ce600 (*((int32_t *)(&riva_dgroup_base[0x2e600])))
#define DAT_001ce604 (*((int32_t *)(&riva_dgroup_base[0x2e604])))
#define DAT_001ce620 (*((int32_t *)(&riva_dgroup_base[0x2e620])))
#define DAT_001ce628 (*((int32_t *)(&riva_dgroup_base[0x2e628])))
#define DAT_001ce630 (*((int32_t *)(&riva_dgroup_base[0x2e630])))
#define DAT_001ce634 (*((int32_t *)(&riva_dgroup_base[0x2e634])))
#define DAT_001ce638 (*((int32_t *)(&riva_dgroup_base[0x2e638])))
#define DAT_001ce714 (*((int32_t *)(&riva_dgroup_base[0x2e714])))
#define DAT_001ce744 (*((int32_t *)(&riva_dgroup_base[0x2e744])))
#define DAT_001ce780 (*((uint8_t *)(&riva_dgroup_base[0x2e780])))
#define DAT_001ce784 (*((uint8_t *)(&riva_dgroup_base[0x2e784])))
#define DAT_001ce79c (*((uint8_t *)(&riva_dgroup_base[0x2e79c])))
#define DAT_001ce7b8 (*((int32_t *)(&riva_dgroup_base[0x2e7b8])))
#define DAT_001ce7bc (*((int32_t *)(&riva_dgroup_base[0x2e7bc])))
#define DAT_001ce7c0 (*((int32_t * *)(&riva_dgroup_base[0x2e7c0])))
#define DAT_001ce7c4 (*((int32_t *)(&riva_dgroup_base[0x2e7c4])))
#define DAT_001ce7c8 (*((int32_t *)(&riva_dgroup_base[0x2e7c8])))
#define DAT_001ce7cc (*((int32_t * *)(&riva_dgroup_base[0x2e7cc])))
#define DAT_001ce7d0 (*((int32_t *)(&riva_dgroup_base[0x2e7d0])))
#define DAT_001ce7d4 (*((int32_t *)(&riva_dgroup_base[0x2e7d4])))
#define DAT_001ce7d8 (*((uint8_t *)(&riva_dgroup_base[0x2e7d8])))
#define DAT_001ce7da (*((uint8_t *)(&riva_dgroup_base[0x2e7da])))
#define DAT_001ce7e6 (*((uint8_t *)(&riva_dgroup_base[0x2e7e6])))
#define DAT_001ce7f4 (*((int32_t *)(&riva_dgroup_base[0x2e7f4])))
#define DAT_001ce7f8 (*((uint8_t * *)(&riva_dgroup_base[0x2e7f8])))
#define DAT_001ce7fc (*((int32_t *)(&riva_dgroup_base[0x2e7fc])))
#define DAT_001ce800 (*((int16_t *)(&riva_dgroup_base[0x2e800])))
#define DAT_001ce802 (*((uint16_t *)(&riva_dgroup_base[0x2e802])))
#define DAT_001ce804 (*((uint8_t *)(&riva_dgroup_base[0x2e804])))
#define DAT_001ce805 (*((uint8_t *)(&riva_dgroup_base[0x2e805])))
#define DAT_001ce806 (*((uint8_t *)(&riva_dgroup_base[0x2e806])))
#define DAT_001ce807 (*((uint8_t *)(&riva_dgroup_base[0x2e807])))
#define DAT_001ce808 (*((uint8_t *)(&riva_dgroup_base[0x2e808])))
#define DAT_001ce810 (*((int32_t *)(&riva_dgroup_base[0x2e810])))
#define DAT_001ce900 (*((int32_t *)(&riva_dgroup_base[0x2e900])))
#define DAT_001ce904 (*((int32_t *)(&riva_dgroup_base[0x2e904])))
#define DAT_001ce908 (*((int32_t *)(&riva_dgroup_base[0x2e908])))
#define DAT_001ce90c (*((int32_t *)(&riva_dgroup_base[0x2e90c])))
#define DAT_001ce9a0 (*((int32_t *)(&riva_dgroup_base[0x2e9a0])))
#define DAT_001ce9a4 (*((int32_t *)(&riva_dgroup_base[0x2e9a4])))
#define DAT_001ce9a8 (*((int32_t *)(&riva_dgroup_base[0x2e9a8])))
#define DAT_001ce9ac (*((int32_t *)(&riva_dgroup_base[0x2e9ac])))
#define DAT_001cea40 (*((int32_t * *)(&riva_dgroup_base[0x2ea40])))
#define DAT_001cea48 (*((int32_t *)(&riva_dgroup_base[0x2ea48])))
#define DAT_001cea4c (*((int32_t *)(&riva_dgroup_base[0x2ea4c])))
#define DAT_001cea50 (*((uint8_t *)(&riva_dgroup_base[0x2ea50])))
#define DAT_001cea51 (*((uint8_t *)(&riva_dgroup_base[0x2ea51])))
#define DAT_001cea60 (*((int32_t *)(&riva_dgroup_base[0x2ea60])))
#define DAT_001cea64 (*((uint8_t *)(&riva_dgroup_base[0x2ea64])))
#define DAT_001d07b0 (*((int32_t *)(&riva_dgroup_base[0x307b0])))
#define DAT_001d07b4 (*((int32_t *)(&riva_dgroup_base[0x307b4])))
#define DAT_001d07b8 (*((int32_t *)(&riva_dgroup_base[0x307b8])))
#define DAT_001d07bc (*((int32_t *)(&riva_dgroup_base[0x307bc])))
#define DAT_001d07c0 (*((int32_t *)(&riva_dgroup_base[0x307c0])))
#define DAT_001d07c4 (*((int32_t *)(&riva_dgroup_base[0x307c4])))
#define DAT_001d07c8 (*((uint8_t *)(&riva_dgroup_base[0x307c8])))
#define DAT_001d07c9 (*((uint8_t *)(&riva_dgroup_base[0x307c9])))
#define DAT_001d118c (*((int32_t *)(&riva_dgroup_base[0x3118c])))
#define DAT_001d1190 (*((int32_t *)(&riva_dgroup_base[0x31190])))
#define DAT_001d1194 (*((int32_t *)(&riva_dgroup_base[0x31194])))
#define DAT_001d1198 (*((int32_t *)(&riva_dgroup_base[0x31198])))
#define DAT_001d119c (*((uint8_t * *)(&riva_dgroup_base[0x3119c])))
#define DAT_001d11a0 (*((int32_t *)(&riva_dgroup_base[0x311a0])))
#define DAT_001d11a4 (*((int32_t *)(&riva_dgroup_base[0x311a4])))
#define DAT_001d11a8 (*((int32_t *)(&riva_dgroup_base[0x311a8])))
#define DAT_001d11ac (*((int32_t *)(&riva_dgroup_base[0x311ac])))
#define DAT_001d11b0 (*((int32_t * *)(&riva_dgroup_base[0x311b0])))
#define DAT_001d11b4 (*((int32_t *)(&riva_dgroup_base[0x311b4])))
#define DAT_001d11b8 (*((int32_t *)(&riva_dgroup_base[0x311b8])))
#define DAT_001d11bc (*((int32_t *)(&riva_dgroup_base[0x311bc])))
#define DAT_001d11c0 (*((int32_t *)(&riva_dgroup_base[0x311c0])))
#define DAT_001d11c4 (*((int32_t *)(&riva_dgroup_base[0x311c4])))
#define DAT_001d11c8 (*((int32_t *)(&riva_dgroup_base[0x311c8])))
#define DAT_001d11cc (*((int32_t *)(&riva_dgroup_base[0x311cc])))
#define DAT_001d11d0 (*((uint8_t *)(&riva_dgroup_base[0x311d0])))
#define DAT_001d11f4 (*((int32_t *)(&riva_dgroup_base[0x311f4])))
#define DAT_001d11f8 (*((int32_t *)(&riva_dgroup_base[0x311f8])))
#define DAT_001d11fc (*((int32_t *)(&riva_dgroup_base[0x311fc])))
#define DAT_001d1200 (*((int32_t *)(&riva_dgroup_base[0x31200])))
#define DAT_001d1204 (*((int32_t * *)(&riva_dgroup_base[0x31204])))
#define DAT_001d1208 (*((int32_t *)(&riva_dgroup_base[0x31208])))
#define DAT_001d120c (*((int32_t *)(&riva_dgroup_base[0x3120c])))
#define DAT_001d1210 (*((int32_t *)(&riva_dgroup_base[0x31210])))
#define DAT_001d1214 (*((int32_t *)(&riva_dgroup_base[0x31214])))
#define DAT_001d1218 (*((uint8_t * *)(&riva_dgroup_base[0x31218])))
#define DAT_001d121c (*((int32_t *)(&riva_dgroup_base[0x3121c])))
#define DAT_001d1220 (*((int32_t *)(&riva_dgroup_base[0x31220])))
#define DAT_001d1224 (*((int32_t *)(&riva_dgroup_base[0x31224])))
#define DAT_001d1228 (*((int32_t *)(&riva_dgroup_base[0x31228])))
#define DAT_001d122c (*((uint8_t *)(&riva_dgroup_base[0x3122c])))
#define DAT_001d122d (*((uint8_t *)(&riva_dgroup_base[0x3122d])))
#define DAT_001d122e (*((uint8_t *)(&riva_dgroup_base[0x3122e])))
#define DAT_001d122f (*((uint8_t *)(&riva_dgroup_base[0x3122f])))
#define DAT_001d1230 (*((uint8_t *)(&riva_dgroup_base[0x31230])))
#define DAT_001d1231 (*((uint8_t *)(&riva_dgroup_base[0x31231])))
#define DAT_001d1234 (*((int32_t *)(&riva_dgroup_base[0x31234])))
#define DAT_001d452c (*((int32_t *)(&riva_dgroup_base[0x3452c])))
#define DAT_001d4540 (*((int32_t *)(&riva_dgroup_base[0x34540])))
#define DAT_001d4550 (*((int32_t *)(&riva_dgroup_base[0x34550])))
#define DAT_001d4554 (*((int32_t *)(&riva_dgroup_base[0x34554])))
#define DAT_001d4568 (*((int32_t *)(&riva_dgroup_base[0x34568])))
#define DAT_001d457c (*((int32_t *)(&riva_dgroup_base[0x3457c])))
#define DAT_001d458c (*((int32_t *)(&riva_dgroup_base[0x3458c])))
#define DAT_001d4590 (*((uint8_t *)(&riva_dgroup_base[0x34590])))
#define DAT_001d49b0 (*((int32_t *)(&riva_dgroup_base[0x349b0])))
#define DAT_001d49b8 (*((int32_t *)(&riva_dgroup_base[0x349b8])))
#define DAT_001d49f8 (*((int32_t *)(&riva_dgroup_base[0x349f8])))
#define PTR_DAT_001a9ac4 (*((int32_t *)(&riva_dgroup_base[0x09ac4])))
#define PTR_DAT_001a9ae0 (*((int32_t *)(&riva_dgroup_base[0x09ae0])))
#define PTR_DAT_001a9b2c (*((int32_t *)(&riva_dgroup_base[0x09b2c])))
#define PTR_DAT_001a9b38 (*((int32_t *)(&riva_dgroup_base[0x09b38])))
#define PTR_DAT_001ad4d4 (*((int32_t *)(&riva_dgroup_base[0x0d4d4])))
#define PTR_F_17594B_001aea50 (*((int32_t *)(&riva_dgroup_base[0x0ea50])))
#define PTR_F_181D47_001aea70 (*((int32_t *)(&riva_dgroup_base[0x0ea70])))
#define PTR_LAB_001a9afc (*((int32_t *)(&riva_dgroup_base[0x09afc])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 (*((int32_t *)(&riva_dgroup_base[0x09a74])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a78 (*((int32_t *)(&riva_dgroup_base[0x09a78])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a7c (*((int32_t *)(&riva_dgroup_base[0x09a7c])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a80 (*((int32_t *)(&riva_dgroup_base[0x09a80])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a84 (*((int32_t *)(&riva_dgroup_base[0x09a84])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a90 (*((int32_t *)(&riva_dgroup_base[0x09a90])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a94 (*((int32_t *)(&riva_dgroup_base[0x09a94])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a98 (*((int32_t *)(&riva_dgroup_base[0x09a98])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a9c (*((int32_t *)(&riva_dgroup_base[0x09a9c])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0 (*((int32_t *)(&riva_dgroup_base[0x09aa0])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4 (*((int32_t *)(&riva_dgroup_base[0x09aa4])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ab0 (*((int32_t *)(&riva_dgroup_base[0x09ab0])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ad4 (*((int32_t *)(&riva_dgroup_base[0x09ad4])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ad8 (*((int32_t *)(&riva_dgroup_base[0x09ad8])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc (*((int32_t *)(&riva_dgroup_base[0x09adc])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9b28 (*((int32_t *)(&riva_dgroup_base[0x09b28])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9d30 (*((int32_t *)(&riva_dgroup_base[0x09d30])))
#define PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20 (*((int32_t *)(&riva_dgroup_base[0x14a20])))
#define _DAT_001a996c (*((int32_t *)(&riva_dgroup_base[0x0996c])))
#define _DAT_001a9970 (*((int32_t *)(&riva_dgroup_base[0x09970])))
#define _DAT_001a99b4 (*((int32_t *)(&riva_dgroup_base[0x099b4])))
#define _DAT_001a99c0 (*((int32_t *)(&riva_dgroup_base[0x099c0])))
#define _DAT_001a99c4 (*((int32_t *)(&riva_dgroup_base[0x099c4])))
#define _DAT_001a99cc (*((int32_t *)(&riva_dgroup_base[0x099cc])))
#define _DAT_001a99d0 (*((int32_t *)(&riva_dgroup_base[0x099d0])))
#define _DAT_001a99d4 (*((int32_t *)(&riva_dgroup_base[0x099d4])))
#define _DAT_001a99d8 (*((int32_t *)(&riva_dgroup_base[0x099d8])))
#define _DAT_001a9a30 (*((int32_t *)(&riva_dgroup_base[0x09a30])))
#define _DAT_001a9a50 (*((int32_t *)(&riva_dgroup_base[0x09a50])))
#define _DAT_001a9a54 (*((int32_t *)(&riva_dgroup_base[0x09a54])))
#define _DAT_001a9a58 (*((int32_t *)(&riva_dgroup_base[0x09a58])))
#define _DAT_001a9ae8 (*((int32_t *)(&riva_dgroup_base[0x09ae8])))
#define _DAT_001aa8a8 (*((int32_t *)(&riva_dgroup_base[0x0a8a8])))
#define _DAT_001aea48 (*((uint8_t *)(&riva_dgroup_base[0x0ea48])))
#define _DAT_001b9a28 (*((double *)(&riva_dgroup_base[0x19a28])))
#define _DAT_001b9b25 (*((double *)(&riva_dgroup_base[0x19b25])))
#define _DAT_001c90fc (*((int32_t *)(&riva_dgroup_base[0x290fc])))
#define _DAT_001cc7b8 (*((int32_t *)(&riva_dgroup_base[0x2c7b8])))
#define _DAT_001ccf38 (*((int32_t *)(&riva_dgroup_base[0x2cf38])))
#define _DAT_001ccf3a (*((int16_t *)(&riva_dgroup_base[0x2cf3a])))
#define _DAT_001cdb64 (*((int32_t *)(&riva_dgroup_base[0x2db64])))
#define _DAT_001cdb90 (*((int32_t *)(&riva_dgroup_base[0x2db90])))
#define _DAT_001ce624 (*((int32_t *)(&riva_dgroup_base[0x2e624])))
#define _DAT_001ce62c (*((int32_t *)(&riva_dgroup_base[0x2e62c])))
#define _DAT_001ce63c (*((int32_t *)(&riva_dgroup_base[0x2e63c])))
#define _DAT_001cea44 (*((int32_t *)(&riva_dgroup_base[0x2ea44])))
#define s_FreeSceneryData__3DM_not_yet_ini_001b98c4 (*((char *)(&riva_dgroup_base[0x198c4])))
#define s_FreeSceneryData__No_Scenery_load_001b98f0 (*((char *)(&riva_dgroup_base[0x198f0])))
#define s_LoadScenery__3DM_not_yet_initial_001b9914 (*((char *)(&riva_dgroup_base[0x19914])))
#define s_LoadScenery__Directory_name_miss_001b9960 (*((char *)(&riva_dgroup_base[0x19960])))
#define s_LoadScenery__Scenery_already_loa_001b993c (*((char *)(&riva_dgroup_base[0x1993c])))
#define s_LoadScenery__Scenery_name_missin_001b9984 (*((char *)(&riva_dgroup_base[0x19984])))
#define s_ReleaseScenery__3DM_not_yet_init_001b99a8 (*((char *)(&riva_dgroup_base[0x199a8])))
#define s_ReleaseScenery__No_Scenery_loade_001b99d0 (*((char *)(&riva_dgroup_base[0x199d0])))
#define DAT_001a9924 (*((int32_t *)(&riva_dgroup_base[0x09924])))
#define DAT_001a996c (*((int32_t *)(&riva_dgroup_base[0x0996c])))
#define DAT_001a9994 (*((int32_t *)(&riva_dgroup_base[0x09994])))
#define DAT_001a9998 (*((int32_t *)(&riva_dgroup_base[0x09998])))
#define DAT_001a99b4 (*((int32_t *)(&riva_dgroup_base[0x099b4])))
#define DAT_001a99c0 (*((int32_t *)(&riva_dgroup_base[0x099c0])))
#define DAT_001a99c4 (*((int32_t *)(&riva_dgroup_base[0x099c4])))
#define DAT_001a99cc (*((int32_t *)(&riva_dgroup_base[0x099cc])))
#define DAT_001a99d0 (*((int32_t *)(&riva_dgroup_base[0x099d0])))
#define DAT_001a99d4 (*((int32_t *)(&riva_dgroup_base[0x099d4])))
#define DAT_001a99d8 (*((int32_t *)(&riva_dgroup_base[0x099d8])))
#define DAT_001a9a30 (*((int32_t *)(&riva_dgroup_base[0x09a30])))
#define DAT_001a9a3c (*((int32_t *)(&riva_dgroup_base[0x09a3c])))
#define DAT_001a9a48 (*((int32_t *)(&riva_dgroup_base[0x09a48])))
#define DAT_001a9a50 (*((int32_t *)(&riva_dgroup_base[0x09a50])))
#define DAT_001a9a54 (*((int32_t *)(&riva_dgroup_base[0x09a54])))
#define DAT_001a9a58 (*((int32_t *)(&riva_dgroup_base[0x09a58])))
#define DAT_001a9a5c (*((int32_t *)(&riva_dgroup_base[0x09a5c])))
#define DAT_001a9ad4 (*((int32_t *)(&riva_dgroup_base[0x09ad4])))
#define DAT_001a9ad8 (*((int32_t *)(&riva_dgroup_base[0x09ad8])))
#define DAT_001a9adc (*((int32_t *)(&riva_dgroup_base[0x09adc])))
#define DAT_001ad9e0 (*((uint8_t *)(&riva_dgroup_base[0x0d9e0])))
#define DAT_001ad9e1 (*((uint8_t *)(&riva_dgroup_base[0x0d9e1])))
#define DAT_001ad9e2 (*((uint8_t *)(&riva_dgroup_base[0x0d9e2])))
#define DAT_001ad9e5 (*((uint8_t *)(&riva_dgroup_base[0x0d9e5])))
#define DAT_001ad9fa (*((int32_t *)(&riva_dgroup_base[0x0d9fa])))
#define DAT_001ad9fe (*((int32_t *)(&riva_dgroup_base[0x0d9fe])))
#define DAT_001ada22 (*((int16_t *)(&riva_dgroup_base[0x0da22])))
#define DAT_001ada24 (*((int16_t *)(&riva_dgroup_base[0x0da24])))
#define DAT_001ada28 (*((int32_t *)(&riva_dgroup_base[0x0da28])))
#define DAT_001ada30 (*((int16_t * *)(&riva_dgroup_base[0x0da30])))
#define DAT_001ada34 (*((int32_t *)(&riva_dgroup_base[0x0da34])))
#define DAT_001ada38 (*((int32_t *)(&riva_dgroup_base[0x0da38])))
#define DAT_001ada3c (*((int32_t *)(&riva_dgroup_base[0x0da3c])))
#define DAT_001ada40 (*((int32_t *)(&riva_dgroup_base[0x0da40])))
#define DAT_001ada4c (*((int32_t *)(&riva_dgroup_base[0x0da4c])))
#define DAT_001add6c (*((int32_t *)(&riva_dgroup_base[0x0dd6c])))
#define DAT_001c6b20 (*((int32_t *)(&riva_dgroup_base[0x26b20])))
#define DAT_001c76f8 (*((uint8_t *)(&riva_dgroup_base[0x276f8])))
#define DAT_001ccf3a (*((int16_t *)(&riva_dgroup_base[0x2cf3a])))
#define DAT_001ccf3c (*((int16_t *)(&riva_dgroup_base[0x2cf3c])))
#define DAT_001cd1d4 (*((int32_t *)(&riva_dgroup_base[0x2d1d4])))
#define DAT_001cd1d8 (*((int32_t *)(&riva_dgroup_base[0x2d1d8])))
#define DAT_001cd1dc (*((int32_t *)(&riva_dgroup_base[0x2d1dc])))
#define DAT_001cd1e4 (*((int32_t *)(&riva_dgroup_base[0x2d1e4])))
#define DAT_001cd1f0 (*((int32_t *)(&riva_dgroup_base[0x2d1f0])))
#define DAT_001cd1f4 (*((int32_t *)(&riva_dgroup_base[0x2d1f4])))
#define DAT_001cd1fc (*((int32_t *)(&riva_dgroup_base[0x2d1fc])))
#define DAT_001cd200 (*((int32_t *)(&riva_dgroup_base[0x2d200])))
#define DAT_001cd248 (*((int32_t *)(&riva_dgroup_base[0x2d248])))
#define DAT_001cd250 (*((int32_t *)(&riva_dgroup_base[0x2d250])))
#define DAT_001cd254 (*((int32_t *)(&riva_dgroup_base[0x2d254])))
#define DAT_001cd258 (*((uint16_t *)(&riva_dgroup_base[0x2d258])))
#define DAT_001cd25a (*((uint8_t *)(&riva_dgroup_base[0x2d25a])))
#define DAT_001cd2a0 (*((int32_t *)(&riva_dgroup_base[0x2d2a0])))
#define DAT_001cd2a4 (*((int32_t *)(&riva_dgroup_base[0x2d2a4])))
#define DAT_001cd2ac (*((int32_t *)(&riva_dgroup_base[0x2d2ac])))
#define DAT_001cd2b4 (*((uint16_t *)(&riva_dgroup_base[0x2d2b4])))
#define DAT_001cd2b6 (*((uint8_t *)(&riva_dgroup_base[0x2d2b6])))
#define DAT_001cd2b8 (*((int32_t *)(&riva_dgroup_base[0x2d2b8])))
#define DAT_001cd2fc (*((int32_t *)(&riva_dgroup_base[0x2d2fc])))
#define DAT_001cdb78 (*((int32_t *)(&riva_dgroup_base[0x2db78])))
#define DAT_001cdb7c (*((int32_t *)(&riva_dgroup_base[0x2db7c])))
#define DAT_001cdb80 (*((int32_t *)(&riva_dgroup_base[0x2db80])))
#define DAT_001cdb84 (*((int32_t *)(&riva_dgroup_base[0x2db84])))
#define DAT_001cdb8c (*((int32_t *)(&riva_dgroup_base[0x2db8c])))
#define DAT_001cdb90 (*((int32_t *)(&riva_dgroup_base[0x2db90])))


#define DAT_001a9918 (*((int32_t *)(&riva_dgroup_base[0x09918])))
#define DAT_001a993e (*((uint8_t *)(&riva_dgroup_base[0x0993e])))
#define DAT_001a9a94 (*((int32_t *)(&riva_dgroup_base[0x09a94])))
#define DAT_001a9a98 (*((int32_t *)(&riva_dgroup_base[0x09a98])))
#define DAT_001a9d64 (*((int32_t *)(&riva_dgroup_base[0x09d64])))
#define DAT_001a9d68 (*((int32_t *)(&riva_dgroup_base[0x09d68])))

#define DAT_001cd308 (*((int32_t *)(&riva_dgroup_base[0x2d308])))
#define DAT_001cd310 (*((int32_t *)(&riva_dgroup_base[0x2d310])))
#define in(port) ((uint8_t)0)
#define out(port, val) ((void)0)
/* Forward declarations */
bool f_187b30(byte *p1,byte *p2);
int f_187bdc(int p1);
undefined4 * f_187bf0(undefined4 *p1);
undefined4 f_187c18(int p1,undefined4 p2);
int f_187c4c(int p1,undefined4 *p2,int p3);
int f_187ca0(undefined4 *p1,int p2);
int f_187ce0(undefined4 p1,undefined4 *p2,int p3);
int f_187d10(undefined4 *p1,undefined4 p2);
int f_187d54(undefined4 *p1,undefined4 p2,int *p3,int p4);
int f_187d94(undefined4 *p1,int p2);
int f_187dcc(int p1,int p2,code *p3,undefined4 p4);
void f_187e30(int *p1);
void f_187e44(int *p1,int *p2);
void f_187ea0(undefined4 p1,int *p2,int *p3);
void f_187eb0(int *p1);
void f_187ec4(undefined4 *p1);
void f_187ecc(int *p1,int *p2);
int *f_187f2c(int *p1);
void f_187f7c(uint *p1,ushort *p2);
void f_188260(undefined4 p1,short *p2);
void f_1882cc(ushort *p1,undefined4 *p2);
uint f_1883e0(int p1);
uint f_188404(int p1,int p2,undefined4 p3);
void f_18850c(int p1);
int f_188580(int p1);
int f_1885c8(int p1);
undefined4 f_188630(int p1);
char * f_188664(undefined4 p1,char *p2);
int f_188c94(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9);
int f_188d48(int *p1);
void f_188ec4(undefined4 *p1,undefined4 *p2);
void f_189284(undefined4 *p1,uint p2,int p3,int p4,int p5);
void f_1896c0(int *p1,int *p2,int *p3);
void f_189900(int *p1,int *p2,int *p3);
void f_189a0c(undefined4 *p1,undefined4 *p2);
void f_189a74(int *p1,int *p2);
uint * f_195940(uint *p1,int *p2);
int * f_195bbc(int *p1,int *p2);
uint * f_195ce8(uint *p1,int *p2);
undefined4 f_195ec0(undefined4 p1,undefined4 p2);
void f_195ee0(undefined4 p1,undefined4 p2);
int f_195f00(int p1,ushort *p2,undefined4 p3,undefined4 p4);
short * f_196280(short *p1,int p2);
undefined4 f_1964f0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_196510(undefined4 p1,undefined4 p2);
void f_18efb0(undefined4 p1);
void f_18efc0(undefined4 p1,undefined4 p2,undefined4 p3);
void f_18f010(undefined4 p1);
undefined4 f_18f020(undefined4 p1);
int f_18f030(int *p1,int p2);
void f_18f0b0(undefined4 p1,undefined4 p2,undefined4 p3);
void f_18f150(undefined4 p1,undefined4 p2,undefined4 p3);
void f_18f1f0(undefined4 p1,undefined4 p2,undefined4 p3);
int f_18f228(int p1);
void f_18f280(undefined4 p1);
undefined4 f_18f290(undefined4 p1);
int f_18f2a0(int *p1,int p2);
int f_18f2e0(int *p1,int p2);
undefined4 * f_18f560(int p1,int p2,int p3,undefined4 *p4);
undefined4 * f_18f710(int p1,int p2,int p3);
undefined4 * f_18f780(int p1);
void f_16b5c0(undefined4 *p1,undefined4 *p2);
void f_16b60c(int *p1,int *p2,int *p3);
void f_16b930(undefined4 *p1);
void f_16b984(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16b9f4(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16ba64(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16bad4(int *p1,uint p2,int *p3,undefined4 p4);
void f_16bc24(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16bc6c(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16bcb4(undefined4 *p1,undefined4 p2,undefined4 p3);
void f_16bd00(undefined4 *p1,undefined4 p2,undefined4 p3);
void f_16bd4c(undefined4 *p1,undefined4 p2,undefined4 p3);
int f_16bd98(uint *p1,int *p2);
void f_16c138(int *p1,int *p2);
void f_16c24c(uint *p1,int p2);
void f_16c544(undefined4 *p1,undefined4 *p2);
void f_16c590(int *p1,short *p2,int *p3,undefined4 p4);
void f_16c73c(int *p1,int *p2,int *p3);
void f_16c810(int *p1,int *p2,int *p3);
void f_16caa0(int *p1,int *p2,int *p3);
void f_16cb64(undefined4 p1,undefined4 p2);
void f_16cb84(undefined4 p1,undefined4 p2);
void f_16cbdc(undefined4 p1,uint p2);
void f_16cc10(undefined4 p1,uint p2,undefined4 p3);
void f_16cc44(undefined4 p1,uint p2);
void f_16ccac(undefined4 p1,uint p2);
void f_16cce0(undefined4 p1,uint p2,undefined4 p3);
void f_16cd48(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16cd74(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16cda0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_16ce50(undefined4 p1,undefined4 p2,undefined4 p3);
ushort f_16cf00(undefined4 p1);
undefined4 f_16cf05(undefined4 p1);
void f_16cf6a(int *p1,int *p2,int *p3);
void f_16cff5(int *p1,int *p2,int *p3);
void f_16d077(int *p1,int *p2,int *p3);
void f_16e060(int p1);
void f_16e080(int p1,undefined4 p2,undefined4 p3);
void f_16e660(int p1,undefined4 p2);
void f_16e680(int p1,undefined4 p2,undefined4 p3,undefined4 p4,undefined4 p5,undefined4 p6);
void f_16e93c(int p1,int p2,undefined4 p3,undefined4 p4,byte *p5,byte *p6);
void f_16ecb4(undefined4 p1);
void f_16ecba(undefined4 p1);
int f_16ecc0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
uint f_16f830(undefined4 p1,undefined4 p2,uint p3,int p4);
void f_16f867(undefined4 p1,undefined4 p2,undefined4 p3,uint p4);
void f_16f992(undefined4 p1,uint p2,int p3,int p4);
undefined4 f_16fc50(int p1);
void f_16ff04(int p1);
undefined4 f_16ff84(byte *p1);
undefined4 f_17004c(int p1,undefined4 p2,ushort *p3);
undefined2 f_1702b8(char *p1);
undefined4 f_1707f8(short *p1,ushort *p2);
undefined4 f_1708f4(int *p1,int *p2,ushort *p3,short *p4);
undefined4 f_170af4(ushort *p1,ushort *p2);
int f_170cb8(int p1);
uint f_170e84(int p1,uint p2);
undefined4 f_171000(int p1,uint p2);
bool f_171180(int p1,int p2,int p3);
undefined4 f_171994(short *p1,short *p2);
uint f_1719e4(int p1,int p2);
bool f_171c20(int p1,int p2);
int f_171f14(int p1,int p2);
void f_172028(int p1,int p2);
undefined4 f_172148(int p1,int p2);
void f_172278(void);
void f_17228c(void);
uint f_1722b0(undefined4 p1);
undefined1 f_172378(int p1,int p2);
int f_1724d8(int p1,int p2);
int f_172628(int p1);
void f_17272c(undefined4 p1);
undefined1 * f_172870(int p1);
void f_1728f0(void);
void f_172bdc(int p1);
undefined4 f_173290(void);
void f_173374(void);
int f_1735c4(undefined4 p1,int *p2);
void f_1737c4(int in_EAX);
undefined4 f_1739e8(int p1,undefined4 p2,undefined4 p3,undefined4 p4);
void f_173d0c(undefined4 p1);
void f_17410c(void);
bool f_174158(int p1,int p2,int p3,int p4);
void f_1744c8(int p1,uint p2,int p3,uint p4);
void f_17464c(ushort *p1);
undefined1 f_176891(void);
undefined1 f_1768a2(undefined4 p1,undefined4 p2);
int f_1768b3(undefined4 p1,undefined4 p2);
undefined4 f_1768d5(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
short f_1769c0(undefined4 p1,undefined4 p2,undefined4 p3);
undefined4 f_1769e0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4);
int f_176a38(int p1,char *p2,undefined4 *p3,int p4);
void f_176b18(int p1,int p2);
int f_176b3c(int p1,int p2);
int f_176b90(int p1);
void f_176d78(int p1);
void f_176da0(int p1);
undefined4 f_176e24(undefined4 p1,int p2);
undefined4 f_15ffa0(char *p1);
undefined4 f_15fffc(undefined4 *p1,int *p2);
undefined4 f_160320(int p1);
undefined4 f_160e94(undefined4 *p1);
undefined4 f_161230(int p1);
undefined4 f_161e84(int in_EAX);
int f_161fd8(char *p1,char *p2,char *unaff_EBX,int unaff_CL);
undefined4 f_162208(void);
undefined4 f_1622c0(int p1);
undefined4 f_16232c(undefined4 p1);
undefined4 f_16238c(undefined4 p1,undefined4 p2,undefined4 p3);
undefined4 f_1624b4(undefined4 p1);
void f_1625f4(void);
void f_1629a8(void);
void f_162a4c(int p1,int p2);
void f_162b10(undefined4 p1);
byte f_162b38(int p1,int p2,int p3,byte *p4);
void f_162db8(undefined4 p1,undefined4 p2,int p3,int *p4);
void f_163050(undefined4 p1);
void f_1630ac(void);
void f_1633a0(void);
void f_1633c0(void);
int f_163504(int p1,undefined4 p2,int unaff_EBX);
undefined4 f_163a98(undefined4 p1);
undefined2 f_163ad0(int p1);
void f_163b08(int p1,undefined4 p2);
void f_163bac(int p1,undefined4 p2);
undefined4 f_163bf8(int p1,int p2,int p3,int p4);
int f_163d48(undefined4 p1);
void f_163e30(void);
void f_164408(void);
undefined4 f_164660(void);
longdouble f_164870(void);
undefined4 f_164880(int p1,int p2,int p3,int p4);
undefined4 f_164cf0(void);
void f_164d04(undefined4 *p1);
void f_164e64(ushort *p1,int p2);

/* =========================================================================
 * Handwritten C implementations for BRender v1.1.2 ASM & Attic 3D routines
 * ========================================================================= */

/* --- 1. brstddiag.c, brstdfile.c & brstdmem.c (0x18e380..0x18e7c0) --- */
void f_18e380(const char *message) {
    (void)message;
}

void f_18e3b8(const char *message) {
    (void)message;
}

uint32_t f_18e400(void) { return 3; }

void *f_18e408(const char *name, uint32_t n_magics, int (*identify)(void *, uint32_t), int *mode_result) {
    int mode = mode_result ? *mode_result : 0;
    void *fp = f_15e469(name, "rb");
    if (!fp) return 0;
    if (n_magics != 0) {
        uint8_t magics[32];
        memset(magics, 0, sizeof(magics));
        uint32_t to_read = n_magics < 32 ? n_magics : 32;
        if ((uint32_t)f_15e65b(magics, 1, (int)to_read, fp) != to_read) {
            f_15e836(fp, 0);
            return 0;
        }
        if (identify) mode = identify(magics, n_magics);
        if (mode_result) *mode_result = mode;
    }
    f_15e836(fp, 0);
    if (mode == 2) return 0;
    return f_15e469(name, (mode == 1) ? "rt" : "rb");
}

void *f_18e60c(const char *name, int mode) {
    return f_15e469(name, (mode == 0) ? "wb" : "wt");
}

void f_18e628(void *f) {
    if (f) f_15e836(f, 1);
}

int f_18e630(void *f) {
    if (!f) return 1;
    return ((((uint8_t *)f)[12] & 0x10) != 0) || ((((uint8_t *)f)[13] & 0x10) != 0);
}

int f_18e638(void *f) {
    return f ? f_1794a7(f) : -1;
}

int f_18e678(int c, void *f) {
    return f ? f_17a891(c, f) : -1;
}

char *f_19749b(char *buf, int n, void *fp) {
    if (!buf || n <= 0 || !fp) return 0;
    int i = 0;
    while (i < n - 1) {
        int ch = f_1794a7(fp);
        if (ch < 0 || ch == 255) {
            if (i == 0) return 0;
            break;
        }
        buf[i++] = (char)ch;
        if (ch == '\n') break;
    }
    buf[i] = '\0';
    return buf;
}

int f_18e6c8(void *buf, int size, unsigned int n, void *f) {
    if (!f || !buf || size <= 0 || n == 0) return 0;
    return f_15e65b(buf, size, (int)n, f);
}

int f_18e6d0(void *buf, int size, unsigned int n, void *f) {
    if (!f || !buf || size <= 0 || n == 0) return 0;
    return f_15ea0f(buf, size, (int)n, f);
}

int f_18e6d8(char *buf, uint32_t max_len, void *f) {
    if (!f || !buf || max_len == 0) return 0;
    if (!f_19749b(buf, (int)max_len, f)) return 0;
    uint32_t l = (uint32_t)strlen(buf);
    if (l > 0 && buf[l - 1] == '\n') buf[--l] = '\0';
    return (int)l;
}

void f_18e714(const char *buf, void *f) {
    if (f && buf) {
        f_197308(buf, f);
        f_17a891('\n', f);
    }
}

void f_18e774(int count, void *f) {
    if (f) f_15fdd5(f, count, 1);
}

void *f_18e790(uint32_t size, uint8_t type) {
    (void)type;
    void *p = f_15eaf3(size > 0 ? size : 4);
    if (p && size > 0) memset(p, 0, size);
    return p;
}

void f_18e7b8(void *mem) {
    if (mem) f_15ebd6(mem);
}

uint32_t f_18e7c0(uint8_t type) {
    (void)type;
    return 4;
}

int f_18ef00(void *p1) {
    f_197510(p1, 0x7fff);
    return f_187c18(&DAT_001d452c, (int)(uintptr_t)p1);
}

int f_18f100(void *p1) {
    return f_187c18(&DAT_001d4554, (int)(uintptr_t)p1);
}

void *f_196810(int size, uint8_t type) {
    void *ptr = 0;
    if (DAT_001d49a4 != 0 && *(void **)(DAT_001d49a4 + 4) != 0) {
        ptr = ((void *(*)(int, uint8_t))(*(void **)(DAT_001d49a4 + 4)))(size, type);
    } else {
        ptr = f_15eaf3(size > 0 ? size : 4);
    }
    if (ptr && size > 0) memset(ptr, 0, size);
    return ptr;
}

void f_196834(void *ptr) {
    if (!ptr) return;
    if (DAT_001d49a4 != 0 && *(void **)(DAT_001d49a4 + 8) != 0) {
        ((void (*)(void *))(*(void **)(DAT_001d49a4 + 8)))(ptr);
    } else {
        f_15ebd6(ptr);
    }
}

uint32_t f_196840(uint8_t type) {
    if (DAT_001d49a4 != 0 && *(void **)(DAT_001d49a4 + 12) != 0) {
        return ((uint32_t (*)(uint8_t))(*(void **)(DAT_001d49a4 + 12)))(type);
    }
    return 4;
}

/* --- 2. memloops.asm (0x18e7c4..0x18eebb) --- */
static inline void write_bpp(uint8_t *dst, uint32_t bpp, uint32_t c) {
    if (bpp == 1) {
        *dst = (uint8_t)c;
    } else if (bpp == 2) {
        *(uint16_t *)dst = (uint16_t)c;
    } else if (bpp == 3) {
        dst[0] = (uint8_t)c;
        dst[1] = (uint8_t)(c >> 8);
        dst[2] = (uint8_t)(c >> 16);
    } else if (bpp >= 4) {
        *(uint32_t *)dst = c;
    }
}

void f_18e7c4(char *d, int p2, uint32_t ds, char *s, int p5, uint32_t ss, uint32_t bw, uint32_t h) {
    for (uint32_t y = 0; y < h; y++) {
        memcpy(d + y * ds, s + y * ss, bw);
    }
}

void f_18ebb4(char *d, int p2, uint32_t ds, uint32_t w, uint32_t h, uint32_t bpp, uint32_t c) {
    for (uint32_t y = 0; y < h; y++) {
        uint8_t *row = (uint8_t *)(d + y * ds);
        if (bpp == 1) {
            memset(row, (uint8_t)c, w);
        } else {
            for (uint32_t x = 0; x < w; x++) write_bpp(row + x * bpp, bpp, c);
        }
    }
}

void f_18ec98(char *d, int p2, uint32_t ds, uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, char *s, int p9, uint32_t ss, uint32_t bpp, uint32_t c) {
    for (uint32_t y = 0; y < h; y++) {
        const uint8_t *srow = (const uint8_t *)(s + y * ss);
        uint8_t *drow = (uint8_t *)(d + (y0 + y) * ds + x0 * bpp);
        for (uint32_t x = 0; x < w; x++) {
            uint8_t mask = srow[(x0 + x) >> 3];
            if (mask & (0x80u >> ((x0 + x) & 7))) {
                write_bpp(drow + x * bpp, bpp, c);
            }
        }
    }
}

void f_18edc1(char *d, int p2, uint32_t n, uint32_t bpp, uint32_t c) {
    if (bpp == 1) {
        memset(d, (uint8_t)c, n);
    } else {
        for (uint32_t i = 0; i < n; i++) write_bpp((uint8_t *)d + i * bpp, bpp, c);
    }
}

/* Original: Pixelanzahl mal Bytes je Pixel, sechs Stackargumente. */
void f_18ee19(char *d, int p2, char *s, int p4, uint32_t n, uint32_t bpp) {
    memcpy(d, s, (size_t)n * bpp);
}

void f_18ee5e(char *d, int p2, uint32_t bpp, uint32_t c) {
    write_bpp((uint8_t *)d, bpp, c);
}

/* Original 18eebb: mov ax,ds; ret. Kein Pixelzugriff und keine Parameter.
 * Alle nativen Speicherhelfer verwenden flache Zeiger und ignorieren den
 * DOS-Segmentselektor. Null ist hier der entsprechende neutrale Wert. */
uint32_t f_18eebb(void) {
    return 0;
}

/* --- 3. resource.c BrResInternalFree (0x188490) --- */
int *f_187f2c(int *p1);
int f_188490(int p1) {
    if (!p1) return 0;
    uint8_t b = *(uint8_t *)(p1 + 1);
    if (b != 0x7e) {
        *(uint8_t *)(p1 + 1) = 0x7e;
        void *cls = *(void **)(&riva_dgroup_base[(0x1d4590 - 0x1a0000) + (uint32_t)b * 4]);
        if (cls) {
            void (*dtor)(void *, void *, uint8_t) = *(void (**)(void *, void *, uint8_t))((char *)cls + 8);
            if (dtor) dtor((void *)(p1 + 0x10), *(void **)((char *)cls + 4), b);
        }
        while (*(int *)(p1 + 4) != 0) {
            int child = *(int *)(p1 + 4);
            f_187f2c((int *)child);
            f_188490(child);
        }
        if (*(int *)(p1 + 8) != 0) {
            f_187f2c((int *)(p1 + 8));
        }
        *(uint8_t *)(p1 + 1) = 0;
        *(uint8_t *)p1 = 1;
        f_196834((void *)p1);
    }
    return p1;
}

/* --- 4. fixed386.asm & Attic math helpers (0x16d295..0x16e00c) --- */
int *f_16d295(int *dst, const int *src, int count) {
    int32_t aa0 = *(int32_t *)(&riva_dgroup_base[0x09aa0]);
    int32_t aa4 = *(int32_t *)(&riva_dgroup_base[0x09aa4]);
    while (--count >= 0) {
        int32_t z = src[2];
        if (z != 0) {
            dst[0] = (int32_t)(((int64_t)src[0] * aa0) / z);
            dst[1] = (int32_t)(((int64_t)src[1] * aa4) / z);
        } else {
            dst[0] = 0;
            dst[1] = 0;
        }
        src += 3;
        dst += 2;
    }
    return dst;
}

int f_16d2b1(const int *a, const int *b) {
    return (int)(((int64_t)a[0] * b[0] + (int64_t)a[1] * b[1] + (int64_t)a[2] * b[2]) >> 16);
}

int f_16d2c9(const int *v) {
    int flags = 0;
    int32_t x = v[0], y = v[1], z = v[2];
    int32_t a90 = *(int32_t *)(&riva_dgroup_base[0x09a90]);
    int32_t a94 = *(int32_t *)(&riva_dgroup_base[0x09a94]);
    int32_t a98 = *(int32_t *)(&riva_dgroup_base[0x09a98]);
    int32_t a9c = *(int32_t *)(&riva_dgroup_base[0x09a9c]);
    int32_t ad8 = *(int32_t *)(&riva_dgroup_base[0x09ad8]);
    int32_t adc = *(int32_t *)(&riva_dgroup_base[0x09adc]);
    if ((int32_t)(((int64_t)a90 * z) >> 16) < x) flags |= 0x02;
    if ((int32_t)(((int64_t)a94 * z) >> 16) > x) flags |= 0x01;
    if ((int32_t)(((int64_t)a9c * z) >> 16) > y) flags |= 0x08;
    if ((int32_t)(((int64_t)a98 * z) >> 16) < y) flags |= 0x04;
    int32_t nz = -z;
    if (nz < ad8) flags |= 0x10;
    else if (nz > adc) flags |= 0x20;
    return flags;
}

int f_16d305(int a, int b) {
    return (int)(((int64_t)a * b) >> 16);
}

int f_16d31c(int a, int b) {
    if (b == 0) return 0;
    return (int)(((int64_t)a << 16) / b);
}

int f_16d32f(int a, int b, int c) {
    if (c == 0) return 0;
    return (int)(((int64_t)a * b) / c);
}

int f_16d33f(int a, int b, int c, int d) {
    return (int)(((int64_t)a * b + (int64_t)c * d) >> 16);
}

int f_16d34f(int a, int b, int c, int d) {
    return (int)(((int64_t)a * b - (int64_t)c * d) >> 16);
}

int f_16d361(const int *a, const int *b) {
    return (int)(((int64_t)a[0] * b[0] + (int64_t)a[1] * b[1] + (int64_t)a[2] * b[2]) >> 16);
}

int f_16d369(const int *a, const int *b) {
    return f_16d361(a, b);
}

int f_16d388(const int *v) {
    int64_t sq = (int64_t)v[0] * v[0] + (int64_t)v[1] * v[1] + (int64_t)v[2] * v[2];
    DAT_001a9968 = (int16_t)((uint64_t)sq >> 16);
    return (int32_t)((uint64_t)sq >> 32);
}

int f_16d3b7(int a, int b, int c, int d) {
    return (int)(((int64_t)a * b - (int64_t)c * d) >> 22);
}

int f_16d3d0(int a) {
    if (a <= 0) return 0;
    double v = (double)(uint32_t)a / 65536.0;
    return (int)(sqrt(v) * 65536.0 + 0.5);
}

int f_16d430(int a) {
    return (a < 0) ? -a : a;
}

int f_16d440(int a, int b) {
    return (int)(((int64_t)a * b) >> 16);
}

int f_16d451(int a, int b, int c) {
    if (c == 0) return 0;
    return (int)(((int64_t)a * b) / c);
}

int f_16d464(int a, int b) {
    if (b == 0) return 0;
    return (int)(((int64_t)a << 16) / b);
}

int f_16d491(int a, int b) {
    if (b == 0) return 0;
    return (int)((((int64_t)a << 16) + (b >> 1)) / b);
}

int f_16d4a7(int a, int b) {
    if (b == 0) return 0;
    return (int)(((int64_t)a << 16) / b);
}

int f_16d4c4(int a) {
    return (int)(((int64_t)a * a) >> 16);
}

int f_16d4d8(int a, int b) {
    double da = (double)a / 65536.0;
    double db = (double)b / 65536.0;
    return (int)(sqrt(da * da + db * db) * 65536.0 + 0.5);
}

int f_16d4fc(int a, int b, int c) {
    double da = (double)a / 65536.0;
    double db = (double)b / 65536.0;
    double dc = (double)c / 65536.0;
    return (int)(sqrt(da * da + db * db + dc * dc) * 65536.0 + 0.5);
}

int f_16d529(int a, int b, int c, int d) {
    double da = (double)a / 65536.0;
    double db = (double)b / 65536.0;
    double dc = (double)c / 65536.0;
    double dd = (double)d / 65536.0;
    return (int)(sqrt(da * da + db * db + dc * dc + dd * dd) * 65536.0 + 0.5);
}

int f_16d564(int a, int b) { return f_16d4d8(a, b); }
int f_16d587(int a, int b, int c) { return f_16d4fc(a, b, c); }
int f_16d5b0(int a, int b, int c, int d) { return f_16d529(a, b, c, d); }
int f_16d5ea(int a) { return f_16d3d0(a); }
int f_16d64e(int a) { return f_16d3d0(a); }

int f_16d704(int a) {
    int s = f_16d3d0(a);
    return (s != 0) ? (int)(0x100000000LL / s) : 0;
}

/* Original BrFixedSin/BrFixedCos: 8-Bit-Interpolation der 16-Bit-Tabelle.
   Die Tabelle stammt zur Laufzeit aus dem Datensegment der Nutzer-EXE. */
extern int16_t d_1ac914[];
static int riva_br_trig(uint16_t angle, unsigned quarter) {
    unsigned i = (angle >> 8) + quarter;
    int lo = d_1ac914[i];
    int delta = (int)d_1ac914[i + 1] - lo;
    return (int16_t)(lo + ((delta * (angle & 255)) >> 8)) * 2;
}
int f_16d7e7(int a) {
    return riva_br_trig((uint16_t)a, 0);
}

int f_16d818(int a) {
    return riva_br_trig((uint16_t)a, 64);
}

int f_16d84d(int a) {
    double v = (double)a / 65536.0;
    if (v < -1.0) v = -1.0;
    if (v > 1.0) v = 1.0;
    int ang = (int)floor(asin(v) * (65536.0 / (2.0 * 3.14159265358979323846)) + 0.5);
    return (uint16_t)ang;
}

int f_16d87b(int a) {
    double v = (double)a / 65536.0;
    if (v < -1.0) v = -1.0;
    if (v > 1.0) v = 1.0;
    int ang = (int)floor(acos(v) * (65536.0 / (2.0 * 3.14159265358979323846)) + 0.5);
    return (uint16_t)ang;
}

int f_16d8ad(int y, int x) {
    if (x == 0 && y == 0) return 0;
    double ang = atan2((double)y, (double)x) * (65536.0 / (2.0 * 3.14159265358979323846));
    return (int16_t)((int)floor(ang + 0.5) & 0xffff);
}

int f_16da14(int a, int b) { return f_16d8ad(a, b); }
uint32_t f_16dd11(int lo, int hi, uint32_t s1, uint32_t s2) {
    uint64_t v = ((uint64_t)(uint32_t)hi << 32) | (uint32_t)lo;
    if (v == 0) return 0;
    return (uint32_t)floor(sqrt((double)v) + 0.5);
}
int f_16dfac(int a, int b, int c, int d) { return f_16d33f(a, b, c, d); }
int f_16dfd0(int a, int b, int c, int d, int e, int f) {
    return (int)(((int64_t)a * b + (int64_t)c * d + (int64_t)e * f) >> 16);
}
int f_16dfe8(int a, int b, int c, int d, int e, int f, int g, int h) {
    return (int)(((int64_t)a * b + (int64_t)c * d + (int64_t)e * f + (int64_t)g * h) >> 16);
}
int f_16dffc(int a, int b, int c) { return (int)(((int64_t)a * b) >> 16) + c; }
int f_16e00c(int a, int b, int c, int d) { return f_16d33f(a, b, c, d); }

/* --- 5. Attic 2D Minimap Polygon Filler & Line Drawer (0x16f086..0x16fb72) --- */
static void f_16f086_step(int y0, int x1, int x0, int y1, uint32_t **p_edi) {
    uint32_t dy = (uint32_t)(y1 - y0);
    if ((int)dy <= 0) return;
    int dx = x1 - x0;
    DAT_001ad9e2 = (dx < 0) ? 1 : 0;
    if (dx < 0) dx = -dx;
    uint32_t base_addr = (uint32_t)((y0 + DAT_001cdb48) * DAT_001a9a60 + DAT_001cdb44 + DAT_001a991c + x0);
    DAT_001ada40 = (int32_t)base_addr;
    int32_t step_int = (int32_t)((uint32_t)dx / dy);
    uint64_t rem = ((uint64_t)((uint32_t)dx % dy)) << 32;
    uint32_t step_frac = (uint32_t)(rem / dy);
    if (DAT_001ad9e2) {
        bool borrow = (step_frac != 0);
        step_frac = (uint32_t)(-(int32_t)step_frac);
        step_int = -(int32_t)borrow - step_int;
    }
    step_int += DAT_001a9a60;
    uint32_t cur_addr = base_addr;
    if (DAT_001ad9e5 != 0) cur_addr++;
    uint32_t frac = 0x8000u;
    uint32_t *edi = *p_edi;
    uint32_t cnt = (dy & 0xffffu) + 1;
    for (uint32_t i = 0; i < cnt; i++) {
        *edi++ = cur_addr;
        uint64_t fsum = (uint64_t)frac + (uint64_t)step_frac;
        frac = (uint32_t)fsum;
        cur_addr = (uint32_t)((int32_t)cur_addr + step_int + (int32_t)(fsum >> 32));
    }
    *p_edi = edi - 1;
}

void f_16f4f0(void) {}

void f_16f4f5(int p1) {
    int16_t *esi = (int16_t *)(&DAT_001ccf38);
    DAT_001ada38 = 0x7fff;
    DAT_001ada3c = -0x7fff;
    DAT_001ada22 = esi[1];
    DAT_001ad9e5 = 0;
    DAT_001ada24 = DAT_001ada22;
    DAT_001ada28 = p1;
    DAT_001ada30 = esi;
    DAT_001ada34 = p1;
    uint32_t *edi1 = (uint32_t *)(&DAT_001ada4c);
    if (DAT_001ad9e1 == 0) {
        DAT_001ad9e5 = 0xff;
        edi1 += 200;
    }
    do {
        int x0 = esi[0], y0 = esi[1], y1 = esi[3];
        if (x0 < DAT_001ada38) DAT_001ada38 = x0;
        if (DAT_001ada3c < x0) DAT_001ada3c = x0;
        if (y1 < y0) break;
        if (y1 != y0) {
            DAT_001ada22 = (int16_t)y1;
            f_16f086_step(y0, esi[2], x0, y1, &edi1);
        }
        DAT_001ada28--;
        esi += 2;
    } while (DAT_001ada28 != 0);

    DAT_001ad9e5 = ~DAT_001ad9e5;
    DAT_001ada28 = DAT_001ada34;
    int16_t *psVar9 = DAT_001ada30 + DAT_001ada34 * 2;
    uint32_t *edi2 = (uint32_t *)(&DAT_001ada4c);
    if (DAT_001ad9e1 != 0) {
        edi2 += 200;
    }
    do {
        int x0 = psVar9[0], y0 = psVar9[1], y1 = psVar9[-1];
        if (x0 < DAT_001ada38) DAT_001ada38 = x0;
        if (DAT_001ada3c < x0) DAT_001ada3c = x0;
        if (y1 < y0) break;
        if (y1 != y0) {
            f_16f086_step(y0, psVar9[-2], x0, y1, &edi2);
        }
        DAT_001ada28--;
        psVar9 -= 2;
    } while (DAT_001ada28 != 0);

    uint8_t col = DAT_001ad9e3;
    int32_t *piVar10 = &DAT_001ada4c;
    if (DAT_001ada24 == DAT_001ada22) {
        int32_t row = (DAT_001ada24 + DAT_001cdb48) * DAT_001a9a60 + DAT_001cdb44 + DAT_001a991c;
        DAT_001ada4c = row + DAT_001ada38;
        DAT_001add6c = row + DAT_001ada3c;
    }
    int count = (int)(int16_t)(DAT_001ada22 - DAT_001ada24);
    for (int i = 0; i <= count; i++) {
        uint32_t a0 = (uint32_t)piVar10[i];
        uint32_t a1 = (uint32_t)piVar10[i + 200];
        uint8_t *p = (uint8_t *)(uintptr_t)((a0 <= a1) ? a0 : a1);
        uint32_t len = (a0 <= a1) ? (a1 - a0) : (a0 - a1);
        if (len > 0 && len < 640) {
            memset(p, col, len);
        }
    }
}



int f_16f693(int p1, int p2, int p3, int p4, int in_stack_00000004) {
    if (in_stack_00000004 > 2 && in_stack_00000004 <= 64) {
        int16_t local_a = 0x7fff, local_6 = 0x7fff, local_c = -0x7fff, local_8 = -0x7fff;
        int16_t *psVar14 = (int16_t *)(&DAT_001ccf60);
        for (int iVar8 = in_stack_00000004; iVar8 != 0; iVar8--) {
            int16_t x = psVar14[0], y = psVar14[1];
            if (local_8 < x) local_8 = x;
            if (x < local_6) local_6 = x;
            if (local_c < y) local_c = y;
            if (y < local_a) { p2 = iVar8; local_a = y; }
            psVar14 += 2;
        }
        uint8_t clip = 0;
        if (local_a < (int16_t)DAT_001cdb50) {
            clip = 0xff;
            if (local_c < (int16_t)DAT_001cdb50) return p1;
        } else if ((int16_t)DAT_001cdb68 < local_c) {
            clip = 1;
            if ((int16_t)DAT_001cdb68 < local_a) return p1;
        }
        if (local_6 < (int16_t)DAT_001cdb4c) {
            clip = 1;
            if (local_8 < (int16_t)DAT_001cdb4c) return p1;
        } else if ((int16_t)DAT_001cdb6c < local_8) {
            clip = 1;
            if ((int16_t)DAT_001cdb6c < local_6) return p1;
        }
        DAT_001ad9e0 = clip;
        uint32_t *puVar15 = (uint32_t *)(&DAT_001ccf60) + (in_stack_00000004 - p2);
        uint32_t *dst = (uint32_t *)(&DAT_001ccf38);
        for (int i = 0; i < p2; i++) *dst++ = *puVar15++;
        puVar15 = (uint32_t *)(&DAT_001ccf60);
        for (int i = 0; i < in_stack_00000004 - p2; i++) *dst++ = *puVar15++;
        *dst = *(uint32_t *)(&DAT_001ccf38);

        int16_t *psVar16 = (int16_t *)(&DAT_001ccf3c);
        int16_t sVar2 = 0, *psVar1 = psVar16;
        do {
            sVar2 = *psVar16;
            psVar1 = psVar16 + 1;
            psVar16 += 2;
            if (DAT_001ccf38 != sVar2) break;
        } while (DAT_001ccf3a == *psVar1);

        int16_t *end_ptr = (int16_t *)dst;
        int16_t sVar3 = 0;
        do {
            sVar3 = end_ptr[-2];
            psVar16 = end_ptr - 1;
            if (DAT_001ccf38 != sVar3) break;
            end_ptr -= 2;
        } while (DAT_001ccf3a == *psVar16);

        int32_t prod1 = (int32_t)(int16_t)(DAT_001ccf3a - *psVar16) * (int32_t)(int16_t)-(sVar2 - DAT_001ccf38);
        int32_t prod2 = (int32_t)(int16_t)-(*psVar1 - DAT_001ccf3a) * (int32_t)(int16_t)(DAT_001ccf38 - sVar3);
        DAT_001ad9e1 = ((uint32_t)prod2 < (uint32_t)prod1) ? 1 : 0;
        int nverts = in_stack_00000004;
        if (DAT_001ad9e0 != 0) {
            nverts = f_16ecc0(in_stack_00000004, 0, 0, 0);
        }
        if ((int16_t)nverts > 2) {
            f_16f4f5(nverts);
        }
    }
    return p1;
}

uint32_t f_16f830(int p1, int p2, uint32_t p3, int p4);
void f_16f992(int p1, uint32_t p2, int p3, int p4);

void f_16fb53_xy(int x, int y) {
    DAT_001ad9fa = x;
    DAT_001ad9fe = y;
    f_16f830(0, 0, (uint32_t)x, y);
}

void f_16fb72_xy(int x, int y) {
    uint32_t prev_code = DAT_001ad9e6;
    DAT_001ad9f2 = DAT_001ad9fa;
    DAT_001ad9f6 = DAT_001ad9fe;
    DAT_001ad9ea = x;
    DAT_001ad9ee = y;
    DAT_001ad9fa = x;
    DAT_001ad9fe = y;
    f_16f992(0, prev_code, x, y);
}

int f_16fb53(int a, int b, int c, int d) {
    /* Handle 2-arg (x, y), 3-arg (color, x, y in fz_14dc28_t6), and 4-arg (b, sc2, 0, 0 in fz_14dc28_t4) */
    int x = a, y = b;
    if (b == DAT_001c6b20 && b > 256 && c == 0 && d == 0) {
        x = 0; y = 0;
    } else if (a == DAT_001cdb60 && (c >= -320 && c <= 320) && (b >= -320 && b <= 320) && a > 0 && (b != a || c != b)) {
        /* 3-arg call in fz_14dc28_t6_P1.CPP: f_16fb53(c, x1, y1) where c == d_1cdb60 */
        /* Check if c looks like y coordinate (-200..200) */
        if (d < -1000 || d > 1000) { x = b; y = c; }
    }
    f_16fb53_xy(x, y);
    return a;
}

int f_16fb72(int a, int b, int c, int d) {
    int x = a, y = b;
    if (a == DAT_001cdb60 && (c >= -320 && c <= 320) && (b >= -320 && b <= 320) && a > 0) {
        if (d < -1000 || d > 1000) { x = b; y = c; }
    }
    f_16fb72_xy(x, y);
    return a;
}

/* --- 6. Timer (0x16fc08..0x16fc19) --- */
int f_16fc08(void) {
    f_1802f0();
    return 0;
}

void f_16fc18(void) {}

uint32_t f_16fc19(void) {
    /* Return monotonic 1.193182 MHz PIT ticks (QPC-backed) for 3D frame rate / movement scaling */
    return dsa_platform_get_pit_ticks();
}

/* ==== 1750B6-17594B  (Attic) ==== */
void f_1750b6(void) {}

void f_1750bc(void) {
    /* Blit 3D viewport buffer (d_1a9920) to VGA VRAM (dsa_platform_get_vram()) */
    uint8_t *vram = dsa_platform_get_vram();
    if (!vram || !DAT_001a9920) return;
    const uint8_t *src = (const uint8_t *)(uintptr_t)DAT_001a9920;
    uint8_t *dst = vram + (uint16_t)DAT_001cdc24 * 320 + (uint16_t)DAT_001cdc22;
    int w = DAT_001a9984;
    int h = DAT_001a9988;
    int src_stride = DAT_001a9a60;
    if (w <= 0 || h <= 0 || w > 320 || h > 200) return;
    for (int y = 0; y < h; y++) {
        memcpy(dst + y * 320, src + y * src_stride, (size_t)w);
    }
    /* Einmaliger Textur-Upload + Present pro 3D-Bild */
    dsa_platform_present();
    uint32_t t_pump0 = f_16fc19();
    static uint32_t s_last_frame_pit = 0;
    riva_pump_timers_and_events();
    /* Sanftes Frame-Pacing auf max. ~100 FPS (~11932 PIT-Ticks/Frame), damit DOS-Festkomma-Divisionen in f_1630ac im Originalbereich bleiben */
    if (s_last_frame_pit != 0) {
        while ((uint32_t)(f_16fc19() - s_last_frame_pit) < 11932u) {
            SDL_Delay(1);
            riva_pump_timers_and_events();
        }
    }
    s_last_frame_pit = f_16fc19();
    uint32_t t_pump1 = s_last_frame_pit;
    DAT_001a9a64 -= (int32_t)(t_pump1 - t_pump0);
}

void f_175127(int y_start, int y_end, uint8_t color) {
    if (!DAT_001a991c) return;
    int w = DAT_001a9984;
    int stride = DAT_001a9a60;
    int x0 = DAT_001cdb44 + DAT_001cdb4c;
    for (int y = y_start; y <= y_end; y++) {
        int sy = y + DAT_001cdb48;
        if (sy >= 0 && sy < DAT_001a9990 && w > 0) {
            memset((uint8_t *)(uintptr_t)DAT_001a991c + sy * stride + x0, color, (size_t)w);
        }
    }
}

void f_1751d3(const uint8_t *tex, int height, int y_off, int tex_w_fp, int u_start, int v_start, int du, int dv) {
    if (!DAT_001a991c || !tex || height <= 0 || DAT_001a9984 <= 0) return;
    int start_y = y_off + DAT_001cdb48 + DAT_001cdb50;
    int start_x = DAT_001cdb44 + DAT_001cdb4c;
    uint8_t *dst_base = (uint8_t *)(uintptr_t)DAT_001a991c + start_y * DAT_001a9a60 + start_x;
    const uint8_t *shade_row = (const uint8_t *)(uintptr_t)(DAT_001cd1ec + (DAT_001a9974 << 8));
    uint32_t u_cur = (uint32_t)u_start;
    uint32_t u_lim = (uint32_t)tex_w_fp;
    int width = DAT_001a9984;
    for (int x = 0; x < width; x++) {
        if (u_lim > 0 && u_cur >= u_lim) {
            u_cur -= u_lim;
        }
        const uint8_t *col_src = tex + (u_cur & ~0xffu);
        uint8_t *col_dst = dst_base + x;
        uint32_t v_cur = (uint32_t)v_start;
        for (int y = 0; y < height; y++) {
            uint8_t c = col_src[(v_cur >> 8) & 0xffu];
            *col_dst = shade_row[c];
            col_dst += DAT_001a9a60;
            v_cur += (uint32_t)dv;
        }
        u_cur += (uint32_t)du;
    }
}

void f_175839(uint8_t color_idx, int p2, void *p3, void *p4) {
    /* Flat-shaded horizontal scanline filler */
    if (!DAT_001a991c || !DAT_001cd1ec || !DAT_001d1204) return;
    int stride = DAT_001a9a60;
    int fb_h = DAT_001a9990 > 0 ? DAT_001a9990 : 200;
    uint8_t *fb_base = (uint8_t *)(uintptr_t)DAT_001a991c;
    size_t fb_size = (size_t)(stride * fb_h);
    uint8_t *left = (uint8_t *)DAT_001d1204;
    uint8_t *right = left + 0x1900;
    for (int y = DAT_001d1228; y <= DAT_001d1224; y++, left += 20, right += 20) {
        int sy = y + DAT_001cdb48;
        if (sy < 0 || sy >= fb_h) continue;
        int x0 = *(int16_t *)(left + 10);
        int x1 = *(int16_t *)(right + 10);
        if (x1 >= x0) {
            uint16_t sh0 = *(uint16_t *)(left + 8);
            uint16_t sh1 = *(uint16_t *)(right + 8);
            uint16_t shade = ((sh0 >= sh1) ? sh0 : sh1) & 0x3f00u;
            uint8_t col = ((const uint8_t *)(uintptr_t)DAT_001cd1ec)[shade + color_idx];
            int sx0 = x0 + DAT_001cdb44;
            int sx1 = x1 + DAT_001cdb44;
            if (sx0 < 0) sx0 = 0;
            if (sx1 >= stride) sx1 = stride - 1;
            if (sx1 >= sx0) {
                uint8_t *dst = fb_base + sy * stride + sx0;
                if ((size_t)(dst - fb_base) + (size_t)(sx1 - sx0 + 1) <= fb_size) {
                    memset(dst, col, (size_t)(sx1 - sx0 + 1));
                }
            }
        }
    }
}

void f_1758bc(uint8_t color_idx, int p2, void *p3, void *p4) {
    /* Flat-shaded vertical column filler */
    if (!DAT_001a991c || !DAT_001cd1ec || !DAT_001d1204) return;
    int stride = DAT_001a9a60;
    int fb_h = DAT_001a9990 > 0 ? DAT_001a9990 : 200;
    uint8_t *fb_base = (uint8_t *)(uintptr_t)DAT_001a991c;
    size_t fb_size = (size_t)(stride * fb_h);
    uint8_t *top = (uint8_t *)DAT_001d1204;
    uint8_t *bot = top + 0x1900;
    for (int x = DAT_001d1228; x <= DAT_001d1224; x++, top += 20, bot += 20) {
        int sx = x + DAT_001cdb44;
        if (sx < 0 || sx >= stride) continue;
        int y0 = *(int16_t *)(top + 10);
        int y1 = *(int16_t *)(bot + 10);
        if (y1 >= y0) {
            uint16_t sh0 = *(uint16_t *)(top + 8);
            uint16_t sh1 = *(uint16_t *)(bot + 8);
            uint16_t shade = ((sh0 >= sh1) ? sh0 : sh1) & 0x3f00u;
            uint8_t col = ((const uint8_t *)(uintptr_t)DAT_001cd1ec)[shade + color_idx];
            int sy0 = y0 + DAT_001cdb48;
            int sy1 = y1 + DAT_001cdb48;
            if (sy0 < 0) sy0 = 0;
            if (sy1 >= fb_h) sy1 = fb_h - 1;
            uint8_t *dst = fb_base + sy0 * stride + sx;
            for (int sy = sy0; sy <= sy1; sy++) {
                if ((size_t)(dst - fb_base) < fb_size) *dst = col;
                dst += stride;
            }
        }
    }
}

/* --- 8. The 12 Textured Polygon Scanline/Column Rasterizers --- */
static inline __attribute__((always_inline)) void rasterize_spans(bool vertical, bool persp, bool gouraud, bool transparent) {
    if (!DAT_001a991c || !DAT_001cd1ec || !DAT_001cdb94 || !DAT_001d1204) return;
    const uint8_t *tex = (const uint8_t *)(uintptr_t)DAT_001cdb94;
    const uint8_t *shade_tbl = (const uint8_t *)(uintptr_t)DAT_001cd1ec;
    uint32_t uv_mask = DAT_001a9a24 ? DAT_001a9a24 : 0xffffu;
    int stride = DAT_001a9a60;
    int fb_h = DAT_001a9990 > 0 ? DAT_001a9990 : 200;
    uint8_t *fb_base = (uint8_t *)(uintptr_t)DAT_001a991c;
    size_t fb_size = (size_t)(stride * fb_h);
    uint8_t *edge0 = (uint8_t *)DAT_001d1204;
    uint8_t *edge1 = edge0 + 0x1900;
    int32_t focal = vertical
        ? (int32_t)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4
        : (int32_t)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0;

    for (int line = DAT_001d1228; line <= DAT_001d1224; line++, edge0 += 20, edge1 += 20) {
        if (!vertical) {
            int sy = line + DAT_001cdb48;
            if (sy < 0 || sy >= fb_h) continue;
        } else {
            int sx = line + DAT_001cdb44;
            if (sx < 0 || sx >= stride) continue;
        }

        int p0 = *(int16_t *)(edge0 + 10);
        int p1 = *(int16_t *)(edge1 + 10);
        int len = p1 - p0;
        if (len < 0) continue;

        uint8_t *dst = vertical
            ? (fb_base + (p0 + DAT_001cdb48) * stride + (line + DAT_001cdb44))
            : (fb_base + (line + DAT_001cdb48) * stride + (p0 + DAT_001cdb44));
        int dst_step = vertical ? stride : 1;

        int32_t u0 = *(int32_t *)(edge0 + 0);
        int32_t v0 = *(int32_t *)(edge0 + 4);
        int32_t u1 = *(int32_t *)(edge1 + 0);
        int32_t v1 = *(int32_t *)(edge1 + 4);
        uint16_t sh0 = *(uint16_t *)(edge0 + 8);
        uint16_t sh1 = *(uint16_t *)(edge1 + 8);
        int32_t s0 = gouraud ? ((int32_t)sh0 << 8) : ((int32_t)((sh0 >= sh1) ? sh0 : sh1) << 8);
        int32_t s1 = (int32_t)sh1 << 8;

        if (len == 0) {
            if ((size_t)(dst - fb_base) < fb_size) {
                uint32_t uv = (((uint32_t)v0 >> 8) & 0xff00u) | (((uint32_t)u0 >> 16) & 0xffu);
                uint8_t texel = tex[uv & uv_mask];
                if (!transparent || texel != 0) {
                    uint32_t sh = ((uint32_t)s0 >> 8) & 0x3f00u;
                    *dst = shade_tbl[sh + texel];
                }
            }
            continue;
        }

        if (!persp) {
            int32_t du = (u1 - u0) / len;
            int32_t dv = (v1 - v0) / len;
            int32_t ds = gouraud ? ((s1 - s0) / len) : 0;
            int32_t u = u0, v = v0, s = s0;
            for (int i = 0; i <= len; i++) {
                if ((size_t)(dst - fb_base) < fb_size) {
                    uint32_t uv = (((uint32_t)v >> 8) & 0xff00u) | (((uint32_t)u >> 16) & 0xffu);
                    uint8_t texel = tex[uv & uv_mask];
                    if (!transparent || texel != 0) {
                        uint32_t sh = ((uint32_t)s >> 8) & 0x3f00u;
                        *dst = shade_tbl[sh + texel];
                    }
                }
                dst += dst_step;
                u += du;
                v += dv;
                s += ds;
            }
        } else {
            /* Original perspective-correct 16-pixel subdivision (f_175de5 / f_17628d / f_1811bc / f_181733):
             * edge0+12 = X0 (or Y0), edge0+16 = Z0, edge1+12 = X1 (or Y1), edge1+16 = Z1 (camera space >> 4). */
            int32_t X0 = *(int32_t *)(edge0 + 12);
            int32_t Z0 = *(int32_t *)(edge0 + 16);
            int32_t dX = *(int32_t *)(edge1 + 12) - X0;
            int32_t dZ = *(int32_t *)(edge1 + 16) - Z0;
            int32_t p0_fp = (int32_t)p0 << 16;
            int32_t num = (int32_t)((((int64_t)Z0 * p0_fp) - ((int64_t)focal * X0)) >> 16);
            int32_t den = (int32_t)((((int64_t)focal * dX) - ((int64_t)dZ * p0_fp)) >> 16);
            int32_t step_num16 = Z0 << 4;
            int32_t step_den16 = dZ << 4;

            int32_t du_total = u1 - u0;
            int32_t dv_total = v1 - v0;
            int32_t ds = gouraud ? ((s1 - s0) / len) : 0;
            int32_t u_cur = u0, v_cur = v0, s = s0;

            int n16 = len >> 4;
            for (int b = 0; b < n16; b++) {
                num += step_num16;
                den -= step_den16;
                int64_t t64 = (den != 0) ? (((int64_t)num << 16) / (int64_t)den) : 0xffff;
                if (t64 < 0) t64 = 0;
                if (t64 > 0x10000) t64 = 0x10000;
                int32_t t = (int32_t)t64;
                int32_t u_next = u0 + (int32_t)(((int64_t)du_total * t) >> 16);
                int32_t v_next = v0 + (int32_t)(((int64_t)dv_total * t) >> 16);
                int32_t du_step = (u_next - u_cur) >> 4;
                int32_t dv_step = (v_next - v_cur) >> 4;
                for (int k = 0; k < 16; k++) {
                    if ((size_t)(dst - fb_base) < fb_size) {
                        uint32_t uv = (((uint32_t)v_cur >> 8) & 0xff00u) | (((uint32_t)u_cur >> 16) & 0xffu);
                        uint8_t texel = tex[uv & uv_mask];
                        if (!transparent || texel != 0) {
                            uint32_t sh = ((uint32_t)s >> 8) & 0x3f00u;
                            *dst = shade_tbl[sh + texel];
                        }
                    }
                    dst += dst_step;
                    u_cur += du_step;
                    v_cur += dv_step;
                    s += ds;
                }
                u_cur = u_next;
                v_cur = v_next;
            }

            int rem = len & 15;
            int32_t du_rem = (rem > 0) ? ((u1 - u_cur) / rem) : 0;
            int32_t dv_rem = (rem > 0) ? ((v1 - v_cur) / rem) : 0;
            for (int k = 0; k <= rem; k++) {
                if ((size_t)(dst - fb_base) < fb_size) {
                    uint32_t uv = (((uint32_t)v_cur >> 8) & 0xff00u) | (((uint32_t)u_cur >> 16) & 0xffu);
                    uint8_t texel = tex[uv & uv_mask];
                    if (!transparent || texel != 0) {
                        uint32_t sh = ((uint32_t)s >> 8) & 0x3f00u;
                        *dst = shade_tbl[sh + texel];
                    }
                }
                dst += dst_step;
                u_cur += du_rem;
                v_cur += dv_rem;
                s += ds;
            }
        }
    }
}

void f_17594b(void) { rasterize_spans(false, false, false, false); }
void f_175b7e(void) { rasterize_spans(true,  false, false, false); }
void f_175de5(void) { rasterize_spans(false, true,  false, false); }
void f_17628d(void) { rasterize_spans(true,  true,  false, false); }
void f_180c40(void) { rasterize_spans(false, false, true,  false); }
void f_180ee4(void) { rasterize_spans(true,  false, true,  false); }
void f_1811bc(void) { rasterize_spans(false, true,  true,  false); }
void f_181733(void) { rasterize_spans(true,  true,  true,  false); }
void f_181d47(void) { rasterize_spans(false, false, true,  true);  }
void f_185038(void) { rasterize_spans(true,  false, true,  true);  }
void f_18707c(void) { rasterize_spans(false, true,  true,  true);  }
void f_187568(void) { rasterize_spans(true,  true,  true,  true);  }

/* --- 9. Palette & CPU Check (0x176784..0x17695f) --- */
int f_176784(void) {
    DAT_001a9924 = 0;
    return 0;
}

void f_1767df(void) {}

void f_17684a(const uint8_t *pal) {
    if (!pal) return;
    for (int i = 0; i < 256; i++) {
        dsa_platform_set_palette_entry((uint8_t)i, pal[i * 4 + 0] >> 2, pal[i * 4 + 1] >> 2, pal[i * 4 + 2] >> 2);
    }
    }

int f_17695f(void) {
    return 0x182;
}

/* --- 10. Attic 3D Scene, Texture Loader & Camera Setup (0x160790..0x164994) --- */
void f_162c64(int w, int h, int src_stride, int dst_stride, const void *src, void *dst);
void f_162cc0(int w, int h, int src_stride, int dst_stride, const void *src, void *dst);
void f_162d28(int w, int h, int src_stride, int dst_stride, const void *src, void *dst);
void f_160d18(int a, int b);
void f_160d8c(int a, int b);

int f_160f64(const char *a, void *b);
int f_16246c(const char *a);

void f_162c64(int w, int h, int src_stride, int dst_stride, const void *src, void *dst) {
    if (!src || !dst || w <= 0 || h <= 0) return;
    const uint8_t *s = (const uint8_t *)src;
    uint8_t *d = (uint8_t *)dst;
    for (int y = 0; y < h; y++, s += src_stride, d += dst_stride) {
        memcpy(d, s, (size_t)w);
    }
}

void f_162cc0(int w, int h, int src_stride, int dst_stride, const void *src, void *dst) {
    if (!src || !dst || w <= 1 || h <= 1) return;
    const uint8_t *s = (const uint8_t *)src;
    uint8_t *d = (uint8_t *)dst;
    int hw = w >> 1, hh = h >> 1;
    for (int y = 0; y < hh; y++, s += src_stride * 2, d += dst_stride) {
        for (int x = 0; x < hw; x++) d[x] = s[x * 2];
    }
}

void f_162d28(int w, int h, int src_stride, int dst_stride, const void *src, void *dst) {
    if (!src || !dst || w <= 3 || h <= 3) return;
    const uint8_t *s = (const uint8_t *)src;
    uint8_t *d = (uint8_t *)dst;
    int qw = w >> 2, qh = h >> 2;
    for (int y = 0; y < qh; y++, s += src_stride * 4, d += dst_stride) {
        for (int x = 0; x < qw; x++) d[x] = s[x * 4];
    }
}

void *f_160790(const char *name) {
    char path[280];
    strcpy(path, (const char *)(&DAT_001cd0b0));
    strcat(path, name);
    strcat(path, ".PIX");
    uint8_t *pm = (uint8_t *)f_177e30(path);
    if (!pm) return 0;

    int frames = 1;
    bool is_anim = false;
    uint8_t *anim_entry = (uint8_t *)(uintptr_t)DAT_001cd200;
    for (int i = 0; i < DAT_001a9a4c; i++, anim_entry += 0x24) {
        if (f_144bf0((const char *)anim_entry, name) == 0) {
            int step_w = *(uint16_t *)(anim_entry + 0x1c);
            if (step_w > 0) {
                frames = (int)(*(uint16_t *)(pm + 0x18)) / step_w;
            }
            if ((int)*(uint16_t *)(anim_entry + 0x1a) < frames) {
                frames = *(uint16_t *)(anim_entry + 0x1a);
            }
            if ((int)*(uint16_t *)(anim_entry + 0x1a) > frames) {
                *(uint16_t *)(anim_entry + 0x1a) = (uint16_t)frames;
            }
            is_anim = true;
            break;
        }
    }

    int orig_w = is_anim ? *(uint16_t *)(anim_entry + 0x1c) : *(uint16_t *)(pm + 0x18);
    int orig_h = is_anim ? *(uint16_t *)(anim_entry + 0x1e) : *(uint16_t *)(pm + 0x1a);
    int w = orig_w, h = orig_h, shift = 0;
    if (DAT_001a994a != 0) {
        while (w > 0x80 || h > 0x80) {
            shift++;
            w >>= 1;
            h >>= 1;
        }
    }

    int32_t *atlas_ptr;
    int step;
    if (w <= 0x40 && h <= 0x40) {
        atlas_ptr = &DAT_001cdb8c;
        step = 0x40;
    } else if (w <= 0x80 && h <= 0x80) {
        atlas_ptr = &DAT_001cdb84;
        step = 0x80;
    } else if (w <= 0x100 && h <= 0x100) {
        atlas_ptr = &DAT_001cdb80;
        step = 0x100;
    } else {
        atlas_ptr = &DAT_001cdb7c;
        step = 0x100;
    }

    uint8_t *new_pm = (uint8_t *)f_1781c8(pm[0x12], w, h, (void *)(uintptr_t)(*atlas_ptr), 0);
    if (!new_pm) return pm;

    int row_adv = (step << 8) - 0x100 + step;
    for (int f = 0; f < frames; f++) {
        if (is_anim) {
            ((int32_t *)(uintptr_t)(*(int32_t *)(anim_entry + 0x20)))[f] = *atlas_ptr;
        }
        if ((int)((uint8_t)(*atlas_ptr)) + step >= 0x100) {
            *atlas_ptr += row_adv;
        } else {
            *atlas_ptr += step;
        }
    }

    *(uint16_t *)(new_pm + 0x1a) = (uint16_t)w;
    *(uint16_t *)(new_pm + 0x18) = (uint16_t)w;
    *(uint16_t *)(new_pm + 0x1c) = (uint16_t)(w >> 1);
    *(uint16_t *)(new_pm + 0x10) = 0x100;
    *(uint16_t *)(new_pm + 0x1e) = (uint16_t)(h >> 1);
    if (is_anim) new_pm[0x13] |= 0x80;
    else new_pm[0x13] &= 0x7f;

    const uint8_t *src_pixels = *(const uint8_t **)(pm + 4);
    int src_stride = *(int32_t *)(pm + 0x10) & 0xffff;
    int dst_stride = *(int32_t *)(new_pm + 0x10) & 0xffff;
    for (int f = 0; f < frames; f++) {
        void *dst_pixels = is_anim
            ? (void *)(uintptr_t)(((int32_t *)(uintptr_t)(*(int32_t *)(anim_entry + 0x20)))[f])
            : *(void **)(new_pm + 4);
        if (shift == 0) {
            f_162c64(orig_w, orig_h, src_stride, dst_stride, src_pixels, dst_pixels);
        } else if (shift == 1) {
            f_162cc0(orig_w, orig_h, src_stride, dst_stride, src_pixels, dst_pixels);
        } else if (shift == 2) {
            f_162d28(orig_w, orig_h, src_stride, dst_stride, src_pixels, dst_pixels);
        } else {
            int s = shift;
            while (s > 1) {
                s--;
                f_162cc0(orig_w, orig_h, src_stride, src_stride, src_pixels, (void *)src_pixels);
            }
            f_162cc0(orig_w, orig_h, src_stride, dst_stride, src_pixels, dst_pixels);
        }
        if (is_anim) src_pixels += orig_w;
    }

    f_1782e8(pm);
    return new_pm;
}



int f_163058(void) {
    return 0x800000;
}

void f_163428(int count, int color) {
    f_16ecba(color);
    const int16_t *pts = (const int16_t *)(&DAT_001ccf60);
    if (count > 0) {
        f_16fb53_xy(pts[(count - 1) * 2], pts[(count - 1) * 2 + 1]);
        for (int i = 0; i < count; i++) {
            f_16fb72_xy(pts[i * 2], pts[i * 2 + 1]);
        }
    }
}

void f_163484(int p1, int color, int p3, int p4) {
    if (p1 != 0) {
        f_16ecba(color);
        int16_t x0 = *(int16_t *)(p1 + 0x40);
        int16_t x1 = *(int16_t *)(p1 + 0x42);
        int16_t y0 = *(int16_t *)(p1 + 0x44);
        int16_t y1 = *(int16_t *)(p1 + 0x46);
        f_16fb53_xy(x0, y0);
        f_16fb72_xy(x1, y0);
        f_16fb72_xy(x1, y1);
        f_16fb72_xy(x0, y1);
        f_16fb72_xy(x0, y0);
    }
}

void f_163dc0(int p1) {
    DAT_001cdb90 = p1;
}

void f_163dc8(int p1) {
    DAT_001cdb90 = p1;
    DAT_001a994e = 1;
}

int f_163dd8(int size) {
    return f_156370(size, (const char *)(&riva_dgroup_base[0x1b9ad4 - 0x1a0000]), 0, 10);
}

void f_163df0(int ptr) {
    f_1563a8(ptr);
}

int f_163df8(void) {
    return 0x249f0;
}

void f_163e00(void) {
    memset(&DAT_001c76f8, 0, 100 * 0x40);
}


void f_160d18(int mod, int scn_obj) {
    if (!mod || !scn_obj) return;
    memcpy((void *)(uintptr_t)(scn_obj + 0x1c), (const void *)(uintptr_t)(mod + 0x10), 12);
    int32_t radius = (int32_t)(((int64_t)(*(int32_t *)(uintptr_t)(mod + 0x1c)) * 0x10cccLL) >> 16);
    *(uint8_t *)(uintptr_t)(scn_obj + 0) = 0;
    *(uint8_t *)(uintptr_t)(scn_obj + 1) = 0;
    *(uint16_t *)(uintptr_t)(scn_obj + 2) = 0xffff;
    *(uint16_t *)(uintptr_t)(scn_obj + 4) = 0;
    *(uint16_t *)(uintptr_t)(scn_obj + 6) = 0;
    *(uint16_t *)(uintptr_t)(scn_obj + 8) = 0;
    *(uint16_t *)(uintptr_t)(scn_obj + 10) = 0;
    *(uint16_t *)(uintptr_t)(scn_obj + 12) = 0;
    *(int32_t *)(uintptr_t)(scn_obj + 0x2c) = 0;
    *(int32_t *)(uintptr_t)(scn_obj + 0x18) = 0;
    *(int32_t *)(uintptr_t)(scn_obj + 0x10) = 0;
    *(int32_t *)(uintptr_t)(scn_obj + 0x14) = radius;
    *(int32_t *)(uintptr_t)(scn_obj + 0x28) = mod;
}

void f_160d8c(int mod, int scn_obj) {
    if (!mod || !scn_obj) return;
    const char *name = *(const char **)(uintptr_t)mod;
    int grp = *(int *)(uintptr_t)(mod + 0x44);
    int n_grp = *(uint16_t *)(uintptr_t)(mod + 0x0a);
    uint8_t c2 = name ? (uint8_t)name[2] : 0;
    uint32_t flags = 1;
    if (c2 == 'O') flags = 0x09;
    else if (c2 == 'R') flags = 0x03;
    else if (c2 == 'S') flags = 0x801;
    else if (c2 == 'Z' || c2 == 'E') flags = 0x81;
    else if (c2 == 'L') flags = 0x401;
    for (int i = 0; i < n_grp; i++, grp += 0x30) {
        int mat = *(int *)(uintptr_t)(grp + 0x28);
        if (mat != 0) {
            const char *mname = *(const char **)(uintptr_t)mat;
            if (mname) {
                if (mname[1] == 'T') flags &= ~1u;
                char m0 = mname[0];
                if (m0 == 'L' || m0 == 'H' || m0 == 'V') flags |= 0x08;
                else if (m0 == 'T' || m0 == 'S') flags |= 0x0c;
                else if (m0 == 'Y') flags |= 0x04;
                else if (m0 == 'X') flags |= 0x02;
            }
        }
        *(uint16_t *)(uintptr_t)(grp + 0x2e) = 0;
        *(uint16_t *)(uintptr_t)(grp + 0x2c) = 0;
    }
    *(uint16_t *)(uintptr_t)(scn_obj + 0x0a) |= (uint16_t)flags;
}

int f_160f64(const char *path, void *hdr) {
    if (!path || !hdr) {
        DAT_001a996c = 0xf005;
        return 0xf005;
    }
    int32_t *edi = (int32_t *)hdr;
    if (edi[7] != 0) {
        DAT_001a996c = 0xf00d;
        return 0xf00d;
    }
    void *fp = f_15e469(path, (const char *)(&riva_dgroup_base[0x1b9678 - 0x1a0000]));
    if (!fp) {
        DAT_001a996c = 0xf00a;
        return 0xf00a;
    }
    int fd = *(int *)((uint8_t *)fp + 0x10);
    int flen = f_1452bc(fd);
    uint8_t *buf = (uint8_t *)(uintptr_t)f_156370(flen, (const char *)(&riva_dgroup_base[0x1b967c - 0x1a0000]), 0, 10);
    if (!buf) {
        f_15e836(fp, 0);
        DAT_001a996c = 0xf001;
        return 0xf001;
    }
    int nread = f_15e65b(buf, 1, flen, fp);
    f_15e836(fp, 0);
    if (nread != flen || nread != *(int32_t *)(buf + 4) || *(int32_t *)(buf + 0) != 0x24680a) {
        f_1563a8((int)(uintptr_t)buf);
        DAT_001a996c = 0xf00f;
        return 0xf00f;
    }
    if (*(uint16_t *)(buf + 0x34) < 0x65 || *(uint16_t *)(buf + 0x36) != 8) {
        f_1563a8((int)(uintptr_t)buf);
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b9688 - 0x1a0000]));
        DAT_001a996c = 0xf00f;
        return 0xf00f;
    }
    int n_models = *(int32_t *)(buf + 8);
    edi[0] = n_models;
    int n_lights = *(int32_t *)(buf + 0x0c);
    edi[1] = n_lights;
    int n_tex = *(int32_t *)(buf + 0x10);
    edi[2] = n_tex;
    edi[4] = *(int32_t *)(buf + 0x18);
    edi[5] = *(int32_t *)(buf + 0x1c);
    edi[7] = (int32_t)(uintptr_t)buf;
    edi[6] = flen;
    uint8_t *str_base = buf + *(int32_t *)(buf + 0x20);
    edi[9] = (int32_t)(uintptr_t)str_base;
    uint8_t *mod_base = buf + *(int32_t *)(buf + 0x24);
    edi[10] = (int32_t)(uintptr_t)mod_base;
    uint8_t *lit_base = buf + *(int32_t *)(buf + 0x28);
    edi[11] = (int32_t)(uintptr_t)lit_base;
    uint8_t *tex_base = buf + *(int32_t *)(buf + 0x2c);
    edi[12] = (int32_t)(uintptr_t)tex_base;

    uint8_t *m = mod_base;
    for (int i = 0; i < n_models; i++, m += 0x7c) {
        uint8_t *mbase = buf + *(int32_t *)(m + 0x38);
        *(int32_t *)(m + 0x38) = (int32_t)(uintptr_t)mbase;
        *(int32_t *)(m + 0x3c) += (int32_t)(uintptr_t)mbase;
        *(int32_t *)(m + 0x40) += (int32_t)(uintptr_t)mbase;
        *(int32_t *)(m + 0x44) += (int32_t)(uintptr_t)mbase;
        uint8_t *f_arr = mbase + *(int32_t *)(m + 0x48);
        *(int32_t *)(m + 0x48) = (int32_t)(uintptr_t)f_arr;
        int nf = *(uint16_t *)(m + 0x0e);
        for (int j = 0; j < nf; j++, f_arr += 0x0c) {
            if (*(int32_t *)(f_arr + 4) != 0) {
                *(int32_t *)(f_arr + 4) += (int32_t)(uintptr_t)buf;
            }
            *(int32_t *)(f_arr + 8) += (int32_t)(uintptr_t)mbase;
        }
        uint8_t *g_arr = (uint8_t *)(uintptr_t)(*(int32_t *)(m + 0x44));
        int ng = *(uint16_t *)(m + 0x0a);
        for (int j = 0; j < ng; j++, g_arr += 0x30) {
            if (*(int32_t *)(g_arr + 0x28) != 0) {
                *(int32_t *)(g_arr + 0x28) += (int32_t)(uintptr_t)buf;
            }
        }
    }
    m = mod_base;
    for (int i = 0; i < n_models; i++, m += 0x7c) {
        if (*(int32_t *)m != 0) {
            *(int32_t *)m = (int32_t)(uintptr_t)(str_base + *(int32_t *)m - 1);
        }
    }
    uint8_t *l = lit_base;
    for (int i = 0; i < n_lights; i++, l += 0x58) {
        if (*(int32_t *)l != 0) {
            *(int32_t *)l = (int32_t)(uintptr_t)(str_base + *(int32_t *)l - 1);
        }
    }
    uint8_t *t = tex_base;
    for (int i = 0; i < n_tex; i++, t += 0x34) {
        t[0x0e] &= 0xfb;
        if (*(int32_t *)t != 0) {
            *(int32_t *)t = (int32_t)(uintptr_t)(str_base + *(int32_t *)t - 1);
        }
        if (*(int32_t *)(t + 0x2c) != 0) {
            *(int32_t *)(t + 0x2c) = (int32_t)(uintptr_t)(str_base + *(int32_t *)(t + 0x2c) - 1);
        }
    }
    DAT_001a996c = 0;
    return 0;
}

void f_162a00(int dst, int pm) {
    if (!dst || !pm) return;
    uint8_t *p = (uint8_t *)(uintptr_t)pm;
    if (p[0x12] != 7 || *(uint16_t *)(p + 0x10) != 4) return;
    const uint8_t *s = *(const uint8_t **)(p + 4);
    int stride = *(int16_t *)(p + 0x10);
    uint8_t *out = (uint8_t *)(uintptr_t)dst;
    for (int i = 0; i < 256; i++, out += 4, s += stride) {
        out[0] = s[2];
        out[1] = s[1];
        out[2] = s[0];
        out[3] = (uint8_t)i;
    }
}

int f_16246c(const char *path) {
    int tmp[2] = {0, 0};
    int save = DAT_001a9a34;
    DAT_001a9a34 = 0;
    int err = f_177910(path, &tmp[1], &tmp[0]);
    int sz = DAT_001a9a34;
    DAT_001a9a34 = save;
    if (err == 0) {
        sz += (tmp[1] << 8) + 0xc8;
    }
    return sz;
}

void f_16402c(void) {
    uint8_t *esi = (uint8_t *)(uintptr_t)DAT_001cd1e0;
    if (!esi) return;
    *(uint16_t *)(esi + 0x0a) = 0x19;
    *(int32_t *)(esi + 0x10) = 0x78000;
    *(int32_t *)(esi + 0x18) = (int32_t)(*(uint16_t *)(esi + 0x0a)) * (*(int32_t *)(esi + 0x10));
    esi[0x04] = 1;
    esi[0x08] = 0;
    esi[0x05] = 2;
    esi[0x06] = 1;
    *(uint16_t *)(esi + 0x0c) = 0;
    *(uint16_t *)(esi + 0x0e) = 0;
    *(int32_t *)(esi + 0x24) = 0;
    *(int32_t *)(esi + 0x28) = 0x90000;
    *(int32_t *)(esi + 0x2c) = (int32_t)0xfffe0000;
    *(int32_t *)(esi + 0x00) = (int32_t)(uintptr_t)(&riva_dgroup_base[0x1b9adc - 0x1a0000]);
    int r = f_165de2();
    *(int32_t *)(esi + 0x4c) = 0;
    esi[0x5c] = 1;
    esi[0x60] = 0;
    esi[0x5d] = 1;
    esi[0x5e] = 2;
    *(uint16_t *)(esi + 0x62) = 0;
    *(uint16_t *)(esi + 0x64) = 0;
    *(int32_t *)(esi + 0x68) = 0;
    *(int32_t *)(esi + 0x70) = 0;
    *(int32_t *)(esi + 0x88) = (int32_t)0xfffe0000;
    *(int32_t *)(esi + 0x8c) = (int32_t)0xffff8000;
    *(int32_t *)(esi + 0x90) = (int32_t)0xfffe8000;
    esi[0xb4] = 1;
    esi[0xb8] = 0;
    esi[0xb5] = 1;
    esi[0xb6] = 2;
    *(uint16_t *)(esi + 0xba) = 0;
    *(uint16_t *)(esi + 0xbc) = 0;
    *(int32_t *)(esi + 0xc0) = 0;
    *(int32_t *)(esi + 0xc8) = 0;
    *(int32_t *)(esi + 0xd4) = (int32_t)0xfff40000;
    *(int32_t *)(esi + 0xd8) = 0x20000;
    *(int32_t *)(esi + 0xdc) = (int32_t)0xfff58000;
    *(int32_t *)(esi + 0x48) = r & 3;
    *(int32_t *)(esi + 0x50) = *(uint16_t *)(esi + 0x0a);

    int32_t len = f_16d4fc(*(int32_t *)(esi + 0x88), *(int32_t *)(esi + 0x8c), *(int32_t *)(esi + 0x90));
    if (len > 2) {
        int32_t inv = 0x100000000LL / len;
        *(int32_t *)(esi + 0x88) = (int32_t)(((int64_t)(*(int32_t *)(esi + 0x88)) * inv) >> 16);
        *(int32_t *)(esi + 0x8c) = (int32_t)(((int64_t)(*(int32_t *)(esi + 0x8c)) * inv) >> 16);
        *(int32_t *)(esi + 0x90) = (int32_t)(((int64_t)(*(int32_t *)(esi + 0x90)) * inv) >> 16);
    } else {
        *(int32_t *)(esi + 0x8c) = 0;
        *(int32_t *)(esi + 0x90) = 0;
        *(int32_t *)(esi + 0x88) = 0x7fff;
    }

    *(int32_t *)(esi + 0x1c) = f_16d818(*(uint16_t *)(esi + 0x0c));
    *(int32_t *)(esi + 0x74) = f_16d818(*(uint16_t *)(esi + 0x64));
    *(int32_t *)(esi + 0xcc) = f_16d818(*(uint16_t *)(esi + 0xbc));
    *(int32_t *)(esi + 0x20) = f_16d818(*(uint16_t *)(esi + 0x0e));
    *(int32_t *)(esi + 0x78) = f_16d818(*(uint16_t *)(esi + 0x66));
    *(int32_t *)(esi + 0xd0) = f_16d818(*(uint16_t *)(esi + 0xbe));

    int offsets[3] = {0x24, 0x7c, 0xd4};
    for (int k = 0; k < 3; k++) {
        int off = offsets[k];
        int32_t l2 = f_16d4fc(*(int32_t *)(esi + off), *(int32_t *)(esi + off + 4), *(int32_t *)(esi + off + 8));
        if (l2 > 2) {
            int32_t inv = 0x100000000LL / l2;
            *(int32_t *)(esi + off) = (int32_t)(((int64_t)(*(int32_t *)(esi + off)) * inv) >> 16);
            *(int32_t *)(esi + off + 4) = (int32_t)(((int64_t)(*(int32_t *)(esi + off + 4)) * inv) >> 16);
            *(int32_t *)(esi + off + 8) = (int32_t)(((int64_t)(*(int32_t *)(esi + off + 8)) * inv) >> 16);
        } else {
            *(int32_t *)(esi + off + 4) = 0;
            *(int32_t *)(esi + off + 8) = 0;
            *(int32_t *)(esi + off) = 0x7fff;
        }
    }
}

int f_161328(void) {
    uint8_t bitmask[0x4e4];
    int32_t chain_tail[100];
    char path[280];

    DAT_001cdb90 = 0;
    if (DAT_001a993d == 0) {
        DAT_001a996c = 0xf002;
        return 0xf002;
    }
    if (DAT_001a9940 == 0) {
        DAT_001a996c = 0xf00c;
        return 0xf00c;
    }
    if (DAT_001a993f == 0) {
        DAT_001a996c = 0xf00d;
        return 0xf00d;
    }

    DAT_001a99b8 = 0;
    DAT_001a99b4 = 0;
    DAT_001a99b0 = 0;
    DAT_001a99ac = 0;
    DAT_001a99f8 = 0;
    memset(bitmask, 0, 0x4e3);

    strcpy(path, (const char *)(&DAT_001cd0b0));
    strcat(path, (const char *)(&DAT_001cd088));
    strcat(path, (const char *)(&riva_dgroup_base[0x1b96f8 - 0x1a0000]));
    f_17b260(path);

    DAT_001a9a4c = 0;
    DAT_001a9a50 = 0;
    DAT_001a9a54 = 0;
    DAT_001a9a58 = 0;
    f_17a940((const char *)(&DAT_001cd088));

    int sz = DAT_001a9a4c * 36 + DAT_001a9a50 * 8 + DAT_001a9a54 * 24 + DAT_001a9a58 * 32;
    DAT_001a9a30 = sz;
    if (DAT_001a992c != 0) {
        f_1563a8(DAT_001a992c);
        DAT_001a9a30 = 0;
        DAT_001a992c = 0;
    }
    if (sz < 16) sz = 16;
    DAT_001a9a30 = sz;
    int mem = f_156370(sz, (const char *)(&riva_dgroup_base[0x1b967c - 0x1a0000]), (const char *)(&riva_dgroup_base[0x1b9700 - 0x1a0000]), 0x14);
    DAT_001a992c = mem;
    if (!mem) {
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b970c - 0x1a0000]));
        DAT_001a996c = 0xf001;
        return 0xf001;
    }

    DAT_001cd200 = mem;
    int p = mem + DAT_001a9a4c * 36;
    DAT_001cd1fc = p;
    p += DAT_001a9a50 * 4;
    DAT_001a9924 = p;
    p += DAT_001a9a50 * 4;
    DAT_001cd1f4 = p;
    p += DAT_001a9a54 * 24;
    DAT_001cd1f0 = p;

    int err = f_17aaec((const char *)(&DAT_001cd088));
    if (err != 0) {
        f_162208();
        return err;
    }

    strcpy(path, (const char *)(&DAT_001cd0b0));
    strcat(path, (const char *)(&DAT_001cd088));
    strcat(path, (const char *)(&riva_dgroup_base[0x1b9730 - 0x1a0000]));
    void *pal_pm = f_177e30(path);
    if (!pal_pm) {
        f_162208();
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b9738 - 0x1a0000]));
        DAT_001a996c = 0xf00a;
        return 0xf00a;
    }
    f_162a00((int)(uintptr_t)(&DAT_001c72f8), (int)(uintptr_t)pal_pm);
    f_1782e8(pal_pm);
    f_164d04((int)(uintptr_t)(&DAT_001c72f8));

    strcpy(path, (const char *)(&DAT_001cd0b0));
    strcat(path, (const char *)(&DAT_001cd088));
    strcat(path, (const char *)(&riva_dgroup_base[0x1b9768 - 0x1a0000]));
    void *tab_pm = f_177e30(path);
    DAT_001a9d20 = (int)(uintptr_t)tab_pm;
    if (!tab_pm) {
        f_162208();
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b9770 - 0x1a0000]));
        DAT_001a996c = 0xf00a;
        return 0xf00a;
    }
    if (f_144bf0(*(const char **)tab_pm, (const char *)(&riva_dgroup_base[0x1b9798 - 0x1a0000])) == 0) {
        DAT_001a994c = 1;
    }

    strcpy(path, (const char *)(&DAT_001cd0b0));
    strcat(path, (const char *)(&DAT_001cd088));
    strcat(path, (const char *)(&riva_dgroup_base[0x1b97a4 - 0x1a0000]));
    err = f_160f64(path, &DAT_001cd1b4);
    if (err != 0) {
        f_162208();
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b97ac - 0x1a0000]));
        return err;
    }

    DAT_001a9a38 = (*(int32_t *)(&DAT_001cd1b4)) + 1;
    err = f_177260(&DAT_001cd1b4);
    if (err != 0) {
        f_162208();
        return err;
    }
    if (f_1564cc() != 0) {
        f_162208();
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b97d8 - 0x1a0000]));
        DAT_001a996c = 0xf001;
        return 0xf001;
    }
    if (f_1563bc() != 0) {
        f_162208();
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b9804 - 0x1a0000]));
        DAT_001a996c = 0xf001;
        return 0xf001;
    }

    strcpy(path, (const char *)(&DAT_001cd0b0));
    strcat(path, (const char *)(&DAT_001cd088));
    strcat(path, (const char *)(&riva_dgroup_base[0x1b9670 - 0x1a0000]));
    int sky_sz = f_16246c(path);
    if (sky_sz < DAT_001a9a34) sky_sz = DAT_001a9a34;
    if ((uint32_t)f_163058() < (uint32_t)(sky_sz + 0xfa0)) {
        f_162208();
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b9830 - 0x1a0000]));
        DAT_001a996c = 0xf001;
        return 0xf001;
    }
    f_1624b4((int)(uintptr_t)path);

    memcpy((void *)(uintptr_t)DAT_001cd1ec, *(const void **)(uintptr_t)(DAT_001a9d20 + 4), 0x4000);
    int shade_row = DAT_001cd1ec + (DAT_001a9974 << 8);
    DAT_001a9955 = *(uint8_t *)(uintptr_t)(shade_row + (uint8_t)DAT_001a9954);
    DAT_001a995a = *(uint8_t *)(uintptr_t)(shade_row + (uint8_t)DAT_001a9959);

    int n_tex = *(int32_t *)(&riva_dgroup_base[0x1cd1bc - 0x1a0000]);
    uint8_t *tex_ent = (uint8_t *)(uintptr_t)(*(int32_t *)(&riva_dgroup_base[0x1cd1e4 - 0x1a0000]));
    DAT_001a99b8 = n_tex;
    for (int i = 0; i < n_tex; i++, tex_ent += 0x34) {
        const char *tname = *(const char **)(tex_ent + 0x2c);
        if (tname) {
            void *pm = f_160790(tname);
            if (!pm) {
                const char *fmt = (DAT_001a996c == 0xf00a)
                    ? (const char *)(&riva_dgroup_base[0x1b9860 - 0x1a0000])
                    : (const char *)(&riva_dgroup_base[0x1b988c - 0x1a0000]);
                f_14572e((char *)(&DAT_001ccf88), fmt, tname);
                int saved_err = DAT_001a996c;
                f_162208();
                f_163050((int)(uintptr_t)(&DAT_001ccf88));
                return saved_err;
            }
            *(void **)(tex_ent + 0x2c) = pm;
            tex_ent[0x0e] |= 0x04;
            if ((((uint8_t *)pm)[0x13] & 0x80) != 0) {
                tex_ent[0x0e] |= 0x02;
            } else {
                tex_ent[0x0e] &= 0xfd;
            }
            *(int32_t *)(tex_ent + 0x30) = DAT_001a9d20;
        }
    }

    int n_mod = *(int32_t *)(&DAT_001cd1b4);
    if (n_mod > DAT_001a9a38) n_mod = DAT_001a9a38;
    DAT_001a99b4 = n_mod;
    DAT_001a99c0 = 0;
    DAT_001a99bc = 0;
    DAT_001a99c4 = 0;
    DAT_001a99c8 = 0;
    DAT_001a99b0 = *(int32_t *)(&riva_dgroup_base[0x1cd1b8 - 0x1a0000]);
    DAT_001a9d24 = 0;
    memset(chain_tail, 0, sizeof(chain_tail));

    uint8_t *ebp = (uint8_t *)(uintptr_t)DAT_001cd210;
    uint8_t *mod_base = (uint8_t *)(uintptr_t)(*(int32_t *)(&riva_dgroup_base[0x1cd1dc - 0x1a0000]));
    for (int i = 0; i < DAT_001a99b4; i++, ebp += 0x30) {
        uint8_t *esi = mod_base + i * 0x7c;
        f_160d18((int)(uintptr_t)esi, (int)(uintptr_t)ebp);
        DAT_001a99c8 += *(uint16_t *)(esi + 0x0a);
        DAT_001a99c0 += *(uint16_t *)(esi + 0x04);
        DAT_001a99bc += *(uint16_t *)(esi + 0x08);
        DAT_001a99c4 += *(uint16_t *)(esi + 0x06);

        uint8_t active = 1;
        int32_t anim_state = 0;
        uint16_t obj_id = 0xffff;
        const char *mname = *(const char **)esi;
        if (mname &&
            (riva_dgroup_base[0x1bbfdc - 0x1a0000 + (uint8_t)(mname[3] + 1)] & 0x20) &&
            (riva_dgroup_base[0x1bbfdc - 0x1a0000 + (uint8_t)(mname[4] + 1)] & 0x20) &&
            (riva_dgroup_base[0x1bbfdc - 0x1a0000 + (uint8_t)(mname[5] + 1)] & 0x20) &&
            (riva_dgroup_base[0x1bbfdc - 0x1a0000 + (uint8_t)(mname[6] + 1)] & 0x20)) {
            obj_id = (uint16_t)((mname[3] - '0') * 1000 + (mname[4] - '0') * 100 + (mname[5] - '0') * 10 + (mname[6] - '0'));
            size_t slen = strlen(mname);
            if (slen >= 2) {
                const char *tail = mname + slen - 2;
                uint8_t c_idx = (uint8_t)(tail[0] + 1);
                if ((riva_dgroup_base[0x1bbfdc - 0x1a0000 + c_idx] & 0xc0) &&
                    tail[0] == tail[1] &&
                    (riva_dgroup_base[0x1bbfdc - 0x1a0000 + c_idx] & 0x40)) {
                    anim_state = f_15ea62((int)(int8_t)tail[0]) - 0x40;
                    if ((int16_t)anim_state != 1) active = 0;
                }
            }
            if (obj_id > 0 && obj_id <= 0x2328) {
                bitmask[obj_id >> 3] |= (uint8_t)(1u << (obj_id & 7));
            }
        }
        ebp[0] = active;
        *(uint16_t *)(ebp + 4) = (uint16_t)anim_state;
        DAT_001a99ac++;
        *(uint16_t *)(ebp + 2) = obj_id;
        if (mname && f_144bf0(mname, (const char *)(&DAT_001cdc00)) == 0) {
            DAT_001a9d24 = (int32_t)(uintptr_t)ebp;
        }
        *(int32_t *)(ebp + 0x10) = 0;
        *(int32_t *)(ebp + 0x18) = 0;
        uint8_t *obj_def = (uint8_t *)(uintptr_t)DAT_001cd1f0;
        for (int k = 0; k < DAT_001a9a58; k++, obj_def += 0x20) {
            if (mname && f_144bf0((const char *)obj_def, mname) == 0) {
                *(int32_t *)(ebp + 0x18) = (int32_t)(uintptr_t)obj_def;
                if (*(int32_t *)(obj_def + 0x1c) != 0 &&
                    *(int32_t *)(obj_def + 0x18) != 0 &&
                    *(int16_t *)(obj_def + 0x14) > 0) {
                    ebp[0x0a] |= 0x40;
                    uint8_t *seq = (uint8_t *)(uintptr_t)(*(int32_t *)(obj_def + 0x18));
                    uint16_t start_f = 0;
                    if (seq[0x14] == 0 && *(uint16_t *)(seq + 0x1a) > 0) {
                        start_f = (uint16_t)(f_165de2() % (*(uint16_t *)(seq + 0x1a)));
                    }
                    *(uint16_t *)(ebp + 6) = start_f;
                }
                break;
            }
        }
        if (mname &&
            (riva_dgroup_base[0x1bbfdc - 0x1a0000 + (uint8_t)(mname[0] + 1)] & 0x20) &&
            (riva_dgroup_base[0x1bbfdc - 0x1a0000 + (uint8_t)(mname[1] + 1)] & 0x20)) {
            int grp_num = (mname[0] - '0') * 10 + (mname[1] - '0');
            ebp[1] = (uint8_t)grp_num;
            if (grp_num > 0 && grp_num < 100) {
                if (chain_tail[grp_num] == 0) {
                    *(int32_t *)(&riva_dgroup_base[0x1c7734 - 0x1a0000 + (grp_num << 6)]) = (int32_t)(uintptr_t)ebp;
                } else {
                    *(int32_t *)(uintptr_t)(chain_tail[grp_num] + 0x2c) = (int32_t)(uintptr_t)ebp;
                }
                chain_tail[grp_num] = (int32_t)(uintptr_t)ebp;
            }
        }
        f_160d8c((int)(uintptr_t)esi, (int)(uintptr_t)ebp);
    }

    f_16402c();
    uint8_t *lit = (uint8_t *)(uintptr_t)DAT_001cd1e0;
    for (int i = 0; i < DAT_001a99b0; i++, lit += 0x58) {
        if (lit[6] == 1) {
            *(int32_t *)(lit + 0x4c) = 0;
            *(int32_t *)(lit + 0x48) = i * 2;
            *(int32_t *)(lit + 0x50) = *(uint16_t *)(lit + 0x0a);
        }
    }
    DAT_001a996c = 0;
    DAT_001a993f = 0;
    return 0;
}

void f_163e30(void);
void f_164408(void);

static float unpack_float_arg(uint32_t a, uint32_t b) {
    uint32_t raw = (a >= 0x38000000u && a <= 0x48000000u) ? a : b;
    float f = 0.0f;
    memcpy(&f, &raw, 4);
    return f;
}

int f_1645a0(uint32_t a, uint32_t b) {
    if (DAT_001a993d == 0) { DAT_001a996c = 0xf002; return 0xf002; }
    float f = unpack_float_arg(a, b);
    if (f < 10.0f || f > 140.0f) { DAT_001a996c = 0xf005; return 0xf005; }
    DAT_001cdc18 = (int16_t)(int)(f * 182.04445f);
    uint8_t *cam = (uint8_t *)(uintptr_t)DAT_001cd2a0;
    if (cam) {
        cam[4] = 1;
        *(int16_t *)(cam + 6) = DAT_001cdc18;
        *(int32_t *)(cam + 8) = DAT_001a9ad8;
        *(int32_t *)(cam + 12) = DAT_001a9adc;
        *(int32_t *)(cam + 16) = DAT_001a9ad4;
    }
    f_164408();
    DAT_001a996c = 0;
    return 0;
}

int f_16468c(uint32_t a, uint32_t b) {
    if (DAT_001a993d == 0) { DAT_001a996c = 0xf002; return 0xf002; }
    float f = unpack_float_arg(a, b);
    if (f < 0.2f || f > 5.0f) { DAT_001a996c = 0xf005; return 0xf005; }
    DAT_001a9ad4 = (int32_t)(f * 65536.0f);
    uint8_t *cam = (uint8_t *)(uintptr_t)DAT_001cd2a0;
    if (cam) {
        cam[4] = 1;
        *(int16_t *)(cam + 6) = DAT_001cdc18;
        *(int32_t *)(cam + 8) = DAT_001a9ad8;
        *(int32_t *)(cam + 12) = DAT_001a9adc;
        *(int32_t *)(cam + 16) = DAT_001a9ad4;
    }
    f_164408();
    DAT_001a996c = 0;
    return 0;
}

int f_164748(uint32_t a, uint32_t b) {
    if (DAT_001a993d == 0) { DAT_001a996c = 0xf002; return 0xf002; }
    float f = unpack_float_arg(a, b);
    if (f < 10.0f) f = 10.0f;
    if (f > 2500.0f) f = 2500.0f;
    DAT_001a9adc = (int32_t)(f * 65536.0f);
    DAT_001a994b = 0;
    uint8_t *cam = (uint8_t *)(uintptr_t)DAT_001cd2a0;
    if (cam) {
        cam[4] = 1;
        *(int16_t *)(cam + 6) = DAT_001cdc18;
        *(int32_t *)(cam + 8) = DAT_001a9ad8;
        *(int32_t *)(cam + 12) = DAT_001a9adc;
        *(int32_t *)(cam + 16) = DAT_001a9ad4;
    }
    f_164408();
    DAT_001a996c = 0;
    return 0;
}

int f_164808(float f) {
    if (DAT_001a993d == 0) { DAT_001a996c = 0xf002; return 0xf002; }
    if (f < 150.0f || f > 3000.0f) { DAT_001a996c = 0xf005; return 0xf005; }
    DAT_001a9af8 = (int32_t)(f * 65536.0f);
    DAT_001a996c = 0;
    return 0;
}

static uint8_t s_dummy_br_camera[64];

int f_164994(int width, int height, int set_mode) {
    if (DAT_001a993d != 0) {
        f_163050((int)(uintptr_t)(&riva_dgroup_base[0x1b9b30 - 0x1a0000]));
        DAT_001a996c = 0xf003;
        return 0xf003;
    }
    if (width < 10 || width > 640 || height < 10 || height > 400) {
        DAT_001a996c = 0xf005;
        return 0xf005;
    }
    DAT_001a9988 = height;
    DAT_001a9990 = height;
    DAT_001cdc24 = 0;
    DAT_001cdc22 = 0;
    DAT_001cdb44 = width / 2;
    DAT_001cdb48 = height / 2;
    DAT_001a9984 = width;
    DAT_001a998c = width;

    f_17b3c0();
    uint8_t *pm = (uint8_t *)f_1781c8(3, width, height, 0, 0);
    DAT_001cd320 = (int32_t)(uintptr_t)pm;
    if (!pm) {
        f_17b4b8();
        DAT_001a996c = 0xf005;
        return 0xf005;
    }
    f_176784();

    DAT_001a9a3c = 4000;
    DAT_001a9a40 = 600;
    DAT_001a9a44 = 800;
    DAT_001a9a48 = 2000;
    f_163e30();
    f_16fc08();
    f_164408();

    DAT_001a991c = *(int32_t *)(pm + 4);
    int stride = *(int32_t *)(pm + 0x10) & 0xffff;
    int h = *(uint16_t *)(pm + 0x1a);
    DAT_001a9a60 = stride;
    DAT_001a9994 = stride;
    DAT_001a9a5c = h;
    DAT_001a9998 = h;
    DAT_001a9920 = DAT_001a991c;
    DAT_001cdb78 = DAT_001a991c;

    DAT_001cd2ac = (int32_t)(uintptr_t)(&DAT_001cd248);
    DAT_001cd2b4 = 0;
    DAT_001cd2b8 = (int32_t)(uintptr_t)(&riva_dgroup_base[0x1b9bd4 - 0x1a0000]);
    DAT_001cd2b6 = 0;
    DAT_001cd258 = 1;
    DAT_001cd25a = 3;
    DAT_001cd254 = (int32_t)(uintptr_t)(&DAT_001cd2a4);
    DAT_001cd2fc = 0;
    DAT_001cd250 = 0;

    /* Safe non-NULL camera struct pointer (avoids DOS4GW NULL write at 0x00000004) */
    DAT_001cd2a0 = (int32_t)(uintptr_t)s_dummy_br_camera;
    s_dummy_br_camera[4] = 1;
    *(int16_t *)(s_dummy_br_camera + 6) = DAT_001cdc18;
    *(int32_t *)(s_dummy_br_camera + 8) = DAT_001a9ad8;
    *(int32_t *)(s_dummy_br_camera + 12) = DAT_001a9adc;
    *(int32_t *)(s_dummy_br_camera + 16) = DAT_001a9ad4;

    f_163a98(0x28);
    f_16232c(0x28);
    DAT_001a993d = 1;
    DAT_001a9940 = 0;
    DAT_001a994e = 0;
    DAT_001a996c = 0;
    DAT_001a994b = 0;
    DAT_001a993e = 0;
    DAT_001a9941 = 0;
    DAT_001a9944 = 0;
    DAT_001a994c = 0;
    return 0;
}


/* ==== 187B30-187BDC  (nach Attic)  fremd? ==== */


bool f_187b30(byte *p1,byte *p2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (p1 == (byte *)0x0) {
    return true;
  }
  if (p2 == (byte *)0x0) {
    return false;
  }
  do {
    bVar1 = *p1;
    if (bVar1 < 0x2a) {
      if (bVar1 == 0) {
LAB_00187b63:
        return *p2 == 0;
      }
LAB_00187ba2:
      bVar1 = *p2;
      if ((bVar1 < 0x61) || (bVar1 != 0x7a && 0x79 < bVar1)) {
        uVar3 = (uint)*p2;
      }
      else {
        uVar3 = bVar1 - 0x20;
      }
      bVar1 = *p1;
      if ((bVar1 < 0x61) || (bVar1 != 0x7a && 0x79 < bVar1)) {
        uVar4 = (uint)*p1;
      }
      else {
        uVar4 = bVar1 - 0x20;
      }
      if (uVar3 != uVar4) {
        return false;
      }
    }
    else {
      if (bVar1 < 0x2b) {
        do {
          iVar2 = f_187b30(p1 + 1,p2);
          if (iVar2 != 0) {
            return true;
          }
          bVar1 = *p2;
          p2 = p2 + 1;
        } while (bVar1 != 0);
        return false;
      }
      if (bVar1 < 0x2f) goto LAB_00187ba2;
      if (bVar1 < 0x30) goto LAB_00187b63;
      if (bVar1 != 0x3f) goto LAB_00187ba2;
      if (*p2 == 0) {
        return false;
      }
    }
    p1 = p1 + 1;
    p2 = p2 + 1;
  } while( true );
}




/* ==== 187BDC-187BF0  (nach Attic)  fremd? ==== */


int f_187bdc(int p1)

{
  f_187e30(p1);
  *(undefined4 *)(p1 + 0xc) = 0;
  return p1;
}




/* ==== 187BF0-187C18  (nach Attic)  fremd? ==== */


undefined4 * f_187bf0(undefined4 *p1)

{
  int *p1_00;
  
  while( true ) {
    p1_00 = (int *)*p1;
    if (*p1_00 == 0) break;
    f_187eb0(p1_00);
    f_18850c(p1_00);
  }
  p1[3] = 0;
  return p1;
}




/* ==== 187C18-187C4C  (nach Attic)  fremd? ==== */


undefined4 f_187c18(int p1,undefined4 p2)

{
  int p2_00;
  
  p2_00 = f_188404(DAT_001d49b0,0xc,0x12);
  *(undefined4 *)(p2_00 + 8) = p2;
  f_187e44(p1,p2_00);
  *(int *)(p1 + 0xc) = *(int *)(p1 + 0xc) + 1;
  return p2;
}




/* ==== 187C4C-187CA0  (nach Attic)  fremd? ==== */


int f_187c4c(int p1,undefined4 *p2,int p3)

{
  undefined4 uVar1;
  int p2_00;
  int iVar2;
  
  iVar2 = 0;
  if (0 < p3) {
    do {
      uVar1 = *p2;
      p2_00 = f_188404(DAT_001d49b0,0xc,0x12);
      *(undefined4 *)(p2_00 + 8) = uVar1;
      p2 = p2 + 1;
      f_187e44(p1,p2_00);
      iVar2 = iVar2 + 1;
      *(int *)(p1 + 0xc) = *(int *)(p1 + 0xc) + 1;
    } while (iVar2 < p3);
  }
  return p3;
}




/* ==== 187CA0-187CE0  (nach Attic)  fremd? ==== */


int f_187ca0(undefined4 *p1,int p2)

{
  int *p1_00;
  int iVar1;
  
  p1_00 = (int *)*p1;
  iVar1 = *p1_00;
  while ((iVar1 != 0 && (p2 != p1_00[2]))) {
    p1_00 = (int *)*p1_00;
    iVar1 = *p1_00;
  }
  if (*p1_00 != 0) {
    f_187eb0(p1_00);
    iVar1 = p1_00[2];
    f_18850c(p1_00);
    p1[3] = p1[3] + -1;
    return iVar1;
  }
  return 0;
}




/* ==== 187CE0-187D10  (nach Attic)  fremd? ==== */


int f_187ce0(undefined4 p1,undefined4 *p2,int p3)

{
  undefined4 p2_00;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < p3) {
    do {
      p2_00 = *p2;
      p2 = p2 + 1;
      iVar1 = f_187ca0(p1,p2_00);
      if (iVar1 != 0) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < p3);
  }
  return iVar3;
}




/* ==== 187D10-187D54  (nach Attic)  fremd? ==== */


int f_187d10(undefined4 *p1,undefined4 p2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*p1;
  iVar2 = *piVar1;
  while (iVar2 != 0) {
    iVar2 = f_187b30(p2,*(undefined4 *)piVar1[2]);
    if (iVar2 != 0) {
      return piVar1[2];
    }
    piVar1 = (int *)*piVar1;
    iVar2 = *piVar1;
  }
  if (p1[4] == 0) {
    return 0;
  }
  iVar2 = (*(code *)p1[4])(p2);
  return iVar2;
}




/* ==== 187D54-187D94  (nach Attic)  fremd? ==== */


int f_187d54(undefined4 *p1,undefined4 p2,int *p3,int p4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)*p1;
  iVar2 = *piVar1;
  iVar3 = 0;
  while ((iVar2 != 0 && (iVar3 < p4))) {
    iVar2 = f_187b30(p2,*(undefined4 *)piVar1[2]);
    piVar4 = p3;
    if (iVar2 != 0) {
      piVar4 = p3 + 1;
      iVar3 = iVar3 + 1;
      *p3 = piVar1[2];
    }
    piVar1 = (int *)*piVar1;
    iVar2 = *piVar1;
    p3 = piVar4;
  }
  return iVar3;
}




/* ==== 187D94-187DCC  (nach Attic)  fremd? ==== */


int f_187d94(undefined4 *p1,int p2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (p2 != 0) {
    piVar1 = (int *)*p1;
    iVar3 = 0;
    iVar2 = *piVar1;
    while (iVar2 != 0) {
      iVar2 = f_187b30(p2,*(undefined4 *)piVar1[2]);
      if (iVar2 != 0) {
        iVar3 = iVar3 + 1;
      }
      piVar1 = (int *)*piVar1;
      iVar2 = *piVar1;
    }
    return iVar3;
  }
  return p1[3];
}




/* ==== 187DCC-187E30  (nach Attic)  fremd? ==== */


int f_187dcc(int p1,int p2,code *p3,undefined4 p4)

{
  int iVar1;
  int iVar2;
  
  if (p2 == 0) {
    iVar1 = *(int *)(p1 + 8);
    iVar2 = *(int *)(iVar1 + 4);
    while (iVar2 != 0) {
      iVar2 = (*p3)(*(undefined4 *)(iVar1 + 8),p4);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar1 = *(int *)(iVar1 + 4);
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  else {
    iVar1 = *(int *)(p1 + 8);
    iVar2 = *(int *)(iVar1 + 4);
    while (iVar2 != 0) {
      iVar2 = f_187b30(p2,**(undefined4 **)(iVar1 + 8));
      if ((iVar2 != 0) && (iVar2 = (*p3)(*(undefined4 *)(iVar1 + 8),p4), iVar2 != 0)) {
        return iVar2;
      }
      iVar1 = *(int *)(iVar1 + 4);
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  return 0;
}




/* ==== 187E30-187E44  (nach Attic)  fremd? ==== */


void f_187e30(int *p1)

{
  p1[1] = 0;
  *p1 = (int)(p1 + 1);
  p1[2] = (int)p1;
  return;
}




/* ==== 187E44-187EA0  (nach Attic)  fremd? ==== */


void f_187e44(int *p1,int *p2)

{
  int iVar1;
  
  p2[1] = (int)p1;
  iVar1 = *p1;
  *p2 = iVar1;
  *(int **)(iVar1 + 4) = p2;
  *p1 = (int)p2;
  return;
}




/* ==== 187EA0-187EB0  (nach Attic)  fremd? ==== */


void f_187ea0(undefined4 p1,int *p2,int *p3)

{
  *p3 = *p2;
  p3[1] = (int)p2;
  *(int **)(*p2 + 4) = p3;
  *p2 = (int)p3;
  return;
}




/* ==== 187EB0-187EC4  (nach Attic)  fremd? ==== */


void f_187eb0(int *p1)

{
  int *piVar1;
  
  piVar1 = (int *)p1[1];
  *(int **)(*p1 + 4) = piVar1;
  *piVar1 = *p1;
  return;
}




/* ==== 187EC4-187ECC  (nach Attic)  fremd? ==== */


void f_187ec4(undefined4 *p1)

{
  *p1 = 0;
  return p1;
}




/* ==== 187ECC-187F2C  (nach Attic)  fremd? ==== */


void f_187ecc(int *p1,int *p2)

{
  *p2 = *p1;
  p2[1] = (int)p1;
  if (*p2 != 0) {
    *(int **)(*p2 + 4) = p2;
  }
  *p1 = (int)p2;
  return;
}




/* ==== 187F2C-187F7C  (nach Attic)  fremd? ==== */


int *f_187f2c(int *p1)

{
  int iVar1;
  
  iVar1 = *p1;
  *(int *)p1[1] = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 4) = p1[1];
  }
  p1[1] = 0;
  *p1 = 0;
  return p1;
}




/* ==== 187F7C-188260  (nach Attic)  fremd? ==== */


void f_187f7c(uint *p1,ushort *p2)

{
  ushort *p1_00;
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint p1_01;
  undefined4 unaff_ECX;
  int p3;
  int p2_00;
  int p4;
  uint *puVar4;
  uint local_38;
  uint local_34;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  if (*p2 < 7) {
    p1_00 = p2 + 2;
    switch(*p2) {
    default:
      puVar4 = (uint *)(p2 + 2);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *p1 = *puVar4;
        puVar4 = puVar4 + 1;
        p1 = p1 + 1;
      }
      return;
    case 2:
      f_195bbc(p1,p1_00);
      p1[9] = *(uint *)(p2 + 0x14);
      p1[10] = *(uint *)(p2 + 0x16);
      p1[0xb] = *(uint *)(p2 + 0x18);
      return;
    case 3:
      f_195f00((int)p1, (ushort *)p1_00, 0, 0);
      p1[9] = *(uint *)(p2 + 0x14);
      p1[10] = *(uint *)(p2 + 0x16);
      p1[0xb] = *(uint *)(p2 + 0x18);
      return;
    case 4:
      iVar2 = f_16d4fc(*(int *)(p2 + 2), *(int *)(p2 + 4), *(int *)(p2 + 6));
      if (iVar2 < 3) {
        uVar3 = 0;
        local_38 = 0x7fff;
        local_34 = 0;
      }
      else {
        iVar2 = (int)(0x100000000 / (longlong)iVar2);
        local_38 = (uint)((longlong)*(int *)(p2 + 2) * (longlong)iVar2) >> 0x10 |
                   (int)((ulonglong)((longlong)*(int *)(p2 + 2) * (longlong)iVar2) >> 0x20) << 0x10;
        local_34 = (uint)((longlong)*(int *)(p2 + 4) * (longlong)iVar2) >> 0x10 |
                   (int)((ulonglong)((longlong)*(int *)(p2 + 4) * (longlong)iVar2) >> 0x20) << 0x10;
        uVar3 = (uint)((longlong)*(int *)(p2 + 6) * (longlong)iVar2) >> 0x10 |
                (int)((ulonglong)((longlong)*(int *)(p2 + 6) * (longlong)iVar2) >> 0x20) << 0x10;
      }
      local_38 = -local_38;
      local_34 = -local_34;
      uVar3 = -uVar3;
      p3 = ((uint)((longlong)*(int *)(p2 + 10) * (longlong)(int)uVar3) >> 0x10 |
           (int)((ulonglong)((longlong)*(int *)(p2 + 10) * (longlong)(int)uVar3) >> 0x20) << 0x10) -
           ((uint)((longlong)*(int *)(p2 + 0xc) * (longlong)(int)local_34) >> 0x10 |
           (int)((ulonglong)((longlong)*(int *)(p2 + 0xc) * (longlong)(int)local_34) >> 0x20) <<
           0x10);
      p2_00 = ((uint)((longlong)*(int *)(p2 + 0xc) * (longlong)(int)local_38) >> 0x10 |
              (int)((ulonglong)((longlong)*(int *)(p2 + 0xc) * (longlong)(int)local_38) >> 0x20) <<
              0x10) - ((uint)((longlong)*(int *)(p2 + 8) * (longlong)(int)uVar3) >> 0x10 |
                      (int)((ulonglong)((longlong)*(int *)(p2 + 8) * (longlong)(int)uVar3) >> 0x20)
                      << 0x10);
      p1_01 = (uint)((longlong)*(int *)(p2 + 10) * (longlong)(int)local_38) >> 0x10 |
              (int)((ulonglong)((longlong)*(int *)(p2 + 10) * (longlong)(int)local_38) >> 0x20) <<
              0x10;
      p4 = ((uint)((longlong)*(int *)(p2 + 8) * (longlong)(int)local_34) >> 0x10 |
           (int)((ulonglong)((longlong)*(int *)(p2 + 8) * (longlong)(int)local_34) >> 0x20) << 0x10)
           - p1_01;
      iVar2 = f_16d4fc(p3, p2_00, p4);
      if (iVar2 < 3) {
        local_20 = 0x7fff;
        local_1c = 0;
        local_18 = 0;
      }
      else {
        iVar2 = (int)(0x100000000 / (longlong)iVar2);
        lVar1 = (longlong)p3 * (longlong)iVar2;
        local_20 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
        lVar1 = (longlong)p2_00 * (longlong)iVar2;
        local_1c = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
        lVar1 = (longlong)p4 * (longlong)iVar2;
        local_18 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
      }
      p1[5] = ((uint)((longlong)(int)local_38 * (longlong)(int)local_1c) >> 0x10 |
              (int)((ulonglong)((longlong)(int)local_38 * (longlong)(int)local_1c) >> 0x20) << 0x10)
              - ((uint)((longlong)(int)local_34 * (longlong)(int)local_20) >> 0x10 |
                (int)((ulonglong)((longlong)(int)local_34 * (longlong)(int)local_20) >> 0x20) <<
                0x10);
      *p1 = local_20;
      p1[1] = local_1c;
      p1[2] = local_18;
      p1[3] = ((uint)((longlong)(int)local_34 * (longlong)(int)local_18) >> 0x10 |
              (int)((ulonglong)((longlong)(int)local_34 * (longlong)(int)local_18) >> 0x20) << 0x10)
              - ((uint)((longlong)(int)uVar3 * (longlong)(int)local_1c) >> 0x10 |
                (int)((ulonglong)((longlong)(int)uVar3 * (longlong)(int)local_1c) >> 0x20) << 0x10);
      p1[4] = ((uint)((longlong)(int)uVar3 * (longlong)(int)local_20) >> 0x10 |
              (int)((ulonglong)((longlong)(int)uVar3 * (longlong)(int)local_20) >> 0x20) << 0x10) -
              ((uint)((longlong)(int)local_38 * (longlong)(int)local_18) >> 0x10 |
              (int)((ulonglong)((longlong)(int)local_38 * (longlong)(int)local_18) >> 0x20) << 0x10)
      ;
      p1[6] = local_38;
      p1[7] = local_34;
      p1[8] = uVar3;
      p1[9] = *(uint *)(p2 + 0x14);
      p1[10] = *(uint *)(p2 + 0x16);
      p1[0xb] = *(uint *)(p2 + 0x18);
      return;
    case 5:
      f_16bc24(p1,*(undefined4 *)(p2 + 0x14),*(undefined4 *)(p2 + 0x16),*(undefined4 *)(p2 + 0x18));
      return;
    case 6:
      f_16b930(p1);
    }
  }
  return;
}




/* ==== 188260-1882CC  (nach Attic)  fremd? ==== */


void f_188260(undefined4 p1,short *p2)

{
  undefined1 auStack_34 [48];
  
  if (*p2 != 6) {
    f_187f7c(auStack_34,p2);
    f_16cb84(p1,auStack_34);
  }
  return;
}




/* ==== 1882CC-1883E0  (nach Attic)  fremd? ==== */


void f_1882cc(ushort *p1,undefined4 *p2)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  if (*p1 < 7) {
    puVar2 = p1 + 2;
    switch(*p1) {
    case 0:
      puVar2 = p1 + 2;
      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)puVar2 = *p2;
        p2 = p2 + 1;
        puVar2 = puVar2 + 2;
      }
      return;
    case 1:
      puVar3 = p1 + 2;
      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)puVar3 = *p2;
        p2 = p2 + 1;
        puVar3 = puVar3 + 2;
      }
      f_16c24c(puVar2,puVar2);
      return;
    case 2:
      f_195ce8(puVar2,p2);
      break;
    case 3:
      f_196280(puVar2,p2);
      break;
    case 4:
      *(undefined4 *)(p1 + 2) = p2[6];
      *(undefined4 *)(p1 + 4) = p2[7];
      iVar1 = p2[8];
      *(int *)(p1 + 6) = iVar1;
      if (((*(int *)(p1 + 2) == 0) && (*(int *)(p1 + 4) == 0)) && (iVar1 == 0)) {
        p1[4] = 0;
        p1[5] = 1;
        p1[6] = 0;
        p1[7] = 0;
      }
      break;
    case 6:
      goto switchD_001882f0_caseD_6;
    }
    *(undefined4 *)(p1 + 0x14) = p2[9];
    *(undefined4 *)(p1 + 0x16) = p2[10];
    *(undefined4 *)(p1 + 0x18) = p2[0xb];
  }
switchD_001882f0_caseD_6:
  return;
}




/* ==== 1883E0-188404  (nach Attic)  fremd? ==== */


uint f_1883e0(int p1)

{
  return p1 + 0x27U & 0xfffffff0;
}




/* ==== 188404-188490  (nach Attic)  fremd? ==== */


uint f_188404(int p1,int p2,undefined4 p3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int p2_00;
  uint uVar4;
  
  uVar4 = p2 + 0x1fU >> 3;
  p2_00 = f_196810(uVar4 * 8 + 0xf,(uint)(byte)p3);
  *(undefined1 *)(p2_00 + 0xc) = 0;
  uVar2 = *(uint *)(p2_00 + 0xc);
  *(uint *)(p2_00 + 0xc) = uVar2 | (byte)p3;
  *(uint *)(p2_00 + 0xc) = uVar2 & 0xff | (uint)(byte)p3 | uVar4 << 8;
  f_187ec4(p2_00 + 8);
  *(undefined4 *)(p2_00 + 0x14) = 0xdeadbeef;
  *(int *)(p2_00 + 0x10) = p2_00;
  if (p1 != 0) {
    iVar3 = *(int *)(p1 + -4);
    while (iVar3 == 0) {
      piVar1 = (int *)(p1 + -8);
      p1 = p1 + -4;
      iVar3 = *piVar1;
    }
    f_187ecc(p1 + -0x10,p2_00);
  }
  return p2_00 + 0x27U & 0xfffffff0;
}




/* ==== 18850C-188580  (nach Attic)  fremd? ==== */


void f_18850c(int p1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(p1 + -4);
  while (iVar2 == 0) {
    piVar1 = (int *)(p1 + -8);
    p1 = p1 + -4;
    iVar2 = *piVar1;
  }
  f_188490(p1 + -0x18);
  return;
}




/* ==== 188580-1885C8  (nach Attic)  fremd? ==== */


int f_188580(int p1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(p1 + -4);
  iVar3 = p1;
  while (iVar2 == 0) {
    piVar1 = (int *)(iVar3 + -8);
    iVar3 = iVar3 + -4;
    iVar2 = *piVar1;
  }
  f_187f2c(iVar3 + -0x18);
  return p1;
}




/* ==== 1885C8-188630  (nach Attic)  fremd? ==== */


int f_1885c8(int p1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(p1 + -4);
  while (iVar2 == 0) {
    piVar1 = (int *)(p1 + -8);
    p1 = p1 + -4;
    iVar2 = *piVar1;
  }
  return (*(int *)(p1 + -0xc) >> 8) << 3;
}




/* ==== 188630-188664  (nach Attic)  fremd? ==== */


undefined4 f_188630(int p1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(p1 + -4);
  while (iVar2 == 0) {
    piVar1 = (int *)(p1 + -8);
    p1 = p1 + -4;
    iVar2 = *piVar1;
  }
  if ((p1 + -0x18 == *(int *)(p1 + -8)) && (*(int *)(*(int *)(p1 + -8) + 0x14) == -0x21524111)) {
    return 1;
  }
  return 0;
}




/* ==== 188664-188C94  (nach Attic)  fremd? ==== */


char * f_188664(undefined4 p1,char *p2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = p2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)f_188404(p1,~uVar3,0x11);
  pcVar4 = pcVar2;
  do {
    cVar1 = *p2;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return pcVar2;
    }
    cVar1 = p2[1];
    p2 = p2 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  return pcVar2;
}




/* ==== 188C94-188D48  (nach Attic)  fremd? ==== */


int f_188c94(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = (longlong)-p3 * (longlong)p5;
  lVar2 = (longlong)-p3 * (longlong)p8;
  lVar3 = (longlong)p1 *
          (longlong)
          (int)(((uint)((longlong)-p6 * (longlong)p8) >> 0x10 |
                (int)((ulonglong)((longlong)-p6 * (longlong)p8) >> 0x20) << 0x10) +
               ((uint)((longlong)p5 * (longlong)p9) >> 0x10 |
               (int)((ulonglong)((longlong)p5 * (longlong)p9) >> 0x20) << 0x10));
  lVar2 = (longlong)-p4 *
          (longlong)
          (int)(((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10) +
               ((uint)((longlong)p2 * (longlong)p9) >> 0x10 |
               (int)((ulonglong)((longlong)p2 * (longlong)p9) >> 0x20) << 0x10));
  lVar1 = (longlong)p7 *
          (longlong)
          (int)(((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
               ((uint)((longlong)p2 * (longlong)p6) >> 0x10 |
               (int)((ulonglong)((longlong)p2 * (longlong)p6) >> 0x20) << 0x10));
  return ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
         ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10) +
         ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
}




/* ==== 188D48-188EC4  (nach Attic)  fremd? ==== */


int f_188d48(int *p1)

{
  int iVar1;
  int p3;
  int iVar2;
  int p7;
  int p5;
  int p6;
  int iVar3;
  int p2;
  int p8;
  int iVar4;
  int p1_00;
  int p3_00;
  int p1_01;
  int p9;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = *p1;
  iVar7 = p1[6];
  iVar8 = p1[9];
  p3 = p1[0xd];
  iVar2 = p1[1];
  p7 = p1[7];
  p5 = p1[10];
  p6 = p1[0xe];
  iVar3 = p1[2];
  p2 = p1[8];
  p8 = p1[0xb];
  iVar4 = p1[3];
  p1_00 = p1[4];
  p3_00 = p1[0xc];
  p1_01 = p1[5];
  p9 = p1[0xf];
  iVar5 = f_188c94(p1_00,p2,p3_00,iVar7,p5,p6,p7,p8,p9);
  iVar6 = f_188c94(p1_01,iVar8,p3,iVar7,p5,p6,p7,p8,p9);
  iVar7 = f_188c94(p1_00,p2,p3_00,p1_01,iVar8,p3,iVar7,p5,p6);
  iVar8 = f_188c94(p1_00,p2,p3_00,p1_01,iVar8,p3,p7,p8,p9);
  return ((uint)((longlong)-iVar4 * (longlong)iVar7) >> 0x10 |
         (int)((ulonglong)((longlong)-iVar4 * (longlong)iVar7) >> 0x20) << 0x10) +
         ((uint)((longlong)iVar3 * (longlong)iVar8) >> 0x10 |
         (int)((ulonglong)((longlong)iVar3 * (longlong)iVar8) >> 0x20) << 0x10) +
         ((uint)((longlong)-iVar2 * (longlong)iVar5) >> 0x10 |
         (int)((ulonglong)((longlong)-iVar2 * (longlong)iVar5) >> 0x20) << 0x10) +
         ((uint)((longlong)iVar1 * (longlong)iVar6) >> 0x10 |
         (int)((ulonglong)((longlong)iVar1 * (longlong)iVar6) >> 0x20) << 0x10);
}




/* ==== 188EC4-189284  (nach Attic)  fremd? ==== */


void f_188ec4(undefined4 *p1,undefined4 *p2)

{
  undefined4 p4;
  undefined4 p7;
  undefined4 p1_00;
  undefined4 p1_01;
  undefined4 p4_00;
  undefined4 p7_00;
  undefined4 p2_00;
  undefined4 p5;
  undefined4 p8;
  undefined4 p6;
  undefined4 p1_02;
  undefined4 p2_01;
  undefined4 p3;
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = *p2;
  p4 = p2[2];
  p7 = p2[3];
  p1_00 = p2[4];
  p1_01 = p2[5];
  p4_00 = p2[6];
  p7_00 = p2[7];
  p2_00 = p2[9];
  p5 = p2[10];
  p8 = p2[0xb];
  uVar4 = p2[0xd];
  p6 = p2[0xe];
  p1_02 = p2[1];
  uVar3 = p2[0xf];
  p2_01 = p2[8];
  p3 = p2[0xc];
  uVar1 = f_188c94(p1_01,p2_00,uVar4,p4_00,p5,p6,p7_00,p8,uVar3);
  *p1 = uVar1;
  iVar2 = f_188c94(p1_00,p2_01,p3,p4_00,p5,p6,p7_00,p8,uVar3);
  p1[4] = -iVar2;
  uVar1 = f_188c94(p1_00,p2_01,p3,p1_01,p2_00,uVar4,p7_00,p8,uVar3);
  p1[8] = uVar1;
  iVar2 = f_188c94(p1_00,p2_01,p3,p1_01,p2_00,uVar4,p4_00,p5,p6);
  p1[0xc] = -iVar2;
  uVar1 = f_188c94(p1_02,p2_00,uVar4,p4,p5,p6,p7,p8,uVar3);
  p1[1] = uVar1;
  p1[1] = -p1[1];
  uVar1 = f_188c94(uVar5,p2_01,p3,p4,p5,p6,p7,p8,uVar3);
  p1[5] = uVar1;
  uVar1 = f_188c94(uVar5,p2_01,p3,p1_02,p2_00,uVar4,p7,p8,uVar3);
  p1[9] = uVar1;
  p1[9] = -p1[9];
  uVar1 = f_188c94(uVar5,p2_01,p3,p1_02,p2_00,uVar4,p4,p5,p6);
  p1[0xd] = uVar1;
  uVar1 = f_188c94(p1_02,p1_01,uVar4,p4,p4_00,p6,p7,p7_00,uVar3);
  p1[2] = uVar1;
  uVar1 = f_188c94(uVar5,p1_00,p3,p4,p4_00,p6,p7,p7_00,uVar3);
  p1[6] = uVar1;
  p1[6] = -p1[6];
  uVar3 = f_188c94(uVar5,p1_00,p3,p1_02,p1_01,uVar4,p7,p7_00,uVar3);
  p1[10] = uVar3;
  iVar2 = f_188c94(uVar5,p1_00,p3,p1_02,p1_01,uVar4,p4,p4_00,p6);
  p1[0xe] = -iVar2;
  uVar4 = f_188c94(p1_02,p1_01,p2_00,p4,p4_00,p5,p7,p7_00,p8);
  p1[3] = uVar4;
  p1[3] = -p1[3];
  uVar4 = f_188c94(uVar5,p1_00,p2_01,p4,p4_00,p5,p7,p7_00,p8);
  p1[7] = uVar4;
  iVar2 = f_188c94(uVar5,p1_00,p2_01,p1_02,p1_01,p2_00,p7,p7_00,p8);
  p1[0xb] = -iVar2;
  uVar5 = f_188c94(uVar5,p1_00,p2_01,p1_02,p1_01,p2_00,p4,p4_00,p5);
  p1[0xf] = uVar5;
  return;
}




/* ==== 189284-1896C0  (nach Attic)  fremd? ==== */


void f_189284(undefined4 *p1,uint p2,int p3,int p4,int p5)

{
  uint p1_00;
  int iVar1;
  int iVar2;
  
  p1_00 = (p2 & 0xffff) / 2;
  iVar1 = f_16d7e7((uint16_t)p1_00);
  iVar2 = f_16d818((uint16_t)p1_00);
  iVar1 = (int)(CONCAT44(iVar2 >> 0x10,iVar2 << 0x10) / (longlong)iVar1);
  p1[5] = iVar1;
  *p1 = (int)(CONCAT44(iVar1 >> 0x10,iVar1 << 0x10) / (longlong)p3);
  p1[10] = (int)(CONCAT44(p5 + p4 >> 0x10,(p5 + p4) * 0x10000) / (longlong)(p5 - p4));
  p1[1] = 0;
  p1[2] = 0;
  p1[3] = 0;
  p1[4] = 0;
  p1[6] = 0;
  p1[7] = 0;
  p1[8] = 0;
  p1[9] = 0;
  p1[0xb] = 0xffff0000;
  p1[0xc] = 0;
  p1[0xd] = 0;
  p1[0xf] = 0;
  p1[0xe] = (int)(((longlong)p5 * (longlong)p4) / (longlong)(p5 - p4)) * -2;
  return;
}




/* ==== 1896C0-189900  (nach Attic)  fremd? ==== */


void f_1896c0(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[1] * (longlong)p3[1]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[1]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[3] * (longlong)p3[3]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[3] * (longlong)p3[3]) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[2] * (longlong)p3[2]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[2]) >> 0x20) << 0x10);
  p1[1] = ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[4]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[3] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10);
  p1[2] = ((uint)((longlong)p2[1] * (longlong)p3[9]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[9]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[3] * (longlong)p3[0xb]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)p3[0xb]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[10]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[10]) >> 0x20) << 0x10);
  p1[3] = ((uint)((longlong)p2[1] * (longlong)p3[0xd]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[0xd]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[0xc]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[0xc]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[3] * (longlong)p3[0xf]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)p3[0xf]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[0xe]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[0xe]) >> 0x20) << 0x10);
  return;
}




/* ==== 189900-189A0C  (nach Attic)  fremd? ==== */


void f_189900(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[2] * (longlong)p3[2]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[2]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[1] * (longlong)p3[1]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[1]) >> 0x20) << 0x10);
  p1[1] = ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[4]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10);
  p1[2] = ((uint)((longlong)p2[2] * (longlong)p3[10]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[10]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[9]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[9]) >> 0x20) << 0x10);
  p1[3] = ((uint)((longlong)p2[2] * (longlong)p3[0xe]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[0xe]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[0xc]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[0xc]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[0xd]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[0xd]) >> 0x20) << 0x10);
  return;
}




/* ==== 189A0C-189A74  (nach Attic)  fremd? ==== */


void f_189a0c(undefined4 *p1,undefined4 *p2)

{
  undefined4 uVar1;
  
  *p1 = *p2;
  p1[1] = p2[1];
  p1[2] = p2[2];
  p1[4] = p2[3];
  p1[5] = p2[4];
  p1[6] = p2[5];
  p1[8] = p2[6];
  p1[9] = p2[7];
  p1[10] = p2[8];
  p1[0xc] = p2[9];
  p1[0xd] = p2[10];
  uVar1 = p2[0xb];
  p1[3] = 0;
  p1[7] = 0;
  p1[0xb] = 0;
  p1[0xf] = 0x10000;
  p1[0xe] = uVar1;
  return;
}




/* ==== 189A74-189DF8  (nach Attic)  fremd? ==== */


void f_189a74(int *p1,int *p2)

{
  int iVar1;
  int *piVar2;
  int local_58 [16];
  #define local_48 (local_58[4])
  #define local_44 (local_58[5])
  #define local_40 (local_58[6])
  #define local_3c (local_58[7])
  #define local_38 (local_58[8])
  #define local_34 (local_58[9])
  #define local_30 (local_58[10])
  #define local_2c (local_58[11])
  #define local_28 (local_58[12])
  #define local_24 (local_58[13])
  #define local_20 (local_58[14])
  #define local_1c (local_58[15])
  int *local_18;
  
  piVar2 = local_58;
  local_18 = p1;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = *p1;
    p1 = p1 + 1;
    piVar2 = piVar2 + 1;
  }
  *local_18 = ((uint)((longlong)p2[2] * (longlong)local_38) >> 0x10 |
              (int)((ulonglong)((longlong)p2[2] * (longlong)local_38) >> 0x20) << 0x10) +
              ((uint)((longlong)*p2 * (longlong)local_58[0]) >> 0x10 |
              (int)((ulonglong)((longlong)*p2 * (longlong)local_58[0]) >> 0x20) << 0x10) +
              ((uint)((longlong)p2[1] * (longlong)local_48) >> 0x10 |
              (int)((ulonglong)((longlong)p2[1] * (longlong)local_48) >> 0x20) << 0x10);
  local_18[1] = ((uint)((longlong)p2[2] * (longlong)local_34) >> 0x10 |
                (int)((ulonglong)((longlong)p2[2] * (longlong)local_34) >> 0x20) << 0x10) +
                ((uint)((longlong)*p2 * (longlong)local_58[1]) >> 0x10 |
                (int)((ulonglong)((longlong)*p2 * (longlong)local_58[1]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[1] * (longlong)local_44) >> 0x10 |
                (int)((ulonglong)((longlong)p2[1] * (longlong)local_44) >> 0x20) << 0x10);
  local_18[2] = ((uint)((longlong)p2[2] * (longlong)local_30) >> 0x10 |
                (int)((ulonglong)((longlong)p2[2] * (longlong)local_30) >> 0x20) << 0x10) +
                ((uint)((longlong)*p2 * (longlong)local_58[2]) >> 0x10 |
                (int)((ulonglong)((longlong)*p2 * (longlong)local_58[2]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[1] * (longlong)local_40) >> 0x10 |
                (int)((ulonglong)((longlong)p2[1] * (longlong)local_40) >> 0x20) << 0x10);
  local_18[3] = ((uint)((longlong)p2[2] * (longlong)local_2c) >> 0x10 |
                (int)((ulonglong)((longlong)p2[2] * (longlong)local_2c) >> 0x20) << 0x10) +
                ((uint)((longlong)*p2 * (longlong)local_58[3]) >> 0x10 |
                (int)((ulonglong)((longlong)*p2 * (longlong)local_58[3]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[1] * (longlong)local_3c) >> 0x10 |
                (int)((ulonglong)((longlong)p2[1] * (longlong)local_3c) >> 0x20) << 0x10);
  local_18[4] = ((uint)((longlong)p2[5] * (longlong)local_38) >> 0x10 |
                (int)((ulonglong)((longlong)p2[5] * (longlong)local_38) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[3] * (longlong)local_58[0]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[3] * (longlong)local_58[0]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[4] * (longlong)local_48) >> 0x10 |
                (int)((ulonglong)((longlong)p2[4] * (longlong)local_48) >> 0x20) << 0x10);
  local_18[5] = ((uint)((longlong)p2[5] * (longlong)local_34) >> 0x10 |
                (int)((ulonglong)((longlong)p2[5] * (longlong)local_34) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[3] * (longlong)local_58[1]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[3] * (longlong)local_58[1]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[4] * (longlong)local_44) >> 0x10 |
                (int)((ulonglong)((longlong)p2[4] * (longlong)local_44) >> 0x20) << 0x10);
  local_18[6] = ((uint)((longlong)p2[5] * (longlong)local_30) >> 0x10 |
                (int)((ulonglong)((longlong)p2[5] * (longlong)local_30) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[3] * (longlong)local_58[2]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[3] * (longlong)local_58[2]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[4] * (longlong)local_40) >> 0x10 |
                (int)((ulonglong)((longlong)p2[4] * (longlong)local_40) >> 0x20) << 0x10);
  local_18[7] = ((uint)((longlong)p2[5] * (longlong)local_2c) >> 0x10 |
                (int)((ulonglong)((longlong)p2[5] * (longlong)local_2c) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[3] * (longlong)local_58[3]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[3] * (longlong)local_58[3]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[4] * (longlong)local_3c) >> 0x10 |
                (int)((ulonglong)((longlong)p2[4] * (longlong)local_3c) >> 0x20) << 0x10);
  local_18[8] = ((uint)((longlong)p2[8] * (longlong)local_38) >> 0x10 |
                (int)((ulonglong)((longlong)p2[8] * (longlong)local_38) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[6] * (longlong)local_58[0]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[6] * (longlong)local_58[0]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[7] * (longlong)local_48) >> 0x10 |
                (int)((ulonglong)((longlong)p2[7] * (longlong)local_48) >> 0x20) << 0x10);
  local_18[9] = ((uint)((longlong)p2[8] * (longlong)local_34) >> 0x10 |
                (int)((ulonglong)((longlong)p2[8] * (longlong)local_34) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[6] * (longlong)local_58[1]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[6] * (longlong)local_58[1]) >> 0x20) << 0x10) +
                ((uint)((longlong)p2[7] * (longlong)local_44) >> 0x10 |
                (int)((ulonglong)((longlong)p2[7] * (longlong)local_44) >> 0x20) << 0x10);
  local_18[10] = ((uint)((longlong)p2[8] * (longlong)local_30) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[8] * (longlong)local_30) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[6] * (longlong)local_58[2]) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[6] * (longlong)local_58[2]) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[7] * (longlong)local_40) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[7] * (longlong)local_40) >> 0x20) << 0x10);
  local_18[0xb] =
       ((uint)((longlong)p2[8] * (longlong)local_2c) >> 0x10 |
       (int)((ulonglong)((longlong)p2[8] * (longlong)local_2c) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[6] * (longlong)local_58[3]) >> 0x10 |
       (int)((ulonglong)((longlong)p2[6] * (longlong)local_58[3]) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[7] * (longlong)local_3c) >> 0x10 |
       (int)((ulonglong)((longlong)p2[7] * (longlong)local_3c) >> 0x20) << 0x10);
  local_18[0xc] =
       local_28 +
       ((uint)((longlong)p2[0xb] * (longlong)local_38) >> 0x10 |
       (int)((ulonglong)((longlong)p2[0xb] * (longlong)local_38) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[9] * (longlong)local_58[0]) >> 0x10 |
       (int)((ulonglong)((longlong)p2[9] * (longlong)local_58[0]) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[10] * (longlong)local_48) >> 0x10 |
       (int)((ulonglong)((longlong)p2[10] * (longlong)local_48) >> 0x20) << 0x10);
  local_18[0xd] =
       local_24 +
       ((uint)((longlong)p2[0xb] * (longlong)local_34) >> 0x10 |
       (int)((ulonglong)((longlong)p2[0xb] * (longlong)local_34) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[9] * (longlong)local_58[1]) >> 0x10 |
       (int)((ulonglong)((longlong)p2[9] * (longlong)local_58[1]) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[10] * (longlong)local_44) >> 0x10 |
       (int)((ulonglong)((longlong)p2[10] * (longlong)local_44) >> 0x20) << 0x10);
  local_18[0xe] =
       local_20 +
       ((uint)((longlong)p2[0xb] * (longlong)local_30) >> 0x10 |
       (int)((ulonglong)((longlong)p2[0xb] * (longlong)local_30) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[9] * (longlong)local_58[2]) >> 0x10 |
       (int)((ulonglong)((longlong)p2[9] * (longlong)local_58[2]) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[10] * (longlong)local_40) >> 0x10 |
       (int)((ulonglong)((longlong)p2[10] * (longlong)local_40) >> 0x20) << 0x10);
  local_18[0xf] =
       local_1c +
       ((uint)((longlong)p2[0xb] * (longlong)local_2c) >> 0x10 |
       (int)((ulonglong)((longlong)p2[0xb] * (longlong)local_2c) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[9] * (longlong)local_58[3]) >> 0x10 |
       (int)((ulonglong)((longlong)p2[9] * (longlong)local_58[3]) >> 0x20) << 0x10) +
       ((uint)((longlong)p2[10] * (longlong)local_3c) >> 0x10 |
       (int)((ulonglong)((longlong)p2[10] * (longlong)local_3c) >> 0x20) << 0x10);
  #undef local_48
  #undef local_44
  #undef local_40
  #undef local_3c
  #undef local_38
  #undef local_34
  #undef local_30
  #undef local_2c
  #undef local_28
  #undef local_24
  #undef local_20
  #undef local_1c
  return;
}




/* ==== 195940-195BBC  (nach Attic)  fremd? ==== */


uint * f_195940(uint *p1,int *p2)

{
  int iVar1;
  
  iVar1 = f_16d529(p2[0], p2[1], p2[2], p2[3]);
  iVar1 = (int)(0x100000000 / (longlong)iVar1);
  *p1 = (uint)((longlong)*p2 * (longlong)iVar1) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)iVar1) >> 0x20) << 0x10;
  p1[1] = (uint)((longlong)p2[1] * (longlong)iVar1) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)iVar1) >> 0x20) << 0x10;
  p1[2] = (uint)((longlong)p2[2] * (longlong)iVar1) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)iVar1) >> 0x20) << 0x10;
  p1[3] = (uint)((longlong)p2[3] * (longlong)iVar1) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)iVar1) >> 0x20) << 0x10;
  return p1;
}




/* ==== 195BBC-195CE8  (nach Attic)  fremd? ==== */


int * f_195bbc(int *p1,int *p2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar2 = p2[1] * 2;
  lVar1 = (longlong)p2[3] * (longlong)(*p2 * 2);
  uVar4 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  iVar3 = p2[2] * 2;
  uVar5 = (uint)((longlong)p2[3] * (longlong)iVar2) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)iVar2) >> 0x20) << 0x10;
  uVar6 = (uint)((longlong)p2[3] * (longlong)iVar3) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)iVar3) >> 0x20) << 0x10;
  lVar1 = (longlong)*p2 * (longlong)(*p2 * 2);
  uVar7 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  uVar8 = (uint)((longlong)*p2 * (longlong)iVar2) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)iVar2) >> 0x20) << 0x10;
  uVar9 = (uint)((longlong)*p2 * (longlong)iVar3) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)iVar3) >> 0x20) << 0x10;
  uVar10 = (uint)((longlong)p2[1] * (longlong)iVar2) >> 0x10 |
           (int)((ulonglong)((longlong)p2[1] * (longlong)iVar2) >> 0x20) << 0x10;
  uVar11 = (uint)((longlong)p2[1] * (longlong)iVar3) >> 0x10 |
           (int)((ulonglong)((longlong)p2[1] * (longlong)iVar3) >> 0x20) << 0x10;
  uVar12 = (uint)((longlong)p2[2] * (longlong)iVar3) >> 0x10 |
           (int)((ulonglong)((longlong)p2[2] * (longlong)iVar3) >> 0x20) << 0x10;
  p1[3] = uVar8 - uVar6;
  p1[6] = uVar9 + uVar5;
  p1[9] = 0;
  p1[1] = uVar8 + uVar6;
  p1[4] = 0x10000 - (uVar12 + uVar7);
  p1[7] = uVar11 - uVar4;
  p1[10] = 0;
  p1[2] = uVar9 - uVar5;
  p1[0xb] = 0;
  p1[5] = uVar11 + uVar4;
  *p1 = 0x10000 - (uVar12 + uVar10);
  p1[8] = 0x10000 - (uVar10 + uVar7);
  return p1;
}




/* ==== 195CE8-195EC0  (nach Attic)  fremd? ==== */


uint * f_195ce8(uint *p1,int *p2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *p2 + p2[4] + p2[8];
  if (iVar4 < 0) {
    uVar5 = (uint)(*p2 < p2[4]);
    if (p2[uVar5 * 4] < p2[8]) {
      uVar5 = 2;
    }
    iVar4 = *(int *)(&DAT_001b4f3c + uVar5 * 4);
    iVar1 = *(int *)(&DAT_001b4f3c + iVar4 * 4);
    iVar3 = f_16d3d0((p2[uVar5 * 4] - (p2[iVar4 * 4] + p2[iVar1 * 4])) + 0x10000);
    p1[uVar5] = iVar3 / 2;
    iVar3 = (int)(0x80000000 / (longlong)iVar3);
    lVar2 = (longlong)(p2[iVar4 * 3 + iVar1] - p2[iVar1 * 3 + iVar4]) * (longlong)iVar3;
    p1[3] = (uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10;
    lVar2 = (longlong)(p2[uVar5 * 3 + iVar4] + p2[iVar4 * 3 + uVar5]) * (longlong)iVar3;
    p1[iVar4] = (uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10;
    lVar2 = (longlong)(p2[uVar5 * 3 + iVar1] + p2[iVar1 * 3 + uVar5]) * (longlong)iVar3;
    p1[iVar1] = (uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10;
  }
  else {
    iVar4 = f_16d3d0(iVar4 + 0x10000);
    p1[3] = iVar4 / 2;
    iVar4 = (int)(0x80000000 / (longlong)iVar4);
    lVar2 = (longlong)(p2[5] - p2[7]) * (longlong)iVar4;
    *p1 = (uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10;
    lVar2 = (longlong)(p2[6] - p2[2]) * (longlong)iVar4;
    p1[1] = (uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10;
    lVar2 = (longlong)(p2[1] - p2[3]) * (longlong)iVar4;
    p1[2] = (uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10;
  }
  return p1;
}




/* ==== 195EC0-195EE0  (nach Attic)  fremd? ==== */


undefined4 f_195ec0(undefined4 p1,undefined4 p2)

{
  undefined1 auStack_34 [48];
  
  f_195bbc(auStack_34,p2);
  f_189a0c(p1,auStack_34);
  return p1;
}




/* ==== 195EE0-195F00  (nach Attic)  fremd? ==== */


void f_195ee0(undefined4 p1,undefined4 p2)

{
  undefined1 auStack_34 [48];
  
  f_16c544(auStack_34,p2);
  f_195ce8(p1,auStack_34);
  return;
}




/* ==== 195F00-196280  (nach Attic)  fremd? ==== */


int f_195f00(int p1,ushort *p2,undefined4 p3,undefined4 p4)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int p1_00;
  int iVar7;
  int p1_01;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  
  bVar1 = (byte)p2[3];
  if ((bVar1 & 0x10) == 0) {
    uVar2 = *p2;
    uVar3 = p2[1];
    uVar4 = p2[2];
  }
  else {
    uVar2 = p2[2];
    uVar3 = p2[1];
    uVar4 = *p2;
  }
  uVar19 = (uint)uVar3;
  uVar18 = (uint)uVar4;
  uVar15 = CONCAT22((short)((uint)p4 >> 0x10),uVar2);
  if ((bVar1 & 4) != 0) {
    uVar15 = -uVar15;
    uVar19 = -uVar19;
    uVar18 = -uVar18;
  }
  iVar5 = f_16d818(uVar15 & 0xffff);
  uVar6 = f_16d818(uVar19 & 0xffff);
  p1_00 = f_16d818(uVar18 & 0xffff);
  iVar7 = f_16d7e7(uVar15 & 0xffff);
  p1_01 = f_16d7e7(uVar19 & 0xffff);
  iVar8 = f_16d7e7(uVar18 & 0xffff);
  uVar15 = (uint)((longlong)iVar5 * (longlong)p1_00) >> 0x10 |
           (int)((ulonglong)((longlong)iVar5 * (longlong)p1_00) >> 0x20) << 0x10;
  uVar18 = (uint)((longlong)iVar5 * (longlong)iVar8) >> 0x10 |
           (int)((ulonglong)((longlong)iVar5 * (longlong)iVar8) >> 0x20) << 0x10;
  uVar19 = (uint)((longlong)iVar7 * (longlong)p1_00) >> 0x10 |
           (int)((ulonglong)((longlong)iVar7 * (longlong)p1_00) >> 0x20) << 0x10;
  uVar9 = (uint)((longlong)iVar7 * (longlong)iVar8) >> 0x10 |
          (int)((ulonglong)((longlong)iVar7 * (longlong)iVar8) >> 0x20) << 0x10;
  uVar10 = (uint)bVar1;
  iVar11 = (uint)(byte)(&DAT_001b4f7b)[uVar10 * 4] * 4;
  iVar12 = (uint)(byte)(&DAT_001b4f7a)[uVar10 * 4] * 4;
  iVar13 = (uint)(byte)(&DAT_001b4f79)[uVar10 * 4] * 4;
  iVar17 = (uint)(byte)(&DAT_001b4f7a)[uVar10 * 4] * 0xc + p1;
  iVar14 = (uint)(byte)(&DAT_001b4f7b)[uVar10 * 4] * 0xc + p1;
  iVar16 = (uint)(byte)(&DAT_001b4f79)[uVar10 * 4] * 0xc + p1;
  if ((bVar1 & 8) == 0) {
    *(uint *)(iVar13 + iVar16) =
         (uint)((longlong)(int)uVar6 * (longlong)p1_00) >> 0x10 |
         (int)((ulonglong)((longlong)(int)uVar6 * (longlong)p1_00) >> 0x20) << 0x10;
    *(uint *)(iVar17 + iVar13) =
         ((uint)((longlong)p1_01 * (longlong)(int)uVar19) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)(int)uVar19) >> 0x20) << 0x10) - uVar18;
    *(uint *)(iVar13 + iVar14) =
         ((uint)((longlong)p1_01 * (longlong)(int)uVar15) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)(int)uVar15) >> 0x20) << 0x10) + uVar9;
    *(uint *)(iVar12 + iVar16) =
         (uint)((longlong)(int)uVar6 * (longlong)iVar8) >> 0x10 |
         (int)((ulonglong)((longlong)(int)uVar6 * (longlong)iVar8) >> 0x20) << 0x10;
    *(int *)(iVar17 + iVar12) =
         ((uint)((longlong)p1_01 * (longlong)(int)uVar9) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)(int)uVar9) >> 0x20) << 0x10) + uVar15;
    *(int *)(iVar12 + iVar14) =
         ((uint)((longlong)p1_01 * (longlong)(int)uVar18) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)(int)uVar18) >> 0x20) << 0x10) - uVar19;
    *(int *)(iVar11 + iVar16) = -p1_01;
    *(uint *)(iVar17 + iVar11) =
         (uint)((longlong)(int)uVar6 * (longlong)iVar7) >> 0x10 |
         (int)((ulonglong)((longlong)(int)uVar6 * (longlong)iVar7) >> 0x20) << 0x10;
    uVar9 = (uint)((longlong)(int)uVar6 * (longlong)iVar5) >> 0x10 |
            (int)((ulonglong)((longlong)(int)uVar6 * (longlong)iVar5) >> 0x20) << 0x10;
  }
  else {
    *(uint *)(iVar13 + iVar16) = uVar6;
    *(uint *)(iVar17 + iVar13) =
         (uint)((longlong)p1_01 * (longlong)iVar7) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)iVar7) >> 0x20) << 0x10;
    *(uint *)(iVar13 + iVar14) =
         (uint)((longlong)p1_01 * (longlong)iVar5) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)iVar5) >> 0x20) << 0x10;
    *(uint *)(iVar12 + iVar16) =
         (uint)((longlong)p1_01 * (longlong)iVar8) >> 0x10 |
         (int)((ulonglong)((longlong)p1_01 * (longlong)iVar8) >> 0x20) << 0x10;
    *(int *)(iVar17 + iVar12) =
         uVar15 - ((uint)((longlong)(int)uVar6 * (longlong)(int)uVar9) >> 0x10 |
                  (int)((ulonglong)((longlong)(int)uVar6 * (longlong)(int)uVar9) >> 0x20) << 0x10);
    *(int *)(iVar12 + iVar14) =
         -uVar19 - ((uint)((longlong)(int)uVar6 * (longlong)(int)uVar18) >> 0x10 |
                   (int)((ulonglong)((longlong)(int)uVar6 * (longlong)(int)uVar18) >> 0x20) << 0x10)
    ;
    *(int *)(iVar11 + iVar16) =
         -((uint)((longlong)p1_01 * (longlong)p1_00) >> 0x10 |
          (int)((ulonglong)((longlong)p1_01 * (longlong)p1_00) >> 0x20) << 0x10);
    *(uint *)(iVar17 + iVar11) =
         ((uint)((longlong)(int)uVar6 * (longlong)(int)uVar19) >> 0x10 |
         (int)((ulonglong)((longlong)(int)uVar6 * (longlong)(int)uVar19) >> 0x20) << 0x10) + uVar18;
    uVar9 = ((uint)((longlong)(int)uVar6 * (longlong)(int)uVar15) >> 0x10 |
            (int)((ulonglong)((longlong)(int)uVar6 * (longlong)(int)uVar15) >> 0x20) << 0x10) -
            uVar9;
  }
  *(uint *)(iVar11 + iVar14) = uVar9;
  *(undefined4 *)(p1 + 0x2c) = 0;
  *(undefined4 *)(p1 + 0x28) = *(undefined4 *)(p1 + 0x2c);
  *(undefined4 *)(p1 + 0x24) = *(undefined4 *)(p1 + 0x2c);
  return p1;
}




/* ==== 196280-1964F0  (nach Attic)  fremd? ==== */


short * f_196280(short *p1,int p2)

{
  undefined4 *p1_00;
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  uint uVar5;
  undefined4 *p1_01;
  undefined4 p1_02;
  int iVar6;
  int iVar7;
  uint p4;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  
  bVar1 = *(byte *)(p1 + 3);
  uVar5 = (uint)bVar1;
  p4 = (uint)(byte)(&DAT_001b4f79)[uVar5 * 4];
  iVar7 = (uint)(byte)(&DAT_001b4f7a)[uVar5 * 4] * 4;
  iVar11 = (uint)(byte)(&DAT_001b4f7b)[uVar5 * 4] * 4;
  iVar9 = (uint)(byte)(&DAT_001b4f7a)[uVar5 * 4] * 0xc + p2;
  iVar12 = p4 * 0xc + p2;
  iVar10 = (uint)(byte)(&DAT_001b4f7b)[uVar5 * 4] * 0xc + p2;
  p1_00 = (undefined4 *)(iVar7 + iVar12);
  iVar8 = p4 * 4;
  piVar13 = (int *)(iVar12 + iVar8);
  if ((bVar1 & 8) == 0) {
    iVar8 = *piVar13;
    iVar6 = f_16d4d8(iVar8, *p1_00);
    if (0 < iVar6) {
      uVar2 = *(undefined4 *)(iVar10 + iVar11);
      uVar3 = *(undefined4 *)(iVar9 + iVar11);
      sVar4 = f_16d8ad(uVar3, uVar2);
      *p1 = sVar4;
      sVar4 = f_16d8ad(-*(int *)(iVar11 + iVar12), iVar6);
      p1[1] = sVar4;
      sVar4 = f_16d8ad(*p1_00, *piVar13);
      p1[2] = sVar4;
      goto LAB_0019649e;
    }
    sVar4 = f_16d8ad(-*(int *)(iVar10 + iVar7), *(int *)(iVar10 + iVar11));
    *p1 = sVar4;
    iVar7 = -*(int *)(iVar11 + iVar12);
  }
  else {
    p1_01 = (undefined4 *)(iVar9 + iVar8);
    iVar11 = f_16d4d8(*p1_01, *(int *)(iVar10 + iVar8));
    if (0 < iVar11) {
      uVar2 = *(undefined4 *)(iVar10 + iVar8);
      uVar3 = *p1_01;
      p1_02 = f_16d8ad(uVar3, uVar2);
      *p1 = (short)p1_02;
      iVar7 = *piVar13;
      sVar4 = f_16d8ad(iVar11, iVar7);
      p1[1] = sVar4;
      sVar4 = f_16d8ad(*p1_00, -*(int *)(iVar11 + iVar12));
      p1[2] = sVar4;
      goto LAB_0019649e;
    }
    iVar8 = *(int *)(iVar9 + iVar7);
    sVar4 = f_16d8ad(-*(int *)(iVar10 + iVar7), *(int *)(iVar10 + iVar11));
    *p1 = sVar4;
    iVar7 = *piVar13;
  }
  sVar4 = f_16d8ad(iVar11, iVar7);
  p1[2] = 0;
  p1[1] = sVar4;
LAB_0019649e:
  if ((bVar1 & 4) != 0) {
    *p1 = -*p1;
    p1[1] = -p1[1];
    p1[2] = -p1[2];
  }
  if ((bVar1 & 0x10) != 0) {
    sVar4 = *p1;
    *p1 = p1[2];
    p1[2] = sVar4;
  }
  return p1;
}




/* ==== 1964F0-196510  (nach Attic)  fremd? ==== */


undefined4 f_1964f0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  undefined1 auStack_34 [48];
  
  f_195f00(auStack_34,p2,p1,p4);
  f_189a0c(p1,auStack_34);
  return p1;
}




/* ==== 196510-196810  (nach Attic)  fremd? ==== */


void f_196510(undefined4 p1,undefined4 p2)

{
  undefined1 auStack_34 [48];
  
  f_16c544(auStack_34,p2);
  f_196280(p1,auStack_34);
  return;
}




/* ==== 18EFB0-18EFC0  (nach Attic)  fremd? ==== */


void f_18efb0(undefined4 p1)

{
  f_187d94(&DAT_001d452c,p1);
  return;
}




/* ==== 18EFC0-18F010  (nach Attic)  fremd? ==== */


void f_18efc0(undefined4 p1,undefined4 p2,undefined4 p3)

{
  f_187dcc(&DAT_001d452c,p1,p2,p3);
  return;
}




/* ==== 18F010-18F020  (nach Attic)  fremd? ==== */


void f_18f010(undefined4 p1)

{
  f_187d10(&DAT_001d4540,p1);
  return;
}




/* ==== 18F020-18F030  (nach Attic)  fremd? ==== */


undefined4 f_18f020(undefined4 p1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_001d4550;
  DAT_001d4550 = p1;
  return uVar1;
}




/* ==== 18F030-18F0B0  (nach Attic)  fremd? ==== */


int f_18f030(int *p1,int p2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < p2) {
    do {
      iVar1 = *p1;
      f_198c50(iVar1,0x7fff);
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) | 4;
      p1 = p1 + 1;
      iVar1 = f_187c18(&DAT_001d4540,iVar1);
      if (iVar1 != 0) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < p2);
  }
  return iVar3;
}




/* ==== 18F0B0-18F150  (nach Attic)  fremd? ==== */


void f_18f0b0(undefined4 p1,undefined4 p2,undefined4 p3)

{
  f_187d54(&DAT_001d4540,p1,p2,p3);
  return;
}




/* ==== 18F150-18F1F0  (nach Attic)  fremd? ==== */


void f_18f150(undefined4 p1,undefined4 p2,undefined4 p3)

{
  f_187d54(&DAT_001d4554,p1,p2,p3);
  return;
}




/* ==== 18F1F0-18F228  (nach Attic)  fremd? ==== */


void f_18f1f0(undefined4 p1,undefined4 p2,undefined4 p3)

{
  f_187d54(&DAT_001d4568,p1,p2,p3);
  return;
}




/* ==== 18F228-18F280  (nach Attic)  fremd? ==== */


int f_18f228(int p1)

{
  int iVar1;
  
  iVar1 = f_187c18(&DAT_001d457c,p1);
  if (iVar1 != 0) {
    *(int *)(&DAT_001d4590 + (uint)*(byte *)(p1 + 4) * 4) = iVar1;
  }
  return iVar1;
}




/* ==== 18F280-18F290  (nach Attic)  fremd? ==== */


void f_18f280(undefined4 p1)

{
  f_187d10(&DAT_001d457c,p1);
  return;
}




/* ==== 18F290-18F2A0  (nach Attic)  fremd? ==== */


undefined4 f_18f290(undefined4 p1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_001d458c;
  DAT_001d458c = p1;
  return uVar1;
}




/* ==== 18F2A0-18F2E0  (nach Attic)  fremd? ==== */


int f_18f2a0(int *p1,int p2)

{
  int p2_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < p2) {
    do {
      p2_00 = *p1;
      p1 = p1 + 1;
      iVar1 = f_187c18(&DAT_001d457c,p2_00);
      if (iVar1 != 0) {
        *(int *)(&DAT_001d4590 + (uint)*(byte *)(p2_00 + 4) * 4) = iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < p2);
  }
  return p2;
}




/* ==== 18F2E0-18F560  (nach Attic)  fremd? ==== */


int f_18f2e0(int *p1,int p2)

{
  int p2_00;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < p2) {
    do {
      p2_00 = *p1;
      p1 = p1 + 1;
      iVar1 = f_187ca0(&DAT_001d457c,p2_00);
      if (iVar1 != 0) {
        *(undefined4 *)(&DAT_001d4590 + (uint)*(byte *)(p2_00 + 4) * 4) = 0;
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < p2);
  }
  return iVar3;
}




/* ==== 18F560-18F710  (nach Attic)  fremd? ==== */


undefined4 * f_18f560(int p1,int p2,int p3,undefined4 *p4)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int aiStack_48 [4];
  int local_38 [6];
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  
  iVar10 = p3 * 0xc;
  aiStack_48[0] = 0x18f583;
  local_10 = p1;
  f_16b930(p4);
  local_20 = p2 * 0xc;
  local_1c = *(int *)(&DAT_001b4a24 + local_20);
  lVar4 = (longlong)local_1c * (longlong)*(int *)(&DAT_001b4a28 + iVar10);
  local_18 = *(int *)(&DAT_001b4a24 + iVar10);
  lVar5 = (longlong)*(int *)(&DAT_001b4a28 + local_20) * (longlong)local_18;
  local_38[3] = ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10) -
                ((uint)lVar5 >> 0x10 | (int)((ulonglong)lVar5 >> 0x20) << 0x10);
  lVar4 = (longlong)*(int *)(&DAT_001b4a28 + local_20) *
          (longlong)(int)(&PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20)[p3 * 3];
  local_14 = (uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10;
  lVar4 = (longlong)(int)(&PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20)[p2 * 3] *
          (longlong)*(int *)(&DAT_001b4a28 + iVar10);
  local_38[4] = local_14 - ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
  lVar4 = (longlong)(int)(&PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20)[p2 * 3] * (longlong)local_18
  ;
  lVar5 = (longlong)local_1c * (longlong)(int)(&PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20)[p3 * 3]
  ;
  iVar9 = 0;
  local_38[5] = ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10) -
                ((uint)lVar5 >> 0x10 | (int)((ulonglong)lVar5 >> 0x20) << 0x10);
  iVar7 = local_20;
  puVar8 = p4;
  do {
    *puVar8 = *(undefined4 *)((int)&PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20 + iVar7);
    puVar3 = (undefined4 *)((int)&PTR_lib_CLIB3R_LIB_cstrt386_010000_001b4a20 + iVar10);
    iVar10 = iVar10 + 4;
    puVar8[1] = *puVar3;
    iVar7 = iVar7 + 4;
    iVar6 = iVar9 + 3;
    iVar9 = iVar9 + 1;
    puVar8[2] = local_38[iVar6];
    puVar8 = puVar8 + 3;
  } while (iVar9 < 3);
  iVar9 = 0;
  iVar7 = local_10;
  do {
    piVar1 = (int *)(iVar7 + 0x38);
    piVar2 = (int *)(iVar7 + 0x2c);
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 4;
    aiStack_48[iVar9] = -(*piVar2 / 2 + *piVar1 / 2);
  } while (iVar9 < 3);
  iVar9 = 0;
  iVar7 = local_10;
  do {
    if (*(int *)(iVar7 + 0x38) == *(int *)(iVar7 + 0x2c)) {
      local_38[iVar9] = 0x10000;
    }
    else {
      local_38[iVar9] =
           (int)(0x100000000 / (longlong)(*(int *)(iVar7 + 0x38) / 2 - *(int *)(iVar7 + 0x2c) / 2));
    }
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 4;
  } while (iVar9 < 3);
  aiStack_48[0] = 0x18f6ec;
  f_16cda0(p4,local_38[0],local_38[1],local_38[2]);
  aiStack_48[0] = 0x18f6fe;
  f_16cd48(p4,aiStack_48[1],aiStack_48[2],aiStack_48[3]);
  return p4;
}




/* ==== 18F710-18F780  (nach Attic)  fremd? ==== */


undefined4 * f_18f710(int p1,int p2,int p3)

{
  undefined4 *p1_00;
  undefined4 uVar1;
  
  p1_00 = (undefined4 *)f_188404(DAT_001d49b0,0x74,7);
  *(short *)(p1_00 + 3) = (short)p2;
  *(short *)((int)p1_00 + 0xe) = (short)p3;
  if (p1 != 0) {
    uVar1 = f_188664(p1_00,p1);
    *p1_00 = uVar1;
  }
  if (p2 != 0) {
    uVar1 = f_188404(p1_00,p2 << 5,4);
    p1_00[1] = uVar1;
  }
  if (p3 != 0) {
    uVar1 = f_188404(p1_00,p3 << 5,5);
    p1_00[2] = uVar1;
  }
  return p1_00;
}




/* ==== 18F780-18F7E0  (nach Attic)  fremd? ==== */


undefined4 * f_18f780(int p1)

{
  undefined4 *p1_00;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  p1_00 = (undefined4 *)f_188404(DAT_001d49b0,0x4c,8);
  puVar3 = DAT_001d49b8;
  puVar4 = p1_00;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if (p1 == 0) {
    *p1_00 = 0;
  }
  else {
    uVar1 = f_188664(p1_00,p1);
    *p1_00 = uVar1;
  }
  return p1_00;
}




/* ==== 16B5C0-16B60C  (nach Attic)  fremd? ==== */


void f_16b5c0(undefined4 *p1,undefined4 *p2)

{
  *p1 = *p2;
  p1[1] = p2[1];
  p1[2] = p2[2];
  p1[3] = p2[3];
  p1[4] = p2[4];
  p1[5] = p2[5];
  p1[6] = p2[6];
  p1[7] = p2[7];
  p1[8] = p2[8];
  p1[9] = p2[9];
  p1[10] = p2[10];
  p1[0xb] = p2[0xb];
  return;
}




/* ==== 16B60C-16B930  (nach Attic)  fremd? ==== */


void f_16b60c(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[1] * (longlong)p3[3]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[3]) >> 0x20) << 0x10);
  p1[1] = ((uint)((longlong)p2[2] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10);
  p1[2] = ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10);
  p1[3] = ((uint)((longlong)p2[5] * (longlong)p3[6]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[5] * (longlong)p3[6]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[3] * (longlong)*p3) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)*p3) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[4] * (longlong)p3[3]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[4] * (longlong)p3[3]) >> 0x20) << 0x10);
  p1[4] = ((uint)((longlong)p2[5] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[5] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[3] * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[4] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[4] * (longlong)p3[4]) >> 0x20) << 0x10);
  p1[5] = ((uint)((longlong)p2[5] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[5] * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[3] * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[3] * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[4] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[4] * (longlong)p3[5]) >> 0x20) << 0x10);
  p1[6] = ((uint)((longlong)p2[8] * (longlong)p3[6]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[8] * (longlong)p3[6]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[6] * (longlong)*p3) >> 0x10 |
          (int)((ulonglong)((longlong)p2[6] * (longlong)*p3) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[7] * (longlong)p3[3]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[7] * (longlong)p3[3]) >> 0x20) << 0x10);
  p1[7] = ((uint)((longlong)p2[8] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[8] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[6] * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[6] * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[7] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[7] * (longlong)p3[4]) >> 0x20) << 0x10);
  p1[8] = ((uint)((longlong)p2[8] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[8] * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[6] * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[6] * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[7] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[7] * (longlong)p3[5]) >> 0x20) << 0x10);
  p1[9] = p3[9] + ((uint)((longlong)p2[0xb] * (longlong)p3[6]) >> 0x10 |
                  (int)((ulonglong)((longlong)p2[0xb] * (longlong)p3[6]) >> 0x20) << 0x10) +
                  ((uint)((longlong)p2[9] * (longlong)*p3) >> 0x10 |
                  (int)((ulonglong)((longlong)p2[9] * (longlong)*p3) >> 0x20) << 0x10) +
                  ((uint)((longlong)p2[10] * (longlong)p3[3]) >> 0x10 |
                  (int)((ulonglong)((longlong)p2[10] * (longlong)p3[3]) >> 0x20) << 0x10);
  p1[10] = ((uint)((longlong)p2[0xb] * (longlong)p3[7]) >> 0x10 |
           (int)((ulonglong)((longlong)p2[0xb] * (longlong)p3[7]) >> 0x20) << 0x10) +
           ((uint)((longlong)p2[9] * (longlong)p3[1]) >> 0x10 |
           (int)((ulonglong)((longlong)p2[9] * (longlong)p3[1]) >> 0x20) << 0x10) +
           ((uint)((longlong)p2[10] * (longlong)p3[4]) >> 0x10 |
           (int)((ulonglong)((longlong)p2[10] * (longlong)p3[4]) >> 0x20) << 0x10) + p3[10];
  p1[0xb] = ((uint)((longlong)p2[0xb] * (longlong)p3[8]) >> 0x10 |
            (int)((ulonglong)((longlong)p2[0xb] * (longlong)p3[8]) >> 0x20) << 0x10) +
            ((uint)((longlong)p2[9] * (longlong)p3[2]) >> 0x10 |
            (int)((ulonglong)((longlong)p2[9] * (longlong)p3[2]) >> 0x20) << 0x10) +
            ((uint)((longlong)p2[10] * (longlong)p3[5]) >> 0x10 |
            (int)((ulonglong)((longlong)p2[10] * (longlong)p3[5]) >> 0x20) << 0x10) + p3[0xb];
  return;
}




/* ==== 16B930-16B984  (nach Attic)  fremd? ==== */


void f_16b930(undefined4 *p1)

{
  *p1 = 0x10000;
  p1[1] = 0;
  p1[2] = 0;
  p1[3] = 0;
  p1[4] = 0x10000;
  __asm__ __volatile__("nop");
  p1[5] = 0;
  p1[6] = 0;
  p1[7] = 0;
  p1[8] = 0x10000;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  return;
}




/* ==== 16B984-16B9F4  (nach Attic)  fremd? ==== */


void f_16b984(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  int p1_00;
  undefined4 uVar1;
  
  p1_00 = f_16d7e7((uint16_t)(p2 & 0xffff));
  uVar1 = f_16d818((uint16_t)(p2 & 0xffff));
  *p1 = 0x10000;
  p1[1] = 0;
  p1[2] = 0;
  p1[3] = 0;
  p1[6] = 0;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  p1[4] = uVar1;
  p1[5] = p1_00;
  p1[7] = p1_00;
  p1[8] = uVar1;
  p1[7] = -p1_00;
  return;
}




/* ==== 16B9F4-16BA64  (nach Attic)  fremd? ==== */


void f_16b9f4(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  int p1_00;
  undefined4 uVar1;
  
  p1_00 = f_16d7e7((uint16_t)(p2 & 0xffff));
  uVar1 = f_16d818((uint16_t)(p2 & 0xffff));
  p1[1] = 0;
  p1[3] = 0;
  p1[4] = 0x10000;
  p1[5] = 0;
  p1[7] = 0;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  *p1 = uVar1;
  p1[2] = p1_00;
  p1[6] = p1_00;
  p1[8] = uVar1;
  p1[2] = -p1_00;
  return;
}




/* ==== 16BA64-16BAD4  (nach Attic)  fremd? ==== */


void f_16ba64(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  int p1_00;
  undefined4 uVar1;
  
  p1_00 = f_16d7e7((uint16_t)(p2 & 0xffff));
  uVar1 = f_16d818((uint16_t)(p2 & 0xffff));
  p1[2] = 0;
  p1[5] = 0;
  p1[6] = 0;
  p1[7] = 0;
  p1[8] = 0x10000;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  *p1 = uVar1;
  p1[1] = p1_00;
  p1[3] = p1_00;
  p1[4] = uVar1;
  p1[3] = -p1_00;
  return;
}




/* ==== 16BAD4-16BC24  (nach Attic)  fremd? ==== */


void f_16bad4(int *p1,uint p2,int *p3,undefined4 p4)

{
  longlong lVar1;
  int p1_00;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  p1_00 = f_16d7e7((uint16_t)(p2 & 0xffff));
  iVar2 = f_16d818((uint16_t)(p2 & 0xffff));
  iVar9 = 0x10000 - iVar2;
  uVar3 = (uint)((longlong)iVar9 * (longlong)*p3) >> 0x10 |
          (int)((ulonglong)((longlong)iVar9 * (longlong)*p3) >> 0x20) << 0x10;
  lVar1 = (longlong)(int)uVar3 * (longlong)p3[2];
  uVar4 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  lVar1 = (longlong)(int)uVar3 * (longlong)p3[1];
  uVar3 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  lVar1 = (longlong)iVar9 *
          (longlong)
          (int)((uint)((longlong)p3[1] * (longlong)p3[2]) >> 0x10 |
               (int)((ulonglong)((longlong)p3[1] * (longlong)p3[2]) >> 0x20) << 0x10);
  uVar5 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  uVar6 = (uint)((longlong)p1_00 * (longlong)*p3) >> 0x10 |
          (int)((ulonglong)((longlong)p1_00 * (longlong)*p3) >> 0x20) << 0x10;
  uVar7 = (uint)((longlong)p1_00 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)p1_00 * (longlong)p3[1]) >> 0x20) << 0x10;
  uVar8 = (uint)((longlong)p1_00 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)p1_00 * (longlong)p3[2]) >> 0x20) << 0x10;
  lVar1 = (longlong)*p3 * (longlong)*p3;
  lVar1 = (longlong)iVar9 *
          (longlong)(int)((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  *p1 = iVar2 + ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  p1[1] = uVar3 + uVar8;
  p1[2] = uVar4 - uVar7;
  p1[3] = uVar3 - uVar8;
  lVar1 = (longlong)p3[1] * (longlong)p3[1];
  lVar1 = (longlong)iVar9 *
          (longlong)(int)((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  p1[4] = iVar2 + ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  p1[5] = uVar5 + uVar6;
  p1[6] = uVar4 + uVar7;
  p1[7] = uVar5 - uVar6;
  lVar1 = (longlong)p3[2] * (longlong)p3[2];
  lVar1 = (longlong)iVar9 *
          (longlong)(int)((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  p1[0xb] = 0;
  p1[8] = iVar2 + ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  p1[10] = p1[0xb];
  p1[9] = p1[0xb];
  return;
}




/* ==== 16BC24-16BC6C  (nach Attic)  fremd? ==== */


void f_16bc24(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  *p1 = 0x10000;
  p1[1] = 0;
  p1[2] = 0;
  p1[3] = 0;
  p1[4] = 0x10000;
  p1[5] = 0;
  p1[6] = 0;
  p1[7] = 0;
  p1[8] = 0x10000;
  p1[9] = p2;
  p1[10] = p3;
  p1[0xb] = p4;
  return;
}




/* ==== 16BC6C-16BCB4  (nach Attic)  fremd? ==== */


void f_16bc6c(undefined4 *p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  p1[1] = 0;
  p1[2] = 0;
  p1[3] = 0;
  p1[5] = 0;
  p1[6] = 0;
  p1[7] = 0;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  *p1 = p2;
  p1[4] = p3;
  p1[8] = p4;
  return;
}




/* ==== 16BCB4-16BD00  (nach Attic)  fremd? ==== */


void f_16bcb4(undefined4 *p1,undefined4 p2,undefined4 p3)

{
  *p1 = 0x10000;
  p1[3] = 0;
  p1[4] = 0x10000;
  p1[5] = 0;
  __asm__ __volatile__("nop");
  p1[6] = 0;
  p1[7] = 0;
  p1[8] = 0x10000;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  p1[1] = p2;
  p1[2] = p3;
  return;
}




/* ==== 16BD00-16BD4C  (nach Attic)  fremd? ==== */


void f_16bd00(undefined4 *p1,undefined4 p2,undefined4 p3)

{
  *p1 = 0x10000;
  p1[1] = 0;
  p1[2] = 0;
  p1[4] = 0x10000;
  __asm__ __volatile__("nop");
  p1[6] = 0;
  p1[7] = 0;
  p1[8] = 0x10000;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  p1[3] = p2;
  p1[5] = p3;
  return;
}




/* ==== 16BD4C-16BD98  (nach Attic)  fremd? ==== */


void f_16bd4c(undefined4 *p1,undefined4 p2,undefined4 p3)

{
  *p1 = 0x10000;
  p1[1] = 0;
  p1[2] = 0;
  p1[3] = 0;
  p1[4] = 0x10000;
  __asm__ __volatile__("nop");
  p1[5] = 0;
  p1[8] = 0x10000;
  p1[9] = 0;
  p1[10] = 0;
  p1[0xb] = 0;
  p1[6] = p2;
  p1[7] = p3;
  return;
}




/* ==== 16BD98-16C138  (nach Attic)  fremd? ==== */


int f_16bd98(uint *p1,int *p2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = 0;
  lVar1 = (longlong)
          (int)((uint)((longlong)*p2 * (longlong)p2[4]) >> 0x10 |
               (int)((ulonglong)((longlong)*p2 * (longlong)p2[4]) >> 0x20) << 0x10) *
          (longlong)p2[8];
  uVar2 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  if (-1 < (int)uVar2) {
    uVar6 = uVar2;
    uVar2 = 0;
  }
  lVar1 = (longlong)
          (int)((uint)((longlong)p2[1] * (longlong)p2[5]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[1] * (longlong)p2[5]) >> 0x20) << 0x10) *
          (longlong)p2[6];
  uVar3 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  if ((int)uVar3 < 0) {
    uVar2 = uVar2 + uVar3;
  }
  else {
    uVar6 = uVar6 + uVar3;
  }
  lVar1 = (longlong)
          (int)((uint)((longlong)p2[2] * (longlong)p2[3]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[2] * (longlong)p2[3]) >> 0x20) << 0x10) *
          (longlong)p2[7];
  uVar3 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  if ((int)uVar3 < 0) {
    uVar2 = uVar2 + uVar3;
  }
  else {
    uVar6 = uVar6 + uVar3;
  }
  lVar1 = (longlong)
          (int)((uint)((longlong)p2[2] * (longlong)p2[4]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[2] * (longlong)p2[4]) >> 0x20) << 0x10) *
          (longlong)p2[6];
  uVar3 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  iVar4 = -uVar3;
  if ((int)uVar3 < 1) {
    uVar6 = uVar6 + iVar4;
  }
  else {
    uVar2 = uVar2 + iVar4;
  }
  lVar1 = (longlong)
          (int)((uint)((longlong)p2[1] * (longlong)p2[3]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[1] * (longlong)p2[3]) >> 0x20) << 0x10) *
          (longlong)p2[8];
  uVar3 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  iVar4 = -uVar3;
  if ((int)uVar3 < 1) {
    uVar6 = uVar6 + iVar4;
  }
  else {
    uVar2 = uVar2 + iVar4;
  }
  lVar1 = (longlong)
          (int)((uint)((longlong)*p2 * (longlong)p2[5]) >> 0x10 |
               (int)((ulonglong)((longlong)*p2 * (longlong)p2[5]) >> 0x20) << 0x10) *
          (longlong)p2[7];
  uVar3 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  iVar4 = -uVar3;
  if ((int)uVar3 < 1) {
    uVar6 = uVar6 + iVar4;
  }
  else {
    uVar2 = uVar2 + iVar4;
  }
  iVar4 = uVar6 + uVar2;
  iVar5 = iVar4;
  if (iVar4 < 0) {
    iVar5 = -iVar4;
  }
  if (iVar5 < 3) {
    iVar4 = 0;
  }
  else {
    iVar5 = uVar6 - uVar2;
    iVar7 = iVar4 >> 0x10;
    if ((int)(CONCAT44(iVar7,iVar4 * 0x10000) / (longlong)iVar5) < 0) {
      iVar5 = -(int)(CONCAT44(iVar7,iVar4 * 0x10000) / (longlong)iVar5);
    }
    else {
      iVar5 = (int)(CONCAT44(iVar7,iVar4 * 0x10000) / (longlong)iVar5);
    }
    if (iVar5 < 0) {
      return 0;
    }
    iVar5 = (int)(0x100000000 / (longlong)iVar4);
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[5] * (longlong)p2[7]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[5] * (longlong)p2[7]) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[4] * (longlong)p2[8]) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[4] * (longlong)p2[8]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    *p1 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[5] * (longlong)p2[6]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[5] * (longlong)p2[6]) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[3] * (longlong)p2[8]) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[3] * (longlong)p2[8]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[3] = -((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[4] * (longlong)p2[6]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[4] * (longlong)p2[6]) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[3] * (longlong)p2[7]) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[3] * (longlong)p2[7]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[6] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[2] * (longlong)p2[7]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[2] * (longlong)p2[7]) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[1] * (longlong)p2[8]) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[1] * (longlong)p2[8]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[1] = -((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[2] * (longlong)p2[6]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[2] * (longlong)p2[6]) >> 0x20) << 0x10) +
                 ((uint)((longlong)*p2 * (longlong)p2[8]) >> 0x10 |
                 (int)((ulonglong)((longlong)*p2 * (longlong)p2[8]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[4] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[1] * (longlong)p2[6]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[1] * (longlong)p2[6]) >> 0x20) << 0x10) +
                 ((uint)((longlong)*p2 * (longlong)p2[7]) >> 0x10 |
                 (int)((ulonglong)((longlong)*p2 * (longlong)p2[7]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[7] = -((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[2] * (longlong)p2[4]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[2] * (longlong)p2[4]) >> 0x20) << 0x10) +
                 ((uint)((longlong)p2[1] * (longlong)p2[5]) >> 0x10 |
                 (int)((ulonglong)((longlong)p2[1] * (longlong)p2[5]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[2] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[2] * (longlong)p2[3]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[2] * (longlong)p2[3]) >> 0x20) << 0x10) +
                 ((uint)((longlong)*p2 * (longlong)p2[5]) >> 0x10 |
                 (int)((ulonglong)((longlong)*p2 * (longlong)p2[5]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[5] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    p1[5] = -p1[5];
    lVar1 = (longlong)
            (int)(((uint)((longlong)-p2[1] * (longlong)p2[3]) >> 0x10 |
                  (int)((ulonglong)((longlong)-p2[1] * (longlong)p2[3]) >> 0x20) << 0x10) +
                 ((uint)((longlong)*p2 * (longlong)p2[4]) >> 0x10 |
                 (int)((ulonglong)((longlong)*p2 * (longlong)p2[4]) >> 0x20) << 0x10)) *
            (longlong)iVar5;
    p1[8] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    p1[9] = -(((uint)((longlong)p2[0xb] * (longlong)(int)p1[6]) >> 0x10 |
              (int)((ulonglong)((longlong)p2[0xb] * (longlong)(int)p1[6]) >> 0x20) << 0x10) +
             ((uint)((longlong)p2[9] * (longlong)(int)*p1) >> 0x10 |
             (int)((ulonglong)((longlong)p2[9] * (longlong)(int)*p1) >> 0x20) << 0x10) +
             ((uint)((longlong)p2[10] * (longlong)(int)p1[3]) >> 0x10 |
             (int)((ulonglong)((longlong)p2[10] * (longlong)(int)p1[3]) >> 0x20) << 0x10));
    p1[10] = -(((uint)((longlong)p2[0xb] * (longlong)(int)p1[7]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[0xb] * (longlong)(int)p1[7]) >> 0x20) << 0x10) +
              ((uint)((longlong)p2[9] * (longlong)(int)p1[1]) >> 0x10 |
              (int)((ulonglong)((longlong)p2[9] * (longlong)(int)p1[1]) >> 0x20) << 0x10) +
              ((uint)((longlong)p2[10] * (longlong)(int)p1[4]) >> 0x10 |
              (int)((ulonglong)((longlong)p2[10] * (longlong)(int)p1[4]) >> 0x20) << 0x10));
    p1[0xb] = -(((uint)((longlong)p2[0xb] * (longlong)(int)p1[8]) >> 0x10 |
                (int)((ulonglong)((longlong)p2[0xb] * (longlong)(int)p1[8]) >> 0x20) << 0x10) +
               ((uint)((longlong)p2[9] * (longlong)(int)p1[2]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[9] * (longlong)(int)p1[2]) >> 0x20) << 0x10) +
               ((uint)((longlong)p2[10] * (longlong)(int)p1[5]) >> 0x10 |
               (int)((ulonglong)((longlong)p2[10] * (longlong)(int)p1[5]) >> 0x20) << 0x10));
  }
  return iVar4;
}




/* ==== 16C138-16C24C  (nach Attic)  fremd? ==== */


void f_16c138(int *p1,int *p2)

{
  int iVar1;
  
  *p1 = *p2;
  p1[1] = p2[3];
  p1[2] = p2[6];
  p1[3] = p2[1];
  p1[4] = p2[4];
  p1[5] = p2[7];
  p1[6] = p2[2];
  p1[7] = p2[5];
  p1[8] = p2[8];
  iVar1 = ((uint)((longlong)p2[0xb] * (longlong)p1[6]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[0xb] * (longlong)p1[6]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[9] * (longlong)*p1) >> 0x10 |
          (int)((ulonglong)((longlong)p2[9] * (longlong)*p1) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[10] * (longlong)p1[3]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[10] * (longlong)p1[3]) >> 0x20) << 0x10);
  p1[9] = iVar1;
  p1[9] = -iVar1;
  iVar1 = ((uint)((longlong)p2[0xb] * (longlong)p1[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[0xb] * (longlong)p1[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[9] * (longlong)p1[1]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[9] * (longlong)p1[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[10] * (longlong)p1[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[10] * (longlong)p1[4]) >> 0x20) << 0x10);
  p1[10] = iVar1;
  p1[10] = -iVar1;
  p1[0xb] = -(((uint)((longlong)p2[0xb] * (longlong)p1[8]) >> 0x10 |
              (int)((ulonglong)((longlong)p2[0xb] * (longlong)p1[8]) >> 0x20) << 0x10) +
             ((uint)((longlong)p2[9] * (longlong)p1[2]) >> 0x10 |
             (int)((ulonglong)((longlong)p2[9] * (longlong)p1[2]) >> 0x20) << 0x10) +
             ((uint)((longlong)p2[10] * (longlong)p1[5]) >> 0x10 |
             (int)((ulonglong)((longlong)p2[10] * (longlong)p1[5]) >> 0x20) << 0x10));
  return;
}




/* ==== 16C24C-16C544  (nach Attic)  fremd? ==== */


void f_16c24c(uint *p1,int p2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint p4;
  
  iVar3 = f_16d4fc(*(int *)(p2 + 0x18), *(int *)(p2 + 0x1c), *(int *)(p2 + 0x20));
  if (iVar3 < 3) {
    p1[6] = 0x7fff;
    p1[7] = 0;
    p1[8] = 0;
  }
  else {
    iVar3 = (int)(0x100000000 / (longlong)iVar3);
    lVar1 = (longlong)*(int *)(p2 + 0x18) * (longlong)iVar3;
    p1[6] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    lVar1 = (longlong)*(int *)(p2 + 0x1c) * (longlong)iVar3;
    p1[7] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    lVar1 = (longlong)*(int *)(p2 + 0x20) * (longlong)iVar3;
    p1[8] = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  }
  lVar1 = (longlong)*(int *)(p2 + 0x10) * (longlong)(int)p1[8];
  lVar2 = (longlong)*(int *)(p2 + 0x14) * (longlong)(int)p1[7];
  *p1 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) -
        ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
  lVar1 = (longlong)*(int *)(p2 + 0x14) * (longlong)(int)p1[6];
  lVar2 = (longlong)*(int *)(p2 + 0xc) * (longlong)(int)p1[8];
  p1[1] = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) -
          ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
  lVar1 = (longlong)*(int *)(p2 + 0xc) * (longlong)(int)p1[7];
  lVar2 = (longlong)*(int *)(p2 + 0x10) * (longlong)(int)p1[6];
  p4 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) -
       ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
  p1[2] = p4;
  iVar3 = f_16d4fc(p1[0], p1[1], p1[2]);
  if (iVar3 < 3) {
    *p1 = 0x7fff;
    p1[1] = 0;
    p1[2] = 0;
  }
  else {
    iVar3 = (int)(0x100000000 / (longlong)iVar3);
    *p1 = (uint)((longlong)(int)*p1 * (longlong)iVar3) >> 0x10 |
          (int)((ulonglong)((longlong)(int)*p1 * (longlong)iVar3) >> 0x20) << 0x10;
    p1[1] = (uint)((longlong)(int)p1[1] * (longlong)iVar3) >> 0x10 |
            (int)((ulonglong)((longlong)(int)p1[1] * (longlong)iVar3) >> 0x20) << 0x10;
    p1[2] = (uint)((longlong)(int)p1[2] * (longlong)iVar3) >> 0x10 |
            (int)((ulonglong)((longlong)(int)p1[2] * (longlong)iVar3) >> 0x20) << 0x10;
  }
  p1[3] = ((uint)((longlong)(int)p1[7] * (longlong)(int)p1[2]) >> 0x10 |
          (int)((ulonglong)((longlong)(int)p1[7] * (longlong)(int)p1[2]) >> 0x20) << 0x10) -
          ((uint)((longlong)(int)p1[8] * (longlong)(int)p1[1]) >> 0x10 |
          (int)((ulonglong)((longlong)(int)p1[8] * (longlong)(int)p1[1]) >> 0x20) << 0x10);
  p1[4] = ((uint)((longlong)(int)p1[8] * (longlong)(int)*p1) >> 0x10 |
          (int)((ulonglong)((longlong)(int)p1[8] * (longlong)(int)*p1) >> 0x20) << 0x10) -
          ((uint)((longlong)(int)p1[6] * (longlong)(int)p1[2]) >> 0x10 |
          (int)((ulonglong)((longlong)(int)p1[6] * (longlong)(int)p1[2]) >> 0x20) << 0x10);
  p1[5] = ((uint)((longlong)(int)p1[6] * (longlong)(int)p1[1]) >> 0x10 |
          (int)((ulonglong)((longlong)(int)p1[6] * (longlong)(int)p1[1]) >> 0x20) << 0x10) -
          ((uint)((longlong)(int)p1[7] * (longlong)(int)*p1) >> 0x10 |
          (int)((ulonglong)((longlong)(int)p1[7] * (longlong)(int)*p1) >> 0x20) << 0x10);
  p1[9] = *(uint *)(p2 + 0x24);
  p1[10] = *(uint *)(p2 + 0x28);
  p1[0xb] = *(uint *)(p2 + 0x2c);
  return;
}




/* ==== 16C544-16C590  (nach Attic)  fremd? ==== */


void f_16c544(undefined4 *p1,undefined4 *p2)

{
  *p1 = *p2;
  p1[1] = p2[1];
  p1[2] = p2[2];
  p1[3] = p2[4];
  p1[4] = p2[5];
  p1[5] = p2[6];
  p1[6] = p2[8];
  p1[7] = p2[9];
  p1[8] = p2[10];
  p1[9] = p2[0xc];
  p1[10] = p2[0xd];
  p1[0xb] = p2[0xe];
  return;
}




/* ==== 16C590-16C73C  (nach Attic)  fremd? ==== */


void f_16c590(int *p1,short *p2,int *p3,undefined4 p4)

{
  *p1 = ((uint)((longlong)(int)p2[2] * (longlong)p3[2]) >> 0xf |
        (int)((ulonglong)((longlong)(int)p2[2] * (longlong)p3[2]) >> 0x20) << 0x11) +
        ((uint)((longlong)(int)*p2 * (longlong)*p3) >> 0xf |
        (int)((ulonglong)((longlong)(int)*p2 * (longlong)*p3) >> 0x20) << 0x11) +
        ((uint)((longlong)(int)p2[1] * (longlong)p3[1]) >> 0xf |
        (int)((ulonglong)((longlong)(int)p2[1] * (longlong)p3[1]) >> 0x20) << 0x11);
  p1[1] = ((uint)((longlong)(int)p2[2] * (longlong)p3[5]) >> 0xf |
          (int)((ulonglong)((longlong)(int)p2[2] * (longlong)p3[5]) >> 0x20) << 0x11) +
          ((uint)((longlong)(int)*p2 * (longlong)p3[3]) >> 0xf |
          (int)((ulonglong)((longlong)(int)*p2 * (longlong)p3[3]) >> 0x20) << 0x11) +
          ((uint)((longlong)(int)p2[1] * (longlong)p3[4]) >> 0xf |
          (int)((ulonglong)((longlong)(int)p2[1] * (longlong)p3[4]) >> 0x20) << 0x11);
  p1[2] = ((uint)((longlong)(int)p2[2] * (longlong)p3[8]) >> 0xf |
          (int)((ulonglong)((longlong)(int)p2[2] * (longlong)p3[8]) >> 0x20) << 0x11) +
          ((uint)((longlong)(int)*p2 * (longlong)p3[6]) >> 0xf |
          (int)((ulonglong)((longlong)(int)*p2 * (longlong)p3[6]) >> 0x20) << 0x11) +
          ((uint)((longlong)(int)p2[1] * (longlong)p3[7]) >> 0xf |
          (int)((ulonglong)((longlong)(int)p2[1] * (longlong)p3[7]) >> 0x20) << 0x11);
  return;
}




/* ==== 16C73C-16C810  (nach Attic)  fremd? ==== */


void f_16c73c(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[1] * (longlong)p3[3]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[3]) >> 0x20) << 0x10) + p3[9];
  p1[1] = ((uint)((longlong)p2[2] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10) + p3[10];
  p1[2] = ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10) + p3[0xb];
  return;
}




/* ==== 16C810-16CAA0  (nach Attic)  fremd? ==== */


void f_16c810(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[1] * (longlong)p3[3]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[3]) >> 0x20) << 0x10);
  p1[1] = ((uint)((longlong)p2[2] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10);
  p1[2] = ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10);
  return;
}




/* ==== 16CAA0-16CB64  (nach Attic)  fremd? ==== */


void f_16caa0(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[2] * (longlong)p3[2]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[2]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[1] * (longlong)p3[1]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[1]) >> 0x20) << 0x10);
  p1[1] = ((uint)((longlong)p2[2] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[5]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[3]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[3]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10);
  p1[2] = ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[6]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[6]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[1] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[7]) >> 0x20) << 0x10);
  return;
}




/* ==== 16CB64-16CB84  (nach Attic)  fremd? ==== */


void f_16cb64(undefined4 p1,undefined4 p2)

{
  f_16b60c(&DAT_001ce744,p2,p1);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CB84-16CBDC  (nach Attic)  fremd? ==== */


void f_16cb84(undefined4 p1,undefined4 p2)

{
  f_16b60c(&DAT_001ce744,p1,p2);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CBDC-16CC10  (nach Attic)  fremd? ==== */


void f_16cbdc(undefined4 p1,uint p2)

{
  f_16b984(&DAT_001ce714,p2 & 0xffff,&DAT_001ce714,p1);
  f_16b60c(&DAT_001ce744,p1,&DAT_001ce714);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CC10-16CC44  (nach Attic)  fremd? ==== */


void f_16cc10(undefined4 p1,uint p2,undefined4 p3)

{
  f_16b9f4(&DAT_001ce714,p2 & 0xffff,p3,p1);
  f_16b60c(&DAT_001ce744,&DAT_001ce714,p1);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CC44-16CCAC  (nach Attic)  fremd? ==== */


void f_16cc44(undefined4 p1,uint p2)

{
  f_16b9f4(&DAT_001ce714,p2 & 0xffff,&DAT_001ce714,p1);
  f_16b60c(&DAT_001ce744,p1,&DAT_001ce714);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CCAC-16CCE0  (nach Attic)  fremd? ==== */


void f_16ccac(undefined4 p1,uint p2)

{
  f_16ba64(&DAT_001ce714,p2 & 0xffff,&DAT_001ce714,p1);
  f_16b60c(&DAT_001ce744,p1,&DAT_001ce714);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CCE0-16CD48  (nach Attic)  fremd? ==== */


void f_16cce0(undefined4 p1,uint p2,undefined4 p3)

{
  f_16bad4(&DAT_001ce714,p2 & 0xffff,p3,p1);
  f_16b60c(&DAT_001ce744,&DAT_001ce714,p1);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CD48-16CD74  (nach Attic)  fremd? ==== */


void f_16cd48(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  f_16bc24(&DAT_001ce714,p2,p3,p4);
  f_16b60c(&DAT_001ce744,&DAT_001ce714,p1);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CD74-16CDA0  (nach Attic)  fremd? ==== */


void f_16cd74(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  f_16bc24(&DAT_001ce714,p2,p3,p4);
  f_16b60c(&DAT_001ce744,p1,&DAT_001ce714);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CDA0-16CE50  (nach Attic)  fremd? ==== */


void f_16cda0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  f_16bc6c(&DAT_001ce714,p2,p3,p4);
  f_16b60c(&DAT_001ce744,&DAT_001ce714,p1);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CE50-16CF00  (nach Attic)  fremd? ==== */


void f_16ce50(undefined4 p1,undefined4 p2,undefined4 p3)

{
  f_16bd00(&DAT_001ce714,p2,p3);
  f_16b60c(&DAT_001ce744,&DAT_001ce714,p1);
  f_16b5c0(p1,&DAT_001ce744);
  return;
}




/* ==== 16CF00-16CF05  (nach Attic)  fremd? ==== */


ushort f_16cf00(undefined4 p1)

{
  return (ushort)p1 << 8 | (ushort)p1 >> 8;
}




/* ==== 16CF05-16CF6A  (nach Attic)  fremd? ==== */




undefined4 f_16cf05(undefined4 p1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  _DAT_001aa8a8 = p1;
  uVar1 = _DAT_001aa8a8;
  DAT_001aa8a8 = (undefined1)p1;
  DAT_001aa8a9 = (undefined1)((uint)p1 >> 8);
  DAT_001aa8aa = (undefined1)((uint)p1 >> 0x10);
  DAT_001aa8ab = (undefined1)((uint)p1 >> 0x18);
  uVar2 = CONCAT31(CONCAT21(CONCAT11(DAT_001aa8a8,DAT_001aa8a9),DAT_001aa8aa),DAT_001aa8ab);
  _DAT_001aa8a8 = uVar1;
  return uVar2;
}




/* ==== 16CF6A-16CFF5  (nach Attic)  fremd? ==== */


void f_16cf6a(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[1] * (longlong)p3[3]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[3]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10) + p3[9];
  p1[1] = ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[7]) >> 0x20) << 0x10) + p3[10];
  p1[2] = ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10) + p3[0xb];
  return;
}




/* ==== 16CFF5-16D077  (nach Attic)  fremd? ==== */


void f_16cff5(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[1] * (longlong)p3[3]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[3]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[2] * (longlong)p3[6]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[6]) >> 0x20) << 0x10);
  p1[1] = ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[7]) >> 0x20) << 0x10);
  p1[2] = ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10);
  return;
}




/* ==== 16D077-16D295  (nach Attic)  fremd? ==== */


void f_16d077(int *p1,int *p2,int *p3)

{
  *p1 = ((uint)((longlong)p2[1] * (longlong)p3[4]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[1] * (longlong)p3[4]) >> 0x20) << 0x10) +
        ((uint)((longlong)*p2 * (longlong)*p3) >> 0x10 |
        (int)((ulonglong)((longlong)*p2 * (longlong)*p3) >> 0x20) << 0x10) +
        ((uint)((longlong)p2[2] * (longlong)p3[8]) >> 0x10 |
        (int)((ulonglong)((longlong)p2[2] * (longlong)p3[8]) >> 0x20) << 0x10) + p3[0xc];
  p1[1] = ((uint)((longlong)p2[1] * (longlong)p3[5]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[5]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[1]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[1]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[9]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[9]) >> 0x20) << 0x10) + p3[0xd];
  p1[2] = ((uint)((longlong)p2[1] * (longlong)p3[6]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[6]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[2]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[10]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[10]) >> 0x20) << 0x10) + p3[0xe];
  p1[3] = ((uint)((longlong)p2[1] * (longlong)p3[7]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[1] * (longlong)p3[7]) >> 0x20) << 0x10) +
          ((uint)((longlong)*p2 * (longlong)p3[3]) >> 0x10 |
          (int)((ulonglong)((longlong)*p2 * (longlong)p3[3]) >> 0x20) << 0x10) +
          ((uint)((longlong)p2[2] * (longlong)p3[0xb]) >> 0x10 |
          (int)((ulonglong)((longlong)p2[2] * (longlong)p3[0xb]) >> 0x20) << 0x10) + p3[0xf];
  return;
}




/* ==== 16E060-16E080  (nach Attic)  fremd? ==== */


void f_16e060(int p1)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)(p1 + 0x20);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = &DAT_001b4518;
  }
  (**(code **)(puVar1 + 0x40))();
  return;
}




/* ==== 16E080-16E660  (nach Attic)  fremd? ==== */


void f_16e080(int p1,undefined4 p2,undefined4 p3)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)(p1 + 0x20);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = &DAT_001b4518;
  }
  (**(code **)(puVar1 + 0x38))();
  return;
}




/* ==== 16E660-16E680  (nach Attic)  fremd? ==== */


void f_16e660(int p1,undefined4 p2)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)(p1 + 0x20);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = &DAT_001b4518;
  }
  (**(code **)(puVar1 + 0x28))();
  return;
}




/* ==== 16E680-16E93C  (nach Attic)  fremd? ==== */


void f_16e680(int p1,undefined4 p2,undefined4 p3,undefined4 p4,undefined4 p5,undefined4 p6)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  short sVar4;
  short sVar5;
  
  puVar3 = *(undefined **)(p1 + 0x20);
  if (puVar3 == (undefined *)0x0) {
    puVar3 = &DAT_001b4518;
  }
  sVar1 = *(short *)(p1 + 0x18) + -1;
  sVar2 = *(short *)(p1 + 0x1a) + -1;
  sVar5 = (short)p5;
  sVar4 = (short)p4;
  if ((short)p4 < (short)p2) {
    sVar5 = (short)p3;
    sVar4 = (short)p2;
    (*((int16_t *)((char *)&(p3) + 0))) = (short)p5;
    (*((int16_t *)((char *)&(p2) + 0))) = (short)p4;
  }
  if (sVar4 < 0) {
    return;
  }
  if (sVar1 < (short)p2) {
    return;
  }
  if ((short)p3 < sVar5) {
    if (sVar5 < 0) {
      return;
    }
    if (sVar2 < (short)p3) {
      return;
    }
    if ((short)p3 < 0) {
      (*((int16_t *)((char *)&(p2) + 0))) = (short)p2 +
                 (short)((uint)(-(int)(short)p3 * ((int)sVar4 - (int)(short)p2)) /
                        (uint)((int)sVar5 - (int)(short)p3));
      if (sVar1 < (short)p2) {
        return;
      }
      (*((int16_t *)((char *)&(p3) + 0))) = 0;
    }
    if (sVar5 <= sVar2) goto LAB_0016e8ed;
    sVar5 = (short)((uint)(((int)sVar4 - (int)(short)p2) * ((int)sVar5 - (int)sVar2)) /
                   (uint)((int)sVar5 - (int)(short)p3));
  }
  else {
    if ((short)p3 < 0) {
      return;
    }
    if (sVar2 < sVar5) {
      return;
    }
    if ((sVar2 < (short)p3) &&
       ((*((int16_t *)((char *)&(p2) + 0))) = (short)p2 +
                   (short)((uint)(((int)sVar4 - (int)(short)p2) * ((int)(short)p3 - (int)sVar2)) /
                          (uint)((int)(short)p3 - (int)sVar5)), (*((int16_t *)((char *)&(p3) + 0))) = sVar2, sVar1 < (short)p2)
       ) {
      return;
    }
    if (-1 < sVar5) goto LAB_0016e8ed;
    sVar5 = (short)((uint)(-(int)sVar5 * ((int)sVar4 - (int)(short)p2)) /
                   (uint)((int)(short)p3 - (int)sVar5));
  }
  if ((short)(sVar4 - sVar5) < 0) {
    return;
  }
LAB_0016e8ed:
  (**(code **)(puVar3 + 0x2c))();
  return;
}




/* ==== 16E93C-16EBD8  (nach Attic)  fremd? ==== */


void f_16e93c(int p1,int p2,undefined4 p3,undefined4 p4,byte *p5,byte *p6)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_30;
  
  puVar1 = *(undefined **)(p1 + 0x20);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = &DAT_001b4518;
  }
  if (p5 == (byte *)0x0) {
    p5 = *(byte **)(puVar1 + 8);
  }
  iVar3 = -(uint)*(ushort *)(p5 + 6);
  iVar2 = (int)(short)p3;
  if (((iVar2 != iVar3 && SBORROW4(iVar2,iVar3) == (int)(iVar2 + (uint)*(ushort *)(p5 + 6)) < 0) &&
      (iVar2 < (int)(uint)*(ushort *)(p1 + 0x1a))) &&
     ((int)(short)p2 < (int)(uint)*(ushort *)(p1 + 0x18))) {
    local_30 = (uint)*(ushort *)(p1 + 0x18) - (int)(short)p2;
    if ((*p5 & 1) == 0) {
      uVar4 = (uint)*(ushort *)(p5 + 4);
      if (*p6 != 0) {
        do {
          if (0 < (int)((int)(short)p2 + uVar4)) {
            (**(code **)(puVar1 + 0x30))();
          }
          local_30 = local_30 - (uVar4 + 1);
          p2 = p2 + uVar4 + 1;
        } while ((0 < local_30) && (p6 = p6 + 1, *p6 != 0));
      }
    }
    else {
      while( true ) {
        if (*p6 == 0) {
          return;
        }
        iVar2 = (int)*(char *)((uint)*p6 + *(int *)(p5 + 0xc));
        if (0 < (short)p2 + iVar2) {
          (**(code **)(puVar1 + 0x30))();
        }
        p2 = p2 + iVar2 + 1;
        local_30 = local_30 - (iVar2 + 1);
        if (local_30 < 1) break;
        p6 = p6 + 1;
      }
    }
  }
  return;
}




/* ==== 16EBD8-16ECB4  (nach Attic)  fremd? ==== */


void f_16ebd8(int p1, int p2, int p3, int p4, ...) {}




/* ==== 16ECB4-16ECBA  (nach Attic)  fremd? ==== */


void f_16ecb4(undefined4 p1)

{
  DAT_001ad9e3 = (undefined1)p1;
  return;
}




/* ==== 16ECBA-16ECC0  (nach Attic)  fremd? ==== */


void f_16ecba(undefined4 p1)

{
  DAT_001ad9e4 = (undefined1)p1;
  return;
}




/* ==== 16ECC0-16F086  (nach Attic)  fremd? ==== */




int f_16ecc0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  short sVar6;
  short *psVar7;
  undefined4 *puVar8;
  short *psVar9;
  undefined4 *puVar10;
  int in_stack_00000004;
  int local_e;
  short local_a;
  int local_8;
  
  *(undefined4 *)((int)&DAT_001ccf5e + in_stack_00000004 * 4 + 2) = (*(uint32_t *)(&DAT_001ccf60));
  psVar7 = (short *)((int)&DAT_001ccf5e + 2);
  psVar9 = &DAT_001ccf38;
  local_8 = in_stack_00000004 + 1;
  in_stack_00000004 = 1;
  uVar3 = (short)DAT_001cdb4c - (*((int16_t *)((char *)&(DAT_001ccf5e) + 2))) & 0x8000;
  while( true ) {
    local_8 = local_8 + -1;
    if (local_8 == 0) break;
    uVar4 = (short)DAT_001cdb4c - psVar7[2] & 0x8000;
    if (uVar3 != 0) {
      psVar1 = psVar9 + 1;
      *psVar9 = *psVar7;
      psVar9 = psVar9 + 2;
      *psVar1 = psVar7[1];
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (uVar3 != uVar4) {
      if (*psVar7 < psVar7[2]) {
        *psVar9 = (short)DAT_001cdb4c;
        sVar2 = (short)(((int)(short)(psVar7[3] - psVar7[1]) *
                        (int)(short)((short)DAT_001cdb4c - *psVar7)) /
                       (int)(short)(psVar7[2] - *psVar7));
        sVar6 = psVar7[1];
      }
      else {
        *psVar9 = (short)DAT_001cdb4c;
        sVar2 = (short)(((int)(short)(psVar7[3] - psVar7[1]) *
                        (int)(short)((short)DAT_001cdb4c - psVar7[2])) /
                       (int)(short)(psVar7[2] - *psVar7));
        sVar6 = psVar7[3];
      }
      psVar1 = psVar9 + 1;
      psVar9 = psVar9 + 2;
      *psVar1 = sVar2 + sVar6;
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    psVar7 = psVar7 + 2;
    uVar3 = uVar4;
  }
  *(undefined4 *)psVar9 = _DAT_001ccf38;
  psVar7 = &DAT_001ccf38;
  psVar9 = (short *)((int)&DAT_001ccf5e + 2);
  local_8 = in_stack_00000004;
  in_stack_00000004 = 1;
  uVar3 = DAT_001ccf38 - (short)DAT_001cdb6c & 0x8000;
  while( true ) {
    local_8 = local_8 + -1;
    if (local_8 == 0) break;
    uVar4 = psVar7[2] - (short)DAT_001cdb6c & 0x8000;
    if (uVar3 != 0) {
      psVar1 = psVar9 + 1;
      *psVar9 = *psVar7;
      psVar9 = psVar9 + 2;
      *psVar1 = psVar7[1];
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (uVar3 != uVar4) {
      if (*psVar7 < psVar7[2]) {
        *psVar9 = (short)DAT_001cdb6c;
        sVar2 = (short)(((int)(short)(psVar7[3] - psVar7[1]) *
                        (int)(short)((short)DAT_001cdb6c - *psVar7)) /
                       (int)(short)(psVar7[2] - *psVar7));
        sVar6 = psVar7[1];
      }
      else {
        *psVar9 = (short)DAT_001cdb6c;
        sVar2 = (short)(((int)(short)(psVar7[3] - psVar7[1]) *
                        (int)(short)((short)DAT_001cdb6c - psVar7[2])) /
                       (int)(short)(psVar7[2] - *psVar7));
        sVar6 = psVar7[3];
      }
      psVar1 = psVar9 + 1;
      psVar9 = psVar9 + 2;
      *psVar1 = sVar2 + sVar6;
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    psVar7 = psVar7 + 2;
    uVar3 = uVar4;
  }
  *(undefined4 *)psVar9 = (*(uint32_t *)(&DAT_001ccf60));
  psVar7 = (short *)((int)&DAT_001ccf5e + 2);
  psVar9 = &DAT_001ccf38;
  local_8 = in_stack_00000004;
  in_stack_00000004 = 1;
  uVar3 = (short)DAT_001cdb50 - DAT_001ccf62 & 0x8000;
  while( true ) {
    local_8 = local_8 + -1;
    if (local_8 == 0) break;
    uVar4 = (short)DAT_001cdb50 - psVar7[3] & 0x8000;
    if (uVar3 != 0) {
      psVar1 = psVar9 + 1;
      *psVar9 = *psVar7;
      psVar9 = psVar9 + 2;
      *psVar1 = psVar7[1];
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (uVar3 != uVar4) {
      if (psVar7[1] < psVar7[3]) {
        sVar2 = (short)(((int)(short)(psVar7[2] - *psVar7) *
                        (int)(short)((short)DAT_001cdb50 - psVar7[1])) /
                       (int)(short)(psVar7[3] - psVar7[1]));
        sVar6 = *psVar7;
      }
      else {
        sVar2 = (short)(((int)(short)(psVar7[2] - *psVar7) *
                        (int)(short)((short)DAT_001cdb50 - psVar7[3])) /
                       (int)(short)(psVar7[3] - psVar7[1]));
        sVar6 = psVar7[2];
      }
      psVar1 = psVar9 + 1;
      *psVar9 = sVar2 + sVar6;
      psVar9 = psVar9 + 2;
      *psVar1 = (short)DAT_001cdb50;
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    psVar7 = psVar7 + 2;
    uVar3 = uVar4;
  }
  *(undefined4 *)psVar9 = _DAT_001ccf38;
  psVar7 = &DAT_001ccf38;
  psVar9 = (short *)((int)&DAT_001ccf5e + 2);
  local_a = 0x7fff;
  local_8 = in_stack_00000004;
  in_stack_00000004 = 0;
  uVar3 = _DAT_001ccf3a - (short)DAT_001cdb68 & 0x8000;
  while( true ) {
    local_8 = local_8 + -1;
    if (local_8 == 0) break;
    uVar4 = psVar7[3] - (short)DAT_001cdb68 & 0x8000;
    if (uVar3 != 0) {
      psVar1 = psVar9 + 1;
      *psVar9 = *psVar7;
      sVar6 = psVar7[1];
      psVar9 = psVar9 + 2;
      *psVar1 = sVar6;
      if (sVar6 < local_a) {
        local_e = in_stack_00000004;
        local_a = sVar6;
      }
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (uVar3 != uVar4) {
      if (psVar7[1] < psVar7[3]) {
        sVar2 = (short)(((int)(short)(psVar7[2] - *psVar7) *
                        (int)(short)((short)DAT_001cdb68 - psVar7[1])) /
                       (int)(short)(psVar7[3] - psVar7[1]));
        sVar6 = *psVar7;
      }
      else {
        sVar2 = (short)(((int)(short)(psVar7[2] - *psVar7) *
                        (int)(short)((short)DAT_001cdb68 - psVar7[3])) /
                       (int)(short)(psVar7[3] - psVar7[1]));
        sVar6 = psVar7[2];
      }
      psVar1 = psVar9 + 1;
      *psVar9 = sVar2 + sVar6;
      psVar9 = psVar9 + 2;
      *psVar1 = (short)DAT_001cdb68;
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    psVar7 = psVar7 + 2;
    uVar3 = uVar4;
  }
  if (in_stack_00000004 != 0) {
    puVar8 = (undefined4 *)((int)&DAT_001ccf5e + local_e * 4 + 2);
    puVar10 = (undefined4 *)&DAT_001ccf38;
    for (iVar5 = in_stack_00000004 - local_e; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    puVar8 = (undefined4 *)((int)&DAT_001ccf5e + 2);
    for (; local_e != 0; local_e = local_e + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    *puVar10 = _DAT_001ccf38;
  }
  return in_stack_00000004;
}




/* ==== 16F830-16F867  (nach Attic)  fremd? ==== */


uint f_16f830(undefined4 p1,undefined4 p2,uint p3,int p4)

{
  DAT_001ad9e6 = (((uint)(p4 - DAT_001cdb50 < 0) << 1 | (uint)(DAT_001cdb68 - p4 < 0)) << 1 |
                 (uint)((int)(DAT_001cdb6c - p3) < 0)) << 1 | (uint)((int)(p3 - DAT_001cdb4c) < 0);
  return (p3 - DAT_001cdb4c) * 2 | (uint)(p3 < DAT_001cdb4c);
}




/* ==== 16F867-16F992  (nach Attic)  fremd? ==== */


void f_16f867(undefined4 p1,undefined4 p2,undefined4 p3,uint p4)

{
  int iVar1;
  
  if ((p4 & 1) == 0) {
    if ((((p4 & 2) != 0) &&
        (iVar1 = (int)(((longlong)(DAT_001cdb6c - DAT_001ad9ea) * (longlong)DAT_001ada06) /
                      (longlong)DAT_001ada02) + DAT_001ad9ee, DAT_001cdb50 <= iVar1)) &&
       (iVar1 <= DAT_001cdb68)) {
      DAT_001ad9ea = DAT_001cdb6c;
      p4 = 0;
      DAT_001ad9ee = iVar1;
    }
  }
  else {
    iVar1 = (int)(((longlong)(DAT_001cdb4c - DAT_001ad9ea) * (longlong)DAT_001ada06) /
                 (longlong)DAT_001ada02) + DAT_001ad9ee;
    if ((DAT_001cdb50 <= iVar1) && (iVar1 <= DAT_001cdb68)) {
      DAT_001ad9ee = iVar1;
      DAT_001ad9ea = DAT_001cdb4c;
      return;
    }
  }
  if ((p4 & 4) == 0) {
    if ((((p4 & 8) != 0) &&
        (iVar1 = (int)(((longlong)(DAT_001cdb50 - DAT_001ad9ee) * (longlong)DAT_001ada02) /
                      (longlong)DAT_001ada06) + DAT_001ad9ea, DAT_001cdb4c <= iVar1)) &&
       (iVar1 <= DAT_001cdb6c)) {
      DAT_001ad9ee = DAT_001cdb50;
      DAT_001ad9ea = iVar1;
    }
  }
  else {
    iVar1 = (int)(((longlong)(DAT_001cdb68 - DAT_001ad9ee) * (longlong)DAT_001ada02) /
                 (longlong)DAT_001ada06) + DAT_001ad9ea;
    if ((DAT_001cdb4c <= iVar1) && (iVar1 <= DAT_001cdb6c)) {
      DAT_001ad9ea = iVar1;
      DAT_001ad9ee = DAT_001cdb68;
      return;
    }
  }
  return;
}




/* ==== 16F992-16FB53  (nach Attic)  fremd? ==== */


void f_16f992(undefined4 p1,uint p2,int p3,int p4)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  
  uVar6 = DAT_001ad9e6;
  f_16f830(p1,p2,p3,p4);
  if (p2 != 0 || uVar6 != 0) {
    if ((p2 & uVar6) != 0) {
      return;
    }
    DAT_001ada02 = DAT_001ad9f2 - p3;
    DAT_001ada06 = DAT_001ad9f6 - p4;
    if ((p2 != 0) && (f_16f867(DAT_001ada06,p2,p3,p2), p2 != 0)) {
      return;
    }
    iVar3 = DAT_001ad9ee;
    iVar7 = DAT_001ad9ea;
    if (uVar6 != 0) {
      DAT_001ad9ea = DAT_001ad9f2;
      DAT_001ad9f2 = iVar7;
      DAT_001ad9ee = DAT_001ad9f6;
      DAT_001ad9f6 = iVar3;
      f_16f867(iVar3,p2,p3,uVar6);
      if (uVar6 != 0) {
        return;
      }
    }
  }
  iVar3 = DAT_001ad9f6;
  iVar7 = DAT_001ad9f2;
  uVar1 = DAT_001ad9e4;
  uVar6 = DAT_001ad9f2 - DAT_001ad9ea;
  if (DAT_001ad9f2 < DAT_001ad9ea) {
    LOCK();
    DAT_001ad9f6 = DAT_001ad9ee;
    UNLOCK();
    LOCK();
    DAT_001ad9ee = iVar3;
    UNLOCK();
    LOCK();
    DAT_001ad9f2 = DAT_001ad9ea;
    UNLOCK();
    LOCK();
    DAT_001ad9ea = iVar7;
    UNLOCK();
    uVar6 = -uVar6;
  }
  uVar2 = DAT_001ad9f6 - DAT_001ad9ee;
  if (uVar2 == 0) {
    puVar9 = (undefined1 *)
             (DAT_001ad9ea +
             (DAT_001ad9ee + DAT_001cdb48) * DAT_001a9a60 + DAT_001cdb44 + DAT_001a991c);
    for (iVar7 = uVar6 + 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = uVar1;
      puVar9 = puVar9 + 1;
    }
    return;
  }
  iVar7 = DAT_001a9a60;
  if (uVar2 == 0 || DAT_001ad9f6 < DAT_001ad9ee) {
    uVar2 = -uVar2;
    iVar7 = -DAT_001a9a60;
  }
  if (uVar6 == 0) {
    puVar9 = (undefined1 *)
             (DAT_001ad9ea +
             (DAT_001ad9ee + DAT_001cdb48) * DAT_001a9a60 + DAT_001cdb44 + DAT_001a991c);
    iVar3 = uVar2 + 1;
    do {
      *puVar9 = uVar1;
      puVar9 = puVar9 + iVar7;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  if ((int)uVar6 <= (int)uVar2) {
    puVar9 = (undefined1 *)
             (DAT_001ad9ea +
             (DAT_001ad9ee + DAT_001cdb48) * DAT_001a9a60 + DAT_001cdb44 + DAT_001a991c);
    iVar3 = uVar2 + 1;
    uVar4 = uVar2 >> 1;
    do {
      *puVar9 = uVar1;
      puVar9 = puVar9 + iVar7;
      uVar5 = uVar4 - uVar6;
      if ((int)uVar4 < (int)uVar6) {
        uVar5 = uVar5 + uVar2;
        puVar9 = puVar9 + 1;
      }
      iVar3 = iVar3 + -1;
      uVar4 = uVar5;
    } while (iVar3 != 0);
    return;
  }
  iVar3 = uVar6 + 1;
  uVar4 = uVar6 >> 1;
  puVar9 = (undefined1 *)
           (DAT_001ad9ea +
           (DAT_001ad9ee + DAT_001cdb48) * DAT_001a9a60 + DAT_001cdb44 + DAT_001a991c);
  do {
    puVar8 = puVar9 + 1;
    *puVar9 = uVar1;
    uVar5 = uVar4 - uVar2;
    if ((int)uVar4 < (int)uVar2) {
      uVar5 = uVar5 + uVar6;
      puVar8 = puVar8 + iVar7;
    }
    iVar3 = iVar3 + -1;
    uVar4 = uVar5;
    puVar9 = puVar8;
  } while (iVar3 != 0);
  return;
}




/* ==== 16FC50-16FF04  (nach Attic)  fremd? ==== */


undefined4 f_16fc50(int p1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  short sVar8;
  short sVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  short sVar15;
  int iVar16;
  short sVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  undefined4 local_50;
  undefined4 local_4c;
  short local_28;
  short local_1c;
  
  iVar22 = DAT_001cd224;
  DAT_001ce808 = 1;
  puVar10 = (ushort *)(p1 + 10);
  piVar21 = (int *)(DAT_001cd224 + (uint)*puVar10 * 8);
  iVar11 = *piVar21 + 0x8000;
  sVar8 = (short)((uint)iVar11 >> 0x10);
  local_50 = CONCAT22(sVar8,sVar8);
  iVar18 = *(int *)(DAT_001cd314 + 8 + (uint)*puVar10 * 0xc);
  iVar12 = piVar21[1];
  *(int *)(p1 + 0x40) = iVar18;
  iVar18 = -iVar18;
  *(int *)(p1 + 0x40) = iVar18;
  iVar12 = iVar12 + 0x8000;
  *(int *)(p1 + 0x3c) = iVar18;
  sVar9 = (short)((uint)iVar12 >> 0x10);
  local_4c = CONCAT22(sVar9,sVar9);
  sVar17 = (short)((uint)(*(int *)(iVar22 + 4 + (uint)*(ushort *)(p1 + 0xc) * 8) + 0x8000) >> 0x10);
  bVar2 = sVar17 < sVar9;
  bVar4 = sVar9 < sVar17;
  sVar17 = (short)((uint)(*(int *)(iVar22 + (uint)*(ushort *)(p1 + 0xc) * 8) + 0x8000) >> 0x10);
  bVar3 = sVar17 < sVar8;
  bVar5 = sVar8 < sVar17;
  uVar19 = (uint)*(ushort *)(p1 + 4);
  iVar18 = 0;
  iVar22 = 0;
  uVar6 = local_50;
  uVar7 = local_4c;
  sVar17 = sVar9;
  sVar15 = sVar8;
  while (uVar19 = uVar19 - 1, 0 < (int)uVar19) {
    piVar21 = (int *)(DAT_001cd224 + (uint)puVar10[1] * 8);
    iVar16 = *piVar21 + 0x8000;
    iVar13 = piVar21[1] + 0x8000;
    sVar15 = (short)((uint)iVar16 >> 0x10);
    iVar1 = *(int *)((uint)puVar10[1] * 0xc + DAT_001cd314 + 8);
    iVar20 = -iVar1;
    sVar17 = (short)((uint)iVar13 >> 0x10);
    if (iVar20 < *(int *)(p1 + 0x3c)) {
      *(int *)(p1 + 0x3c) = iVar20;
    }
    else if (-*(int *)(p1 + 0x40) != iVar1 && *(int *)(p1 + 0x40) <= iVar20) {
      *(int *)(p1 + 0x40) = iVar20;
    }
    (*((int16_t *)((char *)&(local_50) + 0))) = (short)uVar6;
    (*((int16_t *)((char *)&(local_50) + 2))) = (short)((uint)uVar6 >> 0x10);
    if (sVar15 < (short)local_50) {
      local_50 = CONCAT22((*((int16_t *)((char *)&(local_50) + 2))),sVar15);
      uVar6 = local_50;
    }
    else if ((*((int16_t *)((char *)&(local_50) + 2))) < sVar15) {
      local_50 = CONCAT22(sVar15,(short)local_50);
      uVar6 = local_50;
    }
    local_50 = uVar6;
    (*((int16_t *)((char *)&(local_4c) + 0))) = (short)uVar7;
    (*((int16_t *)((char *)&(local_4c) + 2))) = (short)((uint)uVar7 >> 0x10);
    if (sVar17 < (short)local_4c) {
      local_4c = CONCAT22((*((int16_t *)((char *)&(local_4c) + 2))),sVar17);
      uVar7 = local_4c;
    }
    else if ((*((int16_t *)((char *)&(local_4c) + 2))) < sVar17) {
      local_4c = CONCAT22(sVar17,(short)local_4c);
      uVar7 = local_4c;
    }
    local_4c = uVar7;
    local_1c = (short)((uint)iVar12 >> 0x10);
    if ((bVar4) && (sVar17 < local_1c)) {
      bVar4 = false;
      bVar2 = true;
      iVar22 = iVar22 + 1;
    }
    else if ((bVar2) && (local_1c < sVar17)) {
      bVar4 = true;
      bVar2 = false;
      iVar22 = iVar22 + 1;
    }
    local_28 = (short)((uint)iVar11 >> 0x10);
    if ((bVar5) && (sVar15 < local_28)) {
      bVar5 = false;
      bVar3 = true;
      iVar18 = iVar18 + 1;
    }
    else if ((bVar3) && (local_28 < sVar15)) {
      bVar5 = true;
      bVar3 = false;
      iVar18 = iVar18 + 1;
    }
    puVar10 = puVar10 + 1;
    iVar11 = iVar16;
    iVar12 = iVar13;
    uVar6 = local_50;
    uVar7 = local_4c;
  }
  if ((bVar4) && (sVar9 < sVar17)) {
    iVar22 = iVar22 + 1;
  }
  if ((bVar2) && (sVar17 < sVar9)) {
    iVar22 = iVar22 + 1;
  }
  if ((bVar5) && (sVar8 < sVar15)) {
    iVar18 = iVar18 + 1;
  }
  if ((bVar3) && (sVar15 < sVar8)) {
    iVar18 = iVar18 + 1;
  }
  if ((iVar18 < 3) && (iVar22 < 3)) {
    if (*(ushort *)(p1 + 4) < 3) {
      DAT_001ce807 = 0;
      return 0;
    }
    uVar14 = 1;
    *(undefined4 *)(p1 + 0x4c) = uVar6;
    *(undefined4 *)(p1 + 0x50) = uVar7;
  }
  else {
    uVar14 = 0;
    DAT_001ce808 = 0;
  }
  return uVar14;
}




/* ==== 16FF04-16FF84  (nach Attic)  fremd? ==== */


void f_16ff04(int p1)

{
  undefined2 *puVar1;
  int *piVar2;
  uint uVar3;
  ushort *puVar4;
  
  *(undefined4 *)(p1 + 0x56) = *(undefined4 *)(p1 + 0x4c);
  *(undefined4 *)(p1 + 0x5a) = *(undefined4 *)(p1 + 0x50);
  *(undefined2 *)(p1 + 0x54) = *(undefined2 *)(p1 + 4);
  puVar4 = (ushort *)(p1 + 10);
  uVar3 = (uint)*(ushort *)(p1 + 4);
  puVar1 = (undefined2 *)(p1 + 0x5e);
  if (uVar3 == 0) {
    return;
  }
  do {
    piVar2 = (int *)((uint)*puVar4 * 8 + DAT_001cd224);
    *puVar1 = (short)((uint)(*piVar2 + 0x8000) >> 0x10);
    puVar4 = puVar4 + 1;
    puVar1[1] = (short)((uint)(piVar2[1] + 0x8000) >> 0x10);
    uVar3 = uVar3 - 1;
    puVar1 = puVar1 + 2;
  } while (uVar3 != 0);
  return;
}




/* ==== 16FF84-17004C  (nach Attic)  fremd? ==== */


undefined4 f_16ff84(byte *p1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_001ce7f8;
  if (DAT_001a9a44 <= DAT_001a9a00) {
    return 0;
  }
  *(undefined1 *)(DAT_001ce7f8 + 1) = 1;
  *(undefined1 *)(iVar2 + 2) = 1;
  *(undefined1 *)(iVar2 + 3) = 0;
  iVar1 = DAT_001ce7d0;
  *(undefined2 *)(iVar2 + 0x86) = 0;
  *(int *)(iVar2 + 0x44) = iVar1;
  *(int *)(iVar2 + 0x48) = DAT_001ce7c8;
  iVar1 = DAT_001ce7d0;
  *(undefined2 *)(iVar2 + 0x88) = 0;
  if ((((*(byte *)(*(int *)(iVar1 + 0x7c) + 10) & 1) == 0) && (DAT_001ce7c8 != 0)) &&
     (*(char *)(*(int *)DAT_001ce7c8 + 1) == 'T')) {
    *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) & 0xfe;
  }
  if ((*p1 & 0x10) != 0) {
    *(byte *)(DAT_001ce7f8 + 2) = *(byte *)(DAT_001ce7f8 + 2) | 0x80;
  }
  f_16ff04(DAT_001ce7f8);
  iVar2 = DAT_001ce7f8 + 0x9c;
  *(int *)(DAT_001cd220 + DAT_001a9a00 * 4) = DAT_001ce7f8;
  DAT_001ce7f8 = iVar2;
  DAT_001a9a00 = DAT_001a9a00 + 1;
  return 1;
}




/* ==== 17004C-1702B8  (nach Attic)  fremd? ==== */


undefined4 f_17004c(int p1,undefined4 p2,ushort *p3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  ushort *puVar5;
  uint uVar6;
  short *psVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  short *psVar13;
  int local_14;
  
  DAT_001ce7f4 = p1;
  if (p1 < 0xf) {
    DAT_001ce806 = 1;
    DAT_001ce805 = 0;
    DAT_001ce807 = 1;
    if (DAT_001ce804 != '\0') {
      pbVar4 = (byte *)&DAT_001c9330;
      iVar8 = 0;
      puVar5 = p3;
      if (0 < p1) {
        do {
          uVar2 = *puVar5;
          puVar11 = (ushort *)(DAT_001ce7c4 + (uint)uVar2 * 0xc);
          uVar6 = (uint)*puVar11;
          *(undefined4 *)(pbVar4 + 8) = *(undefined4 *)(puVar11 + 2);
          *(undefined4 *)(pbVar4 + 0xc) = *(undefined4 *)(puVar11 + 4);
          *(ushort *)(pbVar4 + 2) = uVar2;
          puVar12 = (undefined4 *)(uVar6 * 0xc + DAT_001ce7d4);
          *(undefined4 *)(pbVar4 + 0x10) = *puVar12;
          *(undefined4 *)(pbVar4 + 0x14) = puVar12[1];
          *(undefined4 *)(pbVar4 + 0x18) = puVar12[2];
          puVar12 = (undefined4 *)(uVar6 * 8 + DAT_001ce7bc);
          *(undefined4 *)(pbVar4 + 0x1c) = *puVar12;
          *(undefined4 *)(pbVar4 + 0x20) = puVar12[1];
          bVar1 = *(byte *)(uVar6 + DAT_001ce7fc);
          iVar8 = iVar8 + 1;
          *pbVar4 = bVar1;
          pbVar4 = pbVar4 + 0x28;
          DAT_001ce805 = DAT_001ce805 | bVar1;
          puVar5 = puVar5 + 1;
        } while (iVar8 < DAT_001ce7f4);
      }
      if (DAT_001ce805 != 0) {
        DAT_001ce7f4 = f_1803e4(DAT_001ce7f4);
        if (DAT_001ce7f4 < 3) {
          DAT_001ce807 = 0;
          return 0;
        }
        if (0xe < DAT_001ce7f4) {
          DAT_001ce806 = 0;
          return 0;
        }
      }
    }
    if (DAT_001ce805 == 0) {
      puVar12 = &DAT_001ce780;
      psVar7 = (short *)&DAT_001ce7d8;
      iVar8 = 0;
      if (0 < DAT_001ce7f4) {
        do {
          uVar2 = *p3;
          p3 = p3 + 1;
          iVar8 = iVar8 + 1;
          psVar13 = (short *)(DAT_001ce7c4 + (uint)uVar2 * 0xc);
          *psVar7 = DAT_001ce802 + *psVar13;
          iVar3 = DAT_001ce7f4;
          *puVar12 = psVar13 + 2;
          psVar7 = psVar7 + 1;
          puVar12 = puVar12 + 1;
        } while (iVar8 < iVar3);
      }
    }
    else {
      psVar7 = (short *)&DAT_001ce7d8;
      puVar9 = &DAT_001ce780;
      puVar12 = &DAT_001c9330;
      local_14 = 0;
      if (0 < DAT_001ce7f4) {
        do {
          if (*(ushort *)((int)puVar12 + 2) == 0xffff) {
            *psVar7 = (short)DAT_001a99fc;
            *puVar9 = DAT_001cd31c;
            *DAT_001ce7c0 = puVar12[4];
            DAT_001ce7c0[1] = puVar12[5];
            DAT_001ce7c0[2] = puVar12[6];
            *DAT_001ce7cc = puVar12[7];
            DAT_001ce7cc[1] = puVar12[8];
            DAT_001ce7c0 = DAT_001ce7c0 + 3;
            DAT_001ce7cc = DAT_001ce7cc + 2;
            *DAT_001cd31c = puVar12[2];
            DAT_001cd31c[1] = puVar12[3];
            DAT_001cd31c = DAT_001cd31c + 2;
            DAT_001a99fc = DAT_001a99fc + 1;
          }
          else {
            psVar13 = (short *)((uint)*(ushort *)((int)puVar12 + 2) * 0xc + DAT_001ce7c4);
            *psVar7 = DAT_001ce802 + *psVar13;
            *puVar9 = psVar13 + 2;
          }
          puVar12 = puVar12 + 10;
          psVar7 = psVar7 + 1;
          local_14 = local_14 + 1;
          puVar9 = puVar9 + 1;
        } while (local_14 < DAT_001ce7f4);
      }
    }
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
    DAT_001ce806 = 0;
  }
  return uVar10;
}




/* ==== 1702B8-1707F8  (nach Attic)  fremd? ==== */


undefined2 f_1702b8(char *p1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte bVar4;
  bool bVar5;
  byte *pbVar6;
  undefined2 uVar7;
  ushort *puVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  int p1_00;
  byte *pbVar16;
  byte *local_3c;
  uint local_24;
  uint local_20;
  
  if (DAT_001a9a00 < DAT_001a9a44) {
    if (((p1[0x10] & 0x40U) != 0) || ((p1[0x10] & 0x31U) == 0)) {
      return 0;
    }
    iVar3 = *(int *)(p1 + 0x80);
    DAT_001ce802 = *(ushort *)(p1 + 6);
    DAT_001ce800 = *(short *)(p1 + 8);
    DAT_001ce7f8 = (byte *)(DAT_001cd21c + DAT_001a9a00 * 0x9c);
    DAT_001ce7c4 = *(int *)(iVar3 + 0x40);
    DAT_001ce7bc = *(undefined4 *)(p1 + 0x24);
    DAT_001ce7d4 = *(undefined4 *)(p1 + 0x1c);
    DAT_001ce7b8 = *(undefined4 *)(p1 + 0x20);
    DAT_001ce804 = *p1 != '\0';
    DAT_001ce7fc = DAT_001cdc14 + (uint)DAT_001ce802;
    DAT_001ce7c0 = DAT_001cd314 + DAT_001a99fc * 0xc;
    DAT_001ce7cc = DAT_001cd224 + DAT_001a99fc * 8;
    DAT_001ce7d0 = p1;
    *(short *)(p1 + 10) = (short)DAT_001a9a00;
    uVar12 = DAT_001cd318 + (DAT_001a9a40 + -8) * 8;
    bVar4 = (*((uint8_t *)((char *)&(DAT_001a9a1c) + 2))) & 0x10;
    local_3c = (byte *)0x0;
    if (*(short *)(*(int *)(p1 + 0x7c) + 8) != 0) {
      local_3c = (byte *)f_172870(p1);
      if (local_3c != (byte *)0x0) {
        p1[0x11] = p1[0x11] | 4;
      }
    }
    local_20 = 0;
    uVar2 = *(ushort *)(iVar3 + 10);
    p1_00 = *(int *)(iVar3 + 0x44);
    if (uVar2 != 0) {
      do {
        if (local_3c == (byte *)0x0) {
          local_24 = local_20;
        }
        else {
          local_24 = (uint)*local_3c;
          local_3c = local_3c + 1;
          p1_00 = *(int *)(iVar3 + 0x44) + local_24 * 0x30;
        }
        DAT_001ce7c8 = *(int *)(p1_00 + 0x28);
        if ((bVar4 == 0) || ((DAT_001ce7c8 != 0 && (*(int *)(DAT_001ce7c8 + 0x2c) != 0)))) {
          if ((DAT_001ce7c8 == 0) || ((*(byte *)(DAT_001ce7c8 + 0xd) & 0x10) != 0)) {
            bVar5 = false;
          }
          else {
            bVar5 = true;
          }
          if (DAT_001ce804 != '\0') {
            puVar8 = (ushort *)(p1_00 + 2);
            bVar15 = *(byte *)(DAT_001ce7fc + (uint)*(ushort *)(DAT_001ce7c4 + (uint)*puVar8 * 0xc))
            ;
            uVar13 = (uint)*(byte *)(p1_00 + 1);
            while( true ) {
              puVar8 = puVar8 + 1;
              uVar13 = uVar13 - 1;
              if (uVar13 == 0) break;
              bVar15 = bVar15 & *(byte *)(DAT_001ce7fc +
                                         (uint)*(ushort *)(DAT_001ce7c4 + (uint)*puVar8 * 0xc));
            }
            if (bVar15 != 0) {
              goto LAB_00170708;
            }
          }
          if (bVar5) {
            uint16_t f_idx = *(uint16_t *)(p1_00 + 2);
            uint16_t v_idx = *(uint16_t *)(DAT_001ce7c4 + (uint32_t)f_idx * 0xc);
            iVar9 = f_16d361((int *)(DAT_001ce7b8 + (uint)*(ushort *)(p1_00 + 0x24) * 0xc), (int *)(DAT_001ce7d4 + (uint32_t)v_idx * 0xc));
            if (0 < iVar9) {
              goto LAB_00170708;
            }
          }
          if (uVar12 < DAT_001cd31c) break;
          iVar9 = f_17004c((uint)*(byte *)(p1_00 + 1),(uint)*(ushort *)(p1_00 + 0x24),p1_00 + 2);
          if (iVar9 != 0) {
            for (; 8 < (int)DAT_001ce7f4; DAT_001ce7f4 = DAT_001ce7f4 - 6) {
              bVar15 = 0;
              pbVar10 = (byte *)&DAT_001ce7d8;
              pbVar16 = DAT_001ce7f8 + 10;
              for (iVar9 = 4; iVar9 != 0; iVar9 = iVar9 + -1) {
                *(undefined4 *)pbVar16 = *(undefined4 *)pbVar10;
                pbVar10 = pbVar10 + 4;
                pbVar16 = pbVar16 + 4;
              }
              for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                *pbVar16 = *pbVar10;
                pbVar10 = pbVar10 + 1;
                pbVar16 = pbVar16 + 1;
              }
              iVar14 = 0;
              pbVar10 = (byte *)&DAT_001ce780;
              pbVar16 = DAT_001ce7f8 + 0x1c;
              for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
                *(undefined4 *)pbVar16 = *(undefined4 *)pbVar10;
                pbVar10 = pbVar10 + 4;
                pbVar16 = pbVar16 + 4;
              }
              for (iVar9 = 0; pbVar6 = DAT_001ce7f8, iVar9 != 0; iVar9 = iVar9 + -1) {
                *pbVar16 = *pbVar10;
                pbVar10 = pbVar10 + 1;
                pbVar16 = pbVar16 + 1;
              }
              pbVar10 = (byte *)&DAT_001c9330;
              do {
                iVar14 = iVar14 + 1;
                bVar1 = *pbVar10;
                pbVar10 = pbVar10 + 0x28;
                bVar15 = bVar15 | bVar1;
              } while (iVar14 < 8);
              pbVar10 = DAT_001ce7f8;
              pbVar10[4] = 8;
              pbVar10[5] = 0;
              *pbVar6 = bVar15;
              *(short *)(pbVar6 + 6) = DAT_001ce800 + *(short *)(p1_00 + 0x24);
              iVar9 = f_16fc50(pbVar6);
              if (iVar9 != 0) {
                iVar9 = f_16ff84(p1_00);
                if (iVar9 == 0) goto LAB_00170720;
              }
              f_14d075((void *)(&DAT_001ce7da), (void *)(&DAT_001ce7e6), (DAT_001ce7f4 - 7) * 2);
              f_14d075((void *)(&DAT_001ce784), (void *)(&DAT_001ce79c), (DAT_001ce7f4 - 7) * 4);
            }
            uVar13 = DAT_001ce7f4 * 2;
            pbVar10 = (byte *)&DAT_001ce7d8;
            pbVar16 = DAT_001ce7f8 + 10;
            for (uVar11 = uVar13 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pbVar16 = *(undefined4 *)pbVar10;
              pbVar10 = pbVar10 + 4;
              pbVar16 = pbVar16 + 4;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *pbVar16 = *pbVar10;
              pbVar10 = pbVar10 + 1;
              pbVar16 = pbVar16 + 1;
            }
            pbVar10 = (byte *)&DAT_001ce780;
            pbVar16 = DAT_001ce7f8 + 0x1c;
            for (uVar13 = DAT_001ce7f4 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined4 *)pbVar16 = *(undefined4 *)pbVar10;
              pbVar10 = pbVar10 + 4;
              pbVar16 = pbVar16 + 4;
            }
            for (iVar9 = 0; pbVar6 = DAT_001ce7f8, iVar9 != 0; iVar9 = iVar9 + -1) {
              *pbVar16 = *pbVar10;
              pbVar10 = pbVar10 + 1;
              pbVar16 = pbVar16 + 1;
            }
            *(undefined2 *)(DAT_001ce7f8 + 4) = (undefined2)DAT_001ce7f4;
            *pbVar6 = DAT_001ce805;
            *(short *)(pbVar6 + 6) = DAT_001ce800 + *(short *)(p1_00 + 0x24);
            *(short *)(pbVar6 + 8) = (short)local_24;
            iVar9 = f_16fc50(pbVar6);
            if (iVar9 != 0) {
              iVar9 = f_16ff84(p1_00);
              if (iVar9 == 0) break;
            }
          }
        }
LAB_00170708:
        local_20 = local_20 + 1;
        p1_00 = p1_00 + 0x30;
      } while ((int)local_20 < (int)(uint)uVar2);
    }
LAB_00170720:
    *(short *)(p1 + 0xc) = (short)DAT_001a9a00 - *(short *)(p1 + 10);
    p1[0x10] = p1[0x10] | 0x40;
    uVar7 = *(undefined2 *)(p1 + 0xc);
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}




/* ==== 1707F8-1708F4  (nach Attic)  fremd? ==== */


undefined4 f_1707f8(short *p1,ushort *p2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int local_1c;
  int local_18;
  
  sVar1 = *p1;
  sVar2 = p1[1];
  if (((((short)p2[1] <= sVar1) && (sVar1 <= (short)p2[2])) && ((short)p2[3] <= sVar2)) &&
     (sVar2 <= (short)p2[4])) {
    local_1c = -0x80000000;
    local_18 = 0x7fffffff;
    puVar4 = p2 + 5;
    iVar5 = *p2 + 1;
    while (iVar5 = iVar5 + -1, iVar5 != 0) {
      if (((((short)puVar4[1] <= sVar2) && (sVar2 <= (short)puVar4[3])) ||
          (((short)puVar4[3] <= sVar2 && (sVar2 <= (short)puVar4[1])))) && (puVar4[3] != puVar4[1]))
      {
        iVar3 = (int)(((longlong)(((int)sVar2 - (*(int *)puVar4 >> 0x10)) * 0x10000) *
                      (longlong)((*(int *)(puVar4 + 1) >> 0x10) - (int)(short)*puVar4)) /
                     (longlong)((*(int *)(puVar4 + 2) >> 0x10) - (*(int *)puVar4 >> 0x10))) +
                (short)*puVar4 * 0x10000;
        if (iVar3 < local_18) {
          local_18 = iVar3;
        }
        if (local_1c < iVar3) {
          local_1c = iVar3;
        }
      }
      puVar4 = puVar4 + 2;
    }
    if ((local_18 <= (int)sVar1 << 0x10) && ((int)sVar1 << 0x10 <= local_1c)) {
      return 1;
    }
  }
  return 0;
}




/* ==== 1708F4-170AF4  (nach Attic)  fremd? ==== */


undefined4 f_1708f4(int *p1,int *p2,ushort *p3,short *p4)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  ushort uVar17;
  int iVar18;
  ushort uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  
  sVar1 = (short)*p2;
  sVar6 = (short)*p1;
  sVar5 = sVar1;
  if (sVar6 < sVar1) {
    sVar5 = sVar6;
    sVar6 = sVar1;
  }
  sVar1 = *(short *)((int)p2 + 2);
  sVar2 = *(short *)((int)p1 + 2);
  sVar7 = sVar1;
  if (sVar2 < sVar1) {
    sVar7 = sVar2;
    sVar2 = sVar1;
  }
  if ((((sVar5 <= (short)p3[2]) && ((short)p3[1] <= sVar6)) && (sVar7 <= (short)p3[4])) &&
     ((short)p3[3] <= sVar2)) {
    iVar13 = (int)(short)*p1;
    iVar4 = *p1;
    iVar8 = iVar4 >> 0x10;
    iVar9 = (short)*p2 - iVar13;
    uVar22 = (uint)*p3;
    iVar10 = (*p2 >> 0x10) - iVar8;
    puVar11 = p3 + 5;
    if (uVar22 == 0) {
      return 0;
    }
    do {
      uVar3 = *puVar11;
      uVar19 = puVar11[2];
      uVar16 = uVar3;
      if ((short)uVar3 < (short)puVar11[2]) {
        uVar16 = puVar11[2];
        uVar19 = uVar3;
      }
      uVar3 = puVar11[3];
      uVar12 = uVar3;
      uVar17 = puVar11[1];
      if ((short)uVar3 <= (short)puVar11[1]) {
        uVar12 = puVar11[1];
        uVar17 = uVar3;
      }
      if (((sVar5 <= (short)uVar16) && ((short)uVar19 <= sVar6)) &&
         ((sVar7 <= (short)uVar12 && ((short)uVar17 <= sVar2)))) {
        iVar20 = (int)(short)*puVar11;
        iVar14 = (*(int *)(puVar11 + 1) >> 0x10) - iVar20;
        iVar18 = *(int *)puVar11 >> 0x10;
        iVar15 = (*(int *)(puVar11 + 2) >> 0x10) - iVar18;
        iVar21 = (iVar20 - iVar13) * iVar15 - (iVar18 - iVar8) * iVar14;
        iVar14 = iVar9 * iVar15 - iVar14 * iVar10;
        if (((iVar21 != 0 || iVar14 != 0) &&
            (((-1 < iVar21 && (iVar21 <= iVar14)) || ((iVar21 < 1 && (iVar14 <= iVar21)))))) &&
           (((iVar15 = (iVar20 - iVar13) * iVar10 - (iVar18 - iVar8) * iVar9, -1 < iVar15 &&
             (iVar15 <= iVar14)) || ((iVar15 < 1 && (iVar14 <= iVar15)))))) {
          *p4 = (short)*p1 + (short)(((longlong)iVar9 * (longlong)iVar21) / (longlong)iVar14);
          p4[1] = (short)((uint)iVar4 >> 0x10) +
                  (short)(((longlong)iVar10 * (longlong)iVar21) / (longlong)iVar14);
          return 1;
        }
      }
      puVar11 = puVar11 + 2;
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  return 0;
}




/* ==== 170AF4-170CB8  (nach Attic)  fremd? ==== */


undefined4 f_170af4(ushort *p1,ushort *p2)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  ushort *puVar8;
  ushort local_58 [26];
  #define sStack_50 (((short *)local_58)[4])
  #define local_4e (((short *)local_58)[5])
  #define sStack_4c (((short *)local_58)[6])
  #define local_4a (&((short *)local_58)[7])
  int local_24;
  int local_20;
  ushort *local_1c;
  short *psVar7;
  
  puVar8 = p1 + 5;
  local_58[0] = 0;
  *(undefined4 *)(puVar8 + (uint)*p1 * 2) = *(undefined4 *)puVar8;
  bVar2 = false;
  *(undefined4 *)(p2 + 5 + (uint)*p2 * 2) = *(undefined4 *)(p2 + 5);
  psVar6 = &local_4e;
  local_1c = p1;
  iVar4 = f_1707f8(puVar8,p2);
  if (iVar4 == 0) {
    local_4e = (short)*(undefined4 *)puVar8;
    sStack_4c = (short)((uint)*(undefined4 *)puVar8 >> 0x10);
    psVar6 = local_4a;
    local_58[0] = local_58[0] + 1;
  }
  local_20 = *local_1c + 1;
  while (local_20 = local_20 + -1, local_20 != 0) {
    local_24 = f_1707f8(puVar8 + 2,p2);
    if (local_24 != iVar4) {
      iVar4 = f_1708f4(puVar8,puVar8 + 2,p2,psVar6);
      uVar3 = local_58[0];
      if (iVar4 != 0) {
        psVar6 = psVar6 + 2;
        local_58[0] = local_58[0] + 1;
        if (7 < uVar3) {
          return 0;
        }
      }
      bVar2 = true;
      DAT_001a9936 = 1;
    }
    uVar3 = local_58[0];
    if (local_24 == 0) {
      *(undefined4 *)psVar6 = *(undefined4 *)(puVar8 + 2);
      psVar6 = psVar6 + 2;
      local_58[0] = local_58[0] + 1;
      if (7 < uVar3) {
        return 0;
      }
    }
    else {
      bVar2 = true;
      DAT_001a9936 = 1;
    }
    puVar8 = puVar8 + 2;
    iVar4 = local_24;
  }
  if (bVar2) {
    if (2 < local_58[0]) {
      local_58[1] = local_4e;
      local_58[2] = local_4e;
      uVar5 = (uint)local_58[0];
      local_58[3] = sStack_4c;
      sStack_50 = sStack_4c;
      psVar6 = &local_4e;
      while( true ) {
        psVar7 = psVar6 + 2;
        uVar5 = uVar5 - 1;
        if (uVar5 == 0) break;
        sVar1 = *psVar7;
        if (sVar1 < (short)local_58[1]) {
          local_58[1] = sVar1;
        }
        else if ((short)local_58[2] < sVar1) {
          local_58[2] = sVar1;
        }
        sVar1 = psVar6[3];
        psVar6 = psVar7;
        if (sVar1 < (short)local_58[3]) {
          local_58[3] = sVar1;
        }
        else if (sStack_50 < sVar1) {
          sStack_50 = sVar1;
        }
      }
      puVar8 = local_58;
      for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined4 *)local_1c = *(undefined4 *)puVar8;
        puVar8 = puVar8 + 2;
        local_1c = local_1c + 2;
      }
      *local_1c = *puVar8;
      return 0;
    }
    return 1;
  }
  #undef sStack_50
  #undef local_4e
  #undef sStack_4c
  #undef local_4a
  return 0;
}




/* ==== 170CB8-170E84  (nach Attic)  fremd? ==== */


int f_170cb8(int p1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = (uint)*(ushort *)(p1 + 0xc);
  piVar3 = (int *)((uint)*(ushort *)(p1 + 10) * 4 + DAT_001cd220);
  if (uVar2 == 0) {
    return 0;
  }
  do {
    iVar1 = *piVar3;
    piVar3 = piVar3 + 1;
    if (*(char *)(iVar1 + 1) != '\x03') {
      iVar4 = iVar4 + 1;
    }
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return iVar4;
}




/* ==== 170E84-171000  (nach Attic)  fremd? ==== */


uint f_170e84(int p1,uint p2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *local_2c;
  int local_28;
  uint local_20;
  uint local_18;
  
  iVar1 = *(int *)(DAT_001cd204 + 4 + p2 * 8);
  local_20 = (uint)*(ushort *)(iVar1 + 0xc);
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    local_2c = (int *)(DAT_001cd220 + (uint)*(ushort *)(iVar1 + 10) * 4);
    local_28 = local_20 + 1;
    while (local_28 = local_28 + -1, local_28 != 0) {
      local_18 = 0;
      iVar1 = *local_2c;
      local_2c = local_2c + 1;
      DAT_001a9936 = '\0';
      if (p2 != 0) {
        do {
          iVar4 = *(int *)(DAT_001cd204 + 4 + local_18 * 8);
          if (((((*(byte *)(iVar4 + 0x10) & 1) != 0) && (*(short *)(iVar4 + 0xc) != 0)) &&
              (iVar2 = f_171994(iVar1 + 0x56,iVar4 + 0x40), iVar2 != 0)) &&
             ((p1 == 0 || (*(int *)(iVar4 + 0x18) < *(int *)(iVar1 + 0x3c))))) {
            iVar2 = *(ushort *)(iVar4 + 0xc) + 1;
            piVar5 = (int *)(DAT_001cd220 + (uint)*(ushort *)(iVar4 + 10) * 4);
            do {
              iVar2 = iVar2 + -1;
              if (iVar2 == 0) goto LAB_00170f77;
              iVar4 = *piVar5;
              piVar5 = piVar5 + 1;
            } while (((*(char *)(iVar4 + 1) == '\x03') || ((*(byte *)(iVar4 + 2) & 1) == 0)) ||
                    ((iVar3 = f_171994(iVar1 + 0x56,iVar4 + 0x56), iVar3 == 0 ||
                     (iVar4 = f_170af4(iVar1 + 0x54,iVar4 + 0x54), iVar4 == 0))));
            *(undefined1 *)(iVar1 + 1) = 3;
            local_20 = local_20 - 1;
            local_18 = p2;
          }
LAB_00170f77:
          local_18 = local_18 + 1;
        } while (local_18 < p2);
      }
      if ((DAT_001a9936 != '\0') && (*(char *)(iVar1 + 1) != '\x03')) {
        *(undefined1 *)(iVar1 + 1) = 2;
      }
    }
  }
  return local_20;
}




/* ==== 171000-171180  (nach Attic)  fremd? ==== */


undefined4 f_171000(int p1,uint p2)

{
  int p1_00;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint local_20;
  int local_18;
  
  p1_00 = *(int *)(DAT_001cd204 + 4 + p2 * 8);
  if ((*(byte *)(p1_00 + 0x10) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    local_18 = DAT_001cd204;
    DAT_001a9936 = '\0';
    local_20 = 0;
    if (p2 != 0) {
      do {
        iVar3 = *(int *)(local_18 + 4);
        if (((*(byte *)(iVar3 + 0x10) & 1) != 0) && (*(short *)(iVar3 + 0xc) != 0)) {
          iVar2 = f_171994(p1_00 + 0x4a,iVar3 + 0x40);
          if ((iVar2 != 0) && ((p1 == 0 || (*(int *)(iVar3 + 0x18) < *(int *)(p1_00 + 0x14))))) {
            iVar2 = *(ushort *)(iVar3 + 0xc) + 1;
            piVar5 = (int *)(DAT_001cd220 + (uint)*(ushort *)(iVar3 + 10) * 4);
            while (iVar2 = iVar2 + -1, iVar2 != 0) {
              iVar3 = *piVar5;
              piVar5 = piVar5 + 1;
              if ((*(char *)(iVar3 + 1) != '\x03') && ((*(byte *)(iVar3 + 2) & 1) != 0)) {
                iVar4 = f_171994(p1_00 + 0x4a,iVar3 + 0x56);
                if (iVar4 != 0) {
                  iVar3 = f_170af4(p1_00 + 0x48,iVar3 + 0x54);
                  if (iVar3 != 0) {
                    *(byte *)(p1_00 + 0x10) = *(byte *)(p1_00 + 0x10) & 0xfe;
                    return 0;
                  }
                }
              }
            }
          }
        }
        local_20 = local_20 + 1;
        local_18 = local_18 + 8;
      } while (local_20 < p2);
    }
    if ((*(byte *)(p1_00 + 0x11) & 2) == 0) {
      f_152870(p1_00);
    }
    if (DAT_001a9936 != '\0') {
      iVar3 = f_170e84(p1,p2);
      if (iVar3 == 0) {
        *(byte *)(p1_00 + 0x10) = *(byte *)(p1_00 + 0x10) & 0xfe;
        return 0;
      }
    }
    iVar3 = f_170cb8(p1_00);
    if (iVar3 == 0) {
      *(byte *)(p1_00 + 0x10) = *(byte *)(p1_00 + 0x10) & 0xfe;
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}




/* ==== 171180-171994  (nach Attic)  fremd? ==== */


bool f_171180(int p1,int p2,int p3)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int *local_54;
  int *local_50;
  int local_44;
  int local_40;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  
  if ((*(short *)(p2 + 4) == 0) || (*(short *)(p3 + 4) == 0)) {
    bVar3 = false;
  }
  else {
    if (p2 != DAT_001cea4c) {
      puVar11 = (ushort *)(p2 + 10);
      iVar16 = 0;
      iVar9 = 0;
      iVar10 = *(ushort *)(p2 + 4) + 1;
      piVar15 = &DAT_001ce900;
      while (iVar10 = iVar10 + -1, iVar10 != 0) {
        piVar17 = (int *)((uint)*puVar11 * 8 + DAT_001cd224);
        *piVar15 = *piVar17;
        piVar15[1] = piVar17[1];
        puVar11 = puVar11 + 1;
        iVar16 = iVar16 + *piVar15;
        iVar9 = iVar9 + piVar15[1];
        piVar15 = piVar15 + 4;
      }
      iVar16 = iVar16 / (int)(uint)*(ushort *)(p2 + 4);
      iVar9 = iVar9 / (int)(uint)*(ushort *)(p2 + 4);
      iVar10 = DAT_001a9b08;
      if (*(int *)(p3 + 0x44) == *(int *)(p2 + 0x44)) {
        iVar10 = 0xffbe;
      }
      iVar18 = *(ushort *)(p2 + 4) + 1;
      piVar15 = &DAT_001ce900;
      while (iVar18 = iVar18 + -1, iVar18 != 0) {
        lVar2 = (longlong)iVar10 * (longlong)(*piVar15 - iVar16);
        *piVar15 = ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10) + iVar16;
        lVar2 = (longlong)iVar10 * (longlong)(piVar15[1] - iVar9);
        piVar15[1] = iVar9 + ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
        piVar15 = piVar15 + 4;
      }
      *piVar15 = DAT_001ce900;
      piVar15[1] = DAT_001ce904;
      piVar15[2] = DAT_001ce908;
      piVar15[3] = DAT_001ce90c;
      piVar15 = &DAT_001ce900;
      iVar16 = *(ushort *)(p2 + 4) + 1;
      while (iVar16 = iVar16 + -1, DAT_001cea4c = p2, iVar16 != 0) {
        if (piVar15[5] < piVar15[1]) {
          piVar15[2] = *piVar15 - piVar15[4];
          piVar15[3] = piVar15[1] - piVar15[5];
          *piVar15 = piVar15[4];
          piVar15[1] = piVar15[5];
        }
        else {
          piVar15[2] = piVar15[4] - *piVar15;
          piVar15[3] = piVar15[5] - piVar15[1];
        }
        piVar15 = piVar15 + 4;
      }
    }
    if (p3 != DAT_001cea48) {
      puVar11 = (ushort *)(p3 + 10);
      iVar16 = 0;
      iVar9 = 0;
      iVar10 = *(ushort *)(p3 + 4) + 1;
      piVar15 = &DAT_001ce9a0;
      while (iVar10 = iVar10 + -1, iVar10 != 0) {
        piVar17 = (int *)((uint)*puVar11 * 8 + DAT_001cd224);
        *piVar15 = *piVar17;
        piVar15[1] = piVar17[1];
        puVar11 = puVar11 + 1;
        iVar16 = iVar16 + *piVar15;
        iVar9 = iVar9 + piVar15[1];
        piVar15 = piVar15 + 4;
      }
      iVar16 = iVar16 / (int)(uint)*(ushort *)(p3 + 4);
      iVar9 = iVar9 / (int)(uint)*(ushort *)(p3 + 4);
      iVar10 = DAT_001a9b08;
      if (*(int *)(p3 + 0x44) == *(int *)(p2 + 0x44)) {
        iVar10 = 0xffbe;
      }
      iVar18 = *(ushort *)(p3 + 4) + 1;
      piVar15 = &DAT_001ce9a0;
      while (iVar18 = iVar18 + -1, iVar18 != 0) {
        lVar2 = (longlong)iVar10 * (longlong)(*piVar15 - iVar16);
        *piVar15 = ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10) + iVar16;
        lVar2 = (longlong)iVar10 * (longlong)(piVar15[1] - iVar9);
        piVar15[1] = iVar9 + ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
        piVar15 = piVar15 + 4;
      }
      *piVar15 = DAT_001ce9a0;
      piVar15[1] = DAT_001ce9a4;
      piVar15[2] = DAT_001ce9a8;
      piVar15[3] = DAT_001ce9ac;
      piVar15 = &DAT_001ce9a0;
      iVar16 = *(ushort *)(p3 + 4) + 1;
      while (iVar16 = iVar16 + -1, DAT_001cea48 = p3, iVar16 != 0) {
        if (piVar15[5] < piVar15[1]) {
          piVar15[2] = *piVar15 - piVar15[4];
          piVar15[3] = piVar15[1] - piVar15[5];
          *piVar15 = piVar15[4];
          piVar15[1] = piVar15[5];
        }
        else {
          piVar15[2] = piVar15[4] - *piVar15;
          piVar15[3] = piVar15[5] - piVar15[1];
        }
        piVar15 = piVar15 + 4;
      }
    }
    if ((((*(short *)(p3 + 0x4c) < *(short *)(p2 + 0x4c)) ||
         (*(short *)(p3 + 0x50) < *(short *)(p2 + 0x50))) ||
        (*(short *)(p2 + 0x4e) < *(short *)(p3 + 0x4e))) ||
       (*(short *)(p2 + 0x52) < *(short *)(p3 + 0x52))) {
      local_54 = &DAT_001ce9a0;
      local_50 = &DAT_001ce900;
      iVar16 = p3;
      p3 = p2;
    }
    else {
      local_54 = &DAT_001ce900;
      local_50 = &DAT_001ce9a0;
      iVar16 = p2;
    }
    iVar9 = *(int *)(iVar16 + 0x4a);
    iVar10 = *(int *)(iVar16 + 0x4e);
    iVar18 = *(int *)(iVar16 + 0x4c);
    iVar1 = *(int *)(iVar16 + 0x50);
    local_14 = local_50;
    local_40 = *(ushort *)(p3 + 4) + 1;
    DAT_001cea40 = &DAT_001ce810;
    while (local_40 = local_40 + -1, local_40 != 0) {
      if (local_14[2] < 0) {
        iVar14 = *local_14 + local_14[2];
      }
      else {
        iVar14 = *local_14;
      }
      if (local_14[2] < 1) {
        iVar4 = *local_14;
      }
      else {
        iVar4 = *local_14 + local_14[2];
      }
      if (((iVar14 <= (iVar18 >> 0x10) << 0x10) && ((iVar9 >> 0x10) << 0x10 <= iVar4)) &&
         ((local_14[1] <= (iVar1 >> 0x10) << 0x10 &&
          ((iVar10 >> 0x10) << 0x10 <= local_14[3] + local_14[1])))) {
        local_28 = -0x80000000;
        local_1c = 0x7fffffff;
        local_18 = *(ushort *)(iVar16 + 4) + 1;
        piVar15 = local_54;
        while (local_18 = local_18 + -1, local_18 != 0) {
          iVar5 = local_14[1] - piVar15[1];
          if ((-1 < iVar5) && (iVar5 < piVar15[3])) {
            iVar5 = (int)(((longlong)iVar5 * (longlong)piVar15[2]) / (longlong)piVar15[3]) +
                    *piVar15;
            if (iVar5 < local_1c) {
              local_1c = iVar5;
            }
            if (local_28 < iVar5) {
              local_28 = iVar5;
            }
            if ((local_1c <= *local_14) && (*local_14 <= local_28)) {
              if (p1 == 0) {
                return true;
              }
              if (DAT_001cea40 < &DAT_001ce900) {
                *DAT_001cea40 = *local_14;
                DAT_001cea40[1] = local_14[1];
                DAT_001cea40 = DAT_001cea40 + 2;
              }
            }
          }
          if ((piVar15[1] <= local_14[1] + local_14[3]) && (local_14[1] <= piVar15[1] + piVar15[3]))
          {
            if (piVar15[2] < 0) {
              iVar5 = *piVar15 + piVar15[2];
            }
            else {
              iVar5 = *piVar15;
            }
            if (piVar15[2] < 1) {
              iVar6 = *piVar15;
            }
            else {
              iVar6 = *piVar15 + piVar15[2];
            }
            if ((iVar5 <= iVar4) && (iVar14 <= iVar6)) {
              iVar5 = f_16d3b7(*piVar15 - *local_14,local_14[3],piVar15[1] - local_14[1],local_14[2]
                              );
              iVar6 = f_16d3b7(piVar15[3],local_14[2],piVar15[2],local_14[3]);
              if ((((-1 < iVar5) && (iVar5 < iVar6)) || ((iVar5 < 1 && (iVar6 < iVar5)))) &&
                 (((iVar7 = f_16d3b7(*piVar15 - *local_14,piVar15[3],piVar15[1] - local_14[1],
                                     piVar15[2]), -1 < iVar7 && (iVar7 < iVar6)) ||
                  ((iVar7 < 1 && (iVar6 < iVar7)))))) {
                if (p1 == 0) {
                  return true;
                }
                iVar12 = *local_14 +
                         (int)(((longlong)local_14[2] * (longlong)iVar7) / (longlong)iVar6);
                iVar7 = local_14[1] +
                        (int)(((longlong)local_14[3] * (longlong)iVar7) / (longlong)iVar6);
                uVar8 = iVar12 - (*piVar15 +
                                 (int)(((longlong)piVar15[2] * (longlong)iVar5) / (longlong)iVar6));
                uVar13 = (int)uVar8 >> 0x1f;
                if ((((int)((uVar8 ^ uVar13) - uVar13) < 0x1999) &&
                    (uVar8 = iVar7 - (piVar15[1] +
                                     (int)(((longlong)piVar15[3] * (longlong)iVar5) /
                                          (longlong)iVar6)), uVar13 = (int)uVar8 >> 0x1f,
                    (int)((uVar8 ^ uVar13) - uVar13) < 0x1999)) && (DAT_001cea40 < &DAT_001ce900)) {
                  *DAT_001cea40 = iVar12;
                  DAT_001cea40[1] = iVar7;
                  DAT_001cea40 = DAT_001cea40 + 2;
                }
              }
            }
          }
          piVar15 = piVar15 + 4;
        }
      }
      local_14 = local_14 + 4;
    }
    if (((int *)(&riva_dgroup_base[0x1ce82f - 0x1a0000])) < DAT_001cea40) {
      return true;
    }
    iVar9 = *(int *)(p3 + 0x4a);
    iVar10 = *(int *)(p3 + 0x4e);
    iVar18 = *(int *)(p3 + 0x4c);
    iVar1 = *(int *)(p3 + 0x50);
    local_44 = *(ushort *)(iVar16 + 4) + 1;
    while (local_44 = local_44 + -1, local_44 != 0) {
      if (local_54[2] < 0) {
        iVar16 = *local_54 + local_54[2];
      }
      else {
        iVar16 = *local_54;
      }
      if (local_54[2] < 1) {
        iVar14 = *local_54;
      }
      else {
        iVar14 = *local_54 + local_54[2];
      }
      if (((iVar16 <= (iVar18 >> 0x10) << 0x10) && ((iVar9 >> 0x10) << 0x10 <= iVar14)) &&
         ((local_54[1] <= (iVar1 >> 0x10) << 0x10 &&
          ((iVar10 >> 0x10) << 0x10 <= local_54[3] + local_54[1])))) {
        local_2c = -0x80000000;
        local_20 = 0x7fffffff;
        local_24 = *(ushort *)(p3 + 4) + 1;
        piVar15 = local_50;
        while (local_24 = local_24 + -1, local_24 != 0) {
          iVar16 = local_54[1] - piVar15[1];
          if ((-1 < iVar16) && (iVar16 < piVar15[3])) {
            iVar16 = (int)(((longlong)iVar16 * (longlong)piVar15[2]) / (longlong)piVar15[3]) +
                     *piVar15;
            if (iVar16 < local_20) {
              local_20 = iVar16;
            }
            if (local_2c < iVar16) {
              local_2c = iVar16;
            }
            if ((local_20 <= *local_54) && (*local_54 <= local_2c)) {
              if (DAT_001cea40 < &DAT_001ce900) {
                *DAT_001cea40 = *local_54;
                DAT_001cea40[1] = local_54[1];
                DAT_001cea40 = DAT_001cea40 + 2;
              }
              if ((p1 == 0) || (((int *)(&riva_dgroup_base[0x1ce82f - 0x1a0000])) < DAT_001cea40)) {
                return true;
              }
            }
          }
          piVar15 = piVar15 + 4;
        }
      }
      local_54 = local_54 + 4;
    }
    bVar3 = &DAT_001ce810 < DAT_001cea40;
  }
  return bVar3;
}




/* ==== 171994-1719E4  (nach Attic)  fremd? ==== */


undefined4 f_171994(short *p1,short *p2)

{
  if (p2[1] < *p1) {
    return 0;
  }
  if (p1[1] < *p2) {
    return 0;
  }
  if (p2[3] < p1[2]) {
    return 0;
  }
  if (p1[3] < p2[2]) {
    return 0;
  }
  return 1;
}




/* ==== 1719E4-171C20  (nach Attic)  fremd? ==== */


uint f_1719e4(int p1,int p2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int local_3c [3];
  int local_2c;
  int local_28;
  int local_24;
  ushort *local_20;
  int *local_18;
  
  local_18 = (int *)(DAT_001cd324 + (uint)*(ushort *)(p1 + 6) * 0xc);
  piVar5 = (int *)(DAT_001cd314 + (uint)*(ushort *)(p1 + 10) * 0xc);
  if (0 < (int)(((uint)((longlong)local_18[2] * (longlong)piVar5[2]) >> 0x10 |
                (int)((ulonglong)((longlong)local_18[2] * (longlong)piVar5[2]) >> 0x20) << 0x10) +
               ((uint)((longlong)*local_18 * (longlong)*piVar5) >> 0x10 |
               (int)((ulonglong)((longlong)*local_18 * (longlong)*piVar5) >> 0x20) << 0x10) +
               ((uint)((longlong)local_18[1] * (longlong)piVar5[1]) >> 0x10 |
               (int)((ulonglong)((longlong)local_18[1] * (longlong)piVar5[1]) >> 0x20) << 0x10))) {
    local_3c[0] = -local_18[0];
    local_3c[1] = -local_18[1];
    local_3c[2] = -local_18[2];
    local_18 = local_3c;
  }
  local_20 = (ushort *)(p2 + 10);
  uVar7 = 0;
  local_28 = 0;
  local_24 = *(ushort *)(p2 + 4) + 1;
  local_2c = 0;
  while (local_24 = local_24 + -1, local_24 != 0) {
    piVar6 = (int *)(DAT_001cd314 + (uint)*local_20 * 0xc);
    lVar1 = (longlong)*local_18 * (longlong)(*piVar6 - *piVar5);
    lVar2 = (longlong)local_18[1] * (longlong)(piVar6[1] - piVar5[1]);
    lVar3 = (longlong)local_18[2] * (longlong)(piVar6[2] - piVar5[2]);
    iVar4 = ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10) +
            ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
            ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10);
    if (iVar4 != 0) {
      if (iVar4 < 1) {
        if (iVar4 < local_2c) {
          local_2c = iVar4;
        }
        uVar7 = uVar7 | 2;
      }
      else {
        if (local_28 < iVar4) {
          local_28 = iVar4;
        }
        uVar7 = uVar7 | 1;
      }
    }
    local_20 = local_20 + 1;
  }
  if (uVar7 == 3) {
    if ((-DAT_001aea34 < local_2c) &&
       ((int)((uint)((longlong)local_2c * -0x640000) >> 0x10 |
             (int)((ulonglong)((longlong)local_2c * -0x640000) >> 0x20) << 0x10) < local_28)) {
      return 1;
    }
    if ((local_28 < DAT_001aea34) &&
       (local_2c <
        (int)((uint)((longlong)local_28 * -0x640000) >> 0x10 |
             (int)((ulonglong)((longlong)local_28 * -0x640000) >> 0x20) << 0x10))) {
      return 2;
    }
    if ((-DAT_001aea34 < local_2c) && (local_28 < DAT_001aea34)) {
      return 0;
    }
  }
  else if ((-0x2666 < local_2c) && (local_28 < 0x2666)) {
    return 0;
  }
  return uVar7;
}




/* ==== 171C20-171F14  (nach Attic)  fremd? ==== */


bool f_171c20(int p1,int p2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  bool bVar14;
  int local_1c;
  uint local_18;
  
  local_18 = 0;
  local_1c = 0;
  DAT_001cea51 = 0;
  piVar1 = (int *)(DAT_001cd324 + (uint)*(ushort *)(p1 + 6) * 0xc);
  piVar12 = (int *)((uint)*(ushort *)(p1 + 10) * 0xc + DAT_001cd314);
  piVar13 = (int *)(DAT_001cd324 + (uint)*(ushort *)(p2 + 6) * 0xc);
  piVar11 = (int *)(DAT_001cd314 + (uint)*(ushort *)(p2 + 10) * 0xc);
  iVar5 = ((uint)((longlong)piVar1[2] * (longlong)piVar12[2]) >> 0x10 |
          (int)((ulonglong)((longlong)piVar1[2] * (longlong)piVar12[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)*piVar1 * (longlong)*piVar12) >> 0x10 |
          (int)((ulonglong)((longlong)*piVar1 * (longlong)*piVar12) >> 0x20) << 0x10) +
          ((uint)((longlong)piVar1[1] * (longlong)piVar12[1]) >> 0x10 |
          (int)((ulonglong)((longlong)piVar1[1] * (longlong)piVar12[1]) >> 0x20) << 0x10);
  iVar6 = ((uint)((longlong)piVar13[2] * (longlong)piVar11[2]) >> 0x10 |
          (int)((ulonglong)((longlong)piVar13[2] * (longlong)piVar11[2]) >> 0x20) << 0x10) +
          ((uint)((longlong)*piVar13 * (longlong)*piVar11) >> 0x10 |
          (int)((ulonglong)((longlong)*piVar13 * (longlong)*piVar11) >> 0x20) << 0x10) +
          ((uint)((longlong)piVar13[1] * (longlong)piVar11[1]) >> 0x10 |
          (int)((ulonglong)((longlong)piVar13[1] * (longlong)piVar11[1]) >> 0x20) << 0x10);
  piVar12 = &DAT_001ce810;
  if (&DAT_001ce810 < DAT_001cea40) {
    do {
      iVar10 = -(int)(CONCAT44((*piVar12 << 5) >> 0x10,*piVar12 << 0x15) /
                     (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0);
      iVar9 = -(int)(CONCAT44((piVar12[1] << 5) >> 0x10,piVar12[1] << 0x15) /
                    (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4);
      lVar2 = (longlong)*piVar1 * (longlong)iVar10;
      lVar3 = (longlong)piVar1[1] * (longlong)iVar9;
      lVar4 = (longlong)piVar1[2] *
              (longlong)((int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 * -0x20);
      uVar7 = ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10) +
              ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10) +
              ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
      if ((iVar5 >> 0xf ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f) <
          (int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f))) {
        iVar8 = (int)(CONCAT44(iVar5 >> 0x10,iVar5 * 0x10000) / (longlong)(int)uVar7);
      }
      else {
        iVar8 = 0x7fffffff;
      }
      lVar2 = (longlong)*piVar13 * (longlong)iVar10;
      lVar3 = (longlong)piVar13[1] * (longlong)iVar9;
      lVar4 = (longlong)piVar13[2] *
              (longlong)((int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 * -0x20);
      uVar7 = ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10) +
              ((uint)lVar2 >> 0x10 | (int)((ulonglong)lVar2 >> 0x20) << 0x10) +
              ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
      if ((iVar6 >> 0xf ^ iVar6 >> 0x1f) - (iVar6 >> 0x1f) <
          (int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f))) {
        iVar9 = (int)(CONCAT44(iVar6 >> 0x10,iVar6 * 0x10000) / (longlong)(int)uVar7);
      }
      else {
        iVar9 = 0x7fffffff;
      }
      iVar8 = iVar8 - iVar9;
      local_1c = local_1c + iVar8;
      if (iVar8 < -0x147a) {
        local_18 = local_18 | 1;
      }
      else if (0x147a < iVar8) {
        local_18 = local_18 | 2;
      }
      piVar12 = piVar12 + 2;
    } while (piVar12 < DAT_001cea40);
  }
  if (local_18 == 3) {
    DAT_001cea51 = 1;
    bVar14 = local_1c < 0;
  }
  else {
    if (local_18 == 0) {
      return local_1c < 0;
    }
    bVar14 = local_18 == 1;
  }
  return bVar14;
}




/* ==== 171F14-172028  (nach Attic)  fremd? ==== */




int f_171f14(int p1,int p2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 p1_00;
  
  _DAT_001cea44 = 0;
  DAT_001a99ec = DAT_001a99ec + 1;
  iVar1 = f_171994(p1 + 0x4c,p2 + 0x4c);
  if (iVar1 != 0) {
    _DAT_001cea44 = 1;
    if (*(int *)(p1 + 0x3c) < *(int *)(p2 + 0x40)) {
      iVar2 = f_1719e4(p1,p2);
      if (iVar2 == 1) {
        return 0;
      }
      iVar3 = f_1719e4(p2,p1);
      if (iVar3 == 2) {
        return 0;
      }
      if ((iVar2 != 0) || (iVar1 = iVar3, iVar3 != 0)) {
        if ((iVar2 == 3) && (iVar3 == 3)) {
          p1_00 = 1;
        }
        else {
          p1_00 = 0;
        }
        iVar1 = f_171180(p1_00,p1,p2);
        if (iVar1 != 0) {
          DAT_001cea51 = '\0';
          DAT_001cea50 = 1;
          if (iVar2 == 2) {
            return 1;
          }
          if (iVar3 == 1) {
            return 1;
          }
          iVar1 = f_171c20(p1,p2);
          if (DAT_001cea51 != '\0') {
            *(undefined1 *)(p1 + 3) = 1;
            *(undefined2 *)(p1 + 0x86) = *(undefined2 *)(p2 + 8);
            *(undefined1 *)(p2 + 3) = 1;
            *(undefined2 *)(p2 + 0x86) = *(undefined2 *)(p1 + 8);
          }
        }
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}




/* ==== 172028-172148  (nach Attic)  fremd? ==== */


void f_172028(int p1,int p2)

{
  int p1_00;
  int p2_00;
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  
  iVar3 = f_16fc19();
  DAT_001a9a68 = DAT_001a9a68 - iVar3;
  local_24 = p1;
  if (p1 < p2) {
    do {
      iVar3 = p2 - local_24;
      do {
        p1_00 = *(int *)(DAT_001cd220 + local_24 * 4);
        if (((p1_00 == 0) || (*(char *)(p1_00 + 1) == '\x03')) ||
           ((*(byte *)(*(int *)(p1_00 + 0x44) + 0x10) & 1) == 0)) break;
        bVar1 = true;
        if (local_24 + 1 <= p2) {
          iVar5 = (local_24 + 1) * 4;
          do {
            p2_00 = *(int *)(iVar5 + DAT_001cd220);
            if (((p2_00 != 0) && (*(char *)(p2_00 + 1) != '\x03')) &&
               ((*(byte *)(*(int *)(p2_00 + 0x44) + 0x10) & 1) != 0)) {
              iVar4 = f_171f14(p1_00,p2_00);
              iVar2 = DAT_001cd220;
              if (iVar4 != 0) {
                iVar3 = iVar3 + -1;
                if (iVar3 < 0) {
                  DAT_001a9a08 = DAT_001a9a08 + 1;
                }
                else {
                  *(int *)(local_24 * 4 + DAT_001cd220) = p2_00;
                  *(int *)(iVar5 + iVar2) = p1_00;
                  bVar1 = false;
                }
                break;
              }
            }
            iVar5 = iVar5 + 4;
          } while (iVar5 <= p2 * 4);
        }
      } while (!bVar1);
      local_24 = local_24 + 1;
    } while (local_24 < p2);
  }
  iVar3 = f_16fc19();
  DAT_001a9a68 = DAT_001a9a68 + iVar3;
  return;
}




/* ==== 172148-172278  (nach Attic)  fremd? ==== */


undefined4 f_172148(int p1,int p2)

{
  int p1_00;
  int p2_00;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *local_20;
  
  (*((uint8_t *)((char *)&(DAT_001a9937) + 0))) = 0;
  DAT_001a9936 = 0;
  DAT_001cea50 = 0;
  if (((*(byte *)(p1 + 0x10) & 1) != 0) && ((*(byte *)(p2 + 0x10) & 1) != 0)) {
    DAT_001a99e8 = DAT_001a99e8 + 1;
    iVar4 = *(ushort *)(p1 + 0xc) + 1;
    piVar3 = (int *)(DAT_001cd220 + (uint)*(ushort *)(p2 + 10) * 4);
    local_20 = (int *)(DAT_001cd220 + (uint)*(ushort *)(p1 + 10) * 4);
    while (iVar4 = iVar4 + -1, iVar4 != 0) {
      piVar5 = local_20 + 1;
      p1_00 = *local_20;
      local_20 = piVar5;
      if (((p1_00 != 0) && (*(char *)(p1_00 + 1) != '\x03')) &&
         (iVar1 = f_171994(p1_00 + 0x4c,p2 + 0x40), iVar1 != 0)) {
        iVar1 = *(ushort *)(p2 + 0xc) + 1;
        piVar5 = piVar3;
        while (iVar1 = iVar1 + -1, iVar1 != 0) {
          p2_00 = *piVar5;
          piVar5 = piVar5 + 1;
          if (((p2_00 != 0) && (*(char *)(p2_00 + 1) != '\x03')) &&
             ((iVar2 = f_171f14(p1_00,p2_00), iVar2 != 0 && (DAT_001cea51 == '\0')))) {
            DAT_001cdc28 = *(undefined2 *)(p1_00 + 8);
            (*((uint8_t *)((char *)&(DAT_001a9937) + 0))) = 1;
            DAT_001cdc26 = *(undefined2 *)(p2_00 + 8);
            return 1;
          }
        }
      }
    }
  }
  (*((uint8_t *)((char *)&(DAT_001a9937) + 0))) = DAT_001cea50;
  return 0;
}




/* ==== 172278-17228C  (nach Attic)  fremd? ==== */


void f_172278(void)

{
  DAT_001cea48 = 0xffffffff;
  DAT_001cea4c = 0xffffffff;
  return;
}




/* ==== 17228C-1722B0  (nach Attic)  fremd? ==== */


void f_17228c(void)

{
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined1 *local_c;
  
  
  return;
}




/* ==== 1722B0-172378  (nach Attic)  fremd? ==== */


uint f_1722b0(undefined4 p1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (uint)*(byte *)(DAT_001cea60 + (uint)(byte)p1 * 0x30 + 1);
  uVar4 = 0;
  iVar3 = 0;
  if (uVar1 != 0) {
    do {
      {
        uint16_t f_idx = *(uint16_t *)(DAT_001cea60 + (uint8_t)p1 * 0x30 + 2 + iVar3 * 2);
        uint16_t v_idx = *(uint16_t *)(*(int32_t *)(&riva_dgroup_base[0x1d1198 - 0x1a0000]) + (uint32_t)f_idx * 12);
        int32_t *v_ptr = (int32_t *)(*(int32_t *)(&DAT_001d07c4) + (uint32_t)v_idx * 12);
        int32_t delta[3] = { v_ptr[0] - DAT_001d118c, v_ptr[1] - DAT_001d1190, v_ptr[2] - DAT_001d1194 };
        iVar2 = f_16d361(delta, (int32_t *)(&DAT_001d07b0));
      }
      if (iVar2 < 0x290) {
        if (iVar2 < -0x28f) {
          uVar4 = uVar4 | 2;
        }
      }
      else {
        uVar4 = uVar4 | 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar1);
  }
  return uVar4;
}




/* ==== 172378-1724D8  (nach Attic)  fremd? ==== */


undefined1 f_172378(int p1,int p2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 local_24;
  int local_20;
  int local_1c;
  
  local_1c = 5000;
  local_20 = -1;
  iVar4 = p1;
  if (p1 < p2) {
    do {
      iVar2 = (uint)(byte)(&DAT_001d07c8)[iVar4] * 0x30 + DAT_001cea60;
      puVar6 = (undefined4 *)
               (DAT_001d07c4 +
               (uint)*(ushort *)((uint)*(ushort *)(iVar2 + 2) * 0xc + DAT_001d1198) * 0xc);
      DAT_001d118c = *puVar6;
      DAT_001d1190 = puVar6[1];
      DAT_001d1194 = puVar6[2];
      puVar6 = (undefined4 *)(DAT_001d07c0 + (uint)*(ushort *)(iVar2 + 0x24) * 0xc);
      DAT_001d07b0 = *puVar6;
      DAT_001d07b4 = puVar6[1];
      DAT_001d07b8 = puVar6[2];
      uVar5 = 0;
      bVar1 = true;
      iVar2 = p1;
      if (p1 < p2) {
        do {
          if (iVar2 != iVar4) {
            iVar3 = f_1722b0((uint)(byte)(&DAT_001d07c8)[iVar2]);
            if (iVar3 == 3) {
              bVar1 = false;
              break;
            }
            if (iVar3 != 1) {
              iVar3 = -1;
            }
            uVar5 = uVar5 + iVar3;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < p2);
      }
      if ((bVar1) && (iVar2 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f), iVar2 < local_1c)
         ) {
        uStack_3c = DAT_001d118c;
        uStack_38 = DAT_001d1190;
        uStack_34 = DAT_001d1194;
        local_24 = (&DAT_001d07c8)[iVar4];
        local_30 = DAT_001d07b0;
        uStack_2c = DAT_001d07b4;
        uStack_28 = DAT_001d07b8;
        local_20 = iVar4;
        local_1c = iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < p2);
  }
  if (local_20 == -1) {
    local_24 = 0;
    DAT_001aea38 = 2;
  }
  else {
    if (local_20 < p2 + -1) {
      f_14d075
                (&DAT_001d07c8 + local_20,&DAT_001d07c9 + local_20,(p2 - local_20) + -1);
    }
    DAT_001d118c = uStack_3c;
    DAT_001d1190 = uStack_38;
    DAT_001d1194 = uStack_34;
    DAT_001d07b0 = local_30;
    DAT_001d07b4 = uStack_2c;
    DAT_001d07b8 = uStack_28;
  }
  return local_24;
}




/* ==== 1724D8-172628  (nach Attic)  fremd? ==== */


int f_1724d8(int p1,int p2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int p2_00;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int local_20;
  
  iVar9 = DAT_001d07bc;
  iVar3 = DAT_001aea3c;
  if ((DAT_001aea38 == 0) && (p1 < p2)) {
    if (DAT_001aea40 <= DAT_001aea3c) {
      DAT_001aea38 = 1;
      return 0xff;
    }
    if (p2 - p1 == 1) {
      iVar10 = DAT_001aea3c * 3;
      DAT_001aea3c = DAT_001aea3c + 1;
      uVar2 = (&DAT_001d07c8)[p1];
      *(undefined1 *)(DAT_001d07bc + 1 + iVar10) = 0xff;
      *(undefined1 *)(iVar9 + 2 + iVar10) = 0xff;
      *(undefined1 *)(iVar9 + iVar10) = uVar2;
    }
    else {
      uVar2 = f_172378(p1,p2);
      if (DAT_001aea38 != 0) {
        return 0xff;
      }
      p2_00 = p2 + -1;
      pbVar5 = &DAT_001d07c8 + p1;
      iVar3 = p2_00;
      pbVar6 = (byte *)((int)&DAT_001d07c4 + p2 + 2);
      iVar9 = p1;
      iVar10 = p1;
      local_20 = p2_00;
      if (p1 < p2_00) {
        do {
          iVar4 = f_1722b0((uint)*pbVar5);
          if (iVar4 == 1) {
            pbVar5 = pbVar5 + 1;
            iVar10 = iVar10 + 1;
            iVar9 = iVar9 + 1;
            pbVar7 = pbVar6;
          }
          else {
            bVar1 = *pbVar6;
            pbVar7 = pbVar6 + -1;
            iVar3 = iVar3 + -1;
            local_20 = local_20 + -1;
            *pbVar6 = *pbVar5;
            *pbVar5 = bVar1;
          }
          pbVar6 = pbVar7;
        } while (iVar9 < iVar3);
      }
      iVar3 = DAT_001aea3c;
      iVar9 = DAT_001aea3c * 3;
      DAT_001aea3c = DAT_001aea3c + 1;
      puVar8 = (undefined1 *)(DAT_001d07bc + iVar9);
      *puVar8 = uVar2;
      uVar2 = f_1724d8(p1,iVar10);
      puVar8[1] = uVar2;
      uVar2 = f_1724d8(local_20,p2_00);
      puVar8[2] = uVar2;
    }
  }
  else {
    iVar3 = 0xff;
  }
  return iVar3;
}




/* ==== 172628-17272C  (nach Attic)  fremd? ==== */


int f_172628(int p1)

{
  ushort uVar1;
  int iVar2;
  uint p2;
  
  if (p1 != 0) {
    if (*(short *)(p1 + 8) == 0) {
      iVar2 = *(int *)(p1 + 0x28);
      DAT_001aea40 = 0x9c4 - DAT_001a99f8;
      uVar1 = *(ushort *)(iVar2 + 10);
      p2 = (uint)uVar1;
      if ((uVar1 < 2) || (0xff < uVar1)) {
        *(byte *)(p1 + 0xb) = *(byte *)(p1 + 0xb) | 0x10;
        return 0;
      }
      if (DAT_001aea40 < (int)p2) {
        return 0;
      }
      DAT_001aea3c = 0;
      DAT_001aea38 = 0;
      DAT_001d07bc = &DAT_001cea64 + DAT_001a99f8 * 3;
      DAT_001cea60 = *(undefined4 *)(iVar2 + 0x44);
      DAT_001d1198 = *(undefined4 *)(iVar2 + 0x40);
      DAT_001d07c4 = *(undefined4 *)(iVar2 + 0x38);
      DAT_001d07c0 = *(undefined4 *)(iVar2 + 0x3c);
      iVar2 = 0;
      if (p2 != 0) {
        do {
          (&DAT_001d07c8)[iVar2] = (char)iVar2;
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)p2);
      }
      f_1724d8(0,p2);
      if (DAT_001aea38 != 0) {
        if (DAT_001aea38 != 1) {
          *(byte *)(p1 + 0xb) = *(byte *)(p1 + 0xb) | 0x10;
        }
        return 0;
      }
      *(short *)(p1 + 8) = (short)DAT_001a99f8 + 1;
      DAT_001a99f8 = DAT_001a99f8 + DAT_001aea3c;
      p1 = 1;
    }
    else {
      p1 = 1;
    }
  }
  return p1;
}




/* ==== 17272C-172870  (nach Attic)  fremd? ==== */


void f_17272c(undefined4 p1)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)(DAT_001d07bc + (uint)(byte)p1 * 3);
  if ((puVar3[1] == 0xff) && (puVar3[2] == 0xff)) {
    *DAT_001d119c = *puVar3;
    DAT_001d119c = DAT_001d119c + 1;
  }
  else {
    {
      uint8_t *poly = (uint8_t *)(DAT_001cea60 + (uint32_t)puVar3[0] * 0x30);
      uint16_t f_idx = *(uint16_t *)(poly + 2);
      uint16_t v_idx = *(uint16_t *)(*(int32_t *)(&riva_dgroup_base[0x1d1198 - 0x1a0000]) + (uint32_t)f_idx * 12);
      uint16_t n_idx = *(uint16_t *)(poly + 0x24);
      int32_t *v_ptr = (int32_t *)(*(int32_t *)(&DAT_001d07c4) + (uint32_t)v_idx * 12);
      int32_t *n_ptr = (int32_t *)(*(int32_t *)(&riva_dgroup_base[0x1d07c0 - 0x1a0000]) + (uint32_t)n_idx * 12);
      int32_t delta[3] = { DAT_001cd308 - v_ptr[0], DAT_001cd30c - v_ptr[1], DAT_001cd310 - v_ptr[2] };
      iVar2 = f_16d361(delta, n_ptr);
    }
    if (iVar2 < 0x42) {
      if (puVar3[1] != 0xff) {
        f_17272c((uint)(byte)puVar3[1]);
      }
      *DAT_001d119c = *puVar3;
      DAT_001d119c = DAT_001d119c + 1;
      bVar1 = puVar3[2];
      if (bVar1 == 0xff) {
        return;
      }
    }
    else {
      if (puVar3[2] != 0xff) {
        f_17272c((uint)(byte)puVar3[2]);
      }
      *DAT_001d119c = *puVar3;
      if (puVar3[1] == 0xff) {
        DAT_001d119c = DAT_001d119c + 1;
        return;
      }
      bVar1 = puVar3[1];
      DAT_001d119c = DAT_001d119c + 1;
    }
    f_17272c((uint)bVar1);
  }
  return;
}




/* ==== 172870-1728F0  (nach Attic)  fremd? ==== */


undefined1 * f_172870(int p1)

{
  int iVar1;
  
  if ((p1 != 0) && (iVar1 = *(int *)(p1 + 0x7c), iVar1 != 0)) {
    if (*(short *)(iVar1 + 8) == 0) {
      return (undefined1 *)0x0;
    }
    DAT_001d119c = &DAT_001d07c8;
    DAT_001d07bc = &DAT_001cea64 + (*(ushort *)(iVar1 + 8) - 1) * 3;
    iVar1 = *(int *)(p1 + 0x80);
    DAT_001cea60 = *(undefined4 *)(iVar1 + 0x44);
    DAT_001d1198 = *(undefined4 *)(iVar1 + 0x40);
    DAT_001d07c4 = *(undefined4 *)(iVar1 + 0x38);
    DAT_001d07c0 = *(undefined4 *)(iVar1 + 0x3c);
    f_17272c(0);
    return &DAT_001d07c8;
  }
  return (undefined1 *)0x0;
}




/* ==== 1728F0-172BDC  (nach Attic)  fremd? ==== */


void f_1728f0(void)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int local_44;
  int local_40;
  int local_3c_arr[3];
  #define local_3c (local_3c_arr[0])
  #define local_38 (local_3c_arr[1])
  #define local_34 (local_3c_arr[2])
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar6 = DAT_001d11c8;
  piVar3 = DAT_001d11b0;
  local_44 = *(int *)(DAT_001d11c8 + 0x1c);
  local_38 = *(int *)(DAT_001d11c8 + 0x20);
  local_1c = *(int *)(DAT_001d11c8 + 0x18);
  local_30 = *(int *)(DAT_001d11cc + 0x18);
  iVar2 = *(int *)(DAT_001d11c8 + 8);
  iVar7 = *(int *)(DAT_001d11c8 + 0xc);
  local_34 = *(int *)(DAT_001d11cc + 8);
  iVar10 = *(int *)(DAT_001d11c8 + 4);
  local_3c = *(int *)(DAT_001d11cc + 0xc);
  local_40 = (*(int *)(DAT_001d11cc + 0x24) >> 0x10) - (*(int *)(DAT_001d11c8 + 0x24) >> 0x10);
  uVar9 = *(int *)(DAT_001d11cc + 0x20) - local_38;
  iVar8 = *(int *)(DAT_001d11cc + 0x1c) - local_44;
  uVar4 = (int)uVar9 >> 0x1f;
  if ((iVar8 >> 0xf ^ iVar8 >> 0x1f) - (iVar8 >> 0x1f) < (int)((uVar9 ^ uVar4) - uVar4)) {
    iVar8 = (int)(CONCAT44(iVar8 >> 0x10,iVar8 * 0x10000) / (longlong)(int)uVar9);
  }
  else {
    iVar8 = iVar8 * 0x10000;
  }
  if (0x3333 < (int)((uVar9 ^ uVar4) - uVar4)) {
    iVar5 = *(int *)(DAT_001d11cc + 4) - iVar10;
    local_20 = (int)(CONCAT44(iVar5 >> 0x10,iVar5 * 0x10000) / (longlong)(int)uVar9);
    local_24 = (int)(CONCAT44(local_30 - local_1c >> 0x10,(local_30 - local_1c) * 0x10000) /
                    (longlong)(int)uVar9);
    local_2c = (int)(CONCAT44(local_34 - iVar2 >> 0x10,(local_34 - iVar2) * 0x10000) /
                    (longlong)(int)uVar9);
    local_28 = (int)(CONCAT44(local_3c - iVar7 >> 0x10,(local_3c - iVar7) * 0x10000) /
                    (longlong)(int)uVar9);
  }
  iVar5 = (*(int *)(DAT_001d11c8 + 0x24) >> 0x10) * 0x10000 - local_38;
  if (iVar5 < 1) {
    *(short *)(DAT_001d11b0 + 2) = (short)((uint)iVar10 >> 8);
    uVar1 = *(undefined2 *)(iVar6 + 0x24);
    piVar3[3] = 0;
    *(undefined2 *)((int)piVar3 + 10) = uVar1;
    piVar3[4] = local_1c;
    *piVar3 = iVar2;
    piVar3[1] = iVar7;
  }
  local_44 = local_44 +
             ((uint)((longlong)iVar5 * (longlong)iVar8) >> 0x10 |
             (int)((ulonglong)((longlong)iVar5 * (longlong)iVar8) >> 0x20) << 0x10);
  iVar6 = local_1c +
          ((uint)((longlong)iVar5 * (longlong)local_24) >> 0x10 |
          (int)((ulonglong)((longlong)iVar5 * (longlong)local_24) >> 0x20) << 0x10);
  iVar2 = iVar2 + ((uint)((longlong)iVar5 * (longlong)local_2c) >> 0x10 |
                  (int)((ulonglong)((longlong)iVar5 * (longlong)local_2c) >> 0x20) << 0x10);
  iVar7 = iVar7 + ((uint)((longlong)iVar5 * (longlong)local_28) >> 0x10 |
                  (int)((ulonglong)((longlong)iVar5 * (longlong)local_28) >> 0x20) << 0x10);
  iVar10 = iVar10 + ((uint)((longlong)iVar5 * (longlong)local_20) >> 0x10 |
                    (int)((ulonglong)((longlong)iVar5 * (longlong)local_20) >> 0x20) << 0x10);
  if (0 < iVar5) {
    *(short *)(piVar3 + 2) = (short)((uint)iVar10 >> 8);
    piVar3[3] = 0;
    *(short *)((int)piVar3 + 10) = (short)((uint)(local_44 + 0x8000) >> 0x10);
    piVar3[4] = iVar6;
    *piVar3 = iVar2;
    piVar3[1] = iVar7;
  }
  {
    int *out_p = piVar3 + 5;
    int cnt = local_40;
    while (cnt > 1) {
      local_44 += iVar8;
      iVar6 += local_24;
      iVar2 += local_2c;
      iVar7 += local_28;
      iVar10 += local_20;
      *(short *)(out_p + 2) = (short)((uint)iVar10 >> 8);
      out_p[3] = 0;
      *(short *)((int)out_p + 10) = (short)((uint)(local_44 + 0x8000) >> 16);
      out_p[4] = iVar6;
      out_p[0] = iVar2;
      out_p[1] = iVar7;
      out_p += 5;
      cnt--;
    }
    DAT_001d11b0 = out_p;
  }
  iVar5 = DAT_001d11cc;
  if (*(int *)(DAT_001d11cc + 0x20) + (*(int *)(DAT_001d11cc + 0x24) >> 0x10) * -0x10000 < 0) {
    *(short *)(DAT_001d11b0 + 2) = (short)((uint)*(undefined4 *)(DAT_001d11cc + 4) >> 8);
    uVar1 = *(undefined2 *)(iVar5 + 0x24);
    DAT_001d11b0[3] = 0;
    *(undefined2 *)((int)DAT_001d11b0 + 10) = uVar1;
    DAT_001d11b0[4] = local_30;
    *DAT_001d11b0 = local_34;
  }
  else {
    local_3c = iVar7 + local_28;
    *(short *)(DAT_001d11b0 + 2) = (short)((uint)(iVar10 + local_20) >> 8);
    DAT_001d11b0[3] = 0;
    *(short *)((int)DAT_001d11b0 + 10) = (short)((uint)(local_44 + iVar8 + 0x8000) >> 0x10);
    DAT_001d11b0[4] = iVar6 + local_24;
    *DAT_001d11b0 = iVar2 + local_2c;
  }
  DAT_001d11b0[1] = local_3c;
  return;
}




/* ==== 172BDC-173290  (nach Attic)  fremd? ==== */


void f_172bdc(int p1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int p2;
  int p4;
  int local_a0_arr[3];
  #define local_a0 (local_a0_arr[0])
  #define local_9c (local_a0_arr[1])
  #define local_98 (local_a0_arr[2])
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined *local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c_arr[3];
  #define local_3c (local_3c_arr[0])
  #define local_38 (local_3c_arr[1])
  #define local_34 (local_3c_arr[2])
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  piVar3 = DAT_001d11b0;
  local_90 = *(int *)(DAT_001d11c8 + 0x1c);
  local_64 = *(int *)(DAT_001d11c8 + 0x20);
  local_78 = *(int *)(DAT_001d11c8 + 4);
  local_94 = *(int *)(DAT_001d11c8 + 0x10);
  local_4c = *(int *)(DAT_001d11c8 + 0x14);
  local_50 = *(int *)(DAT_001d11c8 + 0x18);
  if (DAT_001d122e == '\0') {
    local_68 = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4;
    iVar2 = *(int *)(DAT_001d11cc + 0x14);
    iVar6 = *(int *)(DAT_001d11cc + 0x10);
    iVar4 = local_4c;
    local_28 = local_94;
  }
  else {
    local_68 = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0;
    iVar2 = *(int *)(DAT_001d11cc + 0x10);
    iVar6 = *(int *)(DAT_001d11cc + 0x14);
    iVar4 = local_94;
    local_28 = local_4c;
  }
  local_74 = (*(int *)(DAT_001d11cc + 0x24) >> 0x10) - (*(int *)(DAT_001d11c8 + 0x24) >> 0x10);
  uVar5 = *(int *)(DAT_001d11cc + 0x20) - local_64;
  local_6c = *(int *)(DAT_001d11cc + 0x1c) - local_90;
  local_80 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
  if ((local_6c >> 0xf ^ local_6c >> 0x1f) - (local_6c >> 0x1f) < local_80) {
    local_2c = (int)(CONCAT44(local_6c >> 0x10,local_6c * 0x10000) / (longlong)(int)uVar5);
  }
  else {
    local_2c = local_6c * 0x10000;
  }
  local_84 = DAT_001d11c8;
  local_38 = *(int *)(DAT_001d11c8 + 8);
  local_30 = *(int *)(DAT_001d11c8 + 0xc);
  local_3c = *(int *)(DAT_001d11cc + 8) - local_38;
  local_34 = *(int *)(DAT_001d11cc + 0xc) - local_30;
  p2 = local_50 >> 4;
  local_70 = *(int *)(DAT_001d11cc + 4) - *(int *)(DAT_001d11c8 + 4);
  local_24 = iVar6 - local_28 >> 4;
  local_60 = iVar2 - iVar4 >> 4;
  local_28 = local_28 >> 4;
  p4 = *(int *)(DAT_001d11cc + 0x18) - local_50 >> 4;
  local_7c = p1;
  local_88 = f_16d34f(local_64,p2,local_68,iVar4 >> 4);
  iVar2 = f_16d34f(local_68,local_60,local_64,p4);
  iVar6 = (*(int *)(local_84 + 0x24) >> 0x10) * 0x10000 - local_64;
  local_90 = local_90 +
             ((uint)((longlong)iVar6 * (longlong)local_2c) >> 0x10 |
             (int)((ulonglong)((longlong)iVar6 * (longlong)local_2c) >> 0x20) << 0x10);
  local_88 = local_88 +
             ((uint)((longlong)iVar6 * (longlong)p2) >> 0x10 |
             (int)((ulonglong)((longlong)iVar6 * (longlong)p2) >> 0x20) << 0x10);
  local_8c = iVar2 - ((uint)((longlong)iVar6 * (longlong)p4) >> 0x10 |
                     (int)((ulonglong)((longlong)iVar6 * (longlong)p4) >> 0x20) << 0x10);
  *(short *)(piVar3 + 2) = (short)((uint)*(undefined4 *)(local_84 + 4) >> 8);
  *(undefined2 *)((int)piVar3 + 10) = *(undefined2 *)(local_84 + 0x24);
  piVar3[3] = local_28;
  piVar3[4] = p2;
  *piVar3 = *(int *)(local_84 + 8);
  piVar3[1] = *(int *)(local_84 + 0xc);
  if (0 < iVar6) {
    if (local_88 < 0 != (int)local_8c < 0) {
      local_88 = 0;
    }
    if ((local_88 >> 0xf ^ local_88 >> 0x1f) - (local_88 >> 0x1f) <
        (int)((local_8c ^ (int)local_8c >> 0x1f) - ((int)local_8c >> 0x1f))) {
      local_20 = (int)(CONCAT44(local_88 >> 0x10,local_88 << 0x10) / (longlong)(int)local_8c);
    }
    else {
      local_20 = 0;
    }
    *(short *)((int)piVar3 + 10) = (short)((uint)(local_90 + 0x8000) >> 0x10);
    piVar3[3] = piVar3[3] +
                ((uint)((longlong)local_20 * (longlong)local_24) >> 0x10 |
                (int)((ulonglong)((longlong)local_20 * (longlong)local_24) >> 0x20) << 0x10);
    piVar3[4] = piVar3[4] +
                ((uint)((longlong)local_20 * (longlong)p4) >> 0x10 |
                (int)((ulonglong)((longlong)local_20 * (longlong)p4) >> 0x20) << 0x10);
    *piVar3 = *piVar3 + ((uint)((longlong)local_20 * (longlong)local_3c) >> 0x10 |
                        (int)((ulonglong)((longlong)local_20 * (longlong)local_3c) >> 0x20) << 0x10)
    ;
    piVar3[1] = piVar3[1] +
                ((uint)((longlong)local_20 * (longlong)local_34) >> 0x10 |
                (int)((ulonglong)((longlong)local_20 * (longlong)local_34) >> 0x20) << 0x10);
  }
  piVar3 = piVar3 + 5;
  if (local_7c == 0) {
    {
    for (int cnt = local_74 - 1; cnt > 0; cnt--) {
      local_88 += p2;
      local_90 += local_2c;
      local_8c -= p4;
      local_20 = (local_8c != 0) ? (int)(CONCAT44(local_88 >> 16, local_88 * 0x10000) / (longlong)(int)local_8c) : 0x10000;
      if (local_20 < 0) local_20 = 0;
      if (local_20 > 0x10000) local_20 = 0x10000;
      *(short *)(piVar3 + 2) = (short)((local_78 + (int)(((longlong)local_20 * (longlong)local_70) >> 16)) >> 8);
      *(short *)((char *)piVar3 + 10) = (short)((uint)(local_90 + 0x8000) >> 16);
      piVar3[3] = local_28 + (int)(((longlong)local_20 * (longlong)local_24) >> 16);
      piVar3[4] = p2 + (int)(((longlong)local_20 * (longlong)p4) >> 16);
      piVar3[0] = local_38 + (int)(((longlong)local_20 * (longlong)local_3c) >> 16);
      piVar3[1] = local_30 + (int)(((longlong)local_20 * (longlong)local_34) >> 16);
      piVar3 += 5;
    }
  }
  }
  else {
    local_5c = *(int *)(DAT_001d11cc + 0x10) - local_94;
    local_58 = *(int *)(DAT_001d11cc + 0x14) - local_4c;
    local_54 = *(int *)(DAT_001d11cc + 0x18) - local_50;
    local_48 = *(uint *)(DAT_001d11c8 + 4);
    for (local_40 = local_74 + -1; 0 < local_40; local_40 = local_40 - DAT_001aea4c) {
      local_44 = local_40;
      if (DAT_001aea4c < local_40) {
        local_44 = DAT_001aea4c;
      }
      iVar2 = local_44 + 1;
      while (iVar2 = iVar2 + -1, iVar2 != 0) {
        local_88 = local_88 + p2;
        local_90 = local_90 + local_2c;
        local_8c = local_8c - p4;
        local_20 = (local_8c != 0) ? (int)(CONCAT44(local_88 >> 0x10,local_88 * 0x10000) / (longlong)(int)local_8c) : 0x10000;
        if (local_20 < 0) local_20 = 0;
        if (local_20 > 0x10000) local_20 = 0x10000;
        *(short *)((int)piVar3 + 10) = (short)((uint)(local_90 + 0x8000) >> 0x10);
        piVar3[3] = local_28 +
                    ((uint)((longlong)local_20 * (longlong)local_24) >> 0x10 |
                    (int)((ulonglong)((longlong)local_20 * (longlong)local_24) >> 0x20) << 0x10);
        piVar3[4] = ((uint)((longlong)local_20 * (longlong)p4) >> 0x10 |
                    (int)((ulonglong)((longlong)local_20 * (longlong)p4) >> 0x20) << 0x10) + p2;
        *piVar3 = local_38 +
                  ((uint)((longlong)local_20 * (longlong)local_3c) >> 0x10 |
                  (int)((ulonglong)((longlong)local_20 * (longlong)local_3c) >> 0x20) << 0x10);
        piVar3[1] = local_30 +
                    ((uint)((longlong)local_20 * (longlong)local_34) >> 0x10 |
                    (int)((ulonglong)((longlong)local_20 * (longlong)local_34) >> 0x20) << 0x10);
        piVar3 = piVar3 + 5;
      }
      local_a0 = local_94 +
                 ((uint)((longlong)local_20 * (longlong)local_5c) >> 0x10 |
                 (int)((ulonglong)((longlong)local_20 * (longlong)local_5c) >> 0x20) << 0x10);
      local_9c = local_4c +
                 ((uint)((longlong)local_20 * (longlong)local_58) >> 0x10 |
                 (int)((ulonglong)((longlong)local_20 * (longlong)local_58) >> 0x20) << 0x10);
      local_98 = local_50 +
                 ((uint)((longlong)local_20 * (longlong)local_54) >> 0x10 |
                 (int)((ulonglong)((longlong)local_20 * (longlong)local_54) >> 0x20) << 0x10);
      if (DAT_001a994c == '\0') {
        uVar5 = f_1735c4(1,&local_a0);
      }
      else {
        uVar5 = (uint)((longlong)DAT_001d11f4 * (longlong)local_98) >> 0x10 |
                (int)((ulonglong)((longlong)DAT_001d11f4 * (longlong)local_98) >> 0x20) << 0x10;
      }
      if (local_44 == DAT_001aea4c) {
        local_1c = (int)(local_48 - uVar5) >> (DAT_001aea48 & 0x1f);
      }
      else {
        local_1c = (int)(local_48 - uVar5) / local_44;
      }
      local_44 = local_44 + 1;
      uVar7 = uVar5;
      piVar1 = piVar3;
      while( true ) {
        local_44 = local_44 + -1;
        if (local_44 == 0) break;
        local_80 = (int)uVar7 >> 8;
        *(short *)(piVar1 + -3) = (short)(uVar7 >> 8);
        uVar7 = uVar7 + local_1c;
        piVar1 = piVar1 + -5;
      }
      local_48 = uVar5;
    }
  }
  iVar2 = DAT_001d11cc;
  if (*(int *)(DAT_001d11cc + 0x20) + (*(int *)(DAT_001d11cc + 0x24) >> 0x10) * -0x10000 < 0) {
    *(short *)(piVar3 + 2) = (short)((uint)*(undefined4 *)(DAT_001d11cc + 4) >> 8);
    *(undefined2 *)((int)piVar3 + 10) = *(undefined2 *)(iVar2 + 0x24);
    piVar3[4] = p2 + p4;
    piVar3[3] = local_28 + local_24;
    *piVar3 = *(int *)(iVar2 + 8);
    piVar3[1] = *(int *)(iVar2 + 0xc);
  }
  else {
    local_88 = local_88 + p2;
    local_8c = local_8c - p4;
    if ((local_88 >> 0xf ^ local_88 >> 0x1f) - (local_88 >> 0x1f) <
        (int)((local_8c ^ (int)local_8c >> 0x1f) - ((int)local_8c >> 0x1f))) {
      iVar2 = (int)(CONCAT44(local_88 >> 0x10,local_88 * 0x10000) / (longlong)(int)local_8c);
    }
    else {
      iVar2 = 0x10000;
    }
    *(short *)(piVar3 + 2) =
         (short)(((uint)((longlong)iVar2 * (longlong)local_70) >> 0x10 |
                 (int)((ulonglong)((longlong)iVar2 * (longlong)local_70) >> 0x20) << 0x10) +
                 local_78 >> 8);
    *(short *)((int)piVar3 + 10) = (short)((uint)(local_90 + local_2c + 0x8000) >> 0x10);
    piVar3[3] = local_28 +
                ((uint)((longlong)iVar2 * (longlong)local_24) >> 0x10 |
                (int)((ulonglong)((longlong)iVar2 * (longlong)local_24) >> 0x20) << 0x10);
    piVar3[4] = p2 + ((uint)((longlong)iVar2 * (longlong)p4) >> 0x10 |
                     (int)((ulonglong)((longlong)iVar2 * (longlong)p4) >> 0x20) << 0x10);
    *piVar3 = local_38 +
              ((uint)((longlong)iVar2 * (longlong)local_3c) >> 0x10 |
              (int)((ulonglong)((longlong)iVar2 * (longlong)local_3c) >> 0x20) << 0x10);
    piVar3[1] = local_30 +
                ((uint)((longlong)iVar2 * (longlong)local_34) >> 0x10 |
                (int)((ulonglong)((longlong)iVar2 * (longlong)local_34) >> 0x20) << 0x10);
  }
  DAT_001d11b0 = piVar3;
  #undef local_a0
  #undef local_9c
  #undef local_98
  return;
}




/* ==== 173290-173374  (nach Attic)  fremd? ==== */


undefined4 f_173290(void)

{
  undefined4 uVar1;
  
  if (DAT_001a9932 == '\0') {
    f_1728f0();
    return 0;
  }
  if (((DAT_001d122d & DAT_001d1230) != 0) && (DAT_001a994c == '\0')) {
    f_172bdc(1);
    return 0;
  }
  f_172bdc(0);
  return 0;
}




/* ==== 173374-1735C4  (nach Attic)  fremd? ==== */




void f_173374(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  DAT_001d1200 = _DAT_001a9970 << 0x10;
  DAT_001d1230 = 0;
  if ((DAT_001d122c != '\0') && (iVar1 = f_16d361((int *)(&DAT_001d11a0), (int *)(&DAT_001c90e8)), 0 < iVar1)) {
    DAT_001d11a4 = -DAT_001d11a4;
    DAT_001d11a8 = -DAT_001d11a8;
    DAT_001d11a0 = -DAT_001d11a0;
  }
  local_2c = DAT_001c90e8;
  local_20 = DAT_001c90e8;
  local_1c = DAT_001c90ec;
  local_30 = DAT_001c90ec;
  puVar6 = &DAT_001c9100;
  local_24 = DAT_001c90f0;
  local_28 = DAT_001c90f0;
  iVar1 = DAT_001d11b4;
  while (iVar1 = iVar1 + -1, iVar1 != 0) {
    iVar7 = puVar6[4];
    iVar4 = iVar7;
    if ((local_2c <= iVar7) && (iVar4 = local_2c, local_20 < iVar7)) {
      local_20 = iVar7;
    }
    local_2c = iVar4;
    iVar7 = puVar6[5];
    iVar4 = iVar7;
    if ((local_30 <= iVar7) && (iVar4 = local_30, local_1c < iVar7)) {
      local_1c = iVar7;
    }
    local_30 = iVar4;
    iVar7 = puVar6[6];
    iVar4 = iVar7;
    if ((local_28 <= iVar7) && (iVar4 = local_28, local_24 < iVar7)) {
      local_24 = iVar7;
    }
    local_28 = iVar4;
    puVar6 = puVar6 + 10;
  }
  iVar7 = 0;
  local_34 = 0;
  iVar1 = DAT_001cd1e8;
  do {
    while( true ) {
      if (iVar1 == 0) goto LAB_00173581;
      if (0xe < *(ushort *)(iVar1 + 10)) break;
LAB_00173537:
      iVar1 = *(int *)(iVar1 + 0x54);
      if (0x23 < iVar7) goto LAB_00173581;
    }
    if ((*(char *)(iVar1 + 6) == '\x01') || (*(char *)(iVar1 + 6) == '\x03')) {
      iVar4 = *(int *)(iVar1 + 0x18);
      if (((local_2c <= *(int *)(iVar1 + 0x3c) + iVar4) &&
          (((*(int *)(iVar1 + 0x3c) - iVar4 <= local_20 &&
            (local_30 <= *(int *)(iVar1 + 0x40) + iVar4)) &&
           (*(int *)(iVar1 + 0x40) - iVar4 <= local_1c)))) &&
         ((local_28 <= *(int *)(iVar1 + 0x44) + iVar4 &&
          (*(int *)(iVar1 + 0x44) - iVar4 <= local_24)))) {
        iVar2 = f_16d361((int *)(&DAT_001d11a0), (int *)(iVar1 + 0x3c));
        iVar3 = f_16d361((int *)(&DAT_001d11a0), (int *)(&DAT_001c90e8));
        uVar5 = iVar2 - iVar3 >> 0x1f;
        if ((int)((iVar2 - iVar3 ^ uVar5) - uVar5) <= iVar4) {
          DAT_001d1230 = 1;
          local_34 = local_34 + 1;
          *(int *)(&DAT_001d11d0 + iVar7) = iVar1;
          iVar7 = iVar7 + 4;
        }
      }
      goto LAB_00173537;
    }
    iVar4 = f_16d361((int *)(&DAT_001d11a0), (int *)(iVar1 + 0x48));
    if (0 < iVar4) goto LAB_00173537;
    DAT_001d1200 = DAT_001d1200 + (uint)*(ushort *)(iVar1 + 10) * -iVar4;
    iVar1 = *(int *)(iVar1 + 0x54);
  } while (iVar7 < 0x24);
LAB_00173581:
  DAT_001d11ac = local_34;
  _DAT_001aea48 =
       (0x8000 < (int)((DAT_001d11a8 ^ (int)DAT_001d11a8 >> 0x1f) - ((int)DAT_001d11a8 >> 0x1f))) +
       2;
  DAT_001aea4c = 1 << (sbyte)_DAT_001aea48;
  return;
}




/* ==== 1735C4-1737C4  (nach Attic)  fremd? ==== */


int f_1735c4(undefined4 p1,int *p2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_30_arr[3];
  #define local_30 (local_30_arr[0])
  #define local_2c (local_30_arr[1])
  #define local_28 (local_30_arr[2])
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  local_24 = DAT_001d1200;
  iVar1 = *p2;
  iVar2 = p2[1];
  iVar3 = p2[2];
  local_20 = 0;
  if (0 < DAT_001d11ac) {
    local_1c = 0;
    do {
      iVar4 = *(int *)(&DAT_001d11d0 + local_1c);
      uVar5 = iVar1 - *(int *)(iVar4 + 0x3c);
      uVar9 = (int)uVar5 >> 0x1f;
      if ((((int)((uVar5 ^ uVar9) - uVar9) <= *(int *)(iVar4 + 0x18)) &&
          (uVar5 = iVar2 - *(int *)(iVar4 + 0x40), uVar9 = (int)uVar5 >> 0x1f,
          (int)((uVar5 ^ uVar9) - uVar9) <= *(int *)(iVar4 + 0x18))) &&
         (uVar5 = iVar3 - *(int *)(iVar4 + 0x44), uVar9 = (int)uVar5 >> 0x1f,
         (int)((uVar5 ^ uVar9) - uVar9) <= *(int *)(iVar4 + 0x18))) {
        local_30 = iVar1 - *(int *)(iVar4 + 0x3c);
        local_2c = iVar2 - *(int *)(iVar4 + 0x40);
        local_28 = iVar3 - *(int *)(iVar4 + 0x44);
        local_18 = f_163d48(&local_30);
        if (0 < local_18) {
          if (*(int *)(iVar4 + 0x18) < local_18) goto LAB_00173782;
          iVar6 = (int)(CONCAT44((int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 >> 0x10,
                                 (int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 << 0x10) /
                       (longlong)local_18);
          local_30 = (uint)((longlong)(int)local_30 * (longlong)iVar6) >> 0x10 |
                     (int)((ulonglong)((longlong)(int)local_30 * (longlong)iVar6) >> 0x20) << 0x10;
          local_2c = (uint)((longlong)(int)local_2c * (longlong)iVar6) >> 0x10 |
                     (int)((ulonglong)((longlong)(int)local_2c * (longlong)iVar6) >> 0x20) << 0x10;
          local_28 = (uint)((longlong)(int)local_28 * (longlong)iVar6) >> 0x10 |
                     (int)((ulonglong)((longlong)(int)local_28 * (longlong)iVar6) >> 0x20) << 0x10;
        }
        iVar7 = -f_16d361((int *)(&DAT_001d11a0), (*(char *)(iVar4 + 6) == 1) ? (int *)local_30_arr : (int *)(iVar4 + 0x48));
        // Original 1736d9..1736f0: nur negative Einfallswerte behandeln.
        iVar6 = iVar7;
        if (iVar7 < 0) {
          iVar6 = (DAT_001a9a1c & 0x01000000) ? -iVar7 : 0;
        }
        iVar6 = ((uint)((longlong)iVar6 * 0xcccc) >> 0x10 |
                (int)((ulonglong)((longlong)iVar6 * 0xcccc) >> 0x20) << 0x10) + 0x3333;
        if (*(char *)(iVar4 + 6) == '\x03') {
          iVar8 = f_16d361((int *)(iVar4 + 0x48), (int *)local_30_arr);
          iVar7 = *(int *)(iVar4 + 0x20);
          if (iVar8 < iVar7) goto LAB_00173782;
          if (iVar8 < *(int *)(iVar4 + 0x1c)) {
            iVar6 = (int)(((longlong)iVar6 * (longlong)(iVar8 - iVar7)) /
                         (longlong)(*(int *)(iVar4 + 0x1c) - iVar7));
          }
        }
        if (*(int *)(iVar4 + 0x10) == 0) {
          if (*(int *)(iVar4 + 0x14) < local_18) {
            iVar7 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x14);
            iVar8 = *(int *)(iVar4 + 0x18) - local_18;
            goto LAB_00173767;
          }
        }
        else {
          iVar7 = *(int *)(iVar4 + 0x18);
          iVar8 = iVar7 - local_18;
LAB_00173767:
          iVar6 = (int)(((longlong)iVar6 * (longlong)iVar8) / (longlong)iVar7);
        }
        if (0x28f < iVar6) {
          local_24 = local_24 + (uint)*(ushort *)(iVar4 + 10) * iVar6;
        }
      }
LAB_00173782:
      local_1c = local_1c + 4;
      local_20 = local_20 + 1;
    } while (local_20 < DAT_001d11ac);
  }
  if (0x3f0000 < local_24) {
    local_24 = 0x3f0000;
  }
  #undef local_30
  #undef local_2c
  #undef local_28
  return local_24;
}




/* ==== 1737C4-1739E8  (nach Attic)  fremd? ==== */


void f_1737c4(int in_EAX)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *p2;
  int local_3c_arr[3];
  #define local_3c (local_3c_arr[0])
  #define local_38 (local_3c_arr[1])
  #define local_34 (local_3c_arr[2])
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  ushort *local_1c;
  
  iVar6 = DAT_001d11b4 + 1;
  if (DAT_001a994c == '\0') {
    if ((*(int *)(in_EAX + 0x48) == 0) || (DAT_001d11fc == 0)) {
      iVar6 = DAT_001d11b4 + 1;
      puVar3 = &DAT_001c9330;
      while (iVar6 = iVar6 + -1, iVar6 != 0) {
        puVar3[1] = DAT_001d1200;
        puVar3 = puVar3 + 10;
      }
    }
    else if ((*(byte *)(DAT_001d11fc + 3) & 4) == 0) {
      if ((DAT_001d122d == '\0') || (DAT_001d11f8 == 0)) {
        local_38 = 0;
        local_34 = 0;
        local_1c = (ushort *)(DAT_001d1218 + 2);
        local_3c = 0;
        local_30 = (uint)*(byte *)(DAT_001d1218 + 1);
        local_2c = *(int *)(DAT_001d11f8 + 0x40);
        local_28 = *(int *)(DAT_001d11fc + 0x1c);
        iVar6 = (int)(0x10000 / (ulonglong)(longlong)(int)local_30);
        local_24 = 0;
        local_20 = 0;
        iVar7 = local_30 + 1;
        while (iVar2 = local_20, iVar7 = iVar7 + -1, iVar7 != 0) {
          uVar1 = *local_1c;
          local_1c = local_1c + 1;
          p2 = (int *)((uint)*(ushort *)((uint)uVar1 * 0xc + local_2c) * 0xc + local_28);
          iVar5 = f_1735c4(2,p2);
          if (iVar2 < iVar5) {
            local_20 = iVar5;
          }
          local_24 = local_24 + iVar5;
          local_3c = local_3c +
                     ((uint)((longlong)iVar6 * (longlong)*p2) >> 0x10 |
                     (int)((ulonglong)((longlong)iVar6 * (longlong)*p2) >> 0x20) << 0x10);
          local_38 = local_38 +
                     ((uint)((longlong)iVar6 * (longlong)p2[1]) >> 0x10 |
                     (int)((ulonglong)((longlong)iVar6 * (longlong)p2[1]) >> 0x20) << 0x10);
          local_34 = local_34 +
                     ((uint)((longlong)iVar6 * (longlong)p2[2]) >> 0x10 |
                     (int)((ulonglong)((longlong)iVar6 * (longlong)p2[2]) >> 0x20) << 0x10);
        }
        iVar6 = f_1735c4(2,&local_3c);
        if (iVar2 < iVar6) {
          local_20 = iVar6;
        }
        iVar7 = DAT_001d11b4;
        puVar3 = &DAT_001c9330;
        if (DAT_001d11b4 == 0) {
          return;
        }
        do {
          puVar3[1] = (local_24 + iVar6) / (int)(local_30 + 1) + local_20 >> 1;
          iVar7 = iVar7 + -1;
          puVar3 = puVar3 + 10;
        } while (iVar7 != 0);
      }
      else {
        puVar3 = &DAT_001c9340;
        puVar8 = &DAT_001c9330;
        while (iVar6 = iVar6 + -1, iVar6 != 0) {
          uVar4 = f_1735c4(2,puVar3);
          puVar3 = puVar3 + 10;
          puVar8[1] = uVar4;
          puVar8 = puVar8 + 10;
        }
      }
    }
    else {
      puVar3 = &DAT_001c9330;
      while (iVar6 = iVar6 + -1, iVar6 != 0) {
        puVar3[1] = 0x3e0000;
        puVar3 = puVar3 + 10;
      }
      DAT_001d122d = '\0';
    }
  }
  else {
    DAT_001d11f4 = (int)(-0x3f00000000 / (longlong)DAT_001a9af8);
    puVar3 = &DAT_001c9330;
    while (iVar6 = iVar6 + -1, iVar6 != 0) {
      puVar3[1] = (uint)((longlong)DAT_001d11f4 * (longlong)(int)puVar3[6]) >> 0x10 |
                  (int)((ulonglong)((longlong)DAT_001d11f4 * (longlong)(int)puVar3[6]) >> 0x20) <<
                  0x10;
      puVar3 = puVar3 + 10;
    }
  }
  #undef local_3c
  #undef local_38
  #undef local_34
  return;
}




/* ==== 1739E8-173D0C  (nach Attic)  fremd? ==== */


undefined4 f_1739e8(int p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int p4_00;
  int p2_00;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined *p3_00;
  int p1_00;
  int local_54;
  undefined4 *local_50;
  int local_4c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  lVar8 = (longlong)DAT_001a9b0c * (longlong)(DAT_001d11c0 - DAT_001d1214);
  iVar10 = (int)((uint)lVar8 >> 0x10 | (int)((ulonglong)lVar8 >> 0x20) << 0x10) /
           (int)(short)((*(short *)(p1 + 0x4e) - *(short *)(p1 + 0x4c)) + 1);
  lVar8 = (longlong)DAT_001a9b0c * (longlong)(DAT_001d11bc - DAT_001d1210);
  iVar11 = (int)((uint)lVar8 >> 0x10 | (int)((ulonglong)lVar8 >> 0x20) << 0x10) /
           (int)(short)((*(short *)(p1 + 0x52) - *(short *)(p1 + 0x50)) + 1);
  if (iVar10 < iVar11) {
    iVar11 = iVar10;
  }
  local_50 = &DAT_001c9330;
  p3_00 = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0;
  if (DAT_001d122e != '\0') {
    p3_00 = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4;
  }
  local_54 = 0;
  if (0 < DAT_001d11b4) {
    do {
      local_4c = 0;
      do {
        if (local_4c == 0) {
          iVar10 = ((int)local_50[9] >> 0x10) - DAT_001d1228;
        }
        else {
          iVar10 = (((int)local_50[9] >> 0x10) + ((int)local_50[0x13] >> 0x10) >> 1) - DAT_001d1228;
        }
        uVar13 = (*(int *)(&DAT_001cae90 + iVar10 * 10) >> 0x10) -
                 (*(int *)(&DAT_001c9590 + iVar10 * 10) >> 0x10);
        uVar14 = (int)uVar13 >> 0x1f;
        if (3 < (int)((uVar13 ^ uVar14) - uVar14)) {
          iVar1 = (&DAT_001c9588)[iVar10 * 5];
          iVar2 = (&DAT_001c958c)[iVar10 * 5];
          iVar3 = (&DAT_001cae88)[iVar10 * 5];
          iVar4 = (&DAT_001cae8c)[iVar10 * 5];
          p4_00 = (&DAT_001c9594)[iVar10 * 5];
          p2_00 = (&DAT_001c9598)[iVar10 * 5];
          iVar5 = (&DAT_001cae94)[iVar10 * 5];
          iVar6 = (&DAT_001cae98)[iVar10 * 5];
          iVar7 = *(int *)(&DAT_001cae90 + iVar10 * 10);
          iVar10 = *(int *)(&DAT_001c9590 + iVar10 * 10);
          p1_00 = (iVar10 >> 0x10) << 0x10;
          local_1c = 0;
          local_24 = iVar2;
          local_20 = iVar1;
          do {
            local_20 = local_20 + (iVar3 - iVar1) / 3;
            p1_00 = p1_00 + (((iVar7 >> 0x10) - (iVar10 >> 0x10)) * 0x10000) / 3;
            local_24 = local_24 + (iVar4 - iVar2) / 3;
            iVar12 = f_16d34f(p1_00,p2_00,p3_00,p4_00);
            uVar13 = f_16d34f(p3_00,iVar5 - p4_00,p1_00,iVar6 - p2_00);
            if (((iVar12 >> 0xf ^ iVar12 >> 0x1f) - (iVar12 >> 0x1f) <
                 (int)((uVar13 ^ (int)uVar13 >> 0x1f) - ((int)uVar13 >> 0x1f))) &&
               (iVar12 = (int)(CONCAT44(iVar12 >> 0x10,iVar12 << 0x10) / (longlong)(int)uVar13),
               lVar8 = (longlong)iVar12 * (longlong)(iVar3 - iVar1),
               lVar9 = (longlong)iVar12 * (longlong)(iVar4 - iVar2),
               uVar13 = (iVar1 + ((uint)lVar8 >> 0x10 | (int)((ulonglong)lVar8 >> 0x20) << 0x10)) -
                        local_20, uVar15 = (int)uVar13 >> 0x1f,
               uVar14 = (iVar2 + ((uint)lVar9 >> 0x10 | (int)((ulonglong)lVar9 >> 0x20) << 0x10)) -
                        local_24, uVar16 = (int)uVar14 >> 0x1f,
               local_28 = ((uVar13 ^ uVar15) - uVar15) + ((uVar14 ^ uVar16) - uVar16),
               iVar11 < local_28)) {
              if ((*DAT_001d1218 & 0x20) != 0) {
                return 1;
              }
              if (iVar11 + 0x6666 < local_28) {
                *DAT_001d1218 = *DAT_001d1218 | 0x20;
                return 1;
              }
              return 0;
            }
            local_1c = local_1c + 1;
          } while (local_1c < 2);
        }
        local_4c = local_4c + 1;
      } while (local_4c < 2);
      local_54 = local_54 + 1;
      local_50 = local_50 + 10;
    } while (local_54 < DAT_001d11b4);
  }
  if ((*DAT_001d1218 & 0x20) != 0) {
    if (iVar11 + -0xcccc <= local_28) {
      return 1;
    }
    *DAT_001d1218 = *DAT_001d1218 & 0xdf;
  }
  return 0;
}




/* ==== 173D0C-17410C  (nach Attic)  fremd? ==== */




void f_173d0c(undefined4 p1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  short sVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *puVar13;
  bool bVar14;
  undefined1 *local_2c;
  int local_20;
  char local_1c;
  
  puVar9 = &DAT_001c90d8;
  iVar12 = 1;
  DAT_001d1224 = _DAT_001c90fc >> 0x10;
  local_20 = 0;
  puVar7 = &DAT_001c9100;
  iVar6 = DAT_001c90f8;
  iVar5 = DAT_001c90f8;
  DAT_001d1228 = DAT_001d1224;
  if (1 < DAT_001d11b4) {
    do {
      iVar1 = puVar7[8];
      if (iVar1 < iVar6) {
        DAT_001d1228 = (int)puVar7[9] >> 0x10;
        iVar6 = iVar1;
        puVar9 = puVar7;
        local_20 = iVar12;
      }
      else if (iVar5 < iVar1) {
        DAT_001d1224 = (int)puVar7[9] >> 0x10;
        iVar5 = iVar1;
      }
      iVar12 = iVar12 + 1;
      puVar7 = puVar7 + 10;
    } while (iVar12 < DAT_001d11b4);
  }
  iVar6 = DAT_001d11b4 - local_20;
  puVar7 = &DAT_001c9330;
  for (uVar4 = (uint)(iVar6 * 0x28) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar7 = puVar7 + 1;
  }
  for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar9;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  iVar12 = 1;
  puVar7 = &DAT_001c90d8;
  puVar9 = &DAT_001c9330 + iVar6 * 10;
  for (uVar4 = (uint)(local_20 * 0x28) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  puVar11 = &DAT_001c9358;
  local_2c = &DAT_001c9358;
  if (1 < DAT_001d11b4) {
    do {
      if (iVar5 <= *(int *)(puVar11 + 0x20)) {
        local_2c = puVar11;
      }
      iVar12 = iVar12 + 1;
      puVar11 = puVar11 + 0x28;
    } while (iVar12 < DAT_001d11b4);
  }
  f_1737c4(p1);
  iVar6 = DAT_001d11b4 * 0x28;
  puVar8 = &DAT_001c9330 + DAT_001d11b4 * 10;
  puVar7 = &DAT_001c9330;
  puVar9 = puVar8;
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  puVar11 = (undefined1 *)(iVar6 + ((int)(uintptr_t)(&riva_dgroup_base[0x1c9308 - 0x1a0000])));
  sVar10 = (short)DAT_001c937c;
  for (puVar13 = &DAT_001c9358;
      (sVar10 == (short)DAT_001c9354 && ((*((int16_t *)((char *)&(DAT_001c9354) + 2))) == *(short *)(puVar13 + 0x26)));
      puVar13 = puVar13 + 0x28) {
    sVar10 = *(short *)(puVar13 + 0x4c);
  }
  for (; ((short)DAT_001c9354 == *(short *)(puVar11 + 0x24) &&
         ((*((int16_t *)((char *)&(DAT_001c9354) + 2))) == *(short *)(puVar11 + 0x26))); puVar11 = puVar11 + -0x28) {
  }
  uVar4 = 0;
  cVar2 = local_1c;
  if (0 < DAT_001d11b4) {
    do {
      iVar6 = f_16d34f(*(int *)(puVar13 + 0x1c) - DAT_001c934c >> 8,
                       *(int *)(puVar11 + 0x20) - DAT_001c9350 >> 8,
                       *(int *)(puVar11 + 0x1c) - DAT_001c934c >> 8,
                       *(int *)(puVar13 + 0x20) - DAT_001c9350 >> 8);
      cVar2 = iVar6 < 0;
      if (iVar6 != 0) break;
      if (((uVar4 & 1) == 0) || (local_2c <= puVar13)) {
        if (local_2c < puVar11) {
          puVar11 = puVar11 + -0x28;
        }
      }
      else {
        puVar13 = puVar13 + 0x28;
      }
      uVar4 = uVar4 + 1;
      cVar2 = local_1c;
    } while ((int)uVar4 < DAT_001d11b4);
  }
  local_1c = cVar2;
  bVar14 = DAT_001d1224 == DAT_001d1228;
  if (local_1c == '\0') {
    iVar6 = 0x140;
  }
  else {
    iVar6 = 0;
  }
  sVar10 = -0x7fff;
  DAT_001d11b0 = &DAT_001c9588 + iVar6 * 5;
  iVar6 = 0;
  puVar7 = &DAT_001c9330;
  if (0 < DAT_001d11b4) {
    do {
      puVar9 = DAT_001d11b0;
      if ((*(short *)((int)puVar7 + 0x4e) < *(short *)((int)puVar7 + 0x26)) &&
         ((int)puVar7[9] >> 0x10 == DAT_001d1224)) break;
      if (*(short *)((int)puVar7 + 0x4e) == *(short *)((int)puVar7 + 0x26)) {
        if ((bVar14) && (sVar10 < *(short *)(puVar7 + 9))) {
          *(undefined2 *)((int)DAT_001d11b0 + 10) = *(undefined2 *)(puVar7 + 9);
          cVar2 = DAT_001d122e;
          *(short *)(puVar9 + 2) = (short)((uint)puVar7[1] >> 8);
          puVar9 = DAT_001d11b0;
          if (cVar2 == '\0') {
            uVar3 = puVar7[4];
          }
          else {
            uVar3 = puVar7[5];
          }
          DAT_001d11b0[3] = uVar3;
          puVar9[4] = puVar7[6];
          *puVar9 = puVar7[2];
          puVar9[1] = puVar7[3];
          sVar10 = *(short *)(puVar7 + 9);
        }
      }
      else {
        DAT_001d11cc = puVar7 + 10;
        DAT_001d11c8 = puVar7;
        f_173290();
      }
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 10;
    } while (iVar6 < DAT_001d11b4);
  }
  if (local_1c == '\0') {
    iVar6 = 0;
  }
  else {
    iVar6 = 0x140;
  }
  sVar10 = 0x7fff;
  DAT_001d11b0 = &DAT_001c9588 + iVar6 * 5;
  iVar6 = 0;
  if (0 < DAT_001d11b4) {
    do {
      puVar7 = DAT_001d11b0;
      if ((*(short *)((int)puVar8 + -2) < *(short *)((int)puVar8 + 0x26)) &&
         ((int)puVar8[9] >> 0x10 == DAT_001d1224)) {
        return;
      }
      if (*(short *)((int)puVar8 + -2) == *(short *)((int)puVar8 + 0x26)) {
        if ((bVar14) && (*(short *)(puVar8 + 9) < sVar10)) {
          *(undefined2 *)((int)DAT_001d11b0 + 10) = *(undefined2 *)(puVar8 + 9);
          *(short *)(puVar7 + 2) = (short)((uint)puVar8[1] >> 8);
          puVar7 = DAT_001d11b0;
          if (DAT_001d122e == '\0') {
            uVar3 = puVar8[4];
          }
          else {
            uVar3 = puVar8[5];
          }
          DAT_001d11b0[3] = uVar3;
          puVar7[4] = puVar8[6];
          *puVar7 = puVar8[2];
          puVar7[1] = puVar8[3];
          sVar10 = *(short *)(puVar8 + 9);
        }
      }
      else {
        DAT_001d11cc = puVar8 + -10;
        DAT_001d11c8 = puVar8;
        f_173290();
      }
      iVar6 = iVar6 + 1;
      puVar8 = puVar8 + -10;
    } while (iVar6 < DAT_001d11b4);
  }
  return;
}




/* ==== 17410C-174158  (nach Attic)  fremd? ==== */


void f_17410c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_001cae88;
  puVar1 = &DAT_001c9588;
  iVar3 = (DAT_001d1224 - DAT_001d1228) + 1;
  if (iVar3 == 0) {
    return;
  }
  do {
    if (0x3f00 < *(ushort *)(puVar1 + 2)) {
      *(undefined2 *)(puVar1 + 2) = 0x3f00;
    }
    if (0x3f00 < *(ushort *)(puVar2 + 2)) {
      *(undefined2 *)(puVar2 + 2) = 0x3f00;
    }
    puVar2 = puVar2 + 5;
    puVar1 = puVar1 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}




/* ==== 174158-1744C8  (nach Attic)  fremd? ==== */


bool f_174158(int p1,int p2,int p3,int p4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int p1_00;
  int local_38;
  int local_34;
  int local_2c;
  int local_20;
  undefined *local_1c;
  
  puVar14 = &DAT_001c9330;
  local_2c = 0;
  local_34 = 0x7fffffff;
  local_38 = -0x80000000;
  local_20 = 0;
  p1_00 = p2 * 0x10000;
  if (0 < DAT_001d11b4) {
    do {
      if (((p1 << 0x10 <= (int)puVar14[7]) && ((int)puVar14[7] < p1_00)) ||
         ((p1_00 <= (int)puVar14[7] && ((int)puVar14[7] < p1 << 0x10)))) {
        if ((int)puVar14[9] >> 0x10 < DAT_001d11c4) {
          DAT_001d11c4 = (int)puVar14[9] >> 0x10;
        }
        if (DAT_001d1208 < (int)puVar14[9] >> 0x10) {
          DAT_001d1208 = (int)puVar14[9] >> 0x10;
        }
      }
      if ((((int)puVar14[7] <= p1_00) && (p1_00 < (int)puVar14[0x11])) ||
         (((int)puVar14[0x11] <= p1_00 && (p1_00 < (int)puVar14[7])))) {
        iVar10 = puVar14[7];
        iVar13 = puVar14[0x11];
        iVar1 = puVar14[8];
        iVar2 = puVar14[0x12];
        iVar9 = puVar14[0x10];
        iVar3 = puVar14[6];
        if (DAT_001d122e == '\0') {
          iVar12 = puVar14[4];
          local_1c = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0;
          iVar6 = puVar14[0xe];
        }
        else {
          iVar12 = puVar14[5];
          local_1c = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4;
          iVar6 = puVar14[0xf];
        }
        iVar7 = f_16d34f(p1_00,iVar3 >> 4,local_1c,iVar12 >> 4);
        uVar8 = f_16d34f(local_1c,iVar6 - iVar12 >> 4,p1_00,iVar9 - iVar3 >> 4);
        if ((iVar7 >> 0xf ^ iVar7 >> 0x1f) - (iVar7 >> 0x1f) <
            (int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f))) {
          iVar9 = (int)(CONCAT44(iVar7 >> 0x10,iVar7 << 0x10) / (longlong)(int)uVar8);
          local_2c = local_2c + 1;
          lVar4 = (longlong)
                  ((iVar13 != iVar10)
                     ? (int)(((longlong)(p1_00 - (int)puVar14[7]) << 16) / (longlong)(iVar13 - iVar10))
                     : 0) * (longlong)(iVar2 - iVar1);
          iVar13 = puVar14[8] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
          iVar10 = iVar13 + 0x8000 >> 0x10;
          if (iVar10 < DAT_001d11c4) {
            DAT_001d11c4 = iVar10;
          }
          if (DAT_001d1208 < iVar10) {
            DAT_001d1208 = iVar10;
          }
          uVar5 = (undefined2)((uint)(iVar13 + 0x8000) >> 0x10);
          if (local_38 < iVar13) {
            *(int *)(p4 + 0x1c) = p1_00;
            *(int *)(p4 + 0x20) = iVar13;
            *(short *)(p4 + 0x24) = (short)p2;
            *(undefined2 *)(p4 + 0x26) = uVar5;
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xe] - puVar14[4]);
            *(uint *)(p4 + 0x10) =
                 puVar14[4] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xf] - puVar14[5]);
            *(uint *)(p4 + 0x14) =
                 puVar14[5] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0x10] - puVar14[6]);
            *(uint *)(p4 + 0x18) =
                 puVar14[6] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xc] - puVar14[2]);
            *(uint *)(p4 + 8) =
                 puVar14[2] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xd] - puVar14[3]);
            *(uint *)(p4 + 0xc) =
                 puVar14[3] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            uVar11 = f_1735c4(1,p4 + 0x10);
            *(undefined4 *)(p4 + 4) = uVar11;
            local_38 = iVar13;
          }
          if (iVar13 < local_34) {
            *(int *)(p3 + 0x1c) = p1_00;
            *(int *)(p3 + 0x20) = iVar13;
            *(short *)(p3 + 0x24) = (short)p2;
            *(undefined2 *)(p3 + 0x26) = uVar5;
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xe] - puVar14[4]);
            *(uint *)(p3 + 0x10) =
                 puVar14[4] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xf] - puVar14[5]);
            *(uint *)(p3 + 0x14) =
                 puVar14[5] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0x10] - puVar14[6]);
            *(uint *)(p3 + 0x18) =
                 puVar14[6] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xc] - puVar14[2]);
            *(uint *)(p3 + 8) =
                 puVar14[2] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            lVar4 = (longlong)iVar9 * (longlong)(int)(puVar14[0xd] - puVar14[3]);
            *(uint *)(p3 + 0xc) =
                 puVar14[3] + ((uint)lVar4 >> 0x10 | (int)((ulonglong)lVar4 >> 0x20) << 0x10);
            uVar11 = f_1735c4(1,p3 + 0x10);
            *(undefined4 *)(p3 + 4) = uVar11;
            local_34 = iVar13;
          }
        }
      }
      local_20 = local_20 + 1;
      puVar14 = puVar14 + 10;
    } while (local_20 < DAT_001d11b4);
  }
  return 1 < local_2c;
}




/* ==== 1744C8-17464C  (nach Attic)  fremd? ==== */


void f_1744c8(int p1,uint p2,int p3,uint p4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *p3_00;
  int iVar5;
  
  p3_00 = &DAT_001c9588 + p3 * 5;
  DAT_001d1204 = p3_00;
  if (DAT_001cdb94 == 0) {
    p2 = CONCAT31((int3)(p2 >> 8),DAT_001d122e);
    if (DAT_001d122e == '\0') {
      f_175839(DAT_001d120c & 0xff,p2,p3_00,p4);
    }
    else {
      f_1758bc(DAT_001d120c & 0xff,p2,p3_00,p4);
    }
  }
  else if (DAT_001d122f == '\0') {
    (*(code *)(&PTR_F_181D47_001aea70)[p2 & 3])();
  }
  else {
    (*(code *)(&PTR_F_17594B_001aea50)[p2])();
  }
  if (((*(char *)(p1 + 3) != '\0') && (((*((uint8_t *)((char *)&(DAT_001a9a1c) + 2))) & 0x40) != 0)) ||
     (((*((uint8_t *)((char *)&(DAT_001a9a1c) + 1))) & 8) != 0)) {
    p4 = (uint)(DAT_001d122e != '\0');
    puVar2 = &DAT_001c9330;
    if (-1 < DAT_001d11b4) {
      iVar3 = p4 * 2;
      iVar5 = DAT_001d11b4 * 4 + iVar3;
      puVar4 = (undefined4 *)((uint)(DAT_001d122e == '\0') * 2);
      do {
        *(short *)((int)&DAT_001ccf5e + iVar3 + 2) = (short)((uint)(puVar2[7] + 0x8000) >> 0x10);
        piVar1 = puVar2 + 8;
        p3_00 = puVar4 + 1;
        iVar3 = iVar3 + 4;
        p4 = *piVar1 + 0x8000 >> 0x10;
        puVar2 = puVar2 + 10;
        *(short *)((int)&DAT_001ccf5e + (int)puVar4 + 2) = (short)((uint)(*piVar1 + 0x8000) >> 0x10)
        ;
        puVar4 = p3_00;
      } while (iVar3 <= iVar5);
    }
    p2 = DAT_001cdb74;
    f_163428(DAT_001d11b4,DAT_001cdb74);
  }
  if (((*((uint8_t *)((char *)&(DAT_001a9a1c) + 1))) & 2) != 0) {
    f_16ecba(DAT_001cdb74);
    f_16fb53_xy(*(short *)(p1 + 0x4c), *(short *)(p1 + 0x50));
    f_16fb72_xy(*(short *)(p1 + 0x4e), *(short *)(p1 + 0x50));
    f_16fb72_xy(*(short *)(p1 + 0x4e), *(short *)(p1 + 0x52));
    f_16fb72_xy(*(short *)(p1 + 0x4c), *(short *)(p1 + 0x52));
    f_16fb72_xy(*(short *)(p1 + 0x4c), *(short *)(p1 + 0x50));
  }
  return;
}




/* ==== 17464C-1750B6  (nach Attic)  fremd? ==== */


void f_17464c(ushort *p1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  ushort *p4;
  undefined4 uVar9;
  undefined1 *p4_00;
  ushort *puVar10;
  undefined4 uVar11;
  undefined4 *unaff_EBP = 0;
  undefined4 *puVar12;
  undefined4 *puVar13;
  byte bVar14;
  undefined1 auStack_c8 [40];
  #define local_a4 (*(int *)(auStack_c8 + 0x24))
  undefined1 local_a0 [40];
  #define local_7c (*(int *)(local_a0 + 0x24))
  int local_78;
  int local_74;
  int local_70;
  undefined *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  uint local_58;
  int local_54;
  int local_50;
  ushort *local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  undefined4 uStack_2c;
  short sStack_28;
  int local_24;
  undefined1 local_20;
  char local_1c;
  
  if (*(char *)((int)p1 + 1) != '\x03') {
    uVar3 = p1[2];
    DAT_001d11b4 = (undefined4 *)(uint)uVar3;
    if ((2 < uVar3) && (uVar3 < 9)) {
      local_4c = p1;
      iVar4 = f_16fc19();
      DAT_001a9932 = '\0';
      DAT_001d122c = '\0';
      DAT_001d122e = '\0';
      local_1c = '\0';
      DAT_001a9a70 = DAT_001a9a70 - iVar4;
      DAT_001d122d = 0;
      DAT_001d1231 = 0x550000 < *(int *)(local_4c + 0x20) - *(int *)(local_4c + 0x1e);
      DAT_001d122f = (byte)local_4c[1] & 1;
      DAT_001d11fc = *(int *)(local_4c + 0x22);
      DAT_001d120c = *(uint *)(local_4c + 0x24);
      DAT_001d11f8 = *(int *)(*(int *)(DAT_001d11fc + 0x7c) + 0x28);
      DAT_001d1218 = *(int *)(DAT_001d11f8 + 0x44) + (uint)local_4c[4] * 0x30;
      DAT_001d11ac = 0;
      DAT_001cdb94 = 0;
      puVar12 = (undefined4 *)(DAT_001cd324 + (uint)local_4c[3] * 0xc);
      DAT_001d11a0 = *puVar12;
      DAT_001d11a4 = puVar12[1];
      DAT_001d11a8 = puVar12[2];
      if ((DAT_001d120c != 0) && (local_68 = *(int *)(DAT_001d120c + 0x2c), local_68 != 0)) {
        DAT_001cdb94 = *(int *)(local_68 + 4);
        DAT_001d122c = (*(byte *)(DAT_001d120c + 0xd) & 0x10) != 0;
        iVar4 = *(int *)(DAT_001d11fc + 0x7c);
        iVar6 = *(int *)(iVar4 + 0x18);
        sVar7 = (iVar6 != 0) ? *(short *)(iVar6 + 0x14) : 0;
        if (((iVar6 != 0) && (sVar7 != 0) && ((*(byte *)(iVar4 + 10) & 0x40) != 0)) &&
           ((*(byte *)(DAT_001d120c + 0xe) & 2) != 0)) {
          local_64 = *(int *)(iVar6 + 0x18);
          local_20 = -1 < sVar7;
          sStack_28 = sVar7;
          if (!(bool)local_20) {
            sStack_28 = -sVar7;
          }
          if ((*(char *)(local_64 + 0x14) == '\0') || (*(char *)(local_64 + 0x15) == '\0')) {
            uVar3 = *(ushort *)(iVar4 + 6);
          }
          else {
            uVar3 = *(ushort *)(local_64 + 0x18);
          }
          uVar5 = (uint)uVar3;
          puVar10 = (ushort *)(uVar5 * 4 + *(int *)(iVar6 + 0x1c));
          if ((*(char *)(local_64 + 0x14) == '\0') || (*(char *)(local_64 + 0x15) == '\0')) {
            if (*(char *)(local_64 + 0x14) == '\0') {
              uVar1 = *(undefined2 *)(iVar4 + 0xc);
            }
            else {
              uVar1 = *(undefined2 *)(local_64 + 0x16);
            }
            local_24 = CONCAT22((short)((uint)local_64 >> 0x10),uVar1);
            local_6c = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ab0;
            iVar8 = local_24 - ((int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ab0 * 800 >> 0x10);
            sVar7 = (short)iVar8;
            while (sVar7 < 0) {
              uVar5 = uVar5 + 1;
              if ((int)uVar5 < (int)sStack_28) {
                puVar10 = puVar10 + 2;
              }
              else {
                puVar10 = *(ushort **)(iVar6 + 0x1c);
                uVar5 = 0;
                if (!(bool)local_20) {
                  *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xbf;
                }
              }
              iVar8 = iVar8 + (uint)*puVar10 * 8;
              sVar7 = (short)iVar8;
            }
            uVar3 = (ushort)uVar5;
            if (*(char *)(local_64 + 0x14) == '\0') {
              *(short *)(iVar4 + 0xc) = sVar7;
              *(ushort *)(iVar4 + 6) = uVar3;
            }
            else {
              *(undefined1 *)(local_64 + 0x15) = 1;
              *(short *)(local_64 + 0x16) = sVar7;
              *(ushort *)(local_64 + 0x18) = uVar3;
            }
          }
          *(ushort *)(iVar4 + 6) = uVar3;
          uVar5 = (uint)puVar10[1];
          if (*(ushort *)(local_64 + 0x1a) <= uVar5) {
            uVar5 = *(ushort *)(local_64 + 0x1a) - 1;
          }
          DAT_001cdb94 = *(int *)(*(int *)(local_64 + 0x20) + uVar5 * 4);
          DAT_001d122f = 0;
        }
        if ((*(ushort *)(local_68 + 0x18) < 0x41) && (*(ushort *)(local_68 + 0x1a) < 0x41)) {
          DAT_001a9a24 = 0x3f3f;
        }
        else if ((*(ushort *)(local_68 + 0x18) < 0x81) && (*(ushort *)(local_68 + 0x1a) < 0x81)) {
          DAT_001a9a24 = 0x7f7f;
        }
        else {
          DAT_001a9a24 = 0xffff;
        }
        if ((((byte)DAT_001a9a1c & 8) != 0) && ((*(byte *)(DAT_001d11fc + 3) & 4) == 0)) {
          DAT_001d122d = 1;
        }
      }
      DAT_001d121c = *(int *)(local_4c + 0x25) >> 0x10;
      puVar10 = local_4c + 5;
      p4 = local_4c + 0xe;
      DAT_001d1220 = *(int *)(local_4c + 0x26) >> 0x10;
      iVar4 = (int)DAT_001d11b4 + 1;
      puVar12 = &DAT_001c90d8;
      while (iVar4 = iVar4 + -1, iVar4 != 0) {
        local_44 = (uint)*puVar10;
        puVar13 = (undefined4 *)(DAT_001cd314 + local_44 * 0xc);
        puVar12[4] = *puVar13;
        puVar12[5] = puVar13[1];
        puVar12[6] = puVar13[2];
        local_70 = local_44 * 8;
        puVar13 = (undefined4 *)(DAT_001cd224 + local_70);
        puVar12[7] = *puVar13;
        puVar12[8] = puVar13[1];
        puVar13 = *(undefined4 **)p4;
        puVar12[2] = *puVar13;
        puVar12[3] = puVar13[1];
        *(short *)(puVar12 + 9) = (short)((uint)(puVar12[7] + 0x8000) >> 0x10);
        puVar10 = puVar10 + 1;
        p4 = p4 + 2;
        *(short *)((int)puVar12 + 0x26) = (short)((uint)(puVar12[8] + 0x8000) >> 0x10);
        puVar12 = puVar12 + 10;
      }
      puVar12 = (undefined4 *)0x0;
      if (DAT_001cdb94 != 0) {
        uVar3 = *(ushort *)(local_68 + 0x1a);
        DAT_001d11c0 = DAT_001c90e0;
        DAT_001d1214 = DAT_001c90e0;
        iVar4 = 1;
        DAT_001d11bc = DAT_001c90e4;
        DAT_001d1210 = DAT_001c90e4;
        puVar12 = &DAT_001c9100;
        if (1 < (int)DAT_001d11b4) {
          do {
            iVar6 = puVar12[2];
            iVar8 = iVar6;
            if ((DAT_001d1214 <= iVar6) && (iVar8 = DAT_001d1214, DAT_001d11c0 < iVar6)) {
              DAT_001d11c0 = iVar6;
            }
            DAT_001d1214 = iVar8;
            iVar6 = puVar12[3];
            iVar8 = iVar6;
            if ((DAT_001d1210 <= iVar6) && (iVar8 = DAT_001d1210, DAT_001d11bc < iVar6)) {
              DAT_001d11bc = iVar6;
            }
            DAT_001d1210 = iVar8;
            iVar4 = iVar4 + 1;
            puVar12 = puVar12 + 10;
          } while (iVar4 < (int)DAT_001d11b4);
        }
        if (((*((uint8_t *)((char *)&(DAT_001a9a1c) + 3))) & 4) != 0) {
          local_74 = ((*(int *)(local_4c + 0x26) >> 0x10) - (*(int *)(local_4c + 0x25) >> 0x10)) + 2
          ;
          local_70 = *(int *)(local_4c + 0x28) >> 0x10;
          local_6c = (undefined *)(*(int *)(local_4c + 0x27) >> 0x10);
          local_78 = (local_70 - (int)local_6c) + 2;
          iVar4 = (int)((uint)*(ushort *)(local_68 + 0x18) * (DAT_001d11c0 - DAT_001d1214)) /
                  local_74;
          iVar6 = (int)((uint)uVar3 * (DAT_001d11bc - DAT_001d1210)) / local_78;
          if (iVar6 < iVar4) {
            iVar4 = iVar6;
          }
          if (iVar4 < 0x80001) {
            if (iVar4 < 0x50001) {
              if (0x30000 < iVar4) {
                DAT_001a9a24 = DAT_001a9a24 & 0xfffffefe;
              }
            }
            else {
              DAT_001a9a24 = DAT_001a9a24 & 0xfffffcfc;
            }
          }
          else {
            DAT_001a9a24 = DAT_001a9a24 & 0xfffff8f8;
          }
        }
        iVar4 = DAT_001d1214 >> 0x10;
        local_5c = iVar4 * 0x10000;
        p4 = (ushort *)(*(ushort *)(local_68 + 0x18) - 1);
        iVar6 = DAT_001d1210 >> 0x10;
        local_60 = iVar6 * 0x10000;
        puVar10 = (ushort *)0x0;
        puVar13 = &DAT_001c90d8;
        puVar12 = DAT_001d11b4;
        if (0 < (int)DAT_001d11b4) {
          do {
            puVar13[2] = (puVar13[2] + iVar4 * -0x10000) * (int)p4 + 0x8000;
            iVar8 = (puVar13[3] + iVar6 * -0x10000) * (uVar3 - 1) + 0x8000;
            puVar10 = (ushort *)((int)puVar10 + 1);
            puVar13[3] = iVar8;
            puVar2 = DAT_001d11b4;
            puVar12 = (undefined4 *)-iVar8;
            puVar13[3] = puVar12;
            puVar13 = puVar13 + 10;
          } while ((int)puVar10 < (int)puVar2);
        }
        if ((((((byte)DAT_001a9a1c & 2) != 0) || (DAT_001d122d != 0)) || ((char)*local_4c != '\0'))
           || ((puVar12 = *(undefined4 **)(local_4c + 0x1e), puVar10 = local_4c,
               (int)((uint)((longlong)(int)puVar12 * 0x10ccc) >> 0x10 |
                    (int)((ulonglong)((longlong)(int)puVar12 * 0x10ccc) >> 0x20) << 0x10) <
               *(int *)(local_4c + 0x20) || (*(int *)(local_4c + 0x1e) < 0xf0000)))) {
          DAT_001a9932 = '\x01';
        }
        if (((DAT_001a9932 != '\0') &&
            (puVar10 = (ushort *)((int)DAT_001d11a4 >> 0x1f),
            (int)((DAT_001d11a4 ^ (uint)puVar10) - (int)puVar10) < 0x8000)) &&
           ((DAT_001d1231 != '\0' ||
            ((DAT_001d122c == '\0' || (*(ushort *)(DAT_001d11fc + 0xc) < 3)))))) {
          DAT_001d121c = *(int *)(local_4c + 0x27) >> 0x10;
          puVar12 = (undefined4 *)CONCAT31((int3)((uint)puVar12 >> 8),1);
          puVar10 = (ushort *)((int)DAT_001d11b4 + 1);
          DAT_001d1220 = *(int *)(local_4c + 0x28) >> 0x10;
          DAT_001d122e = '\x01';
          puVar13 = &DAT_001c90d8;
          while (puVar10 = (ushort *)((int)puVar10 + -1), puVar10 != (ushort *)0x0) {
            uVar11 = puVar13[7];
            uVar9 = puVar13[8];
            puVar13[8] = uVar11;
            puVar13[7] = uVar9;
            puVar12 = (undefined4 *)
                      CONCAT22((short)((uint)uVar11 >> 0x10),*(undefined2 *)((int)puVar13 + 0x26));
            uVar1 = *(undefined2 *)(puVar13 + 9);
            p4 = (ushort *)CONCAT22((short)((uint)uVar9 >> 0x10),uVar1);
            *(undefined2 *)(puVar13 + 9) = *(undefined2 *)((int)puVar13 + 0x26);
            *(undefined2 *)((int)puVar13 + 0x26) = uVar1;
            puVar13 = puVar13 + 10;
          }
        }
      }
      f_173374();
      f_173d0c(local_4c);
      if ((DAT_001a9932 != '\0') && (((byte)DAT_001a9a1c & 4) != 0)) {
        local_1c = f_1739e8(local_4c,puVar10,puVar12,p4);
      }
      if (DAT_001a994c != '\0') {
        if (DAT_001d122d == 0) {
          puVar12 = &DAT_001c9588;
          p4 = (ushort *)0x0;
          do {
            puVar10 = (ushort *)
                      ((int)((uint)*(ushort *)(puVar12 + 2) - (uint)*(ushort *)(puVar12 + 0x642)) >>
                      0x1f);
            if (2 < (int)(((uint)*(ushort *)(puVar12 + 2) - (uint)*(ushort *)(puVar12 + 0x642) ^
                          (uint)puVar10) - (int)puVar10)) {
              DAT_001d122d = 1;
              break;
            }
            p4 = (ushort *)((int)p4 + 1);
            puVar12 = puVar12 + ((DAT_001d1224 - DAT_001d1228) + 1 >> 3) * 5;
          } while ((int)p4 < 8);
        }
        if (DAT_001a9af8 < *(int *)(local_4c + 0x20)) {
          f_17410c();
        }
      }
      uVar11 = CONCAT31((int3)((uint)puVar10 >> 8),DAT_001d122e);
      bVar14 = DAT_001d122e != '\0';
      if ((bool)bVar14) {
        uVar11 = 1;
        *(byte *)(local_4c + 1) = (byte)local_4c[1] | 4;
      }
      if (local_1c != '\0') {
        puVar12 = (undefined4 *)
                  (CONCAT22((short)((uint)puVar12 >> 0x10),CONCAT11(bVar14,(char)puVar12)) | 0x200);
        p4 = (ushort *)(CONCAT31((int3)((uint)p4 >> 8),(char)local_4c[1]) | 8);
        bVar14 = (byte)((uint)puVar12 >> 8);
        *(char *)(local_4c + 1) = (char)p4;
      }
      if (DAT_001d122d != 0) {
        bVar14 = bVar14 | 4;
        *(byte *)(local_4c + 1) = (byte)local_4c[1] | 2;
      }
      local_58 = (uint)bVar14;
      if (((*((uint8_t *)((char *)&(DAT_001a9a1c) + 1))) & 0x20) == 0) {
        iVar4 = DAT_001a9988;
        if (DAT_001a9984 < DAT_001a9988) {
          iVar4 = DAT_001a9984;
        }
        DAT_001d11b8 = iVar4 / 5;
        local_3c = (DAT_001d1220 - DAT_001d121c) / DAT_001d11b8;
        if ((((((*((uint8_t *)((char *)&(DAT_001a9a1c) + 2))) & 2) == 0) || ((DAT_001d1230 & DAT_001d122d) == 0)) ||
            (DAT_001a994c != '\0')) || (local_3c < 1)) {
          f_1744c8(local_4c,local_58,0,DAT_001d121c);
        }
        else {
          local_40 = DAT_001d1228;
          DAT_001d11c4 = 0x7fff;
          local_50 = DAT_001d121c + -1;
          local_34 = DAT_001d121c + DAT_001d11b8;
          DAT_001d1208 = -0x8000;
          uStack_2c = 0;
          iVar4 = 0;
          if (-1 < local_3c) {
            do {
              p4_00 = local_a0;
              uStack_2c = iVar4;
              local_54 = f_174158(local_50,local_34,auStack_c8,p4_00);
              local_50 = local_34;
              local_34 = local_34 + DAT_001d11b8;
              local_30 = local_a4 >> 0x10;
              local_48 = local_7c >> 0x10;
              if ((local_54 != 0) && (uStack_2c < local_3c) && (local_48 >= local_30) && (local_48 - local_30 < 320)) {
                local_38 = ((local_48 - local_30) + 1) * 0x14;
                unaff_EBP = &DAT_001c9588 + ((local_30 - local_40) + 0x140) * 5;
                puVar12 = unaff_EBP;
                puVar13 = &DAT_001d1234;
                DAT_001d11b0 = unaff_EBP;
                for (uVar5 = local_38 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *puVar13 = *puVar12;
                  puVar12 = puVar12 + 1;
                  puVar13 = puVar13 + 1;
                }
                for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                  puVar13 = (undefined4 *)((int)puVar13 + 1);
                }
                DAT_001d11cc = local_a0;
                DAT_001d11c8 = auStack_c8;
                f_173290();
                p4_00 = (undefined1 *)0x0;
              }
              DAT_001d1228 = DAT_001d11c4;
              DAT_001d1224 = DAT_001d1208;
              f_1744c8(local_4c,local_58,DAT_001d11c4 - local_40,p4_00);
              if ((local_54 != 0) && (uStack_2c < local_3c) && (local_48 >= local_30) && (local_48 - local_30 < 320)) {
                puVar12 = unaff_EBP;
                puVar13 = &DAT_001c9588 + (local_30 - local_40) * 5;
                for (uVar5 = local_38 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *puVar13 = *puVar12;
                  puVar12 = puVar12 + 1;
                  puVar13 = puVar13 + 1;
                }
                for (uVar5 = local_38 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                  puVar13 = (undefined4 *)((int)puVar13 + 1);
                }
                puVar12 = &DAT_001d1234;
                puVar13 = unaff_EBP;
                for (uVar5 = local_38 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *puVar13 = *puVar12;
                  puVar12 = puVar12 + 1;
                  puVar13 = puVar13 + 1;
                }
                for (uVar5 = local_38 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                  puVar13 = (undefined4 *)((int)puVar13 + 1);
                }
                DAT_001d11c4 = local_30;
                DAT_001d1208 = local_48;
              }
              uStack_2c = uStack_2c + 1;
              iVar4 = uStack_2c;
            } while (uStack_2c <= local_3c);
          }
        }
      }
      else {
        uVar9 = CONCAT31((int3)((uint)p4 >> 8),DAT_001d122e);
        if (DAT_001d122e == '\0') {
          f_175839(DAT_001d120c & 0xff,uVar11,puVar12,uVar9);
        }
        else {
          f_1758bc(DAT_001d120c & 0xff,uVar11,puVar12,uVar9);
        }
      }
      iVar4 = f_16fc19();
      DAT_001a9a70 = DAT_001a9a70 + iVar4;
    }
  }
  #undef local_a4
  #undef local_7c
  return;
}




/* ==== 176891-1768A2  (nach Attic)  fremd? ==== */




undefined1 f_176891(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return 0;
}




/* ==== 1768A2-1768B3  (nach Attic)  fremd? ==== */


undefined1 f_1768a2(undefined4 p1,undefined4 p2)

{
  char cVar1;
  
  cVar1 = f_1768b3(p1,CONCAT22((short)((uint)p2 >> 0x10),0x3d4));
  if (cVar1 == '\0') {
    return 0;
  }
  return 2;
}




/* ==== 1768B3-1768D5  (nach Attic)  fremd? ==== */


int f_1768b3(undefined4 p1,undefined4 p2)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  
  out((short)p2,0xf);
  sVar4 = (short)p2 + 1;
  uVar1 = in(sVar4);
  out(sVar4,0x50);
  sVar3 = 300;
  do {
    sVar3 = sVar3 + -1;
  } while (sVar3 != 0);
  cVar2 = in(sVar4);
  out(sVar4,uVar1);
  return (cVar2 == 'P') ? 1 : 0;
}




/* ==== 1768D5-17695F  (nach Attic)  fremd? ==== */


undefined4 f_1768d5(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  undefined1 uVar1;
  char cVar4;
  undefined4 uVar2;
  uint uVar3;
  undefined3 uVar5;
  int iVar6;
  
  uVar2 = f_1768b3(p1,CONCAT22((short)((uint)p2 >> 0x10),0x3b4));
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar1 = in(0x3ba);
  uVar3 = CONCAT31((int3)((uint)uVar2 >> 8),uVar1) & 0xffffff80;
  uVar3 = (uint)CONCAT21((short)(uVar3 >> 0x10),(char)uVar3) << 8;
  iVar6 = CONCAT22((short)((uint)p4 >> 0x10),0x9000);
  do {
    uVar1 = in(0x3ba);
    uVar3 = CONCAT31((int3)(uVar3 >> 8),uVar1) & 0xffffff80;
    cVar4 = (char)(uVar3 >> 8);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0 && cVar4 == (char)uVar3);
  uVar5 = (undefined3)(uVar3 >> 8);
  if (cVar4 == (char)uVar3) {
    return CONCAT31(uVar5,1);
  }
  return CONCAT31(uVar5,3);
}




/* ==== 1769C0-1769E0  (nach Attic)  fremd? ==== */


short f_1769c0(undefined4 p1,undefined4 p2,undefined4 p3)

{
  if ((short)p3 != 0) {
    if ((short)p2 == 0x58) {
      (*((int16_t *)((char *)&(p2) + 0))) = 0x56;
    }
    else {
      (*((int16_t *)((char *)&(p2) + 0))) = 0xba;
    }
  }
  return (short)p2;
}




/* ==== 1769E0-176A38  (nach Attic)  fremd? ==== */


undefined4 f_1769e0(undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  byte bVar1;
  int iVar2;
  
  do {
    bVar1 = in(0x3da);
  } while ((bVar1 & 8) != 0);
  do {
    bVar1 = in(0x3da);
  } while ((bVar1 & 8) == 0);
  iVar2 = 0x28;
  do {
    do {
      bVar1 = in(0x3da);
    } while ((bVar1 & 1) != 0);
    do {
      bVar1 = in(0x3da);
    } while ((bVar1 & 1) == 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return p1;
}




/* ==== 176A38-176B18  (nach Attic)  fremd? ==== */


int f_176a38(int p1,char *p2,undefined4 *p3,int p4)

{
  char cVar1;
  undefined4 *p1_00;
  int iVar2;
  int p4_00;
  char *p2_00;
  undefined4 *puVar3;
  
  for (; cVar1 = *p2, p2_00 = p2, cVar1 == '/'; p2 = p2 + 1) {
  }
  for (; (cVar1 != '\0' && (*p2_00 != '/')); p2_00 = p2_00 + 1) {
    cVar1 = p2_00[1];
  }
  for (; *p2_00 == '/'; p2_00 = p2_00 + 1) {
  }
  p1_00 = *(undefined4 **)(p1 + 8);
  p4_00 = p4;
  while ((p1_00 != (undefined4 *)0x0 && (0 < p4_00))) {
    iVar2 = f_187b30(p2,p1_00[5]);
    puVar3 = p3;
    if (iVar2 != 0) {
      if (*p2_00 == '\0') {
        puVar3 = p3 + 1;
        p4_00 = p4_00 + -1;
        *p3 = p1_00;
      }
      else {
        iVar2 = f_176a38((int)p1_00,p2_00,p3,p4_00);
        puVar3 = p3 + iVar2;
        p4_00 = p4_00 - iVar2;
      }
    }
    p1_00 = (undefined4 *)*p1_00;
    p3 = puVar3;
  }
  return p4 - p4_00;
}




/* ==== 176B18-176B3C  (nach Attic)  fremd? ==== */


void f_176b18(int p1,int p2)

{
  int *p1_00;
  
  p1_00 = *(int **)(p1 + 8);
  *(short *)(p1 + 0x10) = (short)p2;
  if (p1_00 != (int *)0x0) {
    do {
      f_176b18((int)p1_00,p2 + 1);
      p1_00 = (int *)*p1_00;
    } while (p1_00 != (int *)0x0);
  }
  return;
}




/* ==== 176B3C-176B90  (nach Attic)  fremd? ==== */


int f_176b3c(int p1,int p2)

{
  ushort uVar1;
  undefined4 *puVar2;
  int *p1_00;
  
  f_187ecc(p1 + 8,p2);
  *(int *)(p2 + 0xc) = p1;
  puVar2 = *(undefined4 **)(p2 + 8);
  *(short *)(p2 + 0x10) = *(short *)(p1 + 0x10) + 1;
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    uVar1 = *(ushort *)(p2 + 0x10);
    p1_00 = (int *)puVar2[2];
    *(ushort *)(puVar2 + 4) = uVar1 + 1;
    if (p1_00 != (int *)0x0) {
      do {
        f_176b18(p1_00,uVar1 + 2);
        p1_00 = (int *)*p1_00;
      } while (p1_00 != (int *)0x0);
    }
  }
  return p2;
}




/* ==== 176B90-176D78  (nach Attic)  fremd? ==== */


int f_176b90(int p1)

{
  undefined4 *puVar1;
  undefined4 *p1_00;
  
  f_187f2c(p1);
  puVar1 = *(undefined4 **)(p1 + 8);
  *(undefined2 *)(p1 + 0x10) = 0;
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    *(undefined2 *)(puVar1 + 4) = 1;
    for (p1_00 = (undefined4 *)puVar1[2]; p1_00 != (undefined4 *)0x0; p1_00 = (undefined4 *)*p1_00)
    {
      f_176b18(p1_00,2);
    }
  }
  return p1;
}




/* ==== 176D78-176DA0  (nach Attic)  fremd? ==== */


void f_176d78(int p1)

{
  int iVar1;
  undefined4 p1_00;
  
  iVar1 = *(int *)(p1 + 8);
  while (iVar1 != 0) {
    p1_00 = f_187f2c(*(undefined4 *)(p1 + 8));
    f_176d78(p1_00);
    iVar1 = *(int *)(p1 + 8);
  }
  f_18850c(p1);
  return;
}




/* ==== 176DA0-176E24  (nach Attic)  fremd? ==== */


void f_176da0(int p1)

{
  int iVar1;
  undefined4 p1_00;
  
  iVar1 = *(int *)(p1 + 8);
  while (iVar1 != 0) {
    p1_00 = f_187f2c(*(undefined4 *)(p1 + 8));
    f_176d78(p1_00);
    iVar1 = *(int *)(p1 + 8);
  }
  f_18850c(p1);
  return;
}




/* ==== 176E24-176F10  (nach Attic)  fremd? ==== */




undefined4 f_176e24(undefined4 p1,int p2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_44 [48];
  
  iVar2 = *(int *)(p2 + 0x58);
  bVar1 = *(byte *)(iVar2 + 4);
  if (bVar1 == 0) {
    f_16bc6c(auStack_44,(int)(0x100000000 / (longlong)*(int *)(iVar2 + 0x14)),
             (int)(0x100000000 / (longlong)*(int *)(iVar2 + 0x18)),
             (int)(0x100000000 / (longlong)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8))));
    f_16cd48(auStack_44,0,0,*(undefined4 *)(iVar2 + 8));
    f_189a0c(p1,auStack_44);
LAB_00176eb8:
    uVar3 = 0;
  }
  else {
    if (bVar1 < 2) {
      f_189284(p1,(uint)*(ushort *)(iVar2 + 6),*(undefined4 *)(iVar2 + 0x10),-*(int *)(iVar2 + 8),
               -*(int *)(iVar2 + 0xc));
    }
    else if (bVar1 != 2) goto LAB_00176eb8;
    uVar3 = 1;
  }
  return uVar3;
}




/* ==== 15FFA0-15FFFC  (nach Attic)  fremd? ==== */


undefined4 f_15ffa0(char *p1)

{
  if (*(short *)(p1 + 6) != 0) {
    return 1;
  }
  if (*(int *)(p1 + 0x10) != 0) {
    return 1;
  }
  if ((*(ushort *)(p1 + 10) & 0x360) != 0) {
    return 1;
  }
  if (*p1 == '\0') {
    return 1;
  }
  return 0;
}




/* ==== 15FFFC-160320  (nach Attic)  fremd? ==== */




undefined4 f_15fffc(undefined4 *p1,int *p2)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int iVar12;
  int local_18;
  
  if (DAT_001a993d == '\0') {
    uVar3 = 0xf002;
    _DAT_001a996c = 0xf002;
  }
  else {
    if (DAT_001a9940 == '\0') {
      _DAT_001a996c = 0xf00c;
      return 0xf00c;
    }
    if ((p1 == (undefined4 *)0x0) || (p2 == (int *)0x0)) {
      _DAT_001a996c = 0xf005;
      return 0xf005;
    }
    iVar5 = 0;
    local_18 = 0;
    pcVar6 = DAT_001cd210;
    if (0 < DAT_001a99ac) {
      do {
        iVar4 = f_15ffa0(pcVar6);
        if (iVar4 != 0) {
          local_18 = local_18 + 1;
        }
        iVar5 = iVar5 + 1;
        pcVar6 = pcVar6 + 0x30;
      } while (iVar5 < DAT_001a99ac);
    }
    pcVar6 = (char *)f_156370(local_18 * 0x1c + 0x1f0, (const char *)(&riva_dgroup_base[0x1b9664 - 0x1a0000]), (const char *)(&riva_dgroup_base[0x1b9658 - 0x1a0000]), 10);
    if (pcVar6 == (char *)0x0) {
      _DAT_001a996c = 0xf001;
      return 0xf001;
    }
    pcVar8 = pcVar6 + 0x88;
    pcVar9 = &DAT_001cd088;
    pcVar11 = pcVar6;
    do {
      cVar1 = *pcVar9;
      *pcVar11 = cVar1;
      if (cVar1 == '\0') break;
      cVar1 = pcVar9[1];
      pcVar9 = pcVar9 + 2;
      pcVar11[1] = cVar1;
      pcVar11 = pcVar11 + 2;
    } while (cVar1 != '\0');
    uVar2 = DAT_001a996a;
    pcVar6[0x24] = -0x40;
    pcVar6[0x25] = '4';
    pcVar6[0x26] = '\x0e';
    pcVar6[0x27] = '5';
    *(undefined2 *)(pcVar6 + 0x1e) = uVar2;
    *(undefined4 *)(pcVar6 + 0x28) = DAT_001a9aec;
    *(undefined4 *)(pcVar6 + 0x2c) = DAT_001a9af0;
    *(undefined4 *)(pcVar6 + 0x30) = DAT_001a9b18;
    *(short *)(pcVar6 + 0x20) = (short)local_18;
    *(undefined2 *)(pcVar6 + 0x22) = (undefined2)DAT_001a99ac;
    uVar2 = DAT_001a9970;
    puVar10 = &DAT_001c90c0;
    pcVar11 = pcVar6 + 0x34;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined4 *)pcVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      pcVar11 = pcVar11 + 4;
    }
    *(undefined2 *)(pcVar6 + 0x58) = uVar2;
    *(int *)(pcVar6 + 0x4c) = (int)pcVar8 - (int)pcVar6;
    *(undefined4 *)(pcVar6 + 0x5c) = DAT_001a9a1c;
    *(undefined **)(pcVar6 + 0x60) = PTR_LAB_001a9afc;
    *(undefined **)(pcVar6 + 100) = PTR_DAT_001a9ae0;
    *(undefined4 *)(pcVar6 + 0x68) = DAT_001a9b34;
    *(undefined4 *)(pcVar6 + 0x6c) = DAT_001a9b40;
    *(undefined2 *)(pcVar6 + 0x70) = (undefined2)DAT_001a9984;
    iVar4 = DAT_001cd1f8;
    *(undefined2 *)(pcVar6 + 0x72) = (undefined2)DAT_001a9988;
    *(undefined2 *)(pcVar6 + 0x74) = DAT_001cdc22;
    *(undefined2 *)(pcVar6 + 0x76) = DAT_001cdc24;
    pcVar6[0x7c] = '\0';
    pcVar6[0x7d] = '\0';
    pcVar6[0x7e] = '\0';
    pcVar6[0x7f] = '\0';
    pcVar6[0x80] = '\0';
    iVar5 = DAT_001a99ac;
    pcVar6[0x81] = '\0';
    pcVar6[0x82] = '\0';
    pcVar6[0x83] = '\0';
    pcVar6[0x84] = '\0';
    pcVar11 = DAT_001cd210;
    pcVar6[0x85] = '\0';
    pcVar6[0x86] = '\0';
    pcVar6[0x87] = '\0';
    iVar12 = 0;
    *(short *)(pcVar6 + 0x78) = (short)(((int)iVar4 - (int)(uintptr_t)(&DAT_001c6c78)) / 0x18);
    if (0 < iVar5) {
      pcVar9 = pcVar6 + 0x89;
      pcVar7 = pcVar8;
      do {
        iVar5 = f_15ffa0(pcVar11);
        pcVar8 = pcVar7;
        if (iVar5 != 0) {
          f_148143(pcVar9,**(undefined4 **)(pcVar11 + 0x28),10);
          pcVar7[0xb] = '\0';
          pcVar7[0xc] = *pcVar11;
          *(undefined2 *)(pcVar7 + 0xe) = *(undefined2 *)(pcVar11 + 6);
          *(undefined2 *)(pcVar7 + 0x14) = *(undefined2 *)(pcVar11 + 0xc);
          *(undefined2 *)(pcVar7 + 0x12) = *(undefined2 *)(pcVar11 + 10);
          *(undefined2 *)(pcVar7 + 0x10) = *(undefined2 *)(pcVar11 + 2);
          pcVar8 = pcVar7 + 0x1c;
          pcVar9 = pcVar9 + 0x1c;
          *(undefined4 *)(pcVar7 + 0x18) = *(undefined4 *)(pcVar11 + 0x10);
        }
        iVar12 = iVar12 + 1;
        pcVar11 = pcVar11 + 0x30;
        pcVar7 = pcVar8;
      } while (iVar12 < DAT_001a99ac);
    }
    *(int *)(pcVar6 + 0x50) = (int)pcVar8 - (int)pcVar6;
    pcVar11 = (char *)&DAT_001c6c78;
    pcVar9 = pcVar8;
    for (iVar5 = 0x3c; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (iVar5 = 0; iVar4 = DAT_001cd1e0, iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar9 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar9 = pcVar9 + 1;
    }
    pcVar8 = pcVar8 + 0xf0;
    *(int *)(pcVar6 + 0x54) = (int)pcVar8 - (int)pcVar6;
    iVar5 = 0;
    do {
      *pcVar8 = *(char *)(iVar4 + 4);
      pcVar8[1] = *(char *)(iVar4 + 5);
      pcVar8[2] = *(char *)(iVar4 + 6);
      *(undefined2 *)(pcVar8 + 4) = *(undefined2 *)(iVar4 + 10);
      *(undefined4 *)(pcVar8 + 8) = *(undefined4 *)(iVar4 + 0x10);
      *(undefined4 *)(pcVar8 + 0xc) = *(undefined4 *)(iVar4 + 0x18);
      if (*(char *)(iVar4 + 5) == '\x02') {
        *(undefined4 *)(pcVar8 + 0x10) = *(undefined4 *)(iVar4 + 0x3c);
        *(undefined4 *)(pcVar8 + 0x14) = *(undefined4 *)(iVar4 + 0x40);
        *(undefined4 *)(pcVar8 + 0x18) = *(undefined4 *)(iVar4 + 0x44);
        puVar10 = (undefined4 *)(iVar4 + 0x48);
      }
      else {
        *(undefined4 *)(pcVar8 + 0x10) = *(undefined4 *)(iVar4 + 0x24);
        *(undefined4 *)(pcVar8 + 0x14) = *(undefined4 *)(iVar4 + 0x28);
        *(undefined4 *)(pcVar8 + 0x18) = *(undefined4 *)(iVar4 + 0x2c);
        puVar10 = (undefined4 *)(iVar4 + 0x30);
      }
      *(undefined4 *)(pcVar8 + 0x1c) = *puVar10;
      *(undefined4 *)(pcVar8 + 0x20) = puVar10[1];
      *(undefined4 *)(pcVar8 + 0x24) = puVar10[2];
      pcVar8 = pcVar8 + 0x28;
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x58;
    } while (iVar5 < 3);
    *p1 = pcVar6;
    _DAT_001a996c = 0;
    *p2 = local_18 * 0x1c + 0x1f0;
    uVar3 = 0;
  }
  return uVar3;
}




/* ==== 160320-160790  (nach Attic)  fremd? ==== */




undefined4 f_160320(int p1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char *pcVar13;
  int *piVar14;
  int local_20;
  undefined1 *local_1c;
  
  if (DAT_001a993d == '\0') {
    uVar2 = 0xf002;
    _DAT_001a996c = 0xf002;
  }
  else {
    if (DAT_001a9940 == '\0') {
      _DAT_001a996c = 0xf00c;
      return 0xf00c;
    }
    if (p1 == 0) {
      _DAT_001a996c = 0xf005;
      uVar2 = 0xf005;
    }
    else {
      iVar3 = *(int *)(p1 + 0x24);
      if (((((iVar3 != 0x75bcd15) && (iVar3 != 0xdfb38d2)) && (iVar3 != 0x149aa435)) &&
          ((iVar3 != 0x1b3a0c14 && (iVar3 != 0x21d950cb)))) &&
         ((iVar3 != 0x287735f2 && ((iVar3 != 0x2f075f79 && (iVar3 != 0x350e34c0)))))) {
        _DAT_001a996c = 0xf00f;
        return 0xf00f;
      }
      iVar3 = f_144bf0((const char *)p1, (const char *)(&DAT_001cd088));
      if (iVar3 != 0) {
        _DAT_001a996c = 0xf00e;
        return 0xf00e;
      }
      if (*(uint *)(p1 + 0x24) < 0x149aa435) {
        puVar4 = (undefined4 *)(p1 + 0x34);
        puVar10 = &DAT_001c90c0;
        for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar10 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar10 = puVar10 + 1;
        }
        f_155f70(&DAT_001c90c0);
        DAT_001a9933 = 1;
        DAT_001a99f0 = 0;
        _DAT_001a996c = 0xf00f;
        return 0xf00f;
      }
      puVar4 = (undefined4 *)(*(int *)(p1 + 0x50) + p1);
      local_1c = (undefined1 *)(*(int *)(p1 + 0x54) + p1);
      pcVar5 = (char *)(*(int *)(p1 + 0x4c) + p1);
      DAT_001a996a = *(undefined2 *)(p1 + 0x1e);
      DAT_001a9aec = *(undefined4 *)(p1 + 0x28);
      DAT_001a9af0 = *(undefined4 *)(p1 + 0x2c);
      DAT_001a9b18 = *(undefined4 *)(p1 + 0x30);
      puVar10 = (undefined4 *)(p1 + 0x34);
      puVar12 = &DAT_001c90c0;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      _DAT_001a9970 = (uint)*(ushort *)(p1 + 0x58);
      if (0x1b3a0c13 < *(uint *)(p1 + 0x24)) {
        DAT_001a9a1c = *(undefined4 *)(p1 + 0x5c);
        PTR_LAB_001a9afc = *(undefined **)(p1 + 0x60);
      }
      if (0x21d950ca < *(uint *)(p1 + 0x24)) {
        PTR_DAT_001a9ae0 = *(undefined **)(p1 + 100);
      }
      if (0x287735f1 < *(uint *)(p1 + 0x24)) {
        DAT_001a9b34 = *(undefined4 *)(p1 + 0x68);
        DAT_001a9b40 = *(undefined4 *)(p1 + 0x6c);
      }
      if (0x2f075f78 < *(uint *)(p1 + 0x24)) {
        f_164880(*(int *)(p1 + 0x6e) >> 0x10,*(int *)(p1 + 0x70) >> 0x10,*(int *)(p1 + 0x72) >> 0x10
                 ,*(int *)(p1 + 0x74) >> 0x10);
      }
      pcVar13 = DAT_001cd210;
      if (0x350e34bf < *(uint *)(p1 + 0x24)) {
        DAT_001cd1f8 = &DAT_001c6c78 + ((uint)*(ushort *)(p1 + 0x78) % 10) * 6;
      }
      uVar9 = (uint)*(ushort *)(p1 + 0x20);
      iVar3 = 0;
      pcVar7 = pcVar5;
      if (uVar9 != 0) {
        do {
          iVar3 = iVar3 + 1;
          *pcVar7 = '\0';
          pcVar7 = pcVar7 + 0x1c;
        } while (iVar3 < (int)uVar9);
      }
      local_20 = 0;
      if (0 < DAT_001a99ac) {
        do {
          iVar3 = 0;
          bVar1 = true;
          if (0 < (int)uVar9) {
            pcVar7 = pcVar5 + 1;
            pcVar11 = pcVar5;
            do {
              if ((((*pcVar11 == '\0') &&
                   (iVar3 = iVar3 + 1, *(short *)(pcVar11 + 0x10) == *(short *)(pcVar13 + 2))) &&
                  (*(int *)(pcVar13 + 0x28) != 0)) &&
                 (iVar6 = f_144bf0((const char *)pcVar7, (const char *)**(uint32_t **)(pcVar13 + 0x28)), iVar6 == 0)) {
                *pcVar13 = pcVar11[0xc];
                *(undefined2 *)(pcVar13 + 10) = *(undefined2 *)(pcVar11 + 0x12);
                *(undefined4 *)(pcVar13 + 0x10) = *(undefined4 *)(pcVar11 + 0x18);
                *(undefined2 *)(pcVar13 + 6) = *(undefined2 *)(pcVar11 + 0xe);
                uVar9 = uVar9 - 1;
                *(undefined2 *)(pcVar13 + 0xc) = *(undefined2 *)(pcVar11 + 0x14);
                bVar1 = false;
                *pcVar11 = '\x01';
                break;
              }
              pcVar7 = pcVar7 + 0x1c;
              pcVar11 = pcVar11 + 0x1c;
            } while (iVar3 < (int)uVar9);
          }
          if (bVar1) {
            pcVar13[0x10] = '\0';
            pcVar13[0x11] = '\0';
            pcVar13[0x12] = '\0';
            pcVar13[0x13] = '\0';
            *pcVar13 = '\x01';
            pcVar13[6] = '\0';
            pcVar13[7] = '\0';
            *(ushort *)(pcVar13 + 10) = *(ushort *)(pcVar13 + 10) & 0xfc9f;
          }
          local_20 = local_20 + 1;
          pcVar13 = pcVar13 + 0x30;
        } while (local_20 < DAT_001a99ac);
      }
      if (puVar4 != (undefined4 *)0x0) {
        puVar10 = &DAT_001c6c78;
        for (iVar3 = 0x3c; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar10 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar10 = puVar10 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
      }
      if ((local_1c != (undefined1 *)0x0) && (DAT_001cd1e0 != 0)) {
        iVar3 = 0;
        piVar8 = (int *)DAT_001cd1e0;
        do {
          *(undefined1 *)(piVar8 + 1) = *local_1c;
          *(undefined1 *)((int)piVar8 + 5) = local_1c[1];
          *(undefined1 *)((int)piVar8 + 6) = local_1c[2];
          *(undefined2 *)((int)piVar8 + 10) = *(undefined2 *)(local_1c + 4);
          piVar8[4] = *(int *)(local_1c + 8);
          piVar8[6] = *(int *)(local_1c + 0xc);
          if (*(char *)((int)piVar8 + 5) == '\x02') {
            piVar8[0xf] = *(int *)(local_1c + 0x10);
            piVar8[0x10] = *(int *)(local_1c + 0x14);
            piVar8[0x11] = *(int *)(local_1c + 0x18);
            if (((0x21d950ca < *(uint *)(p1 + 0x24)) || (*(char *)((int)piVar8 + 6) != '\x01')) ||
               (*piVar8 == 0)) {
              piVar14 = piVar8 + 0x12;
              goto LAB_00160740;
            }
            uVar9 = f_165de2();
            piVar8[0x13] = 0;
            piVar8[0x12] = uVar9 & 3;
            piVar8[0x14] = (uint)*(ushort *)((int)piVar8 + 10);
          }
          else {
            piVar8[9] = *(int *)(local_1c + 0x10);
            piVar8[10] = *(int *)(local_1c + 0x14);
            piVar8[0xb] = *(int *)(local_1c + 0x18);
            piVar14 = piVar8 + 0xc;
LAB_00160740:
            *piVar14 = *(int *)(local_1c + 0x1c);
            piVar14[1] = *(int *)(local_1c + 0x20);
            piVar14[2] = *(int *)(local_1c + 0x24);
          }
          piVar8 = piVar8 + 0x16;
          local_1c = local_1c + 0x28;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 3);
      }
      f_155f70(&DAT_001c90c0);
      DAT_001a9933 = 1;
      _DAT_001a996c = 0;
      uVar2 = 0;
      DAT_001a99f0 = 0;
    }
  }
  return uVar2;
}




/* ==== 160D18-160D8C  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 160D8C-160E94  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 160E94-160F64  (nach Attic)  fremd? ==== */




undefined4 f_160e94(undefined4 *p1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (p1 == (undefined4 *)0x0) {
    uVar2 = 0xf005;
    _DAT_001a996c = 0xf005;
  }
  else {
    if (p1[7] == 0) {
      _DAT_001a996c = 0xf00c;
      return 0xf00c;
    }
    iVar1 = p1[2];
    iVar3 = p1[0xc];
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        if (((*(byte *)(iVar3 + 0xe) & 4) != 0) && (*(int *)(iVar3 + 0x2c) != 0)) {
          f_1782e8(*(int *)(iVar3 + 0x2c));
          *(undefined4 *)(iVar3 + 0x2c) = 0;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x34;
      } while (iVar4 < iVar1);
    }
    f_1563a8(p1[7]);
    f_163e00();
    *p1 = 0;
    p1[1] = 0;
    p1[2] = 0;
    p1[4] = 0;
    __asm__ __volatile__("nop");
    p1[5] = 0;
    p1[6] = 0;
    p1[7] = 0;
    p1[9] = 0;
    p1[10] = 0;
    p1[0xb] = 0;
    p1[0xc] = 0;
    uVar2 = 0;
    _DAT_001a996c = 0;
  }
  return uVar2;
}




/* ==== 160F64-161230  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 161230-161328  (nach Attic)  fremd? ==== */




undefined4 f_161230(int p1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = DAT_001cd210;
  if (0 < DAT_001a99ac) {
    do {
      uVar1 = *(ushort *)(iVar6 + 2);
      if ((((uVar1 != 0) && (uVar1 < 0x2329)) &&
          (((uint)*(byte *)(((int)(uint)uVar1 >> 3) + p1) &
           1 << ((byte)*(undefined2 *)(iVar6 + 2) & 7)) != 0)) &&
         (iVar5 = iVar4 + 1, iVar2 = iVar6, iVar5 < DAT_001a99ac)) {
        do {
          if ((*(short *)(iVar6 + 2) == *(short *)(iVar2 + 0x32)) &&
             (iVar3 = f_15f1dc
                                (**(undefined4 **)(iVar6 + 0x28),**(undefined4 **)(iVar2 + 0x58),7),
             iVar3 != 0)) {
            
            _DAT_001cdb90 = &DAT_001ccf88;
            return 1;
          }
          iVar5 = iVar5 + 1;
          iVar2 = iVar2 + 0x30;
        } while (iVar5 < DAT_001a99ac);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x30;
    } while (iVar4 < DAT_001a99ac);
  }
  return 0;
}




/* ==== 161E84-161FD8  (nach Attic)  fremd? ==== */




undefined4 f_161e84(int in_EAX)

{
  undefined4 uVar1;
  
  if (DAT_001a993d == '\0') {
    _DAT_001a996c = 0xf002;
    uVar1 = 0xf002;
    _DAT_001cdb90 = s_FreeSceneryData__3DM_not_yet_ini_001b98c4;
  }
  else {
    if (DAT_001a9940 == '\0') {
      _DAT_001cdb90 = s_FreeSceneryData__No_Scenery_load_001b98f0;
      _DAT_001a996c = 0xf00c;
      return 0xf00c;
    }
    if ((in_EAX == 1) && (DAT_001a9928 != 0)) {
      f_1563a8(DAT_001a9928);
      DAT_001a9928 = 0;
    }
    if (DAT_001a992c != 0) {
      f_1563a8(DAT_001a992c);
      _DAT_001a9a30 = 0;
      DAT_001a992c = 0;
    }
    if (DAT_001a9d20 != 0) {
      f_1782e8(DAT_001a9d20);
      DAT_001a9d20 = 0;
    }
    f_160e94(&DAT_001cd1b4);
    f_156698();
    f_15666c();
    if (DAT_001cd300 != 0) {
      f_1782e8(DAT_001cd300);
      DAT_001cd300 = 0;
    }
    uVar1 = 0;
    DAT_001a9a38 = 0;
    DAT_001a99ac = 0;
    _DAT_001a99b4 = 0;
    DAT_001a99b0 = 0;
    DAT_001a99b8 = 0;
    DAT_001a99bc = 0;
    _DAT_001a99c0 = 0;
    _DAT_001a99c4 = 0;
    DAT_001a99c8 = 0;
    _DAT_001a99cc = 0;
    _DAT_001a99d0 = 0;
    _DAT_001a99d4 = 0;
    _DAT_001a99d8 = 0;
    DAT_001a9a4c = 0;
    _DAT_001a9a50 = 0;
    _DAT_001a9a54 = 0;
    _DAT_001a9a58 = 0;
    _DAT_001a996c = 0;
    DAT_001a993f = 1;
  }
  return uVar1;
}




/* ==== 161FD8-162208  (nach Attic)  fremd? ==== */




int f_161fd8(char *p1,char *p2,char *unaff_EBX,int unaff_CL)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  _DAT_001cdb90 = 0;
  if (DAT_001a993d == '\0') {
    f_163050(s_LoadScenery__3DM_not_yet_initial_001b9914);
    _DAT_001a996c = 0xf002;
    return 0xf002;
  }
  if (DAT_001a9940 != '\0') {
    f_163050(s_LoadScenery__Scenery_already_loa_001b993c);
    _DAT_001a996c = 0xf00d;
    return 0xf00d;
  }
  if (p1 == (char *)0x0) {
    f_163050(s_LoadScenery__Directory_name_miss_001b9960);
    _DAT_001a996c = 0xf005;
    return 0xf005;
  }
  if (p2 == (char *)0x0) {
    f_163050(s_LoadScenery__Scenery_name_missin_001b9984);
    _DAT_001a996c = 0xf005;
    return 0xf005;
  }
  pcVar3 = &DAT_001cd088;
  DAT_001a994a = unaff_CL;
  do {
    cVar1 = *p2;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = p2[1];
    p2 = p2 + 2;
    pcVar3[1] = cVar1;
    pcVar3 = pcVar3 + 2;
  } while (cVar1 != '\0');
  pcVar3 = &DAT_001cd0b0;
  do {
    cVar1 = *p1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = p1[1];
    p1 = p1 + 2;
    pcVar3[1] = cVar1;
    pcVar3 = pcVar3 + 2;
  } while (cVar1 != '\0');
  if (unaff_EBX != (char *)0x0) {
    pcVar3 = &DAT_001cdc00;
    do {
      cVar1 = *unaff_EBX;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      cVar1 = unaff_EBX[1];
      unaff_EBX = unaff_EBX + 2;
      pcVar3[1] = cVar1;
      pcVar3 = pcVar3 + 2;
    } while (cVar1 != '\0');
  }
  DAT_001a9940 = 1;
  DAT_001a993f = 1;
  iVar2 = f_161328();
  if (iVar2 == 0) {
    DAT_001a993f = 0;
    DAT_001a9944 = 0;
    DAT_001a9942 = 1;
    DAT_001a9945 = 1;
    DAT_001a9933 = 1;
    DAT_001a993c = 0;
    DAT_001a9949 = 0;
    DAT_001a9962 = 0xffff;
    DAT_001a996a = 0xffff;
    if (DAT_001a9d24 == 0) {
      DAT_001c90c4 = DAT_001a9d24;
      DAT_001c90c8 = DAT_001a9d24;
      DAT_001c90c0 = DAT_001a9d24;
    }
    else {
      DAT_001c90c0 = *(int *)(DAT_001a9d24 + 0x1c);
      DAT_001c90c4 = *(int *)(DAT_001a9d24 + 0x20);
      DAT_001c90c8 = *(int *)(DAT_001a9d24 + 0x24);
    }
    DAT_001c90d4 = 0;
    DAT_001c90d2 = 0;
    DAT_001c90d0 = 0;
    DAT_001c90cc = PTR_DAT_001a9ac4;
    DAT_001a99f0 = iVar2;
    DAT_001a99f8 = iVar2;
    f_155934();
    DAT_001cd230 = 0;
    DAT_001cd234 = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74;
    DAT_001cd238 = 0;
    DAT_001cdc1a = 0;
    DAT_001a9b34 = 0;
    DAT_001a9b40 = 0;
    _DAT_001a996c = 0;
    return 0;
  }
  DAT_001a993f = 0;
  DAT_001a9940 = 0;
  return iVar2;
}




/* ==== 162208-1622C0  (nach Attic)  fremd? ==== */




undefined4 f_162208(void)

{
  undefined4 uVar1;
  
  if (DAT_001a993d == '\0') {
    uVar1 = 0xf002;
    _DAT_001a996c = 0xf002;
    _DAT_001cdb90 = s_ReleaseScenery__3DM_not_yet_init_001b99a8;
  }
  else {
    if (DAT_001a9940 == '\0') {
      _DAT_001a996c = 0xf00c;
      _DAT_001cdb90 = s_ReleaseScenery__No_Scenery_loade_001b99d0;
      return 0xf00c;
    }
    f_161e84(2);
    f_163e00();
    DAT_001a9942 = 1;
    DAT_001a9940 = '\0';
    DAT_001a993f = 0;
    DAT_001a9941 = 0;
    DAT_001a9933 = 1;
    DAT_001a993c = 0;
    DAT_001cd088 = 0;
    DAT_001a99f0 = 0;
    DAT_001a99f8 = 0;
    _DAT_001a996c = 0;
    uVar1 = 0;
  }
  return uVar1;
}




/* ==== 1622C0-16232C  (nach Attic)  fremd? ==== */




undefined4 f_1622c0(int p1)

{
  if ((0 < p1) && (p1 < 0xb)) {
    DAT_001a9d2c = p1;
    _DAT_001a996c = 0;
    DAT_001a9d28 = 1;
    return 0;
  }
  _DAT_001a996c = 0xf005;
  return 0xf005;
}




/* ==== 16232C-16238C  (nach Attic)  fremd? ==== */




undefined4 f_16232c(undefined4 p1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((ushort)p1 < 0x40) {
    DAT_001a9974 = (uint)(ushort)p1;
    if (DAT_001cd1ec != 0) {
      iVar2 = DAT_001a9974 * 0x100 + DAT_001cd1ec;
      DAT_001a9955 = *(undefined1 *)((uint)DAT_001a9954 + iVar2);
      DAT_001a995a = *(undefined1 *)((uint)DAT_001a9959 + iVar2);
    }
    uVar1 = 0;
    _DAT_001a996c = 0;
  }
  else {
    _DAT_001a996c = 0xf005;
    uVar1 = 0xf005;
  }
  return uVar1;
}




/* ==== 16238C-16246C  (nach Attic)  fremd? ==== */


undefined4 f_16238c(undefined4 p1,undefined4 p2,undefined4 p3)

{
  DAT_001a9951 = (undefined1)p1;
  DAT_001a9952 = (byte)p2;
  DAT_001a9953 = (byte)p3;
  if (DAT_001a9940 != '\0') {
    if (DAT_001cd300 == 0) {
      DAT_001a9954 = f_162b38(CONCAT11(DAT_001a9940,(undefined1)p1) & 0xff,(uint)(byte)p2,
                              (uint)(byte)p3,&DAT_001c6d68);
    }
    else {
      DAT_001a9954 = **(byte **)(DAT_001cd300 + 4);
    }
    DAT_001a9955 = *(undefined1 *)((uint)DAT_001a9954 + DAT_001a9974 * 0x100 + DAT_001cd1ec);
    return 0;
  }
  return 0xf00c;
}




/* ==== 16246C-1624B4  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 1624B4-1625F4  (nach Attic)  fremd? ==== */


undefined4 f_1624b4(undefined4 p1)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  int p1_00;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar8;
  int iVar9;
  uint p3;
  uint uVar10;
  undefined1 *puVar7;
  
  p1_00 = f_177e30(p1);
  if (p1_00 == 0) {
    uVar4 = 0xf00a;
  }
  else {
    uVar2 = *(ushort *)(p1_00 + 0x1a);
    uVar10 = (uint)uVar2;
    uVar3 = *(ushort *)(p1_00 + 0x18);
    p3 = (uint)uVar3;
    if ((*(char *)(p1_00 + 0x12) == '\x03') && (uVar2 < 0x101)) {
      if (DAT_001cd300 != 0) {
        f_1782e8(DAT_001cd300);
      }
      DAT_001cd300 = f_1781c8(3,0x100,p3,0,0);
      if (DAT_001cd300 == 0) {
        f_1782e8(p1_00);
        return 0xf001;
      }
      puVar6 = *(undefined1 **)(DAT_001cd300 + 4);
      iVar9 = 0;
      puVar5 = *(undefined1 **)(p1_00 + 4);
      if (p3 != 0) {
        do {
          iVar8 = 0;
          puVar7 = puVar6;
          if (uVar10 != 0) {
            do {
              puVar6 = puVar7 + 1;
              iVar8 = iVar8 + 1;
              uVar1 = *puVar5;
              puVar5 = puVar5 + p3;
              *puVar7 = uVar1;
              puVar7 = puVar6;
            } while (iVar8 < (int)uVar10);
          }
          iVar9 = iVar9 + 1;
          puVar5 = puVar5 + (1 - uVar10 * p3);
          puVar6 = puVar6 + (0x100 - uVar10);
        } while (iVar9 < (int)p3);
      }
      iVar9 = DAT_001cd300;
      DAT_001a9954 = **(byte **)(DAT_001cd300 + 4);
      if (DAT_001cd1ec != 0) {
        DAT_001a9955 = *(undefined1 *)(DAT_001a9974 * 0x100 + DAT_001cd1ec + (uint)DAT_001a9954);
      }
      *(ushort *)(DAT_001cd300 + 0x18) = uVar3;
      *(ushort *)(iVar9 + 0x1a) = uVar2;
      f_1782e8(p1_00);
      return 0;
    }
    f_1782e8(p1_00);
    uVar4 = 0xf00f;
  }
  return uVar4;
}




/* ==== 1625F4-1629A8  (nach Attic)  fremd? ==== */


void f_1625f4(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint p3;
  int iVar6;
  undefined1 auStack_70 [48];
  int local_40_arr[3];
  #define local_40 (local_40_arr[0])
  #define local_3c (local_40_arr[1])
  #define local_38 (local_40_arr[2])
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  
  if (DAT_001cd1ec != 0) {
    iVar2 = DAT_001cd1ec + DAT_001a9974 * 0x100;
    DAT_001a9955 = *(byte *)((uint)DAT_001a9954 + iVar2);
    DAT_001a995a = *(byte *)((uint)DAT_001a9959 + iVar2);
  }
  local_28 = (uint)DAT_001a9955;
  p3 = (uint)DAT_001a995a;
  f_16b930(auStack_70);
  f_16cbdc(auStack_70,(uint)(ushort)-(DAT_001cdc20 + DAT_001cdc1a));
  local_3c = DAT_001a9b14 - (DAT_001cd30c - DAT_001a9ab8);
  local_40 = 0;
  local_38 = (int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc * 2;
  f_16cf6a(&DAT_001c9340,&local_40,auStack_70);
  local_38 = -local_38;
  f_16cf6a(&DAT_001c9368,&local_40,auStack_70);
  local_2c = -(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc;
  iVar2 = DAT_001c9370;
  iVar6 = DAT_001c936c;
  if (SBORROW4(DAT_001c9370,local_2c) !=
      (int)(PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc + DAT_001c9370) < 0) {
    if ((PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc + DAT_001c9348 != (undefined *)0x0) &&
       (DAT_001c9348 - DAT_001c9370 != 0)) {
      iVar6 = DAT_001c9344 +
              (int)(((longlong)(DAT_001c936c - DAT_001c9344) *
                    (longlong)(int)(PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc + DAT_001c9348)) /
                   (longlong)(DAT_001c9348 - DAT_001c9370));
      iVar2 = local_2c;
    }
  }
  uVar5 = iVar2 >> 5;
  lVar1 = (longlong)(iVar6 >> 5) * (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4;
  uVar4 = (uint)lVar1 >> 0x10;
  uVar3 = uVar4 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
  if (((int)uVar5 < 0) &&
     (((int)uVar3 >> 0xf ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f) <
      (int)((uVar5 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f)))) {
    iVar2 = (int)(CONCAT44((int)uVar3 >> 0x10,uVar4 << 0x10) / (longlong)(int)uVar5) + 0x8000 >>
            0x10;
  }
  else if ((int)uVar3 < 0) {
    iVar2 = 10000;
  }
  else {
    iVar2 = -10000;
  }
  if ((((DAT_001cd300 == 0) || (*(int *)(DAT_001cd300 + 4) == 0)) ||
      (local_20 = (uint)*(ushort *)(DAT_001cd300 + 0x18), local_20 == 0)) ||
     (*(ushort *)(DAT_001cd300 + 0x1a) == 0)) {
    f_175127(DAT_001cdb50,iVar2,local_28);
    f_175127(iVar2 + 1,DAT_001cdb68,p3);
  }
  else {
    local_34 = DAT_001a9d2c * local_20 * ((int)((uint)DAT_001cdc18 << 8) >> 0x10);
    lVar1 = (longlong)(int)((uint)*(ushort *)(DAT_001cd300 + 0x1a) << 8) *
            (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9d30;
    uVar4 = (uint)(((longlong)(int)((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) *
                   (longlong)(int)DAT_001a9984) / (longlong)(int)local_34);
    local_1c = (iVar2 - uVar4) - DAT_001cdb50;
    local_24 = 0;
    if (local_1c < 1) {
      local_24 = -local_1c;
      local_1c = 0;
      if (uVar4 <= local_24) {
        f_175127(DAT_001cdb50,DAT_001cdb68,p3);
        return;
      }
      f_175127(iVar2,DAT_001cdb68,p3);
    }
    else {
      if (DAT_001a9988 < local_1c) {
        f_175127(DAT_001cdb50,DAT_001cdb68,local_28);
        return;
      }
      f_175127(DAT_001cdb50,DAT_001cdb50 + local_1c,local_28);
      if (DAT_001cdb68 < iVar2) {
        if (uVar4 <= (uint)(iVar2 - DAT_001cdb68)) {
          return;
        }
      }
      else {
        f_175127(iVar2,DAT_001cdb68,p3);
      }
    }
    local_20 = local_20 << 8;
    for (iVar2 = (uint)(ushort)(DAT_001cdc18 / 2 - DAT_001cdc1e) * DAT_001a9d2c; 0xffff < iVar2;
        iVar2 = iVar2 + -0x10000) {
    }
    local_30 = local_34 / DAT_001a9984;
    {
      int h_sky = (int)uVar4 - (int)local_24;
      if (local_1c + h_sky > DAT_001a9988) h_sky = DAT_001a9988 - local_1c;
      int tex_h_fp = (int)(uint32_t)*(uint16_t *)(DAT_001cd300 + 0x1a) << 8;
      int dv = (uVar4 != 0) ? (tex_h_fp / (int)uVar4) : 0;
      int u_start = (int)(((int64_t)local_20 * iVar2) / 0x10000);
      int v_start = (uVar4 != 0) ? (int)(((int64_t)tex_h_fp * local_24) / (int)uVar4) : 0;
      f_1751d3(*(const uint8_t **)(DAT_001cd300 + 4), h_sky, local_1c, local_20, u_start, v_start, local_30, dv);
    }
  }
  #undef local_40
  #undef local_3c
  #undef local_38
  return;
}




/* ==== 1629A8-162A00  (nach Attic)  fremd? ==== */


void f_1629a8(void)

{
  uint p3;
  
  if (((DAT_001cd300 != 0) && (*(int *)(DAT_001cd300 + 4) != 0)) &&
     (((byte)DAT_001a9a1c & 0x10) != 0)) {
    f_1625f4();
    return;
  }
  if (DAT_001cd1ec == 0) {
    p3 = 0;
  }
  else {
    p3 = (uint)*(byte *)(DAT_001cd1ec + 0x3f00);
  }
  f_175127(DAT_001cdb50,DAT_001cdb68,p3);
  return;
}




/* ==== 162A00-162A4C  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 162A4C-162B10  (nach Attic)  fremd? ==== */


void f_162a4c(int p1,int p2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int p2_00;
  undefined4 uVar6;
  
  if (p1 < p2) {
    p2_00 = p1 + p2 >> 1;
    f_162a4c(p1,p2_00);
    f_162a4c(p2_00 + 1,p2);
    puVar2 = (undefined4 *)(p1 * 4 + DAT_001ce5e4);
    iVar1 = p1;
    puVar3 = (undefined4 *)(DAT_001ce5e8 + p1 * 4);
    if (p1 <= p2_00) {
      do {
        uVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        iVar1 = iVar1 + 1;
        *puVar3 = uVar6;
        puVar3 = puVar3 + 1;
      } while (iVar1 <= p2_00);
    }
    puVar3 = (undefined4 *)(p2 * 4 + DAT_001ce5e8);
    for (; iVar1 <= p2; iVar1 = iVar1 + 1) {
      uVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar3 = uVar6;
      puVar3 = puVar3 + -1;
    }
    puVar2 = (undefined4 *)(DAT_001ce5e8 + p1 * 4);
    puVar3 = (undefined4 *)(DAT_001ce5e8 + p2 * 4);
    puVar5 = (undefined4 *)(p1 * 4 + DAT_001ce5e4);
    if (p1 <= p2) {
      do {
        if (*(byte *)((int)puVar2 + 1) < *(byte *)((int)puVar3 + 1)) {
          uVar6 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar4 = puVar3;
        }
        else {
          puVar4 = puVar3 + -1;
          uVar6 = *puVar3;
        }
        p1 = p1 + 1;
        *puVar5 = uVar6;
        puVar3 = puVar4;
        puVar5 = puVar5 + 1;
      } while (p1 <= p2);
    }
  }
  return;
}




/* ==== 162B10-162B38  (nach Attic)  fremd? ==== */


void f_162b10(undefined4 p1)

{
  undefined1 auStack_404 [1024];
  
  DAT_001ce5e8 = auStack_404;
  DAT_001ce5e4 = p1;
  f_162a4c(0,0xff);
  return;
}




/* ==== 162B38-162C64  (nach Attic)  fremd? ==== */


byte f_162b38(int p1,int p2,int p3,byte *p4)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *local_20;
  
  pbVar4 = p4;
  pbVar8 = p4 + 0x3fc;
  while( true ) {
    pbVar3 = pbVar4;
    iVar2 = (int)pbVar8 - (int)pbVar3 >> 3;
    if (iVar2 == 0) break;
    pbVar1 = pbVar3 + iVar2 * 4;
    pbVar4 = pbVar1;
    if ((byte)p2 <= pbVar1[1]) {
      pbVar4 = pbVar3;
      pbVar8 = pbVar1;
    }
  }
  local_20 = pbVar8;
  if ((byte)p2 <= pbVar3[1]) {
    local_20 = pbVar3;
  }
  uVar7 = 0x400;
  pbVar4 = local_20;
  while ((p4 <= pbVar4 &&
         (uVar5 = (int)(p2 - (uint)pbVar4[1]) >> 0x1f,
         uVar5 = (p2 - (uint)pbVar4[1] ^ uVar5) - uVar5, uVar5 < uVar7))) {
    uVar6 = (int)(p1 - (uint)*pbVar4) >> 0x1f;
    uVar5 = uVar5 + ((p1 - (uint)*pbVar4 ^ uVar6) - uVar6);
    if ((uVar5 < uVar7) &&
       (uVar6 = (int)(p3 - (uint)pbVar4[2]) >> 0x1f,
       uVar5 = uVar5 + ((p3 - (uint)pbVar4[2] ^ uVar6) - uVar6), uVar5 < uVar7)) {
      uVar7 = uVar5;
      pbVar8 = pbVar4;
    }
    pbVar4 = pbVar4 + -4;
  }
  while ((pbVar4 = local_20, local_20 = pbVar4 + 4, local_20 < p4 + 0x400 &&
         (uVar5 = (int)(p2 - (uint)pbVar4[5]) >> 0x1f,
         uVar5 = (p2 - (uint)pbVar4[5] ^ uVar5) - uVar5, uVar5 < uVar7))) {
    uVar6 = (int)(p1 - (uint)*local_20) >> 0x1f;
    uVar5 = uVar5 + ((p1 - (uint)*local_20 ^ uVar6) - uVar6);
    if ((uVar5 < uVar7) &&
       (uVar6 = (int)(p3 - (uint)pbVar4[6]) >> 0x1f,
       uVar5 = uVar5 + ((p3 - (uint)pbVar4[6] ^ uVar6) - uVar6), uVar5 < uVar7)) {
      uVar7 = uVar5;
      pbVar8 = local_20;
    }
  }
  return pbVar8[3];
}




/* ==== 162C64-162CC0  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 162CC0-162D28  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 162D28-162DB8  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 162DB8-163050  (nach Attic)  fremd? ==== */




void f_162db8(undefined4 p1,undefined4 p2,int p3,int *p4)

{
  undefined1 local_e0 [200];
  float local_18;
  float local_14;
  float local_10;
  
  if (p3 < 3) {
    p3 = 3;
  }
  else if (4 < p3) {
    p3 = 4;
  }
  local_18 = (float)_DAT_001b9a28;
  local_14 = (float)*p4 * local_18;
  local_10 = (float)p4[1] * local_18;
  local_18 = (float)p4[2] * local_18;
  if (p3 == 3) {
    
  }
  else {
    
  }
  f_16e93c(DAT_001cd320,(int)(short)p1,(int)(short)p2,DAT_001a9b00,PTR_DAT_001ad4d4,local_e0);
  return;
}




/* ==== 163050-163058  (nach Attic)  fremd? ==== */




void f_163050(undefined4 p1)

{
  _DAT_001cdb90 = p1;
  return;
}




/* ==== 1630AC-1633A0  (nach Attic)  fremd? ==== */




void f_1630ac(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined *puVar7;
  undefined *puVar8;
  int local_1c;
  
  if (DAT_001a999c < 8) {
    if (DAT_001a999c == 0) {
      DAT_001ce600 = DAT_001a999c;
      DAT_001ce5fc = DAT_001a999c;
      DAT_001ce5f8 = DAT_001a999c;
      DAT_001ce604 = DAT_001a999c;
    }
    local_1c = DAT_001ce540;
    DAT_001a9d34 = DAT_001a999c + 1;
    uVar5 = DAT_001a999c * 0xb5fffe;
    piVar6 = &DAT_001ce540 + DAT_001a999c * 5;
    DAT_001ce604 = DAT_001ce604 + DAT_001a9a64;
    DAT_001ce600 = DAT_001ce600 + DAT_001a9a68;
    DAT_001ce5fc = DAT_001ce5fc + DAT_001a9a6c;
    DAT_001ce5f8 = DAT_001ce5f8 + DAT_001a9a70;
    DAT_001a999c = DAT_001a9d34;
  }
  else {
    uVar5 = DAT_001a9d34 & 7;
    iVar2 = uVar5 * 0x14;
    DAT_001a9d34 = DAT_001a9d34 + 1;
    piVar6 = &DAT_001ce540 + uVar5 * 5;
    local_1c = *piVar6;
    DAT_001ce604 = DAT_001ce604 + (DAT_001a9a64 - *(int *)(&DAT_001ce544 + iVar2));
    DAT_001ce600 = DAT_001ce600 + (DAT_001a9a68 - *(int *)(&DAT_001ce548 + iVar2));
    DAT_001ce5fc = DAT_001ce5fc + (DAT_001a9a6c - *(int *)(&DAT_001ce54c + iVar2));
    uVar5 = 0x5affff0;
    DAT_001ce5f8 = DAT_001ce5f8 + (DAT_001a9a70 - *(int *)(&DAT_001ce550 + iVar2));
  }
  iVar2 = f_16fc19();
  *piVar6 = iVar2;
  piVar6[1] = DAT_001a9a64;
  piVar6[2] = DAT_001a9a68;
  piVar6[3] = DAT_001a9a6c;
  piVar6[4] = DAT_001a9a70;
  iVar2 = DAT_001a9d34;
  if (1 < DAT_001a999c) {
    puVar7 = (undefined *)(*piVar6 - local_1c);
    if ((int)puVar7 < 8000) {
      puVar7 = (undefined *)8000;
    }
    if (((*((uint8_t *)((char *)&(DAT_001a9a1c) + 2))) & 1) != 0) {
      DAT_001cdb10 = (DAT_001ce604 * 100) / (int)puVar7;
      DAT_001cdb08 = (DAT_001ce600 * 100) / (int)puVar7;
      DAT_001cdb0c = (DAT_001ce5fc * 100) / (int)puVar7;
      DAT_001cdb14 = (DAT_001ce5f8 * 100) / (int)puVar7;
    }
    puVar8 = puVar7;
    if (0x747ae < (int)puVar7) {
      puVar8 = ((uint8_t *)0x747ae);
      *piVar6 = (int)(((uint8_t *)0x747ae) + local_1c);
      uVar3 = DAT_001a9d34 - 2;
      do {
        uVar4 = uVar3 & 7;
        uVar3 = uVar3 - 1;
        (&DAT_001ce540)[uVar4 * 5] = (int)(puVar7 + (&DAT_001ce540)[uVar4 * 5] - 0x747ae);
      } while (uVar3 != iVar2 - 10U);
    }
    lVar1 = (longlong)(int)(uVar5 / (uint)puVar8 << 0x10) * 0x1999;
    _DAT_001a9ae8 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
    if (((int)_DAT_001a9ae8 <= (int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74) ||
       (PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ab0 =
             (undefined *)(0xa00000000 / (longlong)(int)(uVar5 / (uint)puVar8 << 0x10)),
       0x6666 < (int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ab0)) {
      PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ab0 = (undefined *)0x6666;
    }
  }
  {
    static uint32_t s_prev_frame_pit = 0;
    static uint32_t s_frame_idx = 0;
    static double   s_sum_total = 0.0, s_sum_scene = 0.0, s_sum_raster = 0.0, s_sum_upload = 0.0, s_sum_wait = 0.0;
    uint32_t cur_pit = (uint32_t)(*piVar6);
    if (s_prev_frame_pit != 0 && cur_pit > s_prev_frame_pit) {
      uint32_t pit_total  = cur_pit - s_prev_frame_pit;
      int32_t  pit_scene  = DAT_001a9a68 + DAT_001a9a6c;
      int32_t  pit_raster = DAT_001a9a70;
      int32_t  pit_upload = DAT_001a9a64;
      if (pit_scene  < 0) pit_scene  = 0;
      if (pit_raster < 0) pit_raster = 0;
      if (pit_upload < 0) pit_upload = 0;
      int32_t  pit_wait   = (int32_t)pit_total - (pit_scene + pit_raster + pit_upload);
      if (pit_wait   < 0) pit_wait   = 0;

      double ms_total  = (double)pit_total  / 1193.182;
      double ms_scene  = (double)pit_scene  / 1193.182;
      double ms_raster = (double)pit_raster / 1193.182;
      double ms_upload = (double)pit_upload / 1193.182;
      double ms_wait   = (double)pit_wait   / 1193.182;
      double fps       = (ms_total > 0.01) ? (1000.0 / ms_total) : 0.0;

      s_frame_idx++;
      s_sum_total  += ms_total;
      s_sum_scene  += ms_scene;
      s_sum_raster += ms_raster;
      s_sum_upload += ms_upload;
      s_sum_wait   += ms_wait;

      if (s_frame_idx <= 25 || (s_frame_idx % 25) == 0) {
        char zbuf[256];
        int wx = DAT_001cd308 >> 16;
        int wz = DAT_001cd310 >> 16;
        unsigned int yaw = (unsigned int)(uint16_t)DAT_001cdc1e;
        int cell = (int)(*(int16_t *)(&riva_dgroup_base[0x2db3c]));
        snprintf(zbuf, sizeof(zbuf),
            "%5u\t%7.2f\t%7.2f\t%7.2f\t%7.2f\t%7.2f\t%6.1f\t%4d\t(%5d,%5d)\t0x%04X\t"
            "[Mittel: Gesamt=%.2fms Szene=%.2fms Raster=%.2fms Upload=%.2fms Warten=%.2fms]\n",
            (unsigned)s_frame_idx, ms_total, ms_scene, ms_raster, ms_upload, ms_wait, fps,
            cell, wx, wz, yaw,
            s_sum_total / s_frame_idx, s_sum_scene / s_frame_idx,
            s_sum_raster / s_frame_idx, s_sum_upload / s_frame_idx, s_sum_wait / s_frame_idx);
        riva_log_zeile_zeiten(zbuf);
      }
    }
    s_prev_frame_pit = cur_pit;
  }
  DAT_001a9a6c = 0;
  DAT_001a9a68 = 0;
  DAT_001a9a64 = 0;
  DAT_001a9a70 = 0;
  DAT_001a9a20 = DAT_001a9a20 + 1;
  return;
}




/* ==== 1633A0-1633C0  (nach Attic)  fremd? ==== */


void f_1633a0(void)

{
  if (DAT_001ce5f6 == '\0') {
    DAT_001ce5ec = f_16fc19();
    DAT_001ce5f6 = '\x01';
  }
  return;
}




/* ==== 1633C0-163428  (nach Attic)  fremd? ==== */


void f_1633c0(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_001ce5f6 != '\0') {
    iVar1 = f_16fc19();
    DAT_001ce5ec = iVar1 - DAT_001ce5ec;
    if (DAT_001a9948 != '\0') {
      f_154f00(DAT_001ce5ec);
    }
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 0x14;
      *(int *)((int)&DAT_001ce540 + iVar1) = *(int *)((int)&DAT_001ce540 + iVar1) + DAT_001ce5ec;
      iVar1 = iVar2;
    } while (iVar2 != 0xa0);
    DAT_001ce5f6 = '\0';
  }
  return;
}




/* ==== 163504-163A98  (nach Attic)  fremd? ==== */


int f_163504(int p1,undefined4 p2,int unaff_EBX)

{
  
  if (p1 != 0) {
    p1 = f_15e469(p1,&DAT_001b9a40);
    if (p1 != 0) {
      f_15ea0f((void *)p2, 1, unaff_EBX, (void *)p1);
      f_15e836((void *)p1, 1);
      p1 = 1;
    }
  }
  return p1;
}




/* ==== 163A98-163AD0  (nach Attic)  fremd? ==== */




undefined4 f_163a98(undefined4 p1)

{
  if (0x3f < (ushort)p1) {
    _DAT_001a996c = 0xf005;
    return 0xf005;
  }
  _DAT_001a9970 = (uint)(ushort)p1;
  _DAT_001a996c = 0;
  return 0;
}




/* ==== 163AD0-163B08  (nach Attic)  fremd? ==== */


undefined2 f_163ad0(int p1)

{
  if (2 < p1) {
    return 0;
  }
  if (DAT_001cd1e0 == 0) {
    return 0;
  }
  return *(undefined2 *)(DAT_001cd1e0 + 10 + p1 * 0x58);
}




/* ==== 163B08-163BAC  (nach Attic)  fremd? ==== */


void f_163b08(int p1,undefined4 p2)

{
  int *piVar1;
  
  if ((p1 < 3) && (DAT_001cd1e0 != 0)) {
    if (0x3f < (ushort)p2) {
      (*((int16_t *)((char *)&(p2) + 0))) = 0x3f;
    }
    piVar1 = (int *)(DAT_001cd1e0 + p1 * 0x58);
    *(ushort *)((int)piVar1 + 10) = (ushort)p2;
    if ((*(char *)((int)piVar1 + 6) == '\x01') || (*(char *)((int)piVar1 + 6) == '\x03')) {
      piVar1[6] = (uint)(ushort)p2 * piVar1[4];
    }
    if (((*(char *)((int)piVar1 + 6) == '\x01') && (*piVar1 != 0)) &&
       (*(char *)(*piVar1 + 2) == 'F')) {
      piVar1[0x14] = (uint)(ushort)p2;
    }
  }
  return;
}




/* ==== 163BAC-163BF8  (nach Attic)  fremd? ==== */


void f_163bac(int p1,undefined4 p2)

{
  int iVar1;
  
  if ((p1 < 3) && (DAT_001cd1e0 != 0)) {
    iVar1 = DAT_001cd1e0 + p1 * 0x58;
    *(undefined4 *)(iVar1 + 0x10) = p2;
    if ((*(char *)(iVar1 + 6) == '\x01') || (*(char *)(iVar1 + 6) == '\x03')) {
      *(uint *)(iVar1 + 0x18) = (uint)*(ushort *)(iVar1 + 10) * *(int *)(iVar1 + 0x10);
    }
  }
  return;
}




/* ==== 163BF8-163D48  (nach Attic)  fremd? ==== */


undefined4 f_163bf8(int p1,int p2,int p3,int p4)

{
  undefined4 uVar1;
  uint p1_00;
  int iVar2;
  uint p3_00;
  uint local_40 [12];
  #define local_38 (((int *)local_40)[2])
  #define local_28 (local_40[6])
  #define local_20 (local_40[8])
  
  if ((p4 == 0) || (p3 == 0)) {
    uVar1 = 0;
  }
  else {
    p1_00 = (*(int *)(p3 + 0x1c) >> 4) - (p1 >> 4);
    p3_00 = (*(int *)(p3 + 0x24) >> 4) - (p2 >> 4);
    if ((int)(PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc + *(int *)(p3 + 0x14)) >> 4 <
        (int)((p1_00 ^ (int)p1_00 >> 0x1f) - ((int)p1_00 >> 0x1f))) {
      return 0;
    }
    if ((int)(PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc + *(int *)(p3 + 0x14)) >> 4 <
        (int)((p3_00 ^ (int)p3_00 >> 0x1f) - ((int)p3_00 >> 0x1f))) {
      return 0;
    }
    iVar2 = f_16d33f(p1_00,p1_00,p3_00,p3_00);
    if (iVar2 < 0) {
      return 0;
    }
    iVar2 = f_16d3d0(iVar2);
    if (0 < iVar2) {
      p1_00 = (uint)(CONCAT44((int)p1_00 >> 0x10,p1_00 * 0x10000) / (longlong)iVar2);
      if ((int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 <
          (int)((p1_00 ^ (int)p1_00 >> 0x1f) - ((int)p1_00 >> 0x1f))) {
        return 0;
      }
      p3_00 = (uint)(CONCAT44((int)p3_00 >> 0x10,p3_00 * 0x10000) / (longlong)iVar2);
      if ((int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74 <
          (int)((p3_00 ^ (int)p3_00 >> 0x1f) - ((int)p3_00 >> 0x1f))) {
        return 0;
      }
    }
    f_16b930(local_40);
    local_38 = -p1_00;
    *(int *)(p4 + 0x24) = *(int *)(p4 + 0x24) - *(int *)(p3 + 0x1c);
    *(int *)(p4 + 0x28) = *(int *)(p4 + 0x28) - *(int *)(p3 + 0x20);
    *(int *)(p4 + 0x2c) = *(int *)(p4 + 0x2c) - *(int *)(p3 + 0x24);
    local_40[0] = p3_00;
    local_28 = p1_00;
    local_20 = p3_00;
    f_16cb84(p4,local_40);
    *(int *)(p4 + 0x24) = *(int *)(p4 + 0x24) + *(int *)(p3 + 0x1c);
    *(int *)(p4 + 0x28) = *(int *)(p4 + 0x28) + *(int *)(p3 + 0x20);
    uVar1 = 1;
    *(int *)(p4 + 0x2c) = *(int *)(p4 + 0x2c) + *(int *)(p3 + 0x24);
  }
  #undef local_38
  #undef local_28
  #undef local_20
  return uVar1;
}




/* ==== 163D48-163DC0  (nach Attic)  fremd? ==== */


int f_163d48(undefined4 p1)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = f_16d388((int *)p1);
  iVar5 = 0;
  uVar6 = (uint)(uint16_t)DAT_001a9968; // Original: XOR ESI,ESI; MOV SI,[9968]
  for (uVar4 = uVar3; 499 < uVar4; uVar4 = uVar4 >> 2) {
    iVar5 = iVar5 + 1;
  }
  bVar2 = (byte)iVar5;
  if (iVar5 != 0) {
    uVar6 = uVar6 + (uVar3 - (uVar4 << (bVar2 * '\x02' & 0x1f))) * 0x10000;
  }
  lVar1 = (longlong)(int)uVar6 *
          (longlong)(*(int *)(&DAT_001cd338 + uVar4 * 4) - (&DAT_001cd334)[uVar4]);
  return ((int)((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) >>
         (bVar2 * '\x02' & 0x1f)) + (&DAT_001cd334)[uVar4] << (bVar2 & 0x1f);
}




/* ==== 163E30-16402C  (nach Attic)  fremd? ==== */




void f_163e30(void)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_001a993d == '\0') {
    DAT_001a993c = DAT_001a993d;
    DAT_001a9942 = DAT_001a993d;
    DAT_001a9949 = DAT_001a993d;
    DAT_001a9941 = DAT_001a993d;
    DAT_001a994b = DAT_001a993d;
    DAT_001a994c = DAT_001a993d;
    DAT_001a994d = DAT_001a993d;
    DAT_001a994e = DAT_001a993d;
    DAT_001a9944 = DAT_001a993d;
    DAT_001cd088 = DAT_001a993d;
    DAT_001cd0b0 = DAT_001a993d;
    DAT_001a9931 = DAT_001a993d;
    DAT_001a9933 = 1;
    DAT_001a9950 = 1;
    DAT_001a9962 = 0xffff;
    DAT_001a996a = 0xffff;
    PTR_DAT_001a9ae0 = (undefined *)0x140000;
    DAT_001a9ae4 = 0x180000;
    PTR_DAT_001a9ac4 = (undefined *)0x140000;
    PTR_DAT_001a9b2c = (undefined *)0x28f;
    PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ad4 = 0x10000;
    _DAT_001a99b4 = 0;
    DAT_001a99b0 = 0;
    DAT_001a99ac = 0;
    DAT_001a99b8 = 0;
    _DAT_001a99c0 = 0;
    DAT_001a99bc = 0;
    _DAT_001a99c4 = 0;
    DAT_001a99c8 = 0;
    DAT_001a99f8 = 0;
    DAT_001a99f0 = 0;
    DAT_001a9a20 = 0;
    DAT_001a999c = 0;
    _DAT_001a9ae8 = 0;
    PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9adc = (undefined *)0x3e80000;
    DAT_001cdc18 = 0x2aa8;
    DAT_001cdc20 = 0;
    DAT_001cdc1e = 0;
    DAT_001cdc1c = 0;
    DAT_001cdc1a = 0;
    PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9b28 = 0x10000;
    DAT_001a9b30 = 0x20000;
    PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ad8 = (undefined *)0x1999;
    PTR_DAT_001a9b38 = (undefined *)0x189;
    _DAT_001cc7b8 = 0;
    iVar4 = 1;
    DAT_001a9b34 = 0;
    DAT_001a9b3c = 0;
    DAT_001a9b40 = 0;
    DAT_001cd230 = 0;
    DAT_001cd238 = 0;
    DAT_001cd234 = PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a74;
    DAT_001a9a1c = 0x4564065;
    iVar3 = 4;
    do {
      lVar1 = (longlong)iVar4;
      iVar4 = iVar4 + 1;
      *(int *)(&DAT_001cc7b8 + iVar3) = (int)(0x40000000 / lVar1) + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < 0x140);
    iVar4 = 0;
    iVar3 = 0;
    do {
      iVar5 = iVar3 + 4;
      uVar2 = f_16d3d0(iVar4);
      iVar4 = iVar4 + 0x10000;
      *(undefined4 *)((int)&DAT_001cd334 + iVar3) = uVar2;
      iVar3 = iVar5;
    } while (iVar5 != 0x7d4);
    f_163e00();
  }
  return;
}




/* ==== 16402C-164408  (nach Attic)  fremd? ==== */

/* keine Funktion */



/* ==== 164408-1645A0  (nach Attic)  fremd? ==== */


void f_164408(void)

{
  longlong lVar1;
  int p1;
  int iVar2;
  
  iVar2 = DAT_001a9984;
  DAT_001a9a88 = DAT_001a9984 / 2 << 0x10;
  DAT_001cdb50 = -DAT_001a9988 / 2;
  DAT_001a9a8c = DAT_001cdb50 << 0x10;
  DAT_001cdb4c = -DAT_001a9984 / 2;
  DAT_001cdb6c = (DAT_001a9984 + -1) / 2;
  DAT_001cdb68 = (DAT_001a9988 + -1) / 2;
  p1 = f_16d7e7((uint16_t)(DAT_001cdc18 / 2));
  iVar2 = f_16d818((uint16_t)(DAT_001cdc18 / 2));
  iVar2 = (int)(CONCAT44(iVar2 >> 0x10,iVar2 << 0x10) / (longlong)p1);
  lVar1 = (longlong)
          (int)(CONCAT44(iVar2 >> 0x10,iVar2 << 0x10) /
               (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9ad4) * (longlong)-DAT_001a9a88
  ;
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0 =
       (undefined *)((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4 =
       (undefined *)
       ((uint)((longlong)iVar2 * (longlong)-DAT_001a9a8c) >> 0x10 |
       (int)((ulonglong)((longlong)iVar2 * (longlong)-DAT_001a9a8c) >> 0x20) << 0x10);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a90 =
       (undefined *)
       ((longlong)((ulonglong)(uint)(DAT_001cdb6c * 0x10000 >> 0x10) << 0x20) /
       (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a94 =
       (undefined *)
       ((longlong)((ulonglong)(uint)((DAT_001cdb4c << 0x10) >> 0x10) << 0x20) /
       (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa0);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a98 =
       (undefined *)
       ((longlong)((ulonglong)(uint)((DAT_001cdb50 << 0x10) >> 0x10) << 0x20) /
       (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a78 = (undefined *)(DAT_001cdb4c << 0x10);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a80 = (undefined *)(DAT_001cdb50 << 0x10);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a9c =
       (undefined *)
       ((longlong)((ulonglong)(uint)(DAT_001cdb68 * 0x10000 >> 0x10) << 0x20) /
       (longlong)(int)PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9aa4);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a84 = (undefined *)(DAT_001cdb68 * 0x10000 + 0xe666);
  PTR_lib_CLIB3R_LIB_cstrt386_010000_001a9a7c = (undefined *)(DAT_001cdb6c * 0x10000 + 0xe666);
  return;
}




/* ==== 164660-164748  (nach Attic)  fremd? ==== */


undefined4 f_164660(void)

{
  undefined4 in_EAX;
  
  return in_EAX;
}




/* ==== 164870-164880  (nach Attic)  fremd? ==== */




longdouble f_164870(void)

{
  return (longdouble)DAT_001a9af8 * (longdouble)_DAT_001b9b25;
}




/* ==== 164880-164994  (nach Attic)  fremd? ==== */




undefined4 f_164880(int p1,int p2,int p3,int p4)

{
  if (DAT_001a993d == '\0') {
    return 0xf002;
  }
  if (((((9 < p1) && (p1 < 0x141)) && (9 < p2)) && ((p2 < 0xc9 && (-1 < p3)))) && (-1 < p4)) {
    if ((p1 <= DAT_001a998c) && (p2 <= DAT_001a9990)) {
      DAT_001cdc22 = (undefined2)p3;
      DAT_001cdc24 = (undefined2)p4;
      if (DAT_001a998c - p1 < p3) {
        p3 = DAT_001a998c - p1;
      }
      if (DAT_001a9990 - p2 < p4) {
        p4 = DAT_001a9990 - p2;
      }
      DAT_001cdb44 = p3 + p1 / 2;
      DAT_001cdb48 = p4 + p2 / 2;
      DAT_001a9984 = p1;
      DAT_001a9988 = p2;
      f_164408();
      DAT_001a994b = 0;
      _DAT_001a996c = 0;
      DAT_001a9920 = DAT_001a991c + (DAT_001cdb48 + DAT_001cdb50) * DAT_001a9a60 +
                     DAT_001cdb44 + DAT_001cdb4c;
      return 0;
    }
    _DAT_001a996c = 0xf005;
    return 0xf005;
  }
  _DAT_001a996c = 0xf005;
  return 0xf005;
}




/* ==== 164CF0-164D04  (nach Attic)  fremd? ==== */


undefined4 f_164cf0(void)

{
  if (DAT_001a993d == '\0') {
    return 0;
  }
  return DAT_001cd1ec;
}




/* ==== 164D04-164E64  (nach Attic)  fremd? ==== */




void f_164d04(undefined4 *p1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((DAT_001a993d != '\0') && (p1 != (undefined4 *)0x0)) {
    if (p1 != &DAT_001c72f8) {
      puVar2 = &DAT_001c72f8;
      for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *p1;
        p1 = p1 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    puVar2 = &DAT_001c72f8;
    puVar3 = &DAT_001c6d68;
    for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    f_162b10(&DAT_001c6d68);
    DAT_001cdb74 = f_162b38(0xff,0xff,0xff,&DAT_001c6d68);
    DAT_001cdb5c = f_162b38(0x8f,0x8f,0x8f,&DAT_001c6d68);
    DAT_001cdb54 = f_162b38(0xff,0x10,0x10,&DAT_001c6d68);
    DAT_001cdb70 = f_162b38(0xff,0xff,0x10,&DAT_001c6d68);
    DAT_001cdb60 = f_162b38(0x10,0xff,0x10,&DAT_001c6d68);
    DAT_001cdb58 = f_162b38(0x10,0x10,0xff,&DAT_001c6d68);
    _DAT_001cdb64 = f_162b38(0,0,0,&DAT_001c6d68);
    if (DAT_001cd300 == 0) {
      DAT_001a9954 = f_162b38((uint)DAT_001a9951,(uint)DAT_001a9952,(uint)DAT_001a9953,&DAT_001c6d68
                             );
    }
    DAT_001a9959 = f_162b38((uint)DAT_001a9956,(uint)DAT_001a9957,(uint)DAT_001a9958,&DAT_001c6d68);
    DAT_001a9941 = 0;
  }
  return;
}




/* ==== 164E64-165460  (nach Attic)  fremd? ==== */




void f_164e64(ushort *p1,int p2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte local_10;
  uint uVar4;
  
  iVar1 = DAT_001ce634;
  if (0 < DAT_001ce630) {
    *(byte *)p1 = (byte)((uint)(byte)*p1 * DAT_001ce634 + _DAT_001ce624 >> 8);
    *(byte *)((int)p1 + 1) = (byte)((uint)*(byte *)((int)p1 + 1) * iVar1 + _DAT_001ce62c >> 8);
    *(byte *)(p1 + 1) = (byte)((uint)(byte)p1[1] * iVar1 + _DAT_001ce63c >> 8);
  }
  iVar1 = DAT_001ce628;
  if (0 < DAT_001ce638) {
    uVar2 = (uint)*p1;
    if ((byte)*p1 <= *(byte *)((int)p1 + 1)) {
      uVar2 = (uint)*(byte *)((int)p1 + 1);
    }
    uVar4 = uVar2 & 0xff;
    if ((uVar2 & 0xff) < (uint)(byte)p1[1]) {
      uVar4 = (uint)(byte)p1[1];
    }
    iVar3 = uVar4 * DAT_001ce638;
    local_10 = (byte)((uint)(byte)*p1 * DAT_001ce628 + iVar3 >> 8);
    *(byte *)p1 = local_10;
    local_10 = (byte)((uint)*(byte *)((int)p1 + 1) * iVar1 + iVar3 >> 8);
    *(byte *)((int)p1 + 1) = local_10;
    *(byte *)(p1 + 1) = (byte)(iVar3 + (uint)(byte)p1[1] * iVar1 >> 8);
  }
  if ((DAT_001ce620 < 0x100) && (p2 != 3)) {
    iVar1 = DAT_001ce620;
    if (p2 != 1) {
      iVar1 = DAT_001ce620 + 0x300 >> 2;
    }
    *(byte *)p1 = (byte)((uint)(byte)*p1 * iVar1 >> 8);
    *(byte *)((int)p1 + 1) = (byte)((uint)*(byte *)((int)p1 + 1) * iVar1 >> 8);
    *(byte *)(p1 + 1) = (byte)(iVar1 * (uint)(byte)p1[1] >> 8);
  }
  return;
}




#ifdef __cplusplus
}
#endif
