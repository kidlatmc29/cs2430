// Ovalles, Isabel
// hash.cpp 
// 11-16-2020

#include "hash.h"

HashTable::HashTable()
{
  arr = new BookNode*[MAX_SIZE];
  for(int index = 0; index < MAX_SIZE; index++){
    arr[index] = nullptr; 
  }
  currentSize = 0;
}

HashTable::~HashTable()
{
  // go through array and delete linked lists 
  for(int index = 0; index < currentSize; index++) {
    BookNode* nPtr = arr[index]->next;
    while(nPtr != nullptr) {
      BookNode* prev = nPtr; 
      nPtr = nPtr->next; 
      delete prev; 
    }
  }
  delete[] arr; 
  currentSize = 0;
}

int HashTable::hash(long key)
{
  return key % MAX_SIZE;
}

int HashTable::contains(long key)
{
  return -1; 
}

void HashTable::addToBookshelf(long key, Book value)
{
  BookNode* newBookNode = new BookNode(key, value);
  int index = hash(key);
  // check if it's the first key-value pair in the bucket
  if(arr[index] == nullptr) {
    arr[index] = newBookNode;
  } else { // iterate through the linked list until it gets to the end
    BookNode* nPtr = arr[index]->next; 
    while(nPtr) {
      nPtr = nPtr->next; 
    }
    nPtr = newBookNode; 
  }
}

bool HashTable::readBook(long key)
{
  return true;
}

void HashTable::bookInfo(long key)
{
  // call contains to find index of key
}

void HashTable::displayAll()
{
  cout << "do I get here? " << endl;
  // iterates through heap table and prints out all book info 
  for(int index = 0; index < currentSize; index++) {
    cout << "do I get here? " << endl;
    if(arr[index]) {
       cout << "Title: " << arr[index]->value.getTitle() << endl;
    }
    if (arr[index]->next) {
      BookNode* nPtr = arr[index]->next; 
      while(nPtr) {
        cout << "Title: " << arr[index]->value.getTitle() << endl;
        nPtr = nPtr->next;
      }
    }
  }
}

void HashTable::recommend(long key)
{

}