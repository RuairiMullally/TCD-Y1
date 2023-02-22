#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

  double initialInvestment; //declaring inital investment amount,
  const int YEARMAX = 30; //the highest number of years to display
  const double RATEMAX = 10.0; //and the highest interest rate to display

  cout << "Enter initial investment amount:"; //inputs initial investment amount
  cin >> initialInvestment;

  cout << setw(10) << "Rate";
  for(int years = 5; years <= YEARMAX; years = years + 5) // prints header column (years at intervals of 5)
    cout << setw(4) << years << " years";
  cout << endl;


  for(double rate = 5.0; rate <= RATEMAX; rate = rate + 0.5){ //loop handles subsequent rows printing the rate followed by the value at every year interval
    cout << setw(10) << fixed <<setprecision(2) << rate;

    for(int years = 5; years <= YEARMAX; years = years + 5){

      double afterInterest = initialInvestment * pow(1+rate/100, years); // calculates investment value after 'years' years
      cout <<setw(10) << setprecision(2) << afterInterest;
    }
    cout <<endl;
  }

}
