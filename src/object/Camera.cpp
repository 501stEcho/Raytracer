/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "object/Camera.hpp"

Raytracer::Ray Raytracer::Camera::ray(double u, double v) const
{
    auto point = _screen.pointAt(u, v);
    auto direction = Vector3D(point.x(), -point.y(), point.z()) - _origin;

    return Ray(_origin, direction);
}
