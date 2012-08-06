/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-3
 */

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

class Counter {
 public:
  Counter(): value_(0) {}
  int value() const {
    return value_.load(); 
  }
  void Increment() {
    ++value_;
  }
  void Decrement() {
    --value_;
  }
 private:
  std::atomic<int> value_;
};

int main(int argc, char **argv) {
  int kThreads = 5;
  Counter cnt;
  std::vector<std::thread> threads;
  for (int i = 0; i < kThreads; ++i) {
    threads.push_back(std::thread([&](){
      for (int j = 0; j < 100; ++j) {
        cnt.Increment();
      }
    }));
  }

  for (auto& thread: threads) {
    thread.join();
  }

  std::cout << "cnt.value()=" << cnt.value() << std::endl;
  return 0;
}
