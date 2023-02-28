#include <iostream>
#include <string>
using namespace std;

bool failed_any(int courseGrade);
string grade_finder(bool failureflag, int gradeAverage);
string best_student(string studentID, int gradeAverage);
int previousBest = 0;

int main(){

    string studentID, courseName, bestStudent;
    int courseGrade;
    double gradeTotal = 0, gradeAverage;
    bool failureflag = false;


    cin >> studentID;
    while(studentID != "999"){
            gradeTotal = 0;
            cout << studentID << " Failed: ";


            for(int i=1; i <=8; i++){
                cin >> courseName;
                cin >> courseGrade;

                if(failed_any(courseGrade)){
                    cout << courseName << " ";
                    failureflag = true;
                }

                gradeTotal = gradeTotal + courseGrade;

            }

            gradeAverage = gradeTotal/8;
            string grade = grade_finder(failureflag, gradeAverage);
            bestStudent = best_student(studentID, gradeAverage);

            cout << " Average: " << gradeAverage << " Grade: " << grade << endl;

            cin >> studentID;
    }
cout << "Best student: " << bestStudent;

}

bool failed_any(int courseGrade){
    if(courseGrade < 40)
        return true;
    else return false;
}

string grade_finder(bool failureflag, int gradeAverage){
    if(failureflag)
        return "F";
    else if(gradeAverage >= 70)
        return "D";
    else if(gradeAverage < 70 && gradeAverage >= 60)
        return "P1";
    else if(gradeAverage < 60 && gradeAverage >= 50)
        return "P2";
    else if(gradeAverage < 50 && gradeAverage >= 40)
        return "P3";
    else return "F";
}

string best_student(string studentID, int gradeAverage){


    if(gradeAverage > previousBest)
        previousBest = gradeAverage;
        return studentID;
}
