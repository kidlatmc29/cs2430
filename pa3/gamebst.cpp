// Ovalles, Isabel
// gamebst.cpp
// 10-21-2020

#include "gamebst.h"

GameBST::GameBST() : root (nullptr) {}

GameBST::GameBST(const GameBST &src)
{

}

GameBST& GameBST::operator=(const GameBST &src)
{
  return *this;
}

GameBST::~GameBST()
{
  // call clear list 
  // make sure root is set to nullptr as well HERE
}

void GameBST::insert(string key, int maxPlayers, int playtime)
{
  TreeNode *newNode = new TreeNode;
  newNode->key = key;
  newNode->maxPlayers = maxPlayers;
  newNode->playtime = playtime;
  newNode->left = nullptr;
  newNode->right = nullptr; 
  
  if(!root) {
    // create new Tree Node for root
    root = newNode; 
  } else if(root->key > key) {
    // call private insert fxn
     insert(root->left, newNode);
  } else if(root->key < key) {
     insert(root->left, newNode);
    // also call private insert fxn
  }
}

void GameBST::insert(TreeNode* &nPtr, TreeNode* newNode) 
{
  if(!nPtr) {
    nPtr = newNode; 
  } else if(nPtr->key > newNode->key) {
    insert(nPtr->left, newNode);
  } else if(nPtr->key < newNode->key) {
    insert(nPtr->left, newNode);
  }
}

void GameBST::print() 
{
  TreeNode* nPtr = root;
  print(nPtr);
}

void GameBST::print(TreeNode *nPtr)
{
  if(nPtr) {
    print(nPtr->left);
    cout << nPtr->key << endl;
    print(nPtr->right);
  }
}