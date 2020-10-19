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
  } else if (nPtr->key == gameName) {
    return true;
  } else if (nPtr->key > gameName) {
    return contains(nPtr->left, gameName);
  } else {
    return contains(nPtr->right, gameName);
  }
}

bool GameBST::contains(TreeNode *nPtr, int timeLeft)
{
  if(!nPtr) {
    return false; 
  } else if(nPtr->playtime == timeLeft) {
    return true;
  } else if (nPtr->playtime > timeLeft) {
    return contains(nPtr->left, timeLeft);
  } else {
    return contains(nPtr->right, timeLeft);
  }
}

bool GameBST::remove(string name)
{
  int removed = false; 
  if(contains(root, name)) {
    removed = true; 
  } else {
    cout << name << " does not exist in the tree! " << endl;
  }
  return removed; 
}

void GameBST::remove(TreeNode* &nPtr, string name)
{
  if(!nPtr) {
    return; 
  } else if (nPtr->key < name) {
      remove(nPtr->right, name);
  } else if(nPtr->key > name) {
      remove(nPtr->left, name);
  } else if(nPtr->left != nullptr && nPtr->right != nullptr){ // 2 children
      nPtr->key = findMin(nPtr->right)->key;
      remove(nPtr->right, name);
  } else {
    TreeNode *temp = nPtr; 
    cout << "removing " << nPtr->key << endl;
    nPtr = (nPtr->left != nullptr) ? nPtr->left: nPtr->right; 
    delete temp;
    temp = nullptr;
  }
}

GameBST::TreeNode* GameBST::findMin(TreeNode *nPtr)
{
  if(!nPtr) {
    return nullptr;
  } 
  if(!nPtr->left) {
    return nPtr; 
  }
  return findMin(nPtr->left);
}

void GameBST::clearTree(TreeNode *nPtr)
{
  if(nPtr) {
    if(nPtr->left) {
      clearTree(nPtr->left);
    } else {
      clearTree(nPtr->right);
      delete nPtr; 
      nodePtr = nullptr; 
    }
  }
}

void GameBST::cloneTree(TreeNode *nPtr)
{
  if(nPtr) {
    insert(nPtr->key, nPtr->maxPlayers, nPtr->playtime);
    copyTree(nPtr->left);
    copyTree(nPtr->right);
  } else {
    cout << "leaf lad" << endl;
  }
}