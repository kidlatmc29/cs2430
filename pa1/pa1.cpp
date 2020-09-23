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
  myList.enqueue("Pike Place Market",0,4.6,1);
  myList.enqueue("Seattle Great Wheel",14,4.5,5);
  myList.enqueue("Space Needle",30,4.5,1);
  myList.printList();
  cout << endl;
  cout << endl;

  cout << "testing copy constructor - making yourList" << endl;
  ActivityList yourList(myList);
  yourList.printList();

  cout << "PA1 Ending..." << endl;
  return 0;
}

void readFile(ActivityList &list)
{
   ifstream input; 
   string line; 
   stringstream ss;

   //string data[4];
  // int index = 0;
   //string incomingName; 
   //string incomingPrice;
   //string incomingRating; 
   //string incomingPriority; 

   cout << "Reading in file " << FILE_NAME << "...." << endl;

   input.open(FILE_NAME);

   if((!input.fail())) {
     while(getline(input, line)) {
      ss.str(line);
   }
   input.close();
  }
}