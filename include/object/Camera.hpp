/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "math/Point3D.hpp"
#include "math/Screen.hpp"
#include "math/Angle.hpp"
#include "math/Ray.hpp"
#include "configuration/ConfigurationLoader.hpp"

namespace Raytracer {

    class Camera {
    private:
        Screen _screen;
        Vector3D _origin;
        Vector3D _rotation;
        double _ambientLight;
        size_t _antiAlias;

    public:
        explicit Camera(const Raytracer::Configuration &configuration) : _screen(Screen(configuration)),
                                                                         _origin(configuration.cameraPosition),
                                                                         _rotation(configuration.cameraRotation),
                                                                         _ambientLight(configuration.cameraAmbient),
                                                                         _antiAlias(configuration.cameraAntiAlias)
        {};

        [[nodiscard]] Ray ray(double u, double v) const;
        [[nodiscard]] double ambientLight() const { return _ambientLight; };
        [[nodiscard]] size_t antiAlias() const { return _antiAlias; };
    };

}
