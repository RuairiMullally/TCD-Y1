//Week 10 P1 name rank
#include <iostream>
#include <string>
using namespace std;

const int NUM_NAMES = 10;

int search (string s, const string sarray[], int size);
//returns the position of s in sarray or -1 if not found
void willContinue(bool& continuing, string response);

int main () {
    string girls [NUM_NAMES] = {"Grace", "Fiadh", "Emily", "Sophie", "Ava", "Amelia", "Ella", "Hannah", "Lucy", "Alex"};
    string boys [NUM_NAMES] = {"Jack", "James", "Noah", "Daniel", "Conor", "Finn", "Liam", "Fionn", "Alex", "Charlie"};

  bool continuing = true;
  string test_name, response;
  int positiongirls, positionboys;

  while(continuing == true){
    cout << "Enter a name to search for:";
    cin >> test_name;
    positiongirls = search(test_name, girls, NUM_NAMES);
    positionboys = search(test_name, boys, NUM_NAMES);

    if(positiongirls == -1 && positionboys == -1)
      cout << test_name << " is not in the top " << NUM_NAMES << " for girls or boys.\n";
    else if(positiongirls != -1 && positionboys != -1){
      cout << test_name << " is ranked " << positiongirls+1 << " in top girls name.\n";
      cout << test_name << " is ranked " << positionboys+1 << " in top boys name.\n";
    }
    else if(positionboys == -1)
      cout << test_name << " is ranked " << positiongirls+1 << " in top girls name.\n";
    else
      cout << test_name << " is ranked " << positionboys+1 << " in top boys name.\n";

    cout << "Look up the rank of another name? Enter No to end:";
    cin >> response;

    willContinue(continuing, response); 
  }
   
    return 0;
}

int search (string s, const string sarray[], int size) {
//returns the position of s in sarray or -1 if not found
    for (int i=0; i < size; i++) {
        if (sarray[i] == s) {
            return i;
        }
    }
    return -1;
}

void willContinue(bool& continuing, string response){
  if(response == "Yes")
    continuing = true;
  else
    continuing = false;
    
}