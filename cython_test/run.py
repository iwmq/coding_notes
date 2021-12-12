import pyximport; pyximport.install(language_level=3) # compile Cython

import time
import primes_cython
import primes_python


def run(primes_func):
    start = time.time()
    _ = primes_func(1000)
    end = time.time()
    return end - start

def main():
    elapsed_cython = run(primes_cython.primes) * 1000
    print("Cython version of primes, elapsed time: {:0.2f} ms".format(elapsed_cython))

    elapsed_python = run(primes_python.primes) * 1000
    print("Python version of primes, elapsed time: {:0.2f} ms".format(elapsed_python))

    speed_up = elapsed_python // elapsed_cython
    print("Speed of Cython vs pure Python: {}X".format(speed_up))
    # The speed_up is about 21X

if __name__ == "__main__":
    main()