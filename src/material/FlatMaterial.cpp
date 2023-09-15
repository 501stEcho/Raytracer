/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "material/FlatMaterial.hpp"

Raytracer::RGB Raytracer::FlatMaterial::getPixelColor(const Ray &, const HitResult &) const
{
    return _color;
}

double Raytracer::FlatMaterial::getMetallicVal() const
{
    return _metallic;
}

