#include "../inc/global_buffer_overflow.h"
#include <cstring>

int arr[10];
void global_buffer_overflow(int len){
  if (len<1){
  int somevar = (int) arr[len*10];
  }
  else{
    printf("global buffer overflow");
  }
}
