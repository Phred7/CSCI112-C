#include <stdio.h>

int divisibleByNine(int n) {
   
    int digit,
        sum = 0;

    // pull off each digit of n by using %10
    while (n > 9) {
        digit = n%10;

        // add that digit to the running sum
        sum += digit;

        // pull that digit out of n by dividing n by 10
        n /= 10;

    }
    sum += n;

    // return 1 if sum%9 = 0, else 0
    if (sum%9 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char** argv) {

     int flag,
         num;

     if (argc != 2) {
        printf("ERROR: wrong number of parameters\n");
        return(1);
     }

     sscanf(argv[1], "%d", &num);

     // convert argument[1] to a integer

    flag = divisibleByNine(num);
    
    // print the result: is it divisible by 9 or not?
    printf("The number %d is %sdivisible by 9\n", num,
            (flag == 1? "" : "not "));

    return(0);
}
        
