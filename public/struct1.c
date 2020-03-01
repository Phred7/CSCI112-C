#include "student.h"   // local header file that defines the student data structure

int main() {

    // declaring a single student
    student_t mac = {"mary ann cummings", 1, 115, 'j'};

    // declaring an array of students
    student_t c112[4] = {
	            {"jane doe", 2, 45, 's'},
		    {"john smith", 3, 15, 'f'},
		    {"josephine burdett", 4, 124, 'r'},
		    {"joe gray", 5, 110, 'j'}
    };

    return(0);
}
