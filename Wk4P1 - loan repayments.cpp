#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const double ANNUAL_RATE = 12; //declares APR as a constant
    double monthly_rate = (ANNUAL_RATE/12)/100; //converts APR to a monthly rate

    double loan_amount, monthly_payment, total_interest, final_payment;//declare variables
    int month_tally = 1; //sets monthly tally to 1

    //takes input for loan amount and monthly payment
    cout << "Loan amount:";
    cin >> loan_amount;
    cout << "Monthly payment:";
    cin >> monthly_payment;

    //calculates total interest paid and months to do so, up until the final payment
    while(monthly_payment < loan_amount){

        total_interest = total_interest + (loan_amount * monthly_rate);//adds iteration interest to total interest

        loan_amount = loan_amount + (loan_amount * monthly_rate);//adds iteration interest to loan
        loan_amount = loan_amount - monthly_payment;//subtracts monthly payment from loan

        month_tally ++;//adds 1 to month tally
    }

    //1 more iteration is required for the final payment
    total_interest = total_interest + (loan_amount * monthly_rate);
    loan_amount = loan_amount + (loan_amount * monthly_rate);
    final_payment = loan_amount;//sets final payment to the remaining balance

    cout << fixed << setprecision (2);//sets decimal precision to 2

    //outputs months, interest, and final payment
    cout << month_tally << " months.\n";
    cout << total_interest << " euro total interest.\n";
    cout << final_payment <<  " euro final payment.\n";

    return 0;
}
