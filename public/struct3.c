// This code is about 2 things:
// 1. setting one structure to another
// 2. looking at their addresses - notice the name string
// HOW DO WE FIX THIS?
//
#include <stdio.h>
#include "student.h"   // local header file that defines student data structure

int main() {

    // declaring a single student
    student_t mac = {"mary ann cummings", 1, 115, 'j'};
    student_t newst;

    // use the direct component selection operator to print each elment
    printf("mac student id: %d\nname: %s\ncredits: %d\n",
		     mac.id, mac.name, mac.credits);
    printf("mac.name address is %p\n", mac.name);
    // now let's change the student
    newst = mac; 
    // are addresses the same?
    printf("mac address is %p, newst address is %p\n", &mac, &newst);
    newst.name[0] = 'c';
    newst.id += 5;
    printf("mac student id: %d\nname: %s\ncredits: %d\n",
              mac.id, mac.name, mac.credits);

    printf("newstr student id: %d\nname: %s\ncredits: %d\n",
                     newst.id, newst.name, newst.credits);
    printf("newst.name address is %p\n", newst.name);

    return(0);
}
