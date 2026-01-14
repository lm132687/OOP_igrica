#include "Mouse.h"

Mouse::Mouse()
{
    this->leftClicked = false;
    //this->prevClicked = false;
    this->mousePos = sf::Vector2i(0, 0);
}

void Mouse::update(sf::RenderWindow& window)
{
    bool current = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    leftClicked = (!prevClicked && current);
    prevClicked = current;

    this->mousePos = sf::Mouse::getPosition(window);
}

bool Mouse::isLeftClicked() const
{
    return this->leftClicked;
}

sf::Vector2i Mouse::getMousePos() const
{
    return this->mousePos;
}

