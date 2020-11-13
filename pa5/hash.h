// Ovalles, Isabel
// hash.h
// 11-16-2020

#include <iostream>
#include "book.h"
using namespace std; 

class HashTable {
  private:
    const int MAX_SIZE = 11;
    int currentSize; 
    class BookNode {
      public:
        BookNode(long k, Book v) : key(k), value(v) {};
        BookNode() : key(-1) {};
        long key; 
        Book value;
        BookNode* next; 
    };
    BookNode** arr; 
    
  public:
    HashTable();
    // default constructor
    // PRE: None. 
    // POST: Creates an empty Hash Table with Booknode pointers and sets current
    //  size to 0. 

    ~HashTable();
    // deconstructor
    // PRE: None.
    // POST: Iteratres through the Hash Table's array and traverses each linked
    //  linked list and deletes all the Book Nodes. Deallocates the array. Sets 
    //  current size to 0. 

    int hash(long key);
    // hash function for inserting new key-value pairs into the table
    // PRE: Hash function is called from the addToBookShelf fxn.
    // POST: Returns the index at which to store a new Book.

    int contains(long key);
    // returns index of where the Book Node is present. If not found, returns
    //  -1. 
    // PRE: Traverses through the Hash Table to find the Book with given key. 
    //  Called from various functions like addToBookshelf or bookInfo.
    // POST: Returns an integer of the index, -1 if not found. 

    void addToBookshelf(long key, Book value);
    // adds the key-pair value to the hash table. If it already exits,
    //  tells the user it's already in the bookshelf. Prints the load factor 
    //  otherwise. 
    // PRE: Called from main while reading in Books from an input file. 
    // POST: currentSize is incremented by one. A new BookNode is inserted at
    //  the given hash index. 

    bool readBook(long key);
    // prints that you've read the given book and removes it from the shelf.
    //  returns false if the book is not on the bookshelf. 
    // PRE: None. 
    // POST: currentSize is decreased by one. The correct book is delete from
    //  the linked list, any relinking with the list is done. 

    void bookInfo(long key);
    // if the key exists, prints out all the info about the book. Else, prints 
    //  that the book is not on the bookshelf.
    // PRE: None. 
    // POST: None. 

    void displayAll();
    // prints all the titles and ISBN's of the books on the bookshelf.
    // PRE: None. 
    // POST: None. 

    void recommend(long key);
    // prints out the title and ISBN of all the books with the same author that 
    //  matches the given key.
    // PRE: None. 
    // POST: None.  
};