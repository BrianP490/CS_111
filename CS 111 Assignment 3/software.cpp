/********************************************************
Brian Perez
CS111
9/29/18
Assignment 3
Software.cpp

This program will ask for today's date, the company name and the quantity they want to buy. The program will display the cost.
********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // declaring variables
  const double DIS2 = .2; // constant for 20%
  const double DIS3 = .3; // constant for 30%
  const double DIS4 = .4; // constant for 40% 
  const double DIS5 = .5; // constant for 50%
  string date; // store date 
  string comp; // store company name
  int quan; // store the amount of the item
  double disco; // store the amount saved
  double tota; // store the price before the discount
  double per; // store the discount
  double due; // store final price
  
  // get user inputs
  cout << "Enter today's date (mm/dd/yy): ";
  cin >> date;  
  cin.ignore();
  cout << "Enter your company name: " ;
  getline(cin,  comp);
  cout << "Enter the quantity you would like to purchase: " ;
  cin >> quan;
  
  // check if quantity is 0 or negative
  if (quan <1)
    { 
      if (quan <0)
	cout << endl << "Invalid quantity" << endl << endl;
      else
	cout << endl << "Hope you decide to buy our software in the future." << endl << endl;
    }
  // find the discount 
  else
    {
      if (quan >=10 && quan <=19)
	per = DIS2;
      else if (quan >=20 && quan <=49)
	per = DIS3;
      else if (quan >=50 && quan <=99)
	per = DIS4;
      else if (quan >=100)	
        per = DIS5;
      else 
	per = 0;
      
      // calculate price, discount, and total due
      cout << fixed << setprecision(2);    
      tota = 99 * quan; // find the total price
      disco = tota * per; // find the discount
      due = tota - disco; // find the final total due
      
      // display the prices 
      cout << endl << "Invoice for "<< comp << endl << endl; 
      cout << left << setw (30) << "Price before discount" << "$" << right << setw (10) << tota << endl;
      cout << left << setw (30) << "Discount" << "$" << right << setw (10) << disco << endl;
      cout << left << setw (30) << "Total Due" << "$" << right << setw (10) << due << endl << endl;
      
    }
  return 0;
 }
