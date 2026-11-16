"""Plattformunabhaengiger x86-32-Disassembler-Helfer (nutzt capstone falls installiert,
sonst exakter Pure-Python-Decoder fuer Befehlslaengen, Sprungziele und Watcom-NOP-Fuellung)."""

try:
    import capstone as _cs
    _HAS_CAPSTONE = True
except ImportError:
    _cs = None
    _HAS_CAPSTONE = False


class _Ins:
    __slots__ = ("address", "size", "mnemonic", "bytes")

    def __init__(self, address, size, mnemonic, raw_bytes):
        self.address = address
        self.size = size
        self.mnemonic = mnemonic
        self.bytes = raw_bytes


def _x86_len_and_mnem(buf, pos):
    n = len(buf)
    i = pos
    op_size = 4
    addr_size = 4
    rep = False
    while i < n and buf[i] in (0x26, 0x2E, 0x36, 0x3E, 0x64, 0x65, 0x66, 0x67, 0xF0, 0xF2, 0xF3):
        if buf[i] == 0x66:
            op_size = 2
        elif buf[i] == 0x67:
            addr_size = 2
        elif buf[i] in (0xF2, 0xF3):
            rep = True
        i += 1
    if i >= n:
        return None
    op = buf[i]
    i += 1

    def modrm(idx_pos, addr_sz):
        if idx_pos >= n:
            return None
        m = buf[idx_pos]
        idx_pos += 1
        mod = m >> 6
        rm = m & 7
        if addr_sz == 4:
            if mod != 3 and rm == 4:
                if idx_pos >= n:
                    return None
                sib = buf[idx_pos]
                idx_pos += 1
                if mod == 0 and (sib & 7) == 5:
                    idx_pos += 4
            if mod == 0 and rm == 5:
                idx_pos += 4
            elif mod == 1:
                idx_pos += 1
            elif mod == 2:
                idx_pos += 4
        else:
            if mod == 0 and rm == 6:
                idx_pos += 2
            elif mod == 1:
                idx_pos += 1
            elif mod == 2:
                idx_pos += 2
        return idx_pos if idx_pos <= n else None

    mnem = "other"
    if op == 0x90 and not rep and op_size == 4:
        mnem = "nop"
    elif op in (0xC2, 0xC3):
        mnem = "ret"
    elif op in (0xCA, 0xCB):
        mnem = "retf"
    elif op in (0xE9, 0xEB):
        mnem = "jmp"

    if op == 0x0F:
        if i >= n:
            return None
        op2 = buf[i]
        i += 1
        if 0x80 <= op2 <= 0x8F:
            i += op_size
        elif op2 in (0x06, 0x08, 0x09, 0x0B, 0x30, 0x31, 0x32, 0xA2, 0xAA) or 0xC8 <= op2 <= 0xCF or op2 in (0xA0, 0xA1, 0xA8, 0xA9):
            pass
        elif op2 in (0x70, 0x71, 0x72, 0x73, 0xA4, 0xAC, 0xBA, 0xC2, 0xC4, 0xC5, 0xC6):
            i = modrm(i, addr_size)
            if i is None:
                return None
            i += 1
        else:
            i = modrm(i, addr_size)
            if i is None:
                return None
        return (i - pos, mnem) if i <= n else None

    if (
        op
        in (
            0x06, 0x07, 0x0E, 0x16, 0x17, 0x1E, 0x1F, 0x27, 0x2F, 0x37, 0x3F,
            0x60, 0x61, 0x6C, 0x6D, 0x6E, 0x6F, 0x90, 0x98, 0x99, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
            0xA4, 0xA5, 0xA6, 0xA7, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
            0xC3, 0xC9, 0xCB, 0xCC, 0xCE, 0xCF, 0xD6, 0xD7, 0xEC, 0xED, 0xEE, 0xEF,
            0xF1, 0xF4, 0xF5, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD,
        )
        or (0x40 <= op <= 0x5F)
        or (0x91 <= op <= 0x97)
    ):
        return (i - pos, mnem)
    if (
        (0x70 <= op <= 0x7F)
        or (0xE0 <= op <= 0xE7)
        or op in (0xEB, 0xCD, 0x6A, 0xA8, 0xD4, 0xD5)
        or (0xB0 <= op <= 0xB7)
        or op in (0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C, 0x34, 0x3C)
    ):
        i += 1
        return (i - pos, mnem) if i <= n else None
    if op in (0xC2, 0xCA):
        i += 2
        return (i - pos, mnem) if i <= n else None
    if op == 0xC8:
        i += 3
        return (i - pos, mnem) if i <= n else None
    if op in (0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x3D, 0x68, 0xA9, 0xE8, 0xE9) or (0xB8 <= op <= 0xBF):
        i += op_size
        return (i - pos, mnem) if i <= n else None
    if 0xA0 <= op <= 0xA3:
        i += addr_size
        return (i - pos, mnem) if i <= n else None
    if op in (0x9A, 0xEA):
        i += op_size + 2
        return (i - pos, mnem) if i <= n else None
    if i >= n:
        return None
    reg_op = (buf[i] >> 3) & 7
    if op == 0xFF and reg_op == 4:
        mnem = "jmp"
    i = modrm(i, addr_size)
    if i is None:
        return None
    if op in (0x80, 0x82, 0x83, 0xC0, 0xC1, 0xC6, 0x6B):
        i += 1
    elif op in (0x81, 0xC7, 0x69):
        i += op_size
    elif op == 0xF6 and reg_op in (0, 1):
        i += 1
    elif op == 0xF7 and reg_op in (0, 1):
        i += op_size
    return (i - pos, mnem) if i <= n else None


