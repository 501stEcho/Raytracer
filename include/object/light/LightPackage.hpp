/*
** EPITECH PROJECT, 2023
** lightpackage
** File description:
** raytracer
*/

#pragma once

#include "AmbientLight.hpp"
#include "DirectionalLight.hpp"
#include "math/Vector3D.hpp"
#include "object/ILight.hpp"
#include "configuration/ConfigurationLoader.hpp"
#include <memory>

namespace Raytracer {

    class LightPackage {
        public:
            LightPackage(Raytracer::Configuration &configuration);
            RGB computePix(Ray &cam, HitResult &point, PrimitiveList &prim) const;
            void setAmbient(Light ambient);
            void addLight(Light light);
            ~LightPackage() = default;

        protected:
        private:
            Light _ambient;
            std::vector<Light> _lights;
    };

}
