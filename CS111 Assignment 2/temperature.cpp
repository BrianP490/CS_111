/************************************************************************
Brian Perez
CS111
Assignment 2
9/19/2018

This program will ask for a Celsius temperature and convert it to Fahrenheit rounded to the nearest integer.
***************************************************************************/

#include <iostream> // for cin and cout
using namespace std;

int main()
{
  // declare variables

  double c; // store celsius information
  double F; // store fahrenheit
  int R; // store rounded fahrenheit 

  // get user's information
  cout << "Enter a temperature in Celsius: ";
  cin >> c;

  // convert Celsius to Farenheit
  F = 1.8*c + 32;
  R = F + .5;
 
  // display outputs
  cout << endl; 
  cout << c << " C = "  << R << " F " << endl << endl;

  return 0;
}