class _PureDisasm:
    def disasm(self, raw, base=0):
        pos = 0
        n = len(raw)
        while pos < n:
            res = _x86_len_and_mnem(raw, pos)
            if res is None:
                break
            sz, mnem = res
            yield _Ins(base + pos, sz, mnem, raw[pos : pos + sz])
            pos += sz


if _HAS_CAPSTONE:
    MD = _cs.Cs(_cs.CS_ARCH_X86, _cs.CS_MODE_32)
    MD.detail = True
else:
    MD = _PureDisasm()


def _py_nop_ins_len(buf, pos):
    n = len(buf)
    i = pos
    while i < n and buf[i] in (0x26, 0x2E, 0x36, 0x3E, 0x64, 0x65, 0x66):
        i += 1
    if i >= n:
        return 0
    op = buf[i]
    i += 1
    if op == 0x90 and i - pos == 1:
        return 1
    if op in (0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B):
        if i < n and buf[i] in (0xC0, 0xC9, 0xD2, 0xDB, 0xE4, 0xED, 0xF6, 0xFF):
            return i + 1 - pos
        return 0
    if op == 0x8D and i < n:
        m = buf[i]
        i += 1
        mod = m >> 6
        reg = (m >> 3) & 7
        rm = m & 7
        if mod == 3:
            return 0
        base = rm
        if rm == 4:
            if i >= n:
                return 0
            sib = buf[i]
            i += 1
            idx_r = (sib >> 3) & 7
            base = sib & 7
            if idx_r != 4:
                return 0
        if base != reg:
            return 0
        if mod == 0:
            if base == 5:
                return 0
            return i - pos
        if mod == 1:
            if i < n and buf[i] == 0:
                return i + 1 - pos
            return 0
        if mod == 2:
            if i + 4 <= n and buf[i : i + 4] == b"\x00\x00\x00\x00":
                return i + 4 - pos
            return 0
    return 0


def padding(raw):
    if len(raw) > 15:
        return False
    if not any(raw):
        return True
    if _HAS_CAPSTONE:
        ins = list(MD.disasm(raw, 0))
        if sum(i.size for i in ins) != len(raw):
            return False
        for i in ins:
            if not any(raw[i.address :]):
                return True
            op = i.operands
            if i.mnemonic == "nop":
                continue
            if (
                i.mnemonic in ("mov", "xchg")
                and len(op) == 2
                and op[0].type == op[1].type == _cs.x86.X86_OP_REG
                and op[0].reg == op[1].reg
            ):
                continue
            if i.mnemonic == "lea" and len(op) == 2 and op[0].type == _cs.x86.X86_OP_REG and op[1].type == _cs.x86.X86_OP_MEM:
                mem = op[1].mem
                if mem.base == op[0].reg and mem.index in (0, _cs.x86.X86_REG_EIZ) and mem.disp == 0:
                    continue
            return False
        return True
    pos = 0
    while pos < len(raw):
        if not any(raw[pos:]):
            return (len(raw) - pos) % 2 == 0
        l = _py_nop_ins_len(raw, pos)
        if l == 0:
            return False
        pos += l
    return True
