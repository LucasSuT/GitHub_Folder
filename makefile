all: hw2
hw2: mainNumber.o atom.o number.o variable.o
ifeq (${OS}, Windows_NT)
		g++ -o hw2 mainNumber.o atom.o number.o variable.o -lgtest
else
		g++ -o hw2 mainNumber.o atom.o number.o variable.o -lgtest -lpthread
endif
mainNumber.o: mainNumber.cpp utTerm.h
	g++ -std=gnu++11 -c mainNumber.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++11 -c atom.h atom.cpp
number.o: number.h number.cpp
	g++ -std=gnu++11 -c number.h number.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++11 -c variable.cpp
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o exp
endif
