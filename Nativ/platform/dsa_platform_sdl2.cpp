/*
 * dsa_platform_sdl2.cpp - SDL2-Plattformschicht fuer die Nordlandtrilogie
 *   (DSA 1 Schicksalsklinge, DSA 2 Sternenschweif, DSA 3 Schatten ueber Riva)
 */

#include "dsa_platform.h"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <direct.h>
#include <io.h>
#define MKDIR(p) _mkdir(p)
#else
#include <sys/stat.h>
#include <unistd.h>
#define MKDIR(p) mkdir(p, 0755)
#endif

/* =========================================================================
 * 1. 8-Bit-Framebuffer & 256-Farben-VGA-Palette
 * ========================================================================= */

/* 64 KB Sicherheits-Padding vor und nach dem 640x480-VRAM-Puffer */
static unsigned char g_vram_padded_storage[65536 + DSA_VRAM_SIZE + 65536];
#define g_vram (&g_vram_padded_storage[65536])

static uint32_t      g_argb_buffer[DSA_VRAM_SIZE];
static unsigned char g_pal_rgb6[256][3];
static uint32_t      g_pal_argb32[256];

static SDL_Window   *g_window   = NULL;
static SDL_Renderer *g_renderer = NULL;
static SDL_Texture  *g_texture  = NULL;

static int      g_initialized     = 0;
static int      g_dos_mode        = 0x13;
static int      g_width           = 320;
static int      g_height          = 200;
static uint32_t g_last_present_ms = 0;

/* Anzeige- und Skalierungsoptionen (DSA_FULLSCREEN, DSA_FENSTER, DSA_SKALIERUNG) */
static int       g_fullscreen   = 0;
static int       g_window_scale = 4; /* 2..5 -> 640x480 .. 1600x1200 (4:3) */
static int       g_scaling_mode = 0; /* 0 = fuellend (Sharp-Bilinear 4:3), 1 = ganzzahlig (4:3) */
static uint32_t *g_canvas_buf   = NULL;
static int       g_canvas_cap   = 0;
static int       g_canvas_tex_w = 0;
static int       g_canvas_tex_h = 0;

static void dsa_display_init_from_env(void) {
    const char *fs_env  = getenv("DSA_FULLSCREEN");
    const char *win_env = getenv("DSA_FENSTER");
    const char *sk_env  = getenv("DSA_SKALIERUNG");
    const char *res_env = getenv("DSA_TEST_FS_RES");

    if (fs_env && (fs_env[0] == '1' || _stricmp(fs_env, "true") == 0 || _stricmp(fs_env, "vollbild") == 0)) {
        g_fullscreen = 1;
    }
    if (win_env && win_env[0]) {
        if (_stricmp(win_env, "vollbild") == 0 || _stricmp(win_env, "fullscreen") == 0) {
            g_fullscreen = 1;
        } else {
            int s = atoi(win_env);
            if (s >= 2 && s <= 5) {
                g_window_scale = s;
                if (!fs_env || fs_env[0] != '1') g_fullscreen = 0;
            }
        }
    }
    if (sk_env && sk_env[0]) {
        if (_stricmp(sk_env, "ganzzahlig") == 0 || _stricmp(sk_env, "integer") == 0 || _stricmp(sk_env, "pixel") == 0) {
            g_scaling_mode = 1;
        } else {
            g_scaling_mode = 0;
        }
    }
    if (res_env && res_env[0]) {
        int rw = 0, rh = 0;
        if (sscanf(res_env, "%dx%d", &rw, &rh) == 2 && rw >= 320 && rh >= 200) {
            SDL_SetFullscreenOverrideRes(rw, rh);
        }
    }
}

