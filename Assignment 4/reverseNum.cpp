/**************************************
Brian Perez
CS111
Assignment 4
ReverseNum.cpp
10/5/18

This program will ask for a number and the program will show the number backwards.
**************************************/
#include <iostream>
using namespace std;

int main()
{
  int num; // store the user's number
  int rnum = 0; // store the reverse number
  int rev; // store the % (remaider) number
  
  // get the user's num
  cout << "Enter a number(N >= 0): ";
  cin >> num;
  
  while(num < 0) // loop until a positive number is entered
    { 
      cout << "Enter a number(N >= 0): ";
      cin >> num;
    }
  
  // find the reverse number
  do
    { 
      rev = (num % 10);
      rnum = (rnum * 10) + rev;
      num = (num / 10);
    }while(num !=0); //exit loop when user enters 0
  
  // give the reverse number to the user  
  cout << rnum << endl << endl;
  
  return 0;
}
