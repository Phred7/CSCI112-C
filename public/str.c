#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = malloc(20 * sizeof(char));
    // char str[20];
    printf("enter string\n");
    scanf("%s", str);
    printf("str is %s\n", str);
    return(0);
}
