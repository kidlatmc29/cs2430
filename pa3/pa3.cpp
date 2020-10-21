// Ovalles, Isabel 
// pa3.cpp
// 10-21-2020

// DESCRIPTION: GameBST saves data from a cvs file of games. Testing of the
//  class function occurs, and allows the user to input what game they would
//  like to print and see what games they can play in allocated time. 

// REFRENCES: My own pa2.cpp file read, lab4.cpp's insert fxn, txt book ch4,
//  figure 4.26 - remove fxn

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
  GameBST bGame; 
  string gameName; 
  int givenTime;

  cout << endl << "Welcome to PA 3 - " << endl << endl;

  cout << "Reading in from boardgames.cvs...." << endl;
  fileRead(myGameMenu);
  cout << "Printing myGameMenu..." << endl;
  myGameMenu.print();

  cout << endl << "Testing copy assignment ===================================="
       << endl;
  bGame = myGameMenu;
  cout << endl << "Printing bGame: " << endl;
  bGame.print();

  cout << endl << "Testing copy constructor ==================================="
       << endl;
  GameBST moreGames(myGameMenu);
  cout << "Creating moreGames from myGameMenu....." << endl
       << "Printing moreGames: " << endl;
  moreGames.print();

  cout << endl << "Testing remove fxn ======================================"
       << endl;
  cout << "What game would you like to remove? ";
  cin >> gameName;
  myGameMenu.remove(gameName);
  cout << "printing myGameMenu..." << endl;
  myGameMenu.print();
  
  cout << endl << "Testing getHeight fxn ======================================"
       << endl;
  cout << "The height of myGameMenu is " << myGameMenu.getHeight() << endl;
  cout << endl << "Testing printGame fxn ======================================"
       << endl;
  cout << "What game would you like to print out? ";
  getline(cin, gameName);
  cout << endl << "Printing out " << gameName << ": " << endl;
  myGameMenu.printGame(gameName);

  cout << endl << "Testing printPlayable fxn =================================="
       << endl;
  cout << "How much time do you have to play? (in minutes): ";
  cin >> givenTime;
  cout << endl << "Games that can be played under " << givenTime << " mins ...." 
       << endl;
  myGameMenu.printPlayable(givenTime);
  
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
    while(getline(input, line)) { 
      ss.str(line);
      index = 0;
      while(ss.good()) {
        getline(ss,item,DELIMITER);
        items[index] = item;
        index++;
      }

      incomingMaxPlayers = stoi(items[1]);
      incomingPlayTime = stoi(items[2]);

      menu.insert(items[0], incomingMaxPlayers, incomingPlayTime);
      ss.clear();
    }  
    input.close();
  } else {
    cout << "file bad- sorry fam " << endl;
  }
}