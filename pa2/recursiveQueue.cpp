// Ovalles, Isabel
// recursiveQueue.cpp
// 10-12-2020

#include "RecursiveQueue.h"

RecursiveQueue::RecursiveQueue()
{

}

RecursiveQueue::~RecursiveQueue()
{
  delete[] arr; 
  size = 0;
  numOfElements = 0;
}

RecursiveQueue& RecursiveQueue::operator=(const RecursiveQueue &arr2)
{
   return *this;
}