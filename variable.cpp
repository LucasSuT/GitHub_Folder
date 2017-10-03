#include "variable.h"
#include "atom.h"
#include "number.h"

bool Variable :: match( Atom atom )
{
  /*bool ret = _assignable;
  if(_assignable)
  {
    _value = atom._symbol ;
    _assignable = false;
  }
  else return _assignable;

  if(ret==true)return true;
  return ret;*/
  _value = atom._symbol ;
  _assignable = false;
  return true;
}

string Variable :: match(Number number)
{
  string returnString="";
  if(_value=="")
  {
    _value=number.value();
    returnString+=_symbol+" = "+number.value();
    return returnString;
  }
  else
  {
    //cout<<"not NULL";
    if(_value==number.value())
    {
      returnString+="true";
      return returnString;
    }
    else return "false";
  }
  //else return "false";
  /*string returnString="";
  returnString+=_symbol+" = "+number.value();
  return returnString;*/
}
