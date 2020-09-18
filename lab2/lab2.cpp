// Ovalles, Isabel 
// lab2.cpp
// 09-18-2020

#include <iostream> 
using namespace std; 

static char PUSH = 'p';
static char POP = 'o';
static char STOP = 's';
typedef int elementType; 

void push(elementType *stack, elementType value, int size, int maxSize);
// Adds one new element to the top of the reverseStack
// PRE: value must be type elementType in order to be pushed
// POST:

bool isFull(int size, int maxSize);


int main()
{
  int size = 0;
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

  reverseStack = new elementType[arrSize];
  maxSize = arrSize; 

  cout << "Do you want to push (" << PUSH << "), pop (" << POP << "), or stop ("
       << STOP << ")?: ";
  cin >> input; 

  while(input != STOP) {
    cout << "you selected: " << input << endl;
    cout << "maxSize = " << maxSize << endl;
    cout << "size = " << size << endl;
    cout << "Do you want to push (p), pop (o), or stop (s)?: ";
    cin >> input; 
  }
  
  cout << endl << "End of Lab2" << endl;
  return 0;
}

void push(elementType *stack, elementType value, int size, int maxSize)
{
  int index = size - 1;
  if(isFull(size, maxSize)) {
    cout << "reverseStack is full!" << endl;
  } else {
      cout << "Pushed " << value << endl;
  }
}

bool isFull(int size, int maxSize)
{
  return size >= maxSize; 
}

//pop()
//print() 