/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <math.h>
#include <vector>
#include <ostream>
#include "Vector3D.hpp"

namespace Raytracer {

    class Matrix {
    private:
        size_t _x;
        size_t _y;
        std::vector<std::vector<double>> _values;

    public:
        Matrix() : _x(1), _y(1) {}
        explicit Matrix(Vector3D vector);
        explicit Matrix(std::pair<size_t, size_t> size, double value = 0.0);
        explicit Matrix(size_t size, double value = 0.0);
        explicit Matrix(std::vector<std::vector<double>> const &values) : _x(values[0].size()), _y(values.size()), _values(values)
        {}

        Matrix(const Matrix &other) = default;
        Matrix(Matrix &&other) noexcept = default;

        Matrix &operator=(const Matrix &other) = default;
        Matrix &operator=(Matrix &&other) noexcept = default;

        ~Matrix() = default;

        [[nodiscard]] bool isNull() const;

        [[nodiscard]] std::pair<size_t, size_t> size() const { return {_x, _y}; }
        [[nodiscard]] std::vector<std::vector<double>> getValues() const { return _values; };
        void setValues(std::vector<std::vector<double>> const& values) { _values = values; };

        [[nodiscard]] Matrix T() const;

        std::vector<double> &operator[](size_t index) { return _values[index]; }

        Matrix operator+(const Matrix &other) const;
        Matrix& operator+=(const Matrix &other);

        Matrix operator-(const Matrix &other) const;
        Matrix& operator-=(const Matrix &other);

        Matrix operator*(const Matrix &other) const;
        Matrix& operator*=(const Matrix &other);
        Matrix operator*(double other) const;
        Matrix& operator*=(double other);

        Matrix operator/(double other) const;
        Matrix& operator/=(double other);

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
            for (const auto& row : matrix._values) {
                for (const auto& value : row) {
                    os << value << " ";
                }
                os << std::endl;
            }
            return os;
        }
    };

}
