/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <string>
#include <libconfig.h++>
#include <vector>

#include "math/Vector3D.hpp"
#include "ConfigurationParser.hpp"
#include "primitive/IPrimitiveConfiguration.hpp"
#include "configuration/primitive/SphereConfiguration.hpp"
#include "configuration/primitive/PlaneConfiguration.hpp"
#include "configuration/primitive/CylinderConfiguration.hpp"
#include "configuration/primitive/ConeConfiguration.hpp"
#include "configuration/light/DirectionalConfiguration.hpp"
#include "configuration/light/AmbientConfiguration.hpp"
#include "math/Matrix.hpp"
#include "configuration/light/PointConfiguration.hpp"

namespace Raytracer {

    struct Configuration {
        // Camera configuration
        std::pair<int, int> cameraResolution;
        Vector3D cameraPosition;
        Vector3D cameraRotation;
        Vector3D cameraScale;
        double cameraFieldOfView;
        double cameraAmbient;
        int cameraAntiAlias;
        bool child = true;

        // Primitives configuration
        std::vector<SphereConfiguration> spheres;
        std::vector<PlaneConfiguration> planes;
        std::vector<CylinderConfiguration> cylinders;
        std::vector<ConeConfiguration> cones;
        std::vector<DirectionalConfiguration> directs;
        std::vector<AmbientConfiguration> ambients;
        std::vector<Configuration> scenes;
        std::vector<PointConfiguration> points;
    };

    class ConfigurationLoader {
    public:
        explicit ConfigurationLoader(std::string path);

        [[nodiscard]] Configuration loadConfiguration() const;

    private:
        std::string _path;
        libconfig::Config _configuration;

        void parseCamera(Configuration &result) const;
        void parsePrimitives(Configuration &result) const;
        void parseLights(Configuration &result) const;
    };

}
