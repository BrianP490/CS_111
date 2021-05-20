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

void readData(emp mAr[], emp fAr[], int& m, int& f)//use while loop
{
  ifstream fin;        //declare input file locally in function
  ofstream fout;       //declare output file locally 
  fin.open("employees.dat");      //open the input file
    
  if(!fin)
    cout << "Cannot open the input file" << endl;
  
  else
    {
      fout.open("employeesout.dat");     
      emp temp; //make a temporary struct
      
      fin >> temp.fn;//fill the struct
      fin >> temp.ln;
      fin >> temp.gen;
      fin >> temp.pay;
      fin >> temp.num;
      fin >> temp.age;      

      while(fin && m < SIZE && f < SIZE)//loop until no more input, or no more room
	{
	  if(temp.gen == 'F')
	    fAr[f++] = temp;//give information to that array slot
	  
	  else
	    mAr[m++] = temp;//transfer the info to the array
	  
	  fin >> temp.fn;
	  fin >> temp.ln;
	  fin >> temp.gen;
	  fin >> temp.pay;
	  fin >> temp.num;
	  fin >> temp.age;
	}
      
      fin.close();
      fout.close();
    }
}

void printEmployee(const emp& temp)
{//show the information to the screen
  cout << left << setw(12) << fixed << setprecision(2) << temp.fn << setw(12) << temp.ln << setw(12) << temp.gen << setw(12) << temp. pay << setw(12) << temp.num << setw(12) << temp.age << endl;
}


void printAllEmp(const emp tempar[], int s)
{
  for(int i = 0; i < s; i++)//go through the array of employees and show them
    printEmployee(tempar[i]);
}


void outfileArray(const emp tempar[], int s)
{
  
  ofstream fout; //make an output file
  string filename; //the file name given
  
  cout << "Enter the input file name: ";
  cin >> filename;
  
  fout.open(filename.c_str());//open the file
  
  for(int i = 0; i < s; i++)//show the info for every employee
    {
      fout << tempar[i].ln << ", " << tempar[i].fn << endl; //show the first and last name
    }    

  fout.close();//close the output file
}


emp findOldest(const emp tempar[], int s)
{
  emp oldest = tempar[0]; //declare oldest
  for(int i = 1; i < s; i++)//go through the array
    {
      if(tempar[i].age > oldest.age)
	oldest = tempar[i];    
    }
  return oldest;
}

void giveRaise(double raise, emp tempar[], int s)
{
  emp temp;
  for(int i = 0; i < s; i++)//give raise to everyone
    tempar[i].pay =  tempar[i].pay + tempar[i].pay*(raise/100);//give the person a raise
}

void giveRaiseToOneEmployee(double raise, emp tempar[], int x)
{
  tempar[x].pay  = tempar[x].pay + tempar[x].pay*(raise/100);               //raise their pay 
  printEmployee(tempar[x]);   //send new info to printEmp
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

