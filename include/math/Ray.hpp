/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Raytracer {

    class Ray {
    private:
        Vector3D _origin = Vector3D();
        Vector3D _direction = Vector3D();
        bool _limited;

    public:
        explicit Ray() = default;

        explicit Ray(Vector3D origin, Vector3D direction, bool limited = false) :
            _origin(origin), _direction(direction), _limited(limited)
        {};

        Ray(const Ray &other) = default;
        Ray(Ray &&other) noexcept = default;

        Ray &operator=(const Ray &other) = default;
        Ray &operator=(Ray &&other) noexcept = default;

        [[nodiscard]] const Vector3D &origin() const;
        [[nodiscard]] const Vector3D &direction() const;
        [[nodiscard]] const bool &limited() const;
    };

}
