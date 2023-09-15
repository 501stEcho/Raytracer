/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "object/ILight.hpp"
#include "object/LightFactory.hpp"

namespace Raytracer {

    class ILightConfiguration {
    public:
        [[nodiscard]] virtual Light toLight() const = 0;

        virtual ~ILightConfiguration() = default;
    };

}
