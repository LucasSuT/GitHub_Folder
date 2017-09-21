#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <iostream>
#include <list>
using namespace std;

TEST (Sort, sortByIncreasingPerimeter) {
    Rectangle r1(1,1,3,4);
    Circle c1(1,1,3);
      /*  //印出Rectangle和Circle的數據
      cout<<r1.toString()<<endl;
        cout<<"perimeter="<<r1.perimeter()<<endl;
        cout<<"area="<<r1.area()<<endl;
      cout<<c1.toString()<<endl;
        cout<<"perimeter="<<c1.perimeter()<<endl;
        cout<<"area="<<c1.area()<<endl;
      */
    vertex v1,v2,v3;
    v1.x=0;
    v1.y=0;
    v2.x=2;
    v2.y=2;
    v3.x=2;
    v3.y=0;
    Triangle t1(v1,v2,v3);
      /*  //印出Triangle的數據
      cout<<t1.toString()<<endl;
          cout<<"perimeter="<<t1.perimeter()<<endl;
          cout<<"area="<<t1.area()<<endl;
      */
    list<Shape *>shapels;
    shapels.push_back (&r1);
    shapels.push_back (&c1);
    shapels.push_back(&t1);
    Sort :: sortByIncreasingPerimeter(&shapels);
      /*
      Sort :: sortByDecreasingPerimeter(&shapels);
      Sort :: sortByIncreasingArea(&shapels);
      Sort :: sortByDecreasingArea(&shapels);
      Sort :: sortByIncreasingCompactness(&shapels);
      */
    list<Shape *> :: iterator iter=shapels.begin();
    Shape *s=*iter;
    //ASSERT_NEAR(6.82843, s->perimeter(),0.00001);
    ASSERT_EQ("t", s->getShapeName());
    ASSERT_EQ("r", (*(++iter))->getShapeName());
    ASSERT_EQ("c", (*(++iter))->getShapeName());
}

TEST (Sort, sortByDecreasingPerimeter) {
  Rectangle r1(1,1,3,4);
  Circle c1(1,1,3);
  vertex v1,v2,v3;
  v1.x=0;
  v1.y=0;
  v2.x=2;
  v2.y=2;
  v3.x=2;
  v3.y=0;
  Triangle t1(v1,v2,v3);
  list<Shape *>shapels;
  shapels.push_back (&r1);
  shapels.push_back (&c1);
  shapels.push_back(&t1);
  Sort :: sortByDecreasingPerimeter(&shapels);
  list<Shape *> :: iterator iter=shapels.begin();
  Shape *s=*iter;
  ASSERT_EQ("c", s->getShapeName());
  ASSERT_EQ("r", (*(++iter))->getShapeName());
  ASSERT_EQ("t", (*(++iter))->getShapeName());
}

TEST (Sort, sortByIncreasingArea) {
  Rectangle r1(1,1,3,4);
  Circle c1(1,1,3);
  vertex v1,v2,v3;
  v1.x=0;
  v1.y=0;
  v2.x=2;
  v2.y=2;
  v3.x=2;
  v3.y=0;
  Triangle t1(v1,v2,v3);
  list<Shape *>shapels;
  shapels.push_back (&r1);
  shapels.push_back (&c1);
  shapels.push_back(&t1);
  Sort :: sortByIncreasingArea(&shapels);
  list<Shape *> :: iterator iter=shapels.begin();
  Shape *s=*iter;
  ASSERT_EQ("t", s->getShapeName());
  ASSERT_EQ("r", (*(++iter))->getShapeName());
  ASSERT_EQ("c", (*(++iter))->getShapeName());
}

TEST (Sort, sortByDecreasingArea) {
  Rectangle r1(1,1,3,4);
  Circle c1(1,1,3);
  vertex v1,v2,v3;
  v1.x=0;
  v1.y=0;
  v2.x=2;
  v2.y=2;
  v3.x=2;
  v3.y=0;
  Triangle t1(v1,v2,v3);
  list<Shape *>shapels;
  shapels.push_back (&r1);
  shapels.push_back (&c1);
  shapels.push_back(&t1);
  Sort :: sortByDecreasingArea(&shapels);
  list<Shape *> :: iterator iter=shapels.begin();
  Shape *s=*iter;
  ASSERT_EQ("c", s->getShapeName());
  ASSERT_EQ("r", (*(++iter))->getShapeName());
  ASSERT_EQ("t", (*(++iter))->getShapeName());
}

TEST (Sort, sortByIncreasingCompactness) {
  Rectangle r1(1,1,3,4);
  Circle c1(1,1,3);
  vertex v1,v2,v3;
  v1.x=0;
  v1.y=0;
  v2.x=2;
  v2.y=2;
  v3.x=2;
  v3.y=0;
  Triangle t1(v1,v2,v3);
  list<Shape *>shapels;
  shapels.push_back (&r1);
  shapels.push_back (&c1);
  shapels.push_back(&t1);
  Sort :: sortByIncreasingCompactness(&shapels);
  list<Shape *> :: iterator iter=shapels.begin();
  Shape *s=*iter;
  ASSERT_EQ("t", s->getShapeName());
  ASSERT_EQ("r", (*(++iter))->getShapeName());
  ASSERT_EQ("c", (*(++iter))->getShapeName());
}

#endif
