//Ruairi Mullally 22336002


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//function declarations
void print_header();
void read_record(string& name, double& balance, char& type, int& mins1, int& mins2);
double compute_charge(char type, int mins1, int mins2);
void compute_balance(double& balance, double charge);
void print_bill(string account, string name, char type, double charge, double balance);



//constant declarations
const int REGMINS = 50, DAYMINS = 75, NIGHTMINS = 100, REGMONTH = 10, PREMMONTH =  25;
const double REGRATE = 0.2, DAYRATE = 0.1, NIGHTRATE = 0.05;
const string SENTINEL = "X0000";


int main(){
    //variables
    string account, name;
    double balance = 0.0, charge;
    char type;
    int mins1 = 0, mins2 = 0;

    //initialize input
    cin >> account;

    //print header
    print_header();

    //main loop that runs until sentinel
    while(account != SENTINEL){

            read_record(name, balance, type, mins1, mins2);
            charge = compute_charge(type, mins1, mins2);
            compute_balance(balance, charge);
            print_bill(account, name, type, charge, balance);

            cin >> account;
    }
}


void print_header(){ // prints the header of the bill
    cout << setw(8) << "Account" << setw(15) << "Name" << setw(11) << "Act. Type" << setw(10) << "Charge" << setw(10) << "Balance" << endl;
}


void read_record(string& name, double& balance, char& type, int& mins1, int& mins2){//reads in record
    cin >> name >> balance >> type;

    if(type == 'R'){
        cin >> mins1;
    }
    else if(type == 'P'){
        cin >> mins1 >> mins2;
    }
}


double compute_charge(char type, int mins1, int mins2){
    int chargedminutes, chargedminutes2;
    double charge;

    if(type == 'R'){
        if(mins1<=REGMINS)
            chargedminutes =0;
        else
            chargedminutes = mins1 - REGMINS;

        charge = chargedminutes*REGRATE + REGMONTH;
        return charge;
    }

    else if(type == 'P'){
        if(mins1<=DAYMINS)
            chargedminutes =0;
        else
            chargedminutes = mins1 - DAYMINS;

        if(mins2<=NIGHTMINS)
            chargedminutes2 =0;
        else
            chargedminutes2 = mins2 - NIGHTMINS;

        charge = chargedminutes*DAYRATE + chargedminutes2*NIGHTRATE + PREMMONTH;
        return charge;
    }
    else return 0;

}

void compute_balance(double& balance, double charge){
    balance = balance + charge;
}

void print_bill(string account, string name, char type, double charge, double balance){
    string PorR;

    if(type == 'R')
        PorR = "Regular";
    else if(type == 'P')
        PorR = "Premium";

    cout << setw(8) << account << setw(15) << name << setw(11) << PorR << setw(10) << fixed << showpoint << setprecision (2) << charge << setw(10) << fixed << showpoint << setprecision (2) << balance << endl;
}
