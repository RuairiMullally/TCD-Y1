#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

bool isaVowel(char toTest);

int main() {
  char toTest, answer;
  bool isVowel, yesNo = true;
  


  while(yesNo){

    cout << "Enter string to be checked for vowels terminated by a '.': " << endl;
    cin >> toTest;
    toTest = tolower(toTest);
    int tally = 0;

    while(toTest != '.'){
      isVowel = isaVowel(toTest);
      if(isVowel){
        cout << toTest << " is a vowel." << endl;
        tally++;
      }
      cin >> toTest;
      toTest = tolower(toTest);
    }
    cout << "There were " << tally << " vowels present." << endl << "Would you like to test another string? (Y/N)";
    cin >> answer;
    if(answer != 'Y')
      yesNo = false;
    }
  }

bool isaVowel(char toTest){
  if(toTest == 'a' || toTest == 'e' || toTest == 'i' || toTest == 'o' || toTest =='u')
    return true;
  return false;
}

