#include <stdio.h>
#include <string.h>

int main(void) {

    char k1[15] = "John ",
         k2[15] = "Jacqueline ",
        last[15] = "Kennedy";

    printf("k1 address is %p, k2 address is %p, last address is %p\n",
        k1, k2, last);
    strcat(k1, last);
     strcat(k2, last);

    printf("k1 is %s, k2 is %s, last is %s\n", k1, k2, last);

    return(0);
}
