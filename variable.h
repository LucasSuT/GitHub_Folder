#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
using std::string;

class Atom;
class Number;

class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string value(){ return _value; }
  bool match(Atom atom);
  bool match(Number number);
private:
  string _value="";
  bool _assignable = true;
};

#endif
