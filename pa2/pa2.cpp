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
  int input; 
  int sum; 

  cout << endl << endl << "Welcome to PA 2 " << endl << endl;
  cout << "Recursive function testing ========================================="
       << endl << "Please enter a positive integer: ";
  cin >> input; 
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
       << "Class function testing ============================================="
       << endl;

  cout << "Copy Constructor - createing yourQueue from myQueue" << endl;
  RecursiveQueue yourQueue(myQueue);
  cout << "yourQueue:" << endl;
  yourQueue.print();

  cout << endl << "Copy Assignment - myQueue = copyQueue" << endl;
  myQueue = copyQueue; 
  cout << "copyQueue:" << endl;
  copyQueue.print();
  
  cout << endl << "Printing on an empty queue- Printing queueB" << endl;
    
  cout << endl << "Dequeueing on an empty queue - Dequeuing on queueB" << endl;
  queueB.dequeue();
 
  cout << endl << endl << "End of PA 2" << endl << endl;
  return 0; 
}