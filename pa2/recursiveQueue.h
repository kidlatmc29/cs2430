// Ovalles, Isabel
// recursiveQueue.h
// 10-12-2020

using namespace std;

#include <iostream> 

class RecursiveQueue {
  private: 
    int size; // tracks the capacity of arr
    int numOfElements; // tracks how many integers are in arr
    int *arr = nullptr;
    int front;
    int rear; 

  // Helper Functions ======================================================
  void print(int front, int rear);
    // helper function for print()
    // PRE: Public print fxn was called
    // POST: All values in arr is printed recursively

  void doubleEven(int front, int rear);
  // helper function for doubleEven()
  // PRE: public doubleEven fxn was called
  // POST: even indices in arr are doubled 

  int sumBiggerX(int sum, int front, int rear);
  // helper function for sumBigger(int x)
  // PRE: public sumBiggerX(int x) fxn was called
  // POST: returns the sum, if no elements in arr are greater than x, returns -1

  public: 
  // Class Functions =======================================================
    RecursiveQueue();
    // default constuctor 
    // PRE:
    // POST:

    ~RecursiveQueue(); 
    // deconstructor 
    // PRE:
    // POST:

    RecursiveQueue(RecursiveQueue& src);
    // copy constructor 
    // PRE:
    // POST:
    RecursiveQueue& operator=(const RecursiveQueue& src);
    // copy assignment
    // PRE:
    // POST:

    void enqueue(int num);
    // inserts num at the rear of the queue
    // PRE:
    // POST: 

    int dequeue();
    // dequeue
    // PRE:
    // POST:

    int* copyArr(const RecursiveQueue& src);
    // copies contents from src's arr into a new array
    // PRE:
    // POST:

    int getSize();
    // returns the size of arr
    // PRE:
    // POST:

    int getNumOfElements();
    //  returns the number of elements in arr 
    // PRE:
    // POST:

    bool isEmpty();
    // returns true if numOfElements is 0
    // PRE:
    // POST:

    int getFront();
    // returns the index of the first element of the queue
    // PRE:
    // POST:

    int getRear();
    // returns the index of the last element of the queue
    // PRE:
    // POST:

  // Recursive Functions ===================================================
   void recInsert(int val);
    //  takes in a positive integer and inserts each digit into the array
    //  edge cases: 
    //    - empty array
    //    - array with values inside it 
    //    - array with not enough space for the given integer
    // PRE: val is a postive integer.
    // POST: each digit of val is inserted into the arr using enqueue fxn. 

   void doubleEven();
    //  calls private doubleEven fxn that doubles each digit at even indices 
    // PRE:
    // POST:
 
   int sumBiggerX(int x);
    //  returns the sum of all the elements in the array that are bigger than x
    // PRE:
    // POST:

   void print();
    //  calls private print fxn to print all values in arr with commas     
    // PRE:
    // POST:
};