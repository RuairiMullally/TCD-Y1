#include <iostream>
#include <cmath>
using namespace std;

void errorBars(int N);
bool isPrime(int n);
void printStars(int j);

int main() {
  const int N = 100;
  errorBars(N/10);
  cout << endl;

  for(int j=1; j<=N; j++)
    if(isPrime(j))
      printStars(j); 
}

void errorBars(int N){
for(int n =1; n<=N; n++)
  cout << "----+----|";
}

bool isPrime(int n){
  if(n==1)
    return false;
  for(int i=2; i<=n/2; i++)
    if(n%i==0)
      return false;
  return true;
}

void printStars(int j){
  for(int n=1; n<=j;n++)
    cout << "*";
  cout << endl;  
}
