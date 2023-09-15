/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <complex>
#include "object/primitive/Cone.hpp"

bool Raytracer::Cone::noObstacle(const Ray &ray)
{
    Raytracer::Vector3D pos = ray.origin();
    Raytracer::Vector3D dir = ray.direction();

    double A = pos.x() - _center.x();
    double B = pos.z() - _center.z();
    double D = _height - pos.y() + _center.y();

    double tan = (_radius / _height) * (_radius / _height);

    double a = (dir.x() * dir.x()) + (dir.z() * dir.z()) - (tan * (dir.y() * dir.y()));
    double b = (2 * A * dir.x()) + (2 * B * dir.z()) + (2 * tan * D * dir.y());
    double c = (A * A) + (B * B) - (tan * (D * D));

    double delta = b * b - 4 * (a * c);
    if (fabs(delta) < 0.001) return true;
    if (delta < 0.0) return true;

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);
    double t;

    if (t1 > t2) t = t2;
    else t = t1;

    if (t < 0 || (ray.limited() && t > 1))
        return (true);
    double r = pos.y() + t * dir.y();

    return (!(r > _center.y()) && (r < _center.y() + _height));
}

Raytracer::HitOptionalResult Raytracer::Cone::hits(const Raytracer::Ray &ray)
{
    Raytracer::Vector3D pos = ray.origin();
    Raytracer::Vector3D dir = ray.direction();

    double A = pos.x() - _center.x();
    double B = pos.z() - _center.z();
    double D = _height - pos.y() + _center.y();

    double tan = (_radius / _height) * (_radius / _height);

    double a = (dir.x() * dir.x()) + (dir.z() * dir.z()) - (tan * (dir.y() * dir.y()));
    double b = (2 * A * dir.x()) + (2 * B * dir.z()) + (2 * tan * D * dir.y());
    double c = (A * A) + (B * B) - (tan * (D * D));

    double delta = b * b - 4 * (a * c);
    if (fabs(delta) < 0.001) return {};
    if (delta < 0.0) return {};

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);
    double t;

    if (t1 > t2) t = t2;
    else t = t1;

    double r = pos.y() + t * dir.y();

    if (t < 0 || (ray.limited() && t > 1))
        return {};

    if ((r > _center.y()) && (r < _center.y() + _height))
        return {{(pos + dir) * t, Raytracer::Vector3D(), t, this}};
    else return {};
}

Raytracer::Material Raytracer::Cone::getMaterial() const
{
    return _material;
}

std::pair<double, double> Raytracer::Cone::getTextureRatio(const Raytracer::HitResult &)
{
    return {0, 0};
}
