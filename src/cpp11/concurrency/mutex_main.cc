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
  std::vector<int> vi;
  vi.push_back(9);
  Counter cnt;
  cnt.Increment();
  std::cout << "cnt.value()=" << cnt.value() << std::endl;
  return 0;
}
