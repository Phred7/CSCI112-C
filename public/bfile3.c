#include <stdio.h>
#include <string.h>

int main() {

    FILE *bfile = fopen("numbers.bin", "rb");

    
    int arr[501]; 

    fread(arr, sizeof(int), 501, bfile);

    fclose(bfile);

    printf("%d %d\n", arr[20], arr[100]);
    return(0);
}
