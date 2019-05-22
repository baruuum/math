#ifndef STAN_MATH_PRIM_META_LIKELY_HPP
#define STAN_MATH_PRIM_META_LIKELY_HPP
#include <stan/math/prim.hpp>
#include <stan/math/prim/meta.hpp>

#ifdef __GNUC__
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

#endif
