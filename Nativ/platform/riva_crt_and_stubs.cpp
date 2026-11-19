/*
 * riva_crt_and_stubs.cpp - Watcom-C/C++-Laufzeitbibliothek, DOS/DPMI/VESA/Maus-Bruecke,
 * HMI-SOS-Timer-Dispatcher und Einstiegspunkt (main) fuer den Windows-Port von
 * DSA 3: Schatten ueber Riva.
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include <direct.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "dsa_platform.h"

static char g_exe_exit_log_path[MAX_PATH];
#include "../src/inc/watcom_compat.h"
#include "../src/inc/i86.h"
#include "../src/inc/dos.h"
#include "../src/inc/bios.h"
#include "../src/inc/conio.h"

/* =========================================================================
 * Externe Symbole aus den Riva-Einheiten und DGROUP
 * ========================================================================= */

extern "C" {
void f_143520(void);
void f_1439e0(short argc, char **argv);
int  f_148570(int p, int p2);
void *f_014710(void *p);

extern int            d_1a34e0;       /* Lineare VRAM-Basisadresse */
extern unsigned char  d_1c2e78;       /* CD-Laufwerksbuchstabe */
extern unsigned char *d_1c1104;       /* VESA VbeInfoBlock (512 Bytes) */
extern unsigned char *d_1c1108;       /* VESA ModeInfoBlock (258 Bytes) */
extern unsigned char  d_1c1110;       /* VESA initialisiert */
extern unsigned int   d_1c3914;       /* Globaler 100-Hz-Tickzaehler */
extern unsigned char  d_1a0100;       /* Ziffernblock 5 (Scancode 0x4C) */
extern unsigned short d_1a0102;       /* Gehaltene 3D-Richtungstasten-Bitmaske (f_0100c0) */
extern int            d_1a0104;       /* Tastatur-Zeitstempel */
extern int            d_1c0b1c;       /* 3D-Demo-Wiedergabe aktiv */

#pragma pack(push, 1)
struct DpmiRealModeRegs {
    unsigned int   edi, esi, ebp, reserved, ebx, edx, ecx, eax;
    unsigned short flags, es, ds, fs, gs, ip, cs, sp, ss;
};
#pragma pack(pop)
extern struct DpmiRealModeRegs d_1c10d0;
}

/* Statische Rückfallpuffer fuer VESA-Info, falls vor f_13d740 darauf zugegriffen wird */
static unsigned char g_fallback_vbe_info[512];
static unsigned char g_fallback_mode_info[260];
static unsigned char g_indos_flag = 0;

/* =========================================================================
 * 1. HMI-SOS-Timer-Emulation (f_16897e / f_168cd4) & Event-Pumpe
 * ========================================================================= */

struct RivaTimerSlot {
    int            active;
    unsigned short rate;
    void         (*callback)(void);
    uint32_t       last_fire_ms;
    uint32_t       rem_acc;
};

#define MAX_RIVA_TIMERS 32
static RivaTimerSlot g_timers[MAX_RIVA_TIMERS];
static int           g_in_timer_dispatch = 0;
static uint32_t      g_last_tick100_ms   = 0;
static void        (*g_int1c_handler)(void) = NULL;

static void riva_abdeckung_sample_stack(const void *stack_anchor);
static void riva_audio_pump(void);

extern "C" void riva_pump_timers_and_events(void) {
    uint32_t now_ms;
    int i;

    riva_abdeckung_sample_stack(&now_ms);
    dsa_platform_pump_and_present_if_due();
    riva_audio_pump();
    now_ms = dsa_platform_get_ticks_ms();

    /* Aktualisiere den DOS-INT-1Ch-Timer (18,2 Hz / ~55 ms -> f_0a7110 / f_0a6fb0:
     * d_1c3914++, d_1c219e = 1, d_1bc5f6++, d_1bf234[0..6], Spielzeituhr f_1261b0) */
    if (g_last_tick100_ms == 0) {
        g_last_tick100_ms = now_ms;
    } else if (now_ms - g_last_tick100_ms >= 55) {
        uint32_t steps = (now_ms - g_last_tick100_ms) / 55;
        g_last_tick100_ms += steps * 55;
        if (steps > 4u) steps = 4u;
        if (!g_in_timer_dispatch) {
            g_in_timer_dispatch = 1;
            for (uint32_t s = 0; s < steps; ++s) {
                if (g_int1c_handler) {
                    g_int1c_handler();
                } else {
                    d_1c3914++;
                }
            }
            g_in_timer_dispatch = 0;
        }
    }

    /* Synchronisiere die 3D-Richtungstasten d_1a0102/d_1a0100 (f_0100c0) direkt aus dem Plattform-Scancode-Zustand */
    if (d_1c0b1c == 0) {
        unsigned short kbits = 0;
        if (dsa_platform_get_scancode_state(0x48) || dsa_platform_get_scancode_state(0x11)) kbits |= 0x01; /* Hoch / W: Vorwaerts */
        if (dsa_platform_get_scancode_state(0x50) || dsa_platform_get_scancode_state(0x1f)) kbits |= 0x02; /* Runter / S: Rueckwaerts */
        if (dsa_platform_get_scancode_state(0x4b) || dsa_platform_get_scancode_state(0x1e)) kbits |= 0x04; /* Links / A: Links drehen */
        if (dsa_platform_get_scancode_state(0x4d) || dsa_platform_get_scancode_state(0x20)) kbits |= 0x08; /* Rechts / D: Rechts drehen */
        if (dsa_platform_get_scancode_state(0x47)) kbits |= 0x10;                                         /* Pos1: Blick nach oben */
        if (dsa_platform_get_scancode_state(0x4f)) kbits |= 0x20;                                         /* Ende: Blick nach unten */
        if (dsa_platform_get_scancode_state(0x49)) kbits |= 0x40;                                         /* Bild hoch */
        if (dsa_platform_get_scancode_state(0x51)) kbits |= 0x80;                                         /* Bild runter */
        d_1a0102 = kbits;
        d_1a0100 = dsa_platform_get_scancode_state(0x4c) ? 1 : 0;                                         /* Ziffernblock 5: Blick zentrieren */
        d_1a0104 = 0x46c;
    }

    /* Feuere registrierte HMI-SOS-Timer-Callbacks (z. B. f_1206a0 120-Hz-3D-Schritt, f_0d2920 Maus, f_01bf70 Animation) */
    if (!g_in_timer_dispatch) {
        g_in_timer_dispatch = 1;
        for (i = 0; i < MAX_RIVA_TIMERS; ++i) {
            if (g_timers[i].active && g_timers[i].callback) {
                uint32_t rate = (g_timers[i].rate > 0) ? (uint32_t)g_timers[i].rate : 100u;
                uint32_t elapsed_ms = now_ms - g_timers[i].last_fire_ms;
                if (elapsed_ms > 100u) elapsed_ms = 100u;
                g_timers[i].last_fire_ms = now_ms;
                uint32_t total_num = elapsed_ms * rate + g_timers[i].rem_acc;
                uint32_t ticks = total_num / 1000u;
                g_timers[i].rem_acc = total_num % 1000u;
                if (ticks > 12u) ticks = 12u;
                for (uint32_t t = 0; t < ticks; ++t) {
                    if (!g_timers[i].active || !g_timers[i].callback) break;
                    g_timers[i].callback();
                }
            }
        }
        g_in_timer_dispatch = 0;
    }
}

/* =========================================================================
 * 2. Port-Hooks aus watcom_compat.h (VRAM, VGA-Ports, BIOS-Tastatur)
 * ========================================================================= */

static int           g_vga_dac_write_idx  = 0;
static int           g_vga_dac_write_comp = 0;
static unsigned char g_vga_dac_pending[3] = {0, 0, 0};
static int           g_vga_dac_read_idx   = 0;
static int           g_vga_dac_read_comp  = 0;
static int           g_vsync_toggle       = 0;

extern "C" unsigned char *port_get_vram(void) {
    return dsa_platform_get_vram();
}

extern "C" int port_inp(unsigned port) {
    if (port == 0x3DA) {
        g_vsync_toggle ^= 0x08;
        if (g_vsync_toggle) {
            riva_pump_timers_and_events();
        }
        return g_vsync_toggle;
    }
    if (port == 0x3C9) {
        unsigned char rgb[3] = {0, 0, 0};
        int val;
        dsa_platform_get_palette_entry(g_vga_dac_read_idx & 0xFF, &rgb[0], &rgb[1], &rgb[2]);
        val = rgb[g_vga_dac_read_comp];
        if (++g_vga_dac_read_comp >= 3) {
            g_vga_dac_read_comp = 0;
            g_vga_dac_read_idx = (g_vga_dac_read_idx + 1) & 0xFF;
        }
        return val;
    }
    return 0;
}

extern "C" int port_outp(unsigned port, int val) {
    if (port == 0x3C7) {
        g_vga_dac_read_idx  = val & 0xFF;
        g_vga_dac_read_comp = 0;
    } else if (port == 0x3C8) {
        g_vga_dac_write_idx  = val & 0xFF;
        g_vga_dac_write_comp = 0;
    } else if (port == 0x3C9) {
        g_vga_dac_pending[g_vga_dac_write_comp++] = (unsigned char)(val & 0x3F);
        if (g_vga_dac_write_comp >= 3) {
            dsa_platform_set_palette_entry(
                g_vga_dac_write_idx & 0xFF,
                g_vga_dac_pending[0],
                g_vga_dac_pending[1],
                g_vga_dac_pending[2]
            );
            g_vga_dac_write_comp = 0;
            g_vga_dac_write_idx = (g_vga_dac_write_idx + 1) & 0xFF;
            if (g_vga_dac_write_idx == 0) {
                dsa_platform_present();
            }
        }
    }
    return val;
}

static unsigned int g_key_poll_counter = 0;
static uint32_t     g_key_poll_last_ms = 0;

extern "C" unsigned short port_bios_keybrd(unsigned cmd) {
    riva_pump_timers_and_events();
    if (cmd == _KEYBRD_READ) {
        while (dsa_platform_key_ready() == 0) {
            riva_pump_timers_and_events();
            dsa_platform_present();
            Sleep(4);
        }
        return dsa_platform_key_read();
    }
    if (cmd == _KEYBRD_READY) {
        unsigned short r = dsa_platform_key_ready();
        if (r == 0) {
            uint32_t now = dsa_platform_get_ticks_ms();
            if (now == g_key_poll_last_ms) {
                if (++g_key_poll_counter >= 32) {
                    g_key_poll_counter = 0;
                    Sleep(1);
                }
            } else {
                g_key_poll_last_ms = now;
                g_key_poll_counter = 0;
            }
        }
        return r;
    }
    if (cmd == _KEYBRD_SHIFTSTATUS) {
        return dsa_platform_key_shift_status();
    }
    return 0;
}

/* PC-Lautsprecher (sound/nosound, Fehlerbildschirm). Menueklicks hatten 1996 keinen Ton. */
static int      g_spk_freq  = 0;
static unsigned g_spk_phase = 0;

extern "C" void port_sound(unsigned freq) {
    g_spk_freq = (freq > 40u && freq < 20000u) ? (int)freq : 0;
    g_spk_phase = 0;
}
extern "C" void port_nosound(void) { g_spk_freq = 0; }

/* =========================================================================
 * 3. VESA-Info-Befuellung & Software-Interrupts (f_149cd2, f_145702, f_149caa)
 * ========================================================================= */

static void fill_vesa_controller_info(unsigned char *buf) {
    unsigned short *modes;
    if (!buf) return;
    memset(buf, 0, 512);
    memcpy(buf, "VESA", 4);
    *(unsigned short *)(buf + 4) = 0x0200; /* VESA 2.0 */
    /* OEM-String und Modusliste liegen im hinteren Teil von buf */
    strcpy((char *)(buf + 0x80), "DSA Nordlandtrilogie SDL2 VESA 2.0");
    *(unsigned short *)(buf + 6)  = (unsigned short)((uintptr_t)(buf + 0x80) & 0x0F);
    *(unsigned short *)(buf + 8)  = (unsigned short)((uintptr_t)(buf + 0x80) >> 4);
    modes = (unsigned short *)(buf + 0xC0);
    modes[0] = 0x0100; /* 640x400x256 */
    modes[1] = 0x0101; /* 640x480x256 */
    modes[2] = 0xFFFF;
    *(unsigned short *)(buf + 14) = (unsigned short)((uintptr_t)modes & 0x0F);
    *(unsigned short *)(buf + 16) = (unsigned short)((uintptr_t)modes >> 4);
    *(unsigned short *)(buf + 18) = 64; /* 64 * 64 KB = 4 MB VRAM */
}

static void fill_vesa_mode_info(unsigned char *buf, unsigned short mode) {
    unsigned short w = 640, h = 480;
    if (!buf) return;
    if (mode == 0x13)       { w = 320; h = 200; }
    else if (mode == 0x100) { w = 640; h = 400; }
    else if (mode == 0x101) { w = 640; h = 480; }
    memset(buf, 0, 256);
    *(unsigned short *)(buf + 0)  = 0x009B; /* ModeAttributes: unterstützt, Grafik, Farbe */
    buf[2]                        = 0x07;   /* WinAAttributes: les-/schreibbar */
    buf[3]                        = 0x00;   /* WinBAttributes */
    *(short *)(buf + 4)           = 0x1000; /* WinGranularity: 4096 KB (4 MB linear!) */
    *(short *)(buf + 6)           = 0x1000; /* WinSize: 4096 KB */
    *(unsigned short *)(buf + 8)  = 0xA000; /* WinASegment */
    *(unsigned short *)(buf + 10) = 0x0000; /* WinBSegment */
    *(unsigned short *)(buf + 16) = w;      /* BytesPerScanLine (s10) */
    *(unsigned short *)(buf + 18) = w;      /* XResolution (s12) */
    *(unsigned short *)(buf + 20) = h;      /* YResolution (s14) */
    buf[22]                       = 8;      /* XCharSize */
    buf[23]                       = 16;     /* YCharSize */
    buf[24]                       = 1;      /* NumberOfPlanes */
    buf[25]                       = 8;      /* BitsPerPixel */
    buf[26]                       = 1;      /* NumberOfBanks */
    buf[27]                       = 4;      /* MemoryModel: Packed Pixel */
}

extern "C" void f_149caa(void *sregs) {
    if (sregs) {
        memset(sregs, 0, sizeof(struct SREGS));
    }
}

