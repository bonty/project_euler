#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long U64;

#define FALSE 0
#define TRUE 1

/* primes up to 256 */
static U64 seed_primes[]  = {
    /*0,1,2,3, 4, 5, 6, 7 */
    2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,
    101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,
    191,193,197,199,211,223,227,229,233,239,241,251, 0
};

int isPrime(U64 n);
int millerRabin(U64 a, U64 s, U64 d, U64 n);
U64 powmod(U64 a, U64 d, U64 n);


int main(int argc, char **argv) {
    U64 check_num = 1;
    U64 result;
    int idx = 0;

    while (idx < 10001) {
        if (isPrime(check_num)) {
            result = check_num;

            idx++;
        }
        check_num++;
    }
    printf("%d\t%lld\n", idx, result);

    return 0;
}

int millerRabin(U64 a, U64 s, U64 d, U64 n) {
    U64 r, x = powmod(a, d, n);
    if (x == 1)
        return FALSE;

    for (r = 0; r < s; r++) {
        if (x == n - 1)
            return FALSE;
        x = (x * x) % n;
    }
    return TRUE;
}

int isPrime(U64 n) {
    if (n <= 1)
        return FALSE;
    if ((n & 1) == 0)
        return n == 2;

    int i;
    for (i = 0; seed_primes[i]; i++) {
        if (n == seed_primes[i])
            return TRUE;
        if (n % seed_primes[i] == 0)
            return FALSE;
    }

    U64 d = n - 1, s = 0;
    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }

    for (i = 0; i < 7; i++) {
        if (millerRabin(seed_primes[i], s, d, n))
            return FALSE;
    }
    return TRUE;
}

U64 powmod(U64 base, U64 power, U64 mod) {
    U64 result = 1;
    while (power > 0) {
        if (power & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

