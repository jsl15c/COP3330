#include <iostream>
#include "date.h"

using namespace std;

int main()
{
  Date d2(01, 01, 2000);
  Date d1(3, 2, 2017);

   cout << "default: ";
   d2.Show();
   d2.SetFormat('T');
   cout << "two digit: ";
   d2.Show();
   cout << "before increment: ";
   d2.Show();
   d2.Increment(365);
   cout << "after increment: ";
   d2.Show();
   d2.SetFormat('L');
   cout << "long format: ";
   d2.Show();
   d2.SetFormat('J');
   cout << "Julian format: ";
   d2.Show();

   d2.Compare(d1);
   d1.Compare(d2);





}
