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
    // PRE: a node's key is in the tree. 
    // POST: None. 

    TreeNode* findMin(TreeNode *nPtr);
    // finds the smallest key in the tree
    // PRE: None. 
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

    void printGame(TreeNode *nPtr, string name);
    // helper fxn for printGame
    // PRE: name is present in the current tree.
    // POST: None.

    void printPlayable(TreeNode *nPtr, int timeLeft);
    // helper fxn for printPlayable
    // PRE: None.
    // POST: None. 

    int getHeight(TreeNode* nPtr);
    // calculates out the current height of the tree
    // PRE: None. 
    // POST: None. 

  public: 
    GameBST(); 
    // default parameterized constructor
    // PRE: None.
    // POST: Root is initialized to nullptr

    GameBST(const GameBST& src);
    // copy constructor
    // PRE: None. 
    // POST: Created new GameBST object with the same contents of src

    GameBST& operator=(const GameBST& src);
    // copy assignment, takes the values of the nodes and copies them into
    //  trees, calls helper fxns clearTree and cloneTree
    // PRE: rhs GameBST can be empty or not
    // POST: lhs GameBST will have the same values as rhs GameBST
  
    ~GameBST();
    // deconstructor, calls clearTree helper fxn
    // PRE: None. 
    // POST: All nodes are deallocated and root is set to nullptr. 

    void insert(string key, int maxPlayers, int playtime);
    // inserts a new node into the bst
    // PRE: None. 
    // POST: New node is add be added properly into the bst

    bool remove(string name);
    // removes the game with the given name, returns true when done, else false
    // PRE: a node with the given name is found in the tree
    // POST: Node with the given key is removed

    int getHeight();
    // returns the height of the tree
    // PRE: None.
    // POST: Returns 0 if only the root exists. 

    void print();
    // prints the game names in the tree, using inorder traversal
    // PRE: Calls private print helper fxn.
    // POST: All games are printed in alphabetical order. 

    void printGame(string name);
    // prints out all the information of the given game name
    // PRE: None.
    // POST: None.

    void printPlayable(int timeLeft);
    // prints all the games that are less than or equal to the time given, using
    //  post-order traversal. 
    // PRE: None. 
    // POST: If no playable games are found, nothing is printed out. 
};