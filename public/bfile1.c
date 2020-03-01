#include <stdio.h>

int main() {
    int i;

    FILE *bfile = fopen("numbers.bin", "wb");

    for (i = 0; i <= 500; ++i) {
        fwrite(&i, sizeof(int), 1, bfile);
    }

    fclose(bfile);
    return(0);
}
