/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "object/IPrimitive.hpp"
#include "primitive/Sphere.hpp"
#include "primitive/Plane.hpp"
#include "object/primitive/Cylinder.hpp"
#include "object/primitive/Cone.hpp"

#include <memory>

namespace Raytracer {

    using Primitive = std::shared_ptr<IPrimitive>;

    class PrimitiveFactory {
    public:
        static Primitive createSphere(Vector3D origin, double radius, const Material &material)
        {
            return std::make_shared<Sphere>(origin, radius, material);
        };

        static Primitive createPlane(double position, Vector3D rotation, Axis axis, const Material &material)
        {
            return std::make_shared<Plane>(position, rotation, axis, material);
        };

        static Primitive createCylinder(Vector3D center, Vector3D rotation, double radius, double height, const Material &material)
        {
            return std::make_shared<Cylinder>(center, rotation, radius, height, material);
        }

        static Primitive createCone(Vector3D center, double radius, double height, const Material &material)
        {
            return std::make_shared<Cone>(center, radius, height, material);
        }
    };

}
