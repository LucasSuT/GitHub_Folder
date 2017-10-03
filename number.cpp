#include "number.h"
#include "variable.h"
#include "atom.h"

bool Number :: match( Number number )
{
  if(number.value()==_value)return true;
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
