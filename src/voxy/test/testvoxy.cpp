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

#include <CGAL/Simple_cartesian.h>
#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/AABB_triangle_primitive.h>
#include <random>

#include "config.hpp"
#include "voxel.hpp"


typedef CGAL::Simple_cartesian<double> K;
typedef K::FT FT;
typedef K::Ray_3 Ray;
typedef K::Line_3 Line;
typedef K::Point_3 Point;
typedef K::Triangle_3 Triangle;
typedef std::list<Triangle>::iterator Iterator;
typedef CGAL::AABB_triangle_primitive<K, Iterator> Primitive;
typedef CGAL::AABB_traits<K, Primitive> AABB_triangle_traits;
typedef CGAL::AABB_tree<AABB_triangle_traits> Tree;

void test_voxy_voxel(int nCases)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disi(0, 999);
  std::uniform_real_distribution<> disf(0, 1);
  for (int i = 0; i < nCases; i++) {
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
}


void CGAL_AABB_tree_demo()
{
  Point a(1.0, 0.0, 0.0);
  Point b(0.0, 1.0, 0.0);
  Point c(0.0, 0.0, 1.0);
  Point d(0.0, 0.0, 0.0);
  std::list<Triangle> triangles;
  triangles.push_back(Triangle(a,b,c));
  triangles.push_back(Triangle(a,b,d));
  triangles.push_back(Triangle(a,d,c));
  // constructs AABB tree
  Tree tree(triangles.begin(),triangles.end());
  // counts #intersections
  Ray ray_query(a,b);
  std::cout << tree.number_of_intersected_primitives(ray_query)
            << " intersections(s) with ray query" << std::endl;
  // compute closest point and squared distance
  Point point_query(2.0, 2.0, 2.0);
  Point closest_point = tree.closest_point(point_query);
  std::cerr << "closest point is: " << closest_point << std::endl;
  FT sqd = tree.squared_distance(point_query);
  std::cout << "squared distance: " << sqd << std::endl;
}

int main() {

  test_voxy_voxel(1000);
  CGAL_AABB_tree_demo();
  return 0;
}
