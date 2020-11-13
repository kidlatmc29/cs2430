// Ovalles, Isabel
// hash.cpp 
// 11-16-2020

#include "hash.h"

HashTable::HashTable()
{
  arr = new BookNode*[MAX_SIZE];
  currentSize = 0;
}

HashTable::~HashTable()
{
  // go through array and delete linked lists 
  for(int index = 0; index < currentSize; index++) {
    BookNode* nPtr = arr[index]->next;
    while(nPtr->key != -1) {
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
  if(arr[index]->key == -1) {
    arr[index] = newBookNode;
  } else { // iterate through the linked list until it gets to the end
    BookNode* nPtr = arr[index]->next; 
    while(nPtr) {
      nPtr = nPtr->next; 
    }
    nPtr->next = newBookNode; 
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
  // iterates through heap table and prints out all book info 
  for(int index = 0; index < currentSize; index++) {
    while(arr[index]->next) {
      BookNode* nPtr = arr[index]->next; 
      cout << "Title: " << arr[index]->value.getTitle() << endl;
      nPtr = nPtr->next;
    }
  }
}

void HashTable::recommend(long key)
{

}