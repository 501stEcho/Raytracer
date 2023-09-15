/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include "math/Matrix.hpp"
#include "exception/MatrixException.hpp"

#include <valarray>
#include <iostream>

Raytracer::Matrix::Matrix(Raytracer::Vector3D vector) : _x(3), _y(1)
{
    _values.push_back({vector.x(), vector.y(), vector.z()});
}

Raytracer::Matrix::Matrix(std::pair<size_t, size_t> size, double value) : _x(size.first), _y(size.second)
{
    for (size_t y = 0; y < _y; y++) {
        std::vector<double> columns;
        for (size_t x = 0; x < _x; x++) {
            columns.push_back(value);
        }
        _values.push_back(columns);
    }
}

Raytracer::Matrix::Matrix(size_t size, double value) : _x(size), _y(size)
{
    for (size_t y = 0; y < _y; y++) {
        std::vector<double> columns;
        for (size_t x = 0; x < _x; x++) {
            columns.push_back(value);
        }
        _values.push_back(columns);
    }
}

Raytracer::Matrix Raytracer::Matrix::operator+(const Raytracer::Matrix &other) const
{
    if (size() != other.size()) {
        throw MatrixException("Matrix A size must be equal to Matrix B size");
    }

    Matrix result = *this;
    for (size_t y = 0; y < _y; y++) {
        for (size_t x = 0; x < _x; x++) {
            result[y][x] += other.getValues()[y][x];
        }
    }

    return result;
}

Raytracer::Matrix &Raytracer::Matrix::operator+=(const Raytracer::Matrix &other)
{
    if (size() != other.size())
        throw MatrixException("Matrix A size must be equal to Matrix B size");

    for (size_t y = 0; y < _y; y++) {
        for (size_t x = 0; x < _x; x++) {
            _values[y][x] += other.getValues()[y][x];
        }
    }
    return *this;
}

Raytracer::Matrix Raytracer::Matrix::operator-(const Raytracer::Matrix &other) const
{
    if (size() != other.size())
        throw MatrixException("Matrix A size must be equal to Matrix B size");

    Matrix result = *this;
    for (size_t y = 0; y < _y; y++) {
        for (size_t x = 0; x < _x; x++) {
            result[y][x] -= other.getValues()[y][x];
        }
    }

    return result;
}

Raytracer::Matrix &Raytracer::Matrix::operator-=(const Raytracer::Matrix &other)
{
    if (size() != other.size())
        throw MatrixException("Matrix A size must be equal to Matrix B size");


    for (size_t y = 0; y < _y; y++) {
        for (size_t x = 0; x < _x; x++) {
            _values[y][x] -= other.getValues()[y][x];
        }
    }
    return *this;
}

Raytracer::Matrix Raytracer::Matrix::operator*(const Raytracer::Matrix &other) const
{
    if (size().first != other.size().second)
        throw MatrixException("The number of columns in the first matrix MUST be the same as the number of rows in the second matrix");

    auto otherValues = other.getValues();
    size_t x = other.size().first;
    size_t y = size().second;
    Matrix result(std::make_pair(x, y));
    for (size_t i = 0; i < y; i++)
        for (size_t j = 0; j < x; j++)
            for (size_t k = 0; k < size().first; k++)
                result[i][j] += _values[i][k] * otherValues[k][j];

    return result;
}

Raytracer::Matrix &Raytracer::Matrix::operator*=(const Raytracer::Matrix &other)
{
    if (size().first != other.size().second)
        throw MatrixException("The number of columns in the first matrix MUST be the same as the number of rows in the second matrix");

    auto otherValues = other.getValues();
    size_t x = other.size().first;
    size_t y = size().second;
    Matrix result(std::make_pair(x, y));
    for (size_t i = 0; i < y; i++)
        for (size_t j = 0; j < x; j++)
            for (size_t k = 0; k < size().first; k++)
                result[i][j] += _values[i][k] * otherValues[k][j];

    setValues(result.getValues());
    return *this;
}

Raytracer::Matrix Raytracer::Matrix::operator*(double other) const
{
    Matrix result = *this;
    for (size_t i = 0; i < _y; i++)
        for (size_t j = 0; j < _x; j++)
            result[i][j] *= other;
    return result;
}

Raytracer::Matrix &Raytracer::Matrix::operator*=(double other)
{
    for (size_t i = 0; i < _y; i++)
        for (size_t j = 0; j < _x; j++)
            _values[i][j] *= other;
    return *this;
}

Raytracer::Matrix Raytracer::Matrix::operator/(double other) const
{
    Matrix result = *this;
    for (size_t i = 0; i < _y; i++)
        for (size_t j = 0; j < _x; j++)
            result[i][j] /= other;
    return result;
}

Raytracer::Matrix &Raytracer::Matrix::operator/=(double other)
{
    for (size_t i = 0; i < _y; i++)
        for (size_t j = 0; j < _x; j++)
            _values[i][j] /= other;
    return *this;
}

bool Raytracer::Matrix::isNull() const
{
    for (size_t y = 0; y < _y; y++)
        for (size_t x = 0; x < _x; x++)
            if (_values[y][x] != 0)
                return false;
    return true;
}

Raytracer::Matrix Raytracer::Matrix::T() const
{
    auto transpose = Matrix(std::make_pair(_y, _x));
    for (size_t i = 0; i < _x; i++)
        for (size_t j = 0; j < _y; j++)
            transpose[i][j] = _values[j][i];
    return transpose;
}
