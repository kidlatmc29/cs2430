#include <iostream>
using namespace std;

const int BOOKSHELF_SIZE = 13; 
const int TITLE_SIZE = 20;

class Book{
  private:
    string title;
    long ISBN;

  public:
    Book(string t, long i) : title(t), ISBN(i) {}

    Book()
    {
      title = "";
      ISBN = 0;
    }

    int getISBN()
    {
      return ISBN; 
    }

    string getTitle()
    {
      return title;
    }

  void printBook(int index) 
  {
    cout << "Bookshelf [" << index << "] --------";
    if(ISBN != 0) {
      cout <<  endl << "Title: " << title << "ISBN: " << ISBN << endl;
    }
  }

};

bool addBook(string newTitle, long newISBN, Book bookshelf[]);

int hashFunc(long key);

int main()
{
  Book bookshelf[BOOKSHELF_SIZE];
  int numCollisions = 0;
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

  cout << endl << "Welcome to Lab 6" << endl << "Adding books..." << endl;
  for(int i = 0; i < TITLE_SIZE; i++) {
    if(!addBook(titleArr[i], isbnArr[i], bookshelf)) {
      numCollisions++;
    }
  }
  cout << "The number of collisions was " << numCollisions << endl;

  for(int i = 0; i < BOOKSHELF_SIZE; i++) {
    //bookshelf.printBook(i);
  }

  cout << "End of Lab 6" << endl << endl;
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
  //cout << "h is " << h << endl;
  
  if(bookshelf[h].getISBN() != 0) {
    cout << "Collisions at index " << h << endl;
    return false; 
  } else if (bookshelf[h].getISBN() == 0) {
    bookshelf[h] = newBook;
    //cout << "Inserted at index " << h << endl;
  }

  return true;
}