#include "date.h"
// fix two digit format
using namespace std;

Date::Date(int m, int d, int y) {
  // check for invalid date
    // create DateIsInvalid() function
  if (DateIsInvalid(m, d, y)) {
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
  // initial input
  cout << "Enter a date (mm/dd/yyyy): " << endl;
  cin >> monthNum;
  cin.get();
  cin >> day;
  cin.get();
  cin >> year;
  // checks for valid date (min and max number of days, leap year)
  while (DateIsInvalid(monthNum, day, year)) {
    cout << "Invalid date entered.  Try again: " << endl;
    cin >> monthNum;
    cin.get();
    cin >> day;
    cin.get();
    cin >> year;
  }
}

void Date::Show() {
  // array of months
  string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "June",
                         "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

  switch(format) {
    // default format
    case 'D':
      cout << monthNum << "/";
      cout << day << "/";
      cout << year;
      break;

    // two digit format
    case 'T':
      cout.fill('0');
      cout.width(2);
      cout << monthNum << "/";
      cout.fill('0');
      cout.width(2);
      cout << day << "/";
      // stores new format of year
        // prevents changing private member value
      int tempYear;
      // converts year to last two digits
      if (year >= 1000) {
        tempYear = year % 100;
      }
      else if (year >= 100) {
        tempYear = year % 10;
      }
      else {
        tempYear = year;
      }
      // print year with leading 0 if less than two digits
      if (tempYear > 9) {
        cout << tempYear;
      }
      else {
        cout.fill('0');
        cout.width(2);
        cout << tempYear;
      }
      break;

    // long format
    case 'L':
      cout << monthNames[monthNum - 1] << " ";
      cout << day << ", ";
      cout << year;
      break;
    // if invalid parameters in SetFormat function
    default:
      cout << monthNum << "/";
      cout << day << "/";
      cout << year;
      break;
  }
  cout << endl;
  cout << endl;
}

bool Date::Set(int m, int d, int y) {
  if (DateIsInvalid(m, d, y)) {
    return false;
  }

  else {
    monthNum = m;
    day = d;
    year = y;
    return true;
  }
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
  // temp value of day
  int tempDay = day;
  int tempMonth = monthNum;
  // check if increment will surpass # of days in month
  while (day + numDays > DaysPerMonth(monthNum, year)) {
    // decrease increment number by days per each
    // respective month to land on the correct month
    numDays -= DaysPerMonth(monthNum, year);
    // if surpasses 12, increase year, reset month to 1
    if (monthNum == 12) {
      // requires reset to zero to increment month by 1
      monthNum = 0;
      year++;
    }
    monthNum++;
  }
  day += numDays;
}

int Date::Compare(const Date& d) {
  return 0;
}

int Date::DaysPerMonth(int m, int y) {
  // if a month with 31 days
  if ((m % 2 != 0 && m <= 7) ||
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

bool Date::DateIsInvalid(int m, int d, int y) {
  if (m < 1 || m > 12 ||d < 1 || y < 1 ||
    d > DaysPerMonth(m, y)) {
    return true;
  }
  else {
    return false;
  }
}
