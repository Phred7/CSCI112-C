#include <stdio.h>
#include <stdlib.h>

int main() {
    double num;
    char* str = malloc(80 * sizeof(char));

    printf("enter a floating point number: ");
    scanf("%s", str);

    sscanf(str, "%lf", &num);

    printf("The number is %.2lf\n", num);
    return(0);
}
