#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
public:
  // house with default parameters
  Date(int m = 1, int d = 1, int y = 2000);

  // need to check # of days in month for function
  void Input();

  void Show();

  bool Set(int m, int d, int y);

  int GetMonth();
  int GetDay() ;
  int GetYear();

  bool SetFormat(char f);

  // need to check # of days in month for function
  void Increment(int numDays = 1);

  int Compare(const Date& d);

  int DaysPerMonth(int m, int d, int y);

private:
  int monthNum, day, year;
  char format;
};
