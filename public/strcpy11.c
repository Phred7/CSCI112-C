#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char name[20]
    strcpy(name, "Mary");
    // strcpy(name, "Mary");

    // don't do name = "Mary";
    //
    if (strcmp(name, "Mary") == 0) {
        printf("Hello, %s\n", name);
    }
    else {
       printf("did not expect the name %s\n", name);
    }
    return(0);
} 
