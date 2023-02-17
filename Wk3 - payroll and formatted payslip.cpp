#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;



int main() {

double hours, rate, credit, gross, PRSI, tax, finalTax, net;
const double PRSIRate = .025, taxRate = .2, overtimeStart = 35;
string name;

cout << "Enter name: ";
getline(cin, name);
cout << "Enter hours, hourly rate, tax credit: ";
cin >> hours >> rate >> credit;


  double overtimeRate = rate * 1.5;

  if(hours <= overtimeStart){
    gross = hours * rate;
  }
  else if(hours > overtimeStart){
    gross = (rate * 35) + ((hours - 35) * overtimeRate);
  }

  tax = gross * taxRate;

  if(tax >= credit){
    finalTax = tax - credit;
  }
  else if(tax < credit){
    finalTax = 0;
  }

  PRSI = gross * PRSIRate;
  net = gross - finalTax - PRSI;


cout << endl;
cout << setw(4) <<fixed << left << "Name" << setw(26) << right << name << endl;
cout << setw(5) <<fixed << left << "Hours" << setw(25) << right << showpoint <<  setprecision(2) << hours << endl;
cout << setw(11) <<fixed << left << "Hourly rate" << setw(19) << right << showpoint <<  setprecision(2) << rate << endl;
cout << setw(10) <<fixed << left << "Gross wage" << setw(20) << right << showpoint <<  setprecision(2) << gross << endl;
cout << setw(9) <<fixed << left << "Tax @ 20%" << setw(21) << right << showpoint <<  setprecision(2) << finalTax << endl;
cout << setw(11) <<fixed << left << "PRSI @ 2.5%" << setw(19) << right << showpoint <<  setprecision(2) << PRSI << endl;
cout << setw(30) <<fixed << "------------------------------" << endl;
cout << setw(7) <<fixed << left << "Net Pay" << setw(23) << right << showpoint <<  setprecision(2) << net << endl;


return 0;
}
