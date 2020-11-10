// Ovalles, Isabel
// pa5.cpp
// 11-16-2020

// DESCRIPTION:

void fileRead();

#include <iostream>
#include <fstream> 
#include <sstream>

using namespace std; 

const int NUM_OF_COLS = 5; 
const string FILE_NAME = "books-sample.cvs"; // REMEMBER TO CHANGE TO books.csv
const char DELIMITER = ',';

int main()
{
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
  }
 }