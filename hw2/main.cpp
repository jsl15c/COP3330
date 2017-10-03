#include <iostream>
#include "date.h"

using namespace std;

int main()
{
  Date d2(2, -28, 2003);
   Date d1(3, 2, 2000);
   Date d3(1, 1, 2001);

  //  cout << "default: ";
  //  d2.Show();
  //  d2.SetFormat('T');
  //  cout << "two digit: ";
  //  d2.Show();
  //  cout << "before increment: ";
  //  d2.Show();
  //  d2.Increment(366);
  //  cout << "after increment: ";
  //  d2.Show();
  //  d2.SetFormat('L');
  //  cout << "long format: ";
  //  d2.Show();
  //  cout << "set date: ";
  //  d2.Set(9,3,2023);
  //  d2.Show();

  //  d2.Input();
  //  d2.Show();

  // === COMPARE TESTS ===
   d3.Compare(d1);
   cout << endl;
   d1.Compare(d3);
}
