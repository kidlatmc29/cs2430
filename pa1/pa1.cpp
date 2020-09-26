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
  ActivityList::ActivityNode *rmNode; 

  cout << endl << "PA1 Starting... " << endl;
  readFile(myList); 

  cout << "Testing printList() ================================================" 
       << endl;
  myList.printList();
  yourList.printList();

  cout << "Testing getRating =================================================="
       << endl
       << "Rating of the Space Needle: " << myList.getRating("Space Needle")
       << "Rating of Starbucks is: " << myList.getRating("Starbucks") << endl
       << endl;
  
  cout << "Test dequeue ====================================================="
       << endl;
  rmNode = myList.dequeue(); 
  cout << "Dequeued: " << endl << myList.getSize() + 1 
       << ". [P" << rmNode->priority << "] " << rmNode->name << " - " << "$" 
       << rmNode->price << " - " << rmNode->rating << " stars" << endl; 
  delete rmNode; 
  rmNode = nullptr; 
  
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