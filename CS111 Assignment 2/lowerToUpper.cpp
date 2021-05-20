/**********************************************************************
Brian Perez
CS111
Assignment 2
9/19/2018

This program will ask for a lowercase letter and will give the user the uppercase letter.
***************************************************************************/
#include <iostream>
using namespace std;

int main()
{

  // declaring variables
  char l; // store the lowercase letter
  char L; // store the uppercase letter
  int a1; // ascii version of lowercase letter 
  int a2; // ascii version of uppercase letter
 
  // get input from user
  cout << "Enter a lowercase letter: ";
  cin >> l;

  // converting the lowercase letter to uppercase
  a1 = l; 
  a2 = a1 - 32;
  L = a2;
  //shorter way: L = l - 32; or l = l - 32;
  // showing outputs to the user
  cout << "The uppercase is " << L << "." << endl << endl; 

  return 0;
}