void dsa_platform_toggle_fullscreen(void) {
    if (!g_window) return;
    g_fullscreen = !g_fullscreen;
    SDL_SetWindowFullscreen(g_window, g_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

/* =========================================================================
 * 2. Maus- und Tastaturzustand
 * ========================================================================= */

static int           g_mouse_x            = 160;
static int           g_mouse_y            = 100;
static int           g_mouse_min_x        = 0;
static int           g_mouse_max_x        = 319;
static int           g_mouse_min_y        = 0;
static int           g_mouse_max_y        = 199;
static int           g_mouse_buttons      = 0;
static int           g_mouse_latched_down = 0;
static int           g_mouse_pending_up   = 0;

#define KEY_QUEUE_CAP 128
static unsigned short g_key_queue[KEY_QUEUE_CAP];
static int            g_key_head = 0;
static int            g_key_tail = 0;
static unsigned short g_shift_status = 0;
static unsigned char  g_scancode_down[128];

/* USB-HID SDL_Scancode -> IBM PC XT/AT Set-1 Scancode (fuer externe SDL2.dll) */
static unsigned char sdl_scancode_to_dos(int sdl_sc, int sym, int mod, unsigned char *out_ascii) {
    static const unsigned char hid_to_xt[128] = {
        0x00, 0x00, 0x00, 0x00, 0x1E, 0x30, 0x2E, 0x20, /* 0..7: A, B, C, D */
        0x12, 0x21, 0x22, 0x23, 0x17, 0x24, 0x25, 0x26, /* 8..15: E..L */
        0x32, 0x31, 0x18, 0x19, 0x10, 0x13, 0x1F, 0x14, /* 16..23: M..T */
        0x16, 0x2F, 0x11, 0x2D, 0x15, 0x2C, 0x02, 0x03, /* 24..31: U..Z, 1, 2 */
        0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, /* 32..39: 3..9, 0 */
        0x1C, 0x01, 0x0E, 0x0F, 0x39, 0x0C, 0x0D, 0x1A, /* 40..47: Enter, Esc, BS, Tab, Space, -, =, [ */
        0x1B, 0x2B, 0x2B, 0x27, 0x28, 0x29, 0x33, 0x34, /* 48..55: ], \, #, ;, ', `, ,, . */
        0x35, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, /* 56..63: /, Caps, F1..F6 */
        0x41, 0x42, 0x43, 0x44, 0x57, 0x58, 0x37, 0x46, /* 64..71: F7..F12, PrtSc, ScrLk */
        0x00, 0x52, 0x47, 0x49, 0x53, 0x4F, 0x51, 0x4D, /* 72..79: Pause, Ins, Home, PgUp, Del, End, PgDn, Right */
        0x4B, 0x50, 0x48, 0x45, 0x35, 0x37, 0x4A, 0x4E, /* 80..87: Left, Down, Up, NumLk, KP/, KP*, KP-, KP+ */
        0x1C, 0x4F, 0x50, 0x51, 0x4B, 0x4C, 0x4D, 0x47, /* 88..95: KPEnter, KP1..KP7 */
        0x48, 0x49, 0x52, 0x53                          /* 96..99: KP8, KP9, KP0, KP. */
    };
    unsigned char xt = 0;
    unsigned char asc = 0;
    if (sdl_sc >= 0 && sdl_sc < 100) {
        xt = hid_to_xt[sdl_sc];
    }
    if (sym >= 32 && sym <= 126) {
        asc = (unsigned char)sym;
        if ((mod & KMOD_SHIFT) && asc >= 'a' && asc <= 'z') {
            asc = (unsigned char)(asc - 'a' + 'A');
        }
    } else if (sym == 13 || sym == 27 || sym == 8 || sym == 9) {
        asc = (unsigned char)sym;
    } else {
        /* Deutsche Umlaute & Eszett (Latin-1 / SDL_Keycode -> DOS CP437 + XT-Scancode) */
        switch (sym & 0xFF) {
        case 0xE4: asc = (mod & KMOD_SHIFT) ? 0x8E : 0x84; xt = 0x28; break; /* ä / Ä */
        case 0xF6: asc = (mod & KMOD_SHIFT) ? 0x99 : 0x94; xt = 0x27; break; /* ö / Ö */
        case 0xFC: asc = (mod & KMOD_SHIFT) ? 0x9A : 0x81; xt = 0x1A; break; /* ü / Ü */
        case 0xC4: asc = 0x8E; xt = 0x28; break; /* Ä */
        case 0xD6: asc = 0x99; xt = 0x27; break; /* Ö */
        case 0xDC: asc = 0x9A; xt = 0x1A; break; /* Ü */
        case 0xDF: asc = 0xE1; xt = 0x0C; break; /* ß */
        default: break;
        }
    }
    if (out_ascii) *out_ascii = asc;
    return xt;
}

static void keyq_push(unsigned short bios_key) {
    int next = (g_key_tail + 1) % KEY_QUEUE_CAP;
    if (next != g_key_head) {
        g_key_queue[g_key_tail] = bios_key;
        g_key_tail = next;
    }
}

/* =========================================================================
 * 2b. Werkzeug W4: Eingabe-Aufzeichnung (--record) & Wiedergabe (--replay)
 * ========================================================================= */

enum ReplayActionType {
    RPL_MOVE = 1,
    RPL_MDOWN,
    RPL_MUP,
    RPL_DCLICK,
    RPL_KDOWN,
    RPL_KUP,
    RPL_SHOT,
    RPL_WALK3D,
    RPL_TRIGGER,
    RPL_LOC,
    RPL_MAP,
    RPL_FIGHT,
    RPL_SPEECH,
    RPL_ENDGAME,
    RPL_QUIT,
    RPL_TEST_TIME,
    RPL_STATE,
    RPL_TEST_HP,
    RPL_TEST_WIN_FIGHT,
    RPL_WALKTO
};

struct ReplayEvent {
    uint32_t         t_ms;
    ReplayActionType type;
    int              a, b, c;
    char             str[260];
};

#define MAX_REPLAY_EVENTS 8192
static ReplayEvent g_replay_events[MAX_REPLAY_EVENTS];
static int         g_replay_count      = 0;
static int         g_replay_idx        = 0;
static int         g_replay_active     = 0;
static uint32_t    g_replay_walk_end   = 0;
static uint32_t    g_walkto_deadline = 0;
static uint32_t    g_walkto_progress_ms = 0;
static int         g_walkto_x = 0, g_walkto_z = 0;
static double      g_walkto_best_distance = 0;
static int         g_replay_failure = 0;
static uint32_t    g_replay_last_ev_ms = 0;
static char        g_replay_dir[512]   = "";
static FILE       *g_record_fp         = NULL;

static int         g_pending_loc       = -999;
static int         g_pending_map       = -999;
static int         g_pending_cell      = 0;
static int         g_pending_fight     = -1;
static int         g_pending_speech    = -1;
static int         g_pending_endgame   = 0;
static int         g_pending_test_time = -1;
static int         g_pending_test_hp_hero = -1;
static int         g_pending_test_hp = 0;
static int         g_in_delay_ms       = 0;

extern "C" {
extern short          d_1bd6c4;
extern signed char    d_1bdb80;
extern signed char    d_1bdb84;
extern int            d_1c0004;
extern int            d_1c1078;
extern int            d_1c2a80;
extern short          d_1c21a4;
extern unsigned int   d_1bf4c0;
extern int            d_1bf4c8;
extern unsigned short d_1bf4f0;
extern short          d_1bf4f2;
extern short          d_1bf4f8;
extern short          d_1bf4fa;
extern unsigned int   d_1c3914;
extern unsigned char  d_1c2c44[];
unsigned int f_0de7e0(int p1);
int f_038c80(int p1);
int f_0391b0(int p1, int hero);
int f_0de810(int p1, short p2);
int f_0dd7f0(int p1, short p2, short p3);
int f_08c920(unsigned short a, int b);
int f_10b890(int p1);
}

extern "C" void dsa_platform_run_pending_3d_actions(void) {
    if (g_pending_test_hp_hero >= 0 && d_1c0004) {
        /* Ausschliesslich Replay-Testaufbau, z.B. verwundeter Heilerpatient. */
        int first = f_038c80(d_1c0004), hero = first;
        for (int i = 0; hero && i < g_pending_test_hp_hero; ++i) {
            hero = f_0391b0(d_1c0004, hero);
            if (hero == first) { hero = 0; break; }
        }
        if (hero) {
            short maximum = 0, hp = (short)g_pending_test_hp;
            memcpy(&maximum, (void *)(hero + 0x70), 2);
            if (hp > maximum) hp = maximum;
            memcpy((void *)(hero + 0x72), &hp, 2);
        }
        g_pending_test_hp_hero = -1;
    }
    if (g_pending_test_time >= 0 && d_1c0004) {
        /* Nur Replay-Testaufbau: Tageszeit im geladenen Teststand setzen.
         * time.cpp speichert die 90 Ticks/Minute ab Objekt-Offset 1. */
        int ticks = g_pending_test_time;
        g_pending_test_time = -1;
        memcpy(d_1c2c44 + 1, &ticks, sizeof(ticks));
    }
    if (g_pending_loc != -999) {
        int loc = g_pending_loc;
        g_pending_loc = -999;
        if (d_1c0004) {
            f_0de810(d_1c0004, (short)loc);
            d_1c2a80 = 0;
        }
    }
    if (g_pending_map != -999) {
        int mp = g_pending_map;
        int cl = g_pending_cell;
        g_pending_map = -999;
        if (d_1c0004) {
            f_0dd7f0(d_1c0004, (short)mp, (short)cl);
        }
    }
    if (g_pending_fight >= 0) {
        int fid = g_pending_fight;
        g_pending_fight = -1;
        f_08c920((unsigned short)fid, 0);
    }
    if (g_pending_speech >= 0) {
        int sid = g_pending_speech;
        g_pending_speech = -1;
        f_10b890(sid);
    }
    if (g_pending_endgame) {
        g_pending_endgame = 0;
        if (d_1bdb84 == 1 && d_1c0004) {
            d_1c1078 = f_038c80(d_1c0004);
        } else {
            d_1c21a4 = 1;
        }
    }
}

static void char_to_dos_key(unsigned char ch, unsigned char *out_sc, unsigned char *out_asc, unsigned short *out_mod) {
    static const unsigned char ascii_to_xt[128] = {
        0,0,0,0,0,0,0,0, 0x0E,0x0F,0x1C,0,0,0x1C,0,0,
        0,0,0,0,0,0,0,0, 0,0,0,0x01,0,0,0,0,
        0x39,0x02,0x03,0x2B,0x05,0x06,0x07,0x2B, 0x09,0x0A,0x1B,0x1B,0x33,0x35,0x34,0x08,
        0x0B,0x02,0x03,0x04,0x05,0x06,0x07,0x08, 0x09,0x0A,0x34,0x33,0x56,0x0B,0x56,0x0C,
        0x10,0x1E,0x30,0x2E,0x20,0x12,0x21,0x22, 0x23,0x17,0x24,0x25,0x26,0x32,0x31,0x18,
        0x19,0x10,0x13,0x1F,0x14,0x16,0x2F,0x11, 0x2D,0x15,0x2C,0x09,0x0C,0x0A,0x29,0x35,
        0x0D,0x1E,0x30,0x2E,0x20,0x12,0x21,0x22, 0x23,0x17,0x24,0x25,0x26,0x32,0x31,0x18,
        0x19,0x10,0x13,0x1F,0x14,0x16,0x2F,0x11, 0x2D,0x15,0x2C,0x08,0x56,0x0B,0x1B,0x0E
    };
    *out_mod = 0;
    if (ch < 128) {
        *out_asc = ch;
        *out_sc  = ascii_to_xt[ch];
        /* Kein Shift-Bit: f_0e4380 verwirft die Taste, solange d_1bd760 gesetzt ist. */
        return;
    }
    switch (ch) {
    case 0x84: case 0xE4: *out_asc = 0x84; *out_sc = 0x28; break; /* ä */
    case 0x94: case 0xF6: *out_asc = 0x94; *out_sc = 0x27; break; /* ö */
    case 0x81: case 0xFC: *out_asc = 0x81; *out_sc = 0x1A; break; /* ü */
    /* TEXT liefert bereits das fertige Zeichen, keine gehaltene Umschalttaste.
       Wie bei ASCII-Grossbuchstaben den Popup-Verschiebemodus nicht ausloesen. */
    case 0x8E: case 0xC4: *out_asc = 0x8E; *out_sc = 0x28; break; /* Ä */
    case 0x99: case 0xD6: *out_asc = 0x99; *out_sc = 0x27; break; /* Ö */
    case 0x9A: case 0xDC: *out_asc = 0x9A; *out_sc = 0x1A; break; /* Ü */
    case 0xE1: case 0xDF: *out_asc = 0xE1; *out_sc = 0x0C; break; /* ß */
    default: *out_asc = '_'; *out_sc = 0x35; break;
    }
}

static void add_replay_ev(uint32_t t_ms, ReplayActionType type, int a, int b, int c, const char *str) {
    if (g_replay_count >= MAX_REPLAY_EVENTS) return;
    ReplayEvent *ev = &g_replay_events[g_replay_count++];
    ev->t_ms = t_ms;
    ev->type = type;
    ev->a    = a;
    ev->b    = b;
    ev->c    = c;
    if (str) {
        strncpy(ev->str, str, sizeof(ev->str) - 1);
        ev->str[sizeof(ev->str) - 1] = '\0';
    } else {
        ev->str[0] = '\0';
    }
}

void dsa_platform_set_record_file(const char *path) {
    if (g_record_fp) { fclose(g_record_fp); g_record_fp = NULL; }
    if (path && path[0]) {
        g_record_fp = fopen(path, "w");
        if (g_record_fp) {
            fprintf(g_record_fp, "# DSA 3: Schatten ueber Riva - Eingabe-Aufzeichnung (W4)\n");
            fflush(g_record_fp);
        }
    }
}

static void parse_replay_command(uint32_t *cur_ms, char *p) {
    char cmd[64];
    int n = 0;
    while (*p == ' ' || *p == '\t') ++p;
    if (*p == '\0' || *p == '#') return;
    if (sscanf(p, "%63s%n", cmd, &n) != 1) return;
    p += n;
    while (*p == ' ' || *p == '\t') ++p;

    if (_stricmp(cmd, "AT") == 0) {
        unsigned int t = 0;
        int n2 = 0;
        if (sscanf(p, "%u%n", &t, &n2) == 1) {
            *cur_ms = (uint32_t)t;
            parse_replay_command(cur_ms, p + n2);
        }
    } else if (_stricmp(cmd, "WAIT") == 0) {
        unsigned int dt = 0;
        if (sscanf(p, "%u", &dt) == 1) {
            *cur_ms += (uint32_t)dt;
        }
    } else if (_stricmp(cmd, "MOVE") == 0) {
        int x = 0, y = 0;
        if (sscanf(p, "%d %d", &x, &y) == 2) {
            add_replay_ev(*cur_ms, RPL_MOVE, x, y, 0, NULL);
        }
    } else if (_stricmp(cmd, "MDOWN") == 0) {
        int x = 0, y = 0, bit = 1;
        if (sscanf(p, "%d %d %d", &x, &y, &bit) >= 2) {
            add_replay_ev(*cur_ms, RPL_MDOWN, x, y, bit, NULL);
        }
    } else if (_stricmp(cmd, "MUP") == 0) {
        int x = 0, y = 0, bit = 1;
        if (sscanf(p, "%d %d %d", &x, &y, &bit) >= 2) {
            add_replay_ev(*cur_ms, RPL_MUP, x, y, bit, NULL);
        }
    } else if (_stricmp(cmd, "CLICK") == 0) {
        int x = 0, y = 0, a3 = 1, a4 = 120;
        int n_args = sscanf(p, "%d %d %d %d", &x, &y, &a3, &a4);
        if (n_args >= 2) {
            int bit = 1, hold = 120;
            if (n_args == 3) {
                if (a3 == 1 || a3 == 2 || a3 == 4) { bit = a3; hold = 120; }
                else { bit = 1; hold = a3; }
            } else if (n_args >= 4) {
                bit = a3;
                hold = a4;
            }
            {
                uint32_t total_ms = (uint32_t)(hold > 0 ? hold : 120);
                uint32_t down_ms  = (total_ms > 80) ? 40 : (total_ms / 2);
                if (down_ms < 20) down_ms = 20;
                uint32_t up_ms    = (total_ms > down_ms) ? (total_ms - down_ms) : 20;
                /* Menues bestimmen die Zeile beim Bewegen, bevor der Klick
                   die aktuelle Auswahl bestaetigt. Einen Frame dafuer lassen. */
                add_replay_ev(*cur_ms, RPL_MOVE, x, y, 0, NULL);
                *cur_ms += 60;
                add_replay_ev(*cur_ms, RPL_MDOWN, x, y, bit, NULL);
                *cur_ms += down_ms;
                add_replay_ev(*cur_ms, RPL_MUP, x, y, bit, NULL);
                *cur_ms += up_ms;
            }
        }
    } else if (_stricmp(cmd, "RCLICK") == 0) {
        int x = 0, y = 0, hold = 120;
        if (sscanf(p, "%d %d %d", &x, &y, &hold) >= 2) {
            uint32_t total_ms = (uint32_t)(hold > 0 ? hold : 120);
            uint32_t down_ms  = (total_ms > 80) ? 40 : (total_ms / 2);
            if (down_ms < 20) down_ms = 20;
            uint32_t up_ms    = (total_ms > down_ms) ? (total_ms - down_ms) : 20;
            add_replay_ev(*cur_ms, RPL_MOVE, x, y, 0, NULL);
            *cur_ms += 60;
            add_replay_ev(*cur_ms, RPL_MDOWN, x, y, 2, NULL);
            *cur_ms += down_ms;
            add_replay_ev(*cur_ms, RPL_MUP, x, y, 2, NULL);
            *cur_ms += up_ms;
        }
    } else if (_stricmp(cmd, "DCLICK") == 0) {
        int x = 0, y = 0, hold = 80;
        if (sscanf(p, "%d %d %d", &x, &y, &hold) >= 2) {
            uint32_t total_ms = (uint32_t)(hold > 0 ? hold : 80);
            uint32_t down_ms  = (total_ms > 80) ? 40 : (total_ms / 2);
            if (down_ms < 20) down_ms = 20;
            uint32_t up_ms    = (total_ms > down_ms) ? (total_ms - down_ms) : 20;
            add_replay_ev(*cur_ms, RPL_MOVE, x, y, 0, NULL);
            *cur_ms += 60;
            add_replay_ev(*cur_ms, RPL_DCLICK, x, y, 1, NULL);
            *cur_ms += down_ms;
            add_replay_ev(*cur_ms, RPL_MUP, x, y, 1, NULL);
            *cur_ms += up_ms;
        }
    } else if (_stricmp(cmd, "TRIGGER") == 0) {
        int id = 0;
        if (sscanf(p, "%i", &id) == 1) {
            add_replay_ev(*cur_ms, RPL_TRIGGER, id, 0, 0, NULL);
        }
    } else if (_stricmp(cmd, "LOC") == 0) {
        int id = 0;
        if (sscanf(p, "%i", &id) == 1) {
            add_replay_ev(*cur_ms, RPL_LOC, id, 0, 0, NULL);
        }
    } else if (_stricmp(cmd, "MAP") == 0) {
        int mp = 0, cl = 0;
        if (sscanf(p, "%i %i", &mp, &cl) == 2) {
            add_replay_ev(*cur_ms, RPL_MAP, mp, cl, 0, NULL);
        }
    } else if (_stricmp(cmd, "FIGHT") == 0) {
        int fid = 0;
        if (sscanf(p, "%i", &fid) == 1) {
            add_replay_ev(*cur_ms, RPL_FIGHT, fid, 0, 0, NULL);
        }
    } else if (_stricmp(cmd, "SPEECH") == 0) {
        int sid = 0;
        if (sscanf(p, "%i", &sid) == 1) {
            add_replay_ev(*cur_ms, RPL_SPEECH, sid, 0, 0, NULL);
        }
    } else if (_stricmp(cmd, "ENDGAME") == 0) {
        add_replay_ev(*cur_ms, RPL_ENDGAME, 1, 0, 0, NULL);
    } else if (_stricmp(cmd, "KDOWN") == 0) {
        unsigned int sc = 0, asc = 0, mod = 0;
        if (sscanf(p, "%i %i %i", &sc, &asc, &mod) >= 1) {
            add_replay_ev(*cur_ms, RPL_KDOWN, (int)sc, (int)asc, (int)mod, NULL);
        }
    } else if (_stricmp(cmd, "KUP") == 0) {
        unsigned int sc = 0, asc = 0, mod = 0;
        if (sscanf(p, "%i %i %i", &sc, &asc, &mod) >= 1) {
            add_replay_ev(*cur_ms, RPL_KUP, (int)sc, (int)asc, (int)mod, NULL);
        }
    } else if (_stricmp(cmd, "KEY") == 0) {
        unsigned int sc = 0, asc = 0;
        int hold = 80;
        if (isdigit((unsigned char)p[0]) && sscanf(p, "%i %i %d", &sc, &asc, &hold) >= 2) {
            uint32_t total_ms = (uint32_t)(hold > 0 ? hold : 80);
            uint32_t down_ms  = (total_ms > 80) ? 40 : (total_ms / 2);
            if (down_ms < 20) down_ms = 20;
            uint32_t up_ms    = (total_ms > down_ms) ? (total_ms - down_ms) : 20;
            add_replay_ev(*cur_ms, RPL_KDOWN, (int)sc, (int)asc, 0, NULL);
            *cur_ms += down_ms;
            add_replay_ev(*cur_ms, RPL_KUP, (int)sc, 0, 0, NULL);
            *cur_ms += up_ms;
        } else {
            char kname[64] = "";
            if (sscanf(p, "%63s %d", kname, &hold) >= 1) {
                unsigned short mod = 0;
                if (_stricmp(kname, "Enter") == 0 || _stricmp(kname, "Return") == 0) { sc = 0x1C; asc = 0x0D; }
                else if (_stricmp(kname, "Escape") == 0 || _stricmp(kname, "Esc") == 0) { sc = 0x01; asc = 0x1B; }
                else if (_stricmp(kname, "Space") == 0) { sc = 0x39; asc = 0x20; }
                else if (_stricmp(kname, "Backspace") == 0 || _stricmp(kname, "BS") == 0) { sc = 0x0E; asc = 0x08; }
                else if (_stricmp(kname, "Tab") == 0) { sc = 0x0F; asc = 0x09; }
                else if (_stricmp(kname, "Up") == 0) { sc = 0x48; asc = 0x00; }
                else if (_stricmp(kname, "Down") == 0) { sc = 0x50; asc = 0x00; }
                else if (_stricmp(kname, "Left") == 0) { sc = 0x4B; asc = 0x00; }
                else if (_stricmp(kname, "Right") == 0) { sc = 0x4D; asc = 0x00; }
                else if (_stricmp(kname, "Insert") == 0 || _stricmp(kname, "Ins") == 0) { sc = 0x52; asc = 0x00; }
                else if (_stricmp(kname, "Delete") == 0 || _stricmp(kname, "Del") == 0) { sc = 0x53; asc = 0x00; }
                else if (_stricmp(kname, "Home") == 0) { sc = 0x47; asc = 0x00; }
                else if (_stricmp(kname, "End") == 0) { sc = 0x4F; asc = 0x00; }
                else if (_stricmp(kname, "PageUp") == 0 || _stricmp(kname, "PgUp") == 0) { sc = 0x49; asc = 0x00; }
                else if (_stricmp(kname, "PageDown") == 0 || _stricmp(kname, "PgDn") == 0) { sc = 0x51; asc = 0x00; }
                else if ((kname[0] == 'F' || kname[0] == 'f') && isdigit((unsigned char)kname[1])) {
                    int fn = atoi(kname + 1);
                    if (fn >= 1 && fn <= 10) { sc = (unsigned int)(0x3B + fn - 1); asc = 0x00; }
                } else if (kname[0] && !kname[1]) {
                    unsigned char c_sc = 0, c_asc = 0;
                    char_to_dos_key((unsigned char)kname[0], &c_sc, &c_asc, &mod);
                    sc = c_sc; asc = c_asc;
                }
                if (sc != 0 || asc != 0) {
                    uint32_t total_ms = (uint32_t)(hold > 0 ? hold : 80);
                    uint32_t down_ms  = (total_ms > 80) ? 40 : (total_ms / 2);
                    if (down_ms < 20) down_ms = 20;
                    uint32_t up_ms    = (total_ms > down_ms) ? (total_ms - down_ms) : 20;
                    add_replay_ev(*cur_ms, RPL_KDOWN, (int)sc, (int)asc, (int)mod, NULL);
                    *cur_ms += down_ms;
                    add_replay_ev(*cur_ms, RPL_KUP, (int)sc, 0, 0, NULL);
                    *cur_ms += up_ms;
                }
            }
        }
    } else if (_stricmp(cmd, "TEXT") == 0) {
        const unsigned char *s = (const unsigned char *)p;
        while (*s && *s != '\r' && *s != '\n') {
            unsigned char ch = *s++;
            if (ch == 0xC3 && *s) {
                /* UTF-8 2-Byte-Sequenz fuer deutsche Umlaute/Eszett */
                unsigned char c2 = *s++;
                if (c2 == 0xA4)      ch = 0x84; /* ä */
                else if (c2 == 0xB6) ch = 0x94; /* ö */
                else if (c2 == 0xBC) ch = 0x81; /* ü */
                else if (c2 == 0x84) ch = 0x8E; /* Ä */
                else if (c2 == 0x96) ch = 0x99; /* Ö */
                else if (c2 == 0x9C) ch = 0x9A; /* Ü */
                else if (c2 == 0x9F) ch = 0xE1; /* ß */
            }
            unsigned char sc = 0, asc = 0;
            unsigned short mod = 0;
            char_to_dos_key(ch, &sc, &asc, &mod);
            add_replay_ev(*cur_ms, RPL_KDOWN, (int)sc, (int)asc, (int)mod, NULL);
            *cur_ms += 80;
            add_replay_ev(*cur_ms, RPL_KUP, (int)sc, 0, 0, NULL);
            *cur_ms += 220;
        }
    } else if (_stricmp(cmd, "SHOT") == 0) {
        char spath[260];
        size_t slen = strlen(p);
        while (slen > 0 && (p[slen - 1] == '\r' || p[slen - 1] == '\n' || p[slen - 1] == ' ' || p[slen - 1] == '\t')) --slen;
        if (slen >= sizeof(spath)) slen = sizeof(spath) - 1;
        memcpy(spath, p, slen);
        spath[slen] = '\0';
        add_replay_ev(*cur_ms, RPL_SHOT, 0, 0, 0, spath);
    } else if (_stricmp(cmd, "WALKTO") == 0) {
        double x = 0, z = 0;
        unsigned int duration = 30000;
        if (sscanf(p, "%lf %lf %u", &x, &z, &duration) == 3 &&
            x >= -30000 && x <= 30000 && z >= -30000 && z <= 30000 &&
            duration > 0 && duration <= 120000)
            add_replay_ev(*cur_ms, RPL_WALKTO, (int)(x * 65536.0), (int)(z * 65536.0), (int)duration, NULL);
    } else if (_stricmp(cmd, "WALK3D") == 0) {
        unsigned int dur = 60000;
        if (sscanf(p, "%u", &dur) == 1) {
            add_replay_ev(*cur_ms, RPL_WALK3D, (int)dur, 0, 0, NULL);
            *cur_ms += (uint32_t)dur;
        }
    } else if (_stricmp(cmd, "TEST_TIME") == 0) {
        int hour = -1, minute = -1;
        if (sscanf(p, "%d %d", &hour, &minute) == 2 &&
            hour >= 0 && hour < 24 && minute >= 0 && minute < 60)
            add_replay_ev(*cur_ms, RPL_TEST_TIME, (hour * 60 + minute) * 90, 0, 0, NULL);
    } else if (_stricmp(cmd, "TEST_HP") == 0) {
        int hero = -1, hp = -1;
        if (sscanf(p, "%d %d", &hero, &hp) == 2 &&
            hero >= 0 && hero < 7 && hp >= 1 && hp <= 32767)
            add_replay_ev(*cur_ms, RPL_TEST_HP, hero, hp, 0, NULL);
    } else if (_stricmp(cmd, "TEST_WIN_FIGHT") == 0) {
        add_replay_ev(*cur_ms, RPL_TEST_WIN_FIGHT, 1, 0, 0, NULL);
    } else if (_stricmp(cmd, "STATE") == 0) {
        char label[80] = "";
        if (sscanf(p, "%79s", label) == 1) {
            int valid = 1;
            for (const char *q = label; *q; ++q)
                if (!isalnum((unsigned char)*q) && *q != '_') valid = 0;
            if (valid) add_replay_ev(*cur_ms, RPL_STATE, 0, 0, 0, label);
        }
    } else if (_stricmp(cmd, "QUIT") == 0) {
        int code = 0;
        sscanf(p, "%d", &code);
        add_replay_ev(*cur_ms, RPL_QUIT, code, 0, 0, NULL);
    }
}

#ifdef _WIN32
static DWORD WINAPI riva_replay_watchdog_thread(LPVOID param) {
    DWORD max_ms = (DWORD)(uintptr_t)param;
    Sleep(max_ms);
    /* ExitProcess statt TerminateProcess: die Konsole wird mit dem Prozess geschlossen. */
    ExitProcess(124); /* Ein abgelaufenes Zeitlimit ist kein erfolgreicher Replay. */
    return 0;
}
#endif

void dsa_platform_set_replay_file(const char *path) {
    g_replay_count      = 0;
    g_replay_idx        = 0;
    g_replay_active     = 0;
    g_replay_last_ev_ms = 0;
    g_replay_dir[0]     = '\0';
    if (!path || !path[0]) return;
    {
        const char *s1 = strrchr(path, '\\');
        const char *s2 = strrchr(path, '/');
        const char *sep = (s1 && s2) ? ((s1 > s2) ? s1 : s2) : (s1 ? s1 : s2);
        if (sep) {
            size_t dlen = (size_t)(sep - path);
            if (dlen < sizeof(g_replay_dir) - 1) {
                memcpy(g_replay_dir, path, dlen);
                g_replay_dir[dlen] = '\0';
            }
        }
    }
    FILE *fp = fopen(path, "r");
    if (!fp) return;
    char line[512];
    uint32_t cur_ms = 0;
    while (fgets(line, sizeof(line), fp)) {
        parse_replay_command(&cur_ms, line);
    }
    fclose(fp);
    if (g_replay_count > 0) {
        g_replay_active = 1;
#ifdef _WIN32
        /* Watchdog nur als letzte Sicherung: ExitProcess nach Replay-Ende + 30s.
         * Kein TerminateProcess und kein FreeConsole, sonst bleibt conhost.exe zurueck. */
        DWORD wd_ms = (DWORD)(cur_ms + 30000u);
        const char *env_wd = getenv("RIVA_WATCHDOG_MS");
        if (env_wd && atoi(env_wd) > 0) wd_ms = (DWORD)atoi(env_wd);
        HANDLE hThread = CreateThread(NULL, 0, riva_replay_watchdog_thread, (LPVOID)(uintptr_t)wd_ms, 0, NULL);
        if (hThread) CloseHandle(hThread);
#endif
    }
}

/* =========================================================================
 * 3. Spielverzeichnis & Dateipfad-Aufloesung
 * ========================================================================= */

static char g_game_dir[512]          = "";
static char g_exe_dir[512]           = "";
static char g_save_dir[512]          = "";
static char g_explicit_save_dir[512] = "";
static int  g_save_dir_redirected    = 0;
static int  g_save_dir_reported      = 0;

static void init_exe_dir_once(void) {
    if (g_exe_dir[0]) return;
#ifdef _WIN32
    char mod_path[512] = "";
    DWORD len = GetModuleFileNameA(NULL, mod_path, sizeof(mod_path) - 1);
    if (len > 0) {
        mod_path[len] = '\0';
        char *last_sep = strrchr(mod_path, '\\');
        if (!last_sep) last_sep = strrchr(mod_path, '/');
        if (last_sep) {
            *last_sep = '\0';
            strncpy(g_exe_dir, mod_path, sizeof(g_exe_dir) - 1);
            g_exe_dir[sizeof(g_exe_dir) - 1] = '\0';
            return;
        }
    }
#endif
    strcpy(g_exe_dir, ".");
}

static int contains_nocase(const char *haystack, const char *needle) {
    if (!haystack || !needle || !needle[0]) return 0;
    size_t nlen = strlen(needle);
    for (const char *p = haystack; *p; ++p) {
        if (_strnicmp(p, needle, nlen) == 0) return 1;
    }
    return 0;
}

static int is_protected_gog_gamedir(const char *dir_path) {
    if (!dir_path || !dir_path[0]) return 0;
    if (contains_nocase(dir_path, "Program Files") ||
        contains_nocase(dir_path, "GOG Galaxy") ||
        contains_nocase(dir_path, "GOG Games")) {
        return 1;
    }
    return 0;
}

static int is_dir_writable(const char *dir_path) {
    if (!dir_path || !dir_path[0]) return 0;
    const char *force_ro = getenv("DSA_FORCE_READONLY_GAMEDIR");
    if (force_ro && force_ro[0] == '1') return 0;
    /* Automatische Tests und Replays duerfen NIE in einen echten GOG-Installationsordner schreiben! */
    if ((g_replay_active || (getenv("RIVA_HEADLESS") && getenv("RIVA_HEADLESS")[0] == '1') ||
         (getenv("RIVA_PORT_AUTOTEST") && getenv("RIVA_PORT_AUTOTEST")[0] == '1')) &&
        is_protected_gog_gamedir(dir_path)) {
        return 0;
    }
    char test_path[600];
#ifdef _WIN32
    snprintf(test_path, sizeof(test_path), "%s\\.riva_wtest_%lu.tmp", dir_path, (unsigned long)GetCurrentProcessId());
#else
    snprintf(test_path, sizeof(test_path), "%s/.riva_wtest.tmp", dir_path);
#endif
    FILE *fp = fopen(test_path, "wb");
    if (!fp) return 0;
    fclose(fp);
    _unlink(test_path);
    return 1;
}

static void copy_file_if_missing(const char *src_path, const char *dst_path) {
    if (_access(dst_path, 0) == 0) return;
    FILE *in_fp = fopen(src_path, "rb");
    if (!in_fp) return;
    FILE *out_fp = fopen(dst_path, "wb");
    if (!out_fp) {
        fclose(in_fp);
        return;
    }
    unsigned char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), in_fp)) > 0) {
        fwrite(buf, 1, n, out_fp);
    }
    fclose(out_fp);
    fclose(in_fp);
}

