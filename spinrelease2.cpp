#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <queue>
#include <stack>
#include <sys/time.h>
#include <ctime>
#include "hash8.hpp"
using namespace std;


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
hashtable t(64);
MyFreeList NodeType::_allocator(10000000) ;
atomic<int> count ;
atomic<int> collisions;
atomic<int> inserts;
atomic<int> deletes;
atomic<int> fors;
atomic<int> processes ;

atomic<int> sparestate;
/*  The available operations are add/subtract/multiply/divide
with the first operand the destination and the next two the sources
sources can be variables or immediates.*/

int updatePC(state a, int thread){
  return  a.instructions[thread] + 4;
}


int program [] = {ADD,xp,0,1,ADD,yp,0,3,ADD2,2,xp,yp};

int GetTime(){

  struct timeval tv;
  gettimeofday(&tv, NULL);

  int ret = tv.tv_usec;
  ret /= 1000;

  ret += (tv.tv_sec * 1000);

  return ret;
  }


void dfs(state a){
  int r= 0;
  bool in;
  int i = 0;
  int j;
  mystack mine;
  state x;
  mine.push(a);
  while(/* r < numcores && */!mine.empty()){
    //  cout << mine.getsize()<< endl;
      a = mine.top();
      mine.pop();
     for (int p = 0; p  < processes; p++){
  i = a.instructions[p];
  if (i < 10 && i >= 0)
{
  x = recurse(a,p);
// a = x;
 //a.instructions[p] =  updatePC(a,p);        // 4 indices per atomioc instruction
 // cout << a.instructions[p] << endl;
  in = t.HashInsert(x);
  //  t.HashNodeCount();

  if (in != 0)
   {
     //     x.prevstate = in;
     r++;
     mine.push(x);

   }
 }
      }
  }
  cout <<"done"<< endl;
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
  vector<thread> thread_pool;
  queue<state> mineq;
  processes = 4;
  count = 0;
  state x;
  state a;
  int j;
  bool in;
  x.types[0] = 0;
  x.types[1] = 1;
  x.types[2] = 1;
  x.types[3] = 1;
  x.types[4] = 1;
  for (int i = 0; i < 5 ; i++)
    {
  x.variables[i] = 0;
  x.instructions[i] = 0;
    }
  stringstream ss;
  ss << x;
  string object = ss.str();
  cout << object<< endl;
 t.HashInsert(x);
  mineq.push(x);
  t.HashNodeCount();
  int r = 1;
  int numcores = 128;
  int i = 0;
  //  cout << "main" << endl;
  thread_pool.reserve(numcores + 10);
  while( r < numcores && !mineq.empty()){
      a = mineq.front();
      mineq.pop();
      r--;
     for (int p = 0; p  < processes; p++){
  i = a.instructions[p];

  if (i < 10)
{
  x = recurse(a,p);

 // cout << a.instructions[p] << endl;
  in = t.HashInsert(x);
  if (in != 0)
   {
     //     x.prevstate = in;
     mineq.push(x);
     r++;
   }
   //t.HashNodeCount();

 }
    }
  }
  //  cout << " first2" << endl ;
  r =0;
  //  t.HashNodeCount();
  //  cout << collisions << endl;
  while(  /*r < numcores && */!mineq.empty()){
    //  cout << "creatre: " << r << endl ;
      x = mineq.front();
      mineq.pop();
      thread_pool.push_back(thread(dfs,x));
      r++;
}
  //  cout << " first2" << endl ;
  r--;
  while( r >= 0 ){
    //    cout << "join: " << r << endl ;
      thread_pool.at(r).join();
      r--;
}

  timer = GetTime() - timer ;
  cout << endl << timer << endl;

 cout << "inserts: "<<std::dec<< inserts << endl;
 cout << "collisions: " << collisions << endl;
 cout << "deletes: " << deletes << endl;
 cout << inserts + collisions << endl;
 cout << t.HashNodeCount() << endl;	    
 cout << count << endl;



  cout << "count: " << count<< endl;
  return 0;
}
