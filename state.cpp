//#include "asm.hpp"
#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <bitset>
#include <sstream>
#include "state.hpp"
using namespace std;


/*
#define P(p) (NodeType* )(((unsigned long)p) & 0xfffffffffffffffc)
#define MARK(p) (unsigned long)(((unsigned long)p) &3)


ostream& operator<<(ostream& out, const state& x){
  out << 
x.instructions[0] << 
x.instructions[1] << 
x.instructions[2] << 
x.instructions[3] << 
x.instructions[4] << 
x.variables[0] << 
x.variables[1] << 
x.variables[2] << 
x.variables[3] << 
x.variables[4] << 
    x.types[0] <<
    x.types[1] <<
    x.types[2] <<
    x.types[3] <<
    x.types[4] ;
    return out;
    }



bool state::operator==(state const&x)
  {
    int j = 0;
    for (int i= 0 ; i < 5 ; i++){
      if( variables[i] == x.variables[i])
	j++;
      if(types[i] == x.types[i])
	j++;
      if (instructions[i] == x.instructions[i]){
	j++;
      }
    }
    return j == 15;
  }

bool state::operator>=(state const&x)
  {
    return instructions[0] + instructions[1] + instructions[2] + instructions[3] + instructions[4] + variables[0] + variables[1] + variables[2] + variables[3] + variables[4] + types[0] + types[1] + types[2] + types[3] + types[4] > x.variables[0] + x.variables[1] + x.variables[2] + x.variables[3] + x.variables[4] + x.instructions[0]+ x.instructions[1] + x.instructions[2] + x.instructions[3] + x.instructions[4] + x.types[0] + x.types[1] + x.types[2] + x.types[3] + x.types[4];
  }
*/

#define vspernode
#define statesize 5
GDDNode* StateAdd(char* state,int v )
{

  int s =  statesize*8;
  int b = s - vspernode*v; //bit index
  int a = b/8; // char index
  int c = b%8; // bits into char
  int d = 8 - c; // bits taken from char for v
  int e = vspernode - d; // bits left to take from next char
  //extract bits from state array into x
  x = (state[a] >>  c)& 3;
  if (a)
    {
      char k = 0xff;
      k = k << (8 - e);
      k = k >> (8 - e);
      x = (state[a - 1] & k) << d;
    }

}

int main(){

  char state[statesize];
  char state1[statesize];

  for (int i= 0 ; i < 20 ; i++)
    {

    }


  GDDNode* n;
  GDDNode* node = new N2<char>;
  cout << node->returnvariable() << endl;
  GDDNode* node1 = new N1<int>;
  node->setP(node1, 3);
  node->setvariable(1);
  node1->setvariable(1544432);
  cout << node->returnvariable() << endl;
  n= node->returnpoint(3);
  cout << n->returnvariable() << endl;

  return 0;
}
