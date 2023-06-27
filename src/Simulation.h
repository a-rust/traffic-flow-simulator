#include <SFML/Graphics.hpp>
#include "Car.h"

class Simulation
{
    public:
    // Speed limits; will be enforced on every car
    int speed_limit_high;
    int speed_limit_low;
    // Safety parameter to slow down speed of car if any other car in front is within some threshold
    int num_cars_to_decrease_speed;
    int decrease_speed;
    // Parameter to speed up car if it has no cars within some threshold in front of it
    int num_cars_to_increase_speed;
    int increase_speed;

    Simulation(int speed_limit_high, int speed_limit_low, int num_cars_to_decrease_speed, int decrease_speed, int num_cars_to_increase_speed, int increase_speed);

    void highway(sf::RenderWindow& window, std::vector<Car>& cars, Road road);
};