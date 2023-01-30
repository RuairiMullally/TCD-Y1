#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    float num1, num2;
    string op;
    string result;

    cout << "Enter number 1:";
    cin >> num1;
    cout << "Enter operator:";
    cin >> op;
    cout << "Enter number 2:";
    cin >> num2;

if(op=="+"){
    cout << "Your result is " << num1 + num2 << endl;
}
else
    if(op=="-"){
    cout << "Your result is " << num1 - num2 << endl;
    }
else
    if(op=="*"){
    cout << "Your result is " << num1 * num2 << endl;
    }
else
    if(op=="/"){
    cout << "Your result is " << num1 / num2 << endl;
    }

    return 0;
}
