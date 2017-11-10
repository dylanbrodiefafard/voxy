/**
 * @file    voxel.hpp
 * @ingroup voxy
 * @brief   Comphrensive test cases for the voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef VOXY_VOXEL_HPP
#define VOXY_VOXEL_HPP

#define VOXY_ID_NOT_SET -1

/**
 * A voxel represents a value on a regular grid in three-dimensonal space.
 */
namespace voxy {
class voxel {
private:
  float mMembership; /**< A fuzzy representation [0, 1] of this voxel's
                        membership to the grid. 0 represents pure exclusion and
                        1 represents pure inclusion */
  float mVisibility; /**< A ratio of how occluded this voxel is in the grid. 0
                        represents complete occlusion and 1 represents no
                        occlusion. */
  int mShapeID;      /**< An ID corresponding to a shape in a palette */
  int mColourID;     /**< An ID corresponding to a colour in a palette */
  int mTextureID;    /**< An ID corresponding to a texture in a palette */

  int mX; /**< The Voxel's X position in the grid */
  int mY; /**< The Voxel's Y position in the grid */
  int mZ; /**< The Voxel's Z position in the grid */
public:
  voxel(int pX, int pY, int pZ);

  void set_membership(float pMembership);
  void set_visibility(float pVisibility);
  void set_shapeID(int pShapeID);
  void set_colourID(int pColourID);
  void set_textureID(int pTextureID);

  inline float get_membership() { return mMembership; }
  inline float get_visibility() { return mVisibility; }
  inline int get_shapeID() { return mShapeID; }
  inline int get_colourID() { return mColourID; }
  inline int get_textureID() { return mTextureID; }
  inline int get_X() { return mX; }
  inline int get_Y() { return mY; }
  inline int get_Z() { return mZ; }

  inline void unassign_shapeID() { mShapeID = VOXY_ID_NOT_SET; }
  inline void unassign_colourID() { mColourID = VOXY_ID_NOT_SET; }
  inline void unassign_textureID() { mTextureID = VOXY_ID_NOT_SET; }

  inline bool is_shapeID_assigned() { return mShapeID != VOXY_ID_NOT_SET; }
  inline bool is_colourID_assigned() { return mColourID != VOXY_ID_NOT_SET; }
  inline bool is_textureID_assigned() { return mTextureID != VOXY_ID_NOT_SET; }
};
} // namespace voxy
#endif // VOXY_VOXEL_HPP
