#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>

template<typename T,unsigned N=sizeof (uint32_t)>
struct DPointer {
public:
  union {
    uint64_t ui;
    struct {
      T* ptr;
      size_t count;
    };
  };

  DPointer() : ptr(NULL), count(0) {}
  DPointer(T* p) : ptr(p), count(0) {}
  DPointer(T* p, size_t c) : ptr(p), count(c) {}

  bool cas(DPointer<T,N> const& nval, DPointer<T,N> const & cmp)
  {
    bool result;
    __asm__ __volatile__(
        "lock cmpxchg8b %1\n\t"
        "setz %0\n"
        : "=q" (result)
         ,"+m" (ui)
        : "a" (cmp.ptr), "d" (cmp.count)
         ,"b" (nval.ptr), "c" (nval.count)
        : "cc"
    );
    return result;
  }

  // We need == to work properly
  bool operator==(DPointer<T,N> const&x) { return x.ui == ui; }

};



template<typename T>
struct DPointer <T,sizeof (uint64_t)> {
public:
  union {
    uint64_t   ui[2];
    struct {
      T* ptr;
      size_t count;
   } __attribute__ (( __aligned__( 16 ) ));
  };

  DPointer() : ptr(NULL), count(0) {}
  DPointer(T* p) : ptr(p), count(0) {}
  DPointer(T* p, size_t c) : ptr(p), count(c) {}


  bool cas(DPointer<T,8> const& nval, DPointer<T,8> const& cmp)
  {
    bool result;
    __asm__ __volatile__ (
        "lock cmpxchg16b %1\n\t"
        "setz %0\n"
        : "=q" ( result )
         ,"+m" ( ui )
        : "a" ( cmp.ptr ), "d" ( cmp.count )
         ,"b" ( nval.ptr ), "c" ( nval.count )
        : "cc"
    );
    return result;
  }

  // We need == to work properly

  bool operator==(DPointer<T,8> const&x)
  {
    return x.ptr == ptr && x.count == count;
  }

  bool operator=(DPointer<T,8> const&x)
  {
    ptr = x.ptr;
    count = x.count;
    return true;
  }
};

