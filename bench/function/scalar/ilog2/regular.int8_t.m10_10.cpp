// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor ilog2 in scalar mode for std::int8_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/ilog2.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_ilog2, bs::ilog2);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_ilog2, std::int8_t>(-10, 10);
}

