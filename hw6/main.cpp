#include "student.h"

using namespace std;

void readAndWrite() {
// declare variables for input/output
// counters to adjust array sizes
ofstream outfile;
string filename;
ifstream infile;

do {
// clears previous data
  infile.clear();
  cout <<  "Please enter the name of the input file:" << endl;
  cin >> filename;
  // attach file to stream
    infile.open(filename);
    if (!infile) {
      cout << "Invalid file.  Please try again." << endl;
    }
  } while (!infile);


  do {
    // clears previous data
    outfile.clear();
    cout <<  "Please enter the name of the output file:" << endl;
    cin >> filename;
    // attach file to stream
    outfile.open(filename);
    if (!outfile) {
      cout << "Invalid file.  Please try again." << endl;
    }
  } while (!outfile);

  int numOfStudents;
  string fname, lname;
  string course;

// 📚 📚 📚 📚 📚 📚 read input file 📚 📚 📚 📚 📚 📚
  infile >> numOfStudents;
  // cout << numOfStudents << endl;
  Student** studentList = new Student * [numOfStudents];

  for (int i = 0; i < numOfStudents; i++) {
    // consumes any blank space
    infile >> ws;
    // gets last name, comma delim
    getline(infile, lname, ',');
    infile >> ws;
    // gets first name, space delim
    getline(infile, fname);
    infile >> ws;
    // gets course string
    infile >> course;

    // cout << "Student " << (i + 1) << endl;
    // cout << "first name: " << fname << endl;
    // cout << "last name: " << lname << endl;
    // cout << "course: " << course << endl;
    // cout << "grades: " << endl;

// all variables used to transfer text file data
// to create object pointers
    /// for grades
    int project, paper, midterm, attend, test1, test2,
        finalexam, q1, q2, q3, q4, q5, qavg;
    // num of students in courses
    int mathCounter;
    int englishCounter;
    int historyCounter;
    // pointers to assign to student object
    English* engStudent;
    Math* mathStudent;
    History* histStudent;
    // switch statement handles number of grades
    // proper assignment relative to course
    switch(course[0]) {
      case 'E':
        infile >> paper >> midterm >> finalexam;
        engStudent = new English(fname, lname, course, paper, midterm, finalexam);
        studentList[i] = engStudent;
        englishCounter++;
        break;

      case 'M':
        infile >> q1 >> q2 >> q3 >> q4 >> q5 >> test1 >> test2 >> finalexam;
        qavg = (q1+q2+q3+q4+q5)/5;
        mathStudent = new Math(fname, lname, course, qavg, test1, test2, finalexam);
        studentList[i] = mathStudent;
        mathCounter++;
        break;

      case 'H':
        infile >> attend >> project >> midterm >> finalexam;
        histStudent = new History(fname, lname, course, attend, project, midterm, finalexam);
        studentList[i] = histStudent;
        historyCounter++;
        break;
    }
  }

// ✏️ ✏️ ✏️ ✏️ ✏️ ✏️ ✏️ write to output file ✏️ ✏️ ✏️ ✏️ ✏️ ✏️ ✏️
string c, fn;
int fe;
char lg;
double ng;
// title section
const char* title = "Student Grade Summary";
outfile.setf(ios::left);
outfile << title;
outfile.fill('-');
outfile.width(22);
outfile << '\n';
outfile << '\n';
// 📕 📕 📕 📕 📕 ENGLISH Students 📕 📕 📕 📕 📕
outfile << '\n' << "ENGLISH CLASS" << '\n';
outfile << '\n';
outfile.fill(' ');
outfile << setw(42) << "Student" << setw(8) << "Final" << setw(8) << "Final" << setw(7) << "Letter" << endl;
outfile << setw(42) << "Name" << setw(8) << "Exam" << setw(8) << "Avg" << setw(7) << "Grade";
outfile.fill('-');
outfile.width(65);
outfile << '\n';
outfile << '\n';
// iterates through double pointer
for (int i = 0; i < numOfStudents; i++) {
  c = studentList[i]->GetCourse();
  fn = studentList[i]->GetFullname();
  fe = studentList[i]->GetFinal();
  lg = studentList[i]->GetGrade();
  ng = studentList[i]->CalcGrade();
// only selects english students
  if (c[0] == 'E') {
    outfile.fill(' ');
    outfile << setw(42) << fn << setw(8) << fe;
    outfile.precision(2);
		outfile << setw(8) << fixed << ng;
		outfile.precision(0);
    outfile << setw(8) << lg << endl;
  }
}
// 🏟 🏟 🏟 🏟 🏟 History Students 🏟 🏟 🏟 🏟 🏟
outfile << '\n' << "HISTORY CLASS" << '\n';
outfile << '\n';
outfile.fill(' ');
outfile << setw(42) << "Student" << setw(8) << "Final" << setw(8) << "Final" << setw(7) << "Letter" << endl;
outfile << setw(42) << "Name" << setw(8) << "Exam" << setw(8) << "Avg" << setw(7) << "Grade";
outfile.fill('-');
outfile.width(65);
outfile << '\n';
outfile << '\n';
for (int i = 0; i < numOfStudents; i++) {
  outfile.fill(' ');
  c = studentList[i]->GetCourse();
  fn = studentList[i]->GetFullname();
  fe = studentList[i]->GetFinal();
  lg = studentList[i]->GetGrade();
  ng = studentList[i]->CalcGrade();
  if (c[0] == 'H') {
    outfile << setw(42) << fn << setw(8) << fe;
    outfile.precision(2);
		outfile << setw(8) << fixed << ng;
		outfile.precision(0);
    outfile << setw(8) << lg << endl;
  }
}
// ➕ ➕ ➕ ➕ ➕ math Students ➕ ➕ ➕ ➕ ➕
outfile << '\n' << "MATH CLASS" << '\n';
outfile << '\n';
outfile.fill(' ');
outfile << setw(42) << "Student" << setw(8) << "Final" << setw(8) << "Final" << setw(7) << "Letter" << endl;
outfile << setw(42) << "Name" << setw(8) << "Exam" << setw(8) << "Avg" << setw(7) << "Grade";
outfile.fill('-');
outfile.width(65);
outfile << '\n';
outfile << '\n';
for (int i = 0; i < numOfStudents; i++) {
  outfile.fill(' ');
  c = studentList[i]->GetCourse();
  fn = studentList[i]->GetFullname();
  fe = studentList[i]->GetFinal();
  lg = studentList[i]->GetGrade();
  ng = studentList[i]->CalcGrade();
  if (c[0] == 'M') {
    outfile << setw(42) << fn << setw(8) << fe;
    outfile.precision(2);
		outfile << setw(8) << fixed << ng;
		outfile.precision(0);
    outfile << setw(8) << lg << endl;
  }
}
// num of each grade
// variables needed
outfile << endl;
outfile << endl;
outfile << "OVERALL GRADE DISTRIBUTION" << endl;
outfile << endl;
int agrade=0, bgrade=0, cgrade=0, dgrade=0, fgrade=0;
for (int i = 0; i < numOfStudents; i++) {
  char studentGrade = studentList[i]->GetGrade();
  cout << studentGrade<<endl;
  switch(studentGrade) {
    case 'A':
      agrade+=1;
      break;
    case 'B':
      bgrade+=1;
      break;
    case 'C':
      cgrade+=1;
      break;
    case 'D':
      dgrade+=1;
      break;
    default:
      fgrade+=1;
      break;
  }
}
outfile << setw(8) << "A:" << agrade << '\n';
outfile << setw(8) << "B:" << bgrade << '\n';
outfile << setw(8) << "C:" << cgrade << '\n';
outfile << setw(8) << "D:" << dgrade << '\n';
outfile << setw(8) << "F:" << fgrade << '\n';

  cout << "Processing complete"<<endl;

  // infile.close();
  // outfile.close();
}

int main() {
  readAndWrite();
  return 0;
}
