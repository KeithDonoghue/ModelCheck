#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <queue>
#include <stack>
#include <sys/time.h>
#include <ctime>
//#include "hash8.hpp"
#include "ModelCheck.hpp"
using namespace std;



// statement are defined in Recurse2
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
#define myfor 10


thread_local int x;
MyFreeList NodeType::_allocator(10000000) ;
atomic<int> fors;


atomic<int> sparestate;
/*  The available operations are add/subtract/multiply/divide
with the first operand the destination and the next two the sources
sources can be variables or immediates.*/

int updatePC(state a, int thread){
  return  a.instructions[thread] + 4;
}



// can be read in from command line
int program [] = {ADD,xp,0,1,ADD,yp,0,3,ADD2,2,xp,yp};

int GetTime(){

  struct timeval tv;
  gettimeofday(&tv, NULL);

  int ret = tv.tv_usec;
  ret /= 1000;

  ret += (tv.tv_sec * 1000);

  return ret;
  }



int main(){
 
  int timer = GetTime();

 /*  int xxxxx;
  int* kloo;
  kloo = &x;
  bitset<sizeof(kloo)> baz(string(kloo)); 
  int moostring = baz.to_ulong();
  cout << moostring << endl;
  state2 ab;
  cout << ab.stater[44];
  ab.stater.set();
  cout << ab.stater[44] << endl;
  string mystring = ab.stater.to_string();
  cout << mystring;
  */
  ModelCheck model(64);
  model.run(128,4);

  timer = GetTime() - timer ;
  cout << endl << timer << endl;

  /*
 cout << "inserts: "<<std::dec<< inserts << endl;
 cout << "collisions: " << collisions << endl;
 cout << "deletes: " << deletes << endl;
 cout << inserts + collisions << endl;
 cout << t.HashNodeCount() << endl;
  */	    
  return 0;
}

