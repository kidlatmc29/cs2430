// Ovalles, Isabel 
// lab2.cpp
// 09-18-2020

#include <iostream> 
using namespace std; 

static char PUSH = 'p';
static char POP = 'o';
static char STOP = 's';
typedef int elementType; 

int push(elementType *stack, elementType value, int& size, int maxSize);
// Adds one new element to the top of the reverseStack, returns new size
// PRE: value must be type elementType in order to be pushed
// POST:

bool isFull(int size, int maxSize);
// Returns true if stack is full
// PRE:
// POST:

void print(elementType *stack, int maxSize);
// Prints out all the elements in the stack in reverse order
// PRE:
// POST:

int main()
{
  int size = 0;
  int maxSize; 
  elementType* reverseStack = nullptr; 
  /**
   * Allow the user to push or pop as many elements as they wish. 
   * When the stack is full OR when the user wants to stop, 
   * print all the elements in reverseStack and end the program.
   **/

  int arrSize; 
  char choice; 
  int value; 

  cout << endl << "Welcome to Lab 2!" << endl;
  cout << "Please enter an array size: ";
  cin >> arrSize; 

  reverseStack = new elementType[arrSize];
  maxSize = arrSize; 

cout << "Do you want to push (" << PUSH << "), pop (" << POP
          << "), or stop (" << STOP << ")?: ";
    cin >> choice; 

  while(!(isFull(size, maxSize)) && choice != STOP) {
    if(choice == PUSH) {
      cout << "Enter a number you want to push to the stack: ";
      cin >> value; 
      push(reverseStack, value, size, maxSize);
    } else if(choice == POP) {
      // we pop here
      cout << "poppin" << endl;
    }
    cout << "Do you want to push (" << PUSH << "), pop (" << POP
           << "), or stop (" << STOP << ")?: ";
      cin >> choice; 
  }

  print(reverseStack, size);

  cout << endl << "End of Lab2" << endl;
  return 0;
}

int push(elementType *stack, elementType value, int& size, int maxSize)
{
  if(isFull(size, maxSize)) {
    cout << "reverseStack is full!" << endl;
  } else {
    stack[size] = value; 
    size++;
    cout << "Pushed " << value << endl;
  }
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