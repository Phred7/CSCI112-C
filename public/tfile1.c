#include <stdio.h>

int main() {
    int i;

    FILE *tfile = fopen("numbers.txt", "w");

    for (i = 0; i <= 500; ++i) {
        
        fprintf(tfile, "%d\n", i);
    }

    fclose(tfile);
    return(0);
}
