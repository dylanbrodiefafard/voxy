/**
 * @file    test.cpp
 * @ingroup voxy
 * @brief   Comphrensive test cases for the voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "voxel.hpp"

int main() {

  voxy::voxel v = voxy::voxel(0, 0, 0);
  v.set_membership(0.5f);
  v.set_visibility(0.5f);
  v.set_visibility(1.9f);
  return 0;
}
