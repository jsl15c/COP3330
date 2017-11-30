#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include "song.h"

using namespace std;

ostream& operator << (ostream& os, const Song& s) {
   os << '\t' << s.title;		// Display name (after tabbing).
   // Display remaining blanks, so that data lines up on screen.
   for (int i = strlen(s.title) + 1; i < 35; i++)
	 os.put(' ');

   os << '\t' << s.artist;		// Display phone number.
   for (int i = strlen(s.artist) + 1; i < 20; i++)
	 os.put(' ');
   os << '\n';

   return os;
}

Song::Song() {
  strcpy(title, " ");
  strcpy(artist, " ");
  category = category;
  size = 0;
}

void Song::Set(const char* t, const char* a, Style st, int sz) {
  strcpy(title, t);
  strcpy(artist, a);
  size = sz;
  category = st;
  // switch(st) {
  //   case POP:
  //     category = POP;
  //     break;
  //   case ROCK:
  //     category = Style.ROCK;
  //     break;
  //   case ALTERNATIVE:
  //     category = Style.ALTERNATIVE;
  //     break;
  //   case COUNTRY:
  //     category = Style.COUNTRY;
  //     break;
  //   case HIPHOP:
  //     category = Style.HIPHOP;
  //     break;
  //   case PARODY:
  //     category = Style.PARODY;
  //     break;
  //   default:
  //     cout << "invalid input"
  //     break;
  //   }
}

const char* Song::GetTitle() const {
  return title;
}

const char* Song::GetArtist() const {
  return artist;
}

int Song::GetSize() const {
  return size;
}

Style Song::GetCategory() const {
  return category;
}
