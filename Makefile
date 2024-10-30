CXX = g++
CXX_FLAG = --std=c++11 -g

all: testlist testrest

testlist: testlist.o intlist.o
	$(CXX) $(CXX_FLAG) -o testlist testlist.o intlist.o

testrest: testrest.o intlist.o
	$(CXX) $(CXX_FLAG) -o testrest testrest.o intlist.o

testlist.o: testlist.cpp
	$(CXX) -c $(CXX_FLAG) testlist.cpp

testrest.o: testrest.cpp
	$(CXX) -c $(CXX_FLAG) testrest.cpp

intlist.o: intlist.cpp
	$(CXX) -c $(CXX_FLAG) intlist.cpp

clean:
	rm -f testrest testlist *.o
