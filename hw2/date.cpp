#include "date.h"

using namespace std;

Date::Date(int m, int d, int y) {
  // check for invalid date
  if (m < 1 || d < 1 || y < 1 || d > DaysPerMonth(m, y)) {
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
  while (monthNum < 1 || day < 1 || year < 1 || day > DaysPerMonth(monthNum, year)) {
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
    // if invalid parameters in SetFormat function
    default:
      cout << monthNum << "/" << day
      << "/" << year << endl;
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
  // temp value of day
  int tempDay = day;
  int tempMonth = monthNum;
  // check if increment will change the month
  // if (day + numDays > DaysPerMonth(GetMonth(), GetDay(), GetYear())) {
  if (day + numDays > DaysPerMonth(monthNum, year)) {
    // reset last month to 1 if Increment
    // is more than max days
    if (monthNum + 1 > 12) {
      monthNum = 1;
    }
    else {
      // increment month by 1
      monthNum += 1;
    }
    // set day to remaing days after last day of month
    day = (tempDay + numDays) - DaysPerMonth(tempMonth, year);
  }
  // does not pass max days in month
  else {
    // increment day by numDays
    day = day + numDays;
  }
}

int Date::Compare(const Date& d) {
  return 0;
}

int Date::DaysPerMonth(int m, int y) {
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
