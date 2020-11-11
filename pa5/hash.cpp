// Ovalles, Isabel
// hash.cpp 
// 11-16-2020

#include "hash.h"

HashTable::HashTable()
{

}

~HashTable::HashTable()
{

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