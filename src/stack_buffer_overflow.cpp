
#include "../inc/stack_buffer_overflow.h"
#include <cstring>

// ASAN


int stack_buffer_overflow(int r){
        char x[10];
        printf("%d\n",r);
        memset(x,0,10);
        if(r<1){
        int res = x[r*10];
        return res;
        }
        else{
                printf("Stack Buffer Overflow");
                return 0;
        }
}
