/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-10-14
 */

#include <iostream>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

int main(int argc, char **argv) {
  using namespace boost::numeric::ublas;
  mapped_matrix<double> m (3, 3, 3 * 3);
  for (unsigned i = 0; i < m.size1 (); ++ i)
      for (unsigned j = 0; j < m.size2 (); ++ j)
          m (i, j) = 3 * i + j;
  std::cout << m << std::endl;
  return 0;
}
