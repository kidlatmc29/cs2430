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
  
  if(myQueue.isEmpty()) {
    cout << endl << " my queue is empty.... :(((" << endl;
  }


  cout << "End of PA 2." << endl << endl;
  return 0; 
}