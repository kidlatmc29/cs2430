// Ovalles, Isabel
// hash.h
// 11-16-2020

#include <iostream>
using namespace std; 

class HashTable {
  private:
    class BookNode() {
      BookNode(long k, Book v);
      long key; 
      Book value;
      BookNode* next; 
    };

  public:
    HashTable();
    // default constructor
    // PRE:
    // POST:

    ~HashTable();
    // deconstructor
    // PRE:
    // POST:

    void addToBookshelf(long key, Book value);
    // adds the key-pair value to the hash table. If it already exits,
    //  tells the user it's already in the bookshelf. Prints the load factor 
    //  otherwise. 
    // PRE: 
    // POST:

    bool readBook(long key);
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