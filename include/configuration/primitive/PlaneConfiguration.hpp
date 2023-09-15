/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "IPrimitiveConfiguration.hpp"
#include "configuration/ConfigurationParser.hpp"
#include "object/primitive/Plane.hpp"
#include "material/FlatMaterial.hpp"
#include "math/Angle.hpp"

namespace Raytracer {

    class PlaneConfiguration : public IPrimitiveConfiguration {
    public:
        explicit PlaneConfiguration(Setting setting) : _axis(findAxis(setting))
        {
            auto const &color = FIND_VALUE(Setting, setting, "color");

            _position = FIND_VALUE(double, setting, "position");
            _color = RGB(FIND_VALUE(int, color, "r"),
                              FIND_VALUE(int, color, "g"),
                              FIND_VALUE(int, color, "b")
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
        };

        [[nodiscard]] Primitive toPrimitive() const override
        {
            return PrimitiveFactory::createPlane(_position, _rotation, _axis, std::make_shared<FlatMaterial>(_color));
        }

    private:
        Axis _axis = Axis::X;
        Vector3D _rotation;
        double _position;
        RGB _color;

        static Axis findAxis(Setting setting)
        {
            auto raw = FIND_VALUE(std::string, setting, "axis");

            switch (raw[0]) {
                case 'x':
                    return Axis::X;
                case 'y':
                    return Axis::Y;
                case 'z':
                    return Axis::Z;
                default:
                    throw ConfigurationException("Invalid axis " + raw);
            }
        }
    };

}
