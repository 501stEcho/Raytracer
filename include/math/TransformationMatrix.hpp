/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-paul.laban
** File description:
** TransformationMatrix
*/

#pragma once

#include "Matrix.hpp"
#include <vector>

namespace Raytracer {

    class TransformationMatrix {

    public:
        static Matrix xRotation(double phi) {
            return Matrix({
                {1, 0, 0},
                {0, cos(phi), -sin(phi)},
                {0, sin(phi), cos(phi)}
            });
        }

        static Matrix yRotation(double theta) {
            return Matrix({
                {cos(theta), 0, sin(theta)},
                {0, 1, 0},
                {-sin(theta), 0, cos(theta)}
            });
        }

        static Matrix zRotation(double psi) {
            return Matrix({
                {cos(psi), -sin(psi), 0},
                {sin(psi), cos(psi), 0},
                {0,0,1}
            });
        }

        static Matrix scalingMatrix(Vector3D vector) {
            return Matrix({
                {vector.x(), 0, 0},
                {0, vector.y(), 0},
                {0, 0, vector.z()}
            });
        }

        static Vector3D rotate(Matrix matrix, Vector3D vector) {
            double x = matrix[0][0] * vector.x() + matrix[0][1] * vector.y() + matrix[0][2] * vector.z();
            double y = matrix[1][0] * vector.x() + matrix[1][1] * vector.y() + matrix[1][2] * vector.z();
            double z = matrix[2][0] * vector.x() + matrix[2][1] * vector.y() + matrix[2][2] * vector.z();

            return Vector3D(x,y,z);
        }
    };
}