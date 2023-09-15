/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "math/Vector3D.hpp"
#include "math/TransformationMatrix.hpp"

#include <valarray>
#include <iostream>

#define SQ(x) x * x

double Raytracer::Vector3D::length() const
{
    return std::sqrt(SQ(_x) + SQ(_y) + SQ(_z));
}

double Raytracer::Vector3D::dot(const Raytracer::Vector3D &other) const
{
    return (_x * other._x + _y * other._y + _z * other._z);
}

Raytracer::Vector3D Raytracer::Vector3D::reflect(Vector3D &normal) const
{
    return Raytracer::Vector3D(*this - (normal * 2 * (dot(normal))));
}

Raytracer::Vector3D Raytracer::Vector3D::cross(Vector3D &other) const
{
    double i = _y * other.z() - _z * other.y();
    double j = _x * other.z() - _z * other.x();
    double k = _x * other.y() - _y * other.x();
    return Raytracer::Vector3D(i, j * -1, k);
}

Raytracer::Vector3D Raytracer::Vector3D::normalized() const
{
    double length = this->length();

    if (length == 0)
        return (Raytracer::Vector3D(0, 0, 0));
    return Raytracer::Vector3D(_x / length, _y / length, _z / length);
}

Raytracer::Vector3D Raytracer::Vector3D::adaptToOrigin(Vector3D &tangent, Vector3D &normal, Vector3D &bitangent) const
{
    double x = _x * tangent.x() + _y * tangent.y() + _z * tangent.z();
    double y = _x * normal.x() + _y * normal.y() + _z * normal.z();
    double z = _x * bitangent.x() + _y * bitangent.y() + _z * bitangent.z();

    return Raytracer::Vector3D(x, y, z);
}

const double &Raytracer::Vector3D::x() const
{
    return _x;
}

const double &Raytracer::Vector3D::y() const
{
    return _y;
}

const double &Raytracer::Vector3D::z() const
{
    return _z;
}

double &Raytracer::Vector3D::x()
{
    return _x;
}

double &Raytracer::Vector3D::y()
{
    return _y;
}

double &Raytracer::Vector3D::z()
{
    return _z;
}

Raytracer::Vector3D Raytracer::Vector3D::operator+(const Raytracer::Vector3D &other) const
{
    return Raytracer::Vector3D(_x + other._x, _y + other._y, _z + other._z);
}

Raytracer::Vector3D &Raytracer::Vector3D::operator+=(const Raytracer::Vector3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

Raytracer::Vector3D Raytracer::Vector3D::operator-(const Raytracer::Vector3D &other) const
{
    return Raytracer::Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

Raytracer::Vector3D &Raytracer::Vector3D::operator-=(const Raytracer::Vector3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

Raytracer::Vector3D Raytracer::Vector3D::operator*(const Raytracer::Vector3D &other) const
{
    return Raytracer::Vector3D(_x * other._x, _y * other._y, _z * other._z);
}

Raytracer::Vector3D &Raytracer::Vector3D::operator*=(const Raytracer::Vector3D &other)
{
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    return *this;
}

Raytracer::Vector3D Raytracer::Vector3D::operator*(double other) const
{
    return Raytracer::Vector3D(_x * other, _y * other, _z * other);
}

Raytracer::Vector3D &Raytracer::Vector3D::operator*=(double other)
{
    _x *= other;
    _y *= other;
    _z *= other;
    return *this;
}

Raytracer::Vector3D Raytracer::Vector3D::operator/(const Raytracer::Vector3D &other) const
{
    return Raytracer::Vector3D(_x / other._x, _y / other._y, _z / other._z);
}

Raytracer::Vector3D &Raytracer::Vector3D::operator/=(const Raytracer::Vector3D &other)
{
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    return *this;
}

Raytracer::Vector3D Raytracer::Vector3D::operator/(double other) const
{
    return Raytracer::Vector3D(_x / other, _y / other, _z / other);
}

Raytracer::Vector3D &Raytracer::Vector3D::operator/=(double other)
{
    _x /= other;
    _y /= other;
    _z /= other;
    return *this;
}

bool Raytracer::Vector3D::isNull() const
{
    return (_x == 0 && _y == 0 && _z == 0);
}

Raytracer::Vector3D Raytracer::Vector3D::scale(Vector3D scale) const
{
    auto result = Matrix(*this).T();
    result = TransformationMatrix::scalingMatrix(scale) * result;

    return Vector3D(result[0][0], result[1][0], result[2][0]);
}

Raytracer::Vector3D Raytracer::Vector3D::rotate(Vector3D rotation) const
{
    auto result = Matrix(*this).T();
    if (rotation.x() != 0) result = TransformationMatrix::xRotation(rotation.x()) * result;
    if (rotation.y() != 0) result = TransformationMatrix::yRotation(rotation.y()) * result;
    if (rotation.z() != 0) result = TransformationMatrix::zRotation(rotation.z()) * result;

    return Vector3D(result[0][0], result[1][0], result[2][0]);
}
