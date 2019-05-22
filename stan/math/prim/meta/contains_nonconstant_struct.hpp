#ifndef STAN_MATH_PRIM_META_CONTAINS_NONCONSTANT_STRUCT_HPP
#define STAN_MATH_PRIM_META_CONTAINS_NONCONSTANT_STRUCT_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>

namespace stan {

/**
 * Extends std::true_type when instantiated with at least 1
 * template parameter that is a nonconstant struct.
 * Extends std::false_type otherwise.
 * @tparam T Types to test
 */
template <typename... T>
using contains_nonconstant_struct
    = math::disjunction<is_nonconstant_struct<T>...>;

}  // namespace stan
#endif
