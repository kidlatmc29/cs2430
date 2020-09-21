// Ovalles, Isabel 
// activity.h
// 9-28-2020

#include <iostream>
using namespace std;

class ActivityList {
  private: 
    class ActivityNode {
      ActivityNode(string n, float p, float r, int pri);
      string name;
      float price; 
      float rating;
      int priority; 
      ActivityNode *next = nullptr; 
    };

    int size; // stores the number of elements in the list 

  public:
  ActivityList(); 
  // default constructor

  // copy constructor
  // copy assignment 
  // deconstructor 

  // enqueue
  // dequeue 
  // getSize
  // isEmpty

  //  printList()
  // getRatings(string name)
  //  returns 0 if the item doesn't exist in the list 
  // createList(ActivityList& s2, int priority)

  ActivityNode *head; 
};