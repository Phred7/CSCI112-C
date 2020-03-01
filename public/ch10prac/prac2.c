#include <stdio.h>
#include "latlon.h"

void location_scan(location_t* loc) {
    printf("Enter latitude for location (degrees, mins, direction): ");

    scanf("%d %d %c", &(loc->lat).degrees, &(loc->lat).min, &(loc->lat).dir);

    printf("Enter longitude for location (degrees, mins, direction): ");
 
    scanf("%d %d %c", &(loc->lon).degrees, &(loc->lon).min, &(loc->lon).dir);
    return;
}

int main() {
    location_t mor;

    location_scan(&mor);

    printf("Museum of the Rockies location is LAT: %d %d %c, LON: %d %d %c\n",
               mor.lat.degrees, mor.lat.min, mor.lat.dir,
               mor.lon.degrees, mor.lon.min, mor.lon.dir);
    return(0);
}


