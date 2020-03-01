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

int main(int argc, char** argv) {

    // get command line argument - string to decompose
    if (argc != 2) {
        printf("ERROR: wrong number of arguments\n");
        return(1);
    }

    // check size of string and print error msg and exit if not 4
    if (strlen(argv[1]) != 4) {
        printf("ERROR: input string must be 4 characters\n");
        return(1);
    }

    printf("one_ele_subs\n");
    printf("(\"%s\")\n", argv[1]);

    decon1subsets(argv[1]);

    printf("two_ele_subs\n");
    printf("(\"%s\")\n", argv[1]);

    decon2subsets(argv[1]);

    printf("three_ele_subs\n");
    printf("(\"%s\")\n", argv[1]);

    decon3subsets(argv[1]);

    return(0);
}

