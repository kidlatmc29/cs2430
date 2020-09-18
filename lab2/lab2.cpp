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
  elementType size = 0;
  elementType maxSize; 
  elementType* reverseStack = nullptr; 
  char choice; // stores user's request
  elementType value; // stores the value the user wants to push 

  cout << endl << "Welcome to Lab 2!" << endl;
  cout << "Please enter an array size: ";
  cin >> maxSize; 
  cout << endl;

  reverseStack = new elementType[maxSize];

  cout << "Do you want to push (" << PUSH << "), pop (" << POP
        << "), or stop (" << STOP << ")?: ";
    cin >> choice; 

  while(!(isFull(size, maxSize)) && choice != STOP) {
    if(choice == PUSH) {
      cout << "Enter a number you want to push to the stack: ";
      cin >> value; 
      if(size == 0 || value > reverseStack[size - 1]) {
        push(reverseStack, value, size, maxSize);
        cout << endl;
      } else {
        cout << value << " is smaller than the current top" << endl;
      }
    } else if(choice == POP) {
      // we pop here
      cout << "poppin" << endl;
    } else {
      cout << "Sorry, I don't understand that command." << endl;
    }
    
    cout << "Do you want to push (" << PUSH << "), pop (" << POP
           << "), or stop (" << STOP << ")?: ";
      cin >> choice; 
  }

  print(reverseStack, size);

  cout << endl << "End of Lab2" << endl << endl;;
  return 0;
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