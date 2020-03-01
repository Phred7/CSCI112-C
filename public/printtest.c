#include <stdio.h>

int main() {
    char c1, c2, c3;
    printf("This is a test\n");

    // showing how tab looks when used
    printf("\t\tThis is a test\n");

    // showing how to backspace 
    printf("This is a test\b\b\b");
    scanf("%c%c%c", &c1, &c2, &c3);

    //showing how to print a %
    printf("\nprint a %c%%\n", c1);
    return(0);
}
