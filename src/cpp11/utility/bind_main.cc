/*
 * Copyright (c) 2013 Binson Zhang.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2013-2-2
 */

#include <random>
#include <iostream>
#include <functional>

void f(int n1, int n2, int n3, const int& n4, int n5) {
  std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1) {
  return n1;
}

struct Foo {
  void print_sum(int n1, int n2) {
    std::cout << n1 + n2 << '\n';
  }
  int data = 10;
};

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;
  using namespace std::placeholders;

  // demonstrates argument reordering and pass-by-reference
  int n = 7;
  auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
  n = 10;
  f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused

  // nested bind subexpressions share the placeholders
  auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
  f2(10, 11, 12);

  // common use case: binding a RNG with a distribution
  std::default_random_engine e;
  std::uniform_int_distribution<> d(0, 10);
  std::function<int()> rnd = std::bind(d, e);
  for (int i = 0; i < 10; ++i)
    std::cout << rnd() << ' ';
  std::cout << '\n';

  // bind to a member function
  Foo foo;
  auto f3 = std::bind(&Foo::print_sum, foo, 95, _1);
  f3(5);

  // bind to member data
  auto f4 = std::bind(&Foo::data, _1);
  std::cout << f4(foo) << '\n';
  return 0;
}
