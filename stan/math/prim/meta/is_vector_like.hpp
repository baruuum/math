#ifndef STAN_MATH_PRIM_META_IS_VECTOR_LIKE_HPP
#define STAN_MATH_PRIM_META_IS_VECTOR_LIKE_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>


namespace stan {



/**
 * Template metaprogram indicates whether a type is vector_like.
 *
 * A type is vector_like if an instance can be accessed like a
 * vector, i.e. square brackets.
 *
 * Access is_vector_like::value for the result.
 *
 * Default behavior is to use the is_vector template metaprogram.
 *
 * @tparam T Type to test
 */
template <typename T>
struct is_vector_like {
  enum { value = is_vector<T>::value };
};

/**
 * Template metaprogram indicates whether a type is vector_like.
 *
 * A type is vector_like if an instance can be accessed like a
 * vector, i.e. square brackets.
 *
 * A C++ array of T is vector_like.
 *
 * @tparam T Type to test
 */
template <typename T>
struct is_vector_like<T*> {
  enum { value = true };
};

/**
 * Template metaprogram indicates whether a type is vector_like.
 *
 * A type is vector_like if an instance can be accessed like a
 * vector, i.e. square brackets.
 *
 * Access is_vector_like::value for the result.
 *
 * This metaprogram removes the const qualifier.
 *
 * @tparam T Type to test
 */
template <typename T>
struct is_vector_like<const T> {
  enum { value = is_vector_like<T>::value };
};



/**
 * Template metaprogram indicates whether a type is vector_like.
 *
 * A type is vector_like if an instance can be accessed like a
 * vector, i.e. square brackets.
 *
 * Access is_vector_like::value for the result.
 *
 * This metaprogram removes the const qualifier.
 *
 * @tparam T Type to test
 */
template <typename T, int R, int C>
struct is_vector_like<Eigen::Matrix<T, R, C> > {
  enum { value = true };
};

/**
 * Template metaprogram indicates whether a type is vector_like.
 *
 * A type is vector_like if an instance can be accessed like a
 * vector, i.e. square brackets.
 *
 * Access is_vector_like::value for the result.
 *
 * This metaprogram removes the const qualifier.
 *
 * @tparam T Type to test
 */
template <typename T, int R, int C>
struct is_vector_like<Eigen::Array<T, R, C> > {
  enum { value = true };
};
};
#endif
