# build executable date program
house: main.o date.o
	g++ -o date main.o date.o

# compile main.cpp
main.o: main.cpp date.h
	g++ -c main.cpp

# compile date.cpp
date.o: date.cpp date.h
	g++ -c date.cpp

# compile all .cpp files
compileAll: date.cpp main.cpp date.h
			g++ -c *cpp

# remove all object file and exec program
clean:
	rm *.o date

# compiles, build exec program, and runs it
allAndRun: date.cpp main.cpp date.h date.o main.o
	g++ -c *cpp
	g++ -o date date.o main.o
	./date
