#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc
#include "student.h"   // local header file that defines student data structure

typedef enum {false, true} Bool;

#define BYNAME "name"
#define BYCREDITS "credits"

void student_print(student_t stdnts[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("STUDENT: name %s ID %d Credits %d\n", stdnts[i].name, stdnts[i].id, stdnts[i].credits);
    }
    return;
}

int student_scan(student_t stdnts[]) {
    char line[81];
    char *result;

    FILE *inptr = fopen("students.txt", "r");
    int i = 0;
    while (fgets(line, 80, inptr) != NULL) {
        result = strtok(line, "$");
        strcpy(stdnts[i].name, result);
        result = strtok(NULL, " ");
        sscanf(result, "%d", &stdnts[i].id);
        result = strtok(NULL, " ");
        sscanf(result, "%d", &stdnts[i].credits);
        result = strtok(NULL, " ");
        sscanf(result, "%c", &stdnts[i].year); 
        ++i;
    }
    fclose(inptr);
    return i;
}

void student_sort(student_t stdnts[], int n, char* type) {

    int i, j, doswap = 0;

    student_t temp;

    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            if (strcmp(type, BYNAME) == 0) {
                doswap = strcmp(stdnts[i].name,
                                stdnts[j].name);
            }
            else if (strcmp(type, BYCREDITS) == 0) {
                doswap = (stdnts[i].credits > stdnts[j].credits ? 1 : 0); 
            }

            if (doswap > 0) {
                temp = stdnts[i];
                stdnts[i]= stdnts[j];
                stdnts[j] = temp;
            }
        } 
    }
    return;
}

int main() {

    student_t students[20]; 
    int num_students;

    num_students = student_scan(students);

    student_sort(students, num_students, BYNAME);
    printf("LIST STORTED BY NAME\n");
    student_print(students, num_students);
    
    student_sort(students, num_students, BYCREDITS);
    printf("\n\nLIST SORTED BY CREDITS\n");
    student_print(students, num_students);

    return(0);
}


