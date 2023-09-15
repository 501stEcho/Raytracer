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

    class PointLight : public ILight {
        public:
            PointLight(Vector3D position, RGB color, double strength) :
                _position(position), _color(color), _strength(strength) {};
            [[nodiscard]] Vector3D getImpact(Ray &cam, HitResult &point, PrimitiveList &primitives) const;
            ~PointLight();
    
        protected:
        private:
            Vector3D _position;
            RGB _color;
            double _strength;
    };

}
