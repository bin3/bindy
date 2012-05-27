/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-27
 */

#include <iostream>
#include <utility>

#define EVAL(x) #x"=" << (x)

void TestPair() {
  std::pair<int, double> p0(1, 3.4);
  std::pair<int, double> p1(3, 1.4);
  std::cout << EVAL(p0 < p1) << std::endl;
  std::cout << EVAL(p0 > p1) << std::endl;
}

int main(int argc, char **argv) {
  TestPair();
  return 0;
}
