/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <memory>

#include "math/RGB.hpp"

namespace Raytracer {

    class AOutput {
    private:
        std::vector<std::vector<RGB>> _colors;

    protected:
        unsigned _width;
        unsigned _height;

    public:
        explicit AOutput(unsigned width, unsigned height) : _width(width), _height(height)
        {
            for (unsigned y = 0; y < height; y++) {
                _colors.emplace_back();

                for (unsigned x = 0; x < width; x++)
                    _colors[y].emplace_back();
            }
        }

        virtual ~AOutput() = default;

        virtual void display() = 0;

        void setColor(size_t x, size_t y, RGB color)
        {
            if (x < _width && y < _height)
                _colors[y][x] = color;
        };

        RGB &getColor(size_t x, size_t y)
        {
            if (x < _width && y < _height)
                return _colors[y][x];
            return _colors[0][0];
        };
    };

    using Output = std::shared_ptr<Raytracer::AOutput>;

}
