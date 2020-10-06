// Ovalles, Isabel
// recursiveQueue.cpp
// 10-12-2020

#include "recursiveQueue.h"

RecursiveQueue::RecursiveQueue()
{
  size = 3; 
  numOfElements = 0;
  arr = new int[size];
}

RecursiveQueue::~RecursiveQueue()
{
   delete[] arr; 
   size = 0;
   numOfElements = 0;
}

RecursiveQueue& RecursiveQueue::operator=(const RecursiveQueue& src)
{
  if(&src != this) {
    copyArr(src);
  }
   return *this;
}

bool RecursiveQueue::isEmpty()
{
  return (numOfElements == 0);
}

void RecursiveQueue::copyArr(const RecursiveQueue& src)
{
  int *copy = new int[src.size];
  for(int index = 0; index < src.size; index++) {
    size++;
    numOfElements++;
    copy[index] = src.arr[index];
  }
  delete[] arr; 
  arr = copy;
}