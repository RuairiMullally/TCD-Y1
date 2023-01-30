//5 points of 20 for this week
//Indicate which pizza is better value
//Complete this program so that the if statement provided will print "FIRST", "SECOND or "SAME" as appropriate.
//Reuse your previous ppsi code
#include <iostream>
#include <cmath>
using namespace std;

double findPPSI(double diameter, double price){
  
const double pi = 3.14;  
double ppsi = price/(pi*pow(diameter/2, 2));
return ppsi;
}

string findANS(double ppsi1, double ppsi2){
   
   if (ppsi1 < ppsi2) {
     
    string answer = "FIRST";
     return answer;
  }
 else if (ppsi1 > ppsi2) {
   
    string answer2 = "SECOND";
   return answer2;
   
  }else {
   
    string answer3 = "SAME";
   return answer3;
   
  }
 cout << endl;
   }


int main() {
  //declare variables
  double diameter, price, ppsi1 = 0, ppsi2 = 0;
  
  //read in data
  cout << "Enter the diameter and price of the first pizza:";
  cin >> diameter >> price;
  ppsi1 = findPPSI(diameter, price);

  cout << "Enter the diameter and price of the second pizza:";
  cin >> diameter >> price;
  ppsi2 = findPPSI(diameter, price);

  string answer = findANS(ppsi1, ppsi2);
  cout << answer;
  }