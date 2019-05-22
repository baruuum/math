#ifndef STAN_MATH_PRIM_META_ERROR_INDEX_HPP
#define STAN_MATH_PRIM_META_ERROR_INDEX_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>

namespace stan {

struct error_index {
  enum {
    value =
#ifdef ERROR_INDEX
        ERROR_INDEX
#else
        1
#endif
  };
};

}  // namespace stan
#endif
