#include "variable.h"
#include "atom.h"
#include "number.h"

bool Variable :: match(Atom atom)
{
  _value = atom._symbol ;
  _assignable = false;
  return true;
}
bool Variable :: match( Number number )
{
  string returnString="";
  if(_value=="")
  {
    _value=number.value();
    returnString+=_symbol+" = "+number.value();
    //return returnString;
    return true;
  }
  else
  {
    //cout<<"not NULL";
    if(_value==number.value())
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
