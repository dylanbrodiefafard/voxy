/**
 * @file    testvoxy.cpp
 * @ingroup voxy
 * @brief   Comprehensive test cases for the voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <random>

#include "debug.hpp"
#include "voxel.hpp"

int main() {

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disi(0, 999);
  std::uniform_real_distribution<> disf(0, 1);

  for (int i = 0; i < 1000; i++) {
    int x = disi(gen);
    int y = disi(gen);
    int z = disi(gen);

    voxy::voxel vox = voxy::voxel(x, y, z);

    ASSERT(vox.get_X() == x)
    ASSERT(vox.get_Y() == y)
    ASSERT(vox.get_Z() == z)

    ASSERT(!vox.is_shapeID_assigned())
    ASSERT(!vox.is_colourID_assigned())
    ASSERT(!vox.is_textureID_assigned())

    ASSERT(vox.get_visibility() == 0.0f)
    ASSERT(vox.get_membership() == 0.0f)

    for (int j = 0; j < 100; j++) {
      auto mem = (float)disf(gen);
      auto vis = (float)disf(gen);
      vox.set_membership(mem);
      vox.set_visibility(vis);

      ASSERT(vox.get_membership() == mem)
      ASSERT(vox.get_visibility() == vis)

      int sid = disi(gen);
      int cid = disi(gen);
      int tid = disi(gen);

      vox.set_shapeID(sid);
      vox.set_colourID(cid);
      vox.set_textureID(tid);

      ASSERT(vox.is_shapeID_assigned())
      ASSERT(vox.is_colourID_assigned())
      ASSERT(vox.is_textureID_assigned())

      ASSERT(vox.get_shapeID() == sid)
      ASSERT(vox.get_colourID() == cid)
      ASSERT(vox.get_textureID() == tid)

      vox.unassign_shapeID();
      vox.unassign_colourID();
      vox.unassign_textureID();

      ASSERT(!vox.is_shapeID_assigned())
      ASSERT(!vox.is_colourID_assigned())
      ASSERT(!vox.is_textureID_assigned())
    }
  }

  return 0;
}
