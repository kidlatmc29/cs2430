// Ovalles, Isabel
// lab1.cpp
// 09-11-2020

#include <iostream>

using namespace std;

const int ARR_LENGTH = 10;

void getInput(int max, int arr[]);

int main()
{

  int nums[ARR_LENGTH] = {0};
  int max;

  cout <<  endl << "Welcome message" << endl;

  cout << "Please enter a max value: ";
  cin >> max;

  getInput(max, nums);

/**
  cout << endl << endl;

  cout << "printing array: " << endl;
  for(int i = 0; i < ARR_LENGTH; i++) {
    cout << "#" << i;
    cout << " = " << nums[i] << " ";
    cout << endl;
  }
  **/

  cout << endl << "End of Lab1 Program" << endl;

  return 0;
}


void getInput(int max, int arr[])
{
  int index = 0;
  int input;

  while (arr[ARR_LENGTH - 1] == 0) {
    cout << "Please enter an integer: ";
    cin >> input;
    if(input <= max && input > 0) {
      arr[index] = input;
      index++;
    }
  }

  cout << endl << endl;

  cout << "printing array: " << endl;
  for(int i = 0; i < ARR_LENGTH; i++) {
    cout << "#" << i;
    cout << " = " << arr[i] << " ";
    cout << endl;
  }
}
