#include <SFML/Graphics.hpp>

class Road : public sf::RectangleShape
{
public:
    // Parameters to choose the number of lanes in the simulation
    int lanes;
    Road(sf::RenderWindow& window, const sf::Vector2f& size);
    void draw(sf::RenderWindow& window, int lanes);
};
