/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-18
 */

#include <cmath>
#include <iostream>
#include <boost/timer/timer.hpp>

using boost::timer::cpu_timer;
using boost::timer::cpu_times;
using boost::timer::nanosecond_type;

void auto_cpu_timer_demo() {
  boost::timer::auto_cpu_timer t;
  for (long i = 0; i < 1000000; ++i)
    std::sqrt(123.456L); // burn some time
}

void cpu_timer_demo() {

  std::cout << "input something:" << std::endl;
  cpu_timer timer;
  std::cin.get();
  cpu_times const elapsed_times(timer.elapsed());
  nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);
  std::cout << "elapsed=" << elapsed << std::endl;
}

int main(int argc, char **argv) {
  auto_cpu_timer_demo();
  cpu_timer_demo();

  return 0;
}
