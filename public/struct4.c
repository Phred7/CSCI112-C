#include <stdio.h>
#include <string.h>  // ADD THIS TO USE STRCPY
#include <stdlib.h>  // ADD THIS TO USE MALLOC
#include "student.h"   // local header file that defines student data structure

int main() {

    // declaring a single student
    student_t mac = {"mary ann cummings", 1, 115, 'j'};
    student_t newst;

    // now let's change the student
    newst = mac; 

    newst.id += 5;

    newst.name[0] = 'c';

    printf("mac student id: %d\nname: %s\ncredits: %d\nyear: %c\n",
                      mac.id, mac.name, mac.credits, mac.year);

    printf("newst student id: %d\nname: %s\ncredits: %d\nyear: %c\n",
                     newst.id, newst.name, newst.credits, newst.year);
    printf("mac.name address is %p\nnewst.name address is %p\n", 
            mac.name, newst.name);

    return(0);
}
