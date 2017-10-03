#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>

using namespace std;

class Variable;
class Atom;

class Number
{
public:
  string _symbol,_value="";
  //Number(string s):_symbol(s),_value(s){}
  Number(int i)
  {
    string s=to_string(i);
    _symbol=s;
    //_value=s;
  }
  string value(){ return _value; }
  string symbol(){return _symbol;}
  bool match( Number number );
  //bool match(Number &number);
  bool match( Atom atom );
  bool match(Variable variable);
private:
  bool _modifiable=true;
};

#endif
