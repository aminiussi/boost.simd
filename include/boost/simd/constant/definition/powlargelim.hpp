//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_POWLARGELIM_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_POWLARGELIM_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct powlargelim_ : boost::dispatch::constant_value_<powlargelim_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,powlargelim_,boost::dispatch::constant_value_<powlargelim_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x44ffe000UL, 0x40cfff8000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,powlargelim_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::powlargelim_,powlargelim);
  }

  template<typename T> BOOST_FORCEINLINE auto Powlargelim() BOOST_NOEXCEPT
  -> decltype(functional::powlargelim( boost::dispatch::as_<T>{}))
  {
    return functional::powlargelim( boost::dispatch::as_<T>{} );
  }
} }

#endif