/************************************
Brian Perez
CS111
9/29/18
Assignment 3
Sqrt_step2.cpp
 
This program will require the user to input the number, a top number and a bottom number. Then, it will calculate the number that is closest to the square root of an integer number. Finally, the program will show which number(top or bottom) is closest to the square root of the given number.
*************************************/
#include <iostream>
using namespace std;

int main()
{
  // declare the variables
  int num; // store the user's number
  int top; // store the top number
  int bot; // store the bottom number
  int pro1; // store the product of the top number
  int pro2; // store the product of the bottom number
  int rem1; // store the remainder of the top number
  int rem2; // store the remainder of the top number
  
  // get user's input
  cout << "Num = ";
  cin >> num;
  cout << "Top = ";
  cin >> top;
  cout << "Bottom = ";
  cin >> bot;
  
  // find the products and remainsers of top and bottom
  pro1 = (top*top); // find the product of the top number

  if (pro1 >= num) 
    rem1 = (pro1-num); // find the remainder for the top number if product > number
  else
    rem1 = (num-pro1); // find the remainder for the top number
  
  pro2 = (bot*bot); // find the product for the bottom number
  
  if (pro2 >= num) 
    rem2 = (pro2-num); // find the remainder for the top number if product > number
  else
    rem2 = (num-pro2); // find the remainder for the top number
  
  
  // give the square root of the number  
  if (rem1 < rem2) // the smaller number has is the closest to the actual squareroot
    cout << "Top is closer to the square root of " << num << "." << endl << endl;
  else
    cout << "Bottom is closer to the square root of " << num << "." << endl << endl;
  
  return 0;
}
