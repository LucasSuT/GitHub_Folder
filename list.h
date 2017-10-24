#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
#include <typeinfo>
#include "atom.h"
using std::vector;

class List : public Term {
public:
  string symbol() const
  {
    return value();
  }
  string value() const
  {
    string s="[";
    if(_elements.size()>0)
    {
      for(int i=0;i<_elements.size()-1;i++)
      {
        s+=_elements[i]->symbol();
        s+=", ";
      }
      s+=_elements[_elements.size()-1]->symbol();
      s+="]";
    }
    else s+="]";
    return s;
  }
  List ()
  {

  }
  List (vector<Term *>  & elements):_elements(elements)
  {
  }
  Term * head() const
  {
    return _elements[0];
  }
  List * tail() const
  {
    List *l=new List();
    l->_elements=_elements;
    if(l->_elements.size()>0)l->_elements.erase(l->_elements.begin());
    return l;
  }
  vector<Term *> getvec()
  {
    return _elements;
  }
private:
  vector<Term *> _elements;

};

#endif
