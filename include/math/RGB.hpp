/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <math.h>
#include <cstdint>
#include "Vector3D.hpp"

namespace Raytracer {

    class RGB {
    private:
        uint32_t _x = 0;
        uint32_t _y = 0;
        uint32_t _z = 0;

    public:
        explicit RGB() = default;

        explicit RGB(uint32_t x, uint32_t y, uint32_t z) : _x(x), _y(y), _z(z)
        {}
        RGB(Vector3D &other);

        [[nodiscard]] Vector3D normalize() const;
        RGB(const RGB &other) = default;
        RGB(RGB &&other) noexcept = default;

        RGB &colorClamp(void);

        RGB &operator=(const RGB &other) = default;
        RGB &operator=(RGB &&other) noexcept = default;

        ~RGB() = default;

        [[nodiscard]] const uint32_t &x() const;
        [[nodiscard]] const uint32_t &y() const;
        [[nodiscard]] const uint32_t &z() const;

        [[nodiscard]] uint32_t &x();
        [[nodiscard]] uint32_t &y();
        [[nodiscard]] uint32_t &z();


        RGB operator+(const RGB &other) const;
        RGB& operator+=(const RGB &other);

        RGB operator-(const RGB &other) const;
        RGB& operator-=(const RGB &other);

        RGB operator*(double other) const;
        RGB operator*(RGB other) const;
        RGB operator*(Vector3D other) const;
        RGB& operator*=(double other);
        RGB& operator*=(Vector3D other);
        RGB& operator*=(RGB other);

        RGB operator/(double other) const;
        RGB& operator/=(double other);
    };
}

uint32_t safe_add(uint32_t v1, uint32_t v2);
uint32_t safe_sub(uint32_t v1, uint32_t v2);
uint32_t safe_mul(uint32_t v1, uint32_t v2);
uint32_t safe_div(uint32_t v1, uint32_t v2);
uint32_t safe_mul(uint32_t v1, double v2);
