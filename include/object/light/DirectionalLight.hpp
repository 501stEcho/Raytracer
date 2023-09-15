/*
** EPITECH PROJECT, 2023
** DirectionalLight
** File description:
** Raytracer
*/

#pragma once

#include "math/Vector3D.hpp"
#include "math/Ray.hpp"
#include "object/ILight.hpp"

namespace Raytracer {

    class DirectionalLight : public ILight {
        public:
            DirectionalLight(Vector3D direction, RGB color, double strength) :
                _direction(direction), _color(color), _strength(strength) {};
            [[nodiscard]] Vector3D getImpact(Ray &cam, HitResult &point, PrimitiveList &primitives) const;
            ~DirectionalLight();
    
        protected:
        private:
            Vector3D _direction;
            RGB _color;
            double _strength;
    };

}
