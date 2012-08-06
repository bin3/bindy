/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-3
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Counter {
 public:
  Counter(): value_(0) {}
  uint32_t value() const { return value_; }
  void Increment() {
    mut_.lock();
    ++value_;
    mut_.unlock();
  }
  void Decrement() {
    mut_.lock();
    --value_;
    mut_.unlock();
  }
 private:
  uint32_t value_;
  std::mutex mut_;
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

//  for (int i = 0; i < kThreads; ++i) {
//    threads[i].join();
//  }
  for (auto& thread: threads) {
    thread.join();
  }

  std::cout << "cnt.value()=" << cnt.value() << std::endl;
  return 0;
}
