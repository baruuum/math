#ifndef STAN_MATH_PRIM_META_PARTIALS_TYPE_HPP
#define STAN_MATH_PRIM_META_PARTIALS_TYPE_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>

namespace stan {

template <typename T>
struct partials_type {
  typedef T type;
};

}  // namespace stan
#endif
