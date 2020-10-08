// Ovalles, Isabel
// recursiveQueue.h
// 10-12-2020

using namespace std;

#include <iostream> 

class RecursiveQueue {
  private: 
    int size; 
    int numOfElements;
    int *arr = nullptr;
    int front;
    int rear; 

  public: 
    RecursiveQueue();
    // default constuctor 

    ~RecursiveQueue(); 
    // deconstructor 
    
    RecursiveQueue(RecursiveQueue& src);
    // copy constructor 

    RecursiveQueue& operator=(const RecursiveQueue& src);
    // copy assignment

    void enqueue(int num);
    // enqueue 

    int dequeue();
    // dequeue

    void copyArr(const RecursiveQueue& src);
    //copies contents from src into current recursiveQueue

    int getSize();
    // returns the size of the array

    bool isEmpty();
    // returns true if numOfElements is 0

    int getFront();
    // returns the index of the first element of the queue

    int getRear();
    // returns the index of the last element of the queue

/**
 * The Recursive Functions 
 **/

    // recInsert(int val)
    //  takes in a positive integer and inserts each digit into the array
    //  edge cases: 
    //    - empty array
    //    - array with values inside it 
    //    - array with not enough space for the given integer

    // doubleEven()
    //  a recursive fxn that doubles each digit at even indices 
    
    // sumBiggerX(int x)
    //  returns the sum of all the elements in the array that are bigger than x
    
    void print();
    //  prints the queue with commas seperated values.       

    void print(int front, int rear);
    //  helper function for print()
};