static void seed_save_dir_from_gamedir(const char *game_dir, const char *save_dir) {
    if (!game_dir || !game_dir[0] || !save_dir || !save_dir[0]) return;
    if (_stricmp(game_dir, save_dir) == 0) return;
    char src_cfg[600], dst_cfg[600];
    snprintf(src_cfg, sizeof(src_cfg), "%s\\DATA\\RIVA.CFG", game_dir);
    snprintf(dst_cfg, sizeof(dst_cfg), "%s\\RIVA.CFG", save_dir);
    if (_access(src_cfg, 0) == 0) {
        copy_file_if_missing(src_cfg, dst_cfg);
    } else {
        snprintf(src_cfg, sizeof(src_cfg), "%s\\RIVA.CFG", game_dir);
        if (_access(src_cfg, 0) == 0) copy_file_if_missing(src_cfg, dst_cfg);
    }
#ifdef _WIN32
    char spec[600];
    struct _finddata_t fd;
    snprintf(spec, sizeof(spec), "%s\\GAMES\\*.GAM", game_dir);
    intptr_t h = _findfirst(spec, &fd);
    if (h != -1) {
        do {
            char sp[600], dp[600];
            snprintf(sp, sizeof(sp), "%s\\GAMES\\%s", game_dir, fd.name);
            snprintf(dp, sizeof(dp), "%s\\GAMES\\%s", save_dir, fd.name);
            copy_file_if_missing(sp, dp);
        } while (_findnext(h, &fd) == 0);
        _findclose(h);
    }
#endif
}

static void setup_save_dir(void) {
    init_exe_dir_once();
    const char *env_sd = getenv("DSA_SAVE_DIR");
    const char *chosen_sd = NULL;
    if (g_explicit_save_dir[0]) {
        chosen_sd = g_explicit_save_dir;
    } else if (env_sd && env_sd[0]) {
        chosen_sd = env_sd;
    }

    if (chosen_sd && chosen_sd[0]) {
        strncpy(g_save_dir, chosen_sd, sizeof(g_save_dir) - 1);
        g_save_dir[sizeof(g_save_dir) - 1] = '\0';
        g_save_dir_redirected = (_stricmp(g_save_dir, g_game_dir) != 0 || !is_dir_writable(g_game_dir)) ? 1 : 0;
    } else if (is_dir_writable(g_game_dir)) {
        strncpy(g_save_dir, g_game_dir, sizeof(g_save_dir) - 1);
        g_save_dir[sizeof(g_save_dir) - 1] = '\0';
        g_save_dir_redirected = 0;
    } else {
        if (g_replay_active && g_replay_dir[0]) {
            snprintf(g_save_dir, sizeof(g_save_dir), "%s\\Spielstaende", g_replay_dir);
        } else {
            snprintf(g_save_dir, sizeof(g_save_dir), "%s\\Spielstaende", g_exe_dir);
        }
        g_save_dir_redirected = 1;
    }

    if (g_save_dir[0]) {
        char sub[600];
        MKDIR(g_save_dir);
        snprintf(sub, sizeof(sub), "%s\\GAMES", g_save_dir); MKDIR(sub);
        snprintf(sub, sizeof(sub), "%s\\TEMP", g_save_dir);  MKDIR(sub);
        snprintf(sub, sizeof(sub), "%s\\CTEMP", g_save_dir); MKDIR(sub);
    }

    if (g_save_dir_redirected) {
        seed_save_dir_from_gamedir(g_game_dir, g_save_dir);
        if (!g_save_dir_reported) {
            fprintf(stderr, "[HINWEIS] Spielordner \"%s\" ist nicht beschreibbar -> Spielstaende und PROBEN.CSV werden nach \"%s\" umgeleitet.\n",
                    g_game_dir, g_save_dir);
            fflush(stderr);
            g_save_dir_reported = 1;
        }
    }
}

