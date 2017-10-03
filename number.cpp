#include "number.h"
#include "atom.h"
#include "variable.h"

bool Number :: match( Number number )
{
  if(number.symbol()==_symbol)return true;
  else return false;
}

bool Number :: match( Atom atom )
{
  return false;
}

bool Number :: match(Variable variable)
{
    return true;
}
