#ifndef STAN_MATH_PRIM_META_CONTAINS_VECTOR_HPP
#define STAN_MATH_PRIM_META_CONTAINS_VECTOR_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>


namespace stan {
/**
 * Metaprogram to determine if any of the
 * provided types is a std::vector.
 * @tparam T Types to test
 */
template <typename... T>
using contains_vector = math::disjunction<is_vector<T>...>;

}  // namespace stan
#endif
