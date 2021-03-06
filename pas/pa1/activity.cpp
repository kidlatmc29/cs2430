// Ovalles, Isabel
// activity.cpp
// 9-28-2020

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
  ActivityNode *nPtr;
  if(this->head != list2.head) {
    clearList();
    nPtr = list2.head; 
    while(nPtr) {
      enqueue(nPtr->name, nPtr->price, nPtr->rating, nPtr->priority);
      nPtr = nPtr->next; 
    }
  } else {
    cout << "Lists are the same!" << endl;
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

ActivityList::ActivityNode *ActivityList::dequeue(string givenName)
{
  ActivityNode *nPtr;
  ActivityNode *previous = head; 
  nPtr = previous->next; 
  if(nPtr->name == givenName) {
    head = nPtr; 
  } else {
    while(nPtr && nPtr->name != givenName) {
      nPtr = nPtr->next;
      previous = previous->next; 
    }
    previous->next = nPtr->next; // reassign next pointer to skip removed node
  }
  size--;
  return nPtr; 
}

void ActivityList::printList()
{
  ActivityNode *nPtr = head;
  int count = 1; 

  if(isEmpty()) {
    cout << "The list is empty!" << endl;
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

void ActivityList::clearList()
{
  head = nullptr; 
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

 void ActivityList::createList(ActivityList& s2, int givenPri)
 {
   ActivityNode *nPtr;
  // edge cases: 
  //    if givenPri isn't in the list
  //    OR if there isn't any givenPri in the list

  if(isEmpty()) {
    cout << "List is empty!" << endl;
  } else {
    nPtr = head; 
    while(nPtr) {
     if(nPtr->priority == givenPri) {
       s2.enqueue(nPtr->name, nPtr->price, nPtr->rating, nPtr->priority);
     } 
     nPtr = nPtr->next; 
    }
  }
  if(s2.getSize() == 0) {
    cout << "No activity found in this list with priority " << givenPri
         << endl;
  }
 }