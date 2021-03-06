// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor sqrt1pm1 in simd mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/sqrt1pm1.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_sqrt1pm1, bs::sqrt1pm1);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_sqrt1pm1, double>(-10, 10);
}
