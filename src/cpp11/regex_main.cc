/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-9
 */

#include <iostream>
#include <string>
#include <regex>

void Demo() {
  std::string fnames[] = { "foo.txt", "bar.txt", "zoidberg" };

  //std::regex txt_regex("[a-z]+\\.txt");
  std::regex txt_regex("[a-z]+");
  for (const auto &fname : fnames) {
    std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
  }
}

void Demo2() {
  try {
    std::regex re("[a-b][a");
  } catch (const std::regex_error& e) {
    std::cout << "regex_error caught: " << e.what() << '\n';
    if (e.code() == std::regex_constants::error_brack)
      std::cout << "The code was error_brack\n";
  }
}

void RegexMatchDemo() {
  std::string str = "Hello World";
  std::regex rx("ello");
  std::cout << std::regex_match(str.begin(), str.end(), rx) << std::endl;
  std::cout << std::regex_search(str.begin(), str.end(), rx) << std::endl;
}

void CheckDate() {
  using namespace std;
  std::regex r("^\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])$");
  while (true) {
    std::cout << "Enter a date (year/month/day) (q=quit): ";
    std::string str;
    if (!getline(cin, str) || str == "q")
      break;
    if (std::regex_match(str, r))
      cout << "  Valid date." << endl;
    else
      cout << "  Invalid date!" << endl;
  }
}

int main() {
  // RE: terminate called after throwing an instance of 'std::regex_error'. ???
  //Demo();
//  Demo2();
//  RegexMatchDemo();
//  CheckDate();
  return 0;
}
