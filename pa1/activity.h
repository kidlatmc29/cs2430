// Ovalles, Isabel 
// activity.h
// 9-28-2020

#include <iostream>
using namespace std;

class ActivityList {
  public:
  // default constructor
  // copy constructor
  // copy assignment 
  // deconstructor 

  // enqueue
  // dequeue 
  // getSize
  // isEmpty

  // getRatings(string name)
  //  returns 0 if the item doesn't exist in the list 
  // createList(ActivityList& s2, int priority)
  private: 
    class ActivityNode {
      ActivityNode(string name, float price, float rating, int prio);
      string name;
      float price; 
      float rating;
      int priority; 
      ActivityNode* next = nullptr; 
    };

};