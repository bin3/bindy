/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-14
 */

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost;
using namespace std;

void Split(const std::string str, const std::string& sep) {
  std::vector<string> tokens;
  boost::split(tokens, str, boost::is_any_of(sep.c_str()), boost::algorithm::token_compress_on);
  std::cout << "str=" << str << ", sep=[" << sep << "]\n";
  std::cout << "tokens(" << tokens.size() << "): ";
  for (size_t i = 0; i < tokens.size(); ++i) {
    std::cout << "[" << tokens[i] << "]";
  }
  std::cout << endl;
}

void SplitDemo() {
  string str("Samus||samus||mario||||Link");
  typedef find_iterator<string::iterator> string_find_iterator;
  string_find_iterator pos, end;
  for (pos = make_find_iterator(str, first_finder("samus", is_iequal()));
      pos != end; ++pos) {
    cout << "[" << *pos << "]";
  }
  cout << endl;

  typedef split_iterator<string::iterator> string_split_iterator;
  string_split_iterator p, endp;
  for (p = make_split_iterator(str, first_finder("||", is_iequal())); p != endp;
      ++p) {
    cout << "[" << *p << "]";
  }
  cout << endl;

  vector<string> tokens;
  boost::split(tokens, str, boost::is_any_of("&|"));
  for (size_t i = 0; i < tokens.size(); ++i) {
    cout << "[" << tokens[i] << "]";
  }
  cout << endl;

  boost::split(tokens, str, boost::is_any_of("&|"), boost::algorithm::token_compress_on);
  for (size_t i = 0; i < tokens.size(); ++i) {
    cout << "[" << tokens[i] << "]";
  }
  cout << endl;

  Split("\t1\t2\t\t3\t\n", "\t\n");
}

void Trim(const std::string& str) {
  std::string trimed = boost::algorithm::trim_copy(str);
  std::cout << "str=" << str << ", trimed=" << trimed << ", trimed_length=" << trimed.length() << std::endl;
}

void TrimDemo() {
  Trim("\t1\t2\t\t3\n");
}

int main(int argc, char **argv) {
  SplitDemo();
  TrimDemo();
  return 0;
}
