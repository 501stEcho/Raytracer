/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "IPrimitive.hpp"
#include "PrimitiveFactory.hpp"
#include "configuration/ConfigurationLoader.hpp"
#include "math/Matrix.hpp"
#include "math/TransformationMatrix.hpp"

#include <vector>
#include <memory>
#include <algorithm>

namespace Raytracer {

    class PrimitiveList : public IPrimitive {
        private:
            std::vector<Primitive> _list;
            std::vector<PrimitiveList> _scenes;
            Vector3D _scale;
            Vector3D _rotation;
            Vector3D _translation;
            Primitive _lastHit;

        public:
            explicit PrimitiveList(Configuration &configuration) : IPrimitive()
            {
                if (configuration.child) {
                    _rotation = configuration.cameraRotation;
                    _scale = configuration.cameraScale;
                    _translation = configuration.cameraPosition;
                } else {
                    _rotation = Vector3D();
                    _scale = Vector3D(1,1,1);
                    _translation = Vector3D();
                }

                for (auto &scene : configuration.scenes) {
                    add(scene);
                }
                for (auto &sphere : configuration.spheres) {
                    add(sphere.toPrimitive());
                }
                for (auto &plane : configuration.planes) {
                    add(plane.toPrimitive());
                }
                for (auto &cylinder : configuration.cylinders) {
                    add(cylinder.toPrimitive());
                }
                for (auto &cone : configuration.cones) {
                    add(cone.toPrimitive());
                }
            };

            PrimitiveList &add(const Primitive &element);
            PrimitiveList &add(Configuration &element);
            void clear();

            bool noObstacle(const Ray &ray) override;
            HitOptionalResult hits(const Ray &ray) override;
            [[nodiscard]] Material getMaterial() const override;

            [[nodiscard]] std::pair<double, double> getTextureRatio(const HitResult &result) override;

    };

}
