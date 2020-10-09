// Ovalles, Isabel
// lab4.cpp
// 10-9-2020

#include <iostream>

using namespace std;

typedef int treeElement; 

struct BNode {
  treeElement value;
  BNode *left; 
  BNode *right; 
};

bool insert (BNode* &n, treeElement k);

bool contains(BNode* root, treeElement k);

int sumOfBST(BNode* root);

void clearTree(BNode* root);

int main()
{
  int numOfKeys = 0;
  BNode *root = nullptr; 

  cout << endl << "Start of Lab 4" << endl;
  cout << "How many keys do you want to add to the BST?: ";
  cin >> numOfKeys; 


  cout << endl << "End of Lab 4" << endl;
  return 0;
}

bool insert(BNode* &n, treeElement k)
{

}

bool contains(BNode* root, treeElement k)
{

}

void printSmallerK(BNode* root, treeElement k)
{

}

int sumOfBST(BNode* root)
{

}

void clearTree(BNode* root)
{

}