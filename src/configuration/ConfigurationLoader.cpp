/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <filesystem>

#include "configuration/ConfigurationLoader.hpp"
#include "exception/ConfigurationException.hpp"
#include "math/Angle.hpp"

namespace fs = std::filesystem;

#define REASON(e) std::string("Parse error at ") + e.getFile() + ":" + std::to_string(e.getLine()) + " - " + e.getError()

Raytracer::ConfigurationLoader::ConfigurationLoader(std::string path) : _path(std::move(path))
{
    if (!fs::exists(_path))
        throw ConfigurationException("Unable to find configuration file");

    try {
        _configuration.readFile(_path.c_str());
    } catch (libconfig::FileIOException &) {
        throw ConfigurationException("Error while reading configuration file");
    } catch (libconfig::ParseException &exception) {
        throw ConfigurationException(REASON(exception));
    }
}

Raytracer::Configuration Raytracer::ConfigurationLoader::loadConfiguration() const
{
    Raytracer::Configuration result;

    try {
        parseCamera(result);
        parsePrimitives(result);
        parseLights(result);
    } catch (libconfig::SettingTypeException &) {
        throw ConfigurationException("Invalid type in configuration file");
    }

    return result;
}

void Raytracer::ConfigurationLoader::parseCamera(Raytracer::Configuration &result) const
{
    const libconfig::Setting &root = _configuration.getRoot();
    const auto &camera = FIND_VALUE(Raytracer::Setting, root, "camera");
    const auto &resolution = FIND_VALUE(Raytracer::Setting, camera, "resolution");
    const auto &position = FIND_VALUE(Raytracer::Setting, camera, "position");
    const auto &rotation = FIND_VALUE(Raytracer::Setting, camera, "rotation");
    const auto &scale = FIND_VALUE(Raytracer::Setting, camera, "scale");

    result.cameraResolution = std::make_pair<int, int>(resolution["width"], resolution["height"]);
    result.cameraPosition = Raytracer::Vector3D(FIND_VALUE(int, position, "x"),
                                                FIND_VALUE(int, position, "y"),
                                                FIND_VALUE(int, position, "z"));
    result.cameraRotation = Angle::radianVector(FIND_VALUE(int, rotation, "x"),
                                                FIND_VALUE(int, rotation, "y"),
                                                FIND_VALUE(int, rotation, "z"));
    result.cameraScale = Raytracer::Vector3D(FIND_VALUE(double, scale, "x"),
                                                FIND_VALUE(double, scale, "y"),
                                                FIND_VALUE(double, scale, "z"));
    result.cameraFieldOfView = camera["fieldOfView"];
    result.cameraAntiAlias = camera["antiAlias"];
}

#define ADD_PRIMITIVE(name, list, configurationClass) \
    if (primitives.exists(name)) {                          \
        const auto &primitiveList = FIND_VALUE(Raytracer::Setting, primitives, name); \
        for (int index = 0; index < primitiveList.getLength(); index++) { \
            const auto &primitive = primitiveList[index]; \
            const auto configuration = configurationClass(primitive); \
            list.push_back(configuration); \
        } \
    } \

void Raytracer::ConfigurationLoader::parsePrimitives(Raytracer::Configuration &result) const
{
    const libconfig::Setting &root = _configuration.getRoot();
    const auto &primitives = FIND_VALUE(Raytracer::Setting, root, "primitives");
    if (primitives.exists("scenes")) {
        const auto &scenes = FIND_VALUE(Raytracer::Setting, primitives, "scenes");
        for (int index = 0; index < scenes.getLength(); index++) {
            const auto &scene = scenes[index];
            auto path = FIND_VALUE(std::string, scene, "path");

            ConfigurationLoader loader(path);
            result.scenes.push_back(loader.loadConfiguration());
        }
    }
    ADD_PRIMITIVE("spheres", result.spheres, SphereConfiguration)
    ADD_PRIMITIVE("planes", result.planes, PlaneConfiguration)
    ADD_PRIMITIVE("cylinders", result.cylinders, CylinderConfiguration)
    ADD_PRIMITIVE("cones", result.cones, ConeConfiguration)
}

void Raytracer::ConfigurationLoader::parseLights(Raytracer::Configuration &result) const
{
    const libconfig::Setting &root = _configuration.getRoot();
    if (!root.exists("lights"))
        return;

    const auto &lights = FIND_VALUE(Raytracer::Setting, root, "lights");
    const auto &ambients = FIND_VALUE(Raytracer::Setting, lights, "ambient");
    const auto &directionals = FIND_VALUE(Raytracer::Setting, lights, "directional");
    const auto &points = FIND_VALUE(Raytracer::Setting, lights, "point");

    for (int index = 0; index < ambients.getLength(); index++) {
        const auto &ambient = ambients[index];
        const auto configuration = AmbientConfiguration(ambient);

        result.ambients.push_back(configuration);
    }

    for (int index = 0; index < directionals.getLength(); index++) {
        const auto &directional = directionals[index];
        const auto configuration = DirectionalConfiguration(directional);

        result.directs.push_back(configuration);
    }

    for (int index = 0; index < points.getLength(); index++) {
        const auto &point = points[index];
        const auto configuration = PointConfiguration(point);

        result.points.push_back(configuration);
    }
}
