/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-7-21
 */

#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

void lexical_cast_demo(char** argv) {
  using boost::lexical_cast;
  using boost::bad_lexical_cast;

  std::vector<short> args;

  while (*++argv) {
    try {
      args.push_back(lexical_cast<short>(*argv));
    } catch (bad_lexical_cast &) {
      args.push_back(0);
    }
  }
  std::cout << "args(" << args.size() << "):" << std::endl;
  for (std::size_t i = 0; i < args.size(); ++i) {
    std::cout << args[i] << std::endl;
  }
}

void numeric_cast_demo() {
  using boost::numeric_cast;
  using boost::numeric::bad_numeric_cast;
  using boost::numeric::positive_overflow;
  using boost::numeric::negative_overflow;
  try {
    int i = 42;
    numeric_cast<short>(i); // This conversion succeeds (is in range) 转换成功(在范围内)
  } catch (negative_overflow& e) {
    std::cout << e.what();
  } catch (positive_overflow& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    float f = -42.1234;
    // This will cause a boost::numeric::negative_overflow exception to be thrown
    // 这将引发一个 boost::numeric::negative_overflow 异常被抛出
    numeric_cast<unsigned int>(f);
  } catch (bad_numeric_cast& e) {
    std::cout << e.what() << std::endl;
  }
  numeric_cast<double>(123); // int -> double

  unsigned long l = std::numeric_limits<unsigned long>::max();
  try {
    // This will cause a boost::numeric::positive_overflow exception to be thrown
    // NOTE: *operations* on unsigned integral types cannot cause overflow
    // but *conversions* to a signed type ARE range checked by numeric_cast.
    // 这将引发一个 boost::numeric::positive_overflow 异常被抛出
    // 注：在无符号整数类型上的*operations*不会引起溢出，
    // 但是在有符号类型上的*operations*则要由 numeric_cast 进行范围检查

    numeric_cast<unsigned char>(l);
  } catch (positive_overflow& e) {
    std::cout << e.what() << std::endl;
  }
}

int main(int argc, char **argv) {
  lexical_cast_demo(argv);
  numeric_cast_demo();

  return 0;
}
