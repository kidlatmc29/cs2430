// Ovalles, Isabel 
// activity.h
// 9-28-2020

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
    // PRE: 
    // POST:  

    ~ActivityList();
    // deconstructor 
    // PRE: None.
    // POST: None. 

    ActivityList(ActivityList &list2);
    // copy constructor
    // PRE: 
    // POST: 

    ActivityList& operator=(const ActivityList &list2);
    // copy assignment 
    // PRE: 
    // POST: 

    void enqueue(string n, float p, float r, int pri);
    // inserts an activity into the list based on it's priority
    // PRE: 
    // POST: 

    ActivityNode* dequeue();
    // removes the last first element in 
    // PRE: 
    // POST: 

    void printList();

    int getSize();
    
    bool isEmpty();
   
    float getRating(string target);
    // returns -1 if the item doesn't exist or if the list is empty
    // PRE: None.
    // POST: None.

    void createList(ActivityList& s2, int priority); 
    // creates a new list with activties of a certain priority
    // PRE: None.
    // POST: None.
};