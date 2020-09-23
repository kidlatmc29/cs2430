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

void readFile(ActivityList &list)
{
   ifstream input; 
   string line; 
   stringstream ss;

   string data[4];
   int index = 0;
   string incomingName; 
   string incomingPrice;
   string incomingRating; 
   string incomingPriority; 

   cout << "Reading in file " << FILE_NAME << "...." << endl;

   input.open(FILE_NAME);

   if((!input.fail())) {
     while(getline(input, line)) {
      ss.str(line);
   }
   input.close();
  }
}