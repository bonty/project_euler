#include <stdio.h>

void twice(int *n) {
    int i, flag = 0;

    for (i=0; i<500; i++) {
        int tmp = n[i] * 2 + flag;
        
        if (tmp >= 10) {
            n[i] = tmp % 10;
            flag = 1;
        }
        else {
            n[i] = tmp;
            flag = 0;
        }
    }

    /* for (i=0; i<500; i++) */
    /*     printf("%d", n[i]); */
    /* printf("\n"); */
}

int main(void) {
    int arr[500] = {0};
    int i, j, res = 0;

    arr[0] = 1;

    for (i=0; i<1000; i++) {
        twice(arr);

        for (j=499; arr[j] == 0; j--);
        /* for (; j>=0; j--) { */
        /*     printf("%d", arr[j]); */
        /* } */
        /* printf("\n"); */

        /* res = 0; */
        /* for (j=0; j<500; j++) { */
        /*     res += arr[j]; */
        /* } */
        /* printf("%d\t%d\n", i+1, res); */
    }

    for (i=0; i<500; i++) {
        res += arr[i];
    }
    printf("%d\n", res);
    
    return 0;
}
