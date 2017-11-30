#include "playlist.h"

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
using namespace std;

Playlist::Playlist() {
  size = 0;
  songList = new Song[size];
}

void Playlist::addSong() {
  for (int i = 0; i < size; i++)	{
    cout << songList[i];
  	 if (songList[i] != 1) {
       i++;
     }
     else {
       size++;
       songList[i] = new Song[size];
     }
     delete [] songList;
   }
}

void Playlist::showSongs() const {
  if (size == 0) {
    cout << "Songlist is empty." << endl;
    return;
  }
  cout << "Title		                   Artist	       Style   Size (MB)";
  for (int i = 0; i < size; i++) {
    cout << songList[i];
  }
}
