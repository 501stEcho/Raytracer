/*
** EPITECH PROJECT, 2023
** AmbientLight
** File description:
** Raytracer
*/

#include "object/light/AmbientLight.hpp"
#include "object/PrimitiveList.hpp"

double randomDouble(void)
{
    double r = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX));
    return (r);
}

Raytracer::AmbientLight::AmbientLight(RGB color, double strength, unsigned int samples_nb, unsigned int noises_nb)
    : _color(color), _strength(strength)
{
    float scale;

    for (unsigned int i = 0; i < samples_nb; i++) {
        Vector3D sample(
            randomDouble() * 2.0 - 1.0,
            randomDouble(),
            randomDouble() * 2.0 - 1.0
        );
        if (sample.y() < 0.01)
            sample.y() += 0.01;
        sample = sample.normalized();
        sample *= randomDouble();

        scale = static_cast<double>(i + 1) / static_cast<double>(samples_nb);
        sample *= std::lerp(0.1, 1.0, scale * scale);
        sample *= scale;
        _ssaokernel.push_back(sample);
    }
    for (unsigned int i = 0; i < noises_nb; i++) {
        Vector3D noise(
            randomDouble() * 2.0 - 1.0,
            randomDouble() * 2.0 - 1.0,
            0.0
        );
        _ssaonoise.push_back(noise);
    }
}

double Raytracer::AmbientLight::getStrength() const
{
    return _strength;
}

Raytracer::RGB Raytracer::AmbientLight::getColor() const
{
    return _color;
}

Raytracer::Vector3D Raytracer::AmbientLight::getImpact(Ray &cam, HitResult &point, PrimitiveList &primitives) const
{
    Vector3D fragPos = point.point;
    Vector3D normal = point.normal.normalized();
    Vector3D randomVec = _ssaonoise[rand() % _ssaonoise.size()];
    Vector3D tangent = (randomVec - normal * randomVec.dot(normal));
    Vector3D bitangent = normal.cross(tangent);
    double radius = 0.5;
    double occlusion = 0.0;

    for (unsigned int i = 0; i < _ssaokernel.size(); i++) {
        Vector3D sample = _ssaokernel[i].adaptToOrigin(tangent, normal, bitangent);

        sample = point.point + sample * radius;
        Ray ray(sample, cam.origin() - sample, true);
        if (!primitives.noObstacle(ray)) {
            occlusion += 1.0;
        }
    }
    return (_color.normalize() * _strength * (1.0 - occlusion / static_cast<double>(_ssaokernel.size())));
}
