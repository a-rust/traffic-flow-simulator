#include <SFML/Graphics.hpp>
#include <vector>
#include "Car.h"

class Simulation
{
    public:
    // Cars in carpool lanes will have a higher speed limit than cars in normal lanes
    std::vector<int> carpool_lanes;
    // Speed limits; will be enforced on every car
    int max_speed_limit;
    int min_speed_limit;
    // Safety parameter to slow down speed of car if any other car in front is within some threshold
    int spaces_to_decrease_speed;
    float decrease_speed;
    // Parameter to speed up car if it has no cars within some threshold in front of it
    int spaces_to_increase_speed;
    float increase_speed;

    Simulation(std::vector<int> carpool_lanes, int max_speed_limit, int min_speed_limit, int spaces_to_decrease_speed, float decrease_speed, int spaces_to_increase_speed, float increase_speed);

    void highway(sf::RenderWindow& window, std::vector<Car>& cars, Road road);
};