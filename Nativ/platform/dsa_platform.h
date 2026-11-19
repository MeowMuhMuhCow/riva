/*
 * dsa_platform.h - Gemeinsame Plattformschnittstelle fuer die Nordlandtrilogie
 *   - DSA 1: Die Schicksalsklinge (320x200, 256 Farben)
 *   - DSA 2: Sternenschweif       (320x200 / SVGA, 256 Farben)
 *   - DSA 3: Schatten ueber Riva  (320x200 & 640x480/640x400 SVGA, 256 Farben)
 *
 * Kapselt Grafik (8-Bit-Framebuffer + 256-Farben-VGA-DAC-Palette -> SDL2-Textur),
 * Maus- und Tastatureingaben (DOS Int 0x33 / BIOS Int 0x16 / Scancode-Matrix),
 * Zeitgeber (PIT-Ticks) sowie Dateipfad-Aufloesung relativ zum Spielverzeichnis.
 */

#ifndef DSA_PLATFORM_H
#define DSA_PLATFORM_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DSA_MAX_VRAM_WIDTH   640
#define DSA_MAX_VRAM_HEIGHT  480
#define DSA_VRAM_SIZE        (DSA_MAX_VRAM_WIDTH * DSA_MAX_VRAM_HEIGHT)

/* Initialisierung & Lebenszyklus */
int  dsa_platform_init(const char *window_title, int width, int height, const char *game_dir);
void dsa_platform_shutdown(void);
void dsa_platform_pump_and_present_if_due(void);

/* Grafikmodus & 8-Bit-Framebuffer */
void           dsa_platform_set_mode(int dos_mode, int width, int height);
int            dsa_platform_get_width(void);
int            dsa_platform_get_height(void);
unsigned char *dsa_platform_get_vram(void);
void           dsa_platform_present(void);
void           dsa_platform_wait_vsync(void);
void           dsa_platform_toggle_fullscreen(void);

/* 256-Farben VGA-DAC-Palette (6-Bit-Komponenten 0..63) */
void dsa_platform_set_palette_entry(int index, unsigned char r6, unsigned char g6, unsigned char b6);
void dsa_platform_set_palette_range(int first, int count, const unsigned char *rgb6_triplets);
void dsa_platform_get_palette_entry(int index, unsigned char *r6, unsigned char *g6, unsigned char *b6);
void dsa_platform_get_palette_range(int first, int count, unsigned char *rgb6_triplets);

/* Maus (DOS Int 0x33 kompatibel) */
void dsa_platform_get_mouse(int *x, int *y, int *buttons);
void dsa_platform_set_mouse_pos(int x, int y);
void dsa_platform_set_mouse_range_x(int min_x, int max_x);
void dsa_platform_set_mouse_range_y(int min_y, int max_y);

/* Tastatur (BIOS Int 0x16 & Int 0x09 Scancode-Tabelle kompatibel) */
unsigned short dsa_platform_key_ready(void);
unsigned short dsa_platform_key_read(void);
unsigned short dsa_platform_key_shift_status(void);
unsigned char  dsa_platform_get_scancode_state(int dos_scancode);

/* Zeitgeber */
uint32_t dsa_platform_get_ticks_ms(void);
uint32_t dsa_platform_get_pit_ticks(void);
void     dsa_platform_delay_ms(uint32_t ms);
void     riva_pump_timers_and_events(void);
void     riva_log_zeile_zeiten(const char *line);

/* Dateipfad-Aufloesung relativ zum konfigurierbaren Spielordner */
void        dsa_platform_set_game_dir(const char *path);
const char *dsa_platform_get_game_dir(void);
void        dsa_platform_set_save_dir(const char *path);
const char *dsa_platform_get_save_dir(void);
int         dsa_platform_is_save_dir_redirected(void);
const char *dsa_platform_resolve_path(const char *dos_path, char *out_buf, size_t out_size);

/* Werkzeug W4: Eingabe-Aufzeichnung (--record) & deterministische Wiedergabe (--replay) */
void dsa_platform_set_record_file(const char *path);
void dsa_platform_set_replay_file(const char *path);

#ifdef __cplusplus
}
#endif

#endif /* DSA_PLATFORM_H */
