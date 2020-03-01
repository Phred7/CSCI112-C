#include <stdio.h>

double computeTax(double salary) {

    if (salary < 15000.0) {
        return (salary * .15);
    }
    else if (salary < 30000.0) {
        return (((salary - 15000.0) * .18) + 2250.0);
    }
    else if (salary < 50000.0) {
        return (((salary - 30000.0) * .22) + 5400.0);
    }
    else {
        return 0;
    }
}

int main(void) {

    double salary, tax;

    // read in salary
    printf("Enter salary with two numbers after decimal ");
    scanf("%lf", &salary);

    // compute the tax
    tax = computeTax(salary);

    // print out salary and tax
    // else print error if salary is not within limits 0 <= salary < 50000
    if (0.0 <= salary && salary < 50000.0) {
        printf("For salary %.2lf, the tax is %.2lf\n", salary, tax);
    }
    else {
        printf("ERROR: salary %.2lf not within limits\n", salary);
    }
    return 0;
}
