#include "Car.h"

Car::Car(sf::RenderWindow& window, const Road& road, sf::Color color, int lane, int lane_position)
{
    this->lane = lane;
    this->lane_position = lane_position;
    setSize(sf::Vector2f((road.getSize().y / road.lanes)/2, (road.getSize().y / road.lanes)/2));
    setPosition(sf::Vector2f(lane_position*25, road.getPosition().y + (lane-1)*(road.getSize().y / road.lanes) + 12.5));
    setFillColor(color);
}

void Car::draw(sf::RenderWindow& window) {
    window.draw(*this);
}
