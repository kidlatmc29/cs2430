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
    ~ActivityList();
    ActivityList(ActivityList &list2);
    // copy constructor

    ActivityList& operator=(const ActivityList &list2);
    // copy assignment 

    void enqueue(string n, float p, float r, int pri);
    ActivityNode dequeue(string name);
    void printList();
    int getSize();
    bool isEmpty();
    float getRating(string name);
    //  returns 0 if the item doesn't exist in the list
    void createList(ActivityList& s2, int priority); 
    // createList(ActivityList& s2, int priority)
};