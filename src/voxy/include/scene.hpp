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


#include "palette.hpp"
#include "voxel.hpp"

namespace voxy {
class scene {
public:
  //std::vector<voxy::voxel> voxels;
  voxy::palette palette;

  // mesh representation of object
};
} // namespace voxy
#endif // VOXY_SCENE_HPP
