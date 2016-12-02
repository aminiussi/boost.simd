//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ifrexp.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <utility>
#include <tuple>

STF_CASE_TPL(" ifrexp0", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifrexp;
  using iT = bd::as_integer_t<T,signed>;

  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Valmax<T>();
    std::tie(m, e) = ifrexp(a);
    STF_ULP_EQUAL(m, bs::One<T>()-bs::Halfeps<T>(), 1);
    STF_EQUAL(e, bs::Limitexponent<T>());
    STF_EQUAL(ldexp(m,e),a);
  }

}

STF_CASE_TPL(" ifrexp", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifrexp;
  using iT = bd::as_integer_t<T,signed>;

  STF_EXPR_IS( (ifrexp(T()))
             , (std::pair<T,iT>)
             );

  {
    namespace bs = boost::simd;
    iT e;
    T  m;

    std::tie(m, e) = ifrexp(bs::One<T>());
    STF_EQUAL(m, bs::Half<T>());
    STF_EQUAL(e, bs::One<iT>());
  }

  {
    namespace bs = boost::simd;
    std::pair<T,iT> p;

    p = ifrexp(bs::One<T>());
    STF_EQUAL(p.first  , bs::Half<T>());
    STF_EQUAL(p.second , bs::One<iT>());
  }
}

STF_CASE_TPL(" ifrexp0", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifrexp;
  using iT = bd::as_integer_t<T,signed>;

  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Valmax<T>();
    std::tie(m, e) = ifrexp(a);
    STF_ULP_EQUAL(m, bs::One<T>()-bs::Halfeps<T>(), 1);
    STF_EQUAL(e, bs::Limitexponent<T>());
    STF_EQUAL(ldexp(m,e),a);
  }


}


