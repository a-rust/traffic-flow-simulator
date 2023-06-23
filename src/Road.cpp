#include "Road.h"

Road::Road(sf::RenderWindow& window, const sf::Vector2f& size, int lanes)
{
    this->lanes = lanes;
    setSize(size);
    // Roads will be grey
    setFillColor(sf::Color(128,128,128,255));
    // For the highway simulation, the road will be position in the middle of the window
    setPosition(window.getSize().x / 2 - size.x / 2,
                       window.getSize().y / 2 - size.y / 2);
}

void Road::draw(sf::RenderWindow& window, int lanes)
{
    sf::Vector2f roadSize = this->getSize();
    sf::Vector2f roadPosition = this->getPosition();
    window.draw(*this);
    // Add dividers to make the roads more realistic
    for (int i=roadPosition.y; i <= roadPosition.y+roadSize.y; i+=(roadSize.y / lanes)){
        for (int j=0; j <= roadSize.x; j+=50) {
        sf::RectangleShape divider;
        divider.setSize(sf::Vector2f(25, 3));
        divider.setPosition(j, i);
        window.draw(divider);
    }
}
}