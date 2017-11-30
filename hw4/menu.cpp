#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include "song.h"
#include "playlist.h"

using namespace std;

void ShowMenu()
// Display the main program menu.
{
   cout << "\n\t\tMusic Menu";
   cout << "\n\tA:\tAdd a song to the playlist";
   cout << "\n\tD:\tDelete a song from the playlist";
   cout << "\n\tF:\tFind a song on the playlist";
   cout << "\n\tS:\tShow the entire playlist";
   cout << "\n\tC:\tCategory summary";
   cout << "\n\tZ:\tShow playlist size";
   cout << "\n\tM:\tShow this menu";
   cout << "\n\tX:\tExit the program" << endl;
}

char isValid(char input) {
	return ((input == 'a') || (input == 'd') || (input == 'f') ||
         (input == 's') || (input == 'c') || (input == 'z') ||
         (input == 'm') || (input == 'x'));
}

char enterOption() {
  char letter;
  cout << "enter a menu option" << endl;
  cin >> letter;
  letter = tolower(letter);
  while (!isValid(letter)) {
    cout << "invalid menu item.  Please try again..." << endl;
    ShowMenu();
    enterOption();
  }
  return letter;
}


int main()
{
   Playlist p;			// Create and initialize a new directory.
   ShowMenu();				// Display the menu.
   switch(enterOption()) {
     case 'a':
       p.addSong();
       break;
     case 's':
       p.showSongs();
       break;
     default:
       cout << "end program";
       break;
   }
   ShowMenu();
   return 0;
}
