#include <stdio.h>
#include <math.h>

int main() {

    int x[] = {2, 6};
    int y[] = {1, 4};

    double distance = sqrt(pow(x[1]-x[0], 2.0) +
                        pow(y[1]-y[0], 2.0));


    printf("distance is %.2lf\n", distance);

    return(0);
}