static void trim_crlf(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\r' || s[n - 1] == '\n' || s[n - 1] == ' ' || s[n - 1] == '\t')) {
        s[--n] = '\0';
    }
}

static void discover_game_dir(const char *explicit_dir) {
    const char *env_dir;
    FILE *fp;
    char line[512];
    const char *candidates[] = {
        "riva_port.ini",
        "SPIELPFAD.txt",
        "..\\SPIELPFAD.txt",
        "../SPIELPFAD.txt",
        "..\\..\\SPIELPFAD.txt",
        "../../SPIELPFAD.txt",
        NULL
    };
    const char *gog_defaults[] = {
        "C:\\Program Files (x86)\\GOG Galaxy\\Games\\Realms of Arkania 3",
        "C:\\Program Files\\GOG Galaxy\\Games\\Realms of Arkania 3",
        "C:\\GOG Games\\Realms of Arkania 3",
        "D:\\GOG Games\\Realms of Arkania 3",
        "C:\\GOG Games\\Realms of Arkania - Shadows over Riva",
        "D:\\GOG Games\\Realms of Arkania - Shadows over Riva",
        NULL
    };
    int i;

    if (explicit_dir && explicit_dir[0]) {
        strncpy(g_game_dir, explicit_dir, sizeof(g_game_dir) - 1);
        g_game_dir[sizeof(g_game_dir) - 1] = '\0';
        return;
    }

    env_dir = getenv("DSA_GAME_DIR");
    if (!env_dir || !env_dir[0]) env_dir = getenv("DSA_GAMEDIR");
    if (env_dir && env_dir[0]) {
        strncpy(g_game_dir, env_dir, sizeof(g_game_dir) - 1);
        g_game_dir[sizeof(g_game_dir) - 1] = '\0';
        return;
    }

    if (_access("DATA\\RIVA.ALF", 0) == 0 && _access("RIVA.EXE", 0) == 0) {
        strcpy(g_game_dir, ".");
        return;
    }

    for (i = 0; candidates[i]; ++i) {
        fp = fopen(candidates[i], "r");
        if (fp) {
            while (fgets(line, sizeof(line), fp)) {
                trim_crlf(line);
                if (line[0] == '\0' || line[0] == '#' || line[0] == ';') continue;
                if (strncmp(line, "gamedir=", 8) == 0) {
                    strncpy(g_game_dir, line + 8, sizeof(g_game_dir) - 1);
                    fclose(fp);
                    return;
                }
                strncpy(g_game_dir, line, sizeof(g_game_dir) - 1);
                fclose(fp);
                return;
            }
            fclose(fp);
        }
    }

    /* Fallback: Standard-GOG-Pfade pruefen */
    for (i = 0; gog_defaults[i]; ++i) {
        char test_alf[600];
        snprintf(test_alf, sizeof(test_alf), "%s\\DATA\\RIVA.ALF", gog_defaults[i]);
        if (_access(test_alf, 0) == 0) {
            strcpy(g_game_dir, gog_defaults[i]);
            return;
        }
    }

    strcpy(g_game_dir, ".");
}

void dsa_platform_set_game_dir(const char *path) {
    discover_game_dir(path);
    setup_save_dir();
}

const char *dsa_platform_get_game_dir(void) {
    if (!g_game_dir[0]) dsa_platform_set_game_dir(NULL);
    return g_game_dir;
}

void dsa_platform_set_save_dir(const char *path) {
    if (path && path[0]) {
        strncpy(g_explicit_save_dir, path, sizeof(g_explicit_save_dir) - 1);
        g_explicit_save_dir[sizeof(g_explicit_save_dir) - 1] = '\0';
    } else {
        g_explicit_save_dir[0] = '\0';
    }
    if (g_game_dir[0]) {
        setup_save_dir();
    }
}

const char *dsa_platform_get_save_dir(void) {
    if (!g_save_dir[0]) dsa_platform_set_game_dir(NULL);
    return g_save_dir;
}

int dsa_platform_is_save_dir_redirected(void) {
    if (!g_save_dir[0]) dsa_platform_set_game_dir(NULL);
    return g_save_dir_redirected;
}

const char *dsa_platform_resolve_path(const char *dos_path, char *out_buf, size_t out_size) {
    const char *p = dos_path;
    char rel[512];
    size_t i = 0;

    if (!dos_path || !out_buf || out_size == 0) return dos_path;
    if (!g_game_dir[0]) dsa_platform_set_game_dir(NULL);

    /* Falls ein DOS-Laufwerksbuchstabe vorangestellt ist (z. B. C:\... oder @:\...):
       Wenn der Pfad bereits auf g_save_dir oder g_game_dir beginnt, relativen Teil extrahieren. */
    if (isalpha((unsigned char)p[0]) && p[1] == ':') {
        size_t sd_len = strlen(g_save_dir);
        size_t gd_len = strlen(g_game_dir);
        if (sd_len > 0 && _strnicmp(p, g_save_dir, sd_len) == 0) {
            p += sd_len;
        } else if (gd_len > 0 && _strnicmp(p, g_game_dir, gd_len) == 0) {
            p += gd_len;
        } else {
            p += 2;
        }
        while (*p == '\\' || *p == '/') ++p;
    } else if (p[0] && p[1] == ':') {
        /* z. B. "@:\\GAMES\\..." wenn getdrive() 0 lieferte */
        p += 2;
        while (*p == '\\' || *p == '/') ++p;
    }

    /* Fuehrende virtuelle DOS-Basis "RIVA\" und .\ / ..\ / DATA\..\ abstreifen */
    if (_strnicmp(p, "RIVA\\", 5) == 0 || _strnicmp(p, "RIVA/", 5) == 0) {
        p += 5;
    }
    while (1) {
        if ((_strnicmp(p, "DATA\\..\\", 8) == 0) || (_strnicmp(p, "DATA/../", 8) == 0)) {
            p += 8;
        } else if (p[0] == '.' && (p[1] == '\\' || p[1] == '/')) {
            p += 2;
        } else if (p[0] == '.' && p[1] == '.' && (p[2] == '\\' || p[2] == '/')) {
            p += 3;
        } else if (*p == '\\' || *p == '/') {
            ++p;
        } else {
            break;
        }
    }

    for (i = 0; p[i] && i < sizeof(rel) - 1; ++i) {
        rel[i] = (p[i] == '/') ? '\\' : p[i];
    }
    rel[i] = '\0';

    /* DOS 8.3-Dateinamen mit Leerzeichen vor dem Punkt (z. B. "START   .GAM") bereinigen */
    {
        char *dot = strrchr(rel, '.');
        char *sep = strrchr(rel, '\\');
        if (dot && (!sep || dot > sep)) {
            char *trim = dot;
            while (trim > rel && trim[-1] == ' ') --trim;
            if (trim < dot) {
                memmove(trim, dot, strlen(dot) + 1);
            }
        }
    }

    if (rel[0] == '\0') {
        strncpy(out_buf, g_game_dir, out_size - 1);
        out_buf[out_size - 1] = '\0';
        return out_buf;
    }

    /* 1. --kein-intro / --skip-intro (RIVA_SKIP_INTRO=1):
     *    In zmain_P1.CPP (f_1439e0, Zeilen 550-556) wird das Intro genau dann uebersprungen,
     *    wenn "C:\\RIVA\\DATA\\..\\GAMES\\LASTGAME" und "C:\\RIVA\\DATA\\..\\GAMES\\START.GAM"
     *    beide existieren und unterschiedliche Dateigroessen haben.
     *    WICHTIG: Direkt danach (zmain_P1.CPP:606) laedt f_05a910("..\\GAMES\\LASTGAME", "LASTGAME")
     *    den Startspielstand! Daher darf GAMES\LASTGAME NIEMALS auf RIVA.EXE umgebogen werden;
     *    stattdessen wird nur die Intro-Groessenpruefung auf "C:\\RIVA\\DATA\\..\\GAMES\\START.GAM"
     *    auf RIVA.EXE umgeleitet (und ein fehlendes GAMES\LASTGAME auf GAMES\START.GAM abgebildet). */
    {
        const char *skip_intro = getenv("RIVA_SKIP_INTRO");
        if (skip_intro && skip_intro[0] == '1') {
            if (_stricmp(rel, "GAMES\\LASTGAME") == 0) {
                const char *base = (g_save_dir_redirected && g_save_dir[0]) ? g_save_dir : g_game_dir;
                snprintf(out_buf, out_size, "%s\\GAMES\\LASTGAME", base);
                if (_access(out_buf, 0) != 0) {
                    snprintf(out_buf, out_size, "%s\\GAMES\\LASTGAME", g_game_dir);
                }
                if (_access(out_buf, 0) != 0) {
                    snprintf(out_buf, out_size, "%s\\GAMES\\START.GAM", g_game_dir);
                }
                return out_buf;
            }
            if (_stricmp(rel, "GAMES\\START.GAM") == 0 &&
                dos_path && (_strnicmp(dos_path, "C:\\RIVA\\DATA\\..\\", 16) == 0 ||
                             _strnicmp(dos_path, "C:/RIVA/DATA/../", 16) == 0)) {
                snprintf(out_buf, out_size, "%s\\RIVA.EXE", g_game_dir);
                if (_access(out_buf, 0) != 0) {
                    snprintf(out_buf, out_size, "%s\\DATA\\RIVA.ALF", g_game_dir);
                }
                return out_buf;
            }
        }
    }

    /* 2. PROBEN.CSV (Live-Probenlog aus R_PLOG.H: d_1c2148\PROBEN.CSV = DATA\PROBEN.CSV)
     *    immer direkt im Wurzelordner von g_save_dir (bzw. g_game_dir) ablegen,
     *    damit die Startskripte und probenlog_fenster.ps1 sie unter %SAVEDIR%\PROBEN.CSV finden. */
    if (_stricmp(rel, "PROBEN.CSV") == 0 ||
        _stricmp(rel, "DATA\\PROBEN.CSV") == 0 ||
        _stricmp(rel, "GAMES\\PROBEN.CSV") == 0) {
        const char *base = g_save_dir[0] ? g_save_dir : g_game_dir;
        snprintf(out_buf, out_size, "%s\\PROBEN.CSV", base);
        return out_buf;
    }

    /* 3. Schreibschutz-Umleitung (g_save_dir_redirected):
     *    GAMES, TEMP, CTEMP, RIVA.CFG, GAMES.NAM, GAMES.TMP und aif.tmp unter g_save_dir aufloesen. */
    if (g_save_dir_redirected && g_save_dir[0]) {
        if (_stricmp(rel, "RIVA.CFG") == 0 || _stricmp(rel, "DATA\\RIVA.CFG") == 0) {
            snprintf(out_buf, out_size, "%s\\RIVA.CFG", g_save_dir);
            return out_buf;
        }
        if (_stricmp(rel, "GAMES.NAM") == 0 || _stricmp(rel, "DATA\\GAMES.NAM") == 0) {
            snprintf(out_buf, out_size, "%s\\GAMES.NAM", g_save_dir);
            return out_buf;
        }
        if (_stricmp(rel, "GAMES.TMP") == 0 || _stricmp(rel, "DATA\\GAMES.TMP") == 0) {
            snprintf(out_buf, out_size, "%s\\GAMES.TMP", g_save_dir);
            return out_buf;
        }
        if (_stricmp(rel, "aif.tmp") == 0 || _stricmp(rel, "DATA\\aif.tmp") == 0) {
            snprintf(out_buf, out_size, "%s\\TEMP\\aif.tmp", g_save_dir);
            return out_buf;
        }
        if (_stricmp(rel, "GAMES") == 0 || _strnicmp(rel, "GAMES\\", 6) == 0 ||
            _stricmp(rel, "TEMP") == 0  || _strnicmp(rel, "TEMP\\", 5) == 0  ||
            _stricmp(rel, "CTEMP") == 0 || _strnicmp(rel, "CTEMP\\", 6) == 0) {
            snprintf(out_buf, out_size, "%s\\%s", g_save_dir, rel);
            if (_strnicmp(rel, "GAMES\\", 6) == 0 && strchr(rel + 6, '*') == NULL &&
                strchr(rel + 6, '?') == NULL && _access(out_buf, 0) != 0) {
                char orig_gam[600];
                snprintf(orig_gam, sizeof(orig_gam), "%s\\%s", g_game_dir, rel);
                if (_access(orig_gam, 0) == 0) {
                    copy_file_if_missing(orig_gam, out_buf);
                }
            }
            return out_buf;
        }
    }

    snprintf(out_buf, out_size, "%s\\%s", g_game_dir, rel);

    /* Falls Datei nicht direkt unter g_game_dir\rel existiert, pruefe g_game_dir\DATA\rel */
    if (_access(out_buf, 0) != 0 && _strnicmp(rel, "DATA\\", 5) != 0 &&
        _strnicmp(rel, "GAMES\\", 6) != 0 && _strnicmp(rel, "TEMP\\", 5) != 0 &&
        _strnicmp(rel, "CTEMP\\", 6) != 0) {
        char alt_buf[600];
        snprintf(alt_buf, sizeof(alt_buf), "%s\\DATA\\%s", g_game_dir, rel);
        if (_access(alt_buf, 0) == 0) {
            strncpy(out_buf, alt_buf, out_size - 1);
            out_buf[out_size - 1] = '\0';
        }
    }

    return out_buf;
}

