//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/log10.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/three.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::rec(T(i));
    b[i] = bs::plain_(bs::log10)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(/*bs::plain_*/(bs::log10)(aa1), bb, 0.5);
}

STF_CASE_TPL("Check log10 on pack", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}



STF_CASE_TPL (" log10", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(bs::plain_(log10)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);
  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Minf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Mone<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Zero<p_t>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Mzero<p_t>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::plain_(log10)(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Two<p_t>()), p_t(0.301029995663981195213738894724), 0);
  STF_ULP_EQUAL(bs::plain_(log10)(bs::Three<p_t>()),p_t(0.477121254719662437295027903255), 0.5);
}

