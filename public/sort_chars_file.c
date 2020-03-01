#include <stdio.h>

void Swap(char*, char*);

// Implements the selection sort
// algorithm
void SelectionSort(char arr[], int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (arr[i] > arr[j]) {
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
    char array[100],
         nl;

    int i;

    // open input file and output file
    FILE *inpf,
         *outf;

    if ((inpf = fopen("alphabet.txt", "r")) == NULL) {
        fprintf(stderr, "ERROR: Could not open input file\n");
        return(1);
    }

    if ((outf = fopen("sorted.txt", "w")) == NULL) {
        fprintf(stderr, "ERROR: Could not open output file\n");
        return(1);
    }


    // changed to fscanf
    fscanf(inpf, "%c%c", &array[0], &nl);
    for (i = 1; array[i-1] != '{'; i++) {
        fscanf(inpf, "%c%c", &array[i], &nl);
    }
    SelectionSort(array, i);
    for (i = 0; array[i] != '{'; i++) {
        // changed to fprintf
        fprintf(outf, " %c ", array[i]);
    }
    // changed to fprintf
    fprintf(outf, "\n");

    // close the files
    fclose(inpf);
    fclose(outf);

    return(0);
}
