/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <complex>
#include "object/primitive/Cylinder.hpp"

bool Raytracer::Cylinder::noObstacle(const Ray &ray)
{
    double a = (ray.direction().x() * ray.direction().x()) + (ray.direction().z() * ray.direction().z());
    double b = 2 * (ray.direction().x() * (ray.origin().x() - _center.x()) +
                    ray.direction().z() * (ray.origin().z() - _center.z()));
    double c = (ray.origin().x() - _center.x()) * (ray.origin().x() - _center.x()) +
               (ray.origin().z() - _center.z()) * (ray.origin().z() - _center.z()) - (_radius * _radius);
    double delta = b * b - 4 * (a * c);

    if (fabs(delta) < 0.001) return true;
    if (delta < 0.0) return true;

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);
    double t = (t1 > t2 ? t2 : t1);

    if (t < 0 || (ray.limited() && t > 1))
        return true;
    Raytracer::Vector3D point = ray.origin() + ray.direction() * t;
    Raytracer::Vector3D normal(2 * point.x(), 0.0f, 2 * point.z());

    if (point.y() > _center.y() + (_height / 2))
        return true;
    if (point.y() < _center.y() - (_height / 2))
        return true;

    return false;
}

Raytracer::HitOptionalResult Raytracer::Cylinder::hits(const Raytracer::Ray &ray)
{
    double a = (ray.direction().x() * ray.direction().x()) + (ray.direction().z() * ray.direction().z());
    double b = 2 * (ray.direction().x() * (ray.origin().x() - _center.x()) +
                    ray.direction().z() * (ray.origin().z() - _center.z()));
    double c = (ray.origin().x() - _center.x()) * (ray.origin().x() - _center.x()) +
               (ray.origin().z() - _center.z()) * (ray.origin().z() - _center.z()) - (_radius * _radius);
    double delta = b * b - 4 * (a * c);

    if (fabs(delta) < 0.001) return {};
    if (delta < 0.0) return {};

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);
    double t = (t1 > t2 ? t2 : t1);

    if (t < 0 || (ray.limited() && t > 1))
        return {};
    Raytracer::Vector3D point = ray.origin() + ray.direction() * t;
    Raytracer::Vector3D normal(2 * point.x(), 0.0f, 2 * point.z());

    if (point.y() > _center.y() + (_height / 2))
        return {};
    if (point.y() < _center.y() - (_height / 2))
        return {};

    return {{point, normal, t, this}};
}

Raytracer::Material Raytracer::Cylinder::getMaterial() const
{
    return _material;
}

std::pair<double, double> Raytracer::Cylinder::getTextureRatio(const Raytracer::HitResult &) {
    return {0, 0};
}
