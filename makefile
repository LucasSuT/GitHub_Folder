#all: utList utAtom utVariable
all: hw5

hw5:	mainScanner.o term.o atom.o
ifeq (${OS}, Windows_NT)
		g++ -o hw5 mainScanner.o term.o atom.o -lgtest
else
		g++ -o hw5 mainScanner.o term.o atom.o -lgtest -lpthread
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
term.o: term.cpp term.h variable.h
	g++ -std=gnu++11 -c term.cpp
atom.o: atom.cpp atom.h term.h number.h
	g++ -std=gnu++11 -c atom.cpp
mainScanner.o: mainScanner.cpp utScanner.h scanner.h struct.h utParser.h parser.h list.h
	g++ -std=gnu++11 -c mainScanner.cpp


clean:
	rm -f *.o *hw5
stat:
	wc *.h *.cpp