/* =========================================================================
 * 4. Initialisierung, Moduswechsel, Palette und Frame-Praesentation
 * ========================================================================= */

static void rebuild_palette_argb(int idx) {
    unsigned int r6 = g_pal_rgb6[idx][0] & 0x3F;
    unsigned int g6 = g_pal_rgb6[idx][1] & 0x3F;
    unsigned int b6 = g_pal_rgb6[idx][2] & 0x3F;
    unsigned int r8 = (r6 << 2) | (r6 >> 4);
    unsigned int g8 = (g6 << 2) | (g6 >> 4);
    unsigned int b8 = (b6 << 2) | (b6 >> 4);
    g_pal_argb32[idx] = 0xFF000000u | (r8 << 16) | (g8 << 8) | b8;
}

int dsa_platform_init(const char *window_title, int width, int height, const char *game_dir) {
    int i, win_w, win_h;
    Uint32 win_flags;
    if (game_dir && game_dir[0]) {
        dsa_platform_set_game_dir(game_dir);
    } else if (!g_game_dir[0]) {
        dsa_platform_set_game_dir(NULL);
    }

    if (g_initialized) return 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        return -1;
    }

    dsa_display_init_from_env();

    if (width <= 0)  width  = 320;
    if (height <= 0) height = 200;
    g_width  = width;
    g_height = height;

    /* 4:3-Fenster (320*scale x 240*scale, Standard 4x = 1280x960) bzw. Vollbild anlegen */
    {
        const char *hl = getenv("RIVA_HEADLESS");
        int is_hl = (hl && hl[0] == '1') ? 1 : 0;
        win_w = 320 * g_window_scale;
        win_h = 240 * g_window_scale;
        win_flags = is_hl ? SDL_WINDOW_HIDDEN : (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (g_fullscreen) {
            win_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }
        g_window = SDL_CreateWindow(
            window_title ? window_title : "DSA 3: Schatten ueber Riva (Windows Port)",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            win_w, win_h,
            win_flags
        );
    }
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(g_renderer, g_width, g_height);
    g_canvas_tex_w = win_w;
    g_canvas_tex_h = win_h;
    g_texture = SDL_CreateTexture(
        g_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, g_canvas_tex_w, g_canvas_tex_h
    );

    /* System-Mauszeiger im Spielfenster ausblenden, da Riva seinen eigenen Software-Cursor zeichnet */
    SDL_ShowCursor(0);

    /* Standard-Graustufenpalette bis zum ersten Spiel-Palettenupdate */
    for (i = 0; i < 256; ++i) {
        g_pal_rgb6[i][0] = (unsigned char)((i >> 2) & 0x3F);
        g_pal_rgb6[i][1] = (unsigned char)((i >> 2) & 0x3F);
        g_pal_rgb6[i][2] = (unsigned char)((i >> 2) & 0x3F);
        rebuild_palette_argb(i);
    }
    g_pal_rgb6[0][0] = g_pal_rgb6[0][1] = g_pal_rgb6[0][2] = 0;
    rebuild_palette_argb(0);

    g_initialized = 1;
    return 0;
}

extern "C" void riva_write_audio_stats(void);

void dsa_platform_shutdown(void) {
    riva_write_audio_stats();
    if (g_record_fp) { fclose(g_record_fp); g_record_fp = NULL; }
    if (!g_initialized) return;
    if (g_canvas_buf) { free(g_canvas_buf); g_canvas_buf = NULL; g_canvas_cap = 0; }
    if (g_texture)  { SDL_DestroyTexture(g_texture);   g_texture  = NULL; }
    if (g_renderer) { SDL_DestroyRenderer(g_renderer); g_renderer = NULL; }
    if (g_window)   { SDL_DestroyWindow(g_window);     g_window   = NULL; }
    SDL_Quit();
    g_initialized = 0;
}

void dsa_platform_set_mode(int dos_mode, int width, int height) {
    if (!g_initialized) {
        dsa_platform_init(NULL, width > 0 ? width : 320, height > 0 ? height : 200, NULL);
    }
    g_dos_mode = dos_mode;
    if (width <= 0 || height <= 0) {
        if (dos_mode == 0x100)      { width = 640; height = 400; }
        else if (dos_mode == 0x101) { width = 640; height = 480; }
        else                        { width = 320; height = 200; }
    }
    if (width > DSA_MAX_VRAM_WIDTH)   width  = DSA_MAX_VRAM_WIDTH;
    if (height > DSA_MAX_VRAM_HEIGHT) height = DSA_MAX_VRAM_HEIGHT;

    if (width != g_width || height != g_height) {
        g_width  = width;
        g_height = height;
        SDL_RenderSetLogicalSize(g_renderer, g_width, g_height);
    }
    g_mouse_max_x = g_width - 1;
    g_mouse_max_y = g_height - 1;
    memset(g_vram, 0, DSA_VRAM_SIZE);
    dsa_platform_present();
}

int dsa_platform_get_width(void)  { return g_width; }
int dsa_platform_get_height(void) { return g_height; }

unsigned char *dsa_platform_get_vram(void) {
    return g_vram;
}

static void poll_sdl_events_internal(void) {
    SDL_Event ev;
    if (!g_initialized) return;

    while (SDL_PollEvent(&ev)) {
        if (g_replay_active && ev.type != SDL_QUIT) {
            continue;
        }
        switch (ev.type) {
        case SDL_QUIT:
            dsa_platform_shutdown();
            exit(0);
            break;

        case SDL_MOUSEMOTION:
            g_mouse_x = ev.motion.x;
            g_mouse_y = ev.motion.y;
            if (g_mouse_x < g_mouse_min_x) g_mouse_x = g_mouse_min_x;
            if (g_mouse_x > g_mouse_max_x) g_mouse_x = g_mouse_max_x;
            if (g_mouse_y < g_mouse_min_y) g_mouse_y = g_mouse_min_y;
            if (g_mouse_y > g_mouse_max_y) g_mouse_y = g_mouse_max_y;
            d_1bf4f0 = (unsigned short)g_mouse_x;
            d_1bf4f2 = (short)g_mouse_y;
            if (g_record_fp) {
                fprintf(g_record_fp, "AT %u MOVE %d %d\n", (unsigned)SDL_GetTicks(), g_mouse_x, g_mouse_y);
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            int bit = 0;
            if (ev.button.button == SDL_BUTTON_LEFT)        bit = 1;
            else if (ev.button.button == SDL_BUTTON_RIGHT)  bit = 2;
            else if (ev.button.button == SDL_BUTTON_MIDDLE) bit = 4;

            g_mouse_x = ev.button.x;
            g_mouse_y = ev.button.y;
            if (g_mouse_x < g_mouse_min_x) g_mouse_x = g_mouse_min_x;
            if (g_mouse_x > g_mouse_max_x) g_mouse_x = g_mouse_max_x;
            if (g_mouse_y < g_mouse_min_y) g_mouse_y = g_mouse_min_y;
            if (g_mouse_y > g_mouse_max_y) g_mouse_y = g_mouse_max_y;
            d_1bf4f0 = (unsigned short)g_mouse_x;
            d_1bf4f2 = (short)g_mouse_y;

            if (ev.type == SDL_MOUSEBUTTONDOWN) {
                d_1bf4f8 = (short)g_mouse_x;
                d_1bf4fa = (short)g_mouse_y;
                g_mouse_buttons |= bit;
                g_mouse_latched_down |= bit;
                g_mouse_pending_up &= ~bit;
                if (g_record_fp) {
                    fprintf(g_record_fp, "AT %u MDOWN %d %d %d\n", (unsigned)SDL_GetTicks(), g_mouse_x, g_mouse_y, bit);
                    fflush(g_record_fp);
                }
            } else {
                if (g_mouse_latched_down & bit) {
                    /* Halte kurzen Klick bis zur naechsten Mausabfrage sichtbar */
                    g_mouse_pending_up |= bit;
                } else {
                    g_mouse_buttons &= ~bit;
                }
                if (g_record_fp) {
                    fprintf(g_record_fp, "AT %u MUP %d %d %d\n", (unsigned)SDL_GetTicks(), g_mouse_x, g_mouse_y, bit);
                    fflush(g_record_fp);
                }
            }
            break;
        }

        case SDL_KEYDOWN:
        case SDL_KEYUP: {
            int down = (ev.type == SDL_KEYDOWN);
            unsigned char dos_sc = 0;
            unsigned char ascii = 0;
            Uint16 mod = ev.key.keysym.mod;

            /* BIOS Shift-Status aktualisieren */
            g_shift_status = 0;
            if (mod & KMOD_RSHIFT) g_shift_status |= 0x01;
            if (mod & KMOD_LSHIFT) g_shift_status |= 0x02;
            if (mod & KMOD_CTRL)   g_shift_status |= 0x04;
            if (mod & KMOD_ALT)    g_shift_status |= 0x08;

            if (ev.key.keysym.scancode < 0) {
                /* Eingebauter Win32-Provider liefert direkten DOS-Set-1-Scancode */
                dos_sc = (unsigned char)((-ev.key.keysym.scancode) & 0x7F);
                ascii  = (unsigned char)(ev.key.keysym.unused & 0xFF);
            } else {
                dos_sc = sdl_scancode_to_dos(ev.key.keysym.scancode, ev.key.keysym.sym, mod, &ascii);
            }

            /* Alt+Enter: Vollbild/Fenstermodus umschalten */
            if (down && !ev.key.repeat && (mod & KMOD_ALT) && (dos_sc == 0x1C || ev.key.keysym.sym == 13)) {
                dsa_platform_toggle_fullscreen();
                break;
            }

            if (dos_sc < 128) {
                g_scancode_down[dos_sc] = down ? 1 : 0;
            }
            if (down && dos_sc != 0 && dos_sc != 0x2A && dos_sc != 0x36 && dos_sc != 0x1D && dos_sc != 0x38) {
                keyq_push(((unsigned short)dos_sc << 8) | (unsigned short)ascii);
            }
            if (g_record_fp && !ev.key.repeat) {
                fprintf(g_record_fp, "AT %u %s 0x%02X 0x%02X 0x%04X\n",
                        (unsigned)SDL_GetTicks(), down ? "KDOWN" : "KUP",
                        (unsigned)dos_sc, (unsigned)ascii, (unsigned)g_shift_status);
                fflush(g_record_fp);
            }
            break;
        }
        }
    }
}

static void dsa_save_bmp(const char *path) {
    char full_path[600];
    if (g_replay_dir[0] && strchr(path, ':') == NULL && path[0] != '\\' && path[0] != '/') {
        snprintf(full_path, sizeof(full_path), "%s\\%s", g_replay_dir, path);
        path = full_path;
    }
    FILE *fp = fopen(path, "wb");
    if (!fp) return;
    int w = g_width, h = g_height;
    uint32_t row_bytes = (uint32_t)(w * 3);
    uint32_t img_size = row_bytes * (uint32_t)h;
    uint32_t file_size = 54 + img_size;
    unsigned char hdr[54];
    memset(hdr, 0, sizeof(hdr));
    hdr[0] = 'B'; hdr[1] = 'M';
    *(uint32_t *)(hdr + 2)  = file_size;
    *(uint32_t *)(hdr + 10) = 54;
    *(uint32_t *)(hdr + 14) = 40;
    *(int32_t  *)(hdr + 18) = w;
    *(int32_t  *)(hdr + 22) = -h; /* top-down */
    *(uint16_t *)(hdr + 26) = 1;
    *(uint16_t *)(hdr + 28) = 24;
    *(uint32_t *)(hdr + 34) = img_size;
    fwrite(hdr, 1, 54, fp);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            uint32_t c = g_argb_buffer[y * w + x];
            unsigned char bgr[3] = {
                (unsigned char)(c & 0xFF),
                (unsigned char)((c >> 8) & 0xFF),
                (unsigned char)((c >> 16) & 0xFF)
            };
            fwrite(bgr, 1, 3, fp);
        }
    }
    fclose(fp);
}

static void dsa_save_canvas_bmp(const char *path, const uint32_t *argb, int w, int h) {
    FILE *fp = fopen(path, "wb");
    if (!fp || !argb || w <= 0 || h <= 0) {
        if (fp) fclose(fp);
        return;
    }
    uint32_t row_bytes = (uint32_t)((w * 3 + 3) & ~3);
    uint32_t img_size = row_bytes * (uint32_t)h;
    uint32_t file_size = 54 + img_size;
    unsigned char hdr[54];
    unsigned char pad[3] = {0, 0, 0};
    int pad_len = (int)row_bytes - w * 3;
    memset(hdr, 0, sizeof(hdr));
    hdr[0] = 'B'; hdr[1] = 'M';
    *(uint32_t *)(hdr + 2)  = file_size;
    *(uint32_t *)(hdr + 10) = 54;
    *(uint32_t *)(hdr + 14) = 40;
    *(int32_t  *)(hdr + 18) = w;
    *(int32_t  *)(hdr + 22) = -h;
    *(uint16_t *)(hdr + 26) = 1;
    *(uint16_t *)(hdr + 28) = 24;
    *(uint32_t *)(hdr + 34) = img_size;
    fwrite(hdr, 1, 54, fp);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            uint32_t c = argb[y * w + x];
            unsigned char bgr[3] = {
                (unsigned char)(c & 0xFF),
                (unsigned char)((c >> 8) & 0xFF),
                (unsigned char)((c >> 16) & 0xFF)
            };
            fwrite(bgr, 1, 3, fp);
        }
        if (pad_len > 0) fwrite(pad, 1, (size_t)pad_len, fp);
    }
    fclose(fp);
}

