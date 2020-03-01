#include <stdio.h>
#include <string.h>

int main() {
    char line[80];
    char line_copy[80];
    char *token; // what happens if I make token an array?

    printf("Type in a sentence\n");
    fgets(line, 79, stdin);
    // printf("The sentence is: %s\n", line);
    strcpy(line_copy,line);
    //printf("at first line_copy is %s\n", line_copy);
    // break apart the line
    token = strtok(line_copy, " ");
    printf("first token is %s\n", token);
    //printf("line_copy is %s\n", line_copy);
    while ((token = strtok(NULL, " ")) != NULL) {
        printf("Token is %s\n", token);
        //printf("line_copy is now %s\n", line_copy);
    }
    return(0);

}
