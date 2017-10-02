# build exec house program
house: driver.o house.o
	g++ -o house driver.o house.o

# compile driver.cpp
driver.o: driver.cpp house.h
	g++ -c driver.cpp

# compile house.cpp
house.o: house.cpp house.h
	g++ -c house.cpp

# compile all .cpp files
compileAll: house.cpp driver.cpp house.h
			g++ -c *cpp

# remove all object file and exec program
clean:
	rm *.o house

# compiles, build exec program, and runs it
allAndRun: house.cpp driver.cpp house.h house.o driver.o
	g++ -c *cpp
	g++ -o house house.o driver.o
	./house
