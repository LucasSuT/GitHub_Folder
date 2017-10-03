#ifndef UTATOM_H
#define UTATOM_H
#include "atom.h"

TEST(Atom, first) {
  ASSERT_TRUE(true);
}

TEST(Atom, tom) {
  Atom tom("tom");
  ASSERT_EQ("tom", tom._symbol);
}

TEST(Atom, match_tom_and_jerry) {
  Atom tom("tom");
  Atom jerry("jerry");
  bool a=false;
  int i=5;
  if(i==5)std::cout << i << '\n';
  else std::cout << "false" << '\n';
  EXPECT_FALSE(tom == jerry);
  EXPECT_TRUE(tom == tom);
}

#endif
