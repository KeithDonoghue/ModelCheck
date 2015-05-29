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

state  recurse(state x, int p)
{
int  j = program[x.instructions[p]];
 int i = x.instructions[p]; 
switch (j){
 case ADD:
   {
     //ADD 2 immediates
   x.variables[program[i + 1] + p*x.types[program[i + 1]]] = program[i + 2] + program[i + 3];
  x.instructions[p] = x.instructions[p] + 4;
   break;
   }
 case ADD1:
   {
     //ADD first slot variable and second slot immediate
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] + program[i + 3];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case ADD2:
   {
     //ADD 2 x.variables
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] + x.variables[program[i + 3] + p*x.types[program[i + 1]]];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case OR:
   {
     //ADD 2 x.variables
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] | x.variables[program[i + 3] + p*x.types[program[i + 1]]];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case OR1:
   {
     //ADD first slot variable and second slot immediate
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] | program[i + 3];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case AND:
   {
     //ADD 2 x.variables
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] & x.variables[program[i + 3] + p*x.types[program[i + 1]]];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case AND1:
   {
     //ADD first slot variable and second slot immediate
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] & program[i + 3];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case XOR:
   {
     //ADD 2 x.variables
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables[program[i + 2] + p*x.types[program[i + 1]]] ^ x.variables[program[i + 3] + p*x.types[program[i + 1]]];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 case XOR1:
   {
     //ADD first slot variable and second slot immediate
  x.variables[program[i + 1] + p*x.types[program[i + 1]]] = x.variables [program[i + 2] + p*x.types[program[i + 1]]] ^ program[i + 3];
  x.instructions[p] = x.instructions[p] + 4;
  break;
   }
 }
 return x;
}

unsigned int DJBHash(const std::string& str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
/* End Of DJB Hash Function */

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

NodeType::NodeType(){
  nextstate = NULL;
  prevstate = NULL;
}


ListPointer::ListPointer()
{
  head = NULL;
  pthread_mutex_init(&mutex, NULL);
}
hashtable::hashtable(unsigned int size)
{
  hsize = size;
  table = new ListPointer[size];
}

hashtable::Find(ListPointer* head, state key)
{
  return head.find(key);
}
hashtable::
hashtable::
hashtable::
hashtable::
hashtable::
