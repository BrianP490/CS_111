/*****************************************
Brian Perez
cs111
Assignment 5
10/22/18
mailOrder.cpp

This program will charge customers of a clothing store from their catalogue.
*******************************************/
#include <iostream>
#include <iomanip>
#include "input.h"
void getcustomerInfo(int& account, int& month, int& day, int& year, char& code, string& county); 
char getCode(string msg);
void getItemsInfo(char& response, double& total, int& weight);
/*
double calcDiscount(int month);
double calcSalesTax(char code);
double calcShipping(int weight);
*/
using namespace std;


int main()
{
  int account; //store the account number
  int month; // store the month number
  int day; // store the day
  int year; // store the year
  char code; //store the county code
  string county; //store the county
  double total = 0; //store the total
  int weight = 0; //store the weight
  char response; //store the response of the user
  double disc; //store the discount
  double tax; //store the tax
  double ship; //store the shipping cost
  getcustomerInfo(account, month, day, year, code, county);
  cout << account << endl;
  cout << month << endl;
  cout << day << endl;
  cout << year << endl;
  cout << code << endl;
  cout << county << endl;
  /*  getItemsInfo(response, total, weight);

  disc = calcDiscount(month); //get the discount throught the function
  tax = calcSalesTax(code); //get the discount throught the function
  ship = calcShipping(weight); //get the discount throught the function
  outputInvoice(account, code, county, month, day, year, total, disc, tax, ship); //output t\
he invoice
  */
  return 0;
}

void getcustomerInfo(int& account, int& month, int& day, int& year, char& code, string& county) 
{
cout << "Enter an account number: ";
account = getInt(1000, 9999, "An account number must be 1000 - 9999. Enter again: ");

cout << "\nEnter a month: ";
month = getInt(1, 12, "A month must be 1 - 12. Enter again: ");

cout << "\nEnter a day: ";
day = getInt(1, 31, "A day must be 1 - 31. Enter again: ");

cout << "\nEnter a year: ";
year = getInt(2000, 2100, "A year must be 2000 - 2100. Enter again: ");

cout << "\nEnter a county code. Enter S, O or L: ";
code = getCode("Invalid county code. Enter uppercase S, O or L: ");
if( code == 'S') //get the full county
  county = "San Diego County";
 else if(code == 'O') //get the full county
   county = "Orange County";
 else //get the full county
   county = "LA County";
}

/**************************************
msg is the message shown when the user's input was invalid
This function will how a text and will continue to show the text until a valid country code is entered. This will return the country code.
**************************************/
char getCode(string msg) 
{
  char co; //user's input
  cin >> co;
  
  while(co != 'S' && co != 'O' && co != 'L') //loop until a valid input is put
    {
      cout << msg; //show the message to get valid input
      cin >> co; //store the new input
    }
  return co; //return county code
}


void getItemsInfo(char& response, double& total, int& weight)
{
  cout << "\nDo you want to order an item? Enter Y or N: ";
  response = getYN("Invalid response. Enter uppercase Y or N: ");
  
  while(response == 'Y') //ask for price and weight if user enters Y
    {
      cout << "\n\tEnter a price: ";
      total += getDouble(0.00, 999.99, "A price must be between 0.00 and 999.99. Enter again: \
");
      
      cout << "\n\tEnter a weight: ";
      weight += getInt(0, 99, "A weight must be between 0 and 99. Enter again: ");
      
      cout << "\nDo you want to order an item? Enter Y or N: ";
      response = getYN("Invalid response. Enter uppercase Y or N: ");
    }
 }

/***************************************
month is the month number of the purchase
This function will get a valid month numberand figure out the right discount. The function will return a valid discount.
****************************************/
double calcDiscount(int month)
{
  double disc; //store the discount  
  if(month >= 1 && month <= 5) //get the discount for month 1-5
   disc = .05;
 else if(month >= 6 && month <= 8)  //get the discount for month 6-8
   disc = .10;
 else  //get the discount for the rest
   disc = .15;
  return disc; //return a discount %
}
/**************************************
code is the county code that will be used to find the tax
The function will return the tax according to the code.
**************************************/
double calcSalesTax(char code) 
{
  double tax; //store the tax
  if(code == 'L') //tax rate for LA county
    tax = .0825;
  else 
    tax = .0775; //taxes for the rest of the counties
  return tax; // return a valid tax
}
/**************************************
weight is the weight of the item being purchased
The function will get the shipping cost for the item.
*************************************/
double calcShipping(int weight)
{
  double ship; //store the shipping cost  
  if(weight > 50) //cost for shipping for over 50
    ship = 5 + (25)*.1 +(weight - 50)*.07; 
  else if(weight >= 26 && weight <=50) //cost for shipping for  26-50
    ship = 5 + (weight - 25)*.1;
  else if(weight <= 25) //cost for shipping for 25 and under
    ship = 5;
  return ship; //return the shipping cost
}

/**************************************
This function will show the invoice for the purchase.
************************************/
void outputInvoice(int account, char code, string county, int month, int day, int year, double total, double disc, double tax, double ship) 
 {
   cout << left << setw(40) << "\nACCOUNT NUMBER" << "COUNTY" << endl;
   cout << left << setw(40) << account  << county << endl;
   cout << "\nDATE OF SALE " << month << "/" << day << "/" << year << endl << endl;
   cout << left << setw(20) << "TOTAL SALE AMOUNT: " << "$" << right << setw(8)<< fixed << setprecision(2) << total << endl;
   cout << left << setw(20) << "DISCOUNT: " << "$" << right << setw(8) << total*disc << endl;
   cout << left << setw(20) << "SALES TAX: " << "$" << right << setw(8) << total*tax << endl;
   cout << left << setw(20) << "SHIPPING: " << "$" << right << setw(8) << ship << endl;
   cout << left << setw(20) << "TOTAL DUE: " << "$" << right << setw(8) <<(total - total*disc + total*tax + ship) << endl << endl;
}


