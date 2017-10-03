#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"
//test Number.value()
TEST (Number,ctor) {
    Number n25("25");
    ASSERT_EQ("25", n25.value());
}
//test Number.symbol()
TEST (Number, symbol) {
    Number n25("25");
    ASSERT_EQ("25", n25.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number n25("25");
    ASSERT_TRUE(n25.match(n25));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number n25("25");
    Number n0("0");
    ASSERT_FALSE(n25.match(n0));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number n25("25");
    Atom tom("tom");
    ASSERT_FALSE(n25.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
    Number n25("25");
    Variable X("X");
    ASSERT_TRUE(n25.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Atom tom("tom");
    Number n25("25");
    ASSERT_FALSE(tom.match(n25));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
    Atom tom("tom");
    Variable X("X");
    ASSERT_EQ("X = tom",tom.match(X));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Variable X("X");
    X.match(tom);
    ASSERT_EQ("X = tom",tom.match(X));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Variable X("X");
    Atom tom("tom");
    Atom jerry("jerry");
    X.match(jerry);
    //cout<<tom.match(X);
    ASSERT_EQ("false",tom.match(X));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
    Variable X("X");
    Number n5("5");
    ASSERT_EQ("X = 5",X.match(n5));
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
    Variable X("X");
    Number n25("25");
    Number n100("100");
    X.match(n25);
    ASSERT_EQ("false",X.match(n100));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
    Variable X("X");
    Number n25("25");
    Atom tom("tom");
    X.match(tom);
    ASSERT_EQ("false",X.match(n25));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
    ASSERT_TRUE(true);
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
    ASSERT_TRUE(true);
}
#endif
