/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "IMaterial.hpp"

#include <vector>
#include <fstream>
#include <iostream>

namespace Raytracer {

    class TexturedMaterial : public IMaterial {
    public:
        explicit TexturedMaterial(const std::string &path);

        [[nodiscard]] RGB getPixelColor(const Ray &ray, const HitResult &result) const override;
        [[nodiscard]] double getMetallicVal() const override;

    private:
        void parsePPM6(std::ifstream &file);

        std::vector<std::vector<Raytracer::RGB>> _texture;
        int _width = 0;
        int _height = 0;
        double _metallic = 0;
    };

}
