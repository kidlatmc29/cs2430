// Ovalles, Isabel
// pa1.cpp
// 9-28-2020

// DESCRIPTION: Tests ActivityList class. Tests functions: default constuctor,
//   enqueue, printList, getRating, dequeue, getSize, copy assignment, 
//   createList, and copy constructor. readFile is used to intialize listA, 
//   with activties that is used throughout the testing. 
// 
// SOURCES: Dr. Kong lecture powerpoint - insert function code 

#include <iostream>
#include <sstream>
#include <fstream>
#include "activity.h"

using namespace std; 

const string FILE_NAME = "activities.csv";
const char DELIMITER = ','; 
const int NUM_ITEMS = 4; 

void readFile(ActivityList &myList, string listName);

int main()
{
  ActivityList listA;
  ActivityList listB; 
  ActivityList::ActivityNode *rmNode1; 
  ActivityList::ActivityNode *rmNode2; 

  cout << endl << "PA1 Starting... " << endl << endl;
  cout << "Created empty ActivityLists listA and listB...." << endl;
  readFile(listA, "listA"); 

  cout << "Testing printList() ================================================" 
       << endl
       << "listA: " << endl;
       listA.printList();
       cout << "listB:" << endl;
       listB.printList();
       cout << endl;

  cout << "Testing getRating() ================================================"
       << endl
       << "Rating of the Space Needle: " << listA.getRating("Space Needle")
       << endl << "Rating of Starbucks is: " << listA.getRating("Starbucks") 
       << endl << endl;
  
  cout << "Testing dequeue() =================================================="
       << endl;
  rmNode1 = listA.dequeue("Seattle Great Wheel"); 
  cout << "Dequeued " << listA.getSize() + 1 
       << ". [P" << rmNode1->priority << "] " << rmNode1->name << " - " << "$" 
       << rmNode1->price << " - " << rmNode1->rating << " stars from listA"
       << endl; 
  rmNode2 = listA.dequeue("Sample Activity");     
  cout << "Dequeued " << listA.getSize() + 1 
       << ". [P" << rmNode2->priority << "] " << rmNode2->name << " - " << "$" 
       << rmNode2->price << " - " << rmNode2->rating << " stars from listA"
       << endl;
  listA.printList();    
  cout << endl;  
  
  cout << "Testing getSize() =================================================="
       << endl;
  cout << "listA has " << listA.getSize() <<  " activites" << endl
       << "listB has " << listB.getSize() << " activites" << endl << endl;

  cout << "Testing copy assignment ============================================"
       << endl << "listB = listA" << endl;
  listB = listA; 
  cout << "Printing listB:" << endl;
  listB.printList(); 
  cout << endl;
  
  cout << "Testing createList ================================================="
       << endl << "Creating list of priority 1 from listA..." << endl;
  ActivityList important;
  listA.createList(important, 1);
  cout << "Printing important list:" << endl;
  important.printList();
  cout << endl;

  cout << "Testing copy constructor ==========================================="
       << endl << "Creating listC from listB..." << endl;
     ActivityList listC(listB);
     listC.printList();
  cout << endl;

  cout << endl << "PA1 Ending..." << endl << endl;
  return 0;
}

void readFile(ActivityList &list, string listName)
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

   cout << "Reading from file " << FILE_NAME << " into " << listName << endl 
        << endl;

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