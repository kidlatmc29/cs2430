// Ovalles, Isabel
// hash.cpp 
// 11-16-2020

#include "hash.h"

HashTable::HashTable()
{
  arr = new BookNode*[MAX_SIZE];
  for(int index = 0; index < MAX_SIZE; index++) {
    BookNode *head = new BookNode();
    arr[index] = head; 
  }
  numOfElements = 0;
}

HashTable::~HashTable()
{
  // go through array and delete linked lists 
  for(int index = 0; index < MAX_SIZE; index++) {
    BookNode* nPtr = arr[index]->next;
    if(nPtr) {
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
  int index = -1;
  for(int i = 0; index < MAX_SIZE; i++) {
    BookNode *nPtr = arr[i]->next; 
    while(nPtr) {
      if(nPtr->key == key) {
        index = i;
      }
      nPtr = nPtr->next;
    }
  }
  return index; 
}

void HashTable::addToBookshelf(long key, Book value)
{
  BookNode* newBookNode = new BookNode(key, value);
  int index = hash(key);
  // cout << "Load factor: " << numOfElements / MAX_SIZE << endl;
  // check if it's the first key-value pair in the bucket
  if(!arr[index]->next) {
    arr[index]->next = newBookNode;
    cout << "inserted " << newBookNode->value.getTitle() << " at "
         << index << endl;
  } else {
    BookNode *nPtr = arr[index]->next;
    while(nPtr) {
      nPtr = nPtr->next;
    }
    nPtr = newBookNode;
    cout << "inserted " << newBookNode->value.getTitle() << " at "
         << index << endl;
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
    BookNode *nPtr = arr[index]->next;
    cout << "Index " << index << ": " << endl;
    while(nPtr) {
      cout << "Title: " << nPtr->value.getTitle() << endl
           << "ISBN: " << nPtr->value.getISBN() << endl << endl;
      nPtr = nPtr->next;
    }
  }
} 


void HashTable::recommend(long key)
{

}