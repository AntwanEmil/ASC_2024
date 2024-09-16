// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// A library that does ... stuff.
// Serves as an example of good fuzz testing and OSS-Fuzz integration.
#include <string>

size_t DoStuff(const std::string &str);

void global_buffer_overflow(int len);

void stack_buffer_overflow(int r);

void undefined_behavior(size_t len);