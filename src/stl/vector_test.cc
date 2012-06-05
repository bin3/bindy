/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-25
 */

#include "vector.h"
#include <gtest/gtest.h>

namespace bindy {
namespace stl {

template<typename T>
void PushBack(Vector<T>& v, const T& x, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    v.push_back(x);
  }
}

TEST(VectorTest, size) {
  Vector<int> v;
  EXPECT_EQ(0, v.size());
}

TEST(VectorTest, push_back) {
  Vector<int> v;
  EXPECT_EQ(0, v.size());
  EXPECT_EQ(0, v.capacity());

  PushBack(v, 1, 1);
  EXPECT_EQ(1, v.size());
  EXPECT_EQ(1, v.capacity());

  PushBack(v, 2, 2);
  EXPECT_EQ(3, v.size());
  EXPECT_EQ(4, v.capacity());

  PushBack(v, 3, 5);
  EXPECT_EQ(8, v.size());
  EXPECT_EQ(8, v.capacity());

  PushBack(v, 4, 1);
  EXPECT_EQ(9, v.size());
  EXPECT_EQ(16, v.capacity());
}

} /* namespace stl */
} /* namespace bindy */
