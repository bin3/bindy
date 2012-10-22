/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-22
 */

#include <iostream>
#include <omp.h>

void Sum() {
  int sum = 0;
  std::cout << "[begin] sum=" << sum << std::endl;
#pragma omp parallel for
  for (int i = 0; i < 100; ++i) {
    sum += i;
    std::cout << "sum=" << sum << std::endl;
  }
  std::cout << "[end] sum=" << sum << std::endl;
}

int main(int argc, char **argv) {
  Sum();
  return 0;
}
