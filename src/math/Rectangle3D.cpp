/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <iostream>

#include "math/Screen.hpp"

Raytracer::Screen::Screen(const Raytracer::Configuration &configuration)
{
    Raytracer::Vector3D cameraOrigin = configuration.cameraPosition;
    double distance = (1 / tan((configuration.cameraFieldOfView / 2) * (M_PI / 180.0))) / 2;
    auto [cameraWidth, cameraHeight] = configuration.cameraResolution;
    auto ratio = (double) cameraHeight / cameraWidth;

    _origin = Vector3D(cameraOrigin.x() - .5, cameraOrigin.y() - (ratio / 2), cameraOrigin.z() + distance);
    _leftSide = Vector3D(0, ratio, 0);
}

Raytracer::Vector3D Raytracer::Screen::pointAt(double u, double v) const
{
    if (u < 0 || u > 1 || v < 0 || v > 1)
        return Vector3D();

    return _origin + (_bottomSide * u) + (_leftSide * v);
}
