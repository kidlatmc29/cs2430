// Ovalles, Isabel
// pa4.cpp
// 11-2-2020

// DESCRIPTION: Pa 4 creates a Word Heap on a user given size. It is filled up
//  with words given by the user as well. Then it prints out the children of
//  a given key. Following that, testing for class functions and then the heaps
//  are emptied. 
// SOURCES: Textbook code examples pg 50, 250, figure 6.8 

#include <iostream> 
#include "heap.h"

using namespace std; 

int main()
{
  WordHeap sentence; 
  WordHeap copySentence; 
  int numOfVals; 
  string input; 

  cout << endl  << "Welcome to PA 4" << endl;
  cout << "Created WordHeap sentence..." << endl;
  cout << "How many values do you want to add to the heap? ";
  cin >> numOfVals;
  
  for(int i = 0; i < numOfVals; i++) {
    cout << "Enter a word you want to add: ";
    cin >> input;
    sentence.insert(input);
  }

  cout << endl << "What value do you want to print the children of?: ";
  cin >> input; 
  sentence.printChildren(input);

  // test copy constructor
  cout << endl << "Creating WordHeap s2 sentence using copy constructor...." 
       << endl;
  WordHeap s2(sentence);

  cout << endl <<"Removing three words from s2 using deleteMax...." << endl;
  for(int i = 0; i < 3; i++) {
    cout << s2.deleteMax() << endl; 
  }

  cout << endl << "Creating WordHeap copySentence from s2 using copy assignment...." 
       << endl;
  copySentence = s2; 

  cout << "Emptying sentence: " << endl;
  sentence.makeEmpty();
  cout << endl << "Emptying s2: " << endl;
  s2.makeEmpty();
  cout << endl << "Emptying copySentence: " << endl;
  copySentence.makeEmpty();
  
  cout << endl << "End of PA 4" << endl << endl; 
  return 0;
}