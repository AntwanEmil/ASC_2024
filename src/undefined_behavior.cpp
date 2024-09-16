#include "../inc/undefined_behavior.h"
#include <cstring>

// UBSAN
void undefined_behavior(size_t len){
  int k = 0x7fffffff;
  k += len;
}

