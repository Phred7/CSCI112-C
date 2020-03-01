#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char array[100],
         nl;

    int i;

    // open input file and output file
    FILE *inpf = NULL,  // initialize to NULL so we can test later
         *outf = stdout; // using stdout for output

    fpos_t pos; // position in file

    char* filename = malloc(50 * sizeof(char));

    // making sure you get a good input file
    strcpy(filename, "alphabet.txt");
    while (inpf == NULL) {
        if ((inpf = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "ERROR: Could not open input file\n");
            printf("Enter new input filename: ");
            scanf("%s", filename);
        }
    }

    // get initial position in input file
    fgetpos(inpf, &pos); 

    // changed to fscanf
    fscanf(inpf, "%c%c", &array[0], &nl);
    for (i = 1; array[i-1] != '0'; i++) {
        fscanf(inpf, "%c%c", &array[i], &nl);
        if (i == 5) {
            fsetpos(inpf, &pos);  // reset back to start of input file
        }
    }
    SelectionSort(array, i);
    for (i = 0; array[i] != '0'; i++) {
        // changed to fprintf
        fprintf(outf, " %c ", array[i]);
    }
    // changed to fprintf
    fprintf(outf, "\n");

    // close the files
    fclose(inpf);

    return(0);
}
