def primes(int num_primes):
    cdef int n, i, len_p
    cdef int p[1000]

    # Should be to large, as C allocates memory in stack for the array
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
    
    # Copy to Python list
    resuls = [prime for prime in p[:len_p]]
    return resuls
