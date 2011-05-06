#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

const long tm = 2000000ul;

int main(void) {
    long res = 0;
    long i;

    for (i = 0; i < tm; i++)
        if (isPrime(i))
            res += i;

    printf("%lu\n", res);
    return 0;
}

int isPrime(long n) {
    long i;
    if (n <= 1)
        return FALSE;
    else if (n < 4)
        return TRUE;
    else if (n % 2 == 0)
        return FALSE;
    else if (n < 9)
        return TRUE;
    else if (n % 3 == 0)
        return FALSE;
    else {
        long r = floor(sqrt(n));
        long f = 5;
        while (f <= r) {
            if (n % f == 0)
                return FALSE;
            if (n % (f + 2) == 0)
                return FALSE;
            f += 6;
        }
        return TRUE;
    }
}
