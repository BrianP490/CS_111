/*******************************************************************************
Brian Perez
CS 111
Assignment 2
9/19/2018

This program will ask the user for a time, in seconds, and the program will convert it into hours, minutes, and seconds.
*******************************************************************************/

#include <iostream> // for cin and cout
using namespace std; 

int main()
{
  // declare variables
  const int S2H = 3600; // store conversion from seconds to hours
  const int S2M = 60; // store conversion grom seconds to minutes
  int sec; // store seconds
  int min; // store minutes
  int hr; // store hours
  int rse; // store remaining seconds

  // get number of seconds from the user
  cout << "Enter the time in seconds: ";
  cin >> sec;

  // convert seconds to hours, minutes, and seconds
  hr = sec / S2H;
  rse = sec % S2H;
  min = rse / S2M;
  rse = sec % S2M;

  // output the hours, minutes, and seconds
  cout << endl;
  cout << hr << " hours " << min << " minutes " << rse << " seconds " << endl << endl;

  return 0;
}
