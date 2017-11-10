/**
 * @file    debug.hpp
 * @ingroup voxy
 * @brief   Debug related macros, templates, and code.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef VOXY_DEBUG_HPP
#define VOXY_DEBUG_HPP

#include <assert.h>

#ifndef NDEBUG
#define ASSERT(x) assert(x);
#else
#define ASSERT(x)
#endif

#endif // VOXY_DEBUG_HPP
