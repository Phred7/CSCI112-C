#include <stdio.h>
#include <string.h>

int main(void) {
    char place[20] = "Bozeman, MT";

    char *city, *state;

    printf("place is %s\n", place);
    city = strtok(place, ", ");

    printf("place is %s\n", place);

    state = strtok(NULL, ", ");
    printf("place is %s\n", place);

    printf("city is %s and state is %s\n", city, state);

    return(0);
}
