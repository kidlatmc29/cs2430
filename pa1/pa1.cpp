// Ovalles, Isabel
// pa1.cpp
// 9-28-2020

// DESCRIPTION: 
// ASSUMPTION: 
// SOURCES: Lecture powerpoint - slide # insert function code 

#include <iostream>
#include <sstream>
#include <fstream>
#include "activity.h"

using namespace std; 

const string FILE_NAME = "activities.csv";
const char delimeter = ','; 

void readFile(ActivityList &myList);

int main()
{
  cout << "PA1 Starting... " << endl;
  ActivityList myList; 
  readFile(myList);

  cout << "PA1 Ending..." << endl;
  return 0;
}

// read file fxn 
void readFile(ActivityList &list)
{
   ifstream input; 
   string line; 
   // stringstream ss;

   cout << "Reading in file " << FILE_NAME << "...." << endl;

   input.open(FILE_NAME);

   if((!input.fail())) {
     while(getline(input, line)) {
       cout << line << endl; // just printing out the file as it reads it
      // need to figure out how to split the elements on ,
   }
   input.close();
  }
}