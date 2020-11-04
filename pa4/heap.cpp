// Ovalles, Isabel
// heap.cpp
// 11-2-2020

#include "heap.h"

WordHeap::WordHeap() 
{
  arr = new Item[STARTING_SIZE];
  currentSize = STARTING_SIZE; 
  numOfItems = 0;
}

WordHeap::WordHeap(WordHeap& src)
{
  currentSize = src.getNumOfItems();
  arr = new Item[currentSize];

  for(int index = 1; index < currentSize; index++) {
    arr[index].key = src.arr[index].key;
    arr[index].word = src.arr[index].word;
  }
   numOfItems = src.getNumOfItems();
}

WordHeap& WordHeap::operator=(WordHeap& src)
{
  if(this != &src) {
    numOfItems = src.getNumOfItems();
    currentSize = src.getNumOfItems();
    Item *temp = new Item[numOfItems + 1];

    for(int index = 1; index <= numOfItems; index++) {
      temp[index].key = src.arr[index].key;
      temp[index].word = src.arr[index].word;
    }
    delete[] arr; 
    arr = temp;
  }
  return *this;
}

WordHeap::~WordHeap()
{
  delete[] arr; 
  numOfItems = 0; 
  currentSize = 0;
}

void WordHeap::resize()
{
  Item *temp = new Item[currentSize * 2];

  for(int index = 1; index < numOfItems; index++) {
    temp[index].key = arr[index].key;
    temp[index].word = arr[index].word;
  }
  delete[] arr; 
  arr = temp;

  currentSize *= 2;
}

void WordHeap::insert(string x)
{
  int hole = ++numOfItems; 

  if(numOfItems == currentSize -1) {
    cout << "Need to resizing..." << endl;
    resize();
  }

  Item wordInfo;
  wordInfo.word = x; 
  wordInfo.key = x.length();
  arr[0] = wordInfo;

  while(arr[0].key > arr[hole/2].key) {
    arr[hole] = arr[hole/2];
    hole /= 2; 
  }

  cout << "inserting at " << hole << endl;
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
  while(numOfItems != 0) {
    cout << deleteMax() << endl;
  }
  numOfItems = 0;
}

void WordHeap::printChildren(string x)
{
  int index = contains(x);
  if(index > numOfItems) 
  {
    cout << x << " is not in the heap" << endl;
  } else {
    cout << "Left child: ";
    if(arr[index*2 + 1].word == "") {
      cout << "nullptr";
    } else {
      cout << arr[index*2 + 1].word;
    }
    cout << endl;
    cout << "Right child: ";
    if(arr[index*2 + 2].word == "") {
      cout << "nullptr";
    } else {
      cout << arr[index*2 + 2].word;
    }
  }
  cout << endl;
}

int WordHeap::contains(string word)
{
  int index = 1; 
  while(index <= numOfItems && arr[index].word != word) {
    index++; 
  }
  return index; 
}

int WordHeap::getNumOfItems()
{
  return numOfItems;
}