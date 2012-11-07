/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-11-8
 */

#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/tss.hpp>

boost::thread_specific_ptr<int> g_value;
boost::mutex g_cout_mut;

void ThreadProc() {
  g_value.reset(new int(0));
  for (int i = 0; i < 100; ++i) {
    ++(*g_value);
  }
  {
    boost::lock_guard<boost::mutex> lock(g_cout_mut);
    std::cout << "Thread#" << boost::this_thread::get_id() << " g_value="
        << *g_value << std::endl;
  }
}

int main(int argc, char **argv) {
  boost::thread_group threads;
  for (int i = 0; i < 8; ++i) {
    threads.create_thread(&ThreadProc);
  }
  threads.join_all();
  return 0;
}
