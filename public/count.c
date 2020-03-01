#include <stdio.h>

int count(char* str, char c) {
    int num;
    if (str[0] == '\0') {
        num = 0;
    }
    else {
        if (c == str[0]) {
            num = 1 + count(&str[1], c);
        }
        else {
            num = count(&str[1], c);
        }
    }
    return num;
}

int main(int argc, char** argv) {
    int numchars;

    if (argc != 3) {
        printf("wrong number of arguments\n");
        return(1);
    }
    numchars = count(argv[1], argv[2][0]);
    printf("The number of times %c appears in %s is %d\n", 
            argv[2][0], argv[1], numchars);
    return(0);
}
