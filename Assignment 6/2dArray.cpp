/***************************************************************
Brian Perez
CS111
11/2/2018
Assignment 6
2dArrays.cpp
Show the test scores of the students in the class.
***************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;
const int NUM_STU = 5;
const int NUM_TEST = 3;
void showTable(const int ar[][NUM_TEST]);
void fillArray(int ar[][NUM_TEST], int t, int s);

int main()
{
  int total; // store the total
  int ar[NUM_STU][NUM_TEST]; //declare the array
  fillArray(ar, NUM_TEST, NUM_STU); //fill the array
  showTable(ar); //show the table
  cout << endl; 
  return 0;
}
/**********************
ar is the array from the main
int t is the number of tests 
int s is the number of students
************************/
void fillArray(int ar[][NUM_TEST], int t, int s)
{
  int score; //store the score
  for(int T = 0; T < t; T++) //go through each test 
    {
      cout << "Enter scores for Test #" << T + 1 << endl;
      for(int i = 0; i < s; i++) //go through each student
	{
	  cout << setw(14) << "Student #" << i + 1 << ": ";
	  cin >> score; 
	  ar[i][T] = score; //get a score from user
	}
      cout << endl;
      
    }
}
void showTable(const int ar[][NUM_TEST])
{
  int total = 0;  
  //Show the lables for the table
  cout << setw(8) << "Test#" << setw(10) << "Stu 1" << setw(10) << "Stu 2" << setw(10) << "Stu 3" << setw(10) << "Stu 4" << setw(10) << "Stu 5" << setw(10) << "Average" << endl;
  
  //Show the table using a nested for loop here
  for(int test = 0; test < NUM_TEST; test++)
    {
      cout << setw(8) << test + 1;
      
      for(int stu = 0; stu < NUM_STU; stu++) //loop for each student
	{
	  cout << setw(10) << ar[stu][test];
	  total += ar[stu][test];
	}
      cout << setw(10) << fixed << setprecision(1)<< (double)total/NUM_STU; 
      total = 0;
      
      cout<< endl;
    }
  
  total = 0; //reset total
  cout << left << setw(8) << "Averages";  
  for(int stu = 0; stu < NUM_STU; stu++) //go through each student
    {
      for(int tes = 0; tes < NUM_TEST; tes++) //go through each test
	total += ar[stu][tes];
      
      cout << right << setw(10) << fixed << setprecision(1) << (double)total/NUM_TEST; 
      total = 0;    
    }
  cout << endl;
}
