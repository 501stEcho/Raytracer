/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <exception>
#include <string>

namespace Raytracer {

    class ConfigurationException : public std::exception {
    public:
        explicit ConfigurationException(std::string reason) : _reason(std::move(reason))
        {};

        [[nodiscard]] const char *what() const noexcept override
        {
            return _reason.c_str();
        };


    private:
        std::string _reason;
    };

}
