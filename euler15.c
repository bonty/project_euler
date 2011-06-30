#include <stdio.h>

int main(void) {
    unsigned long long arr[21][21];
    int i, j;

    for (i =0; i<21; i++) {
        arr[i][0] = 1;
        arr[0][i] = 1;
    }

    for (i=1; i<21; i++) {
        for (j=1; j<21; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    printf("%llu\n", arr[20][20]);
    
    return 0;
}
