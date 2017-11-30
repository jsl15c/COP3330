# compiles, build exec program, and runs it
allAndRun: mystring.h mystring.cpp driver.cpp mystring.o driver.o
	g++ -c *.cpp
	g++ -o mystring mystring.o driver.o
	./mystring

# remove all object file and exec program
clean:
	rm *.o mystring
