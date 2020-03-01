#include <stdio.h>
#include <math.h>

double calculatePayment(double princ, double ann_int, int n) {

    double mon_int_rate = ann_int/(12.0 * 100.0);

    // calculate
    double payment = (mon_int_rate * princ) /
                     (1.0 - pow((1.0 + mon_int_rate), (-1.0 * n)));
                 
    // round to the nearest cent
    payment = roundf(payment * 100.0);
    payment /= 100.0;

    return payment;
}

void writeTable(double principal, double payment, double ann_int, int n) {

    int i;
    
    double monthly_int, mon_int_rate, buy_downp; 
    // print header to table
    printf("payment: %.2lf annual interest rate: %.2lf%%\n", payment, ann_int);

    // calculate monthly interest rate
    mon_int_rate = ann_int / (12.0 * 100.0); 

    for (i = 1; i <= n; ++i) { 

        // calculate monthly interest
        monthly_int = mon_int_rate * principal; // column 2 of table

        // round monthly interest to nearest cent
        monthly_int = roundf(monthly_int * 100.0);
        monthly_int /= 100.0;

        // calculate rest of payment as buy down to principal
        buy_downp = payment - monthly_int;  // column 3 of table

        // column 4 - changed principal
        principal -= buy_downp;

        if (i == n) {
            // calculate final line differently
            // calculate final payment by subtracting the principal below 0
            payment +=  principal;

            // you have to remove that negative balance from the buydown
            buy_downp += principal;

            // and finally you now have a 0 balance
            principal = 0.0;
        }
 
        // print each line
        printf("%d %.2lf %.2lf %.2lf\n", i, monthly_int,
                 buy_downp, principal);

    }
    // print final payment
    printf("final payment is %.2lf\n", payment);

    return;
}

int main(void) {
    double principal, annual_int, payment;
    int no_payments;

    // read in principal, interest, and no of payments
    printf("Enter principal, annual int, and no_payments: ");
    scanf("%lf %lf %d", &principal, &annual_int, &no_payments);
    
    // calculate payment
    payment = calculatePayment(principal, annual_int, no_payments);
 
    // write the table showing how loan is paid off
    writeTable(principal, payment, annual_int, no_payments);

    return(0);
}
