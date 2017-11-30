#include "song.h"

class Playlist {
public:
  Playlist();

  void addSong();
  void showSongs() const;


private:
  Song* songList;
  int size;
};
