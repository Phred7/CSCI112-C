#include <stdio.h>
#include <stdlib.h>

int main() {
    char* month_array[12] = {"january", "february", "march", "april",
                             "may", "june", "july", "august", "september",
                             "october", "november", "december"};
    int month = 10,
        day = 29,
        year = 2018;

   char *str1 = malloc(30 * sizeof(char)),
        *str2 = malloc(30 * sizeof(char));

   sprintf(str1, "%d/%d/%d", month, day, year);
   sprintf(str2, "%s/%d/%d", month_array[month-1], day, year);
  
   printf("date1 is %s\ndate2 is %s\n", str1, str2);
   return(0);
}
