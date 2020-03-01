#include <stdio.h>

int main(int argc, char** argv) {

    //pull the first character off
    //find the connecting class of that character
    printf("argv[1] is %s\n", argv[1]);
    switch (argv[1][0]) {
    case 'B':
    case 'b': 
        printf("The ship %s is a battleship\n", argv[1]);
        break;
    case 'C':
    case 'c': 
        printf("The ship %s is a cruiser\n", argv[1]);
        break;
    default:
        printf("ERROR: bad ship id %s\n", argv[1]);
    }
    return(0);
}
