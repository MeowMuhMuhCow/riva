// RIVA_CLOBBER.H - erzeugt von gw/clobber.py: Aufgerufene, die ihre Parameterregister selbst sichern (R83).
// Nur fuer freie Funktionen (f_xxxxxx) nach deren Deklaration einfuegbar; Methoden: Aufruf als freie Funktion f_xxxxxx(this,...) deklarieren.
// Form: #pragma aux f_x parm [regs] modify exact [clobber]
#pragma aux f_01cc90 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 2
#pragma aux f_02e56f parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 1
#pragma aux f_02f883 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 3
#pragma aux f_07a9e0 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 3
#pragma aux f_07aa10 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 3
#pragma aux f_07aab0 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx; Aufrufe 3
#pragma aux f_07b580 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx esi; Aufrufe 1
#pragma aux f_07beb0 parm [eax edx ebx ecx] modify exact [eax edx]   // gesichert: ebx ecx esi edi; Aufrufe 6
#pragma aux f_085050 parm [eax edx ebx ecx] modify exact [eax ebx edx]   // gesichert: ecx esi edi ebp; Aufrufe 5
#pragma aux f_0971f0 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 1
#pragma aux f_0974f0 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx ecx esi edi; Aufrufe 11
#pragma aux f_09a040 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 46
#pragma aux f_09a080 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 21
#pragma aux f_09d640 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 10
#pragma aux f_0a7610 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 2
#pragma aux f_0d1320 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx edx; Aufrufe 2
#pragma aux f_0d2050 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 1
#pragma aux f_0d4324 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 5
#pragma aux f_0d82f0 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 1
#pragma aux f_0da9a0 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 3
#pragma aux f_0dac90 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx ecx; Aufrufe 1
#pragma aux f_0fdc30 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 1
#pragma aux f_0fdd10 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx ecx edx esi; Aufrufe 1
#pragma aux f_0fe5c0 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi; Aufrufe 1
#pragma aux f_100e30 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx ecx edx; Aufrufe 1
#pragma aux f_105cd0 parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx esi; Aufrufe 1
#pragma aux f_11f790 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx esi edi ebp; Aufrufe 1
#pragma aux f_134030 parm [eax edx ebx] modify exact [eax]   // gesichert: ebx; Aufrufe 10
#pragma aux f_15e114 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx ecx; Aufrufe 4
#pragma aux f_15f2d6 parm [eax edx] modify exact [edx]   // gesichert: ecx eax; Aufrufe 5
#pragma aux f_165de2 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 4
#pragma aux f_1666fc parm [eax edx] modify exact [eax]   // gesichert: ebx ecx edx; Aufrufe 4
#pragma aux f_167721 parm [eax edx ebx ecx] modify exact [eax edx]   // gesichert: ecx esi edi; Aufrufe 1
#pragma aux f_167f75 parm [eax edx ebx ecx] modify exact [eax edx]   // gesichert: ebx ecx esi edi ebp; Aufrufe 2
#pragma aux f_16cf6a parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx ecx esi edi ebp; Aufrufe 8
#pragma aux f_16cff5 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx ecx esi edi ebp; Aufrufe 6
#pragma aux f_16d077 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebx ecx esi edi ebp; Aufrufe 2
#pragma aux f_178334 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx esi; Aufrufe 1
#pragma aux f_178c64 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx esi; Aufrufe 5
#pragma aux f_178ee6 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx; Aufrufe 1
#pragma aux f_179001 parm [eax edx ebx ecx] modify exact [eax]   // gesichert: ebx ecx edx; Aufrufe 1
#pragma aux f_179b51 parm [eax edx ebx ecx] modify exact [eax edx]   // gesichert: ebx ecx esi edi; Aufrufe 1
#pragma aux f_18d558 parm [eax] modify exact [ebp edi]   // gesichert: ebx edx eax; Aufrufe 1
#pragma aux f_18d571 parm [eax edx] modify exact [ebp]   // gesichert: edi esi edx ecx ebx eax; Aufrufe 1
#pragma aux f_18dd50 parm [eax edx ebx ecx] modify exact []   // gesichert: ebp edi ecx ebx esi edx eax; Aufrufe 5
#pragma aux f_1971eb parm [eax] modify exact []   // gesichert: eax ebx ecx edx esi; Aufrufe 3
#pragma aux f_1992e9 parm [eax edx ebx] modify exact [eax edx]   // gesichert: ebp edi ecx ebx; Aufrufe 1
