// Ovalles, Isabel
// activity.cpp
// 9-28-2020

#include "activity.h"

ActivityList::ActivityList() : head(nullptr) {} 

ActivityList::ActivityNode::ActivityNode(string n, float p, float r, int pri)
: name(n), price(p), rating(r), priority(pri) {}

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