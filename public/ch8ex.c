#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char* mystr = (char*)malloc(sizeof(char) * 80);

    strcat(mystr, "this ");
    strcat(mystr, "is ");
    strcat(mystr, "an ");
    strcat(mystr, "example.");

    printf("mystr is %s\n", mystr);

    return(0);
}
