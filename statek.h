#pragma once
#include <SFML/Graphics.hpp>

class Statek {
private:
    sf::ConvexShape shape;
    float speed;
    int zycia;

public:
    Statek(float startX, float startY) {
        shape.setPointCount(3);
        shape.setPoint(0, { 0.f, 30.f });
        shape.setPoint(1, { 60.f, 30.f });
        shape.setPoint(2, { 30.f, 0.f });
        shape.setFillColor(sf::Color::Cyan);

        shape.setPosition(startX - 30.f, startY - 30.f);

        speed = 8.f;
        zycia = 3;
    }

    void moveLeft() { shape.move(-speed, 0.f); }
    void moveRight() { shape.move(speed, 0.f); }

    void update() {
        auto pozycja = shape.getPosition();
        if (pozycja.x < 0) shape.setPosition(0, pozycja.y);
        if (pozycja.x + shape.getGlobalBounds().width > 800)
            shape.setPosition(800 - shape.getGlobalBounds().width, pozycja.y);
    }

    void draw(sf::RenderTarget& target) { target.draw(shape); }
};
