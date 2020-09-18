// Ovalles, Isabel 
// lab2.cpp
// 09-18-2020

// DESCRIPTION: Lab2 asks the user for a length of an array and creates it. 
// The user then is asked to select a choice from a menu, either pushing, 
// popping, stopping. The choice is exectuted and the user can continue until
// it wants to stop or the stack is full. Then the stack is printed out. 

// ASSUMPTION: None. 

// SOURCES: For switch code, refrenced "hw1.cpp" from cpcs 1430 class. 

#include <iostream> 
using namespace std; 

const char PUSH = 'p';
const char POP = 'o';
const char STOP = 's';
typedef int elementType; 

char getUserInput(); 
// Asks user for their choice from the menu, returns their choice.
// PRE: None.
// POST: None. 

void push(elementType *stack, elementType value, int& size, int maxSize);
// Adds one new element to the top of the reverseStack, returns new size
// PRE: Value must be type elementType in order to be pushed.
// POST: Adds 1 to size. 

elementType pop(elementType *stack, int& size);
// Removes the top element of the stack, returns the value that was popped.
// PRE: The stack must have a size greater than 0.
// POST: Subtracts 1 from size. 

bool isFull(int size, int maxSize);
// Returns true if stack is full
// PRE: None. 
// POST: None.

void print(elementType *stack, int maxSize);
// Prints out all the elements in the stack in reverse order. If stack is empty
// it will print nothing. 
// PRE: None. 
// POST: None. 

int main()
{
  elementType size = 0;
  elementType maxSize = 0; 
  elementType* reverseStack = nullptr; 
  char choice = 'x'; // stores user's request, intialized with a invalid value
  elementType value; // stores the value the user wants to push 

  cout << endl << "Welcome to Lab 2!" << endl;

  while(maxSize <= 0) {
    cout << "Please enter an array size: ";
    cin >> maxSize; 
    if(maxSize <= 0) {
      cout << "Array size must be greater than 1." ; 
    }
    cout << endl;
  }

  reverseStack = new elementType[maxSize];

  while((choice != STOP) && !(isFull(size, maxSize))) {
    while((choice != PUSH) && (choice != POP) && (choice != STOP)) {
      choice = getUserInput();
    }
    switch(choice)
    {
      case PUSH :
      {
        cout << "Please enter a number you want to push to the stack: ";
        cin >> value; 

        if(size == 0 || value > reverseStack[size - 1]) {
          push(reverseStack, value, size, maxSize);
        } else {
          cout << value << " is smaller than the current top." << endl;
        }
        cout << endl;

        if(size < maxSize) {
        choice = getUserInput(); 
        }
        break; 
      }
      case POP :
      {
      if(size > 0) {
        cout << "The popped value is " << pop(reverseStack, size) << endl;
      } else {
        cout << "reverseStack is empty! " << endl;
      }
        cout << endl;
        choice = getUserInput();
        break;
      }
    }
  }

  print(reverseStack, size);
  cout << "End of Lab2" << endl << endl;

  delete[] reverseStack;
  return 0;
}

char getUserInput()
{
  char input;
  cout << "Do you want to push (" << PUSH << "), pop (" << POP
          << "), or stop (" << STOP << ")?: ";
  cin >> input;

  return input; 
}

void push(elementType *stack, elementType value, int& size, int maxSize)
{
  stack[size] = value; 
  size++;
  cout << "Pushed " << value << endl;
}

elementType pop(elementType *stack, int& size)
{
    elementType poppedVal = stack[size - 1];
    stack[size - 1] = 0; 
    size--;
    return poppedVal; 
}

bool isFull(int size, int maxSize)
{
  return size >= maxSize; 
}

void print(elementType *stack, int size)
{
  cout << "reverseStack: ";
  for(int index = 0; index < size; index++) {
    if(index == size - 1) {
      cout << stack[index] << endl; 
    } else {
    cout << stack[index] << ", "; 
    }
  }
}