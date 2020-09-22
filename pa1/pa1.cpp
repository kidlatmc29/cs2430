// Ovalles, Isabel
// pa1.cpp
// 9-28-2020

#include <iostream>
#include <sstream> // ask in oh's if we can use stringstream
#include <fstream>
#include "activity.h"

using namespace std; 

// const string FILE_NAME = "activity.csv";
// const char delimeter = ','; 

void readFile(ActivityList &myList);

int main()
{
  cout << "PA1 Starting... " << endl;
  ActivityList myList; 
  
  cout << "Adding Pike Place Market into myList...." << endl;
  myList.enqueue("Pike Place Market", 0, 4.6, 1);
  myList.printList();

  cout << "PA1 Ending..." << endl;
  return 0;
}

// read file fxn 
void readFile(ActivityList &list)
{
}