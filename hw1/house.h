#include <iostream>
#include <math.h>
using namespace std;

class House
{
public:
  // default of 3, 'X', and '*'
  House(int size = 3, char border = 'X', char fill = '*');

  int GetSize(), Perimeter();
  double Area();

  void Grow(), Shrink();
  void SetBorder(char border);
  void SetFill(char fill);
  void Draw();
  void Summary();

private:
  int baseSize;
  char borderChar, fillChar;
};
