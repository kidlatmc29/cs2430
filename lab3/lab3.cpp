// Ovalles, Isabel
// lab3.cpp
// 9-25-2020

/**
For this lab, you should write a C++ program with a recursive function that reverse
prints the first X values in a linked list AND returns the sum of those values. The number
X is determined by the user.
Catch and print the number that is returned (i.e. the sum of first X nodes in the list) and
end the program. Remember that your list has been dynamically allocated.
Submit your program by running the following
script in the directory with your program:
/home/fac/hkong/submit/cpsc2430/submit_lab3
**/
#include <iostream>

using namespace std; 

typedef int elementType; 

struct Node{
  elementType num; 
  Node *next; 
};

Node *append(Node* head, elementType val); 

bool isEmpty(Node* head);

void testPrint(Node *head);

void clearList(Node *head);

elementType sumPrint(Node *head, int numElements, elementType sum); 

void removeNode(Node *head); 

int main()
{
  Node *head = nullptr; 
  int size = -1; 
  elementType value;
  elementType finalSum = 0; 
  int x; // stores how many values the user wants to print and sum to 

  while(size < 1) {
    cout << "Please enter a size for a linked list: ";
    cin >> size; 
  }
  for(int i = 0; i < size; i++) {
    cout << "Please enter a value to append to the linkd list: "; 
    cin >> value; 
    head = append(head, value);
  }

  // recursion time
  cout << "Enter a integer: ";
  cin >> x; 
  cout << endl << "the sum of the first " << x << " elements are " << endl  
       << sumPrint(head, x, finalSum);
  // testPrint(head);

  while(!isEmpty(head)){
    removeNode(head);
  }
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

void testPrint(Node *head) {
  Node *nPtr;
  cout << "Printing linked list...." << endl;
  if(isEmpty(head)) {
    cout << "The list is empty!" << endl;
  } else {
    nPtr = head; 
    while(nPtr) {
      cout << nPtr->num << " "; 
      nPtr = nPtr->next; 
    }
  }
  cout << endl;
}

void removeNode(Node *head)
{
  Node *nPtr = head;
  Node *previous;  
  while(nPtr) {
    nPtr = nPtr->next;
    previous = nPtr; 
  }
  delete nPtr; 
  previous->next = nullptr; 
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
    return sumPrint(head, numElements, sum);
  }
}
