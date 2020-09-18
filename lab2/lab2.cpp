// Ovalles, Isabel 
// lab2.cpp
// 09-18-2020

// DESCRIPTION: 
// ASSUMPTION: None. 
// SOURCES: 
#include <iostream> 
using namespace std; 

const char PUSH = 'p';
const char POP = 'o';
const char STOP = 's';
typedef int elementType; 

char getUserInput(); 
// Asks user for their choice from the menu, returns the choice
// PRE: None.
// POST: None. 

int push(elementType *stack, elementType value, int& size, int maxSize);
// Adds one new element to the top of the reverseStack, returns new size
// PRE: value must be type elementType in order to be pushed
// POST:

bool isFull(int size, int maxSize);
// Returns true if stack is full
// PRE: None. 
// POST: None.

void print(elementType *stack, int maxSize);
// Prints out all the elements in the stack in reverse order
// PRE: None. 
// POST: None. 

int main()
{
  elementType size = 0;
  elementType maxSize; 
  elementType* reverseStack = nullptr; 
  char choice = 'x'; // stores user's request, intialized with a dummy value
  elementType value; // stores the value the user wants to push 

  cout << endl << "Welcome to Lab 2!" << endl;
  cout << "Please enter an array size: ";
  cin >> maxSize; 
  cout << endl;

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

        choice = getUserInput(); 
        break; 
      }
      case POP :
      {
        // ya pop here
       cout << "poppin";
       choice = getUserInput();
       break;
      }
    }
  }

  print(reverseStack, size);
  cout << endl << "End of Lab2" << endl << endl;
  
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

int push(elementType *stack, elementType value, int& size, int maxSize)
{
  stack[size] = value; 
  size++;
  cout << "Pushed " << value << endl;

  return size; 
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

//pop()