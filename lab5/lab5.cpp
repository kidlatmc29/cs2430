// Ovalles, Isabel
// lab5.cpp
// 10-16-2020

#include <iostream> 
#include <ctime> 

using namespace std;

const int MAX_SIZE = 15;
const int MAX = 50;
const int MIN = 0;

void insert(const int &x, int currentSize, int arr[]);

int deleteMax(int &x, int arr[], int currentSize); 

int main()
{
  srand(time(0));
  int currentSize = 0;
  int arr[MAX_SIZE] = {0};
  int rando; 
  
  cout << endl << "Lab 5 start - " << endl;
  for(int i = 1; i < MAX_SIZE; i++) {
    rando = rand() % ((MAX - MIN) + 1) + MIN;
    cout << "inserting " << rando << endl;
    insert(rando, currentSize, arr);
    currentSize++;
  }

  cout << "Lab 5 end - " << endl << endl;
  return 0;
}

void insert(const int &x, int currentSize, int arr[])
{
  if(currentSize == MAX_SIZE - 1) {
    // resize fxn here
    cout << "the heap is full oop" << endl;
  }

  // percolating up 
  int hole = ++currentSize; 
  arr[0]= x; 

  while(x > arr[hole/2]) {
    arr[hole] = arr[hole/2];
    hole /= 2; 
  }

  arr[hole] = arr[0];
}

int deleteMax(int &x, int arr[], int currentSize)
{
  // if empty, then throw expection
  if(currentSize == 0) { 
    cout << " tree is empty- " << endl;
  }
  x = arr[1];
  arr[1] = arr[currentSize--];
  //percolate up? for deleteMax? 

  return x; 
}