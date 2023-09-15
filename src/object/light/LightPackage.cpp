/*
** EPITECH PROJECT, 2023
** getImpact
** File description:
** Raytracer
*/

#include "object/light/LightPackage.hpp"

Raytracer::LightPackage::LightPackage(Raytracer::Configuration &configuration)
{
    for (auto &ambient : configuration.ambients) {
        setAmbient(ambient.toLight());
    }
    for (auto &direct : configuration.directs) {
        addLight(direct.toLight());
    }
    for (auto &point : configuration.points) {
        addLight(point.toLight());
    }
}

Raytracer::RGB Raytracer::LightPackage::computePix(Ray &cam, HitResult &point, PrimitiveList &prim) const
{
    Vector3D result(0, 0, 0);
    RGB objColor = point.primitive->getMaterial()->getPixelColor(cam, point);

    result += _ambient->getImpact(cam, point, prim);
    for (unsigned int i = 0; i < _lights.size(); i++) {
        result += _lights[i]->getImpact(cam, point, prim);
    }
    return (objColor * result);
}

void Raytracer::LightPackage::setAmbient(Light ambient)
{
    _ambient = ambient;
}

void Raytracer::LightPackage::addLight(Light light)
{
    _lights.push_back(light);
}

