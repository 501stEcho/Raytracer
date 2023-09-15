/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "math/Point3D.hpp"

namespace Raytracer {

    const double &Point3D::x() const
    {
        return _x;
    }

    const double &Point3D::y() const
    {
        return _y;
    }

    const double &Point3D::z() const
    {
        return _z;
    }

    double Point3D::dot(const Point3D &other) const
    {
        return _x * other._x + _y * other._y + _z * other._z;
    }

    Point3D Point3D::operator+(const Vector3D &vector) const
    {
        return Point3D(_x + vector.x(), _y + vector.y(), _z + vector.z());
    }

    Point3D &Point3D::operator+=(const Vector3D &vector)
    {
        _x += vector.x();
        _y += vector.y();
        _z += vector.z();

        return *this;
    }

    Point3D Point3D::operator-(const Point3D &other) const
    {
        return Point3D(_x - other.x(), _y - other.y(), _z - other.z());
    }

    Point3D &Point3D::operator-=(const Point3D &other)
    {
        _x -= other.x();
        _y -= other.y();
        _z -= other.z();

        return *this;
    }

}