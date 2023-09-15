/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** No file there , just an epitech header example
*/

#pragma once

#include "AOutput.hpp"

#include <SFML/Graphics.hpp>

namespace Raytracer {

    class SFMLOutput : public AOutput {
    private:
        sf::Texture _texture;
        sf::Image _image;
        sf::Sprite _sprite;
        sf::Event _event{};
        bool _loop = true;

        void displayResult(sf::RenderWindow &window);

    public:
        explicit SFMLOutput(unsigned width, unsigned height) : AOutput(width, height)
        {
            for (size_t y = 0; y < _height; y++) {
                for (size_t x = 0; x < _width; x++) {
                    setColor(x, y, RGB());
                }
            }
        };

        void display() override;
    };

    void SFMLOutput::display()
    {
        sf::RenderWindow window(sf::VideoMode(_width, _height), "Raytracer", sf::Style::Titlebar | sf::Style::Close);

        window.setTitle("Raytracer");
        window.setFramerateLimit(16);
        window.requestFocus();

        _texture.create(_width, _height);
        _image = _texture.copyToImage();
        _sprite.setTexture(_texture);

        for (unsigned y = 0; y < _height; y++) {
            for (unsigned x = 0; x < _width; x++) {
                RGB color = getColor(x, y);
                sf::Color newColor((sf::Uint8) color.x(), (sf::Uint8) color.y(), (sf::Uint8) color.z());

                _image.setPixel(x, y, newColor);
            }
        }
        _texture.update(_image);
        displayResult(window);
    }

    void SFMLOutput::displayResult(sf::RenderWindow &window)
    {
        while (_loop) {
            while (window.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed)
                    _loop = false;
                if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Key::Escape)
                    _loop = false;
            }

            window.draw(_sprite);
            window.display();
        }
        window.close();
    }

}