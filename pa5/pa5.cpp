// Ovalles, Isabel
// pa5.cpp
// 11-16-2020

// DESCRIPTION:

// SOURCES: 

#include <iostream>
#include <fstream> 
#include <sstream>

using namespace std; 

const int NUM_OF_COLS = 5; 
const string FILE_NAME = "books-sample.csv"; // REMEMBER TO CHANGE TO books.csv
const char DELIMITER = ',';
const char BROWSE = '1';
const char READ = '2';
const char INFO = '3';
const char REC = '4';
const char QUIT = '5';

void fileRead();

int main()
{
  char menuChoice; 
  cout << endl << "Welcome to PA 5" << endl; 
  // cout << "Reading from books-sample.csv..." << endl << endl;
  // fileRead();

  while(menuChoice != QUIT && menuChoice != BROWSE && menuChoice != READ
        && menuChoice != INFO && menuChoice != REC) {
    cout << "Bookshelf Menu: " << endl
         << "1. Browse for books" << endl
         << "2. Read a book" << endl
         << "3. View more info about a book" << endl
         << "4. Get a reccomendation" << endl;
         << "5. Quit" << endl;
      cout << "What would you like to do?: ";  
     cin >> menuChoice;
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