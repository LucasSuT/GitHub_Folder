#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include <vector>
using std::string;

class Variable : public Term{
public:
  Variable(string s):_symbol(s){_type="Variable";}
  string const _symbol;
  string value()
  {
    if(*_value=="")return symbol();
     return *_value;
   }
  string symbol() const
  {
    return _symbol;
  }
  bool match(Term & term)
  {
    bool ret = _assignable;
    Variable *ps = dynamic_cast<Variable *>(&term);
    if(ps)
    {
      //cout<<"in"<<endl;
      //cout<<_value<<"   "<<ps->_value<<endl;
      if(*(ps->_value)!="")*_value=*(ps->_value);
      ps->_value=_value;
      //cout<<_value<<"   "<<ps->_value<<endl;
    }
    else
    {
      if(_assignable)
      {
        *_value = term.value();
        _assignable = false;
      }
    }

    return ret;
  }
  //vector<Term *>link;
  string address="";
  string *_value=&address;
private:
  bool _assignable = true;
};

#endif
