/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "IPrimitiveConfiguration.hpp"
#include "configuration/ConfigurationParser.hpp"

namespace Raytracer {

    class ConeConfiguration : public IPrimitiveConfiguration {
    public:
        explicit ConeConfiguration(Setting setting)
        {
            auto const &center = FIND_VALUE(Setting, setting, "center");
            auto const &color = FIND_VALUE(Setting, setting, "color");

            _radius = FIND_VALUE(double, setting, "radius");
            _height = FIND_VALUE(double, setting, "height");
            _center = Vector3D(FIND_VALUE(double, center, "x"),
                               FIND_VALUE(double, center, "y"),
                               FIND_VALUE(double, center, "z")
            );
            _color = RGB(FIND_VALUE(int, color, "r"),
                              FIND_VALUE(int, color, "g"),
                              FIND_VALUE(int, color, "b")
            );
        };

        [[nodiscard]] Primitive toPrimitive() const override
        {
            return PrimitiveFactory::createCone(_center, _radius, _height, std::make_shared<FlatMaterial>(_color));
        }

    private:
        double _radius;
        double _height;
        Vector3D _center;
        RGB _color;
    };

}
