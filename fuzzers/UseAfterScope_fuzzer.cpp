#include "../inc/use_after_scope.h"

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
  use_after_scope(len);

  return 0;
}

