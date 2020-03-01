#include <stdio.h>

void Swap(char*, char*);

// Implements the selection sort
// algorithm
void SelectionSort(char arr[], int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (arr[i] < arr[j]) {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

//function to swap two variables
void Swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n = 100;
    char array[n],
         nl;

    int i;

    //scanf("%c%c", &array[0], &nl);
    array[0] = getchar();
    nl = getchar();
    for (i = 1; array[i-1] != '0'; i++) {
        //scanf("%c%c", &array[i], &nl);
        array[i] = getchar();
        nl = getchar();
    }
    SelectionSort(array, i);
    for (i = 0; array[i] != '0'; i++) {
        printf(" %c ", array[i]);
    }
    printf("\n");
    return(0);
}
