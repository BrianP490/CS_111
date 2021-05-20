/***************************************
Brian Perez
CS111
9/29/18
Assignment 3
TemperatureSwitch.cpp0

This program will convert a temperature between Fahrenheit and Celsius. (From F to C, or C to F.)
****************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // declare variables
  char type; // store the temperature type F or C
  int Cel; // store the temperature for Celsius
  int Fah; // store the temperature for Fahrenheit
  double answ; // store the double value 
  double fina; // store the converted temperature
  
  // get the user's input
  cout << "Which temperature do you have? Enter F for Fahrenheit or C for Celsius: ";
  cin >> type;
  cout << fixed << setprecision(2); // set decimal at two decimal  places
 
  // convert to the other type
  switch(type)
    { 
    case 'C': cout << "Enter a temperature in Celsius: "; 
      cin >> Cel;
      answ = (1.8)*Cel; // convert to double
      fina = answ + 32; // find the temperaute in the other unit
      cout << Cel << " Celsius = " << fina << " Fahrenheit" << endl << endl;
      break;
    case 'F': cout << "Enter a temperature in Fahrenheit: ";
      cin >> Fah;
      answ = (5 * (Fah - 32)); // convert to double
      fina = (answ / 9); // find the other unit's temperature
      cout << Fah << " Fahrenheit = " << fina << " Celsius" << endl << endl;
      break;
    default: cout << "Invalid choice " << endl << endl;
    }
  return 0;
}
