// Ovalles, Isabel
// lab3.cpp
// 9-25-2020

/**
For this lab, you should write a C++ program with a recursive function that reverse
prints the first X values in a linked list AND returns the sum of those values. The number
X is determined by the user.
Before calling the recursive function, you must first write a program that creates an
unordered linked list. Allow the user to add as many nodes as they wish. When they are
done, call the recursive function by passing the front of the linked list.
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

const char YES = 'y';

void append(Node* head, elementType val); 

bool isEmpty(Node* head);

int main()
{
  Node *head = nullptr; 
   
  elementType value;
  char input = YES; 

  while(input == YES) {
    cout << "Enter values to add to a list: ";
    cin >> value; 
    append(head, value);
    cout << endl << "Do you want to add another value? (y/n): ";
    cin >> input; 
  }
  return 0;
}

void append(Node *head, elementType val)
{
  Node *tmp = new Node; 
  tmp->num - val; 
  tmp->next = nullptr; 
  Node *nPtr; 

  if(isEmpty(head)) {
    head = tmp; 
  } else { 
    nPtr = head; 
    while(tmp){
      nPtr = nPtr->next; 
    }
    nPtr->next = tmp; 
  }
}

bool isEmpty(Node *head)
{
  return (!head);
}

void testPrint(Node *head)
{
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
}