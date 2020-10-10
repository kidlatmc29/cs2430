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

bool insert(BNode* &n, treeElement k);
// inserts a new BNode with k as its value, if k is unique
// PRE: None.
// POST: the tree has one more new node, if k is unique

bool contains(BNode* n, treeElement k);
// checks to see if k is an existing key in the BST
// PRE: was called in insert() 
// POST: returns false if k is not a value in any nodes in the tree, returns 
//  true otherwise

int sumOfBST(BNode* n);
// sums up all the values of the nodes
// PRE: All the values in the tree are positive. 
// POST: The sum will be postive. 

void printSmallerK(BNode* n, treeElement k);
// prints out all values less than k
// PRE: k is key present in the tree
// POST: None. 

void clearTree(BNode* n);
// uses post traversal in order to delete all the nodes in the tree
// PRE: None. 
// POST: All the nodes except the root has been deleted

int main()
{
  int numOfKeys = 0;
  int count; 
  treeElement val; 
  bool unique = false; 
  BNode *root = nullptr; 

  cout << endl << "Start of Lab 4" << endl << endl;
  cout << "How many keys do you want to add to the BST?: ";
  cin >> numOfKeys; 

  while(count != numOfKeys) {
    cout << "Please enter a value: ";
    cin >> val;
    unique = insert(root, val);
    if(unique) {
      count++;
    } else {
      cout << endl << "Please enter a unique positive value next time." << endl;
    }
  }

  cout << endl << endl;
  val = -1; 
  while(!contains(root, val)) {
    cout << "Enter a key: ";
    cin >> val;
    if(contains(root, val)) {
      cout << "Values smaller than " << val << " are: " << endl;
      printSmallerK(root,val);
    } else {
      cout << val << " is not a key in the BST" << endl;
    }
  }
  cout << "The sum of the tree is " << sumOfBST(root) << endl;
  delete root; 
  cout << "Tree is deleted."; 

  cout << endl << endl << "End of Lab 4" << endl << endl;
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

treeElement sumOfBST(BNode* n)
{
  treeElement leftSum; 
  treeElement rightSum; 
  treeElement currentSum;

  if(n != nullptr) {
    leftSum = sumOfBST(n->left);
    rightSum = sumOfBST(n->right);
    currentSum = n->value + leftSum + rightSum;
    return currentSum;
  } else {
    currentSum = 0;
    return currentSum;
  }
}

void clearTree(BNode* n)
{
  if (n != nullptr) {
    clearTree(n->left);
    clearTree(n->right);
    delete n;
  }
}

void printSmallerK(BNode* n, treeElement k)
{
  if(n != nullptr) {
    printSmallerK(n->left, k);
    if(n->value < k){
      cout << n->value << endl;
    }
    printSmallerK(n->right, k);
  }
}