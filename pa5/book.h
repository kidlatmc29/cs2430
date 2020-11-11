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
    // PRE:
    // POST:


    Book(string t, string a, float r, long i, int p);
    // default para constructor
    // PRE:
    // POST:

    ~Book();
    // deconstructor
    // PRE:
    // POST:

    long getISBN();
    // returns the ISBN of the book
    // PRE:
    // POST:

    string getAuthor();
    // returns the author of the book
    // PRE:
    // POST:
};