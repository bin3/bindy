/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-25
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <unistd.h>
#include <stddef.h>
#include <memory>

#include <stl/allocator.h>

namespace bindy {
namespace stl {

/**
 * @brief 
 */
//template<typename T, typename Alloc = Allocator>
// dev
//typedef Allocator Alloc;
template<typename T>
class Vector {
public:
  typedef std::allocator<T> Alloc; // dev

  typedef T value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type* iterator;
  typedef const value_type* const_iterator;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  Vector() : begin_(NULL), end_(NULL), end_of_storage_(NULL) {}

  iterator begin() {
    return begin_;
  }
  const_iterator begin() const {
    return begin_;
  }
  iterator end() {
    return end_;
  }
  const_iterator end() const {
    return end_;
  }
  size_type size() {
    return size_type(end_ - begin_);
  }
  size_type capacity() {
    return size_type(end_of_storage_ - begin_);
  }
  size_type max_size() {
    // TODO
    static const size_type kMaxSize = size_type(-1) / sizeof(T);
    return kMaxSize;
  }
  bool empty() {
    return size() == 0;
  }

  void push_back(const T& x) {
    if (end_ != end_of_storage_) {
      *end_ = x;
      ++end_;
    } else {
      size_type old_sz = size();
      size_type new_sz = old_sz > 0 ? old_sz * 2 : 1;
      if (new_sz > max_size()) {
        new_sz = max_size();
      }

      pointer new_begin = alloc_.allocate(new_sz, pointer(0));
      pointer new_end(new_begin);
      new_end = construct(begin_, end_, new_end);
      *new_end = x;
      ++new_end;
      destroy(begin_, end_);
      alloc_.deallocate(begin_, capacity());

      begin_ = new_begin;
      end_ = new_end;
      end_of_storage_ = new_begin + new_sz;
    }
  }
  void pop_back() {
    --end_;
    alloc_.destroy(end_);
  }
  void insert(iterator p, const value_type& x) {
    if (end_ != end_of_storage_) {

    }
  }
  void clear() {
    destroy(begin_, end_);
    end_ = begin_;
  }
private:
  pointer begin_;
  pointer end_;
  pointer end_of_storage_;
  Alloc alloc_;

  pointer construct(pointer first, pointer last, pointer result) {
    for (pointer p = first; p != last; ++p, ++result) {
      alloc_.construct(result, *p);
    }
    return result;
  }
  void destroy(pointer first, pointer last) {
    for (pointer p = first; p != last; ++p) {
      alloc_.destroy(p);
    }
  }
};

} /* namespace stl */
} /* namespace bindy */
#endif /* VECTOR_H_ */
