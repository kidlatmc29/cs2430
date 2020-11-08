// Ovalles, Isabel 
// lab7.cpp
// 11-6-2020

// DESCRIPTION: Creates a hash table of books. Keeps tracks of collion then,
//  prints out the hash table once it has tried to insert all the given books.

// SOURCE: 

#include <iostream>
using namespace std;

const int BOOKSHELF_SIZE = 13;
const int NUM_BOOKS = 20;

#ifndef BOOK_H
#define BOOK_H

template <typename titleType, typename ISBNType>
class Book{
  private:
    titleType title;
    ISBNType ISBN;

  public:
    Book()
    {
      title = "";
      ISBN = -1;
    }
    Book(titleType nT, ISBNType nI) : title(nT), ISBN(nI) {}

    
    long getISBN()
    {
      return ISBN;
    }

    titleType getTitle()
    {
      return title;
    }

    void printBook(int index)
    {
      cout << "Bookshelf[" << index << "]----------";
      if(ISBN != -1) {
        cout << endl << "Title: " << title << endl << "ISBN: " 
             << ISBN;
      }
      cout << endl << endl;
    }
};
#endif

bool addBook(string newTitle, long newISBN, Book<string,long> bookshelf[]);

int hashFunc(long key);

int main()
{
  Book<string, long> bookshelf[NUM_BOOKS];
  int numCol;
  string titleArr [] = {"Sherlock Holmes: The Complete Novels and Stories",
  "The Very Hungry Caterpillar","Goodnight Moon","On the Night You Were Born",
  "The Kissing Hand","The Monster at the End of this Book",
  "The Story of Ruby Bridges","The Road Not Taken and Other Poems",
  "The Cat in the Hat and Other Dr. Seuss Favorites","Green Eggs and Ham",
  "One Morning in Maine","The Glass Castle","A Child's Garden of Verses",
  "Twenty Love Poems and a Song of Despair","The Lorax",
  "Letters to a Young Poet","The Body","The Missing Piece Meets the Big O",
  "Matilda","Harry Potter and the Sorcerer's Stone"};
  long isbnArr [] = {9780553212419,9780241003008,9780060775858,9780312346065,
    9781933718002,9780375829130,9780439598446,9780486275505,9780807218730,
    9780394800165,9780140501742,9780743247542,9780689823824,9780143039969,
    9780679889106,9780486422459,9780582418172,9780060256579,9780141301068,
    9780439554930};

   cout << endl << "Welcome to Lab 7 " << endl;

  for(int index = 0; index < NUM_BOOKS; index++) {
    if(!addBook(titleArr[index], isbnArr[index], bookshelf)) {
      numCol++;
    }
  }
  
  cout << "The number of collisions was " << numCol << "." << endl << endl;

  for(int index = 0; index < BOOKSHELF_SIZE; index++) {
    bookshelf[index].printBook(index);
  }

  cout << "End of Lab 7 " << endl  << endl;

  return 0;
}

int hashFunc(long key)
{
   return key % BOOKSHELF_SIZE; 
}

bool addBook(string newTitle, long newISBN, Book<string,long> bookshelf[])
{
  Book<string, long> newBook(newTitle, newISBN);
  int h = hashFunc(newBook.getISBN());

  if(bookshelf[h].getISBN() != -1) {
    cout << "Collision at index " << h << endl;
    return false; 
  }

  bookshelf[h] = newBook;
  return true; 
}