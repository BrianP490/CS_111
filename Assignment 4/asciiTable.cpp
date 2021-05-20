/**************************************
Brian Perez
CS111
10/5/18
Assignment 4
AsciiTable.cpp

This program will display the characters for the ASCII values from 33 through 126
*************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // set variables
  int row = 1; // store the row number
  int colum = 1; // store the counter
  int n = 33; // store the ascii value
  
  // print out the ascii Table 
  while(row <= 7) // makes 7 rows
    {
      while(colum <= 15 && n <= 126)  // keeps 15 characters and stops when n <= 126
	{  
	  colum++;
	  cout << (char) n << " ";   //typecast an int and display it as a character
	  n++;
	}
      cout << endl; 
      colum = 1; 
      row++;
    } 
  
  return 0;
}
