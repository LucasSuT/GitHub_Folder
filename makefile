all: hw2
hw2: mainNumber.o atom.o number.o variable.o
ifeq (${OS}, Windows_NT)
		g++ -o hw2 mainNumber.o atom.o number.o variable.o -lgtest
else
		g++ -o hw2 mainNumber.o atom.o number.o variable.o -lgtest -lpthread
endif
mainNumber.o: mainNumber.cpp utTerm.h
	g++ -std=gnu++11 -c mainNumber.cpp
atom.o: atom.h variable.h number.h atom.cpp
	g++ -std=gnu++11 -c atom.cpp
number.o: atom.h variable.h number.h number.cpp
	g++ -std=gnu++11 -c number.cpp
variable.o: atom.h variable.h number.h variable.cpp
	g++ -std=gnu++11 -c variable.cpp
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o exp
endif
