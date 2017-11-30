#include <iostream>

using namespace std;

class Distance {
public:
  Distance() {
    inches = 0;
  }

  Distance(int in) {
    inches = in;
  }

  Distance(int in, int ft, int yd, int mi) {
    inches = in;
    feet = ft;
    yards = yd;
    miles = mi;
  }

private:
  int inches, feet, yards, miles;
};
