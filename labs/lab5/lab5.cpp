// Ovalles, Isabel
// lab5.cpp
// 10-16-2020

#include <iostream> 
#include <ctime> 

using namespace std;

const int MAX_SIZE = 15;
const int MAX = 50;
const int MIN = 0;

void insert(int num, int arr[], int &currentSize);
// inserts an integer into the heap, creating a max-heap
// PRE: None.
// POST: Root will be the max value in the heap

int deleteMax(int arr[], int &currentSize); 
// returns the deleted integer from the heap
// PRE: currentSize is greater then 1 
// POST: currentSize has decreased by 1

void percolateDown(int hole, int arr[], int currentSize);
// helper fxn for deleteMax, percolates values
// PRE: currentSize is great than 1
// POST: the heap is still a max-heap

int main()
{
  srand(time(0));
  int currentSize = 0;
  int arr[MAX_SIZE] = {0};
  int rando; 
  int input; // for user given integer 
  int deletedVal = -1; 
  
  cout << endl << "Lab 5 start - " << endl;
  for(int i = 1; i < MAX_SIZE; i++) {
    rando = rand() % ((MAX - MIN) + 1) + MIN;
    // cout << "inserting " << rando << endl;
    if(i != MAX_SIZE) {    
      cout << "inserting " << rando << "....." << endl;
      insert(rando, arr, currentSize);
    }
  }

  while(currentSize > 1) {
      // ask user a positive intger must be less than or equal to 14
      cout << "Please enter a positive integer: ";
      cin >> input; 
      cout << endl;

      while((input > currentSize || input < 1)){
        if(input > currentSize) {
          cout << "Given integer was too big!" << endl;
        } else if (input < currentSize) {
          cout << "Must be a positive integer! " << endl;
        }
        cout << "Please enter a positive integer: ";
        cin >> input;
        cout << endl;
      }

      // call delete max with given integer (input) then print val
      for(int i = 1; i < input; i++){
        deletedVal = deleteMax(arr, currentSize);
      }
      cout << "The " << input << "th greatest value was " << deletedVal << endl 
            << endl;

      if(currentSize > 1) {
        // then print remaining heap
        cout << "The remaining heap is: " << endl;
        for(int i = 1; i <= currentSize; i++) {
          cout << i << ". " << arr[i] << endl;
        }
      }
    }

    cout << "Lab 5 end - " << endl << endl;
    return 0;
}

void insert(int num, int arr[], int &currentSize)
{
  if(currentSize == MAX_SIZE - 1) {
    cout << "the heap is full oop" << endl;
  }

  int hole = ++currentSize; 
  arr[0]= num; 

  while(num > arr[hole/2]) { // percolating up 
    arr[hole] = arr[hole/2];
    hole /= 2; 
  }

  arr[hole] = arr[0];
}

int deleteMax(int arr[], int &currentSize)
{
  int rmVal = arr[1];
  if(currentSize == 0) { 
    cout << " tree is empty! " << endl; // if empty, then throw "expection"
  }

  arr[1] = arr[currentSize--];
  percolateDown(1, arr, currentSize);

  return rmVal; 
}

void percolateDown(int hole, int arr[], int currentSize)
{
  int child; 
  int temp = arr[hole];
  bool bDown = true; // not a leaf
  
  while(bDown && hole * 2 <= currentSize) {
    child = hole * 2;
    
    if(child != currentSize && arr[child + 1] > arr[child]) {
      ++child;
    }

    if(arr[child] > temp) {
      arr[hole] = arr [child];
    } else {
      bDown = false; 
    }

    if(bDown) {
      hole = child;
    }
    arr[hole] = temp;
  }
}