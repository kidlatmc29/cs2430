// Ovalles, Isabel 
// lab2.cpp
// 09-18-2020

#include <iostream> 
using namespace std; 

static char PUSH = 'p';
static char POP = 'o';
static char STOP = 's';
typedef int elementType; 

int main()
{
  int size;
  int maxSize; 
  elementType* reverseStack; 
  /**
   * Allow the user to push or pop as many elements as they wish. 
   * When the stack is full OR when the user wants to stop, 
   * print all the elements in reverseStack and end the program.
   **/

  int arrSize; 
  char input; 

  cout << endl << "Welcome to Lab 2!" << endl;
  cout << "Please enter an array size: ";
  cin >> arrSize; 

  reverseStack = new int[arrSize];
  maxSize = arrSize; 

  cout << "Do you want to push (p), pop (o), or stop (s)?: ";
  cin >> input; 
  while(input != STOP) {
    cout << "you selected: " << input << endl;
    cout << "Do you want to push (p), pop (o), or stop (s)?: ";
    cin >> input; 
  }
  
  cout << endl << "End of Lab2" << endl;
  return 0;
}

//push()
//pop()
//print() 
// isFull() fxn