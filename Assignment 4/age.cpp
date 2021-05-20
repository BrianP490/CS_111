/**************************************
Brian Perez
CS111
Assignment 4
Age.cpp
10/5/18

This program will read 'x' amount of ages until a negative number is entered. The program will give the average age, the # of minors, # of adults, and the youngest and oldest ages.
***************************************/
#include <iostream>
using namespace std;

int main()
{
  int age; // store the age of the users
  int oldest = -999; // store the oldest age
  int youngest = 999; // store the youngest age
  int minor = 0; // store the number of minors
  int adult = 0; // store the number of adults
  int total = 0; // store the total age
  int count = 0; // store the amount of ages entered
  
  // get the user's input
  cout << "Enter an age: ";
  cin >> age;
  
  // categorize each number
  while(age >= 0)
    {
      if(age > oldest) // for oldest number
	oldest = age;
      if(age < youngest) // for youngest number
	youngest = age;   
      if(age >= 18) // if they are an adult
	adult++;
      else // if they are a minor
	minor++;
      total += age; // add up the ages so far
      count++;
      cout << "Enter an age: "; // get the next age
      cin >> age;
    }
  // output the results
  if(count == 0)
    cout << "\nNo ages were entered " << endl << endl;
  else // if the user enters at least 1 number
    {
      cout << endl << (double)total/count << " (average) " << endl;
      cout << minor << " (minors) " << endl; // shows minors
      cout << adult << " (adults) " << endl; // shows adults
      cout << oldest << " (oldest) " << endl;
      cout << youngest << " (youngest) " << endl << endl;
    }
  
  return 0;
}
