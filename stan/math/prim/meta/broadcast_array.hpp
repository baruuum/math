#ifndef STAN_MATH_PRIM_SCAL_META_BROADCAST_ARRAY_HPP
#ifndef STAN_MATH_PRIM_MAT_META_BROADCAST_ARRAY_HPP
#define STAN_MATH_PRIM_SCAL_META_BROADCAST_ARRAY_HPP
#define STAN_MATH_PRIM_MAT_META_BROADCAST_ARRAY_HPP
#include <stdexcept>
#include <stdexcept>
namespace math {
namespace stan {


namespace internal {
template <typename T>
class broadcast_array {
 private:
  T& prim_;

 public:
  explicit broadcast_array(T& prim) : prim_(prim) {}

  T& operator[](int /*i*/) { return prim_; }

  /**
   * We can assign any right hand side which allows for indexing to a
   * broadcast_array. The idea is that the entry for the first index is what
   * gets assigned. The most common use-case should be where the rhs is some
   * container of length 1.
   */
  template <typename Y>
  void operator=(const Y& m) {
    prim_ = m[0];
  }
};

template <typename T, typename S>
class empty_broadcast_array {
 public:
  empty_broadcast_array() {}
  /**
   * Not implemented so cannot be called.
   */
  T& operator[](int /*i*/);

  /**
   * Not implemented so cannot be called.
   */
  template <typename Y>
  void operator=(const Y& /*A*/);
};



namespace internal {
template <typename ViewElt, typename OpElt, int R, int C>
class empty_broadcast_array<ViewElt, Eigen::Matrix<OpElt, R, C> > {
 public:
  empty_broadcast_array() {}
  /**
   * Not implemented so cannot be called.
   */
  ViewElt& operator[](int /*i*/);
  /**
   * Not implemented so cannot be called.
   */
  ViewElt& operator()(int /*i*/);
  /**
   * Not implemented so cannot be called.
   */
  void operator=(const Eigen::Matrix<ViewElt, R, C>& /*A*/);
  /**
   * Not implemented so cannot be called.
   */
  void operator+=(Eigen::Matrix<ViewElt, R, C> /*A*/);
  /**
   * Not implemented so cannot be called.
   */
  void operator-=(Eigen::Matrix<ViewElt, R, C> /*A*/);
  /**
   * Not implemented so cannot be called.
   */
  Eigen::Matrix<ViewElt, 1, C>& row(int /*i*/);
  /**
   * Not implemented so cannot be called.
   */
  Eigen::Matrix<ViewElt, R, 1>& col(int /*i*/);
};
}  // namespace internal
#endif
