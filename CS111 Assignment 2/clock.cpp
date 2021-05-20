/****************************************************************************
Brian Perez
CS 111
Assignment 2
9/19/2019

This program will ask for a time and will display the angles of both hands on the clock.
*****************************************************************************/
#include <iostream> //for cin, cout
#include <cmath>
using namespace std;

int main()
{

  // declare variables
  int hr; // store hours
  int min; // store minutes
  double ahr; // store angle of hour hand
  double amin; // store angle of minute hand
  

  // get time from user
  cout << "Enter hours: " ;
  cin >> hr;
  
  cout << "Enter minutes: " ;
  cin >> min;
  

  // convert hour hand to angles
  ahr = hr * 30 + min *.5;

  // convert minute hand to angle
  amin = min * 6;

  // output the angle of the hour and minute hands
  cout << "The angle of the hour hand is : " << ahr << endl;
  cout << "The angle of the minute hand is : " << amin << endl << endl;
  

  return 0;
}
