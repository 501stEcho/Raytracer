/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#include <string>
#include <iostream>

#include "configuration/ConfigurationLoader.hpp"
#include "exception/ConfigurationException.hpp"
#include "rendering/RendererContext.hpp"

static void printHelp()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "  SCENE_FILE: scene configuration" << std::endl;
}

static void launchProgram(const std::string &path)
{
    try {
        Raytracer::ConfigurationLoader loader(path);
        Raytracer::Configuration configuration = loader.loadConfiguration();
        configuration.child = false;
        Raytracer::RendererContext render(configuration);

        render.renderFrame();
        render.outputFrame();
    } catch (Raytracer::ConfigurationException &exception) {
        std::cerr << "./raytracer: " << exception.what() << std::endl;
    }
}

int main(int size, char *args[])
{
    if (size == 2) {
        if (std::string firstArgument = args[1]; firstArgument == "--help")
            printHelp();
        else
            launchProgram(firstArgument);
        return 0;
    }

    printHelp();
    return 84;
}
