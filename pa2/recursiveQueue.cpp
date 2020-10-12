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
  front = -1;
  rear = -1;
  numOfElements = 0;
  size = 0; 
  delete[] arr; 
  arr = nullptr;
}

RecursiveQueue::RecursiveQueue(RecursiveQueue& src)
{
  arr = new int[src.numOfElements];
  front = src.front;
  rear = src.rear;
  numOfElements = src.numOfElements; 
  size = numOfElements;

  for(int index = front; index <= rear; index++) {
    arr[index] = src.arr[index];
  }
}

RecursiveQueue& RecursiveQueue::operator=(const RecursiveQueue& src)
{
  if(&src != this) {
    front = src.front;
    rear = src.numOfElements - 1;
    arr = copyArr(src);
  } else {
    cout << "These are the same RecursiveQueues!" << endl;
  }
   return *this;
}

void RecursiveQueue::enqueue(int num)
{
  if(isEmpty()) {
    front++;
  } else if(numOfElements + 1 > size) {
      cout << "Doubling size to " << size*2 << "..." << endl;
      int *doubleArr = new int[size*2];
      for(int index = front; index < size; index++) {
        doubleArr[index] = arr[index];
      }
      delete [] arr; 
      arr = doubleArr;  
      size *= 2; 
  } 
  rear++;
  arr[rear] = num;
  numOfElements++;
}

int RecursiveQueue::dequeue()
{
  int removed;

  if(!isEmpty()) {
    removed = arr[front];
    numOfElements--;
    front++;
  } else {
    cout << "RecursiveQueue is empty!" << endl;
    removed = -1; 
  }

  return removed;
}

bool RecursiveQueue::isEmpty()
{
  return (numOfElements == 0);
}

int* RecursiveQueue::copyArr(const RecursiveQueue& src)
{
  int *copy = new int[src.size];
  for(int index = 0; index < src.size; index++) {
    size++;
    numOfElements++;
    copy[index] = src.arr[index];
  }
  return copy; 
}

int RecursiveQueue::getFront()
{
  return front; 
}

int RecursiveQueue::getRear()
{
  return rear; 
}

void RecursiveQueue::recInsert(int val)
{
  if(val < 10) {
    enqueue(val);
  } else {
  recInsert(val / 10);
  enqueue(val % 10);
  }
}

void RecursiveQueue::doubleEven()
{
  doubleEven(getFront(), getRear());
}

void RecursiveQueue::doubleEven(int front, int rear)
{
  if (front == rear) {
    return;
  } else {
    if(front % 2 == 0) {
    arr[front] *= 2;  
    }
    doubleEven(front + 1, rear);
  }
}

int RecursiveQueue::sumBiggerX(int x)
{
  int sum;
  if(!isEmpty()) {
    sum = sumBiggerX(x, getFront(), getRear());
  } else {
    sum = -1; 
  }
  return sum; 
}

int RecursiveQueue::sumBiggerX(int x, int front, int rear)
{
  if(front == rear) {
    if(arr[front] > x) {
      return arr[front];
    } else {
      return 0;
    }
  } else {
    if(arr[front] > x) {
      return arr[front] + sumBiggerX(x, front + 1, rear);
   } else {
      return sumBiggerX(x, front + 1, rear);
    }
  }
}

void RecursiveQueue::print()
{
 print(getFront(), getRear());
}

void RecursiveQueue::print(int front, int rear)
{
  if(front == rear){
    cout << arr[front] << endl;
  } else {
    cout << arr[front] << ", ";
    print(front + 1, rear);
  }
}