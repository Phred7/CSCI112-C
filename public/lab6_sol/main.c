#include <stdio.h>
#include <string.h>
#include "decon.h"

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

