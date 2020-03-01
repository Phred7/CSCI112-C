#include <stdio.h>

int read_array(int a[]) {

    int i = 0, no_items;

    do {
        no_items = scanf("%d", &a[i]);
        printf("no_items is %d, a[i] is %d\n", no_items, a[i]);
        i++;
    } while (no_items > 0);
    printf("i is %d\n", i);
    i-- ; // to get the right count of items read 
    printf("final number of things read %d\n", i);

    return(i);
} 

int main(void) {
    int arr[20];

    int n = read_array(arr);

    printf("number of items in array is %d\n", n);
    return(0);
}
