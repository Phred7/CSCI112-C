#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "Blue";
    char *b = "Blue";
    char c[] = {'B', 'l', 'u', 'e', '\0'};

    printf(strcmp(a, b) == 0 ? "Equal\n" : "Not Equal\n");
    printf(strcmp(a, c) == 0 ? "Equal\n" : "Not Equal\n");

    return(0);
}
