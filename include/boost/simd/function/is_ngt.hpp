//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NGT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is not greater than y else returns @ref False.

    This is a convenient alias of @ref is_not_greater
**/
  template<typename T> auto is_ngt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is not greater than y else returns @ref False.


      Function object tied to simd::is_ngt

      @see simd::is_ngt
    **/
    const boost::dispatch::functor<tag::is_ngt_> is_ngt = {};
  }
} }
#endif

#include <boost/simd/function/scalar/is_not_greater.hpp>
#include <boost/simd/function/simd/is_ngt.hpp>

#endif
