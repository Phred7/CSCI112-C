#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buildEquation(char* str, int num) {

    int i;

    str[0] = num + 48;

    strcat(str, " = ");

    for (i = 1; i < num; ++i) {
        strcat(str, "1 + ");
    }
    strcat(str, "1");
    return;
}
         
int main(void) {
    char* str = (char*) malloc(sizeof(char) * 80);
    int num;

    while (1) {

        printf("Enter a number, -1 to quit: ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }
        memset(str, '\0', 80);
        buildEquation(str, num);
        printf("str is %s\n", str);
    }
    return (0);
}


    
