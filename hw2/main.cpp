#include <iostream>
#include "date.h"

using namespace std;

int main()
{
  //  Date d1;		// should default to 1/1/2000
   Date d2(2, 28, 2003);  // should init to 4/10/1992
   // display dates to the screen
   d2.Show();
   d2.SetFormat('T');
   cout << "before increment: ";
   d2.Show();
   d2.Increment(366);
   d2.SetFormat('L');
   cout << "after increment: ";
   d2.Show();
   d2.Set(9,3,2023);
   d2.Show();
   d2.Input();
   d2.Show();
}
