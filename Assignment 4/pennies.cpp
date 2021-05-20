/**************************************
Brian Perez
CS111
Assignment 4
Pennies.cpp
10/5/18

This program will calculate the earnings of someone starting with a penny and 2 pennies the second day, and coutinuing to double each day.
***************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // declare the variables
  int days; // store the days worked
  int row; // store the row number
  double pay = .01; // store the pay
  double total; // store the total earned
  
  // get the number of days until the user wants to stop
  do 
    {
      cout << "Enter the number of days you worked: ";
      cin >> days;
    }while(days < 1);
  
  // display the table  
  for(int row = 1; row <= days; row++) // for loop for the rows
    {     
      cout << setw(5) << row << setw(10) << pay << endl;
      total += pay;
      pay = pay * 2;
    }
  cout << endl;
  
  // show the total 
  cout << "Total " << setw(9) << total << endl << endl;
  
  return 0;
}
