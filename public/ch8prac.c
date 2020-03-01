#include <stdio.h>
#include <string.h>

int main(void) {
    char str[20];

    printf("enter word: ");
    scanf("%s", str);

    int len = strlen(str);
    printf("length of str is %d\n", len);
    printf("%s starts with the letter %c\n", str, str[0]);

    return(0);
}
