#include <stdio.h>
#include <string.h>

int main() {
    int i;

    FILE *tfile = fopen("numbers1.txt", "w");

    char* string = "string";
    for (i = 0; i <= 5000; ++i) {
        fprintf(tfile, "%s\n", string);
    }

    fclose(tfile);
    return(0);
}
