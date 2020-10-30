// Ovalles, Isabel 
// lab6.cpp
// 10-30-2020

// DESCRIPTION: 
// ASSUMPTIONS: 
// SOURCES: 

#include <iostream>
using namespace std;

const int BOOKSHELF_SIZE = 13;
const int NUM_BOOKS = 20;

class Book{
  private:
    string title;
    long ISBN;

  public:
    Book()
    {
      title = "";
      ISBN = 0;
    }

    Book(string nT, int nI) : title(nT), ISBN(nI) {}

    int getISBN()
    {
      return ISBN;
    }

    string getTitle()
    {
      return title;
    }

};

bool addBook(string newTitle, long newISBN, Book bookshelf[]);

int hashFunc(long key);

int main()
{
  Book bookshelf[NUM_BOOKS];
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

  cout << endl "Welcome to Lab 6 " << endl;

  for(int index = 0; index < NUM_BOOKS; index++) {
    if(!addBook(titleArr[index], isbnArr[index], bookshelf) {
      numCol++;
    }
  }

  cout << "End of Lab 6 " << endl  << endl;
  return 0;
}


int hashFunc(long key)
{
   return key % BOOKSHELF_SIZE; 
}

bool addBook(string newTitle, long newISBN, Book bookshelf[])
{
  Book newBook(newTitle, newISBN);
  int h = hashFunc(newBook.getISBN());

  if(bookshelf[h].getISBN() != 0) {
    cout << "Collision at index " << h << endl;
    return false; 
  }

  bookshelf[h] = newBook;
  return true; 
}