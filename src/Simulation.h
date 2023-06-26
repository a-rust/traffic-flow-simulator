#include <SFML/Graphics.hpp>
#include "Car.h"

class Simulation
{
    public:
    Simulation();
    void next_state(sf::RenderWindow& window, std::vector<Car>& cars, Road road);
};