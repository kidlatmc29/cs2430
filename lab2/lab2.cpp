// Ovalles, Isabel 
// lab2.cpp
// 09-18-2020

#include <iostream> 
using namespace std; 

//static char PUSH = 'p';
//static char POP = 'o';
//static char STOP = 's';
typedef int elementType; 

class reverseStack {
  public:
    //default constructor 
    //param construtor
    //push()
    //pop()
    //print() 
  private:
    int size;
    int maxSize; 
    elementType* array; 
    // top
    // isFull() fxn
};

int main()
{
  /**
   * Allow the user to push or pop as many elements as they wish. 
   * When the stack is full OR when the user wants to stop, 
   * print all the elements in reverseStack and end the program.
   **/

  int input; 

  cout << endl << "Welcome to Lab 2!" << endl;
  cout << "Please enter an array size: ";
  cin >> input; 

  
  cout << endl << "End of Lab2" << endl;
  return 0;
}