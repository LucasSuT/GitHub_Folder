#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "number.h"
#include "list.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token==ATOMSC){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' )
        {
          int token2=_scanner.nextToken() ;
          vector<Term*> terms;
          /*if(tok==')')return new Struct(*atom, terms);
          else
          {*/
            terms = getArgs();
            if(_currentToken == ')')
            {
                //cout<<"in ))))))\n";
              return new Struct(*atom, terms);
            }
          //}
        }
        else
        {
          return atom;
        }
    }
    else if(token==')')
    {
      _currentToken=')';
      return nullptr;
    }
    else if(token=='[')
    {
      vector<Term*> terms = getArgs();
      //cout<<terms.size()<<endl;
      //if(_currentToken==']')cout<<"yes  "<<_currentToken<<endl;
      //return new List();
      if(terms.size()>0 && _currentToken==']')
      {
        //cout<<"in new List(terms)\n";
        return new List(terms);
      }
      else if(terms.size()==0 && _currentToken==']')
      {
        //cout<<"in new Lise()\n";
        return new List();
      }
      else throw string("unexpected token");
    }
    else if(token==']')
    {
      _currentToken=']';
      return nullptr;
    }
    //else if(tolen==')')
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    //cout<<"in getargs\n";
    Term* term = createTerm();
    vector<Term*> args;
    if(term!=nullptr)
    {
      //cout<<"in\n";
      args.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',')
      {
        args.push_back(createTerm());
      }
    }
    //cout<<_currentToken<<"in\n";
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken=-1;
};
#endif
