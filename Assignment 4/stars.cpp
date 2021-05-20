/**************************************
Brian Perez
CS111
Assignment 4
Stars.cpp
10/5/18

This program will ask for a value for n then the program will show 1 star on the first line, 2 stars on the second line, ... n stars on the nth line.
***************************************/
#include <iostream>
using namespace std;

int main()
{
  // identify the variables
  int n; // store the value of n
  int row =1 ; // store the row number
  int col = 1; // store the column number
  
  // get the user's number
  cout << "n = ";
  cin >> n;
  
  // display the *'s 
  for(int row = 1; row <= n; row++ ) 
    {
      for(int col = 1; col <= (n-row); col++)// makes the spaces
	cout << " ";
      
      for(int col = 1; col <= row; col++ ) // mades the *'s
	cout << "*";
      
      cout << endl;// makes the line end
    }
  return 0;
}
