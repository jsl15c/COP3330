#include "date.h"

using namespace std;

Date::Date(int m, int d, int y) {
  // check for invalid date
  if (m < 1 || d < 1 || y < 1 || d > DaysPerMonth(m, d, y)) {
    monthNum = 1;
    day = 1;
    year = 2000;
  }

  else {
    monthNum = m;
    day = d;
    year = y;
  }
  format = 'D';
}

void Date::Input() {

}

void Date::Show() {
  // array of months
  string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "June",
                         "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

  switch(format) {
    // default format
    case 'D':
      cout << monthNum << "/" << day
      << "/" << year << endl;
      // spacing
      cout << endl;
      break;

    // two digit format
    case 'T':
      cout.fill('0');
      cout.width(2);
      cout << monthNum << "/";
      cout.fill('0');
      cout.width(2);
      cout << day << "/";
      cout << year << endl;
      // spacing
      cout << endl;
      break;

    // long format
    case 'L':
      cout << monthNames[monthNum - 1] << " "
           << day << ", " << year << endl;
      // spacing
      cout << endl;
      break;
  }
}

bool Date::Set(int m, int d, int y) {
  return true;
}

int Date::GetMonth() {
  return monthNum;
}

int Date::GetDay() {
  return day;
}

int Date::GetYear() {
  return year;
}


// changes display format for each Date object
bool Date::SetFormat(char f) {
  if (f == 'D' || f == 'T' || f == 'L') {
    format = f;
    return true;
  }
  else {
    // do nothing & return false
    return false;
  }
}

void Date::Increment(int numDays) {
    cout << endl;
}

int Date::Compare(const Date& d) {
  return 0;
}

int Date::DaysPerMonth(int m, int d, int y) {
  // if a month with 31 days
  if ((m % 2 != 0 && m < 7) ||
      (m % 2 == 0 && m > 7)) {
    return 31;
  }
  // remaining months except for February
  else if (m != 2) {
    return 30;
  }
  // is February
  else {
    // check leap year
    if (y % 4 == 0 || y % 400 == 0) {
      return 29;
    }
    else {
      return 28;
    }
  }
}
