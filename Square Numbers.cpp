#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int squareNums[10000];
    int n, i;

    cout << "How many square numbers do you want to print? \nEnter here:";
    cin >> n;

    for(i=0; i<=n; i++){
        squareNums[i] = i*i;
        cout << squareNums[i] << ",";
    }

    return 0;
}


