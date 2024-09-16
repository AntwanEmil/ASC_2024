#include "../inc/undefined_behavior.h"

#include <string>
#include <stdlib.h>
#include <cstdint>
// Simple fuzz target for DoStuff().
// See http://libfuzzer.info for details.
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (size < 1){
    return 0;
  }
  undefined_behavior(size);

  return 0;
}

