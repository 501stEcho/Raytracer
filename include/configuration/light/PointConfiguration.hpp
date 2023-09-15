/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "ILightConfiguration.hpp"
#include "configuration/ConfigurationParser.hpp"

#pragma once

namespace Raytracer {

    class PointConfiguration : public ILightConfiguration {
    public:
        explicit PointConfiguration(Setting setting)
        {
            auto const &position = FIND_VALUE(Setting, setting, "position");
            auto const &color = FIND_VALUE(Setting, setting, "color");

            _strength = FIND_VALUE(double, setting, "strength");
            _position = Vector3D(FIND_VALUE(double, position, "x"),
                                    FIND_VALUE(double, position, "y"),
                                    FIND_VALUE(double, position, "z"));
            _color = RGB(FIND_VALUE(int, color, "r"),
                              FIND_VALUE(int, color, "g"),
                              FIND_VALUE(int, color, "b")
            );
            _color.colorClamp();
        };

        [[nodiscard]] Light toLight() const override
        {
            return LightFactory::createPoint(_position, _color, _strength);
        }

    private:
        double _strength;
        RGB _color;
        Vector3D _position;
    };

}