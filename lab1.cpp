// Ovalles, Isabel
// lab1.cpp
// 09-11-2020

#include <iostream>

using namespace std;

const int ARR_LENGTH = 10;
const char YES = 'y';

void getInput(int max, int arr[]);
int findMin(int arr[]);

int main()
{

  int nums[ARR_LENGTH] = {0};
  int max;
  char again = YES;

  cout <<  endl << "- Welcome to Lab1 - " << endl;

  while (again == YES) {
    cout << "Please enter a max value: ";
    cin >> max;

    getInput(max, nums);

    cout << endl << endl;

    cout << "Printing array.... " << endl;
    for(int i = 0; i < ARR_LENGTH; i++) {
      cout << "#" << i;
      cout << " = " << nums[i] << " ";
      cout << endl;
    }

    cout << "Minimum value: " << findMin(nums) << endl;
    cout << "Again? (y/n): ";
    cin >> again; 
  }

  cout << endl << "- End of Lab1 Program - " << endl;

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
}

int findMin(int arr[])
{
  int min = arr[0];
  for(int index = 1; index < ARR_LENGTH; index++) {
    if(arr[index] < min) {
      min = arr[index];
    }
  }
  return min;
}
