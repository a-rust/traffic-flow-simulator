#include <SFML/Graphics.hpp>
// #include "Car.h"
#include "Simulation.h"
#include <time.h>
#include "iostream"

// Road parameters
const int NUM_LANES = 10;
const int NUM_CARS = 200;
const int ROAD_WIDTH = 400;


// Simulation parameters; defined in "Simulations.cpp"
const int SPEED_LIMIT_HIGH = 5;
const int SPEED_LIMIT_LOW = 1;
const int DISTANCE_TO_DECREASE_SPEED = 2;
const int DECREASE_SPEED = -1;
const int DISTANCE_TO_INCREASE_SPEED = 2;
const int INCREASE_SPEED = 1;


void draw_cars(sf::RenderWindow& window, std::vector<Car>& cars) {
  for (Car& car: cars) {
    car.draw(window);
    }
}


int main()
{
    // Carpool lanes
    std::vector<int> carpool_lanes;
    carpool_lanes.push_back(1);
    carpool_lanes.push_back(2);

    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Traffic Flow Simulator");
    window.setFramerateLimit(25);
    Road highway(window, sf::Vector2f(window.getSize().x, ROAD_WIDTH), NUM_LANES);
    std::vector<Car> cars;
    srand(time(NULL));
    // Initial configuration of the simulation
    for (int i = 0; i < NUM_CARS; i++) {
        int lane = 1 + rand() % highway.lanes;
        int lane_position = 1 + rand() % (window.getSize().x / 25);
        int speed = 1 + rand() % 4;
        Car c(window, highway, sf::Color::Green, lane, lane_position, speed);
        cars.push_back(c);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

    highway.draw(window, highway.lanes);

    draw_cars(window, cars);
    

    Simulation sim = Simulation(carpool_lanes, SPEED_LIMIT_HIGH, SPEED_LIMIT_LOW, DISTANCE_TO_DECREASE_SPEED, DECREASE_SPEED, DISTANCE_TO_INCREASE_SPEED, INCREASE_SPEED);

    sim.highway(window, cars, highway);

    window.display();
    }

    return 0;
}
