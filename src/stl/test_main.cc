/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-26
 */

#include <stdio.h>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  printf("Running main() from test_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


