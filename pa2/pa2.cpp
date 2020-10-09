// Ovalles, Isabel
// pa2.cpp
// 10-12-2020

// DESCRIPTION:
// ASSUMPTIONS:
// SOURCES:

#include <iostream> 
#include "recursiveQueue.h"

using namespace std; 

int main()
{
  RecursiveQueue myQueue; 
  int input; 
  cout << endl << endl;
  cout << "Welcome to PA 2. Please enter a positive integer: ";
  cin >> input; 
  
  myQueue.recInsert(input);

  myQueue.print();
  cout << "dequeuing " << myQueue.dequeue() << " and " << myQueue.dequeue()
       << endl;

  myQueue.print();
  cout << "End of PA 2." << endl << endl;
  return 0; 
}