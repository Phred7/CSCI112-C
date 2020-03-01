#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2, num3;
    char* str = malloc(81 * sizeof(char));

    printf("enter 3 floating point numbers: ");
    fgets(str, 80, stdin);

    sscanf(str, "%lf %lf %lf", &num1, &num2, &num3);

    printf("The numbers are %.2lf, %.2lf, %.2lf\n", num1, num2, num3);
    return(0);
}
