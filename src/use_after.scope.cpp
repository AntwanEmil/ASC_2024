#include "../inc/use_after_scope.h"
#include <cstring>

void use_after_scope(int len) {
  int *p;
  if (len > 10) {
    int x[10];
    p = x;
  }
  *p = 1;
}
