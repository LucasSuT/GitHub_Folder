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

enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};

class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t, Node *l, Node *r):payload(op), term(t), left(l), right(r) {}
  bool evaluate()
  {
    if(payload==EQUALITY)return left->term->match(*(right->term));
    else if(payload==COMMA || payload==SEMICOLON)
    {
      left->evaluate();
      return right->evaluate();
      //return true;
    }
  }
  Operators payload;
  Term *term;
  Node *left;
  Node *right;
};

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  Term *found(string s,Node *n)
  {
      Term *t=nullptr;
      if(n->payload!=TERM)
      {
        t=found(s,n->left);
        if(t!=nullptr)return t;
      }
      if(n->payload!=TERM)
      {
        t=found(s,n->right);
        if(t!=nullptr)return t;
      }
      if(n->payload==TERM)
      {
        if(n->term->arity()==0)
        {
          if(n->term->symbol()==s)return n->term;
          return nullptr;
        }
        else
        {
          for(int i=0;i<n->term->arity();i++)
          {
            if(n->term->args(i)->symbol()==s)return n->term->args(i);
          }
        }
      }
      return nullptr;
  }

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      if(link==';')return new Variable(symtable[_scanner.tokenValue()].first);
      else if(n!=nullptr)
      {
        //cout<<_terms[0]<<"   "<<_terms[1]<<endl;
        string s=symtable[_scanner.tokenValue()].first;
        //cout<<s<<endl;
        Term *t=found(s,n);
        if(t!=nullptr)return t;
      }
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }

  /*bool found(string s)
  {
    bool find=false;
    for(int i=0;i<_terms.size();i++)
    {
      if(_terms[i]->symbol()==s)
    }
  }*/

  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    //cout<<_terms.size()<<endl;
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }

  void matchings()
  {
    char token;
    _terms.push_back(createTerm());
    if(_scanner.currentChar()=='=')
    {
      _scanner.nextToken();
      _terms.push_back(createTerm());
      Node *left=new Node(TERM,_terms[count++],0,0);
      Node *right=new Node(TERM,_terms[count++],0,0);
      Node *root=new Node(EQUALITY,0,left,right);
      n=root;
      link=_scanner.currentChar();
      if(_scanner.currentChar()==',')
      {
        Node *temp1=n;
        _scanner.nextToken();
        matchings();
        Node *temp2=n;
        /*
        cout<<temp1->left->term->symbol()<<endl;
        cout<<temp2->left->term->symbol()<<endl;
        */
        Node *root=new Node(COMMA,0,temp1,temp2);
        n=root;
      }
      else if(_scanner.currentChar()==';')
      {
        Node *temp1=n;
        _scanner.nextToken();
        matchings();
        Node *temp2=n;
        Node *root=new Node(SEMICOLON,0,temp1,temp2);
        n=root;
      }
    }
  }

  Node* expressionTree()
  {
    return n;
  }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }
  Node *n=nullptr;
  vector<Term *> _terms;
  Scanner _scanner;
  char link=0;
  int _currentToken;
  int count=0;
};
#endif
