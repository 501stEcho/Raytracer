/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "object/PrimitiveList.hpp"

#include <limits>

Raytracer::HitOptionalResult Raytracer::PrimitiveList::hits(const Raytracer::Ray &ray)
{
    Raytracer::HitOptionalResult result = {};
    auto closest = std::numeric_limits<double>::infinity();

    auto transformedRay = Ray(
            ray.origin().rotate(_rotation).scale(_scale) + _translation,
            ray.direction().rotate(_rotation).scale(_scale)
        );

    for (const auto &object: _list) {
        Raytracer::HitOptionalResult optional = object->hits(transformedRay);

        if (!optional.has_value()) continue;
        if (optional->t < closest) {
            closest = optional->t;
            result = optional;
            _lastHit = object;
        }
    }

    for (PrimitiveList scene : _scenes) {
        Raytracer::HitOptionalResult optional = scene.hits(transformedRay);

        if (!optional.has_value()) continue;
        if (optional->t < closest) {
            closest = optional->t;
            result = optional;
            _lastHit = scene._lastHit;
        }
    }

    return result;
}

bool Raytracer::PrimitiveList::noObstacle(const Ray &ray)
{
    for (const auto &object: _list) {
        if (!object->noObstacle(ray))
            return (false);
    }
    return (true);
}

Raytracer::Material Raytracer::PrimitiveList::getMaterial() const
{
    return _lastHit->getMaterial();
}

Raytracer::PrimitiveList &Raytracer::PrimitiveList::add(const Primitive &element)
{
    _list.push_back(element);

    return *this;
}

Raytracer::PrimitiveList &Raytracer::PrimitiveList::add(Configuration &element)
{
    _scenes.emplace_back(element);

    return *this;
}

void Raytracer::PrimitiveList::clear()
{
    _list.clear();
}

std::pair<double, double> Raytracer::PrimitiveList::getTextureRatio(const Raytracer::HitResult &) {
    return {0, 0};
}
