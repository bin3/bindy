/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-5-27
 */

#ifndef PAIR_H_
#define PAIR_H_

namespace bindy {
namespace stl {

/**
 * @brief 
 */
template<typename T1, typename T2>
struct Pair {
public:
  typedef T1 first_type;
  typedef T2 second_type;

  Pair() {}
  Pair(const T1& fst, const T2& snd)
  : first(fst), second(snd) {}
  template<typename U1, typename U2>
  Pair(const Pair<U1, U2>& p)
  : first(p.first), second(p.second) {}

  T1 first;
  T2 second;
};

template<typename T1, typename T2>
inline bool operator==(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
  return x.first == y.first && x.second == y.second;
}

template<typename T1, typename T2>
inline bool operator!=(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
  return !(x == y);
}

template<typename T1, typename T2>
inline bool operator<(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
  return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template<typename T1, typename T2>
inline bool operator>(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
  return y < x;
}

template<typename T1, typename T2>
inline bool operator<=(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
  return !(x > y);
}

template<typename T1, typename T2>
inline bool operator>=(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
  return !(x < y);
}

template<typename T1, typename T2>
Pair<T1, T2> make_pair(const T1& fst, const T2& snd) {
  return Pair<T1, T2>(fst, snd);
}

} /* namespace stl */
} /* namespace bindy */
#endif /* PAIR_H_ */
