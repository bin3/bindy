/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-4
 */

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <stx/btree_map>

#include <util/util.h>

void BtreeMapDemo() {
  stx::btree_map<int, std::string> id2name;

  const int kNum = 5;
  for (int i = 0; i < kNum; ++i) {
    std::string name = "name" + boost::lexical_cast<std::string>(i);
    id2name[i] = name;
  }
  for (int i = 0; i < kNum; ++i) {
    std::cout << NVC_(i) << NV_(id2name[i]) << std::endl;
  }
}

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
	BtreeMapDemo();

  return 0;
}
