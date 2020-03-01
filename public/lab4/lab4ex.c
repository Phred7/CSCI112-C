#include <stdio.h>

int main(void) {

    int num, i = 0, no_items;

    do {
        no_items = scanf("%d", &num);
        ++i;
        printf("no_items is %d, num is %d\n", no_items, num);
    } while (no_items > 0);
    printf("i is %d\n", i);
    i-- ; // to get the right count of items read 
    printf("final number of things read %d\n", i);

    return(0);
} 
