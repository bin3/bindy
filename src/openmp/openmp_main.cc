/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-22
 */

#include <iostream>

int main(int argc, char **argv) {
#pragma omp parallel
  {
    std::cout << "Hello OpenMP" << std::endl;
  }
#pragma omp parallel for
  for (int i = 0; i < 10; i++) {
    printf("i = %d\n", i);
  }
  return 0;
}
