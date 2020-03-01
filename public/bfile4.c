#include <stdio.h>
#include <string.h>

int main() {

    FILE *bfile = fopen("numbers1.bin", "rb");

    
    char arr[5001][7]; 

    fread(arr, 7, 5001, bfile);

    fclose(bfile);

    printf("%s %s\n", arr[20], arr[100]);
    return(0);
}
