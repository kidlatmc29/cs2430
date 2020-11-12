// Ovalles, Isabel
// hash.cpp 
// 11-16-2020

#include "hash.h"

HashTable::HashTable()
{
  arr = new BookNode[MAX_SIZE];
  currentSize = 0;
}

HashTable::~HashTable()
{
  // need to go through array and delete linked lists 
  for(int index = 0; index < currentSize; index++) {
    BookNode* nPtr = arr[index].next;
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

bool HashTable::contains(long key)
{
  return false; 
}

void HashTable::addToBookshelf(long key, Book value)
{

}

bool HashTable::readBook(long key)
{
  return true;
}

void HashTable::bookInfo(long key)
{

}

void HashTable::displayAll()
{

}

void HashTable::recommend(long key)
{

}