#include "hash8.hpp"
using namespace std;




state  recurse2(state x, int p)
{
int*  j = &program[x.instructions[p]];
 int i = x.instructions[p]; 
switch (*j){
  // if statements limited to equals(because im bored)
 case myif:
   {
     //ADD 2 immediates
     if(   x.variables[*(j + 1) + p*x.types[*(j + 1)]] == *(j + 2) + *(j + 3)){
  x.instructions[p] = x.instructions[p] + 1;
     }else{ 
       x.instructions[p] = x.instructions[p] + *(j + 4);
     }
   break;
   }
 case myif1:
   {
     //ADD first slot variable and second slot immediate
     if( x.variables[*(j + 1) + p*x.types[*(j + 1)]] == x.variables[*(j + 2) + p*x.types[*(j + 1)]] + *(j + 3)){
  x.instructions[p] = x.instructions[p] + 1;
     }else{
       x.instructions[p] = x.instructions[p] + *(j+4);
     }
  break;
   }
 case myif2:
   {
     //ADD 2 x.variables
     if( x.variables[*(j + 1) + p*x.types[*(j + 1)]] == x.variables[*(j + 2) + p*x.types[*(j + 1)]] + x.variables[*(j + 3) + p*x.types[*(j + 1)]]){
  x.instructions[p] = x.instructions[p] + 1;
     }else{
       x.instructions[p] = x.instructions[p] + *(j + 4);
     }
  break;
   }
 case ADD:
   {
     //ADD 2 immediates
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = *(j + 2) + *(j + 3);
  x.instructions[p] = x.instructions[p] + 1;
   break;
   }
 case ADD1:
   {
     //ADD first slot variable and second slot immediate
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] + *(j + 3);
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case ADD2:
   {
     //ADD 2 x.variables
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] + x.variables[*(j + 3) + p*x.types[*(j + 1)]];
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case OR:
   {
     //ADD 2 x.variables
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] | x.variables[*(j + 3) + p*x.types[*(j + 1)]];
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case OR1:
   {
     //ADD first slot variable and second slot immediate
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] | *(j + 3);
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case AND:
   {
     //ADD 2 x.variables
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] & x.variables[*(j + 3) + p*x.types[*(j + 1)]];
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case AND1:
   {
     //ADD first slot variable and second slot immediate
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] & *(j + 3);
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case XOR:
   {
     //ADD 2 x.variables
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables[*(j + 2) + p*x.types[*(j + 1)]] ^ x.variables[*(j + 3) + p*x.types[*(j + 1)]];
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 case XOR1:
   {
     //ADD first slot variable and second slot immediate
     x.variables[*(j + 1) + p*x.types[*(j + 1)]] = x.variables [*(j + 2) + p*x.types[*(j + 1)]] ^ *( j + 3);
  x.instructions[p] = x.instructions[p] + 1;
  break;
   }
 }
 return x;
}


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



thread_local  bool saturationmode;
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


//Greater then required for hash chain ordering
bool state::operator>=(state const&x)
  {
    return instructions[0] + instructions[1] + instructions[2] + instructions[3] + instructions[4] + variables[0] + variables[1] + variables[2] + variables[3] + variables[4] + types[0] + types[1] + types[2] + types[3] + types[4] > x.variables[0] + x.variables[1] + x.variables[2] + x.variables[3] + x.variables[4] + x.instructions[0]+ x.instructions[1] + x.instructions[2] + x.instructions[3] + x.instructions[4] + x.types[0] + x.types[1] + x.types[2] + x.types[3] + x.types[4];
  }


void MyFreeList::deallocate(NodeType* node){
	      first = tail->nnext;
	      second.count = first.count + 1;
	second.ptr = node;
	node->nnext.ptr = NULL;
	/*	if (tail == NULL)
	  {
	    tail =&(head.ptr->nnext);
	    }*/
	// 	//cout<< "deallocate" << second.ptr << endl;
	//cout << "deallocate: " << node <<endl;
	while(true)
      {
	//cout << "inside true" << endl;
	//	//cout << "true: " << endl;
	if (first.ptr == NULL)
	  {
	    	//cout << "first if" << endl;
	    if ((tail->nnext).cas(second,first)){
	      	//cout << "second if" << endl;
	free++;
	tail = node;
	break;
	    }else{
	      first = tail->nnext;
	      second.count = first.count + 1;
	      	//cout << "continue" << endl;
	      continue;

	    }
	  }
	first = ((P(first.ptr))->nnext);
      }
}

NodeType* MyFreeList::allocate(){
    //  NodeType* node = new NodeType;
  //  //cout << free << endl;
  if (free <= 15)
    saturationmode = 1;
  if (free !=0 )
    {
    while (true){
            //cout << "allocate" << endl;
      first = head;
      second = (P(first.ptr))->nnext;
      second.count = first.count + 1;
      if (head.cas(second,first)){
	free--;
	//	//cout << "free: "<<dec << free << endl;
	//	//cout << (P(first.ptr))->nnext.ptr << endl;     
	//	(P(first.ptr))->nnext.count = 0;
	(P(first.ptr))->nnext.ptr = NULL;
		if (tail == P(first.ptr))
	 tail = P(head.ptr);
		//cout <<	(P(first.ptr))<< endl<< free<< endl;
       	return 	(P(first.ptr));
    }
    }
    }
  return NULL;
  }

double MyFreeList::getcount(){
    return space - free;

  }

MyFreeList::MyFreeList(int x){
    space  = x;
    free = space;
    //cout << "constructor" << endl;
    location  = new NodeType[space];
    //cout << "constructor2" << endl;
    //cout << "constructor3" << endl;
    for (int i = 0; i< space;i++)
  {
     location[i].nnext.ptr = &location[i+1];
     location[i].nnext.count = 0;
     //     //cout <<location[i].nnext.ptr << "--";
  }
  location[space-1].nnext.ptr = NULL; 
  //cout << endl << location << endl;
  head.ptr = &location[0];
  head.count = 0;
  //cout << head.ptr << endl;
  tail = &location[space -1];
  //cout << tail << endl;
  }

MyFreeList::~MyFreeList(){
    delete[] location; 
  }
 

void mystack::push(state a){
  NodeType* temp = new NodeType;
  temp->key = a ;
  //  cout << "head" <<  head<< endl;
  temp->nextstate = head;
  head = temp;
  //  cout << "head2" <<  head<< endl;
  size++;
}


mystack::mystack(){
  head = NULL;
  size = 0;
}
bool mystack::empty(){
  return size == 0;
}

int mystack::getsize(){
  return size;
}

void mystack::pop(){
  NodeType* temp = head;
  head = head->nextstate;
  delete temp;
  size--;
}

state mystack::top(){
  //  cout << "head" <<  head<< endl;
  return head->key;
}


NodeType::NodeType(){
  nextstate = NULL;
  prevstate = NULL;
}
void* NodeType::operator new(size_t){
    return _allocator.allocate();
   }

void NodeType::operator delete(void* deleter){
  //cout << "deaaaaa" << endl;
  _allocator.deallocate(P(deleter));
  }

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



int hashtable::HashNodeCount(){
    int count = 0;
    int* tabla = new int[hsize];
    int interim = 0 ;
    DPointer<NodeType,8> node ;  
 for (unsigned int i = 0 ; i < hsize; i++)
      {
	node = table[i];
	while (P(node.ptr) != NULL){
	  count++;
	  interim++;
node = (P(node.ptr))->nnext;
	}
	tabla[i] = interim;
	interim = 0; 
     }
 for (unsigned int i = 0 ; i < hsize; i++)
      {
	cout << "tabla " << i << ": " << tabla[i] << endl; 
     }
 return count;
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

hashtable::hashtable()
{

  hsize = 0;
  table = NULL;
 
}
void hashtable::init(unsigned int size)
{

  hsize = size;
  table = new DPointer<NodeType,8>[size];
  /*
  hp0 = &HP[3*j];
  hp1 = &HP[3*j + 1];
  hp2 = &HP[3*j + 2];
  */
}

  bool hashtable::Find(DPointer<NodeType,8>* head, state key)
  {
    cout << "hello:" ;
    state ckey;
  TryAgain: 
    prev1 = head;
    cur = *prev1;
    prev2 = cur;
    next1 = cur;
    //*hp1 = cur;
    //if (prev->next != cur)
    //goto TryAgain;
    while (true)
      {
	//	cout << "find"<<endl;
    if (P(cur.ptr) == NULL) {
	  return false;

    }
    cout << "hello:" <<  (P(cur.ptr))->nnext.ui;
	next1 = (P(cur.ptr))->nnext;
	//*hp0 = next;
	//if (cur->next != next)
	//goto TryAgain;
	ckey = (P(cur.ptr))->key;
	if (prev1->ptr != P(cur.ptr) || prev1->count != cur.count){
    goto TryAgain;
	}
	if (!MARK(cur.ptr)){
	    if(ckey>= key){
	      return (ckey == key);
 	    }
	    prev1 = &((P(cur.ptr))->nnext);
	    prev2 = cur;
	    //*hp2 = cur
	  }else{
	  first = cur;
	  second = next1 ;
	  second.count = first.count + 1;
	  second.ptr = P(second.ptr);
	  first.ptr = P(first.ptr);
	  if ((*prev1).cas(second,first)){
	    delete(P(cur.ptr));
	  next1.count = cur.count +1;
	  }
	  else 
	    goto TryAgain;
	}
	cur = next1;
	//	*hp1 = next;
      }
  }
  
bool hashtable::Insert(DPointer<NodeType,8>* head, NodeType* node)
  {
    //    cout << &head << endl;
    //    cout <<head << endl;
    //    cout << &head << endl;
    bool result;
    state key;
    state key1;
    key = node->key;
    while (true){
      //      cout << "insert" << endl;
      if (Find(head,key))
    {     
      //  this->collisions++;
      result = false;
      break;
    }
    if(saturationmode)
	{
	  /*

 Hashtable full, delete for every entry 
	  */	 
	  if (cur.ptr != NULL)// node belongs in midle of list
	    {
	    key1 =(P(cur.ptr))->key;
            Delete(head,key1);

	    }
	  else if(prev2.ptr != NULL)// if statement gaurds against empty list failure
	    {
	    key1 =(P(prev2.ptr))->key;
            Delete(head,key1);
	      //cout <<"deletes: "<< this->deletes++;
	    }

	}
       if (Find(head,key))
    {
      //      this->collisions++;
      result = false;
      break;
    }
  node->nnext.ptr = P(cur.ptr);
  first.ptr = P(cur.ptr);
  first.count = cur.count;
  second.ptr = node;
  second.count = first.count + 1;
  if ((*prev1).cas(second,first))
    {
      //      this->inserts++;
      result = true;
      break;
    }
    }
    //  *hp0 = NULL;
    //*hp1 = NULL;
    //*hp2 = NULL;
  return result;

    
  }

 bool  hashtable::Delete(DPointer<NodeType,8>* head,state key)
 {
   //   cout << "inside delete" << endl;
   bool result;
   while(true)
     {
       if (!Find(head,key))
	 {
	   //	   cout << "didin find" << endl;
	   result = false;
	   break;
	 }
       /*       first.ptr = P(next1.ptr);
		first.count = next1.count;*/
       first = next1;
       second.ptr = P(first.ptr) + 1;
       second.count = first.count + 1;


       if (!(P(cur.ptr))->nnext.cas(second,first))
	 continue;
       first = cur;
       first.ptr = P(cur.ptr);
       second.ptr = P(next1.ptr);
       second.count = first.count+ 1;
       if((*prev1).cas(second,first))
	 delete(P(cur.ptr));
       else 
	 Find(head,key);
       result = true;
       break;
     }
   //*hp0 = NULL;
   //*hp1 = NULL;
   //*hp2 = NULL;
   return result;
}

 bool hashtable::Search(DPointer<NodeType,8> *head, state key)
 {
   //*hp0 = NULL;
   //*hp1 = NULL;
   //*hp2 = NULL;
   return Find(head,key);
 }


unsigned int  hashtable::Function(state x )
  {


    stringstream ss;
    ss << x;
    string object = ss.str();
    //  cout << object << endl;
    /*   unsigned int p = (x.instructions[0] + x.instructions[1] + x.instructions[2] + x.instructions[3] + x.instructions[4]);
    p = (((p ^ (p << 4))| (p << 8))| (p << 16))%hsize;
    */
    unsigned int p = DJBHash(object);
    p = p & 0x1ff;
    return p;
  }




NodeType* hashtable::HashInsert( state s)
{
  NodeType* node = new NodeType;
  unsigned int index  = Function(s);
  node->key = s;
  //cout << index;
  if (Insert(&table[index], node)){
	     return node;
  }
  else{
    delete(node);
    return NULL;
}
}


bool hashtable::HashDelete( state key)
{
  unsigned int index = Function(key);
  return Delete(&table[index],key);
}

  bool hashtable::HashSearch( state key)
{
  unsigned int index = Function(key);
  return Search(&table[index],key);
}

thread_local DPointer<NodeType,8>*  hashtable::prev1;
thread_local DPointer<NodeType,8>  hashtable::prev2;
thread_local DPointer<NodeType,8>  hashtable::cur;
thread_local DPointer<NodeType,8>  hashtable::next1;
thread_local DPointer<NodeType,8>  hashtable::first;
thread_local DPointer<NodeType,8>  hashtable::second;
thread_local DPointer<NodeType,8>  MyFreeList::first;
thread_local DPointer<NodeType,8>  MyFreeList::second;
