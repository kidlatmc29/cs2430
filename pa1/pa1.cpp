// Ovalles, Isabel
// pa1.cpp
// 9-28-2020

#include <iostream>
#include <sstream> // ask in oh's if we can use stringstream
#include <fstream>
#include "activity.h"

using namespace std; 

const string FILE_NAME = "activity.csv";
const char delimeter = ','; 

void readFile(ActivityList &myList);

int main()
{
  cout << "PA1 Start! " << endl;
  ActivityList myList; 
  cout << "Adding Pike Place Market into myList...." << endl;
  myList.enqueue("Pike Place Market", 0, 4.6, 1);
  myList.printList();
  // read in activities from file, adding activity nodes to the list
    // readFile(myList);



  // testing magic

  cout << "PA1 Ending" << endl;
  // clean up
  return 0;
}

// read file fxn 
void readFile(ActivityList &list)
{
  ifstream input; 
  string line; 
  stringstream ss;
  bool failed = false; 

  cout << "Reading in file " << FILE_NAME << "..." << endl;
  input.open(FILE_NAME);

  if(!failed) {
    while(getline(input, line)) {
      for(int row = 1; row <= 4; row++) {
        
      }
      // get the whole line, then split on the ',' to get indiviual values 
      // call enqueue passing in the parameters to create the activity node
    }
  }

  input.close();
}