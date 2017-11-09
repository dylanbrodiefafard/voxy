#ifndef VOXY_VOXEL_HPP
#define VOXY_VOXEL_HPP

/**
* A voxel represents a value on a regular grid in three-dimensonal space.
*/
namespace voxy
{
    class voxel
    {
        private:
            float mMembership; /**< A fuzzy representation [0, 1] of this voxel's membership to the grid. 0 represents pure exclusion and 1 represents pure inclusion */
            float mVisibility; /**< A ratio of how occluded this voxel is in the grid. 0 represents complete occlusion and 1 represents no occlusion. */

        public:
            voxel(int pX, int pY, int pZ);

            void set_membership(float pMembership);
            void set_visibility(float pVisibility);

            float get_membership() const;
            float get_visiblity() const;

            int mX; /**< The Voxel's X position in the grid */
            int mY; /**< The Voxel's Y position in the grid */
            int mZ; /**< The Voxel's Z position in the grid */
    };
}
#endif // VOXY_VOXEL_HPP
