#include <stdio.h>
#include "student.h"   // local header file that defines student data structure

int main() {

    // declaring a single student
    student_t mac = {"mary ann cummings", 1, 115, 'j'};

    // use the direct component selection operator to print each elment
    printf("student id: %d\nname: %s\ncredits: %d\nyear: ",
		     mac.id, mac.name, mac.credits);

    switch (mac.year) {
    case 'f':
	    printf("freshman");
	    break;
    case 's':
	    printf("sophomore");
	    break;
    case 'j':
	    printf("junior");
	    break;
    case 'r':
	    printf("senior");
    }
    // to finish the printed line
    printf("\n");
    return(0);
}
