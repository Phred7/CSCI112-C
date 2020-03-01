#include <stdio.h>

#define NUM 5

void add_arrays(const int a1[], const int a2[], int n, int asum[]) {

    int i;
    for (i = 0; i < n; ++i) {
        asum[i] = a1[i] + a2[i];
    }
    
    return;
}

int main(void) {

    int ar1[] = {1,2,3,4,5};
    int ar2[NUM];
    int arsum[NUM];
    int i;

    for (i = 0; i < NUM; ++i) {
        ar2[i] = ar1[i] * 20;
    }

    add_arrays(ar1, ar2, NUM, arsum);

     for (i = 0; i < NUM; ++i) {
        printf("arsum of %d is %d\n", i, arsum[i]);
    }
    return(0);
}
