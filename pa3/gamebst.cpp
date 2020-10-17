// Ovalles, Isabel
// gamebst.cpp
// 10-21-2020

#include "gamebst.h"

GameBST::GameBST() : root (nullptr) {}

GameBST::GameBST(const GameBST &src)
{
  // copy tree fxn
}

GameBST& GameBST::operator=(const GameBST &src)
{
  return *this;
}

GameBST::~GameBST()
{
  // call clear fxn 
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
    root = newNode; 
  } else if(root->key > key) {
     insert(root->left, newNode);
  } else if(root->key < key) {
     insert(root->left, newNode);
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

bool GameBST::contains(TreeNode *nPtr, string gameName)
{
  if(!nPtr) {
    return false; 
  } else if (nPtr->key < gameName) {
    contains(nPtr->left, gameName);
  } else if(nPtr->key > gameName) {
    contains(nPtr->right, gameName);
  } else {
    return true; 
  }
}

bool GameBST::contains(TreeNode *nPtr, int timeLeft)
{
  if(!nPtr) {
      return false; 
    } else if (nPtr->playtime < timeLeft) {
      contains(nPtr->left, timeLeft);
    } else if(nPtr->playtime > timeLeft) {
      contains(nPtr->right, timeLeft);
    } else {
      return true; 
    }
}