// Ovalles, Isabel 
// book.h
// 11-16-2020

#include <iostream>

class Book {
  private:
    string title;
    string author;
    float rating;
    long ISBN;
    int pages; 
  public:
    Book(string t, string a, float r, long i, int p);
    // default constructor
    // PRE:
    // POST:

    long getISBN();
};