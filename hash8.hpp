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


#define ADD 0
#define ADD1 1
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
#define myfor2 14

extern atomic<int> count ;
extern atomic<int> collisions;
extern atomic<int> inserts;
extern atomic<int> deletes;
extern int program[];


class NodeType;

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

/*
class state2 {
public:
  bitset<8*sizeof(state)> stater;
  };*/



state recurse(state x, int p);
class MyFreeList{

  NodeType* location;
  int space;
  atomic<int> free;
static thread_local DPointer<NodeType,8> first;
static thread_local DPointer<NodeType,8> second;

public:
  DPointer<NodeType,8> head;
  NodeType* tail;

  void deallocate(NodeType* node);
  NodeType* allocate();
  double getcount();
  MyFreeList(int x);
  ~MyFreeList();
};

class mystack{
  NodeType* head;
  int size;
public:
  state top();
  void pop();
  void push(state a);
  int getsize();
  bool empty();
  mystack();
};


class NodeType{

public:
 state key;
  union{
  DPointer<NodeType,8> nnext;
  struct{
    NodeType* nextstate;
    NodeType* prevstate;
    };
  };
  NodeType();
  void* operator new(size_t);
  void operator delete(void* deleter);
private:
  static MyFreeList _allocator;
};

class hashtable{
  unsigned int hsize;
thread_local static DPointer<NodeType,8> *prev1;
thread_local static DPointer<NodeType,8> cur;
thread_local static DPointer<NodeType,8> prev2;
thread_local static DPointer<NodeType,8> next1;
thread_local static DPointer<NodeType,8> first;
thread_local static DPointer<NodeType,8> second;
  NodeType** hp0;  
  NodeType** hp1;  
  NodeType** hp2;  
 
public:
  DPointer<NodeType,8>* table;
  int HashNodeCount();
  hashtable(unsigned int size);
  bool Find(DPointer<NodeType,8>* head, state key);
  bool Insert(DPointer<NodeType,8>* head, NodeType* node);
  bool  Delete(DPointer<NodeType,8>* head,state key);
  bool Search(DPointer<NodeType,8> *head, state key);
  unsigned int  Function(state x );
  NodeType* HashInsert( state s);
bool HashDelete( state key);
bool HashSearch( state key);
};





