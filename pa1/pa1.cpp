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
const char DELIMITER = ','; 

void readFile(ActivityList &myList);

int main()
{
  cout << "PA1 Starting... " << endl;
  ActivityList myList;
  readFile(myList); 
  myList.printList();
  cout << "PA1 Ending..." << endl;
  return 0;
}

void readFile(ActivityList &list)
{
   ifstream input; 
   string line; 
   stringstream ss;
   string items[4];
   string item;
   int index;

   float incomingPrice;
   float incomingRating;
   int incomingPriority; 

   cout << "Reading in file " << FILE_NAME << "...." << endl;

   input.open(FILE_NAME);

   if((!input.fail())) {
     while(getline(input, line)) {
      ss.str(line);
      index = 0;
      while(ss.good()) { 
        getline(ss, item, DELIMITER);
        items[index] = item; 
        index++;
      }
      incomingPrice = stof(items[1]);
      incomingRating = stof(items[2]);
      incomingPriority = stoi(items[3]);
      
      list.enqueue(items[0], incomingPrice, incomingRating, incomingPriority);
      ss.clear();
   }
   input.close();
  }
}