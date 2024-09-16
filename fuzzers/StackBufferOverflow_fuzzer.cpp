#include "../inc/stack_buffer_overflow.h"

#include <string>
#include <stdlib.h>
#include <cstdint>
// Simple fuzz target for DoStuff().
// See http://libfuzzer.info for details.
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (size < 1){
    return 0;
  }
  int len = static_cast<int>(size);
  int res = stack_buffer_overflow(len);

  return 0;
}

