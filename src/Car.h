#include <SFML/Graphics.hpp>
#include "Road.h"

class Car : public sf::RectangleShape 
{
  public:
    float speed;
    int lane;
    int lane_position;
    sf::Color color;
    Car(sf::RenderWindow& window, const Road& road, sf::Color color, int lane, int lane_position, float speed);
    void draw(sf::RenderWindow& window);
};