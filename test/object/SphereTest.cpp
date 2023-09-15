/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <gtest/gtest.h>

#include "../../include/object/Sphere.hpp"
#include "../../include/math/Vector3D.hpp"
#include "../../include/math/Ray.hpp"

#define VEC(x,y,z) Raytracer::Vector3D(x, y, z)

class SphereTest : public testing::Test {

};

TEST_F(SphereTest, RayIntersection)
{
    Raytracer::Sphere sphere(VEC(10, 0, 0), 5);

    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 0, 0), VEC(1, 0, 0))));
    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 0, 0), VEC(5, 0, 0))));
    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 5, 0), VEC(10, -5, 0))));
    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 5, 5), VEC(10, -5, -5))));

    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 1, 1), VEC(1, 0, 0))));
    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 4, 0), VEC(1, 0, 0))));
    ASSERT_TRUE(sphere.hits(Raytracer::Ray(VEC(0, 2, 2), VEC(1, 0, 0))));
    
    ASSERT_FALSE(sphere.hits(Raytracer::Ray(VEC(0, 10, 10), VEC(1, 0, 0))));
    ASSERT_FALSE(sphere.hits(Raytracer::Ray(VEC(15, 0, 0), VEC(1, 0, 0))));
}
