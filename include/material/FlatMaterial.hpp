/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "IMaterial.hpp"

namespace Raytracer {

    class FlatMaterial : public IMaterial {
    public:
        explicit FlatMaterial(RGB color) : IMaterial(), _color(color), _metallic(10.0)
        {};

        [[nodiscard]] RGB getPixelColor(const Ray &ray, const HitResult &result) const override;
        [[nodiscard]] double getMetallicVal() const override;

    private:
        RGB _color;
        double _metallic;
    };

}
