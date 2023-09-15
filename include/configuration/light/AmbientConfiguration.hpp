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

    class AmbientConfiguration : public ILightConfiguration {
    public:
        explicit AmbientConfiguration(Setting setting)
        {
            auto const &color = FIND_VALUE(Setting, setting, "color");

            _strength = FIND_VALUE(double, setting, "strength");
            _samplesnb = FIND_VALUE(unsigned int, setting, "samples");
            _noisenb = FIND_VALUE(unsigned int, setting, "noises");
            _color = RGB(FIND_VALUE(int, color, "r"),
                              FIND_VALUE(int, color, "g"),
                              FIND_VALUE(int, color, "b")
            );
            _color.colorClamp();
        };

        [[nodiscard]] Light toLight() const override
        {
            return LightFactory::createAmbient(_color, _strength, _samplesnb, _noisenb);
        }

    private:
        double _strength;
        unsigned int _samplesnb;
        unsigned int _noisenb;
        RGB _color;
    };

}