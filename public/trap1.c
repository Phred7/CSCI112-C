#include <stdio.h>
#include <string.h>

int main(void) {
    char a[] = "Blue";

    char b[] = "Blue";

    if (strcmp(a,b) == 0) {
        printf("is equal\n");
    }
    else {
        printf("is not equal\n");
    }

    return(0);
}
