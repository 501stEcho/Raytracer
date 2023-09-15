/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "math/Angle.hpp"

namespace Raytracer {

    class CylinderConfiguration : public IPrimitiveConfiguration {
    public:
        explicit CylinderConfiguration(Setting setting) {
            auto const &center = FIND_VALUE(Setting, setting, "center");
            auto const &color = FIND_VALUE(Setting, setting, "color");

            _radius = FIND_VALUE(double, setting, "radius");
            _height = (setting.exists("height") ? FIND_VALUE(double, setting, "height") :
                       std::numeric_limits<double>::infinity());
            _center = Vector3D(FIND_VALUE(double, center, "x"),
                               FIND_VALUE(double, center, "y"),
                               FIND_VALUE(double, center, "z")
            );
            if (setting.exists("rotation")) {
                auto const &rotation = FIND_VALUE(Setting, setting, "rotation");
                _rotation = Angle::radianVector(FIND_VALUE(double, rotation, "x"),
                                                FIND_VALUE(double, rotation, "y"),
                                                FIND_VALUE(double, rotation, "z")
                );
            } else {
                _rotation = Vector3D(0,0,0);
            }
            _color = RGB(FIND_VALUE(int, color, "r"),
                         FIND_VALUE(int, color, "g"),
                         FIND_VALUE(int, color, "b")
            );
        };

        [[nodiscard]] Primitive toPrimitive() const override {
            return PrimitiveFactory::createCylinder(_center, _rotation, _radius, _height, std::make_shared<FlatMaterial>(_color));
        }

    private:
        double _radius;
        double _height;
        Vector3D _center;
        Vector3D _rotation;
        RGB _color;
    };

}
