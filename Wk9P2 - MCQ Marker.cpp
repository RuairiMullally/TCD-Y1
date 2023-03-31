#include <iostream>
using namespace std;

void readInData(char answers[], int SIZE);
int questionScorer(const char answers[], char attempt[], int SIZE);
int examScorer(const char answers[], char attempt[], int SIZE);
int scoreAttempts(const char answers[], char attempt[], int SIZE);

int main() {
  const int SIZE = 20; //length of MCQ test
  char answers[SIZE], attempt[SIZE];
  int score = 0;
  int studentID;


  readInData(answers, SIZE);//read in answers to reference
  cin >> studentID;


  while(studentID >0){//while there is a valid studentID, the program will mark tests and output the result

    score = scoreAttempts(answers, attempt, SIZE);
    cout << studentID <<": "<<score<<endl;
    cin >> studentID;
  }


}

void readInData(char answers[], int SIZE){//reads in answers
  for(int i=0; i<SIZE; i++)
    cin >> answers[i];
}

int questionScorer(const char answers[], char attempt[], int SIZE, int question_num){//compares array to answer array and return te mark for that q
  if(attempt[question_num] == 'x')
    return 0;
  else if(attempt[question_num] == answers[question_num])
    return 2;
  return -1;
}

int examScorer(const char answers[], char attempt[], int SIZE){//returns the sum of marks for all questions
  int mark = 0;
  for(int i=0; i<SIZE; i++){
    mark += questionScorer(answers, attempt, SIZE, i);
  }
  return mark;
}

int scoreAttempts(const char answers[], char attempt[], int SIZE){//reads in an attempt and returns the score for that attempt
  readInData(attempt, SIZE);
  int score = examScorer(answers, attempt, SIZE);
  return score;

}
