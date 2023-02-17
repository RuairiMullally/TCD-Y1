#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main() {

  //declare variables
  string location;
  double temperature, sum = 0, max, min, average;
  //inputs location and temperature data
  cin >> location >> temperature;

  int n = 0;//sets counter for average to 0
  //sets reference temperature for while loop to first input
  max = temperature;
  min = temperature;

  //exit clause if no data
  if(temperature == -999){
    cout << location << " NO DATA";
    return 0;
  }

  //runs loop to determine sum of temps for average and fin min/max
  while(temperature != -999){

    sum = sum + temperature;
    n++;

    if(temperature > max)
      max = temperature;
    if(temperature < min)
      min = temperature;

    cin >> temperature;
  }

  average = sum/n; // calculates average
  //output
  cout << fixed << setprecision(1) << showpoint;
  cout << location << " " << min << " " << max << " " << average << endl;

  return 0;
  }
