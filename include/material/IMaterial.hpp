/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <memory>

#include "math/Vector3D.hpp"
#include "math/Ray.hpp"
#include "math/HitResult.hpp"
#include "math/RGB.hpp"

namespace Raytracer {

    enum class MaterialType {
        FLAT, TEXTURE
    };

    class IMaterial {
    public:
        [[nodiscard]] virtual RGB getPixelColor(const Ray &ray, const HitResult &result) const = 0;
        [[nodiscard]] virtual double getMetallicVal() const = 0;

        virtual ~IMaterial() = default;
    };

    using Material = std::shared_ptr<IMaterial>;

}