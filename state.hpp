#include "asm.hpp"
#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <bitset>
#include <sstream>
using namespace std;


class GDDNode {

public:
  virtual GDDNode* returnpoint(int x )= 0;
  virtual int returnvariable()=0;
  virtual void setP(GDDNode* x, int y)=0;
  virtual void setvariable(int x) = 0;

//  ostream& operator<< ( ostream& out, const GDDNode)=0;
  //  state recurse(int p);

};

template<class T>
class N1: public GDDNode{
  T variable;
  GDDNode* p[2];



  GDDNode* returnpoint(int x)
  {
    if (x)
      return p[0];
    else
      return p[1];
  }

  int returnvariable()
  {
    return (int)variable;
  }

  void setP(GDDNode* x, int y)
  {
    p[y] = x;
  }

  void setvariable(int x)
  {
    variable = x;
  }

public:
  N1()
{
  p[0] = NULL;
  p[1] = NULL;
}

};

template<class T>
class N2: public GDDNode{

  T variable;
  GDDNode* p[4];



  GDDNode* returnpoint(int x)
  {
    return p[x];
  }


  int returnvariable()
  {
    return (int)variable;
  }

  void setP(GDDNode* x, int y)
  {
    p[y] = x;
  }

  void setvariable(int x)
  {
    variable = x;
  }

public:

  N2()
  {
    for (int i =0;i< 4; i++)
      p[i] = NULL;
  }

};

template<class T>
class N3: public GDDNode{
  T variable;
  GDDNode* p[8];



  GDDNode* returnpoint(int x)
  {
    return p[x];
  }

  int returnvariable()
  {
    return (int)variable;
  }

  void setP(GDDNode* x, int y)
  {
    p[y] = x;
  }

  void setvariable(int x)
  {
    variable = x;
  }

public:

  N3()
  {
    for (int i =0;i< 8; i++)
      p[i] = NULL;
  }

};
//ostream& operator<<(ostream& out, const state& x);



/* Later replace the variables with a single char array

within the methods extract the pointers and the variable*/
