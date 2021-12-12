def primes(num_primes: int):
    n: int
    i: int
    len_p: int
    p: list[int] = [0] * 1000

    if num_primes > 1000:
        num_primes = 1000

    len_p = 0  # number of primes in the p array
    n = 2 # primes starts with 2
    while len_p < num_primes:
        for i in p[:len_p]:
            if n % i == 0:
                break   # not a prime
        else:   # find a new prime
            p[len_p] = n
            len_p += 1
        
        n += 1

    resuls = [prime for prime in p[:len_p]]
    return resuls
