/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-paul.laban
** File description:
** Angle
*/

#pragma once

#include <cmath>
#include "Vector3D.hpp"

namespace Raytracer {

    class Angle {
    public:
        static double toRadians(double value) {
            return value * M_PI / 180;
        }
        static double toDegrees(double value) {
            return value * 180 / M_PI;
        }
        static Vector3D radianVector(double x, double y, double z) {
            return Vector3D(toRadians(x), toRadians(y), toRadians(z));
        }
    };

}