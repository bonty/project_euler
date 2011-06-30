#include <stdio.h>
#include <stdlib.h>

#define MILLION 1000000
typedef unsigned long long ull;

int *cache;

ull even(ull n) {
    return n / 2;
}

ull odd(ull n) {
    return 3 * n + 1;
}

ull getChain(ull n) {
    ull res;
    /* printf("%llu\n", n); */
    
    if (n == 1) {
        return 1;
    }

    if (n <= MILLION*3 && cache[n] > 0) {
        return cache[n];
    }

    res = n%2 == 0 ? getChain(even(n)) + 1 : getChain(odd(n)) + 1;

    if (n <= MILLION*3) {
        cache[n] = res;
    }

    return res;
}

int main(void) {
    ull i;
    int max = 0;
    int max_i = 0;
    cache = (int *)calloc(MILLION*3, sizeof(int));

    for (i=1; i<=MILLION; i++) {
        int tmp = getChain(i);
        if (tmp > max) {
            max = tmp;
            max_i = i;
        }
        /* printf("%llu\t%d\n", i, tmp); */
    }

    printf("%d\n", max_i);
    
    return 0;
}
