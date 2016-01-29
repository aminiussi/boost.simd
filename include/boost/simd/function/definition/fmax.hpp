//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_FMAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_FMAX_HPP_INCLUDED

#include <boost/simd/function/definition/maxnum.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    using fmax_ = maxnum_;
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::fmax_,fmax);
} }

#endif
