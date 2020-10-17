// Ovalles, Isabel 
// pa3.cpp
// 10-21-2020

// DESCRIPTION: 
// ASSUMPTION: 
// REFRENCES: My own pa2.cpp file read and lab4.cpp's insert fxn

#include <iostream> 
#include <fstream> 
#include <sstream>
#include "gamebst.h"

using namespace std; 

const string FILE_NAME = "boardgames.csv";
const char DELIMITER = ','; 
const int MAX_ITEMS = 3; 

void fileRead(GameBST &menu);

int main()
{
  GameBST myGameMenu; 
  cout << endl << "Welcome to PA 3 - " << endl << endl;

  fileRead(myGameMenu);
  cout << "printing myGameMenu..." << endl;
  myGameMenu.print();

  cout << endl << "End of PA 3 - " << endl << endl;
  return 0;
}

void fileRead(GameBST &menu) 
{
  ifstream input;
  string line;
  stringstream ss;
  string items[MAX_ITEMS];
  string item;
  int index;

  int incomingMaxPlayers; 
  int incomingPlayTime; 

  cout << "Reading from file " << FILE_NAME << "...." << endl;

  input.open(FILE_NAME);

  if(!input.fail()) {
    while(getline(input, line)) { // NEED TO DEBUG WHY FIRST CHAR IS LEFT OUT
      // cout << line << endl;
      ss.str(line);
      index = 0;
      while(ss.good()) {
        getline(ss,item,DELIMITER);
        //cout << item << " ";
        items[index] = item;
        index++;
      }

    // testing file read
    //  for(int i = 0; i < MAX_ITEMS; i++) {
    //    cout << items[i] << " ";
    //  }
    // cout //<< endl;

      incomingMaxPlayers = stof(items[1]);
      incomingPlayTime = stof(items[2]);


      // call insert fxn
      menu.insert(items[0], incomingMaxPlayers, incomingPlayTime);
      ss.clear();
    }  
    input.close();
  } else {
    cout << "file bad- sorry fam " << endl;
  }

}