#include "../inc/global_buffer_overflow.h"
#include <cstring>

int arr[10];
void global_buffer_overflow(int len){
  int somevar = (int) arr[len];
}
