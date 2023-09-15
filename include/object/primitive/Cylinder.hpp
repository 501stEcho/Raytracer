/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <utility>

#include "math/HitResult.hpp"
#include "material/IMaterial.hpp"
#include "object/IPrimitive.hpp"

namespace Raytracer {

    class Cylinder : public IPrimitive {
    private:
        Vector3D _center;
        Vector3D _rotation;
        double _radius;
        double _height;
        Material _material;

    public:
        Cylinder(Vector3D center, Vector3D rotation, double radius, double height, Material material) :
                 _center(center), _rotation(rotation), _radius(radius), _height(height), _material(std::move(material))
        {};

        ~Cylinder() override = default;

        bool noObstacle(const Ray &ray) override;
        HitOptionalResult hits(const Ray &ray) override;
        [[nodiscard]] Material getMaterial() const override;

        [[nodiscard]] std::pair<double, double> getTextureRatio(const HitResult &result) override;
    };

}
