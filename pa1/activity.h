// Ovalles, Isabel 
// activity.h
// 9-28-2020

#include <iostream>
using namespace std;

class ActivityList {
  public:
    class ActivityNode {
      public: 
        ActivityNode(string n, float p, float r, int pri);
        string name;
        float price; 
        float rating;
        int priority; 
        ActivityNode *next; 
    };

    ActivityNode *head; 
    int size; // stores the number of elements in the list 

    ActivityList(); 
    // default constructor 

    ~ActivityList();
    // deconstructor 

    ActivityList(ActivityList &list2);
    // copy constructor

    ActivityList& operator=(const ActivityList &list2);
    // copy assignment 

    void enqueue(string n, float p, float r, int pri);
    // Inserts an activity into the list based on it's priority. 

    ActivityNode* dequeue();
    // "Removes" the last first element in the list, increments list's size by 1
    //  then cuts off the node from the rest of the list by setting the previous
    //  node's next to nullptr.
    // PRE: None. 
    // POST: The node is returned to main, and deallocated once the program is 
    //   over. 

    void printList();

    int getSize();
    
    bool isEmpty();
   
    float getRating(string target);
    // Returns -1 if the item doesn't exist or if the list is empty.

    void createList(ActivityList& s2, int givenPri); 
    // creates a new list with activites of a certain priority
    // PRE: s2 is an empty ActivityList.
    // POST: If this listis empty or there is no item with given priority, 
    //  the s2 stays empty. 
};