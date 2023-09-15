/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "object/primitive/Plane.hpp"

#include <valarray>
#include <optional>

bool Raytracer::Plane::noObstacle(const Ray &ray)
{
    using
    enum Axis;
    Raytracer::Vector3D rayOrigin = ray.origin();
    Raytracer::Vector3D rayDirection = ray.direction();
    Raytracer::Vector3D planePoint(_axis == X ? _position : 0,
                                   _axis == Y ? _position : 0,
                                   _axis == Z ? _position : 0);
    Raytracer::Vector3D planeNormal(_axis == X ? 1 : 0,
                                    _axis == Y ? 1 : 0,
                                    _axis == Z ? 1 : 0);

    double denominator = rayDirection.dot(planeNormal);
    if (fabs(denominator) < 0.0001f) return true;
    double t = (planePoint - rayOrigin).dot(planeNormal) / denominator;

    if (t < 0.0f || (ray.limited() && t > 1))
        return true;
    Vector3D res = rayOrigin + rayDirection * t;
    return false;
}

Raytracer::HitOptionalResult Raytracer::Plane::hits(const Raytracer::Ray &ray)
{
    using
    enum Axis;
    Raytracer::Vector3D rayOrigin = ray.origin();
    Raytracer::Vector3D rayDirection = ray.direction();
    Raytracer::Vector3D planePoint(_axis == X ? _position : 0,
                                   _axis == Y ? _position : 0,
                                   _axis == Z ? _position : 0);
    Raytracer::Vector3D planeNormal(_axis == X ? 1 : 0,
                                    _axis == Y ? 1 : 0,
                                    _axis == Z ? 1 : 0);

    planePoint = planePoint.rotate(_rotation);
    planeNormal = planeNormal.rotate(_rotation);

    double denominator = rayDirection.dot(planeNormal);
    if (fabs(denominator) < 0.0001f) return {};
    double t = (planePoint - rayOrigin).dot(planeNormal) / denominator;

    if (t < 0.0f || (ray.limited() && t > 1))
        return {};
    if (planeNormal.dot(ray.direction()) > 0.0)
        planeNormal *= -1;
    return {{rayOrigin + rayDirection * t, planeNormal, t, this}};
}

Raytracer::Material Raytracer::Plane::getMaterial() const
{
    return _material;
}

std::pair<double, double> Raytracer::Plane::getTextureRatio(const Raytracer::HitResult &) {
    return {0, 0};
}
