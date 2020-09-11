// Ovalles, Isabel
// lab1.cpp
// 09-11-2020

#include <iostream>

using namespace std;

const int ARR_LENGTH = 8;


int main()
{

  int evenNums[8] = {0};
  int index = 0;
  int input;

  cout <<  endl << "Welcome message" << endl;

  //while (evenNums[7] == 0) {
  for (int i = 0; i < ARR_LENGTH; i++) {
    cout << "Please enter an integer: ";
    cin >> input;
    evenNums[index] = input;
    index++;
  }
  //}

  cout << "printing array: " << endl << endl;
  for(int i = 0; i < ARR_LENGTH; i++) {
    cout << "index =  " << i;
    cout << endl << " value = " << evenNums[i] << " ";
    cout << endl;
  }

  // 3.)
  // Write the code needed to accept interger input from the keyboard
  // Unil 8 EVEN numbers greater than or equal to 25 have been stored
  // In a STATIC array

  // 4.)
  //Output the values along with the array index for each

  // 5.)
  // Put the code from 3.) into a function and call the function from main
  // with a PARAMETER that determins the min value that will be stored.
  // Replacing 25. Accept inter input from the keyboard to determine the int main(int argc, char const *argv[]) {
  // value.

  // 6.)
  // Write a function that returns the min value stored in the array and call the fxn
  // from main, printing the value returned in main.

  // 7.)
  // Add the code that will allow the input and serach to be repated as many
  // times as the user desires

  cout << endl << "End of Lab1 Program" << endl;

  return 0;
}
