// Ovalles, Isabel
// heap.cpp
// 11-2-2020

#include "heap.h"

WordHeap::WordHeap() 
{
  arr = new Item[STARTING_SIZE];
  currentSize = STARTING_SIZE; 
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
}

WordHeap::~WordHeap()
{
  // call rm fxn 
  // make the pointer nullptr; 
}


void WordHeap::insert(string word)
{
  if(numOfItems == currentSize - 1) {
    cout << "Need to resizing..." << endl;
    // call resize here
  }

  int hole = ++currentSize; 
  // make struct here
  Item wordInfo;
  wordInfo.word = word; 
  wordInfo.key = word.length();
  arr[0] = wordInfo;  //then insert struct into the array 

  while(word.length() > arr[hole/2].key) {
    arr[hole] = arr[hole/2];
    hole /= 2; 
  }

  arr[hole] = arr[0];
}

string WordHeap::deleteMax()
{
  string rmWord = arr[1];
  if(currentSize == 0) {
    scout << "This WordHeap is empty!" << endl; 
  }

  arr[1] = arr[currentSize--];
  precolateDown();

  return rmVal;
}

void percolateDown()
{
  int child;
  int hole = 1; 
  string temp = arr[hole];
  bool pDown = true; 

  while(pDown && hole * 2 <= currentSize) {
    child = hole *2;

    if(child != currentSize && arr[child + 1].key > arr[child].key) {
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

