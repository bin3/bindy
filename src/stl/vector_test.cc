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
  EXPECT_EQ(0u, v.size());
}

TEST(VectorTest, push_back) {
  Vector<int> v;
  EXPECT_EQ(0u, v.size());
  EXPECT_EQ(0u, v.capacity());

  PushBack(v, 1, 1);
  EXPECT_EQ(1u, v.size());
  EXPECT_EQ(1u, v.capacity());

  PushBack(v, 2, 2);
  EXPECT_EQ(3u, v.size());
  EXPECT_EQ(4u, v.capacity());

  PushBack(v, 3, 5);
  EXPECT_EQ(8u, v.size());
  EXPECT_EQ(8u, v.capacity());

  PushBack(v, 4, 1);
  EXPECT_EQ(9u, v.size());
  EXPECT_EQ(16u, v.capacity());
}

} /* namespace stl */
} /* namespace bindy */
