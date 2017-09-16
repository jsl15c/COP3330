#include <iostream>
#include "house.h"

using namespace std;

House::House() {
  baseSize = 3;
  // borderChar = 'X';
  // fillChar = '*';
}

House::House(int size, char border, char fill) {
  baseSize = size;
  borderChar = border;
  fillChar = fill;
}

int House::GetSize() {
  return baseSize;
}

void House::Draw() {
  // for loop for all house char + spaces
  for (int i = 0; i < baseSize*2 + 1; i++) {

    // top most point
    for (int j = 0; j < baseSize + 2; j++) {
      // center of x-axis
      if (j == baseSize/2) {
        cout << borderChar;
      }
      else {
        cout << " ";
      }
    }
  }
}
