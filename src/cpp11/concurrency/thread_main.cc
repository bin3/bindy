/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-3
 */

#include <thread>
#include <iostream>
#include <vector>

void hello() {
  std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  for (int i = 0; i < 5; ++i) {
    threads.push_back(std::thread(hello));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  return 0;
}
