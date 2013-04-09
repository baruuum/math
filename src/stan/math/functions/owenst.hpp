#ifndef __STAN__MATH__FUNCTIONS__OWENST_HPP__
#define __STAN__MATH__FUNCTIONS__OWENST_HPP__

#include <boost/math/tools/promotion.hpp>
#include <boost/math/special_functions/owens_t.hpp>

namespace stan {
  namespace math {

 
    /** 
     * The Owen's T function of h and a.
     *
     * Used to compute the cumulative density function for the skew normal
     * distribution.
     * 
     * @tparam T1 Type of first argument.
     * @tparam T2 Type of second argument.
     * @param a First argument
     * @param b Second argument
     * @return The Owen's T function.
     */
    template <typename T1, typename T2>
    inline typename boost::math::tools::promote_args<T1,T2>::type
    owenst(const T1& a, const T2& b) {
      return boost::math::owens_t(a, b);
    }
  }
}

#endif
