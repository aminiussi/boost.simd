// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor deinterleave_first in simd mode for std::int16_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/deinterleave_first.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_deinterleave_first, bs::deinterleave_first);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_deinterleave_first, std::int16_t>(-10, 10,-10, 10);
}

