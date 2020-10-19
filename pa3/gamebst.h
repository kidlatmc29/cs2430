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
    void insert(TreeNode* &nPtr, TreeNode* newNode);
    // helper fxn for public insert
    // PRE: Was called in public insert fxn, passed in root and new TreeNode
    // POST:

    void print(TreeNode *nPtr);
    // helper fxn for public print
    // PRE: Was called in public print fxn, passed in root
    // POST:

    bool contains(TreeNode *nPtr, string gameName);
    // helper fxn for many public fxns such as remove and printGame
    // PRE: None. 
    // POST: returns false if the key of nPtr does not exist in the tree 

    bool contains(TreeNode *nPtr, int timeLeft);
    // helper fxn for many public fxns such as printPlayable
    // PRE: None. 
    // POST: returns false if there is no game playable in given time 

    void remove(TreeNode* &nPtr, string name);
    // helper fxn for public remove
    // PRE:  
    // POST: 

    TreeNode* findMin(TreeNode *nPtr);
    // finds the smallest key in the tree
    // PRE: 
    // POST: returns the the smallest key 

    void clearTree(TreeNode *nPtr);
    // clears the current nodes in the tree
    // PRE: None.
    // POST: All nodes except for the root has been deallocated and set to 
    //  nullptr  

    void cloneTree(TreeNode *copy);
    // copies all the nodes from the given TreeNode pointer 
    // PRE: clearTree fxn has been called before this one
    // POST: *this tree will have the same nodes as the copy 

  public: 
    GameBST(); 
    // default parameterized constructor
    // PRE: None.
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