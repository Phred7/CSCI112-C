#include <stdio.h>

void printArrays(int*, int*, int);

int read_array(int a[], int b[]) {

    int i = 0, no_items;

    do {
        no_items = scanf("%d %d", &a[i], &b[i]);
        i++;
    } while (no_items > 0);
    printf("i is %d\n", i);
    i-- ; // to get the right count of items read 
    printf("final number of things read %d\n", i);

    return(i);
} 

int main(void) {
    int arr1[20], arr2[20];

    int n = read_array(arr1, arr2);

    printf("number of items in array is %d\n", n);
    printArrays(arr1, arr2, n);

    return(0);
}

void printArrays(int *a, int *b, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("arr1[%d] is %d, arr2[%d] is %d\n", i, a[i], i, *(b+i));
    }
    return;
}
