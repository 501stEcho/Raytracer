/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "Vector3D.hpp"

namespace Raytracer {

    class Point3D {
    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;

    public:
        explicit Point3D() = default;

        explicit Point3D(double x, double y, double z) : _x(x), _y(y), _z(z)
        {};

        Point3D(const Point3D &other) = default;
        Point3D(Point3D &&other) noexcept = default;

        Point3D &operator=(const Point3D &other) = default;
        Point3D &operator=(Point3D &&other) noexcept = default;

        [[nodiscard]] const double &x() const;
        [[nodiscard]] const double &y() const;
        [[nodiscard]] const double &z() const;

        [[nodiscard]] double dot(const Point3D &other) const;

        Point3D operator+(const Vector3D &vector) const;
        Point3D &operator+=(const Vector3D &vector);

        Point3D operator-(const Point3D &other) const;
        Point3D &operator-=(const Point3D &other);
    };

}
