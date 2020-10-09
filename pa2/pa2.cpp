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

  cout << endl << endl << "Welcome to PA 2 " << endl;
  cout << "Recursive function testing ========================================="
       << "Please enter a positive integer: ";
  cin >> input; 
  cout << "Initalizing array with recInsert...." << endl;
  myQueue.recInsert(input);

  cout << "Initalized array is: ";
  myQueue.print();

  // call double even
  // sumBigger x 
  // test other class fxns

  cout << "Class function testing ============================================="
       << endl;
  cout << "End of PA 2." << endl << endl;
  return 0; 
}