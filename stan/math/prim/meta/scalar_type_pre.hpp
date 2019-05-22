#ifndef STAN_MATH_PRIM_META_SCALAR_TYPE_PRE_HPP
#define STAN_MATH_PRIM_META_SCALAR_TYPE_PRE_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>


namespace stan {
namespace internal {
template <bool is_vec, typename T, typename T_container>
struct scalar_type_helper_pre {
  typedef T_container type;
};

template <typename T, typename T_container>
struct scalar_type_helper_pre<true, T, T_container> {
  typedef typename scalar_type_helper_pre<
      is_vector<typename stan::math::value_type<T>::type>::value,
      typename stan::math::value_type<T>::type,
      typename stan::math::value_type<T_container>::type>::type type;
};
}  // namespace internal

/**
 * Metaprogram structure to determine the type of first container of
 * the base scalar type of a template argument.
 *
 * @tparam T Type of object.
 */
template <typename T>
struct scalar_type_pre {
  typedef typename internal::scalar_type_helper_pre<
      is_vector<typename stan::math::value_type<T>::type>::value,
      typename stan::math::value_type<T>::type, T>::type type;
};

}  // namespace stan
#endif
