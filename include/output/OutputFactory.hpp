/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "AOutput.hpp"
#include "PPMOutput.hpp"
#include "SFMLOutput.hpp"

#include <memory>

namespace Raytracer {

    class OutputFactory {
    public:
        static Output getCurrentOutput(unsigned width, unsigned height);

    private:
        static Output createPPMOutput(unsigned width, unsigned height);

        static Output createSFMLOutput(unsigned width, unsigned height);
    };

    Output OutputFactory::getCurrentOutput(unsigned int width, unsigned int height) {
        return (isatty(fileno(stdout)) ? createSFMLOutput(width, height)
                                       : createPPMOutput(width, height));
    }

    Output OutputFactory::createPPMOutput(unsigned width, unsigned height) {
        return std::make_shared<PPMOutput>(width, height);
    }

    Output OutputFactory::createSFMLOutput(unsigned width, unsigned height) {
        return std::make_shared<SFMLOutput>(width, height);
    }

}
