/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-9
 */

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
  // construction uses aggregate initialization
  std::array<int, 3> a1{ {1,2,3} };    // double-braces required
  //std::array<int, 3> a2 = {1, 2, 3}; // except after =
  std::array<int, 3> a2 = { {1, 2, 3} };
  std::array<std::string, 2> a3 = { {std::string("a"), "b"} };

  // container operations are supported
  std::sort(a1.begin(), a1.end());
  std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));

  // ranged for loop is supported
  for(auto& s: a3)
    std::cout << s << ' ';
  std::cout << std::endl;
}
