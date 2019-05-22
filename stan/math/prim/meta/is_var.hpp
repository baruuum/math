#ifndef STAN_MATH_PRIM_META_IS_VAR_HPP
#define STAN_MATH_PRIM_META_IS_VAR_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>

namespace stan {
/**
 * Defines a public enum named value which is defined to be false
 * as the primitive scalar types cannot be a stan::math::var type.
 */
template <typename T>
struct is_var {
  enum { value = false };
};

}  // namespace stan
#endif
