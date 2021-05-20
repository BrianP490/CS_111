/*******************************************************
Brian Perez
CS111
9/29/18
Assignment 3
ElectricBill.cpp

This is a billing program for Mission Viejo Electric Cumpany. This program will ask for some of the user's information and will show the consumption levels and bill.
******************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // declare variables
  string name; // store user's first name
  char ch; // for the enter button 
  int mthn; // store the user's month number
  int kwh; // store the kwh for billing
  int cmet; // store the current meter reading
  int pmet; // store the previous meter reading
  double bill; // store the total bill
  
  // get the user's information
  cout << "Enter your first name: ";
  cin >> name;
  cin.ignore(1);  //clears the input stream
  cout << endl << "Welcome, " << name << "!";
  cout << endl << "This program will ask for the month and current and previous meter readings then calculate your electric bill. Please press \"ENTER\" to continue. ";
  cin.get(ch);
  cout << endl << "Enter the month: ";
  cin >> mthn;
  if (mthn < 1 || mthn > 12) // determines if input is bad
    cout << mthn <<  " is an invalid month " << endl <<  endl;
  else
    { 
      cout << "Enter the current meter reading: ";
      cin >> cmet;
      cout << "Enter the previous meter reading: ";
      cin >> pmet;
      kwh = cmet - pmet; // finds the amount of energy used that month        
      cout << fixed << setprecision(2); // linit to only 2 decimal places
      if (cmet <0 || cmet < pmet || pmet <0) // determines if meter readings are bad
	{
	  cout << "The readings are invalid " << endl << endl;
	}
      else
	{
	  if (kwh >= 1 && kwh <= 400)
	    bill = 8.50;
	  else if (kwh > 400)
	    {
	      if (mthn >= 5 && mthn <= 9)
		bill = 8.50 + (kwh - 400) * .07525; // find the bill
	      else
		bill = 8.50 + (kwh - 400) * .06575; // find the bill for monthss 5-9
	    }
	  cout << endl << "You consumed " << kwh << " KWH and your amount due is $" << bill << endl << endl;
	}
    }
  return 0;
}
