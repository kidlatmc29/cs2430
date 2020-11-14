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
  int index = -1;
  for(int i = 0; i < MAX_SIZE; i++) {
    if(arr[i]) {
      if(arr[index]->key == key) {
        index = i; 
      } else if(arr[i]->next) {
        BookNode *nPtr = arr[i]->next; 
        while(nPtr) {
          if(nPtr->key == key) {
            index = i;
          }
          nPtr = nPtr->next; 
        }
      }
    }
  }
  return index; 
}

void HashTable::addToBookshelf(long key, Book value)
{
  BookNode* newBookNode = new BookNode(key, value);
  /** check if there's a duplicate 
  if(contains(key) != -1) {
    cout << "A book with ISBN " << key << " is already in the bookshelf!"
         << endl;
    return; 
  }
  **/

  int index = hash(key);
  // cout << "Load factor: " << numOfElements / MAX_SIZE << endl;
  // check if it's the first key-value pair in the bucket
  if(!arr[index]) {
    arr[index] = newBookNode;
    cout << "inserted at " << index << endl;
  } else if(!arr[index]->next) { 
    arr[index]->next = newBookNode;
  } else {
    BookNode *nPtr = arr[index]->next;
    while(nPtr) {
      nPtr = nPtr->next;
    }
    nPtr = newBookNode;
    cout << "inserted at " << index << " after " << nPtr->value.getTitle()
         << endl;
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
  // int count = 0;
  for(int index = 0; index < MAX_SIZE; index++) {
    if(arr[index]) {
      cout << "Title: " << arr[index]->value.getTitle() << endl
           << "ISBN: " << arr[index]->value.getISBN() << endl << endl;
    }
      /** count++;
      BookNode* nPtr = arr[index]->next; 
      while(nPtr) {
        cout << "Title: " << nPtr->value.getTitle() << endl
             << "ISBN: " << nPtr->value.getISBN() << endl << endl;
        nPtr = nPtr->next; 
        count++;
      }
    }  
    **/ 
  }
  // cout << "Total Books: " << count  << endl;
}

void HashTable::recommend(long key)
{

}