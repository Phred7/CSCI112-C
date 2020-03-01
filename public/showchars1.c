#include <stdio.h>

int main() {
    char word[20];
    while (scanf("%s", word) == 1) { ;
        printf("word is %s\n", word);
    }
    printf("finished\n");
    return(0);
}

