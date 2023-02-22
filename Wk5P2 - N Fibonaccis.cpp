#include <iostream>
using namespace std;

int main() {

  int nFibs; //number of numbers in series to be printed
  int previous = 0, current = 1, next = 0; // variables for calculating each term in series

  cout << "How many fibs:";//inputs number of fibs
  cin >> nFibs;

  for(int n=1; n<=nFibs; n++){ //calcuates and prints series up to nFibs terms
    cout << next << " ";
    previous = current;
    current = next;
    next = previous + current;
  }
}
