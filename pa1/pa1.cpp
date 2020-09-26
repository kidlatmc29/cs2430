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
  ActivityList myList;
  ActivityList yourList; 
  ActivityList::ActivityNode *rmNode1; 
  ActivityList::ActivityNode *rmNode2; 

  cout << endl << "PA1 Starting... " << endl;
  cout << "Created myList and yourList...." << endl;
  readFile(myList); 

  cout << "Testing printList() ================================================" 
       << endl;
  myList.printList();
  yourList.printList();
  cout << endl;

  cout << "Testing getRating =================================================="
       << endl
       << "Rating of the Space Needle: " << myList.getRating("Space Needle")
       << endl << "Rating of Starbucks is: " << myList.getRating("Starbucks") 
       << endl << endl;
  
  cout << "Test dequeue ======================================================="
       << endl;
  rmNode1 = myList.dequeue(); 
  cout << "Dequeued " << myList.getSize() + 1 
       << ". [P" << rmNode1->priority << "] " << rmNode1->name << " - " << "$" 
       << rmNode1->price << " - " << rmNode1->rating << " stars from myList"
       << endl; 
  rmNode2 = myList.dequeue();     
  cout << "Dequeued " << myList.getSize() + 1 
       << ". [P" << rmNode2->priority << "] " << rmNode2->name << " - " << "$" 
       << rmNode2->price << " - " << rmNode2->rating << " stars from myList"
       << endl;      
  
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

   cout << "Reading from file " << FILE_NAME << "...." << endl << endl;

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