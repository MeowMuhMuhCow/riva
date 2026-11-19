#!/usr/bin/env python3
"""
vergleich.py (Werkzeug W5) - Referenzvergleich zwischen Original (DOSBox) und Windows-Port.

Liest zwei Bilder (.bmp oder .png, ohne externe Abhaengigkeiten wie PIL/Pillow),
skaliert sie bei Bedarf auf die Referenzaufloesung (Standard 320x200), berechnet:
  - Exakte Pixel-Uebereinstimmung (%)
  - VGA-6-Bit-tolerante Uebereinstimmung (|dR|,|dG|,|dB| <= 4, %)
  - Mittlere absolute RGB-Abweichung (MAE in %)
  - Quadratischer Mittelwert der Abweichung (RMSE in %)
und erzeugt ein Differenzbild (.png), in dem Abweichungen farblich hervorgehoben sind.
"""

from __future__ import annotations

import argparse
import math
import struct
import sys
import zlib
from pathlib import Path


def read_bmp(data: bytes) -> tuple[int, int, list[tuple[int, int, int]]]:
    if len(data) < 54 or data[:2] != b"BM":
        raise ValueError("Ungueltige BMP-Datei")
    off = struct.unpack_from("<I", data, 10)[0]
    w = struct.unpack_from("<i", data, 18)[0]
    h = struct.unpack_from("<i", data, 22)[0]
    bpp = struct.unpack_from("<H", data, 28)[0]
    top_down = h < 0
    h = abs(h)
    pixels: list[tuple[int, int, int]] = [(0, 0, 0)] * (w * h)

    if bpp == 24:
        stride = (w * 3 + 3) & ~3
        for y in range(h):
            sy = y if top_down else (h - 1 - y)
            row_off = off + sy * stride
            for x in range(w):
                b, g, r = data[row_off + x * 3 : row_off + x * 3 + 3]
                pixels[y * w + x] = (r, g, b)
    elif bpp == 32:
        stride = w * 4
        for y in range(h):
            sy = y if top_down else (h - 1 - y)
            row_off = off + sy * stride
            for x in range(w):
                b, g, r = data[row_off + x * 4 : row_off + x * 4 + 3]
                pixels[y * w + x] = (r, g, b)
    elif bpp == 8:
        hdr_sz = struct.unpack_from("<I", data, 14)[0]
        pal_off = 14 + hdr_sz
        pal = []
        for i in range(256):
            b, g, r, _ = data[pal_off + i * 4 : pal_off + i * 4 + 4]
            pal.append((r, g, b))
        stride = (w + 3) & ~3
        for y in range(h):
            sy = y if top_down else (h - 1 - y)
            row_off = off + sy * stride
            for x in range(w):
                idx = data[row_off + x]
                pixels[y * w + x] = pal[idx]
    else:
        raise ValueError(f"Nicht unterstuetzte BMP-Farbtiefe: {bpp} bpp")
    return w, h, pixels


def paeth(a: int, b: int, c: int) -> int:
    p = a + b - c
    pa = abs(p - a)
    pb = abs(p - b)
    pc = abs(p - c)
    if pa <= pb and pa <= pc:
        return a
    if pb <= pc:
        return b
    return c


