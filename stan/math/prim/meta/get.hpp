#ifndef STAN_MATH_PRIM_META_GET_HPP
#define STAN_MATH_PRIM_META_GET_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>
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

}


/**
 * Returns the n-th element of the provided std::vector.
 *
 * @param x input vector
 * @param n index of the element to return
 * @return n-th element of the input vector
 */
template <typename T>
inline T get(const std::vector<T>& x, size_t n) {
  return x[n];
}

}
#endif
