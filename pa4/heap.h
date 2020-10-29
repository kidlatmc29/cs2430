// Ovalles, Isabel 
// heap.h
// 11-2-2020

class WordHeap {
  private: 
    const int STARTING_SIZE = 3; 
    struct Item {
      int key; 
      string word; 
    };
    Item* root; 
    int* arr;
  
  public: 
    WordHeap();
    // default parameterized constructor
    // PRE: None. 
    // POST: Root is set to nullptr

    WordHeap(const WordHeap& src);
    // 
    // PRE: 
    // POST: 

    WordHeap& operator=(const WordHeap src);
    // 
    // PRE: 
    // POST:

    ~WordHeap();
    // 
    // PRE: 
    // POST:

    void insert(string x);
    // inserts an new node into the heap, creating a max heap based on word
    //  length
    // PRE: 
    // POST:

    string deleteMax();
    // returns the deleted max string from the heap
    // PRE: 
    // POST:

    void percolateDown();
    // 
    // PRE: 
    // POST:

    void printChildren(string x);
    // 
    // PRE: 
    // POST:

    void makeEmpty();
    // 
    // PRE: 
    // POST: 
};