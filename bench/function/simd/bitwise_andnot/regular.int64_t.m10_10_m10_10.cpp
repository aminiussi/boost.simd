// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor bitwise_andnot in simd mode for std::int64_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_bitwise_andnot, bs::bitwise_andnot);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_bitwise_andnot, std::int64_t>(-10, 10,-10, 10);
}
