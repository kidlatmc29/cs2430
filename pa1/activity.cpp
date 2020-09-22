// Ovalles, Isabel
// activity.cpp
// 9-28-2020

#include "activity.h" 

ActivityList::ActivityList()
{
  cout << "in default constructor";
  head = nullptr; 
}

ActivityList::ActivityNode::ActivityNode(string n, float p, float r, int pri)
{
  name = n;
  price = p;
  rating = r; 
  pri = priority;
}

void ActivityList::enqueue(string n, float p, float r, int pri )
{
  cout << "in enqueue fxn" << endl;
  ActivityNode *newNode = new ActivityNode(n, p, r, pri);
  ActivityNode *nPtr; 

}

void ActivityList::printList()
{
  int elements  = 1;
  ActivityNode *nPtr = head;
  cout << "Printing ActivityList: " << endl;
  
  if (isEmpty()) {
    cout << "the activity list is empty! " << endl;
  } else if(size == 1) {
    cout << elements <<  ". [" << nPtr->priority << "] " << nPtr->name << " - " 
         << nPtr-> price << " - " << nPtr->rating << " stars" << endl;
  } else { 
      while(nPtr->next) {
        cout << elements << ". [" << nPtr->priority << "] " << nPtr->name
             << " - "  << nPtr-> price << " - " << nPtr->rating << " stars" 
             << endl;
        elements++;
        nPtr = nPtr->next; 
    }
  }
}

bool ActivityList::isEmpty()
{
  return !(head); 
}