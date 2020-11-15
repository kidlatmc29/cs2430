// Ovalles, Isabel
// pa5.cpp
// 11-16-2020

// DESCRIPTION: PA 5 is a program that inserts books into a Hash Table and 
//  allows the user to interact with the bookshelf. A menu is displayed to the
//  user and they can select certain functions and continue to do so until they
//  quit the program. 

// ASSUMPTIONS: When inputting a menu command the user only selects integers. 
//  If user inputs chars, the program gets trapped in an infinte loop with
//  the menu. 

// SOURCES: Referenced my menu code from my cs1420 PA 5 project. 

#include <iostream>
#include <fstream> 
#include <sstream>
#include "hash.h"

using namespace std; 

const int NUM_OF_COLS = 5; 
const string FILE_NAME = "books.csv"; // REMEMBER TO CHANGE TO books.csv
const char DELIMITER = ',';
const int BROWSE = 1;
const int READ = 2;
const int INFO = 3;
const int REC = 4;
const int QUIT = 5;

void fileRead(HashTable &bookshelf);
//
// PRE:
// POST:

int getMenuChoice();
//
// PRE:
// POST:

int main()
{
  HashTable bookshelf; 
  int menuChoice; 
  cout << endl << "Welcome to PA 5" << endl; 
  cout << "Reading from books-sample.csv..." << endl << endl;
  fileRead(bookshelf);

  while(menuChoice != QUIT) {
    while(menuChoice != QUIT && menuChoice != BROWSE && menuChoice != READ
          && menuChoice != INFO && menuChoice != REC) {
      menuChoice = getMenuChoice();
    }

    switch(menuChoice) 
    {
      case BROWSE:
      {
        cout << endl;
        bookshelf.displayAll();
        menuChoice = getMenuChoice();
        break;
      }
      case READ:
      {
        cout << "reading a book! " << endl;
        menuChoice = getMenuChoice();
        break;
      }
      case INFO:
      {
        long input;
        cout << "Enter the ISBN of the book: ";
        cin >> input; 
        cout << endl;
        bookshelf.bookInfo(input);
        menuChoice = getMenuChoice();
        break;
      }
      case REC:
      {
        cout << "getting a reccomendation! " << endl;
        menuChoice = getMenuChoice();
        break;  
      }
    }
  }
  cout << endl << "End of PA 5" << endl << endl;
  return 0;
}

void fileRead(HashTable &bookshelf)
{
  ifstream input; 
  string line;

  stringstream ss;
  string row[NUM_OF_COLS]; 
  string data; 
  int index; 

  float incomingRating; 
  long incomingISBN;
  int incomingPages; 
  
  input.open(FILE_NAME);

  if(!input.fail()) {
    while(getline(input, line)) {
      ss.str(line);
      index = 0;
      while(ss.good()) {
        getline(ss, data, DELIMITER);
        row[index] = data;
        index++;
      }
      incomingRating = stof(row[2]);
      incomingISBN = stol(row[3]);
      incomingPages = stoi(row[4]);

      // create book object
      Book newBook(row[0], row[1], incomingRating, incomingISBN, incomingPages);
      //add book and isbn to shelf
      bookshelf.addToBookshelf(incomingISBN, newBook);

      // clear ss for next book
      ss.clear();
    }
    input.close();
  } else {
    cout << "Cannot read file! " << endl;
  }
 }

 int getMenuChoice()
 {
   int choice = 0; 
   while(choice > 5 || choice < 1) {
    cout << endl << "Bookshelf Menu: " << endl
          << "===============================" << endl
          << "1. Browse for books" << endl
          << "2. Read a book" << endl
          << "3. View more info about a book" << endl
          << "4. Get a reccomendation" << endl
          << "5. Quit" << endl
          << "===============================" << endl;
    cout << "What would you like to do?: ";  
    cin >> choice;
    if(choice > 5 || choice < 1) {
      cout << "Invalid command! Please try again." << endl;
    }
   }
   return choice;
 }