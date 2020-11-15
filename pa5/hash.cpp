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
  int location = -1;
  BookNode *nPtr;
  for(int index = 0; index < MAX_SIZE; index++) {
    nPtr = arr[index]->next;
    while(nPtr && nPtr->key != key) {
      nPtr = nPtr->next;
    }
    if(nPtr && nPtr->key == key) {
      location = index;
    }
  }

  return location; 
}

void HashTable::addToBookshelf(long key, Book value)
{
  BookNode* newBookNode = new BookNode(key, value);
  int index = hash(key);

  // check if there's a duplicate
  if(contains(key) != -1) {
    cout << newBookNode->value.getTitle() << " is already in the bookshelf!" 
         << endl;
    return;
  }

  if(!arr[index]->next) {
    arr[index]->next = newBookNode;
  } else {
    BookNode* nPtr = arr[index]->next;
    while(nPtr->next) {
      nPtr = nPtr->next; 
    }
    nPtr->next = newBookNode;
  }
}

bool HashTable::readBook(long key)
{
  bool read = true; 
  int location = contains(key);

  if(location != -1) {
    BookNode *nPtr = arr[location]->next; 
    BookNode *prev; 
    while(nPtr && nPtr->key != key) {
      prev = nPtr;
      nPtr = nPtr->next; 
    }
    if(nPtr && nPtr->key == key) {
      prev->next = nPtr->next;
      delete nPtr; 
      read = true;
    }
  } else {
    cout << "A book with the ISBN " << key << " is not in the bookshelf." 
         << endl;
    read = false; 
  }

  return read;
}

void HashTable::bookInfo(long key)
{
  // call contains to find index of key
  int location = contains(key);
  if(location == -1) {
    cout << "A book with the ISBN " << key << " is not in the bookshelf." 
         << endl;
  } else {
    BookNode *nPtr = arr[location]->next; 
    while(nPtr && nPtr->key != key) {
      nPtr = nPtr->next; 
    }

    if(nPtr && nPtr->key == key) {
      cout << "Title: " << nPtr->value.getTitle() << endl
           << "Author(s): " << nPtr->value.getAuthor() << endl
           << "ISBN: " << nPtr->value.getISBN() << endl 
           << "Pages: " << nPtr->value.getPages() << endl
           << "Rating: " << nPtr->value.getRating() << endl
           << endl;
    }
  }
}

void HashTable::displayAll()
{
  BookNode *nPtr;
  for(int index = 0; index < MAX_SIZE; index++) {
    nPtr = arr[index]->next;
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