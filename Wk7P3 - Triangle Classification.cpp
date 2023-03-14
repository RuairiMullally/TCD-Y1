#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1,double y1,double x2,double y2);
int triangle_type(double x1,double y1,double x2,double y2, double x3, double y3);
bool very_close (double x, double y);





int main(){
    double x1, y1, x2, y2, x3, y3;
    int type;

    cout << "Enter x1, y1, x2, y2, x3, y3:";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    type = triangle_type(x1, y1, x2, y2, x3, y3);

    cout << "That is ";
    if(type == 3)
        cout << "equilateral";
    else if(type == 2)
        cout << "isoceles";
    else if(type == 0)
        cout << "scalene";

    cout << ".\n";


    return 0;
}

double distance(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
}

int triangle_type(double x1,double y1,double x2,double y2, double x3, double y3){
    double side1, side2, side3;
    side1 = distance(x1, y1, x2, y2);
    side2 = distance(x2, y2, x3, y3);
    side3 = distance(x3, y3, x1, y1);

    if(very_close(side1, side2) && very_close(side2, side3) && very_close(side3, side1))
        return 3;
    else if( very_close(side1, side2) || very_close(side2, side3) || very_close(side3, side1))
        return 2;
    return 0;
}

bool very_close (double x, double y){
    return (fabs (x-y) < 0.0001);
}


