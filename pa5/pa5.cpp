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

using namespace std; 

const int NUM_OF_COLS = 5; 
const string FILE_NAME = "books-sample.csv"; // REMEMBER TO CHANGE TO books.csv
const char DELIMITER = ',';
const int BROWSE = 1;
const int READ = 2;
const int INFO = 3;
const int REC = 4;
const int QUIT = 5;

void fileRead();
//
// PRE:
// POST:

int getMenuChoice();
//
// PRE:
// POST:

int main()
{
  int menuChoice; 
  cout << endl << "Welcome to PA 5" << endl; 
  // cout << "Reading from books-sample.csv..." << endl << endl;
  // fileRead();

  while(menuChoice != QUIT) {
    while(menuChoice != QUIT && menuChoice != BROWSE && menuChoice != READ
          && menuChoice != INFO && menuChoice != REC) {
      menuChoice = getMenuChoice();
      cout << "Your choice was " << menuChoice << endl;
    }

    switch(menuChoice) 
    {
      case BROWSE:
      {
        cout << "browsing for book! " << endl;
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
        cout << "getting info for book! " << endl;
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

void fileRead()
{
  ifstream input; 
  string line;
 /**
  stringstream ss;
  string row[NUM_OF_COLS]; 
  string item; 
  int index; 

  float incomingRating; 
  long incomingISBN;
  int incomingPages; 
  **/
  input.open(FILE_NAME);

  // let's just read row by row for now
  if(!input.fail()) {
    while(getline(input, line)) {
      cout << line << endl;
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