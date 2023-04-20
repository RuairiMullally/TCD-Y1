#include <iostream>
#include <cmath>
using namespace std;

//function declarations
void readToSentinel(double numbers[], int CAPACITY, int SENTINEL, int& arraySize);

double mean(double numbers[], int arraySize);
double varience(double numbers[], int arraySize);
double stdev(double numbers[], int arraySize);
int zeroCrossings(double numbers[], int arraySize);

int main()
{
    const int CAPACITY = 100, SENTINEL = 9999;
    double numbers[CAPACITY];
    int arraySize;

    readToSentinel(numbers, CAPACITY, SENTINEL, arraySize);
    double m = mean(numbers, arraySize);
    double var = varience(numbers, arraySize);
    double sd = stdev(numbers, arraySize);
    double zeros = zeroCrossings(numbers, arraySize);

    //print out results
    cout << "Count: " << arraySize << "\nMean: " << m << "\nVarience: " << var << "\nStd. Dev.: " << sd << "\nZero Xs: " << zeros << endl;
}

void readToSentinel(double numbers[], int CAPACITY, int SENTINEL, int& arraySize){ //reads in data and defines the size of the array
    int size = 0;
    double x;
    cin >> x;

    while(size < CAPACITY && x!=SENTINEL){
        numbers[size] = x;
        size++;
        cin >> x;

    }

    arraySize = size;
    if(size == CAPACITY)
        cout << "\nWARNING OVERFLOW Only first " << CAPACITY << " numbers handled.\n";

}

double mean(double numbers[], int arraySize){//calculates the mean of the array
    double tally;
    for(int i=0; i<arraySize; i++){
        tally += numbers[i];
    }
    return tally/arraySize;
}

double varience(double numbers[], int arraySize){//finds the varience of the array
    double mu = mean(numbers, arraySize);
    int numerator;

    for(int i=0; i<arraySize; i++){
        numerator += pow((numbers[i] - mu), 2);
    }
    return (numerator/arraySize);
}

double stdev(double numbers[], int arraySize){ //calculates standard deviation
    double Varience = varience(numbers, arraySize);
    return sqrt(Varience);

}

int zeroCrossings(double numbers[], int arraySize){//tallys the amount of times the x axis is crossed
    int tally = 0;
    for(int i=0; i<arraySize-1; i++){
        if(numbers[i]*numbers[i+1] < 0)
            tally++;
    }
    return tally;
}


