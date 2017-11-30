# compiles, build exec program, and runs it
allAndRun: student.cpp main.cpp student.h student.o main.o
	g++ -c *cpp
	g++ -o student student.o main.o
	./student

clean: student.o main.o student.h.gch
	rm *o student.h.gch

test: test.cpp
	g++ -c *cpp
	g++ -o test1 test.o
	./test1
