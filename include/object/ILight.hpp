/*
** EPITECH PROJECT, 2023
** ILight
** File description:
** Raytracer
*/

#pragma once
#include "math/HitResult.hpp"
#include "math/Vector3D.hpp"
#include "math/RGB.hpp"
#include "math/Ray.hpp"

namespace Raytracer {

    class PrimitiveList;

    class ILight {
        public:
            [[nodiscard]] virtual Vector3D getImpact(Ray &cam, HitResult &point, PrimitiveList &prim) const = 0;
            virtual ~ILight() = default;

        protected:
        private:
    };

}
