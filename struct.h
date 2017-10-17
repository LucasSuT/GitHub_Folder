#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>

using std::string;

class Struct:public Term
{
public:
  Struct(Atom const & name, std::vector<Term *> args):_name(name), _args(args) {_type="Struct";}

  Term * args(int index) {
    return _args[index];
  }

  Atom const & name() {
    return _name;
  }
  string symbol() const{
    string ret =_name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> symbol() + ", ";
    }
    ret += _args[_args.size()-1]-> symbol() + ")";
    return  ret;
  }
  string value() 
  {
    string ret=_name.symbol()+"(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      //cout<<_args[i]-> value()<<endl;
      ret += _args[i]-> value() + ", ";
      //cout<<_args[i]->value()<<endl;
    }
    ret += _args[_args.size()-1]-> value() + ")";
    //cout<<_args[_args.size()-1]-> value()<<endl;
    return ret;
  }
  bool match(Term &term){
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps)
    {
      //cout<<term.symbol();
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++)
      {
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    //cout<<"fail";
    return false;
  }
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
