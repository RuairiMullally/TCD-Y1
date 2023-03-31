//Ruairi Mullally 22336002

#include <iostream>
#include <iomanip>
using namespace std;

//function declarations
void readInData(int integers[], int SIZE);
void initialise(char yAxisValues[], int SIZE);

void convertArrays(const int integers[], char yAxisValues[], int SIZE, int iteration);
void printArray(char yAxisValues[], int SIZE, int iteration);

void printGraph(const int integers[], char yAxisValues[], int SIZE, int iteration);

void scaleBars(int N);

const int SIZE = 70; // determines max 'x' value for length of the scale bars & arrays
const int HEIGHT = 20; //determines max 'y' value, contols loops

int main() {
  int integers[SIZE], iteration = HEIGHT;
  char yAxisValues[SIZE];

  readInData(integers, SIZE); //read in integer values with corresponding x position (array slot)
  initialise(yAxisValues, SIZE); //initialises yAxisValues with blanks

  printGraph(integers, yAxisValues, SIZE, iteration);
  scaleBars(SIZE/10);
}


void readInData(int integers[], int SIZE){ //reads in the list of integers to be graphed
  for(int i=0; i<SIZE; i++)
    cin >> integers[i];
}


void initialise(char yAxisValues[], int SIZE){//initialises 'y' axis array to blank spaces
  for(int i=0; i<SIZE; i++)
    yAxisValues[i]=' ';
}



void convertArrays(const int integers[], char yAxisValues[], int SIZE, int iteration){//if there is a value at that level iteration for some x value, the yAxisValues receives an '*' in that position
  for(int i=0; i<SIZE; i++){
    if(integers[i] == iteration){
      yAxisValues[i] = '*';
    }
  }
}


void printArray(char yAxisValues[], int SIZE, int iteration){ //prints the vertical bars forming the graph

    cout << setw(2) << iteration << setw(3)  << "|";

    for(int n=0; n<SIZE; n++){
      cout << yAxisValues[n];
    }
    cout << endl;
}


void printGraph(const int integers[], char yAxisValues[], int SIZE, int iteration){

    for(int p=HEIGHT; p>0; p--){
        convertArrays(integers, yAxisValues, SIZE, iteration);
        printArray(yAxisValues, SIZE, iteration);
        iteration --;
  }
}



void scaleBars(int N) { //prints out scale bars at bottom of graph
  cout << "----|";
  for (int n = 1; n <= N; n++)
    cout << "----+----|";
}





