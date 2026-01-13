#include "Mouse.h"

Mouse::Mouse()
{
    this->leftClicked = false;
    this->mousePos = sf::Vector2i(0, 0);
}

void Mouse::update(sf::RenderWindow& window)
{
    this->mousePos = sf::Mouse::getPosition(window);
    this->leftClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Mouse::isLeftClicked() const
{
    return this->leftClicked;
}

sf::Vector2i Mouse::getMousePos() const
{
    return this->mousePos;
}

