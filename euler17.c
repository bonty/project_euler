#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dict[] = {
    "","one","two","three","four","five","six","seven","eight",
    "nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen","twenty","thirty",
    "forty","fifty","sixty","seventy","eighty","ninety","hundred",
    "thousand"
};

int main(void) {
    char *letter;
    letter = (char *)malloc(10000*sizeof(char));

    int i;

    for (i=1; i<=1000; i++) {
        int tmp = i;
        int tmp1 = tmp % 100;

        char *tmplet;
        tmplet = (char *)malloc(100*sizeof(char));

        if (tmp1 <= 20) {
            strcat(tmplet, dict[tmp1]);
        }
        else {
            int tmp2 = tmp1 % 10;
            strcat(tmplet, dict[tmp2]);
            tmp1 = (tmp1/10) % 10;
            strcat(tmplet, dict[tmp1+18]);
        }

        tmp /= 100;
        int idx = 28;

        do {
            tmp1 = tmp % 10;
            
            if (tmp1 != 0) {
                if (strlen(tmplet) > 0) {
                    strcat(tmplet, "and");
                }
                strcat(tmplet, dict[tmp1]);
                strcat(tmplet, dict[idx]);
            }
            idx++;
            tmp /= 10;
        } while (tmp > 0);

        /* printf("%d %lu %s\n", i, strlen(tmplet), tmplet); */
        strcat(letter, tmplet);
    }

    printf("%lu\n", strlen(letter));
    
    return 0;
}
