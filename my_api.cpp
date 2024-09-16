// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// Implementation of "my_api".
#include "my_api.h"
#include <cstring>
#include <vector>
// Do some computations with 'str', return the result.
// This function contains a bug. Can you spot it?
size_t DoStuff(const std::string &str) {
  std::vector<int> Vec({0, 1, 2, 3, 4});
  size_t Idx = 0;
  if (str.size() > 5)
    Idx++;
  if (str.find("foo") != std::string::npos)
    Idx++;
  if (str.find("bar") != std::string::npos)
    Idx++;
  if (str.find("ouch") != std::string::npos)
    Idx++;
  if (str.find("omg") != std::string::npos)
    Idx++;
  if (str.find("on") != std::string::npos)
    Idx++;
  // This is the bug fix [Heap buffer overflow / addres out of bounds]
  if (Idx >= 5)
    {
      printf("Idx too large\n");
      return 0;
    }
  return Vec[Idx];
}

int arr[10];
void global_buffer_overflow(int len){
  int somevar = (int) arr[len];
}

// ASAN
void stack_buffer_overflow(int r){
        char x[10];
        memset(x,0,10);
        int res = x[r];
}


// UBSAN
void undefined_behavior(size_t len){
  int k = 0x7fffffff;
  k += len;
}


