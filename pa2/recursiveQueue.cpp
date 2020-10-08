// Ovalles, Isabel
// recursiveQueue.cpp
// 10-12-2020

#include "recursiveQueue.h"

RecursiveQueue::RecursiveQueue()
{
  size = 3; 
  numOfElements = 0;
  arr = new int[size];
  front = -1;
  rear = -1; 
}

RecursiveQueue::~RecursiveQueue()
{
  delete[] arr; 
  arr = nullptr;
}

RecursiveQueue::RecursiveQueue(RecursiveQueue& src)
{

}

RecursiveQueue& RecursiveQueue::operator=(const RecursiveQueue& src)
{
  if(&src != this) {
    copyArr(src);
  }
   return *this;
}

void RecursiveQueue::enqueue(int num)
{
  
  if(isEmpty()) {
    cout << "queue is empty, enquing fist node" << endl;
    front++;
    rear++;
    arr[front] = num;
    numOfElements++;
  } else if(numOfElements + 1 > size) {
    cout << "Doubling size..." << endl;
    int *doubleArr = new int[size*2];
    for(int index = front; index < size; index++) {
      doubleArr[index] = arr[index];
    }
    delete [] arr; 
    arr = doubleArr;  
    size *= 2; 
  } else {
    arr[rear] = num;
    numOfElements++;
    rear++;
  }
}

int RecursiveQueue::dequeue()
{
  int removed = arr[front];
  numOfElements--;
  front++;

  return removed;
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
  delete [] arr;
  arr = copy;
}

void RecursiveQueue::print()
{
  
}

int RecursiveQueue::getFront()
{
  return front; 
}

int RecursiveQueue::getRear()
{
  return rear; 
}