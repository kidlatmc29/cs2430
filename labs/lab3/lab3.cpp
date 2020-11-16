// Ovalles, Isabel
// lab3.cpp
// 9-25-2020

// DESCRIPTION: Lab 3 allows the user to create a linked list with given values
//  and then asks the user how many values to print and summate. 

#include <iostream>

using namespace std; 
typedef float elementType; 

struct Node{
  elementType num; 
  Node *next; 
};

Node *append(Node* head, elementType val); 
// adds node to the end of the linked list

bool isEmpty(Node* head);

elementType sumPrint(Node *head, int numElements, elementType sum); 

int main()
{
  Node *head = nullptr; 
  int size = -1; 
  elementType value;
  elementType sum = 0; // used to store the current sum in printSum fxn
  elementType finalSum;
  int x; // stores how many values the user wants to print and sum to 

  while(size < 1) {
    cout << endl << "Lab 3 start.... " << endl;
    cout << "Please enter a size for a linked list: ";
    cin >> size; 
  }
  for(int i = 0; i < size; i++) {
    cout << "Please enter a value to append to the linked list: "; 
    cin >> value; 
    head = append(head, value);
  }

  cout << "How many values do you want to reverse print? ";
  cin >> x; 
  finalSum = sumPrint(head, x, sum);
  cout << endl << "The sum of these numbers are " << finalSum << endl; 

  // deallocating nodes
  Node *nPtr = head;
  Node *nextPtr;
  while(nPtr) {
    nextPtr = nPtr->next;
    delete nPtr; 
    nPtr = nextPtr; 
  }
  head = nullptr; 

  cout << endl;
  return 0;
}

Node *append(Node *head, elementType val)
{
  Node *tmp = new Node; 
  tmp->num = val; 
  tmp->next = nullptr; 
  Node *nPtr; 

  if(isEmpty(head)) {
    head = tmp; 
  } else { 
    nPtr = head; 
    while(nPtr->next){
      nPtr = nPtr->next; 
    }
    nPtr->next = tmp; 
  }
  return head; 
}

bool isEmpty(Node *head)
{
  return (!head); 
}

elementType sumPrint(Node *head, int numElements, elementType sum)
{
  int index; 
  Node *nPtr;
  if(numElements == 0)  {
    return sum; 
  } else {
    index = numElements; 
    nPtr = head; 
    while(nPtr && index != 0) {
      nPtr = nPtr->next; 
      index--; 
    }
    sum += nPtr->num;
    cout << nPtr->num << " "; 
    return sumPrint(head, numElements - 1, sum);
  }
}
