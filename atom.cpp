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

string Atom :: match(Variable variable)
{
    /*if(variable.value()==_symbol)
    {*/
    string returnstring="";
    if(variable.value()=="")
    {
      returnstring+=variable._symbol+" = "+_symbol;
      return returnstring;
    }
    else if(variable.value()==_symbol)return returnstring+=variable._symbol+" = "+_symbol;
    else if(variable.value()!=_symbol)return returnstring+="false";
    return "NULL";
    //}
}
