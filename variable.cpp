#include "variable.h"
#include "atom.h"
#include "number.h"

bool Variable :: match(Atom& atom)
{
  _value = atom._symbol ;
  _assignable = false;
  return true;
}
bool Variable :: match( Number& number )
{
  string returnString="";
  if(_value=="")
  {
    _value=number.symbol();
    returnString+=_symbol+" = "+number.symbol();
    //return returnString;
    return true;
  }
  else
  {
    //cout<<"not NULL";
    if(_value==number.symbol())
    {
      returnString+="true";
      //return returnString;
      return true;
    }
    else return false;
  }
  //return true;
  return true;
}