static void dsa_compute_viewport_4_3(int cw, int ch, int *out_vx, int *out_vy, int *out_vw, int *out_vh) {
    int vx = 0, vy = 0, vw = cw, vh = ch;
    if (cw <= 0) cw = 320;
    if (ch <= 0) ch = 240;

    if (g_scaling_mode == 1) {
        /* Ganzzahlige 4:3-Skalierung: groesstes k >= 1 mit (320*k, 240*k) <= (cw, ch) */
        int base_w = (g_width >= 640) ? 640 : 320;
        int base_h = (g_width >= 640) ? 480 : 240;
        int kx = cw / base_w;
        int ky = ch / base_h;
        int k  = (kx < ky) ? kx : ky;
        if (k >= 1) {
            vw = k * base_w;
            vh = k * base_h;
            vx = (cw - vw) / 2;
            vy = (ch - vh) / 2;
            *out_vx = vx; *out_vy = vy; *out_vw = vw; *out_vh = vh;
            return;
        }
    }

    /* 4:3 Vollbild-/Fenster-Einpassung mit Letterbox/Pillarbox */
    if (cw * 3 <= ch * 4) {
        vw = cw;
        vh = (cw * 3 + 2) / 4;
    } else {
        vh = ch;
        vw = (ch * 4 + 1) / 3;
    }
    if (vw <= 0) vw = 1;
    if (vh <= 0) vh = 1;
    vx = (cw - vw) / 2;
    vy = (ch - vh) / 2;
    *out_vx = vx; *out_vy = vy; *out_vw = vw; *out_vh = vh;
}

static void dsa_scale_4_3_canvas(int cw, int ch, int vx, int vy, int vw, int vh) {
    int total_px = cw * ch;
    if (total_px <= 0) return;
    if (total_px > g_canvas_cap) {
        uint32_t *nb = (uint32_t *)realloc(g_canvas_buf, (size_t)total_px * sizeof(uint32_t));
        if (!nb) return;
        g_canvas_buf = nb;
        g_canvas_cap = total_px;
    }
    memset(g_canvas_buf, 0, (size_t)total_px * sizeof(uint32_t));
    if (vw <= 0 || vh <= 0) return;

    int src_w = (g_width > 0) ? g_width : 320;
    int src_h = (g_height > 0) ? g_height : 200;

    if (g_scaling_mode == 1) {
        for (int dy = 0; dy < vh; ++dy) {
            int sy = (dy * src_h) / vh;
            if (sy >= src_h) sy = src_h - 1;
            const uint32_t *srow = g_argb_buffer + sy * src_w;
            uint32_t *drow = g_canvas_buf + (vy + dy) * cw + vx;
            for (int dx = 0; dx < vw; ++dx) {
                int sx = (dx * src_w) / vw;
                if (sx >= src_w) sx = src_w - 1;
                drow[dx] = srow[sx];
            }
        }
        return;
    }

    /* F7 (2b): Scharfe pixelgetreue 4:3-Skalierung (Sharp-Bilinear / Sub-Texel-AA) */
    int scale_x_fp = (vw << 8) / src_w;
    int scale_y_fp = (vh << 8) / src_h;
    if (scale_x_fp < 256) scale_x_fp = 256;
    if (scale_y_fp < 256) scale_y_fp = 256;

    for (int dy = 0; dy < vh; ++dy) {
        int u_y = ((dy * 2 + 1) * src_h * 128) / vh - 128;
        int sy0, sy1, wy;
        if (u_y <= 0) {
            sy0 = sy1 = 0; wy = 0;
        } else if (u_y >= (src_h - 1) * 256) {
            sy0 = sy1 = src_h - 1; wy = 0;
        } else {
            sy0 = u_y >> 8;
            sy1 = sy0 + 1;
            int fy = u_y & 255;
            int dist = (fy < 128) ? (128 - fy) : (fy - 128);
            int edge = (dist * scale_y_fp) >> 8;
            if (edge >= 128) {
                wy = (fy < 128) ? 0 : 256;
            } else {
                wy = (fy < 128) ? (128 - edge) : (128 + edge);
            }
        }
        const uint32_t *srow0 = g_argb_buffer + sy0 * src_w;
        const uint32_t *srow1 = g_argb_buffer + sy1 * src_w;
        uint32_t *drow = g_canvas_buf + (vy + dy) * cw + vx;

        for (int dx = 0; dx < vw; ++dx) {
            int u_x = ((dx * 2 + 1) * src_w * 128) / vw - 128;
            int sx0, sx1, wx;
            if (u_x <= 0) {
                sx0 = sx1 = 0; wx = 0;
            } else if (u_x >= (src_w - 1) * 256) {
                sx0 = sx1 = src_w - 1; wx = 0;
            } else {
                sx0 = u_x >> 8;
                sx1 = sx0 + 1;
                int fx = u_x & 255;
                int dist = (fx < 128) ? (128 - fx) : (fx - 128);
                int edge = (dist * scale_x_fp) >> 8;
                if (edge >= 128) {
                    wx = (fx < 128) ? 0 : 256;
                } else {
                    wx = (fx < 128) ? (128 - edge) : (128 + edge);
                }
            }

            if (wx == 0 && wy == 0) {
                drow[dx] = srow0[sx0];
            } else if (wx == 256 && wy == 0) {
                drow[dx] = srow0[sx1];
            } else if (wx == 0 && wy == 256) {
                drow[dx] = srow1[sx0];
            } else if (wx == 256 && wy == 256) {
                drow[dx] = srow1[sx1];
            } else {
                uint32_t c00 = srow0[sx0], c10 = srow0[sx1];
                uint32_t c01 = srow1[sx0], c11 = srow1[sx1];
                int w00 = (256 - wx) * (256 - wy);
                int w10 = wx * (256 - wy);
                int w01 = (256 - wx) * wy;
                int w11 = wx * wy;
                uint32_t r = (((c00 >> 16) & 0xFF) * w00 + ((c10 >> 16) & 0xFF) * w10 + ((c01 >> 16) & 0xFF) * w01 + ((c11 >> 16) & 0xFF) * w11) >> 16;
                uint32_t g = (((c00 >>  8) & 0xFF) * w00 + ((c10 >>  8) & 0xFF) * w10 + ((c01 >>  8) & 0xFF) * w01 + ((c11 >>  8) & 0xFF) * w11) >> 16;
                uint32_t b = (( c00        & 0xFF) * w00 + ( c10        & 0xFF) * w10 + ( c01        & 0xFF) * w01 + ( c11        & 0xFF) * w11) >> 16;
                drow[dx] = 0xFF000000u | (r << 16) | (g << 8) | b;
            }
        }
    }
}

extern "C" unsigned char riva_dgroup_base[];

