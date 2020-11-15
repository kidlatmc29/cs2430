// Ovalles, Isabel
// book.cpp
// 11-16-2020

#include "book.h"

Book::Book() : title(""), ISBN (-1) {}

Book::Book(string t, string a, float r, long i, int p) 
{
  title = t;
  author = a;
  rating = r;
  ISBN = i;
  pages = p;
}

Book::~Book()
{
  title = "";
  author = "";
  rating = -1; 
  ISBN = -1; 
  pages = -1;
}

long Book::getISBN() 
{
  return ISBN;
}

string Book::getAuthor()
{
  return author;
}

string Book::getTitle()
{
  return title;
}

int Book::getPages()
{
  return pages;
}

double Book::getRating()
{
  return rating; 
}

void Book::printInfo()
{
  cout << "Title: " << title << endl
       << "Authors: " << author << endl
       << "ISBN: " << ISBN  << endl
       << "Pages: " << pages << endl
       << "Rating " << rating << endl;
}