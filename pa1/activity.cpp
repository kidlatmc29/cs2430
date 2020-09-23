// Ovalles, Isabel
// activity.cpp
// 9-28-2020

// DESCRIPTION: 
// ASSUMPTION: 
// SOURCES: Lecture powerpoint - slide # insert function code 

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
  ActivityNode *copyNode = list2.head; 
  while(copyNode) {
    enqueue(copyNode->name, copyNode->price, copyNode->rating, 
            copyNode->priority);
    cout << "copying node..." << endl;
    copyNode = copyNode->next; 
  }
}

ActivityList& ActivityList::operator=(const ActivityList &list2)
{
  // copy values from notes from this list into list2
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

 float ActivityList::getRating(string name)
 {
   float rating = 0.0; 
   return rating; 
   // traverse the linked list until you find the name, return the float
 }