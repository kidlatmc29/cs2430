// Ovalles, Isabel
// recursiveQueue.h
// 10-12-2020

class RecursiveQueue {
  private: 
    int size = 3; 
    int numOfElements;
    int *arr = new int[size];
  public: 
    RecursiveQueue();
    // default constuctor 
    ~RecursiveQueue(); 
    // deconstructor 
    
    RecursiveQueue& operator=(const RecursiveQueue &arr2);
    // copy assignment

    void doubleSize();
    // resizes the array to have double the size

    // enqueue 
    // dequeue
    // copyArr
    // getSize
    // isEmpty

    // recInsert(int val)
    //  takes in a positive integer and inserts each digit into the array
    //  edge cases: 
    //    - empty array
    //    - array with values inside it 
    //    - array with not enough space for the given integer

    // doubleEven()
    //  a recursive fxn that doubles each digit at even indices 
    
    //sumBiggerX(int x)
    //  returns the sum of all the elements in the array that are bigger than x
    
    // print()
    //  prints the queue with commas seperated values. there should be no 
    //  trailing comma. 
};