void dsa_platform_present(void) {
    static int autotest_checked = 0;
    static int autotest_enabled = 0;
    static int autotest_stage = 0;
    static int canvas_dumped = 0;
    int total, i, cw = 0, ch = 0, vx = 0, vy = 0, vw = 0, vh = 0;
    if (!g_initialized) {
        dsa_platform_init(NULL, g_width, g_height, NULL);
    }
    if (!autotest_checked) {
        const char *at = getenv("RIVA_PORT_AUTOTEST");
        autotest_enabled = (at && at[0] == '1') ? 1 : 0;
        autotest_checked = 1;
    }
    poll_sdl_events_internal();

    total = g_width * g_height;
    for (i = 0; i < total; ++i) {
        g_argb_buffer[i] = g_pal_argb32[g_vram[i]];
    }

    SDL_GetWindowSize(g_window, &cw, &ch);
    if (cw <= 0) cw = 320 * g_window_scale;
    if (ch <= 0) ch = 240 * g_window_scale;

    dsa_compute_viewport_4_3(cw, ch, &vx, &vy, &vw, &vh);
    SDL_SetWindowViewport(g_window, vx, vy, vw, vh);
    dsa_scale_4_3_canvas(cw, ch, vx, vy, vw, vh);

    if (cw != g_canvas_tex_w || ch != g_canvas_tex_h || !g_texture) {
        if (g_texture) SDL_DestroyTexture(g_texture);
        g_canvas_tex_w = cw;
        g_canvas_tex_h = ch;
        g_texture = SDL_CreateTexture(
            g_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, g_canvas_tex_w, g_canvas_tex_h
        );
    }

    if (g_canvas_buf && g_texture) {
        SDL_UpdateTexture(g_texture, NULL, g_canvas_buf, cw * (int)sizeof(uint32_t));
    }

    if (!canvas_dumped && g_canvas_buf) {
        const char *dump_path = getenv("DSA_DUMP_CANVAS_BMP");
        if (dump_path && dump_path[0] && SDL_GetTicks() >= 1500) {
            dsa_save_canvas_bmp(dump_path, g_canvas_buf, cw, ch);
            canvas_dumped = 1;
        }
    }

    SDL_RenderClear(g_renderer);
    SDL_RenderCopy(g_renderer, g_texture, NULL, NULL);
    SDL_RenderPresent(g_renderer);
    g_last_present_ms = SDL_GetTicks();

    if (g_replay_active) {
        uint32_t now = g_last_present_ms;
        static uint32_t rpl_last_check_ms = 0;
        static uint32_t rpl_turn_until_ms = 0;
        static int      rpl_turn_dir = 0;
        static int      rpl_last_wx = 0, rpl_last_wz = 0;
        static int      rpl_start_wz = 0;
        static int      rpl_stuck_count = 0;

        if (g_replay_walk_end > 0) {
            if (now < g_replay_walk_end) {
                int wx = *(int *)(&riva_dgroup_base[0x2d308]);
                int wz = *(int *)(&riva_dgroup_base[0x2d310]);
                unsigned short yaw = *(unsigned short *)(&riva_dgroup_base[0x2dc1e]);
                if (rpl_start_wz == 0 && wz != 0) rpl_start_wz = wz >> 16;
                int dz_start = (wz >> 16) - rpl_start_wz;
                if (dz_start < 0) dz_start = -dz_start;
                if ((wx >> 16) <= -950 && dz_start <= 160 && yaw >= 0x1800u && yaw <= 0x6800u) {
                    rpl_turn_dir = 0;
                    rpl_turn_until_ms = now + 450;
                }
                if (now < rpl_turn_until_ms) {
                    g_scancode_down[0x48] = (rpl_stuck_count > 0) ? 0 : 1;
                    g_scancode_down[0x4b] = (rpl_turn_dir == 0) ? 1 : 0;
                    g_scancode_down[0x4d] = (rpl_turn_dir == 1) ? 1 : 0;
                    rpl_last_check_ms = now;
                    rpl_last_wx = wx;
                    rpl_last_wz = wz;
                } else {
                    g_scancode_down[0x48] = 1;
                    g_scancode_down[0x4b] = 0;
                    g_scancode_down[0x4d] = 0;
                    if (now - rpl_last_check_ms >= 400) {
                        int dx = (wx - rpl_last_wx) >> 16;
                        int dz = (wz - rpl_last_wz) >> 16;
                        if (dx * dx + dz * dz < 225) {
                            rpl_stuck_count++;
                            rpl_turn_dir = ((rpl_stuck_count % 4) == 0) ? (1 - rpl_turn_dir) : rpl_turn_dir;
                            rpl_turn_until_ms = now + 350 + (rpl_stuck_count % 3) * 180;
                        } else {
                            rpl_stuck_count = 0;
                            if (((now / 400) % 12) == 0) {
                                rpl_turn_dir = ((now / 400) / 12) & 1;
                                rpl_turn_until_ms = now + 260;
                            }
                        }
                        rpl_last_wx = wx;
                        rpl_last_wz = wz;
                        rpl_last_check_ms = now;
                    }
                }
            } else {
                g_scancode_down[0x48] = 0;
                g_scancode_down[0x4b] = 0;
                g_scancode_down[0x4d] = 0;
                g_replay_walk_end = 0;
            }
        }

        if (g_walkto_deadline) {
            int wx = 0, wz = 0;
            unsigned short yaw = 0;
            memcpy(&wx, riva_dgroup_base + 0x2d308, 4);
            memcpy(&wz, riva_dgroup_base + 0x2d310, 4);
            memcpy(&yaw, riva_dgroup_base + 0x2dc1e, 2);
            double dx = ((double)g_walkto_x - wx) / 65536.0;
            double dz = ((double)g_walkto_z - wz) / 65536.0;
            double distance = sqrt(dx * dx + dz * dz);
            int heading = (int)(atan2(-dx, -dz) * (65536.0 / 6.283185307179586));
            short delta = (short)((unsigned short)heading - yaw);
            if (distance + 5 < g_walkto_best_distance) {
                g_walkto_best_distance = distance;
                g_walkto_progress_ms = now;
            }
            if (delta > 450 || delta < -450) g_walkto_progress_ms = now;
            int reached = distance <= 18.0;
            int expired = (int32_t)(now - g_walkto_deadline) >= 0;
            int stalled = now - g_walkto_progress_ms >= 2500;
            g_scancode_down[0x48] = (!reached && !expired && !stalled && delta <= 900 && delta >= -900);
            g_scancode_down[0x4b] = (!reached && !expired && !stalled && delta > 450);
            g_scancode_down[0x4d] = (!reached && !expired && !stalled && delta < -450);
            if (reached || expired || stalled) {
                char path[600];
                snprintf(path, sizeof(path), "%s\\walkto.jsonl", g_replay_dir);
                FILE *fp = fopen(path, "a");
                if (fp) {
                    fprintf(fp, "{\"target\":[%.3f,%.3f],\"position\":[%.3f,%.3f],"
                            "\"distance\":%.3f,\"result\":\"%s\"}\n",
                            g_walkto_x / 65536.0, g_walkto_z / 65536.0,
                            wx / 65536.0, wz / 65536.0, distance,
                            reached ? "reached" : expired ? "timeout" : "stalled");
                    fclose(fp);
                }
                if (!reached) g_replay_failure = 125;
                g_walkto_deadline = 0;
            }
        }

        if (g_replay_last_ev_ms == 0) {
            g_replay_last_ev_ms = now;
        }
        if (g_walkto_deadline) {
            g_replay_last_ev_ms = now;
        } else if (g_in_delay_ms > 0 && g_replay_idx < g_replay_count &&
            g_replay_events[g_replay_idx].type != RPL_MUP &&
            g_replay_events[g_replay_idx].type != RPL_KUP) {
            g_replay_last_ev_ms = now;
        } else {
        while (g_replay_idx < g_replay_count) {
            uint32_t prev_t = (g_replay_idx == 0) ? 0 : g_replay_events[g_replay_idx - 1].t_ms;
            uint32_t cur_t  = g_replay_events[g_replay_idx].t_ms;
            uint32_t dt_ms  = (cur_t >= prev_t) ? (cur_t - prev_t) : 0;
            if (now - g_replay_last_ev_ms < dt_ms) {
                break;
            }
            ReplayEvent *ev = &g_replay_events[g_replay_idx++];
            g_replay_last_ev_ms = now;
            switch (ev->type) {
            case RPL_MOVE:
                g_mouse_x = ev->a;
                g_mouse_y = ev->b;
                d_1bf4f0 = (unsigned short)g_mouse_x;
                d_1bf4f2 = (short)g_mouse_y;
                break;
            case RPL_MDOWN:
                g_mouse_x = ev->a;
                g_mouse_y = ev->b;
                d_1bf4f0 = (unsigned short)g_mouse_x;
                d_1bf4f2 = (short)g_mouse_y;
                d_1bf4f8 = (short)g_mouse_x;
                d_1bf4fa = (short)g_mouse_y;
                g_mouse_buttons |= ev->c;
                g_mouse_latched_down |= ev->c;
                g_mouse_pending_up &= ~ev->c;
                break;
            case RPL_DCLICK:
                g_mouse_x = ev->a;
                g_mouse_y = ev->b;
                d_1bf4f0 = (unsigned short)g_mouse_x;
                d_1bf4f2 = (short)g_mouse_y;
                d_1bf4f8 = (short)g_mouse_x;
                d_1bf4fa = (short)g_mouse_y;
                d_1bf4c0 = d_1c3914;
                d_1bf4c8 = 1;
                g_mouse_buttons |= ev->c;
                g_mouse_latched_down |= ev->c;
                g_mouse_pending_up &= ~ev->c;
                break;
            case RPL_MUP:
                g_mouse_x = ev->a;
                g_mouse_y = ev->b;
                d_1bf4f0 = (unsigned short)g_mouse_x;
                d_1bf4f2 = (short)g_mouse_y;
                if (g_mouse_latched_down & ev->c) g_mouse_pending_up |= ev->c;
                else g_mouse_buttons &= ~ev->c;
                break;
            case RPL_TRIGGER:
                d_1bd6c4 = (short)ev->a;
                break;
            case RPL_LOC:
                g_pending_loc = ev->a;
                break;
            case RPL_MAP:
                g_pending_map  = ev->a;
                g_pending_cell = ev->b;
                break;
            case RPL_FIGHT:
                g_pending_fight = ev->a;
                break;
            case RPL_SPEECH:
                g_pending_speech = ev->a;
                break;
            case RPL_ENDGAME:
                g_pending_endgame = 1;
                break;
            case RPL_TEST_TIME:
                g_pending_test_time = ev->a;
                break;
            case RPL_TEST_HP:
                g_pending_test_hp_hero = ev->a;
                g_pending_test_hp = ev->b;
                break;
            case RPL_TEST_WIN_FIGHT: {
                unsigned char *monsters = NULL;
                memcpy(&monsters, riva_dgroup_base + 0x22ed4, sizeof(monsters));
                if (monsters) {
                    for (int i = 0; i < 20; ++i) {
                        unsigned char *m = monsters + i * 0x73;
                        short zero = 0;
                        memcpy(m + 0x1b, &zero, 2);
                        m[0x38] |= 1;
                    }
                }
                break;
            }
            case RPL_STATE: {
                char path[600];
                snprintf(path, sizeof(path), "%s\\state_%s.json", g_replay_dir, ev->str);
                FILE *fp = fopen(path, "w");
                if (fp) {
                    int ticks = 0;
                    memcpy(&ticks, d_1c2c44 + 1, sizeof(ticks));
                    short combat_id = 0, combat_result = 0, combat_rounds = 0;
                    short game_state = 0, combat_active = 0;
                    /* Nur lesen: Originalstatistik wird erst am Kampfende geschrieben. */
                    memcpy(&combat_id, riva_dgroup_base + 0x1c96c, 2);
                    memcpy(&combat_result, riva_dgroup_base + 0x1c96e, 2);
                    memcpy(&combat_rounds, riva_dgroup_base + 0x1c970, 2);
                    memcpy(&game_state, riva_dgroup_base + 0x221a4, 2);
                    memcpy(&combat_active, riva_dgroup_base + 0x1d90c, 2);
                    fprintf(fp, "{\"money_heller\":%u,\"clock_ticks\":%d,"
                            "\"game_state\":%d,\"combat_active\":%d,"
                            "\"last_combat_id\":%d,\"last_combat_result\":%d,"
                            "\"last_combat_rounds\":%d,"
                            "\"final_phase1\":%d,\"final_queen_dead\":%d,\"heroes\":[",
                            d_1c0004 ? f_0de7e0(d_1c0004) : 0, ticks,
                            game_state, combat_active, combat_id, combat_result, combat_rounds,
                            (int)d_1bdb80, (int)d_1bdb84);
                    int first = d_1c0004 ? f_038c80(d_1c0004) : 0;
                    int hero = first;
                    for (int h = 0; hero && h < 7; ++h) {
                        const unsigned char *data = (const unsigned char *)(uintptr_t)hero;
                        short le = 0, le_max = 0, ae = 0, ae_max = 0;
                        memcpy(&le_max, data + 0x70, 2);
                        memcpy(&le, data + 0x72, 2);
                        memcpy(&ae_max, data + 0x74, 2);
                        memcpy(&ae, data + 0x76, 2);
                        fprintf(fp, "%s{\"name_hex\":\"", h ? "," : "");
                        for (int j = 0; j < 16 && data[0x22+j]; ++j)
                            fprintf(fp, "%02x", data[0x22+j]);
                        int grid_x = -1, grid_y = -1;
                        if (combat_active) {
                            const unsigned char *grid = NULL;
                            const unsigned char *hero_base = NULL;
                            memcpy(&grid, riva_dgroup_base + 0x1d984, sizeof(grid));
                            memcpy(&hero_base, riva_dgroup_base + 0x1c8f0, sizeof(hero_base));
                            int id = hero_base ? (int)((data - hero_base) / 0x5ef) + 1 : 0;
                            if (grid && id >= 1 && id <= 7) {
                                for (int gy = 0; gy < 24; ++gy)
                                    for (int gx = 0; gx < 24; ++gx)
                                        if (grid[gy * 25 + gx] == id) { grid_x = gx; grid_y = gy; }
                            }
                        }
                        fprintf(fp, "\",\"le\":%d,\"le_max\":%d,\"ae\":%d,\"ae_max\":%d,"
                                "\"bp\":%u,\"combat_action\":%d,\"combat_spell\":%d,\"combat_target\":%u,"
                                "\"grid\":[%d,%d],\"slots\":[",
                                le, le_max, ae, ae_max, data[0x45], (signed char)data[0x96],
                                (signed char)data[0x97], data[0x98], grid_x, grid_y);
                        /* RIVAHERO.H: Inventar ab 0x1a8, 31 Slots zu 0x1b Bytes. */
                        for (int j = 0; j < 31; ++j) {
                            short id = 0, quantity = 0;
                            memcpy(&id, data + 0x1a8 + j * 0x1b, 2);
                            memcpy(&quantity, data + 0x1aa + j * 0x1b, 2);
                            fprintf(fp, "%s[%d,%d]", j ? "," : "", id, quantity);
                        }
                        fprintf(fp, "]}");
                        hero = f_0391b0(d_1c0004, hero);
                        if (hero == first) break;
                    }
                    fprintf(fp, "],\"combat_grid\":[");
                    const unsigned char *combat_grid = NULL;
                    if (combat_active) memcpy(&combat_grid, riva_dgroup_base + 0x1d984, sizeof(combat_grid));
                    int grid_count = 0;
                    if (combat_grid) {
                        for (int gy = 0; gy < 24; ++gy)
                            for (int gx = 0; gx < 24; ++gx) {
                                unsigned id = combat_grid[gy * 25 + gx];
                                if (id > 0)
                                    fprintf(fp, "%s[%d,%d,%u]", grid_count++ ? "," : "", gx, gy, id);
                            }
                    }
                    short location = -1, map_id = -1;
                    unsigned short yaw = 0;
                    int wx = 0, wy = 0, wz = 0;
                    if (d_1c0004) {
                        memcpy(&location, (const char *)(uintptr_t)d_1c0004 + 0x23, 2);
                        memcpy(&map_id, (const char *)(uintptr_t)d_1c0004 + 0x25, 2);
                    }
                    memcpy(&wx, riva_dgroup_base + 0x2d308, 4);
                    memcpy(&wy, riva_dgroup_base + 0x2d30c, 4);
                    memcpy(&wz, riva_dgroup_base + 0x2d310, 4);
                    memcpy(&yaw, riva_dgroup_base + 0x2dc1e, 2);
                    fprintf(fp, "],\"world\":{\"location\":%d,\"map\":%d,"
                            "\"xyz_fixed\":[%d,%d,%d],\"yaw\":%u}",
                            location, map_id, wx, wy, wz, yaw);
                    if (strncmp(ev->str, "scene_", 6) == 0) {
                        const unsigned char *objects = NULL;
                        int object_count = 0;
                        memcpy(&objects, riva_dgroup_base + 0x2d210, sizeof(objects));
                        memcpy(&object_count, riva_dgroup_base + 0x99ac, 4);
                        fprintf(fp, ",\"scene_objects\":[");
                        if (riva_dgroup_base[0x993d] && objects && object_count >= 0 && object_count < 20000) {
                            for (int i = 0; i < object_count; ++i) {
                                const unsigned char *entry = objects + i * 0x30;
                                unsigned short id = 0;
                                int x = 0, y = 0, z = 0;
                                memcpy(&id, entry + 2, 2);
                                memcpy(&x, entry + 0x1c, 4);
                                memcpy(&y, entry + 0x20, 4);
                                memcpy(&z, entry + 0x24, 4);
                                fprintf(fp, "%s[%u,%d,%d,%d,%u]", i ? "," : "", id, x, y, z, entry[0]);
                            }
                        }
                        fprintf(fp, "]");
                    }
                    fprintf(fp, "}\n");
                    fclose(fp);
                }
                break;
            }
            case RPL_KDOWN: {
                unsigned char sc  = (unsigned char)(ev->a & 0x7F);
                unsigned char asc = (unsigned char)(ev->b & 0xFF);
                g_shift_status = (unsigned short)(ev->c & 0xFFFF);
                if (sc < 128) g_scancode_down[sc] = 1;
                if ((sc != 0 || asc != 0) && sc != 0x2A && sc != 0x36 && sc != 0x1D && sc != 0x38) {
                    keyq_push(((unsigned short)sc << 8) | (unsigned short)asc);
                }
                break;
            }
            case RPL_KUP: {
                unsigned char sc = (unsigned char)(ev->a & 0x7F);
                if (sc < 128) g_scancode_down[sc] = 0;
                g_shift_status = 0;
                break;
            }
            case RPL_SHOT:
                if (ev->str[0]) dsa_save_bmp(ev->str);
                break;
            case RPL_WALKTO:
                g_walkto_x = ev->a;
                g_walkto_z = ev->b;
                g_walkto_deadline = now + (uint32_t)ev->c;
                g_walkto_progress_ms = now;
                g_walkto_best_distance = 1.0e30;
                break;
            case RPL_WALK3D:
                g_replay_walk_end = now + (uint32_t)ev->a;
                rpl_last_check_ms = now;
                rpl_last_wx = *(int *)(&riva_dgroup_base[0x2d308]);
                rpl_last_wz = *(int *)(&riva_dgroup_base[0x2d310]);
                rpl_start_wz = rpl_last_wz >> 16;
                break;
            case RPL_QUIT:
                dsa_platform_shutdown();
#ifdef _WIN32
                ExitProcess((UINT)(g_replay_failure ? g_replay_failure : ev->a));
#else
                exit(g_replay_failure ? g_replay_failure : ev->a);
#endif
                break;
            }
            if (ev->type != RPL_MOVE) {
                break;
            }
        }
        }
    }

    if (autotest_enabled) {
        uint32_t now = g_last_present_ms;
        if (autotest_stage == 0 && now >= 2000) {
            dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot1_menu.bmp");
            g_mouse_x = 110;
            g_mouse_y = 110;
            autotest_stage = 1;
        } else if (autotest_stage == 1 && now >= 2500) {
            g_mouse_buttons = 1;
            g_mouse_latched_down = 1;
            autotest_stage = 2;
        } else if (autotest_stage == 2 && now >= 2700) {
            g_mouse_buttons = 0;
            autotest_stage = 3;
        } else if (autotest_stage == 3 && now >= 3500) {
            dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot3_clicked.bmp");
            g_mouse_x = 302;
            g_mouse_y = 102;
            autotest_stage = 4;
        } else if (autotest_stage == 4 && now >= 3800) {
            g_mouse_buttons = 1;
            g_mouse_latched_down = 1;
            autotest_stage = 5;
        } else if (autotest_stage == 5 && now >= 4000) {
            g_mouse_buttons = 0;
            autotest_stage = 6;
        } else if (autotest_stage == 6 && now >= 4800) {
            dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot4_leave.bmp");
            /* Klick auf "Gespraechsende" (260, 190) */
            g_mouse_x = 260;
            g_mouse_y = 190;
            autotest_stage = 7;
        } else if (autotest_stage == 7 && now >= 5100) {
            g_mouse_buttons = 1;
            g_mouse_latched_down = 1;
            autotest_stage = 8;
        } else if (autotest_stage == 8 && now >= 5300) {
            g_mouse_buttons = 0;
            autotest_stage = 9;
        } else if (autotest_stage == 9 && now >= 6100) {
            /* Zweiter Klick zum Beenden des Abschiedssatzes */
            g_mouse_buttons = 1;
            g_mouse_latched_down = 1;
            autotest_stage = 10;
        } else if (autotest_stage == 10 && now >= 6300) {
            g_mouse_buttons = 0;
            autotest_stage = 11;
        } else if (autotest_stage >= 11 && autotest_stage <= 16) {
            static uint32_t stage_enter_ms = 0;
            static unsigned short stage_start_yaw = 0;
            static uint32_t walk_start_ms = 0;
            static uint32_t last_check_ms = 0;
            static uint32_t last_log_ms = 0;
            static uint32_t turn_until_ms = 0;
            static int turn_dir = 0;
            static int last_wx = 0, last_wz = 0;
            static int start_wz = 0;
            static int stuck_count = 0;
            static int shot_idx = 0;

            int wx = *(int *)(&riva_dgroup_base[0x2d308]);
            int wz = *(int *)(&riva_dgroup_base[0x2d310]);
            unsigned short yaw = *(unsigned short *)(&riva_dgroup_base[0x2dc1e]);
            short cell = *(short *)(&riva_dgroup_base[0x2db3c]);

            if (autotest_stage == 11 && cell > 0 && now >= 7500) {
                /* Blickrichtung nach Verlassen des Travia-Tempels: Osten (O, yaw ~ 0xC000) */
                start_wz = wz >> 16;
                dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot5_city3d.bmp");
                dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot_O.bmp");
                g_scancode_down[0x4b] = 1;
                stage_enter_ms = now;
                stage_start_yaw = yaw;
                autotest_stage = 12;
            } else if (autotest_stage == 12) {
                unsigned short turned = (unsigned short)(yaw - stage_start_yaw);
                if ((turned >= 0x3F00u && turned < 0x8000u) || (now - stage_enter_ms >= 2500)) {
                    g_scancode_down[0x4b] = 0;
                    dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot_N.bmp");
                    g_scancode_down[0x4b] = 1;
                    stage_enter_ms = now;
                    stage_start_yaw = yaw;
                    autotest_stage = 13;
                }
            } else if (autotest_stage == 13) {
                unsigned short turned = (unsigned short)(yaw - stage_start_yaw);
                if ((turned >= 0x3F00u && turned < 0x8000u) || (now - stage_enter_ms >= 2500)) {
                    g_scancode_down[0x4b] = 0;
                    dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot_W.bmp");
                    g_scancode_down[0x4b] = 1;
                    stage_enter_ms = now;
                    stage_start_yaw = yaw;
                    autotest_stage = 14;
                }
            } else if (autotest_stage == 14) {
                unsigned short turned = (unsigned short)(yaw - stage_start_yaw);
                if ((turned >= 0x3F00u && turned < 0x8000u) || (now - stage_enter_ms >= 2500)) {
                    g_scancode_down[0x4b] = 0;
                    dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot_S.bmp");
                    g_scancode_down[0x4b] = 1;
                    stage_enter_ms = now;
                    stage_start_yaw = yaw;
                    autotest_stage = 15;
                }
            } else if (autotest_stage == 15) {
                unsigned short turned = (unsigned short)(yaw - stage_start_yaw);
                if ((turned >= 0x3F00u && turned < 0x8000u) || (now - stage_enter_ms >= 2500)) {
                    g_scancode_down[0x4b] = 0;
                    /* Starte >2-Minuten-Stadtlauf (125 Sekunden durch mehrere Gassen und alle Richtungen, Start nach Osten) */
                    g_scancode_down[0x48] = 1;
                    walk_start_ms = now;
                    last_check_ms = now;
                    last_wx = wx;
                    last_wz = wz;
                    autotest_stage = 16;
                }
            } else if (autotest_stage == 16) {
                /* Vermeide Rueckkehr in die Travia-Tempeltuer bei (-1143, start_wz) waehrend des 2-Minuten-Stadtlaufs */
                int dz_start = (wz >> 16) - start_wz;
                if (dz_start < 0) dz_start = -dz_start;
                if ((wx >> 16) <= -950 && dz_start <= 160 && yaw >= 0x1800u && yaw <= 0x6800u) {
                    turn_dir = 0;
                    turn_until_ms = now + 450;
                }

                if (now < turn_until_ms) {
                    /* Beim Wenden vor Hindernissen auf der Stelle drehen, danach erst wieder 400 ms geradeaus laufen */
                    g_scancode_down[0x48] = (stuck_count > 0) ? 0 : 1;
                    g_scancode_down[0x4b] = (turn_dir == 0) ? 1 : 0;
                    g_scancode_down[0x4d] = (turn_dir == 1) ? 1 : 0;
                    last_check_ms = now;
                    last_wx = wx;
                    last_wz = wz;
                } else {
                    g_scancode_down[0x48] = 1;
                    g_scancode_down[0x4b] = 0;
                    g_scancode_down[0x4d] = 0;
                    if (now - last_check_ms >= 400) {
                        int dx = (wx - last_wx) >> 16;
                        int dz = (wz - last_wz) >> 16;
                        /* Bei 146 Einheiten/s legt die Gruppe in 400 ms ca. 58 Einheiten in der XZ-Ebene zurueck; < 15 heisst Wand/Hindernis */
                        if (dx * dx + dz * dz < 225) {
                            stuck_count++;
                            turn_dir = ((stuck_count % 4) == 0) ? (1 - turn_dir) : turn_dir;
                            turn_until_ms = now + 350 + (stuck_count % 3) * 180;
                        } else {
                            stuck_count = 0;
                            if (((now / 400) % 12) == 0) {
                                turn_dir = ((now / 400) / 12) & 1;
                                turn_until_ms = now + 260;
                            }
                        }
                        last_wx = wx;
                        last_wz = wz;
                        last_check_ms = now;
                    }
                }

                if (now - last_log_ms >= 2000) {
                    FILE *flog = fopen("C:\\Windows\\Temp\\riva_port_build\\walk_test.log", "a");
                    if (flog) {
                        fprintf(flog, "[t=%6.1fs | walk=%5.1fs] cell=%d world=(%d, %d) yaw=0x%04X\n",
                                now / 1000.0, (now - walk_start_ms) / 1000.0, (int)cell, wx >> 16, wz >> 16, (unsigned)yaw);
                        fclose(flog);
                    }
                    last_log_ms = now;
                }

                if (now - walk_start_ms >= (uint32_t)(shot_idx + 1) * 25000u && shot_idx < 5) {
                    char spath[128];
                    shot_idx++;
                    snprintf(spath, sizeof(spath), "C:\\Windows\\Temp\\riva_port_build\\shot_walk_%d.bmp", shot_idx);
                    dsa_save_bmp(spath);
                }

                if (now - walk_start_ms >= 125000) {
                    /* > 125 Sekunden reiner 3D-Stadtlauf erfolgreich abgeschlossen! */
                    g_scancode_down[0x48] = 0;
                    g_scancode_down[0x4b] = 0;
                    g_scancode_down[0x4d] = 0;
                    dsa_save_bmp("C:\\Windows\\Temp\\riva_port_build\\shot6_walked.bmp");
                    autotest_stage = 17;
                    dsa_platform_shutdown();
                    exit(0);
                }
            }
        }
    }
}

