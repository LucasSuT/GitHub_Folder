#include "number.h"
#include "atom.h"
#include "variable.h"

bool Number :: match( Number& number )
{
  if(number.symbol()==_symbol)return true;
  else return false;
}

bool Number :: match( Atom& atom )
{
  return false;
}

bool Number :: match(Variable& variable)
{
    if(_value=="")
    {
      _value=variable._symbol;
      return true;
    }
    else if(_value!="")
    {
      if(_value==variable._symbol)return true;
    }
    else return false;
    return true;
}
