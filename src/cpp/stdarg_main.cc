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
 * @date		2013-1-22
 */

#include <cstdarg>
#include <iostream>

int Sum(int argc, ...) {
  int sum = 0;
  va_list p;
  va_start(p, argc);
  for (int i = 0; i < argc; ++i) {
    int x = va_arg(p, int);
    sum += x;
  }
  va_end(p);
  return sum;
}

int Printf(const char* fmt, ...) {
  printf("Printf\n");
  return 0;
}

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
	std::cout << Sum(4, 1, 2, 3, 4) << std::endl;

	printf("%s, bin%d\n", "hello", 3);
	Printf("%s, bin%d\n", "hello", 3);

//	printf("%d\n", 124, 456);

  return 0;
}
