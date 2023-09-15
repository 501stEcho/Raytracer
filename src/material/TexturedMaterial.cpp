/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <sstream>
#include <valarray>

#include "material/TexturedMaterial.h"
#include "exception/TextureException.hpp"
#include "object/IPrimitive.hpp"

Raytracer::TexturedMaterial::TexturedMaterial(const std::string &path) : Raytracer::IMaterial() {
    std::ifstream file(path, std::ios::binary);
    std::string buffer;

    if (!file.is_open())
        throw TextureException("Invalid texture path");

    getline(file, buffer);
    if (buffer != "P6")
        throw TextureException("Invalid PPM format (only P6)");

    getline(file, buffer);
    std::stringstream stream(buffer);

    stream >> _width >> _height;

    getline(file, buffer);

    parsePPM6(file);
    file.close();
}

void Raytracer::TexturedMaterial::parsePPM6(std::ifstream &file) {
    std::vector<unsigned char> data(_width * _height * 3);

    for (int y = 0; y < _height; y++) {
        _texture.emplace_back();
        for (int x = 0; x < _width; x++)
            _texture[y].emplace_back();
    }

    file.get();
    file.read(std::bit_cast<char *>(data.data()), (std::streamsize) data.size());

    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            int offset = (y * _width + x) * 3;
            unsigned char g = data[offset];
            unsigned char b = data[offset + 1];
            unsigned char r = data[offset + 2];

            _texture[y][x] = RGB(r, g, b);
        }
    }
}

Raytracer::RGB
Raytracer::TexturedMaterial::getPixelColor(const Raytracer::Ray &, const Raytracer::HitResult &result) const
{
    auto [u, v] = result.primitive->getTextureRatio(result);
    auto i = (int) (v * _height);
    auto j = (int) (u * _width);

    return _texture[i][j];
}

double Raytracer::TexturedMaterial::getMetallicVal() const
{
    return (_metallic);
}