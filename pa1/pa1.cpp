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
const int NUM_ITEMS = 4; 

void readFile(ActivityList &myList);

int main()
{
  cout << endl << "PA1 Starting... " << endl << endl;
  ActivityList myList;
  readFile(myList); 
  myList.printList();

  cout << "Testing getRating(str x) with a item that doesn't exist..." << endl;
  cout << "Rating of SU is: " << myList.getRating("SU");
  
  cout << endl << "PA1 Ending..." << endl << endl;
  return 0;
}

void readFile(ActivityList &list)
{
   ifstream input; 
   string line; 
   stringstream ss;
   string items[NUM_ITEMS];
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