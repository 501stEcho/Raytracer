/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "math/RGB.hpp"

#include <valarray>

#define SQ(x) x * x

uint32_t safe_add(uint32_t v1, uint32_t v2)
{
    if (v1 + v2 > UINT32_MAX)
        return (UINT32_MAX);
    return (v1 + v2);
}

uint32_t safe_sub(uint32_t v1, uint32_t v2)
{
    if (v1 < v2)
        return (0);
    return (v1 - v2);
}

uint32_t safe_mul(uint32_t v1, uint32_t v2)
{
    if (v1 * v2 > UINT32_MAX)
        return (UINT32_MAX);
    return (v1 * v2);
}

uint32_t safe_div(uint32_t v1, uint32_t v2)
{
    if (v2 == 0)
        return (0);
    return (v1 / v2);
}

uint32_t safe_mul(uint32_t v1, double v2)
{
    if (v1 * v2 > UINT32_MAX)
        return (UINT32_MAX);
    if (v1 * v2 < 0)
        return (0);
    return (v1 * v2);
}

Raytracer::RGB::RGB(Vector3D &other)
{
    _x = static_cast<uint32_t>(other.x());
    _y = static_cast<uint32_t>(other.y());
    _z = static_cast<uint32_t>(other.z());
}


Raytracer::Vector3D Raytracer::RGB::normalize() const
{
    double x(_x);
    double y(_y);
    double z(_z);

    return (Raytracer::Vector3D(x / 255, y / 255, z / 255));
}

Raytracer::RGB &Raytracer::RGB::colorClamp(void)
{
    if (_x > UINT8_MAX)
        _x = UINT8_MAX;
    if (_y > UINT8_MAX)
        _y = UINT8_MAX;
    if (_z > UINT8_MAX)
        _z = UINT8_MAX;
    return (*this);
}

const uint32_t &Raytracer::RGB::x() const
{
    return _x;
}

const uint32_t &Raytracer::RGB::y() const
{
    return _y;
}

const uint32_t &Raytracer::RGB::z() const
{
    return _z;
}

uint32_t &Raytracer::RGB::x()
{
    return _x;
}

uint32_t &Raytracer::RGB::y()
{
    return _y;
}

uint32_t &Raytracer::RGB::z()
{
    return _z;
}

Raytracer::RGB Raytracer::RGB::operator+(const Raytracer::RGB &other) const
{
    return Raytracer::RGB(safe_add(_x, other._x), safe_add(_y, other._y), safe_add(_z, other._z));
}

Raytracer::RGB &Raytracer::RGB::operator+=(const Raytracer::RGB &other)
{
    _x = safe_add(_x, other._x);
    _y = safe_add(_y, other._y);
    _z = safe_add(_z, other._z);
    return *this;
}

Raytracer::RGB Raytracer::RGB::operator-(const Raytracer::RGB &other) const
{
    return Raytracer::RGB(safe_sub(_x, other._x), safe_sub(_y, other._y), safe_sub(_z, other._z));
}

Raytracer::RGB &Raytracer::RGB::operator-=(const Raytracer::RGB &other)
{
    _x = safe_sub(_x, other._x);
    _y = safe_sub(_y, other._y);
    _z = safe_sub(_z, other._z);
    return *this;
}

Raytracer::RGB Raytracer::RGB::operator*(double other) const
{
    return Raytracer::RGB(safe_mul(_x, other), safe_mul(_y, other), safe_mul(_z, other));
}

Raytracer::RGB &Raytracer::RGB::operator*=(double other)
{
    _x = (safe_mul(_x, other));
    _y = (safe_mul(_y, other));
    _z = (safe_mul(_z, other));
    return *this;
}

Raytracer::RGB Raytracer::RGB::operator*(Vector3D other) const
{
    return Raytracer::RGB(safe_mul(_x, other.x()), safe_mul(_y, other.y()), safe_mul(_z, other.z()));
}

Raytracer::RGB& Raytracer::RGB::operator*=(Vector3D other)
{
    _x = (safe_mul(_x, other.x()));
    _y = (safe_mul(_y, other.y()));
    _z = (safe_mul(_z, other.z()));
    return *this;
}


Raytracer::RGB Raytracer::RGB::operator*(RGB other) const
{
    return Raytracer::RGB(safe_mul(_x, other._x), safe_mul(_y, other._y), safe_mul(_z, other._z));
}

Raytracer::RGB& Raytracer::RGB::operator*=(RGB other)
{
    _x = (safe_mul(_x, other._x));
    _y = (safe_mul(_y, other._y));
    _z = (safe_mul(_z, other._z));
    return *this;
}

Raytracer::RGB Raytracer::RGB::operator/(double other) const
{
    return Raytracer::RGB(safe_div(_x, other), safe_div(_y, other), safe_div(_z, other));
}

Raytracer::RGB& Raytracer::RGB::operator/=(double other)
{
    _x = (safe_div(_x, other));
    _y = (safe_div(_y, other));
    _z = (safe_div(_z, other));
    return *this;
}


