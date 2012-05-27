/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-25
 */

#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <stdlib.h>

namespace bindy {
namespace stl {

/**
 * @brief 
 */
class Allocator {
public:
  virtual ~Allocator() {}

  static void* allocate(size_t sz) {
    void* result = malloc(sz);
    // TODO
    if (result == NULL) {}
    return result;
  }
  static void deallocate(void* p, size_t sz) {
    free(p);
  }
  static void* reallocate(void* p, size_t old_sz, size_t new_sz) {
    void* result = realloc(p, new_sz);
    // TODO
    if (result == NULL) {}
    return result;
  }
};

} /* namespace stl */
} /* namespace bindy */
#endif /* ALLOCATOR_H_ */
