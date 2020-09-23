// Andrea Lee, Jin Hu, Isabel Ovalles
// cpcs 2430 

#include<iostream>
using namespace std; 

void printOut(int n);

int main()
{
  int test = 123456789; 
  printOut(test);

  return 0;
}

void printOut(int n)
{
  if((n/10) == 0) {
    cout << n;
    // printDigit(n);
  } else {
  // ex.) 123%10 = 3
  cout << n%10;
  // printDigit(n%10);
  
  // ex.) 123/10 = 12 
  cout << n/10;
  // printOut(n/10);
  }
}