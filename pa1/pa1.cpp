// Ovalles, Isabel
// pa1.cpp
// 9-28-2020

#include <iostream>
#include <sstream>
#include <fstream>
#include "activity.h"

using namespace std; 

const string FILE_NAME = "activity.csv";
const char delimeter = ','; 

void readFile(ActivityList &myList);

int main()
{
  cout << "PA1 Starting... " << endl;
  ActivityList myList; 
  
  myList.printList();

  cout << "PA1 Ending..." << endl;
  return 0;
}

// read file fxn 
void readFile(ActivityList &list)
{
   ifstream input; 
   string line; 
   stringstream ss;

   string incomingName; 
   float incomingPrice; 
   float incomingRating; 
   int incomingPriority; 
   
   bool cannotOpen = false; 

   cout << "Reading in file " << FILE_NAME << "...." << endl;

   input.open(FILE_NAME);
   cannotOpen = input.fail();

   if(!cannotOpen) {
     while(getline(input, line)) {
      ss.str(line);
      // need to figure out how to split the elements on ,
      ss.clear(); 
     }
   }
   input.close();
}