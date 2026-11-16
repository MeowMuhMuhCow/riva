from functools import lru_cache
from wlrule import simulate


def inverse(seq, sizes):
    n = len(seq)
    prefix = [0]
    for a in seq:
        prefix.append(prefix[-1] + sizes[a])

    @lru_cache(None)
    def tails(start, previous_first):
        if start == n:
            return ((),)
        out = []
        for end in range(start + 1, n + 1):
            used = prefix[end] - prefix[start]
            if used > 512:
                break
            if previous_first and used + previous_first <= 512:
                continue
            for suffix in tails(end, sizes[seq[start]]):
                out.append(((start, end),) + suffix)
        return tuple(out)

    out = []
    for blocks in tails(0, 0):
        candidate = [a for start, end in reversed(blocks) for a in seq[start:end]]
        if simulate(candidate, sizes, 512) == seq:
            out.append(candidate)
    return out
