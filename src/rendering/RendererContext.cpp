/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <random>
#include "rendering/RendererContext.hpp"
#include "output/OutputFactory.hpp"

Raytracer::RendererContext::RendererContext(Raytracer::Configuration &configuration) :
        _resolution(configuration.cameraResolution), _camera(configuration), _primitives(configuration),
        _lights(configuration) {
    auto [width, height] = _resolution;

    _output = Raytracer::OutputFactory::getCurrentOutput(width, height);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            _pixelsToRender.emplace_back(x, y);
}

void Raytracer::RendererContext::renderFrame() {
    auto [width, height] = _resolution;

    for (const auto &pixel : _pixelsToRender) {
        auto [x, y] = pixel;

        Raytracer::RGB pixel_color(0, 0, 0);
        for (size_t i = 0; i < _camera.antiAlias(); i++) {
            double u = ((x + randomDouble()) / (double) width);
            double v = ((y + randomDouble()) / (double) height);
            Raytracer::Ray ray = _camera.ray(u, v);
            Raytracer::HitOptionalResult optional = _primitives.hits(ray);

            if (optional.has_value())
                pixel_color += _lights.computePix(ray, optional.value(), _primitives);
        }
        pixel_color /= (double) _camera.antiAlias();
        pixel_color.colorClamp();
        _output->setColor(x, y, pixel_color);
    }
}

void Raytracer::RendererContext::outputFrame() const {
    _output->display();
}

double Raytracer::RendererContext::randomDouble() {
    static std::uniform_real_distribution distribution(0.0, 1.0);
    static std::mt19937 generator;

    return distribution(generator);
}
