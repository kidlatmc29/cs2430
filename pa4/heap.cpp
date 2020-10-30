// Ovalles, Isabel
// heap.cpp
// 11-2-2020

#include "heap.h"

WordHeap::WordHeap() 
{
  arr = new Item[STARTING_SIZE];
  currentSize = 0; 
  numOfItems = 0;
  root = nullptr; 
}

WordHeap::WordHeap(const WordHeap& src)
{
  root = nullptr;
  // some cloneHeap stuff
}

WordHeap& WordHeap::operator=(const WordHeap& src)
{
  // some cool stuff
  return *this;
}

WordHeap::~WordHeap()
{
  // call rm fxn 
  // make the pointer nullptr; 
}


void WordHeap::insert(string x)
{
  if(numOfItems == currentSize - 1) {
    cout << "Need to resizing..." << endl;
    // call resize here
  }

  int hole = ++numOfItems; 
  // make struct here
  Item wordInfo;
  wordInfo.word = x; 
  wordInfo.key = x.length();
  arr[0] = wordInfo;

  while(arr[0].key > arr[hole/2].key) {
    arr[hole] = arr[hole/2];
    hole /= 2; 
  }
  arr[hole] = arr[0];
}

string WordHeap::deleteMax()
{
  string rmWord = arr[1].word;
  if(numOfItems == 0) {
    cout << "This WordHeap is empty!" << endl; 
  }

  arr[1] = arr[numOfItems--];
  percolateDown();

  return rmWord;
}

void WordHeap::percolateDown()
{
  int child;
  int hole = 1; 
  Item temp = arr[hole];
  bool pDown = true; 

  while(pDown && hole * 2 <= numOfItems) {
    child = hole *2;

    if(child != numOfItems && arr[child + 1].key > arr[child].key) {
      ++child;
    }

    if(arr[child].key > temp.key) {
      arr[hole] = arr[child];
    } else {
      pDown = false; 
    }

    if(pDown) {
      hole = child;
    }
    arr[hole] = temp;
  }
}

void WordHeap::makeEmpty()
{
  cout << "Emptying Wordheap..." << endl;
  while(numOfItems != 0) {
    cout << deleteMax();
  }
}
