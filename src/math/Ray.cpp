/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "math/Ray.hpp"

const Raytracer::Vector3D &Raytracer::Ray::origin() const
{
    return _origin;
}

const Raytracer::Vector3D &Raytracer::Ray::direction() const
{
    return _direction;
}

const bool &Raytracer::Ray::limited() const
{
    return _limited;
}
