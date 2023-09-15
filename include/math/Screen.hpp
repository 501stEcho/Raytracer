/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <cmath>
#include "Point3D.hpp"
#include "configuration/ConfigurationLoader.hpp"

namespace Raytracer {

    class Screen {
    private:
        Vector3D _origin;
        Vector3D _bottomSide = Vector3D(1, 0, 0);
        Vector3D _leftSide;

    public:
        explicit Screen(const Configuration &configuration);

        [[nodiscard]] Vector3D pointAt(double u, double v) const;
    };

}
