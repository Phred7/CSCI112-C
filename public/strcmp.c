#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char a[] = "blue";
    char b[] = "black";
    char *c = (char*) malloc(sizeof(char) * 20);
    strcpy(c, "blue");

    char* d = (char*) malloc(sizeof(char) * 20);
    strcpy(d, b);

    if (*a == *b) {
        printf("*a = *b\n");
    }
    else {
        printf("*a=*b not equal\n");
    }
    if (*a == *c) {
        printf("*c=*a\n");
    }
    else {
        printf("*a=*c not equal\n");
    }
    if (*a == *d) {
        printf("*d=*a\n");
    }
    else {
        printf("*a=*d not equal\n");
    }


    if (strcmp(a,b) == 0) {
        printf("*a = *b\n");
    }
    else {
        printf("*a=*b not equal\n");
    }
    if (strcmp(a,c) == 0) {
        printf("*c=*a\n");
    }
    else {
        printf("*a=*c not equal\n");
    }
    if (strcmp(a,d) == 0) {
        printf("*d=*a\n");
    }
    else {
        printf("*a=*d not equal\n");
    }
    return(0);
}



    
