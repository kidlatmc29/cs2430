// Ovalles, Isabel
// gamebst.h
// 10-21-2020

#include <iostream> 
using namespace std; 

class GameBST {
  private: 
    struct TreeNode {
      string key; // saves game name
      int maxPlayers;
      int playtime;
      TreeNode *left; 
      TreeNode *right;
    };
    
    TreeNode *root;

    // Helper Functions: 

  public: 
    GameBST(); 
    // default constructor
    // PRE: 
    // POST: Root is initialized to nullptr

    GameBST(const GameBST& src);
    // copy constructor
    // PRE: 
    // POST:  

    GameBST& operator=(const GameBST& src);
    // copy assignment
    // PRE: 
    // POST: 
  
    ~GameBST();
    // deconstructor
    // PRE: 
    // POST: 

    void insert(string key, int maxPlayers, int playtime);
    // inserts a new node into the bst
    // PRE: 
    // POST: 

    bool remove(string name);
    // removes the game with the given name, returns true when done, else false
    // PRE:
    // POST: 

    int getHeight();
    // returns the height of the tree
    // PRE:
    // POST: 

    void print();
    // prints the game names in the tree, using inorder traversal
    // PRE: 
    // POST: 

    void printGame(string name);
    // prints out all the information of the given game name
    // PRE:
    // POST: 

    void printPlayable(int timeLeft);
    // prints all the games that are less than or equal to the time given, using
    //  post-order traversal. 

};