#include <stdio.h>
#include <stdlib.h>

int countDiv(long long n);

int main(void) {
    long long tri_num = 0, current = 0;
    int div_num = 0;

    while (div_num < 500) {
        tri_num += ++current;
        div_num = countDiv(tri_num);
        /* printf("%lld\t%d\n", tri_num, div_num); */
    } 

    printf("%lld\t%d\n", tri_num, div_num);

    return 0;
}

int countDiv(long long n) {
    long long i;
    int cnt = 1;
    int last_idx = 0;
    int *array = (int *)calloc(10000, sizeof(int));

    if (array == 0) {
        printf("calloc error\n");
        exit(1);
    }

    for (i=2; i<=n; i++) {
        while (n % i == 0) {
            n /= i;
            array[last_idx]++;
        }
        last_idx++;
    }

    for (i=0; i<5000; i++) {
        cnt *= (array[i]+1);
    }

    free(array);

    return cnt;
}
