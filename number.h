#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
#include <sstream>
using std::string;
using std::to_string;

class Number : public Term
{
public:
  Number(double s):_symbol(std::to_string(s))
  {
    _type="Number";
    ostringstream os;
    os << s;
    string str = os.str();
    //cout<<str;
    _value=str;
  }
  string const _symbol;
  string symbol() const
  {
    return _symbol;
  }
  string value()
  {
     return _value;
   }
   bool match(Term & term){
     bool ret = _assignable;
     if(_assignable){
       _value = term.symbol();
       _assignable = false;
     }
     return ret;
   }

 private:
   string _value;
   bool _assignable = true;
};
#endif
