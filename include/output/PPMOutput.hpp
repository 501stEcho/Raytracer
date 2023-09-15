/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "AOutput.hpp"

namespace Raytracer {

    class PPMOutput : public AOutput {
    public:
        explicit PPMOutput(unsigned width, unsigned height) : AOutput(width, height)
        {
            for (size_t y = 0; y < _height; y++) {
                for (size_t x = 0; x < _width; x++) {
                    setColor(x, y, RGB());
                }
            }
        };

        void display() override;
    };

    void PPMOutput::display()
    {
        std::string result{};

        std::cout << "P3" << std::endl << _width << ' ' << _height << std::endl << "255" << std::endl;
        for (unsigned y = 0; y < _height; y++) {
            for (unsigned x = 0; x < _width; x++) {
                RGB color = getColor(x, y);

                result += std::to_string(color.x()) + " " + std::to_string(color.y()) + " " +
                          std::to_string(color.z()) + '\n';
            }
        }
        std::cout << result;
    }

}