/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-9
 */

#include <iostream>
#include <string>
#include <regex>

int main() {
  std::string fnames[] = { "foo.txt", "bar.txt", "zoidberg" };

  std::regex txt_regex("[a-z]+\\.txt");
  for (const auto &fname : fnames) {
    std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
  }
}
