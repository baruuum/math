#ifndef STAN_MATH_PRIM_SCAL_META_GET_HPP
#define STAN_MATH_PRIM_SCAL_META_GET_HPP
#include <cmath>
#include <cstddef>
#include <stan/math/prim/fun/Eigen.hpp>
namespace stan {



template <typename T>
inline T get(const T& x, size_t n) {
  return x;
}




template <typename T, int R, int C>
inline T get(const Eigen::Matrix<T, R, C>& m, size_t n) {
  return m(static_cast<int>(n));
}

template <typename T, int R, int C>
inline T get(const Eigen::Array<T, R, C>& m, size_t n) {
  return m(static_cast<int>(n));
}

#endif
