#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <queue>
#include <stack>
#include <sys/time.h>
#include <ctime>
#include "ModelCheck.hpp"
using namespace std;












void dfs(int processes,state a,hashtable *t){
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
  in =t->HashInsert(x);
  // this->t.HashNodeCount();

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

ModelCheck::ModelCheck(){}
ModelCheck::ModelCheck(int x){

  t.init(x);
}

ModelCheck::~ModelCheck(){}

void ModelCheck::run(int numcores,int processes){
  vector<thread> thread_pool;
  queue<state> mineq;
  //  processes = 4;
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
this->t.HashInsert(x);
  mineq.push(x);
 this->t.HashNodeCount();
  int r = 1;
  //  int numcores = 128;
  int i = 0;
  cout << "main" << endl;
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
  cout << "thex: "<< x << endl;
  in =this->t.HashInsert(x);
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
  // this->t.HashNodeCount();
  //  cout << collisions << endl;
  while(  /*r < numcores && */!mineq.empty()){
    //  cout << "creatre: " << r << endl ;
      x = mineq.front();
      mineq.pop();
      thread_pool.push_back(thread(dfs,processes,x,&(this->t)));
      r++;
}
  //  cout << " first2" << endl ;
  r--;
  while( r >= 0 ){
    //    cout << "join: " << r << endl ;
      thread_pool.at(r).join();
      r--;
}

}
