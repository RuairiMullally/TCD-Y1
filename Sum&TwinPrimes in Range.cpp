#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num);
bool twinPrimes(int num);

int main() {
  int sum = 0, n, N, twintally = 0;

  cout << "Enter a range to find the sum of primes between: " << endl;
  cin >> n >> N;

  cout << "List of twin primes in range: ";

  for(int i = n; i <=N; i++){
    if(isPrime(i))
      sum = sum + i;

    if(twinPrimes(i)){
      cout << i-2  << " and " << i << ", ";
      twintally++;
    } 
  }
  cout << "There were " << twintally << " twin primes." << endl << "The sum of primes in range was " << sum << endl;
}

bool isPrime(int num){
  if(num == 1)
    return false;
  else if(num%2 ==0)
    return false;
  return true;
}

bool twinPrimes(int num){
  if(isPrime(num) && isPrime(num - 2))
    return true;
  return false;
}