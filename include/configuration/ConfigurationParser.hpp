/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <optional>

#include "exception/ConfigurationException.hpp"

#define FIND_VALUE(type, element, key) Raytracer::ConfigurationParser::getValue<type>(element, key)

namespace Raytracer {

    using Setting = const libconfig::Setting &;

    class ConfigurationParser {
    public:
        template<typename T>
        static T getValue(const libconfig::Setting &element, const std::string &key)
        {
            existsOrThrow(element, key);

            return element[key.c_str()];
        }

        static void existsOrThrow(const libconfig::Setting &element, const std::string &key)
        {
            if (element.exists(key))
                return;
            std::string target = (element.getName() == nullptr ? "" : std::string(element.getName()) + " ") + key;
            std::string reason = "Missing " + target + " configuration";

            throw Raytracer::ConfigurationException(reason);
        }
    };

}
