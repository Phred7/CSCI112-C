#include <stdio.h>
#include <string.h>
#include "latlon.h"

void LineToLocation(location_t* loc, char* line) {
    char *result;
    char copy_line[81];
    strcpy(copy_line, line);
    result = strtok(copy_line, " ");
    sscanf(result, "%d", &loc->lat.degrees);
    result = strtok(NULL, " ");
    sscanf(result, "%d", &loc->lat.min);
    result = strtok(NULL, " ");
    loc->lat.dir = result[0];
     result = strtok(NULL, " ");
     sscanf(result, "%d", &loc->lon.degrees);
     result = strtok(NULL, " ");
     sscanf(result, "%d", &loc->lon.min);
     result = strtok(NULL, " ");
     loc->lon.dir = result[0];
     return;
}

int main() {
    location_t locs[10];
    char line[81];
    FILE* inf = fopen("locs.txt", "r");

    int i = 0; // holds number of locations that we have read and stored
    while (fgets(line, 80, inf) != NULL) {
        LineToLocation(&locs[i], line);
        ++i;
    }
    int num_locations = i;
    for (i = 0; i < num_locations; ++i) {
        printf("Location %d is LAT: %d %d %c, LON: %d %d %c\n",
               i, locs[i].lat.degrees, locs[i].lat.min, locs[i].lat.dir,
               locs[i].lon.degrees, locs[i].lon.min, locs[i].lon.dir);
    }
    return(0);
}


