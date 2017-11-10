/**
 * @file    voxel.cpp
 * @ingroup voxy
 * @brief   Comphrensive test cases for the voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "voxel.hpp"
#include "debug.hpp"

voxy::voxel::voxel(int pX, int pY, int pZ) {
  mX = pX;
  mY = pY;
  mZ = pZ;

  mMembership = 0.0f;
  mVisibility = 0.0f;
}

void voxy::voxel::set_membership(float pMembership) {
  ASSERT(pMembership > 0.0f)
  ASSERT(pMembership < 1.0f)

  mMembership = pMembership;
}

void voxy::voxel::set_visibility(float pVisibility) {
  ASSERT(pVisibility > 0.0f)
  ASSERT(pVisibility < 1.0f)

  mVisibility = pVisibility;
}
