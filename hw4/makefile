# compiles, build exec program, and runs it
allAndRun: song.cpp song.h song.o playlist.cpp playlist.h playlist.o menu.cpp menu.o
					 g++ -c *cpp
					 g++ -o menu song.o playlist.o menu.o
					 ./menu

testsong:	song.cpp test.cpp song.h test.o song.o
						g++ -c *cpp
						g++ -o program song.o test.o
						./program
