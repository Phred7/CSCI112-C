#include <stdio.h>
#include <string.h>

int main() {
    int i;

    FILE *bfile = fopen("numbers1.bin", "wb");

    char* string = "string";
    for (i = 0; i <= 5000; ++i) {
        // add 1 to strlen to allow for the \0
        fwrite(string, strlen(string) + 1, 1, bfile);
    }

    fclose(bfile);
    return(0);
}
