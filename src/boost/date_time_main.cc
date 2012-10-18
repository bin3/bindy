/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-18
 */

#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

void burn_time() {
  for (long i = 0; i < 1000000; ++i)
    std::sqrt(123.456L); // burn some time
}

void wait_input() {
  std::cout << "input something:";
  std::string input;
  std::cin >> input;
}

void posix_time_demo() {
  boost::posix_time::ptime start =
      boost::posix_time::microsec_clock::local_time();
  burn_time();
  boost::posix_time::ptime end =
      boost::posix_time::microsec_clock::local_time();
  boost::posix_time::time_duration elapsed = end - start;
  std::cout << "elapsed=" << elapsed << std::endl;
}

void posix_time_demo2() {
  boost::posix_time::ptime start =
      boost::posix_time::microsec_clock::local_time();
  wait_input();
  boost::posix_time::ptime end =
      boost::posix_time::microsec_clock::local_time();
  boost::posix_time::time_duration elapsed = end - start;
  std::cout << "elapsed=" << elapsed << std::endl;
  std::cout << "elapsed=" << elapsed.total_milliseconds() << "ms" << std::endl;
}

int main(int argc, char **argv) {
  using namespace boost::posix_time;
  using namespace boost::gregorian;

  //get the current time from the clock -- one second resolution
  ptime now = second_clock::local_time();
  //Get the date part out of the time
  date today = now.date();
  date tommorrow = today + days(1);
  ptime tommorrow_start(tommorrow); //midnight

  //iterator adds by one hour
  time_iterator titr(now, hours(1));
  for (; titr < tommorrow_start; ++titr) {
    std::cout << to_simple_string(*titr) << std::endl;
  }

  time_duration remaining = tommorrow_start - now;
  std::cout << "Time left till midnight: " << to_simple_string(remaining)
      << std::endl;

  posix_time_demo();
  posix_time_demo2();

  return 0;
}
