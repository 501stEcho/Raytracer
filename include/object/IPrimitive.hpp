/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <utility>
#include <optional>

#include "math/Ray.hpp"
#include "math/Color.hpp"
#include "material/IMaterial.hpp"
#include "math/HitResult.hpp"

namespace Raytracer {

    class IPrimitive {
    public:
        virtual bool noObstacle(const Ray &ray) = 0;
        virtual HitOptionalResult hits(const Ray &ray) = 0;
        [[nodiscard]] virtual Material getMaterial() const = 0;
        [[nodiscard]] virtual std::pair<double, double> getTextureRatio(const HitResult &result) = 0;

        virtual ~IPrimitive() = default;
    };

}
