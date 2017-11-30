#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>

#include "mystring.h"

using namespace std;

ostream& operator<< (ostream& o, const MyString& s) {
  // print member data
  o << s.data;
  // o << '\n' << s.length << '\n';
  return o;
}

istream& operator>> (istream& i, MyString& s) {
  // clear memory
  delete [] s.data;
  int length = 1;
  char * tempfordata = new char[length];
  // keeps track of spaces to input chars
  int index;
  // ignores spaces of input
  // includes tabs and newline
  while (isspace(i.peek())) {
    i.ignore();
 }
 index = 0;
 // not empty space
  while(!isspace(i.peek())) {
    // input char
    i >> tempfordata[index];
    length++;
    index++;
  }
  length++;
  index++;
  tempfordata[index] = '\0';
  s.data = tempfordata;
  return i;
}

istream& getline (istream& i , MyString& s , char delim) {
  delete [] s.data;
  // index for char and spaces
  int index = 0;
  int length = 1;
  char * temp = new char[length + 1];

  while((i.peek() != delim) && !(i.eof())) {
    temp[index] = i.get();
    index++;
    length++;
  }
  i.ignore();
  index++;
  temp[index] = '\n';
  s.data = temp;

  return i;
}

MyString operator+ (const MyString& a, const MyString& b) {
  // create new object
  MyString s;
  // set new object equal to one of passed in objects
  s = a;
  // concatenate
  s += b;
  return s;
}

MyString& MyString::operator=(const MyString& a) {
  // get length for new object
  if(*this != a)
	{
		delete [] data;
		length = a.length;
		data = new char[length];
    // copy to new object
		for(int i = 0; i < length; i++)
		{
			data[i] = a.data[i];
		}
		data[length - 1] = '\0';
	}
	return *this;
}

bool operator< (const MyString& a, const MyString& b) {
  int counter = 0;
	while(a.data[counter] == b.data[counter]) {
    counter++;
  }
  int result = (a.data[counter]) - (b.data[counter]);
  if (result < 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator> (const MyString& a, const MyString& b) {
  int counter = 0;
	while(a.data[counter] == b.data[counter]) {
    counter++;
  }
  int result = (a.data[counter]) - (b.data[counter]);
  if (result > 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator>= (const MyString& a, const MyString& b) {
  int counter = 0;
	while(a.data[counter] == b.data[counter]) {
    counter++;
  }
  int result = (a.data[counter]) - (b.data[counter]);
  if (result >= 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator<= (const MyString& a, const MyString& b) {
  int counter = 0;
	while(a.data[counter] == b.data[counter]) {
    counter++;
  }
  int result = (a.data[counter]) - (b.data[counter]);
  if (result <= 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator== (const MyString& a, const MyString& b) {
  int counter = 0;
	while(a.data[counter] == b.data[counter]) {
    counter++;
  }
  int result = (a.data[counter]) - (b.data[counter]);
  if (result == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator!= (const MyString& a, const MyString& b) {
  int counter = 0;
	while(a.data[counter] == b.data[counter]) {
    counter++;
  }
  int result = (a.data[counter]) - (b.data[counter]);
  if (result != 0) {
    return true;
  }
  else {
    return false;
  }
}

MyString::MyString() {
  length = 1;
  data = new char[length];
}

MyString::MyString(const char* string) {
  length = strlen(string) + 10;
  data = new char[length];

  for (int i = 0; i < strlen(string); i++) {
    data[i] = string[i];
  }
}

MyString::MyString(int num) {
  // find out how many digitz in num
  int counter = 0;
  int temp = num;
  // keeps dividing until num is 0
      // equivalent to number of digits in num
  while (temp != 0) {
    temp = temp/10;
    counter++;
  }
  // store length
  length = counter;
  // create new arr with extra length
  data = new char[counter + 1];

  for (int i = (counter-1); i >= 0; i--) {
    data[i] = ((num%10)+48);
    num = num/10;
  }
}

int MyString::getLength() const {
  // dereference data
  return *data - 1;
}

MyString& MyString::operator+=(const MyString& s)  	// concatenation/assignment
{
  int newLength = s.length + length-1;
	char * temp = new char[newLength];

  // copy over cstring
	for(int i = 0; i < length - 1; i++) {
		temp[i] = data[i];
	}

  // used to append new string
  // to correct index on temp
  int endIndex;
	for(int i = 0; i < length; i++) {
    endIndex = i + length;
		temp[endIndex] = s.data[i];
	}

	length = length + s.length;
	delete [] data;
	data = temp;	// resultant object replaces calling object
	return *this;
}

const char * MyString::getCString() const       // return c-string equiv
{
	return data;
}

MyString::~MyString()                          		// destructor
{
	delete [] data;
}

const char& MyString::operator[] (unsigned int index) const
{
	if (index < length - 1) {
		return data[index];
  }
	else {
		return data[length - 1];
  }
}
