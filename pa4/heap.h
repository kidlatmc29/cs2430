// Ovalles, Isabel 
// heap.h
// 11-2-2020

#include<iostream>

using namespace std; 

class WordHeap {
  private: 
    const int STARTING_SIZE = 4; 
    int currentSize; 
    int numOfItems;
    struct Item {
      int key; 
      string word; 
    };
    Item* arr;
  
    // helper fxn
    void resize();
    // 
    // PRE:
    // POST: 

    void percolateDown();
    // 
    // PRE:
    // POST:

  
    int contains(string word);
    // 
    // PRE:
    // POST:

  public: 
    WordHeap();
    // default parameterized constructor
    // PRE: None. 
    // POST: 

    WordHeap(const WordHeap& src);
    // 
    // PRE:
    // POST: 

    WordHeap& operator=(const WordHeap& src);
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

    void printChildren(string x);
    // 
    // PRE: 
    // POST:

    void makeEmpty();
    // 
    // PRE: 
    // POST: 

    int getNumOfItems();
    // 
    // PRE:
    // POST:
};