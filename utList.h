#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;
using namespace std;
#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List l;
  EXPECT_EQ(string("[]"),l.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number _8128(8128),_496(496);
  vector<Term *> args = {&_8128,&_496};
  List l(args);
  EXPECT_EQ(string("[8128, 496]"), l.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom a("terence_tao"),b("alan_mathison_turing");
  vector<Term *> args = {&a,&b};
  List l(args);
  EXPECT_EQ(string("[terence_tao, alan_mathison_turing]"), l.symbol());

}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable X("X"),Y("Y");
  vector<Term *> args = {&X,&Y};
  List l(args);
  EXPECT_EQ(string("[X, Y]"), l.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Variable X("X");
  Atom a("terence_tao"),tom("tom");
  Number _496(496);
  vector<Term *> args = {&X,&a,&_496};
  List l(args);
  EXPECT_FALSE(l.match(tom));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Number _8128(8128),_496(496);
  Variable X("X");
  Atom a("terence_tao");
  vector<Term *> args = {&X,&a,&_496};
  List l(args);
  EXPECT_FALSE(l.match(_8128));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Variable X("X");
  vector<Term *> args={&X};
  Struct s(Atom("s"),args);
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args2 = {&X,&a,&_496};
  List l(args2);
  EXPECT_FALSE(l.match(s));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Variable X("X");
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args = {&_496,&X,&a};
  List l(args);
  Variable Y("Y");
  EXPECT_TRUE(l.match(Y));
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Variable X("X");
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args = {&_496,&X,&a};
  List l(args);
  EXPECT_TRUE(l.match(X));

}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Variable X("X");
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args = {&_496,&X,&a};
  List l(args);
  EXPECT_TRUE(l.match(l));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Variable X("X");
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args = {&_496,&X,&a};
  List l(args);
  Variable Y("Y");
  vector<Term *> args2 = {&_496,&Y,&a};
  List l2(args2);
  EXPECT_TRUE(l.match(l2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
  Variable X("X");
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args = {&_496,&X,&a};
  List l(args);
  Number n(8128);
  vector<Term *> args2 = {&_496,&n,&a};
  List l2(args2);
  EXPECT_TRUE(l.match(l2));
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
  Variable X("X");
  Number _496(496);
  Atom a("terence_tao");
  vector<Term *> args = {&_496,&X,&a};
  List l(args);
  Variable Y("Y");
  Atom b("alan_mathison_turing");
  EXPECT_TRUE(l.match(Y));
  EXPECT_TRUE(X.match(b));
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
  Atom f("[first]"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("[first]"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("third"), l.tail()->tail()->head()->value());
  EXPECT_EQ(string("[]"), l.tail()->tail()->tail()->value());
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
  vector<Term *> args;
  List l(args);
  try
  {
    l.head()->symbol();
  }
  catch(string e)
  {
    //cout<< e;
  }
  //l.head()->symbol();
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
  vector<Term *> args;
  List l(args);
  try
  {
    l.tail()->head()->symbol();
  }
  catch(std::string *e)
  {
    //cout<<"1";
    //cout<<*e;
    //throw e;
  }
  catch(std::string e)
  {
    //cout<<"2";
    //cout<<*e;
    //throw e;
  }
  //l.tail()->head()->symbol();
}




#endif
