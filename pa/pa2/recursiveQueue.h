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

  int sumBiggerX(int x, int front, int rear);
  // helper function for sumBigger(int x)
  // PRE: public sumBiggerX(int x) fxn was called and the arr is not empty
  // POST: returns the sum, if no elements in arr are greater than x, returns -1

  public: 
  // Class Functions =======================================================
    RecursiveQueue();
    // default constuctor 
    // PRE: 
    // POST: RecursiveQueue is initalized with size 3 and arr is dynamically
    //  allocated

    ~RecursiveQueue(); 
    // deconstructor 
    // PRE: None. 
    // POST: All member variabels are set to 0 or -1 respectively, and arr is
    //  deallocated

    RecursiveQueue(RecursiveQueue& src);
    // copy constructor 
    // PRE: None.
    // POST: A new RecursiveQueue object has been created and has the same
    //  contents from src

    RecursiveQueue& operator=(const RecursiveQueue& src);
    // copy assignment
    // PRE: None.
    // POST: The left hand size RecursiveQueue now has the contents of 
    //  the right side Recrusive Queue

    void enqueue(int num);
    // inserts num at the rear of the queue
    // PRE: num is a postive integer 
    // POST: front stays the same, but rear is incremented up one

    int dequeue();
    // dequeues the first element in the array
    // PRE: None. 
    // POST: front is now incremented up one, rear stays the same
    
    int* copyArr(const RecursiveQueue& src);
    // copies contents from src's arr into a new array
    // PRE: Was called from the copy constructor or the copy assignment
    // POST: this RecrusiveQueue has the contents of src's array

    int getSize();
    // returns the size of arr
    // PRE: None. 
    // POST: Size will be a positive integer. (includes 0)

    int getNumOfElements();
    //  returns the number of elements in arr 
    // PRE: None. 
    // POST: numOfElements will be a positive integer. 

    bool isEmpty();
    // returns true if numOfElements is 0, else returns false
    // PRE: None. 
    // POST: None. 

    int getFront();
    // returns the index of the first element of the queue
    // PRE: None.
    // POST: None. 

    int getRear();
    // returns the index of the last element of the queue
    // PRE: None.
    // POST: None. 

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
    // PRE: None.
    // POST: the array at even indices are doubled
 
   int sumBiggerX(int x);
    //  returns the sum of all the elements in the array that are bigger than x
    // PRE: 
    // POST: returns the sum of the private helper fxn to main

   void print();
    //  calls private print fxn to print all values in arr with commas     
    // PRE: None.
    // POST: All values of arr are printed. 
};