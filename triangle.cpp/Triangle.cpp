/******************************
Brian Perez
CS111
triangle.cpp
11/27/18

This program will determine the type of triangle that the user's creates with three points.
*******************************/
#include <iostream>
#include <iomanip>

using namespace std;
#include "myMath.h"

void getPoints(int point, int& xco, int& yco);
double length(int x1, int y1, int x2, int y2);
void type(double len1, double len2, double len3);

int main()
{
  char ch;//store the enter press
  int x1;//store the x value of the first point
  int y1;//store the y value of the first point
  int x2;//store the x value of the second point
  int y2;//store the y value of the second point
  int x3;//store the x value of the third point
  int y3;//store the y value of the third point
  double len1;//store the first length
  double len2;//store the second length
  double len3;//store the third length
  
  cout << "\n*******************************" << endl << "This program will ask you to enter 3 points of a triangle and tell what kind of triangle it is. Please hit ENTER to continue." << endl << "*******************************" << endl;
  cin.get(ch);
  //get the three coordinates
  getPoints(1, x1, y1);
  getPoints(2, x2, y2);
  getPoints(3, x3, y3);
  //get three lengths
  len1 = length(x1, y1, x2, y2);
  len2 = length(x2, y2, x3, y3);
  len3 = length(x1, y1, x3, y3);
  //find the type of triangle
  type(len1, len2, len3);
  cout << endl;
  return 0;
}

/**************************
int point is the point number
int& xco is the x coordinate passed by reference
int& yco is the y coordinate passed by reference
This function will get inputs for a point
***************************/
void getPoints(int point, int& xco, int& yco)
{
  cout << "Point " << point << endl; //show which point is asked for
  cout << "\tEnter the x-cordinate: ";//input x
  cin >> xco;
  cout << "\tEnter the y-cordinate: ";//input y
  cin >> yco;
  cout << endl;
}

/**************************************
int x1 and int y1 is the first endpoint
int x1 and int y1 is the other endpoint
This will determine the length of the side
***********************************/
double length(int x1, int y1, int x2, int y2)
{
  int subx;//store the difference of x values
  int suby;//store the difference of y values
  int xpow;//store the subx squared
  int ypow;//store the suby squared
  
  subx = x2 - x1;//find the difference of the x coordinates
  suby = y2 - y1;//find the difference of the y coordinates
  
  xpow= pow(subx, 2);// square the difference for the x coordinate
  ypow = pow(suby, 2);//square the difference for y coordinate
  
  return sqrt(xpow + ypow); //return the length of the side
}

/**********************************
double len1 is the length of the first side
double len2 is the length of the second side
double len3 is the length of the third side
This function will determine the type of triangle it is
************************************/
void type(double len1, double len2, double len3)
{
  int equ = 0; //store the number of sides that are equal
  len1 = fabs(len1);//find absolute value of length1
  len2 = fabs(len2);//find absolute value of length2
  len3 = fabs(len3);//find absolute value of length3
  
  if(fabs(len1 - len2) < 0.00001)//these 2 sides are same
    equ += 2;//add 2 to number of sides equal
  if(fabs(len2 - len3) < 0.00001)//these 2 sides are same
    equ += 2;
  if(fabs(len1 - len3) < 0.00001)//these sides are same
    equ += 2;
  
  switch(equ)
    {
    case 0: cout << "This triangle is scalene " << endl;//no sides are the same
      break;
    case 2: cout << "This triangle is isosceles" << endl;//only 2 sides are the same
      break;
    case 6: cout << "This triangle is equilateral" << endl;//all the sides are the same
      break;
    }
}

