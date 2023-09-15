/*
** EPITECH PROJECT, 2023
** DirectionalLight
** File description:
** Raytracer
*/

#include "object/light/PointLight.hpp"
#include "object/PrimitiveList.hpp"

Raytracer::Vector3D Raytracer::PointLight::getImpact(Ray &cam, HitResult &point, PrimitiveList &primitives) const
{
    Vector3D diffuse;
    Vector3D specular;
    Vector3D norm(point.normal.normalized());
    Vector3D origin(point.point + norm);
    Vector3D lightdir((origin - _position).normalized());
    Vector3D lightColor(_color.normalize());
    Vector3D reflectDir(lightdir.reflect(norm));
    Vector3D viewdir((cam.direction()).normalized());
    Ray ray(origin, (origin - _position) * -1, true);
    double specularStrength = point.primitive->getMaterial()->getMetallicVal();
    double diff;
    double spec;

    if (primitives.noObstacle(ray)) {
        diff = _strength * std::max(norm.dot(lightdir * -1), 0.0);
        diffuse = lightColor * diff;

        spec = _strength * pow(std::max(reflectDir.dot(viewdir * -1), 0.0), specularStrength);
        specular = lightColor * spec;
        return (diffuse + specular);
    }
    return Vector3D(0, 0, 0);
}

Raytracer::PointLight::~PointLight()
{
}
