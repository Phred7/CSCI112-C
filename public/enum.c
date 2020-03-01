#include <stdio.h>

typedef enum {january, february, march, april, may, june,july,
              august, september, october, november, december} months_t;

int main() {

    char* month_names[] = {"january", "february", "march", "april", "may",
                          "june", "july", "august", "september", "october",
                          "november", "december"};

    months_t months = january;
    while (months <= december) {
        printf("month %d is %s\n", months, month_names[months]);
        ++months;
    }
    return(0);
}
