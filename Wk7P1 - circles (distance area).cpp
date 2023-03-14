//use functions to compute the area of a circular track and the distance of one lap along its centre
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415;

double circle_area (double diameter);
double ring_area (double circleD, double holeD);
double circumference(double diameter);

int main() {
  double outerD, innerD, area, distance;

  cout << "Enter outer and inner diameters:";
  cin >> outerD >> innerD;

  //compute area and distance using the functions ...
  area = ring_area (outerD, innerD);
  //distance is for the circle half way between outer and inner ...
  distance = circumference((outerD+innerD)/2);

  cout << "Area:" << area << " Distance:" << distance << endl;

  return 0;
}

double circle_area (double diameter) {
  return PI*pow(diameter/2, 2);

}

double ring_area (double circleD, double holeD) {
  //using 2 calls to circle_area compute the area of a ring
  return circle_area(circleD) - circle_area(holeD);
}

//define circumference function ...
double circumference(double diameter){
  return 2*PI*(diameter/2);
}
