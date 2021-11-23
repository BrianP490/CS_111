/***********************************
Brian Perez
CS111
Lab 6-1
array.cpp
Assignment 6
This program will reverse a number within the array
***********************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
void fillArray(int ar[], int s);
void printArray(const int ar[], int s);
void reverseNum(int ar[], int s);
double getAvg(const int a[], int s);
int getHighest(const int a[], int s);
void doubleArray(int a[], int s);
void showBarGraph(int a[], int s);
int sequentialSearch(const int a[], int s, int key);
int binarySearchAscend(const int a[], int s, int key);
void selectionSortAscend(int array[], int N);
int binarySearchDescend(const int a[], int s, int key);
void selectionSortDescend(int array[], int N);
using namespace std;

int main()
{
  
  const int SIZE = 5; //the size of the array
  int ar[SIZE];//make the array 
  int choice;//store the input of the user
  int key;//store the number that the user wants to find in the array
  int index;//store the location of the array  
  double avg; //store the average 
  int high; //store the highest
  do{
    //show the menu of the main
    /**********************
  cout << "======================" << endl;
  cout << "1: fill the array" << endl;
  cout << "2: print the array" << endl;
  cout << "3: reverse the contents of the array" << endl;
  cout << "4: find the average" << endl;
  cout << "5: find the highest number" << endl;
  cout << "6: double" << endl;
  cout << "7: graph" << endl;
  cout << "8: sort the array in ascending order" << endl;
  cout << "9: sort the array in descending order" << endl;
  cout << "11: binary search for an ascending list" << endl;
  cout << "12: binary search for an descending list" << endl;
  cout << "13: quit" << endl;
  cout << "==========" << endl;
    **********************/
    cout << "-----------------------------------------------------" << endl;
    cout << "1)fill 2)print 3)reverse 4)average 5)highest 6)double 7)bar graph 8)selection sort ascending 9)selection sort descending 10)sequential search 11)binary search ascending 12)binary search descending 13)quit" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice)
      {
      case 1://filling the array
	{
	  cout << endl;
	  fillArray(ar, SIZE);          
	  break;
	}
      case 2: printArray(ar, SIZE);//show the array contents
	break;
      case 3:
	{
	  cout << endl;
	  reverseNum(ar, SIZE);//reverse the array
	  break;
	}
      case 4: 
	{
	  avg = getAvg(ar, SIZE); //get and display the average
	  cout <<"\nThe average number is " << avg << endl << endl;
	  break;
	}
      case 5:
	{
	  high = getHighest(ar, SIZE); //get and display the highest number
	  cout << "\nThe highest number is " << ar[high] << endl << endl;
	  break;
	}
      case 6:
	{
	  doubleArray(ar, SIZE);//double the values of the array
	  cout << endl;
	  break;
	}
      case 7: 
	{
	  cout << endl;
	  showBarGraph(ar, SIZE);//show the graph with *'s
	  cout << endl;
	  break;
	}
      case 8: 
	{
	  selectionSortAscend(ar, SIZE);//arrange the array in ascending order
	  cout << endl;
	  break;
	}
      case 9:
	{
	  selectionSortDescend(ar, SIZE);//sort the array in descending order
	  cout << endl;	
	  break;
	}
      case 10:
	{
	  cout << "\nEnter a key: ";
	  cin >> key;
	  index = sequentialSearch(ar, SIZE, key);
	  if(index == -1)//if index is -1, the key was not found
	    {
	      cout << endl;          
	      cout << key << " was not found" << endl << endl;
	    }       
	  else//if the key was found
	    cout << endl << key << " was found at index " << index << endl << endl;
	  break;
	}    
      case 11: 
	{	
	  cout << "\nEnter the key: ";     
	  cin >> key;
	  index = binarySearchAscend(ar, SIZE, key);//get the index
	  if(index == -1)//display if index was not found
	    {
	      cout << endl;
	      cout << key << " was not found" << endl << endl;
	    }
	  else//display thekey and index
	    cout << endl << key << " was found at index " << index << endl << endl;
	  break;
	}      
      case 12:
	{
	  cout << "\nEnter the key: ";
	  cin >> key;
	  index = binarySearchDescend(ar, SIZE, key);//get the index 
	  if(index == -1)//the key was not found
	    { 
	      cout << endl;
	      cout << key <<" was not found" << endl << endl;
	    }
	  else//the key was found
	    cout << endl << key << " was found at index " << index << endl << endl;
	  break;      
	} 
      case 13:
	{
	  cout << "\nThank you for using our system." << endl << endl;
	  break;
	}
      default: cout << "\nInvalid choice" << endl << endl;
      }
  }while(choice != 13);//loop until the user wants to quit
  
  return 0;
}


