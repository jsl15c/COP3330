#include <iostream>
#include <math.h>
#include "house.h"

using namespace std;

House::House() {
  baseSize = 3;
  borderChar = 'X';
  fillChar = '*';
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
  int houseCenter = ceil(baseSize/2);
  int rows = baseSize*2 + 1;
  int columns = baseSize + 2;


  // // for loop for number of rows
  for (int i = 0; i <= rows; i++) {
    cout << "this is row: " << i << endl;
    // for loop to handle columns
    for (int j = 0; j < i; j++) {
      cout << borderChar << " ";
    }
    cout << endl;
  }
}
