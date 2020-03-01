#include <stdio.h>

int main(void) {
    char a[] = "Blue";

    char b[] = "Blue";

    if (*a == *b) {
        printf("is equal\n");
    }
    else {
        printf("is not equal\n");
    }

    return(0);
}
