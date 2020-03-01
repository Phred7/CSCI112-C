#include <stdio.h>
#include <string.h>  // ADD THIS TO USE STRCPY
#include <stdlib.h>  // ADD THIS TO USE MALLOC
#include "student_malloc.h"   // local header file that defines student data structure

int main() {

    // declaring a single student
    student_t mac = {"mary ann cummings", 1, 115, 'j'};
    student_t newst;

    // now let's change the student
    newst = mac; 

    newst.id += 5;

    // but I have to change the name of this new student - THIS WAY
    newst.name = malloc(sizeof(char) * 40);
    strcpy(newst.name, mac.name);

    newst.name[0] = 'c';

    printf("mac student id: %d\nname: %s\ncredits: %d\nyear: %c\n",
                      mac.id, mac.name, mac.credits, mac.year);

    printf("newst student id: %d\nname: %s\ncredits: %d\nyear: %c\n",
                     newst.id, newst.name, newst.credits, newst.year);
    printf("mac.name address is %p\nnewst.name address is %p\n", 
            mac.name, newst.name);

    return(0);
}
