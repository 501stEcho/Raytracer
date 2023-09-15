/*
** EPITECH PROJECT, 2023
** AmbientLight
** File description:
** raytracer
*/

#pragma once

#include "math/Vector3D.hpp"
#include "object/ILight.hpp"
#include <vector>

namespace Raytracer {

    class AmbientLight : public ILight {
        public:
            AmbientLight(RGB color, double strength, unsigned samples_nb, unsigned int noises_nb);
            [[nodiscard]] Vector3D getImpact(Ray &cam, HitResult &point, PrimitiveList &primitives) const;
            [[nodiscard]] double getStrength() const;
            [[nodiscard]] RGB getColor() const;
            ~AmbientLight() = default;

        protected:
        private:
            RGB _color;
            std::vector<Vector3D> _ssaokernel;
            std::vector<Vector3D> _ssaonoise;
            double _strength;
    };

}
