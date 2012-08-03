/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-26
 */

#include <ext/type_traits.h>

struct A {
  int a;
};

int main(int argc, char **argv) {
  __gnu_cxx::__add_unsigned<int>::__type ui = 1;
  ++ui;
  //__gnu_cxx::__add_unsigned<void>::__type uv; // CE
  //__gnu_cxx::__add_unsigned<A>::__type ua;    // CE
  return 0;
}

