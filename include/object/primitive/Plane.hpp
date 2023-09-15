/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <utility>

#include "object/IPrimitive.hpp"
#include "material/IMaterial.hpp"

namespace Raytracer {

    enum class Axis {
        X, Y, Z
    };

    class Plane : public IPrimitive {
    private:
        double _position;
        Vector3D _rotation;
        Axis _axis;
        Material _material;

    public:
        Plane(double position, Vector3D rotation, Axis axis, Material material) : IPrimitive(),
                                                               _position(position),
                                                               _rotation(rotation),
                                                               _axis(axis),
                                                               _material(std::move(material))
        {};

        ~Plane() override = default;

        bool noObstacle(const Ray &ray) override;
        HitOptionalResult hits(const Ray &ray) override;
        [[nodiscard]] Material getMaterial() const override;

        [[nodiscard]] std::pair<double, double> getTextureRatio(const HitResult &result) override;
    };

}
