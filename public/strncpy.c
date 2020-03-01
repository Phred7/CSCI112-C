#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    // show what happens when you using char* instead
    //
    char string1[26], 
         string2[26];


    printf("Enter a string up to 25 characters\n");
    scanf("%s", string1);

    strncpy(string2, string1, 9);

    string2[9] = '\0';

    // with an array, you need to put the \0 at the end
    //
    printf("string2 is %s\n", string2);
    return(0);
}

