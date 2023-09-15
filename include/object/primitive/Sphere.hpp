/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <utility>

#include "object/IPrimitive.hpp"

namespace Raytracer {

    class Sphere : public IPrimitive {
    private:
        Vector3D _center = Vector3D();
        double _radius = 0.0;
        Material _material;

    public:
        Sphere(Vector3D center, double radius, Material material) : IPrimitive(), _center(center), _radius(radius),
                                                                    _material(std::move(material)) {};

        ~Sphere() override = default;

        bool noObstacle(const Ray &ray) override;
        HitOptionalResult hits(const Ray &ray) override;

        [[nodiscard]] Material getMaterial() const override;

        [[nodiscard]] std::pair<double, double> getTextureRatio(const HitResult &result) override;
    };

}
