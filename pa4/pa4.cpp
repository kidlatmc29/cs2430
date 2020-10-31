// Ovalles, Isabel
// pa4.cpp
// 11-2-2020

// DESCRIPTION:
// SOURCES: 

#include <iostream> 
#include "heap.h"

using namespace std; 

int main()
{
  WordHeap phrase; 
  int numOfVals; 
  string input; 

  cout << endl  << "Welcome to PA 4" << endl;
  cout << "How many values do you want to add to the heap?: ";
  cin >> numOfVals;
  
  for(int i = 0; i < numOfVals; i++) {
    cout << "Enter a word you want to add: ";
    cin >> input;
    phrase.insert(input);
    cout << endl << "Adding " << input << " ...." << endl;
  }

  cout << "What value do you want to print the children of?: ";
  cin >> input; 
  // call printing fxn or whatever

  // call emptying heap fxn here
  cout << "Removing words" << endl;
  cout << phrase.deleteMax() << endl; 
  cout << phrase.deleteMax() << endl;
  cout << phrase.deleteMax() << endl;
  
  cout << endl << "End of PA 4" << endl << endl; 
  return 0;
}