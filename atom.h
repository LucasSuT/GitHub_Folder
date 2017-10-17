#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <iostream>
using std::string;
using namespace std;


class Term{

public:
  virtual string symbol() const= 0;
  virtual string value() 
  {
    return symbol();
  };

  virtual bool match(Term & term) {
    //cout<<symbol()<<endl;
    return symbol() == term.symbol();
  }
  string _type;
  string  *_value;
};

class Atom : public Term{
public:
  Atom (string s):_symbol(s) {
    _type="Atom";
  }

  string symbol() const{
    return _symbol;
  }

  string _symbol;
};


#endif
