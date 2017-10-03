#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <iostream>
using std::string;
using namespace std;

class Number;
class Variable;

class Atom {
public:
  Atom (string s):_symbol(s) {/*cout<<_symbol<<"\n";*/}
  bool operator ==(Atom a) {return _symbol == a._symbol;}
  string _symbol;
  void test();
  bool match(Number number);
  bool match(Variable variable);
};

#endif