def read_png(data: bytes) -> tuple[int, int, list[tuple[int, int, int]]]:
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError("Ungueltige PNG-Signatur")
    pos = 8
    w = h = bit_depth = color_type = 0
    plte: list[tuple[int, int, int]] = []
    idat_chunks: list[bytes] = []

    while pos + 8 <= len(data):
        length = struct.unpack_from(">I", data, pos)[0]
        ctype = data[pos + 4 : pos + 8]
        cbody = data[pos + 8 : pos + 8 + length]
        pos += 12 + length
        if ctype == b"IHDR":
            w, h, bit_depth, color_type, _, _, _ = struct.unpack(">IIBBBBB", cbody[:13])
        elif ctype == b"PLTE":
            for i in range(0, len(cbody), 3):
                plte.append((cbody[i], cbody[i + 1], cbody[i + 2]))
        elif ctype == b"IDAT":
            idat_chunks.append(cbody)
        elif ctype == b"IEND":
            break

    raw = zlib.decompress(b"".join(idat_chunks))
    if color_type == 2:
        bpp = 3
    elif color_type == 6:
        bpp = 4
    elif color_type == 3:
        bpp = 1
    elif color_type == 0:
        bpp = 1
    else:
        raise ValueError(f"Nicht unterstuetzter PNG-Farbtyp: {color_type}")

    stride = w * bpp
    recon = bytearray(h * stride)
    in_pos = 0
    for y in range(h):
        ftype = raw[in_pos]
        in_pos += 1
        row = raw[in_pos : in_pos + stride]
        in_pos += stride
        out_off = y * stride
        prev_off = (y - 1) * stride
        for i in range(stride):
            x_val = row[i]
            a = recon[out_off + i - bpp] if i >= bpp else 0
            b = recon[prev_off + i] if y > 0 else 0
            c = recon[prev_off + i - bpp] if (y > 0 and i >= bpp) else 0
            if ftype == 0:
                recon[out_off + i] = x_val
            elif ftype == 1:
                recon[out_off + i] = (x_val + a) & 0xFF
            elif ftype == 2:
                recon[out_off + i] = (x_val + b) & 0xFF
            elif ftype == 3:
                recon[out_off + i] = (x_val + ((a + b) >> 1)) & 0xFF
            elif ftype == 4:
                recon[out_off + i] = (x_val + paeth(a, b, c)) & 0xFF

    pixels: list[tuple[int, int, int]] = [(0, 0, 0)] * (w * h)
    for y in range(h):
        out_off = y * stride
        for x in range(w):
            if color_type == 2:
                o = out_off + x * 3
                pixels[y * w + x] = (recon[o], recon[o + 1], recon[o + 2])
            elif color_type == 6:
                o = out_off + x * 4
                pixels[y * w + x] = (recon[o], recon[o + 1], recon[o + 2])
            elif color_type == 3:
                idx = recon[out_off + x]
                pixels[y * w + x] = plte[idx] if idx < len(plte) else (0, 0, 0)
            elif color_type == 0:
                v = recon[out_off + x]
                pixels[y * w + x] = (v, v, v)
    return w, h, pixels


def load_image(path: Path) -> tuple[int, int, list[tuple[int, int, int]]]:
    data = path.read_bytes()
    if data[:2] == b"BM":
        return read_bmp(data)
    if data[:8] == b"\x89PNG\r\n\x1a\n":
        return read_png(data)
    raise ValueError(f"Unbekanntes Bildformat in {path}")


def write_png(path: Path, w: int, h: int, pixels: list[tuple[int, int, int]]) -> None:
    raw_rows = []
    for y in range(h):
        row = bytearray(1 + w * 3)
        row[0] = 0
        base = y * w
        for x in range(w):
            r, g, b = pixels[base + x]
            row[1 + x * 3 : 1 + x * 3 + 3] = bytes((r, g, b))
        raw_rows.append(bytes(row))
    raw = b"".join(raw_rows)

    def chunk(tag: bytes, body: bytes) -> bytes:
        return (
            struct.pack(">I", len(body))
            + tag
            + body
            + struct.pack(">I", zlib.crc32(tag + body) & 0xFFFFFFFF)
        )

    ihdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)
    png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", ihdr) + chunk(b"IDAT", zlib.compress(raw, 6)) + chunk(b"IEND", b"")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(png)


