#include <iostream>
#include <cmath>

using namespace std;
bool verifier(int age);
int age;

int main()
{
    cout << "Enter your age: ";
    cin >> age;

    if(verifier(age)){
        cout << "You are old enough!" <<endl;
    }
    else{
        cout << "You are not old enough." <<endl;
    }
    return 0;
}

bool verifier(int age){
if(age>=18){return true;}
else{return false;}
}
