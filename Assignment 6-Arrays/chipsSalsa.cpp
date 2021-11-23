/***********************************
Brian Perez
CS 111
11/4/18
Assignment 6
chipsSalsa.cpp

This program keeps trach of sales for 5 different types of salsa.
************************************/
#include <iostream>
#include <iomanip>
#include "input.h"
void fillJarsSoldArray(const string sa[], int ar[]);
void printSales(const string sa[], const int ar[]);
int getTotal(const int ar[]);
void getHighestLowestSelling(const int ar[], int& hi, int& lo);
using namespace std;
const int SIZE = 5; //set global size of array

int main()
{
  //state the variables
  string sal[SIZE] = {"mild", "medium", "sweet", "hot", "zesty"};
  int array[SIZE];
  int total = 0;
  int high = 0;
  int low = 0;
  
  fillJarsSoldArray(sal, array);//fill the jars array
  printSales(sal, array);//show the amount of each salsa sold
  total = getTotal(array);//total up all the jars sold
  cout << "The total number of jars sold is " << total << endl;
  getHighestLowestSelling(array, high, low);//get both highest and lowest index
  cout << "The highest selling type is " << sal[high] << endl;
  cout << "The lowest selling type is " << sal[low] << endl << endl;
  return 0;
}
/************************************
string sa[] is the string array of salsa names
int ar[] is the int array for the amount bought
************************************/
void fillJarsSoldArray(const string sa[], int ar[])
{
  for(int i = 0; i < SIZE; i++)//get valid jar numbers for each flavor
    {
      cout << "Enter the number of jars sold for " << sa[i] << ": ";
      ar[i] = getInt(0, 1000000, "\tInvalid. Enter a number between 0 and 1000000: ");
      cout << endl;
    }
}
/************************************
string sa[] is the string array of salsa names
int ar[] is the int array for the amount bought
************************************/
void printSales(const string sa[], const int ar[])
{
  for(int i = 0; i < SIZE; i++)//show salsa name and number of jars
    {
      cout << left << setw(10) << sa[i] << right << setw(5) << ar[i] << endl;
    }
  cout << endl;
}
/************************************
int ar[] is the int array for the amount bought
This function will return the total
***********************************/
int getTotal(const int ar[])
{
  int total;//declare total
  for(int i = 0; i < SIZE; i++)//add up all the jars
    total += ar[i];
  
  return total;//return total to main
}

/************************************
int ar[] is the int array for the amount bought
int& hi is the pass by reference for highest index
int& lo is the pass by reference for lowest index
************************************/
void getHighestLowestSelling(const int ar[], int& hi, int& lo)
{
  for(int i = 1; i < SIZE; i++)//find the highest number's index
    if(ar[i] > ar[hi])
      hi = i;//set highest index to number
  
  for(int i = 1; i <SIZE; i++)//find the lowest number
    if(ar[i] < ar[lo])
      lo = i;//set low to that index 
}
