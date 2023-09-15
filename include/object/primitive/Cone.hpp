/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "object/IPrimitive.hpp"

namespace Raytracer {

    class Cone : public IPrimitive {
    private:
        Vector3D _center;
        double _radius;
        double _height;
        Material _material;

    public:
        Cone(Vector3D center, double radius, double height, Material material) : _center(center),
                                                                                 _radius(radius),
                                                                                 _height(height),
                                                                                 _material(std::move(material))
        {};

        ~Cone() override = default;

        bool noObstacle(const Ray &ray) override;
        HitOptionalResult hits(const Ray &ray) override;
        [[nodiscard]] Material getMaterial() const override;

        [[nodiscard]] std::pair<double, double> getTextureRatio(const HitResult &result) override;
    };

}
