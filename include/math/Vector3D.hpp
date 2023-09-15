/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <math.h>

namespace Raytracer {

    class Vector3D {
    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;

    public:
        explicit Vector3D() = default;

        explicit Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z)
        {}

        Vector3D(const Vector3D &other) = default;
        Vector3D(Vector3D &&other) noexcept = default;

        Vector3D &operator=(const Vector3D &other) = default;
        Vector3D &operator=(Vector3D &&other) noexcept = default;

        ~Vector3D() = default;

        [[nodiscard]] double length() const;
        [[nodiscard]] double dot(const Vector3D &other) const;
        [[nodiscard]] Vector3D normalized() const;
        [[nodiscard]] Vector3D reflect(Vector3D &normal) const;
        [[nodiscard]] Vector3D rotate(Vector3D rotation) const;
        [[nodiscard]] Vector3D cross(Vector3D &other) const;
        [[nodiscard]] Vector3D adaptToOrigin(Vector3D &tangent, Vector3D &normal, Vector3D &bitangent) const;
        [[nodiscard]] Vector3D scale(Vector3D scale) const;
        [[nodiscard]] bool isNull() const;

        [[nodiscard]] const double &x() const;
        [[nodiscard]] const double &y() const;
        [[nodiscard]] const double &z() const;

        [[nodiscard]] double &x();
        [[nodiscard]] double &y();
        [[nodiscard]] double &z();


        Vector3D operator+(const Vector3D &other) const;
        Vector3D& operator+=(const Vector3D &other);

        Vector3D operator-(const Vector3D &other) const;
        Vector3D& operator-=(const Vector3D &other);

        Vector3D operator*(const Vector3D &other) const;
        Vector3D& operator*=(const Vector3D &other);
        Vector3D operator*(double other) const;
        Vector3D& operator*=(double other);

        Vector3D operator/(const Vector3D &other) const;
        Vector3D& operator/=(const Vector3D &other);
        Vector3D operator/(double other) const;
        Vector3D& operator/=(double other);
    };

}
