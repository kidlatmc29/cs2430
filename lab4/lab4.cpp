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

int sumOfBST(BNode* n);

void printSmallerK(BNode* n, treeElement k);

void clearTree(BNode* n);

void print(BNode* n);

int main()
{
  int numOfKeys = 0;
  int count; 
  treeElement val; 
  BNode *root = nullptr; 

  cout << endl << "Start of Lab 4" << endl;
  cout << "How many keys do you want to add to the BST?: ";
  cin >> numOfKeys; 

  while(count != numOfKeys) {
    cout << "Please enter a value: ";
    cin >> val;
    if(insert(root, val)) {
      count++;
    } else {
      cout << endl << "Please enter a unique vaue next time." << endl;
    }
  }
  

  print(root);

  cout << endl << "End of Lab 4" << endl << endl;
  return 0;
}

bool insert(BNode* &n, treeElement k)
{
  int unique = false;
  if(!contains(n, k)) {
    unique = true;
    if(n == nullptr) {
      n = new BNode; 
      n->value = k;
      n->right = nullptr;
      n->left = nullptr; 
    } else if(n->value > k) {
      insert(n->left, k);
    } else {
      insert(n->right, k);
    }
  }
  return unique;
}

bool contains(BNode* n, treeElement k)
{
  if(n == nullptr) {
    return false;
  } else if (n->value == k) {
    return true;
  } else if (n->value > k) {
    return contains(n->left, k);
  } else {
    return contains(n->right, k);
  }
}

void printSmallerK(BNode* n, treeElement k)
{

}

int sumOfBST(BNode* n)
{
  return -1; 
}

void clearTree(BNode* n)
{
  // post order traversal 
}

void print(BNode* n)
{
  if(n != nullptr) {
    cout << n->value << " ";
    print(n->left);
    print(n->right);
  }
}