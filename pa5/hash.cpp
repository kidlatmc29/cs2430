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
  numOfElements = 0;
}

HashTable::~HashTable()
{
  // go through array and delete linked lists 
  for(int index = 0; index < MAX_SIZE; index++) {
    if(arr[index]) {
      BookNode* nPtr = arr[index]->next;
      while(nPtr != nullptr) {
        BookNode* prev = nPtr; 
        nPtr = nPtr->next; 
        delete prev; 
      }
    }
  }
  delete[] arr; 
  numOfElements = 0;
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
  // check if there's a duplicate 
  int index = hash(key);
  cout << "Load factor: " << numOfElements / MAX_SIZE;
  // check if it's the first key-value pair in the bucket
  if(!arr[index]) {
    arr[index] = newBookNode;
  } else if(!arr[index]->next) { 
    arr[index]->next = newBookNode;
  } else {
    BookNode *nPtr = arr[index]->next;
    while(nPtr) {
      nPtr = nPtr->next;
    }
    nPtr = newBookNode;
  }
  numOfElements++;
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
  for(int index = 0; index < MAX_SIZE; index++) {
    if(arr[index]) {
      cout << "Title: " << arr[index]->value.getTitle() << endl
           << "ISBN: " << arr[index]->value.getISBN() << endl << endl;
      BookNode* nPtr = arr[index]->next; 
      while(nPtr) {
        cout << "Title: " << nPtr->value.getTitle() << endl
             << "ISBN: " << nPtr->value.getISBN() << endl << endl;
        nPtr = nPtr->next; 
      }
    }  
  }
}

void HashTable::recommend(long key)
{

}