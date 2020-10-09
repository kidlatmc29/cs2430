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
  // call double even
  cout << endl << "Resulting array is: ";
  myQueue.print();

  // sumBigger x 
  cout << endl << "Please enter an integer: ";
  cin >> input; 
  cout << endl << "Calling sumBiggerX with " << input << "...." << endl;
  // call sumBiggerX here

  cout << endl 
       << "Class function testing ============================================="
       << endl;
  cout << endl << endl << "End of PA 2" << endl << endl;
  return 0; 
}