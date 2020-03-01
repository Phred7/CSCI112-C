#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkPalindrome(char* str) {
    if (strlen(str) == 0 || strlen(str) == 1) {
        return 0; 
    }
    else if (str[0] == str[strlen(str)-1]) {
        str[strlen(str) - 1] = '\0';
        return (0 + checkPalindrome(str+1));
    }
    else {
        return 1;
    }
}
    

int main(void) {

    char word[30] ,
         word_copy[30];

    int result,
        stop = 0;
    do { 
        printf("Enter word to check: ");
        scanf("%s", word);

        if ((strcmp(word,"STOP") == 0 || 
            strcmp(word,"stop") == 0 || 
            strcmp(word,"Stop") == 0) ) {
            stop = 1; 
        }
        else if (strcmp(word, "BAD") == 0) {
            exit(1);
        }
        else {
            
            strcpy(word_copy, word);
            result = checkPalindrome(word_copy);
            printf("string %s is %sa palindrome\n",
                     word, (result == 0 ? "" : "not "));
            memset(word_copy,'\0', 30);
        }
    } while (!stop);
    return(0);
}