void dsa_platform_pump_and_present_if_due(void) {
    static uint32_t s_last_poll_ms = 0;
    uint32_t now;
    if (!g_initialized) {
        dsa_platform_init(NULL, g_width, g_height, NULL);
    }
    now = SDL_GetTicks();
    if (now - s_last_poll_ms >= 2) {
        s_last_poll_ms = now;
        poll_sdl_events_internal();
    }
    if (now - g_last_present_ms >= 16) {
        dsa_platform_present();
    }
}

void dsa_platform_wait_vsync(void) {
    uint32_t before = SDL_GetTicks();
    dsa_platform_present();
    uint32_t elapsed = SDL_GetTicks() - before;
    if (elapsed < 14) {
        SDL_Delay(14 - elapsed);
    }
}

void dsa_platform_set_palette_entry(int index, unsigned char r6, unsigned char g6, unsigned char b6) {
    if (index < 0 || index >= 256) return;
    g_pal_rgb6[index][0] = r6 & 0x3F;
    g_pal_rgb6[index][1] = g6 & 0x3F;
    g_pal_rgb6[index][2] = b6 & 0x3F;
    rebuild_palette_argb(index);
}

void dsa_platform_set_palette_range(int first, int count, const unsigned char *rgb6_triplets) {
    int i;
    if (!rgb6_triplets) return;
    for (i = 0; i < count; ++i) {
        int idx = first + i;
        if (idx >= 0 && idx < 256) {
            g_pal_rgb6[idx][0] = rgb6_triplets[i * 3 + 0] & 0x3F;
            g_pal_rgb6[idx][1] = rgb6_triplets[i * 3 + 1] & 0x3F;
            g_pal_rgb6[idx][2] = rgb6_triplets[i * 3 + 2] & 0x3F;
            rebuild_palette_argb(idx);
        }
    }
    dsa_platform_present();
}

void dsa_platform_get_palette_entry(int index, unsigned char *r6, unsigned char *g6, unsigned char *b6) {
    if (index < 0 || index >= 256) return;
    if (r6) *r6 = g_pal_rgb6[index][0];
    if (g6) *g6 = g_pal_rgb6[index][1];
    if (b6) *b6 = g_pal_rgb6[index][2];
}

void dsa_platform_get_palette_range(int first, int count, unsigned char *rgb6_triplets) {
    int i;
    if (!rgb6_triplets) return;
    for (i = 0; i < count; ++i) {
        int idx = first + i;
        if (idx >= 0 && idx < 256) {
            rgb6_triplets[i * 3 + 0] = g_pal_rgb6[idx][0];
            rgb6_triplets[i * 3 + 1] = g_pal_rgb6[idx][1];
            rgb6_triplets[i * 3 + 2] = g_pal_rgb6[idx][2];
        }
    }
}

void dsa_platform_get_mouse(int *x, int *y, int *buttons) {
    dsa_platform_pump_and_present_if_due();
    if (x) *x = g_mouse_x;
    if (y) *y = g_mouse_y;
    if (buttons) *buttons = g_mouse_buttons;

    /* Nach dem Auslesen gelatchte Kurzklicks freigeben */
    if (g_mouse_latched_down) {
        g_mouse_latched_down = 0;
        if (g_mouse_pending_up) {
            g_mouse_buttons &= ~g_mouse_pending_up;
            g_mouse_pending_up = 0;
        }
    }
}

void dsa_platform_set_mouse_pos(int x, int y) {
    g_mouse_x = x;
    g_mouse_y = y;
    if (g_window) {
        SDL_WarpMouseInWindow(g_window, x, y);
    }
}

void dsa_platform_set_mouse_range_x(int min_x, int max_x) {
    g_mouse_min_x = (min_x < max_x) ? min_x : max_x;
    g_mouse_max_x = (min_x < max_x) ? max_x : min_x;
}

void dsa_platform_set_mouse_range_y(int min_y, int max_y) {
    g_mouse_min_y = (min_y < max_y) ? min_y : max_y;
    g_mouse_max_y = (min_y < max_y) ? max_y : min_y;
}

unsigned short dsa_platform_key_ready(void) {
    dsa_platform_pump_and_present_if_due();
    if (g_key_head == g_key_tail) return 0;
    return g_key_queue[g_key_head];
}

unsigned short dsa_platform_key_read(void) {
    unsigned short k;
    while (g_key_head == g_key_tail) {
        dsa_platform_present();
        SDL_Delay(10);
    }
    k = g_key_queue[g_key_head];
    g_key_head = (g_key_head + 1) % KEY_QUEUE_CAP;
    return k;
}

unsigned short dsa_platform_key_shift_status(void) {
    dsa_platform_pump_and_present_if_due();
    return g_shift_status;
}

unsigned char dsa_platform_get_scancode_state(int dos_scancode) {
    if (dos_scancode < 0 || dos_scancode >= 128) return 0;
    return g_scancode_down[dos_scancode];
}

uint32_t dsa_platform_get_ticks_ms(void) {
    if (!g_initialized) return 0;
    return SDL_GetTicks();
}

uint32_t dsa_platform_get_pit_ticks(void) {
#ifdef _WIN32
    static LARGE_INTEGER s_freq = {0};
    static LARGE_INTEGER s_start = {0};
    LARGE_INTEGER now;
    if (s_freq.QuadPart == 0) {
        QueryPerformanceFrequency(&s_freq);
        QueryPerformanceCounter(&s_start);
    }
    QueryPerformanceCounter(&now);
    uint64_t elapsed = (uint64_t)(now.QuadPart - s_start.QuadPart);
    return (uint32_t)((elapsed * 1193182ULL) / (uint64_t)s_freq.QuadPart);
#else
    return (uint32_t)(SDL_GetTicks() * 1193ULL);
#endif
}

void dsa_platform_delay_ms(uint32_t ms) {
    uint32_t start = dsa_platform_get_ticks_ms();
    int pause_rpl = (ms != 10) ? 1 : 0;
    if (pause_rpl) g_in_delay_ms++;
    while (dsa_platform_get_ticks_ms() - start < ms) {
        dsa_platform_pump_and_present_if_due();
        SDL_Delay(1);
    }
    if (pause_rpl) g_in_delay_ms--;
}