def resample_nearest(
    w_src: int, h_src: int, px_src: list[tuple[int, int, int]], w_dst: int, h_dst: int
) -> list[tuple[int, int, int]]:
    if w_src == w_dst and h_src == h_dst:
        return px_src
    out = [(0, 0, 0)] * (w_dst * h_dst)
    for y in range(h_dst):
        sy = (y * h_src) // h_dst
        for x in range(w_dst):
            sx = (x * w_src) // w_dst
            out[y * w_dst + x] = px_src[sy * w_src + sx]
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description="Bildvergleich Original (DOSBox) vs. Port (W5)")
    ap.add_argument("bild_a", type=Path, help="Referenzbild (z. B. DOSBox-Original .png/.bmp)")
    ap.add_argument("bild_b", type=Path, help="Vergleichsbild (z. B. RIVA_PORT .png/.bmp)")
    ap.add_argument("--diff", type=Path, default=None, help="Ausgabepfad fuer das Differenzbild (.png)")
    ap.add_argument("--ignore-y-ge", type=int, default=None, help="Optional: ignoriere Zeilen y >= N (z. B. UI-Leiste)")
    args = ap.parse_args()

    w1, h1, px1 = load_image(args.bild_a)
    w2, h2, px2 = load_image(args.bild_b)

    if (w1, h1) != (w2, h2):
        px2 = resample_nearest(w2, h2, px2, w1, h1)
        w2, h2 = w1, h1

    diff_px: list[tuple[int, int, int]] = [(0, 0, 0)] * (w1 * h1)
    total_compared = 0
    exact_match = 0
    vga6_match = 0
    abs_err_sum = 0.0
    sq_err_sum = 0.0

    max_y = args.ignore_y_ge if (args.ignore_y_ge is not None and args.ignore_y_ge <= h1) else h1

    for y in range(h1):
        for x in range(w1):
            idx = y * w1 + x
            r1, g1, b1 = px1[idx]
            r2, g2, b2 = px2[idx]
            dr = abs(r1 - r2)
            dg = abs(g1 - g2)
            db = abs(b1 - b2)
            if y < max_y:
                total_compared += 1
                if dr == 0 and dg == 0 and db == 0:
                    exact_match += 1
                if dr <= 4 and dg <= 4 and db <= 4:
                    vga6_match += 1
                err = (dr + dg + db) / (3.0 * 255.0)
                abs_err_sum += err
                sq_err_sum += (dr * dr + dg * dg + db * db) / (3.0 * 255.0 * 255.0)

            if dr <= 4 and dg <= 4 and db <= 4:
                diff_px[idx] = (r2 // 3, g2 // 3, b2 // 3)
            else:
                mag = min(255, (dr + dg + db) * 2)
                diff_px[idx] = (255, max(0, 255 - mag), min(255, mag))

    diff_path = args.diff or args.bild_b.with_name(args.bild_b.stem + "_diff.png")
    write_png(diff_path, w1, h1, diff_px)

    if total_compared == 0:
        total_compared = 1
    exact_pct = (exact_match * 100.0) / total_compared
    vga6_pct = (vga6_match * 100.0) / total_compared
    mae_pct = (abs_err_sum * 100.0) / total_compared
    rmse_pct = math.sqrt(sq_err_sum / total_compared) * 100.0

    print("========================================================================")
    print("DSA 3: Schatten ueber Riva - Bildvergleich (Werkzeug W5: vergleich.py)")
    print("========================================================================")
    print(f"Referenzbild A:       {args.bild_a} ({w1}x{h1})")
    print(f"Vergleichsbild B:     {args.bild_b} ({w2}x{h2})")
    print(f"Verglichene Pixel:    {total_compared} (Zeilen 0..{max_y - 1})")
    print(f"Exakt gleich:         {exact_match} / {total_compared} ({exact_pct:.2f} %)")
    print(f"VGA-6Bit-gleich:      {vga6_match} / {total_compared} ({vga6_pct:.2f} %)")
    print(f"Abweichung (MAE):     {mae_pct:.2f} %")
    print(f"Abweichung (RMSE):    {rmse_pct:.2f} %")
    print(f"Differenzbild:        {diff_path}")
    print("========================================================================")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
