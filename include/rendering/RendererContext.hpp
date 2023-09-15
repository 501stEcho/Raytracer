/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include <utility>
#include <queue>

#include "object/Camera.hpp"
#include "object/PrimitiveList.hpp"
#include "object/light/LightPackage.hpp"
#include "output/AOutput.hpp"

namespace Raytracer {

    class RendererContext {
    private:
        std::pair<int, int> _resolution;
        Camera _camera;
        PrimitiveList _primitives;
        LightPackage _lights;
        Output _output;

        std::vector<std::pair<int, int>> _pixelsToRender;

        static double randomDouble();

    public:
        explicit RendererContext(Configuration &configuration);

        void renderFrame();
        void outputFrame() const;
    };

}
