/**********************************
Brian Perez
CS111
11/8/2018
Lab 8-1
***********************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 100;

struct emp //employee struct
{
  string fn; //first name member
  string ln; //last name member
  char gen; //gender
  double pay;//pay
  int num; //employee number
  int age; //age
};

void readData(emp mAr[], emp fAr[], int& m, int& f);
void printEmployee(const emp& temp);
void printAllEmp(const emp tempar[], int s);
void outfileArray(const emp tempar[], int s);
emp findOldest(const emp tempar[], int s);
void giveRaise(double raise, emp tempar[], int s);
void giveRaiseToOneEmployee(double raise, emp tempar[], int x);
void combineArray(emp allEmp[], const emp mAr[], const emp fAr[], int m, int f, int& i);
void findEmp(const emp allEmp[], int i);
void sortEmployees(emp allEmp[], int i);

int main()
{
  int mi = 0;//count number of males
  int fi = 0;//count number of females
  int ai = 0;//number of all employees
  emp mAr[SIZE];//array for males
  emp fAr[SIZE]; //array for females 

  emp oldest; //struct for oldest employee
  emp allEmp[SIZE*2];
  int x; //employee who gets a raise
  
  cout << "------------------------- readData() --------------------------------------------------------------" << endl;

  readData(mAr, fAr, mi, fi);
  cout << "There are " << mi << " male employees and " << fi  << " female employees." << endl;

  cout << "\n------------------------- printEmployee() --------------------------------------------------------------" << endl;  

  printEmployee(fAr[0]);

  cout << "\n------------------------- printEmployee() --------------------------------------------------------------" << endl;

  printEmployee(mAr[0]);
  cout << endl;

  cout << "\n------------------------- printAllEmp() --------------------------------------------------------------" << endl;
  
  printAllEmp(mAr, mi);
  cout << endl;
            
  cout << "\n------------------------- printAllEmp() --------------------------------------------------------------" << endl;

  printAllEmp(fAr, fi);
  cout << endl;

  cout << "------------------------- outfileArray() --------------------------------------------------------------" << endl;

  //  outfileArray(mAr, mi);

  cout << "\n------------------------- outfileArray() --------------------------------------------------------------" << endl;

  // outfileArray(fAr, fi);

  cout << "\n------------------------- findOldest() --------------------------------------------------------------" << endl;

  oldest = findOldest(mAr, mi);
  cout << oldest.fn << endl;

  cout << "\n------------------------- giveRaise() --------------------------------------------------------------" << endl;

  giveRaise(5.5, fAr , fi);
  printAllEmp(fAr, fi);
  
  cout << "\n------------------------- giveRaise() --------------------------------------------------------------" << endl;

  giveRaise(5.0, mAr , mi);
  printAllEmp(mAr, mi);

  cout << "\n------------------------- giveRaiseToOneEmployee() --------------------------------------------------------------" << endl;

  giveRaiseToOneEmployee(2.0, fAr, 1);

  cout << "\n------------------------- giveRaiseToOneEmployee() --------------------------------------------------------------" << endl;

  giveRaiseToOneEmployee(50.0, mAr, 0);

  cout << "\n------------------------- combineArray() --------------------------------------------------------------" << endl;

  combineArray(allEmp, mAr, fAr, mi, fi, ai);

  cout << "\n------------------------- findEmp() --------------------------------------------------------------" << endl;

  findEmp(allEmp, ai);

  cout << "\n------------------------- findEmp() --------------------------------------------------------------" << endl;

  findEmp(allEmp, ai);
  
  cout << "\n------------------------- sortEmployees() --------------------------------------------------------------" << endl;

  sortEmployees(allEmp, ai);


  return 0;
}

/***********************************
emp allEmp[] is the struct with all the employees
emp mAr[] is the male array
emp fAr[] is the female array
int m is amount of males
int f is the amount of females
this function will combine the female and male arrays
*************************************/
void combineArray(emp allEmp[], const emp mAr[], const emp fAr[], int m, int f, int& i)
{
  for(i = 0; i < m; i++)
    allEmp[i] = mAr[i];
  for(int d = 0; d < f; d++, i++)
    allEmp[i] = fAr[d]; 
  printAllEmp(allEmp, i); 
}
/*************************************
emp allEmp[] is the array with all the employees
int i is the amount of employees
this function will check for an employee
*************************************/
void findEmp(const emp allEmp[], int i)
{
  int key;//declare the key
  bool find = false;
 
  cout << "Enter the employee id: ";
  cin >> key;

  int s;//declare counter

  for(s = 0; s < i; s++)//look for the employee
    {
      if(allEmp[s].num == key)//check if there is a match
	{
	  cout << endl << left << setw(15) << allEmp[s].fn << setw(15) << allEmp[s].ln << endl;
	  find = true;
	}
    }
  if(find == false)//no employee was found
    cout << "\nThere is no employee with ID " << key << endl;
}

/******************************
This funtion will put the employees in alphabetical order
*******************************/
void sortEmployees(emp allEmp[], int i)
{
  i = 0;
  if(allEmp[2].fn > allEmp[11].fn)
    cout << allEmp[2].fn;
  else
    cout << allEmp[11].fn;   /**
  int first;
  int largest;
  for(int s = 0; s < i; s++, first ++)
    {
      largest = s;
      for(
      if(num > largest)
	largest = num;
	}**/
}

