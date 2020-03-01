#include <stdio.h>
typedef enum {false, true} Bool;

Bool is_even(unsigned int);
Bool is_odd(unsigned int);

Bool is_even(unsigned int n) {
    Bool answer;
    if (n == 0) {
         return true;
    }
    else {
        answer = is_odd(n - 1);
    }
    return answer;
} 

Bool is_odd(unsigned int n) {
    Bool answer;
    if (n == 0) {
        answer = false;
    }
    else {
        answer = is_even(n - 1);
    }
    return answer;
}

int main(int argc, char** argv) {
    int num;

    printf("argc is %d\n", argc);
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        return(1); 
    }
    else {
        sscanf(argv[argc-1], "%d", &num);
        printf("num is %d\n", num); 
        if (num < 0) {
            printf("Number must not be negative\n");
            return(1);
        }
        printf("%d is %s even\n", num, (is_even(num) ? "" : "not "));
        return(0);
    }
}
    
