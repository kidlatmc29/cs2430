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
  RecursiveQueue copyQueue; 
  RecursiveQueue queueB;
  int input = -1;
  int sum; 

  cout << endl << endl << "Welcome to PA 2 " << endl << endl;
  cout << "Testing Recursive Functions ========================================"
       << endl;
  while(input < 0) { // checking user input
     cout << "Please enter a positive integer: ";
     cin >> input; 
  }
  cout <<  endl << "Initalizing array with recInsert...." << endl;
  myQueue.recInsert(input);

  cout << endl << "Initalized array is: ";
  myQueue.print();

  cout << endl << "Doubling on even indices...." << endl;
  myQueue.doubleEven();
  cout << endl << "Resulting array is: ";
  myQueue.print();

  cout << endl << "Please enter an integer for x: ";
  cin >> input; 
  cout << endl << "Calling sumBiggerX with " << input << "...." << endl;
  sum = myQueue.sumBiggerX(input);
  cout << "The sum off all values greater than x is " << sum << endl;

  cout << endl 
       << "Testing Class Functions ============================================"
       << endl;

  cout << "Dequeueing - on myQueue " << endl;
  cout << "The dequeued value is " << myQueue.dequeue() << endl << endl;

  cout << "Copy Constructor - creating yourQueue from myQueue" << endl;
  RecursiveQueue yourQueue(myQueue);
  cout << "yourQueue: ";
  yourQueue.print();

  cout << endl << "Copy Assignment - copyQueue = myQueue" << endl;
  copyQueue = myQueue; 
  cout << "copyQueue: ";
  copyQueue.print();
  
  cout << endl << "Printing on an empty queue- Printing queueB" << endl;

  cout << endl << "Dequeueing on an empty queue - Dequeuing on queueB" << endl;
  queueB.dequeue();
 
  cout << endl << "End of PA 2" << endl << endl;
  return 0; 
}