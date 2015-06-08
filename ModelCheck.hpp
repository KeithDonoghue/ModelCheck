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


class hashtable;

class ModelCheck{
private:
  hashtable t;
public:
  ModelCheck();
  ModelCheck(int x);
  ~ModelCheck();
  void run(int numcores, int processes);
};
