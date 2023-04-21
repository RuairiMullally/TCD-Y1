
#include <iostream>
#include <iomanip>
using namespace std;


//Function Declarations
int search(string s, const string a[], int size);//returns the position of a matching search
int maxpos(const int numbers[], int size);//returns the positions of the largest number in an array
double itemvalue(string item, const string items[], const double prices[], int size);//returns the value of an iem
void initialisecounters(int& itemcounter, double& ordervalue, bool& unknownflag);
void itemtally(string item, const string items[], int quantities[], int size);//tallys all items order frequency
void printsummary(const string items[], int size, int quantities[]);//prints the 



int main () {
  //constants
  const int NUM_ITEMS = 10;
  const string ORDERSENTINEL = "XXX", PSENTINEL = "C-999";

  //variables
  string items [NUM_ITEMS] = {"I001", "I111", "I222", "I303", "I444", "I550", "I666", "I707", "I888", "I990"};
  double prices [NUM_ITEMS] = {0.99, 1.50, 2.00, 0.33, 4.04, 1.55, 2.66, 7.00, 2.88, 3.99};
  int quantities [NUM_ITEMS] {0,0,0,0,0,0,0,0,0,0};

  string customerID, item;
  int itemcounter;
  double itemcost, ordervalue, totalordervalue;
  bool unknownflag;

  
  cin >> customerID;
  while(customerID != PSENTINEL){
    
    initialisecounters(itemcounter, ordervalue, unknownflag);
    cin >> item;
    
    while(item != ORDERSENTINEL){
      
      itemcost = itemvalue(item, items, prices, NUM_ITEMS);
      itemtally(item, items, quantities, NUM_ITEMS);

      if(itemcost == -1)
        unknownflag = true;
      else{
        ordervalue +=itemcost;
        itemcounter++;
      }
      cin >> item;  
    }
    
    if(unknownflag == true)
      cout << "WARNING: Unknown item code IUNKNOWN ignored." << endl;
    
    totalordervalue += ordervalue;
    
    cout << customerID << " Value: €" << ordervalue << " Number of Items: " << itemcounter << endl; 
    cin >> customerID; 
  }
  
  
  cout << "Total value of all orders: €" << totalordervalue << endl;
  printsummary(items, NUM_ITEMS, quantities);
  
  return 0;
}


//FUNCTION DEFINITIONS

//returns the position of s in a, or -1 if not found
int search(string s, const string a[], int size) {
	for (int i=0; i<size; i++)
	{
		if (a[i] == s)
			return i;
	}
	//s not found
	return -1;
}

//returns the (first) slot containing the maximum value 
int maxpos(const int numbers[], int size) {
  int maxslot = 0; //max so far is in slot 0
  for (int i=1; i<size; i++){
    if (numbers[i] > numbers[maxslot])
      maxslot = i; //new max so far is in slot i
    //else do nothing
  }
  return maxslot;
}

double itemvalue(string item, const string items[], const double prices[], int size){
  double value=0;
  int place = search(item, items, size);
  if(place == -1)
    return -1;
  return prices[place];
}

void initialisecounters(int&itemcounter, double&ordervalue, bool& unknownflag){
  itemcounter =0;
  ordervalue = 0;
  unknownflag = false; 
}

void itemtally(string item, const string items[], int quantities[], int size){
  int place = search(item, items, size);
  quantities[place] +=1;
}

void printsummary(const string items[], int size, int quantities[]){
  cout << "Total of each item ordered: ";
  for(int i=0; i< size; i++){
    cout <<" " << items[i]<< ": " << quantities [i] ;
  }

   cout << endl << "Most popular item: " << items[maxpos(quantities, size)] << endl;
}