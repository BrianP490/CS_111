 /*****************************************
Brian Perez
CS111
Assignment 5
CrapsStat.cpp
10/19/18

This program will simulate 'X' amount of games of craps and will tell the user the probability of winning and losing.
******************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "input.h"
int rollDice();
bool playGame();

using namespace std;
/*********************************
This function simulates rolling a pair of dice. It will return a random number between 2 and 12.
**********************************/
int rollDice()
{
  int roll;//store the random roll

  roll = (rand()% 6 + 1) + (rand()% 6 + 1);  
  return roll; //return the reandom roll to main 
}
/*********************************
This function will calculate if the game wins or loses. It will return the wins
**********************************/
bool playGame()
{
  int roll = 0; // store the rolls after the first roll
  int fr; //store first roll
  bool win = false;  //store true if game is a win

  fr = rollDice(); //generate first roll
  
  if(fr == 7 || fr == 11) //add to win if first roll is 7 or 11  
   win = true;  
  else if(fr == 2 || fr == 3 || fr == 12) //dont add win if roll is 2,3, or 12
    ;//lost/do nothing
  else //keep rolling until win or lose
    {
      do
	{       
	  roll = rollDice();//roll again to get next roll
	  
	  if(roll == 7)  
	    ;//lost	      
	  else if(roll == fr)
	    win = true;
	  
	}while(roll != 7 && roll != fr);//keep repeating until roll is 7 or fr
    }
  return win;//returns the number of wins
}

int main()
{
  srand(time(0));
  int games;//store the number of games teh user wants
  int win = 0;//store number of games
  bool torf;//store if win is true or false

  cout << "How many games do you want to play?: ";
  games = getInt(1, 100000000, "You need to input a number between 1 and 100000000: ");

  for(int i = 0; i < games; i++)//get the total number of wins that happened 	
    {
      torf = playGame();
      if(torf == true)    
	win += 1;
    }
  //display the results
  cout << setw(10) << "Win %" << setw(10) << "Lose %" << endl; 	
  cout << fixed << setprecision(3) << setw(10) <<(double)win/games*100 << setw(10) << ((double)(games - win)/games)*100 << endl;
  return 0;
}
