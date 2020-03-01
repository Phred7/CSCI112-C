#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char name[5];
    char longname[50] = "Mary Ann Cummings";
    strncpy(name, longname, 5);
    if (strcmp(name, "Mary") == 0) {
        printf("Hello, %s\n", name);
    }
    else {
       printf("did not expect the name %s\n", name);
    }
    return(0);
} 

