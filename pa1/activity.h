// Ovalles, Isabel 
// activity.h
// 9-28-2020

// DESCRIPTION: 
// ASSUMPTION: 
// SOURCES: Lecture powerpoint - slide # insert function code 

#include <iostream>
using namespace std;

class ActivityList {
  private: 
    class ActivityNode {
      public: 
        ActivityNode(string n, float p, float r, int pri);
        string name;
        float price; 
        float rating;
        int priority; 
        ActivityNode *next; 
    };

  public:
    ActivityNode *head; 
    int size; // stores the number of elements in the list 

    ActivityList(); 
    // default constructor
    ~ActivityList();
    // deconstructor 

    // copy constructor
    // copy assignment 

   void enqueue(string n, float p, float r, int pri);
    // enqueue
    // dequeue 
    // getSize

    bool isEmpty();
    // isEmpty

    void printList();
    //  printList()
    // getRatings(string name)
    //  returns 0 if the item doesn't exist in the list 
    // createList(ActivityList& s2, int priority)
};