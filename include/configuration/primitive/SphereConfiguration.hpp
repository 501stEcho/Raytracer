/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "IPrimitiveConfiguration.hpp"
#include "configuration/ConfigurationParser.hpp"
#include "material/FlatMaterial.hpp"
#include "material/TexturedMaterial.h"

#pragma once

namespace Raytracer {

    class SphereConfiguration : public IPrimitiveConfiguration {
    public:
        explicit SphereConfiguration(Setting setting) {
            _x = FIND_VALUE(double, setting, "x");
            _y = FIND_VALUE(double, setting, "y");
            _z = FIND_VALUE(double, setting, "z");
            _radius = FIND_VALUE(double, setting, "r");

            if (setting.exists("color")) {
                auto const &color = FIND_VALUE(Setting, setting, "color");

                _color = RGB(FIND_VALUE(int, color, "r"),
                                  FIND_VALUE(int, color, "g"),
                                  FIND_VALUE(int, color, "b")
                );
                _materialType = MaterialType::FLAT;
            } else if (setting.exists("texture")) {
                auto const &texture = FIND_VALUE(Setting, setting, "texture");

                _path = FIND_VALUE(std::string, texture, "path");
                _materialType = MaterialType::TEXTURE;
            }
        };

        [[nodiscard]] Primitive toPrimitive() const override {
            std::shared_ptr<IMaterial> material;
            switch (_materialType) {
                using
                enum MaterialType;
                case FLAT:
                    material = std::make_shared<FlatMaterial>(_color);
                    break;

                case TEXTURE:
                    material = std::make_shared<TexturedMaterial>(_path);
                    break;

                default:
                    throw ConfigurationException("Missing material for sphere");
            }

            return PrimitiveFactory::createSphere(Vector3D(_x, _y, _z), _radius, material);
        }

    private:
        double _x;
        double _y;
        double _z;
        double _radius;
        RGB _color;
        std::string _path;
        MaterialType _materialType;
    };

}
