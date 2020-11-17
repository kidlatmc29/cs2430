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
  
    // helper fxns
    void resize();
    // Creates a new dynamic array of Words with a size of currentSize*2
    // PRE: numItems = currentSize - 1
    // POST: currentSize is doubled and all elements in the array are the same

    void percolateDown();
    // Finds the correct new spot for a node to reside after deleting max node
    // PRE: The max node has been deleted from the heap
    // POST: Heap structure is preserved with a new max node. 

  
    int contains(string word);
    // Finds the index of the given word, returns out of bounds index
    //  if the word is not in the heap
    // PRE: None
    // POST: Returns an index

  public: 
    WordHeap();
    // default parameterized constructor
    // PRE: None. 
    // POST: All member vars are set to 0 or ""

    WordHeap(WordHeap& src);
    // copy constructor 
    // PRE: None.
    // POST: this word heap will have the same heap and memeber vars as it's
    //  src. 

    WordHeap& operator=(WordHeap& src);
    // This wordheap gets the same values of src
    // PRE: None.
    // POST: None.

    ~WordHeap();
    // deconstructor  
    // PRE: None
    // POST: arr is deallocated, all applicable member variables are set to 0

    void insert(string x);
    // inserts an new node into the heap, creating a max heap based on word
    //  length
    // PRE: None. 
    // POST: A Word node is inserted into the correct place into the heap

    string deleteMax();
    // returns the deleted max string from the heap
    // PRE: None. 
    // POST: the max node is deleted and the heap retains its structure

    void printChildren(string x);
    // prints out the left and right child of the given string
    // PRE: None.
    // POST: Prints out left and right child, if one or both doesn't exist,
    //  prints out nullptr, if x doesn't exist in the heap it tells the user

    void makeEmpty();
    // deletes all the nodes from the heap
    // PRE: None.
    // POST: The arr is now empty and numOfItems is set to 0

    int getNumOfItems();
    // returns numOfItems
    // PRE: None.
    // POST: None.
};