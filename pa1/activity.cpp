// Ovalles, Isabel
// activity.cpp
// 9-28-2020

// DESCRIPTION: 
// ASSUMPTION: 
// SOURCES: Dr. Kong's lecture ppt - slide # insert fxn code 

#include "activity.h"

ActivityList::ActivityList()
{
  head = nullptr;
  size = 0;
}

ActivityList::ActivityNode::ActivityNode(string n, float p, float r, int pri)
{
  name = n;
  price = p;
  rating = r;
  priority = pri;
}

ActivityList::ActivityList(ActivityList &list2)
{
  head = nullptr;
  size = 0;
  ActivityNode *copyNode = list2.head; 

  while(copyNode) {
    enqueue(copyNode->name, copyNode->price, copyNode->rating, 
            copyNode->priority);
    copyNode = copyNode->next; 
  }
}

ActivityList& ActivityList::operator=(const ActivityList &list2)
{
  // copy values from notes from this list into list2
  ActivityNode *nPtr = list2.head; 
  if(nPtr && (&list2 != this)) {
    // we got nodes to copy B)
  } else if(!nPtr) {

  }
  return *this;
}

ActivityList::~ActivityList()
{
  ActivityNode *nPtr = head;
  ActivityNode *nextPtr;
  while(nPtr) {
    nextPtr = nPtr->next;
    delete nPtr;
    nPtr = nextPtr;
  }
  head = nullptr;
}

void ActivityList::enqueue(string n, float p, float r, int pri)
{
  ActivityNode *newNode = new ActivityNode(n, p, r, pri);
  ActivityNode *nPtr;

  if((isEmpty()) || head->priority >= newNode->priority) {
    newNode->next = head;
    head = newNode;
  } else {
    nPtr = head;
    while(nPtr->next && (nPtr->next->priority < newNode->priority)) {
      nPtr = nPtr->next;
    }
    newNode->next = nPtr->next;
    nPtr->next = newNode;
  }
   size++;
}

ActivityList::ActivityNode *ActivityList::dequeue()
{
  ActivityNode *removed = nullptr; 
  ActivityNode *nPtr = head; 
  if(!(isEmpty())) {
    while(nPtr) {
      nPtr = nPtr->next; 
    }
    removed = nPtr; 
  }
  size--;
  return removed; 
}

void ActivityList::printList()
{
  ActivityNode *nPtr = head;
  int count = 1; 

  if(isEmpty()) {
    cout << "the list is empty" << endl;
  } else {
    while(nPtr) {
      cout << count << ". [P" << nPtr->priority << "] " << nPtr->name << " - "
           << "$" << nPtr->price << " - " << nPtr->rating << " stars" << endl; 
      nPtr = nPtr->next;
      count++;
    } 
  }
}

int ActivityList::getSize()
{
  return size; 
}

bool ActivityList::isEmpty()
{
  return !(head);
}

 float ActivityList::getRating(string target)
 {
  float rating = -1.0;  
  ActivityNode *nPtr; 
  if(!(isEmpty())) {
    nPtr = head; 
    while(nPtr && nPtr->name != target) {
      nPtr = nPtr->next; 
    }
    if(nPtr) {
      rating = nPtr->rating;
    }
  }
  return rating; 
 }