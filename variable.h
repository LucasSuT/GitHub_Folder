#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
//#include "Number.h"
using std::string;

class Atom;
class Number;

class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string value(){ return _value; }
  bool match( Atom atom );
  /*{
    bool ret = _assignable;
    if(_assignable)
    {
      _value = atom._symbol ;
      _assignable = false;
    }
    return ret;
  }*/
  string match(Number number);
private:
  string _value="";
  bool _assignable = true;
};

#endif
