// Ovalles, Isabel 
// book.h
// 11-16-2020

#include <iostream>
using namespace std; 

class Book {
  private:
    string title;
    string author;
    float rating;
    long ISBN;
    int pages; 

  public:
    Book();
    // default constructor
    // PRE: This is called when needed to make empty Book objects
    // POST: All data members are set to "empty" state.

    Book(string t, string a, float r, long i, int p);
    // default param constructor
    // PRE: This is called when all data memebers are given to create a Book
    // POST: All data memebers are stored in the correct variables. 

    ~Book();
    // deconstructor
    // PRE: None.
    // POST: Sets all data members to "empty" state.

    long getISBN();
    // returns the ISBN of the book
    // PRE: Called from by HashTable class.
    // POST: None.

    string getAuthor();
    // returns the author of the book
    // PRE: Called from the HashTable class.
    // POST: None.

    string getTitle();
    // returns the title of the book
    // PRE: Called from the HashTable class
    // POST: None.

    void printInfo();
    // prints all info for the book
    // PRE: Called by the HashTable class from the bookInfo() fxn.
    // POST: None.
};  