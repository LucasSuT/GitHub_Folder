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
    //Number tom("tom");
    //cout<<tom.symbol();
    //if(typeid(_elements[0])==typeid("Number"))cout<<"yes"<<endl;
    //else cout<<typeid(_elements[1]).name();
    /*Number *n=static_cast<Number*>(&_elements[0]);
    if(n)cout<<"yes"<<endl;
    else cout<<"no"<<endl;*/
    string s="[";
    if(_elements.size()>0)
    {
      for(int i=_elements.size()-1;i>0;i--)
      {
        s+=_elements[i]->symbol();
        s+=", ";
      }
      s+=_elements[0]->symbol();
      s+="]";
    }
    else s+="]";
    return s;
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
  //string value() const{return symbol();};
  //bool match(Term & term){};
  //List ()/*: _elements() */{}
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
private:
  vector<Term *> _elements;

};

#endif
