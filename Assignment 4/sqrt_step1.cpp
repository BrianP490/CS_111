/************************************
Brian Perez
CS111
Assignment 4
Sqrt-step1.cpp
10/6/18

This program will figure out the top and bottom number for the square root of a positive integer.
*************************************/
#include <iostream>
using namespace std;

int main()
{
  // declare variables
  int num; // store the user's number
  int top; // store the top number
  int bot; // store the bottom number

  // get the number from the user
  cout << "Enter Num: ";
  cin >> num;
  
  // loop to find the top number
  for(top = 1; (top * top) < num ; top++)
    ;
  
  // give the top and bottom number  
  cout << "Top is " << top << endl;
  cout << "Bottom is " << (top -1) << endl << endl;
  
  return 0;
}
