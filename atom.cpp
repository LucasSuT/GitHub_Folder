#include <iostream>
#include "atom.h"
#include "number.h"
#include "variable.h"

using namespace std;

void Atom :: test()
{
    cout<<"test";
}

bool Atom :: match(Number number)
{
    return false;
}

bool Atom :: match(Variable variable)
{
    /*if(variable.value()==_symbol)
    {*/
    string returnstring="";
    if(variable.value()=="")
    {
      returnstring+=variable._symbol+" = "+_symbol;
      return true;
    }
    else if(variable.value()==_symbol)return true;
    else if(variable.value()!=_symbol)return false;
    return true;
    //}
}
