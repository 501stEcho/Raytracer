/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <optional>
#include <memory>

#include "math/Vector3D.hpp"

namespace Raytracer {

    class IPrimitive;

    struct HitResult {
        Raytracer::Vector3D point;
        Raytracer::Vector3D normal;
        double t;
        IPrimitive *primitive;
    };

    using HitOptionalResult = std::optional<struct HitResult>;

}
