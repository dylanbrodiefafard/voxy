/**
 * @file    voxelizer.hpp
 * @ingroup voxy
 * @brief   Comphrensive test cases for the voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef VOXY_VOXYLIZER_HPP
#define VOXY_VOXYLIZER_HPP
namespace voxy {
class voxylizer {
public:
  void voxelize(&voxy::scene);
  // void subvoxelize(&voxy::scene);
};
} // namespace voxy
#endif // VOXY_VOXYLIZER_HPP
