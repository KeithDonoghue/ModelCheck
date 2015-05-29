#include "asm.hpp"
#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <bitset>
#include <sstream>
using namespace std;

#define P(p) (NodeType* )(((unsigned long)p) & 0xfffffffffffffffc)
#define MARK(p) (unsigned long)(((unsigned long)p) &3)

ine ADD1 1
#define ADD2 2
#define xp 0
#define yp 1
#define OR 3
#define OR1 4
#define AND 5
#define AND1 6
#define XOR 7
#define XOR1 8
#define myif 9
#define myif1 10
#define myif2 11
#define myfor 12
#define myfor1 13
#define myfor2 1
struct state {



  //  short rand;
  NodeType* prevstate;
  int variables[5];
  bool types[5];
  int instructions[5];
  bool operator==(state const&x);
  bool operator>=(state const&x);
  state recurse(int p);
};

ostream& operator<<(ostream& out, const state& x);


