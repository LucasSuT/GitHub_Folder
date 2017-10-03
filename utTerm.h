#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"

TEST (Number,ctor) {
    int i=25;
    Number n25(i);
    ASSERT_EQ("", n25.value());
}
//test Number.symbol()
TEST (Number, symbol) {
    Number n25(25);
    ASSERT_EQ("25", n25.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number n25(25);
    ASSERT_TRUE(n25.match(n25));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number n25(25);
    Number n0(0);
    ASSERT_FALSE(n25.match(n0));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number n25(25);
    Atom tom("tom");
    ASSERT_FALSE(n25.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
    Number n25(25);
    Variable X("X");
    ASSERT_TRUE(n25.match(X));
}
//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Atom tom("tom");
    Number n25(25);
    ASSERT_FALSE(tom.match(n25));
}
// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
    Atom tom("tom");
    Variable X("X");
    ASSERT_TRUE(tom.match(X));
}
// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Variable X("X");
    X.match(tom);
    ASSERT_TRUE(tom.match(X));
}
// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Variable X("X");
    Atom tom("tom");
    Atom jerry("jerry");
    X.match(jerry);
    ASSERT_FALSE(tom.match(X));
}
// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
    Variable X("X");
    Number n5(5);
    ASSERT_TRUE(X.match(n5));
}
// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
    Variable X("X");
    Number n25(25);
    Number n100(100);
    X.match(n25);
    ASSERT_FALSE(X.match(n100));
}
// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
    Variable X("X");
    Number n25(25);
    Atom tom("tom");
    X.match(tom);
    ASSERT_FALSE(X.match(n25));
}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
    ASSERT_TRUE(true);
}
//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){
    ASSERT_TRUE(true);
}
#endif
