#include <iostream>
using namespace std;

int main() {

  int maxFibs; //the maximum number to which fib nums will be printed
  int previous = 0, current = 1, next = 0, counter = 0; //variables for calculating fib nums and initializes them

  cout << "Fibs below what:";
  cin >> maxFibs; //inputs max

  while(next < maxFibs){
    cout << next << " ";
    counter++; //adds 1 to the term counter
    previous = current;
    current = next;
    next = previous + current;
  }
  cout << endl << "That was " << counter << " terms.";
}
