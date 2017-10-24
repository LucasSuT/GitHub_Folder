#all: utList utAtom utVariable
all: hw4

hw4:	mainList.o term.o atom.o
ifeq (${OS}, Windows_NT)
		g++ -o hw4 mainList.o term.o atom.o -lgtest
else
		g++ -o hw4 mainList.o term.o atom.o -lgtest -lpthread
endif
utAtom: mainAtom.o atom.o term.o
	g++	-o	utAtom mainAtom.o	term.o atom.o -lgtest -lpthread
utVariable: mainVariable.o atom.o term.o
	g++	-o	utVariable mainVariable.o	term.o atom.o -lgtest -lpthread

mainVariable.o: mainVariable.cpp utVariable.h variable.h term.h
	g++ -std=gnu++11 -c mainVariable.cpp
mainAtom.o: mainAtom.cpp utAtom.h
	g++ -std=gnu++11 -c mainAtom.cpp
mainList.o: mainList.cpp utList.h
	g++ -std=gnu++11 -c mainList.cpp
term.o: term.cpp
	g++ -std=gnu++11 -c term.cpp
atom.o: atom.cpp
	g++ -std=gnu++11 -c atom.cpp
variable.o: variable.h term.h

clean:
	rm -f *.o utList
stat:
	wc *.h *.cpp
