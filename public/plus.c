#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* plus = "+++++++++++++++++++++++++++++++++++++++++++++++";
    char* len_plus = (char*) malloc(sizeof(char) * 80);
    int num;
 
    while (1) {
        printf("Enter number of plusses, or -1 to quit: ");
        scanf("%d", &num);
    
        if (num == -1) {
            break;
        }

        memset(len_plus, '\0', 80);
        strncpy(len_plus, plus, num);

        printf("%s\n", len_plus);

    }
    return(0);
}

        
