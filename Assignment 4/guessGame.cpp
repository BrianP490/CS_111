/**************************************
Brian Perez
CS111
Assignment 4
guessGame.cpp

The program will ask the user to guess a random number generated from 1 to 100.
***************************************/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
  // declare variables
  srand(time(0)); // generate a number
  int num; // store the generated number
  int guess; // store the user's guess
  
  // generate a random number and get the user's guess
  num = rand()% 100 + 1;     //the num is between 1 and 100
  cout << "Guess a number between 1 and 100. Enter your guess: ";
  cin >> guess;
  
  // runs until they get the number correct
  while(guess != num)
    {
      if(guess > num) // tell the user to try again
	cout << setw(28) << "Too high, try again. " << endl;
      else // tell the user to try again
	cout << setw(28) <<  "Too low, try again, " << endl;
      cout << "Enter your guess: ";
      cin >> guess;   
    }
  
  // congradulates the user for correct answer
  if(guess == num)
    cout << "You guessed it right! " << endl << endl << "The progrma will now end. Goodbye!!!" << endl;
  
  return 0;
}
