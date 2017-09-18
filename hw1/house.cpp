#include <iostream>
#include <math.h>
#include "house.h"

using namespace std;

House::House(int size, char border, char fill) {
  if (size > 37) {
    baseSize = 37;
  }
  else if (size < 3) {
    baseSize = 3;
  }
  else {
    baseSize = size;
  }
  borderChar = border;
  fillChar = fill;
}

int House::GetSize() {
  return baseSize;
}

void House::Draw() {
  int totalRows = baseSize*2 + 1;
  int totalColumns = baseSize + 2;
  int triangleRows = baseSize + 2;
  int baseRows = baseSize - 1;

// parent loop for trianglular portion of house
  for (int i = 1; i <= triangleRows; i++) {
    // triangle spaces
      int counter = 1;
      while (counter <= triangleRows - i) {
          cout << " ";
          counter++;
      }

    // triangle fill and border
    for (int j = 1; j <= i; j++) {
      // left border check
      if (j == 1 || (j == 2 && i == triangleRows)) {
        cout << borderChar << " ";
      }
      // right border check
      else if (j == i || (j == i-1 && i == triangleRows)) {
        cout << borderChar << " ";
      }
      // remaining are fill characters
      else {
        cout << fillChar << " ";
      }
    }
    cout << endl;
  }

  // parent loop for base portion of house
  for (int i = 1; i <= baseRows; i++) {
    // base spaces
    int counter = 1;
    while (counter < 3) {
      cout << " ";
      counter++;
    }
    // base fill
    counter = 1;
    while (counter <= baseSize) {
      // determines which fill type is used
        // if last row
      if (i == baseRows || counter == 1 || counter == baseSize) {
        cout << borderChar << " ";
      }
        // remaining is fill
      else {
        cout << fillChar << " ";
      }
      counter++;
    }
    cout << endl;
  }

}


double House::Area() {
  // variable for triangle portion of house
  int triangleBase = baseSize + 2;
  int triangleHeight = baseSize + 2;
  double triangleArea = 0.5 * triangleBase * triangleHeight;
  // cout << triangleHeight << "     😁😁😁😁😁";
  // cout << triangleBase << "     😁😁😁😁😁";

  // variables for squre portion of house
  int squareBase = baseSize;
  int squareHeight = baseSize - 1;
  double squareArea = squareBase * squareHeight;

  // area of total house
  double area = triangleArea + squareArea;

  return area;
}

void House::Grow() {
  if (baseSize == 37) {

  }
  else {
    baseSize++;
  }
}

void House::Shrink() {
  if (baseSize == 3) {

  }
  else {
    baseSize--;
  }
}

int House::Perimeter() {
  int perimeter = baseSize * 5 + 1;
  return perimeter;
}

void House::SetFill(char fill) {
  fillChar = fill;
}

void House::SetBorder(char border) {
  borderChar = border;
}
