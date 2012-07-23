/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-7-21
 */

#include <iostream>
#include <limits>
using namespace std;

int main () {
  cout << boolalpha;
  cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
  cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
  cout << "int is signed: " << numeric_limits<int>::is_signed << endl;
  cout << "Non-sign bits in int: " << numeric_limits<int>::digits << endl;
  cout << "digits10 in int: " << numeric_limits<int>::digits10 << endl;
  cout << "int has infinity: " << numeric_limits<int>::has_infinity << endl;

  cout << "Maximum value for size_t: " << numeric_limits<size_t>::max() << endl;
  cout << "Non-sign bits in size_t: " << numeric_limits<size_t>::digits << endl;

  cout << "epsilon for float: " << numeric_limits<float>::epsilon() << endl;
  cout << "Maximum value for float: " << numeric_limits<float>::max() << endl;
  cout << "Non-sign bits in float: " << numeric_limits<float>::digits << endl;
  cout << "epsilon for double: " << numeric_limits<double>::epsilon() << endl;
  cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;
  cout << "Non-sign bits in double: " << numeric_limits<double>::digits << endl;

  return 0;
}