/************************
ar is the array being used to write in the numbers
s is the size of the array
This function will fill the array with numbers from the keyboard.
************************/
void fillArray(int ar[], int s)
{ 
  int num;
  for(int i = 0; i < s; i++)//get the array filled
    {
      cout << "Enter a number: ";
      cin >> num;
      ar[i] = num;  
    }
  cout << endl;    
}
/************************
ar is the array being used to write in the numbers
s is the size of the array
This function will display the numbers entered from the keyboard
*************************/
void printArray(const int ar[], int s)
{   
  cout << "\nThe numbers entered in the array are: ";
  for(int i = 0; i < s; i++)//show the array
    cout << ar[i] << " ";
  cout << endl << endl;
}

/**************************
s is the size of the array
ar is the array being used to write in the numbers
This function will reverse the contents of the array within the array.
***************************/
void reverseNum(int ar[], int s)
{
  for(int X = 0, r = s - 1; X < s/2; X++, r--)//reverse the array
    {
      int temp = ar[X];
      ar[X] = ar[r];
      ar[r] = temp;
    }
}
/**************************
s is the size of the array
a is the array from main
This function will return the average 
**************************/
double getAvg(const int a[], int s)
{
  int total = 0;
  for(int i = 0; i < s; i++)//add up all the numbers
    total += a[i];
  return (double)total/s;
}

/***************************
a is the array of the main
s is the size of the array
This function will return the index of the largest number.
***************************/
int getHighest(const int a[], int s)
{
  int highIndex = 0;
  for(int i = 0; i < s; i++)
    if(a[i] > a[highIndex])
      highIndex = i;
  return highIndex;
}
/*************************
s is the size of the array
a[] is the array of the main
This function will double all the values in the array
*************************/
void doubleArray(int a[], int s)
{
  for(int i = 0; i < s; i++)//double the array values 
    a[i] = 2 * a[i];
}

/***************************
a[] is the array from the main
s is the size of the array
This function will show a graph, each * represents 10
***************************/
void showBarGraph(int a[], int s)
{
  int X = 0;
  for(int i = 0; i < s; i++)//loop s times
    {
      cout << "Slot " << i << " : ";
      X = a[i]/10;      
      for(int a = 0; a < X; a++)//shows the stars
	cout << "*";
      cout << endl;    
    } 
}
/***************************
a[] is the array from the main
s is the size of the array
This function will return the indez of the key
******************************/
int sequentialSearch(const int a[], int s, int key)
{
  for(int i = 0; i < s; i++)//search through array
    {
      if(a[i] == key)
	return i;
    }
  return -1;
}
/****************************
int a{] is the array
int s is the size of the aray 
int key is the number that is being searched for in the ascending array
*****************************/
int binarySearchAscend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found.
  while(l <= r)
    {
      //calculate the middle point between l and r
      m = (l + r) / 2;

      if(a[m] == key) //key was found
	return m;
      else if(a[m] > key)//move the r
	r = m - 1;
      else if(a[m] < key)//move the l
	l = m + 1;
    }
  return -1; //key wasn't found
}

/****************************
int a{] is the array
int s is the size of the aray
int key is the number that is being searched for in the descending array
*****************************/
int binarySearchDescend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s; //right boundary starts at last index
  int m; //middle point between left and right.
  
  //When l and r cross over, search ends. --> key was not found.
  while(l <= r)
    {
      //calculate the middle point between l and r
      m = (l + r) / 2;
      
      if(a[m] == key) //key was found
	return m;
      else if(a[m] < key)
	r = m - 1;
      else if(a[m] > key)
	l = m + 1;
    }
  return -1; //key wasn't found
}

//N is the size of array
//array is the array from main
//this function will sort the numbers in ascending order: smallest up to largest
void selectionSortAscend(int array[], int N)
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value
  
  //last is the last index in unsorted portion
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger
            lrgIndx = i;
        }
      
      //swap the largest with the last item in the unsorted portion
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}

//N is the size of array
//array is the array from main
//this function will sort the numbers in ascending order: biggest to smallest
void selectionSortDescend(int array[], int N)
{
  int smlIndx; //the index of the smallest value
  int temp; //temporary variable that holds the smallest value
  
  //last is the last index in unsorted portion
  for(int last = N-1; last >= 1; last--)
    {
      smlIndx = 0; //assume the first item is the smallest
      //find the smallest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smlIndx]) //The current item is smaller
            smlIndx = i;
        }
      
      //swap the smallest with the last item in the unsorted portion
      temp = array[smlIndx];
      array[smlIndx] = array[last];
      array[last] = temp;
    }
}