extern "C" int f_145702(int intno, void *in_ptr, void *out_ptr, void *sregs_ptr) {
    union REGS  in_r;
    union REGS *out_r = (union REGS *)out_ptr;
    (void)sregs_ptr;

    if (!in_ptr) return 0;
    memcpy(&in_r, in_ptr, sizeof(union REGS));
    if (out_r && out_ptr != in_ptr) {
        memcpy(out_r, &in_r, sizeof(union REGS));
    }
    if (!out_r) out_r = &in_r;
    out_r->x.cflag = 0;

    switch (intno) {
    case 0x10: /* VGA / VESA Video-BIOS */
        if (in_r.h.ah == 0x00) {
            int m = in_r.h.al & 0x7F;
            if (m == 0x13) {
                dsa_platform_set_mode(0x13, 320, 200);
            }
        } else if (in_r.h.ah == 0x0F) {
            out_r->h.al = 0x13;
            out_r->h.ah = 80;
            out_r->h.bh = 0;
        } else if (in_r.w.ax == 0x4F00) {
            fill_vesa_controller_info(d_1c1104 ? d_1c1104 : g_fallback_vbe_info);
            out_r->w.ax = 0x004F;
        } else if (in_r.w.ax == 0x4F01) {
            fill_vesa_mode_info(d_1c1108 ? d_1c1108 : g_fallback_mode_info, in_r.w.cx);
            out_r->w.ax = 0x004F;
        } else if (in_r.w.ax == 0x4F02) {
            unsigned short m = in_r.w.bx & 0x3FFF;
            fill_vesa_mode_info(d_1c1108 ? d_1c1108 : g_fallback_mode_info, m);
            dsa_platform_set_mode(m, 0, 0);
            out_r->w.ax = 0x004F;
        } else if (in_r.w.ax == 0x4F05 || in_r.w.ax == 0x4F06 || in_r.w.ax == 0x4F07) {
            riva_pump_timers_and_events();
            out_r->w.ax = 0x004F;
        }
        break;

    case 0x21: /* DOS-Systemaufrufe */
        if (in_r.h.ah == 0x19) {
            out_r->h.al = 2; /* C: */
        } else if (in_r.h.ah == 0x2A) {
            out_r->w.cx = 1996;
            out_r->h.dh = 11;
            out_r->h.dl = 16;
            out_r->h.al = 6;
        } else if (in_r.h.ah == 0x2C) {
            out_r->h.ch = 12;
            out_r->h.cl = 0;
            out_r->h.dh = 0;
            out_r->h.dl = 0;
        } else if (in_r.h.ah == 0x34) {
            out_r->x.ebx = (unsigned int)(uintptr_t)&g_indos_flag;
        } else if (in_r.h.ah == 0x36) {
            out_r->w.ax = 64;
            out_r->w.bx = 32000;
            out_r->w.cx = 512;
            out_r->w.dx = 64000;
        } else if (in_r.h.ah == 0x47) {
            char *dir_buf = (char *)(uintptr_t)in_r.x.esi;
            if (dir_buf) dir_buf[0] = '\0';
            out_r->x.cflag = 0;
        }
        break;

    case 0x2F: /* MSCDEX CD-ROM */
        if (in_r.w.ax == 0x1500) {
            out_r->w.bx = 1;
            out_r->w.cx = 2; /* C: */
        } else if (in_r.w.ax == 0x150B) {
            out_r->w.ax = 1;
            out_r->w.bx = 0xADAD;
        } else if (in_r.w.ax == 0x150C) {
            out_r->w.bx = 0x0215;
        }
        break;

    case 0x31: /* DPMI */
        if (in_r.w.ax == 0x0100) {
            out_r->x.eax = (unsigned int)(uintptr_t)calloc(1, ((size_t)in_r.w.bx + 16) * 16);
            out_r->w.dx = 1;
            out_r->x.cflag = 0;
        } else if (in_r.w.ax == 0x0300 && in_r.h.bl == 0x10) {
            /* Simulierter Real-Mode-Interrupt 0x10 ueber d_1c10d0 */
            unsigned short vbe_ax = (unsigned short)(d_1c10d0.eax & 0xFFFF);
            if (vbe_ax == 0x4F00) {
                fill_vesa_controller_info(d_1c1104 ? d_1c1104 : g_fallback_vbe_info);
                d_1c10d0.eax = 0x004F;
            } else if (vbe_ax == 0x4F01) {
                fill_vesa_mode_info(d_1c1108 ? d_1c1108 : g_fallback_mode_info, (unsigned short)d_1c10d0.ecx);
                d_1c10d0.eax = 0x004F;
            } else if (vbe_ax == 0x4F04) {
                d_1c10d0.ebx = 1;
                d_1c10d0.eax = 0x004F;
            } else {
                d_1c10d0.eax = 0x004F;
            }
            out_r->x.cflag = 0;
        } else if (in_r.w.ax == 0x0300 && in_r.h.bl == 0x33) {
            /* Simulierter Real-Mode-Interrupt 0x33 (Maustreiber-Reset ueber f_05fc00 / d_1bd68c) */
            struct DpmiRealModeRegs *rm = (struct DpmiRealModeRegs *)(uintptr_t)in_r.x.edi;
            if (rm) {
                unsigned short m_ax = (unsigned short)(rm->eax & 0xFFFF);
                if (m_ax == 0x0000 || m_ax == 0x0021) {
                    rm->eax = 0xFFFFFFFFu; /* -1 = Maustreiber installiert */
                    rm->ebx = 2;           /* 2 Maustasten */
                }
            }
            out_r->x.cflag = 0;
        } else if (in_r.w.ax == 0x0300 && in_r.h.bl == 0x2F) {
            /* Simulierter Real-Mode-Interrupt 0x2F (MSCDEX ueber f_05fc00 / d_1bd68c) */
            struct DpmiRealModeRegs *rm = (struct DpmiRealModeRegs *)(uintptr_t)in_r.x.edi;
            if (rm) {
                unsigned short cd_ax = (unsigned short)(rm->eax & 0xFFFF);
                if (cd_ax == 0x1500)      { rm->ebx = 1; rm->ecx = 2; }
                else if (cd_ax == 0x150B) { rm->eax = 1; rm->ebx = 0xADAD; }
                else if (cd_ax == 0x150C) { rm->ebx = 0x0215; }
            }
            out_r->x.cflag = 0;
        } else if (in_r.w.ax == 0x0500) {
            unsigned int *mem_info = (unsigned int *)(uintptr_t)in_r.x.edi;
            if (mem_info) {
                memset(mem_info, 0, 48);
                mem_info[0] = 0x02000000; /* 32 MB freier Speicher */
                mem_info[1] = 0x00002000;
                mem_info[2] = 0x00002000;
            }
            out_r->x.cflag = 0;
        } else {
            out_r->w.ax = 0;
            out_r->x.cflag = 0;
        }
        break;

    case 0x33: /* DOS-Maustreiber (Int 0x33) */
        switch (in_r.w.ax) {
        case 0x0000: /* Reset Driver */
        case 0x0021: /* Software Reset */
            out_r->x.eax = 0xFFFFFFFFu; /* (short)-1 = Maustreiber installiert */
            out_r->x.ebx = 2;           /* 2 Tasten */
            break;
        case 0x0003: { /* Get Position & Button Status */
            int mx = 0, my = 0, mbtn = 0;
            dsa_platform_get_mouse(&mx, &my, &mbtn);
            out_r->x.ebx = (unsigned int)mbtn;
            out_r->x.ecx = (unsigned int)mx;
            out_r->x.edx = (unsigned int)my;
            break;
        }
        case 0x0004: /* Set Mouse Position */
            dsa_platform_set_mouse_pos((int)(short)in_r.w.cx, (int)(short)in_r.w.dx);
            break;
        case 0x0007: /* Set Horizontal Range */
            dsa_platform_set_mouse_range_x((int)(short)in_r.w.cx, (int)(short)in_r.w.dx);
            break;
        case 0x0008: /* Set Vertical Range */
            dsa_platform_set_mouse_range_y((int)(short)in_r.w.cx, (int)(short)in_r.w.dx);
            break;
        case 0x000B: /* Read Motion Counters */
            out_r->x.ecx = 0;
            out_r->x.edx = 0;
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }

    return (int)out_r->x.eax;
}

extern "C" int f_149cd2(int intno, void *in_ptr, void *out_ptr) {
    return f_145702(intno, in_ptr, out_ptr, NULL);
}

/* =========================================================================
 * 4. VGA-, Paletten-, Tastatur-, Timer- und CD-Funktionen
 * ========================================================================= */

extern "C" int f_0ce0b0(void) {
    return 3; /* Laufwerk C: ('@' + 3 == 'C') */
}

extern "C" void *f_01ebd0(void *self) {
    return self;
}

static void riva_trace(const char *fmt, ...);

/* CD-Laufwerks- und Geschwindigkeits-Abfragen (Original vorhanden) */
extern "C" char d_1a96a4[];
extern "C" int f_0d3c75(void) {
    if (!d_1a96a4[0]) strcpy(d_1a96a4, "C:\\RIVA");
    return 1;
}
extern "C" int f_0d3df6(void *m, int a, int b) {
    (void)a; (void)b;
    if (!d_1a96a4[0]) strcpy(d_1a96a4, "C:\\RIVA");
    if (m && (uintptr_t)m >= 0x10000u) {
        *(int *)((char *)m + 0x12)   = 1; /* open = 1 (CD eingelegt) */
        *(short *)((char *)m + 0x42) = 1; /* s42 = 1 */
        *(int *)((char *)m + 0x4c)   = 1; /* i4c = 1 (CD initialisiert) */
    }
    return 1;
}
extern "C" unsigned char f_0d451f(void *self, int a, int b) { (void)self; (void)a; (void)b; return 64; }

extern "C" void f_149cf0(unsigned int ms) {
    /* In f_09a4c0 (Pixel-Aufloeseblende beim Betreten/Verlassen von Gebaeuden/Haendlern)
     * wird f_149cf0(1) 640-mal pro Vollbild aufgerufen (alle 100 Pixel).
     * Unter Windows fuehrten 640 Einzel-Sleeps zu ~2,5s Wartezeit pro Blende;
     * wir fassen kurze 1-ms-Schritte zu 64er-Bloecken (~100 ms Gesamtblende) zusammen. */
    if (ms <= 2) {
        static unsigned int s_sub_accum = 0;
        if ((++s_sub_accum & 63u) != 0) return;
        dsa_platform_delay_ms(1);
        return;
    }
    dsa_platform_delay_ms(ms);
}

extern "C" int f_149d20(void) {
    riva_pump_timers_and_events();
    while (dsa_platform_key_ready() != 0) {
        dsa_platform_key_read();
    }
    return 0;
}

extern "C" void f_149d38(void) {}

extern "C" int f_149d50(void) {
    while (dsa_platform_key_ready() != 0) {
        dsa_platform_key_read();
    }
    return (int)port_bios_keybrd(_KEYBRD_READ);
}

extern "C" int f_149d80(void) {
    return port_bios_keybrd(_KEYBRD_READY) != 0;
}

extern "C" int f_149d9b(void) {
    return (int)port_bios_keybrd(_KEYBRD_SHIFTSTATUS);
}

extern "C" void f_149dbe(short *mode_info) {
    if (mode_info) {
        mode_info[0] = 0;
        mode_info[1] = 3;
        mode_info[2] = 80;
        mode_info[3] = 25;
    }
}

extern "C" void f_149dea(void) {
    riva_pump_timers_and_events();
    dsa_platform_wait_vsync();
}

extern "C" void f_149dfe(const void *mode_info) {
    (void)mode_info;
}

extern "C" void f_149e0f(const unsigned char *pal, int count) {
    dsa_platform_set_palette_range(0, count, pal);
}

extern "C" void f_149e2e(const unsigned char *rgb, int idx) {
    if (rgb) {
        dsa_platform_set_palette_entry(idx & 0xFF, rgb[0], rgb[1], rgb[2]);
        dsa_platform_pump_and_present_if_due();
    }
}

extern "C" void f_149e58(const unsigned char *pal, int first, int count) {
    dsa_platform_set_palette_range(first, count, pal);
}

extern "C" void f_149e89(unsigned char *rgb, int idx) {
    if (rgb) {
        dsa_platform_get_palette_entry(idx & 0xFF, &rgb[0], &rgb[1], &rgb[2]);
    }
}

extern "C" void f_149eb4(unsigned char *buf, int first, int count) {
    dsa_platform_get_palette_range(first, count, buf);
}

/* HMI-SOS-Timer-, Digital-Sound-, CD-Musik- (Ogg Vorbis) und RAD-Smacker-Video-System */
static void riva_trace(const char *fmt, ...);

extern "C" {
int  f_144fbf(const char *path, int oflag, ...);
int  f_144e8b(int fd, void *buf, unsigned int cnt);
long f_145279(int fd, long offset, int whence);
int  f_145259(int fd);
long f_1455a4(int fd);
void *f_15b990(void *p, int cap);
int  f_146d86(int p, int p2);
void f_169845(void);

extern char *d_1af4c8[];
extern int   d_1a9698;
extern void (*d_1ce430)(void);
extern unsigned char riva_dgroup_base[];
}

/* Hypertext-Vektor-Konstruktoren (f_15c4e0, f_15c500 -> f_15b990(p, 16)) */
extern "C" void *f_15c4e0(void *p) { return f_15b990(p, 0x10); }
extern "C" void *f_15c500(void *p) { return f_15b990(p, 0x10); }

/* -------------------------------------------------------------------------
 * 4a. WinMM waveOut 44.1 kHz 16-Bit-Stereo-Mischer + Ogg Vorbis CD-Musik
 * ------------------------------------------------------------------------- */
#define RIVA_AUDIO_RATE       44100
#define RIVA_AUDIO_BUF_FRAMES 1024
#define RIVA_AUDIO_NUM_BUFS   8

static HWAVEOUT g_hWaveOut = NULL;
static int      g_waveout_tried = 0;
static WAVEHDR  g_wave_hdrs[RIVA_AUDIO_NUM_BUFS];
static int16_t  g_wave_bufs[RIVA_AUDIO_NUM_BUFS][RIVA_AUDIO_BUF_FRAMES * 2];
static int      g_wave_prepared[RIVA_AUDIO_NUM_BUFS];

/* Smacker-Audio-Ringpuffer (44100 Hz Stereo 16-Bit) */
#define SMK_AUDIO_RING_FRAMES 131072
static int16_t  g_smk_audio_ring[SMK_AUDIO_RING_FRAMES * 2];
static uint32_t g_smk_audio_read  = 0;
static uint32_t g_smk_audio_write = 0;

static void smk_audio_clear(void) {
    g_smk_audio_read  = 0;
    g_smk_audio_write = 0;
}

static void smk_audio_push_frame(int16_t l, int16_t r) {
    uint32_t next_w = (g_smk_audio_write + 1u) & (SMK_AUDIO_RING_FRAMES - 1u);
    if (next_w == g_smk_audio_read) return;
    g_smk_audio_ring[g_smk_audio_write * 2 + 0] = l;
    g_smk_audio_ring[g_smk_audio_write * 2 + 1] = r;
    g_smk_audio_write = next_w;
}

/* Eingebetteter stb_vorbis-Decoder (Public Domain / MIT) fuer MUSIC/Track02..13.ogg */
struct stb_vorbis;
struct stb_vorbis_alloc;
extern "C" stb_vorbis *stb_vorbis_open_filename(const char *filename, int *error, const stb_vorbis_alloc *alloc_buffer);
extern "C" int stb_vorbis_get_samples_short_interleaved(stb_vorbis *f, int channels, short *buffer, int num_shorts);
extern "C" int stb_vorbis_seek_start(stb_vorbis *f);
extern "C" void stb_vorbis_close(stb_vorbis *f);

static stb_vorbis       *g_ogg_stb       = NULL;
static int               g_ogg_open      = 0;
static int               g_ogg_playing   = 0;
static int               g_ogg_enabled   = 1;
static short             g_ogg_cur_track = 0;
static short             g_ogg_vol       = 100;
static int               g_ogg_channels  = 2;

static void riva_ogg_stop(void) {
    g_ogg_playing = 0;
    if (g_ogg_open && g_ogg_stb) {
        stb_vorbis_close(g_ogg_stb);
        g_ogg_stb = NULL;
    }
    g_ogg_open = 0;
}

static void riva_ogg_start_track(short logic_track) {
    if (!g_ogg_enabled || logic_track <= 0) {
        riva_ogg_stop();
        return;
    }
    if (g_ogg_playing && g_ogg_open && g_ogg_cur_track == logic_track) {
        return;
    }
    riva_ogg_stop();
    g_ogg_cur_track = logic_track;

    /* d_1a5a1c (Offset 0x5a1c in DGROUP) bildet Musik-ID 1..12 auf CD-Track 2..13 ab */
    const short *track_tab = (const short *)(riva_dgroup_base + 0x5a1c);
    int cd_track = (logic_track >= 1 && logic_track <= 12) ? (int)track_tab[logic_track] : 0;
    if (cd_track < 2 || cd_track > 13) {
        cd_track = (int)logic_track + 1;
    }
    if (cd_track < 2 || cd_track > 13) return;

    char rel_path[64], full_path[600];
    snprintf(rel_path, sizeof(rel_path), "MUSIC\\Track%02d.ogg", cd_track);
    dsa_platform_resolve_path(rel_path, full_path, sizeof(full_path));
    int err = 0;
    g_ogg_stb = stb_vorbis_open_filename(full_path, &err, NULL);
    if (g_ogg_stb) {
        g_ogg_open     = 1;
        g_ogg_playing  = 1;
        g_ogg_channels = 2;
        riva_trace("[cd-music] playing logic=%d -> %s\n", (int)logic_track, full_path);
    }
}

extern "C" int f_02fcb7(void *m) {
    if (m && (uintptr_t)m >= 0x10000u) {
        *(short *)((char *)m + 0x3a) = 0;
        *(int *)((char *)m + 0x12)   = 1;
        *(int *)((char *)m + 10)     = g_ogg_playing ? 1 : 0;
    }
    return g_ogg_playing ? 1 : 0;
}

extern "C" void f_0d3f25(void *m, int track) {
    short trk = (short)track;
    if (m && (uintptr_t)m >= 0x10000u) {
        *(short *)((char *)m + 0x3c) = trk;
        *(int *)((char *)m + 0x12)   = 1;
        *(int *)((char *)m + 0x4c)   = 1;
    }
    if (trk > 0 && g_ogg_enabled) {
        riva_ogg_start_track(trk);
        if (m && (uintptr_t)m >= 0x10000u) {
            *(int *)((char *)m + 10) = g_ogg_playing ? 1 : 0;
        }
    }
}

extern "C" int f_0d4070(void *m) {
    riva_ogg_stop();
    if (m && (uintptr_t)m >= 0x10000u) {
        *(int *)((char *)m + 10) = 0;
    }
    return 0;
}

extern "C" short f_0d40b6(void *m) {
    if (m && (uintptr_t)m >= 0x10000u) {
        return *(short *)((char *)m + 0x3c);
    }
    return g_ogg_cur_track;
}

extern "C" int f_0d40dd(void *m) {
    if (m && (uintptr_t)m >= 0x10000u) {
        return (int)*((signed char *)m + 0x47);
    }
    return g_ogg_enabled;
}

extern "C" short f_0d4103(void *m) {
    if (m && (uintptr_t)m >= 0x10000u) {
        return *(short *)((char *)m + 0x40);
    }
    return g_ogg_vol;
}

extern "C" void f_0d412a(void *m, int v) {
    g_ogg_vol = (short)v;
    if (m && (uintptr_t)m >= 0x10000u) {
        *(short *)((char *)m + 0x40) = (short)v;
    }
}

extern "C" int f_0d4163(void *m) {
    (void)m;
    riva_audio_pump();
    return 0;
}

extern "C" void f_0d4248(void *m, int enable) {
    g_ogg_enabled = (enable != 0) ? 1 : 0;
    if (m && (uintptr_t)m >= 0x10000u) {
        *((unsigned char *)m + 0x47) = (unsigned char)g_ogg_enabled;
    }
    if (!g_ogg_enabled) {
        riva_ogg_stop();
    }
}

extern "C" unsigned int f_0d4394(void) {
    static unsigned int s_cd_tick = 100;
    return ++s_cd_tick;
}

extern "C" void f_0d448c(short a, short b, void *p) {
    (void)a; (void)b; (void)p;
}

/* Hilfsfunktion: entfernt Sample-Slot r aus der verketteten SOS-Liste PT(b, 0x30) */
static void sos_unlink_slot(char *b, char *r) {
    char **pp = (char **)(b + 0x30);
    while (*pp) {
        if (*pp == r) {
            *pp = *(char **)(r + 0xec);
            break;
        }
        pp = (char **)(*pp + 0xec);
    }
    *(char **)(r + 0xec) = NULL;
    *(unsigned char *)(r + 0x21) = 0;
}

static uint64_t g_stat_ogg_nonzero_frames = 0;
static uint64_t g_stat_smk_nonzero_frames = 0;
static uint64_t g_stat_sos_nonzero_frames = 0;
static uint64_t g_stat_sos_stream_reloads = 0;

extern "C" void riva_write_audio_stats(void) {
    const char *al = getenv("RIVA_AUDIO_LOG");
    riva_trace("[audio-log] ogg_nonzero_frames=%llu smk_nonzero_frames=%llu sos_nonzero_frames=%llu sos_stream_reloads=%llu ogg_last_track=%d ogg_vol=%d ogg_enabled=%d\n",
               (unsigned long long)g_stat_ogg_nonzero_frames,
               (unsigned long long)g_stat_smk_nonzero_frames,
               (unsigned long long)g_stat_sos_nonzero_frames,
               (unsigned long long)g_stat_sos_stream_reloads,
               g_ogg_cur_track, g_ogg_vol, g_ogg_enabled);
    if (!al || al[0] != '1') return;
    FILE *fp = fopen("audio_stats.log", "w");
    if (!fp) return;
    fprintf(fp, "ogg_nonzero_frames=%llu\n", (unsigned long long)g_stat_ogg_nonzero_frames);
    fprintf(fp, "smk_nonzero_frames=%llu\n", (unsigned long long)g_stat_smk_nonzero_frames);
    fprintf(fp, "sos_nonzero_frames=%llu\n", (unsigned long long)g_stat_sos_nonzero_frames);
    fprintf(fp, "sos_stream_reloads=%llu\n", (unsigned long long)g_stat_sos_stream_reloads);
    fprintf(fp, "ogg_last_track=%d ogg_vol=%d ogg_enabled=%d\n", g_ogg_cur_track, g_ogg_vol, g_ogg_enabled);
    fclose(fp);
}

static void riva_audio_init_waveout(void) {
    if (g_waveout_tried) return;
    g_waveout_tried = 1;
    atexit(riva_write_audio_stats);
    const char *hl = getenv("RIVA_HEADLESS");
    if (hl && hl[0] == '1') {
        /* Im Headless-Testbetrieb kein physisches waveOut-Geraet oeffnen, damit der Desktop stumm bleibt */
        return;
    }
    WAVEFORMATEX wfx;
    memset(&wfx, 0, sizeof(wfx));
    wfx.wFormatTag      = WAVE_FORMAT_PCM;
    wfx.nChannels       = 2;
    wfx.nSamplesPerSec  = RIVA_AUDIO_RATE;
    wfx.wBitsPerSample  = 16;
    wfx.nBlockAlign     = 4;
    wfx.nAvgBytesPerSec = RIVA_AUDIO_RATE * 4;
    if (waveOutOpen(&g_hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) == MMSYSERR_NOERROR && g_hWaveOut) {
        for (int i = 0; i < RIVA_AUDIO_NUM_BUFS; ++i) {
            memset(&g_wave_hdrs[i], 0, sizeof(WAVEHDR));
            g_wave_hdrs[i].lpData         = (LPSTR)g_wave_bufs[i];
            g_wave_hdrs[i].dwBufferLength = RIVA_AUDIO_BUF_FRAMES * 4;
            if (waveOutPrepareHeader(g_hWaveOut, &g_wave_hdrs[i], sizeof(WAVEHDR)) == MMSYSERR_NOERROR) {
                g_wave_prepared[i] = 1;
                g_wave_hdrs[i].dwFlags |= WHDR_DONE;
            }
        }
    }
}

static void riva_mix_one_buffer(int16_t *out_stereo, int frames) {
    int32_t acc[RIVA_AUDIO_BUF_FRAMES * 2];
    memset(acc, 0, (size_t)frames * 2 * sizeof(int32_t));

    /* 1. Ogg Vorbis CD-Musik einmischen (stb_vorbis) */
    if (g_ogg_playing && g_ogg_open && g_ogg_enabled && g_ogg_stb) {
        int16_t ogg_tmp[RIVA_AUDIO_BUF_FRAMES * 2];
        int frames_got = 0;
        while (frames_got < frames) {
            int n = stb_vorbis_get_samples_short_interleaved(
                g_ogg_stb, 2,
                ogg_tmp + frames_got * 2,
                (frames - frames_got) * 2
            );
            if (n > 0) {
                frames_got += n;
            } else {
                if (!stb_vorbis_seek_start(g_ogg_stb)) break;
                n = stb_vorbis_get_samples_short_interleaved(
                    g_ogg_stb, 2,
                    ogg_tmp + frames_got * 2,
                    (frames - frames_got) * 2
                );
                if (n <= 0) break;
                frames_got += n;
            }
        }
        int got_frames = frames_got;
        int mvol = (g_ogg_vol > 0 && g_ogg_vol <= 100) ? (int)g_ogg_vol : 75;
        for (int f = 0; f < got_frames; ++f) {
            int32_t l = ogg_tmp[f * 2 + 0];
            int32_t r = ogg_tmp[f * 2 + 1];
            if (l != 0 || r != 0) g_stat_ogg_nonzero_frames++;
            acc[f * 2 + 0] += (l * mvol) / 140;
            acc[f * 2 + 1] += (r * mvol) / 140;
        }
    }

    /* 2. Smacker-Video/Sprach-Audio einmischen */
    for (int f = 0; f < frames; ++f) {
        if (g_smk_audio_read == g_smk_audio_write) break;
        int16_t sl = g_smk_audio_ring[g_smk_audio_read * 2 + 0];
        int16_t sr = g_smk_audio_ring[g_smk_audio_read * 2 + 1];
        if (sl != 0 || sr != 0) g_stat_smk_nonzero_frames++;
        acc[f * 2 + 0] += sl;
        acc[f * 2 + 1] += sr;
        g_smk_audio_read = (g_smk_audio_read + 1u) & (SMK_AUDIO_RING_FRAMES - 1u);
    }

    /* 3. HMI SOS Digital-Sound-Kanaele (d_1af4c8[0]) einmischen */
    char *b = d_1af4c8[0];
    if (b && *(char **)(b + 0x58)) {
        char *recs = *(char **)(b + 0x58);
        int max_slots = *(int *)(b + 0x14);
        if (max_slots <= 0 || max_slots > 32) max_slots = 32;
        int active_cnt = 0;
        for (int i = 0; i < max_slots; ++i) {
            char *r = recs + i * 0xf0;
            unsigned char fl = *(unsigned char *)(r + 0x21);
            if (!(fl & 0x80)) continue;
            if (fl & 0x40) {
                void (*cb_done)(void *) = *(void (**)(void *))(r + 0x60);
                sos_unlink_slot(b, r);
                if (cb_done && f_146d86(d_1a9698, i) != 0) cb_done(r);
                continue;
            }
            active_cnt++;
            uint8_t *start_p = *(uint8_t **)(r + 0x00);
            uint8_t *cur_p   = *(uint8_t **)(r + 0x04);
            uint32_t len     = *(uint32_t *)(r + 0x0c);
            uint32_t rate    = *(uint32_t *)(r + 0x34);
            if (rate < 2000u || rate > 48000u) rate = 11025u;
            int bits         = *(int *)(r + 0x38);
            int ch           = *(int *)(r + 0x3c);
            if (ch < 1 || ch > 2) ch = 1;
            int bytes_per_smp = ((bits == 16) ? 2 : 1) * ch;
            int is_unsigned  = (*(int *)(r + 0x40) & 0x8000) != 0;
            int32_t vol      = (int32_t)(*(uint32_t *)(r + 0x2c) & 0x7FFFu);
            int32_t pan      = (int32_t)(*(uint32_t *)(r + 0x44) & 0xFFFFu);
            int32_t gain_l   = (vol * (0x10000 - pan)) >> 15;
            int32_t gain_r   = (vol * pan) >> 15;
            uint32_t frac    = *(uint32_t *)(r + 0x80);
            uint32_t step    = (rate << 16) / (uint32_t)RIVA_AUDIO_RATE;

            for (int f = 0; f < frames; ++f) {
                if (!start_p || !cur_p || (uint32_t)(cur_p - start_p) + (uint32_t)bytes_per_smp > len) {
                    /* Pufferende erreicht: pruefe Streaming-Nachladung (cb_stream = f_146809) */
                    void (*cb_stream)(void *) = *(void (**)(void *))(r + 0x5c);
                    int hm_ptr = f_146d86(d_1a9698, i);
                    if (cb_stream && hm_ptr != 0) {
                        int hm_c = *(int *)((char *)(uintptr_t)hm_ptr + 0x0e);
                        int hm_d = *(int *)((char *)(uintptr_t)hm_ptr + 0x12);
                        short hm_idx = *(short *)((char *)(uintptr_t)hm_ptr + 0x1a);
                        if (hm_c == 1) {
                            g_stat_sos_stream_reloads++;
                            *(uint32_t *)(r + 0x0c) = 0;
                            cb_stream(r);
                            /* Markiere Wechselpuffer als verbraucht, bis f_146389 neu nachlaedt */
                            if (hm_idx == 0 || hm_idx == 1) {
                                *(uint32_t *)((char *)(uintptr_t)hm_ptr + 0x3a + hm_idx * 0xf0 + 0x0c) = 0;
                            }
                            start_p = *(uint8_t **)(r + 0x00);
                            cur_p   = start_p;
                            len     = *(uint32_t *)(r + 0x0c);
                            *(uint8_t **)(r + 0x04) = cur_p;
                        } else if (hm_d == 0) {
                            /* Hauptschleife (f_146dfa) hat den naechsten Block noch nicht gelesen -> warten */
                            break;
                        } else {
                            len = 0;
                        }
                    } else {
                        len = 0;
                    }
                    if (len == 0) {
                        int loops = *(int *)(r + 0x48);
                        if (loops == -1 || loops > 0) {
                            if (loops > 0) *(int *)(r + 0x48) = loops - 1;
                            cur_p = start_p;
                            len   = *(uint32_t *)(r + 0x0c);
                        } else {
                            void (*cb_done)(void *) = *(void (**)(void *))(r + 0x60);
                            sos_unlink_slot(b, r);
                            if (cb_done && hm_ptr != 0) cb_done(r);
                            cur_p = NULL;
                            break;
                        }
                    }
                }
                if (!cur_p) break;

                int32_t sl = 0, sr = 0;
                if (bits == 16) {
                    sl = *(const int16_t *)cur_p;
                    sr = (ch == 2) ? *((const int16_t *)cur_p + 1) : sl;
                } else if (is_unsigned) {
                    sl = ((int32_t)cur_p[0] - 128) << 8;
                    sr = (ch == 2) ? (((int32_t)cur_p[1] - 128) << 8) : sl;
                } else {
                    sl = ((int32_t)(*(const int8_t *)cur_p)) << 8;
                    sr = (ch == 2) ? (((int32_t)(*((const int8_t *)cur_p + 1))) << 8) : sl;
                }
                if (sl != 0 || sr != 0) g_stat_sos_nonzero_frames++;
                acc[f * 2 + 0] += (sl * gain_l) >> 15;
                acc[f * 2 + 1] += (sr * gain_r) >> 15;

                frac += step;
                uint32_t adv_smp = frac >> 16;
                frac &= 0xFFFFu;
                if (adv_smp > 0) {
                    uint32_t adv_bytes = adv_smp * (uint32_t)bytes_per_smp;
                    cur_p += adv_bytes;
                    *(uint32_t *)(r + 0x58) += adv_bytes;
                }
            }
            if (*(unsigned char *)(r + 0x21) & 0x80) {
                *(uint8_t **)(r + 0x04) = cur_p;
                *(uint32_t *)(r + 0x80) = frac;
            }
        }
        *(int *)(b + 0x54) = active_cnt;
    }

    if (g_spk_freq > 0) {
        const int spk_period = (g_spk_freq > 40) ? (44100 / g_spk_freq) : 2;
        for (int f = 0; f < frames; ++f) {
            int32_t s = (g_spk_phase < (unsigned)(spk_period / 2)) ? 7000 : -7000;
            if (++g_spk_phase >= (unsigned)spk_period) g_spk_phase = 0;
            acc[f * 2 + 0] += s;
            acc[f * 2 + 1] += s;
        }
    }

    for (int k = 0; k < frames * 2; ++k) {
        int32_t v = acc[k];
        if (v > 32767) v = 32767;
        else if (v < -32768) v = -32768;
        out_stereo[k] = (int16_t)v;
    }
}

static void riva_audio_pump(void) {
    static int s_in_audio_pump = 0;
    if (s_in_audio_pump) return;
    s_in_audio_pump = 1;

    riva_audio_init_waveout();
    if (!g_hWaveOut) {
        /* Falls Headless oder kein Audiogeraet verfuegbar: mit 44.1-kHz-Echtzeittakt (alle ~20 ms je 1024 Frames) mischen */
        static uint32_t s_last_dummy_ms = 0;
        uint32_t now_ms = dsa_platform_get_ticks_ms();
        if (s_last_dummy_ms == 0) s_last_dummy_ms = now_ms;
        int loops = 0;
        while ((int32_t)(now_ms - s_last_dummy_ms) >= 20 && loops < 4) {
            int16_t dummy[RIVA_AUDIO_BUF_FRAMES * 2];
            riva_mix_one_buffer(dummy, RIVA_AUDIO_BUF_FRAMES);
            s_last_dummy_ms += 23;
            loops++;
        }
        s_in_audio_pump = 0;
        return;
    }
    for (int i = 0; i < RIVA_AUDIO_NUM_BUFS; ++i) {
        if (g_wave_prepared[i] && (g_wave_hdrs[i].dwFlags & WHDR_DONE)) {
            riva_mix_one_buffer(g_wave_bufs[i], RIVA_AUDIO_BUF_FRAMES);
            g_wave_hdrs[i].dwFlags &= ~WHDR_DONE;
            waveOutWrite(g_hWaveOut, &g_wave_hdrs[i], sizeof(WAVEHDR));
        }
    }

    s_in_audio_pump = 0;
}

static int riva_audio_is_device_open(void) {
    riva_audio_init_waveout();
    const char *hl = getenv("RIVA_HEADLESS");
    if (hl && hl[0] == '1') return 1;
    return (g_hWaveOut != NULL) ? 1 : 0;
}

extern "C" int f_16886d(int a, int b) { (void)a; (void)b; return 0; }
extern "C" int f_168944(int a)        { (void)a; return 0; }
extern "C" int f_168faf(int a, int b) {
    int audio_ok = riva_audio_is_device_open();
    if (a) {
        char *p1 = (char *)(uintptr_t)a;
        d_1af4c8[0] = p1;
        if (!*(char **)(p1 + 0x58)) {
            *(char **)(p1 + 0x58) = (char *)calloc(32, 0xf0);
        } else {
            memset(*(char **)(p1 + 0x58), 0, 32 * 0xf0);
        }
        *(int *)(p1 + 0x30)  = 0;
        *(int *)(p1 + 0x54)  = 0;
        *(int *)(p1 + 0x2c)  = 0x400;
        *(int *)(p1 + 0x14)  = 0x20;
        *(int *)(p1 + 0x18)  = 60;
        *(int *)(p1 + 0x108) = (int)(uintptr_t)&f_169845;
        *(unsigned char *)p1 = (unsigned char)audio_ok;
        *(int *)(p1 - 100 + 4) = 1; /* II(4) = 1: Timer-System bereit */
        *(int *)(p1 - 100 + 8) = audio_ok ? 1 : 0; /* II(8): Digital-Soundtreiber nur bei offenem Audiogeraet 1 */
    }
    if (b) *(int *)(uintptr_t)b = 0;
    return audio_ok ? 0 : 1;
}
extern "C" int f_169412(int a, int b, int c) {
    (void)b; (void)c;
    if (a >= 0 && a < 5) d_1af4c8[a] = NULL;
    return 0;
}
extern "C" int f_16991e(int a, int b) { (void)a; (void)b; return 0; }
extern "C" int f_16997a(void)         { return 0; }
extern "C" void f_169845(void)        { riva_audio_pump(); }
extern "C" int  f_17c709(void *b)     { (void)b; riva_audio_pump(); return 0; }

/* -------------------------------------------------------------------------
 * 4b. RAD Smacker (SMK2) Video- und Audio-Decoder (f_149f90 .. f_14d040)
 * ------------------------------------------------------------------------- */
struct SmkBits {
    const uint8_t *p, *end;
    uint32_t cur;
    int bits;
    void init(const uint8_t *buf, size_t len) { p = buf; end = buf + len; cur = 0; bits = 0; }
    uint32_t get1(void) {
        if (bits == 0) { cur = (p < end) ? *p++ : 0; bits = 8; }
        uint32_t r = cur & 1u; cur >>= 1; bits--; return r;
    }
    uint32_t get8(void) {
        uint32_t r = 0;
        for (int i = 0; i < 8; ++i) r |= (get1() << i);
        return r;
    }
    uint32_t get16(void) {
        uint32_t lo = get8();
        return lo | (get8() << 8);
    }
};

struct SmkTree8 {
    int n;
    int l[1024], r[1024];
    uint8_t val[1024];
    int build_rec(SmkBits &b) {
        if (n >= 1024) return 0;
        int idx = n++;
        if (b.get1()) {
            l[idx] = build_rec(b);
            r[idx] = build_rec(b);
        } else {
            l[idx] = r[idx] = -1;
            val[idx] = (uint8_t)b.get8();
        }
        return idx;
    }
    void read(SmkBits &b) {
        n = 0;
        if (!b.get1()) return;
        build_rec(b);
        b.get1(); /* Abschliessendes 0-Bit */
    }
    uint8_t decode(SmkBits &b) const {
        if (n == 0) return 0;
        int cur = 0;
        while (l[cur] >= 0) cur = b.get1() ? r[cur] : l[cur];
        return val[cur];
    }
};

#define SMK_MAX_BIGTREE_NODES 131072

struct SmkBigTree {
    int n;
    int l[SMK_MAX_BIGTREE_NODES], r[SMK_MAX_BIGTREE_NODES];
    uint16_t val[SMK_MAX_BIGTREE_NODES];
    int esc_idx[3];
    uint16_t cache[3];
    uint16_t init_cache[3];
    int build_rec(SmkBits &b, const SmkTree8 &lo_t, const SmkTree8 &hi_t, uint16_t esc[3]) {
        if (n >= SMK_MAX_BIGTREE_NODES) return 0;
        int idx = n++;
        if (b.get1()) {
            l[idx] = build_rec(b, lo_t, hi_t, esc);
            r[idx] = build_rec(b, lo_t, hi_t, esc);
        } else {
            l[idx] = r[idx] = -1;
            uint16_t v = (uint16_t)lo_t.decode(b) | ((uint16_t)hi_t.decode(b) << 8);
            val[idx] = v;
            for (int k = 0; k < 3; ++k) {
                if (v == esc[k]) esc_idx[k] = idx;
            }
        }
        return idx;
    }
    void read(SmkBits &b) {
        n = 0;
        esc_idx[0] = esc_idx[1] = esc_idx[2] = -1;
        init_cache[0] = init_cache[1] = init_cache[2] = 0;
        if (!b.get1()) return;
        SmkTree8 lo_t, hi_t;
        lo_t.read(b);
        hi_t.read(b);
        uint16_t esc[3];
        esc[0] = (uint16_t)b.get16();
        esc[1] = (uint16_t)b.get16();
        esc[2] = (uint16_t)b.get16();
        build_rec(b, lo_t, hi_t, esc);
        b.get1(); /* Abschliessendes 0-Bit */
        for (int k = 0; k < 3; ++k) {
            if (esc_idx[k] >= 0) val[esc_idx[k]] = 0;
        }
        reset_mru();
    }
    void reset_mru(void) {
        cache[0] = init_cache[0];
        cache[1] = init_cache[1];
        cache[2] = init_cache[2];
        for (int k = 0; k < 3; ++k) {
            if (esc_idx[k] >= 0) val[esc_idx[k]] = cache[k];
        }
    }
    uint16_t decode(SmkBits &b) {
        if (n == 0) return 0;
        int cur = 0;
        while (l[cur] >= 0) cur = b.get1() ? r[cur] : l[cur];
        uint16_t v = val[cur];
        if (v != cache[0]) {
            cache[2] = cache[1];
            cache[1] = cache[0];
            cache[0] = v;
            for (int k = 0; k < 3; ++k) {
                if (esc_idx[k] >= 0) val[esc_idx[k]] = cache[k];
            }
        }
        return v;
    }
};

#pragma pack(push, 1)
struct RivaSmackInstance {
    /* Oeffentlicher SmackHdr-Bereich (+0x00 .. +0x383), direkt vom Spielcode gelesen */
    uint32_t Version;           /* +0x00 */
    uint32_t Width;             /* +0x04 */
    uint32_t Height;            /* +0x08 */
    uint32_t Frames;            /* +0x0C */
    int32_t  FrameRate;         /* +0x10 */
    uint32_t Flags;             /* +0x14 */
    uint32_t AudioSize[7];      /* +0x18 */
    uint32_t TreesSize;         /* +0x34 */
    uint32_t MMap_Size;         /* +0x38 */
    uint32_t MClr_Size;         /* +0x3C */
    uint32_t Full_Size;         /* +0x40 */
    uint32_t Type_Size;         /* +0x44 */
    uint32_t AudioRate[7];      /* +0x48 */
    uint32_t Dummy;             /* +0x64 */
    uint32_t NewPalette;        /* +0x68 */
    uint8_t  Pal[768];          /* +0x6C */
    uint32_t PalType;           /* +0x36C */
    uint32_t FrameNum;          /* +0x370 */
    uint32_t left;              /* +0x374 */
    uint32_t top;               /* +0x378 */
    uint32_t rectWidth;         /* +0x37C */
    uint32_t rectHeight;        /* +0x380 */

    /* Interne Decoder-Felder ab +0x384 */
    int          fd;
    int          own_fd;
    long         first_frame_off;
    uint32_t     total_frames;
    uint32_t    *frame_sizes;
    uint8_t     *frame_types;
    uint8_t     *frame_buf;
    uint8_t     *dest_buf;
    int          dest_pitch;
    int          dest_height;
    int          dest_left;
    int          dest_top;
    int          rect_pending;
    uint32_t     frame_delay_ms;
    uint32_t     next_frame_ms;
    SmkBigTree  *trees;         /* [0]=mmap, [1]=mclr, [2]=full, [3]=type */
};
#pragma pack(pop)

#define MAX_ACTIVE_SMKS 32
static RivaSmackInstance *g_active_smks[MAX_ACTIVE_SMKS];

static int smk_is_valid(const void *p) {
    if (!p || (uintptr_t)p < 0x10000u) return 0;
    for (int i = 0; i < MAX_ACTIVE_SMKS; ++i) {
        if (g_active_smks[i] == (const RivaSmackInstance *)p) return 1;
    }
    return 0;
}

static void riva_rad_timer_done(void) {}

extern "C" int f_15f4a0(void) {
    d_1ce430 = riva_rad_timer_done;
    return 0;
}

extern "C" int f_14a0b0(void) { return 0; }
extern "C" int f_14bb10(int a) { (void)a; return 0; }
extern "C" int f_14bb30(int a) { (void)a; return 1; }

extern "C" void f_14d040(const unsigned char *pal) {
    if (pal && (uintptr_t)pal >= 0x10000u) {
        dsa_platform_set_palette_range(0, 256, pal);
        dsa_platform_present();
    }
}

static void smk_decode_palette_chunk(RivaSmackInstance *smk, const uint8_t *p, uint32_t chunk_len) {
    uint8_t old_pal[768];
    memcpy(old_pal, smk->Pal, 768);
    const uint8_t *end = p + chunk_len;
    int idx = 0;
    while (p < end && idx < 256) {
        uint8_t b0 = *p++;
        if (b0 & 0x80) {
            idx += (b0 & 0x7F) + 1;
        } else if (b0 & 0x40) {
            if (p >= end) break;
            int cnt = (b0 & 0x3F) + 1;
            int src = *p++;
            for (int k = 0; k < cnt && idx < 256 && src < 256; ++k, ++idx, ++src) {
                memcpy(&smk->Pal[idx * 3], &old_pal[src * 3], 3);
            }
        } else {
            if (p + 1 >= end) break;
            smk->Pal[idx * 3 + 0] = (uint8_t)(b0 & 0x3F);
            smk->Pal[idx * 3 + 1] = (uint8_t)(*p++ & 0x3F);
            smk->Pal[idx * 3 + 2] = (uint8_t)(*p++ & 0x3F);
            idx++;
        }
    }
    smk->NewPalette = 1;
}

static void smk_decode_audio_chunk(RivaSmackInstance *smk, const uint8_t *chunk, uint32_t chunk_len) {
    if (chunk_len <= 4) return;
    uint32_t ar = smk->AudioRate[0];
    uint32_t rate = ar & 0xFFFFFFu;
    if (rate < 2000u || rate > 48000u) return;
    int hdr_stereo = (ar & 0x10000000u) ? 2 : 1;
    int hdr_16bit  = (ar & 0x20000000u) ? 1 : 0;
    int hdr_comp   = (ar & 0x80000000u) ? 1 : 0;

    if (!hdr_comp) {
        const uint8_t *pcm = chunk + 4;
        uint32_t pcm_bytes = chunk_len - 4;
        int bps = (hdr_16bit ? 2 : 1) * hdr_stereo;
        uint32_t total_smp = pcm_bytes / (uint32_t)bps;
        uint32_t out_frames = (uint32_t)(((uint64_t)total_smp * RIVA_AUDIO_RATE) / rate);
        for (uint32_t f = 0; f < out_frames; ++f) {
            uint32_t si = (uint32_t)(((uint64_t)f * rate) / RIVA_AUDIO_RATE);
            if (si >= total_smp) si = total_smp - 1;
            const uint8_t *sp = pcm + si * (uint32_t)bps;
            int16_t l = 0, r = 0;
            if (hdr_16bit) {
                l = *(const int16_t *)sp;
                r = (hdr_stereo == 2) ? *((const int16_t *)sp + 1) : l;
            } else {
                l = (int16_t)(((int32_t)sp[0] - 128) << 8);
                r = (hdr_stereo == 2) ? (int16_t)(((int32_t)sp[1] - 128) << 8) : l;
            }
            smk_audio_push_frame(l, r);
        }
        return;
    }

    if (chunk_len <= 8) return;
    uint32_t uncomp_len = *(const uint32_t *)(chunk + 4);
    if (uncomp_len == 0 || uncomp_len > 0x100000u) return;

    SmkBits ab;
    ab.init(chunk + 8, chunk_len - 8);
    if (!ab.get1()) return;
    int is_stereo = ab.get1() ? 2 : 1;
    int is_16bit  = ab.get1() ? 1 : 0;
    int num_trees = is_stereo * (is_16bit ? 2 : 1);
    SmkTree8 trees[4];
    for (int k = 0; k < num_trees; ++k) trees[k].read(ab);

    int bps = (is_16bit ? 2 : 1) * is_stereo;
    uint32_t total_frames = uncomp_len / (uint32_t)bps;
    if (total_frames == 0) return;

    int16_t *dec_lr = (int16_t *)malloc((size_t)total_frames * 2 * sizeof(int16_t));
    if (!dec_lr) return;

    if (is_16bit) {
        int32_t base[2] = {0, 0};
        for (int c = 0; c < is_stereo; ++c) {
            uint8_t hi = (uint8_t)ab.get8();
            uint8_t lo = (uint8_t)ab.get8();
            base[c] = (int16_t)((hi << 8) | lo);
        }
        dec_lr[0] = (int16_t)base[0];
        dec_lr[1] = (int16_t)((is_stereo == 2) ? base[1] : base[0]);
        for (uint32_t f = 1; f < total_frames; ++f) {
            for (int c = 0; c < is_stereo; ++c) {
                uint8_t lo = trees[c * 2 + 0].decode(ab);
                uint8_t hi = trees[c * 2 + 1].decode(ab);
                base[c] += (int16_t)(lo | (hi << 8));
            }
            dec_lr[f * 2 + 0] = (int16_t)base[0];
            dec_lr[f * 2 + 1] = (int16_t)((is_stereo == 2) ? base[1] : base[0]);
        }
    } else {
        uint8_t base[2] = {0x80, 0x80};
        for (int c = 0; c < is_stereo; ++c) {
            base[c] = (uint8_t)ab.get8();
        }
        dec_lr[0] = (int16_t)(((int32_t)base[0] - 128) << 8);
        dec_lr[1] = (int16_t)(((int32_t)((is_stereo == 2) ? base[1] : base[0]) - 128) << 8);
        for (uint32_t f = 1; f < total_frames; ++f) {
            for (int c = 0; c < is_stereo; ++c) {
                base[c] = (uint8_t)(base[c] + trees[c].decode(ab));
            }
            dec_lr[f * 2 + 0] = (int16_t)(((int32_t)base[0] - 128) << 8);
            dec_lr[f * 2 + 1] = (int16_t)(((int32_t)((is_stereo == 2) ? base[1] : base[0]) - 128) << 8);
        }
    }

    uint32_t out_frames = (uint32_t)(((uint64_t)total_frames * RIVA_AUDIO_RATE) / rate);
    for (uint32_t f = 0; f < out_frames; ++f) {
        uint32_t si = (uint32_t)(((uint64_t)f * rate) / RIVA_AUDIO_RATE);
        if (si >= total_frames) si = total_frames - 1;
        smk_audio_push_frame(dec_lr[si * 2 + 0], dec_lr[si * 2 + 1]);
    }
    free(dec_lr);
}

static int smk_decode_video_bitstream(RivaSmackInstance *smk, const uint8_t *vdata, size_t vlen) {
    if (!smk->trees || !smk->frame_buf) return 0;
    for (int t = 0; t < 4; ++t) smk->trees[t].reset_mru();

    SmkBits vb;
    vb.init(vdata, vlen);
    int bw = (int)(smk->Width / 4);
    int bh = (int)(smk->Height / 4);
    int total_blocks = bw * bh;
    int stride = (int)smk->Width;
    int blk = 0;
    int min_x = (int)smk->Width, min_y = (int)smk->Height;
    int max_x = 0, max_y = 0;
    while (blk < total_blocks) {
        uint16_t desc = smk->trees[3].decode(vb);
        int typ = desc & 3;
        int r_idx = (desc >> 2) & 63;
        int run = (r_idx < 59) ? (r_idx + 1) : (128 << (r_idx - 59));
        uint8_t hdr = (uint8_t)(desc >> 8);
        for (int r = 0; r < run && blk < total_blocks; ++r, ++blk) {
            int bx = (blk % bw) * 4;
            int by = (blk / bw) * 4;
            uint8_t *dst = smk->frame_buf + by * stride + bx;
            if (typ != 2) {
                if (bx < min_x) min_x = bx;
                if (by < min_y) min_y = by;
                if (bx + 4 > max_x) max_x = bx + 4;
                if (by + 4 > max_y) max_y = by + 4;
            }
            if (typ == 0) { /* MONO (2-Farben-4x4-Block) */
                uint16_t clr = smk->trees[1].decode(vb);
                uint16_t map = smk->trees[0].decode(vb);
                uint8_t c0 = (uint8_t)(clr & 0xFF);
                uint8_t c1 = (uint8_t)(clr >> 8);
                for (int py = 0; py < 4; ++py) {
                    for (int px = 0; px < 4; ++px) {
                        dst[py * stride + px] = (map & 1u) ? c1 : c0;
                        map >>= 1;
                    }
                }
            } else if (typ == 1) { /* FULL (unkomprimierter 4x4-Block, 8 Pixelpaare) */
                for (int py = 0; py < 4; ++py) {
                    uint16_t p2 = smk->trees[2].decode(vb);
                    uint16_t p1 = smk->trees[2].decode(vb);
                    dst[py * stride + 0] = (uint8_t)(p1 & 0xFF);
                    dst[py * stride + 1] = (uint8_t)(p1 >> 8);
                    dst[py * stride + 2] = (uint8_t)(p2 & 0xFF);
                    dst[py * stride + 3] = (uint8_t)(p2 >> 8);
                }
            } else if (typ == 2) { /* VOID (unveraendert aus Vorframe) */
                /* nichts zu tun */
            } else { /* SOLID (Einfarbiger 4x4-Block mit Farbe hdr) */
                for (int py = 0; py < 4; ++py) {
                    memset(dst + py * stride, hdr, 4);
                }
            }
        }
    }
    if (min_x < max_x && min_y < max_y) {
        smk->left       = (uint32_t)min_x;
        smk->top        = (uint32_t)min_y;
        smk->rectWidth  = (uint32_t)(max_x - min_x);
        smk->rectHeight = (uint32_t)(max_y - min_y);
        return 1;
    }
    return 0;
}

extern "C" void *f_14bb40(int a1, int a2, int a3) {
    int name_or_fd = 0, flags = 0, extrabuf = 0;
    if (a3 == -1) {
        name_or_fd = a1; flags = a2; extrabuf = a3;
    } else if (a1 == -1 || a1 == 0) {
        extrabuf = a1; flags = a2; name_or_fd = a3;
    } else {
        name_or_fd = a2; flags = 0; extrabuf = 0;
    }
    (void)extrabuf;

    int fd = -1;
    int own_fd = 0;
    if ((flags & 0x1000) || (name_or_fd > 0 && (uintptr_t)name_or_fd < 0x10000u)) {
        fd = name_or_fd;
        own_fd = 0;
    } else if ((uintptr_t)name_or_fd >= 0x10000u) {
        const char *path = (const char *)(uintptr_t)name_or_fd;
        fd = f_144fbf(path, 0x200);
        if (fd < 0) {
            riva_trace("[smacker] SmackOpen failed to open '%s'\n", path);
            return NULL;
        }
        own_fd = 1;
    } else {
        return NULL;
    }

    RivaSmackInstance *smk = (RivaSmackInstance *)calloc(1, sizeof(RivaSmackInstance));
    if (!smk) {
        if (own_fd) f_145259(fd);
        return NULL;
    }
    if (f_144e8b(fd, smk, 104) != 104 || (smk->Version != 0x324B4D53u && smk->Version != 0x344B4D53u)) {
        riva_trace("[smacker] invalid SMK magic 0x%08X on fd=%d\n", (unsigned)smk->Version, fd);
        free(smk);
        if (own_fd) f_145259(fd);
        return NULL;
    }

    uint32_t total_frames = smk->Frames + ((smk->Flags & 1u) ? 1u : 0u);
    smk->fd           = fd;
    smk->own_fd       = own_fd;
    smk->total_frames = total_frames;
    smk->frame_sizes  = (uint32_t *)calloc(total_frames + 1, sizeof(uint32_t));
    smk->frame_types  = (uint8_t *)calloc(total_frames + 1, 1);
    smk->frame_buf    = (uint8_t *)calloc(1, (size_t)smk->Width * (size_t)smk->Height + 64);
    smk->trees        = (SmkBigTree *)calloc(4, sizeof(SmkBigTree));

    f_144e8b(fd, smk->frame_sizes, total_frames * 4u);
    f_144e8b(fd, smk->frame_types, total_frames);

    uint8_t *tbuf = (uint8_t *)malloc(smk->TreesSize + 16);
    if (tbuf && smk->TreesSize > 0) {
        f_144e8b(fd, tbuf, smk->TreesSize);
        SmkBits tb;
        tb.init(tbuf, smk->TreesSize);
        for (int t = 0; t < 4; ++t) smk->trees[t].read(tb);
        for (int t = 0; t < 4; ++t) {
            for (int k = 0; k < 3; ++k) smk->trees[t].init_cache[k] = smk->trees[t].cache[k];
        }
        free(tbuf);
    }
    smk->first_frame_off = f_1455a4(fd);
    smk->FrameNum        = 0;
    smk->left            = 0;
    smk->top             = 0;
    smk->rectWidth       = smk->Width;
    smk->rectHeight      = smk->Height;

    int32_t fr = smk->FrameRate;
    if (fr > 0)      smk->frame_delay_ms = (uint32_t)fr;
    else if (fr < 0) smk->frame_delay_ms = (uint32_t)((-fr) / 100);
    else             smk->frame_delay_ms = 66u;
    if (smk->frame_delay_ms < 10u)   smk->frame_delay_ms = 66u;
    if (smk->frame_delay_ms > 2000u) smk->frame_delay_ms = 1000u;
    smk->next_frame_ms = dsa_platform_get_ticks_ms() + smk->frame_delay_ms;

    smk_audio_clear();
    for (int i = 0; i < MAX_ACTIVE_SMKS; ++i) {
        if (!g_active_smks[i]) { g_active_smks[i] = smk; break; }
    }
    riva_trace("[smacker] opened %ux%u frames=%u rate=%d aud0=0x%08X (%u Hz, %s, %s, %s) fd=%d\n",
               (unsigned)smk->Width, (unsigned)smk->Height, (unsigned)smk->Frames, (int)smk->FrameRate,
               (unsigned)smk->AudioRate[0], (unsigned)(smk->AudioRate[0] & 0xFFFFFFu),
               (smk->AudioRate[0] & 0x20000000u) ? "16bit" : "8bit",
               (smk->AudioRate[0] & 0x10000000u) ? "stereo" : "mono",
               (smk->AudioRate[0] & 0x80000000u) ? "comp" : "pcm",
               fd);
    return smk;
}

extern "C" int f_14a940(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    RivaSmackInstance *smk = NULL;
    int left = 0, top = 0, pitch = 0, destheight = 0, flags = 0;
    void *buf = NULL;
    if (smk_is_valid((void *)(uintptr_t)a1)) {
        smk = (RivaSmackInstance *)(uintptr_t)a1;
        left = a2; top = a3; pitch = a4; destheight = a5; buf = (void *)(uintptr_t)a6; flags = a7;
    } else if (smk_is_valid((void *)(uintptr_t)a7)) {
        flags = a1; buf = (void *)(uintptr_t)a2; destheight = a3; pitch = a4; top = a5; left = a6;
        smk = (RivaSmackInstance *)(uintptr_t)a7;
    }
    (void)flags;
    if (!smk) return 0;
    smk->dest_buf    = (uint8_t *)buf;
    smk->dest_left   = left;
    smk->dest_top    = top;
    smk->dest_pitch  = (pitch > 0) ? pitch : (int)smk->Width;
    smk->dest_height = (destheight > 0) ? destheight : (int)smk->Height;
    return 1;
}

extern "C" int f_14b3d0(void *p) {
    if (!smk_is_valid(p)) return 0;
    RivaSmackInstance *smk = (RivaSmackInstance *)p;
    uint32_t fn = smk->FrameNum;
    if (fn >= smk->total_frames) fn = 0;

    uint32_t fsz = smk->frame_sizes[fn] & ~3u;
    uint8_t  ftyp = smk->frame_types[fn];
    smk->NewPalette = 0;

    if (fsz > 0 && fsz < 0x400000u) {
        uint8_t *fbuf = (uint8_t *)malloc(fsz + 16);
        if (fbuf) {
            f_144e8b(smk->fd, fbuf, fsz);
            const uint8_t *fp = fbuf;
            const uint8_t *fend = fbuf + fsz;
            if ((ftyp & 1u) && fp < fend) {
                uint32_t plen = (uint32_t)(*fp) * 4u;
                if (plen > 0 && fp + plen <= fend) {
                    smk_decode_palette_chunk(smk, fp + 1, plen - 1);
                    fp += plen;
                }
            }
            for (int t = 0; t < 7; ++t) {
                if ((ftyp & (2u << t)) && fp + 4 <= fend) {
                    uint32_t alen = *(const uint32_t *)fp;
                    if (alen >= 4u && fp + alen <= fend) {
                        if (t == 0) smk_decode_audio_chunk(smk, fp, alen);
                        fp += alen;
                    } else {
                        break;
                    }
                }
            }
            int has_dirty = 0;
            if (fp < fend) {
                has_dirty = smk_decode_video_bitstream(smk, fp, (size_t)(fend - fp));
            }
            free(fbuf);
            if (!has_dirty && fn == 0) {
                smk->left       = 0;
                smk->top        = 0;
                smk->rectWidth  = smk->Width;
                smk->rectHeight = smk->Height;
                has_dirty       = 1;
            }
            smk->rect_pending = has_dirty;
        }
    }

    if (smk->dest_buf && smk->frame_buf && smk->rect_pending) {
        int w = (int)smk->Width;
        int h = (int)smk->Height;
        for (int y = 0; y < h && (smk->dest_top + y) < smk->dest_height; ++y) {
            memcpy(smk->dest_buf + (smk->dest_top + y) * smk->dest_pitch + smk->dest_left,
                   smk->frame_buf + y * w,
                   (size_t)w);
        }
    }

    riva_audio_pump();
    return 0;
}

extern "C" int f_14a1d0(int a1, int a2) {
    RivaSmackInstance *smk = NULL;
    if (smk_is_valid((void *)(uintptr_t)a1)) smk = (RivaSmackInstance *)(uintptr_t)a1;
    else if (smk_is_valid((void *)(uintptr_t)a2)) smk = (RivaSmackInstance *)(uintptr_t)a2;
    if (!smk) return 0;
    if (smk->rect_pending) {
        smk->rect_pending = 0;
        return 1;
    }
    return 0;
}

extern "C" int f_14b100(void *p) {
    if (!smk_is_valid(p)) return 0;
    RivaSmackInstance *smk = (RivaSmackInstance *)p;
    smk->FrameNum++;
    if (smk->FrameNum >= smk->Frames) {
        smk->FrameNum = 0;
        f_145279(smk->fd, smk->first_frame_off, SEEK_SET);
    }
    return 0;
}

extern "C" int f_14a450(int a1, int a2) {
    RivaSmackInstance *smk = NULL;
    int target = 0;
    if (smk_is_valid((void *)(uintptr_t)a1)) {
        smk = (RivaSmackInstance *)(uintptr_t)a1;
        target = a2;
    } else if (smk_is_valid((void *)(uintptr_t)a2)) {
        smk = (RivaSmackInstance *)(uintptr_t)a2;
        target = a1;
    }
    if (!smk) return 0;
    if (target < 1) target = 1;
    uint32_t idx = (uint32_t)(target - 1);
    if (idx >= smk->Frames) idx = smk->Frames > 0 ? smk->Frames - 1 : 0;
    long off = smk->first_frame_off;
    for (uint32_t i = 0; i < idx; ++i) {
        off += (long)(smk->frame_sizes[i] & ~3u);
    }
    f_145279(smk->fd, off, SEEK_SET);
    smk->FrameNum = idx;
    return 1;
}

extern "C" int f_149f90(void *p) {
    riva_pump_timers_and_events();
    dsa_platform_present();
    if (!smk_is_valid(p)) return 0;
    const char *fast_env = getenv("RIVA_FAST_SMK");
    if (fast_env && fast_env[0] == '1') return 0;
    RivaSmackInstance *smk = (RivaSmackInstance *)p;
    uint32_t now_ms = dsa_platform_get_ticks_ms();
    if ((int32_t)(now_ms - smk->next_frame_ms) >= 0) {
        smk->next_frame_ms = now_ms + smk->frame_delay_ms;
        return 0;
    }
    Sleep(2);
    return 1;
}

extern "C" int f_14b7b0(void *p) {
    if (!smk_is_valid(p)) return 0;
    RivaSmackInstance *smk = (RivaSmackInstance *)p;
    for (int i = 0; i < MAX_ACTIVE_SMKS; ++i) {
        if (g_active_smks[i] == smk) g_active_smks[i] = NULL;
    }
    if (smk->own_fd && smk->fd >= 0) {
        f_145259(smk->fd);
    }
    free(smk->frame_sizes);
    free(smk->frame_types);
    free(smk->frame_buf);
    free(smk->trees);
    free(smk);
    return 0;
}

extern "C" int f_16897e(unsigned short rate, void (*callback)(void), int *out_handle) {
    int i;
    for (i = 0; i < MAX_RIVA_TIMERS; ++i) {
        if (!g_timers[i].active) {
            g_timers[i].active       = 1;
            g_timers[i].rate         = rate ? rate : 100;
            g_timers[i].callback     = callback;
            g_timers[i].last_fire_ms = dsa_platform_get_ticks_ms();
            g_timers[i].rem_acc      = 0;
            if (out_handle) *out_handle = i + 1;
            riva_trace("[timer] registered #%d rate=%u cb=%p\n", i + 1, (unsigned)g_timers[i].rate, (void *)callback);
            return 0; /* 0 = Erfolg */
        }
    }
    if (out_handle) *out_handle = -1;
    return -1;
}

extern "C" int f_168cd4(int handle) {
    int idx = handle - 1;
    if (idx >= 0 && idx < MAX_RIVA_TIMERS) {
        g_timers[idx].active   = 0;
        g_timers[idx].callback = NULL;
    }
    return 0;
}

/* =========================================================================
 * 5. Watcom C/C++ Laufzeitbibliothek (Datei-I/O mit Spielpfad-Aufloesung)
 * ========================================================================= */

static FILE *g_trace_fp = NULL;
static int   g_trace_checked = 0;
static int   g_trace_count = 0;

static void riva_trace(const char *fmt, ...) {
    if (g_trace_count > 50000) return;
    if (!g_trace_checked) {
        const char *tf = getenv("RIVA_PORT_TRACE_FILE");
        const char *te = getenv("RIVA_PORT_TRACE");
        g_trace_checked = 1;
        if (tf && tf[0]) {
            g_trace_fp = fopen(tf, "w");
        } else if (te && te[0] == '1') {
            g_trace_fp = fopen("riva_port_trace.log", "w");
        }
    }
    if (g_trace_fp) {
        va_list ap;
        va_start(ap, fmt);
        vfprintf(g_trace_fp, fmt, ap);
        va_end(ap);
        fflush(g_trace_fp);
        ++g_trace_count;
    }
}

/* =========================================================================
 * 5a. Virtueller ISO9660 / Mode-2-CD-ROM-Leser fuer GOG game.gog
 *     Liest CD-Dateien (z.B. DATA\SPEX.ALF, DATA\SPEX.MOD, RAW*.ALF, SEQS.ALF)
 *     direkt aus game.gog im Spielverzeichnis, falls nicht entpackt vorhanden.
 * ========================================================================= */

#define GOG_ISO_FD_BASE   0x4000
#define GOG_ISO_MAX_FDS   32
#define GOG_ISO_MAX_FILES 256

struct GogIsoFileEntry {
    char     rel_path[80]; /* z.B. "DATA\\SPEX.ALF" */
    char     base_name[32];/* z.B. "SPEX.ALF" */
    uint32_t lba;
    uint32_t size;
};

struct GogIsoOpenFd {
    int      used;
    uint32_t lba;
    uint32_t size;
    uint32_t pos;
};

static FILE              *g_iso_fp         = NULL;
static int                g_iso_init_done  = 0;
static uint32_t           g_iso_sec_size   = 2352;
static uint32_t           g_iso_sec_hdr    = 24;
static GogIsoFileEntry    g_iso_files[GOG_ISO_MAX_FILES];
static int                g_iso_file_count = 0;
static GogIsoOpenFd       g_iso_fds[GOG_ISO_MAX_FDS];

static int gog_iso_read_sector(uint32_t lba, unsigned char *buf2048) {
    uint64_t off;
    if (!g_iso_fp) return -1;
    off = (uint64_t)lba * (uint64_t)g_iso_sec_size + (uint64_t)g_iso_sec_hdr;
    if (_fseeki64(g_iso_fp, (int64_t)off, SEEK_SET) != 0) return -1;
    if (fread(buf2048, 1, 2048, g_iso_fp) != 2048) return -1;
    return 0;
}

static void gog_iso_parse_dir(uint32_t dir_lba, uint32_t dir_size, const char *prefix, int depth) {
    uint32_t num_secs = (dir_size + 2047u) / 2048u;
    unsigned char sec[2048];
    uint32_t s;
    for (s = 0; s < num_secs; ++s) {
        uint32_t pos = 0;
        if (gog_iso_read_sector(dir_lba + s, sec) != 0) break;
        while (pos < 2048) {
            unsigned char rec_len = sec[pos];
            unsigned char flags, name_len;
            uint32_t ext_lba, data_len;
            char name[64];
            int i, k;
            if (rec_len == 0) break;
            if (pos + rec_len > 2048) break;
            ext_lba  = *(uint32_t *)(sec + pos + 2);
            data_len = *(uint32_t *)(sec + pos + 10);
            flags    = sec[pos + 25];
            name_len = sec[pos + 32];
            if (name_len > 0 && !(name_len == 1 && (sec[pos + 33] == 0 || sec[pos + 33] == 1))) {
                k = 0;
                for (i = 0; i < (int)name_len && k < 60; ++i) {
                    char c = (char)sec[pos + 33 + i];
                    if (c == ';') break;
                    if (c >= 'a' && c <= 'z') c = (char)(c - 'a' + 'A');
                    name[k++] = c;
                }
                if (k > 0 && name[k - 1] == '.') --k;
                name[k] = '\0';
                if (flags & 0x02) {
                    if (depth < 2) {
                        char sub_prefix[80];
                        if (prefix && prefix[0]) {
                            snprintf(sub_prefix, sizeof(sub_prefix), "%s\\%s", prefix, name);
                        } else {
                            snprintf(sub_prefix, sizeof(sub_prefix), "%s", name);
                        }
                        gog_iso_parse_dir(ext_lba, data_len, sub_prefix, depth + 1);
                    }
                } else if (g_iso_file_count < GOG_ISO_MAX_FILES) {
                    GogIsoFileEntry *fe = &g_iso_files[g_iso_file_count++];
                    if (prefix && prefix[0]) {
                        snprintf(fe->rel_path, sizeof(fe->rel_path), "%s\\%s", prefix, name);
                    } else {
                        snprintf(fe->rel_path, sizeof(fe->rel_path), "%s", name);
                    }
                    snprintf(fe->base_name, sizeof(fe->base_name), "%s", name);
                    fe->lba  = ext_lba;
                    fe->size = data_len;
                }
            }
            pos += rec_len;
        }
    }
}

static void gog_iso_init(void) {
    const char *game_dir;
    char iso_path[600];
    unsigned char pvd[2048];
    uint32_t root_lba, root_size;
    if (g_iso_init_done) return;
    g_iso_init_done = 1;

    game_dir = dsa_platform_get_game_dir();
    if (!game_dir || !game_dir[0]) game_dir = ".";

    snprintf(iso_path, sizeof(iso_path), "%s\\game.gog", game_dir);
    g_iso_fp = fopen(iso_path, "rb");
    if (!g_iso_fp) {
        snprintf(iso_path, sizeof(iso_path), "%s\\..\\game.gog", game_dir);
        g_iso_fp = fopen(iso_path, "rb");
    }
    if (!g_iso_fp) {
        snprintf(iso_path, sizeof(iso_path), "%s\\DATA\\game.gog", game_dir);
        g_iso_fp = fopen(iso_path, "rb");
    }
    if (!g_iso_fp) {
        snprintf(iso_path, sizeof(iso_path), "%s\\CD\\game.gog", game_dir);
        g_iso_fp = fopen(iso_path, "rb");
    }
    if (!g_iso_fp) return;

    /* Pruefe Mode-2/2352 (Offset 24) vs. Standard-ISO 2048 (Offset 0) */
    g_iso_sec_size = 2352;
    g_iso_sec_hdr  = 24;
    if (gog_iso_read_sector(16, pvd) != 0 || memcmp(pvd + 1, "CD001", 5) != 0) {
        g_iso_sec_size = 2352;
        g_iso_sec_hdr  = 16;
        if (gog_iso_read_sector(16, pvd) != 0 || memcmp(pvd + 1, "CD001", 5) != 0) {
            g_iso_sec_size = 2048;
            g_iso_sec_hdr  = 0;
            if (gog_iso_read_sector(16, pvd) != 0 || memcmp(pvd + 1, "CD001", 5) != 0) {
                fclose(g_iso_fp);
                g_iso_fp = NULL;
                return;
            }
        }
    }

    root_lba  = *(uint32_t *)(pvd + 156 + 2);
    root_size = *(uint32_t *)(pvd + 156 + 10);
    gog_iso_parse_dir(root_lba, root_size, "", 0);
    riva_trace("[gog_iso] Indiziert '%s': %d Dateien (sec=%u hdr=%u)\n",
               iso_path, g_iso_file_count, g_iso_sec_size, g_iso_sec_hdr);
}

static int gog_iso_open(const char *dos_path) {
    char norm[260];
    const char *p = dos_path;
    const char *base;
    int i = 0, idx = -1, slot = -1;
    if (!dos_path || !dos_path[0]) return -1;
    gog_iso_init();
    if (!g_iso_fp || g_iso_file_count <= 0) return -1;

    if (p[0] && p[1] == ':') p += 2;
    while (*p == '\\' || *p == '/' || *p == '.') {
        if (*p == '.' && (p[1] == '\\' || p[1] == '/')) {
            p += 2;
        } else if (*p == '\\' || *p == '/') {
            ++p;
        } else {
            break;
        }
    }
    while (*p && i < (int)sizeof(norm) - 1) {
        char c = *p++;
        if (c == '/') c = '\\';
        if (c >= 'a' && c <= 'z') c = (char)(c - 'a' + 'A');
        norm[i++] = c;
    }
    norm[i] = '\0';

    base = strrchr(norm, '\\');
    base = base ? (base + 1) : norm;

    for (i = 0; i < g_iso_file_count; ++i) {
        if (_stricmp(g_iso_files[i].rel_path, norm) == 0) {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        for (i = 0; i < g_iso_file_count; ++i) {
            if (_stricmp(g_iso_files[i].base_name, base) == 0) {
                idx = i;
                break;
            }
        }
    }
    if (idx < 0) return -1;

    for (i = 0; i < GOG_ISO_MAX_FDS; ++i) {
        if (!g_iso_fds[i].used) {
            slot = i;
            break;
        }
    }
    if (slot < 0) return -1;

    g_iso_fds[slot].used = 1;
    g_iso_fds[slot].lba  = g_iso_files[idx].lba;
    g_iso_fds[slot].size = g_iso_files[idx].size;
    g_iso_fds[slot].pos  = 0;
    riva_trace("[gog_iso] Geoeffnet '%s' -> ISO:'%s' (LBA=%u, %u Bytes) => fd=%d\n",
               dos_path, g_iso_files[idx].rel_path,
               (unsigned)g_iso_files[idx].lba, (unsigned)g_iso_files[idx].size,
               GOG_ISO_FD_BASE + slot);
    return GOG_ISO_FD_BASE + slot;
}

static int gog_iso_is_fd(int fd) {
    return (fd >= GOG_ISO_FD_BASE && fd < GOG_ISO_FD_BASE + GOG_ISO_MAX_FDS &&
            g_iso_fds[fd - GOG_ISO_FD_BASE].used);
}

static int gog_iso_read(int fd, void *buf, unsigned int cnt) {
    GogIsoOpenFd *f = &g_iso_fds[fd - GOG_ISO_FD_BASE];
    unsigned char *dst = (unsigned char *)buf;
    unsigned int total = 0;
    unsigned char sec[2048];
    if (f->pos >= f->size || cnt == 0) return 0;
    if (cnt > f->size - f->pos) cnt = f->size - f->pos;

    while (total < cnt) {
        uint32_t cur_pos = f->pos;
        uint32_t sec_idx = cur_pos >> 11;
        uint32_t sec_off = cur_pos & 2047u;
        uint32_t chunk   = 2048u - sec_off;
        if (chunk > cnt - total) chunk = cnt - total;
        if (gog_iso_read_sector(f->lba + sec_idx, sec) != 0) break;
        memcpy(dst + total, sec + sec_off, chunk);
        f->pos += chunk;
        total  += chunk;
    }
    return (int)total;
}

static long gog_iso_lseek(int fd, long offset, int whence) {
    GogIsoOpenFd *f = &g_iso_fds[fd - GOG_ISO_FD_BASE];
    int64_t np = (int64_t)f->pos;
    if (whence == SEEK_SET)      np = offset;
    else if (whence == SEEK_CUR) np += offset;
    else if (whence == SEEK_END) np = (int64_t)f->size + offset;
    if (np < 0) np = 0;
    if (np > (int64_t)f->size) np = (int64_t)f->size;
    f->pos = (uint32_t)np;
    return (long)f->pos;
}

static void redirect_write_to_savedir_if_needed(char *resolved, size_t resolved_size) {
    if (!dsa_platform_is_save_dir_redirected()) return;
    const char *gd = dsa_platform_get_game_dir();
    const char *sd = dsa_platform_get_save_dir();
    if (!gd || !gd[0] || !sd || !sd[0]) return;
    size_t gd_len = strlen(gd);
    if (_strnicmp(resolved, gd, gd_len) == 0 && (resolved[gd_len] == '\\' || resolved[gd_len] == '/')) {
        const char *sub = resolved + gd_len + 1;
        char tmp[600];
        if (_strnicmp(sub, "DATA\\", 5) == 0 || _strnicmp(sub, "DATA/", 5) == 0) {
            sub += 5;
        }
        snprintf(tmp, sizeof(tmp), "%s\\%s", sd, sub);
        strncpy(resolved, tmp, resolved_size - 1);
        resolved[resolved_size - 1] = '\0';
    }
}

extern "C" int f_144fbf(const char *path, int oflag, ...) {
    char resolved[600];
    int win_flags = _O_BINARY;
    int fd;
    dsa_platform_resolve_path(path, resolved, sizeof(resolved));

    /* Watcom O_RDONLY=0, O_WRONLY=1, O_RDWR=2, O_APPEND=8, O_CREAT=0x20, O_TRUNC=0x40 */
    if ((oflag & 3) == 1)      win_flags |= _O_WRONLY;
    else if ((oflag & 3) == 2) win_flags |= _O_RDWR;
    else                       win_flags |= _O_RDONLY;

    if (oflag & 0x0008) win_flags |= _O_APPEND;
    if (oflag & 0x0020) win_flags |= _O_CREAT;
    if (oflag & 0x0040) win_flags |= _O_TRUNC;

    if ((oflag & 3) != 0 || (oflag & 0x0060) != 0) {
        redirect_write_to_savedir_if_needed(resolved, sizeof(resolved));
    }

    fd = _open(resolved, win_flags, _S_IREAD | _S_IWRITE);
    if (fd == -1 && (oflag & 3) == 0) {
        fd = gog_iso_open(path);
    }
    riva_trace("[open] '%s' -> '%s' (oflag=0x%x) => fd=%d\n", path ? path : "NULL", resolved, oflag, fd);
    return fd;
}

extern "C" int f_14d0d7(const char *path, int pmode) {
    char resolved[600];
    (void)pmode;
    dsa_platform_resolve_path(path, resolved, sizeof(resolved));
    redirect_write_to_savedir_if_needed(resolved, sizeof(resolved));
    return _open(resolved, _O_BINARY | _O_CREAT | _O_TRUNC | _O_RDWR, _S_IREAD | _S_IWRITE);
}

static unsigned int g_io_pump_counter = 0;

extern "C" int f_144e8b(int fd, void *buf, unsigned int cnt) {
    long len, pos;
    if ((++g_io_pump_counter & 0x3Fu) == 0) {
        riva_pump_timers_and_events();
    }
    if (cnt == 0) return 0;
    if (gog_iso_is_fd(fd)) {
        return gog_iso_read(fd, buf, cnt);
    }
    len = _filelength(fd);
    pos = _tell(fd);
    if (len >= 0 && pos >= 0) {
        long rem = len - pos;
        if (rem <= 0) return 0;
        if ((unsigned long)cnt > (unsigned long)rem) {
            cnt = (unsigned int)rem;
        }
    }
    return _read(fd, buf, cnt);
}

extern "C" int f_144cb6(int fd, const void *buf, unsigned int cnt) {
    if ((++g_io_pump_counter & 0x3Fu) == 0) {
        riva_pump_timers_and_events();
    }
    return _write(fd, buf, cnt);
}

extern "C" long f_145279(int fd, long offset, int whence) {
    if (gog_iso_is_fd(fd)) {
        return gog_iso_lseek(fd, offset, whence);
    }
    return _lseek(fd, offset, whence);
}

extern "C" int f_145259(int fd) {
    if (gog_iso_is_fd(fd)) {
        g_iso_fds[fd - GOG_ISO_FD_BASE].used = 0;
        return 0;
    }
    return _close(fd);
}

extern "C" long f_1452bc(int fd) {
    if (gog_iso_is_fd(fd)) {
        return (long)g_iso_fds[fd - GOG_ISO_FD_BASE].size;
    }
    return _filelength(fd);
}

extern "C" long f_1455a4(int fd) {
    if (gog_iso_is_fd(fd)) {
        return (long)g_iso_fds[fd - GOG_ISO_FD_BASE].pos;
    }
    return _tell(fd);
}

extern "C" void f_145590(int fd, unsigned dt, unsigned tm) {
    (void)fd; (void)dt; (void)tm;
}

extern "C" int f_16a9da(int fd, long size) {
    return _chsize(fd, size);
}

extern "C" int f_149336(const char *path) {
    char resolved[600];
    dsa_platform_resolve_path(path, resolved, sizeof(resolved));
    return _unlink(resolved);
}

extern "C" int f_15eb02(const char *oldname, const char *newname) {
    char r_old[600], r_new[600];
    dsa_platform_resolve_path(oldname, r_old, sizeof(r_old));
    dsa_platform_resolve_path(newname, r_new, sizeof(r_new));
    _unlink(r_new);
    return rename(r_old, r_new);
}

extern "C" int f_149292(const char *path) {
    char resolved[600];
    dsa_platform_resolve_path(path, resolved, sizeof(resolved));
    return _mkdir(resolved);
}

/* DOS _dos_findfirst / _dos_findnext / _dos_findclose Emulation */
static void copy_finddata_to_dta(const struct _finddata_t *fd, struct find_t *dta) {
    struct tm *lt;
    dta->attrib = (char)fd->attrib;
    dta->size   = (unsigned long)fd->size;
    lt = localtime(&fd->time_write);
    if (lt) {
        dta->wr_time = (unsigned short)(((lt->tm_hour & 31) << 11) | ((lt->tm_min & 63) << 5) | ((lt->tm_sec / 2) & 31));
        dta->wr_date = (unsigned short)((((lt->tm_year - 80) & 127) << 9) | (((lt->tm_mon + 1) & 15) << 5) | (lt->tm_mday & 31));
    } else {
        dta->wr_time = 0;
        dta->wr_date = 0;
    }
    strncpy(dta->name, fd->name, 12);
    dta->name[12] = '\0';
    _strupr(dta->name);
}

/* DOS attribute 0 includes regular/archive/read-only files, but no directories,
   hidden/system entries. Preserve the requested filter for findnext. */
static bool dos_find_matches(const struct _finddata_t *fd, unsigned attr) {
    const unsigned optional = 0x02u | 0x04u | 0x10u;
    if (attr & 0x08u) return false; /* Win32 has no DOS volume-label entry. */
    return (fd->attrib & optional & ~attr) == 0;
}

extern "C" int f_1492b4(const char *filespec, unsigned attr, struct find_t *dta) {
    char resolved[600];
    struct _finddata_t fd;
    intptr_t h;
    if (!filespec || !dta) return -1;
    dsa_platform_resolve_path(filespec, resolved, sizeof(resolved));
    h = _findfirst(resolved, &fd);
    memcpy(dta->reserved + sizeof(h), &attr, sizeof(attr));
    if (h != -1) {
        while (!dos_find_matches(&fd, attr)) {
            if (_findnext(h, &fd) != 0) {
                _findclose(h);
                h = -1;
                break;
            }
        }
    }
    *(intptr_t *)dta->reserved = h;
    if (h == -1) return -1;
    copy_finddata_to_dta(&fd, dta);
    return 0;
}

extern "C" int f_1492d1(struct find_t *dta) {
    struct _finddata_t fd;
    intptr_t h;
    unsigned attr;
    if (!dta) return -1;
    h = *(intptr_t *)dta->reserved;
    if (h == -1) return -1;
    memcpy(&attr, dta->reserved + sizeof(h), sizeof(attr));
    do {
        if (_findnext(h, &fd) != 0) return -1;
    } while (!dos_find_matches(&fd, attr));
    copy_finddata_to_dta(&fd, dta);
    return 0;
}

extern "C" int f_1492ed(struct find_t *dta) {
    intptr_t h;
    if (!dta) return 0;
    h = *(intptr_t *)dta->reserved;
    if (h != -1) {
        _findclose(h);
        *(intptr_t *)dta->reserved = -1;
    }
    return 0;
}

extern "C" FILE *f_15e469(const char *path, const char *mode) {
    char resolved[600];
    FILE *fp;
    if (!path) return NULL;
    dsa_platform_resolve_path(path, resolved, sizeof(resolved));
    if ((uintptr_t)mode < 0x00400000 || (mode[0] != 'r' && mode[0] != 'w' && mode[0] != 'a')) {
        mode = "rb";
    }
    fp = fopen(resolved, mode);
    riva_trace("[fopen] '%s' -> '%s' (mode='%s') => %p\n", path, resolved, mode, (void *)fp);
    return fp;
}

extern "C" FILE *f_165d60(const char *path, const char *mode) {
    return f_15e469(path, mode);
}

extern "C" int f_15e55f(FILE *fp, long offset, int whence) {
    return fp ? fseek(fp, offset, whence) : -1;
}

extern "C" size_t f_15e65b(void *buf, size_t size, size_t count, FILE *fp) {
    if ((++g_io_pump_counter & 0x3Fu) == 0) {
        riva_pump_timers_and_events();
    }
    return fp ? fread(buf, size, count, fp) : 0;
}

extern "C" size_t f_15e6d8(void *buf, size_t size, size_t count, FILE *fp) {
    return f_15e65b(buf, size, count, fp);
}

extern "C" int f_15e5f7(FILE *fp) {
    return fp ? fclose(fp) : 0;
}

extern "C" int f_15e836(FILE *fp) {
    return fp ? fclose(fp) : 0;
}

extern "C" int f_1794a7(FILE *fp) {
    if (!fp) return -1;
    int c = fgetc(fp);
    if (c == EOF) {
        ((unsigned char *)fp)[12] |= 0x10;
        ((unsigned char *)fp)[13] |= 0x10;
        return -1;
    }
    return c;
}

extern "C" int f_17a891(int ch, FILE *fp) {
    return fp ? fputc(ch, fp) : -1;
}

extern "C" int f_197308(const char *str, FILE *fp) {
    return (fp && str) ? fputs(str, fp) : -1;
}

extern "C" char *f_1968cf(const char *name) {
    return name ? getenv(name) : NULL;
}

extern "C" void *f_1771c2(void *ptr, size_t size) {
    if (!ptr) return malloc(size ? size : 4);
    if (!size) { free(ptr); return NULL; }
    return realloc(ptr, size);
}

extern "C" unsigned int f_17a51a(unsigned int drive, unsigned short *diskspace) {
    (void)drive;
    if (diskspace) {
        diskspace[0] = 32768; /* total_clusters */
        diskspace[1] = 32768; /* avail_clusters */
        diskspace[2] = 64;    /* sectors_per_cluster */
        diskspace[3] = 512;   /* bytes_per_sector */
    }
    return 0;
}

/* =========================================================================
 * 6. String-, Speicher-, Formatierungs- und C++-Array-Laufzeitfunktionen
 * ========================================================================= */

extern "C" int    f_144bf0(const char *a, const char *b)             { return strcmp(a ? a : "", b ? b : ""); }
extern "C" char  *f_14d50b(const char *h, const char *n)             { return (char *)strstr(h ? h : "", n ? n : ""); }
extern "C" char  *f_15f2d6(char *d, const char *s)                   { return strcpy(d, s ? s : ""); }
extern "C" char  *f_148120(char *d, const char *s)                   { return strcat(d, s ? s : ""); }
extern "C" char  *f_15f282(char *d, const char *s)                   { return strcat(d, s ? s : ""); }
extern "C" size_t f_145530(const char *s)                            { return s ? strlen(s) : 0; }
extern "C" size_t f_15f269(const char *s)                            { return s ? strlen(s) : 0; }
extern "C" char  *f_148143(char *d, const char *s, size_t n)         { if (n > 4096) n = 64; return strncpy(d, s ? s : "", n); }
extern "C" int    f_14d6ef(const char *a, const char *b, size_t n)   { return strncmp(a ? a : "", b ? b : "", n); }
extern "C" char  *f_14d546(char *d, const char *s, size_t n)         { return strncat(d, s ? s : "", n); }
extern "C" int    f_14d717(const char *a, const char *b)             { return _stricmp(a ? a : "", b ? b : ""); }
extern "C" int    f_15eb47(const char *a, const char *b, size_t n)   { return _strnicmp(a ? a : "", b ? b : "", n); }
extern "C" int    f_14d6c4(const char *a, const char *b, size_t n)   { return _strnicmp(a ? a : "", b ? b : "", n); }
extern "C" char  *f_1492fd(const char *s, int c)                     { return (char *)strchr(s ? s : "", c); }
extern "C" char  *f_15ea0f(const char *s, int c)                     { return (char *)strrchr(s ? s : "", c); }
extern "C" char  *f_15dc3f(const char *s, int c)                     { return (char *)strrchr(s ? s : "", c); }
extern "C" char  *f_145318(char *s, const char *d)                   { return strtok(s, d); }
extern "C" double f_148160(const char *s, char **endp)               { return strtod(s, endp); }

static inline void *riva_fix_dos_vram_ptr(void *p) {
    uintptr_t u = (uintptr_t)p;
    if (u >= 0xA0000u && u < 0xB0000u) {
        return (void *)((uint8_t *)port_get_vram() + (u - 0xA0000u));
    }
    return p;
}
extern "C" void  *f_145300(void *p, int c, size_t n)                 { return memset(riva_fix_dos_vram_ptr(p), c, n); }
extern "C" void  *f_1452d0(void *d, const void *s, size_t n)         { return memcpy(d, s, n); }
extern "C" void  *f_149cf5(void *d, const void *s, size_t n)         { return memcpy(d, s, n); }
extern "C" void  *f_14d075(void *d, const void *s, size_t n)         { return memmove(d, s, n); }
extern "C" int    f_145547(const void *a, const void *b, size_t n)   { return strncmp((const char *)a, (const char *)b, n); }

extern "C" unsigned short f_148170(unsigned short v) {
    return (unsigned short)((v >> 8) | (v << 8));
}

extern "C" unsigned int f_148180(unsigned int v) {
    return ((v >> 24) & 0x000000FFu) |
           ((v >>  8) & 0x0000FF00u) |
           ((v <<  8) & 0x00FF0000u) |
           ((v << 24) & 0xFF000000u);
}

extern "C" int f_14572e(char *buf, const char *fmt, ...) {
    int r;
    va_list ap;
    va_start(ap, fmt);
    r = vsprintf(buf, fmt, ap);
    va_end(ap);
    return r;
}

extern "C" int f_165db0(char *buf, const char *fmt, va_list ap) {
    return vsprintf(buf, fmt, ap);
}

extern "C" int f_14d652(char *buf, const char *fmt, va_list ap) {
    return vsprintf(buf, fmt, ap);
}

extern "C" int f_15ead2(const char *buf, const char *fmt, ...) {
    int r;
    va_list ap;
    va_start(ap, fmt);
    r = vsscanf(buf, fmt, ap);
    va_end(ap);
    return r;
}

extern "C" int f_14d0e4(const char *fmt, ...) {
    int r;
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    r = vsnprintf(buf, sizeof(buf), fmt ? fmt : "", ap);
    va_end(ap);
    riva_trace("[printf] %s\n", buf);
    if (strstr(buf, "Assertion")) {
        unsigned int *sp = (unsigned int *)&fmt;
        for (int i = -1; i < 40; ++i) {
            unsigned int v = sp[i];
            if (v >= 0x00401000 && v <= 0x005C0000) {
                riva_trace("  [assert_stk+%d] 0x%08X\n", i * 4, v);
            }
        }
    }
    return r;
}

extern "C" int f_15f3d4(const char *fmt, va_list ap) {
    int r;
    char buf[1024];
    r = vsnprintf(buf, sizeof(buf), fmt ? fmt : "", ap);
    riva_trace("[vprintf] %s\n", buf);
    return r;
}

extern "C" int f_14d27d(const char *fmt, ...) {
    int r;
    va_list ap;
    va_start(ap, fmt);
    r = vprintf(fmt, ap);
    va_end(ap);
    return r;
}

extern "C" char *f_14d1c9(int val, char *buf, int radix) { return _itoa(val, buf, radix); }
extern "C" char *f_148518(int val, char *buf, int radix) { return _itoa(val, buf, radix); }
extern "C" int   f_148420(const char *s)                 { return s ? atoi(s) : 0; }
extern "C" long  f_148429(const char *s)                 { return s ? atol(s) : 0; }
/* f_148450 ist NICHT rand(), sondern die vertikale Linienfunktion in fz_148170_P1.CPP (zeichnet LE/AE-Balken)! */
extern "C" int   f_165de2(void)                          { return rand() & 0x7FFF; }
extern "C" void  f_148469(unsigned int seed)             { srand(seed); }

extern "C" void *f_15eb9d(size_t sz)                     { return malloc(sz ? sz : 4); }
extern "C" void *f_15eaf3(size_t sz)                     { return malloc(sz ? sz : 4); }
extern "C" void *f_15ec58(size_t nmemb, size_t sz)       { return calloc(nmemb ? nmemb : 1, sz ? sz : 4); }
extern "C" void  f_15ebd6(void *p)                       { if (p) free(p); }
extern "C" void  f_1455b5(void)                          {}

extern "C" int d_1a9620;

extern "C" void f_148534(int code) {
    char ebuf[256];
    int elen = snprintf(ebuf, sizeof(ebuf), "[f_148534] exit(%d) d_1a9620=%d ret0=%p\n", code, d_1a9620, __builtin_return_address(0));
    if (elen > 0) {
        HANDLE hf = CreateFileA(g_exe_exit_log_path, FILE_APPEND_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hf != INVALID_HANDLE_VALUE) { DWORD w = 0; WriteFile(hf, ebuf, (DWORD)elen, &w, NULL); CloseHandle(hf); }
    }
    unsigned int *sp = (unsigned int *)&code;
    riva_trace("[exit] f_148534(code=%d, d_1a9620=%d) ret0=%p\n", code, d_1a9620, __builtin_return_address(0));
    for (int i = -1; i < 32; ++i) {
        unsigned int v = sp[i];
        if (v >= 0x00401000 && v <= 0x005C0000) {
            riva_trace("  [stk+%d] 0x%08X\n", i * 4, v);
        }
    }
    dsa_platform_shutdown();
    exit(code);
}

extern "C" int   f_14d1c1(short r, short c)              { (void)r; (void)c; return 0; }
extern "C" int   f_14d667(int freq)                      { port_sound((unsigned)freq); return 0; }
extern "C" int   f_14d6b1(void)                          { port_nosound(); return 0; }
extern "C" void  f_14d7dc(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) {
    if (base && nmemb > 1 && size > 0 && compar) qsort(base, nmemb, size, compar);
}
extern "C" size_t f_15fdd5(const void *buf, size_t size, size_t count, FILE *fp) {
    return fp ? fwrite(buf, size, count, fp) : 0;
}
extern "C" time_t f_1567af(time_t *t)                    { return time(t); }
extern "C" int    f_15dc98(int sig, void *h)             { (void)sig; (void)h; return 0; }
extern "C" void   f_15e0e7(unsigned intno, void *h)      { if (intno == 0x1c) g_int1c_handler = (void (*)(void))h; }
extern "C" void  *f_15e114(unsigned intno)               { return (intno == 0x1c) ? (void *)g_int1c_handler : NULL; }
extern "C" int    f_15e181(void (*fn)(void))             { (void)fn; return 0; }
extern "C" void   f_15e1be(void *h)                      { (void)h; }
extern "C" void   f_15e97a(void *h)                      { (void)h; }
extern "C" int    f_15ea62(int c)                        { return toupper((unsigned char)c); }
extern "C" int    f_15ea70(int c)                        { return tolower((unsigned char)c); }
extern "C" void   f_15f1b4(unsigned *p)                  { if (p) *p = 3; /* C: */ }
extern "C" void   f_15f1c8(int drive, unsigned *p)       { (void)drive; if (p) *p = 26; }
extern "C" int    f_15f1dc(int drive, unsigned short *df) {
    (void)drive;
    if (df) {
        df[0] = 32768; /* total_clusters */
        df[1] = 16384; /* avail_clusters */
        df[2] = 64;    /* sectors_per_cluster */
        df[3] = 512;   /* bytes_per_sector -> 512 MB frei */
    }
    return 0;
}
extern "C" char  *f_15f1e1(char *buf, int n) {
    /* Im Original-DOS-Spiel ist das Arbeitsverzeichnis "C:\RIVA\DATA" (12 Zeichen).
     * Viele Stack-Puffer im Spiel (z. B. char buf[40] in f_144110) erwarten einen
     * kurzen 8.3-DOS-Pfad, der auf "\DATA" endet, damit *strrchr(p, '\\') = 0; strcat(p, "\\TEMP")
     * daraus "C:\RIVA\TEMP" bildet. dsa_platform_resolve_path bildet "C:\RIVA\..." auf g_game_dir ab. */
    const char *virtual_dos_cwd = "C:\\RIVA\\DATA";
    if (!buf) {
        size_t len = strlen(virtual_dos_cwd) + 1;
        if ((size_t)n > len) len = (size_t)n;
        buf = (char *)malloc(len);
        if (buf) strcpy(buf, virtual_dos_cwd);
        return buf;
    }
    strncpy(buf, virtual_dos_cwd, (size_t)n - 1);
    buf[n - 1] = '\0';
    return buf;
}
extern "C" int    f_15f2b5(const char *path)             { (void)path; return 0; }
extern "C" void   f_15f307(void)                         { fflush(NULL); }
extern "C" int    f_15f3e5(void)                         { return dsa_platform_key_ready() != 0; }
extern "C" int    f_15f3fc(void)                         { return (int)(port_bios_keybrd(_KEYBRD_READ) & 0xFF); }

/* Vollstaendige Rekonstruktion von TempDisk (0x165460..0x165d40, Vtable d_1bc140) */

#pragma pack(push, 1)
struct RivaDiskVtbl {
    void *(*v00)(void *self, int flags);
    void  (*v04)(void *self);
    char *(*v08)(void *self, unsigned id);
    int   (*v0c)(void *self, unsigned id);
    int   (*v10)(void *self, unsigned id);
    int   (*v14)(void *self, unsigned id, int mode);
    int   (*v18)(void *self, unsigned id, void *buf);
    int   (*v1c)(void *self, void *buf);
    int   (*v20)(void *self, void *buf, int len);
    int   (*v24)(void *self, const void *buf, int len);
    int   (*v28)(void *self);
    int   (*v2c)(void *self);
    int   (*v30)(void *self);
    int   (*v34)(void *self, unsigned id);
    int   (*v38)(void *self, int new_len);
    int   (*v3c)(void *self);
    int   (*v40)(void *self, int offset, int whence);
    int   (*v44)(void *self, unsigned id);
    char *(*v48)(void *self);
    int   (*v4c)(void *self, const char *dir);
    int   (*v50)(void *self, unsigned off, const void *data, int len);
    int   (*v54)(void *self, int off, int len);
    void  (*v58)(void *self, void *backing);
};

struct RivaTempDisk {
    RivaDiskVtbl  *vtbl;      /* +0x00: &g_tempdisk_vtbl */
    RivaDiskVtbl **backing;   /* +0x04: unterliegendes realdisk/alfdisk */
    RivaDiskVtbl **rd;        /* +0x08: eigenes realdisk fuer TEMP\ */
    int            open_flag; /* +0x0c */
    short          mode;      /* +0x10 */
    unsigned int   cur_id;    /* +0x12 */
    char           dir[0x90]; /* +0x16 */
    char           fname[14]; /* +0xa6 */
    char         **p_name;    /* +0xb4: &d_1a965c */
};
#pragma pack(pop)

extern "C" {
void *f_165520(RivaTempDisk *self, int flags);
void  f_1657a0(RivaTempDisk *self);
char *f_165730(RivaTempDisk *self, unsigned id);
int   f_1657d0(RivaTempDisk *self, unsigned id);
int   f_165820(RivaTempDisk *self, unsigned id);
int   f_1658a0(RivaTempDisk *self, unsigned id, short mode);
int   f_165920(RivaTempDisk *self, unsigned id, void *buf);
int   f_165960(RivaTempDisk *self, void *buf);
int   f_165990(RivaTempDisk *self, void *buf, int len);
int   f_1659d0(RivaTempDisk *self, const void *buf, int len);
int   f_165a10(RivaTempDisk *self);
int   f_165a50(RivaTempDisk *self);
int   f_165a90(RivaTempDisk *self);
int   f_165ac0(RivaTempDisk *self, unsigned id);
int   f_165b30(RivaTempDisk *self, int new_len);
int   f_165b60(RivaTempDisk *self);
int   f_165b90(RivaTempDisk *self, int offset, short whence);
int   f_165bd0(RivaTempDisk *self, unsigned id);
char *f_165c40(RivaTempDisk *self);
int   f_165c50(RivaTempDisk *self, const char *dir);
int   f_165d00(RivaTempDisk *self, unsigned off, const void *data, int len);
int   f_165d40(RivaTempDisk *self, int off, int len);
void  f_165700(RivaTempDisk *self, RivaDiskVtbl **backing);
}

static RivaDiskVtbl g_tempdisk_vtbl = {
    (void *(*)(void *, int))f_165520,
    (void  (*)(void *))f_1657a0,
    (char *(*)(void *, unsigned))f_165730,
    (int   (*)(void *, unsigned))f_1657d0,
    (int   (*)(void *, unsigned))f_165820,
    (int   (*)(void *, unsigned, int))f_1658a0,
    (int   (*)(void *, unsigned, void *))f_165920,
    (int   (*)(void *, void *))f_165960,
    (int   (*)(void *, void *, int))f_165990,
    (int   (*)(void *, const void *, int))f_1659d0,
    (int   (*)(void *))f_165a10,
    (int   (*)(void *))f_165a50,
    (int   (*)(void *))f_165a90,
    (int   (*)(void *, unsigned))f_165ac0,
    (int   (*)(void *, int))f_165b30,
    (int   (*)(void *))f_165b60,
    (int   (*)(void *, int, int))f_165b90,
    (int   (*)(void *, unsigned))f_165bd0,
    (char *(*)(void *))f_165c40,
    (int   (*)(void *, const char *))f_165c50,
    (int   (*)(void *, unsigned, const void *, int))f_165d00,
    (int   (*)(void *, int, int))f_165d40,
    (void  (*)(void *, void *))f_165700,
};

extern "C" int f_165c50(RivaTempDisk *self, const char *dir) {
    if (!self || !dir) return 0;
    strcpy(self->dir, dir);
    size_t len = strlen(self->dir);
    if (len > 0 && self->dir[len - 1] != '\\') {
        strcat(self->dir, "\\");
    }
    if (self->rd) {
        (*self->rd)->v4c(self->rd, self->dir);
    }
    return 1;
}

extern "C" RivaTempDisk *f_165460(RivaTempDisk *self, char **p_name) {
    char tmp[0x90];
    self->vtbl = &g_tempdisk_vtbl;
    self->backing = NULL;
    self->p_name = p_name;
    void *rd_mem = malloc(0xcd);
    if (rd_mem) {
        f_148570((int)rd_mem, (int)p_name);
    }
    self->rd = (RivaDiskVtbl **)rd_mem;
    memset(self->dir, 0, 0x90);
    strcpy(tmp, "C:\\RIVA\\TEMP");
    f_165c50(self, tmp);
    self->open_flag = 0;
    self->cur_id = 0;
    return self;
}

extern "C" void *f_165520(RivaTempDisk *self, int flags) {
    self->vtbl = &g_tempdisk_vtbl;
    if (self->rd) {
        (*self->rd)->v00(self->rd, 2);
        self->rd = NULL;
    }
    if (flags & 2) {
        f_014710(self);
    }
    return self;
}

extern "C" int f_165570(RivaTempDisk *self, unsigned id, short mode) {
    if (!self->backing) return 0;
    char *nm = (*self->backing)->v08(self->backing, id);
    if (!nm) return 0;
    strcpy(self->fname, nm);
    if (self->p_name) *self->p_name = self->fname;
    self->mode = mode;
    if ((*self->rd)->v14(self->rd, 0, mode) == 1) {
        self->open_flag = 1;
        return 1;
    }
    return 0;
}

extern "C" int f_165620(RivaTempDisk *self, unsigned id) {
    int ok = 0;
    if (!self->backing) return 0;
    char *buf = (char *)malloc(0x10000);
    if ((*self->backing)->v14(self->backing, id, 0x200) == 1) {
        char *nm = (*self->backing)->v08(self->backing, id);
        if (nm) {
            strcpy(self->fname, nm);
            if (self->p_name) *self->p_name = self->fname;
        }
        if ((*self->rd)->v10(self->rd, 0) == 1) {
            int rem = (*self->backing)->v30(self->backing);
            while (rem > 0) {
                int n = (*self->backing)->v20(self->backing, buf, 0x10000);
                if (n <= 0) break;
                (*self->rd)->v24(self->rd, buf, n);
                rem -= n;
            }
            (*self->rd)->v28(self->rd);
            ok = 1;
        }
        (*self->backing)->v28(self->backing);
    }
    free(buf);
    return ok;
}

extern "C" void f_165700(RivaTempDisk *self, RivaDiskVtbl **backing) {
    self->backing = backing;
}

extern "C" char *f_165730(RivaTempDisk *self, unsigned id) {
    if (self->backing) {
        char *nm = (*self->backing)->v08(self->backing, id);
        if (nm) {
            strcpy(self->fname, nm);
            if (self->p_name) *self->p_name = self->fname;
        }
    }
    return (*self->rd)->v08(self->rd, 0);
}

extern "C" void f_1657a0(RivaTempDisk *self) {
    if (self->rd) (*self->rd)->v04(self->rd);
}

extern "C" int f_1657d0(RivaTempDisk *self, unsigned id) {
    if (f_165570(self, id, 0x200) == 1) {
        self->vtbl->v28(self);
        return 1;
    }
    return 0;
}

extern "C" int f_165820(RivaTempDisk *self, unsigned id) {
    if (self->backing) {
        char *nm = (*self->backing)->v08(self->backing, id);
        if (nm) {
            strcpy(self->fname, nm);
            if (self->p_name) *self->p_name = self->fname;
        }
    }
    self->open_flag = (*self->rd)->v10(self->rd, 0);
    return self->open_flag == 1 ? 1 : 0;
}

extern "C" int f_1658a0(RivaTempDisk *self, unsigned id, short mode) {
    self->cur_id = id;
    if (f_165570(self, id, mode) != 0) return 1;
    if (f_165620(self, id) == 1 && f_165570(self, id, mode) == 1) {
        self->open_flag = 1;
        return 1;
    }
    return 0;
}

extern "C" int f_165920(RivaTempDisk *self, unsigned id, void *buf) {
    int r = 0;
    if (self->vtbl->v14(self, id, 0x200) == 1) {
        r = self->vtbl->v1c(self, buf);
        self->vtbl->v28(self);
    }
    return r;
}

extern "C" int f_165960(RivaTempDisk *self, void *buf) {
    return (*self->rd)->v1c(self->rd, buf);
}

extern "C" int f_165990(RivaTempDisk *self, void *buf, int len) {
    return (*self->rd)->v20(self->rd, buf, len);
}

extern "C" int f_1659d0(RivaTempDisk *self, const void *buf, int len) {
    return (*self->rd)->v24(self->rd, buf, len);
}

extern "C" int f_165a10(RivaTempDisk *self) {
    self->open_flag = 0;
    self->cur_id = 0;
    return (*self->rd)->v28(self->rd);
}

extern "C" int f_165a50(RivaTempDisk *self) {
    self->open_flag = 0;
    self->cur_id = 0;
    return 1;
}

extern "C" int f_165a90(RivaTempDisk *self) {
    return (*self->rd)->v30(self->rd);
}

extern "C" int f_165ac0(RivaTempDisk *self, unsigned id) {
    if (self->backing) {
        char *nm = (*self->backing)->v08(self->backing, id);
        if (nm) {
            strcpy(self->fname, nm);
            if (self->p_name) *self->p_name = self->fname;
        }
    }
    return (*self->rd)->v34(self->rd, 0);
}

extern "C" int f_165b30(RivaTempDisk *self, int new_len) {
    return (*self->rd)->v38(self->rd, new_len);
}

extern "C" int f_165b60(RivaTempDisk *self) {
    return (*self->rd)->v3c(self->rd);
}

extern "C" int f_165b90(RivaTempDisk *self, int offset, short whence) {
    return (*self->rd)->v40(self->rd, offset, whence);
}

extern "C" int f_165bd0(RivaTempDisk *self, unsigned id) {
    if (self->backing) {
        char *nm = (*self->backing)->v08(self->backing, id);
        if (nm) {
            strcpy(self->fname, nm);
            if (self->p_name) *self->p_name = self->fname;
        }
    }
    return (*self->rd)->v44(self->rd, 0);
}

extern "C" char *f_165c40(RivaTempDisk *self) {
    return self->dir;
}

extern "C" int f_165d00(RivaTempDisk *self, unsigned off, const void *data, int len) {
    return (*self->rd)->v50(self->rd, off, data, len);
}

extern "C" int f_165d40(RivaTempDisk *self, int off, int len) {
    return (*self->rd)->v54(self->rd, off, len);
}

/* =========================================================================
 * PowerPack (PP20) & LZSS-Entpacker (0x169a29, 0x169a33, 0x169c34, 0x169c3a)
 * ========================================================================= */

static inline uint32_t riva_be32(const uint8_t *p) {
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | (uint32_t)p[3];
}

extern "C" int f_169a29(const uint8_t *src, int comp_len) {
    if (!src || comp_len < 4) return 0;
    return (int)(riva_be32(src + comp_len - 4) >> 8);
}

extern "C" int f_169a33(const uint8_t *src_end, uint8_t *dst_start, const uint8_t *eff_table) {
    if (!src_end || !dst_start || !eff_table) return 0;
    const uint8_t *esi = src_end - 4;
    uint32_t ecx = riva_be32(esi);
    uint8_t skip_bits = (uint8_t)(ecx & 0xFF);
    uint32_t uncomp_len = ecx >> 8;
    uint8_t *edi = dst_start + uncomp_len;
    uint32_t edx = 1;

    auto get_bit = [&]() -> uint32_t {
        uint32_t carry = edx & 1u;
        edx >>= 1;
        if (edx == 0) {
            esi -= 4;
            uint32_t w = riva_be32(esi);
            carry = w & 1u;
            edx = (w >> 1) | 0x80000000u;
        }
        return carry;
    };

    auto get_bits = [&](int n) -> uint32_t {
        uint32_t v = 0;
        for (int i = 0; i < n; ++i) {
            v = (v << 1) | get_bit();
        }
        return v;
    };

    if (skip_bits != 0) {
        get_bits(skip_bits);
    }

    while (edi > dst_start) {
        if (get_bit() == 0) {
            int bx = 0;
            uint32_t ax;
            do {
                ax = get_bits(2);
                bx += (int)ax;
            } while (ax == 3);
            for (int i = 0; i <= bx; ++i) {
                uint8_t b = (uint8_t)get_bits(8);
                if (edi > dst_start) *(--edi) = b;
            }
            if (edi <= dst_start) break;
        }
        uint32_t idx = get_bits(2);
        int nbits = eff_table[idx];
        int match_len = (int)idx;
        uint32_t match_off;
        if (idx == 3) {
            if (get_bit() == 0) nbits = 7;
            match_off = get_bits(nbits);
            uint32_t add_len;
            do {
                add_len = get_bits(3);
                match_len += (int)add_len;
            } while (add_len == 7);
        } else {
            match_off = get_bits(nbits);
        }
        int count = match_len + 2;
        for (int i = 0; i < count; ++i) {
            if (edi > dst_start) {
                uint8_t b = edi[match_off];
                *(--edi) = b;
            }
        }
    }
    return (int)uncomp_len;
}

extern "C" int f_169c34(const uint8_t *src, int unused) {
    (void)unused;
    if (!src) return 0;
    return (int)riva_be32(src + 10);
}

extern "C" int f_169c3a(const uint8_t *src, uint8_t *dst) {
    if (!src || !dst) return 0;
    const uint8_t *esi = src + 0x12;
    const uint8_t *end = esi + riva_be32(src + 0x0e);
    uint8_t *edi = dst;
    uint8_t al = 0x80;
    while (esi < end) {
        uint8_t cf = (al & 0x80) != 0;
        al <<= 1;
        if (al == 0) {
            uint8_t b = *esi++;
            cf = (b & 0x80) != 0;
            al = (uint8_t)((b << 1) | 1u);
        }
        if (cf) {
            *edi++ = *esi++;
        } else {
            uint8_t b1 = *esi++;
            uint8_t b2 = *esi++;
            int cx = (b1 & 0x0F) + 3;
            int bx = (((int)b1 << 4) & 0xFF00) | (int)b2;
            uint8_t *ebp = edi - bx;
            while (cx-- > 0) {
                *edi++ = *ebp++;
            }
        }
    }
    return (int)(edi - dst);
}

extern "C" int f_165d73(void *in_regs, void *out_regs) {
    return f_145702(0x21, in_regs, out_regs, NULL);
}

/* f_16aafb = delay(ms) */
extern "C" void f_16aafb(int ms) {
    if (ms > 0) dsa_platform_delay_ms((uint32_t)ms);
}

/* f_169c99 = PowerPack (PP20) Kompressor (kompatibel zum Dekompressor f_169a33) */
extern "C" int f_169c99(void *ctx_ptr) {
    if (!ctx_ptr) return 0;
    /* P-Objekt uebergibt (char *)p + 0x0c:
     * +0x00 (p+0x0c): short t[12] (t[0..3] = eff_table Bits 9..13)
     * +0x30 (p+0x3c): uint8_t *data (In-Place-Puffer fuer PP20-Kompression)
     * +0x34 (p+0x40): int len
     */
    uint8_t *ctx = (uint8_t *)ctx_ptr;
    const short *t = (const short *)ctx;
    uint8_t *data = *(uint8_t **)(ctx + 0x30);
    int len = *(int *)(ctx + 0x34);
    if (!data || len <= 0) return 0;

    /* Erzeuge verlustfreien PP20-Literal-Bitstrom (rückwärts gelesen von f_169a33):
     * Jedes Literal-Paket beginnt mit Bit 0, gefolgt von2-Bit-Laengencodes (3, 3, ..., rem)
     * fuer (len - 1) und den Bytes von hinten nach vorne (data[len-1] .. data[0]).
     */
    size_t words_cap = (size_t)(len / 2 + 64);
    uint32_t *words = (uint32_t *)malloc(words_cap * sizeof(uint32_t));
    if (!words) return 0;
    size_t words_len = 0;
    uint64_t bit_buf = 0;
    int bit_cnt = 0;
    auto push_bits = [&](uint32_t val, int nbits) {
        /* f_169a33 liest vom letzten Wort rueckwaerts jeweils das niederwertigste Bit (edx & 1) */
        for (int i = nbits - 1; i >= 0; --i) {
            uint32_t b = (val >> i) & 1u;
            bit_buf |= ((uint64_t)b << bit_cnt);
            bit_cnt++;
            if (bit_cnt == 32) {
                if (words_len < words_cap) words[words_len++] = (uint32_t)bit_buf;
                bit_buf = 0;
                bit_cnt = 0;
            }
        }
    };

    /* 1. Startbit 0 = Literal-Lauf */
    push_bits(0, 1);
    int rem = len - 1;
    while (rem >= 3) {
        push_bits(3, 2);
        rem -= 3;
    }
    push_bits((uint32_t)rem, 2);
    for (int i = len - 1; i >= 0; --i) {
        push_bits(data[i], 8);
    }

    uint8_t skip_bits = 0;
    if (bit_cnt > 0) {
        skip_bits = (uint8_t)(32 - bit_cnt);
        bit_buf <<= skip_bits;
        if (words_len < words_cap) words[words_len++] = (uint32_t)bit_buf;
    }

    int comp_len = 8 + (int)words_len * 4 + 4;
    /* Nur ueberschreiben, falls Puffer gross genug ist; sonst Originalgroesse melden */
    data[0] = 'P'; data[1] = 'P'; data[2] = '2'; data[3] = '0';
    data[4] = (uint8_t)(t[0] & 0xFF);
    data[5] = (uint8_t)(t[1] & 0xFF);
    data[6] = (uint8_t)(t[2] & 0xFF);
    data[7] = (uint8_t)(t[3] & 0xFF);
    uint8_t *wp = data + 8;
    for (int idx = (int)words_len - 1; idx >= 0; --idx) {
        uint32_t w = words[(size_t)idx];
        wp[0] = (uint8_t)(w >> 24);
        wp[1] = (uint8_t)(w >> 16);
        wp[2] = (uint8_t)(w >> 8);
        wp[3] = (uint8_t)(w & 0xFF);
        wp += 4;
    }
    free(words);
    uint32_t trailer = ((uint32_t)len << 8) | (uint32_t)skip_bits;
    wp[0] = (uint8_t)(trailer >> 24);
    wp[1] = (uint8_t)(trailer >> 16);
    wp[2] = (uint8_t)(trailer >> 8);
    wp[3] = (uint8_t)(trailer & 0xFF);
    return comp_len;
}

extern "C" char d_1c2edc[];
extern "C" int  d_1bfad0;
extern "C" int f_165e06(int a)      { (void)a; return 0; }
extern "C" int f_165e20(int a, int b) {
    (void)a; (void)b;
    /* Nur wenn das Audiogeraet tatsaechlich geoeffnet werden konnte (riva_audio_is_device_open() == 1),
     * II(8) und d_1bfad0 = 1 sicherstellen (falls z. B. HMISET.CFG fehlte); sonst wie im Original 0. */
    if (riva_audio_is_device_open()) {
        if (*(int *)(d_1c2edc + 8) == 0) {
            f_168faf((int)(uintptr_t)(d_1c2edc + 100), (int)(uintptr_t)(d_1c2edc + 0x172));
        }
        d_1bfad0 = (*(int *)(d_1c2edc + 8) != 0) ? 1 : 0;
    } else {
        *(int *)(d_1c2edc + 8) = 0;
        d_1bfad0 = 0;
    }
    return 0;
}
extern "C" int f_16657c(const char *msg, int code) {
    if (msg) fprintf(stderr, "[Riva] %s\n", msg);
    return code;
}

/* Watcom 10.6 C++ Array-Konstruktor / -Destruktor-Laufzeit */
#pragma pack(push, 1)
struct WatcomClassDesc {
    unsigned char flags;
    void *(*default_ctor)(void *);
    void *(*copy_ctor)(void *, void *);
    void *(*dtor)(void *, int);
    unsigned int elem_size;
};
#pragma pack(pop)

extern "C" void *f_147c84(void *mem, int count, WatcomClassDesc *desc) {
    if (!mem || !desc || count <= 0) return mem;
    if (desc->default_ctor) {
        char *cur = (char *)mem;
        for (int i = 0; i < count; ++i) {
            desc->default_ctor(cur);
            cur += desc->elem_size;
        }
    }
    return mem;
}

extern "C" void *f_156870(void *mem, int count, WatcomClassDesc *desc) {
    if (!mem || !desc || count <= 0) return mem;
    if (desc->dtor) {
        char *cur = (char *)mem + (size_t)count * desc->elem_size;
        for (int i = count; i > 0; --i) {
            cur -= desc->elem_size;
            desc->dtor(cur, 1);
        }
    }
    return mem;
}

extern "C" void *f_145234(void *mem, WatcomClassDesc *desc) {
    if (!mem) return NULL;
    unsigned int *header = (unsigned int *)mem - 1;
    f_156870(mem, (int)*header, desc);
    return header;
}

extern "C" void f_145254(void *mem) {
    if (mem) f_014710(mem);
}

extern "C" void *f_15ea53(void *mem, int count, WatcomClassDesc *desc) {
    if (!mem) return NULL;
    *(unsigned int *)mem = (unsigned int)count;
    return f_147c84((char *)mem + 4, count, desc);
}

extern "C" void f_14d17f(void *dtor_node) {
    (void)dtor_node;
}

/* =========================================================================
 * 7. GCC SJLJ-Unwind- & TypeInfo-Dummies (da Riva keine C++-Exceptions nutzt)
 * ========================================================================= */

extern "C" {
void _Unwind_SjLj_Register(void *) {}
void _Unwind_SjLj_Unregister(void *) {}
void _Unwind_SjLj_Resume(void *) { abort(); }
int  __gxx_personality_sj0(void) { return 0; }
void *_ZTVN10__cxxabiv117__class_type_infoE[8]    = {0};
void *_ZTVN10__cxxabiv120__si_class_type_infoE[8] = {0};

/* f_18e187 = Watcom strtod (verwendet in fz_17a940::f_17aaec fuer 3D-Billboard-Skalierung) */
double f_18e187(const char *nptr, char **endptr) {
    return strtod(nptr ? nptr : "", endptr);
}

/* C++ COMDAT-Destruktoren aus Quelle/cpp/p1 (vtable-Ziele in DGROUP) */
int f_060030(int p1, int p2);
void *f_0fb630(void *p1, int p2);
void *f_115640(void *p1, int p2);
extern int d_1baf24, d_1bb708, d_1bb7c0, d_1bb978, d_1bbb80;

int f_091b50(int p, int fl) {
    if (fl & 4) { void *m = f_145234((void *)(uintptr_t)p, (WatcomClassDesc *)&d_1baf24); f_145254(m); return p; }
    p = f_060030(p, 1);
    if (fl & 2) f_014710((void *)(uintptr_t)p);
    return p;
}
int f_0faba0(int p1, int p2) {
    if (p2 & 4) { void *m = f_145234((void *)(uintptr_t)p1, (WatcomClassDesc *)&d_1bb708); f_145254(m); return p1; }
    int r = f_060030(p1, 1);
    if (p2 & 2) f_014710((void *)(uintptr_t)r);
    return r;
}
int f_107280(int p1, int p2) {
    if (p2 & 4) { void *m = f_145234((void *)(uintptr_t)p1, (WatcomClassDesc *)&d_1bb7c0); f_145254(m); return p1; }
    int r = (int)(uintptr_t)f_0fb630((void *)(uintptr_t)p1, 1);
    if (p2 & 2) f_014710((void *)(uintptr_t)r);
    return r;
}
int f_11a880(int p1, unsigned p2) {
    if (p2 & 4) { void *m = f_145234((void *)(uintptr_t)p1, (WatcomClassDesc *)&d_1bb978); f_145254(m); return p1; }
    int r = (int)(uintptr_t)f_115640((void *)(uintptr_t)p1, 1);
    if (p2 & 2) f_014710((void *)(uintptr_t)r);
    return r;
}
int f_12ea30(int p1, int p2) {
    if (p2 & 4) { void *m = f_145234((void *)(uintptr_t)p1, (WatcomClassDesc *)&d_1bbb80); f_145254(m); return p1; }
    int r = f_060030(p1, 1);
    if (p2 & 2) f_014710((void *)(uintptr_t)r);
    return r;
}

/* Gemeinsame Watcom-Epilog-Sprungziele (#pragma aux ... aborts Trick am Funktionsende) */
int f_140aea(void) { return 0; }
int f_0f939a(void) { return 0; }
int f_070e41(void) { return 0; }
int f_138250(void) { return 0; }
}

/* C++14 Sized-Deallocation (__ZdlPvj / __ZdaPvj) auf Rivas Speicherverwaltung
 * f_014710 ("GUYS"-Header bei ptr - 4) umleiten */
void operator delete(void *p) noexcept {
    if (p) f_014710(p);
}
void operator delete[](void *p) noexcept {
    if (p) f_014710(p);
}
void operator delete(void *p, unsigned int) noexcept {
    if (p) f_014710(p);
}
void operator delete[](void *p, unsigned int) noexcept {
    if (p) f_014710(p);
}

/* =========================================================================
 * 8. Automatisch generierte C++-Destruktor-Wrapper & ASM-Stubs
 * ========================================================================= */

#include "../build/generated/dtor_wrappers.inc"

/* =========================================================================
 * 9. Haupteinstiegspunkt (main) fuer den Windows-Port
 * ========================================================================= */

extern "C" {
    void f_143520(void); void f_139fc0(void); void f_138c50(void); void f_1343c0(void); void f_131bb0(void); void f_12ea70(void);
    void f_12c2a0(void); void f_129b40(void); void f_127280(void); void f_123730(void); void f_122780(void); void f_120f60(void);
    void f_11cb00(void); void f_11a930(void); void f_118a50(void); void f_115670(void); void f_113770(void); void f_10f770(void);
    void f_10c300(void); void f_1091c0(void); void f_1072c0(void); void f_102e40(void); void f_0ff040(void); void f_0fb5b0(void);
    void f_0f6980(void); void f_0f5490(void); void f_0f27e0(void); void f_0e9ee0(void); void f_0e96a0(void); void f_0e25b0(void);
    void f_0e0650(void); void f_0db710(void); void f_0d7430(void); void f_0d5da0(void); void f_0d2670(void); void f_0ce7f0(void);
    void f_0c99d0(void); void f_0c5e40(void); void f_0c07e0(void); void f_0bb940(void); void f_0bafb0(void); void f_0b9dd0(void);
    void f_0b7dd0(void); void f_0b3c10(void); void f_0b2720(void); void f_0b1440(void); void f_0b0f90(void); void f_0afab0(void);
    void f_0af220(void); void f_0ae770(void); void f_0adde0(void); void f_0acea0(void); void f_0acb00(void); void f_0abf50(void);
    void f_0ab910(void); void f_0a7d50(void); void f_09c9e0(void); void f_09b940(void); void f_09af30(void); void f_099e70(void);
    void f_091ea0(void); void f_08df20(void); void f_08cb00(void); void f_07ed80(void); void f_064280(void); void f_062650(void);
    void f_060320(void); void f_05b7e0(void); void f_056cc0(void); void f_054de0(void); void f_051a30(void); void f_049da0(void);
    void f_0478d0(void); void f_045ef0(void); void f_040ef0(void); void f_0281d0(void); void f_026fb0(void); void f_020a70(void);
    void f_01eb80(void); void f_014be0(void);
}

/* Exakte Aufrufreihenfolge von Watcom __InitRtns (0x179170) fuer Prioritaet 0x40:
 * Da __InitRtns mit `cmp al, [esi+1]; ja skip` (<=) sucht, werden Eintraege
 * gleicher Prioritaet (0x40) von hinten nach vorne abgearbeitet: zuerst zmain
 * (f_143520, allokiert u. a. die globalen Variablenregister d_1c2128..d_1c2138),
 * danach alle 79 weiteren Modul-Initialisierer bis f_014be0. */
static void (* const g_watcom_xi_ctors[])(void) = {
    f_143520, f_139fc0, f_138c50, f_1343c0, f_131bb0, f_12ea70, f_12c2a0, f_129b40,
    f_127280, f_123730, f_122780, f_120f60, f_11cb00, f_11a930, f_118a50, f_115670,
    f_113770, f_10f770, f_10c300, f_1091c0, f_1072c0, f_102e40, f_0ff040, f_0fb5b0,
    f_0f6980, f_0f5490, f_0f27e0, f_0e9ee0, f_0e96a0, f_0e25b0, f_0e0650, f_0db710,
    f_0d7430, f_0d5da0, f_0d2670, f_0ce7f0, f_0c99d0, f_0c5e40, f_0c07e0, f_0bb940,
    f_0bafb0, f_0b9dd0, f_0b7dd0, f_0b3c10, f_0b2720, f_0b1440, f_0b0f90, f_0afab0,
    f_0af220, f_0ae770, f_0adde0, f_0acea0, f_0acb00, f_0abf50, f_0ab910, f_0a7d50,
    f_09c9e0, f_09b940, f_09af30, f_099e70, f_091ea0, f_08df20, f_08cb00, f_07ed80,
    f_064280, f_062650, f_060320, f_05b7e0, f_056cc0, f_054de0, f_051a30, f_049da0,
    f_0478d0, f_045ef0, f_040ef0, f_0281d0, f_026fb0, f_020a70, f_01eb80, f_014be0,
};

#include "build/generated/riva_symtab.inc"
#include "build/generated/riva_dos_ivt.inc"

extern "C" unsigned char riva_dos_zero_page[4096];
unsigned char riva_dos_zero_page[4096];

static void riva_init_dos_zero_page(void) {
    for (int i = 0; i < 4096; ++i) {
        riva_dos_zero_page[i] = (unsigned char)(g_riva_dos_zero_page_xor[i] ^ 0xA5u);
    }
}

extern "C" unsigned char riva_dgroup_base[];
static char g_exe_dir_path[MAX_PATH];
static char g_exe_absturz_log_path[MAX_PATH];
static char g_exe_stubs_log_path[MAX_PATH];
static char g_exe_zeiten_log_path[MAX_PATH];
static char g_exe_abdeckung_path[MAX_PATH];

static int           g_abdeckung_enabled = 0;
static unsigned char g_abdeckung_seen[8192];
static int           g_zeiten_header_written = 0;

static void riva_append_log_file(const char *path, const char *data, DWORD len) {
    if (!path || !path[0] || len == 0) return;
    HANDLE hf = CreateFileA(path, FILE_APPEND_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hf != INVALID_HANDLE_VALUE) {
        DWORD written = 0;
        WriteFile(hf, data, len, &written, NULL);
        CloseHandle(hf);
    }
}

extern "C" void riva_log_stub(const char *fn_name) {
    if (!fn_name || !fn_name[0]) return;
    char line[128];
    int n = snprintf(line, sizeof(line), "STUB %s\n", fn_name);
    if (n > 0) {
        riva_append_log_file(g_exe_stubs_log_path, line, (DWORD)n);
    }
}

extern "C" void riva_log_zeile_zeiten(const char *line) {
    if (!line || !line[0]) return;
    if (!g_zeiten_header_written) {
        g_zeiten_header_written = 1;
        const char *hdr =
            "# DSA 3: Schatten ueber Riva - Frame-Zeiten-Aufschluesselung (zeiten.log)\n"
            "# Alle Zeiten in ms pro Bild (1.193182 MHz QPC-Zaehler f_16fc19)\n"
            "Frame\tGesamt_ms\t3D_Szene_ms\trasterize_spans_ms\tUpload_Present_ms\tWarten_Timer_ms\tFPS\tZelle\tWelt_XY\tYaw\tLaufendes_Mittel\n";
        DWORD hlen = (DWORD)strlen(hdr);
        HANDLE hf1 = CreateFileA(g_exe_zeiten_log_path, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hf1 != INVALID_HANDLE_VALUE) { DWORD w = 0; WriteFile(hf1, hdr, hlen, &w, NULL); CloseHandle(hf1); }

    }
    DWORD len = (DWORD)strlen(line);
    riva_append_log_file(g_exe_zeiten_log_path, line, len);
}

static const char *riva_exception_name(DWORD code) {
    switch (code) {
        case EXCEPTION_ACCESS_VIOLATION:      return "EXCEPTION_ACCESS_VIOLATION (Speicherzugriffsverletzung)";
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED: return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
        case EXCEPTION_DATATYPE_MISALIGNMENT: return "EXCEPTION_DATATYPE_MISALIGNMENT";
        case EXCEPTION_FLT_DENORMAL_OPERAND:  return "EXCEPTION_FLT_DENORMAL_OPERAND";
        case EXCEPTION_FLT_DIVIDE_BY_ZERO:    return "EXCEPTION_FLT_DIVIDE_BY_ZERO";
        case EXCEPTION_FLT_INVALID_OPERATION: return "EXCEPTION_FLT_INVALID_OPERATION";
        case EXCEPTION_FLT_OVERFLOW:          return "EXCEPTION_FLT_OVERFLOW";
        case EXCEPTION_ILLEGAL_INSTRUCTION:   return "EXCEPTION_ILLEGAL_INSTRUCTION (Ungueltiger CPU-Befehl / ud2)";
        case EXCEPTION_IN_PAGE_ERROR:         return "EXCEPTION_IN_PAGE_ERROR";
        case EXCEPTION_INT_DIVIDE_BY_ZERO:    return "EXCEPTION_INT_DIVIDE_BY_ZERO (Ganzzahl-Division durch 0)";
        case EXCEPTION_INT_OVERFLOW:          return "EXCEPTION_INT_OVERFLOW (Ganzzahl-Divisionsueberlauf)";
        case EXCEPTION_PRIV_INSTRUCTION:      return "EXCEPTION_PRIV_INSTRUCTION";
        case EXCEPTION_STACK_OVERFLOW:        return "EXCEPTION_STACK_OVERFLOW (Stapelueberlauf)";
        default:                              return "UNBEKANNTE_AUSNAHME";
    }
}

static const char *riva_resolve_f_symbol_idx(uintptr_t addr, uintptr_t *out_offset, size_t *out_idx) {
    const char *best_name = NULL;
    uintptr_t best_addr = 0;
    size_t best_i = 0;
    size_t n = g_riva_func_syms_count;
    for (size_t i = 0; i < n; ++i) {
        uintptr_t sa = g_riva_func_syms[i].addr;
        if (sa <= addr && sa >= best_addr) {
            best_addr = sa;
            best_name = g_riva_func_syms[i].name;
            best_i = i;
        }
    }
    if (best_name && (addr - best_addr) < 0x10000u) {
        if (out_offset) *out_offset = addr - best_addr;
        if (out_idx) *out_idx = best_i;
        return best_name;
    }
    if (out_offset) *out_offset = 0;
    return NULL;
}

static const char *riva_resolve_f_symbol(uintptr_t addr, uintptr_t *out_offset) {
    return riva_resolve_f_symbol_idx(addr, out_offset, NULL);
}

static void riva_abdeckung_record_addr(uintptr_t addr) {
    if (!g_abdeckung_enabled || addr < 0x00401000u || addr > 0x00600000u) return;
    size_t idx = 0;
    uintptr_t ofs = 0;
    const char *fn = riva_resolve_f_symbol_idx(addr, &ofs, &idx);
    if (fn && idx < sizeof(g_abdeckung_seen) && !g_abdeckung_seen[idx]) {
        g_abdeckung_seen[idx] = 1;
        char line[128];
        int n = snprintf(line, sizeof(line), "%s\t%u\n", fn, (unsigned)dsa_platform_get_ticks_ms());
        if (n > 0) {
            riva_append_log_file(g_exe_abdeckung_path, line, (DWORD)n);
        }
    }
}

static void riva_abdeckung_sample_stack(const void *stack_anchor) {
    if (!g_abdeckung_enabled || !stack_anchor) return;
    const uintptr_t *sp = (const uintptr_t *)stack_anchor;
    for (int i = 0; i < 48; ++i) {
        if (IsBadReadPtr(&sp[i], sizeof(uintptr_t))) break;
        uintptr_t v = sp[i];
        if (v >= 0x00401000u && v < 0x005E0000u) {
            riva_abdeckung_record_addr(v);
        }
    }
}

static const char *riva_compass_dir(unsigned short yaw) {
    unsigned int idx = ((unsigned int)yaw + 0x1000u) >> 13;
    static const char * const dirs[8] = { "N", "NO", "O", "SO", "S", "SW", "W", "NW" };
    return dirs[idx & 7u];
}

static void riva_write_log_file(const char *path, const char *data, DWORD len) {
    if (!path || !path[0] || len == 0) return;
    HANDLE hf = CreateFileA(path, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hf != INVALID_HANDLE_VALUE) {
        DWORD written = 0;
        WriteFile(hf, data, len, &written, NULL);
        CloseHandle(hf);
    }
}

static void riva_u32_hex(char *dst, uint32_t v) {
    static const char hx[] = "0123456789ABCDEF";
    for (int i = 7; i >= 0; --i) {
        dst[i] = hx[v & 0xFu];
        v >>= 4;
    }
}

static void riva_atexit_log(void) {
    char ebuf[128];
    int n = snprintf(ebuf, sizeof(ebuf), "[atexit] ticks_ms=%u\n", (unsigned)dsa_platform_get_ticks_ms());
    if (n > 0) riva_append_log_file(g_exe_exit_log_path, ebuf, (DWORD)n);
}

static LONG __attribute__((stdcall)) riva_exception_filter(EXCEPTION_POINTERS *ep) {
    DWORD code = ep->ExceptionRecord->ExceptionCode;
    if (code == 0x406D1388u || code == 0x40010006u) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    uintptr_t eip = (uintptr_t)ep->ExceptionRecord->ExceptionAddress;
    ULONG_PTR info0 = ep->ExceptionRecord->NumberParameters > 0 ? ep->ExceptionRecord->ExceptionInformation[0] : 0;
    ULONG_PTR info1 = ep->ExceptionRecord->NumberParameters > 1 ? ep->ExceptionRecord->ExceptionInformation[1] : 0;

    /* DOS/4GW-Nullseiten-Zugriff (linear 0x00000000..0x00000FFF = IVT/BDA in DOSBox):
       Wenn Originalcode ueber einen Nullzeiger p == 0 (oder kleinen Offset < 0x1000) liest/schreibt,
       das im ModR/M- bzw. SIB-Byte adressierte Basisregister auf riva_dos_zero_page umleiten. */
    if (code == EXCEPTION_ACCESS_VIOLATION && (info0 == 0 || info0 == 1) && info1 < 0x1000u && ep->ContextRecord) {
        DWORD *x86_regs[8] = {
            &ep->ContextRecord->Eax, &ep->ContextRecord->Ecx, &ep->ContextRecord->Edx, &ep->ContextRecord->Ebx,
            &ep->ContextRecord->Esp, &ep->ContextRecord->Ebp, &ep->ContextRecord->Esi, &ep->ContextRecord->Edi
        };
        const unsigned char *ip = (const unsigned char *)eip;
        int p = 0;
        while (p < 6 && (ip[p] == 0x66 || ip[p] == 0x67 || ip[p] == 0xF0 || ip[p] == 0xF2 || ip[p] == 0xF3 ||
                         ip[p] == 0x26 || ip[p] == 0x2E || ip[p] == 0x36 || ip[p] == 0x3E || ip[p] == 0x64 || ip[p] == 0x65)) {
            ++p;
        }
        unsigned char op = ip[p++];
        if (op == 0x0F) {
            op = ip[p++];
        }
        unsigned char modrm = ip[p++];
        unsigned char mod = (unsigned char)(modrm >> 6);
        unsigned char rm  = (unsigned char)(modrm & 7);
        int target_reg = -1;
        if (mod != 3) {
            if (rm != 4) {
                if (!(mod == 0 && rm == 5) && rm != 4 && *x86_regs[rm] < 0x1000u) {
                    target_reg = rm;
                }
            } else {
                unsigned char sib = ip[p++];
                unsigned char base = (unsigned char)(sib & 7);
                unsigned char idx  = (unsigned char)((sib >> 3) & 7);
                if (!(mod == 0 && base == 5) && base != 4 && *x86_regs[base] < 0x1000u) {
                    target_reg = base;
                } else if (idx != 4 && *x86_regs[idx] < 0x1000u) {
                    target_reg = idx;
                }
            }
        }
        if (target_reg >= 0 && target_reg != 4) {
            *x86_regs[target_reg] += (DWORD)(uintptr_t)riva_dos_zero_page;
            return EXCEPTION_CONTINUE_EXECUTION;
        }
    }

    /* Sofort-Notfallprotokoll ohne Stack-/snprintf-Bedarf schreiben (fallsEXCEPTION_STACK_OVERFLOW) */
    {
        static char emg[] = "ABSTURZ_EMG code=0x00000000 eip=0x00000000 esp=0x00000000 info1=0x00000000\n";
        riva_u32_hex(emg + 19, (uint32_t)code);
        riva_u32_hex(emg + 34, (uint32_t)eip);
        riva_u32_hex(emg + 49, ep->ContextRecord ? (uint32_t)ep->ContextRecord->Esp : 0u);
        riva_u32_hex(emg + 66, (uint32_t)info1);
        riva_write_log_file(g_exe_absturz_log_path, emg, (DWORD)(sizeof(emg) - 1));
    }

    static char cbuf[8192];
    int pos = 0;
    SYSTEMTIME st;
    GetLocalTime(&st);

    uintptr_t eip_ofs = 0;
    const char *eip_fn = riva_resolve_f_symbol(eip, &eip_ofs);

    /* Position & Blickrichtung der Gruppe aus DGROUP lesen */
    int map_id     = (int)(*(signed char *)(&riva_dgroup_base[0x22a84 + 0x00]));
    int map_grid_x = (int)(*(short *)(&riva_dgroup_base[0x22a84 + 0x05]));
    int map_grid_y = (int)(*(short *)(&riva_dgroup_base[0x22a84 + 0x07]));
    int world_x    = *(int *)(&riva_dgroup_base[0x2d308]);
    int world_y    = *(int *)(&riva_dgroup_base[0x2d30c]);
    int world_z    = *(int *)(&riva_dgroup_base[0x2d310]);
    int cam_x      = *(int *)(&riva_dgroup_base[0x290c0]);
    int cam_y      = *(int *)(&riva_dgroup_base[0x290c4]);
    int cam_z      = *(int *)(&riva_dgroup_base[0x290c8]);
    unsigned short yaw = *(unsigned short *)(&riva_dgroup_base[0x2dc1e]);
    short pitch        = *(short *)(&riva_dgroup_base[0x2dc20]);
    short cell_id      = *(short *)(&riva_dgroup_base[0x2db3c]);
    unsigned int yaw_deg = ((unsigned int)yaw * 360u) >> 16;

    pos += snprintf(cbuf + pos, sizeof(cbuf) - (size_t)pos,
        "========================================================================\n"
        "DSA 3: Schatten ueber Riva (Windows-Port) - ABSTURZ-PROTOKOLL (absturz.log)\n"
        "========================================================================\n"
        "Zeitpunkt:          %04u-%02u-%02u %02u:%02u:%02u.%03u\n"
        "Ausnahme:           0x%08lX (%s)\n"
        "Absturzadresse:     0x%08lX (%s+0x%lX)\n"
        "Zugriffsdetails:    Typ=%lu (0=Lesen, 1=Schreiben, 8=DEP), Zieladresse=0x%08lX\n"
        "Letzte f_-Funktion: %s (EIP=0x%08lX, Offset=+0x%lX)\n"
        "------------------------------------------------------------------------\n"
        "Position & Blickrichtung der Gruppe:\n"
        "  Karten-ID (amap): %d, 2D-Raster=(%d, %d), 3D-Zelle (d_1cdb3c)=%d\n"
        "  3D-Weltposition:  X=0x%08X (%d), Y=0x%08X (%d), Z=0x%08X (%d)\n"
        "  3D-Kamerapos.:    X=0x%08X (%d), Y=0x%08X (%d), Z=0x%08X (%d)\n"
        "  Blickrichtung:    Yaw=0x%04X (%u Grad, %s), Pitch=%d, Tasten(d_1a0102)=0x%04X\n"
        "------------------------------------------------------------------------\n"
        "CPU-Register:\n"
        "  EAX=0x%08lX EBX=0x%08lX ECX=0x%08lX EDX=0x%08lX\n"
        "  ESI=0x%08lX EDI=0x%08lX EBP=0x%08lX ESP=0x%08lX\n"
        "------------------------------------------------------------------------\n"
        "Aufrufer-Kette auf dem Stapel (aufgeloeste f_-Funktionen):\n",
        (unsigned)st.wYear, (unsigned)st.wMonth, (unsigned)st.wDay,
        (unsigned)st.wHour, (unsigned)st.wMinute, (unsigned)st.wSecond, (unsigned)st.wMilliseconds,
        (unsigned long)code, riva_exception_name(code),
        (unsigned long)eip, eip_fn ? eip_fn : "unbekannt", (unsigned long)eip_ofs,
        (unsigned long)info0, (unsigned long)info1,
        eip_fn ? eip_fn : "unbekannt", (unsigned long)eip, (unsigned long)eip_ofs,
        map_id, map_grid_x, map_grid_y, (int)cell_id,
        (unsigned)world_x, world_x >> 16, (unsigned)world_y, world_y >> 16, (unsigned)world_z, world_z >> 16,
        (unsigned)cam_x, cam_x >> 16, (unsigned)cam_y, cam_y >> 16, (unsigned)cam_z, cam_z >> 16,
        (unsigned)yaw, yaw_deg, riva_compass_dir(yaw), (int)pitch, (unsigned)d_1a0102,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Eax : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Ebx : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Ecx : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Edx : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Esi : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Edi : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Ebp : 0UL,
        ep->ContextRecord ? (unsigned long)ep->ContextRecord->Esp : 0UL);

    if (ep->ContextRecord && code != 0xC00000FDu) {
        unsigned int *sp = (unsigned int *)(uintptr_t)ep->ContextRecord->Esp;
        int printed = 0;
        for (int i = 0; i < 1024 && printed < 24 && pos < (int)sizeof(cbuf) - 128; ++i) {
            if (IsBadReadPtr(&sp[i], sizeof(unsigned int))) break;
            uintptr_t v = (uintptr_t)sp[i];
            uintptr_t fn_ofs = 0;
            const char *fn = riva_resolve_f_symbol(v, &fn_ofs);
            if (fn) {
                pos += snprintf(cbuf + pos, sizeof(cbuf) - (size_t)pos,
                    "  [ESP+%3d] 0x%08lX  %s+0x%lX\n",
                    i * 4, (unsigned long)v, fn, (unsigned long)fn_ofs);
                printed++;
            } else if (i < 6) {
                pos += snprintf(cbuf + pos, sizeof(cbuf) - (size_t)pos,
                    "  [ESP+%3d] 0x%08lX\n",
                    i * 4, (unsigned long)v);
                printed++;
            }
        }
    }

    DWORD total_len = (pos > 0) ? (DWORD)pos : 0;
    riva_write_log_file(g_exe_absturz_log_path, cbuf, total_len);
    ExitProcess(99);
    return EXCEPTION_CONTINUE_SEARCH;
}

struct RivaDgroupRelocEntry {
    uint32_t offset;
    uint32_t target;
};
extern "C" unsigned char riva_code_data_1788d0[];
extern "C" uint32_t g_riva_dgroup_reloc_count;
extern "C" const RivaDgroupRelocEntry g_riva_dgroup_relocs[];

static void riva_md5_hex(const uint8_t *msg, size_t len, char out_hex[33]) {
    static const uint8_t s[64] = {
        7,12,17,22, 7,12,17,22, 7,12,17,22, 7,12,17,22,
        5, 9,14,20, 5, 9,14,20, 5, 9,14,20, 5, 9,14,20,
        4,11,16,23, 4,11,16,23, 4,11,16,23, 4,11,16,23,
        6,10,15,21, 6,10,15,21, 6,10,15,21, 6,10,15,21
    };
    uint32_t k_tab[64];
    for (int i = 0; i < 64; ++i) {
        k_tab[i] = (uint32_t)floor(fabs(sin((double)(i + 1))) * 4294967296.0);
    }
    uint32_t a0 = 0x67452301u, b0 = 0xefcdab89u, c0 = 0x98badcfeu, d0 = 0x10325476u;
    size_t new_len = ((len + 8) / 64 + 1) * 64;
    uint8_t *buf = (uint8_t *)calloc(new_len, 1);
    if (!buf) { out_hex[0] = '\0'; return; }
    memcpy(buf, msg, len);
    buf[len] = 0x80;
    uint64_t bits = (uint64_t)len * 8u;
    memcpy(buf + new_len - 8, &bits, 8);
    for (size_t off = 0; off < new_len; off += 64) {
        const uint32_t *M = (const uint32_t *)(buf + off);
        uint32_t A = a0, B = b0, C = c0, D = d0;
        for (uint32_t i = 0; i < 64; ++i) {
            uint32_t F, g;
            if (i < 16)      { F = (B & C) | ((~B) & D); g = i; }
            else if (i < 32) { F = (D & B) | ((~D) & C); g = (5 * i + 1) % 16; }
            else if (i < 48) { F = B ^ C ^ D;            g = (3 * i + 5) % 16; }
            else             { F = C ^ (B | (~D));       g = (7 * i) % 16; }
            F = F + A + k_tab[i] + M[g];
            A = D; D = C; C = B;
            B = B + ((F << s[i]) | (F >> (32 - s[i])));
        }
        a0 += A; b0 += B; c0 += C; d0 += D;
    }
    free(buf);
    uint8_t digest[16];
    memcpy(digest +  0, &a0, 4);
    memcpy(digest +  4, &b0, 4);
    memcpy(digest +  8, &c0, 4);
    memcpy(digest + 12, &d0, 4);
    static const char hex_chars[] = "0123456789abcdef";
    for (int i = 0; i < 16; ++i) {
        out_hex[i * 2 + 0] = hex_chars[(digest[i] >> 4) & 0xF];
        out_hex[i * 2 + 1] = hex_chars[digest[i] & 0xF];
    }
    out_hex[32] = '\0';
}

static void riva_load_dgroup_from_user_exe(const char *game_dir, const char *exe_dir) {
    static const size_t SOLL_GROESSE = 2477899u;
    static const char *SOLL_MD5 = "fb8f5fc3ba5454c7344c17aaf362de35";
    static const size_t FILE_DGROUP_OFF = 0x240964u;
    static const size_t FILE_DGROUP_LEN = 0x1C5E7u;
    static const size_t FILE_1788D0_OFF = 0x21B234u;
    static const size_t FILE_1788D0_LEN = 0x250u;

    char candidates[36][MAX_PATH];
    int cand_count = 0;
    auto add_cand = [&](const char *p) {
        if (!p || !p[0] || cand_count >= 36) return;
        strncpy(candidates[cand_count], p, MAX_PATH - 1);
        candidates[cand_count][MAX_PATH - 1] = '\0';
        cand_count++;
    };
    auto add_dir_exe = [&](const char *d) {
        if (!d || !d[0]) return;
        char tmp[MAX_PATH];
        size_t n = strlen(d);
        const char *sep = (d[n - 1] == '\\' || d[n - 1] == '/') ? "" : "\\";
        snprintf(tmp, sizeof(tmp), "%s%sRIVA.EXE", d, sep);
        add_cand(tmp);
    };

    const char *env_exe = getenv("RIVA_EXE");
    if (env_exe && env_exe[0]) {
        add_cand(env_exe);
    } else {
    if (game_dir && game_dir[0]) add_dir_exe(game_dir);
    if (exe_dir && exe_dir[0]) {
        add_dir_exe(exe_dir);
        char tmp[MAX_PATH];
        snprintf(tmp, sizeof(tmp), "%s..\\RIVA.EXE", exe_dir); add_cand(tmp);
        snprintf(tmp, sizeof(tmp), "%s..\\..\\RIVA.EXE", exe_dir); add_cand(tmp);
        snprintf(tmp, sizeof(tmp), "%s..\\Original\\RIVA.EXE", exe_dir); add_cand(tmp);
        snprintf(tmp, sizeof(tmp), "%s..\\..\\Original\\RIVA.EXE", exe_dir); add_cand(tmp);
        snprintf(tmp, sizeof(tmp), "%s..\\..\\..\\Original\\RIVA.EXE", exe_dir); add_cand(tmp);
        snprintf(tmp, sizeof(tmp), "%s..\\..\\..\\..\\Original\\RIVA.EXE", exe_dir); add_cand(tmp);
    }

    const char *sp_files[] = {
        "SPIELPFAD.txt", "..\\SPIELPFAD.txt", "..\\..\\SPIELPFAD.txt", "..\\..\\..\\SPIELPFAD.txt", NULL
    };
    for (int si = 0; sp_files[si]; ++si) {
        FILE *sf = fopen(sp_files[si], "r");
        if (sf) {
            char line[MAX_PATH];
            while (fgets(line, sizeof(line), sf)) {
                size_t l = strlen(line);
                while (l > 0 && (line[l - 1] == '\r' || line[l - 1] == '\n' || line[l - 1] == ' ')) line[--l] = '\0';
                if (line[0] == '\0' || line[0] == '#' || line[0] == ';') continue;
                const char *p = (strncmp(line, "gamedir=", 8) == 0) ? (line + 8) : line;
                add_dir_exe(p);
            }
            fclose(sf);
        }
    }
    if (exe_dir && exe_dir[0]) {
        const char *rel_sp[] = { "SPIELPFAD.txt", "..\\SPIELPFAD.txt", "..\\..\\SPIELPFAD.txt", "..\\..\\..\\SPIELPFAD.txt", NULL };
        for (int si = 0; rel_sp[si]; ++si) {
            char sp_path[MAX_PATH];
            snprintf(sp_path, sizeof(sp_path), "%s%s", exe_dir, rel_sp[si]);
            FILE *sf = fopen(sp_path, "r");
            if (sf) {
                char line[MAX_PATH];
                while (fgets(line, sizeof(line), sf)) {
                    size_t l = strlen(line);
                    while (l > 0 && (line[l - 1] == '\r' || line[l - 1] == '\n' || line[l - 1] == ' ')) line[--l] = '\0';
                    if (line[0] == '\0' || line[0] == '#' || line[0] == ';') continue;
                    const char *p = (strncmp(line, "gamedir=", 8) == 0) ? (line + 8) : line;
                    add_dir_exe(p);
                }
                fclose(sf);
            }
        }
    }

    add_cand("RIVA.EXE");
    add_cand("Original\\RIVA.EXE");
    add_cand("..\\Original\\RIVA.EXE");
    add_cand("..\\..\\Original\\RIVA.EXE");
    add_cand("..\\..\\..\\Original\\RIVA.EXE");
    add_cand("..\\..\\..\\..\\Original\\RIVA.EXE");
    add_cand("C:\\Program Files (x86)\\GOG Galaxy\\Games\\Realms of Arkania 3\\RIVA.EXE");
    add_cand("C:\\Program Files\\GOG Galaxy\\Games\\Realms of Arkania 3\\RIVA.EXE");
    add_cand("C:\\GOG Games\\Realms of Arkania 3\\RIVA.EXE");
    add_cand("D:\\GOG Games\\Realms of Arkania 3\\RIVA.EXE");
    }

    char bad_path[MAX_PATH] = "";
    char bad_md5[33] = "";
    long bad_size = -1;

    for (int ci = 0; ci < cand_count; ++ci) {
        FILE *fp = fopen(candidates[ci], "rb");
        if (!fp) continue;
        fseek(fp, 0, SEEK_END);
        long fsz = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        if (fsz != (long)SOLL_GROESSE) {
            if (!bad_path[0]) {
                strncpy(bad_path, candidates[ci], sizeof(bad_path) - 1);
                bad_size = fsz;
                strcpy(bad_md5, "(Groesse weicht ab)");
            }
            fclose(fp);
            continue;
        }
        uint8_t *exe_buf = (uint8_t *)malloc(SOLL_GROESSE);
        if (!exe_buf) { fclose(fp); continue; }
        size_t nread = fread(exe_buf, 1, SOLL_GROESSE, fp);
        fclose(fp);
        if (nread != SOLL_GROESSE) { free(exe_buf); continue; }
        char md5_hex[33];
        riva_md5_hex(exe_buf, SOLL_GROESSE, md5_hex);
        if (strcmp(md5_hex, SOLL_MD5) != 0) {
            if (!bad_path[0]) {
                strncpy(bad_path, candidates[ci], sizeof(bad_path) - 1);
                bad_size = fsz;
                strcpy(bad_md5, md5_hex);
            }
            free(exe_buf);
            continue;
        }
        memset(&riva_dgroup_base, 0, 0x58000u);
        memcpy(&riva_dgroup_base, exe_buf + FILE_DGROUP_OFF, FILE_DGROUP_LEN);
        memcpy(riva_code_data_1788d0, exe_buf + FILE_1788D0_OFF, FILE_1788D0_LEN);
        free(exe_buf);
        for (uint32_t ri = 0; ri < g_riva_dgroup_reloc_count; ++ri) {
            uint32_t off = g_riva_dgroup_relocs[ri].offset;
            uint32_t target = g_riva_dgroup_relocs[ri].target;
            if (off + 4u <= 0x58000u) {
                *(uint32_t *)((uint8_t *)&riva_dgroup_base + off) = target;
            }
        }
        char zmsg[256];
        int zlen = snprintf(zmsg, sizeof(zmsg),
                            "[dgroup] Loaded DGROUP (%u bytes) + code_data_1788d0 (%u bytes), applied %u relocations (RIVA.EXE MD5 %s)\n",
                            (unsigned)FILE_DGROUP_LEN, (unsigned)FILE_1788D0_LEN, (unsigned)g_riva_dgroup_reloc_count, md5_hex);
        if (zlen > 0) riva_append_log_file(g_exe_exit_log_path, zmsg, (DWORD)zlen);
        riva_trace("[dgroup] Loaded DGROUP (%u bytes) + code_data_1788d0 (%u bytes) and applied %u relocations from '%s' (MD5 %s)\n",
                   (unsigned)FILE_DGROUP_LEN, (unsigned)FILE_1788D0_LEN, (unsigned)g_riva_dgroup_reloc_count, candidates[ci], md5_hex);
        return;
    }

    char err_msg[1024];
    if (bad_path[0]) {
        snprintf(err_msg, sizeof(err_msg),
                 "FEHLER: Original-RIVA.EXE gefunden ('%s', %ld Bytes, MD5 %s), aber Pruefsumme stimmt nicht!\n"
                 "Erwartet wird die deutsche Originalversion V1.12 (2.477.899 Bytes, MD5 %s).\n",
                 bad_path, bad_size, bad_md5, SOLL_MD5);
    } else {
        snprintf(err_msg, sizeof(err_msg),
                 "FEHLER: Original-RIVA.EXE (Deutsche Version V1.12, 2.477.899 Bytes, MD5 %s) wurde nicht gefunden!\n"
                 "Bitte RIVA.EXE in den Spielordner legen oder den Spielordner in SPIELPFAD.txt eintragen.\n",
                 SOLL_MD5);
    }
    fprintf(stderr, "%s", err_msg);
    riva_append_log_file(g_exe_exit_log_path, err_msg, (DWORD)strlen(err_msg));
    const char *hl = getenv("RIVA_HEADLESS");
    if (!hl || hl[0] != '1') {
        MessageBoxA(NULL, err_msg, "DSA 3: Schatten ueber Riva - Original-EXE erforderlich", MB_OK | MB_ICONERROR);
    }
    ExitProcess(2);
}

int main(int argc, char **argv) {
    riva_init_dos_zero_page();
    /* Kein FreeConsole(): das loest die von WSL mitgegebene Konsole ab und laesst conhost.exe als Waise liegen.
       Die EXE ist mit -mwindows gelinkt. Sie beendet sich ueber ExitProcess, dann geht die Konsole mit. */

    /* Setze Windows-Timeraufloesung auf 1 ms (statt 15.6 ms Standard), damit 120-Hz-Timer und Frame-Pacing exakt laufen */
    HMODULE hWinMM = LoadLibraryA("winmm.dll");
    if (hWinMM) {
        typedef UINT (__stdcall *timeBeginPeriod_t)(UINT);
        timeBeginPeriod_t pTimeBeginPeriod = (timeBeginPeriod_t)GetProcAddress(hWinMM, "timeBeginPeriod");
        if (pTimeBeginPeriod) pTimeBeginPeriod(1);
    }

    /* Bestimme Pfade zu Port/build/{absturz.log,stubs.log,zeiten.log,abdeckung.tsv} relativ zur ausgefuehrten EXE */
    strcpy(g_exe_absturz_log_path, "absturz.log");
    strcpy(g_exe_stubs_log_path,   "stubs.log");
    strcpy(g_exe_zeiten_log_path,  "zeiten.log");
    strcpy(g_exe_exit_log_path,    "exit_trace.log");
    strcpy(g_exe_abdeckung_path,   "abdeckung.tsv");
    DWORD mod_len = GetModuleFileNameA(NULL, g_exe_dir_path, MAX_PATH - 32);
    if (mod_len > 0 && mod_len < MAX_PATH - 32) {
        char *last_sep = strrchr(g_exe_dir_path, '\\');
        if (!last_sep) last_sep = strrchr(g_exe_dir_path, '/');
        if (last_sep) {
            last_sep[1] = '\0';
            snprintf(g_exe_absturz_log_path, sizeof(g_exe_absturz_log_path), "%sabsturz.log", g_exe_dir_path);
            snprintf(g_exe_stubs_log_path,   sizeof(g_exe_stubs_log_path),   "%sstubs.log",   g_exe_dir_path);
            snprintf(g_exe_zeiten_log_path,  sizeof(g_exe_zeiten_log_path),  "%szeiten.log",  g_exe_dir_path);
            snprintf(g_exe_exit_log_path, sizeof(g_exe_exit_log_path), "%sexit_trace.log", g_exe_dir_path);
            snprintf(g_exe_abdeckung_path,   sizeof(g_exe_abdeckung_path),   "%sabdeckung.tsv", g_exe_dir_path);
        }
    }
    atexit(riva_atexit_log);
    AddVectoredExceptionHandler(1, riva_exception_filter);
    SetUnhandledExceptionFilter(riva_exception_filter);
    const char *gamedir = NULL;
    const char *record_arg = getenv("RIVA_RECORD");
    const char *replay_arg = getenv("RIVA_REPLAY");
    char record_full[MAX_PATH] = "";
    char replay_full[MAX_PATH] = "";
    char *game_argv[32];
    int game_argc = 0;
    size_t k;
    int i;

    game_argv[game_argc++] = argv[0];
    for (i = 1; i < argc && game_argc < 31; ++i) {
        if ((strcmp(argv[i], "--gamedir") == 0 || strcmp(argv[i], "-d") == 0) && i + 1 < argc) {
            gamedir = argv[++i];
        } else if (strncmp(argv[i], "--gamedir=", 10) == 0) {
            gamedir = argv[i] + 10;
        } else if ((strcmp(argv[i], "--savedir") == 0 || strcmp(argv[i], "--save-dir") == 0) && i + 1 < argc) {
            const char *sd = argv[++i];
            dsa_platform_set_save_dir(sd);
            { char env_buf[600]; snprintf(env_buf, sizeof(env_buf), "DSA_SAVE_DIR=%s", sd); _putenv(env_buf); }
        } else if (strncmp(argv[i], "--savedir=", 10) == 0) {
            const char *sd = argv[i] + 10;
            dsa_platform_set_save_dir(sd);
            { char env_buf[600]; snprintf(env_buf, sizeof(env_buf), "DSA_SAVE_DIR=%s", sd); _putenv(env_buf); }
        } else if (strcmp(argv[i], "--record") == 0 && i + 1 < argc) {
            record_arg = argv[++i];
        } else if (strncmp(argv[i], "--record=", 9) == 0) {
            record_arg = argv[i] + 9;
        } else if (strcmp(argv[i], "--replay") == 0 && i + 1 < argc) {
            replay_arg = argv[++i];
        } else if (strncmp(argv[i], "--replay=", 9) == 0) {
            replay_arg = argv[i] + 9;
        } else if (strcmp(argv[i], "--skip-intro") == 0 || strcmp(argv[i], "--kein-intro") == 0) {
            _putenv("RIVA_SKIP_INTRO=1");
        } else if (strcmp(argv[i], "--intro") == 0) {
            _putenv("RIVA_SKIP_INTRO=0");
        } else if (strcmp(argv[i], "--vollbild") == 0 || strcmp(argv[i], "--fullscreen") == 0) {
            _putenv("DSA_FULLSCREEN=1");
            _putenv("DSA_FENSTER=vollbild");
        } else if (strcmp(argv[i], "--fenstermodus") == 0 || strcmp(argv[i], "--windowed") == 0) {
            _putenv("DSA_FULLSCREEN=0");
        } else if (strncmp(argv[i], "--fenster=", 10) == 0) {
            const char *val = argv[i] + 10;
            char env_buf[64];
            snprintf(env_buf, sizeof(env_buf), "DSA_FENSTER=%s", val);
            _putenv(env_buf);
            if (_stricmp(val, "vollbild") == 0 || _stricmp(val, "fullscreen") == 0) {
                _putenv("DSA_FULLSCREEN=1");
            } else {
                _putenv("DSA_FULLSCREEN=0");
            }
        } else if (strcmp(argv[i], "--fenster") == 0 && i + 1 < argc) {
            const char *val = argv[++i];
            char env_buf[64];
            snprintf(env_buf, sizeof(env_buf), "DSA_FENSTER=%s", val);
            _putenv(env_buf);
            if (_stricmp(val, "vollbild") == 0 || _stricmp(val, "fullscreen") == 0) {
                _putenv("DSA_FULLSCREEN=1");
            } else {
                _putenv("DSA_FULLSCREEN=0");
            }
        } else if (strncmp(argv[i], "--skalierung=", 13) == 0) {
            char env_buf[64];
            snprintf(env_buf, sizeof(env_buf), "DSA_SKALIERUNG=%s", argv[i] + 13);
            _putenv(env_buf);
        } else if (strcmp(argv[i], "--skalierung") == 0 && i + 1 < argc) {
            char env_buf[64];
            snprintf(env_buf, sizeof(env_buf), "DSA_SKALIERUNG=%s", argv[++i]);
            _putenv(env_buf);
        } else if (strcmp(argv[i], "--headless") == 0) {
            _putenv("RIVA_HEADLESS=1");
        } else if (strcmp(argv[i], "--abdeckung") == 0) {
            _putenv("RIVA_ABDECKUNG=1");
        } else if (strcmp(argv[i], "--audio-log") == 0) {
            _putenv("RIVA_AUDIO_LOG=1");
        } else if (!gamedir && (strchr(argv[i], '\\') != NULL || (argv[i][0] != '/' && strchr(argv[i], '/') != NULL))) {
            gamedir = argv[i];
        } else {
            game_argv[game_argc++] = argv[i];
        }
    }
    game_argv[game_argc] = NULL;

    if (replay_arg && replay_arg[0]) {
        if (!getenv("RIVA_HEADLESS"))  _putenv("RIVA_HEADLESS=1");
        if (!getenv("RIVA_ABDECKUNG")) _putenv("RIVA_ABDECKUNG=1");
        if (!getenv("RIVA_AUDIO_LOG")) _putenv("RIVA_AUDIO_LOG=1");
    }

    const char *abd_env = getenv("RIVA_ABDECKUNG");
    if (abd_env && abd_env[0] == '1') {
        g_abdeckung_enabled = 1;
        const char *ahdr = "fkt\terster_aufruf_ms\n";
        /* Kopf nur anlegen, wenn die Datei noch fehlt. Sonst wuerde jeder Lauf die Messung ersetzen. */
        if (GetFileAttributesA(g_exe_abdeckung_path) == INVALID_FILE_ATTRIBUTES)
            riva_write_log_file(g_exe_abdeckung_path, ahdr, (DWORD)strlen(ahdr));
        for (size_t xi = 0; xi < sizeof(g_watcom_xi_ctors) / sizeof(g_watcom_xi_ctors[0]); ++xi) {
            riva_abdeckung_record_addr((uintptr_t)g_watcom_xi_ctors[xi]);
        }
        riva_abdeckung_record_addr((uintptr_t)&f_1439e0);
    }

    if (record_arg && record_arg[0]) {
        if (!_fullpath(record_full, record_arg, sizeof(record_full))) {
            strncpy(record_full, record_arg, sizeof(record_full) - 1);
        }
        dsa_platform_set_record_file(record_full);
    }
    if (replay_arg && replay_arg[0]) {
        if (!_fullpath(replay_full, replay_arg, sizeof(replay_full))) {
            strncpy(replay_full, replay_arg, sizeof(replay_full) - 1);
        }
        dsa_platform_set_replay_file(replay_full);
    }

    /* Spielverzeichnis aufloesen und DGROUP zur Laufzeit aus der RIVA.EXE des Nutzers laden */
    dsa_platform_set_game_dir(gamedir);
    riva_load_dgroup_from_user_exe(dsa_platform_get_game_dir(), g_exe_dir_path);

    /* Initialisiere Plattformschicht (SDL2-Fenster, 8-Bit-Framebuffer, Spielverzeichnis) */
    dsa_platform_init("DSA 3: Schatten ueber Riva (Windows Port)", 320, 200, gamedir);

    /* Wechsle Arbeitsverzeichnis in den Spielordner, falls vorhanden */
    if (dsa_platform_get_game_dir()[0]) {
        _chdir(dsa_platform_get_game_dir());
    }

    /* Initialisiere globale Zeiger in DGROUP vor dem Konstruktorlauf */
    fill_vesa_controller_info(g_fallback_vbe_info);
    fill_vesa_mode_info(g_fallback_mode_info, 0x13);
    d_1c1104 = g_fallback_vbe_info;
    d_1c1108 = g_fallback_mode_info;
    d_1a34e0 = (int)(uintptr_t)dsa_platform_get_vram();
    if (!d_1a96a4[0]) strcpy(d_1a96a4, "C:\\RIVA");

    /* 1. Alle 80 statischen C++-Modulkonstruktoren aus Watcoms XI-Tabelle ausfuehren */
    riva_trace("[main] game_dir='%s', starting 80 XI constructors...\n", dsa_platform_get_game_dir());
    for (k = 0; k < sizeof(g_watcom_xi_ctors) / sizeof(g_watcom_xi_ctors[0]); ++k) {
        riva_trace("[xi] #%u @ %p\n", (unsigned)k, (void *)g_watcom_xi_ctors[k]);
        ((void (*)(int, int, int, int))g_watcom_xi_ctors[k])(0, 0, 0, 0);
    }
    riva_trace("[main] all 80 XI constructors done! Calling f_1439e0(argc=%d)...\n", game_argc);

    /* 2. Spiel-Hauptfunktion starten (zmain::f_1439e0) */
    f_1439e0((short)game_argc, game_argv);
    riva_append_log_file(g_exe_exit_log_path, "[main] f_1439e0 returned\n", 25);
    riva_trace("[main] f_1439e0 returned cleanly.\n");

    dsa_platform_shutdown();
    return 0;
}
