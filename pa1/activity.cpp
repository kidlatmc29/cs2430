// Ovalles, Isabel
// activity.cpp
// 9-28-2020

#include "activity.h"

ActivityList::ActivityList()
{
  head = nullptr;
}

ActivityList::ActivityNode::ActivityNode(string n, float p, float r, int pri)
{
  name = n;
  price = p;
  rating = r;
  pri = priority;
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
  cout << "in enqueue fxn" << endl;
  ActivityNode *newNode = new ActivityNode(n, p, r, pri);
  ActivityNode *nPtr;
  size++;

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
}

void ActivityList::printList()
{
  ActivityNode *nPtr = head;
  cout << "Printing ActivityList: " << endl;

  if (isEmpty()) {
    cout << "the activity list is empty! " << endl;
  } else if (!head->next){
    cout << " there is only one element in the list... printing" << endl;
    cout << nPtr->name << " " << nPtr->priority << endl;
  } else {
    cout << "list is not empty so I stuff to print";
      while(nPtr->next) {
        cout << nPtr->name << " " << nPtr->priority << endl;
      nPtr = nPtr->next; 
    }
  }
}

bool ActivityList::isEmpty()
{
  return !(head);
}
