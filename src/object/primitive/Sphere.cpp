/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "object/primitive/Sphere.hpp"

#include <valarray>
#include <optional>

bool Raytracer::Sphere::noObstacle(const Ray &ray)
{
    Raytracer::Vector3D oc = ray.origin() - _center;
    auto a = ray.direction().dot(ray.direction());
    auto b = oc.dot(ray.direction());
    auto c = oc.dot(oc) - _radius * _radius;

    if (auto discriminant = b * b - a * c; discriminant >= 0) {
        auto sqrtDiscriminant = std::sqrt(discriminant);
        auto t1 = (-b - sqrtDiscriminant) / a;
        auto t2 = (-b + sqrtDiscriminant) / a;
        auto t = (t1 > t2 ? t2 : t1);

        if (t < 0 || (ray.limited() && t > 1))
            return true;

        Raytracer::Vector3D point = ray.origin() + ray.direction() * t;

        return false;
    }
    return true;
}

Raytracer::HitOptionalResult Raytracer::Sphere::hits(const Raytracer::Ray &ray)
{
    Raytracer::Vector3D oc = ray.origin() - _center;
    auto a = ray.direction().dot(ray.direction());
    auto b = oc.dot(ray.direction());
    auto c = oc.dot(oc) - _radius * _radius;

    if (auto discriminant = b * b - a * c; discriminant >= 0) {
        auto sqrtDiscriminant = std::sqrt(discriminant);
        auto t1 = (-b - sqrtDiscriminant) / a;
        auto t2 = (-b + sqrtDiscriminant) / a;
        auto t = (t1 > t2 ? t2 : t1);

        if (t < 0 || (ray.limited() && t1 > 1))
            return {};
        Raytracer::Vector3D point = ray.origin() + ray.direction() * t;
        Raytracer::Vector3D normal = (point - _center) / _radius;

        return {{point, normal, t, this}};
    }
    return {};
}

Raytracer::Material Raytracer::Sphere::getMaterial() const
{
    return _material;
}

std::pair<double, double> Raytracer::Sphere::getTextureRatio(const Raytracer::HitResult &result) {
    Raytracer::Vector3D normal = result.normal.normalized();
    double u = asin(normal.x()) / M_PI + .5;
    double v = asin(normal.y()) / M_PI + .5;

    return {u, v};
}
