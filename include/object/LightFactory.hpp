/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "object/ILight.hpp"
#include "light/DirectionalLight.hpp"
#include "light/AmbientLight.hpp"
#include "light/PointLight.hpp"

#include <memory>

namespace Raytracer {
    using Light = std::shared_ptr<ILight>;

    class LightFactory {
    public:
        static Light createDirectional(Vector3D direction, RGB color, double strength)
        {
            return std::make_shared<DirectionalLight>(direction, color, strength);
        };

        static Light createPoint(Vector3D position, RGB color, double strength)
        {
            return std::make_shared<PointLight>(position, color, strength);
        };

        static Light createAmbient(RGB color, double strength, unsigned int samplesnb, unsigned int noisenb)
        {
            return std::make_shared<AmbientLight>(color, strength, samplesnb, noisenb);
        };
    };
}