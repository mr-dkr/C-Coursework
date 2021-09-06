# Makefile

# the C++ compiler
CXX     = g++
#CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3 -std=c++14

All: all
all: main1 main2 main3

main1:	main1.cpp Bst.h
	$(CXX) $(CXXFLAGS) main1.cpp -o main1

main2:	main2.cpp Bst.h
	$(CXX) $(CXXFLAGS) main2.cpp -o main2

main3:	main3.cpp Bst.h
	$(CXX) $(CXXFLAGS) main3.cpp -o main3

deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.stackdump

