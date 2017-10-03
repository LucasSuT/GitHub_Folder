#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using std::string;
using namespace std;

class Atom;
class Variable;

class Number
{
public:
  string const _symbol,_value;
  Number(string s):_symbol(s),_value(s){}
  string value(){ return _value; }
  string symbol(){return _symbol;}
  bool match( Number number );
  /*{
    if(number.value()==_value)return true;
    else return false;
  }*/
  bool match( Atom atom );
  /*{
    return false;
  }*/
  bool match(Variable variable);
  /*{
    return true;
  }*/
private:
  bool _modifiable=true;
};

#endif
