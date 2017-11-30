#include "student.h"

using namespace std;

Student::Student(string fname, string lname, string c) {
  firstName = fname;
  lastName = lname;
  course = c;
}
// english student member functions
English::English(string fname, string lname, string c, int p, int m, int f) : Student(fname, lname, c) {
  firstname = fname;
  lastname = lname;
  fullname = fname + " " + lname;
  paper = p;
  midterm = m;
  finalexam = f;
}
string English::GetFirstname() const{
  return firstName;
}
string English::GetLastname() const{
  return lastName;
}
string English::GetFullname() const{
  return fullname;
}
double English::CalcGrade() const{
  // Term Paper = 25%, Midterm = 35%, Final Exam = 40%
  return (paper*0.25) + (midterm*0.35) + (finalexam*0.4);
}
string English::GetCourse() const{
  return course;
}
int English::GetFinal() const{
  return finalexam;
}
char English::GetGrade() const{
  int num = CalcGrade()/10;
  switch(num) {
    case 10:
      return 'A';
      break;
    case 9:
      return 'A';
      break;
    case 8:
      return 'B';
      break;
    case 7:
      return 'C';
      break;
    case 6:
      return 'D';
      break;
    default:
      return 'F';
      break;
  }
}



// math student member functions
Math::Math(string fname, string lname, string c, int q, int t1, int t2, int f) : Student(fname, lname, c) {
  firstname = fname;
  lastname = lname;
  fullname = fname + " " + lname;
  test1 = t1;
  test2 = t2;
  finalexam = f;
  quizavg = q;
}
string Math::GetFirstname() const{
  return firstname;
}
string Math::GetLastname() const{
  return lastname;
}
string Math::GetFullname() const{
  return fullname;
}
double Math::CalcGrade() const{
  // * Quiz Average = 15%, Test 1 = 25%, Test 2 = 25%, Final Exam = 35%
  return (quizavg*0.15) + (test1*0.25) + (test2*0.25) + (finalexam*0.35);
}
string Math::GetCourse() const{
  return course;
}
int Math::GetFinal() const{
  return finalexam;
}
char Math::GetGrade() const{
  int num = CalcGrade()/10;
  switch(num) {
    case 10:
      return 'A';
      break;
    case 9:
      return 'A';
      break;
    case 8:
      return 'B';
      break;
    case 7:
      return 'C';
      break;
    case 6:
      return 'D';
      break;
    default:
      return 'F';
      break;
  }
}


// history student member functions
History::History(string fname, string lname, string c, int a, int p, int m, int f) : Student(fname, lname, c) {
  firstname = fname;
  lastname = lname;
  fullname = fname + " " + lname;
  attend = a;
  project = p;
  midterm = m;
  finalexam = f;
}
string History::GetFirstname() const{
  return firstName;
}
string History::GetLastname() const{
  return lastname;
}
string History::GetFullname() const{
  return fullname;
}
double History::CalcGrade() const{
  // Attendance = 10%, Project = 30%, Midterm = 30%, Final Exam = 30%
  return (attend*0.10) + (project*0.30) + (midterm*0.30) + (finalexam*0.30);
}
string History::GetCourse() const{
  return course;
}
int History::GetFinal() const{
  return finalexam;
}
char History::GetGrade() const{
  int num = CalcGrade()/10;
  switch(num) {
    case 10:
      return 'A';
      break;
    case 9:
      return 'A';
      break;
    case 8:
      return 'B';
      break;
    case 7:
      return 'C';
      break;
    case 6:
      return 'D';
      break;
    default:
      return 'F';
      break;
  }
}
