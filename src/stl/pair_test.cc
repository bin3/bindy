/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-27
 */

#include "pair.h"
#include <gtest/gtest.h>

namespace bindy {
namespace stl {

TEST(PairTest, Pair) {
  Pair<int, double> pid(1, 3.4);
  Pair<double, int> pdi(pid);
  EXPECT_EQ(1, pdi.first);
  EXPECT_EQ(3, pdi.second);
}

TEST(PairTest, operators) {
  Pair<int, double> p0(1, 3.4);
  Pair<int, double> p1(p0);
  EXPECT_TRUE(p0 == p1);
  EXPECT_TRUE(p0 <= p1);
  EXPECT_TRUE(p0 >= p1);
  EXPECT_FALSE(p0 < p1);
  EXPECT_FALSE(p0 < p1);

  Pair<int, double> p2(4, 0.9);
  EXPECT_TRUE(p0 < p2);
  EXPECT_TRUE(p2 > p0);

  p2 = Pair<int, double>(1, 9.9);
  EXPECT_TRUE(p0 < p2);
  EXPECT_TRUE(p2 > p0);

  p2 = Pair<int, double>(4, 9.9);
  EXPECT_TRUE(p0 < p2);
  EXPECT_TRUE(p2 > p0);
}

} /* namespace stl */
} /* namespace bindy */
