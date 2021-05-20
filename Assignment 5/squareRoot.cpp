/**************************************
Brian Perez
CS111
Assignment 5
SquareRoot.cpp
10/26/18

This function will find the square root of a positive integer.
****************************************/
#include <iostream>
#include "input.h"
using namespace std;

int main()
{
  int num;//store the user's number
  int top;//store the top number
  int bot;//store the bottom number
  int pro1;//store the top numb squared
  int pro2;//store the bot numb squared
  int rem1;//store the remainder for the top numb
  int rem2;//store the remainder for the bottom numb
  double use;//store the number being used to divide the user's number
  double rem;//store the remainder for num/use

  cout << "Enter a positive integer number that you want to find the square root for: ";
  num = getInt(1, 9000000, "Enter a positive integer number between 1 and 9000000: ");

  for(top =1; (top * top) < num; top++)//loop to find the top number
    ;
  bot = (top - 1);//find the bot number
  
  pro1 = (top * top);//find the product
  
  if(pro1 == num)//cout the perfect square
    cout << top << " is the square root of " << num << endl << endl;
  else//find the square
    {
      if(pro1 >= num)//find the remainder to compare to rem2
	rem1 = (pro1 - num);
      else
	rem1 = (pro1 - num);
      
      pro2 = (bot * bot);
      
      if(pro2 >= num)//find the remainder 
	rem2 = (pro2 - num);
      else
	rem2 = (num - pro2);
            
      if(rem1 < rem2)//compare the twot remainders to find the closer number
	use = top;
      else
	use = bot;//use the bottom number to find approximate sqrt
      
      cout << "Start at " << use << endl;
      for(int i = 1; i <= 10; i++)//find the accurate square root number
	{
	  rem = (double)num / use; //find the quotient
	  use = (double)(use + rem)/2; //find the number to use to divide to find the remainder     
	}
      //output the square root
      cout << "The square root of " << num << " is " << use << endl;
      cout << "The square of the square root is " << num << endl << endl;
    }
  return 0;
}
