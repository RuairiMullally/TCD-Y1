#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//computes the square root of n, given an inital approximation
double newton_sqrt (double n, double init);
double better_approx (double x, double n);
bool close_enough (double x, double n);


int main () {
  double n;
  double approx;
  cout << "Enter n:";
  cin >> n;
  approx = newton_sqrt (n, n/2); //n/2 is an arbitrary initial approximation.
  cout << fixed << setprecision(6);
  cout << "The square root of " << n;
  cout << " is approx " << approx << endl;
    
  return 0;
}

double newton_sqrt(double n, double init) {
 
  //uses Newton's method and starts at init. 
  double approx = init;
  bool SENTINEL = false;
  
  //keep improving approximations until close enough (or while not close enough); you must use the two other functions
  
  while(SENTINEL != true){
    approx = better_approx(approx, n);
    cout << fixed << setprecision(6) << approx << endl;
    SENTINEL = close_enough(approx, n);
  }
  return approx;
}

//define the other two fucntions
double better_approx (double x, double n){
  return ((n/x)+x)/2;
}

bool close_enough(double approx,double n){
  if((pow(approx, 2) > n - 0.0001) && (pow(approx, 2) < n +0.0001))
    return true;
  return false;
}
