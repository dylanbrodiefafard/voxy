/**
 * @file    scene.hpp
 * @ingroup voxy
 * @brief   Scene object for voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef VOXY_SCENE_HPP
#define VOXY_SCENE_HPP

#include <assimp/scene.h>
#include <vector>

#include "palette.hpp"
#include "voxel.hpp"

namespace voxy {
class scene {
public:
  std::vector<voxy::voxel> voxels;
  voxy::palette palette;
  aiScene continuous_scene;
  aiScene discrete_scene;
  void voxelize(int pMaximumVoxels);
};
} // namespace voxy
#endif // VOXY_SCENE_HPP
