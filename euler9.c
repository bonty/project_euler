#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main(void) {
    int i, j;
    int a, b, c;

    for (i = 1; i < 999; i++) {
        a = i;
        for (j = 1; j < 999; j++) {
            b = j;
            c = 1000 - i - j;
            if (isPythagorean(a, b, c))
                printf("%d * %d * %d = %d\n", a, b, c, a * b * c);
        }

    }
    return 0;
}

int isPythagorean(int a, int b, int c) {
    if (a * a + b * b == c * c)
        return TRUE;
    return FALSE;
}
