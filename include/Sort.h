#include <list>
#include "Shapes.h"
#include <iostream>
using namespace std;

bool compIncreaingPerimeter(Shape* b,Shape* c)
{
    return b->perimeter() < c->perimeter();
}

bool compDecreasingPerimeter(Shape* b,Shape* c)
{
    return b->perimeter() > c->perimeter();
}

bool compIncreasingArea(Shape* b,Shape* c)
{
    return b->area() < c->area();
}

bool compDecreasingArea(Shape* b,Shape* c)
{
    return b->area() > c->area();
}

bool compIncreasingCompactness(Shape* b,Shape* c)
{
    return (b->area()+b->perimeter()) < (c->area()+c->perimeter());
}

class Sort {

  public :static void sortByIncreasingPerimeter(std::list<Shape *>  *shapeList)
  {
        //list<Shape *> :: iterator iter=shapeList->begin();
        /*  //印出排序前list sequence
        cout<<*iter<<endl;
        for(;iter!=shapeList->end();iter++)
        {
          Shape *s = *iter;
          std::cout<<s->getShapeName()<<"\n";
        }
        iter=shapeList->begin();
        */
      shapeList->sort(compIncreaingPerimeter);
        /*  //印出排序後list sequence
        iter=shapeList->begin();
        for(;iter!=shapeList->end();iter++)
        {
          Shape *s = *iter;
          std::cout<<s->getShapeName()<<"\n";
        }
          cout<<"\n\n";
        */
  }

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
  {
        //list<Shape *> :: iterator iter=shapeList->begin();
        shapeList->sort(compDecreasingPerimeter);
          /*  //印出排序後list sequence
          iter=shapeList->begin();
          for(;iter!=shapeList->end();iter++)
          {
            Shape *s = *iter;
            std::cout<<s->getShapeName()<<"\n";
          }
          cout<<"\n\n";
          */
  }

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList)
  {
        //list<Shape *> :: iterator iter=shapeList->begin();
        shapeList->sort(compIncreasingArea);
          /*  //印出排序後list sequence
          iter=shapeList->begin();
          for(;iter!=shapeList->end();iter++)
          {
            Shape *s = *iter;
            std::cout<<s->getShapeName()<<"\n";
          }
            cout<<"\n\n";
          */
  }

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList)
  {
        //list<Shape *> :: iterator iter=shapeList->begin();
        shapeList->sort(compDecreasingArea);
          /*  //印出排序後list sequence
          iter=shapeList->begin();
          for(;iter!=shapeList->end();iter++)
          {
            Shape *s = *iter;
            std::cout<<s->getShapeName()<<"\n";
          }
            cout<<"\n\n";
          */
  }

  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList)
  {
        //list<Shape *> :: iterator iter=shapeList->begin();
        shapeList->sort(compIncreasingCompactness);
          /*  //印出排序後list sequence
          iter=shapeList->begin();
          for(;iter!=shapeList->end();iter++)
          {
            Shape *s = *iter;
            std::cout<<s->getShapeName()<<"\n";
          }
            cout<<"\n\n";
          */
  }
};
