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
    // copy constructor
    // copy assignment
    // print on an empty 
    // dequeue on an empty
  cout << endl << endl << "End of PA 2" << endl << endl;
  return 0; 
}