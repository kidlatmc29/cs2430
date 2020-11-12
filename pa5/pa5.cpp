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

void fileRead();

int main()
{
  cout << endl << "Welcome to PA 5" << endl; 
  cout << "Reading from books-sample.csv..." << endl << endl;
  fileRead();
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