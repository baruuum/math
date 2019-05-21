#ifndef STAN_MATH_PRIM_SCAL_META_INDEX_TYPE_HPP
#define STAN_MATH_PRIM_SCAL_META_INDEX_TYPE_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>
namespace math {
namespace stan {


/**
 * Primary template class for the metaprogram to compute the index
 * type of a container.
 *
 * Only the specializations have behavior that can be used, and
 * all implement a typedef <code>type</code> for the type of the
 * index given container <code>T</code>.
 *
 * tparam T type of container.
 */
template <typename T>
struct index_type {};

/**
 * Template class for metaprogram to compute the type of indexes
 * used in a constant container type.
 *
 * @tparam T type of container without const modifier.
 */
template <typename T>
struct index_type<const T> {
  typedef typename index_type<T>::type type;
};





/**
 * Template metaprogram defining typedef for the type of index for
 * an Eigen matrix, vector, or row vector.
 *
 * @tparam T type of matrix.
 * @tparam R number of rows for matrix.
 * @tparam C number of columns for matrix.
 */
template <typename T, int R, int C>
struct index_type<Eigen::Matrix<T, R, C> > {
  typedef typename Eigen::Matrix<T, R, C>::Index type;
};

};
};

#endif
