#include <stdio.h>
#include "student.h"   // local header file that defines student data structure

int main() {

    // declaring an array of students
    student_t c112[4] = {
            {"jane doe", 2, 45, 's'},
		    {"john smith", 3, 15, 'f'},
		    {"josephine burdett", 4, 124, 'r'},
		    {"joe gray", 5, 110, 'j'}
    };

    int i; // counter

    // walk through the array to print each item
    for (i = 0; i < 4; i++) {

        // use the direct component selection operator to print each elment
        printf("\nstudent id: %d\nname: %s\ncredits: %d\nyear: ",
		     c112[i].id, c112[i].name, c112[i].credits);
	switch (c112[i].year) {
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
    }

    return(0);
}
