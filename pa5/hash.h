// Ovalles, Isabel
// hash.h
// 11-16-2020

#include <iostream>
#include "book.h"
using namespace std; 

class HashTable {
  private:
    class BookNode {
      public:
        BookNode(long k, Book v);
        long key; 
        Book value;
        BookNode* next; 
    };
    const int MAX_SIZE = 11;
    int currentSize; 
    BookNode* arr; 
    
  public:
    HashTable();
    // default constructor
    // PRE:
    // POST:

    ~HashTable();
    // deconstructor
    // PRE:
    // POST:

    int hash(long key);
    // hash function for inserting new key-value pairs into the table
    // PRE:
    // POST:

    bool contains(Book b);
    // returns true if the given book is present in the hash table
    // PRE:
    // POST:

    void addToBookshelf(long key, Book value); // insert
    // adds the key-pair value to the hash table. If it already exits,
    //  tells the user it's already in the bookshelf. Prints the load factor 
    //  otherwise. 
    // PRE: 
    // POST:

    bool readBook(long key); // remove
    // prints that you've read the given book and removes it from the shelf.
    //  returns false if the book is not on the bookshelf. 
    // PRE:
    // POST:

    void bookInfo(long key);
    // if the key exists, prints out all the info about the book. Else, prints 
    //  that the book is not on the bookshelf.
    // PRE:
    // POST:

    void displayAll();
    // prints all the titles and ISBN's of the books on the bookshelf.
    // PRE:
    // POST:

    void recommend(long key);
    // prints out the title and ISBn of all the books with the same author that 
    //  matches the given key.
    // PRE:
    // POST:
};