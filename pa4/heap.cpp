// Ovalles, Isabel
// heap.cpp
// 11-2-2020

#include "heap.h"

WordHeap::WordHeap() 
{
  arr = new int[STARTING_SIZE];
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
  // go through the array and delete every single element 
  // make the pointer nullptr; 
}

