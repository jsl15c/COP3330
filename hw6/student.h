#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;


class Student {
public:
  virtual string GetFirstname() const = 0;
  virtual string GetLastname() const = 0;
  virtual string GetFullname() const = 0;
  virtual double CalcGrade() const = 0;
  virtual string GetCourse() const = 0;
  virtual int GetFinal() const = 0;
  virtual char GetGrade() const = 0;
protected:
  Student(string fname, string lname, string c);
  string firstName;
  string lastName;
  string course;
};

class English : public Student {
public:
  English(string fname, string lname, string c, int p, int m, int f);
  string GetFirstname() const;
  string GetLastname() const;
  string GetFullname() const;
  double CalcGrade() const;
  string GetCourse() const;
  int GetFinal() const;
  char GetGrade() const;
private:
  string firstname;
  string lastname;
  string fullname;
  int paper, midterm, finalexam;
};

class Math : public Student {
public:
  Math(string fname, string lname, string c, int q, int t1, int t2, int f);
  string GetFirstname() const;
  string GetLastname() const;
  string GetFullname() const;
  double CalcGrade() const;
  string GetCourse() const;
  int GetFinal() const;
  char GetGrade() const;
private:
  string firstname;
  string lastname;
  string fullname;
  int quizavg, test1, test2, finalexam;
};

class History : public Student {
public:
  History(string fname, string lname, string c, int a, int p, int m, int f);
  string GetFirstname() const;
  string GetLastname() const;
  string GetFullname() const;
  double CalcGrade() const;
  string GetCourse() const;
  int GetFinal() const;
  char GetGrade() const;
private:
  string firstname;
  string lastname;
  string fullname;
  int attend, project, midterm, finalexam;
};
