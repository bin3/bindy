/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-17
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main(int argc, char **argv) {
  const long double pi = std::acos(-1.L);
  std::cout << "default precision (6): " << pi << '\n'
            << "std::precision(10):    " << std::setprecision(10) << pi << '\n'
            << "max precision:         "
            << std::setprecision(std::numeric_limits<long double>::digits10)
            << pi << '\n';

  return 0;
}
