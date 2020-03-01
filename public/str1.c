#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = (char*)malloc(50 * sizeof(char));
    printf("enter string\n");
    scanf("%s", str);
    printf("str is %-8srightbehind it\n", str);
    return(0);
}
