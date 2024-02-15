#!/usr/bin/env python3
from functools import lru_cache
import time


@lru_cache
def archerman(n: int, m: int) -> int:
    """
    A fast increasing recursive function.
    """
    assert isinstance(n, int) and n >= 0, "n must be natural number"
    assert isinstance(m, int) and m >= 0, "m must be natural number"
    if n == 0:
        return m + 1
    elif m == 0:
        return archerman(n - 1, 1)
    else:
        return archerman(n - 1, archerman(n, m - 1))


def archerman_benchmark(n: int, m: int) -> None:
    t0 = time.time_ns()
    try:
        result = archerman(n, m)
    except RecursionError:
        print(f"maximum recursion depth exceeded for archerman({n}, {m})")
        return
    dt = time.time_ns() - t0
    print(f"archerman({n}, {m}) = {result}: {dt} nanoseconds")


def run_benchmark():
    archerman_benchmark(2, 1)
    archerman_benchmark(2, 2)
    archerman_benchmark(3, 2)
    archerman_benchmark(4, 1)


if __name__ == "__main__":
    run_benchmark()