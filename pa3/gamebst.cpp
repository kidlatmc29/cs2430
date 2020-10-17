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

}

GameBST::~GameBST()
{
  // call clear list 
  // make sure root is set to nullptr as well HERE
}

void GameBST::insert(string key, int maxPlayers, int playtime)
{
  if(!root) {
    // create new Tree Node
    TreeNode *newNode = new TreeNode;
     

  } 
}
