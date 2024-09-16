
#include "../inc/stack_buffer_overflow.h"
#include <cstring>

// ASAN
void stack_buffer_overflow(int r){
        char x[10];
        memset(x,0,10);
        int res = x[r];
}
