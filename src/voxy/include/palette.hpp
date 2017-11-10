/**
 * @file    palette.hpp
 * @ingroup voxy
 * @brief   Palette object for voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef VOXY_PALETTE_HPP
#define VOXY_PALETTE_HPP

#include <vector>
#include <assimp/scene.h>

namespace voxy
{
    class palette
    {
    private:
      bool **mColourValidity;
      bool **mTextureValidity;
      std::vector<std::vector<aiColor4D>> mShapeColours;
      std::vector<std::vector<aiTexture>> mShapeTextures;
      std::vector<aiScene> mShapes;
      std::vector<aiColor4D> mColours;
      std::vector<aiTexture> mTextures;
    public:
      inline bool is_valid_shape_colour(int pShapeID, int pColourID){ return mColourValidity[pShapeID][pColourID]; }
      inline bool is_valid_shape_texture(int pShapeID, int pTextureID){ return mTextureValidity[pShapeID][pTextureID]; }
    };
}
#endif // VOXY_PALETTE_HPP
