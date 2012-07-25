/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-7-21
 */

#include <iostream>
#include <string>
#include <boost/regex.hpp>
//#include <boost/regex/icu.hpp>

using namespace std;
using namespace boost;

void Demo() {
  if (regex_match("subject", regex("(sub)(.*)")))
      cout << "string literal matched\n";

    string s("subject");
    regex e("(sub)(.*)");
    if (regex_match(s, e))
      cout << "string object matched\n";

    if (regex_match(s.begin(), s.end(), e))
      cout << "range matched\n";

    cmatch cm; // same as match_results<const char*> cm;
    regex_match("subject", cm, e);
    cout << "string literal with " << cm.size() << " matches\n";

    smatch sm; // same as match_results<string::const_iterator> sm;
    regex_match(s, sm, e);
    cout << "string object with " << sm.size() << " matches\n";

  //  regex_match(s.cbegin(), s.cend(), sm, e);
  //  cout << "range with " << cm.size() << " matches\n";

    // using explicit flags:
    regex_match("subject", cm, e, regex_constants::match_default);

    cout << "the matches were: ";
    for (unsigned i = 0; i < sm.size(); ++i) {
      cout << "[" << sm[i] << "] ";
    }

    cout << endl;
}

int main() {
  Demo();

  //u32regex u32reg; // Have to install ICU

  return 0;
}
