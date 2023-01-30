//10 points of 20 for this week
//Complete the following program to turn a length in centimetres to its nearest whole inches value (using the round function)
//Then turn the inches into the equivalent yards/feet/inches value
//Sample output: 
//"254cm is approx. 100 inches which is 2 yards, 2 feet and 4 inches."
//Notes: 1 inch is 2.54cm
//a yard is 3 feet or 36 inches;
//a foot is 12 inches
//Use integer division and remainder.

#include <iostream>
#include <cmath> //for the round function
using namespace std;

int main ()
{
	//declare the variables you need
  //You will need to use ints for the yards feet and inches in order for integer division and remainder to work
  double cm;
  int inches, yards, feet;

	//prompt for and read input
	cout << "Enter a length in centimetres:";
	cin >> cm;

  inches = round(cm/2.54); //compute total inches
  cout << cm << "cm is approx. " << inches << " inches";  //print out first part of output; 

  yards = inches/36;
  feet = (inches%36)/12;
  inches = inches - yards*36 - feet*12;
  
  cout << " which is " << yards << " yards, " << feet << " feet and " << inches << " inches.";  //output the answer

	return 0;
}