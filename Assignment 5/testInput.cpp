/**********************************
Brian Perez
CS111
10/23/18
assignment 5
testInput.cpp
This will get valid inputs for the age, score, gpa, and response. 
**********************************/
#include <iostream>
using namespace std;
#include "input.h" //include input.h

int main()
{
  int age; //store the age of user
  int score; //store the test score
  double gpa; // store the user's gpa
  char resp; // store the response of the user
  
  cout << "Enter an age: ";
  age = getInt(0, 200, "An age must be between 0 and 200. Enter again: "); // get age
  cout << "age = " << age << endl;//show age input
  
  cout << "\nEnter a test score: ";
  score = getScore(0, 100, "A test score must be between 0 and 100. Enter again: "); // get test score
  cout << "score = " << score << endl; //show the score
  
  cout << "\nEnter a test score: ";
  gpa = getDouble(0.00, 4.00, "A GPA must be between 0.00 amd 4.00. Enter again: "); // get a gpa
  cout << "gpa = " << gpa << endl;//store gpa
 
  cout << "\nAre you a college student? Enter Y or N: ";
  resp = getYN("Your response must be uppercase Y or N. Enter again: "); // get a response
  cout << "ans = " << resp << endl << endl;//show response
  
  return 0;
}
