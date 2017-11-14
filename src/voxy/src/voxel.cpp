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
#include "config.hpp"

voxy::voxel::voxel(int pX, int pY, int pZ) {
  mX = pX;
  mY = pY;
  mZ = pZ;

  mMembership = 0.0f;
  mVisibility = 0.0f;

  mShapeID = VOXY_ID_NOT_SET;
  mColourID = VOXY_ID_NOT_SET;
  mTextureID = VOXY_ID_NOT_SET;
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

void voxy::voxel::set_shapeID(int pShapeID) {
  ASSERT(pShapeID >= 0)
  ASSERT(pShapeID != VOXY_ID_NOT_SET)

  mShapeID = pShapeID;
}

void voxy::voxel::set_colourID(int pColourID) {
  ASSERT(pColourID >= 0)
  ASSERT(pColourID != VOXY_ID_NOT_SET)

  mColourID = pColourID;
}

void voxy::voxel::set_textureID(int pTextureID) {
  ASSERT(pTextureID >= 0)
  ASSERT(pTextureID != VOXY_ID_NOT_SET)

  mTextureID = pTextureID;
}