#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  char list[100];
  // new list so original list is not altered
  char newlist[100];
  // keeps track of number of spaces of invalid characters
  int invalidCounter = 0;

  cout << "Please enter a string:" << endl;
  cin.getline(list, 100);
  for (int i = 0; i < strlen(list); i++) {
    // check for spaces or punctuation
    if (isspace(list[i]) || ispunct(list[i])) {
      // increase to account for invalid spaces
      invalidCounter++;
    }
    else {
      // subtract number of invalid spaces to
      // place letter in proper spot
      newlist[i - invalidCounter] = list[i];
    }
  }
}
