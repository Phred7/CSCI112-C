#include <stdio.h>
#include <string.h>

void decon1subsets(char* str) {

    // base case
    if (strlen(str) == 0) {
        return;
    }
    else {
        // recursive case
        printf("{%c}\n", str[0]);
        decon1subsets(str+1);
  }  
  return;
}

void decon2subsets(char* str) {

    int i;

    // base case
    if (strlen(str) <= 1) {
        return;
    }
    else {
        // recursive case
        for (i = 1; i < strlen(str); ++i) {
            printf("{%c, %c}\n", str[0], str[i]);
        }
        decon2subsets(str+1);
    }
    return;
}
            
void decon3subsets(char* str) {
    int i, j;

    // base case
    if (strlen(str) <= 2) {
        return;
    }
    else {
        // recursive case
        for (i = 1; i < strlen(str)-1; ++i) {
            for (j = i+1; j < strlen(str); ++j) {
                printf("{%c, %c, %c}\n", 
                     str[0], str[i], str[j]);
            }
        }
    
        decon3subsets(str+1);
    }
    return;
}

