// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor fms in simd mode for std::int64_t type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/fms.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_fms, bs::pedantic_(bs::fms));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_fms, std::int64_t>(-10, 10, -10, 10, -10, 10);
}

