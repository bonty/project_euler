#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    int *btree;
    int i, j, a;

    if ((fp = fopen("euler18.dat", "r")) == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    btree =(int *)malloc(130*sizeof(int));
    int *p = btree;

    for (i=0; i<120; i++) {
        fscanf(fp, "%d", &a);
        *p++ = a;
    }

    for (i=15; i>1; i--) {
        a = (i+1)*i/2;

        for (j=a-1; j>a-i; j--) {
            if (btree[j] > btree[j-1]) {
                btree[j-i] += btree[j];
            }
            else {
                btree[j-i] += btree[j-1];
            }
        }

        /* for (j=a-1; j>=a-i; j--) */
        /*     printf("%d ", *(btree+j)); */
        /* printf("\n"); */
    }

    printf("%d\n", *btree);
    
    
    return 0;
}
