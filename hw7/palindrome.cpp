#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char* getLetters(char* input) {
  int size = 1;
  // keeps track of number of spaces of invalid characters
  int invalidCounter = 0;
  for (int i = 0; i < strlen(input); i++) {
    // check for spaces or punctuation
    if (!isspace(input[i]) || !ispunct(input[i])) {
      size++;
    }
  }
  // new list to store string without spaces/punctuation
  char* newlist = new char[size];
  for (int i = 0; i < strlen(input); i++) {
    // check for spaces or punctuation
    if (isspace(input[i]) || ispunct(input[i])) {
      // increase to account for invalid spaces
      invalidCounter++;
    }
    else {
      // subtract invalid spaces to place letter at proper index
        // lowercase all letters for comparison
        newlist[i - invalidCounter] = tolower(input[i]);
    }
  }
  return newlist;
}

char* reverseString(char* input) {
  int newSize = strlen(input);
  // allows different index on input array
  // to copy into the backwards string
  int diffIndex = newSize - 1;
  char* backwards = new char[newSize];
  for (int i = 0; i < newSize; i++) {
    backwards[i] = input[diffIndex];
    diffIndex--;
  }
  return backwards;
}

void checkPalindrome(char* input) {
  int size = strlen(getLetters(input));
  //variables to store char array of both arrays
  // received from prev functions
  char* forwardString = new char[size];
  char* backwardString = new char[size];
  forwardString = getLetters(input);
  backwardString = reverseString(forwardString);

  int correctLetters = 0;
  for (int i = 0; i < strlen(forwardString); i++) {
      if (forwardString[i] == backwardString[i]) {
        correctLetters++;
      }
  }
  if (correctLetters == strlen(forwardString)) {
    cout << "\"" << input << "\"" << " IS a palindrome" << endl;
  }
  else {
    cout << "\"" << input << "\"" << " is NOT a palindrome" << endl;
  }
}


int main() {
  char* list = new char[100];
  cout << "Please enter a string:" << endl;
  cin.getline(list, 100);
  // chages string to compare to backwards string
  checkPalindrome(list);

  delete [] list;

  return 0;
}
