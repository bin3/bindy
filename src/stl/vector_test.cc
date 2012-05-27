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

TEST(VectorTest, size) {
  Vector<int> vi;
  EXPECT_EQ(0, vi.size());
}

} /* namespace stl */
} /* namespace bindy */
