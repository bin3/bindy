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

#include <functional>
#include <iostream>

struct Foo {
  void display_greeting() {
    std::cout << "Hello, world.\n";
  }
  void display_number(int i) {
    std::cout << "number: " << i << '\n';
  }
  int data = 7;
};

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
  Foo f;

  auto greet = std::mem_fn(&Foo::display_greeting);
  greet(f);

  auto print_num = std::mem_fn(&Foo::display_number);
  print_num(f, 42);

  auto access_data = std::mem_fn(&Foo::data);
  std::cout << "data: " << access_data(f) << '\n';
  return 0;
}
