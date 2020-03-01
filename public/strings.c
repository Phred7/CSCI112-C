#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} Bool;

Bool isPalindrome(char* s) {

    int i,
        j;
    Bool itis = true;
    for (i = 0, j = strlen(s)-1; i != j && i < j; ++i, --j) {
        if (s[i] != s[j]) {
            itis = false;
            break;
        }
    }
    return itis;
}

int upperChar(char* s) {
    int i, count = 0, size = strlen(s);
    for (i = 0; i < size; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ++count;
        }
    }
    return count;
}

int lowerChar(char* s) {
    int i, count = 0, size = strlen(s);
    for (i = 0; i < size; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ++count;
        }
    }
    return count;
}

char isNumber(char* s) {
    // return n if not a number, i if integer, r if real
    char strtype = 'i';
    int i, size = strlen(s);

    for (i = 0; i < size; ++i) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '.') { 
            strtype = 'n';
            break;
        }
        else if (s[i] == '.' && strtype == 'i') {
            strtype = 'r';
        }
        else if (s[i] == '.' && strtype == 'r') {
            // odd case with two dots - then its a string 
            fprintf(stderr, "ERROR: Found 2 dots in number\n");
            strtype = 'n';
            break;
        }
    }
    return strtype;
}

int main() {
    char *line = malloc(81 * sizeof(char));
    char *str;
    char numtype;
    int size;

    fgets(line, 80, stdin);

    str = strtok(line, " ");
    while (str != NULL) {
        printf("String %s is %sa palindrome.\n", str, 
                  (isPalindrome(str) ? "" : "not "));

        printf("Its first character is %c.\n", str[0]);

        size = strlen(str);
        printf("It is of length %d.\n", size);

        printf("It has %d uppercase letters.\n", upperChar(str));
 
        printf("It has %d lowercase letters.\n\n", lowerChar(str));
        // could also have computed lowercase letters by
        // strlen(str) - upperChar(str)

        str = strtok(NULL, " \n");     
    }

    fgets(line, 80, stdin);
    str = strtok(line, " \n");
    while (str != NULL) {
        numtype = isNumber(str);
        printf("String %s is %sa number.\n", str,
                   (numtype == 'n' ? "not " : ""));
        if (numtype != 'n') {
            printf("It is %s.\n",
                   (numtype == 'i' ? "an integer" : "a real number"));
        }
        str = strtok(NULL, " \n");
        printf("\n");
    }
    return(0);
}
    
