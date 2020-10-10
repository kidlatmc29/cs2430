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

int sumOfBST(BNode* n, int sum);

void printSmallerK(BNode* n, treeElement k);

void clearTree(BNode* n);

int main()
{
  int numOfKeys = 0;
  int count; 
  int sum = 0;
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

  // call sum
  cout << "The sum of the tree is " << sumOfBST(root, sum) << endl;
  // call delete list
  delete root; 

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

int sumOfBST(BNode* n, int sum)
{
  if(n != nullptr) {
    sum += n->value;
    sumOfBST(n->left, sum);
    sumOfBST(n->right, sum);
  }
}

void clearTree(BNode* n)
{
  // post order traversal 
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